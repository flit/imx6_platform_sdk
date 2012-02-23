/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EIM_H
#define _EIM_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_EIM_CSGCR1 - Chip Select n General Configuration Register 1
 * - HW_EIM_CSGCR2 - Chip Select n General Configuration Register 2
 * - HW_EIM_CSRCR1 - Chip Select n Read Configuration Register 1
 * - HW_EIM_CSRCR2 - Chip Select n Read Configuration Register 2
 * - HW_EIM_CSWCR1 - Chip Select n Write Configuration Register 1
 * - HW_EIM_CSWCR2 - Chip Select n Write Configuration Register 2
 * - HW_EIM_WCR - EIM Configuration Register
 * - HW_EIM_WIAR - EIM IP Access Register
 * - HW_EIM_EAR - Error Address Register
 *
 * hw_eim_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_EIM_BASE
#define REGS_EIM_BASE (0x021b8000) //!< Base address for EIM.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR1 - Chip Select n General Configuration Register 1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CSEN : 1; //!< CS Enable. This bit controls the operation of the chip select pin. CSEN is set by a hardware reset for CSGCR0 to allow external boot operation. CSEN is cleared by a hardware reset to CSGCR1-CSGCR5. Reset value for EIM_CS0GCR1 for CSEN is 1. For EIM_CS1GCR1-CS1GCR5 reset value is 0.
        unsigned SWR : 1; //!< Synchronous Write Data. This bit field determine the write accesses mode to the External device of the chip select. The External device should be configured to the same mode as this bit implicates. SWR is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
        unsigned SRD : 1; //!< Synchronous Read Data. This bit field determine the read accesses mode to the External device of the chip select. The External device should be configured to the same mode as this bit implicates. SRD is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
        unsigned MUM : 1; //!< Multiplexed Mode. This bit determines the address/data multiplexed mode for asynchronous and synchronous accesses for 8 bit, 16 bit or 32 bit devices (DSZ config. dependent). The reset value for EIM_CS0GCR1[MUM] = EIM_BOOT[2]. For EIM_CS1GCR1 - EIM_CS5GCR1 the reset value is 0.
        unsigned WFL : 1; //!< Write Fix Latency. This bit field determine if the controller is monitoring the WAIT signal from the External device connected to the chip select (handshake mode - fix or variable data latency) or if it start data transfer according to WWSC field, it only valid in synchronous mode. WFL is cleared by a hardware reset. When WFL=1 Burst access is terminated on page boundary and resume on the following page according to BL bit field configuration, because WAIT signal is not monitored from the external device
        unsigned RFL : 1; //!< Read Fix Latency. This bit field determine if the controller is monitoring the WAIT signal from the External device connected to the chip select (handshake mode - fix or variable data latency) or if it start sampling data according to RWSC field, it only valid in synchronous mode. RFL is cleared by a hardware reset. When RFL=1 Burst access is terminated on page boundary and resume on the following page according to BL bit field configuration, because WAIT signal is not monitored from the external device.
        unsigned CRE : 1; //!< Configuration Register Enable. This bit indicates CRE memory pin state while executing a memory register set command to PSRAM external device. CRE is cleared by a hardware reset.
        unsigned CREP : 1; //!< Configuration Register Enable Polarity. This bit indicates CRE memory pin assertion state, active-low or active-high, while executing a memory register set command to the external device (PSRAM memory type). CREP is set by a hardware reset. Whenever PSRAM is connected the CREP value must be correct also for accesses where CRE is disabled. For Non-PSRAM memory CREP value should be 1.
        unsigned BL : 3; //!< Burst Length. The BL bit field indicates memory burst length in words (word is defined by the DSZ field) and should be properly initialized for mixed wrap/increment accesses support. Continuous BL value corresponds to continuous burst length setting of the external memory device. For fix memory burst size, type is always wrap. In case not matching wrap boundaries in both the memory (BL field) and Master access on the current address, EIM update address on the external device address bus and regenerates the access. BL is cleared by a hardware reset. When APR=1, Page Read Mode is applied, BL determine the number of words within the read page burst. BL is cleared by a hardware reset for EIM_CS0GCR1 - EIM_CS5GCR1.
        unsigned WC : 1; //!< Write Continuous. The WI bit indicates that write access to the memory are always continuous accesses regardless of the BL field value. WI is cleared by hardware reset.
        unsigned BCD : 2; //!< Burst Clock Divisor. This bit field contains the value used to program the burst clock divisor for BCLK generation. It is used to divide the internal EIMbus frequency. BCD is cleared by a hardware reset. For other then the mentioned below frequency such as 104 MHz, EIM clock (input clock) should be adjust accordingly.
        unsigned BCS : 2; //!< Burst Clock Start. When SRD=1 or SWR=1,this bit field determines the number of EIM clock cycles delay from start of access before the first rising edge of BCLK is generated. When BCD=0 value of BCS=0 results in a half clock delay after the start of access. For other values of BCD a one clock delay after the start of access is applied, not an immediate assertion. BCS is cleared by a hardware reset.
        unsigned DSZ : 3; //!< Data Port Size. This bit field defines the width of an external device's data port as shown below. Only async. access supported for 8 bit port. The reset value for EIM_CS0GCR1[DSZ] = {EIM_BOOT[11], EIM_BOOT[1:0]} EIM_CS0GCR1, DSZ[2] = 0, DSZ[1:0] = EIM_BOOT[1:0]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value is 0b001.
        unsigned SP : 1; //!< Supervisor Protect. This bit prevents accesses to the address range defined by the corresponding chip select when the access is attempted in the User mode. SP is cleared by a hardware reset.
        unsigned CSREC : 3; //!< CS Recovery. This bit field, according to the settings shown below, determines the minimum pulse width of CS, OE, and WE control signals before executing a new back to back access to the same chip select. CSREC is cleared by a hardware reset. The reset value for EIM_CS0GCR1, CSREC[2:1] is EIM_BOOT[9:8], for CSREC[0] is 0 CSREC[2:0] is 0b110. For EIM_CS1GCR1 - EIM_CS5GCR, the reset value is 0b000. Example settings:
        unsigned AUS : 1; //!< Address UnShifted. This bit indicates an unshifted mode for address assertion for the relevant chip select accesses. AUS bit is cleared by hardware reset. The reset value for EIM_CS0GCR1[AUS] = EIM_BOOT[10]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value of AUS is 0.
        unsigned GBC : 3; //!< Gap Between Chip Selects. This bit field, according to the settings shown below, determines the minimum time between end of access to the current chip select and start of access to different chip select. GBC is cleared by a hardware reset. Example settings:
        unsigned WP : 1; //!< Write Protect. This bit prevents writes to the address range defined by the corresponding chip select. WP is cleared by a hardware reset.
        unsigned PSZ : 4; //!< Page Size. This bit field indicates memory page size in words (word is defined by the DSZ field). PSZ is used when fix latency mode is applied, WFL=1 for sync. write accesses, RFL=1 for sync. Read accesses. When working in fix latency mode WAIT signal from the external device is not being monitored, PSZ is used to determine if page boundary is reached and renewal of access is preformed. This bit field is ignored when sync. Mode is disabled or fix latency mode is not being used for write or read access separately. It can be valid for both access type, read or write, or only for one type, according to configuration. PSZ is cleared by a hardware reset.
    } B;
} hw_eim_csgcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR1 register
 */
#define HW_EIM_CSGCR1_ADDR      (REGS_EIM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR1           (*(volatile hw_eim_csgcr1_t *) HW_EIM_CSGCR1_ADDR)
#define HW_EIM_CSGCR1_RD()      (HW_EIM_CSGCR1.U)
#define HW_EIM_CSGCR1_WR(v)     (HW_EIM_CSGCR1.U = (v))
#define HW_EIM_CSGCR1_SET(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() |  (v)))
#define HW_EIM_CSGCR1_CLR(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() & ~(v)))
#define HW_EIM_CSGCR1_TOG(v)    (HW_EIM_CSGCR1_WR(HW_EIM_CSGCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR1 bitfields
 */

/* --- Register HW_EIM_CSGCR1, field CSEN (RW)
 *
 * CS Enable. This bit controls the operation of the chip select pin. CSEN is set by a hardware
 * reset for CSGCR0 to allow external boot operation. CSEN is cleared by a hardware reset to
 * CSGCR1-CSGCR5. Reset value for EIM_CS0GCR1 for CSEN is 1. For EIM_CS1GCR1-CS1GCR5 reset value is
 * 0.
 *
 * Values:
 * 0 - Chip select function is disabled; attempts to access an address mapped by this chip select results
 *     in an error respond and no assertion of the chip select output
 * 1 - Chip select is enabled, and is asserted when presented with a valid access.
 */

#define BP_EIM_CSGCR1_CSEN      0
#define BM_EIM_CSGCR1_CSEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR1_CSEN)
#else
#define BF_EIM_CSGCR1_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR1_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSEN field to a new value.
#define BW_EIM_CSGCR1_CSEN(v)   BF_CS1(EIM_CSGCR1, CSEN, v)
#endif


/* --- Register HW_EIM_CSGCR1, field SWR (RW)
 *
 * Synchronous Write Data. This bit field determine the write accesses mode to the External device
 * of the chip select. The External device should be configured to the same mode as this bit
 * implicates. SWR is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - write accesses are in Asynchronous mode
 * 1 - write accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR1_SWR      1
#define BM_EIM_CSGCR1_SWR      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR1_SWR)
#else
#define BF_EIM_CSGCR1_SWR(v)   (((v) << 1) & BM_EIM_CSGCR1_SWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_EIM_CSGCR1_SWR(v)   BF_CS1(EIM_CSGCR1, SWR, v)
#endif


/* --- Register HW_EIM_CSGCR1, field SRD (RW)
 *
 * Synchronous Read Data. This bit field determine the read accesses mode to the External device of
 * the chip select. The External device should be configured to the same mode as this bit
 * implicates. SRD is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - read accesses are in Asynchronous mode
 * 1 - read accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR1_SRD      2
#define BM_EIM_CSGCR1_SRD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR1_SRD)
#else
#define BF_EIM_CSGCR1_SRD(v)   (((v) << 2) & BM_EIM_CSGCR1_SRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRD field to a new value.
#define BW_EIM_CSGCR1_SRD(v)   BF_CS1(EIM_CSGCR1, SRD, v)
#endif


/* --- Register HW_EIM_CSGCR1, field MUM (RW)
 *
 * Multiplexed Mode. This bit determines the address/data multiplexed mode for asynchronous and
 * synchronous accesses for 8 bit, 16 bit or 32 bit devices (DSZ config. dependent). The reset value
 * for EIM_CS0GCR1[MUM] = EIM_BOOT[2]. For EIM_CS1GCR1 - EIM_CS5GCR1 the reset value is 0.
 *
 * Values:
 * 0 - Multiplexed Mode disable
 * 1 - Multiplexed Mode enable
 */

#define BP_EIM_CSGCR1_MUM      3
#define BM_EIM_CSGCR1_MUM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR1_MUM)
#else
#define BF_EIM_CSGCR1_MUM(v)   (((v) << 3) & BM_EIM_CSGCR1_MUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUM field to a new value.
#define BW_EIM_CSGCR1_MUM(v)   BF_CS1(EIM_CSGCR1, MUM, v)
#endif


