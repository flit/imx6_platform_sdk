/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_ESAI_REGISTERS_H__
#define __HW_ESAI_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ ESAI registers defined in this header file.
 *
 * - HW_ESAI_ETDR - ESAI Transmit Data Register
 * - HW_ESAI_ERDR - ESAI Receive Data Register
 * - HW_ESAI_ECR - ESAI Control Register
 * - HW_ESAI_ESR - ESAI Status Register
 * - HW_ESAI_TFCR - Transmit FIFO Configuration Register
 * - HW_ESAI_TFSR - Transmit FIFO Status Register
 * - HW_ESAI_RFCR - Receive FIFO Configuration Register
 * - HW_ESAI_RFSR - Receive FIFO Status Register
 * - HW_ESAI_TX0 - Transmit Data Register n
 * - HW_ESAI_TX1 - Transmit Data Register n
 * - HW_ESAI_TX2 - Transmit Data Register n
 * - HW_ESAI_TX3 - Transmit Data Register n
 * - HW_ESAI_TX4 - Transmit Data Register n
 * - HW_ESAI_TX5 - Transmit Data Register n
 * - HW_ESAI_TX - Transmit Data Register n
 * - HW_ESAI_RX0 - Receive Data Register n
 * - HW_ESAI_RX1 - Receive Data Register n
 * - HW_ESAI_RX2 - Receive Data Register n
 * - HW_ESAI_RX3 - Receive Data Register n
 * - HW_ESAI_SAISR - Serial Audio Interface Status Register
 * - HW_ESAI_SAICR - Serial Audio Interface Control Register
 * - HW_ESAI_TCR - Transmit Control Register
 * - HW_ESAI_TCCR - Transmit Clock Control Register
 * - HW_ESAI_RCR - Receive Control Register
 * - HW_ESAI_RCCR - Receive Clock Control Register
 * - HW_ESAI_TSMA - Transmit Slot Mask Register A
 * - HW_ESAI_TSMB - Transmit Slot Mask Register B
 * - HW_ESAI_RSMA - Receive Slot Mask Register A
 * - HW_ESAI_RSMB - Receive Slot Mask Register B
 * - HW_ESAI_PRRC - Port C Direction Register
 * - HW_ESAI_PCRC - Port C Control Register
 *
 * - hw_esai_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ESAI_BASE
#define HW_ESAI_INSTANCE_COUNT (1) //!< Number of instances of the ESAI module.
#define REGS_ESAI_BASE (0x02024000) //!< Base address for ESAI.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_ETDR - ESAI Transmit Data Register (WORZ)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_etdr
{
    reg32_t U;
    struct _hw_esai_etdr_bitfields
    {
        unsigned ETDR : 32; //!< [31:0] ESAI Transmit Data Register. Writing to this register stores the data written into the ESAI Transmit FIFO. Writing to this register when the Transmit FIFO is full causes the data written to be lost (the existing data within the FIFO is not overwritten). When multiple ESAI transmitters are enabled, the data for each transmitter must be interleaved from lowest transmitter to highest transmitter (for example, if transmitters 0, 2 and 3 are enabled then data must be written as follows: transmitter #0, transmitter #2, transmitter #3, transmitter #0, transmitter #2, transmitter #3, transmitter #0, etc). Data within the ESAI Transmit FIFO is passed to the ESAI transmit shifter registers as defined by the Transmit Word Alignment configuration bits.
    } B;
} hw_esai_etdr_t;
#endif

/*
 * constants & macros for entire ESAI_ETDR register
 */
#define HW_ESAI_ETDR_ADDR      (REGS_ESAI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ETDR           (*(volatile hw_esai_etdr_t *) HW_ESAI_ETDR_ADDR)
#define HW_ESAI_ETDR_WR(v)     (HW_ESAI_ETDR.U = (v))
#endif

/*
 * constants & macros for individual ESAI_ETDR bitfields
 */

/* --- Register HW_ESAI_ETDR, field ETDR[31:0] (WORZ)
 *
 * ESAI Transmit Data Register. Writing to this register stores the data written into the ESAI
 * Transmit FIFO. Writing to this register when the Transmit FIFO is full causes the data written to
 * be lost (the existing data within the FIFO is not overwritten). When multiple ESAI transmitters
 * are enabled, the data for each transmitter must be interleaved from lowest transmitter to highest
 * transmitter (for example, if transmitters 0, 2 and 3 are enabled then data must be written as
 * follows: transmitter #0, transmitter #2, transmitter #3, transmitter #0, transmitter #2,
 * transmitter #3, transmitter #0, etc). Data within the ESAI Transmit FIFO is passed to the ESAI
 * transmit shifter registers as defined by the Transmit Word Alignment configuration bits.
 */

#define BP_ESAI_ETDR_ETDR      (0)      //!< Bit position for ESAI_ETDR_ETDR.
#define BM_ESAI_ETDR_ETDR      (0xffffffff)  //!< Bit mask for ESAI_ETDR_ETDR.

//! @brief Get value of ESAI_ETDR_ETDR from a register value.
#define BG_ESAI_ETDR_ETDR(r)   (((r) & BM_ESAI_ETDR_ETDR) >> BP_ESAI_ETDR_ETDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ETDR_ETDR.
#define BF_ESAI_ETDR_ETDR(v)   ((((reg32_t) v) << BP_ESAI_ETDR_ETDR) & BM_ESAI_ETDR_ETDR)
#else
//! @brief Format value for bitfield ESAI_ETDR_ETDR.
#define BF_ESAI_ETDR_ETDR(v)   (((v) << BP_ESAI_ETDR_ETDR) & BM_ESAI_ETDR_ETDR)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_ERDR - ESAI Receive Data Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_erdr
{
    reg32_t U;
    struct _hw_esai_erdr_bitfields
    {
        unsigned ERDR : 32; //!< [31:0] ESAI Receive Data Register. Reading this register returns the data within the ESAI Receive FIFO. Reading this register when the Receive FIFO is empty returns the last valid data word. When multiple ESAI receivers are enabled, the data for each receiver is interleaved from lowest receiver to highest receiver (for example, if receivers 0, 2 and 3 are enabled then data is returned as follows: receiver #0, receiver #2, receiver #3, receiver #0, receiver #2, receiver #3, receiver #0, etc). Data is passed from the ESAI receive shift registers to the ESAI Receive FIFO as defined by the Receiver Word Alignment configuration bits either zero or sign-extended based on the Receive Extension control bit.
    } B;
} hw_esai_erdr_t;
#endif

/*
 * constants & macros for entire ESAI_ERDR register
 */
#define HW_ESAI_ERDR_ADDR      (REGS_ESAI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ERDR           (*(volatile hw_esai_erdr_t *) HW_ESAI_ERDR_ADDR)
#define HW_ESAI_ERDR_RD()      (HW_ESAI_ERDR.U)
#endif

/*
 * constants & macros for individual ESAI_ERDR bitfields
 */

/* --- Register HW_ESAI_ERDR, field ERDR[31:0] (RO)
 *
 * ESAI Receive Data Register. Reading this register returns the data within the ESAI Receive FIFO.
 * Reading this register when the Receive FIFO is empty returns the last valid data word. When
 * multiple ESAI receivers are enabled, the data for each receiver is interleaved from lowest
 * receiver to highest receiver (for example, if receivers 0, 2 and 3 are enabled then data is
 * returned as follows: receiver #0, receiver #2, receiver #3, receiver #0, receiver #2, receiver
 * #3, receiver #0, etc). Data is passed from the ESAI receive shift registers to the ESAI Receive
 * FIFO as defined by the Receiver Word Alignment configuration bits either zero or sign-extended
 * based on the Receive Extension control bit.
 */

#define BP_ESAI_ERDR_ERDR      (0)      //!< Bit position for ESAI_ERDR_ERDR.
#define BM_ESAI_ERDR_ERDR      (0xffffffff)  //!< Bit mask for ESAI_ERDR_ERDR.

//! @brief Get value of ESAI_ERDR_ERDR from a register value.
#define BG_ESAI_ERDR_ERDR(r)   (((r) & BM_ESAI_ERDR_ERDR) >> BP_ESAI_ERDR_ERDR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_ECR - ESAI Control Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_ecr
{
    reg32_t U;
    struct _hw_esai_ecr_bitfields
    {
        unsigned ESAIEN : 1; //!< [0] ESAI Enable. Enables/disables the ESAI logic clock. Enable the ESAI before reading or writing other ESAI registers.
        unsigned ERST : 1; //!< [1] ESAI Reset. Reset the ESAI core logic (including configuration registers) but not the ESAI FIFOs.
        unsigned RESERVED0 : 14; //!< [15:2] Reserved
        unsigned ERO : 1; //!< [16] EXTAL Receiver Out. Drive the EXTAL input on the High Frequency Receiver Clock pin.
        unsigned ERI : 1; //!< [17] EXTAL Receiver In. Mux EXTAL in place of the High Frequency Receiver Clock input pin. HCKR can still be used to drive a divided down EXTAL or as GPIO.
        unsigned ETO : 1; //!< [18] EXTAL Transmitter Out. Drive the EXTAL input on the High Frequency Transmitter Clock pin.
        unsigned ETI : 1; //!< [19] EXTAL Transmitter In. Mux EXTAL in place of the High Frequency Transmitter Clock input pin. HCKT can still be used to drive a divided down EXTAL or as GPIO.
        unsigned RESERVED1 : 12; //!< [31:20] Reserved
    } B;
} hw_esai_ecr_t;
#endif

/*
 * constants & macros for entire ESAI_ECR register
 */
#define HW_ESAI_ECR_ADDR      (REGS_ESAI_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ECR           (*(volatile hw_esai_ecr_t *) HW_ESAI_ECR_ADDR)
#define HW_ESAI_ECR_RD()      (HW_ESAI_ECR.U)
#define HW_ESAI_ECR_WR(v)     (HW_ESAI_ECR.U = (v))
#define HW_ESAI_ECR_SET(v)    (HW_ESAI_ECR_WR(HW_ESAI_ECR_RD() |  (v)))
#define HW_ESAI_ECR_CLR(v)    (HW_ESAI_ECR_WR(HW_ESAI_ECR_RD() & ~(v)))
#define HW_ESAI_ECR_TOG(v)    (HW_ESAI_ECR_WR(HW_ESAI_ECR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_ECR bitfields
 */

/* --- Register HW_ESAI_ECR, field ESAIEN[0] (RW)
 *
 * ESAI Enable. Enables/disables the ESAI logic clock. Enable the ESAI before reading or writing
 * other ESAI registers.
 *
 * Values:
 * 0 - ESAI disabled.
 * 1 - ESAI enabled.
 */

#define BP_ESAI_ECR_ESAIEN      (0)      //!< Bit position for ESAI_ECR_ESAIEN.
#define BM_ESAI_ECR_ESAIEN      (0x00000001)  //!< Bit mask for ESAI_ECR_ESAIEN.

//! @brief Get value of ESAI_ECR_ESAIEN from a register value.
#define BG_ESAI_ECR_ESAIEN(r)   (((r) & BM_ESAI_ECR_ESAIEN) >> BP_ESAI_ECR_ESAIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ECR_ESAIEN.
#define BF_ESAI_ECR_ESAIEN(v)   ((((reg32_t) v) << BP_ESAI_ECR_ESAIEN) & BM_ESAI_ECR_ESAIEN)
#else
//! @brief Format value for bitfield ESAI_ECR_ESAIEN.
#define BF_ESAI_ECR_ESAIEN(v)   (((v) << BP_ESAI_ECR_ESAIEN) & BM_ESAI_ECR_ESAIEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ESAIEN field to a new value.
#define BW_ESAI_ECR_ESAIEN(v)   (HW_ESAI_ECR_WR((HW_ESAI_ECR_RD() & ~BM_ESAI_ECR_ESAIEN) | BF_ESAI_ECR_ESAIEN(v)))
#endif


/* --- Register HW_ESAI_ECR, field ERST[1] (RW)
 *
 * ESAI Reset. Reset the ESAI core logic (including configuration registers) but not the ESAI FIFOs.
 *
 * Values:
 * 0 - ESAI not reset.
 * 1 - ESAI reset.
 */

#define BP_ESAI_ECR_ERST      (1)      //!< Bit position for ESAI_ECR_ERST.
#define BM_ESAI_ECR_ERST      (0x00000002)  //!< Bit mask for ESAI_ECR_ERST.

//! @brief Get value of ESAI_ECR_ERST from a register value.
#define BG_ESAI_ECR_ERST(r)   (((r) & BM_ESAI_ECR_ERST) >> BP_ESAI_ECR_ERST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ECR_ERST.
#define BF_ESAI_ECR_ERST(v)   ((((reg32_t) v) << BP_ESAI_ECR_ERST) & BM_ESAI_ECR_ERST)
#else
//! @brief Format value for bitfield ESAI_ECR_ERST.
#define BF_ESAI_ECR_ERST(v)   (((v) << BP_ESAI_ECR_ERST) & BM_ESAI_ECR_ERST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERST field to a new value.
#define BW_ESAI_ECR_ERST(v)   (HW_ESAI_ECR_WR((HW_ESAI_ECR_RD() & ~BM_ESAI_ECR_ERST) | BF_ESAI_ECR_ERST(v)))
#endif


/* --- Register HW_ESAI_ECR, field ERO[16] (RW)
 *
 * EXTAL Receiver Out. Drive the EXTAL input on the High Frequency Receiver Clock pin.
 *
 * Values:
 * 0 - HCKR pin has normal function.
 * 1 - EXTAL driven onto HCKR pin.
 */

#define BP_ESAI_ECR_ERO      (16)      //!< Bit position for ESAI_ECR_ERO.
#define BM_ESAI_ECR_ERO      (0x00010000)  //!< Bit mask for ESAI_ECR_ERO.

//! @brief Get value of ESAI_ECR_ERO from a register value.
#define BG_ESAI_ECR_ERO(r)   (((r) & BM_ESAI_ECR_ERO) >> BP_ESAI_ECR_ERO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ECR_ERO.
#define BF_ESAI_ECR_ERO(v)   ((((reg32_t) v) << BP_ESAI_ECR_ERO) & BM_ESAI_ECR_ERO)
#else
//! @brief Format value for bitfield ESAI_ECR_ERO.
#define BF_ESAI_ECR_ERO(v)   (((v) << BP_ESAI_ECR_ERO) & BM_ESAI_ECR_ERO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERO field to a new value.
#define BW_ESAI_ECR_ERO(v)   (HW_ESAI_ECR_WR((HW_ESAI_ECR_RD() & ~BM_ESAI_ECR_ERO) | BF_ESAI_ECR_ERO(v)))
#endif


/* --- Register HW_ESAI_ECR, field ERI[17] (RW)
 *
 * EXTAL Receiver In. Mux EXTAL in place of the High Frequency Receiver Clock input pin. HCKR can
 * still be used to drive a divided down EXTAL or as GPIO.
 *
 * Values:
 * 0 - HCKR pin has normal function.
 * 1 - EXTAL muxed into HCKR input.
 */

#define BP_ESAI_ECR_ERI      (17)      //!< Bit position for ESAI_ECR_ERI.
#define BM_ESAI_ECR_ERI      (0x00020000)  //!< Bit mask for ESAI_ECR_ERI.

//! @brief Get value of ESAI_ECR_ERI from a register value.
#define BG_ESAI_ECR_ERI(r)   (((r) & BM_ESAI_ECR_ERI) >> BP_ESAI_ECR_ERI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ECR_ERI.
#define BF_ESAI_ECR_ERI(v)   ((((reg32_t) v) << BP_ESAI_ECR_ERI) & BM_ESAI_ECR_ERI)
#else
//! @brief Format value for bitfield ESAI_ECR_ERI.
#define BF_ESAI_ECR_ERI(v)   (((v) << BP_ESAI_ECR_ERI) & BM_ESAI_ECR_ERI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ERI field to a new value.
#define BW_ESAI_ECR_ERI(v)   (HW_ESAI_ECR_WR((HW_ESAI_ECR_RD() & ~BM_ESAI_ECR_ERI) | BF_ESAI_ECR_ERI(v)))
#endif


/* --- Register HW_ESAI_ECR, field ETO[18] (RW)
 *
 * EXTAL Transmitter Out. Drive the EXTAL input on the High Frequency Transmitter Clock pin.
 *
 * Values:
 * 0 - HCKT pin has normal function.
 * 1 - EXTAL driven onto HCKT pin.
 */

#define BP_ESAI_ECR_ETO      (18)      //!< Bit position for ESAI_ECR_ETO.
#define BM_ESAI_ECR_ETO      (0x00040000)  //!< Bit mask for ESAI_ECR_ETO.

//! @brief Get value of ESAI_ECR_ETO from a register value.
#define BG_ESAI_ECR_ETO(r)   (((r) & BM_ESAI_ECR_ETO) >> BP_ESAI_ECR_ETO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ECR_ETO.
#define BF_ESAI_ECR_ETO(v)   ((((reg32_t) v) << BP_ESAI_ECR_ETO) & BM_ESAI_ECR_ETO)
#else
//! @brief Format value for bitfield ESAI_ECR_ETO.
#define BF_ESAI_ECR_ETO(v)   (((v) << BP_ESAI_ECR_ETO) & BM_ESAI_ECR_ETO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ETO field to a new value.
#define BW_ESAI_ECR_ETO(v)   (HW_ESAI_ECR_WR((HW_ESAI_ECR_RD() & ~BM_ESAI_ECR_ETO) | BF_ESAI_ECR_ETO(v)))
#endif


/* --- Register HW_ESAI_ECR, field ETI[19] (RW)
 *
 * EXTAL Transmitter In. Mux EXTAL in place of the High Frequency Transmitter Clock input pin. HCKT
 * can still be used to drive a divided down EXTAL or as GPIO.
 *
 * Values:
 * 0 - HCKT pin has normal function.
 * 1 - EXTAL muxed into HCKT input.
 */

#define BP_ESAI_ECR_ETI      (19)      //!< Bit position for ESAI_ECR_ETI.
#define BM_ESAI_ECR_ETI      (0x00080000)  //!< Bit mask for ESAI_ECR_ETI.

//! @brief Get value of ESAI_ECR_ETI from a register value.
#define BG_ESAI_ECR_ETI(r)   (((r) & BM_ESAI_ECR_ETI) >> BP_ESAI_ECR_ETI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_ECR_ETI.
#define BF_ESAI_ECR_ETI(v)   ((((reg32_t) v) << BP_ESAI_ECR_ETI) & BM_ESAI_ECR_ETI)
#else
//! @brief Format value for bitfield ESAI_ECR_ETI.
#define BF_ESAI_ECR_ETI(v)   (((v) << BP_ESAI_ECR_ETI) & BM_ESAI_ECR_ETI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ETI field to a new value.
#define BW_ESAI_ECR_ETI(v)   (HW_ESAI_ECR_WR((HW_ESAI_ECR_RD() & ~BM_ESAI_ECR_ETI) | BF_ESAI_ECR_ETI(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_ESR - ESAI Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_esr
{
    reg32_t U;
    struct _hw_esai_esr_bitfields
    {
        unsigned RD : 1; //!< [0] Receive Data.
        unsigned RED : 1; //!< [1] Receive Even Data.
        unsigned RDE : 1; //!< [2] Receive Data Exception.
        unsigned RLS : 1; //!< [3] Receive Last Slot. Reading this register when RLS is set will negate the Receive Last Slot interrupt.
        unsigned TD : 1; //!< [4] Transmit Data.
        unsigned TED : 1; //!< [5] Transmit Even Data.
        unsigned TDE : 1; //!< [6] Transmit Data Exception.
        unsigned TLS : 1; //!< [7] Transmit Last Slot. Reading this register when TLS is set will negate the Transmit Last Slot interrupt.
        unsigned TFE : 1; //!< [8] Transmit FIFO Empty. Indicates that the number of empty slots in the Transmit FIFO has met or exceeded the Transmit FIFO Watermark. This flag also drives the ESAI Transmitter DMA request line. ESAI FIFO DMA request see .
        unsigned RFF : 1; //!< [9] Receive FIFO Full. Indicates that the number of data words in the Receive FIFO has equaled or exceeded the Receive FIFO Watermark. This flag also drives the ESAI Receiver DMA request line. ESAI FIFO DMA requests see .
        unsigned TINIT : 1; //!< [10] Transmit Initialization. Indicates that the Transmit FIFO is writing the first word for each enabled transmitter into the Transmit Data Registers. This bit sets when the Transmit FIFO is enabled (provided Transmit Initialization is enabled) and clears after the Transmit Data Registers have been initialized. The Transmit Enable bits in the Transmit Control Register should not be set until this flag has cleared.
        unsigned RESERVED0 : 21; //!< [31:11] Reserved
    } B;
} hw_esai_esr_t;
#endif

/*
 * constants & macros for entire ESAI_ESR register
 */
#define HW_ESAI_ESR_ADDR      (REGS_ESAI_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_ESR           (*(volatile hw_esai_esr_t *) HW_ESAI_ESR_ADDR)
#define HW_ESAI_ESR_RD()      (HW_ESAI_ESR.U)
#endif

/*
 * constants & macros for individual ESAI_ESR bitfields
 */

/* --- Register HW_ESAI_ESR, field RD[0] (RO)
 *
 * Receive Data.
 *
 * Values:
 * 0 - RD is not the highest priority active interrupt.
 * 1 - RD is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_RD      (0)      //!< Bit position for ESAI_ESR_RD.
#define BM_ESAI_ESR_RD      (0x00000001)  //!< Bit mask for ESAI_ESR_RD.

//! @brief Get value of ESAI_ESR_RD from a register value.
#define BG_ESAI_ESR_RD(r)   (((r) & BM_ESAI_ESR_RD) >> BP_ESAI_ESR_RD)


/* --- Register HW_ESAI_ESR, field RED[1] (RO)
 *
 * Receive Even Data.
 *
 * Values:
 * 0 - RED is not the highest priority active interrupt.
 * 1 - RED is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_RED      (1)      //!< Bit position for ESAI_ESR_RED.
#define BM_ESAI_ESR_RED      (0x00000002)  //!< Bit mask for ESAI_ESR_RED.

//! @brief Get value of ESAI_ESR_RED from a register value.
#define BG_ESAI_ESR_RED(r)   (((r) & BM_ESAI_ESR_RED) >> BP_ESAI_ESR_RED)


/* --- Register HW_ESAI_ESR, field RDE[2] (RO)
 *
 * Receive Data Exception.
 *
 * Values:
 * 0 - RDE is not the highest priority active interrupt.
 * 1 - RDE is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_RDE      (2)      //!< Bit position for ESAI_ESR_RDE.
#define BM_ESAI_ESR_RDE      (0x00000004)  //!< Bit mask for ESAI_ESR_RDE.

//! @brief Get value of ESAI_ESR_RDE from a register value.
#define BG_ESAI_ESR_RDE(r)   (((r) & BM_ESAI_ESR_RDE) >> BP_ESAI_ESR_RDE)


/* --- Register HW_ESAI_ESR, field RLS[3] (RO)
 *
 * Receive Last Slot. Reading this register when RLS is set will negate the Receive Last Slot
 * interrupt.
 *
 * Values:
 * 0 - RLS is not the highest priority active interrupt.
 * 1 - RLS is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_RLS      (3)      //!< Bit position for ESAI_ESR_RLS.
#define BM_ESAI_ESR_RLS      (0x00000008)  //!< Bit mask for ESAI_ESR_RLS.

//! @brief Get value of ESAI_ESR_RLS from a register value.
#define BG_ESAI_ESR_RLS(r)   (((r) & BM_ESAI_ESR_RLS) >> BP_ESAI_ESR_RLS)


/* --- Register HW_ESAI_ESR, field TD[4] (RO)
 *
 * Transmit Data.
 *
 * Values:
 * 0 - TD is not the highest priority active interrupt.
 * 1 - TD is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_TD      (4)      //!< Bit position for ESAI_ESR_TD.
#define BM_ESAI_ESR_TD      (0x00000010)  //!< Bit mask for ESAI_ESR_TD.

//! @brief Get value of ESAI_ESR_TD from a register value.
#define BG_ESAI_ESR_TD(r)   (((r) & BM_ESAI_ESR_TD) >> BP_ESAI_ESR_TD)


/* --- Register HW_ESAI_ESR, field TED[5] (RO)
 *
 * Transmit Even Data.
 *
 * Values:
 * 0 - TED is not the highest priority active interrupt.
 * 1 - TED is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_TED      (5)      //!< Bit position for ESAI_ESR_TED.
#define BM_ESAI_ESR_TED      (0x00000020)  //!< Bit mask for ESAI_ESR_TED.

//! @brief Get value of ESAI_ESR_TED from a register value.
#define BG_ESAI_ESR_TED(r)   (((r) & BM_ESAI_ESR_TED) >> BP_ESAI_ESR_TED)


/* --- Register HW_ESAI_ESR, field TDE[6] (RO)
 *
 * Transmit Data Exception.
 *
 * Values:
 * 0 - TDE is not the highest priority active interrupt.
 * 1 - TDE is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_TDE      (6)      //!< Bit position for ESAI_ESR_TDE.
#define BM_ESAI_ESR_TDE      (0x00000040)  //!< Bit mask for ESAI_ESR_TDE.

//! @brief Get value of ESAI_ESR_TDE from a register value.
#define BG_ESAI_ESR_TDE(r)   (((r) & BM_ESAI_ESR_TDE) >> BP_ESAI_ESR_TDE)


/* --- Register HW_ESAI_ESR, field TLS[7] (RO)
 *
 * Transmit Last Slot. Reading this register when TLS is set will negate the Transmit Last Slot
 * interrupt.
 *
 * Values:
 * 0 - TLS is not the highest priority active interrupt.
 * 1 - TLS is the highest priority active interrupt.
 */

#define BP_ESAI_ESR_TLS      (7)      //!< Bit position for ESAI_ESR_TLS.
#define BM_ESAI_ESR_TLS      (0x00000080)  //!< Bit mask for ESAI_ESR_TLS.

//! @brief Get value of ESAI_ESR_TLS from a register value.
#define BG_ESAI_ESR_TLS(r)   (((r) & BM_ESAI_ESR_TLS) >> BP_ESAI_ESR_TLS)


/* --- Register HW_ESAI_ESR, field TFE[8] (RO)
 *
 * Transmit FIFO Empty. Indicates that the number of empty slots in the Transmit FIFO has met or
 * exceeded the Transmit FIFO Watermark. This flag also drives the ESAI Transmitter DMA request
 * line. ESAI FIFO DMA request see .
 *
 * Values:
 * 0 - Number of empty slots in Transmit FIFO less than Transmit FIFO watermark.
 * 1 - Number of empty slots in Transmit FIFO is equal to or greater than Transmit FIFO watermark.
 */

#define BP_ESAI_ESR_TFE      (8)      //!< Bit position for ESAI_ESR_TFE.
#define BM_ESAI_ESR_TFE      (0x00000100)  //!< Bit mask for ESAI_ESR_TFE.

//! @brief Get value of ESAI_ESR_TFE from a register value.
#define BG_ESAI_ESR_TFE(r)   (((r) & BM_ESAI_ESR_TFE) >> BP_ESAI_ESR_TFE)


/* --- Register HW_ESAI_ESR, field RFF[9] (RO)
 *
 * Receive FIFO Full. Indicates that the number of data words in the Receive FIFO has equaled or
 * exceeded the Receive FIFO Watermark. This flag also drives the ESAI Receiver DMA request line.
 * ESAI FIFO DMA requests see .
 *
 * Values:
 * 0 - Number of words in Receive FIFO less than Receive FIFO watermark.
 * 1 - Number of words in Receive FIFO is equal to or greater than Receive FIFO watermark.
 */

#define BP_ESAI_ESR_RFF      (9)      //!< Bit position for ESAI_ESR_RFF.
#define BM_ESAI_ESR_RFF      (0x00000200)  //!< Bit mask for ESAI_ESR_RFF.

//! @brief Get value of ESAI_ESR_RFF from a register value.
#define BG_ESAI_ESR_RFF(r)   (((r) & BM_ESAI_ESR_RFF) >> BP_ESAI_ESR_RFF)


/* --- Register HW_ESAI_ESR, field TINIT[10] (RO)
 *
 * Transmit Initialization. Indicates that the Transmit FIFO is writing the first word for each
 * enabled transmitter into the Transmit Data Registers. This bit sets when the Transmit FIFO is
 * enabled (provided Transmit Initialization is enabled) and clears after the Transmit Data
 * Registers have been initialized. The Transmit Enable bits in the Transmit Control Register should
 * not be set until this flag has cleared.
 *
 * Values:
 * 0 - Transmitter has finished initializing the Transmit Data Registers (or Transmit FIFO is not enabled
 *     or Transmit Initialization is not enabled).
 * 1 - Transmitter has not finished initializing the Transmit Data Registers.
 */

#define BP_ESAI_ESR_TINIT      (10)      //!< Bit position for ESAI_ESR_TINIT.
#define BM_ESAI_ESR_TINIT      (0x00000400)  //!< Bit mask for ESAI_ESR_TINIT.

//! @brief Get value of ESAI_ESR_TINIT from a register value.
#define BG_ESAI_ESR_TINIT(r)   (((r) & BM_ESAI_ESR_TINIT) >> BP_ESAI_ESR_TINIT)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TFCR - Transmit FIFO Configuration Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_tfcr
{
    reg32_t U;
    struct _hw_esai_tfcr_bitfields
    {
        unsigned TFE : 1; //!< [0] Transmit FIFO Enable. This bit enables the use of the Transmit FIFO.
        unsigned TFR : 1; //!< [1] Transmit FIFO Reset. This bit resets the Transmit FIFO pointers.
        unsigned TE0 : 1; //!< [2] Transmitter #0 FIFO Enable. This bit enables transmitter #0 to use the Transmit FIFO. Do not change this bit when the Transmitter FIFO is enabled.
        unsigned TE1 : 1; //!< [3] Transmitter #1 FIFO Enable. This bit enables transmitter #1 to use the Transmit FIFO. Do not change this bit when the Transmitter FIFO is enabled.
        unsigned TE2 : 1; //!< [4] Transmitter #2 FIFO Enable. This bit enables transmitter #2 to use the Transmit FIFO. Do not change this bit when the Transmitter FIFO is enabled.
        unsigned TE3 : 1; //!< [5] Transmitter #3 FIFO Enable. This bit enables transmitter #3 to use the Transmit FIFO. Do not change this bit when the Transmitter FIFO is enabled.
        unsigned TE4 : 1; //!< [6] Transmitter #4 FIFO Enable. This bit enables transmitter #4 to use the Transmit FIFO. Do not change this bit when the Transmitter FIFO is enabled.
        unsigned TE5 : 1; //!< [7] Transmitter #5 FIFO Enable. This bit enables transmitter #5 to use the Transmit FIFO. Do not change this bit when the Transmitter FIFO is enabled.
        unsigned TFWM : 8; //!< [15:8] Transmit FIFO Watermark. These bits configure the threshold at which the Transmit FIFO Empty flag will set. The TFE is set when the number of empty slots in the Transmit FIFO equal or exceed the selected threshold.
        unsigned TWA : 3; //!< [18:16] Transmit Word Alignment. Configures the alignment of the data written into the ESAI Transmit Data Register and then passed to the relevant 24 bit Transmit shift register.
        unsigned TIEN : 1; //!< [19] Transmitter Initialization Enable. Enables the initialization of the Transmit Data Registers when the Transmitter FIFO is enabled.
        unsigned RESERVED0 : 12; //!< [31:20] Reserved
    } B;
} hw_esai_tfcr_t;
#endif

/*
 * constants & macros for entire ESAI_TFCR register
 */
#define HW_ESAI_TFCR_ADDR      (REGS_ESAI_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TFCR           (*(volatile hw_esai_tfcr_t *) HW_ESAI_TFCR_ADDR)
#define HW_ESAI_TFCR_RD()      (HW_ESAI_TFCR.U)
#define HW_ESAI_TFCR_WR(v)     (HW_ESAI_TFCR.U = (v))
#define HW_ESAI_TFCR_SET(v)    (HW_ESAI_TFCR_WR(HW_ESAI_TFCR_RD() |  (v)))
#define HW_ESAI_TFCR_CLR(v)    (HW_ESAI_TFCR_WR(HW_ESAI_TFCR_RD() & ~(v)))
#define HW_ESAI_TFCR_TOG(v)    (HW_ESAI_TFCR_WR(HW_ESAI_TFCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_TFCR bitfields
 */

/* --- Register HW_ESAI_TFCR, field TFE[0] (RW)
 *
 * Transmit FIFO Enable. This bit enables the use of the Transmit FIFO.
 *
 * Values:
 * 0 - Transmit FIFO disabled.
 * 1 - Transmit FIFO enabled.
 */

#define BP_ESAI_TFCR_TFE      (0)      //!< Bit position for ESAI_TFCR_TFE.
#define BM_ESAI_TFCR_TFE      (0x00000001)  //!< Bit mask for ESAI_TFCR_TFE.

//! @brief Get value of ESAI_TFCR_TFE from a register value.
#define BG_ESAI_TFCR_TFE(r)   (((r) & BM_ESAI_TFCR_TFE) >> BP_ESAI_TFCR_TFE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TFE.
#define BF_ESAI_TFCR_TFE(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TFE) & BM_ESAI_TFCR_TFE)
#else
//! @brief Format value for bitfield ESAI_TFCR_TFE.
#define BF_ESAI_TFCR_TFE(v)   (((v) << BP_ESAI_TFCR_TFE) & BM_ESAI_TFCR_TFE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFE field to a new value.
#define BW_ESAI_TFCR_TFE(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TFE) | BF_ESAI_TFCR_TFE(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TFR[1] (RW)
 *
 * Transmit FIFO Reset. This bit resets the Transmit FIFO pointers.
 *
 * Values:
 * 0 - Transmit FIFO not reset.
 * 1 - Transmit FIFO reset.
 */

#define BP_ESAI_TFCR_TFR      (1)      //!< Bit position for ESAI_TFCR_TFR.
#define BM_ESAI_TFCR_TFR      (0x00000002)  //!< Bit mask for ESAI_TFCR_TFR.

//! @brief Get value of ESAI_TFCR_TFR from a register value.
#define BG_ESAI_TFCR_TFR(r)   (((r) & BM_ESAI_TFCR_TFR) >> BP_ESAI_TFCR_TFR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TFR.
#define BF_ESAI_TFCR_TFR(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TFR) & BM_ESAI_TFCR_TFR)
#else
//! @brief Format value for bitfield ESAI_TFCR_TFR.
#define BF_ESAI_TFCR_TFR(v)   (((v) << BP_ESAI_TFCR_TFR) & BM_ESAI_TFCR_TFR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFR field to a new value.
#define BW_ESAI_TFCR_TFR(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TFR) | BF_ESAI_TFCR_TFR(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TE0[2] (RW)
 *
 * Transmitter #0 FIFO Enable. This bit enables transmitter #0 to use the Transmit FIFO. Do not
 * change this bit when the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmitter #0 is not using the Transmit FIFO.
 * 1 - Transmitter #0 is using the Transmit FIFO.
 */

#define BP_ESAI_TFCR_TE0      (2)      //!< Bit position for ESAI_TFCR_TE0.
#define BM_ESAI_TFCR_TE0      (0x00000004)  //!< Bit mask for ESAI_TFCR_TE0.

//! @brief Get value of ESAI_TFCR_TE0 from a register value.
#define BG_ESAI_TFCR_TE0(r)   (((r) & BM_ESAI_TFCR_TE0) >> BP_ESAI_TFCR_TE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TE0.
#define BF_ESAI_TFCR_TE0(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TE0) & BM_ESAI_TFCR_TE0)
#else
//! @brief Format value for bitfield ESAI_TFCR_TE0.
#define BF_ESAI_TFCR_TE0(v)   (((v) << BP_ESAI_TFCR_TE0) & BM_ESAI_TFCR_TE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE0 field to a new value.
#define BW_ESAI_TFCR_TE0(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TE0) | BF_ESAI_TFCR_TE0(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TE1[3] (RW)
 *
 * Transmitter #1 FIFO Enable. This bit enables transmitter #1 to use the Transmit FIFO. Do not
 * change this bit when the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmitter #1 is not using the Transmit FIFO.
 * 1 - Transmitter #1 is using the Transmit FIFO.
 */