/* --- Register HW_EIM_CSGCR1, field WFL (RW)
 *
 * Write Fix Latency. This bit field determine if the controller is monitoring the WAIT signal from
 * the External device connected to the chip select (handshake mode - fix or variable data latency)
 * or if it start data transfer according to WWSC field, it only valid in synchronous mode. WFL is
 * cleared by a hardware reset. When WFL=1 Burst access is terminated on page boundary and resume on
 * the following page according to BL bit field configuration, because WAIT signal is not monitored
 * from the external device
 *
 * Values:
 * 0 - the External device WAIT signal is being monitored, and it reflect the external data bus state
 * 1 - the state of the External devices is determined internally (Fix latency mode only)
 */

#define BP_EIM_CSGCR1_WFL      4
#define BM_EIM_CSGCR1_WFL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR1_WFL)
#else
#define BF_EIM_CSGCR1_WFL(v)   (((v) << 4) & BM_EIM_CSGCR1_WFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WFL field to a new value.
#define BW_EIM_CSGCR1_WFL(v)   BF_CS1(EIM_CSGCR1, WFL, v)
#endif


/* --- Register HW_EIM_CSGCR1, field RFL (RW)
 *
 * Read Fix Latency. This bit field determine if the controller is monitoring the WAIT signal from
 * the External device connected to the chip select (handshake mode - fix or variable data latency)
 * or if it start sampling data according to RWSC field, it only valid in synchronous mode. RFL is
 * cleared by a hardware reset. When RFL=1 Burst access is terminated on page boundary and resume on
 * the following page according to BL bit field configuration, because WAIT signal is not monitored
 * from the external device.
 *
 * Values:
 * 0 - the External device WAIT signal is being monitored, and it reflect the external data bus state
 * 1 - the state of the External devices is determined internally (Fix latency mode only)
 */

#define BP_EIM_CSGCR1_RFL      5
#define BM_EIM_CSGCR1_RFL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR1_RFL)
#else
#define BF_EIM_CSGCR1_RFL(v)   (((v) << 5) & BM_EIM_CSGCR1_RFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFL field to a new value.
#define BW_EIM_CSGCR1_RFL(v)   BF_CS1(EIM_CSGCR1, RFL, v)
#endif


/* --- Register HW_EIM_CSGCR1, field CRE (RW)
 *
 * Configuration Register Enable. This bit indicates CRE memory pin state while executing a memory
 * register set command to PSRAM external device. CRE is cleared by a hardware reset.
 *
 * Values:
 * 0 - CRE signal use is disable
 * 1 - CRE signal use is enable
 */

#define BP_EIM_CSGCR1_CRE      6
#define BM_EIM_CSGCR1_CRE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR1_CRE)
#else
#define BF_EIM_CSGCR1_CRE(v)   (((v) << 6) & BM_EIM_CSGCR1_CRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRE field to a new value.
#define BW_EIM_CSGCR1_CRE(v)   BF_CS1(EIM_CSGCR1, CRE, v)
#endif


/* --- Register HW_EIM_CSGCR1, field CREP (RW)
 *
 * Configuration Register Enable Polarity. This bit indicates CRE memory pin assertion state,
 * active-low or active-high, while executing a memory register set command to the external device
 * (PSRAM memory type). CREP is set by a hardware reset. Whenever PSRAM is connected the CREP value
 * must be correct also for accesses where CRE is disabled. For Non-PSRAM memory CREP value should
 * be 1.
 *
 * Values:
 * 0 - CRE signal is active low
 * 1 - CRE signal is active high
 */

#define BP_EIM_CSGCR1_CREP      7
#define BM_EIM_CSGCR1_CREP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR1_CREP)
#else
#define BF_EIM_CSGCR1_CREP(v)   (((v) << 7) & BM_EIM_CSGCR1_CREP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CREP field to a new value.
#define BW_EIM_CSGCR1_CREP(v)   BF_CS1(EIM_CSGCR1, CREP, v)
#endif


/* --- Register HW_EIM_CSGCR1, field BL (RW)
 *
 * Burst Length. The BL bit field indicates memory burst length in words (word is defined by the DSZ
 * field) and should be properly initialized for mixed wrap/increment accesses support. Continuous
 * BL value corresponds to continuous burst length setting of the external memory device. For fix
 * memory burst size, type is always wrap. In case not matching wrap boundaries in both the memory
 * (BL field) and Master access on the current address, EIM update address on the external device
 * address bus and regenerates the access. BL is cleared by a hardware reset. When APR=1, Page Read
 * Mode is applied, BL determine the number of words within the read page burst. BL is cleared by a
 * hardware reset for EIM_CS0GCR1 - EIM_CS5GCR1.
 *
 * Values:
 * 000 - 4 words Memory wrap burst length (read page burst size when APR = 1)
 * 001 - 8 words Memory wrap burst length (read page burst size when APR = 1)
 * 010 - 16 words Memory wrap burst length (read page burst size when APR = 1)
 * 011 - 32 words Memory wrap burst length (read page burst size when APR = 1)
 * 100 - Continuous burst length (2 words read page burst size when APR = 1)
 * 101 - Reserved
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_EIM_CSGCR1_BL      8
#define BM_EIM_CSGCR1_BL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR1_BL)
#else
#define BF_EIM_CSGCR1_BL(v)   (((v) << 8) & BM_EIM_CSGCR1_BL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BL field to a new value.
#define BW_EIM_CSGCR1_BL(v)   BF_CS1(EIM_CSGCR1, BL, v)
#endif


/* --- Register HW_EIM_CSGCR1, field WC (RW)
 *
 * Write Continuous. The WI bit indicates that write access to the memory are always continuous
 * accesses regardless of the BL field value. WI is cleared by hardware reset.
 *
 * Values:
 * 0 - Write access burst length occurs according to BL value.
 * 1 - Write access burst length is continuous.
 */

#define BP_EIM_CSGCR1_WC      11
#define BM_EIM_CSGCR1_WC      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR1_WC)
#else
#define BF_EIM_CSGCR1_WC(v)   (((v) << 11) & BM_EIM_CSGCR1_WC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WC field to a new value.
#define BW_EIM_CSGCR1_WC(v)   BF_CS1(EIM_CSGCR1, WC, v)
#endif


/* --- Register HW_EIM_CSGCR1, field BCD (RW)
 *
 * Burst Clock Divisor. This bit field contains the value used to program the burst clock divisor
 * for BCLK generation. It is used to divide the internal EIMbus frequency. BCD is cleared by a
 * hardware reset. For other then the mentioned below frequency such as 104 MHz, EIM clock (input
 * clock) should be adjust accordingly.
 *
 * Values:
 * 00 - Divide EIM clock by 1
 * 01 - Divide EIM clock by 2
 * 10 - Divide EIM clock by 3
 * 11 - Divide EIM clock by 4
 */

#define BP_EIM_CSGCR1_BCD      12
#define BM_EIM_CSGCR1_BCD      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR1_BCD)
#else
#define BF_EIM_CSGCR1_BCD(v)   (((v) << 12) & BM_EIM_CSGCR1_BCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCD field to a new value.
#define BW_EIM_CSGCR1_BCD(v)   BF_CS1(EIM_CSGCR1, BCD, v)
#endif


/* --- Register HW_EIM_CSGCR1, field BCS (RW)
 *
 * Burst Clock Start. When SRD=1 or SWR=1,this bit field determines the number of EIM clock cycles
 * delay from start of access before the first rising edge of BCLK is generated. When BCD=0 value of
 * BCS=0 results in a half clock delay after the start of access. For other values of BCD a one
 * clock delay after the start of access is applied, not an immediate assertion. BCS is cleared by a
 * hardware reset.
 *
 * Values:
 * 00 - 0 EIM clock cycle additional delay
 * 01 - 1 EIM clock cycle additional delay
 * 10 - 2 EIM clock cycle additional delay
 * 11 - 3 EIM clock cycle additional delay
 */

#define BP_EIM_CSGCR1_BCS      14
#define BM_EIM_CSGCR1_BCS      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR1_BCS)
#else
#define BF_EIM_CSGCR1_BCS(v)   (((v) << 14) & BM_EIM_CSGCR1_BCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCS field to a new value.
#define BW_EIM_CSGCR1_BCS(v)   BF_CS1(EIM_CSGCR1, BCS, v)
#endif


/* --- Register HW_EIM_CSGCR1, field DSZ (RW)
 *
 * Data Port Size. This bit field defines the width of an external device's data port as shown
 * below. Only async. access supported for 8 bit port. The reset value for EIM_CS0GCR1[DSZ] =
 * {EIM_BOOT[11], EIM_BOOT[1:0]} EIM_CS0GCR1, DSZ[2] = 0, DSZ[1:0] = EIM_BOOT[1:0]. For EIM_CS1GCR1
 * - EIM_CS5GCR1, the reset value is 0b001.
 *
 * Values:
 * 000 - Reserved.
 * 001 - 16 bit port resides on DATA[15:0]
 * 010 - 16 bit port resides on DATA[31:16]
 * 011 - 32 bit port resides on DATA[31:0]
 * 100 - 8 bit port resides on DATA[7:0]
 * 101 - 8 bit port resides on DATA[15:8]
 * 110 - 8 bit port resides on DATA[23:16]
 * 111 - 8 bit port resides on DATA[31:24]
 */

#define BP_EIM_CSGCR1_DSZ      16
#define BM_EIM_CSGCR1_DSZ      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR1_DSZ)
#else
#define BF_EIM_CSGCR1_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR1_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSZ field to a new value.
#define BW_EIM_CSGCR1_DSZ(v)   BF_CS1(EIM_CSGCR1, DSZ, v)
#endif


/* --- Register HW_EIM_CSGCR1, field SP (RW)
 *
 * Supervisor Protect. This bit prevents accesses to the address range defined by the corresponding
 * chip select when the access is attempted in the User mode. SP is cleared by a hardware reset.
 *
 * Values:
 * 0 - User mode accesses are allowed in the memory range defined by chip select.
 * 1 - User mode accesses are prohibited. All attempts to access an address mapped by this chip select in
 *     User mode results in an error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR1_SP      19
#define BM_EIM_CSGCR1_SP      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR1_SP)
#else
#define BF_EIM_CSGCR1_SP(v)   (((v) << 19) & BM_EIM_CSGCR1_SP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SP field to a new value.
#define BW_EIM_CSGCR1_SP(v)   BF_CS1(EIM_CSGCR1, SP, v)
#endif


/* --- Register HW_EIM_CSGCR1, field CSREC (RW)
 *
 * CS Recovery. This bit field, according to the settings shown below, determines the minimum pulse
 * width of CS, OE, and WE control signals before executing a new back to back access to the same
 * chip select. CSREC is cleared by a hardware reset. The reset value for EIM_CS0GCR1, CSREC[2:1] is
 * EIM_BOOT[9:8], for CSREC[0] is 0 CSREC[2:0] is 0b110. For EIM_CS1GCR1 - EIM_CS5GCR, the reset
 * value is 0b000. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles minimum width of CS, OE and WE signals (read async. mode only)
 * 001 - 1 EIM clock cycles minimum width of CS, OE and WE signals
 * 010 - 2 EIM clock cycles minimum width of CS, OE and WE signals
 * 111 - 7 EIM clock cycles minimum width of CS, OE and WE signals
 */

#define BP_EIM_CSGCR1_CSREC      20
#define BM_EIM_CSGCR1_CSREC      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR1_CSREC)
#else
#define BF_EIM_CSGCR1_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR1_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSREC field to a new value.
#define BW_EIM_CSGCR1_CSREC(v)   BF_CS1(EIM_CSGCR1, CSREC, v)
#endif


/* --- Register HW_EIM_CSGCR1, field AUS (RW)
 *
 * Address UnShifted. This bit indicates an unshifted mode for address assertion for the relevant
 * chip select accesses. AUS bit is cleared by hardware reset. The reset value for EIM_CS0GCR1[AUS]
 * = EIM_BOOT[10]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value of AUS is 0.
 *
 * Values:
 * 0 - Address shifted according to port size (DSZ config.)
 * 1 - Address unshifted
 */

#define BP_EIM_CSGCR1_AUS      23
#define BM_EIM_CSGCR1_AUS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR1_AUS)
#else
#define BF_EIM_CSGCR1_AUS(v)   (((v) << 23) & BM_EIM_CSGCR1_AUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUS field to a new value.
#define BW_EIM_CSGCR1_AUS(v)   BF_CS1(EIM_CSGCR1, AUS, v)
#endif


/* --- Register HW_EIM_CSGCR1, field GBC (RW)
 *
 * Gap Between Chip Selects. This bit field, according to the settings shown below, determines the
 * minimum time between end of access to the current chip select and start of access to different
 * chip select. GBC is cleared by a hardware reset. Example settings:
 *
 * Values:
 * 000 - minimum of 0 EIM clock cycles before next access from different chip select (async. mode only)
 * 001 - minimum of 1 EIM clock cycles before next access from different chip select
 * 010 - minimum of 2 EIM clock cycles before next access from different chip select
 * 111 - minimum of 7 EIM clock cycles before next access from different chip select
 */

#define BP_EIM_CSGCR1_GBC      24
#define BM_EIM_CSGCR1_GBC      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR1_GBC)
#else
#define BF_EIM_CSGCR1_GBC(v)   (((v) << 24) & BM_EIM_CSGCR1_GBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBC field to a new value.
#define BW_EIM_CSGCR1_GBC(v)   BF_CS1(EIM_CSGCR1, GBC, v)
#endif


/* --- Register HW_EIM_CSGCR1, field WP (RW)
 *
 * Write Protect. This bit prevents writes to the address range defined by the corresponding chip
 * select. WP is cleared by a hardware reset.
 *
 * Values:
 * 0 - Writes are allowed in the memory range defined by chip.
 * 1 - Writes are prohibited. All attempts to write to an address mapped by this chip select result in a
 *     error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR1_WP      27
#define BM_EIM_CSGCR1_WP      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR1_WP)
#else
#define BF_EIM_CSGCR1_WP(v)   (((v) << 27) & BM_EIM_CSGCR1_WP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WP field to a new value.
#define BW_EIM_CSGCR1_WP(v)   BF_CS1(EIM_CSGCR1, WP, v)
#endif


/* --- Register HW_EIM_CSGCR1, field PSZ (RW)
 *
 * Page Size. This bit field indicates memory page size in words (word is defined by the DSZ field).
 * PSZ is used when fix latency mode is applied, WFL=1 for sync. write accesses, RFL=1 for sync.
 * Read accesses. When working in fix latency mode WAIT signal from the external device is not being
 * monitored, PSZ is used to determine if page boundary is reached and renewal of access is
 * preformed. This bit field is ignored when sync. Mode is disabled or fix latency mode is not being
 * used for write or read access separately. It can be valid for both access type, read or write, or
 * only for one type, according to configuration. PSZ is cleared by a hardware reset.
 *
 * Values:
 * 0000 - 8 words page size
 * 0001 - 16 words page size
 * 0010 - 32 words page size
 * 0011 - 64 words page size
 * 0100 - 128 words page size
 * 0101 - 256 words page size
 * 0110 - 512 words page size
 * 0111 - 1024 (1k) words page size
 * 1000 - 2048 (2k) words page size
 * 1001 - - 1111 Reserved
 */

#define BP_EIM_CSGCR1_PSZ      28
#define BM_EIM_CSGCR1_PSZ      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR1_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR1_PSZ)
#else
#define BF_EIM_CSGCR1_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR1_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSZ field to a new value.
#define BW_EIM_CSGCR1_PSZ(v)   BF_CS1(EIM_CSGCR1, PSZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR2 - Chip Select n General Configuration Register 2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADH : 2; //!< Address hold time - This bit field determine the address hold time after ADV negation when mum = 1 (muxed mode). When mum = 0 this bit has no effect. For read accesses the field determines when the pads direction will be switched. Reset value for EIM_CS0GCR2 for ADH is 10. For EIM_CS1GCR2-EIM_CS5GCR2 reset value is 00.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned DAPS : 4; //!< Data Acknowledge Poling Start. This bit field determine the starting point of DTACK input signal polling. DAPS is used only in asynchronous single read or write accesses. Since DTACK is an async. signal the start point of DTACK signal polling is at least 3 cycles after the start of access. DAPS is cleared by a hardware reset. Example settings:
        unsigned DAE : 1; //!< Data Acknowledge Enable. This bit indicates external device is using DTACK pin as strobe/terminator of an async. access. DTACK signal may be used only in asynchronous single read (APR=0) or write accesses. DTACK poling start point is set by DAPS bit field. polarity of DTACK is set by DAP bit field. DAE is cleared by a hardware reset.
        unsigned DAP : 1; //!< Data Acknowledge Polarity. This bit indicates DTACK memory pin assertion state, active-low or active-high, while executing an async access using DTACK signal from the external device. DAP is cleared by a hardware reset.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned MUX16_BYP_GRANT : 1; //!< Muxed 16 bypass grant. This bit when asserted causes EIM to bypass the grant/ack. arbitration with NFC (only for 16 bit muxed mode accesses). The reset value for EIM_CS0GCR2[MUX16_BYP_GRANT] = EIM_BOOT[12]. For EIM_CS1GCR2 - EIM_CS5GCR2, MUX16_BYP_GRANT reset value is 1.
        unsigned RESERVED2 : 19; //!< Reserved
    } B;
} hw_eim_csgcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR2 register
 */
#define HW_EIM_CSGCR2_ADDR      (REGS_EIM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR2           (*(volatile hw_eim_csgcr2_t *) HW_EIM_CSGCR2_ADDR)
#define HW_EIM_CSGCR2_RD()      (HW_EIM_CSGCR2.U)
#define HW_EIM_CSGCR2_WR(v)     (HW_EIM_CSGCR2.U = (v))
#define HW_EIM_CSGCR2_SET(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() |  (v)))
#define HW_EIM_CSGCR2_CLR(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() & ~(v)))
#define HW_EIM_CSGCR2_TOG(v)    (HW_EIM_CSGCR2_WR(HW_EIM_CSGCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR2 bitfields
 */

/* --- Register HW_EIM_CSGCR2, field ADH (RW)
 *
 * Address hold time - This bit field determine the address hold time after ADV negation when mum =
 * 1 (muxed mode). When mum = 0 this bit has no effect. For read accesses the field determines when
 * the pads direction will be switched. Reset value for EIM_CS0GCR2 for ADH is 10. For
 * EIM_CS1GCR2-EIM_CS5GCR2 reset value is 00.
 *
 * Values:
 * 00 - 0 cycle after ADV negation
 * 01 - 1 cycle after ADV negation
 * 10 - 2 cycle after ADV negation
 * 11 - Reserved
 */

#define BP_EIM_CSGCR2_ADH      0
#define BM_EIM_CSGCR2_ADH      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR2_ADH)
#else
#define BF_EIM_CSGCR2_ADH(v)   (((v) << 0) & BM_EIM_CSGCR2_ADH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADH field to a new value.
#define BW_EIM_CSGCR2_ADH(v)   BF_CS1(EIM_CSGCR2, ADH, v)
#endif


/* --- Register HW_EIM_CSGCR2, field DAPS (RW)
 *
 * Data Acknowledge Poling Start. This bit field determine the starting point of DTACK input signal
 * polling. DAPS is used only in asynchronous single read or write accesses. Since DTACK is an
 * async. signal the start point of DTACK signal polling is at least 3 cycles after the start of
 * access. DAPS is cleared by a hardware reset. Example settings:
 *
 * Values:
 * 0000 - 3 EIM clk cycle between start of access and first DTACK check
 * 0001 - 4 EIM clk cycles between start of access and first DTACK check
 * 0010 - 5 EIM clk cycles between start of access and first DTACK check
 * 0111 - 10 EIM clk cycles between start of access and first DTACK check
 * 1011 - 14 EIM clk cycles between start of access and first DTACK check
 * 1111 - 18 EIM clk cycles between start of access and first DTACK check
 */

#define BP_EIM_CSGCR2_DAPS      4
#define BM_EIM_CSGCR2_DAPS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR2_DAPS)
#else
#define BF_EIM_CSGCR2_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR2_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAPS field to a new value.
#define BW_EIM_CSGCR2_DAPS(v)   BF_CS1(EIM_CSGCR2, DAPS, v)
#endif


/* --- Register HW_EIM_CSGCR2, field DAE (RW)
 *
 * Data Acknowledge Enable. This bit indicates external device is using DTACK pin as
 * strobe/terminator of an async. access. DTACK signal may be used only in asynchronous single read
 * (APR=0) or write accesses. DTACK poling start point is set by DAPS bit field. polarity of DTACK
 * is set by DAP bit field. DAE is cleared by a hardware reset.
 *
 * Values:
 * 0 - DTACK signal use is disable
 * 1 - DTACK signal use is enable
 */

#define BP_EIM_CSGCR2_DAE      8
#define BM_EIM_CSGCR2_DAE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR2_DAE)
#else
#define BF_EIM_CSGCR2_DAE(v)   (((v) << 8) & BM_EIM_CSGCR2_DAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAE field to a new value.
#define BW_EIM_CSGCR2_DAE(v)   BF_CS1(EIM_CSGCR2, DAE, v)
#endif


/* --- Register HW_EIM_CSGCR2, field DAP (RW)
 *
 * Data Acknowledge Polarity. This bit indicates DTACK memory pin assertion state, active-low or
 * active-high, while executing an async access using DTACK signal from the external device. DAP is
 * cleared by a hardware reset.
 *
 * Values:
 * 0 - DTACK signal is active high
 * 1 - DTACK signal is active low
 */

#define BP_EIM_CSGCR2_DAP      9
#define BM_EIM_CSGCR2_DAP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR2_DAP)
#else
#define BF_EIM_CSGCR2_DAP(v)   (((v) << 9) & BM_EIM_CSGCR2_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAP field to a new value.
#define BW_EIM_CSGCR2_DAP(v)   BF_CS1(EIM_CSGCR2, DAP, v)
#endif


/* --- Register HW_EIM_CSGCR2, field MUX16_BYP_GRANT (RW)
 *
 * Muxed 16 bypass grant. This bit when asserted causes EIM to bypass the grant/ack. arbitration
 * with NFC (only for 16 bit muxed mode accesses). The reset value for EIM_CS0GCR2[MUX16_BYP_GRANT]
 * = EIM_BOOT[12]. For EIM_CS1GCR2 - EIM_CS5GCR2, MUX16_BYP_GRANT reset value is 1.
 *
 * Values:
 * 0 - EIM waits for grant before driving a 16 bit muxed mode access to the memory.
 * 1 - EIM ignores the grant signal and immediately drives a 16 bit muxed mode access to the memory.
 */