#define BP_ESAI_TFCR_TE1      (3)      //!< Bit position for ESAI_TFCR_TE1.
#define BM_ESAI_TFCR_TE1      (0x00000008)  //!< Bit mask for ESAI_TFCR_TE1.

//! @brief Get value of ESAI_TFCR_TE1 from a register value.
#define BG_ESAI_TFCR_TE1(r)   (((r) & BM_ESAI_TFCR_TE1) >> BP_ESAI_TFCR_TE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TE1.
#define BF_ESAI_TFCR_TE1(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TE1) & BM_ESAI_TFCR_TE1)
#else
//! @brief Format value for bitfield ESAI_TFCR_TE1.
#define BF_ESAI_TFCR_TE1(v)   (((v) << BP_ESAI_TFCR_TE1) & BM_ESAI_TFCR_TE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE1 field to a new value.
#define BW_ESAI_TFCR_TE1(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TE1) | BF_ESAI_TFCR_TE1(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TE2[4] (RW)
 *
 * Transmitter #2 FIFO Enable. This bit enables transmitter #2 to use the Transmit FIFO. Do not
 * change this bit when the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmitter #2 is not using the Transmit FIFO.
 * 1 - Transmitter #2 is using the Transmit FIFO.
 */

#define BP_ESAI_TFCR_TE2      (4)      //!< Bit position for ESAI_TFCR_TE2.
#define BM_ESAI_TFCR_TE2      (0x00000010)  //!< Bit mask for ESAI_TFCR_TE2.

//! @brief Get value of ESAI_TFCR_TE2 from a register value.
#define BG_ESAI_TFCR_TE2(r)   (((r) & BM_ESAI_TFCR_TE2) >> BP_ESAI_TFCR_TE2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TE2.
#define BF_ESAI_TFCR_TE2(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TE2) & BM_ESAI_TFCR_TE2)
#else
//! @brief Format value for bitfield ESAI_TFCR_TE2.
#define BF_ESAI_TFCR_TE2(v)   (((v) << BP_ESAI_TFCR_TE2) & BM_ESAI_TFCR_TE2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE2 field to a new value.
#define BW_ESAI_TFCR_TE2(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TE2) | BF_ESAI_TFCR_TE2(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TE3[5] (RW)
 *
 * Transmitter #3 FIFO Enable. This bit enables transmitter #3 to use the Transmit FIFO. Do not
 * change this bit when the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmitter #3 is not using the Transmit FIFO.
 * 1 - Transmitter #3 is using the Transmit FIFO.
 */

#define BP_ESAI_TFCR_TE3      (5)      //!< Bit position for ESAI_TFCR_TE3.
#define BM_ESAI_TFCR_TE3      (0x00000020)  //!< Bit mask for ESAI_TFCR_TE3.

//! @brief Get value of ESAI_TFCR_TE3 from a register value.
#define BG_ESAI_TFCR_TE3(r)   (((r) & BM_ESAI_TFCR_TE3) >> BP_ESAI_TFCR_TE3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TE3.
#define BF_ESAI_TFCR_TE3(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TE3) & BM_ESAI_TFCR_TE3)
#else
//! @brief Format value for bitfield ESAI_TFCR_TE3.
#define BF_ESAI_TFCR_TE3(v)   (((v) << BP_ESAI_TFCR_TE3) & BM_ESAI_TFCR_TE3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE3 field to a new value.
#define BW_ESAI_TFCR_TE3(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TE3) | BF_ESAI_TFCR_TE3(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TE4[6] (RW)
 *
 * Transmitter #4 FIFO Enable. This bit enables transmitter #4 to use the Transmit FIFO. Do not
 * change this bit when the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmitter #4 is not using the Transmit FIFO.
 * 1 - Transmitter #4 is using the Transmit FIFO.
 */

#define BP_ESAI_TFCR_TE4      (6)      //!< Bit position for ESAI_TFCR_TE4.
#define BM_ESAI_TFCR_TE4      (0x00000040)  //!< Bit mask for ESAI_TFCR_TE4.

//! @brief Get value of ESAI_TFCR_TE4 from a register value.
#define BG_ESAI_TFCR_TE4(r)   (((r) & BM_ESAI_TFCR_TE4) >> BP_ESAI_TFCR_TE4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TE4.
#define BF_ESAI_TFCR_TE4(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TE4) & BM_ESAI_TFCR_TE4)
#else
//! @brief Format value for bitfield ESAI_TFCR_TE4.
#define BF_ESAI_TFCR_TE4(v)   (((v) << BP_ESAI_TFCR_TE4) & BM_ESAI_TFCR_TE4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE4 field to a new value.
#define BW_ESAI_TFCR_TE4(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TE4) | BF_ESAI_TFCR_TE4(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TE5[7] (RW)
 *
 * Transmitter #5 FIFO Enable. This bit enables transmitter #5 to use the Transmit FIFO. Do not
 * change this bit when the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmitter #5 is not using the Transmit FIFO.
 * 1 - Transmitter #5 is using the Transmit FIFO.
 */

#define BP_ESAI_TFCR_TE5      (7)      //!< Bit position for ESAI_TFCR_TE5.
#define BM_ESAI_TFCR_TE5      (0x00000080)  //!< Bit mask for ESAI_TFCR_TE5.

//! @brief Get value of ESAI_TFCR_TE5 from a register value.
#define BG_ESAI_TFCR_TE5(r)   (((r) & BM_ESAI_TFCR_TE5) >> BP_ESAI_TFCR_TE5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TE5.
#define BF_ESAI_TFCR_TE5(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TE5) & BM_ESAI_TFCR_TE5)
#else
//! @brief Format value for bitfield ESAI_TFCR_TE5.
#define BF_ESAI_TFCR_TE5(v)   (((v) << BP_ESAI_TFCR_TE5) & BM_ESAI_TFCR_TE5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE5 field to a new value.
#define BW_ESAI_TFCR_TE5(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TE5) | BF_ESAI_TFCR_TE5(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TFWM[15:8] (RW)
 *
 * Transmit FIFO Watermark. These bits configure the threshold at which the Transmit FIFO Empty flag
 * will set. The TFE is set when the number of empty slots in the Transmit FIFO equal or exceed the
 * selected threshold.
 */

#define BP_ESAI_TFCR_TFWM      (8)      //!< Bit position for ESAI_TFCR_TFWM.
#define BM_ESAI_TFCR_TFWM      (0x0000ff00)  //!< Bit mask for ESAI_TFCR_TFWM.

//! @brief Get value of ESAI_TFCR_TFWM from a register value.
#define BG_ESAI_TFCR_TFWM(r)   (((r) & BM_ESAI_TFCR_TFWM) >> BP_ESAI_TFCR_TFWM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TFWM.
#define BF_ESAI_TFCR_TFWM(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TFWM) & BM_ESAI_TFCR_TFWM)
#else
//! @brief Format value for bitfield ESAI_TFCR_TFWM.
#define BF_ESAI_TFCR_TFWM(v)   (((v) << BP_ESAI_TFCR_TFWM) & BM_ESAI_TFCR_TFWM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFWM field to a new value.
#define BW_ESAI_TFCR_TFWM(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TFWM) | BF_ESAI_TFCR_TFWM(v)))
#endif

/* --- Register HW_ESAI_TFCR, field TWA[18:16] (RW)
 *
 * Transmit Word Alignment. Configures the alignment of the data written into the ESAI Transmit Data
 * Register and then passed to the relevant 24 bit Transmit shift register.
 *
 * Values:
 * 000 - MSB of data is bit 31. Data bits 7-0 are ignored when passed to transmit shift register.
 * 001 - MSB of data is bit 27. Data bits 3-0 are ignored when passed to transmit shift register.
 * 010 - MSB of data is bit 23.
 * 011 - MSB of data is bit 19. Bottom 4 bits of transmit shift register are zeroed.
 * 100 - MSB of data is bit 15. Bottom 8 bits of transmit shift register are zeroed.
 * 101 - MSB of data is bit 11. Bottom 12 bits of transmit shift register are zeroed.
 * 110 - MSB of data is bit 7. Bottom 16 bits of transmit shift register are zeroed.
 * 111 - MSB of data is bit 3. Bottom 20 bits of transmit shift register are zeroed.
 */

#define BP_ESAI_TFCR_TWA      (16)      //!< Bit position for ESAI_TFCR_TWA.
#define BM_ESAI_TFCR_TWA      (0x00070000)  //!< Bit mask for ESAI_TFCR_TWA.

//! @brief Get value of ESAI_TFCR_TWA from a register value.
#define BG_ESAI_TFCR_TWA(r)   (((r) & BM_ESAI_TFCR_TWA) >> BP_ESAI_TFCR_TWA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TWA.
#define BF_ESAI_TFCR_TWA(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TWA) & BM_ESAI_TFCR_TWA)
#else
//! @brief Format value for bitfield ESAI_TFCR_TWA.
#define BF_ESAI_TFCR_TWA(v)   (((v) << BP_ESAI_TFCR_TWA) & BM_ESAI_TFCR_TWA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TWA field to a new value.
#define BW_ESAI_TFCR_TWA(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TWA) | BF_ESAI_TFCR_TWA(v)))
#endif


/* --- Register HW_ESAI_TFCR, field TIEN[19] (RW)
 *
 * Transmitter Initialization Enable. Enables the initialization of the Transmit Data Registers when
 * the Transmitter FIFO is enabled.
 *
 * Values:
 * 0 - Transmit Data Registers are not initialized from the FIFO once the Transmit FIFO is enabled.
 *     Software must manually initialize the Transmit Data Registers separately.
 * 1 - Transmit Data Registers are initialized from the FIFO once the Transmit FIFO is enabled.
 */

#define BP_ESAI_TFCR_TIEN      (19)      //!< Bit position for ESAI_TFCR_TIEN.
#define BM_ESAI_TFCR_TIEN      (0x00080000)  //!< Bit mask for ESAI_TFCR_TIEN.

//! @brief Get value of ESAI_TFCR_TIEN from a register value.
#define BG_ESAI_TFCR_TIEN(r)   (((r) & BM_ESAI_TFCR_TIEN) >> BP_ESAI_TFCR_TIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TFCR_TIEN.
#define BF_ESAI_TFCR_TIEN(v)   ((((reg32_t) v) << BP_ESAI_TFCR_TIEN) & BM_ESAI_TFCR_TIEN)
#else
//! @brief Format value for bitfield ESAI_TFCR_TIEN.
#define BF_ESAI_TFCR_TIEN(v)   (((v) << BP_ESAI_TFCR_TIEN) & BM_ESAI_TFCR_TIEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIEN field to a new value.
#define BW_ESAI_TFCR_TIEN(v)   (HW_ESAI_TFCR_WR((HW_ESAI_TFCR_RD() & ~BM_ESAI_TFCR_TIEN) | BF_ESAI_TFCR_TIEN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TFSR - Transmit FIFO Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_tfsr
{
    reg32_t U;
    struct _hw_esai_tfsr_bitfields
    {
        unsigned TFCNT : 8; //!< [7:0] Transmit FIFO Counter. These bits indicate the number of data words stored in the Transmit FIFO.
        unsigned NTFI : 3; //!< [10:8] Next Transmitter FIFO In. Indicates which transmitter receives the next word written to the FIFO.
        unsigned RESERVED0 : 1; //!< [11] Reserved
        unsigned NTFO : 3; //!< [14:12] Next Transmitter FIFO Out. Indicates which Transmit Data Register receives the top word of the Transmit FIFO. This will usually equal the lowest enabled transmitter, unless the transmit FIFO is empty.
        unsigned RESERVED1 : 17; //!< [31:15] Reserved
    } B;
} hw_esai_tfsr_t;
#endif

/*
 * constants & macros for entire ESAI_TFSR register
 */
#define HW_ESAI_TFSR_ADDR      (REGS_ESAI_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TFSR           (*(volatile hw_esai_tfsr_t *) HW_ESAI_TFSR_ADDR)
#define HW_ESAI_TFSR_RD()      (HW_ESAI_TFSR.U)
#endif

/*
 * constants & macros for individual ESAI_TFSR bitfields
 */

/* --- Register HW_ESAI_TFSR, field TFCNT[7:0] (RO)
 *
 * Transmit FIFO Counter. These bits indicate the number of data words stored in the Transmit FIFO.
 */

#define BP_ESAI_TFSR_TFCNT      (0)      //!< Bit position for ESAI_TFSR_TFCNT.
#define BM_ESAI_TFSR_TFCNT      (0x000000ff)  //!< Bit mask for ESAI_TFSR_TFCNT.

//! @brief Get value of ESAI_TFSR_TFCNT from a register value.
#define BG_ESAI_TFSR_TFCNT(r)   (((r) & BM_ESAI_TFSR_TFCNT) >> BP_ESAI_TFSR_TFCNT)

/* --- Register HW_ESAI_TFSR, field NTFI[10:8] (RO)
 *
 * Next Transmitter FIFO In. Indicates which transmitter receives the next word written to the FIFO.
 *
 * Values:
 * 000 - Transmitter #0 receives next word written to the Transmit FIFO.
 * 001 - Transmitter #1 receives next word written to the Transmit FIFO.
 * 010 - Transmitter #2 receives next word written to the Transmit FIFO.
 * 011 - Transmitter #3 receives next word written to the Transmit FIFO.
 * 100 - Transmitter #4 receives next word written to the Transmit FIFO.
 * 101 - Transmitter #5 receives next word written to the Transmit FIFO.
 * 110 - Reserved.
 * 111 - Reserved.
 */

#define BP_ESAI_TFSR_NTFI      (8)      //!< Bit position for ESAI_TFSR_NTFI.
#define BM_ESAI_TFSR_NTFI      (0x00000700)  //!< Bit mask for ESAI_TFSR_NTFI.

//! @brief Get value of ESAI_TFSR_NTFI from a register value.
#define BG_ESAI_TFSR_NTFI(r)   (((r) & BM_ESAI_TFSR_NTFI) >> BP_ESAI_TFSR_NTFI)


/* --- Register HW_ESAI_TFSR, field NTFO[14:12] (RO)
 *
 * Next Transmitter FIFO Out. Indicates which Transmit Data Register receives the top word of the
 * Transmit FIFO. This will usually equal the lowest enabled transmitter, unless the transmit FIFO
 * is empty.
 *
 * Values:
 * 000 - Transmitter #0 receives next word from the Transmit FIFO.
 * 001 - Transmitter #1 receives next word from the Transmit FIFO.
 * 010 - Transmitter #2 receives next word from the Transmit FIFO.
 * 011 - Transmitter #3 receives next word from the Transmit FIFO.
 * 100 - Transmitter #4 receives next word from the Transmit FIFO.
 * 101 - Transmitter #5 receives next word from the Transmit FIFO.
 * 110 - Reserved.
 * 111 - Reserved.
 */

#define BP_ESAI_TFSR_NTFO      (12)      //!< Bit position for ESAI_TFSR_NTFO.
#define BM_ESAI_TFSR_NTFO      (0x00007000)  //!< Bit mask for ESAI_TFSR_NTFO.

//! @brief Get value of ESAI_TFSR_NTFO from a register value.
#define BG_ESAI_TFSR_NTFO(r)   (((r) & BM_ESAI_TFSR_NTFO) >> BP_ESAI_TFSR_NTFO)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RFCR - Receive FIFO Configuration Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_rfcr
{
    reg32_t U;
    struct _hw_esai_rfcr_bitfields
    {
        unsigned RFE : 1; //!< [0] Receive FIFO Enable. This bit enables the use of the Receive FIFO.
        unsigned RFR : 1; //!< [1] Receive FIFO Reset. This bit resets the Receive FIFO pointers.
        unsigned RE0 : 1; //!< [2] Receiver #0 FIFO Enable. This bit enables receiver #0 to use the Receive FIFO. Do not change this bit when the Receiver FIFO is enabled.
        unsigned RE1 : 1; //!< [3] Receiver #1 FIFO Enable. This bit enables receiver #1 to use the Receive FIFO. Do not change this bit when the Receiver FIFO is enabled.
        unsigned RE2 : 1; //!< [4] Receiver #2 FIFO Enable. This bit enables receiver #2 to use the Receive FIFO. Do not change this bit when the Receiver FIFO is enabled.
        unsigned RE3 : 1; //!< [5] Receiver #3 FIFO Enable. This bit enables receiver #3 to use the Receive FIFO. Do not change this bit when the Receiver FIFO is enabled.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved
        unsigned RFWM : 8; //!< [15:8] Receive FIFO Watermark. These bits configure the threshold at which the Receive FIFO Full flag will set. The RFF is set when the number of words in the Receive FIFO equal or exceed the selected threshold. It can be set to a non-zero value.
        unsigned RWA : 3; //!< [18:16] Receive Word Alignment. Configures the alignment of the data passed from the relevant 24 bit Receive shift register and read out the ESAI Receive Data Register.
        unsigned REXT : 1; //!< [19] Receive Extension. Enables the receive data to be returned sign extended when the Receive Word Alignment is configured to return data where the MSB is not aligned with bit 31.
        unsigned RESERVED1 : 12; //!< [31:20] Reserved
    } B;
} hw_esai_rfcr_t;
#endif

/*
 * constants & macros for entire ESAI_RFCR register
 */
#define HW_ESAI_RFCR_ADDR      (REGS_ESAI_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RFCR           (*(volatile hw_esai_rfcr_t *) HW_ESAI_RFCR_ADDR)
#define HW_ESAI_RFCR_RD()      (HW_ESAI_RFCR.U)
#define HW_ESAI_RFCR_WR(v)     (HW_ESAI_RFCR.U = (v))
#define HW_ESAI_RFCR_SET(v)    (HW_ESAI_RFCR_WR(HW_ESAI_RFCR_RD() |  (v)))
#define HW_ESAI_RFCR_CLR(v)    (HW_ESAI_RFCR_WR(HW_ESAI_RFCR_RD() & ~(v)))
#define HW_ESAI_RFCR_TOG(v)    (HW_ESAI_RFCR_WR(HW_ESAI_RFCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_RFCR bitfields
 */

/* --- Register HW_ESAI_RFCR, field RFE[0] (RW)
 *
 * Receive FIFO Enable. This bit enables the use of the Receive FIFO.
 *
 * Values:
 * 0 - Receive FIFO disabled.
 * 1 - Receive FIFO enabled.
 */

#define BP_ESAI_RFCR_RFE      (0)      //!< Bit position for ESAI_RFCR_RFE.
#define BM_ESAI_RFCR_RFE      (0x00000001)  //!< Bit mask for ESAI_RFCR_RFE.

//! @brief Get value of ESAI_RFCR_RFE from a register value.
#define BG_ESAI_RFCR_RFE(r)   (((r) & BM_ESAI_RFCR_RFE) >> BP_ESAI_RFCR_RFE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RFE.
#define BF_ESAI_RFCR_RFE(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RFE) & BM_ESAI_RFCR_RFE)
#else
//! @brief Format value for bitfield ESAI_RFCR_RFE.
#define BF_ESAI_RFCR_RFE(v)   (((v) << BP_ESAI_RFCR_RFE) & BM_ESAI_RFCR_RFE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFE field to a new value.
#define BW_ESAI_RFCR_RFE(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RFE) | BF_ESAI_RFCR_RFE(v)))
#endif


/* --- Register HW_ESAI_RFCR, field RFR[1] (RW)
 *
 * Receive FIFO Reset. This bit resets the Receive FIFO pointers.
 *
 * Values:
 * 0 - Receive FIFO not reset.
 * 1 - Receive FIFO reset.
 */

#define BP_ESAI_RFCR_RFR      (1)      //!< Bit position for ESAI_RFCR_RFR.
#define BM_ESAI_RFCR_RFR      (0x00000002)  //!< Bit mask for ESAI_RFCR_RFR.

//! @brief Get value of ESAI_RFCR_RFR from a register value.
#define BG_ESAI_RFCR_RFR(r)   (((r) & BM_ESAI_RFCR_RFR) >> BP_ESAI_RFCR_RFR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RFR.
#define BF_ESAI_RFCR_RFR(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RFR) & BM_ESAI_RFCR_RFR)
#else
//! @brief Format value for bitfield ESAI_RFCR_RFR.
#define BF_ESAI_RFCR_RFR(v)   (((v) << BP_ESAI_RFCR_RFR) & BM_ESAI_RFCR_RFR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFR field to a new value.
#define BW_ESAI_RFCR_RFR(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RFR) | BF_ESAI_RFCR_RFR(v)))
#endif


/* --- Register HW_ESAI_RFCR, field RE0[2] (RW)
 *
 * Receiver #0 FIFO Enable. This bit enables receiver #0 to use the Receive FIFO. Do not change this
 * bit when the Receiver FIFO is enabled.
 *
 * Values:
 * 0 - Receiver #0 is not using the Receive FIFO.
 * 1 - Receiver #0 is using the Receive FIFO.
 */

#define BP_ESAI_RFCR_RE0      (2)      //!< Bit position for ESAI_RFCR_RE0.
#define BM_ESAI_RFCR_RE0      (0x00000004)  //!< Bit mask for ESAI_RFCR_RE0.

//! @brief Get value of ESAI_RFCR_RE0 from a register value.
#define BG_ESAI_RFCR_RE0(r)   (((r) & BM_ESAI_RFCR_RE0) >> BP_ESAI_RFCR_RE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RE0.
#define BF_ESAI_RFCR_RE0(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RE0) & BM_ESAI_RFCR_RE0)
#else
//! @brief Format value for bitfield ESAI_RFCR_RE0.
#define BF_ESAI_RFCR_RE0(v)   (((v) << BP_ESAI_RFCR_RE0) & BM_ESAI_RFCR_RE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE0 field to a new value.
#define BW_ESAI_RFCR_RE0(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RE0) | BF_ESAI_RFCR_RE0(v)))
#endif


/* --- Register HW_ESAI_RFCR, field RE1[3] (RW)
 *
 * Receiver #1 FIFO Enable. This bit enables receiver #1 to use the Receive FIFO. Do not change this
 * bit when the Receiver FIFO is enabled.
 *
 * Values:
 * 0 - Receiver #1 is not using the Receive FIFO.
 * 1 - Receiver #1 is using the Receive FIFO.
 */

#define BP_ESAI_RFCR_RE1      (3)      //!< Bit position for ESAI_RFCR_RE1.
#define BM_ESAI_RFCR_RE1      (0x00000008)  //!< Bit mask for ESAI_RFCR_RE1.

//! @brief Get value of ESAI_RFCR_RE1 from a register value.
#define BG_ESAI_RFCR_RE1(r)   (((r) & BM_ESAI_RFCR_RE1) >> BP_ESAI_RFCR_RE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RE1.
#define BF_ESAI_RFCR_RE1(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RE1) & BM_ESAI_RFCR_RE1)
#else
//! @brief Format value for bitfield ESAI_RFCR_RE1.
#define BF_ESAI_RFCR_RE1(v)   (((v) << BP_ESAI_RFCR_RE1) & BM_ESAI_RFCR_RE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE1 field to a new value.
#define BW_ESAI_RFCR_RE1(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RE1) | BF_ESAI_RFCR_RE1(v)))
#endif


/* --- Register HW_ESAI_RFCR, field RE2[4] (RW)
 *
 * Receiver #2 FIFO Enable. This bit enables receiver #2 to use the Receive FIFO. Do not change this
 * bit when the Receiver FIFO is enabled.
 *
 * Values:
 * 0 - Receiver #2 is not using the Receive FIFO.
 * 1 - Receiver #2 is using the Receive FIFO.
 */

#define BP_ESAI_RFCR_RE2      (4)      //!< Bit position for ESAI_RFCR_RE2.
#define BM_ESAI_RFCR_RE2      (0x00000010)  //!< Bit mask for ESAI_RFCR_RE2.

//! @brief Get value of ESAI_RFCR_RE2 from a register value.
#define BG_ESAI_RFCR_RE2(r)   (((r) & BM_ESAI_RFCR_RE2) >> BP_ESAI_RFCR_RE2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RE2.
#define BF_ESAI_RFCR_RE2(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RE2) & BM_ESAI_RFCR_RE2)
#else
//! @brief Format value for bitfield ESAI_RFCR_RE2.
#define BF_ESAI_RFCR_RE2(v)   (((v) << BP_ESAI_RFCR_RE2) & BM_ESAI_RFCR_RE2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE2 field to a new value.
#define BW_ESAI_RFCR_RE2(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RE2) | BF_ESAI_RFCR_RE2(v)))
#endif


/* --- Register HW_ESAI_RFCR, field RE3[5] (RW)
 *
 * Receiver #3 FIFO Enable. This bit enables receiver #3 to use the Receive FIFO. Do not change this
 * bit when the Receiver FIFO is enabled.
 *
 * Values:
 * 0 - Receiver #3 is not using the Receive FIFO.
 * 1 - Receiver #3 is using the Receive FIFO.
 */

#define BP_ESAI_RFCR_RE3      (5)      //!< Bit position for ESAI_RFCR_RE3.
#define BM_ESAI_RFCR_RE3      (0x00000020)  //!< Bit mask for ESAI_RFCR_RE3.

//! @brief Get value of ESAI_RFCR_RE3 from a register value.
#define BG_ESAI_RFCR_RE3(r)   (((r) & BM_ESAI_RFCR_RE3) >> BP_ESAI_RFCR_RE3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RE3.
#define BF_ESAI_RFCR_RE3(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RE3) & BM_ESAI_RFCR_RE3)
#else
//! @brief Format value for bitfield ESAI_RFCR_RE3.
#define BF_ESAI_RFCR_RE3(v)   (((v) << BP_ESAI_RFCR_RE3) & BM_ESAI_RFCR_RE3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE3 field to a new value.
#define BW_ESAI_RFCR_RE3(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RE3) | BF_ESAI_RFCR_RE3(v)))
#endif


/* --- Register HW_ESAI_RFCR, field RFWM[15:8] (RW)
 *
 * Receive FIFO Watermark. These bits configure the threshold at which the Receive FIFO Full flag
 * will set. The RFF is set when the number of words in the Receive FIFO equal or exceed the
 * selected threshold. It can be set to a non-zero value.
 */

#define BP_ESAI_RFCR_RFWM      (8)      //!< Bit position for ESAI_RFCR_RFWM.
#define BM_ESAI_RFCR_RFWM      (0x0000ff00)  //!< Bit mask for ESAI_RFCR_RFWM.

//! @brief Get value of ESAI_RFCR_RFWM from a register value.
#define BG_ESAI_RFCR_RFWM(r)   (((r) & BM_ESAI_RFCR_RFWM) >> BP_ESAI_RFCR_RFWM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RFWM.
#define BF_ESAI_RFCR_RFWM(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RFWM) & BM_ESAI_RFCR_RFWM)
#else
//! @brief Format value for bitfield ESAI_RFCR_RFWM.
#define BF_ESAI_RFCR_RFWM(v)   (((v) << BP_ESAI_RFCR_RFWM) & BM_ESAI_RFCR_RFWM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFWM field to a new value.
#define BW_ESAI_RFCR_RFWM(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RFWM) | BF_ESAI_RFCR_RFWM(v)))
#endif

/* --- Register HW_ESAI_RFCR, field RWA[18:16] (RW)
 *
 * Receive Word Alignment. Configures the alignment of the data passed from the relevant 24 bit
 * Receive shift register and read out the ESAI Receive Data Register.
 *
 * Values:
 * 000 - MSB of data is at bit 31. Data bits 7-0 are zeroed.
 * 001 - MSB of data is at bit 27. Data bits 3-0 are zeroed.
 * 010 - MSB of data is at bit 23.
 * 011 - MSB of data is at bit 19. Data bits 3-0 from receive shift register are ignored.
 * 100 - MSB of data is at bit 15. Data bits 7-0 from receive shift register are ignored.
 * 101 - MSB of data is at bit 11. Data bits 11-0 from receive shift register are ignored.
 * 110 - MSB of data is at bit 7. Data bits 15-0 from receive shift register are ignored.
 * 111 - MSB of data is at bit 3. Data bits 19-0 from receive shift register are ignored.
 */

#define BP_ESAI_RFCR_RWA      (16)      //!< Bit position for ESAI_RFCR_RWA.
#define BM_ESAI_RFCR_RWA      (0x00070000)  //!< Bit mask for ESAI_RFCR_RWA.

//! @brief Get value of ESAI_RFCR_RWA from a register value.
#define BG_ESAI_RFCR_RWA(r)   (((r) & BM_ESAI_RFCR_RWA) >> BP_ESAI_RFCR_RWA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_RWA.
#define BF_ESAI_RFCR_RWA(v)   ((((reg32_t) v) << BP_ESAI_RFCR_RWA) & BM_ESAI_RFCR_RWA)
#else
//! @brief Format value for bitfield ESAI_RFCR_RWA.
#define BF_ESAI_RFCR_RWA(v)   (((v) << BP_ESAI_RFCR_RWA) & BM_ESAI_RFCR_RWA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RWA field to a new value.
#define BW_ESAI_RFCR_RWA(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_RWA) | BF_ESAI_RFCR_RWA(v)))
#endif


/* --- Register HW_ESAI_RFCR, field REXT[19] (RW)
 *
 * Receive Extension. Enables the receive data to be returned sign extended when the Receive Word
 * Alignment is configured to return data where the MSB is not aligned with bit 31.
 *
 * Values:
 * 0 - Receive data is zero extended.
 * 1 - Receive data is sign extended.
 */

#define BP_ESAI_RFCR_REXT      (19)      //!< Bit position for ESAI_RFCR_REXT.
#define BM_ESAI_RFCR_REXT      (0x00080000)  //!< Bit mask for ESAI_RFCR_REXT.

//! @brief Get value of ESAI_RFCR_REXT from a register value.
#define BG_ESAI_RFCR_REXT(r)   (((r) & BM_ESAI_RFCR_REXT) >> BP_ESAI_RFCR_REXT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RFCR_REXT.
#define BF_ESAI_RFCR_REXT(v)   ((((reg32_t) v) << BP_ESAI_RFCR_REXT) & BM_ESAI_RFCR_REXT)
#else
//! @brief Format value for bitfield ESAI_RFCR_REXT.
#define BF_ESAI_RFCR_REXT(v)   (((v) << BP_ESAI_RFCR_REXT) & BM_ESAI_RFCR_REXT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REXT field to a new value.
#define BW_ESAI_RFCR_REXT(v)   (HW_ESAI_RFCR_WR((HW_ESAI_RFCR_RD() & ~BM_ESAI_RFCR_REXT) | BF_ESAI_RFCR_REXT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RFSR - Receive FIFO Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_esai_rfsr
{
    reg32_t U;
    struct _hw_esai_rfsr_bitfields
    {
        unsigned RFCNT : 8; //!< [7:0] Receive FIFO Counter. These bits indicate the number of data words stored in the Receive FIFO.
        unsigned NRFO : 2; //!< [9:8] Next Receiver FIFO Out. Indicates which receiver returns the top word of the Receive FIFO.
        unsigned RESERVED0 : 2; //!< [11:10] Reserved
        unsigned NRFI : 2; //!< [13:12] Next Receiver FIFO In. Indicates which Receiver Data Register the Receive FIFO will load next. This will usually equal the lowest enabled receiver, unless the receive FIFO is full.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved
    } B;
} hw_esai_rfsr_t;
#endif

/*
 * constants & macros for entire ESAI_RFSR register
 */
#define HW_ESAI_RFSR_ADDR      (REGS_ESAI_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RFSR           (*(volatile hw_esai_rfsr_t *) HW_ESAI_RFSR_ADDR)
#define HW_ESAI_RFSR_RD()      (HW_ESAI_RFSR.U)
#endif

/*
 * constants & macros for individual ESAI_RFSR bitfields
 */

/* --- Register HW_ESAI_RFSR, field RFCNT[7:0] (RO)
 *
 * Receive FIFO Counter. These bits indicate the number of data words stored in the Receive FIFO.
 */

#define BP_ESAI_RFSR_RFCNT      (0)      //!< Bit position for ESAI_RFSR_RFCNT.
#define BM_ESAI_RFSR_RFCNT      (0x000000ff)  //!< Bit mask for ESAI_RFSR_RFCNT.

//! @brief Get value of ESAI_RFSR_RFCNT from a register value.
#define BG_ESAI_RFSR_RFCNT(r)   (((r) & BM_ESAI_RFSR_RFCNT) >> BP_ESAI_RFSR_RFCNT)

/* --- Register HW_ESAI_RFSR, field NRFO[9:8] (RO)
 *
 * Next Receiver FIFO Out. Indicates which receiver returns the top word of the Receive FIFO.
 *
 * Values:
 * 00 - Receiver #0 returns next word from the Receive FIFO.
 * 01 - Receiver #1 returns next word from the Receive FIFO.
 * 10 - Receiver #2 returns next word from the Receive FIFO.
 * 11 - Receiver #3 returns next word from the Receive FIFO.
 */

#define BP_ESAI_RFSR_NRFO      (8)      //!< Bit position for ESAI_RFSR_NRFO.
#define BM_ESAI_RFSR_NRFO      (0x00000300)  //!< Bit mask for ESAI_RFSR_NRFO.

//! @brief Get value of ESAI_RFSR_NRFO from a register value.
#define BG_ESAI_RFSR_NRFO(r)   (((r) & BM_ESAI_RFSR_NRFO) >> BP_ESAI_RFSR_NRFO)


/* --- Register HW_ESAI_RFSR, field NRFI[13:12] (RO)
 *
 * Next Receiver FIFO In. Indicates which Receiver Data Register the Receive FIFO will load next.
 * This will usually equal the lowest enabled receiver, unless the receive FIFO is full.
 *
 * Values:
 * 00 - Receiver #0 returns next word to the Receive FIFO.
 * 01 - Receiver #1 returns next word to the Receive FIFO.
 * 10 - Receiver #2 returns next word to the Receive FIFO.
 * 11 - Receiver #3 returns next word to the Receive FIFO.
 */

#define BP_ESAI_RFSR_NRFI      (12)      //!< Bit position for ESAI_RFSR_NRFI.
#define BM_ESAI_RFSR_NRFI      (0x00003000)  //!< Bit mask for ESAI_RFSR_NRFI.