#define BP_EIM_CSGCR2_MUX16_BYP_GRANT      12
#define BM_EIM_CSGCR2_MUX16_BYP_GRANT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR2_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR2_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR2_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR2_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUX16_BYP_GRANT field to a new value.
#define BW_EIM_CSGCR2_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR2, MUX16_BYP_GRANT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR1 - Chip Select n Read Configuration Register 1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RCSN : 3; //!< Read CS Negation. This bit field determines when CS signal is negated during read cycles in asynchronous single mode only (SRD=0 & APR = 0), according to the settings shown below. This bit field is ignored when SRD=1. RCSN is cleared by a hardware reset. Example settings:
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RCSA : 3; //!< Read CS Assertion. This bit field determines when CS signal is asserted during read cycles (synchronous or asynchronous mode), according to the settings shown below. RCSA is cleared by a hardware reset. Example settings:
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned OEN : 3; //!< OE Negation. This bit field determines when OE signal is negated during read cycles in asynchronous single mode only (SRD=0 & APR = 0), according to the settings shown below. This bit field is ignored when SRD=1. OEN is cleared by a hardware reset. Example settings:
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned OEA : 3; //!< OE Assertion. This bit field determines when OE signal are asserted during read cycles (synchronous or asynchronous mode), according to the settings shown below. OEA is cleared by a hardware reset. In muxed mode OE assertion occurs (OEA + RADVN + RADVA + ADH +1) EIM clock cycles from start of access. The reset value for EIM_CS0RCR1[OEA] is 0b000 if EIM_BOOT[2] = 0. If EIM_BOOT[2] is 1, the reset value for EIM_CS0RCR1 is 0b010. The reset value of this field for EIM_CS1RCR1 - EIM_CS5RCR1 is 0b000. Example settings:
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RADVN : 3; //!< ADV Negation. This bit field determines when ADV signal to memory is negated during read accesses. When SRD=1 (synchronous read mode), ADV negation occurs according to the following formula: (RADVN + RADVA + BCD + BCS + 1) EIM clock cycles from start of access. When asynchronous read mode is applied (SRD=0) and RAL=0 ADV negation occurs according to the following formula: (RADVN + RADVA + 1) EIM clock cycles from start of access. RADVN is cleared by a hardware reset. the reset value for EIM_CS0RCR1[RADVN] = 2. For EIM_CS1RCR1 - EIM_CS5RCR1, the reset value is 0b000. This field should be configured so ADV negation will occur before the end of access. For ADV negation at the same time with the end of access user should RAL bit.
        unsigned RAL : 1; //!< Read ADV Low. This bit field determine ADV signal negation time. When RAL=1, RADVN bit field is ignored and ADV signal will stay asserted until end of access. When RAL=0 negation of ADV signal is according to RADVN bit field configuration. The reset value of EIM_CS0RCR1[RAL] = EIM_BOOT[3]. RAL is cleared by a hardware reset for EIM_CS1RCR1 - EIM_CS5RCR1.
        unsigned RADVA : 3; //!< ADV Assertion. This bit field determines when ADV signal is asserted for synchronous or asynchronous read modes according to the settings shown below. RADVA is cleared by a hardware reset. Example settings:
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned RWSC : 6; //!< Read Wait State Control. This bit field programs the number of wait-states, according to the settings shown below, for synchronous or asynchronous read access to the external device connected to the chip select. When SRD=1 and RFL=0, RWSC indicates the number of burst clock (BCLK) cycles from the start of an access, before the controller can start sample data.Since WAIT signal can be asserted one cycle before the first data can be sampled, the controller starts evaluating the WAIT signal state one cycle before, this is referred as handshake mode or variable latency mode. When SRD=1 and RFL=1, RWSC indicates the number of burst clock (BCLK) cycles from the start of an access, until the external device is ready for data transfer, this is referred as fix latency mode. When SRD=0, RFL bit is ignored, RWSC indicates the asynchronous access length and the number of EIM clock cycles from the start of access until the external device is ready for data transfer. RWSC is cleared by a hardware reset. The reset value for EIM_CS0RCR1[RWSC[4:2]] = EIM_BOOT [7:5]. For {RWSC[5], RWSC[1:0]} the reset value is 0b000 EIM_CS0RCR1, RWSC[5:0] = 0b011100. For CG1RCR1 - CS1RCR5 the reset value is 0b000000. Example settings:
        unsigned RESERVED5 : 2; //!< Reserved
    } B;
} hw_eim_csrcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR1 register
 */
#define HW_EIM_CSRCR1_ADDR      (REGS_EIM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR1           (*(volatile hw_eim_csrcr1_t *) HW_EIM_CSRCR1_ADDR)
#define HW_EIM_CSRCR1_RD()      (HW_EIM_CSRCR1.U)
#define HW_EIM_CSRCR1_WR(v)     (HW_EIM_CSRCR1.U = (v))
#define HW_EIM_CSRCR1_SET(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() |  (v)))
#define HW_EIM_CSRCR1_CLR(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() & ~(v)))
#define HW_EIM_CSRCR1_TOG(v)    (HW_EIM_CSRCR1_WR(HW_EIM_CSRCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR1 bitfields
 */

/* --- Register HW_EIM_CSRCR1, field RCSN (RW)
 *
 * Read CS Negation. This bit field determines when CS signal is negated during read cycles in
 * asynchronous single mode only (SRD=0 & APR = 0), according to the settings shown below. This bit
 * field is ignored when SRD=1. RCSN is cleared by a hardware reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between end of read access and CS negation
 * 001 - 1 EIM clock cycles between end of read access and CS negation
 * 010 - 2 EIM clock cycles between end of read access and CS negation
 * 111 - 7 EIM clock cycles between end of read access and CS negation
 */

#define BP_EIM_CSRCR1_RCSN      0
#define BM_EIM_CSRCR1_RCSN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR1_RCSN)
#else
#define BF_EIM_CSRCR1_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR1_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSN field to a new value.
#define BW_EIM_CSRCR1_RCSN(v)   BF_CS1(EIM_CSRCR1, RCSN, v)
#endif


/* --- Register HW_EIM_CSRCR1, field RCSA (RW)
 *
 * Read CS Assertion. This bit field determines when CS signal is asserted during read cycles
 * (synchronous or asynchronous mode), according to the settings shown below. RCSA is cleared by a
 * hardware reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of read access and CS assertion
 * 001 - 1 EIM clock cycles between beginning of read access and CS assertion
 * 010 - 2 EIM clock cycles between beginning of read access and CS assertion
 * 111 - 7 EIM clock cycles between beginning of read access and CS assertion
 */

#define BP_EIM_CSRCR1_RCSA      4
#define BM_EIM_CSRCR1_RCSA      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR1_RCSA)
#else
#define BF_EIM_CSRCR1_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR1_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSA field to a new value.
#define BW_EIM_CSRCR1_RCSA(v)   BF_CS1(EIM_CSRCR1, RCSA, v)
#endif


/* --- Register HW_EIM_CSRCR1, field OEN (RW)
 *
 * OE Negation. This bit field determines when OE signal is negated during read cycles in
 * asynchronous single mode only (SRD=0 & APR = 0), according to the settings shown below. This bit
 * field is ignored when SRD=1. OEN is cleared by a hardware reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between end of access and OE negation
 * 001 - 1 EIM clock cycles between end of access and OE negation
 * 010 - 2 EIM clock cycles between end of access and OE negation
 * 111 - 7 EIM clock cycles between end of access and OE negation
 */

#define BP_EIM_CSRCR1_OEN      8
#define BM_EIM_CSRCR1_OEN      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR1_OEN)
#else
#define BF_EIM_CSRCR1_OEN(v)   (((v) << 8) & BM_EIM_CSRCR1_OEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEN field to a new value.
#define BW_EIM_CSRCR1_OEN(v)   BF_CS1(EIM_CSRCR1, OEN, v)
#endif


/* --- Register HW_EIM_CSRCR1, field OEA (RW)
 *
 * OE Assertion. This bit field determines when OE signal are asserted during read cycles
 * (synchronous or asynchronous mode), according to the settings shown below. OEA is cleared by a
 * hardware reset. In muxed mode OE assertion occurs (OEA + RADVN + RADVA + ADH +1) EIM clock cycles
 * from start of access. The reset value for EIM_CS0RCR1[OEA] is 0b000 if EIM_BOOT[2] = 0. If
 * EIM_BOOT[2] is 1, the reset value for EIM_CS0RCR1 is 0b010. The reset value of this field for
 * EIM_CS1RCR1 - EIM_CS5RCR1 is 0b000. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of access and OE assertion
 * 001 - 1 EIM clock cycles between beginning of access and OE assertion
 * 010 - 2 EIM clock cycles between beginning of access and OE assertion
 * 111 - 7 EIM clock cycles between beginning of access and OE assertion
 */

#define BP_EIM_CSRCR1_OEA      12
#define BM_EIM_CSRCR1_OEA      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR1_OEA)
#else
#define BF_EIM_CSRCR1_OEA(v)   (((v) << 12) & BM_EIM_CSRCR1_OEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEA field to a new value.
#define BW_EIM_CSRCR1_OEA(v)   BF_CS1(EIM_CSRCR1, OEA, v)
#endif


/* --- Register HW_EIM_CSRCR1, field RADVN (RW)
 *
 * ADV Negation. This bit field determines when ADV signal to memory is negated during read
 * accesses. When SRD=1 (synchronous read mode), ADV negation occurs according to the following
 * formula: (RADVN + RADVA + BCD + BCS + 1) EIM clock cycles from start of access. When asynchronous
 * read mode is applied (SRD=0) and RAL=0 ADV negation occurs according to the following formula:
 * (RADVN + RADVA + 1) EIM clock cycles from start of access. RADVN is cleared by a hardware reset.
 * the reset value for EIM_CS0RCR1[RADVN] = 2. For EIM_CS1RCR1 - EIM_CS5RCR1, the reset value is
 * 0b000. This field should be configured so ADV negation will occur before the end of access. For
 * ADV negation at the same time with the end of access user should RAL bit.
 */

#define BP_EIM_CSRCR1_RADVN      16
#define BM_EIM_CSRCR1_RADVN      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR1_RADVN)
#else
#define BF_EIM_CSRCR1_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR1_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVN field to a new value.
#define BW_EIM_CSRCR1_RADVN(v)   BF_CS1(EIM_CSRCR1, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RAL (RW)
 *
 * Read ADV Low. This bit field determine ADV signal negation time. When RAL=1, RADVN bit field is
 * ignored and ADV signal will stay asserted until end of access. When RAL=0 negation of ADV signal
 * is according to RADVN bit field configuration. The reset value of EIM_CS0RCR1[RAL] = EIM_BOOT[3].
 * RAL is cleared by a hardware reset for EIM_CS1RCR1 - EIM_CS5RCR1.
 */

#define BP_EIM_CSRCR1_RAL      19
#define BM_EIM_CSRCR1_RAL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR1_RAL)
#else
#define BF_EIM_CSRCR1_RAL(v)   (((v) << 19) & BM_EIM_CSRCR1_RAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RAL field to a new value.
#define BW_EIM_CSRCR1_RAL(v)   BF_CS1(EIM_CSRCR1, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR1, field RADVA (RW)
 *
 * ADV Assertion. This bit field determines when ADV signal is asserted for synchronous or
 * asynchronous read modes according to the settings shown below. RADVA is cleared by a hardware
 * reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of access and ADV assertion
 * 001 - 1 EIM clock cycles between beginning of access and ADV assertion
 * 010 - 2 EIM clock cycles between beginning of access and ADV assertion
 * 111 - 7 EIM clock cycles between beginning of access and ADV assertion
 */

#define BP_EIM_CSRCR1_RADVA      20
#define BM_EIM_CSRCR1_RADVA      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR1_RADVA)
#else
#define BF_EIM_CSRCR1_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR1_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVA field to a new value.
#define BW_EIM_CSRCR1_RADVA(v)   BF_CS1(EIM_CSRCR1, RADVA, v)
#endif


/* --- Register HW_EIM_CSRCR1, field RWSC (RW)
 *
 * Read Wait State Control. This bit field programs the number of wait-states, according to the
 * settings shown below, for synchronous or asynchronous read access to the external device
 * connected to the chip select. When SRD=1 and RFL=0, RWSC indicates the number of burst clock
 * (BCLK) cycles from the start of an access, before the controller can start sample data.Since WAIT
 * signal can be asserted one cycle before the first data can be sampled, the controller starts
 * evaluating the WAIT signal state one cycle before, this is referred as handshake mode or variable
 * latency mode. When SRD=1 and RFL=1, RWSC indicates the number of burst clock (BCLK) cycles from
 * the start of an access, until the external device is ready for data transfer, this is referred as
 * fix latency mode. When SRD=0, RFL bit is ignored, RWSC indicates the asynchronous access length
 * and the number of EIM clock cycles from the start of access until the external device is ready
 * for data transfer. RWSC is cleared by a hardware reset. The reset value for
 * EIM_CS0RCR1[RWSC[4:2]] = EIM_BOOT [7:5]. For {RWSC[5], RWSC[1:0]} the reset value is 0b000
 * EIM_CS0RCR1, RWSC[5:0] = 0b011100. For CG1RCR1 - CS1RCR5 the reset value is 0b000000. Example
 * settings:
 *
 * Values:
 * 000000 - Reserved
 * 000001 - RWSC value is 1
 * 000010 - RWSC value is 2
 * 111101 - RWSC value is 61
 * 111110 - RWSC value is 62
 * 111111 - RWSC value is 63
 */

#define BP_EIM_CSRCR1_RWSC      24
#define BM_EIM_CSRCR1_RWSC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR1_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR1_RWSC)
#else
#define BF_EIM_CSRCR1_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR1_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWSC field to a new value.
#define BW_EIM_CSRCR1_RWSC(v)   BF_CS1(EIM_CSRCR1, RWSC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR2 - Chip Select n Read Configuration Register 2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RBEN : 3; //!< Read BE Negation. This bit field determines when BE signal is negated during read cycles in asynchronous single mode only (SRD=0 & APR=0), according to the settings shown below. This bit field is ignored when SRD=1. RBEN is cleared by a hardware reset. Example settings:
        unsigned RBE : 1; //!< Read BE enable. This bit field determines if BE will be asserted during read access.
        unsigned RBEA : 3; //!< Read BE Assertion. This bit field determines when BE signal is asserted during read cycles (synchronous or asynchronous mode), according to the settings shown below. RBEA is cleared by a hardware reset. Example settings:
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RL : 2; //!< Read Latency. This bit field indicates cycle latency when executing a synchronous read operation. The fields holds the feedback clock loop delay in aclk cycle units. This field is cleared by a hardware reset.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned PAT : 3; //!< Page Access Time. This bit field is used in Asynchronous Page Read mode only (APR=1). the initial access is set by RWSC as in regular asynchronous mode. the consecutive address assertions width determine by PAT field according to the settings shown below. when APR=0 this field is ignored. PAT is cleared by a hardware reset for EIM_CS1GCR1 - EIM_CS5GCR1.
        unsigned APR : 1; //!< Asynchronous Page Read. This bit field determine the asynchronous read mode to the external device. When APR=0, the async. read access is done as single word (where word is defined by the DSZ field). when APR=1, the async. read access executed as page read. page size is according to BL field config., RCSN,RBEN,OEN and RADVN are being ignored. APR is cleared by a hardware reset for EIM_CS1GCR1 - EIM_CS5GCR1. SRD=0 and MUM=0 must apply when APR=1
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_eim_csrcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR2 register
 */
#define HW_EIM_CSRCR2_ADDR      (REGS_EIM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR2           (*(volatile hw_eim_csrcr2_t *) HW_EIM_CSRCR2_ADDR)
#define HW_EIM_CSRCR2_RD()      (HW_EIM_CSRCR2.U)
#define HW_EIM_CSRCR2_WR(v)     (HW_EIM_CSRCR2.U = (v))
#define HW_EIM_CSRCR2_SET(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() |  (v)))
#define HW_EIM_CSRCR2_CLR(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() & ~(v)))
#define HW_EIM_CSRCR2_TOG(v)    (HW_EIM_CSRCR2_WR(HW_EIM_CSRCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR2 bitfields
 */

/* --- Register HW_EIM_CSRCR2, field RBEN (RW)
 *
 * Read BE Negation. This bit field determines when BE signal is negated during read cycles in
 * asynchronous single mode only (SRD=0 & APR=0), according to the settings shown below. This bit
 * field is ignored when SRD=1. RBEN is cleared by a hardware reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between end of read access and BE negation
 * 001 - 1 EIM clock cycles between end of read access and BE negation
 * 010 - 2 EIM clock cycles between end of read access and BE negation
 * 111 - 7 EIM clock cycles between end of read access and BE negation
 */

#define BP_EIM_CSRCR2_RBEN      0
#define BM_EIM_CSRCR2_RBEN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR2_RBEN)
#else
#define BF_EIM_CSRCR2_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR2_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEN field to a new value.
#define BW_EIM_CSRCR2_RBEN(v)   BF_CS1(EIM_CSRCR2, RBEN, v)
#endif


/* --- Register HW_EIM_CSRCR2, field RBE (RW)
 *
 * Read BE enable. This bit field determines if BE will be asserted during read access.
 *
 * Values:
 * 0 - - BE are disabled during read access.
 * 1- - BE are enable during read access according to value of RBEA & RBEN bit fields.
 */

#define BP_EIM_CSRCR2_RBE      3
#define BM_EIM_CSRCR2_RBE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR2_RBE)
#else
#define BF_EIM_CSRCR2_RBE(v)   (((v) << 3) & BM_EIM_CSRCR2_RBE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBE field to a new value.
#define BW_EIM_CSRCR2_RBE(v)   BF_CS1(EIM_CSRCR2, RBE, v)
#endif


/* --- Register HW_EIM_CSRCR2, field RBEA (RW)
 *
 * Read BE Assertion. This bit field determines when BE signal is asserted during read cycles
 * (synchronous or asynchronous mode), according to the settings shown below. RBEA is cleared by a
 * hardware reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of read access and BE assertion
 * 001 - 1 EIM clock cycles between beginning of read access and BE assertion
 * 010 - 2 EIM clock cycles between beginning of read access and BE assertion
 * 111 - 7 EIM clock cycles between beginning of read access and BE assertion
 */

#define BP_EIM_CSRCR2_RBEA      4
#define BM_EIM_CSRCR2_RBEA      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR2_RBEA)
#else
#define BF_EIM_CSRCR2_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR2_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEA field to a new value.
#define BW_EIM_CSRCR2_RBEA(v)   BF_CS1(EIM_CSRCR2, RBEA, v)
#endif


/* --- Register HW_EIM_CSRCR2, field RL (RW)
 *
 * Read Latency. This bit field indicates cycle latency when executing a synchronous read operation.
 * The fields holds the feedback clock loop delay in aclk cycle units. This field is cleared by a
 * hardware reset.
 *
 * Values:
 * 00 - Feedback clock loop delay is up to 1 cycle for BCD = 0 or 1.5 cycles for BCD != 0
 * 01 - Feedback clock loop delay is up to 2 cycles for BCD = 0 or 2.5 cycles for BCD != 0
 * 10 - Feedback clock loop delay is up to 3 cycles for BCD = 0 or 3.5 cycles for BCD != 0
 * 11 - Feedback clock loop delay is up to 4 cycles for BCD = 0 or 4.5 cycles for BCD != 0
 */

#define BP_EIM_CSRCR2_RL      8
#define BM_EIM_CSRCR2_RL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR2_RL)
#else
#define BF_EIM_CSRCR2_RL(v)   (((v) << 8) & BM_EIM_CSRCR2_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_EIM_CSRCR2_RL(v)   BF_CS1(EIM_CSRCR2, RL, v)
#endif


/* --- Register HW_EIM_CSRCR2, field PAT (RW)
 *
 * Page Access Time. This bit field is used in Asynchronous Page Read mode only (APR=1). the initial
 * access is set by RWSC as in regular asynchronous mode. the consecutive address assertions width
 * determine by PAT field according to the settings shown below. when APR=0 this field is ignored.
 * PAT is cleared by a hardware reset for EIM_CS1GCR1 - EIM_CS5GCR1.
 *
 * Values:
 * 000 - Address width is 2 EIM clock cycles
 * 001 - Address width is 3 EIM clock cycles
 * 010 - Address width is 4 EIM clock cycles
 * 011 - Address width is 5 EIM clock cycles
 * 100 - Address width is 6 EIM clock cycles
 * 101 - Address width is 7 EIM clock cycles
 * 110 - Address width is 8 EIM clock cycles
 * 111 - Address width is 9 EIM clock cycles
 */

#define BP_EIM_CSRCR2_PAT      12
#define BM_EIM_CSRCR2_PAT      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR2_PAT)
#else
#define BF_EIM_CSRCR2_PAT(v)   (((v) << 12) & BM_EIM_CSRCR2_PAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT field to a new value.
#define BW_EIM_CSRCR2_PAT(v)   BF_CS1(EIM_CSRCR2, PAT, v)
#endif


/* --- Register HW_EIM_CSRCR2, field APR (RW)
 *
 * Asynchronous Page Read. This bit field determine the asynchronous read mode to the external
 * device. When APR=0, the async. read access is done as single word (where word is defined by the
 * DSZ field). when APR=1, the async. read access executed as page read. page size is according to
 * BL field config., RCSN,RBEN,OEN and RADVN are being ignored. APR is cleared by a hardware reset
 * for EIM_CS1GCR1 - EIM_CS5GCR1. SRD=0 and MUM=0 must apply when APR=1
 */