//! @brief Get value of ESAI_RFSR_NRFI from a register value.
#define BG_ESAI_RFSR_NRFI(r)   (((r) & BM_ESAI_RFSR_NRFI) >> BP_ESAI_RFSR_NRFI)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX0 - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx0
{
    reg32_t U;
    struct _hw_esai_tx0_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx0_t;
#endif

/*
 * constants & macros for entire ESAI_TX0 register
 */
#define HW_ESAI_TX0_ADDR      (REGS_ESAI_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX0           (*(volatile hw_esai_tx0_t *) HW_ESAI_TX0_ADDR)
#define HW_ESAI_TX0_WR(v)     (HW_ESAI_TX0.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX0 bitfields
 */

/* --- Register HW_ESAI_TX0, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX0_TXN      (0)      //!< Bit position for ESAI_TX0_TXN.
#define BM_ESAI_TX0_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX0_TXN.

//! @brief Get value of ESAI_TX0_TXN from a register value.
#define BG_ESAI_TX0_TXN(r)   (((r) & BM_ESAI_TX0_TXN) >> BP_ESAI_TX0_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX0_TXN.
#define BF_ESAI_TX0_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX0_TXN) & BM_ESAI_TX0_TXN)
#else
//! @brief Format value for bitfield ESAI_TX0_TXN.
#define BF_ESAI_TX0_TXN(v)   (((v) << BP_ESAI_TX0_TXN) & BM_ESAI_TX0_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX1 - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx1
{
    reg32_t U;
    struct _hw_esai_tx1_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx1_t;
#endif

/*
 * constants & macros for entire ESAI_TX1 register
 */
#define HW_ESAI_TX1_ADDR      (REGS_ESAI_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX1           (*(volatile hw_esai_tx1_t *) HW_ESAI_TX1_ADDR)
#define HW_ESAI_TX1_WR(v)     (HW_ESAI_TX1.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX1 bitfields
 */

/* --- Register HW_ESAI_TX1, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX1_TXN      (0)      //!< Bit position for ESAI_TX1_TXN.
#define BM_ESAI_TX1_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX1_TXN.

//! @brief Get value of ESAI_TX1_TXN from a register value.
#define BG_ESAI_TX1_TXN(r)   (((r) & BM_ESAI_TX1_TXN) >> BP_ESAI_TX1_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX1_TXN.
#define BF_ESAI_TX1_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX1_TXN) & BM_ESAI_TX1_TXN)
#else
//! @brief Format value for bitfield ESAI_TX1_TXN.
#define BF_ESAI_TX1_TXN(v)   (((v) << BP_ESAI_TX1_TXN) & BM_ESAI_TX1_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX2 - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx2
{
    reg32_t U;
    struct _hw_esai_tx2_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx2_t;
#endif

/*
 * constants & macros for entire ESAI_TX2 register
 */
#define HW_ESAI_TX2_ADDR      (REGS_ESAI_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX2           (*(volatile hw_esai_tx2_t *) HW_ESAI_TX2_ADDR)
#define HW_ESAI_TX2_WR(v)     (HW_ESAI_TX2.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX2 bitfields
 */

/* --- Register HW_ESAI_TX2, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX2_TXN      (0)      //!< Bit position for ESAI_TX2_TXN.
#define BM_ESAI_TX2_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX2_TXN.

//! @brief Get value of ESAI_TX2_TXN from a register value.
#define BG_ESAI_TX2_TXN(r)   (((r) & BM_ESAI_TX2_TXN) >> BP_ESAI_TX2_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX2_TXN.
#define BF_ESAI_TX2_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX2_TXN) & BM_ESAI_TX2_TXN)
#else
//! @brief Format value for bitfield ESAI_TX2_TXN.
#define BF_ESAI_TX2_TXN(v)   (((v) << BP_ESAI_TX2_TXN) & BM_ESAI_TX2_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX3 - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx3
{
    reg32_t U;
    struct _hw_esai_tx3_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx3_t;
#endif

/*
 * constants & macros for entire ESAI_TX3 register
 */
#define HW_ESAI_TX3_ADDR      (REGS_ESAI_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX3           (*(volatile hw_esai_tx3_t *) HW_ESAI_TX3_ADDR)
#define HW_ESAI_TX3_WR(v)     (HW_ESAI_TX3.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX3 bitfields
 */

/* --- Register HW_ESAI_TX3, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX3_TXN      (0)      //!< Bit position for ESAI_TX3_TXN.
#define BM_ESAI_TX3_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX3_TXN.

//! @brief Get value of ESAI_TX3_TXN from a register value.
#define BG_ESAI_TX3_TXN(r)   (((r) & BM_ESAI_TX3_TXN) >> BP_ESAI_TX3_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX3_TXN.
#define BF_ESAI_TX3_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX3_TXN) & BM_ESAI_TX3_TXN)
#else
//! @brief Format value for bitfield ESAI_TX3_TXN.
#define BF_ESAI_TX3_TXN(v)   (((v) << BP_ESAI_TX3_TXN) & BM_ESAI_TX3_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX4 - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx4
{
    reg32_t U;
    struct _hw_esai_tx4_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx4_t;
#endif

/*
 * constants & macros for entire ESAI_TX4 register
 */
#define HW_ESAI_TX4_ADDR      (REGS_ESAI_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX4           (*(volatile hw_esai_tx4_t *) HW_ESAI_TX4_ADDR)
#define HW_ESAI_TX4_WR(v)     (HW_ESAI_TX4.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX4 bitfields
 */

/* --- Register HW_ESAI_TX4, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX4_TXN      (0)      //!< Bit position for ESAI_TX4_TXN.
#define BM_ESAI_TX4_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX4_TXN.

//! @brief Get value of ESAI_TX4_TXN from a register value.
#define BG_ESAI_TX4_TXN(r)   (((r) & BM_ESAI_TX4_TXN) >> BP_ESAI_TX4_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX4_TXN.
#define BF_ESAI_TX4_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX4_TXN) & BM_ESAI_TX4_TXN)
#else
//! @brief Format value for bitfield ESAI_TX4_TXN.
#define BF_ESAI_TX4_TXN(v)   (((v) << BP_ESAI_TX4_TXN) & BM_ESAI_TX4_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX5 - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx5
{
    reg32_t U;
    struct _hw_esai_tx5_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx5_t;
#endif

/*
 * constants & macros for entire ESAI_TX5 register
 */
#define HW_ESAI_TX5_ADDR      (REGS_ESAI_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX5           (*(volatile hw_esai_tx5_t *) HW_ESAI_TX5_ADDR)
#define HW_ESAI_TX5_WR(v)     (HW_ESAI_TX5.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX5 bitfields
 */

/* --- Register HW_ESAI_TX5, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX5_TXN      (0)      //!< Bit position for ESAI_TX5_TXN.
#define BM_ESAI_TX5_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX5_TXN.

//! @brief Get value of ESAI_TX5_TXN from a register value.
#define BG_ESAI_TX5_TXN(r)   (((r) & BM_ESAI_TX5_TXN) >> BP_ESAI_TX5_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX5_TXN.
#define BF_ESAI_TX5_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX5_TXN) & BM_ESAI_TX5_TXN)
#else
//! @brief Format value for bitfield ESAI_TX5_TXN.
#define BF_ESAI_TX5_TXN(v)   (((v) << BP_ESAI_TX5_TXN) & BM_ESAI_TX5_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TX - Transmit Data Register n (WORZ)
 *
 * Reset value: 0x00000000
 *
 * ESAI_TX5, ESAI_TX4, ESAI_TX3, ESAI_TX2, ESAI_TX1 and ESAI_TX0 are 32-bit write-only registers.
 * Data to be transmitted is written into these registers and is automatically transferred to the
 * transmit shift registers ( and ). The data written (8, 12, 16, 20, or 24 bits) should occupy the
 * most significant portion of the TXn according to the ALC control bit setting. The unused bits
 * (least significant portion and the 8 most significant bits when ALC=1) of the TXn are don't care
 * bits. The Core is interrupted whenever the TXn becomes empty if the transmit data register empty
 * interrupt has been enabled.
 */
typedef union _hw_esai_tx
{
    reg32_t U;
    struct _hw_esai_tx_bitfields
    {
        unsigned TXN : 24; //!< [23:0] Stores the data to be transmitted and is automatically transferred to the transmit shift registers. See .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_tx_t;
#endif

/*
 * constants & macros for entire ESAI_TX register
 */
#define HW_ESAI_TX_ADDR      (REGS_ESAI_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TX           (*(volatile hw_esai_tx_t *) HW_ESAI_TX_ADDR)
#define HW_ESAI_TX_WR(v)     (HW_ESAI_TX.U = (v))
#endif

/*
 * constants & macros for individual ESAI_TX bitfields
 */

/* --- Register HW_ESAI_TX, field TXN[23:0] (WORZ)
 *
 * Stores the data to be transmitted and is automatically transferred to the transmit shift
 * registers. See .
 */

#define BP_ESAI_TX_TXN      (0)      //!< Bit position for ESAI_TX_TXN.
#define BM_ESAI_TX_TXN      (0x00ffffff)  //!< Bit mask for ESAI_TX_TXN.

//! @brief Get value of ESAI_TX_TXN from a register value.
#define BG_ESAI_TX_TXN(r)   (((r) & BM_ESAI_TX_TXN) >> BP_ESAI_TX_TXN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TX_TXN.
#define BF_ESAI_TX_TXN(v)   ((((reg32_t) v) << BP_ESAI_TX_TXN) & BM_ESAI_TX_TXN)
#else
//! @brief Format value for bitfield ESAI_TX_TXN.
#define BF_ESAI_TX_TXN(v)   (((v) << BP_ESAI_TX_TXN) & BM_ESAI_TX_TXN)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RX0 - Receive Data Register n (RO)
 *
 * Reset value: 0x00000000
 *
 * ESAI_RX3, ESAI_RX2, ESAI_RX1, and ESAI_RX0 are 32-bit read-only registers that accept data from
 * the receive shift registers when they become full ( and ). The data occupies the most significant
 * portion of the receive data registers, according to the ALC control bit setting. The unused bits
 * (least significant portion and 8 most significant bits when ALC=1) read as zeros. The Core is
 * interrupted whenever RXn becomes full if the associated interrupt is enabled.
 */
typedef union _hw_esai_rx0
{
    reg32_t U;
    struct _hw_esai_rx0_bitfields
    {
        unsigned RXN : 24; //!< [23:0] Accept data from the receive shift registers when they become full See
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_rx0_t;
#endif

/*
 * constants & macros for entire ESAI_RX0 register
 */
#define HW_ESAI_RX0_ADDR      (REGS_ESAI_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RX0           (*(volatile hw_esai_rx0_t *) HW_ESAI_RX0_ADDR)
#define HW_ESAI_RX0_RD()      (HW_ESAI_RX0.U)
#endif

/*
 * constants & macros for individual ESAI_RX0 bitfields
 */

/* --- Register HW_ESAI_RX0, field RXN[23:0] (RO)
 *
 * Accept data from the receive shift registers when they become full See
 */

#define BP_ESAI_RX0_RXN      (0)      //!< Bit position for ESAI_RX0_RXN.
#define BM_ESAI_RX0_RXN      (0x00ffffff)  //!< Bit mask for ESAI_RX0_RXN.

//! @brief Get value of ESAI_RX0_RXN from a register value.
#define BG_ESAI_RX0_RXN(r)   (((r) & BM_ESAI_RX0_RXN) >> BP_ESAI_RX0_RXN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RX1 - Receive Data Register n (RO)
 *
 * Reset value: 0x00000000
 *
 * ESAI_RX3, ESAI_RX2, ESAI_RX1, and ESAI_RX0 are 32-bit read-only registers that accept data from
 * the receive shift registers when they become full ( and ). The data occupies the most significant
 * portion of the receive data registers, according to the ALC control bit setting. The unused bits
 * (least significant portion and 8 most significant bits when ALC=1) read as zeros. The Core is
 * interrupted whenever RXn becomes full if the associated interrupt is enabled.
 */
typedef union _hw_esai_rx1
{
    reg32_t U;
    struct _hw_esai_rx1_bitfields
    {
        unsigned RXN : 24; //!< [23:0] Accept data from the receive shift registers when they become full See
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_rx1_t;
#endif

/*
 * constants & macros for entire ESAI_RX1 register
 */
#define HW_ESAI_RX1_ADDR      (REGS_ESAI_BASE + 0xa4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RX1           (*(volatile hw_esai_rx1_t *) HW_ESAI_RX1_ADDR)
#define HW_ESAI_RX1_RD()      (HW_ESAI_RX1.U)
#endif

/*
 * constants & macros for individual ESAI_RX1 bitfields
 */

/* --- Register HW_ESAI_RX1, field RXN[23:0] (RO)
 *
 * Accept data from the receive shift registers when they become full See
 */

#define BP_ESAI_RX1_RXN      (0)      //!< Bit position for ESAI_RX1_RXN.
#define BM_ESAI_RX1_RXN      (0x00ffffff)  //!< Bit mask for ESAI_RX1_RXN.

//! @brief Get value of ESAI_RX1_RXN from a register value.
#define BG_ESAI_RX1_RXN(r)   (((r) & BM_ESAI_RX1_RXN) >> BP_ESAI_RX1_RXN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RX2 - Receive Data Register n (RO)
 *
 * Reset value: 0x00000000
 *
 * ESAI_RX3, ESAI_RX2, ESAI_RX1, and ESAI_RX0 are 32-bit read-only registers that accept data from
 * the receive shift registers when they become full ( and ). The data occupies the most significant
 * portion of the receive data registers, according to the ALC control bit setting. The unused bits
 * (least significant portion and 8 most significant bits when ALC=1) read as zeros. The Core is
 * interrupted whenever RXn becomes full if the associated interrupt is enabled.
 */
typedef union _hw_esai_rx2
{
    reg32_t U;
    struct _hw_esai_rx2_bitfields
    {
        unsigned RXN : 24; //!< [23:0] Accept data from the receive shift registers when they become full See
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_rx2_t;
#endif

/*
 * constants & macros for entire ESAI_RX2 register
 */
#define HW_ESAI_RX2_ADDR      (REGS_ESAI_BASE + 0xa8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RX2           (*(volatile hw_esai_rx2_t *) HW_ESAI_RX2_ADDR)
#define HW_ESAI_RX2_RD()      (HW_ESAI_RX2.U)
#endif

/*
 * constants & macros for individual ESAI_RX2 bitfields
 */

/* --- Register HW_ESAI_RX2, field RXN[23:0] (RO)
 *
 * Accept data from the receive shift registers when they become full See
 */

#define BP_ESAI_RX2_RXN      (0)      //!< Bit position for ESAI_RX2_RXN.
#define BM_ESAI_RX2_RXN      (0x00ffffff)  //!< Bit mask for ESAI_RX2_RXN.

//! @brief Get value of ESAI_RX2_RXN from a register value.
#define BG_ESAI_RX2_RXN(r)   (((r) & BM_ESAI_RX2_RXN) >> BP_ESAI_RX2_RXN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RX3 - Receive Data Register n (RO)
 *
 * Reset value: 0x00000000
 *
 * ESAI_RX3, ESAI_RX2, ESAI_RX1, and ESAI_RX0 are 32-bit read-only registers that accept data from
 * the receive shift registers when they become full ( and ). The data occupies the most significant
 * portion of the receive data registers, according to the ALC control bit setting. The unused bits
 * (least significant portion and 8 most significant bits when ALC=1) read as zeros. The Core is
 * interrupted whenever RXn becomes full if the associated interrupt is enabled.
 */
typedef union _hw_esai_rx3
{
    reg32_t U;
    struct _hw_esai_rx3_bitfields
    {
        unsigned RXN : 24; //!< [23:0] Accept data from the receive shift registers when they become full See
        unsigned RESERVED0 : 8; //!< [31:24] Reserved
    } B;
} hw_esai_rx3_t;
#endif

/*
 * constants & macros for entire ESAI_RX3 register
 */
#define HW_ESAI_RX3_ADDR      (REGS_ESAI_BASE + 0xac)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RX3           (*(volatile hw_esai_rx3_t *) HW_ESAI_RX3_ADDR)
#define HW_ESAI_RX3_RD()      (HW_ESAI_RX3.U)
#endif

/*
 * constants & macros for individual ESAI_RX3 bitfields
 */

/* --- Register HW_ESAI_RX3, field RXN[23:0] (RO)
 *
 * Accept data from the receive shift registers when they become full See
 */

#define BP_ESAI_RX3_RXN      (0)      //!< Bit position for ESAI_RX3_RXN.
#define BM_ESAI_RX3_RXN      (0x00ffffff)  //!< Bit mask for ESAI_RX3_RXN.

//! @brief Get value of ESAI_RX3_RXN from a register value.
#define BG_ESAI_RX3_RXN(r)   (((r) & BM_ESAI_RX3_RXN) >> BP_ESAI_RX3_RXN)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_SAISR - Serial Audio Interface Status Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The Status Register (ESAI_SAISR) is a read-only status register used by the ARM Core to read the
 * status and serial input flags of the ESAI.
 */
typedef union _hw_esai_saisr
{
    reg32_t U;
    struct _hw_esai_saisr_bitfields
    {
        unsigned IF0 : 1; //!< [0] ESAI_SAISR Serial Input Flag 0. The IF0 bit is enabled only when the SCKR pin is defined as ESAI in the Port Control Register, SYN=1 and RCKD=0, indicating that SCKR is an input flag and the synchronous mode is selected. Data present on the SCKR pin is latched during reception of the first received data bit after frame sync is detected. The IF0 bit is updated with this data when the receiver shift registers are transferred into the receiver data registers. IF0 reads as a zero when it is not enabled. Hardware, software, ESAI individual reset clear IF0.
        unsigned IF1 : 1; //!< [1] ESAI_SAISR Serial Inout Flag 1. The IF1 bit is enabled only when the FSR pin is defined as ESAI in the Port Control Register, SYN =1, RFSD=0 and TEBE=0, indicating that FSR is an input flag and the synchronous mode is selected. Data present on the FSR pin is latched during reception of the first received data bit after frame sync is detected. The IF1 bit is updated with this data when the receiver shift registers are transferred into the receiver data registers. IF1 reads as a zero when it is not enabled. Hardware, software, ESAI individual reset clear IF1.
        unsigned IF2 : 1; //!< [2] ESAI_SAISR Serial Input Flag 2. The IF2 bit is enabled only when the HCKR pin is defined as ESAI in the Port Control Register, SYN=1 and RHCKD=0, indicating that HCKR is an input flag and the synchronous mode is selected. Data present on the HCKR pin is latched during reception of the first received data bit after frame sync is detected. The IF2 bit is updated with this data when the receive shift registers are transferred into the receiver data registers. IF2 reads as a zero when it is not enabled. Hardware, software, ESAI individual reset clear IF2.
        unsigned RESERVED0 : 3; //!< [5:3] Reserved.
        unsigned RFS : 1; //!< [6] ESAI_SAISR Receive Frame Sync Flag. When set, RFS indicates that a receive frame sync occurred during reception of the words in the receiver data registers. This indicates that the data words are from the first slot in the frame. When RFS is clear and a word is received, it indicates (only in the network mode) that the frame sync did not occur during reception of that word. RFS is cleared by hardware, software, ESAI individual reset. RFS is valid only if at least one of the receivers is enabled (REx=1). (In normal mode, RFS always reads as a one when reading data because there is only one time slot per frame - the "frame sync" time slot)
        unsigned ROE : 1; //!< [7] ESAI_SAISR Receive Overrun Error Flag. The ROE flag is set when the serial receive shift register of an enabled receiver is full and ready to transfer to its receiver data register (RXn) and the register is already full (RDF=1). If REIE is set, an ESAI receive data with exception (overrun error) interrupt request is issued when ROE is set. Hardware, software, ESAI individual reset clear ROE. ROE is also cleared by reading the SAISR with ROE set, followed by reading all the enabled receive data registers.
        unsigned RDF : 1; //!< [8] ESAI_SAISR Receive Data Register Full. RDF is set when the contents of the receive shift register of an enabled receiver is transferred to the respective receive data register. RDF is cleared when the Core reads the receive data register of all enabled receivers or cleared by hardware, software, ESAI individual reset. If RIE is set, an ESAI receive data interrupt request is issued when RDF is set.
        unsigned REDF : 1; //!< [9] ESAI_SAISR Receive Even-Data Register Full. When set, REDF indicates that the received data in the receive data registers of the enabled receivers have arrived during an even time slot when operating in the network mode. Even time slots are all even-numbered slots (0, 2, 4, 6, and so on). Time slots are numbered from zero to N-1, where N is the number of time slots in the frame. The zero time slot is considered even. REDF is set when the contents of the receive shift registers are transferred to the receive data registers. REDF is cleared when the Core reads all the enabled receive data registers or cleared by hardware, software, ESAI individual resets. If REDIE is set, an ESAI receive even slot data interrupt request is issued when REDF is set.
        unsigned RODF : 1; //!< [10] ESAI_SAISR Receive Odd-Data Register Full. When set, RODF indicates that the received data in the receive data registers of the enabled receivers have arrived during an odd time slot when operating in the network mode. Odd time slots are all odd-numbered slots (1, 3, 5, and so on). Time slots are numbered from zero to N-1, where N is the number of time slots in the frame. RODF is set when the contents of the receive shift registers are transferred to the receive data registers. RODF is cleared when the Core reads all the enabled receive data registers or cleared by hardware, software, ESAI individual resets.
        unsigned RESERVED1 : 2; //!< [12:11] Reserved.
        unsigned TFS : 1; //!< [13] ESAI_SAISR Transmit Frame Sync Flar. When set, TFS indicates that a transmit frame sync occurred in the current time slot. TFS is set at the start of the first time slot in the frame and cleared during all other time slots. Data written to a transmit data register during the time slot when TFS is set is transmitted (in network mode), if the transmitter is enabled, during the second time slot in the frame. TFS is useful in network mode to identify the start of a frame. TFS is cleared by hardware, software, ESAI individual reset. TFS is valid only if at least one transmitter is enabled, that is, one or more of TE0, TE1, TE2, TE3, TE4 and TE5 are set. (In normal mode, TFS always reads as a one when transmitting data because there is only one time slot per frame - the "frame sync" time slot)
        unsigned TUE : 1; //!< [14] ESAI_SAISR Transmit Underrun Error Flag. TUE is set when at least one of the enabled serial transmit shift registers is empty (no new data to be transmitted) and a transmit time slot occurs. When a transmit underrun error occurs, the previous data (which is still present in the TX registers that were not written) is retransmitted. If TEIE is set, an ESAI transmit data with exception (underrun error) interrupt request is issued when TUE is set. Hardware, software, ESAI individual reset clear TUE. TUE is also cleared by reading the ESAI_SAISR with TUE set, followed by writing to all the enabled transmit data registers or to ESAI_TSR.
        unsigned TDE : 1; //!< [15] ESAI_SAISR Transmit Data Register Empty. TDE is set when the contents of the transmit data register of all the enabled transmitters are transferred to the transmit shift registers; it is also set for a TSR disabled time slot period in network mode (as if data were being transmitted after the TSR was written). When set, TDE indicates that data should be written to all the TX registers of the enabled transmitters or to the transmit slot register (ESAI_TSR). TDE is cleared when the Core writes to all the transmit data registers of the enabled transmitters, or when the Core writes to the TSR to disable transmission of the next time slot. If TIE is set, an ESAI transmit data interrupt request is issued when TDE is set. Hardware, software, ESAI individual reset clear TDE.
        unsigned TEDE : 1; //!< [16] ESAI_SAISR Transmit Even-DataRegister Empty. When set, TEDE indicates that the enabled transmitter data registers became empty at the beginning of an even time slot. Even time slots are all even-numbered slots (0, 2, 4, 6, etc.). Time slots are numbered from zero to N-1, where N is the number of time slots in the frame. The zero time slot is considered even. This flag is set when the contents of the transmit data register of all the enabled transmitters are transferred to the transmit shift registers; it is also set for a TSR disabled time slot period in network mode (as if data were being transmitted after the TSR was written). When set, TEDE indicates that data should be written to all the TX registers of the enabled transmitters or to the transmit slot register (ESAI_TSR). TEDE is cleared when the Core writes to all the transmit data registers of the enabled transmitters, or when the Core writes to the TSR to disable transmission of the next time slot. If TIE is set, an ESAI transmit data interrupt request is issued when TEDE is set. Hardware, software, ESAI individual reset clear TEDE.
        unsigned TODFE : 1; //!< [17] ESAI_SAISR Transmit Odd-Data Register Empty. When set, TODFE indicates that the enabled transmitter data registers became empty at the beginning of an odd time slot. Odd time slots are all odd-numbered slots (1, 3, 5, and so on). Time slots are numbered from zero to N-1, where N is the number of time slots in the frame. This flag is set when the contents of the transmit data register of all the enabled transmitters are transferred to the transmit shift registers; it is also set for a TSR disabled time slot period in network mode (as if data were being transmitted after the TSR was written). When set, TODFE indicates that data should be written to all the TX registers of the enabled transmitters or to the transmit slot register (ESAI_TSR). TODE is cleared when the Core writes to all the transmit data registers of the enabled transmitters, or when the Core writes to the TSR to disable transmission of the next time slot. If TIE is set, an ESAI transmit data interrupt request is issued when TODFE is set. Hardware, software, ESAI individual reset clear TODFE.
        unsigned RESERVED2 : 14; //!< [31:18] Reserved.
    } B;
} hw_esai_saisr_t;
#endif

/*
 * constants & macros for entire ESAI_SAISR register
 */
#define HW_ESAI_SAISR_ADDR      (REGS_ESAI_BASE + 0xcc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_SAISR           (*(volatile hw_esai_saisr_t *) HW_ESAI_SAISR_ADDR)
#define HW_ESAI_SAISR_RD()      (HW_ESAI_SAISR.U)
#endif

/*
 * constants & macros for individual ESAI_SAISR bitfields
 */

/* --- Register HW_ESAI_SAISR, field IF0[0] (RO)
 *
 * ESAI_SAISR Serial Input Flag 0. The IF0 bit is enabled only when the SCKR pin is defined as ESAI
 * in the Port Control Register, SYN=1 and RCKD=0, indicating that SCKR is an input flag and the
 * synchronous mode is selected. Data present on the SCKR pin is latched during reception of the
 * first received data bit after frame sync is detected. The IF0 bit is updated with this data when
 * the receiver shift registers are transferred into the receiver data registers. IF0 reads as a
 * zero when it is not enabled. Hardware, software, ESAI individual reset clear IF0.
 */

#define BP_ESAI_SAISR_IF0      (0)      //!< Bit position for ESAI_SAISR_IF0.
#define BM_ESAI_SAISR_IF0      (0x00000001)  //!< Bit mask for ESAI_SAISR_IF0.

//! @brief Get value of ESAI_SAISR_IF0 from a register value.
#define BG_ESAI_SAISR_IF0(r)   (((r) & BM_ESAI_SAISR_IF0) >> BP_ESAI_SAISR_IF0)

/* --- Register HW_ESAI_SAISR, field IF1[1] (RO)
 *
 * ESAI_SAISR Serial Inout Flag 1. The IF1 bit is enabled only when the FSR pin is defined as ESAI
 * in the Port Control Register, SYN =1, RFSD=0 and TEBE=0, indicating that FSR is an input flag and
 * the synchronous mode is selected. Data present on the FSR pin is latched during reception of the
 * first received data bit after frame sync is detected. The IF1 bit is updated with this data when
 * the receiver shift registers are transferred into the receiver data registers. IF1 reads as a
 * zero when it is not enabled. Hardware, software, ESAI individual reset clear IF1.
 */

#define BP_ESAI_SAISR_IF1      (1)      //!< Bit position for ESAI_SAISR_IF1.
#define BM_ESAI_SAISR_IF1      (0x00000002)  //!< Bit mask for ESAI_SAISR_IF1.

//! @brief Get value of ESAI_SAISR_IF1 from a register value.
#define BG_ESAI_SAISR_IF1(r)   (((r) & BM_ESAI_SAISR_IF1) >> BP_ESAI_SAISR_IF1)

/* --- Register HW_ESAI_SAISR, field IF2[2] (RO)
 *
 * ESAI_SAISR Serial Input Flag 2. The IF2 bit is enabled only when the HCKR pin is defined as ESAI
 * in the Port Control Register, SYN=1 and RHCKD=0, indicating that HCKR is an input flag and the
 * synchronous mode is selected. Data present on the HCKR pin is latched during reception of the
 * first received data bit after frame sync is detected. The IF2 bit is updated with this data when
 * the receive shift registers are transferred into the receiver data registers. IF2 reads as a zero
 * when it is not enabled. Hardware, software, ESAI individual reset clear IF2.
 */

#define BP_ESAI_SAISR_IF2      (2)      //!< Bit position for ESAI_SAISR_IF2.
#define BM_ESAI_SAISR_IF2      (0x00000004)  //!< Bit mask for ESAI_SAISR_IF2.

//! @brief Get value of ESAI_SAISR_IF2 from a register value.
#define BG_ESAI_SAISR_IF2(r)   (((r) & BM_ESAI_SAISR_IF2) >> BP_ESAI_SAISR_IF2)

/* --- Register HW_ESAI_SAISR, field RFS[6] (RO)
 *
 * ESAI_SAISR Receive Frame Sync Flag. When set, RFS indicates that a receive frame sync occurred
 * during reception of the words in the receiver data registers. This indicates that the data words
 * are from the first slot in the frame. When RFS is clear and a word is received, it indicates
 * (only in the network mode) that the frame sync did not occur during reception of that word. RFS
 * is cleared by hardware, software, ESAI individual reset. RFS is valid only if at least one of the
 * receivers is enabled (REx=1). (In normal mode, RFS always reads as a one when reading data
 * because there is only one time slot per frame - the "frame sync" time slot)
 */

#define BP_ESAI_SAISR_RFS      (6)      //!< Bit position for ESAI_SAISR_RFS.
#define BM_ESAI_SAISR_RFS      (0x00000040)  //!< Bit mask for ESAI_SAISR_RFS.

//! @brief Get value of ESAI_SAISR_RFS from a register value.
#define BG_ESAI_SAISR_RFS(r)   (((r) & BM_ESAI_SAISR_RFS) >> BP_ESAI_SAISR_RFS)

/* --- Register HW_ESAI_SAISR, field ROE[7] (RO)
 *
 * ESAI_SAISR Receive Overrun Error Flag. The ROE flag is set when the serial receive shift register
 * of an enabled receiver is full and ready to transfer to its receiver data register (RXn) and the
 * register is already full (RDF=1). If REIE is set, an ESAI receive data with exception (overrun
 * error) interrupt request is issued when ROE is set. Hardware, software, ESAI individual reset
 * clear ROE. ROE is also cleared by reading the SAISR with ROE set, followed by reading all the
 * enabled receive data registers.
 */

#define BP_ESAI_SAISR_ROE      (7)      //!< Bit position for ESAI_SAISR_ROE.
#define BM_ESAI_SAISR_ROE      (0x00000080)  //!< Bit mask for ESAI_SAISR_ROE.

//! @brief Get value of ESAI_SAISR_ROE from a register value.
#define BG_ESAI_SAISR_ROE(r)   (((r) & BM_ESAI_SAISR_ROE) >> BP_ESAI_SAISR_ROE)

/* --- Register HW_ESAI_SAISR, field RDF[8] (RO)
 *
 * ESAI_SAISR Receive Data Register Full. RDF is set when the contents of the receive shift register
 * of an enabled receiver is transferred to the respective receive data register. RDF is cleared
 * when the Core reads the receive data register of all enabled receivers or cleared by hardware,
 * software, ESAI individual reset. If RIE is set, an ESAI receive data interrupt request is issued
 * when RDF is set.
 */

#define BP_ESAI_SAISR_RDF      (8)      //!< Bit position for ESAI_SAISR_RDF.
#define BM_ESAI_SAISR_RDF      (0x00000100)  //!< Bit mask for ESAI_SAISR_RDF.

//! @brief Get value of ESAI_SAISR_RDF from a register value.
#define BG_ESAI_SAISR_RDF(r)   (((r) & BM_ESAI_SAISR_RDF) >> BP_ESAI_SAISR_RDF)

/* --- Register HW_ESAI_SAISR, field REDF[9] (RO)
 *
 * ESAI_SAISR Receive Even-Data Register Full. When set, REDF indicates that the received data in
 * the receive data registers of the enabled receivers have arrived during an even time slot when
 * operating in the network mode. Even time slots are all even-numbered slots (0, 2, 4, 6, and so
 * on). Time slots are numbered from zero to N-1, where N is the number of time slots in the frame.
 * The zero time slot is considered even. REDF is set when the contents of the receive shift
 * registers are transferred to the receive data registers. REDF is cleared when the Core reads all
 * the enabled receive data registers or cleared by hardware, software, ESAI individual resets. If
 * REDIE is set, an ESAI receive even slot data interrupt request is issued when REDF is set.
 */

#define BP_ESAI_SAISR_REDF      (9)      //!< Bit position for ESAI_SAISR_REDF.
#define BM_ESAI_SAISR_REDF      (0x00000200)  //!< Bit mask for ESAI_SAISR_REDF.

//! @brief Get value of ESAI_SAISR_REDF from a register value.
#define BG_ESAI_SAISR_REDF(r)   (((r) & BM_ESAI_SAISR_REDF) >> BP_ESAI_SAISR_REDF)

/* --- Register HW_ESAI_SAISR, field RODF[10] (RO)
 *
 * ESAI_SAISR Receive Odd-Data Register Full. When set, RODF indicates that the received data in the
 * receive data registers of the enabled receivers have arrived during an odd time slot when
 * operating in the network mode. Odd time slots are all odd-numbered slots (1, 3, 5, and so on).
 * Time slots are numbered from zero to N-1, where N is the number of time slots in the frame. RODF
 * is set when the contents of the receive shift registers are transferred to the receive data
 * registers. RODF is cleared when the Core reads all the enabled receive data registers or cleared
 * by hardware, software, ESAI individual resets.
 */

#define BP_ESAI_SAISR_RODF      (10)      //!< Bit position for ESAI_SAISR_RODF.
#define BM_ESAI_SAISR_RODF      (0x00000400)  //!< Bit mask for ESAI_SAISR_RODF.

//! @brief Get value of ESAI_SAISR_RODF from a register value.
#define BG_ESAI_SAISR_RODF(r)   (((r) & BM_ESAI_SAISR_RODF) >> BP_ESAI_SAISR_RODF)

/* --- Register HW_ESAI_SAISR, field TFS[13] (RO)
 *
 * ESAI_SAISR Transmit Frame Sync Flar. When set, TFS indicates that a transmit frame sync occurred
 * in the current time slot. TFS is set at the start of the first time slot in the frame and cleared
 * during all other time slots. Data written to a transmit data register during the time slot when
 * TFS is set is transmitted (in network mode), if the transmitter is enabled, during the second
 * time slot in the frame. TFS is useful in network mode to identify the start of a frame. TFS is
 * cleared by hardware, software, ESAI individual reset. TFS is valid only if at least one
 * transmitter is enabled, that is, one or more of TE0, TE1, TE2, TE3, TE4 and TE5 are set. (In
 * normal mode, TFS always reads as a one when transmitting data because there is only one time slot
 * per frame - the "frame sync" time slot)
 */

#define BP_ESAI_SAISR_TFS      (13)      //!< Bit position for ESAI_SAISR_TFS.
#define BM_ESAI_SAISR_TFS      (0x00002000)  //!< Bit mask for ESAI_SAISR_TFS.

//! @brief Get value of ESAI_SAISR_TFS from a register value.
#define BG_ESAI_SAISR_TFS(r)   (((r) & BM_ESAI_SAISR_TFS) >> BP_ESAI_SAISR_TFS)

/* --- Register HW_ESAI_SAISR, field TUE[14] (RO)
 *
 * ESAI_SAISR Transmit Underrun Error Flag. TUE is set when at least one of the enabled serial
 * transmit shift registers is empty (no new data to be transmitted) and a transmit time slot
 * occurs. When a transmit underrun error occurs, the previous data (which is still present in the
 * TX registers that were not written) is retransmitted. If TEIE is set, an ESAI transmit data with
 * exception (underrun error) interrupt request is issued when TUE is set. Hardware, software, ESAI
 * individual reset clear TUE. TUE is also cleared by reading the ESAI_SAISR with TUE set, followed
 * by writing to all the enabled transmit data registers or to ESAI_TSR.
 */

#define BP_ESAI_SAISR_TUE      (14)      //!< Bit position for ESAI_SAISR_TUE.
#define BM_ESAI_SAISR_TUE      (0x00004000)  //!< Bit mask for ESAI_SAISR_TUE.

//! @brief Get value of ESAI_SAISR_TUE from a register value.
#define BG_ESAI_SAISR_TUE(r)   (((r) & BM_ESAI_SAISR_TUE) >> BP_ESAI_SAISR_TUE)

/* --- Register HW_ESAI_SAISR, field TDE[15] (RO)
 *
 * ESAI_SAISR Transmit Data Register Empty. TDE is set when the contents of the transmit data
 * register of all the enabled transmitters are transferred to the transmit shift registers; it is
 * also set for a TSR disabled time slot period in network mode (as if data were being transmitted
 * after the TSR was written). When set, TDE indicates that data should be written to all the TX
 * registers of the enabled transmitters or to the transmit slot register (ESAI_TSR). TDE is cleared
 * when the Core writes to all the transmit data registers of the enabled transmitters, or when the
 * Core writes to the TSR to disable transmission of the next time slot. If TIE is set, an ESAI
 * transmit data interrupt request is issued when TDE is set. Hardware, software, ESAI individual
 * reset clear TDE.
 */

#define BP_ESAI_SAISR_TDE      (15)      //!< Bit position for ESAI_SAISR_TDE.
#define BM_ESAI_SAISR_TDE      (0x00008000)  //!< Bit mask for ESAI_SAISR_TDE.

//! @brief Get value of ESAI_SAISR_TDE from a register value.
#define BG_ESAI_SAISR_TDE(r)   (((r) & BM_ESAI_SAISR_TDE) >> BP_ESAI_SAISR_TDE)

/* --- Register HW_ESAI_SAISR, field TEDE[16] (RO)
 *
 * ESAI_SAISR Transmit Even-DataRegister Empty. When set, TEDE indicates that the enabled
 * transmitter data registers became empty at the beginning of an even time slot. Even time slots
 * are all even-numbered slots (0, 2, 4, 6, etc.). Time slots are numbered from zero to N-1, where N
 * is the number of time slots in the frame. The zero time slot is considered even. This flag is set
 * when the contents of the transmit data register of all the enabled transmitters are transferred
 * to the transmit shift registers; it is also set for a TSR disabled time slot period in network
 * mode (as if data were being transmitted after the TSR was written). When set, TEDE indicates that
 * data should be written to all the TX registers of the enabled transmitters or to the transmit
 * slot register (ESAI_TSR). TEDE is cleared when the Core writes to all the transmit data registers
 * of the enabled transmitters, or when the Core writes to the TSR to disable transmission of the
 * next time slot. If TIE is set, an ESAI transmit data interrupt request is issued when TEDE is
 * set. Hardware, software, ESAI individual reset clear TEDE.
 */

#define BP_ESAI_SAISR_TEDE      (16)      //!< Bit position for ESAI_SAISR_TEDE.
#define BM_ESAI_SAISR_TEDE      (0x00010000)  //!< Bit mask for ESAI_SAISR_TEDE.

//! @brief Get value of ESAI_SAISR_TEDE from a register value.
#define BG_ESAI_SAISR_TEDE(r)   (((r) & BM_ESAI_SAISR_TEDE) >> BP_ESAI_SAISR_TEDE)

/* --- Register HW_ESAI_SAISR, field TODFE[17] (RO)
 *
 * ESAI_SAISR Transmit Odd-Data Register Empty. When set, TODFE indicates that the enabled
 * transmitter data registers became empty at the beginning of an odd time slot. Odd time slots are
 * all odd-numbered slots (1, 3, 5, and so on). Time slots are numbered from zero to N-1, where N is
 * the number of time slots in the frame. This flag is set when the contents of the transmit data
 * register of all the enabled transmitters are transferred to the transmit shift registers; it is
 * also set for a TSR disabled time slot period in network mode (as if data were being transmitted
 * after the TSR was written). When set, TODFE indicates that data should be written to all the TX
 * registers of the enabled transmitters or to the transmit slot register (ESAI_TSR). TODE is
 * cleared when the Core writes to all the transmit data registers of the enabled transmitters, or
 * when the Core writes to the TSR to disable transmission of the next time slot. If TIE is set, an
 * ESAI transmit data interrupt request is issued when TODFE is set. Hardware, software, ESAI
 * individual reset clear TODFE.
 */

#define BP_ESAI_SAISR_TODFE      (17)      //!< Bit position for ESAI_SAISR_TODFE.
#define BM_ESAI_SAISR_TODFE      (0x00020000)  //!< Bit mask for ESAI_SAISR_TODFE.

//! @brief Get value of ESAI_SAISR_TODFE from a register value.
#define BG_ESAI_SAISR_TODFE(r)   (((r) & BM_ESAI_SAISR_TODFE) >> BP_ESAI_SAISR_TODFE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_SAICR - Serial Audio Interface Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The read/write Common Control Register (ESAI_SAICR) contains control bits for functions that
 * affect both the receive and transmit sections of the ESAI.   SAICR SYN Bit Operation
 */
typedef union _hw_esai_saicr
{
    reg32_t U;
    struct _hw_esai_saicr_bitfields
    {
        unsigned OF0 : 1; //!< [0] ESAI_SAICR Serial Output Flag 0. The Serial Output Flag 0 (OF0) is a data bit used to hold data to be send to the OF0 pin. When the ESAI is in the synchronous clock mode (SYN=1), the SCKR pin is configured as the ESAI flag 0. If the receiver serial clock direction bit (RCKD) is set, the SCKR pin is the output flag OF0, and data present in the OF0 bit is written to the OF0 pin at the beginning of the frame in normal mode or at the beginning of the next time slot in network mode.
        unsigned OF1 : 1; //!< [1] ESAI_SAICR Serial Output Flag 1. The Serial Output Flag 1 (OF1) is a data bit used to hold data to be send to the OF1 pin. When the ESAI is in the synchronous clock mode (SYN=1), the FSR pin is configured as the ESAI flag 1. If the receiver frame sync direction bit (RFSD) is set and the TEBE bit is cleared, the FSR pin is the output flag OF1, and data present in the OF1 bit is written to the OF1 pin at the beginning of the frame in normal mode or at the beginning of the next time slot in network mode.
        unsigned OF2 : 1; //!< [2] ESAI_SAICR Serial Output Flag 2. The Serial Output Flag 2 (OF2) is a data bit used to hold data to be send to the OF2 pin. When the ESAI is in the synchronous clock mode (SYN=1), the HCKR pin is configured as the ESAI flag 2. If the receiver high frequency clock direction bit (RHCKD) is set, the HCKR pin is the output flag OF2, and data present in the OF2 bit is written to the OF2 pin at the beginning of the frame in normal mode or at the beginning of the next time slot in network mode.
        unsigned RESERVED0 : 3; //!< [5:3] Reserved.
        unsigned SYN : 1; //!< [6] ESAI_SAICR Synchronous Mode Selection. The Synchronous Mode Selection (SYN) bit controls whether the receiver and transmitter sections of the ESAI operate synchronously or asynchronously with respect to each other (see Port C Control Register ). When SYN is cleared, the asynchronous mode is chosen and independent clock and frame sync signals are used for the transmit and receive sections. When SYN is set, the synchronous mode is chosen and the transmit and receive sections use common clock and frame sync signals. When in the synchronous mode (SYN=1), the transmit and receive sections use the transmitter section clock generator as the source of the clock and frame sync for both sections. Also, the receiver clock pins SCKR, FSR and HCKR now operate as I/O flags. Refer to , , and for the effects of SYN on the receiver clock pins.
        unsigned TEBE : 1; //!< [7] ESAI_SAICR Transmit External Buffer Enable. The Transmitter External Buffer Enable (TEBE) bit controls the function of the FSR pin when in the synchronous mode. If the ESAI is configured for operation in the synchronous mode (SYN=1), and TEBE is set while FSR pin is configured as an output (RFSD=1), the FSR pin functions as the transmitter external buffer enable control to enable the use of an external buffers on the transmitter outputs. If TEBE is cleared, the FSR pin functions as the serial I/O flag 1. See Port C Control Register for a summary of the effects of TEBE on the FSR pin.
        unsigned ALC : 1; //!< [8] ESAI_SAICR Alignment Control. The ESAI is designed for 24-bit fractional data, thus shorter data words are left aligned to the MSB (bit 23). Some applications use 16-bit fractional data. In those cases, shorter data words may be left aligned to bit 15. The Alignment Control (ALC) bit supports these applications. If ALC is set, transmitted and received words are left aligned to bit 15 in the transmit and receive shift registers. If ALC is cleared, transmitted and received word are left aligned to bit 23 in the transmit and receive shift registers. While ALC is set, 20-bit and 24-bit words may not be used, and word length control should specify 8-, 12-, or 16-bit words; otherwise, results are unpredictable.
        unsigned RESERVED1 : 23; //!< [31:9] Reserved
    } B;
} hw_esai_saicr_t;
#endif

/*
 * constants & macros for entire ESAI_SAICR register
 */
#define HW_ESAI_SAICR_ADDR      (REGS_ESAI_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_SAICR           (*(volatile hw_esai_saicr_t *) HW_ESAI_SAICR_ADDR)
#define HW_ESAI_SAICR_RD()      (HW_ESAI_SAICR.U)
#define HW_ESAI_SAICR_WR(v)     (HW_ESAI_SAICR.U = (v))
#define HW_ESAI_SAICR_SET(v)    (HW_ESAI_SAICR_WR(HW_ESAI_SAICR_RD() |  (v)))
#define HW_ESAI_SAICR_CLR(v)    (HW_ESAI_SAICR_WR(HW_ESAI_SAICR_RD() & ~(v)))
#define HW_ESAI_SAICR_TOG(v)    (HW_ESAI_SAICR_WR(HW_ESAI_SAICR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_SAICR bitfields
 */

/* --- Register HW_ESAI_SAICR, field OF0[0] (RW)
 *
 * ESAI_SAICR Serial Output Flag 0. The Serial Output Flag 0 (OF0) is a data bit used to hold data
 * to be send to the OF0 pin. When the ESAI is in the synchronous clock mode (SYN=1), the SCKR pin
 * is configured as the ESAI flag 0. If the receiver serial clock direction bit (RCKD) is set, the
 * SCKR pin is the output flag OF0, and data present in the OF0 bit is written to the OF0 pin at the
 * beginning of the frame in normal mode or at the beginning of the next time slot in network mode.
 */

#define BP_ESAI_SAICR_OF0      (0)      //!< Bit position for ESAI_SAICR_OF0.
#define BM_ESAI_SAICR_OF0      (0x00000001)  //!< Bit mask for ESAI_SAICR_OF0.

//! @brief Get value of ESAI_SAICR_OF0 from a register value.
#define BG_ESAI_SAICR_OF0(r)   (((r) & BM_ESAI_SAICR_OF0) >> BP_ESAI_SAICR_OF0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_SAICR_OF0.
#define BF_ESAI_SAICR_OF0(v)   ((((reg32_t) v) << BP_ESAI_SAICR_OF0) & BM_ESAI_SAICR_OF0)
#else
//! @brief Format value for bitfield ESAI_SAICR_OF0.
#define BF_ESAI_SAICR_OF0(v)   (((v) << BP_ESAI_SAICR_OF0) & BM_ESAI_SAICR_OF0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF0 field to a new value.
#define BW_ESAI_SAICR_OF0(v)   (HW_ESAI_SAICR_WR((HW_ESAI_SAICR_RD() & ~BM_ESAI_SAICR_OF0) | BF_ESAI_SAICR_OF0(v)))
#endif

/* --- Register HW_ESAI_SAICR, field OF1[1] (RW)
 *
 * ESAI_SAICR Serial Output Flag 1. The Serial Output Flag 1 (OF1) is a data bit used to hold data
 * to be send to the OF1 pin. When the ESAI is in the synchronous clock mode (SYN=1), the FSR pin is
 * configured as the ESAI flag 1. If the receiver frame sync direction bit (RFSD) is set and the
 * TEBE bit is cleared, the FSR pin is the output flag OF1, and data present in the OF1 bit is
 * written to the OF1 pin at the beginning of the frame in normal mode or at the beginning of the
 * next time slot in network mode.
 */

#define BP_ESAI_SAICR_OF1      (1)      //!< Bit position for ESAI_SAICR_OF1.
#define BM_ESAI_SAICR_OF1      (0x00000002)  //!< Bit mask for ESAI_SAICR_OF1.

//! @brief Get value of ESAI_SAICR_OF1 from a register value.
#define BG_ESAI_SAICR_OF1(r)   (((r) & BM_ESAI_SAICR_OF1) >> BP_ESAI_SAICR_OF1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_SAICR_OF1.
#define BF_ESAI_SAICR_OF1(v)   ((((reg32_t) v) << BP_ESAI_SAICR_OF1) & BM_ESAI_SAICR_OF1)
#else
//! @brief Format value for bitfield ESAI_SAICR_OF1.
#define BF_ESAI_SAICR_OF1(v)   (((v) << BP_ESAI_SAICR_OF1) & BM_ESAI_SAICR_OF1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF1 field to a new value.
#define BW_ESAI_SAICR_OF1(v)   (HW_ESAI_SAICR_WR((HW_ESAI_SAICR_RD() & ~BM_ESAI_SAICR_OF1) | BF_ESAI_SAICR_OF1(v)))
#endif

/* --- Register HW_ESAI_SAICR, field OF2[2] (RW)
 *
 * ESAI_SAICR Serial Output Flag 2. The Serial Output Flag 2 (OF2) is a data bit used to hold data
 * to be send to the OF2 pin. When the ESAI is in the synchronous clock mode (SYN=1), the HCKR pin
 * is configured as the ESAI flag 2. If the receiver high frequency clock direction bit (RHCKD) is
 * set, the HCKR pin is the output flag OF2, and data present in the OF2 bit is written to the OF2
 * pin at the beginning of the frame in normal mode or at the beginning of the next time slot in
 * network mode.
 */

#define BP_ESAI_SAICR_OF2      (2)      //!< Bit position for ESAI_SAICR_OF2.
#define BM_ESAI_SAICR_OF2      (0x00000004)  //!< Bit mask for ESAI_SAICR_OF2.

//! @brief Get value of ESAI_SAICR_OF2 from a register value.
#define BG_ESAI_SAICR_OF2(r)   (((r) & BM_ESAI_SAICR_OF2) >> BP_ESAI_SAICR_OF2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_SAICR_OF2.
#define BF_ESAI_SAICR_OF2(v)   ((((reg32_t) v) << BP_ESAI_SAICR_OF2) & BM_ESAI_SAICR_OF2)
#else
//! @brief Format value for bitfield ESAI_SAICR_OF2.
#define BF_ESAI_SAICR_OF2(v)   (((v) << BP_ESAI_SAICR_OF2) & BM_ESAI_SAICR_OF2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OF2 field to a new value.
#define BW_ESAI_SAICR_OF2(v)   (HW_ESAI_SAICR_WR((HW_ESAI_SAICR_RD() & ~BM_ESAI_SAICR_OF2) | BF_ESAI_SAICR_OF2(v)))
#endif

/* --- Register HW_ESAI_SAICR, field SYN[6] (RW)
 *
 * ESAI_SAICR Synchronous Mode Selection. The Synchronous Mode Selection (SYN) bit controls whether
 * the receiver and transmitter sections of the ESAI operate synchronously or asynchronously with
 * respect to each other (see Port C Control Register ). When SYN is cleared, the asynchronous mode
 * is chosen and independent clock and frame sync signals are used for the transmit and receive
 * sections. When SYN is set, the synchronous mode is chosen and the transmit and receive sections
 * use common clock and frame sync signals. When in the synchronous mode (SYN=1), the transmit and
 * receive sections use the transmitter section clock generator as the source of the clock and frame
 * sync for both sections. Also, the receiver clock pins SCKR, FSR and HCKR now operate as I/O
 * flags. Refer to , , and for the effects of SYN on the receiver clock pins.
 */

#define BP_ESAI_SAICR_SYN      (6)      //!< Bit position for ESAI_SAICR_SYN.
#define BM_ESAI_SAICR_SYN      (0x00000040)  //!< Bit mask for ESAI_SAICR_SYN.

//! @brief Get value of ESAI_SAICR_SYN from a register value.
#define BG_ESAI_SAICR_SYN(r)   (((r) & BM_ESAI_SAICR_SYN) >> BP_ESAI_SAICR_SYN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_SAICR_SYN.
#define BF_ESAI_SAICR_SYN(v)   ((((reg32_t) v) << BP_ESAI_SAICR_SYN) & BM_ESAI_SAICR_SYN)
#else
//! @brief Format value for bitfield ESAI_SAICR_SYN.
#define BF_ESAI_SAICR_SYN(v)   (((v) << BP_ESAI_SAICR_SYN) & BM_ESAI_SAICR_SYN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYN field to a new value.
#define BW_ESAI_SAICR_SYN(v)   (HW_ESAI_SAICR_WR((HW_ESAI_SAICR_RD() & ~BM_ESAI_SAICR_SYN) | BF_ESAI_SAICR_SYN(v)))
#endif

/* --- Register HW_ESAI_SAICR, field TEBE[7] (RW)
 *
 * ESAI_SAICR Transmit External Buffer Enable. The Transmitter External Buffer Enable (TEBE) bit
 * controls the function of the FSR pin when in the synchronous mode. If the ESAI is configured for
 * operation in the synchronous mode (SYN=1), and TEBE is set while FSR pin is configured as an
 * output (RFSD=1), the FSR pin functions as the transmitter external buffer enable control to
 * enable the use of an external buffers on the transmitter outputs. If TEBE is cleared, the FSR pin
 * functions as the serial I/O flag 1. See Port C Control Register for a summary of the effects of
 * TEBE on the FSR pin.
 */

#define BP_ESAI_SAICR_TEBE      (7)      //!< Bit position for ESAI_SAICR_TEBE.
#define BM_ESAI_SAICR_TEBE      (0x00000080)  //!< Bit mask for ESAI_SAICR_TEBE.

//! @brief Get value of ESAI_SAICR_TEBE from a register value.
#define BG_ESAI_SAICR_TEBE(r)   (((r) & BM_ESAI_SAICR_TEBE) >> BP_ESAI_SAICR_TEBE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_SAICR_TEBE.
#define BF_ESAI_SAICR_TEBE(v)   ((((reg32_t) v) << BP_ESAI_SAICR_TEBE) & BM_ESAI_SAICR_TEBE)
#else
//! @brief Format value for bitfield ESAI_SAICR_TEBE.
#define BF_ESAI_SAICR_TEBE(v)   (((v) << BP_ESAI_SAICR_TEBE) & BM_ESAI_SAICR_TEBE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEBE field to a new value.
#define BW_ESAI_SAICR_TEBE(v)   (HW_ESAI_SAICR_WR((HW_ESAI_SAICR_RD() & ~BM_ESAI_SAICR_TEBE) | BF_ESAI_SAICR_TEBE(v)))
#endif

/* --- Register HW_ESAI_SAICR, field ALC[8] (RW)
 *
 * ESAI_SAICR Alignment Control. The ESAI is designed for 24-bit fractional data, thus shorter data
 * words are left aligned to the MSB (bit 23). Some applications use 16-bit fractional data. In
 * those cases, shorter data words may be left aligned to bit 15. The Alignment Control (ALC) bit
 * supports these applications. If ALC is set, transmitted and received words are left aligned to
 * bit 15 in the transmit and receive shift registers. If ALC is cleared, transmitted and received
 * word are left aligned to bit 23 in the transmit and receive shift registers. While ALC is set,
 * 20-bit and 24-bit words may not be used, and word length control should specify 8-, 12-, or
 * 16-bit words; otherwise, results are unpredictable.
 */

#define BP_ESAI_SAICR_ALC      (8)      //!< Bit position for ESAI_SAICR_ALC.
#define BM_ESAI_SAICR_ALC      (0x00000100)  //!< Bit mask for ESAI_SAICR_ALC.

//! @brief Get value of ESAI_SAICR_ALC from a register value.
#define BG_ESAI_SAICR_ALC(r)   (((r) & BM_ESAI_SAICR_ALC) >> BP_ESAI_SAICR_ALC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_SAICR_ALC.
#define BF_ESAI_SAICR_ALC(v)   ((((reg32_t) v) << BP_ESAI_SAICR_ALC) & BM_ESAI_SAICR_ALC)
#else
//! @brief Format value for bitfield ESAI_SAICR_ALC.
#define BF_ESAI_SAICR_ALC(v)   (((v) << BP_ESAI_SAICR_ALC) & BM_ESAI_SAICR_ALC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALC field to a new value.
#define BW_ESAI_SAICR_ALC(v)   (HW_ESAI_SAICR_WR((HW_ESAI_SAICR_RD() & ~BM_ESAI_SAICR_ALC) | BF_ESAI_SAICR_ALC(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TCR - Transmit Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The read/write Transmit Control Register (ESAI_TCR) controls the ESAI transmitter section.
 * Interrupt enable bits for the transmitter section are provided in this control register.
 * Operating modes are also selected in this register.   Transmit Network Mode Selection
 * TMOD1  TMOD0  TDC4-TDC0  Transmitter Network Mode      0  0  0x0-0x1F  Normal Mode    0  1  0x0
 * On-Demand Mode    0  1  0x1-0x1F  Network Mode    1  0  X  Reserved    1  1  0x0C  AC97
 * Normal and Network Operation     ESAI Transmit Slot and Word Length Selection            TSWS4
 * TSWS3  TSWS2  TSWS1  TSWS0  SLOT LENGTH  WORD LENGTH      0  0  0  0  0  8  8    0  0  1  0  0
 * 12  8    0  0  0  0  1  12    0  1  0  0  0  16  8    0  0  1  0  1  12    0  0  0  1  0  16    0
 * 1  1  0  0  20  8    0  1  0  0  1  12    0  0  1  1  0  16    0  0  0  1  1  20    1  0  0  0  0
 * 24  8    0  1  1  0  1  12    0  1  0  1  0  16    0  0  1  1  1  20    1  1  1  1  0  24    1  1
 * 0  0  0  32  8    1  0  1  0  1  12    1  0  0  1  0  16    0  1  1  1  1  20    1  1  1  1  1
 * 24    0  1  0  1  1  Reserved    0  1  1  1  0    1  0  0  0  1    1  0  0  1  1    1  0  1  0  0
 * 1  0  1  1  0    1  0  1  1  1    1  1  0  0  1    1  1  0  1  0    1  1  0  1  1    1  1  1  0
 * 0    1  1  1  0  1         Frame Length Selection
 */
typedef union _hw_esai_tcr
{
    reg32_t U;
    struct _hw_esai_tcr_bitfields
    {
        unsigned TE0 : 1; //!< [0] ESAI_TCR ESAI Transmit 0 Enable. TE0 enables the transfer of data from ESAI_TX0 to the transmit shift register #0. When TE0 is set and a frame sync is detected, the transmit #0 portion of the ESAI is enabled for that frame. When TE0 is cleared, the transmitter #0 is disabled after completing transmission of data currently in the ESAI transmit shift register. The SDO0 output is tri-stated, and any data present in ESAI_TX0 is not transmitted, that is, data can be written to ESAI_TX0 with TE0 cleared, but data is not transferred to the transmit shift register #0. The normal mode transmit enable sequence is to write data to one or more transmit data registers before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In the network mode, the operation of clearing TE0 and setting it again disables the transmitter #0 after completing transmission of the current data word until the beginning of the next frame. During that time period, the SDO0 pin remains in the high-impedance state.The on-demand mode transmit enable sequence can be the same as the normal mode, or TE0 can be left enabled.
        unsigned TE1 : 1; //!< [1] ESAI_TCR ESAI Transmit 1 Enable. TE1 enables the transfer of data from TX1 to the transmit shift register #1. When TE1 is set and a frame sync is detected, the transmit #1 portion of the ESAI is enabled for that frame. When TE1 is cleared, the transmitter #1 is disabled after completing transmission of data currently in the ESAI transmit shift register. The SDO1 output is tri-stated, and any data present in TX1 is not transmitted, that is, data can be written to TX1 with TE1 cleared, but data is not transferred to the transmit shift register #1. The normal mode transmit enable sequence is to write data to one or more transmit data registers before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In the network mode, the operation of clearing TE1 and setting it again disables the transmitter #1 after completing transmission of the current data word until the beginning of the next frame. During that time period, the SDO1 pin remains in the high-impedance state. The on-demand mode transmit enable sequence can be the same as the normal mode, or TE1 can be left enabled.
        unsigned TE2 : 1; //!< [2] ESAI_TCR ESAI Transmit 2 Enable. TE2 enables the transfer of data from ESAI_TX2 to the transmit shift register #2. When TE2 is set and a frame sync is detected, the transmit #2 portion of the ESAI is enabled for that frame. When TE2 is cleared, the transmitter #2 is disabled after completing transmission of data currently in the ESAI transmit shift register. Data can be written to ESAI_TX2 when TE2 is cleared but the data is not transferred to the transmit shift register #2. The SDO2/SDI3 pin is the data input pin for ESAI_RX3 if TE2 is cleared and RE3 in the ESAI_RCR register is set. If both RE3 and TE2 are cleared, the transmitter and receiver are disabled, and the pin is tri-stated. Both RE3 and TE2 should not be set at the same time. The normal mode transmit enable sequence is to write data to one or more transmit data registers before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In the network mode, the operation of clearing TE2 and setting it again disables the transmitter #2 after completing transmission of the current data word until the beginning of the next frame. During that time period, the SDO2/SDI3 pin remains in the high-impedance state. The on-demand mode transmit enable sequence can be the same as the normal mode, or TE2 can be left enabled.
        unsigned TE3 : 1; //!< [3] ESAI_TCR ESAI Transmit 3 Enable. TE3 enables the transfer of data from ESAI_TX3 to the transmit shift register #3. When TE3 is set and a frame sync is detected, the transmit #3 portion of the ESAI is enabled for that frame. When TE3 is cleared, the transmitter #3 is disabled after completing transmission of data currently in the ESAI transmit shift register. Data can be written to ESAI_TX3 when TE3 is cleared but the data is not transferred to the transmit shift register #3. The SDO3/SDI2 pin is the data input pin for ESAI_RX2 if TE3 is cleared and RE2 in the ESAI_RCR register is set. If both RE2 and TE3 are cleared, the transmitter and receiver are disabled, and the pin is tri-stated. Both RE2 and TE3 should not be set at the same time. The normal mode transmit enable sequence is to write data to one or more transmit data registers before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In the network mode, the operation of clearing TE3 and setting it again disables the transmitter #3 after completing transmission of the current data word until the beginning of the next frame. During that time period, the SDO3/SDI2 pin remains in the high-impedance state. The on-demand mode transmit enable sequence can be the same as the normal mode, or TE3 can be left enabled.
        unsigned TE4 : 1; //!< [4] ESAI_TCR ESAI Transmit 4 Enable. TE4 enables the transfer of data from ESAI_TX4 to the transmit shift register #4. When TE4 is set and a frame sync is detected, the transmit #4 portion of the ESAI is enabled for that frame. When TE4 is cleared, the transmitter #4 is disabled after completing transmission of data currently in the ESAI transmit shift register. Data can be written to ESAI_TX4 when TE4 is cleared but the data is not transferred to the transmit shift register #4. The SDO4/SDI1 pin is the data input pin for ESAI_RX1 if TE4 is cleared and RE1 in the RCR register is set. If both RE1 and TE4 are cleared, the transmitter and receiver are disabled, and the pin is tri-stated. Both RE1 and TE4 should not be set at the same time. The normal mode transmit enable sequence is to write data to one or more transmit data registers before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In the network mode, the operation of clearing TE4 and setting it again disables the transmitter #4 after completing transmission of the current data word until the beginning of the next frame. During that time period, the SDO4/SDI1 pin remains in the high-impedance state. The on-demand mode transmit enable sequence can be the same as the normal mode, or TE4 can be left enabled.
        unsigned TE5 : 1; //!< [5] ESAI_TCR ESAI Transmit 5 Enable. TE5 enables the transfer of data from ESAI_TX5 to the transmit shift register #5. When TE5 is set and a frame sync is detected, the transmit #5 portion of the ESAI is enabled for that frame. When TE5 is cleared, the transmitter #5 is disabled after completing transmission of data currently in the ESAI transmit shift register. Data can be written to ESAI_TX5 when TE5 is cleared but the data is not transferred to the transmit shift register #5. The SDO5/SDI0 pin is the data input pin for ESAI_RX0 if TE5 is cleared and RE0 in the ESAI_RCR register is set. If both RE0 and TE5 are cleared, the transmitter and receiver are disabled, and the pin is tri-stated. Both RE0 and TE5 should not be set at the same time. The normal mode transmit enable sequence is to write data to one or more transmit data registers before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In the network mode, the operation of clearing TE5 and setting it again disables the transmitter #5 after completing transmission of the current data word until the beginning of the next frame. During that time period, the SDO5/SDI0 pin remains in the high-impedance state. The on-demand mode transmit enable sequence can be the same as the normal mode, or TE5 can be left enabled.
        unsigned TSHFD : 1; //!< [6] ESAI_TCR Transmit Shift Direction. The TSHFD bit causes the transmit shift registers to shift data out MSB first when TSHFD equals zero or LSB first when TSHFD equals one (see and .
        unsigned TWA : 1; //!< [7] ESAI_TCR Transmit Word Alignment Control. The Transmitter Word Alignment Control (TWA) bit defines the alignment of the data word in relation to the slot. This is relevant for the cases where the word length is shorter than the slot length. If TWA is cleared, the data word is left-aligned in the slot frame during transmission. If TWA is set, the data word is right-aligned in the slot frame during transmission. Because the data word is shorter than the slot length, the data word is extended until achieving the slot length, according to the following rule: If the data word is left-aligned (TWA=0), and zero padding is disabled (PADC=0), the last data bit is repeated after the data word has been transmitted. If zero padding is enabled (PADC=1), zeroes are transmitted after the data word has been transmitted. If the data word is right-aligned (TWA=1), and zero padding is disabled (PADC=0), the first data bit is repeated before the transmission of the data word. If zero padding is enabled (PADC=1), zeroes are transmitted before the transmission of the data word.
        unsigned TMOD : 2; //!< [9:8] ESAI_TCR Transmit Network Mode Control (TMOD1-TMOD0). The TMOD1 and TMOD0 bits are used to define the network mode of ESAI transmitters, as shown in Port C Control Register . In the normal mode, the frame rate divider determines the word transfer rate - one word is transferred per frame sync during the frame sync time slot, as shown in . In network mode, it is possible to transfer a word for every time slot, as shown in . For further details, refer to In order to comply with AC-97 specifications, TSWS4-TSWS0 should be set to 00011 (20-bit slot, 20-bit word length), TFSL and TFSR should be cleared, and TDC4-TDC0 should be set to 0x0C (13 words in frame). If TMOD[1:0]=0b11 and the above recommendations are followed, the first slot and word will be 16 bits long, and the next 12 slots and words will be 20 bits long, as required by the AC97 protocol.
        unsigned TSWS : 5; //!< [14:10] ESAI_TCR Tx Slot and Word Length Select (TSWS4-TSWS0). The TSWS4-TSWS0 bits are used to select the length of the slot and the length of the data words being transferred through the ESAI. The word length must be equal to or shorter than the slot length. The possible combinations are shown in . See also the ESAI data path programming model in and .
        unsigned TFSL : 1; //!< [15] ESAI_TCR Transmit Frame Sync Length. The TFSL bit selects the length of frame sync to be generated or recognized. If TFSL is cleared, a word-length frame sync is selected. If TFSL is set, a 1-bit clock period frame sync is selected. See Figure 1-21 for examples of frame length selection.
        unsigned TFSR : 1; //!< [16] ESAI_TCR Transmit Frame Sync Relative Timing. TFSR determines the relative timing of the transmit frame sync signal as referred to the serial data lines, for a word length frame sync only (TFSL=0). When TFSR is cleared the word length frame sync occurs together with the first bit of the data word of the first slot. When TFSR is set the word length frame sync starts one serial clock cycle earlier, that is, together with the last bit of the previous data word.
        unsigned PADC : 1; //!< [17] ESAI_TCR Transmit Zero Padding Control. When PADC is cleared, zero padding is disabled. When PADC is set, zero padding is enabled. PADC, in conjunction with the TWA control bit, determines the way that padding is done for operating modes where the word length is less than the slot length. See the TWA bit description in bit 7 for more details. Because the data word is shorter than the slot length, the data word is extended until achieving the slot length, according to the following rule: If the data word is left-aligned (TWA=0), and zero padding is disabled (PADC=0), the last data bit is repeated after the data word has been transmitted. If zero padding is enabled (PADC=1), zeroes are transmitted after the data word has been transmitted. If the data word is right-aligned (TWA=1), and zero padding is disabled (PADC=0), the first data bit is repeated before the transmission of the data word. If zero padding is enabled (PADC=1), zeroes are transmitted before the transmission of the data word.
        unsigned RESERVED0 : 1; //!< [18] Reserved.
        unsigned TPR : 1; //!< [19] ESAI_TCR Transmit Section Personal Reset. The TPR control bit is used to put the transmitter section of the ESAI in the personal reset state. The receiver section is not affected. When TPR is cleared, the transmitter section may operate normally. When TPR is set, the transmitter section enters the personal reset state immediately. When in the personal reset state, the status bits are reset to the same state as after hardware reset. The control bits are not affected by the personal reset state. The transmitter data pins are tri-stated while in the personal reset state; if a stable logic level is desired, the transmitter data pins should be defined as GPIO outputs, or external pull-up or pull-down resistors should be used. The transmitter clock outputs drive zeroes while in the personal reset state. Note that to leave the personal reset state by clearing TPR, the procedure described in should be followed.
        unsigned TEIE : 1; //!< [20] ESAI_TCR Transmit Exception Interrupt Enable. When TEIE is set, the Core is interrupted when both TDE and TUE in the ESAI_SAISR status register are set. When TEIE is cleared, this interrupt is disabled. Reading the ESAI_SAISR status register followed by writing to all the data registers of the enabled transmitters clears TUE, thus clearing the pending interrupt.
        unsigned TEDIE : 1; //!< [21] ESAI_TCR Transmit Even Slot Data Interrupt Enable. The TEDIE control bit is used to enable the transmit even slot data interrupts. If TEDIE is set, the transmit even slot data interrupts are enabled. If TEDIE is cleared, the transmit even slot data interrupts are disabled. A transmit even slot data interrupt request is generated if TEDIE is set and the TEDE status flag in the ESAI_SAISR status register is set. Even time slots are all even-numbered time slots (0, 2, 4, etc.) when operating in network mode. The zero time slot in the frame is marked by the frame sync signal and is considered to be even. Writing data to all the data registers of the enabled transmitters or to ESAI_TSR clears the TEDE flag, thus servicing the interrupt. Transmit interrupts with exception have higher priority than transmit even slot data interrupts, therefore if exception occurs (TUE is set) and TEIE is set, the ESAI requests an ESAI transmit data with exception interrupt from the interrupt controller.
        unsigned TIE : 1; //!< [22] ESAI_TCR Transmit Interrupt Enable. The Core is interrupted when TIE and the TDE flag in the ESAI_SAISR status register are set. When TIE is cleared, this interrupt is disabled. Writing data to all the data registers of the enabled transmitters or to ESAI_TSR clears TDE, thus clearing the interrupt. Transmit interrupts with exception have higher priority than normal transmit data interrupts, therefore if exception occurs (TUE is set) and TEIE is set, the ESAI requests an ESAI transmit data with exception interrupt from the interrupt controller.
        unsigned TLIE : 1; //!< [23] ESAI_TCR Transmit Last Slot Interrupt Enable. TLIE enables an interrupt at the beginning of last slot of a frame in network mode. When TLIE is set the Core is interrupted at the start of the last slot in a frame in network mode regardless of the transmit mask register setting. When TLIE is cleared the transmit last slot interrupt is disabled. TLIE is disabled when TDC[4:0]=0x00000 (on-demand mode). The use of the transmit last slot interrupt is described in .
        unsigned RESERVED1 : 8; //!< [31:24] Reserved.
    } B;
} hw_esai_tcr_t;
#endif

/*
 * constants & macros for entire ESAI_TCR register
 */
#define HW_ESAI_TCR_ADDR      (REGS_ESAI_BASE + 0xd4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TCR           (*(volatile hw_esai_tcr_t *) HW_ESAI_TCR_ADDR)
#define HW_ESAI_TCR_RD()      (HW_ESAI_TCR.U)
#define HW_ESAI_TCR_WR(v)     (HW_ESAI_TCR.U = (v))
#define HW_ESAI_TCR_SET(v)    (HW_ESAI_TCR_WR(HW_ESAI_TCR_RD() |  (v)))
#define HW_ESAI_TCR_CLR(v)    (HW_ESAI_TCR_WR(HW_ESAI_TCR_RD() & ~(v)))
#define HW_ESAI_TCR_TOG(v)    (HW_ESAI_TCR_WR(HW_ESAI_TCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_TCR bitfields
 */

/* --- Register HW_ESAI_TCR, field TE0[0] (RW)
 *
 * ESAI_TCR ESAI Transmit 0 Enable. TE0 enables the transfer of data from ESAI_TX0 to the transmit
 * shift register #0. When TE0 is set and a frame sync is detected, the transmit #0 portion of the
 * ESAI is enabled for that frame. When TE0 is cleared, the transmitter #0 is disabled after
 * completing transmission of data currently in the ESAI transmit shift register. The SDO0 output is
 * tri-stated, and any data present in ESAI_TX0 is not transmitted, that is, data can be written to
 * ESAI_TX0 with TE0 cleared, but data is not transferred to the transmit shift register #0. The
 * normal mode transmit enable sequence is to write data to one or more transmit data registers
 * before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE
 * equals one. In the network mode, the operation of clearing TE0 and setting it again disables the
 * transmitter #0 after completing transmission of the current data word until the beginning of the
 * next frame. During that time period, the SDO0 pin remains in the high-impedance state.The on-
 * demand mode transmit enable sequence can be the same as the normal mode, or TE0 can be left
 * enabled.
 */

#define BP_ESAI_TCR_TE0      (0)      //!< Bit position for ESAI_TCR_TE0.
#define BM_ESAI_TCR_TE0      (0x00000001)  //!< Bit mask for ESAI_TCR_TE0.

//! @brief Get value of ESAI_TCR_TE0 from a register value.
#define BG_ESAI_TCR_TE0(r)   (((r) & BM_ESAI_TCR_TE0) >> BP_ESAI_TCR_TE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TE0.
#define BF_ESAI_TCR_TE0(v)   ((((reg32_t) v) << BP_ESAI_TCR_TE0) & BM_ESAI_TCR_TE0)
#else
//! @brief Format value for bitfield ESAI_TCR_TE0.
#define BF_ESAI_TCR_TE0(v)   (((v) << BP_ESAI_TCR_TE0) & BM_ESAI_TCR_TE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE0 field to a new value.
#define BW_ESAI_TCR_TE0(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TE0) | BF_ESAI_TCR_TE0(v)))
#endif

/* --- Register HW_ESAI_TCR, field TE1[1] (RW)
 *
 * ESAI_TCR ESAI Transmit 1 Enable. TE1 enables the transfer of data from TX1 to the transmit shift
 * register #1. When TE1 is set and a frame sync is detected, the transmit #1 portion of the ESAI is
 * enabled for that frame. When TE1 is cleared, the transmitter #1 is disabled after completing
 * transmission of data currently in the ESAI transmit shift register. The SDO1 output is tri-
 * stated, and any data present in TX1 is not transmitted, that is, data can be written to TX1 with
 * TE1 cleared, but data is not transferred to the transmit shift register #1. The normal mode
 * transmit enable sequence is to write data to one or more transmit data registers before setting
 * TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE equals one. In
 * the network mode, the operation of clearing TE1 and setting it again disables the transmitter #1
 * after completing transmission of the current data word until the beginning of the next frame.
 * During that time period, the SDO1 pin remains in the high-impedance state. The on-demand mode
 * transmit enable sequence can be the same as the normal mode, or TE1 can be left enabled.
 */

#define BP_ESAI_TCR_TE1      (1)      //!< Bit position for ESAI_TCR_TE1.
#define BM_ESAI_TCR_TE1      (0x00000002)  //!< Bit mask for ESAI_TCR_TE1.

//! @brief Get value of ESAI_TCR_TE1 from a register value.
#define BG_ESAI_TCR_TE1(r)   (((r) & BM_ESAI_TCR_TE1) >> BP_ESAI_TCR_TE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TE1.
#define BF_ESAI_TCR_TE1(v)   ((((reg32_t) v) << BP_ESAI_TCR_TE1) & BM_ESAI_TCR_TE1)
#else
//! @brief Format value for bitfield ESAI_TCR_TE1.
#define BF_ESAI_TCR_TE1(v)   (((v) << BP_ESAI_TCR_TE1) & BM_ESAI_TCR_TE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE1 field to a new value.
#define BW_ESAI_TCR_TE1(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TE1) | BF_ESAI_TCR_TE1(v)))
#endif

/* --- Register HW_ESAI_TCR, field TE2[2] (RW)
 *
 * ESAI_TCR ESAI Transmit 2 Enable. TE2 enables the transfer of data from ESAI_TX2 to the transmit
 * shift register #2. When TE2 is set and a frame sync is detected, the transmit #2 portion of the
 * ESAI is enabled for that frame. When TE2 is cleared, the transmitter #2 is disabled after
 * completing transmission of data currently in the ESAI transmit shift register. Data can be
 * written to ESAI_TX2 when TE2 is cleared but the data is not transferred to the transmit shift
 * register #2. The SDO2/SDI3 pin is the data input pin for ESAI_RX3 if TE2 is cleared and RE3 in
 * the ESAI_RCR register is set. If both RE3 and TE2 are cleared, the transmitter and receiver are
 * disabled, and the pin is tri-stated. Both RE3 and TE2 should not be set at the same time. The
 * normal mode transmit enable sequence is to write data to one or more transmit data registers
 * before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE
 * equals one. In the network mode, the operation of clearing TE2 and setting it again disables the
 * transmitter #2 after completing transmission of the current data word until the beginning of the
 * next frame. During that time period, the SDO2/SDI3 pin remains in the high-impedance state. The
 * on-demand mode transmit enable sequence can be the same as the normal mode, or TE2 can be left
 * enabled.
 */

#define BP_ESAI_TCR_TE2      (2)      //!< Bit position for ESAI_TCR_TE2.
#define BM_ESAI_TCR_TE2      (0x00000004)  //!< Bit mask for ESAI_TCR_TE2.

//! @brief Get value of ESAI_TCR_TE2 from a register value.
#define BG_ESAI_TCR_TE2(r)   (((r) & BM_ESAI_TCR_TE2) >> BP_ESAI_TCR_TE2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TE2.
#define BF_ESAI_TCR_TE2(v)   ((((reg32_t) v) << BP_ESAI_TCR_TE2) & BM_ESAI_TCR_TE2)
#else
//! @brief Format value for bitfield ESAI_TCR_TE2.
#define BF_ESAI_TCR_TE2(v)   (((v) << BP_ESAI_TCR_TE2) & BM_ESAI_TCR_TE2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE2 field to a new value.
#define BW_ESAI_TCR_TE2(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TE2) | BF_ESAI_TCR_TE2(v)))
#endif

/* --- Register HW_ESAI_TCR, field TE3[3] (RW)
 *
 * ESAI_TCR ESAI Transmit 3 Enable. TE3 enables the transfer of data from ESAI_TX3 to the transmit
 * shift register #3. When TE3 is set and a frame sync is detected, the transmit #3 portion of the
 * ESAI is enabled for that frame. When TE3 is cleared, the transmitter #3 is disabled after
 * completing transmission of data currently in the ESAI transmit shift register. Data can be
 * written to ESAI_TX3 when TE3 is cleared but the data is not transferred to the transmit shift
 * register #3. The SDO3/SDI2 pin is the data input pin for ESAI_RX2 if TE3 is cleared and RE2 in
 * the ESAI_RCR register is set. If both RE2 and TE3 are cleared, the transmitter and receiver are
 * disabled, and the pin is tri-stated. Both RE2 and TE3 should not be set at the same time. The
 * normal mode transmit enable sequence is to write data to one or more transmit data registers
 * before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE
 * equals one. In the network mode, the operation of clearing TE3 and setting it again disables the
 * transmitter #3 after completing transmission of the current data word until the beginning of the
 * next frame. During that time period, the SDO3/SDI2 pin remains in the high-impedance state. The
 * on-demand mode transmit enable sequence can be the same as the normal mode, or TE3 can be left
 * enabled.
 */

#define BP_ESAI_TCR_TE3      (3)      //!< Bit position for ESAI_TCR_TE3.
#define BM_ESAI_TCR_TE3      (0x00000008)  //!< Bit mask for ESAI_TCR_TE3.

//! @brief Get value of ESAI_TCR_TE3 from a register value.
#define BG_ESAI_TCR_TE3(r)   (((r) & BM_ESAI_TCR_TE3) >> BP_ESAI_TCR_TE3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TE3.
#define BF_ESAI_TCR_TE3(v)   ((((reg32_t) v) << BP_ESAI_TCR_TE3) & BM_ESAI_TCR_TE3)
#else
//! @brief Format value for bitfield ESAI_TCR_TE3.
#define BF_ESAI_TCR_TE3(v)   (((v) << BP_ESAI_TCR_TE3) & BM_ESAI_TCR_TE3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE3 field to a new value.
#define BW_ESAI_TCR_TE3(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TE3) | BF_ESAI_TCR_TE3(v)))
#endif

/* --- Register HW_ESAI_TCR, field TE4[4] (RW)
 *
 * ESAI_TCR ESAI Transmit 4 Enable. TE4 enables the transfer of data from ESAI_TX4 to the transmit
 * shift register #4. When TE4 is set and a frame sync is detected, the transmit #4 portion of the
 * ESAI is enabled for that frame. When TE4 is cleared, the transmitter #4 is disabled after
 * completing transmission of data currently in the ESAI transmit shift register. Data can be
 * written to ESAI_TX4 when TE4 is cleared but the data is not transferred to the transmit shift
 * register #4. The SDO4/SDI1 pin is the data input pin for ESAI_RX1 if TE4 is cleared and RE1 in
 * the RCR register is set. If both RE1 and TE4 are cleared, the transmitter and receiver are
 * disabled, and the pin is tri-stated. Both RE1 and TE4 should not be set at the same time. The
 * normal mode transmit enable sequence is to write data to one or more transmit data registers
 * before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE
 * equals one. In the network mode, the operation of clearing TE4 and setting it again disables the
 * transmitter #4 after completing transmission of the current data word until the beginning of the
 * next frame. During that time period, the SDO4/SDI1 pin remains in the high-impedance state. The
 * on-demand mode transmit enable sequence can be the same as the normal mode, or TE4 can be left
 * enabled.
 */

#define BP_ESAI_TCR_TE4      (4)      //!< Bit position for ESAI_TCR_TE4.
#define BM_ESAI_TCR_TE4      (0x00000010)  //!< Bit mask for ESAI_TCR_TE4.

//! @brief Get value of ESAI_TCR_TE4 from a register value.
#define BG_ESAI_TCR_TE4(r)   (((r) & BM_ESAI_TCR_TE4) >> BP_ESAI_TCR_TE4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TE4.
#define BF_ESAI_TCR_TE4(v)   ((((reg32_t) v) << BP_ESAI_TCR_TE4) & BM_ESAI_TCR_TE4)
#else
//! @brief Format value for bitfield ESAI_TCR_TE4.
#define BF_ESAI_TCR_TE4(v)   (((v) << BP_ESAI_TCR_TE4) & BM_ESAI_TCR_TE4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE4 field to a new value.
#define BW_ESAI_TCR_TE4(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TE4) | BF_ESAI_TCR_TE4(v)))
#endif

/* --- Register HW_ESAI_TCR, field TE5[5] (RW)
 *
 * ESAI_TCR ESAI Transmit 5 Enable. TE5 enables the transfer of data from ESAI_TX5 to the transmit
 * shift register #5. When TE5 is set and a frame sync is detected, the transmit #5 portion of the
 * ESAI is enabled for that frame. When TE5 is cleared, the transmitter #5 is disabled after
 * completing transmission of data currently in the ESAI transmit shift register. Data can be
 * written to ESAI_TX5 when TE5 is cleared but the data is not transferred to the transmit shift
 * register #5. The SDO5/SDI0 pin is the data input pin for ESAI_RX0 if TE5 is cleared and RE0 in
 * the ESAI_RCR register is set. If both RE0 and TE5 are cleared, the transmitter and receiver are
 * disabled, and the pin is tri-stated. Both RE0 and TE5 should not be set at the same time. The
 * normal mode transmit enable sequence is to write data to one or more transmit data registers
 * before setting TEx. The normal transmit disable sequence is to clear TEx, TIE and TEIE after TDE
 * equals one. In the network mode, the operation of clearing TE5 and setting it again disables the
 * transmitter #5 after completing transmission of the current data word until the beginning of the
 * next frame. During that time period, the SDO5/SDI0 pin remains in the high-impedance state. The
 * on-demand mode transmit enable sequence can be the same as the normal mode, or TE5 can be left
 * enabled.
 */

#define BP_ESAI_TCR_TE5      (5)      //!< Bit position for ESAI_TCR_TE5.
#define BM_ESAI_TCR_TE5      (0x00000020)  //!< Bit mask for ESAI_TCR_TE5.

//! @brief Get value of ESAI_TCR_TE5 from a register value.
#define BG_ESAI_TCR_TE5(r)   (((r) & BM_ESAI_TCR_TE5) >> BP_ESAI_TCR_TE5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TE5.
#define BF_ESAI_TCR_TE5(v)   ((((reg32_t) v) << BP_ESAI_TCR_TE5) & BM_ESAI_TCR_TE5)
#else
//! @brief Format value for bitfield ESAI_TCR_TE5.
#define BF_ESAI_TCR_TE5(v)   (((v) << BP_ESAI_TCR_TE5) & BM_ESAI_TCR_TE5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TE5 field to a new value.
#define BW_ESAI_TCR_TE5(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TE5) | BF_ESAI_TCR_TE5(v)))
#endif

/* --- Register HW_ESAI_TCR, field TSHFD[6] (RW)
 *
 * ESAI_TCR Transmit Shift Direction. The TSHFD bit causes the transmit shift registers to shift
 * data out MSB first when TSHFD equals zero or LSB first when TSHFD equals one (see and .
 */

#define BP_ESAI_TCR_TSHFD      (6)      //!< Bit position for ESAI_TCR_TSHFD.
#define BM_ESAI_TCR_TSHFD      (0x00000040)  //!< Bit mask for ESAI_TCR_TSHFD.

//! @brief Get value of ESAI_TCR_TSHFD from a register value.
#define BG_ESAI_TCR_TSHFD(r)   (((r) & BM_ESAI_TCR_TSHFD) >> BP_ESAI_TCR_TSHFD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TSHFD.
#define BF_ESAI_TCR_TSHFD(v)   ((((reg32_t) v) << BP_ESAI_TCR_TSHFD) & BM_ESAI_TCR_TSHFD)
#else
//! @brief Format value for bitfield ESAI_TCR_TSHFD.
#define BF_ESAI_TCR_TSHFD(v)   (((v) << BP_ESAI_TCR_TSHFD) & BM_ESAI_TCR_TSHFD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSHFD field to a new value.
#define BW_ESAI_TCR_TSHFD(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TSHFD) | BF_ESAI_TCR_TSHFD(v)))
#endif

/* --- Register HW_ESAI_TCR, field TWA[7] (RW)
 *
 * ESAI_TCR Transmit Word Alignment Control. The Transmitter Word Alignment Control (TWA) bit
 * defines the alignment of the data word in relation to the slot. This is relevant for the cases
 * where the word length is shorter than the slot length. If TWA is cleared, the data word is left-
 * aligned in the slot frame during transmission. If TWA is set, the data word is right-aligned in
 * the slot frame during transmission. Because the data word is shorter than the slot length, the
 * data word is extended until achieving the slot length, according to the following rule: If the
 * data word is left-aligned (TWA=0), and zero padding is disabled (PADC=0), the last data bit is
 * repeated after the data word has been transmitted. If zero padding is enabled (PADC=1), zeroes
 * are transmitted after the data word has been transmitted. If the data word is right-aligned
 * (TWA=1), and zero padding is disabled (PADC=0), the first data bit is repeated before the
 * transmission of the data word. If zero padding is enabled (PADC=1), zeroes are transmitted before
 * the transmission of the data word.
 */

#define BP_ESAI_TCR_TWA      (7)      //!< Bit position for ESAI_TCR_TWA.
#define BM_ESAI_TCR_TWA      (0x00000080)  //!< Bit mask for ESAI_TCR_TWA.

//! @brief Get value of ESAI_TCR_TWA from a register value.
#define BG_ESAI_TCR_TWA(r)   (((r) & BM_ESAI_TCR_TWA) >> BP_ESAI_TCR_TWA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TWA.
#define BF_ESAI_TCR_TWA(v)   ((((reg32_t) v) << BP_ESAI_TCR_TWA) & BM_ESAI_TCR_TWA)
#else
//! @brief Format value for bitfield ESAI_TCR_TWA.
#define BF_ESAI_TCR_TWA(v)   (((v) << BP_ESAI_TCR_TWA) & BM_ESAI_TCR_TWA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TWA field to a new value.
#define BW_ESAI_TCR_TWA(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TWA) | BF_ESAI_TCR_TWA(v)))
#endif

/* --- Register HW_ESAI_TCR, field TMOD[9:8] (RW)
 *
 * ESAI_TCR Transmit Network Mode Control (TMOD1-TMOD0). The TMOD1 and TMOD0 bits are used to define
 * the network mode of ESAI transmitters, as shown in Port C Control Register . In the normal mode,
 * the frame rate divider determines the word transfer rate - one word is transferred per frame sync
 * during the frame sync time slot, as shown in . In network mode, it is possible to transfer a word
 * for every time slot, as shown in . For further details, refer to In order to comply with AC-97
 * specifications, TSWS4-TSWS0 should be set to 00011 (20-bit slot, 20-bit word length), TFSL and
 * TFSR should be cleared, and TDC4-TDC0 should be set to 0x0C (13 words in frame). If
 * TMOD[1:0]=0b11 and the above recommendations are followed, the first slot and word will be 16
 * bits long, and the next 12 slots and words will be 20 bits long, as required by the AC97
 * protocol.
 */

#define BP_ESAI_TCR_TMOD      (8)      //!< Bit position for ESAI_TCR_TMOD.
#define BM_ESAI_TCR_TMOD      (0x00000300)  //!< Bit mask for ESAI_TCR_TMOD.

//! @brief Get value of ESAI_TCR_TMOD from a register value.
#define BG_ESAI_TCR_TMOD(r)   (((r) & BM_ESAI_TCR_TMOD) >> BP_ESAI_TCR_TMOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TMOD.
#define BF_ESAI_TCR_TMOD(v)   ((((reg32_t) v) << BP_ESAI_TCR_TMOD) & BM_ESAI_TCR_TMOD)
#else
//! @brief Format value for bitfield ESAI_TCR_TMOD.
#define BF_ESAI_TCR_TMOD(v)   (((v) << BP_ESAI_TCR_TMOD) & BM_ESAI_TCR_TMOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TMOD field to a new value.
#define BW_ESAI_TCR_TMOD(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TMOD) | BF_ESAI_TCR_TMOD(v)))
#endif

/* --- Register HW_ESAI_TCR, field TSWS[14:10] (RW)
 *
 * ESAI_TCR Tx Slot and Word Length Select (TSWS4-TSWS0). The TSWS4-TSWS0 bits are used to select
 * the length of the slot and the length of the data words being transferred through the ESAI. The
 * word length must be equal to or shorter than the slot length. The possible combinations are shown
 * in . See also the ESAI data path programming model in and .
 */

#define BP_ESAI_TCR_TSWS      (10)      //!< Bit position for ESAI_TCR_TSWS.
#define BM_ESAI_TCR_TSWS      (0x00007c00)  //!< Bit mask for ESAI_TCR_TSWS.

//! @brief Get value of ESAI_TCR_TSWS from a register value.
#define BG_ESAI_TCR_TSWS(r)   (((r) & BM_ESAI_TCR_TSWS) >> BP_ESAI_TCR_TSWS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TSWS.
#define BF_ESAI_TCR_TSWS(v)   ((((reg32_t) v) << BP_ESAI_TCR_TSWS) & BM_ESAI_TCR_TSWS)
#else
//! @brief Format value for bitfield ESAI_TCR_TSWS.
#define BF_ESAI_TCR_TSWS(v)   (((v) << BP_ESAI_TCR_TSWS) & BM_ESAI_TCR_TSWS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSWS field to a new value.
#define BW_ESAI_TCR_TSWS(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TSWS) | BF_ESAI_TCR_TSWS(v)))
#endif

/* --- Register HW_ESAI_TCR, field TFSL[15] (RW)
 *
 * ESAI_TCR Transmit Frame Sync Length. The TFSL bit selects the length of frame sync to be
 * generated or recognized. If TFSL is cleared, a word-length frame sync is selected. If TFSL is
 * set, a 1-bit clock period frame sync is selected. See Figure 1-21 for examples of frame length
 * selection.
 */

#define BP_ESAI_TCR_TFSL      (15)      //!< Bit position for ESAI_TCR_TFSL.
#define BM_ESAI_TCR_TFSL      (0x00008000)  //!< Bit mask for ESAI_TCR_TFSL.

//! @brief Get value of ESAI_TCR_TFSL from a register value.
#define BG_ESAI_TCR_TFSL(r)   (((r) & BM_ESAI_TCR_TFSL) >> BP_ESAI_TCR_TFSL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TFSL.
#define BF_ESAI_TCR_TFSL(v)   ((((reg32_t) v) << BP_ESAI_TCR_TFSL) & BM_ESAI_TCR_TFSL)
#else
//! @brief Format value for bitfield ESAI_TCR_TFSL.
#define BF_ESAI_TCR_TFSL(v)   (((v) << BP_ESAI_TCR_TFSL) & BM_ESAI_TCR_TFSL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSL field to a new value.
#define BW_ESAI_TCR_TFSL(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TFSL) | BF_ESAI_TCR_TFSL(v)))
#endif

/* --- Register HW_ESAI_TCR, field TFSR[16] (RW)
 *
 * ESAI_TCR Transmit Frame Sync Relative Timing. TFSR determines the relative timing of the transmit
 * frame sync signal as referred to the serial data lines, for a word length frame sync only
 * (TFSL=0). When TFSR is cleared the word length frame sync occurs together with the first bit of
 * the data word of the first slot. When TFSR is set the word length frame sync starts one serial
 * clock cycle earlier, that is, together with the last bit of the previous data word.
 */

#define BP_ESAI_TCR_TFSR      (16)      //!< Bit position for ESAI_TCR_TFSR.
#define BM_ESAI_TCR_TFSR      (0x00010000)  //!< Bit mask for ESAI_TCR_TFSR.

//! @brief Get value of ESAI_TCR_TFSR from a register value.
#define BG_ESAI_TCR_TFSR(r)   (((r) & BM_ESAI_TCR_TFSR) >> BP_ESAI_TCR_TFSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TFSR.
#define BF_ESAI_TCR_TFSR(v)   ((((reg32_t) v) << BP_ESAI_TCR_TFSR) & BM_ESAI_TCR_TFSR)
#else
//! @brief Format value for bitfield ESAI_TCR_TFSR.
#define BF_ESAI_TCR_TFSR(v)   (((v) << BP_ESAI_TCR_TFSR) & BM_ESAI_TCR_TFSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSR field to a new value.
#define BW_ESAI_TCR_TFSR(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TFSR) | BF_ESAI_TCR_TFSR(v)))
#endif

/* --- Register HW_ESAI_TCR, field PADC[17] (RW)
 *
 * ESAI_TCR Transmit Zero Padding Control. When PADC is cleared, zero padding is disabled. When PADC
 * is set, zero padding is enabled. PADC, in conjunction with the TWA control bit, determines the
 * way that padding is done for operating modes where the word length is less than the slot length.
 * See the TWA bit description in bit 7 for more details. Because the data word is shorter than the
 * slot length, the data word is extended until achieving the slot length, according to the
 * following rule: If the data word is left-aligned (TWA=0), and zero padding is disabled (PADC=0),
 * the last data bit is repeated after the data word has been transmitted. If zero padding is
 * enabled (PADC=1), zeroes are transmitted after the data word has been transmitted. If the data
 * word is right-aligned (TWA=1), and zero padding is disabled (PADC=0), the first data bit is
 * repeated before the transmission of the data word. If zero padding is enabled (PADC=1), zeroes
 * are transmitted before the transmission of the data word.
 */

#define BP_ESAI_TCR_PADC      (17)      //!< Bit position for ESAI_TCR_PADC.
#define BM_ESAI_TCR_PADC      (0x00020000)  //!< Bit mask for ESAI_TCR_PADC.

//! @brief Get value of ESAI_TCR_PADC from a register value.
#define BG_ESAI_TCR_PADC(r)   (((r) & BM_ESAI_TCR_PADC) >> BP_ESAI_TCR_PADC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_PADC.
#define BF_ESAI_TCR_PADC(v)   ((((reg32_t) v) << BP_ESAI_TCR_PADC) & BM_ESAI_TCR_PADC)
#else
//! @brief Format value for bitfield ESAI_TCR_PADC.
#define BF_ESAI_TCR_PADC(v)   (((v) << BP_ESAI_TCR_PADC) & BM_ESAI_TCR_PADC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PADC field to a new value.
#define BW_ESAI_TCR_PADC(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_PADC) | BF_ESAI_TCR_PADC(v)))
#endif

/* --- Register HW_ESAI_TCR, field TPR[19] (RW)
 *
 * ESAI_TCR Transmit Section Personal Reset. The TPR control bit is used to put the transmitter
 * section of the ESAI in the personal reset state. The receiver section is not affected. When TPR
 * is cleared, the transmitter section may operate normally. When TPR is set, the transmitter
 * section enters the personal reset state immediately. When in the personal reset state, the status
 * bits are reset to the same state as after hardware reset. The control bits are not affected by
 * the personal reset state. The transmitter data pins are tri-stated while in the personal reset
 * state; if a stable logic level is desired, the transmitter data pins should be defined as GPIO
 * outputs, or external pull-up or pull-down resistors should be used. The transmitter clock outputs
 * drive zeroes while in the personal reset state. Note that to leave the personal reset state by
 * clearing TPR, the procedure described in should be followed.
 */

#define BP_ESAI_TCR_TPR      (19)      //!< Bit position for ESAI_TCR_TPR.
#define BM_ESAI_TCR_TPR      (0x00080000)  //!< Bit mask for ESAI_TCR_TPR.

//! @brief Get value of ESAI_TCR_TPR from a register value.
#define BG_ESAI_TCR_TPR(r)   (((r) & BM_ESAI_TCR_TPR) >> BP_ESAI_TCR_TPR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TPR.
#define BF_ESAI_TCR_TPR(v)   ((((reg32_t) v) << BP_ESAI_TCR_TPR) & BM_ESAI_TCR_TPR)
#else
//! @brief Format value for bitfield ESAI_TCR_TPR.
#define BF_ESAI_TCR_TPR(v)   (((v) << BP_ESAI_TCR_TPR) & BM_ESAI_TCR_TPR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TPR field to a new value.
#define BW_ESAI_TCR_TPR(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TPR) | BF_ESAI_TCR_TPR(v)))
#endif

/* --- Register HW_ESAI_TCR, field TEIE[20] (RW)
 *
 * ESAI_TCR Transmit Exception Interrupt Enable. When TEIE is set, the Core is interrupted when both
 * TDE and TUE in the ESAI_SAISR status register are set. When TEIE is cleared, this interrupt is
 * disabled. Reading the ESAI_SAISR status register followed by writing to all the data registers of
 * the enabled transmitters clears TUE, thus clearing the pending interrupt.
 */

#define BP_ESAI_TCR_TEIE      (20)      //!< Bit position for ESAI_TCR_TEIE.
#define BM_ESAI_TCR_TEIE      (0x00100000)  //!< Bit mask for ESAI_TCR_TEIE.

//! @brief Get value of ESAI_TCR_TEIE from a register value.
#define BG_ESAI_TCR_TEIE(r)   (((r) & BM_ESAI_TCR_TEIE) >> BP_ESAI_TCR_TEIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TEIE.
#define BF_ESAI_TCR_TEIE(v)   ((((reg32_t) v) << BP_ESAI_TCR_TEIE) & BM_ESAI_TCR_TEIE)
#else
//! @brief Format value for bitfield ESAI_TCR_TEIE.
#define BF_ESAI_TCR_TEIE(v)   (((v) << BP_ESAI_TCR_TEIE) & BM_ESAI_TCR_TEIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEIE field to a new value.
#define BW_ESAI_TCR_TEIE(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TEIE) | BF_ESAI_TCR_TEIE(v)))
#endif

/* --- Register HW_ESAI_TCR, field TEDIE[21] (RW)
 *
 * ESAI_TCR Transmit Even Slot Data Interrupt Enable. The TEDIE control bit is used to enable the
 * transmit even slot data interrupts. If TEDIE is set, the transmit even slot data interrupts are
 * enabled. If TEDIE is cleared, the transmit even slot data interrupts are disabled. A transmit
 * even slot data interrupt request is generated if TEDIE is set and the TEDE status flag in the
 * ESAI_SAISR status register is set. Even time slots are all even-numbered time slots (0, 2, 4,
 * etc.) when operating in network mode. The zero time slot in the frame is marked by the frame sync
 * signal and is considered to be even. Writing data to all the data registers of the enabled
 * transmitters or to ESAI_TSR clears the TEDE flag, thus servicing the interrupt. Transmit
 * interrupts with exception have higher priority than transmit even slot data interrupts, therefore
 * if exception occurs (TUE is set) and TEIE is set, the ESAI requests an ESAI transmit data with
 * exception interrupt from the interrupt controller.
 */

#define BP_ESAI_TCR_TEDIE      (21)      //!< Bit position for ESAI_TCR_TEDIE.
#define BM_ESAI_TCR_TEDIE      (0x00200000)  //!< Bit mask for ESAI_TCR_TEDIE.

//! @brief Get value of ESAI_TCR_TEDIE from a register value.
#define BG_ESAI_TCR_TEDIE(r)   (((r) & BM_ESAI_TCR_TEDIE) >> BP_ESAI_TCR_TEDIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TEDIE.
#define BF_ESAI_TCR_TEDIE(v)   ((((reg32_t) v) << BP_ESAI_TCR_TEDIE) & BM_ESAI_TCR_TEDIE)
#else
//! @brief Format value for bitfield ESAI_TCR_TEDIE.
#define BF_ESAI_TCR_TEDIE(v)   (((v) << BP_ESAI_TCR_TEDIE) & BM_ESAI_TCR_TEDIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEDIE field to a new value.
#define BW_ESAI_TCR_TEDIE(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TEDIE) | BF_ESAI_TCR_TEDIE(v)))
#endif

/* --- Register HW_ESAI_TCR, field TIE[22] (RW)
 *
 * ESAI_TCR Transmit Interrupt Enable. The Core is interrupted when TIE and the TDE flag in the
 * ESAI_SAISR status register are set. When TIE is cleared, this interrupt is disabled. Writing data
 * to all the data registers of the enabled transmitters or to ESAI_TSR clears TDE, thus clearing
 * the interrupt. Transmit interrupts with exception have higher priority than normal transmit data
 * interrupts, therefore if exception occurs (TUE is set) and TEIE is set, the ESAI requests an ESAI
 * transmit data with exception interrupt from the interrupt controller.
 */

#define BP_ESAI_TCR_TIE      (22)      //!< Bit position for ESAI_TCR_TIE.
#define BM_ESAI_TCR_TIE      (0x00400000)  //!< Bit mask for ESAI_TCR_TIE.

//! @brief Get value of ESAI_TCR_TIE from a register value.
#define BG_ESAI_TCR_TIE(r)   (((r) & BM_ESAI_TCR_TIE) >> BP_ESAI_TCR_TIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TIE.
#define BF_ESAI_TCR_TIE(v)   ((((reg32_t) v) << BP_ESAI_TCR_TIE) & BM_ESAI_TCR_TIE)
#else
//! @brief Format value for bitfield ESAI_TCR_TIE.
#define BF_ESAI_TCR_TIE(v)   (((v) << BP_ESAI_TCR_TIE) & BM_ESAI_TCR_TIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE field to a new value.
#define BW_ESAI_TCR_TIE(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TIE) | BF_ESAI_TCR_TIE(v)))
#endif

/* --- Register HW_ESAI_TCR, field TLIE[23] (RW)
 *
 * ESAI_TCR Transmit Last Slot Interrupt Enable. TLIE enables an interrupt at the beginning of last
 * slot of a frame in network mode. When TLIE is set the Core is interrupted at the start of the
 * last slot in a frame in network mode regardless of the transmit mask register setting. When TLIE
 * is cleared the transmit last slot interrupt is disabled. TLIE is disabled when TDC[4:0]=0x00000
 * (on-demand mode). The use of the transmit last slot interrupt is described in .
 */

#define BP_ESAI_TCR_TLIE      (23)      //!< Bit position for ESAI_TCR_TLIE.
#define BM_ESAI_TCR_TLIE      (0x00800000)  //!< Bit mask for ESAI_TCR_TLIE.

//! @brief Get value of ESAI_TCR_TLIE from a register value.
#define BG_ESAI_TCR_TLIE(r)   (((r) & BM_ESAI_TCR_TLIE) >> BP_ESAI_TCR_TLIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCR_TLIE.
#define BF_ESAI_TCR_TLIE(v)   ((((reg32_t) v) << BP_ESAI_TCR_TLIE) & BM_ESAI_TCR_TLIE)
#else
//! @brief Format value for bitfield ESAI_TCR_TLIE.
#define BF_ESAI_TCR_TLIE(v)   (((v) << BP_ESAI_TCR_TLIE) & BM_ESAI_TCR_TLIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TLIE field to a new value.
#define BW_ESAI_TCR_TLIE(v)   (HW_ESAI_TCR_WR((HW_ESAI_TCR_RD() & ~BM_ESAI_TCR_TLIE) | BF_ESAI_TCR_TLIE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TCCR - Transmit Clock Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The read/write Transmitter Clock Control Register (ESAI_TCCR) controls the ESAI transmitter clock
 * generator bit and frame sync rates, the bit clock and high frequency clock sources and the
 * directions of the HCKT, FST and SCKT signals. In the synchronous mode (SYN=1), the bit clock
 * defined for the transmitter determines the receiver bit clock as well. ESAI_TCCR also controls
 * the number of words per frame for the serial data. Hardware and software reset clear all the bits
 * of the ESAI_TCCR register.  Care should be taken in asynchronous mode whenever the frame sync
 * clock (FSR, FST) is not sourced directly from its associated bit clock (SCKR, SCKT). Proper phase
 * relationships must be maintained between these clocks in order to guarantee proper operation of
 * the ESAI.  ARM Core clock is ipg_clk_esai in block ESAI which is from CCM's ahb_clk_root.   ESAI
 * Clock Generator Functional Block Diagram    1. ETI, ETO, ERI and ERO bit descriptions are covered
 * in . 2. Fsys is the ESAI system 133 MHz clock. 3. EXTAL is the on-chip clock sources other than
 * ESAI system 133MHz clock.   ESAI Frame Sync Generator Functional Block Diagram       Transmitter
 * High Frequency Clock Divider       TFP3-TFP0  Divide Ratio      0x0  1    0x1  2    0x2  3    0x3
 * 4    ...  ...    0xF  16
 */
typedef union _hw_esai_tccr
{
    reg32_t U;
    struct _hw_esai_tccr_bitfields
    {
        unsigned TPM : 8; //!< [7:0] ESAI_TCCR Transmit Prescale Modulus Select. The TPM7-TPM0 bits specify the divide ratio of the prescale divider in the ESAI transmitter clock generator. A divide ratio from 1 to 256 (TPM[7:0]=0x00 to 0xFF) may be selected. The bit clock output is available at the transmit serial bit clock (SCKT) pin. The bit clock output is also available internally for use as the bit clock to shift the transmit and receive shift registers. The ESAI transmit clock generator functional diagram is shown in .
        unsigned TPSR : 1; //!< [8] ESAI_TCCR Transmit Prescaler Range. The TPSR bit controls a fixed divide-by-eight prescaler in series with the variable prescaler. This bit is used to extend the range of the prescaler for those cases where a slower bit clock is desired. When TPSR is set, the fixed prescaler is bypassed. When TPSR is cleared, the fixed divide-by-eight prescaler is operational (see ). The maximum internally generated bit clock frequency is Fsys/4; the minimum internally generated bit clock frequency is Fsys/(2 x 8 x 256 x 16)=Fsys/65536. (Do not use the combination TPSR=1, TPM7-TPM0=0x00, and TFP3-TFP0=0x0 which causes synchronization problems when using the internal ARM Core clock as source (TCKD=1 or THCKD=1))
        unsigned TDC : 5; //!< [13:9] ESAI_TCCR Tx Frame Rate Divider Control. The TDC4-TDC0 bits control the divide ratio for the programmable frame rate dividers used to generate the transmitter frame clocks. In network mode, this ratio may be interpreted as the number of words per frame minus one. The divide ratio may range from 2 to 32 (TDC[4:0]=0x00001 to 0x11111) for network mode. A divide ratio of one (TDC[4:0]=0x00000) in network mode is a special case (on-demand mode). In normal mode, this ratio determines the word transfer rate. The divide ratio may range from 1 to 32 (TDC[4:0]=0x00000 to 0x11111) for normal mode. In normal mode, a divide ratio of 1 (TDC[4:0]=0x00000) provides continuous periodic data word transfers. A bit-length frame sync (TFSL=1) must be used in this case. The ESAI frame sync generator functional diagram is shown in
        unsigned TFP : 4; //!< [17:14] ESAI_TCCR Tx High Frequency Clock Divider. The TFP3-TFP0 bits control the divide ratio of the transmitter high frequency clock to the transmitter serial bit clock when the source of the high frequency clock and the bit clock is the internal ARM Core clock. When the HCKT input is being driven from an external high frequency clock, the TFP3-TFP0 bits specify an additional division ratio in the clock divider chain. shows the specification for the divide ratio. shows the ESAI high frequency clock generator functional diagram.
        unsigned TCKP : 1; //!< [18] ESAI_TCCR Transmit Clock Polarity. The Transmitter Clock Polarity (TCKP) bit controls on which bit clock edge data and frame sync are clocked out and latched in. If TCKP is cleared the data and the frame sync are clocked out on the rising edge of the transmit bit clock and latched in on the falling edge of the transmit bit clock. If TCKP is set the falling edge of the transmit clock is used to clock the data out and frame sync and the rising edge of the transmit clock is used to latch the data and frame sync in.
        unsigned TFSP : 1; //!< [19] ESAI_TCCR Transmit Frame Sync Polarity. The Transmitter Frame Sync Polarity (TFSP) bit determines the polarity of the transmit frame sync signal. When TFSP is cleared, the frame sync signal polarity is positive, that is, the frame start is indicated by a high level on the frame sync pin. When TFSP is set, the frame sync signal polarity is negative, that is, the frame start is indicated by a low level on the frame sync pin.
        unsigned THCKP : 1; //!< [20] ESAI_TCCR Transmit High Frequency Clock Polarity. The Transmitter High Frequency Clock Polarity (THCKP) bit controls on which bit clock edge data and frame sync are clocked out and latched in. If THCKP is cleared the data and the frame sync are clocked out on the rising edge of the transmit high frequency bit clock and latched in on the falling edge of the transmit bit clock. If THCKP is set the falling edge of the transmit clock is used to clock the data out and frame sync and the rising edge of the transmit clock is used to latch the data and frame sync in.
        unsigned TCKD : 1; //!< [21] ESAI_TCCR Transmit Clock Source Direction. The Transmitter Clock Source Direction (TCKD) bit selects the source of the clock signal used to clock the transmit shift registers in the asynchronous mode (SYN=0) and the transmit shift registers and the receive shift registers in the synchronous mode (SYN=1). When TCKD is set, the internal clock source becomes the bit clock for the transmit shift registers and word length divider and is the output on the SCKT pin. When TCKD is cleared, the clock source is external; the internal clock generator is disconnected from the SCKT pin, and an external clock source may drive this pin (see ).
        unsigned TFSD : 1; //!< [22] ESAI_TCCR Transmit Frame Sync Signal Direction. TFSD controls the direction of the FST pin. When TFSD is cleared, FST is an input; when TFSD is set, FST is an output (see ).
        unsigned THCKD : 1; //!< [23] ESAI_TCCR Transmit High Frequency Clock Direction. THCKD controls the direction of the HCKT pin. When THCKD is cleared, HCKT is an input; when THCKD is set, HCKT is an output (see ).
        unsigned RESERVED0 : 8; //!< [31:24] Reserved.
    } B;
} hw_esai_tccr_t;
#endif

/*
 * constants & macros for entire ESAI_TCCR register
 */
#define HW_ESAI_TCCR_ADDR      (REGS_ESAI_BASE + 0xd8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TCCR           (*(volatile hw_esai_tccr_t *) HW_ESAI_TCCR_ADDR)
#define HW_ESAI_TCCR_RD()      (HW_ESAI_TCCR.U)
#define HW_ESAI_TCCR_WR(v)     (HW_ESAI_TCCR.U = (v))
#define HW_ESAI_TCCR_SET(v)    (HW_ESAI_TCCR_WR(HW_ESAI_TCCR_RD() |  (v)))
#define HW_ESAI_TCCR_CLR(v)    (HW_ESAI_TCCR_WR(HW_ESAI_TCCR_RD() & ~(v)))
#define HW_ESAI_TCCR_TOG(v)    (HW_ESAI_TCCR_WR(HW_ESAI_TCCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_TCCR bitfields
 */

/* --- Register HW_ESAI_TCCR, field TPM[7:0] (RW)
 *
 * ESAI_TCCR Transmit Prescale Modulus Select. The TPM7-TPM0 bits specify the divide ratio of the
 * prescale divider in the ESAI transmitter clock generator. A divide ratio from 1 to 256
 * (TPM[7:0]=0x00 to 0xFF) may be selected. The bit clock output is available at the transmit serial
 * bit clock (SCKT) pin. The bit clock output is also available internally for use as the bit clock
 * to shift the transmit and receive shift registers. The ESAI transmit clock generator functional
 * diagram is shown in .
 */

#define BP_ESAI_TCCR_TPM      (0)      //!< Bit position for ESAI_TCCR_TPM.
#define BM_ESAI_TCCR_TPM      (0x000000ff)  //!< Bit mask for ESAI_TCCR_TPM.

//! @brief Get value of ESAI_TCCR_TPM from a register value.
#define BG_ESAI_TCCR_TPM(r)   (((r) & BM_ESAI_TCCR_TPM) >> BP_ESAI_TCCR_TPM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TPM.
#define BF_ESAI_TCCR_TPM(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TPM) & BM_ESAI_TCCR_TPM)
#else
//! @brief Format value for bitfield ESAI_TCCR_TPM.
#define BF_ESAI_TCCR_TPM(v)   (((v) << BP_ESAI_TCCR_TPM) & BM_ESAI_TCCR_TPM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TPM field to a new value.
#define BW_ESAI_TCCR_TPM(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TPM) | BF_ESAI_TCCR_TPM(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TPSR[8] (RW)
 *
 * ESAI_TCCR Transmit Prescaler Range. The TPSR bit controls a fixed divide-by-eight prescaler in
 * series with the variable prescaler. This bit is used to extend the range of the prescaler for
 * those cases where a slower bit clock is desired. When TPSR is set, the fixed prescaler is
 * bypassed. When TPSR is cleared, the fixed divide-by-eight prescaler is operational (see ). The
 * maximum internally generated bit clock frequency is Fsys/4; the minimum internally generated bit
 * clock frequency is Fsys/(2 x 8 x 256 x 16)=Fsys/65536. (Do not use the combination TPSR=1,
 * TPM7-TPM0=0x00, and TFP3-TFP0=0x0 which causes synchronization problems when using the internal
 * ARM Core clock as source (TCKD=1 or THCKD=1))
 */

#define BP_ESAI_TCCR_TPSR      (8)      //!< Bit position for ESAI_TCCR_TPSR.
#define BM_ESAI_TCCR_TPSR      (0x00000100)  //!< Bit mask for ESAI_TCCR_TPSR.

//! @brief Get value of ESAI_TCCR_TPSR from a register value.
#define BG_ESAI_TCCR_TPSR(r)   (((r) & BM_ESAI_TCCR_TPSR) >> BP_ESAI_TCCR_TPSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TPSR.
#define BF_ESAI_TCCR_TPSR(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TPSR) & BM_ESAI_TCCR_TPSR)
#else
//! @brief Format value for bitfield ESAI_TCCR_TPSR.
#define BF_ESAI_TCCR_TPSR(v)   (((v) << BP_ESAI_TCCR_TPSR) & BM_ESAI_TCCR_TPSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TPSR field to a new value.
#define BW_ESAI_TCCR_TPSR(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TPSR) | BF_ESAI_TCCR_TPSR(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TDC[13:9] (RW)
 *
 * ESAI_TCCR Tx Frame Rate Divider Control. The TDC4-TDC0 bits control the divide ratio for the
 * programmable frame rate dividers used to generate the transmitter frame clocks. In network mode,
 * this ratio may be interpreted as the number of words per frame minus one. The divide ratio may
 * range from 2 to 32 (TDC[4:0]=0x00001 to 0x11111) for network mode. A divide ratio of one
 * (TDC[4:0]=0x00000) in network mode is a special case (on-demand mode). In normal mode, this ratio
 * determines the word transfer rate. The divide ratio may range from 1 to 32 (TDC[4:0]=0x00000 to
 * 0x11111) for normal mode. In normal mode, a divide ratio of 1 (TDC[4:0]=0x00000) provides
 * continuous periodic data word transfers. A bit-length frame sync (TFSL=1) must be used in this
 * case. The ESAI frame sync generator functional diagram is shown in
 */

#define BP_ESAI_TCCR_TDC      (9)      //!< Bit position for ESAI_TCCR_TDC.
#define BM_ESAI_TCCR_TDC      (0x00003e00)  //!< Bit mask for ESAI_TCCR_TDC.

//! @brief Get value of ESAI_TCCR_TDC from a register value.
#define BG_ESAI_TCCR_TDC(r)   (((r) & BM_ESAI_TCCR_TDC) >> BP_ESAI_TCCR_TDC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TDC.
#define BF_ESAI_TCCR_TDC(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TDC) & BM_ESAI_TCCR_TDC)
#else
//! @brief Format value for bitfield ESAI_TCCR_TDC.
#define BF_ESAI_TCCR_TDC(v)   (((v) << BP_ESAI_TCCR_TDC) & BM_ESAI_TCCR_TDC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TDC field to a new value.
#define BW_ESAI_TCCR_TDC(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TDC) | BF_ESAI_TCCR_TDC(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TFP[17:14] (RW)
 *
 * ESAI_TCCR Tx High Frequency Clock Divider. The TFP3-TFP0 bits control the divide ratio of the
 * transmitter high frequency clock to the transmitter serial bit clock when the source of the high
 * frequency clock and the bit clock is the internal ARM Core clock. When the HCKT input is being
 * driven from an external high frequency clock, the TFP3-TFP0 bits specify an additional division
 * ratio in the clock divider chain. shows the specification for the divide ratio. shows the ESAI
 * high frequency clock generator functional diagram.
 */

#define BP_ESAI_TCCR_TFP      (14)      //!< Bit position for ESAI_TCCR_TFP.
#define BM_ESAI_TCCR_TFP      (0x0003c000)  //!< Bit mask for ESAI_TCCR_TFP.

//! @brief Get value of ESAI_TCCR_TFP from a register value.
#define BG_ESAI_TCCR_TFP(r)   (((r) & BM_ESAI_TCCR_TFP) >> BP_ESAI_TCCR_TFP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TFP.
#define BF_ESAI_TCCR_TFP(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TFP) & BM_ESAI_TCCR_TFP)
#else
//! @brief Format value for bitfield ESAI_TCCR_TFP.
#define BF_ESAI_TCCR_TFP(v)   (((v) << BP_ESAI_TCCR_TFP) & BM_ESAI_TCCR_TFP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFP field to a new value.
#define BW_ESAI_TCCR_TFP(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TFP) | BF_ESAI_TCCR_TFP(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TCKP[18] (RW)
 *
 * ESAI_TCCR Transmit Clock Polarity. The Transmitter Clock Polarity (TCKP) bit controls on which
 * bit clock edge data and frame sync are clocked out and latched in. If TCKP is cleared the data
 * and the frame sync are clocked out on the rising edge of the transmit bit clock and latched in on
 * the falling edge of the transmit bit clock. If TCKP is set the falling edge of the transmit clock
 * is used to clock the data out and frame sync and the rising edge of the transmit clock is used to
 * latch the data and frame sync in.
 */

#define BP_ESAI_TCCR_TCKP      (18)      //!< Bit position for ESAI_TCCR_TCKP.
#define BM_ESAI_TCCR_TCKP      (0x00040000)  //!< Bit mask for ESAI_TCCR_TCKP.

//! @brief Get value of ESAI_TCCR_TCKP from a register value.
#define BG_ESAI_TCCR_TCKP(r)   (((r) & BM_ESAI_TCCR_TCKP) >> BP_ESAI_TCCR_TCKP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TCKP.
#define BF_ESAI_TCCR_TCKP(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TCKP) & BM_ESAI_TCCR_TCKP)
#else
//! @brief Format value for bitfield ESAI_TCCR_TCKP.
#define BF_ESAI_TCCR_TCKP(v)   (((v) << BP_ESAI_TCCR_TCKP) & BM_ESAI_TCCR_TCKP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCKP field to a new value.
#define BW_ESAI_TCCR_TCKP(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TCKP) | BF_ESAI_TCCR_TCKP(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TFSP[19] (RW)
 *
 * ESAI_TCCR Transmit Frame Sync Polarity. The Transmitter Frame Sync Polarity (TFSP) bit determines
 * the polarity of the transmit frame sync signal. When TFSP is cleared, the frame sync signal
 * polarity is positive, that is, the frame start is indicated by a high level on the frame sync
 * pin. When TFSP is set, the frame sync signal polarity is negative, that is, the frame start is
 * indicated by a low level on the frame sync pin.
 */

#define BP_ESAI_TCCR_TFSP      (19)      //!< Bit position for ESAI_TCCR_TFSP.
#define BM_ESAI_TCCR_TFSP      (0x00080000)  //!< Bit mask for ESAI_TCCR_TFSP.

//! @brief Get value of ESAI_TCCR_TFSP from a register value.
#define BG_ESAI_TCCR_TFSP(r)   (((r) & BM_ESAI_TCCR_TFSP) >> BP_ESAI_TCCR_TFSP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TFSP.
#define BF_ESAI_TCCR_TFSP(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TFSP) & BM_ESAI_TCCR_TFSP)
#else
//! @brief Format value for bitfield ESAI_TCCR_TFSP.
#define BF_ESAI_TCCR_TFSP(v)   (((v) << BP_ESAI_TCCR_TFSP) & BM_ESAI_TCCR_TFSP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSP field to a new value.
#define BW_ESAI_TCCR_TFSP(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TFSP) | BF_ESAI_TCCR_TFSP(v)))
#endif

/* --- Register HW_ESAI_TCCR, field THCKP[20] (RW)
 *
 * ESAI_TCCR Transmit High Frequency Clock Polarity. The Transmitter High Frequency Clock Polarity
 * (THCKP) bit controls on which bit clock edge data and frame sync are clocked out and latched in.
 * If THCKP is cleared the data and the frame sync are clocked out on the rising edge of the
 * transmit high frequency bit clock and latched in on the falling edge of the transmit bit clock.
 * If THCKP is set the falling edge of the transmit clock is used to clock the data out and frame
 * sync and the rising edge of the transmit clock is used to latch the data and frame sync in.
 */

#define BP_ESAI_TCCR_THCKP      (20)      //!< Bit position for ESAI_TCCR_THCKP.
#define BM_ESAI_TCCR_THCKP      (0x00100000)  //!< Bit mask for ESAI_TCCR_THCKP.

//! @brief Get value of ESAI_TCCR_THCKP from a register value.
#define BG_ESAI_TCCR_THCKP(r)   (((r) & BM_ESAI_TCCR_THCKP) >> BP_ESAI_TCCR_THCKP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_THCKP.
#define BF_ESAI_TCCR_THCKP(v)   ((((reg32_t) v) << BP_ESAI_TCCR_THCKP) & BM_ESAI_TCCR_THCKP)
#else
//! @brief Format value for bitfield ESAI_TCCR_THCKP.
#define BF_ESAI_TCCR_THCKP(v)   (((v) << BP_ESAI_TCCR_THCKP) & BM_ESAI_TCCR_THCKP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the THCKP field to a new value.
#define BW_ESAI_TCCR_THCKP(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_THCKP) | BF_ESAI_TCCR_THCKP(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TCKD[21] (RW)
 *
 * ESAI_TCCR Transmit Clock Source Direction. The Transmitter Clock Source Direction (TCKD) bit
 * selects the source of the clock signal used to clock the transmit shift registers in the
 * asynchronous mode (SYN=0) and the transmit shift registers and the receive shift registers in the
 * synchronous mode (SYN=1). When TCKD is set, the internal clock source becomes the bit clock for
 * the transmit shift registers and word length divider and is the output on the SCKT pin. When TCKD
 * is cleared, the clock source is external; the internal clock generator is disconnected from the
 * SCKT pin, and an external clock source may drive this pin (see ).
 */

#define BP_ESAI_TCCR_TCKD      (21)      //!< Bit position for ESAI_TCCR_TCKD.
#define BM_ESAI_TCCR_TCKD      (0x00200000)  //!< Bit mask for ESAI_TCCR_TCKD.

//! @brief Get value of ESAI_TCCR_TCKD from a register value.
#define BG_ESAI_TCCR_TCKD(r)   (((r) & BM_ESAI_TCCR_TCKD) >> BP_ESAI_TCCR_TCKD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TCKD.
#define BF_ESAI_TCCR_TCKD(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TCKD) & BM_ESAI_TCCR_TCKD)
#else
//! @brief Format value for bitfield ESAI_TCCR_TCKD.
#define BF_ESAI_TCCR_TCKD(v)   (((v) << BP_ESAI_TCCR_TCKD) & BM_ESAI_TCCR_TCKD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCKD field to a new value.
#define BW_ESAI_TCCR_TCKD(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TCKD) | BF_ESAI_TCCR_TCKD(v)))
#endif

/* --- Register HW_ESAI_TCCR, field TFSD[22] (RW)
 *
 * ESAI_TCCR Transmit Frame Sync Signal Direction. TFSD controls the direction of the FST pin. When
 * TFSD is cleared, FST is an input; when TFSD is set, FST is an output (see ).
 */

#define BP_ESAI_TCCR_TFSD      (22)      //!< Bit position for ESAI_TCCR_TFSD.
#define BM_ESAI_TCCR_TFSD      (0x00400000)  //!< Bit mask for ESAI_TCCR_TFSD.

//! @brief Get value of ESAI_TCCR_TFSD from a register value.
#define BG_ESAI_TCCR_TFSD(r)   (((r) & BM_ESAI_TCCR_TFSD) >> BP_ESAI_TCCR_TFSD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_TFSD.
#define BF_ESAI_TCCR_TFSD(v)   ((((reg32_t) v) << BP_ESAI_TCCR_TFSD) & BM_ESAI_TCCR_TFSD)
#else
//! @brief Format value for bitfield ESAI_TCCR_TFSD.
#define BF_ESAI_TCCR_TFSD(v)   (((v) << BP_ESAI_TCCR_TFSD) & BM_ESAI_TCCR_TFSD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFSD field to a new value.
#define BW_ESAI_TCCR_TFSD(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_TFSD) | BF_ESAI_TCCR_TFSD(v)))
#endif

/* --- Register HW_ESAI_TCCR, field THCKD[23] (RW)
 *
 * ESAI_TCCR Transmit High Frequency Clock Direction. THCKD controls the direction of the HCKT pin.
 * When THCKD is cleared, HCKT is an input; when THCKD is set, HCKT is an output (see ).
 */

#define BP_ESAI_TCCR_THCKD      (23)      //!< Bit position for ESAI_TCCR_THCKD.
#define BM_ESAI_TCCR_THCKD      (0x00800000)  //!< Bit mask for ESAI_TCCR_THCKD.

//! @brief Get value of ESAI_TCCR_THCKD from a register value.
#define BG_ESAI_TCCR_THCKD(r)   (((r) & BM_ESAI_TCCR_THCKD) >> BP_ESAI_TCCR_THCKD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TCCR_THCKD.
#define BF_ESAI_TCCR_THCKD(v)   ((((reg32_t) v) << BP_ESAI_TCCR_THCKD) & BM_ESAI_TCCR_THCKD)
#else
//! @brief Format value for bitfield ESAI_TCCR_THCKD.
#define BF_ESAI_TCCR_THCKD(v)   (((v) << BP_ESAI_TCCR_THCKD) & BM_ESAI_TCCR_THCKD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the THCKD field to a new value.
#define BW_ESAI_TCCR_THCKD(v)   (HW_ESAI_TCCR_WR((HW_ESAI_TCCR_RD() & ~BM_ESAI_TCCR_THCKD) | BF_ESAI_TCCR_THCKD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RCR - Receive Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The read/write Receive Control Register (ESAI_RCR) controls the ESAI receiver section. Interrupt
 * enable bits for the receivers are provided in this control register. The receivers are enabled in
 * this register (0,1,2 or 3 receivers can be enabled) if the input data pin is not used by a
 * transmitter. Operating modes are also selected in this register.     ESAI Receive Network Mode
 * Selection         RMOD1  RMOD0  RDC4-RDC0  Receiver Network Mode      0  0  0x0-0x1F  Normal Mode
 * 0  1  0x0  On-Demand Mode    0  1  0x1-0x1F  Network Mode    1  0  X  Reserved    1  1  0x0C
 * AC97       ESAI Receive Slot and Word Length Selection            RSWS4  RSWS3  RSWS2  RSWS1
 * RSWS0  SLOT LENGTH  WORD LENGTH      0  0  0  0  0  8  8    0  0  1  0  0  12  8    0  0  0  0  1
 * 12    0  1  0  0  0  16  8    0  0  1  0  1  12    0  0  0  1  0  16    0  1  1  0  0  20  8    0
 * 1  0  0  1  12    0  0  1  1  0  16    0  0  0  1  1  20    1  0  0  0  0  24  8    0  1  1  0  1
 * 12    0  1  0  1  0  16    0  0  1  1  1  20    1  1  1  1  0  24    1  1  0  0  0  32  8    1  0
 * 1  0  1  12    1  0  0  1  0  16    0  1  1  1  1  20    1  1  1  1  1  24    0  1  0  1  1
 * Reserved    0  1  1  1  0    1  0  0  0  1    1  0  0  1  1    1  0  1  0  0    1  0  1  1  0
 * 1  0  1  1  1    1  1  0  0  1    1  1  0  1  0    1  1  0  1  1    1  1  1  0  0    1  1  1  0
 * 1
 */
typedef union _hw_esai_rcr
{
    reg32_t U;
    struct _hw_esai_rcr_bitfields
    {
        unsigned RE0 : 1; //!< [0] ESAI_RCR ESAI Receiver 0 Enable. When RE0 is set and TE5 is cleared, the ESAI receiver 0 is enabled and samples data at the SDO5/SDI0 pin. ESAI_TX5 and ESAI_RX0 should not be enabled at the same time (RE0=1 and TE5=1). When RE0 is cleared, receiver 0 is disabled by inhibiting data transfer into ESAI_RX0. If this bit is cleared while receiving a data word, the remainder of the word is shifted in and transferred to the ESAI_RX0 data register. If RE0 is set while some of the other receivers are already in operation, the first data word received in ESAI_RX0 will be invalid and must be discarded.
        unsigned RE1 : 1; //!< [1] ESAI_RCR ESAI Receiver 1 Enable. When RE1 is set and TE4 is cleared, the ESAI receiver 1 is enabled and samples data at the SDO4/SDI1 pin. ESAI_TX4 and ESAI_RX1 should not be enabled at the same time (RE1=1 and TE4=1). When RE1 is cleared, receiver 1 is disabled by inhibiting data transfer into ESAI_RX1. If this bit is cleared while receiving a data word, the remainder of the word is shifted in and transferred to the ESAI_RX1 data register. If RE1 is set while some of the other receivers are already in operation, the first data word received in ESAI_RX1 will be invalid and must be discarded.
        unsigned RE2 : 1; //!< [2] ESAI_RCR ESAI Receiver 2 Enable. When RE2 is set and TE3 is cleared, the ESAI receiver 2 is enabled and samples data at the SDO3/SDI2 pin. ESAI_TX3 and ESAI_RX2 should not be enabled at the same time (RE2=1 and TE3=1). When RE2 is cleared, receiver 2 is disabled by inhibiting data transfer into ESAI_RX2. If this bit is cleared while receiving a data word, the remainder of the word is shifted in and transferred to the ESAI_RX2 data register. If RE2 is set while some of the other receivers are already in operation, the first data word received in ESAI_RX2 will be invalid and must be discarded.
        unsigned RE3 : 1; //!< [3] ESAI_RCR ESAI Receiver 3 Enable. When RE3 is set and TE2 is cleared, the ESAI receiver 3 is enabled and samples data at the SDO2/SDI3 pin. ESAI_TX2 and ESAI_RX3 should not be enabled at the same time (RE3=1 and TE2=1). When RE3 is cleared, receiver 3 is disabled by inhibiting data transfer into ESAI_RX3. If this bit is cleared while receiving a data word, the remainder of the word is shifted in and transferred to the ESAI_RX3 data register. If RE3 is set while some of the other receivers are already in operation, the first data word received in ESAI_RX3 will be invalid and must be discarded.
        unsigned RESERVED0 : 2; //!< [5:4] Reserved.
        unsigned RSHFD : 1; //!< [6] ESAI_RCR Receiver Shift Direction. The RSHFD bit causes the receiver shift registers to shift data in MSB first when RSHFD is cleared or LSB first when RSHFD is set (see and ).
        unsigned RWA : 1; //!< [7] ESAI_RCR Receiver Word Alignment Control. The Receiver Word Alignment Control (RWA) bit defines the alignment of the data word in relation to the slot. This is relevant for the cases where the word length is shorter than the slot length. If RWA is cleared, the data word is assumed to be left-aligned in the slot frame. If RWA is set, the data word is assumed to be right-aligned in the slot frame. If the data word is shorter than the slot length, the data bits which are not in the data word field are ignored. For data word lengths of less than 24 bits, the data word is right-extended with zeroes before being stored in the receive data registers.
        unsigned RMOD : 2; //!< [9:8] ESAI_RCR Receiver Network Mode Control. The RMOD1 and RMOD0 bits are used to define the network mode of the ESAI receivers, as shown in . In the normal mode, the frame rate divider determines the word transfer rate - one word is transferred per frame sync during the frame sync time slot, as shown in . In network mode, it is possible to transfer a word for every time slot, as shown in . For more details, see . In order to comply with AC-97 specifications, RSWS4-RSWS0 should be set to 0x00011 (20-bit slot, 20-bit word); RFSL and RFSR should be cleared, and RDC4-RDC0 should be set to 0x0C (13 words in frame).
        unsigned RSWS : 5; //!< [14:10] ESAI_RCR Receiver Slot and Word Select. The RSWS4-RSWS0 bits are used to select the length of the slot and the length of the data words being received through the ESAI. The word length must be equal to or shorter than the slot length. The possible combinations are shown in . See also the ESAI data path programming model in and .
        unsigned RFSL : 1; //!< [15] ESAI_RCR Receiver Frame Sync Length. The RFSL bit selects the length of the receive frame sync to be generated or recognized. If RFSL is cleared, a word-length frame sync is selected. If RFSL is set, a 1-bit clock period frame sync is selected. Refer to for examples of frame length selection.
        unsigned RFSR : 1; //!< [16] ESAI_RCR Receiver Frame Sync Relative Timing. RFSR determines the relative timing of the receive frame sync signal as referred to the serial data lines, for a word length frame sync only. When RFSR is cleared the word length frame sync occurs together with the first bit of the data word of the first slot. When RFSR is set the word length frame sync starts one serial clock cycle earlier, that is, together with the last bit of the previous data word.
        unsigned RESERVED1 : 2; //!< [18:17] Reserved.
        unsigned RPR : 1; //!< [19] ESAI_RCR Receiver Section Personal Reset. The RPR control bit is used to put the receiver section of the ESAI in the personal reset state. The transmitter section is not affected. When RPR is cleared, the receiver section may operate normally. When RPR is set, the receiver section enters the personal reset state immediately. When in the personal reset state, the status bits are reset to the same state as after hardware reset.The control bits are not affected by the personal reset state.The receiver data pins are disconnected while in the personal reset state. To leave the personal reset state by clearing RPR, the procedure described in should be followed.
        unsigned REIE : 1; //!< [20] ESAI_RCR Receive Exception Interrupt Enable. When REIE is set, the Core is interrupted when both RDF and ROE in the ESAI_SAISR status register are set. When REIE is cleared, this interrupt is disabled. Reading the ESAI_SAISR status register followed by reading the enabled receivers data registers clears ROE, thus clearing the pending interrupt.
        unsigned REDIE : 1; //!< [21] ESAI_RCR Receive Even Slot Data Interrupt Enable. The REDIE control bit is used to enable the receive even slot data interrupts. If REDIE is set, the receive even slot data interrupts are enabled. If REDIE is cleared, the receive even slot data interrupts are disabled. A receive even slot data interrupt request is generated if REDIE is set and the REDF status flag in the ESAI_SAISR status register is set. Even time slots are all even-numbered time slots (0, 2, 4, etc.) when operating in network mode. The zero time slot is marked by the frame sync signal and is considered to be even. Reading all the data registers of the enabled receivers clears the REDF flag, thus servicing the interrupt. Receive interrupts with exception have higher priority than receive even slot data interrupts, therefore if exception occurs (ROE is set) and REIE is set, the ESAI requests an ESAI receive data with exception interrupt from the interrupt controller.
        unsigned RIE : 1; //!< [22] ESAI_RCR Receive Interrupt Enable. The Core is interrupted when RIE and the RDF flag in the ESAI_SAISR status register are set. When RIE is cleared, this interrupt is disabled. Reading the receive data registers of the enabled receivers clears RDF, thus clearing the interrupt. Receive interrupts with exception have higher priority than normal receive data interrupts, therefore if exception occurs (ROE is set) and REIE is set, the ESAI requests an ESAI receive data with exception interrupt from the interrupt controller.
        unsigned RLIE : 1; //!< [23] ESAI_RCR Receive Last Slot Interrupt Enable. RLIE enables an interrupt after the last slot of a frame ended in network mode only. When RLIE is set the Core is interrupted after the last slot in a frame ended regardless of the receive mask register setting. When RLIE is cleared the receive last slot interrupt is disabled. Hardware and software reset clear RLIE. RLIE is disabled when RDC[4:0]=00000 (on-demand mode). The use of the receive last slot interrupt is described in .
        unsigned RESERVED2 : 8; //!< [31:24] Reserved.
    } B;
} hw_esai_rcr_t;
#endif

/*
 * constants & macros for entire ESAI_RCR register
 */
#define HW_ESAI_RCR_ADDR      (REGS_ESAI_BASE + 0xdc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RCR           (*(volatile hw_esai_rcr_t *) HW_ESAI_RCR_ADDR)
#define HW_ESAI_RCR_RD()      (HW_ESAI_RCR.U)
#define HW_ESAI_RCR_WR(v)     (HW_ESAI_RCR.U = (v))
#define HW_ESAI_RCR_SET(v)    (HW_ESAI_RCR_WR(HW_ESAI_RCR_RD() |  (v)))
#define HW_ESAI_RCR_CLR(v)    (HW_ESAI_RCR_WR(HW_ESAI_RCR_RD() & ~(v)))
#define HW_ESAI_RCR_TOG(v)    (HW_ESAI_RCR_WR(HW_ESAI_RCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_RCR bitfields
 */

/* --- Register HW_ESAI_RCR, field RE0[0] (RW)
 *
 * ESAI_RCR ESAI Receiver 0 Enable. When RE0 is set and TE5 is cleared, the ESAI receiver 0 is
 * enabled and samples data at the SDO5/SDI0 pin. ESAI_TX5 and ESAI_RX0 should not be enabled at the
 * same time (RE0=1 and TE5=1). When RE0 is cleared, receiver 0 is disabled by inhibiting data
 * transfer into ESAI_RX0. If this bit is cleared while receiving a data word, the remainder of the
 * word is shifted in and transferred to the ESAI_RX0 data register. If RE0 is set while some of the
 * other receivers are already in operation, the first data word received in ESAI_RX0 will be
 * invalid and must be discarded.
 */

#define BP_ESAI_RCR_RE0      (0)      //!< Bit position for ESAI_RCR_RE0.
#define BM_ESAI_RCR_RE0      (0x00000001)  //!< Bit mask for ESAI_RCR_RE0.

//! @brief Get value of ESAI_RCR_RE0 from a register value.
#define BG_ESAI_RCR_RE0(r)   (((r) & BM_ESAI_RCR_RE0) >> BP_ESAI_RCR_RE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RE0.
#define BF_ESAI_RCR_RE0(v)   ((((reg32_t) v) << BP_ESAI_RCR_RE0) & BM_ESAI_RCR_RE0)
#else
//! @brief Format value for bitfield ESAI_RCR_RE0.
#define BF_ESAI_RCR_RE0(v)   (((v) << BP_ESAI_RCR_RE0) & BM_ESAI_RCR_RE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE0 field to a new value.
#define BW_ESAI_RCR_RE0(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RE0) | BF_ESAI_RCR_RE0(v)))
#endif

/* --- Register HW_ESAI_RCR, field RE1[1] (RW)
 *
 * ESAI_RCR ESAI Receiver 1 Enable. When RE1 is set and TE4 is cleared, the ESAI receiver 1 is
 * enabled and samples data at the SDO4/SDI1 pin. ESAI_TX4 and ESAI_RX1 should not be enabled at the
 * same time (RE1=1 and TE4=1). When RE1 is cleared, receiver 1 is disabled by inhibiting data
 * transfer into ESAI_RX1. If this bit is cleared while receiving a data word, the remainder of the
 * word is shifted in and transferred to the ESAI_RX1 data register. If RE1 is set while some of the
 * other receivers are already in operation, the first data word received in ESAI_RX1 will be
 * invalid and must be discarded.
 */

#define BP_ESAI_RCR_RE1      (1)      //!< Bit position for ESAI_RCR_RE1.
#define BM_ESAI_RCR_RE1      (0x00000002)  //!< Bit mask for ESAI_RCR_RE1.

//! @brief Get value of ESAI_RCR_RE1 from a register value.
#define BG_ESAI_RCR_RE1(r)   (((r) & BM_ESAI_RCR_RE1) >> BP_ESAI_RCR_RE1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RE1.
#define BF_ESAI_RCR_RE1(v)   ((((reg32_t) v) << BP_ESAI_RCR_RE1) & BM_ESAI_RCR_RE1)
#else
//! @brief Format value for bitfield ESAI_RCR_RE1.
#define BF_ESAI_RCR_RE1(v)   (((v) << BP_ESAI_RCR_RE1) & BM_ESAI_RCR_RE1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE1 field to a new value.
#define BW_ESAI_RCR_RE1(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RE1) | BF_ESAI_RCR_RE1(v)))
#endif

/* --- Register HW_ESAI_RCR, field RE2[2] (RW)
 *
 * ESAI_RCR ESAI Receiver 2 Enable. When RE2 is set and TE3 is cleared, the ESAI receiver 2 is
 * enabled and samples data at the SDO3/SDI2 pin. ESAI_TX3 and ESAI_RX2 should not be enabled at the
 * same time (RE2=1 and TE3=1). When RE2 is cleared, receiver 2 is disabled by inhibiting data
 * transfer into ESAI_RX2. If this bit is cleared while receiving a data word, the remainder of the
 * word is shifted in and transferred to the ESAI_RX2 data register. If RE2 is set while some of the
 * other receivers are already in operation, the first data word received in ESAI_RX2 will be
 * invalid and must be discarded.
 */

#define BP_ESAI_RCR_RE2      (2)      //!< Bit position for ESAI_RCR_RE2.
#define BM_ESAI_RCR_RE2      (0x00000004)  //!< Bit mask for ESAI_RCR_RE2.

//! @brief Get value of ESAI_RCR_RE2 from a register value.
#define BG_ESAI_RCR_RE2(r)   (((r) & BM_ESAI_RCR_RE2) >> BP_ESAI_RCR_RE2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RE2.
#define BF_ESAI_RCR_RE2(v)   ((((reg32_t) v) << BP_ESAI_RCR_RE2) & BM_ESAI_RCR_RE2)
#else
//! @brief Format value for bitfield ESAI_RCR_RE2.
#define BF_ESAI_RCR_RE2(v)   (((v) << BP_ESAI_RCR_RE2) & BM_ESAI_RCR_RE2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE2 field to a new value.
#define BW_ESAI_RCR_RE2(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RE2) | BF_ESAI_RCR_RE2(v)))
#endif

/* --- Register HW_ESAI_RCR, field RE3[3] (RW)
 *
 * ESAI_RCR ESAI Receiver 3 Enable. When RE3 is set and TE2 is cleared, the ESAI receiver 3 is
 * enabled and samples data at the SDO2/SDI3 pin. ESAI_TX2 and ESAI_RX3 should not be enabled at the
 * same time (RE3=1 and TE2=1). When RE3 is cleared, receiver 3 is disabled by inhibiting data
 * transfer into ESAI_RX3. If this bit is cleared while receiving a data word, the remainder of the
 * word is shifted in and transferred to the ESAI_RX3 data register. If RE3 is set while some of the
 * other receivers are already in operation, the first data word received in ESAI_RX3 will be
 * invalid and must be discarded.
 */

#define BP_ESAI_RCR_RE3      (3)      //!< Bit position for ESAI_RCR_RE3.
#define BM_ESAI_RCR_RE3      (0x00000008)  //!< Bit mask for ESAI_RCR_RE3.

//! @brief Get value of ESAI_RCR_RE3 from a register value.
#define BG_ESAI_RCR_RE3(r)   (((r) & BM_ESAI_RCR_RE3) >> BP_ESAI_RCR_RE3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RE3.
#define BF_ESAI_RCR_RE3(v)   ((((reg32_t) v) << BP_ESAI_RCR_RE3) & BM_ESAI_RCR_RE3)
#else
//! @brief Format value for bitfield ESAI_RCR_RE3.
#define BF_ESAI_RCR_RE3(v)   (((v) << BP_ESAI_RCR_RE3) & BM_ESAI_RCR_RE3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RE3 field to a new value.
#define BW_ESAI_RCR_RE3(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RE3) | BF_ESAI_RCR_RE3(v)))
#endif

/* --- Register HW_ESAI_RCR, field RSHFD[6] (RW)
 *
 * ESAI_RCR Receiver Shift Direction. The RSHFD bit causes the receiver shift registers to shift
 * data in MSB first when RSHFD is cleared or LSB first when RSHFD is set (see and ).
 */

#define BP_ESAI_RCR_RSHFD      (6)      //!< Bit position for ESAI_RCR_RSHFD.
#define BM_ESAI_RCR_RSHFD      (0x00000040)  //!< Bit mask for ESAI_RCR_RSHFD.

//! @brief Get value of ESAI_RCR_RSHFD from a register value.
#define BG_ESAI_RCR_RSHFD(r)   (((r) & BM_ESAI_RCR_RSHFD) >> BP_ESAI_RCR_RSHFD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RSHFD.
#define BF_ESAI_RCR_RSHFD(v)   ((((reg32_t) v) << BP_ESAI_RCR_RSHFD) & BM_ESAI_RCR_RSHFD)
#else
//! @brief Format value for bitfield ESAI_RCR_RSHFD.
#define BF_ESAI_RCR_RSHFD(v)   (((v) << BP_ESAI_RCR_RSHFD) & BM_ESAI_RCR_RSHFD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSHFD field to a new value.
#define BW_ESAI_RCR_RSHFD(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RSHFD) | BF_ESAI_RCR_RSHFD(v)))
#endif

/* --- Register HW_ESAI_RCR, field RWA[7] (RW)
 *
 * ESAI_RCR Receiver Word Alignment Control. The Receiver Word Alignment Control (RWA) bit defines
 * the alignment of the data word in relation to the slot. This is relevant for the cases where the
 * word length is shorter than the slot length. If RWA is cleared, the data word is assumed to be
 * left-aligned in the slot frame. If RWA is set, the data word is assumed to be right-aligned in
 * the slot frame. If the data word is shorter than the slot length, the data bits which are not in
 * the data word field are ignored. For data word lengths of less than 24 bits, the data word is
 * right-extended with zeroes before being stored in the receive data registers.
 */

#define BP_ESAI_RCR_RWA      (7)      //!< Bit position for ESAI_RCR_RWA.
#define BM_ESAI_RCR_RWA      (0x00000080)  //!< Bit mask for ESAI_RCR_RWA.

//! @brief Get value of ESAI_RCR_RWA from a register value.
#define BG_ESAI_RCR_RWA(r)   (((r) & BM_ESAI_RCR_RWA) >> BP_ESAI_RCR_RWA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RWA.
#define BF_ESAI_RCR_RWA(v)   ((((reg32_t) v) << BP_ESAI_RCR_RWA) & BM_ESAI_RCR_RWA)
#else
//! @brief Format value for bitfield ESAI_RCR_RWA.
#define BF_ESAI_RCR_RWA(v)   (((v) << BP_ESAI_RCR_RWA) & BM_ESAI_RCR_RWA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RWA field to a new value.
#define BW_ESAI_RCR_RWA(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RWA) | BF_ESAI_RCR_RWA(v)))
#endif

/* --- Register HW_ESAI_RCR, field RMOD[9:8] (RW)
 *
 * ESAI_RCR Receiver Network Mode Control. The RMOD1 and RMOD0 bits are used to define the network
 * mode of the ESAI receivers, as shown in . In the normal mode, the frame rate divider determines
 * the word transfer rate - one word is transferred per frame sync during the frame sync time slot,
 * as shown in . In network mode, it is possible to transfer a word for every time slot, as shown in
 * . For more details, see . In order to comply with AC-97 specifications, RSWS4-RSWS0 should be set
 * to 0x00011 (20-bit slot, 20-bit word); RFSL and RFSR should be cleared, and RDC4-RDC0 should be
 * set to 0x0C (13 words in frame).
 */

#define BP_ESAI_RCR_RMOD      (8)      //!< Bit position for ESAI_RCR_RMOD.
#define BM_ESAI_RCR_RMOD      (0x00000300)  //!< Bit mask for ESAI_RCR_RMOD.

//! @brief Get value of ESAI_RCR_RMOD from a register value.
#define BG_ESAI_RCR_RMOD(r)   (((r) & BM_ESAI_RCR_RMOD) >> BP_ESAI_RCR_RMOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RMOD.
#define BF_ESAI_RCR_RMOD(v)   ((((reg32_t) v) << BP_ESAI_RCR_RMOD) & BM_ESAI_RCR_RMOD)
#else
//! @brief Format value for bitfield ESAI_RCR_RMOD.
#define BF_ESAI_RCR_RMOD(v)   (((v) << BP_ESAI_RCR_RMOD) & BM_ESAI_RCR_RMOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RMOD field to a new value.
#define BW_ESAI_RCR_RMOD(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RMOD) | BF_ESAI_RCR_RMOD(v)))
#endif

/* --- Register HW_ESAI_RCR, field RSWS[14:10] (RW)
 *
 * ESAI_RCR Receiver Slot and Word Select. The RSWS4-RSWS0 bits are used to select the length of the
 * slot and the length of the data words being received through the ESAI. The word length must be
 * equal to or shorter than the slot length. The possible combinations are shown in . See also the
 * ESAI data path programming model in and .
 */

#define BP_ESAI_RCR_RSWS      (10)      //!< Bit position for ESAI_RCR_RSWS.
#define BM_ESAI_RCR_RSWS      (0x00007c00)  //!< Bit mask for ESAI_RCR_RSWS.

//! @brief Get value of ESAI_RCR_RSWS from a register value.
#define BG_ESAI_RCR_RSWS(r)   (((r) & BM_ESAI_RCR_RSWS) >> BP_ESAI_RCR_RSWS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RSWS.
#define BF_ESAI_RCR_RSWS(v)   ((((reg32_t) v) << BP_ESAI_RCR_RSWS) & BM_ESAI_RCR_RSWS)
#else
//! @brief Format value for bitfield ESAI_RCR_RSWS.
#define BF_ESAI_RCR_RSWS(v)   (((v) << BP_ESAI_RCR_RSWS) & BM_ESAI_RCR_RSWS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSWS field to a new value.
#define BW_ESAI_RCR_RSWS(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RSWS) | BF_ESAI_RCR_RSWS(v)))
#endif

/* --- Register HW_ESAI_RCR, field RFSL[15] (RW)
 *
 * ESAI_RCR Receiver Frame Sync Length. The RFSL bit selects the length of the receive frame sync to
 * be generated or recognized. If RFSL is cleared, a word-length frame sync is selected. If RFSL is
 * set, a 1-bit clock period frame sync is selected. Refer to for examples of frame length
 * selection.
 */

#define BP_ESAI_RCR_RFSL      (15)      //!< Bit position for ESAI_RCR_RFSL.
#define BM_ESAI_RCR_RFSL      (0x00008000)  //!< Bit mask for ESAI_RCR_RFSL.

//! @brief Get value of ESAI_RCR_RFSL from a register value.
#define BG_ESAI_RCR_RFSL(r)   (((r) & BM_ESAI_RCR_RFSL) >> BP_ESAI_RCR_RFSL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RFSL.
#define BF_ESAI_RCR_RFSL(v)   ((((reg32_t) v) << BP_ESAI_RCR_RFSL) & BM_ESAI_RCR_RFSL)
#else
//! @brief Format value for bitfield ESAI_RCR_RFSL.
#define BF_ESAI_RCR_RFSL(v)   (((v) << BP_ESAI_RCR_RFSL) & BM_ESAI_RCR_RFSL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSL field to a new value.
#define BW_ESAI_RCR_RFSL(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RFSL) | BF_ESAI_RCR_RFSL(v)))
#endif

/* --- Register HW_ESAI_RCR, field RFSR[16] (RW)
 *
 * ESAI_RCR Receiver Frame Sync Relative Timing. RFSR determines the relative timing of the receive
 * frame sync signal as referred to the serial data lines, for a word length frame sync only. When
 * RFSR is cleared the word length frame sync occurs together with the first bit of the data word of
 * the first slot. When RFSR is set the word length frame sync starts one serial clock cycle
 * earlier, that is, together with the last bit of the previous data word.
 */

#define BP_ESAI_RCR_RFSR      (16)      //!< Bit position for ESAI_RCR_RFSR.
#define BM_ESAI_RCR_RFSR      (0x00010000)  //!< Bit mask for ESAI_RCR_RFSR.

//! @brief Get value of ESAI_RCR_RFSR from a register value.
#define BG_ESAI_RCR_RFSR(r)   (((r) & BM_ESAI_RCR_RFSR) >> BP_ESAI_RCR_RFSR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RFSR.
#define BF_ESAI_RCR_RFSR(v)   ((((reg32_t) v) << BP_ESAI_RCR_RFSR) & BM_ESAI_RCR_RFSR)
#else
//! @brief Format value for bitfield ESAI_RCR_RFSR.
#define BF_ESAI_RCR_RFSR(v)   (((v) << BP_ESAI_RCR_RFSR) & BM_ESAI_RCR_RFSR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSR field to a new value.
#define BW_ESAI_RCR_RFSR(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RFSR) | BF_ESAI_RCR_RFSR(v)))
#endif

/* --- Register HW_ESAI_RCR, field RPR[19] (RW)
 *
 * ESAI_RCR Receiver Section Personal Reset. The RPR control bit is used to put the receiver section
 * of the ESAI in the personal reset state. The transmitter section is not affected. When RPR is
 * cleared, the receiver section may operate normally. When RPR is set, the receiver section enters
 * the personal reset state immediately. When in the personal reset state, the status bits are reset
 * to the same state as after hardware reset.The control bits are not affected by the personal reset
 * state.The receiver data pins are disconnected while in the personal reset state. To leave the
 * personal reset state by clearing RPR, the procedure described in should be followed.
 */

#define BP_ESAI_RCR_RPR      (19)      //!< Bit position for ESAI_RCR_RPR.
#define BM_ESAI_RCR_RPR      (0x00080000)  //!< Bit mask for ESAI_RCR_RPR.

//! @brief Get value of ESAI_RCR_RPR from a register value.
#define BG_ESAI_RCR_RPR(r)   (((r) & BM_ESAI_RCR_RPR) >> BP_ESAI_RCR_RPR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RPR.
#define BF_ESAI_RCR_RPR(v)   ((((reg32_t) v) << BP_ESAI_RCR_RPR) & BM_ESAI_RCR_RPR)
#else
//! @brief Format value for bitfield ESAI_RCR_RPR.
#define BF_ESAI_RCR_RPR(v)   (((v) << BP_ESAI_RCR_RPR) & BM_ESAI_RCR_RPR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RPR field to a new value.
#define BW_ESAI_RCR_RPR(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RPR) | BF_ESAI_RCR_RPR(v)))
#endif

/* --- Register HW_ESAI_RCR, field REIE[20] (RW)
 *
 * ESAI_RCR Receive Exception Interrupt Enable. When REIE is set, the Core is interrupted when both
 * RDF and ROE in the ESAI_SAISR status register are set. When REIE is cleared, this interrupt is
 * disabled. Reading the ESAI_SAISR status register followed by reading the enabled receivers data
 * registers clears ROE, thus clearing the pending interrupt.
 */

#define BP_ESAI_RCR_REIE      (20)      //!< Bit position for ESAI_RCR_REIE.
#define BM_ESAI_RCR_REIE      (0x00100000)  //!< Bit mask for ESAI_RCR_REIE.

//! @brief Get value of ESAI_RCR_REIE from a register value.
#define BG_ESAI_RCR_REIE(r)   (((r) & BM_ESAI_RCR_REIE) >> BP_ESAI_RCR_REIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_REIE.
#define BF_ESAI_RCR_REIE(v)   ((((reg32_t) v) << BP_ESAI_RCR_REIE) & BM_ESAI_RCR_REIE)
#else
//! @brief Format value for bitfield ESAI_RCR_REIE.
#define BF_ESAI_RCR_REIE(v)   (((v) << BP_ESAI_RCR_REIE) & BM_ESAI_RCR_REIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REIE field to a new value.
#define BW_ESAI_RCR_REIE(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_REIE) | BF_ESAI_RCR_REIE(v)))
#endif

/* --- Register HW_ESAI_RCR, field REDIE[21] (RW)
 *
 * ESAI_RCR Receive Even Slot Data Interrupt Enable. The REDIE control bit is used to enable the
 * receive even slot data interrupts. If REDIE is set, the receive even slot data interrupts are
 * enabled. If REDIE is cleared, the receive even slot data interrupts are disabled. A receive even
 * slot data interrupt request is generated if REDIE is set and the REDF status flag in the
 * ESAI_SAISR status register is set. Even time slots are all even-numbered time slots (0, 2, 4,
 * etc.) when operating in network mode. The zero time slot is marked by the frame sync signal and
 * is considered to be even. Reading all the data registers of the enabled receivers clears the REDF
 * flag, thus servicing the interrupt. Receive interrupts with exception have higher priority than
 * receive even slot data interrupts, therefore if exception occurs (ROE is set) and REIE is set,
 * the ESAI requests an ESAI receive data with exception interrupt from the interrupt controller.
 */

#define BP_ESAI_RCR_REDIE      (21)      //!< Bit position for ESAI_RCR_REDIE.
#define BM_ESAI_RCR_REDIE      (0x00200000)  //!< Bit mask for ESAI_RCR_REDIE.

//! @brief Get value of ESAI_RCR_REDIE from a register value.
#define BG_ESAI_RCR_REDIE(r)   (((r) & BM_ESAI_RCR_REDIE) >> BP_ESAI_RCR_REDIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_REDIE.
#define BF_ESAI_RCR_REDIE(v)   ((((reg32_t) v) << BP_ESAI_RCR_REDIE) & BM_ESAI_RCR_REDIE)
#else
//! @brief Format value for bitfield ESAI_RCR_REDIE.
#define BF_ESAI_RCR_REDIE(v)   (((v) << BP_ESAI_RCR_REDIE) & BM_ESAI_RCR_REDIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REDIE field to a new value.
#define BW_ESAI_RCR_REDIE(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_REDIE) | BF_ESAI_RCR_REDIE(v)))
#endif

/* --- Register HW_ESAI_RCR, field RIE[22] (RW)
 *
 * ESAI_RCR Receive Interrupt Enable. The Core is interrupted when RIE and the RDF flag in the
 * ESAI_SAISR status register are set. When RIE is cleared, this interrupt is disabled. Reading the
 * receive data registers of the enabled receivers clears RDF, thus clearing the interrupt. Receive
 * interrupts with exception have higher priority than normal receive data interrupts, therefore if
 * exception occurs (ROE is set) and REIE is set, the ESAI requests an ESAI receive data with
 * exception interrupt from the interrupt controller.
 */

#define BP_ESAI_RCR_RIE      (22)      //!< Bit position for ESAI_RCR_RIE.
#define BM_ESAI_RCR_RIE      (0x00400000)  //!< Bit mask for ESAI_RCR_RIE.

//! @brief Get value of ESAI_RCR_RIE from a register value.
#define BG_ESAI_RCR_RIE(r)   (((r) & BM_ESAI_RCR_RIE) >> BP_ESAI_RCR_RIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RIE.
#define BF_ESAI_RCR_RIE(v)   ((((reg32_t) v) << BP_ESAI_RCR_RIE) & BM_ESAI_RCR_RIE)
#else
//! @brief Format value for bitfield ESAI_RCR_RIE.
#define BF_ESAI_RCR_RIE(v)   (((v) << BP_ESAI_RCR_RIE) & BM_ESAI_RCR_RIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RIE field to a new value.
#define BW_ESAI_RCR_RIE(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RIE) | BF_ESAI_RCR_RIE(v)))
#endif

/* --- Register HW_ESAI_RCR, field RLIE[23] (RW)
 *
 * ESAI_RCR Receive Last Slot Interrupt Enable. RLIE enables an interrupt after the last slot of a
 * frame ended in network mode only. When RLIE is set the Core is interrupted after the last slot in
 * a frame ended regardless of the receive mask register setting. When RLIE is cleared the receive
 * last slot interrupt is disabled. Hardware and software reset clear RLIE. RLIE is disabled when
 * RDC[4:0]=00000 (on-demand mode). The use of the receive last slot interrupt is described in .
 */

#define BP_ESAI_RCR_RLIE      (23)      //!< Bit position for ESAI_RCR_RLIE.
#define BM_ESAI_RCR_RLIE      (0x00800000)  //!< Bit mask for ESAI_RCR_RLIE.

//! @brief Get value of ESAI_RCR_RLIE from a register value.
#define BG_ESAI_RCR_RLIE(r)   (((r) & BM_ESAI_RCR_RLIE) >> BP_ESAI_RCR_RLIE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCR_RLIE.
#define BF_ESAI_RCR_RLIE(v)   ((((reg32_t) v) << BP_ESAI_RCR_RLIE) & BM_ESAI_RCR_RLIE)
#else
//! @brief Format value for bitfield ESAI_RCR_RLIE.
#define BF_ESAI_RCR_RLIE(v)   (((v) << BP_ESAI_RCR_RLIE) & BM_ESAI_RCR_RLIE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RLIE field to a new value.
#define BW_ESAI_RCR_RLIE(v)   (HW_ESAI_RCR_WR((HW_ESAI_RCR_RD() & ~BM_ESAI_RCR_RLIE) | BF_ESAI_RCR_RLIE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RCCR - Receive Clock Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The read/write Receiver Clock Control Register (ESAI_RCCR) controls the ESAI receiver clock
 * generator bit and frame sync rates, word length, and number of words per frame for the serial
 * data. The ESAI_RCCR control bits are described in the following paragraphs.  ARM Core clock is
 * ipg_clk_esai in block ESAI which is from CCM's ahb_clk_root.     Receiver High Frequency Clock
 * Divider       RFP3-RFP0  Divide Ratio      0x0  1    0x1  2    0x2  3    0x3  4    ...  ...
 * 0xF  16       SCKR Pin Definition Table        Control Bits  SCKR PIN    SYN  RCKD      0  0
 * SCKR input    0  1  SCKR output    1  0  IF0    1  1  OF0       FSR Pin Definition Table
 * Control Bits  FSR Pin    SYN  TEBE  RFSD      0  X  0  FSR input    0  X  1  FSR output    1  0
 * 0  IF1    1  0  1  OF1    1  1  0  reserved    1  1  1  Transmitter Buffer Enable       HCKR Pin
 * Definition Table        Control Bits  HCKR PIN    SYN  RHCKD      0  0  HCKR input    0  1  HCKR
 * output    1  0  IF2    1  1  OF2
 */
typedef union _hw_esai_rccr
{
    reg32_t U;
    struct _hw_esai_rccr_bitfields
    {
        unsigned RPM : 8; //!< [7:0] ESAI_RCCR Receiver Prescale Modulus Select. The RPM7-RPM0 bits specify the divide ratio of the prescale divider in the ESAI receiver clock generator. A divide ratio from 1 to 256 (RPM[7:0]=0x00 to 0xFF) may be selected. The bit clock output is available at the receiver serial bit clock (SCKR) pin. The bit clock output is also available internally for use as the bit clock to shift the receive shift registers. The ESAI receive clock generator functional diagram is shown in .
        unsigned RPSP : 1; //!< [8] ESAI_RCCR Receiver Prescaler Range. The RPSR controls a fixed divide-by-eight prescaler in series with the variable prescaler. This bit is used to extend the range of the prescaler for those cases where a slower bit clock is desired. When RPSR is set, the fixed prescaler is bypassed. When RPSR is cleared, the fixed divide-by-eight prescaler is operational (see ). The maximum internally generated bit clock frequency is Fsys/4, the minimum internally generated bit clock frequency is Fsys/(2 x 8 x 256 x 16)=Fsys/65536. (Do not use the combination RPSR=1 and RPM7-RPM0 =0x00, which causes synchronization problems when using the internal Core clock as source (RHCKD=1 or RCKD=1))
        unsigned RDC : 5; //!< [13:9] ESAI_RCCR Rx Frame Rate Divider Control. The RDC4-RDC0 bits control the divide ratio for the programmable frame rate dividers used to generate the receiver frame clocks. In network mode, this ratio may be interpreted as the number of words per frame minus one. The divide ratio may range from 2 to 32 (RDC[4:0]=0x00001 to 0x11111) for network mode. A divide ratio of one (RDC[4:0]=0x00000) in network mode is a special case (on-demand mode). In normal mode, this ratio determines the word transfer rate. The divide ratio may range from 1 to 32 (RDC[4:0]=0x00000 to 0x11111) for normal mode. In normal mode, a divide ratio of one (RDC[4:0]=0x00000) provides continuous periodic data word transfers. A bit-length frame sync (RFSL=1) must be used in this case. The ESAI frame sync generator functional diagram is shown in .
        unsigned RFP : 4; //!< [17:14] ESAI_RCCR Rx High Frequency Clock Divider. The RFP3-RFP0 bits control the divide ratio of the receiver high frequency clock to the receiver serial bit clock when the source of the receiver high frequency clock and the bit clock is the internal Arm Core clock. When the HCKR input is being driven from an external high frequency clock, the RFP3-RFP0 bits specify an additional division ration in the clock divider chain. provides the specification of the divide ratio. shows the ESAI high frequency generator functional diagram.
        unsigned RCKP : 1; //!< [18] The Receiver Clock Polarity (RCKP) bit controls on which bit clock edge data and frame sync are clocked out and latched in. If RCKP is cleared the data and the frame sync are clocked out on the rising edge of the receive bit clock and the frame sync is latched in on the falling edge of the receive bit clock. If RCKP is set the falling edge of the receive clock is used to clock the data and frame sync out and the rising edge of the receive clock is used to latch the frame sync in.
        unsigned RFSP : 1; //!< [19] ESAI_RCCR Receiver Frame Sync Polarity. The Receiver Frame Sync Polarity (RFSP) determines the polarity of the receive frame sync signal. When RFSP is cleared the frame sync signal polarity is positive, that is, the frame start is indicated by a high level on the frame sync pin. When RFSP is set the frame sync signal polarity is negative, that is, the frame start is indicated by a low level on the frame sync pin.
        unsigned RHCKP : 1; //!< [20] ESAI_RCCR Receiver High Frequency Clock Polarity. The Receiver High Frequency Clock Polarity (RHCKP) bit controls on which bit clock edge data and frame sync are clocked out and latched in. If RHCKP is cleared the data and the frame sync are clocked out on the rising edge of the receive high frequency bit clock and the frame sync is latched in on the falling edge of the receive bit clock. If RHCKP is set the falling edge of the receive clock is used to clock the data and frame sync out and the rising edge of the receive clock is used to latch the frame sync in.
        unsigned RCKD : 1; //!< [21] ESAI_RCCR Receiver Clock Source Direction. The Receiver Clock Source Direction (RCKD) bit selects the source of the clock signal used to clock the receive shift register in the asynchronous mode (SYN=0) and the IF0/OF0 flag direction in the synchronous mode (SYN=1). In the asynchronous mode, when RCKD is set, the internal clock source becomes the bit clock for the receive shift registers and word length divider and is the output on the SCKR pin. In the asynchronous mode when RCKD is cleared, the clock source is external; the internal clock generator is disconnected from the SCKR pin, and an external clock source may drive this pin. In the synchronous mode when RCKD is set, the SCKR pin becomes the OF0 output flag. If RCKD is cleared, the SCKR pin becomes the IF0 input flag. Refer to and .
        unsigned RFSD : 1; //!< [22] ESAI_RCCR Receiver Frame Sync Signal Direction. The Receiver Frame Sync Signal Direction (RFSD) bit selects the source of the receiver frame sync signal when in the asynchronous mode (SYN=0) and the IF1/OF1/Transmitter Buffer Enable flag direction in the synchronous mode (SYN=1). In the asynchronous mode, when RFSD is set, the internal clock generator becomes the source of the receiver frame sync and is the output on the FSR pin. In the asynchronous mode, when RFSD is cleared, the receiver frame sync source is external; the internal clock generator is disconnected from the FSR pin, and an external clock source may drive this pin. In the synchronous mode when RFSD is set, the FSR pin becomes the OF1 output flag or the Transmitter Buffer Enable, according to the TEBE control bit. If RFSD is cleared, the FSR pin becomes the IF1 input flag. Refer to and .
        unsigned RHCKD : 1; //!< [23] ESAI_RCCR Receiver High Frequency Clock Direction. The Receiver High Frequency Clock Direction (RHCKD) bit selects the source of the receiver high frequency clock when in the asynchronous mode (SYN=0) and the IF2/OF2 flag direction in the synchronous mode (SYN=1). In the asynchronous mode, when RHCKD is set, the internal clock generator becomes the source of the receiver high frequency clock and is the output on the HCKR pin. In the asynchronous mode, when RHCKD is cleared, the receiver high frequency clock source is external; the internal clock generator is disconnected from the HCKR pin, and an external clock source may drive this pin. When RHCKD is cleared, HCKR is an input; when RHCKD is set, HCKR is an output. In the synchronous mode when RHCKD is set, the HCKR pin becomes the OF2 output flag. If RHCKD is cleared, the HCKR pin becomes the IF2 input flag. Refer to and .
        unsigned RESERVED0 : 8; //!< [31:24] Reserved.
    } B;
} hw_esai_rccr_t;
#endif

/*
 * constants & macros for entire ESAI_RCCR register
 */
#define HW_ESAI_RCCR_ADDR      (REGS_ESAI_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RCCR           (*(volatile hw_esai_rccr_t *) HW_ESAI_RCCR_ADDR)
#define HW_ESAI_RCCR_RD()      (HW_ESAI_RCCR.U)
#define HW_ESAI_RCCR_WR(v)     (HW_ESAI_RCCR.U = (v))
#define HW_ESAI_RCCR_SET(v)    (HW_ESAI_RCCR_WR(HW_ESAI_RCCR_RD() |  (v)))
#define HW_ESAI_RCCR_CLR(v)    (HW_ESAI_RCCR_WR(HW_ESAI_RCCR_RD() & ~(v)))
#define HW_ESAI_RCCR_TOG(v)    (HW_ESAI_RCCR_WR(HW_ESAI_RCCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_RCCR bitfields
 */

/* --- Register HW_ESAI_RCCR, field RPM[7:0] (RW)
 *
 * ESAI_RCCR Receiver Prescale Modulus Select. The RPM7-RPM0 bits specify the divide ratio of the
 * prescale divider in the ESAI receiver clock generator. A divide ratio from 1 to 256
 * (RPM[7:0]=0x00 to 0xFF) may be selected. The bit clock output is available at the receiver serial
 * bit clock (SCKR) pin. The bit clock output is also available internally for use as the bit clock
 * to shift the receive shift registers. The ESAI receive clock generator functional diagram is
 * shown in .
 */

#define BP_ESAI_RCCR_RPM      (0)      //!< Bit position for ESAI_RCCR_RPM.
#define BM_ESAI_RCCR_RPM      (0x000000ff)  //!< Bit mask for ESAI_RCCR_RPM.

//! @brief Get value of ESAI_RCCR_RPM from a register value.
#define BG_ESAI_RCCR_RPM(r)   (((r) & BM_ESAI_RCCR_RPM) >> BP_ESAI_RCCR_RPM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RPM.
#define BF_ESAI_RCCR_RPM(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RPM) & BM_ESAI_RCCR_RPM)
#else
//! @brief Format value for bitfield ESAI_RCCR_RPM.
#define BF_ESAI_RCCR_RPM(v)   (((v) << BP_ESAI_RCCR_RPM) & BM_ESAI_RCCR_RPM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RPM field to a new value.
#define BW_ESAI_RCCR_RPM(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RPM) | BF_ESAI_RCCR_RPM(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RPSP[8] (RW)
 *
 * ESAI_RCCR Receiver Prescaler Range. The RPSR controls a fixed divide-by-eight prescaler in series
 * with the variable prescaler. This bit is used to extend the range of the prescaler for those
 * cases where a slower bit clock is desired. When RPSR is set, the fixed prescaler is bypassed.
 * When RPSR is cleared, the fixed divide-by-eight prescaler is operational (see ). The maximum
 * internally generated bit clock frequency is Fsys/4, the minimum internally generated bit clock
 * frequency is Fsys/(2 x 8 x 256 x 16)=Fsys/65536. (Do not use the combination RPSR=1 and RPM7-RPM0
 * =0x00, which causes synchronization problems when using the internal Core clock as source
 * (RHCKD=1 or RCKD=1))
 */

#define BP_ESAI_RCCR_RPSP      (8)      //!< Bit position for ESAI_RCCR_RPSP.
#define BM_ESAI_RCCR_RPSP      (0x00000100)  //!< Bit mask for ESAI_RCCR_RPSP.

//! @brief Get value of ESAI_RCCR_RPSP from a register value.
#define BG_ESAI_RCCR_RPSP(r)   (((r) & BM_ESAI_RCCR_RPSP) >> BP_ESAI_RCCR_RPSP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RPSP.
#define BF_ESAI_RCCR_RPSP(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RPSP) & BM_ESAI_RCCR_RPSP)
#else
//! @brief Format value for bitfield ESAI_RCCR_RPSP.
#define BF_ESAI_RCCR_RPSP(v)   (((v) << BP_ESAI_RCCR_RPSP) & BM_ESAI_RCCR_RPSP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RPSP field to a new value.
#define BW_ESAI_RCCR_RPSP(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RPSP) | BF_ESAI_RCCR_RPSP(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RDC[13:9] (RW)
 *
 * ESAI_RCCR Rx Frame Rate Divider Control. The RDC4-RDC0 bits control the divide ratio for the
 * programmable frame rate dividers used to generate the receiver frame clocks. In network mode,
 * this ratio may be interpreted as the number of words per frame minus one. The divide ratio may
 * range from 2 to 32 (RDC[4:0]=0x00001 to 0x11111) for network mode. A divide ratio of one
 * (RDC[4:0]=0x00000) in network mode is a special case (on-demand mode). In normal mode, this ratio
 * determines the word transfer rate. The divide ratio may range from 1 to 32 (RDC[4:0]=0x00000 to
 * 0x11111) for normal mode. In normal mode, a divide ratio of one (RDC[4:0]=0x00000) provides
 * continuous periodic data word transfers. A bit-length frame sync (RFSL=1) must be used in this
 * case. The ESAI frame sync generator functional diagram is shown in .
 */

#define BP_ESAI_RCCR_RDC      (9)      //!< Bit position for ESAI_RCCR_RDC.
#define BM_ESAI_RCCR_RDC      (0x00003e00)  //!< Bit mask for ESAI_RCCR_RDC.

//! @brief Get value of ESAI_RCCR_RDC from a register value.
#define BG_ESAI_RCCR_RDC(r)   (((r) & BM_ESAI_RCCR_RDC) >> BP_ESAI_RCCR_RDC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RDC.
#define BF_ESAI_RCCR_RDC(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RDC) & BM_ESAI_RCCR_RDC)
#else
//! @brief Format value for bitfield ESAI_RCCR_RDC.
#define BF_ESAI_RCCR_RDC(v)   (((v) << BP_ESAI_RCCR_RDC) & BM_ESAI_RCCR_RDC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RDC field to a new value.
#define BW_ESAI_RCCR_RDC(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RDC) | BF_ESAI_RCCR_RDC(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RFP[17:14] (RW)
 *
 * ESAI_RCCR Rx High Frequency Clock Divider. The RFP3-RFP0 bits control the divide ratio of the
 * receiver high frequency clock to the receiver serial bit clock when the source of the receiver
 * high frequency clock and the bit clock is the internal Arm Core clock. When the HCKR input is
 * being driven from an external high frequency clock, the RFP3-RFP0 bits specify an additional
 * division ration in the clock divider chain. provides the specification of the divide ratio. shows
 * the ESAI high frequency generator functional diagram.
 */

#define BP_ESAI_RCCR_RFP      (14)      //!< Bit position for ESAI_RCCR_RFP.
#define BM_ESAI_RCCR_RFP      (0x0003c000)  //!< Bit mask for ESAI_RCCR_RFP.

//! @brief Get value of ESAI_RCCR_RFP from a register value.
#define BG_ESAI_RCCR_RFP(r)   (((r) & BM_ESAI_RCCR_RFP) >> BP_ESAI_RCCR_RFP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RFP.
#define BF_ESAI_RCCR_RFP(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RFP) & BM_ESAI_RCCR_RFP)
#else
//! @brief Format value for bitfield ESAI_RCCR_RFP.
#define BF_ESAI_RCCR_RFP(v)   (((v) << BP_ESAI_RCCR_RFP) & BM_ESAI_RCCR_RFP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFP field to a new value.
#define BW_ESAI_RCCR_RFP(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RFP) | BF_ESAI_RCCR_RFP(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RCKP[18] (RW)
 *
 * The Receiver Clock Polarity (RCKP) bit controls on which bit clock edge data and frame sync are
 * clocked out and latched in. If RCKP is cleared the data and the frame sync are clocked out on the
 * rising edge of the receive bit clock and the frame sync is latched in on the falling edge of the
 * receive bit clock. If RCKP is set the falling edge of the receive clock is used to clock the data
 * and frame sync out and the rising edge of the receive clock is used to latch the frame sync in.
 */

#define BP_ESAI_RCCR_RCKP      (18)      //!< Bit position for ESAI_RCCR_RCKP.
#define BM_ESAI_RCCR_RCKP      (0x00040000)  //!< Bit mask for ESAI_RCCR_RCKP.

//! @brief Get value of ESAI_RCCR_RCKP from a register value.
#define BG_ESAI_RCCR_RCKP(r)   (((r) & BM_ESAI_RCCR_RCKP) >> BP_ESAI_RCCR_RCKP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RCKP.
#define BF_ESAI_RCCR_RCKP(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RCKP) & BM_ESAI_RCCR_RCKP)
#else
//! @brief Format value for bitfield ESAI_RCCR_RCKP.
#define BF_ESAI_RCCR_RCKP(v)   (((v) << BP_ESAI_RCCR_RCKP) & BM_ESAI_RCCR_RCKP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCKP field to a new value.
#define BW_ESAI_RCCR_RCKP(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RCKP) | BF_ESAI_RCCR_RCKP(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RFSP[19] (RW)
 *
 * ESAI_RCCR Receiver Frame Sync Polarity. The Receiver Frame Sync Polarity (RFSP) determines the
 * polarity of the receive frame sync signal. When RFSP is cleared the frame sync signal polarity is
 * positive, that is, the frame start is indicated by a high level on the frame sync pin. When RFSP
 * is set the frame sync signal polarity is negative, that is, the frame start is indicated by a low
 * level on the frame sync pin.
 */

#define BP_ESAI_RCCR_RFSP      (19)      //!< Bit position for ESAI_RCCR_RFSP.
#define BM_ESAI_RCCR_RFSP      (0x00080000)  //!< Bit mask for ESAI_RCCR_RFSP.

//! @brief Get value of ESAI_RCCR_RFSP from a register value.
#define BG_ESAI_RCCR_RFSP(r)   (((r) & BM_ESAI_RCCR_RFSP) >> BP_ESAI_RCCR_RFSP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RFSP.
#define BF_ESAI_RCCR_RFSP(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RFSP) & BM_ESAI_RCCR_RFSP)
#else
//! @brief Format value for bitfield ESAI_RCCR_RFSP.
#define BF_ESAI_RCCR_RFSP(v)   (((v) << BP_ESAI_RCCR_RFSP) & BM_ESAI_RCCR_RFSP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSP field to a new value.
#define BW_ESAI_RCCR_RFSP(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RFSP) | BF_ESAI_RCCR_RFSP(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RHCKP[20] (RW)
 *
 * ESAI_RCCR Receiver High Frequency Clock Polarity. The Receiver High Frequency Clock Polarity
 * (RHCKP) bit controls on which bit clock edge data and frame sync are clocked out and latched in.
 * If RHCKP is cleared the data and the frame sync are clocked out on the rising edge of the receive
 * high frequency bit clock and the frame sync is latched in on the falling edge of the receive bit
 * clock. If RHCKP is set the falling edge of the receive clock is used to clock the data and frame
 * sync out and the rising edge of the receive clock is used to latch the frame sync in.
 */

#define BP_ESAI_RCCR_RHCKP      (20)      //!< Bit position for ESAI_RCCR_RHCKP.
#define BM_ESAI_RCCR_RHCKP      (0x00100000)  //!< Bit mask for ESAI_RCCR_RHCKP.

//! @brief Get value of ESAI_RCCR_RHCKP from a register value.
#define BG_ESAI_RCCR_RHCKP(r)   (((r) & BM_ESAI_RCCR_RHCKP) >> BP_ESAI_RCCR_RHCKP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RHCKP.
#define BF_ESAI_RCCR_RHCKP(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RHCKP) & BM_ESAI_RCCR_RHCKP)
#else
//! @brief Format value for bitfield ESAI_RCCR_RHCKP.
#define BF_ESAI_RCCR_RHCKP(v)   (((v) << BP_ESAI_RCCR_RHCKP) & BM_ESAI_RCCR_RHCKP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RHCKP field to a new value.
#define BW_ESAI_RCCR_RHCKP(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RHCKP) | BF_ESAI_RCCR_RHCKP(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RCKD[21] (RW)
 *
 * ESAI_RCCR Receiver Clock Source Direction. The Receiver Clock Source Direction (RCKD) bit selects
 * the source of the clock signal used to clock the receive shift register in the asynchronous mode
 * (SYN=0) and the IF0/OF0 flag direction in the synchronous mode (SYN=1). In the asynchronous mode,
 * when RCKD is set, the internal clock source becomes the bit clock for the receive shift registers
 * and word length divider and is the output on the SCKR pin. In the asynchronous mode when RCKD is
 * cleared, the clock source is external; the internal clock generator is disconnected from the SCKR
 * pin, and an external clock source may drive this pin. In the synchronous mode when RCKD is set,
 * the SCKR pin becomes the OF0 output flag. If RCKD is cleared, the SCKR pin becomes the IF0 input
 * flag. Refer to and .
 */

#define BP_ESAI_RCCR_RCKD      (21)      //!< Bit position for ESAI_RCCR_RCKD.
#define BM_ESAI_RCCR_RCKD      (0x00200000)  //!< Bit mask for ESAI_RCCR_RCKD.

//! @brief Get value of ESAI_RCCR_RCKD from a register value.
#define BG_ESAI_RCCR_RCKD(r)   (((r) & BM_ESAI_RCCR_RCKD) >> BP_ESAI_RCCR_RCKD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RCKD.
#define BF_ESAI_RCCR_RCKD(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RCKD) & BM_ESAI_RCCR_RCKD)
#else
//! @brief Format value for bitfield ESAI_RCCR_RCKD.
#define BF_ESAI_RCCR_RCKD(v)   (((v) << BP_ESAI_RCCR_RCKD) & BM_ESAI_RCCR_RCKD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RCKD field to a new value.
#define BW_ESAI_RCCR_RCKD(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RCKD) | BF_ESAI_RCCR_RCKD(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RFSD[22] (RW)
 *
 * ESAI_RCCR Receiver Frame Sync Signal Direction. The Receiver Frame Sync Signal Direction (RFSD)
 * bit selects the source of the receiver frame sync signal when in the asynchronous mode (SYN=0)
 * and the IF1/OF1/Transmitter Buffer Enable flag direction in the synchronous mode (SYN=1). In the
 * asynchronous mode, when RFSD is set, the internal clock generator becomes the source of the
 * receiver frame sync and is the output on the FSR pin. In the asynchronous mode, when RFSD is
 * cleared, the receiver frame sync source is external; the internal clock generator is disconnected
 * from the FSR pin, and an external clock source may drive this pin. In the synchronous mode when
 * RFSD is set, the FSR pin becomes the OF1 output flag or the Transmitter Buffer Enable, according
 * to the TEBE control bit. If RFSD is cleared, the FSR pin becomes the IF1 input flag. Refer to and
 * .
 */

#define BP_ESAI_RCCR_RFSD      (22)      //!< Bit position for ESAI_RCCR_RFSD.
#define BM_ESAI_RCCR_RFSD      (0x00400000)  //!< Bit mask for ESAI_RCCR_RFSD.

//! @brief Get value of ESAI_RCCR_RFSD from a register value.
#define BG_ESAI_RCCR_RFSD(r)   (((r) & BM_ESAI_RCCR_RFSD) >> BP_ESAI_RCCR_RFSD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RFSD.
#define BF_ESAI_RCCR_RFSD(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RFSD) & BM_ESAI_RCCR_RFSD)
#else
//! @brief Format value for bitfield ESAI_RCCR_RFSD.
#define BF_ESAI_RCCR_RFSD(v)   (((v) << BP_ESAI_RCCR_RFSD) & BM_ESAI_RCCR_RFSD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RFSD field to a new value.
#define BW_ESAI_RCCR_RFSD(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RFSD) | BF_ESAI_RCCR_RFSD(v)))
#endif

/* --- Register HW_ESAI_RCCR, field RHCKD[23] (RW)
 *
 * ESAI_RCCR Receiver High Frequency Clock Direction. The Receiver High Frequency Clock Direction
 * (RHCKD) bit selects the source of the receiver high frequency clock when in the asynchronous mode
 * (SYN=0) and the IF2/OF2 flag direction in the synchronous mode (SYN=1). In the asynchronous mode,
 * when RHCKD is set, the internal clock generator becomes the source of the receiver high frequency
 * clock and is the output on the HCKR pin. In the asynchronous mode, when RHCKD is cleared, the
 * receiver high frequency clock source is external; the internal clock generator is disconnected
 * from the HCKR pin, and an external clock source may drive this pin. When RHCKD is cleared, HCKR
 * is an input; when RHCKD is set, HCKR is an output. In the synchronous mode when RHCKD is set, the
 * HCKR pin becomes the OF2 output flag. If RHCKD is cleared, the HCKR pin becomes the IF2 input
 * flag. Refer to and .
 */

#define BP_ESAI_RCCR_RHCKD      (23)      //!< Bit position for ESAI_RCCR_RHCKD.
#define BM_ESAI_RCCR_RHCKD      (0x00800000)  //!< Bit mask for ESAI_RCCR_RHCKD.

//! @brief Get value of ESAI_RCCR_RHCKD from a register value.
#define BG_ESAI_RCCR_RHCKD(r)   (((r) & BM_ESAI_RCCR_RHCKD) >> BP_ESAI_RCCR_RHCKD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RCCR_RHCKD.
#define BF_ESAI_RCCR_RHCKD(v)   ((((reg32_t) v) << BP_ESAI_RCCR_RHCKD) & BM_ESAI_RCCR_RHCKD)
#else
//! @brief Format value for bitfield ESAI_RCCR_RHCKD.
#define BF_ESAI_RCCR_RHCKD(v)   (((v) << BP_ESAI_RCCR_RHCKD) & BM_ESAI_RCCR_RHCKD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RHCKD field to a new value.
#define BW_ESAI_RCCR_RHCKD(v)   (HW_ESAI_RCCR_WR((HW_ESAI_RCCR_RD() & ~BM_ESAI_RCCR_RHCKD) | BF_ESAI_RCCR_RHCKD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TSMA - Transmit Slot Mask Register A (RW)
 *
 * Reset value: 0x0000ffff
 *
 * The Transmit Slot Mask Register A together with Transmit Slot Mask Register B (ESAI_TSMA and
 * ESAI_TSMB) are two read/write registers used by the transmitters in network mode to determine for
 * each slot whether to transmit a data word and generate a transmitter empty condition (TDE=1), or
 * to tri-state the transmitter data pins. Fields ESAI_TSMA [TS[15:0]] and ESAI_TSMB [TS[31:16]] are
 * concatenated to form the 32-bit field TS[31:0]. Bit number n in TS[31:0] is the enable/disable
 * control bit for transmission in slot number n.
 */
typedef union _hw_esai_tsma
{
    reg32_t U;
    struct _hw_esai_tsma_bitfields
    {
        unsigned TS : 16; //!< [15:0] When bit number N in ESAI_TSMA is cleared, all the transmit data pins of the enabled transmitters are tri-stated during transmit time slot number N. The data is still transferred from the transmit data registers to the transmit shift registers but neither the TDE nor the TUE flags are set. This means that during a disabled slot, no transmitter empty interrupt is generated. The Core is interrupted only for enabled slots. Data that is written to the transmit data registers when servicing this request is transmitted in the next enabled transmit time slot. When bit number N in ESAI_TSMA register is set, the transmit sequence is as usual: data is transferred from the TX registers to the shift registers and transmitted during slot number N, and the TDE flag is set. Using the slot mask in ESAI_TSMA does not conflict with using TSR. Even if a slot is enabled in ESAI_TSMA, the user may choose to write to TSR instead of writing to the transmit data registers TXn. This causes all the transmit data pins of the enabled transmitters to be tri-stated during the next slot. Data written to the ESAI_TSMA affects the next frame transmission. The frame being transmitted is not affected by this data and would comply to the last ESAI_TSMA setting. Data read from ESAI_TSMA returns the last written data. After hardware or software reset, the ESAI_TSMA register is preset to 0x0000FFFF, which means that all 16 possible slots are enabled for data transmission. When operating in normal mode, bit 0 of the ESAI_TSMA register must be set, otherwise no output is generated.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_esai_tsma_t;
#endif

/*
 * constants & macros for entire ESAI_TSMA register
 */
#define HW_ESAI_TSMA_ADDR      (REGS_ESAI_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TSMA           (*(volatile hw_esai_tsma_t *) HW_ESAI_TSMA_ADDR)
#define HW_ESAI_TSMA_RD()      (HW_ESAI_TSMA.U)
#define HW_ESAI_TSMA_WR(v)     (HW_ESAI_TSMA.U = (v))
#define HW_ESAI_TSMA_SET(v)    (HW_ESAI_TSMA_WR(HW_ESAI_TSMA_RD() |  (v)))
#define HW_ESAI_TSMA_CLR(v)    (HW_ESAI_TSMA_WR(HW_ESAI_TSMA_RD() & ~(v)))
#define HW_ESAI_TSMA_TOG(v)    (HW_ESAI_TSMA_WR(HW_ESAI_TSMA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_TSMA bitfields
 */

/* --- Register HW_ESAI_TSMA, field TS[15:0] (RW)
 *
 * When bit number N in ESAI_TSMA is cleared, all the transmit data pins of the enabled transmitters
 * are tri-stated during transmit time slot number N. The data is still transferred from the
 * transmit data registers to the transmit shift registers but neither the TDE nor the TUE flags are
 * set. This means that during a disabled slot, no transmitter empty interrupt is generated. The
 * Core is interrupted only for enabled slots. Data that is written to the transmit data registers
 * when servicing this request is transmitted in the next enabled transmit time slot. When bit
 * number N in ESAI_TSMA register is set, the transmit sequence is as usual: data is transferred
 * from the TX registers to the shift registers and transmitted during slot number N, and the TDE
 * flag is set. Using the slot mask in ESAI_TSMA does not conflict with using TSR. Even if a slot is
 * enabled in ESAI_TSMA, the user may choose to write to TSR instead of writing to the transmit data
 * registers TXn. This causes all the transmit data pins of the enabled transmitters to be tri-
 * stated during the next slot. Data written to the ESAI_TSMA affects the next frame transmission.
 * The frame being transmitted is not affected by this data and would comply to the last ESAI_TSMA
 * setting. Data read from ESAI_TSMA returns the last written data. After hardware or software
 * reset, the ESAI_TSMA register is preset to 0x0000FFFF, which means that all 16 possible slots are
 * enabled for data transmission. When operating in normal mode, bit 0 of the ESAI_TSMA register
 * must be set, otherwise no output is generated.
 */

#define BP_ESAI_TSMA_TS      (0)      //!< Bit position for ESAI_TSMA_TS.
#define BM_ESAI_TSMA_TS      (0x0000ffff)  //!< Bit mask for ESAI_TSMA_TS.

//! @brief Get value of ESAI_TSMA_TS from a register value.
#define BG_ESAI_TSMA_TS(r)   (((r) & BM_ESAI_TSMA_TS) >> BP_ESAI_TSMA_TS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TSMA_TS.
#define BF_ESAI_TSMA_TS(v)   ((((reg32_t) v) << BP_ESAI_TSMA_TS) & BM_ESAI_TSMA_TS)
#else
//! @brief Format value for bitfield ESAI_TSMA_TS.
#define BF_ESAI_TSMA_TS(v)   (((v) << BP_ESAI_TSMA_TS) & BM_ESAI_TSMA_TS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TS field to a new value.
#define BW_ESAI_TSMA_TS(v)   (HW_ESAI_TSMA_WR((HW_ESAI_TSMA_RD() & ~BM_ESAI_TSMA_TS) | BF_ESAI_TSMA_TS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_TSMB - Transmit Slot Mask Register B (RW)
 *
 * Reset value: 0x0000ffff
 *
 * The Transmit Slot Mask Register B together with Transmit Slot Mask Register A (ESAI_TSMA and
 * ESAI_TSMB) are two read/write registers used by the transmitters in network mode to determine for
 * each slot whether to transmit a data word and generate a transmitter empty condition (TDE=1), or
 * to tri-state the transmitter data pins. Fields ESAI_TSMA [TS[15:0]] and ESAI_TSMB [TS[31:16]] are
 * concatenated to form the 32-bit field TS[31:0]. Bit number n in TS[31:0] is the enable/disable
 * control bit for transmission in slot number n.
 */
typedef union _hw_esai_tsmb
{
    reg32_t U;
    struct _hw_esai_tsmb_bitfields
    {
        unsigned TS : 16; //!< [15:0] When bit number N in ESAI_TSMB is cleared, all the transmit data pins of the enabled transmitters are tri-stated during transmit time slot number N. The data is still transferred from the transmit data registers to the transmit shift registers but neither the TDE nor the TUE flags are set. This means that during a disabled slot, no transmitter empty interrupt is generated. The Core is interrupted only for enabled slots. Data that is written to the transmit data registers when servicing this request is transmitted in the next enabled transmit time slot. When bit number N in ESAI_TSMB register is set, the transmit sequence is as usual: data is transferred from the TX registers to the shift registers and transmitted during slot number N, and the TDE flag is set. Using the slot mask in ESAI_TSMB does not conflict with using TSR. Even if a slot is enabled in TSMB, the user may chose to write to TSR instead of writing to the transmit data registers TXn. This causes all the transmit data pins of the enabled transmitters to be tri-stated during the next slot. Data written to the ESAI_TSMB affects the next frame transmission. The frame being transmitted is not affected by this data and would comply to the last ESAI_TSMB setting. Data read from ESAI_TSMB returns the last written data. After hardware or software reset, the ESAI_TSMB register is preset to 0x0000FFFF, which means that all 16 possible slots are enabled for data transmission.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_esai_tsmb_t;
#endif

/*
 * constants & macros for entire ESAI_TSMB register
 */
#define HW_ESAI_TSMB_ADDR      (REGS_ESAI_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_TSMB           (*(volatile hw_esai_tsmb_t *) HW_ESAI_TSMB_ADDR)
#define HW_ESAI_TSMB_RD()      (HW_ESAI_TSMB.U)
#define HW_ESAI_TSMB_WR(v)     (HW_ESAI_TSMB.U = (v))
#define HW_ESAI_TSMB_SET(v)    (HW_ESAI_TSMB_WR(HW_ESAI_TSMB_RD() |  (v)))
#define HW_ESAI_TSMB_CLR(v)    (HW_ESAI_TSMB_WR(HW_ESAI_TSMB_RD() & ~(v)))
#define HW_ESAI_TSMB_TOG(v)    (HW_ESAI_TSMB_WR(HW_ESAI_TSMB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_TSMB bitfields
 */

/* --- Register HW_ESAI_TSMB, field TS[15:0] (RW)
 *
 * When bit number N in ESAI_TSMB is cleared, all the transmit data pins of the enabled transmitters
 * are tri-stated during transmit time slot number N. The data is still transferred from the
 * transmit data registers to the transmit shift registers but neither the TDE nor the TUE flags are
 * set. This means that during a disabled slot, no transmitter empty interrupt is generated. The
 * Core is interrupted only for enabled slots. Data that is written to the transmit data registers
 * when servicing this request is transmitted in the next enabled transmit time slot. When bit
 * number N in ESAI_TSMB register is set, the transmit sequence is as usual: data is transferred
 * from the TX registers to the shift registers and transmitted during slot number N, and the TDE
 * flag is set. Using the slot mask in ESAI_TSMB does not conflict with using TSR. Even if a slot is
 * enabled in TSMB, the user may chose to write to TSR instead of writing to the transmit data
 * registers TXn. This causes all the transmit data pins of the enabled transmitters to be tri-
 * stated during the next slot. Data written to the ESAI_TSMB affects the next frame transmission.
 * The frame being transmitted is not affected by this data and would comply to the last ESAI_TSMB
 * setting. Data read from ESAI_TSMB returns the last written data. After hardware or software
 * reset, the ESAI_TSMB register is preset to 0x0000FFFF, which means that all 16 possible slots are
 * enabled for data transmission.
 */

#define BP_ESAI_TSMB_TS      (0)      //!< Bit position for ESAI_TSMB_TS.
#define BM_ESAI_TSMB_TS      (0x0000ffff)  //!< Bit mask for ESAI_TSMB_TS.

//! @brief Get value of ESAI_TSMB_TS from a register value.
#define BG_ESAI_TSMB_TS(r)   (((r) & BM_ESAI_TSMB_TS) >> BP_ESAI_TSMB_TS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_TSMB_TS.
#define BF_ESAI_TSMB_TS(v)   ((((reg32_t) v) << BP_ESAI_TSMB_TS) & BM_ESAI_TSMB_TS)
#else
//! @brief Format value for bitfield ESAI_TSMB_TS.
#define BF_ESAI_TSMB_TS(v)   (((v) << BP_ESAI_TSMB_TS) & BM_ESAI_TSMB_TS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TS field to a new value.
#define BW_ESAI_TSMB_TS(v)   (HW_ESAI_TSMB_WR((HW_ESAI_TSMB_RD() & ~BM_ESAI_TSMB_TS) | BF_ESAI_TSMB_TS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RSMA - Receive Slot Mask Register A (RW)
 *
 * Reset value: 0x0000ffff
 *
 * The Receive Slot Mask Register A together with Receive Slot Mask Register B (ESAI_RSMA and
 * ESAI_RSMB) are two read/write registers used by the receiver in network mode to determine for
 * each slot whether to receive a data word and generate a receiver full condition (RDF=1), or to
 * ignore the received data. Fields ESAI_RSMA [RS[15:0]] and ESAI_RSMB [RS31:16]] are concatenated
 * to form the 32-bit field RS[31:0]. Bit number n in RS[31:0] is an enable/disable control bit for
 * receiving data in slot number n.
 */
typedef union _hw_esai_rsma
{
    reg32_t U;
    struct _hw_esai_rsma_bitfields
    {
        unsigned RS : 16; //!< [15:0] When bit number N in the ESAI_RSMA register is cleared, the data from the enabled receivers input pins are shifted into their receive shift registers during slot number N. The data is not transferred from the receive shift registers to the receive data registers, and neither the RDF nor the ROE flag is set. This means that during a disabled slot, no receiver full interrupt is generated. The Core is interrupted only for enabled slots. When bit number N in the ESAI_RSMA is set, the receive sequence is as usual: data which is shifted into the enabled receivers shift registers is transferred to the receive data registers and the RDF flag is set. Data written to the ESAI_RSMA affects the next received frame. The frame being received is not affected by this data and would comply to the last ESAI_RSMA setting. Data read from ESAI_RSMA returns the last written data. After hardware or software reset, the ESAI_RSMA register is preset to 0x0000FFFF, which means that all 16 possible slots are enabled for data reception. When operating in normal mode, bit 0 of the ESAI_RSMA register must be set to one, otherwise no input is received.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_esai_rsma_t;
#endif

/*
 * constants & macros for entire ESAI_RSMA register
 */
#define HW_ESAI_RSMA_ADDR      (REGS_ESAI_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RSMA           (*(volatile hw_esai_rsma_t *) HW_ESAI_RSMA_ADDR)
#define HW_ESAI_RSMA_RD()      (HW_ESAI_RSMA.U)
#define HW_ESAI_RSMA_WR(v)     (HW_ESAI_RSMA.U = (v))
#define HW_ESAI_RSMA_SET(v)    (HW_ESAI_RSMA_WR(HW_ESAI_RSMA_RD() |  (v)))
#define HW_ESAI_RSMA_CLR(v)    (HW_ESAI_RSMA_WR(HW_ESAI_RSMA_RD() & ~(v)))
#define HW_ESAI_RSMA_TOG(v)    (HW_ESAI_RSMA_WR(HW_ESAI_RSMA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_RSMA bitfields
 */

/* --- Register HW_ESAI_RSMA, field RS[15:0] (RW)
 *
 * When bit number N in the ESAI_RSMA register is cleared, the data from the enabled receivers input
 * pins are shifted into their receive shift registers during slot number N. The data is not
 * transferred from the receive shift registers to the receive data registers, and neither the RDF
 * nor the ROE flag is set. This means that during a disabled slot, no receiver full interrupt is
 * generated. The Core is interrupted only for enabled slots. When bit number N in the ESAI_RSMA is
 * set, the receive sequence is as usual: data which is shifted into the enabled receivers shift
 * registers is transferred to the receive data registers and the RDF flag is set. Data written to
 * the ESAI_RSMA affects the next received frame. The frame being received is not affected by this
 * data and would comply to the last ESAI_RSMA setting. Data read from ESAI_RSMA returns the last
 * written data. After hardware or software reset, the ESAI_RSMA register is preset to 0x0000FFFF,
 * which means that all 16 possible slots are enabled for data reception. When operating in normal
 * mode, bit 0 of the ESAI_RSMA register must be set to one, otherwise no input is received.
 */

#define BP_ESAI_RSMA_RS      (0)      //!< Bit position for ESAI_RSMA_RS.
#define BM_ESAI_RSMA_RS      (0x0000ffff)  //!< Bit mask for ESAI_RSMA_RS.

//! @brief Get value of ESAI_RSMA_RS from a register value.
#define BG_ESAI_RSMA_RS(r)   (((r) & BM_ESAI_RSMA_RS) >> BP_ESAI_RSMA_RS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RSMA_RS.
#define BF_ESAI_RSMA_RS(v)   ((((reg32_t) v) << BP_ESAI_RSMA_RS) & BM_ESAI_RSMA_RS)
#else
//! @brief Format value for bitfield ESAI_RSMA_RS.
#define BF_ESAI_RSMA_RS(v)   (((v) << BP_ESAI_RSMA_RS) & BM_ESAI_RSMA_RS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RS field to a new value.
#define BW_ESAI_RSMA_RS(v)   (HW_ESAI_RSMA_WR((HW_ESAI_RSMA_RD() & ~BM_ESAI_RSMA_RS) | BF_ESAI_RSMA_RS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_RSMB - Receive Slot Mask Register B (RW)
 *
 * Reset value: 0x0000ffff
 *
 * The Receive Slot Mask Register B together with Receive Slot Mask Register A (ESAI_RSMA and
 * ESAI_RSMB) are two read/write registers used by the receiver in network mode to determine for
 * each slot whether to receive a data word and generate a receiver full condition (RDF=1), or to
 * ignore the received data. Fields ESAI_RSMA [RS[15:0]] and ESAI_RSMB [RS31:16]] are concatenated
 * to form the 32-bit field RS[31:0]. Bit number n in RS[31:0] is an enable/disable control bit for
 * receiving data in slot number n.
 */
typedef union _hw_esai_rsmb
{
    reg32_t U;
    struct _hw_esai_rsmb_bitfields
    {
        unsigned RS : 16; //!< [15:0] When bit number N in the ESAI_RSMB register is cleared, the data from the enabled receivers input pins are shifted into their receive shift registers during slot number N. The data is not transferred from the receive shift registers to the receive data registers, and neither the RDF nor the ROE flag is set. This means that during a disabled slot, no receiver full interrupt is generated. The Core is interrupted only for enabled slots. When bit number N in the ESAI_RSMB is set, the receive sequence is as usual: data which is shifted into the enabled receivers shift registers is transferred to the receive data registers and the RDF flag is set. Data written to the ESAI_RSMB affects the next received frame. The frame being received is not affected by this data and would comply to the last ESAI_RSMB setting. Data read from ESAI_RSMB returns the last written data. After hardware or software reset, the ESAI_RSMB register is preset to 0x0000FFFF, which means that all 16 possible slots are enabled for data reception.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_esai_rsmb_t;
#endif

/*
 * constants & macros for entire ESAI_RSMB register
 */
#define HW_ESAI_RSMB_ADDR      (REGS_ESAI_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_RSMB           (*(volatile hw_esai_rsmb_t *) HW_ESAI_RSMB_ADDR)
#define HW_ESAI_RSMB_RD()      (HW_ESAI_RSMB.U)
#define HW_ESAI_RSMB_WR(v)     (HW_ESAI_RSMB.U = (v))
#define HW_ESAI_RSMB_SET(v)    (HW_ESAI_RSMB_WR(HW_ESAI_RSMB_RD() |  (v)))
#define HW_ESAI_RSMB_CLR(v)    (HW_ESAI_RSMB_WR(HW_ESAI_RSMB_RD() & ~(v)))
#define HW_ESAI_RSMB_TOG(v)    (HW_ESAI_RSMB_WR(HW_ESAI_RSMB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_RSMB bitfields
 */

/* --- Register HW_ESAI_RSMB, field RS[15:0] (RW)
 *
 * When bit number N in the ESAI_RSMB register is cleared, the data from the enabled receivers input
 * pins are shifted into their receive shift registers during slot number N. The data is not
 * transferred from the receive shift registers to the receive data registers, and neither the RDF
 * nor the ROE flag is set. This means that during a disabled slot, no receiver full interrupt is
 * generated. The Core is interrupted only for enabled slots. When bit number N in the ESAI_RSMB is
 * set, the receive sequence is as usual: data which is shifted into the enabled receivers shift
 * registers is transferred to the receive data registers and the RDF flag is set. Data written to
 * the ESAI_RSMB affects the next received frame. The frame being received is not affected by this
 * data and would comply to the last ESAI_RSMB setting. Data read from ESAI_RSMB returns the last
 * written data. After hardware or software reset, the ESAI_RSMB register is preset to 0x0000FFFF,
 * which means that all 16 possible slots are enabled for data reception.
 */

#define BP_ESAI_RSMB_RS      (0)      //!< Bit position for ESAI_RSMB_RS.
#define BM_ESAI_RSMB_RS      (0x0000ffff)  //!< Bit mask for ESAI_RSMB_RS.

//! @brief Get value of ESAI_RSMB_RS from a register value.
#define BG_ESAI_RSMB_RS(r)   (((r) & BM_ESAI_RSMB_RS) >> BP_ESAI_RSMB_RS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_RSMB_RS.
#define BF_ESAI_RSMB_RS(v)   ((((reg32_t) v) << BP_ESAI_RSMB_RS) & BM_ESAI_RSMB_RS)
#else
//! @brief Format value for bitfield ESAI_RSMB_RS.
#define BF_ESAI_RSMB_RS(v)   (((v) << BP_ESAI_RSMB_RS) & BM_ESAI_RSMB_RS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RS field to a new value.
#define BW_ESAI_RSMB_RS(v)   (HW_ESAI_RSMB_WR((HW_ESAI_RSMB_RD() & ~BM_ESAI_RSMB_RS) | BF_ESAI_RSMB_RS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_PRRC - Port C Direction Register (RW)
 *
 * Reset value: 0x00000000
 *
 * There are two registers to control the ESAI personal reset status: Port C Direction Register
 * (ESAI_PRRC) and Port C Control Register (ESAI_PCRC).  The read/write 32-bit Port C Direction
 * Register (ESAI_PRRC) in conjunction with the Port C Control Register (ESAI_PCRC) controls the
 * functionality of the ESAI personal reset state. provides the port pin configurations. Hardware
 * and software reset clear all ESAI_PRRC bits.
 */
typedef union _hw_esai_prrc
{
    reg32_t U;
    struct _hw_esai_prrc_bitfields
    {
        unsigned PDC : 12; //!< [11:0] See .
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_esai_prrc_t;
#endif

/*
 * constants & macros for entire ESAI_PRRC register
 */
#define HW_ESAI_PRRC_ADDR      (REGS_ESAI_BASE + 0xf8)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_PRRC           (*(volatile hw_esai_prrc_t *) HW_ESAI_PRRC_ADDR)
#define HW_ESAI_PRRC_RD()      (HW_ESAI_PRRC.U)
#define HW_ESAI_PRRC_WR(v)     (HW_ESAI_PRRC.U = (v))
#define HW_ESAI_PRRC_SET(v)    (HW_ESAI_PRRC_WR(HW_ESAI_PRRC_RD() |  (v)))
#define HW_ESAI_PRRC_CLR(v)    (HW_ESAI_PRRC_WR(HW_ESAI_PRRC_RD() & ~(v)))
#define HW_ESAI_PRRC_TOG(v)    (HW_ESAI_PRRC_WR(HW_ESAI_PRRC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_PRRC bitfields
 */

/* --- Register HW_ESAI_PRRC, field PDC[11:0] (RW)
 *
 * See .
 */

#define BP_ESAI_PRRC_PDC      (0)      //!< Bit position for ESAI_PRRC_PDC.
#define BM_ESAI_PRRC_PDC      (0x00000fff)  //!< Bit mask for ESAI_PRRC_PDC.

//! @brief Get value of ESAI_PRRC_PDC from a register value.
#define BG_ESAI_PRRC_PDC(r)   (((r) & BM_ESAI_PRRC_PDC) >> BP_ESAI_PRRC_PDC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_PRRC_PDC.
#define BF_ESAI_PRRC_PDC(v)   ((((reg32_t) v) << BP_ESAI_PRRC_PDC) & BM_ESAI_PRRC_PDC)
#else
//! @brief Format value for bitfield ESAI_PRRC_PDC.
#define BF_ESAI_PRRC_PDC(v)   (((v) << BP_ESAI_PRRC_PDC) & BM_ESAI_PRRC_PDC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDC field to a new value.
#define BW_ESAI_PRRC_PDC(v)   (HW_ESAI_PRRC_WR((HW_ESAI_PRRC_RD() & ~BM_ESAI_PRRC_PDC) | BF_ESAI_PRRC_PDC(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ESAI_PCRC - Port C Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The read/write 32-bit Port C Control Register (ESAI_PCRC) in conjunction with the Port C
 * Direction Register (ESAI_PRRC) controls the functionality of the ESAI personal reset state. Each
 * of the PC(11:0) bits controls the functionality of the corresponding port pin. provides the port
 * pin configurations. Hardware and software reset clear all ESAI_PCRC bits.   PCRC and PRRC Bits
 * Functionality        PDC[i]  PC[i]  Port Pin[i] Function      0  0  Disconnected    0  1  Not
 * used    1  0  Not used    1  1  ESAI
 */
typedef union _hw_esai_pcrc
{
    reg32_t U;
    struct _hw_esai_pcrc_bitfields
    {
        unsigned PC : 12; //!< [11:0] See .
        unsigned RESERVED0 : 20; //!< [31:12] Reserved
    } B;
} hw_esai_pcrc_t;
#endif

/*
 * constants & macros for entire ESAI_PCRC register
 */
#define HW_ESAI_PCRC_ADDR      (REGS_ESAI_BASE + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_ESAI_PCRC           (*(volatile hw_esai_pcrc_t *) HW_ESAI_PCRC_ADDR)
#define HW_ESAI_PCRC_RD()      (HW_ESAI_PCRC.U)
#define HW_ESAI_PCRC_WR(v)     (HW_ESAI_PCRC.U = (v))
#define HW_ESAI_PCRC_SET(v)    (HW_ESAI_PCRC_WR(HW_ESAI_PCRC_RD() |  (v)))
#define HW_ESAI_PCRC_CLR(v)    (HW_ESAI_PCRC_WR(HW_ESAI_PCRC_RD() & ~(v)))
#define HW_ESAI_PCRC_TOG(v)    (HW_ESAI_PCRC_WR(HW_ESAI_PCRC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ESAI_PCRC bitfields
 */

/* --- Register HW_ESAI_PCRC, field PC[11:0] (RW)
 *
 * See .
 */

#define BP_ESAI_PCRC_PC      (0)      //!< Bit position for ESAI_PCRC_PC.
#define BM_ESAI_PCRC_PC      (0x00000fff)  //!< Bit mask for ESAI_PCRC_PC.

//! @brief Get value of ESAI_PCRC_PC from a register value.
#define BG_ESAI_PCRC_PC(r)   (((r) & BM_ESAI_PCRC_PC) >> BP_ESAI_PCRC_PC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ESAI_PCRC_PC.
#define BF_ESAI_PCRC_PC(v)   ((((reg32_t) v) << BP_ESAI_PCRC_PC) & BM_ESAI_PCRC_PC)
#else
//! @brief Format value for bitfield ESAI_PCRC_PC.
#define BF_ESAI_PCRC_PC(v)   (((v) << BP_ESAI_PCRC_PC) & BM_ESAI_PCRC_PC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PC field to a new value.
#define BW_ESAI_PCRC_PC(v)   (HW_ESAI_PCRC_WR((HW_ESAI_PCRC_RD() & ~BM_ESAI_PCRC_PC) | BF_ESAI_PCRC_PC(v)))
#endif


/*!
 * @brief All ESAI module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_esai
{
    volatile hw_esai_etdr_t ETDR; //!< ESAI Transmit Data Register
    volatile hw_esai_erdr_t ERDR; //!< ESAI Receive Data Register
    volatile hw_esai_ecr_t ECR; //!< ESAI Control Register
    volatile hw_esai_esr_t ESR; //!< ESAI Status Register
    volatile hw_esai_tfcr_t TFCR; //!< Transmit FIFO Configuration Register
    volatile hw_esai_tfsr_t TFSR; //!< Transmit FIFO Status Register
    volatile hw_esai_rfcr_t RFCR; //!< Receive FIFO Configuration Register
    volatile hw_esai_rfsr_t RFSR; //!< Receive FIFO Status Register
    reg32_t _reserved0[24];
    volatile hw_esai_tx0_t TX0; //!< Transmit Data Register n
    volatile hw_esai_tx1_t TX1; //!< Transmit Data Register n
    volatile hw_esai_tx2_t TX2; //!< Transmit Data Register n
    volatile hw_esai_tx3_t TX3; //!< Transmit Data Register n
    volatile hw_esai_tx4_t TX4; //!< Transmit Data Register n
    volatile hw_esai_tx5_t TX5; //!< Transmit Data Register n
    volatile hw_esai_tx_t TX; //!< Transmit Data Register n
    reg32_t _reserved1;
    volatile hw_esai_rx0_t RX0; //!< Receive Data Register n
    volatile hw_esai_rx1_t RX1; //!< Receive Data Register n
    volatile hw_esai_rx2_t RX2; //!< Receive Data Register n
    volatile hw_esai_rx3_t RX3; //!< Receive Data Register n
    reg32_t _reserved2[7];
    volatile hw_esai_saisr_t SAISR; //!< Serial Audio Interface Status Register
    volatile hw_esai_saicr_t SAICR; //!< Serial Audio Interface Control Register
    volatile hw_esai_tcr_t TCR; //!< Transmit Control Register
    volatile hw_esai_tccr_t TCCR; //!< Transmit Clock Control Register
    volatile hw_esai_rcr_t RCR; //!< Receive Control Register
    volatile hw_esai_rccr_t RCCR; //!< Receive Clock Control Register
    volatile hw_esai_tsma_t TSMA; //!< Transmit Slot Mask Register A
    volatile hw_esai_tsmb_t TSMB; //!< Transmit Slot Mask Register B
    volatile hw_esai_rsma_t RSMA; //!< Receive Slot Mask Register A
    volatile hw_esai_rsmb_t RSMB; //!< Receive Slot Mask Register B
    reg32_t _reserved3;
    volatile hw_esai_prrc_t PRRC; //!< Port C Direction Register
    volatile hw_esai_pcrc_t PCRC; //!< Port C Control Register
} hw_esai_t;
#pragma pack()

//! @brief Macro to access all ESAI registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ESAI(0)</code>.
#define HW_ESAI     (*(volatile hw_esai_t *) REGS_ESAI_BASE)

#endif


#endif // __HW_ESAI_REGISTERS_H__