#define BP_EIM_CSRCR2_APR      15
#define BM_EIM_CSRCR2_APR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR2_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR2_APR)
#else
#define BF_EIM_CSRCR2_APR(v)   (((v) << 15) & BM_EIM_CSRCR2_APR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the APR field to a new value.
#define BW_EIM_CSRCR2_APR(v)   BF_CS1(EIM_CSRCR2, APR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR1 - Chip Select n Write Configuration Register 1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned WCSN : 3; //!< Write CS Negation. This bit field determines when CS signal is negated during write cycles in asynchronous mode only (SWR=0), according to the settings shown below. This bit field is ignored when SWR=1. WCSN is cleared by a hardware reset. Example settings:
        unsigned WCSA : 3; //!< Write CS Assertion. This bit field determines when CS signal is asserted during write cycles (synchronous or asynchronous mode), according to the settings shown below.this bit field is ignored when executing a read access to the external device. WCSA is cleared by a hardware reset. Example settings:
        unsigned WEN : 3; //!< WE Negation. This bit field determines when WE signal is negated during write cycles in asynchronous mode only (SWR=0), according to the settings shown below. This bit field is ignored when SWR=1. WEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WEN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings:
        unsigned WEA : 3; //!< WE Assertion. This bit field determines when WE signal is asserted during write cycles (synchronous or asynchronous mode), according to the settings shown below. This bit field is ignored when executing a read access to the external device. WEA is cleared by a hardware reset. Reset value for EIM_CS0WCR for WEA is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings:
        unsigned WBEN : 3; //!< BE[3:0] Negation. This bit field determines when BE[3:0] bus signal is negated during write cycles in async. mode only (SWR=0), according to the settings shown below. This bit field is ignored when SWR=1. BEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings: 000 0 EIM clock cycles between end of access and WE negation 001 1 EIM clock cycles between end of access and WE negation 010 2 EIM clock cycles between end of access and WE negation 111 7 EIM clock cycles between end of access and WE negation
        unsigned WBEA : 3; //!< BE Assertion. This bit field determines when BE signal is asserted during write cycles in async. mode only (SWR=0), according to the settings shown below. BEA is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEA is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings:
        unsigned WADVN : 3; //!< ADV Negation. This bit field determines when ADV signal to memory is negated during write accesses. When SWR=1 (synchronous write mode), ADV negation occurs according to the following formula: (WADVN + WADVA + BCD + BCS + 1) EIM clock cycles. When asynchronous read mode is applied (SWR=0) ADV negation occurs according to the following formula: (WADVN + WADVA + 1) EIM clock cycles. Reset value for EIM_CS0WCR for WADVN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. This field should be configured so ADV negation will occur before the end of access. For ADV negation at the same time as the end of access, S/W should set the WAL bit.
        unsigned WADVA : 3; //!< ADV Assertion. This bit field determines when ADV signal is asserted for synchronous or asynchronous write modes according to the settings shown below. WADVA is cleared by a hardware reset. Example settings:
        unsigned WWSC : 6; //!< Write Wait State Control. This bit field programs the number of wait-states, according to the settings shown below, for synchronous or asynchronous write access to the external device connected to the chip select. When SWR=1 and WFL=0, WWSC indicates the number of burst clock (BCLK) cycles from the start of an access, before the memory can sample the first data.Since WAIT signal can be asserted one cycle before the first data can be sampled, the controller starts evaluating the WAIT signal state one cycle before, this is referred as handshake mode or variable latency mode. When SWR=1 and WFL=1, WWSC indicates the number of burst clock (BCLK) cycles from the start of an access, until the external device is ready for data transfer, this is referred as fix latency mode. When SWR=0, WFL bit is ignored, WWSC indicates the asynchronous access length and the number of EIM clock cycles from the start of access until the external device is ready for data transfer. WWSC is cleared by a hardware reset. The reset value for EIM_CS0WCR1[WWSC[4:2]] = EIM_BOOT [7:5], {WWSC[5], WWSC[1:0]} = 0b000 EIM_CS0WCR1, WWSC[5:0] = 0b011100. For EIM_CS1WCR1 - EIM_CS5WCR1, the reset value of this field is 0b000000. Example settings:
        unsigned WBED : 1; //!< Write Byte Enable Disable. When asserted this bit prevent from IPP_DO_BE_B[x] to be asserted during write accesses.This bit is cleared by hardware reset.
        unsigned WAL : 1; //!< Write ADV Low. This bit field determine ADV signal negation time in write accesses. When WAL=1, WADVN bit field is ignored and ADV signal will stay asserted until end of access. When WAL=0 negation of ADV signal is according to WADVN bit field configuration. The reset value of CS0WCR1[WAL] = EIM_BOOT[3]. This field is cleared by a hardware reset for CS1WCR1 - CS5WCR1.
    } B;
} hw_eim_cswcr1_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR1 register
 */
#define HW_EIM_CSWCR1_ADDR      (REGS_EIM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR1           (*(volatile hw_eim_cswcr1_t *) HW_EIM_CSWCR1_ADDR)
#define HW_EIM_CSWCR1_RD()      (HW_EIM_CSWCR1.U)
#define HW_EIM_CSWCR1_WR(v)     (HW_EIM_CSWCR1.U = (v))
#define HW_EIM_CSWCR1_SET(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() |  (v)))
#define HW_EIM_CSWCR1_CLR(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() & ~(v)))
#define HW_EIM_CSWCR1_TOG(v)    (HW_EIM_CSWCR1_WR(HW_EIM_CSWCR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR1 bitfields
 */

/* --- Register HW_EIM_CSWCR1, field WCSN (RW)
 *
 * Write CS Negation. This bit field determines when CS signal is negated during write cycles in
 * asynchronous mode only (SWR=0), according to the settings shown below. This bit field is ignored
 * when SWR=1. WCSN is cleared by a hardware reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between end of read access and CS negation
 * 001 - 1 EIM clock cycles between end of read access and CS negation
 * 010 - 2 EIM clock cycles between end of read access and CS negation
 * 111 - 7 EIM clock cycles between end of read access and CS negation
 */

#define BP_EIM_CSWCR1_WCSN      0
#define BM_EIM_CSWCR1_WCSN      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR1_WCSN)
#else
#define BF_EIM_CSWCR1_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR1_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSN field to a new value.
#define BW_EIM_CSWCR1_WCSN(v)   BF_CS1(EIM_CSWCR1, WCSN, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WCSA (RW)
 *
 * Write CS Assertion. This bit field determines when CS signal is asserted during write cycles
 * (synchronous or asynchronous mode), according to the settings shown below.this bit field is
 * ignored when executing a read access to the external device. WCSA is cleared by a hardware reset.
 * Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of write access and CS assertion
 * 001 - 1 EIM clock cycles between beginning of write access and CS assertion
 * 010 - 2 EIM clock cycles between beginning of write access and CS assertion
 * 111 - 7 EIMclock cycles between beginning of write access and CS assertion
 */

#define BP_EIM_CSWCR1_WCSA      3
#define BM_EIM_CSWCR1_WCSA      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR1_WCSA)
#else
#define BF_EIM_CSWCR1_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR1_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSA field to a new value.
#define BW_EIM_CSWCR1_WCSA(v)   BF_CS1(EIM_CSWCR1, WCSA, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WEN (RW)
 *
 * WE Negation. This bit field determines when WE signal is negated during write cycles in
 * asynchronous mode only (SWR=0), according to the settings shown below. This bit field is ignored
 * when SWR=1. WEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WEN is 2. For
 * EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of access and WE assertion
 * 001 - 1 EIM clock cycles between beginning of access and WE assertion
 * 010 - 2 EIM clock cycles between beginning of access and WE assertion
 * 111 - 7 EIM clock cycles between beginning of access and WE assertion
 */

#define BP_EIM_CSWCR1_WEN      6
#define BM_EIM_CSWCR1_WEN      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR1_WEN)
#else
#define BF_EIM_CSWCR1_WEN(v)   (((v) << 6) & BM_EIM_CSWCR1_WEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEN field to a new value.
#define BW_EIM_CSWCR1_WEN(v)   BF_CS1(EIM_CSWCR1, WEN, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WEA (RW)
 *
 * WE Assertion. This bit field determines when WE signal is asserted during write cycles
 * (synchronous or asynchronous mode), according to the settings shown below. This bit field is
 * ignored when executing a read access to the external device. WEA is cleared by a hardware reset.
 * Reset value for EIM_CS0WCR for WEA is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example
 * settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of access and WE assertion
 * 001 - 1 EIM clock cycles between beginning of access and WE assertion
 * 010 - 2 EIM clock cycles between beginning of access and WE assertion
 * 111 - 7 EIMclock cycles between beginning of access and WE assertion
 */

#define BP_EIM_CSWCR1_WEA      9
#define BM_EIM_CSWCR1_WEA      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR1_WEA)
#else
#define BF_EIM_CSWCR1_WEA(v)   (((v) << 9) & BM_EIM_CSWCR1_WEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEA field to a new value.
#define BW_EIM_CSWCR1_WEA(v)   BF_CS1(EIM_CSWCR1, WEA, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WBEN (RW)
 *
 * BE[3:0] Negation. This bit field determines when BE[3:0] bus signal is negated during write
 * cycles in async. mode only (SWR=0), according to the settings shown below. This bit field is
 * ignored when SWR=1. BEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEN is 2.
 * For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings: 000 0 EIM clock cycles between
 * end of access and WE negation 001 1 EIM clock cycles between end of access and WE negation 010 2
 * EIM clock cycles between end of access and WE negation 111 7 EIM clock cycles between end of
 * access and WE negation
 */

#define BP_EIM_CSWCR1_WBEN      12
#define BM_EIM_CSWCR1_WBEN      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR1_WBEN)
#else
#define BF_EIM_CSWCR1_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR1_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEN field to a new value.
#define BW_EIM_CSWCR1_WBEN(v)   BF_CS1(EIM_CSWCR1, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WBEA (RW)
 *
 * BE Assertion. This bit field determines when BE signal is asserted during write cycles in async.
 * mode only (SWR=0), according to the settings shown below. BEA is cleared by a hardware reset.
 * Reset value for EIM_CS0WCR for WBEA is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example
 * settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of access and BE assertion
 * 001 - 1 EIM clock cycles between beginning of access and BE assertion
 * 010 - 2 EIM clock cycles between beginning of access and BE assertion
 * 111 - 7 EIM clock cycles between beginning of access and BE assertion
 */

#define BP_EIM_CSWCR1_WBEA      15
#define BM_EIM_CSWCR1_WBEA      0x00038000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR1_WBEA)
#else
#define BF_EIM_CSWCR1_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR1_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEA field to a new value.
#define BW_EIM_CSWCR1_WBEA(v)   BF_CS1(EIM_CSWCR1, WBEA, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WADVN (RW)
 *
 * ADV Negation. This bit field determines when ADV signal to memory is negated during write
 * accesses. When SWR=1 (synchronous write mode), ADV negation occurs according to the following
 * formula: (WADVN + WADVA + BCD + BCS + 1) EIM clock cycles. When asynchronous read mode is applied
 * (SWR=0) ADV negation occurs according to the following formula: (WADVN + WADVA + 1) EIM clock
 * cycles. Reset value for EIM_CS0WCR for WADVN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is
 * 000. This field should be configured so ADV negation will occur before the end of access. For ADV
 * negation at the same time as the end of access, S/W should set the WAL bit.
 */

#define BP_EIM_CSWCR1_WADVN      18
#define BM_EIM_CSWCR1_WADVN      0x001c0000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR1_WADVN)
#else
#define BF_EIM_CSWCR1_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR1_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVN field to a new value.
#define BW_EIM_CSWCR1_WADVN(v)   BF_CS1(EIM_CSWCR1, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WADVA (RW)
 *
 * ADV Assertion. This bit field determines when ADV signal is asserted for synchronous or
 * asynchronous write modes according to the settings shown below. WADVA is cleared by a hardware
 * reset. Example settings:
 *
 * Values:
 * 000 - 0 EIM clock cycles between beginning of access and ADV assertion
 * 001 - 1 EIM clock cycles between beginning of access and ADV assertion
 * 010 - 2 EIM clock cycles between beginning of access and ADV assertion
 * 111 - 7 EIM clock cycles between beginning of access and ADV assertion
 */

#define BP_EIM_CSWCR1_WADVA      21
#define BM_EIM_CSWCR1_WADVA      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR1_WADVA)
#else
#define BF_EIM_CSWCR1_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR1_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVA field to a new value.
#define BW_EIM_CSWCR1_WADVA(v)   BF_CS1(EIM_CSWCR1, WADVA, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WWSC (RW)
 *
 * Write Wait State Control. This bit field programs the number of wait-states, according to the
 * settings shown below, for synchronous or asynchronous write access to the external device
 * connected to the chip select. When SWR=1 and WFL=0, WWSC indicates the number of burst clock
 * (BCLK) cycles from the start of an access, before the memory can sample the first data.Since WAIT
 * signal can be asserted one cycle before the first data can be sampled, the controller starts
 * evaluating the WAIT signal state one cycle before, this is referred as handshake mode or variable
 * latency mode. When SWR=1 and WFL=1, WWSC indicates the number of burst clock (BCLK) cycles from
 * the start of an access, until the external device is ready for data transfer, this is referred as
 * fix latency mode. When SWR=0, WFL bit is ignored, WWSC indicates the asynchronous access length
 * and the number of EIM clock cycles from the start of access until the external device is ready
 * for data transfer. WWSC is cleared by a hardware reset. The reset value for
 * EIM_CS0WCR1[WWSC[4:2]] = EIM_BOOT [7:5], {WWSC[5], WWSC[1:0]} = 0b000 EIM_CS0WCR1, WWSC[5:0] =
 * 0b011100. For EIM_CS1WCR1 - EIM_CS5WCR1, the reset value of this field is 0b000000. Example
 * settings:
 *
 * Values:
 * 000000 - Reserved
 * 000001 - WWSC value is 1
 * 000010 - WWSC value is 2
 * 000011 - WWSC value is 3
 * 111111 - WWSC value is 63
 */

#define BP_EIM_CSWCR1_WWSC      24
#define BM_EIM_CSWCR1_WWSC      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR1_WWSC)
#else
#define BF_EIM_CSWCR1_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR1_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WWSC field to a new value.
#define BW_EIM_CSWCR1_WWSC(v)   BF_CS1(EIM_CSWCR1, WWSC, v)
#endif


/* --- Register HW_EIM_CSWCR1, field WBED (RW)
 *
 * Write Byte Enable Disable. When asserted this bit prevent from IPP_DO_BE_B[x] to be asserted
 * during write accesses.This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR1_WBED      30
#define BM_EIM_CSWCR1_WBED      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR1_WBED)
#else
#define BF_EIM_CSWCR1_WBED(v)   (((v) << 30) & BM_EIM_CSWCR1_WBED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBED field to a new value.
#define BW_EIM_CSWCR1_WBED(v)   BF_CS1(EIM_CSWCR1, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR1, field WAL (RW)
 *
 * Write ADV Low. This bit field determine ADV signal negation time in write accesses. When WAL=1,
 * WADVN bit field is ignored and ADV signal will stay asserted until end of access. When WAL=0
 * negation of ADV signal is according to WADVN bit field configuration. The reset value of
 * CS0WCR1[WAL] = EIM_BOOT[3]. This field is cleared by a hardware reset for CS1WCR1 - CS5WCR1.
 */

#define BP_EIM_CSWCR1_WAL      31
#define BM_EIM_CSWCR1_WAL      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR1_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR1_WAL)
#else
#define BF_EIM_CSWCR1_WAL(v)   (((v) << 31) & BM_EIM_CSWCR1_WAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAL field to a new value.
#define BW_EIM_CSWCR1_WAL(v)   BF_CS1(EIM_CSWCR1, WAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR2 - Chip Select n Write Configuration Register 2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned WBCDD : 1; //!< Write Burst Clock Divisor Decrement. If this bit is asserted and BCD value is 0 sync. write access will be preformed as if BCD value is 1.When this bit is negated or BCD value is not 0 this bit has no affect. This bit is cleared by hardware reset.
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_eim_cswcr2_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR2 register
 */
#define HW_EIM_CSWCR2_ADDR      (REGS_EIM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR2           (*(volatile hw_eim_cswcr2_t *) HW_EIM_CSWCR2_ADDR)
#define HW_EIM_CSWCR2_RD()      (HW_EIM_CSWCR2.U)
#define HW_EIM_CSWCR2_WR(v)     (HW_EIM_CSWCR2.U = (v))
#define HW_EIM_CSWCR2_SET(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() |  (v)))
#define HW_EIM_CSWCR2_CLR(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() & ~(v)))
#define HW_EIM_CSWCR2_TOG(v)    (HW_EIM_CSWCR2_WR(HW_EIM_CSWCR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR2 bitfields
 */

/* --- Register HW_EIM_CSWCR2, field WBCDD (RW)
 *
 * Write Burst Clock Divisor Decrement. If this bit is asserted and BCD value is 0 sync. write
 * access will be preformed as if BCD value is 1.When this bit is negated or BCD value is not 0 this
 * bit has no affect. This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR2_WBCDD      0
#define BM_EIM_CSWCR2_WBCDD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR2_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR2_WBCDD)
#else
#define BF_EIM_CSWCR2_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR2_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCDD field to a new value.
#define BW_EIM_CSWCR2_WBCDD(v)   BF_CS1(EIM_CSWCR2, WBCDD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_WCR - EIM Configuration Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BCM : 1; //!< Burst Clock Mode. This bit selects the burst clock mode of operation. It is used for system debug mode. BCM is cleared by a hardware reset. The BCLK frequency in this mode is according to GBCD bit field. The BCLK phase is opposite to the EIM clock in this mode if GBCD is 0. This bit should be used only in async. accesses. No sync access can be executed if this bit is set. When this bit is set bcd field shouldn't be configured to 0.
        unsigned GBCD : 2; //!< General Burst Clock Divisor. When BCM bit is set, this bit field contains the value used to program the burst clock divisor for Continuous BCLK generation. The other BCD bit fields for each chip select are ignored. It is used to divide the internal AXI bus frequency. When BCM=0 GBCD bit field has no influence. GBCD is cleared by a hardware reset.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned INTEN : 1; //!< Interrupt Enable. When this bit is set the External signal RDY_INT as active interrupt. When interrupt occurs, INT bit at the WCR will be set and t EIM_EXT_INT signal will be asserted correspondingly. This bit is cleared by a hardware reset.
        unsigned INTPOL : 1; //!< Interrupt Polarity. This bit field determines the polarity of the external device interrupt.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned WDOG_EN : 1; //!< Memory WDog enable. This bit controls the operation of the wdog counter that terminates the EIM access.
        unsigned WDOG_LIMIT : 2; //!< Memory Watch Dog (WDog) cycle limit. This bit field determines the number of BCLK cycles (ACLK cycles in dtack mode) before the wdog counter terminates the access and send an error response to the master.
        unsigned RESERVED2 : 21; //!< Reserved
    } B;
} hw_eim_wcr_t;
#endif

/*
 * constants & macros for entire EIM_WCR register
 */
#define HW_EIM_WCR_ADDR      (REGS_EIM_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_WCR           (*(volatile hw_eim_wcr_t *) HW_EIM_WCR_ADDR)
#define HW_EIM_WCR_RD()      (HW_EIM_WCR.U)
#define HW_EIM_WCR_WR(v)     (HW_EIM_WCR.U = (v))
#define HW_EIM_WCR_SET(v)    (HW_EIM_WCR_WR(HW_EIM_WCR_RD() |  (v)))
#define HW_EIM_WCR_CLR(v)    (HW_EIM_WCR_WR(HW_EIM_WCR_RD() & ~(v)))
#define HW_EIM_WCR_TOG(v)    (HW_EIM_WCR_WR(HW_EIM_WCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_WCR bitfields
 */

/* --- Register HW_EIM_WCR, field BCM (RW)
 *
 * Burst Clock Mode. This bit selects the burst clock mode of operation. It is used for system debug
 * mode. BCM is cleared by a hardware reset. The BCLK frequency in this mode is according to GBCD
 * bit field. The BCLK phase is opposite to the EIM clock in this mode if GBCD is 0. This bit should
 * be used only in async. accesses. No sync access can be executed if this bit is set. When this bit
 * is set bcd field shouldn't be configured to 0.
 *
 * Values:
 * 0 - The burst clock runs only when accessing a chip select range with the SWR/SRD bits set. When the
 *     burst clock is not running it remains in a logic 0 state. When the burst clock is running it
 *     is configured by the BCD and BCS bit fields in the chip select Configuration Register.
 * 1 - The burst clock runs whenever ACLK is active (independent of chip select configuration)
 */

#define BP_EIM_WCR_BCM      0
#define BM_EIM_WCR_BCM      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_BCM(v)   ((((reg32_t) v) << 0) & BM_EIM_WCR_BCM)
#else
#define BF_EIM_WCR_BCM(v)   (((v) << 0) & BM_EIM_WCR_BCM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCM field to a new value.
#define BW_EIM_WCR_BCM(v)   BF_CS1(EIM_WCR, BCM, v)
#endif


/* --- Register HW_EIM_WCR, field GBCD (RW)
 *
 * General Burst Clock Divisor. When BCM bit is set, this bit field contains the value used to
 * program the burst clock divisor for Continuous BCLK generation. The other BCD bit fields for each
 * chip select are ignored. It is used to divide the internal AXI bus frequency. When BCM=0 GBCD bit
 * field has no influence. GBCD is cleared by a hardware reset.
 *
 * Values:
 * 00 - Divide EIM clock by 1
 * 01 - Divide EIM clock by 2
 * 10 - Divide EIM clock by 3
 * 11 - Divide EIM clock by 4
 */

#define BP_EIM_WCR_GBCD      1
#define BM_EIM_WCR_GBCD      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_GBCD(v)   ((((reg32_t) v) << 1) & BM_EIM_WCR_GBCD)
#else
#define BF_EIM_WCR_GBCD(v)   (((v) << 1) & BM_EIM_WCR_GBCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBCD field to a new value.
#define BW_EIM_WCR_GBCD(v)   BF_CS1(EIM_WCR, GBCD, v)
#endif


/* --- Register HW_EIM_WCR, field INTEN (RW)
 *
 * Interrupt Enable. When this bit is set the External signal RDY_INT as active interrupt. When
 * interrupt occurs, INT bit at the WCR will be set and t EIM_EXT_INT signal will be asserted
 * correspondingly. This bit is cleared by a hardware reset.
 *
 * Values:
 * 0 - External interrupt Disable
 * 1 - External interrupt Enable
 */

#define BP_EIM_WCR_INTEN      4
#define BM_EIM_WCR_INTEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTEN(v)   ((((reg32_t) v) << 4) & BM_EIM_WCR_INTEN)
#else
#define BF_EIM_WCR_INTEN(v)   (((v) << 4) & BM_EIM_WCR_INTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTEN field to a new value.
#define BW_EIM_WCR_INTEN(v)   BF_CS1(EIM_WCR, INTEN, v)
#endif


/* --- Register HW_EIM_WCR, field INTPOL (RW)
 *
 * Interrupt Polarity. This bit field determines the polarity of the external device interrupt.
 *
 * Values:
 * 0 - External interrupt polarity is active low
 * 1 - External interrupt polarity is active high
 */

#define BP_EIM_WCR_INTPOL      5
#define BM_EIM_WCR_INTPOL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTPOL(v)   ((((reg32_t) v) << 5) & BM_EIM_WCR_INTPOL)
#else
#define BF_EIM_WCR_INTPOL(v)   (((v) << 5) & BM_EIM_WCR_INTPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTPOL field to a new value.
#define BW_EIM_WCR_INTPOL(v)   BF_CS1(EIM_WCR, INTPOL, v)
#endif


/* --- Register HW_EIM_WCR, field WDOG_EN (RW)
 *
 * Memory WDog enable. This bit controls the operation of the wdog counter that terminates the EIM
 * access.
 *
 * Values:
 * 0 - Memory WDog is Disabled
 * 1 - Memory WDog is Enabled
 */

#define BP_EIM_WCR_WDOG_EN      8
#define BM_EIM_WCR_WDOG_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_EN(v)   ((((reg32_t) v) << 8) & BM_EIM_WCR_WDOG_EN)
#else
#define BF_EIM_WCR_WDOG_EN(v)   (((v) << 8) & BM_EIM_WCR_WDOG_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WDOG_EN field to a new value.
#define BW_EIM_WCR_WDOG_EN(v)   BF_CS1(EIM_WCR, WDOG_EN, v)
#endif


/* --- Register HW_EIM_WCR, field WDOG_LIMIT (RW)
 *
 * Memory Watch Dog (WDog) cycle limit. This bit field determines the number of BCLK cycles (ACLK
 * cycles in dtack mode) before the wdog counter terminates the access and send an error response to
 * the master.
 *
 * Values:
 * 00 - 128 BCLK cycles
 * 01 - 256 BCLK cycles
 * 10 - 512 BCLK cycles
 * 11 - 1024 BCLK cycles
 */

#define BP_EIM_WCR_WDOG_LIMIT      9
#define BM_EIM_WCR_WDOG_LIMIT      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_LIMIT(v)   ((((reg32_t) v) << 9) & BM_EIM_WCR_WDOG_LIMIT)
#else
#define BF_EIM_WCR_WDOG_LIMIT(v)   (((v) << 9) & BM_EIM_WCR_WDOG_LIMIT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WDOG_LIMIT field to a new value.
#define BW_EIM_WCR_WDOG_LIMIT(v)   BF_CS1(EIM_WCR, WDOG_LIMIT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_WIAR - EIM IP Access Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IPS_REQ : 1; //!< IPS request. The Master requests to access one of the IPS registers. During such access the EIM should not perform any AXI/memory accesses. The EIM finishes the AXI accesses that already starts and asserts the IPS_ACK bit.
        unsigned IPS_ACK : 1; //!< IPS ACK. The EIM is ready for ips access. There is no active AXI access and no new AXI access is accepted till this bit is cleared. This bit is cleared by the master after it completes the ips accesses.
        unsigned INT : 1; //!< Interrupt. This bit indicates interrupt assertion by an external device according to RDY_INT signal. When polling this bit, INT=0 indicates interrupt not occurred and INT=1 indicates assertion of the external device interrupt. This bit is cleared by a hardware reset.
        unsigned ERRST : 1; //!< READY After Reset. This bit controls the initial ready/busy status for external devices on CS0 immediately after hardware reset. This is a sticky bit which is cleared once the RDY_INT signal is asserted by the external device. When ERRST = 1 the first fetch access from EIM to the external device located on CS0 will be pending until RDY_INT signal indicates that the external device is ready, then EIM will execute the access. Reset value for ERRST is EIM_BOOT[4].
        unsigned ACLK_EN : 1; //!< ACLK enable. This bit gates the ACLK for the EIM except from FFs that get ipg_aclk_s. After reset ACLK is enabled.
        unsigned RESERVED0 : 27; //!< Reserved
    } B;
} hw_eim_wiar_t;
#endif

/*
 * constants & macros for entire EIM_WIAR register
 */
#define HW_EIM_WIAR_ADDR      (REGS_EIM_BASE + 0x94)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_WIAR           (*(volatile hw_eim_wiar_t *) HW_EIM_WIAR_ADDR)
#define HW_EIM_WIAR_RD()      (HW_EIM_WIAR.U)
#define HW_EIM_WIAR_WR(v)     (HW_EIM_WIAR.U = (v))
#define HW_EIM_WIAR_SET(v)    (HW_EIM_WIAR_WR(HW_EIM_WIAR_RD() |  (v)))
#define HW_EIM_WIAR_CLR(v)    (HW_EIM_WIAR_WR(HW_EIM_WIAR_RD() & ~(v)))
#define HW_EIM_WIAR_TOG(v)    (HW_EIM_WIAR_WR(HW_EIM_WIAR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_WIAR bitfields
 */

/* --- Register HW_EIM_WIAR, field IPS_REQ (RW)
 *
 * IPS request. The Master requests to access one of the IPS registers. During such access the EIM
 * should not perform any AXI/memory accesses. The EIM finishes the AXI accesses that already starts
 * and asserts the IPS_ACK bit.
 *
 * Values:
 * 0 - No Master requests ips access
 * 1 - Master requests ips access
 */

#define BP_EIM_WIAR_IPS_REQ      0
#define BM_EIM_WIAR_IPS_REQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_REQ(v)   ((((reg32_t) v) << 0) & BM_EIM_WIAR_IPS_REQ)
#else
#define BF_EIM_WIAR_IPS_REQ(v)   (((v) << 0) & BM_EIM_WIAR_IPS_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IPS_REQ field to a new value.
#define BW_EIM_WIAR_IPS_REQ(v)   BF_CS1(EIM_WIAR, IPS_REQ, v)
#endif


/* --- Register HW_EIM_WIAR, field IPS_ACK (RW)
 *
 * IPS ACK. The EIM is ready for ips access. There is no active AXI access and no new AXI access is
 * accepted till this bit is cleared. This bit is cleared by the master after it completes the ips
 * accesses.
 *
 * Values:
 * 0 - Master cannot access ips.
 * 1 - Master can access ips.
 */

#define BP_EIM_WIAR_IPS_ACK      1
#define BM_EIM_WIAR_IPS_ACK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_ACK(v)   ((((reg32_t) v) << 1) & BM_EIM_WIAR_IPS_ACK)
#else
#define BF_EIM_WIAR_IPS_ACK(v)   (((v) << 1) & BM_EIM_WIAR_IPS_ACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IPS_ACK field to a new value.
#define BW_EIM_WIAR_IPS_ACK(v)   BF_CS1(EIM_WIAR, IPS_ACK, v)
#endif


/* --- Register HW_EIM_WIAR, field INT (RW)
 *
 * Interrupt. This bit indicates interrupt assertion by an external device according to RDY_INT
 * signal. When polling this bit, INT=0 indicates interrupt not occurred and INT=1 indicates
 * assertion of the external device interrupt. This bit is cleared by a hardware reset.
 */

#define BP_EIM_WIAR_INT      2
#define BM_EIM_WIAR_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_INT(v)   ((((reg32_t) v) << 2) & BM_EIM_WIAR_INT)
#else
#define BF_EIM_WIAR_INT(v)   (((v) << 2) & BM_EIM_WIAR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT field to a new value.
#define BW_EIM_WIAR_INT(v)   BF_CS1(EIM_WIAR, INT, v)
#endif

/* --- Register HW_EIM_WIAR, field ERRST (RW)
 *
 * READY After Reset. This bit controls the initial ready/busy status for external devices on CS0
 * immediately after hardware reset. This is a sticky bit which is cleared once the RDY_INT signal
 * is asserted by the external device. When ERRST = 1 the first fetch access from EIM to the
 * external device located on CS0 will be pending until RDY_INT signal indicates that the external
 * device is ready, then EIM will execute the access. Reset value for ERRST is EIM_BOOT[4].
 *
 * Values:
 * 0 - RDY_INT After Reset Disable
 * 1 - RDY_INT After Reset Enable
 */

#define BP_EIM_WIAR_ERRST      3
#define BM_EIM_WIAR_ERRST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ERRST(v)   ((((reg32_t) v) << 3) & BM_EIM_WIAR_ERRST)
#else
#define BF_EIM_WIAR_ERRST(v)   (((v) << 3) & BM_EIM_WIAR_ERRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERRST field to a new value.
#define BW_EIM_WIAR_ERRST(v)   BF_CS1(EIM_WIAR, ERRST, v)
#endif


/* --- Register HW_EIM_WIAR, field ACLK_EN (RW)
 *
 * ACLK enable. This bit gates the ACLK for the EIM except from FFs that get ipg_aclk_s. After reset
 * ACLK is enabled.
 *
 * Values:
 * 0 - ACLK is disabled
 * 1 - ACLK is enabled
 */

#define BP_EIM_WIAR_ACLK_EN      4
#define BM_EIM_WIAR_ACLK_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ACLK_EN(v)   ((((reg32_t) v) << 4) & BM_EIM_WIAR_ACLK_EN)
#else
#define BF_EIM_WIAR_ACLK_EN(v)   (((v) << 4) & BM_EIM_WIAR_ACLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACLK_EN field to a new value.
#define BW_EIM_WIAR_ACLK_EN(v)   BF_CS1(EIM_WIAR, ACLK_EN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_EAR - Error Address Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ERROR : 32; //!< Error Address. This bit field holds the AXI address of the last access that caused error. This register is read only register.
    } B;
} hw_eim_ear_t;
#endif

/*
 * constants & macros for entire EIM_EAR register
 */
#define HW_EIM_EAR_ADDR      (REGS_EIM_BASE + 0x98)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_EAR           (*(volatile hw_eim_ear_t *) HW_EIM_EAR_ADDR)
#define HW_EIM_EAR_RD()      (HW_EIM_EAR.U)
#define HW_EIM_EAR_WR(v)     (HW_EIM_EAR.U = (v))
#define HW_EIM_EAR_SET(v)    (HW_EIM_EAR_WR(HW_EIM_EAR_RD() |  (v)))
#define HW_EIM_EAR_CLR(v)    (HW_EIM_EAR_WR(HW_EIM_EAR_RD() & ~(v)))
#define HW_EIM_EAR_TOG(v)    (HW_EIM_EAR_WR(HW_EIM_EAR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_EAR bitfields
 */

/* --- Register HW_EIM_EAR, field ERROR (RW)
 *
 * Error Address. This bit field holds the AXI address of the last access that caused error. This
 * register is read only register.
 */

#define BP_EIM_EAR_ERROR      0
#define BM_EIM_EAR_ERROR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EIM_EAR_ERROR(v)   ((((reg32_t) v) << 0) & BM_EIM_EAR_ERROR)
#else
#define BF_EIM_EAR_ERROR(v)   (((v) << 0) & BM_EIM_EAR_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR field to a new value.
#define BW_EIM_EAR_ERROR(v)   BF_CS1(EIM_EAR, ERROR, v)
#endif


/*!
 * @brief All EIM module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_eim_csgcr1_t CSGCR1; //!< Chip Select n General Configuration Register 1
    volatile hw_eim_csgcr2_t CSGCR2; //!< Chip Select n General Configuration Register 2
    volatile hw_eim_csrcr1_t CSRCR1; //!< Chip Select n Read Configuration Register 1
    volatile hw_eim_csrcr2_t CSRCR2; //!< Chip Select n Read Configuration Register 2
    volatile hw_eim_cswcr1_t CSWCR1; //!< Chip Select n Write Configuration Register 1
    volatile hw_eim_cswcr2_t CSWCR2; //!< Chip Select n Write Configuration Register 2
    reg32_t _reserved0[30];
    volatile hw_eim_wcr_t WCR; //!< EIM Configuration Register
    volatile hw_eim_wiar_t WIAR; //!< EIM IP Access Register
    volatile hw_eim_ear_t EAR; //!< Error Address Register
} hw_eim_t
#endif

//! @brief Macro to access all EIM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_EIM(0)</code>.
#define HW_EIM     (*(volatile hw_eim_t *) REGS_EIM_BASE)


#endif // _EIM_H
