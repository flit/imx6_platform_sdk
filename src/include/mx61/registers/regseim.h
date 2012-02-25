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
 * - HW_EIM_CSGCR10 - Chip Select n General Configuration Register 1 0
 * - HW_EIM_CSGCR20 - Chip Select n General Configuration Register 2 0
 * - HW_EIM_CSRCR10 - Chip Select n Read Configuration Register 1 0
 * - HW_EIM_CSRCR20 - Chip Select n Read Configuration Register 2 0
 * - HW_EIM_CSWCR10 - Chip Select n Write Configuration Register 1 0
 * - HW_EIM_CSWCR20 - Chip Select n Write Configuration Register 2 0
 * - HW_EIM_CSGCR11 - Chip Select n General Configuration Register 1 1
 * - HW_EIM_CSGCR21 - Chip Select n General Configuration Register 2 1
 * - HW_EIM_CSRCR11 - Chip Select n Read Configuration Register 1 1
 * - HW_EIM_CSRCR21 - Chip Select n Read Configuration Register 2 1
 * - HW_EIM_CSWCR11 - Chip Select n Write Configuration Register 1 1
 * - HW_EIM_CSWCR21 - Chip Select n Write Configuration Register 2 1
 * - HW_EIM_CSGCR12 - Chip Select n General Configuration Register 1 2
 * - HW_EIM_CSGCR22 - Chip Select n General Configuration Register 2 2
 * - HW_EIM_CSRCR12 - Chip Select n Read Configuration Register 1 2
 * - HW_EIM_CSRCR22 - Chip Select n Read Configuration Register 2 2
 * - HW_EIM_CSWCR12 - Chip Select n Write Configuration Register 1 2
 * - HW_EIM_CSWCR22 - Chip Select n Write Configuration Register 2 2
 * - HW_EIM_CSGCR13 - Chip Select n General Configuration Register 1 3
 * - HW_EIM_CSGCR23 - Chip Select n General Configuration Register 2 3
 * - HW_EIM_CSRCR13 - Chip Select n Read Configuration Register 1 3
 * - HW_EIM_CSRCR23 - Chip Select n Read Configuration Register 2 3
 * - HW_EIM_CSWCR13 - Chip Select n Write Configuration Register 1 3
 * - HW_EIM_CSWCR23 - Chip Select n Write Configuration Register 2 3
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
 * @brief HW_EIM_CSGCR10 - Chip Select n General Configuration Register 1 0 (RW)
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
} hw_eim_csgcr10_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR10 register
 */
#define HW_EIM_CSGCR10_ADDR      (REGS_EIM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR10           (*(volatile hw_eim_csgcr10_t *) HW_EIM_CSGCR10_ADDR)
#define HW_EIM_CSGCR10_RD()      (HW_EIM_CSGCR10.U)
#define HW_EIM_CSGCR10_WR(v)     (HW_EIM_CSGCR10.U = (v))
#define HW_EIM_CSGCR10_SET(v)    (HW_EIM_CSGCR10_WR(HW_EIM_CSGCR10_RD() |  (v)))
#define HW_EIM_CSGCR10_CLR(v)    (HW_EIM_CSGCR10_WR(HW_EIM_CSGCR10_RD() & ~(v)))
#define HW_EIM_CSGCR10_TOG(v)    (HW_EIM_CSGCR10_WR(HW_EIM_CSGCR10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR10 bitfields
 */

/* --- Register HW_EIM_CSGCR10, field CSEN[0:0] (RW)
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

#define BP_EIM_CSGCR10_CSEN      (0)
#define BM_EIM_CSGCR10_CSEN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR10_CSEN)
#else
#define BF_EIM_CSGCR10_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR10_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSEN field to a new value.
#define BW_EIM_CSGCR10_CSEN(v)   BF_CS1(EIM_CSGCR10, CSEN, v)
#endif


/* --- Register HW_EIM_CSGCR10, field SWR[1:1] (RW)
 *
 * Synchronous Write Data. This bit field determine the write accesses mode to the External device
 * of the chip select. The External device should be configured to the same mode as this bit
 * implicates. SWR is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - write accesses are in Asynchronous mode
 * 1 - write accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR10_SWR      (1)
#define BM_EIM_CSGCR10_SWR      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR10_SWR)
#else
#define BF_EIM_CSGCR10_SWR(v)   (((v) << 1) & BM_EIM_CSGCR10_SWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_EIM_CSGCR10_SWR(v)   BF_CS1(EIM_CSGCR10, SWR, v)
#endif


/* --- Register HW_EIM_CSGCR10, field SRD[2:2] (RW)
 *
 * Synchronous Read Data. This bit field determine the read accesses mode to the External device of
 * the chip select. The External device should be configured to the same mode as this bit
 * implicates. SRD is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - read accesses are in Asynchronous mode
 * 1 - read accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR10_SRD      (2)
#define BM_EIM_CSGCR10_SRD      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR10_SRD)
#else
#define BF_EIM_CSGCR10_SRD(v)   (((v) << 2) & BM_EIM_CSGCR10_SRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRD field to a new value.
#define BW_EIM_CSGCR10_SRD(v)   BF_CS1(EIM_CSGCR10, SRD, v)
#endif


/* --- Register HW_EIM_CSGCR10, field MUM[3:3] (RW)
 *
 * Multiplexed Mode. This bit determines the address/data multiplexed mode for asynchronous and
 * synchronous accesses for 8 bit, 16 bit or 32 bit devices (DSZ config. dependent). The reset value
 * for EIM_CS0GCR1[MUM] = EIM_BOOT[2]. For EIM_CS1GCR1 - EIM_CS5GCR1 the reset value is 0.
 *
 * Values:
 * 0 - Multiplexed Mode disable
 * 1 - Multiplexed Mode enable
 */

#define BP_EIM_CSGCR10_MUM      (3)
#define BM_EIM_CSGCR10_MUM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR10_MUM)
#else
#define BF_EIM_CSGCR10_MUM(v)   (((v) << 3) & BM_EIM_CSGCR10_MUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUM field to a new value.
#define BW_EIM_CSGCR10_MUM(v)   BF_CS1(EIM_CSGCR10, MUM, v)
#endif


/* --- Register HW_EIM_CSGCR10, field WFL[4:4] (RW)
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

#define BP_EIM_CSGCR10_WFL      (4)
#define BM_EIM_CSGCR10_WFL      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR10_WFL)
#else
#define BF_EIM_CSGCR10_WFL(v)   (((v) << 4) & BM_EIM_CSGCR10_WFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WFL field to a new value.
#define BW_EIM_CSGCR10_WFL(v)   BF_CS1(EIM_CSGCR10, WFL, v)
#endif


/* --- Register HW_EIM_CSGCR10, field RFL[5:5] (RW)
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

#define BP_EIM_CSGCR10_RFL      (5)
#define BM_EIM_CSGCR10_RFL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR10_RFL)
#else
#define BF_EIM_CSGCR10_RFL(v)   (((v) << 5) & BM_EIM_CSGCR10_RFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFL field to a new value.
#define BW_EIM_CSGCR10_RFL(v)   BF_CS1(EIM_CSGCR10, RFL, v)
#endif


/* --- Register HW_EIM_CSGCR10, field CRE[6:6] (RW)
 *
 * Configuration Register Enable. This bit indicates CRE memory pin state while executing a memory
 * register set command to PSRAM external device. CRE is cleared by a hardware reset.
 *
 * Values:
 * 0 - CRE signal use is disable
 * 1 - CRE signal use is enable
 */

#define BP_EIM_CSGCR10_CRE      (6)
#define BM_EIM_CSGCR10_CRE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR10_CRE)
#else
#define BF_EIM_CSGCR10_CRE(v)   (((v) << 6) & BM_EIM_CSGCR10_CRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRE field to a new value.
#define BW_EIM_CSGCR10_CRE(v)   BF_CS1(EIM_CSGCR10, CRE, v)
#endif


/* --- Register HW_EIM_CSGCR10, field CREP[7:7] (RW)
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

#define BP_EIM_CSGCR10_CREP      (7)
#define BM_EIM_CSGCR10_CREP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR10_CREP)
#else
#define BF_EIM_CSGCR10_CREP(v)   (((v) << 7) & BM_EIM_CSGCR10_CREP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CREP field to a new value.
#define BW_EIM_CSGCR10_CREP(v)   BF_CS1(EIM_CSGCR10, CREP, v)
#endif


/* --- Register HW_EIM_CSGCR10, field BL[10:8] (RW)
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

#define BP_EIM_CSGCR10_BL      (8)
#define BM_EIM_CSGCR10_BL      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR10_BL)
#else
#define BF_EIM_CSGCR10_BL(v)   (((v) << 8) & BM_EIM_CSGCR10_BL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BL field to a new value.
#define BW_EIM_CSGCR10_BL(v)   BF_CS1(EIM_CSGCR10, BL, v)
#endif


/* --- Register HW_EIM_CSGCR10, field WC[11:11] (RW)
 *
 * Write Continuous. The WI bit indicates that write access to the memory are always continuous
 * accesses regardless of the BL field value. WI is cleared by hardware reset.
 *
 * Values:
 * 0 - Write access burst length occurs according to BL value.
 * 1 - Write access burst length is continuous.
 */

#define BP_EIM_CSGCR10_WC      (11)
#define BM_EIM_CSGCR10_WC      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR10_WC)
#else
#define BF_EIM_CSGCR10_WC(v)   (((v) << 11) & BM_EIM_CSGCR10_WC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WC field to a new value.
#define BW_EIM_CSGCR10_WC(v)   BF_CS1(EIM_CSGCR10, WC, v)
#endif


/* --- Register HW_EIM_CSGCR10, field BCD[13:12] (RW)
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

#define BP_EIM_CSGCR10_BCD      (12)
#define BM_EIM_CSGCR10_BCD      (0x00003000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR10_BCD)
#else
#define BF_EIM_CSGCR10_BCD(v)   (((v) << 12) & BM_EIM_CSGCR10_BCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCD field to a new value.
#define BW_EIM_CSGCR10_BCD(v)   BF_CS1(EIM_CSGCR10, BCD, v)
#endif


/* --- Register HW_EIM_CSGCR10, field BCS[15:14] (RW)
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

#define BP_EIM_CSGCR10_BCS      (14)
#define BM_EIM_CSGCR10_BCS      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR10_BCS)
#else
#define BF_EIM_CSGCR10_BCS(v)   (((v) << 14) & BM_EIM_CSGCR10_BCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCS field to a new value.
#define BW_EIM_CSGCR10_BCS(v)   BF_CS1(EIM_CSGCR10, BCS, v)
#endif


/* --- Register HW_EIM_CSGCR10, field DSZ[18:16] (RW)
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

#define BP_EIM_CSGCR10_DSZ      (16)
#define BM_EIM_CSGCR10_DSZ      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR10_DSZ)
#else
#define BF_EIM_CSGCR10_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR10_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSZ field to a new value.
#define BW_EIM_CSGCR10_DSZ(v)   BF_CS1(EIM_CSGCR10, DSZ, v)
#endif


/* --- Register HW_EIM_CSGCR10, field SP[19:19] (RW)
 *
 * Supervisor Protect. This bit prevents accesses to the address range defined by the corresponding
 * chip select when the access is attempted in the User mode. SP is cleared by a hardware reset.
 *
 * Values:
 * 0 - User mode accesses are allowed in the memory range defined by chip select.
 * 1 - User mode accesses are prohibited. All attempts to access an address mapped by this chip select in
 *     User mode results in an error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR10_SP      (19)
#define BM_EIM_CSGCR10_SP      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR10_SP)
#else
#define BF_EIM_CSGCR10_SP(v)   (((v) << 19) & BM_EIM_CSGCR10_SP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SP field to a new value.
#define BW_EIM_CSGCR10_SP(v)   BF_CS1(EIM_CSGCR10, SP, v)
#endif


/* --- Register HW_EIM_CSGCR10, field CSREC[22:20] (RW)
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

#define BP_EIM_CSGCR10_CSREC      (20)
#define BM_EIM_CSGCR10_CSREC      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR10_CSREC)
#else
#define BF_EIM_CSGCR10_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR10_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSREC field to a new value.
#define BW_EIM_CSGCR10_CSREC(v)   BF_CS1(EIM_CSGCR10, CSREC, v)
#endif


/* --- Register HW_EIM_CSGCR10, field AUS[23:23] (RW)
 *
 * Address UnShifted. This bit indicates an unshifted mode for address assertion for the relevant
 * chip select accesses. AUS bit is cleared by hardware reset. The reset value for EIM_CS0GCR1[AUS]
 * = EIM_BOOT[10]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value of AUS is 0.
 *
 * Values:
 * 0 - Address shifted according to port size (DSZ config.)
 * 1 - Address unshifted
 */

#define BP_EIM_CSGCR10_AUS      (23)
#define BM_EIM_CSGCR10_AUS      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR10_AUS)
#else
#define BF_EIM_CSGCR10_AUS(v)   (((v) << 23) & BM_EIM_CSGCR10_AUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUS field to a new value.
#define BW_EIM_CSGCR10_AUS(v)   BF_CS1(EIM_CSGCR10, AUS, v)
#endif


/* --- Register HW_EIM_CSGCR10, field GBC[26:24] (RW)
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

#define BP_EIM_CSGCR10_GBC      (24)
#define BM_EIM_CSGCR10_GBC      (0x07000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR10_GBC)
#else
#define BF_EIM_CSGCR10_GBC(v)   (((v) << 24) & BM_EIM_CSGCR10_GBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBC field to a new value.
#define BW_EIM_CSGCR10_GBC(v)   BF_CS1(EIM_CSGCR10, GBC, v)
#endif


/* --- Register HW_EIM_CSGCR10, field WP[27:27] (RW)
 *
 * Write Protect. This bit prevents writes to the address range defined by the corresponding chip
 * select. WP is cleared by a hardware reset.
 *
 * Values:
 * 0 - Writes are allowed in the memory range defined by chip.
 * 1 - Writes are prohibited. All attempts to write to an address mapped by this chip select result in a
 *     error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR10_WP      (27)
#define BM_EIM_CSGCR10_WP      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR10_WP)
#else
#define BF_EIM_CSGCR10_WP(v)   (((v) << 27) & BM_EIM_CSGCR10_WP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WP field to a new value.
#define BW_EIM_CSGCR10_WP(v)   BF_CS1(EIM_CSGCR10, WP, v)
#endif


/* --- Register HW_EIM_CSGCR10, field PSZ[31:28] (RW)
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

#define BP_EIM_CSGCR10_PSZ      (28)
#define BM_EIM_CSGCR10_PSZ      (0xf0000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR10_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR10_PSZ)
#else
#define BF_EIM_CSGCR10_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR10_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSZ field to a new value.
#define BW_EIM_CSGCR10_PSZ(v)   BF_CS1(EIM_CSGCR10, PSZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR20 - Chip Select n General Configuration Register 2 0 (RW)
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
} hw_eim_csgcr20_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR20 register
 */
#define HW_EIM_CSGCR20_ADDR      (REGS_EIM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR20           (*(volatile hw_eim_csgcr20_t *) HW_EIM_CSGCR20_ADDR)
#define HW_EIM_CSGCR20_RD()      (HW_EIM_CSGCR20.U)
#define HW_EIM_CSGCR20_WR(v)     (HW_EIM_CSGCR20.U = (v))
#define HW_EIM_CSGCR20_SET(v)    (HW_EIM_CSGCR20_WR(HW_EIM_CSGCR20_RD() |  (v)))
#define HW_EIM_CSGCR20_CLR(v)    (HW_EIM_CSGCR20_WR(HW_EIM_CSGCR20_RD() & ~(v)))
#define HW_EIM_CSGCR20_TOG(v)    (HW_EIM_CSGCR20_WR(HW_EIM_CSGCR20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR20 bitfields
 */

/* --- Register HW_EIM_CSGCR20, field ADH[1:0] (RW)
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

#define BP_EIM_CSGCR20_ADH      (0)
#define BM_EIM_CSGCR20_ADH      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR20_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR20_ADH)
#else
#define BF_EIM_CSGCR20_ADH(v)   (((v) << 0) & BM_EIM_CSGCR20_ADH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADH field to a new value.
#define BW_EIM_CSGCR20_ADH(v)   BF_CS1(EIM_CSGCR20, ADH, v)
#endif


/* --- Register HW_EIM_CSGCR20, field DAPS[7:4] (RW)
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

#define BP_EIM_CSGCR20_DAPS      (4)
#define BM_EIM_CSGCR20_DAPS      (0x000000f0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR20_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR20_DAPS)
#else
#define BF_EIM_CSGCR20_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR20_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAPS field to a new value.
#define BW_EIM_CSGCR20_DAPS(v)   BF_CS1(EIM_CSGCR20, DAPS, v)
#endif


/* --- Register HW_EIM_CSGCR20, field DAE[8:8] (RW)
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

#define BP_EIM_CSGCR20_DAE      (8)
#define BM_EIM_CSGCR20_DAE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR20_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR20_DAE)
#else
#define BF_EIM_CSGCR20_DAE(v)   (((v) << 8) & BM_EIM_CSGCR20_DAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAE field to a new value.
#define BW_EIM_CSGCR20_DAE(v)   BF_CS1(EIM_CSGCR20, DAE, v)
#endif


/* --- Register HW_EIM_CSGCR20, field DAP[9:9] (RW)
 *
 * Data Acknowledge Polarity. This bit indicates DTACK memory pin assertion state, active-low or
 * active-high, while executing an async access using DTACK signal from the external device. DAP is
 * cleared by a hardware reset.
 *
 * Values:
 * 0 - DTACK signal is active high
 * 1 - DTACK signal is active low
 */

#define BP_EIM_CSGCR20_DAP      (9)
#define BM_EIM_CSGCR20_DAP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR20_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR20_DAP)
#else
#define BF_EIM_CSGCR20_DAP(v)   (((v) << 9) & BM_EIM_CSGCR20_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAP field to a new value.
#define BW_EIM_CSGCR20_DAP(v)   BF_CS1(EIM_CSGCR20, DAP, v)
#endif


/* --- Register HW_EIM_CSGCR20, field MUX16_BYP_GRANT[12:12] (RW)
 *
 * Muxed 16 bypass grant. This bit when asserted causes EIM to bypass the grant/ack. arbitration
 * with NFC (only for 16 bit muxed mode accesses). The reset value for EIM_CS0GCR2[MUX16_BYP_GRANT]
 * = EIM_BOOT[12]. For EIM_CS1GCR2 - EIM_CS5GCR2, MUX16_BYP_GRANT reset value is 1.
 *
 * Values:
 * 0 - EIM waits for grant before driving a 16 bit muxed mode access to the memory.
 * 1 - EIM ignores the grant signal and immediately drives a 16 bit muxed mode access to the memory.
 */

#define BP_EIM_CSGCR20_MUX16_BYP_GRANT      (12)
#define BM_EIM_CSGCR20_MUX16_BYP_GRANT      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR20_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR20_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR20_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR20_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUX16_BYP_GRANT field to a new value.
#define BW_EIM_CSGCR20_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR20, MUX16_BYP_GRANT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR10 - Chip Select n Read Configuration Register 1 0 (RW)
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
} hw_eim_csrcr10_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR10 register
 */
#define HW_EIM_CSRCR10_ADDR      (REGS_EIM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR10           (*(volatile hw_eim_csrcr10_t *) HW_EIM_CSRCR10_ADDR)
#define HW_EIM_CSRCR10_RD()      (HW_EIM_CSRCR10.U)
#define HW_EIM_CSRCR10_WR(v)     (HW_EIM_CSRCR10.U = (v))
#define HW_EIM_CSRCR10_SET(v)    (HW_EIM_CSRCR10_WR(HW_EIM_CSRCR10_RD() |  (v)))
#define HW_EIM_CSRCR10_CLR(v)    (HW_EIM_CSRCR10_WR(HW_EIM_CSRCR10_RD() & ~(v)))
#define HW_EIM_CSRCR10_TOG(v)    (HW_EIM_CSRCR10_WR(HW_EIM_CSRCR10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR10 bitfields
 */

/* --- Register HW_EIM_CSRCR10, field RCSN[2:0] (RW)
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

#define BP_EIM_CSRCR10_RCSN      (0)
#define BM_EIM_CSRCR10_RCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR10_RCSN)
#else
#define BF_EIM_CSRCR10_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR10_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSN field to a new value.
#define BW_EIM_CSRCR10_RCSN(v)   BF_CS1(EIM_CSRCR10, RCSN, v)
#endif


/* --- Register HW_EIM_CSRCR10, field RCSA[6:4] (RW)
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

#define BP_EIM_CSRCR10_RCSA      (4)
#define BM_EIM_CSRCR10_RCSA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR10_RCSA)
#else
#define BF_EIM_CSRCR10_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR10_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSA field to a new value.
#define BW_EIM_CSRCR10_RCSA(v)   BF_CS1(EIM_CSRCR10, RCSA, v)
#endif


/* --- Register HW_EIM_CSRCR10, field OEN[10:8] (RW)
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

#define BP_EIM_CSRCR10_OEN      (8)
#define BM_EIM_CSRCR10_OEN      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR10_OEN)
#else
#define BF_EIM_CSRCR10_OEN(v)   (((v) << 8) & BM_EIM_CSRCR10_OEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEN field to a new value.
#define BW_EIM_CSRCR10_OEN(v)   BF_CS1(EIM_CSRCR10, OEN, v)
#endif


/* --- Register HW_EIM_CSRCR10, field OEA[14:12] (RW)
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

#define BP_EIM_CSRCR10_OEA      (12)
#define BM_EIM_CSRCR10_OEA      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR10_OEA)
#else
#define BF_EIM_CSRCR10_OEA(v)   (((v) << 12) & BM_EIM_CSRCR10_OEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEA field to a new value.
#define BW_EIM_CSRCR10_OEA(v)   BF_CS1(EIM_CSRCR10, OEA, v)
#endif


/* --- Register HW_EIM_CSRCR10, field RADVN[18:16] (RW)
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

#define BP_EIM_CSRCR10_RADVN      (16)
#define BM_EIM_CSRCR10_RADVN      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR10_RADVN)
#else
#define BF_EIM_CSRCR10_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR10_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVN field to a new value.
#define BW_EIM_CSRCR10_RADVN(v)   BF_CS1(EIM_CSRCR10, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR10, field RAL[19:19] (RW)
 *
 * Read ADV Low. This bit field determine ADV signal negation time. When RAL=1, RADVN bit field is
 * ignored and ADV signal will stay asserted until end of access. When RAL=0 negation of ADV signal
 * is according to RADVN bit field configuration. The reset value of EIM_CS0RCR1[RAL] = EIM_BOOT[3].
 * RAL is cleared by a hardware reset for EIM_CS1RCR1 - EIM_CS5RCR1.
 */

#define BP_EIM_CSRCR10_RAL      (19)
#define BM_EIM_CSRCR10_RAL      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR10_RAL)
#else
#define BF_EIM_CSRCR10_RAL(v)   (((v) << 19) & BM_EIM_CSRCR10_RAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RAL field to a new value.
#define BW_EIM_CSRCR10_RAL(v)   BF_CS1(EIM_CSRCR10, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR10, field RADVA[22:20] (RW)
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

#define BP_EIM_CSRCR10_RADVA      (20)
#define BM_EIM_CSRCR10_RADVA      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR10_RADVA)
#else
#define BF_EIM_CSRCR10_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR10_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVA field to a new value.
#define BW_EIM_CSRCR10_RADVA(v)   BF_CS1(EIM_CSRCR10, RADVA, v)
#endif


/* --- Register HW_EIM_CSRCR10, field RWSC[29:24] (RW)
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

#define BP_EIM_CSRCR10_RWSC      (24)
#define BM_EIM_CSRCR10_RWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR10_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR10_RWSC)
#else
#define BF_EIM_CSRCR10_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR10_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWSC field to a new value.
#define BW_EIM_CSRCR10_RWSC(v)   BF_CS1(EIM_CSRCR10, RWSC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR20 - Chip Select n Read Configuration Register 2 0 (RW)
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
} hw_eim_csrcr20_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR20 register
 */
#define HW_EIM_CSRCR20_ADDR      (REGS_EIM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR20           (*(volatile hw_eim_csrcr20_t *) HW_EIM_CSRCR20_ADDR)
#define HW_EIM_CSRCR20_RD()      (HW_EIM_CSRCR20.U)
#define HW_EIM_CSRCR20_WR(v)     (HW_EIM_CSRCR20.U = (v))
#define HW_EIM_CSRCR20_SET(v)    (HW_EIM_CSRCR20_WR(HW_EIM_CSRCR20_RD() |  (v)))
#define HW_EIM_CSRCR20_CLR(v)    (HW_EIM_CSRCR20_WR(HW_EIM_CSRCR20_RD() & ~(v)))
#define HW_EIM_CSRCR20_TOG(v)    (HW_EIM_CSRCR20_WR(HW_EIM_CSRCR20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR20 bitfields
 */

/* --- Register HW_EIM_CSRCR20, field RBEN[2:0] (RW)
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

#define BP_EIM_CSRCR20_RBEN      (0)
#define BM_EIM_CSRCR20_RBEN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR20_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR20_RBEN)
#else
#define BF_EIM_CSRCR20_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR20_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEN field to a new value.
#define BW_EIM_CSRCR20_RBEN(v)   BF_CS1(EIM_CSRCR20, RBEN, v)
#endif


/* --- Register HW_EIM_CSRCR20, field RBE[3:3] (RW)
 *
 * Read BE enable. This bit field determines if BE will be asserted during read access.
 *
 * Values:
 * 0 - - BE are disabled during read access.
 * 1- - BE are enable during read access according to value of RBEA & RBEN bit fields.
 */

#define BP_EIM_CSRCR20_RBE      (3)
#define BM_EIM_CSRCR20_RBE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR20_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR20_RBE)
#else
#define BF_EIM_CSRCR20_RBE(v)   (((v) << 3) & BM_EIM_CSRCR20_RBE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBE field to a new value.
#define BW_EIM_CSRCR20_RBE(v)   BF_CS1(EIM_CSRCR20, RBE, v)
#endif


/* --- Register HW_EIM_CSRCR20, field RBEA[6:4] (RW)
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

#define BP_EIM_CSRCR20_RBEA      (4)
#define BM_EIM_CSRCR20_RBEA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR20_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR20_RBEA)
#else
#define BF_EIM_CSRCR20_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR20_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEA field to a new value.
#define BW_EIM_CSRCR20_RBEA(v)   BF_CS1(EIM_CSRCR20, RBEA, v)
#endif


/* --- Register HW_EIM_CSRCR20, field RL[9:8] (RW)
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

#define BP_EIM_CSRCR20_RL      (8)
#define BM_EIM_CSRCR20_RL      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR20_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR20_RL)
#else
#define BF_EIM_CSRCR20_RL(v)   (((v) << 8) & BM_EIM_CSRCR20_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_EIM_CSRCR20_RL(v)   BF_CS1(EIM_CSRCR20, RL, v)
#endif


/* --- Register HW_EIM_CSRCR20, field PAT[14:12] (RW)
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

#define BP_EIM_CSRCR20_PAT      (12)
#define BM_EIM_CSRCR20_PAT      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR20_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR20_PAT)
#else
#define BF_EIM_CSRCR20_PAT(v)   (((v) << 12) & BM_EIM_CSRCR20_PAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT field to a new value.
#define BW_EIM_CSRCR20_PAT(v)   BF_CS1(EIM_CSRCR20, PAT, v)
#endif


/* --- Register HW_EIM_CSRCR20, field APR[15:15] (RW)
 *
 * Asynchronous Page Read. This bit field determine the asynchronous read mode to the external
 * device. When APR=0, the async. read access is done as single word (where word is defined by the
 * DSZ field). when APR=1, the async. read access executed as page read. page size is according to
 * BL field config., RCSN,RBEN,OEN and RADVN are being ignored. APR is cleared by a hardware reset
 * for EIM_CS1GCR1 - EIM_CS5GCR1. SRD=0 and MUM=0 must apply when APR=1
 */

#define BP_EIM_CSRCR20_APR      (15)
#define BM_EIM_CSRCR20_APR      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR20_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR20_APR)
#else
#define BF_EIM_CSRCR20_APR(v)   (((v) << 15) & BM_EIM_CSRCR20_APR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the APR field to a new value.
#define BW_EIM_CSRCR20_APR(v)   BF_CS1(EIM_CSRCR20, APR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR10 - Chip Select n Write Configuration Register 1 0 (RW)
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
} hw_eim_cswcr10_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR10 register
 */
#define HW_EIM_CSWCR10_ADDR      (REGS_EIM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR10           (*(volatile hw_eim_cswcr10_t *) HW_EIM_CSWCR10_ADDR)
#define HW_EIM_CSWCR10_RD()      (HW_EIM_CSWCR10.U)
#define HW_EIM_CSWCR10_WR(v)     (HW_EIM_CSWCR10.U = (v))
#define HW_EIM_CSWCR10_SET(v)    (HW_EIM_CSWCR10_WR(HW_EIM_CSWCR10_RD() |  (v)))
#define HW_EIM_CSWCR10_CLR(v)    (HW_EIM_CSWCR10_WR(HW_EIM_CSWCR10_RD() & ~(v)))
#define HW_EIM_CSWCR10_TOG(v)    (HW_EIM_CSWCR10_WR(HW_EIM_CSWCR10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR10 bitfields
 */

/* --- Register HW_EIM_CSWCR10, field WCSN[2:0] (RW)
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

#define BP_EIM_CSWCR10_WCSN      (0)
#define BM_EIM_CSWCR10_WCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR10_WCSN)
#else
#define BF_EIM_CSWCR10_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR10_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSN field to a new value.
#define BW_EIM_CSWCR10_WCSN(v)   BF_CS1(EIM_CSWCR10, WCSN, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WCSA[5:3] (RW)
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

#define BP_EIM_CSWCR10_WCSA      (3)
#define BM_EIM_CSWCR10_WCSA      (0x00000038)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR10_WCSA)
#else
#define BF_EIM_CSWCR10_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR10_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSA field to a new value.
#define BW_EIM_CSWCR10_WCSA(v)   BF_CS1(EIM_CSWCR10, WCSA, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WEN[8:6] (RW)
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

#define BP_EIM_CSWCR10_WEN      (6)
#define BM_EIM_CSWCR10_WEN      (0x000001c0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR10_WEN)
#else
#define BF_EIM_CSWCR10_WEN(v)   (((v) << 6) & BM_EIM_CSWCR10_WEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEN field to a new value.
#define BW_EIM_CSWCR10_WEN(v)   BF_CS1(EIM_CSWCR10, WEN, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WEA[11:9] (RW)
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

#define BP_EIM_CSWCR10_WEA      (9)
#define BM_EIM_CSWCR10_WEA      (0x00000e00)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR10_WEA)
#else
#define BF_EIM_CSWCR10_WEA(v)   (((v) << 9) & BM_EIM_CSWCR10_WEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEA field to a new value.
#define BW_EIM_CSWCR10_WEA(v)   BF_CS1(EIM_CSWCR10, WEA, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WBEN[14:12] (RW)
 *
 * BE[3:0] Negation. This bit field determines when BE[3:0] bus signal is negated during write
 * cycles in async. mode only (SWR=0), according to the settings shown below. This bit field is
 * ignored when SWR=1. BEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEN is 2.
 * For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings: 000 0 EIM clock cycles between
 * end of access and WE negation 001 1 EIM clock cycles between end of access and WE negation 010 2
 * EIM clock cycles between end of access and WE negation 111 7 EIM clock cycles between end of
 * access and WE negation
 */

#define BP_EIM_CSWCR10_WBEN      (12)
#define BM_EIM_CSWCR10_WBEN      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR10_WBEN)
#else
#define BF_EIM_CSWCR10_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR10_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEN field to a new value.
#define BW_EIM_CSWCR10_WBEN(v)   BF_CS1(EIM_CSWCR10, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR10, field WBEA[17:15] (RW)
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

#define BP_EIM_CSWCR10_WBEA      (15)
#define BM_EIM_CSWCR10_WBEA      (0x00038000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR10_WBEA)
#else
#define BF_EIM_CSWCR10_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR10_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEA field to a new value.
#define BW_EIM_CSWCR10_WBEA(v)   BF_CS1(EIM_CSWCR10, WBEA, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WADVN[20:18] (RW)
 *
 * ADV Negation. This bit field determines when ADV signal to memory is negated during write
 * accesses. When SWR=1 (synchronous write mode), ADV negation occurs according to the following
 * formula: (WADVN + WADVA + BCD + BCS + 1) EIM clock cycles. When asynchronous read mode is applied
 * (SWR=0) ADV negation occurs according to the following formula: (WADVN + WADVA + 1) EIM clock
 * cycles. Reset value for EIM_CS0WCR for WADVN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is
 * 000. This field should be configured so ADV negation will occur before the end of access. For ADV
 * negation at the same time as the end of access, S/W should set the WAL bit.
 */

#define BP_EIM_CSWCR10_WADVN      (18)
#define BM_EIM_CSWCR10_WADVN      (0x001c0000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR10_WADVN)
#else
#define BF_EIM_CSWCR10_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR10_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVN field to a new value.
#define BW_EIM_CSWCR10_WADVN(v)   BF_CS1(EIM_CSWCR10, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR10, field WADVA[23:21] (RW)
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

#define BP_EIM_CSWCR10_WADVA      (21)
#define BM_EIM_CSWCR10_WADVA      (0x00e00000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR10_WADVA)
#else
#define BF_EIM_CSWCR10_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR10_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVA field to a new value.
#define BW_EIM_CSWCR10_WADVA(v)   BF_CS1(EIM_CSWCR10, WADVA, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WWSC[29:24] (RW)
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

#define BP_EIM_CSWCR10_WWSC      (24)
#define BM_EIM_CSWCR10_WWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR10_WWSC)
#else
#define BF_EIM_CSWCR10_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR10_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WWSC field to a new value.
#define BW_EIM_CSWCR10_WWSC(v)   BF_CS1(EIM_CSWCR10, WWSC, v)
#endif


/* --- Register HW_EIM_CSWCR10, field WBED[30:30] (RW)
 *
 * Write Byte Enable Disable. When asserted this bit prevent from IPP_DO_BE_B[x] to be asserted
 * during write accesses.This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR10_WBED      (30)
#define BM_EIM_CSWCR10_WBED      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR10_WBED)
#else
#define BF_EIM_CSWCR10_WBED(v)   (((v) << 30) & BM_EIM_CSWCR10_WBED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBED field to a new value.
#define BW_EIM_CSWCR10_WBED(v)   BF_CS1(EIM_CSWCR10, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR10, field WAL[31:31] (RW)
 *
 * Write ADV Low. This bit field determine ADV signal negation time in write accesses. When WAL=1,
 * WADVN bit field is ignored and ADV signal will stay asserted until end of access. When WAL=0
 * negation of ADV signal is according to WADVN bit field configuration. The reset value of
 * CS0WCR1[WAL] = EIM_BOOT[3]. This field is cleared by a hardware reset for CS1WCR1 - CS5WCR1.
 */

#define BP_EIM_CSWCR10_WAL      (31)
#define BM_EIM_CSWCR10_WAL      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR10_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR10_WAL)
#else
#define BF_EIM_CSWCR10_WAL(v)   (((v) << 31) & BM_EIM_CSWCR10_WAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAL field to a new value.
#define BW_EIM_CSWCR10_WAL(v)   BF_CS1(EIM_CSWCR10, WAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR20 - Chip Select n Write Configuration Register 2 0 (RW)
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
} hw_eim_cswcr20_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR20 register
 */
#define HW_EIM_CSWCR20_ADDR      (REGS_EIM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR20           (*(volatile hw_eim_cswcr20_t *) HW_EIM_CSWCR20_ADDR)
#define HW_EIM_CSWCR20_RD()      (HW_EIM_CSWCR20.U)
#define HW_EIM_CSWCR20_WR(v)     (HW_EIM_CSWCR20.U = (v))
#define HW_EIM_CSWCR20_SET(v)    (HW_EIM_CSWCR20_WR(HW_EIM_CSWCR20_RD() |  (v)))
#define HW_EIM_CSWCR20_CLR(v)    (HW_EIM_CSWCR20_WR(HW_EIM_CSWCR20_RD() & ~(v)))
#define HW_EIM_CSWCR20_TOG(v)    (HW_EIM_CSWCR20_WR(HW_EIM_CSWCR20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR20 bitfields
 */

/* --- Register HW_EIM_CSWCR20, field WBCDD[0:0] (RW)
 *
 * Write Burst Clock Divisor Decrement. If this bit is asserted and BCD value is 0 sync. write
 * access will be preformed as if BCD value is 1.When this bit is negated or BCD value is not 0 this
 * bit has no affect. This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR20_WBCDD      (0)
#define BM_EIM_CSWCR20_WBCDD      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR20_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR20_WBCDD)
#else
#define BF_EIM_CSWCR20_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR20_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCDD field to a new value.
#define BW_EIM_CSWCR20_WBCDD(v)   BF_CS1(EIM_CSWCR20, WBCDD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR11 - Chip Select n General Configuration Register 1 1 (RW)
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
} hw_eim_csgcr11_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR11 register
 */
#define HW_EIM_CSGCR11_ADDR      (REGS_EIM_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR11           (*(volatile hw_eim_csgcr11_t *) HW_EIM_CSGCR11_ADDR)
#define HW_EIM_CSGCR11_RD()      (HW_EIM_CSGCR11.U)
#define HW_EIM_CSGCR11_WR(v)     (HW_EIM_CSGCR11.U = (v))
#define HW_EIM_CSGCR11_SET(v)    (HW_EIM_CSGCR11_WR(HW_EIM_CSGCR11_RD() |  (v)))
#define HW_EIM_CSGCR11_CLR(v)    (HW_EIM_CSGCR11_WR(HW_EIM_CSGCR11_RD() & ~(v)))
#define HW_EIM_CSGCR11_TOG(v)    (HW_EIM_CSGCR11_WR(HW_EIM_CSGCR11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR11 bitfields
 */

/* --- Register HW_EIM_CSGCR11, field CSEN[0:0] (RW)
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

#define BP_EIM_CSGCR11_CSEN      (0)
#define BM_EIM_CSGCR11_CSEN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR11_CSEN)
#else
#define BF_EIM_CSGCR11_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR11_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSEN field to a new value.
#define BW_EIM_CSGCR11_CSEN(v)   BF_CS1(EIM_CSGCR11, CSEN, v)
#endif


/* --- Register HW_EIM_CSGCR11, field SWR[1:1] (RW)
 *
 * Synchronous Write Data. This bit field determine the write accesses mode to the External device
 * of the chip select. The External device should be configured to the same mode as this bit
 * implicates. SWR is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - write accesses are in Asynchronous mode
 * 1 - write accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR11_SWR      (1)
#define BM_EIM_CSGCR11_SWR      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR11_SWR)
#else
#define BF_EIM_CSGCR11_SWR(v)   (((v) << 1) & BM_EIM_CSGCR11_SWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_EIM_CSGCR11_SWR(v)   BF_CS1(EIM_CSGCR11, SWR, v)
#endif


/* --- Register HW_EIM_CSGCR11, field SRD[2:2] (RW)
 *
 * Synchronous Read Data. This bit field determine the read accesses mode to the External device of
 * the chip select. The External device should be configured to the same mode as this bit
 * implicates. SRD is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - read accesses are in Asynchronous mode
 * 1 - read accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR11_SRD      (2)
#define BM_EIM_CSGCR11_SRD      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR11_SRD)
#else
#define BF_EIM_CSGCR11_SRD(v)   (((v) << 2) & BM_EIM_CSGCR11_SRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRD field to a new value.
#define BW_EIM_CSGCR11_SRD(v)   BF_CS1(EIM_CSGCR11, SRD, v)
#endif


/* --- Register HW_EIM_CSGCR11, field MUM[3:3] (RW)
 *
 * Multiplexed Mode. This bit determines the address/data multiplexed mode for asynchronous and
 * synchronous accesses for 8 bit, 16 bit or 32 bit devices (DSZ config. dependent). The reset value
 * for EIM_CS0GCR1[MUM] = EIM_BOOT[2]. For EIM_CS1GCR1 - EIM_CS5GCR1 the reset value is 0.
 *
 * Values:
 * 0 - Multiplexed Mode disable
 * 1 - Multiplexed Mode enable
 */

#define BP_EIM_CSGCR11_MUM      (3)
#define BM_EIM_CSGCR11_MUM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR11_MUM)
#else
#define BF_EIM_CSGCR11_MUM(v)   (((v) << 3) & BM_EIM_CSGCR11_MUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUM field to a new value.
#define BW_EIM_CSGCR11_MUM(v)   BF_CS1(EIM_CSGCR11, MUM, v)
#endif


/* --- Register HW_EIM_CSGCR11, field WFL[4:4] (RW)
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

#define BP_EIM_CSGCR11_WFL      (4)
#define BM_EIM_CSGCR11_WFL      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR11_WFL)
#else
#define BF_EIM_CSGCR11_WFL(v)   (((v) << 4) & BM_EIM_CSGCR11_WFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WFL field to a new value.
#define BW_EIM_CSGCR11_WFL(v)   BF_CS1(EIM_CSGCR11, WFL, v)
#endif


/* --- Register HW_EIM_CSGCR11, field RFL[5:5] (RW)
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

#define BP_EIM_CSGCR11_RFL      (5)
#define BM_EIM_CSGCR11_RFL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR11_RFL)
#else
#define BF_EIM_CSGCR11_RFL(v)   (((v) << 5) & BM_EIM_CSGCR11_RFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFL field to a new value.
#define BW_EIM_CSGCR11_RFL(v)   BF_CS1(EIM_CSGCR11, RFL, v)
#endif


/* --- Register HW_EIM_CSGCR11, field CRE[6:6] (RW)
 *
 * Configuration Register Enable. This bit indicates CRE memory pin state while executing a memory
 * register set command to PSRAM external device. CRE is cleared by a hardware reset.
 *
 * Values:
 * 0 - CRE signal use is disable
 * 1 - CRE signal use is enable
 */

#define BP_EIM_CSGCR11_CRE      (6)
#define BM_EIM_CSGCR11_CRE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR11_CRE)
#else
#define BF_EIM_CSGCR11_CRE(v)   (((v) << 6) & BM_EIM_CSGCR11_CRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRE field to a new value.
#define BW_EIM_CSGCR11_CRE(v)   BF_CS1(EIM_CSGCR11, CRE, v)
#endif


/* --- Register HW_EIM_CSGCR11, field CREP[7:7] (RW)
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

#define BP_EIM_CSGCR11_CREP      (7)
#define BM_EIM_CSGCR11_CREP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR11_CREP)
#else
#define BF_EIM_CSGCR11_CREP(v)   (((v) << 7) & BM_EIM_CSGCR11_CREP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CREP field to a new value.
#define BW_EIM_CSGCR11_CREP(v)   BF_CS1(EIM_CSGCR11, CREP, v)
#endif


/* --- Register HW_EIM_CSGCR11, field BL[10:8] (RW)
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

#define BP_EIM_CSGCR11_BL      (8)
#define BM_EIM_CSGCR11_BL      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR11_BL)
#else
#define BF_EIM_CSGCR11_BL(v)   (((v) << 8) & BM_EIM_CSGCR11_BL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BL field to a new value.
#define BW_EIM_CSGCR11_BL(v)   BF_CS1(EIM_CSGCR11, BL, v)
#endif


/* --- Register HW_EIM_CSGCR11, field WC[11:11] (RW)
 *
 * Write Continuous. The WI bit indicates that write access to the memory are always continuous
 * accesses regardless of the BL field value. WI is cleared by hardware reset.
 *
 * Values:
 * 0 - Write access burst length occurs according to BL value.
 * 1 - Write access burst length is continuous.
 */

#define BP_EIM_CSGCR11_WC      (11)
#define BM_EIM_CSGCR11_WC      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR11_WC)
#else
#define BF_EIM_CSGCR11_WC(v)   (((v) << 11) & BM_EIM_CSGCR11_WC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WC field to a new value.
#define BW_EIM_CSGCR11_WC(v)   BF_CS1(EIM_CSGCR11, WC, v)
#endif


/* --- Register HW_EIM_CSGCR11, field BCD[13:12] (RW)
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

#define BP_EIM_CSGCR11_BCD      (12)
#define BM_EIM_CSGCR11_BCD      (0x00003000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR11_BCD)
#else
#define BF_EIM_CSGCR11_BCD(v)   (((v) << 12) & BM_EIM_CSGCR11_BCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCD field to a new value.
#define BW_EIM_CSGCR11_BCD(v)   BF_CS1(EIM_CSGCR11, BCD, v)
#endif


/* --- Register HW_EIM_CSGCR11, field BCS[15:14] (RW)
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

#define BP_EIM_CSGCR11_BCS      (14)
#define BM_EIM_CSGCR11_BCS      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR11_BCS)
#else
#define BF_EIM_CSGCR11_BCS(v)   (((v) << 14) & BM_EIM_CSGCR11_BCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCS field to a new value.
#define BW_EIM_CSGCR11_BCS(v)   BF_CS1(EIM_CSGCR11, BCS, v)
#endif


/* --- Register HW_EIM_CSGCR11, field DSZ[18:16] (RW)
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

#define BP_EIM_CSGCR11_DSZ      (16)
#define BM_EIM_CSGCR11_DSZ      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR11_DSZ)
#else
#define BF_EIM_CSGCR11_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR11_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSZ field to a new value.
#define BW_EIM_CSGCR11_DSZ(v)   BF_CS1(EIM_CSGCR11, DSZ, v)
#endif


/* --- Register HW_EIM_CSGCR11, field SP[19:19] (RW)
 *
 * Supervisor Protect. This bit prevents accesses to the address range defined by the corresponding
 * chip select when the access is attempted in the User mode. SP is cleared by a hardware reset.
 *
 * Values:
 * 0 - User mode accesses are allowed in the memory range defined by chip select.
 * 1 - User mode accesses are prohibited. All attempts to access an address mapped by this chip select in
 *     User mode results in an error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR11_SP      (19)
#define BM_EIM_CSGCR11_SP      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR11_SP)
#else
#define BF_EIM_CSGCR11_SP(v)   (((v) << 19) & BM_EIM_CSGCR11_SP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SP field to a new value.
#define BW_EIM_CSGCR11_SP(v)   BF_CS1(EIM_CSGCR11, SP, v)
#endif


/* --- Register HW_EIM_CSGCR11, field CSREC[22:20] (RW)
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

#define BP_EIM_CSGCR11_CSREC      (20)
#define BM_EIM_CSGCR11_CSREC      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR11_CSREC)
#else
#define BF_EIM_CSGCR11_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR11_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSREC field to a new value.
#define BW_EIM_CSGCR11_CSREC(v)   BF_CS1(EIM_CSGCR11, CSREC, v)
#endif


/* --- Register HW_EIM_CSGCR11, field AUS[23:23] (RW)
 *
 * Address UnShifted. This bit indicates an unshifted mode for address assertion for the relevant
 * chip select accesses. AUS bit is cleared by hardware reset. The reset value for EIM_CS0GCR1[AUS]
 * = EIM_BOOT[10]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value of AUS is 0.
 *
 * Values:
 * 0 - Address shifted according to port size (DSZ config.)
 * 1 - Address unshifted
 */

#define BP_EIM_CSGCR11_AUS      (23)
#define BM_EIM_CSGCR11_AUS      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR11_AUS)
#else
#define BF_EIM_CSGCR11_AUS(v)   (((v) << 23) & BM_EIM_CSGCR11_AUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUS field to a new value.
#define BW_EIM_CSGCR11_AUS(v)   BF_CS1(EIM_CSGCR11, AUS, v)
#endif


/* --- Register HW_EIM_CSGCR11, field GBC[26:24] (RW)
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

#define BP_EIM_CSGCR11_GBC      (24)
#define BM_EIM_CSGCR11_GBC      (0x07000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR11_GBC)
#else
#define BF_EIM_CSGCR11_GBC(v)   (((v) << 24) & BM_EIM_CSGCR11_GBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBC field to a new value.
#define BW_EIM_CSGCR11_GBC(v)   BF_CS1(EIM_CSGCR11, GBC, v)
#endif


/* --- Register HW_EIM_CSGCR11, field WP[27:27] (RW)
 *
 * Write Protect. This bit prevents writes to the address range defined by the corresponding chip
 * select. WP is cleared by a hardware reset.
 *
 * Values:
 * 0 - Writes are allowed in the memory range defined by chip.
 * 1 - Writes are prohibited. All attempts to write to an address mapped by this chip select result in a
 *     error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR11_WP      (27)
#define BM_EIM_CSGCR11_WP      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR11_WP)
#else
#define BF_EIM_CSGCR11_WP(v)   (((v) << 27) & BM_EIM_CSGCR11_WP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WP field to a new value.
#define BW_EIM_CSGCR11_WP(v)   BF_CS1(EIM_CSGCR11, WP, v)
#endif


/* --- Register HW_EIM_CSGCR11, field PSZ[31:28] (RW)
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

#define BP_EIM_CSGCR11_PSZ      (28)
#define BM_EIM_CSGCR11_PSZ      (0xf0000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR11_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR11_PSZ)
#else
#define BF_EIM_CSGCR11_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR11_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSZ field to a new value.
#define BW_EIM_CSGCR11_PSZ(v)   BF_CS1(EIM_CSGCR11, PSZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR21 - Chip Select n General Configuration Register 2 1 (RW)
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
} hw_eim_csgcr21_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR21 register
 */
#define HW_EIM_CSGCR21_ADDR      (REGS_EIM_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR21           (*(volatile hw_eim_csgcr21_t *) HW_EIM_CSGCR21_ADDR)
#define HW_EIM_CSGCR21_RD()      (HW_EIM_CSGCR21.U)
#define HW_EIM_CSGCR21_WR(v)     (HW_EIM_CSGCR21.U = (v))
#define HW_EIM_CSGCR21_SET(v)    (HW_EIM_CSGCR21_WR(HW_EIM_CSGCR21_RD() |  (v)))
#define HW_EIM_CSGCR21_CLR(v)    (HW_EIM_CSGCR21_WR(HW_EIM_CSGCR21_RD() & ~(v)))
#define HW_EIM_CSGCR21_TOG(v)    (HW_EIM_CSGCR21_WR(HW_EIM_CSGCR21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR21 bitfields
 */

/* --- Register HW_EIM_CSGCR21, field ADH[1:0] (RW)
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

#define BP_EIM_CSGCR21_ADH      (0)
#define BM_EIM_CSGCR21_ADH      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR21_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR21_ADH)
#else
#define BF_EIM_CSGCR21_ADH(v)   (((v) << 0) & BM_EIM_CSGCR21_ADH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADH field to a new value.
#define BW_EIM_CSGCR21_ADH(v)   BF_CS1(EIM_CSGCR21, ADH, v)
#endif


/* --- Register HW_EIM_CSGCR21, field DAPS[7:4] (RW)
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

#define BP_EIM_CSGCR21_DAPS      (4)
#define BM_EIM_CSGCR21_DAPS      (0x000000f0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR21_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR21_DAPS)
#else
#define BF_EIM_CSGCR21_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR21_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAPS field to a new value.
#define BW_EIM_CSGCR21_DAPS(v)   BF_CS1(EIM_CSGCR21, DAPS, v)
#endif


/* --- Register HW_EIM_CSGCR21, field DAE[8:8] (RW)
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

#define BP_EIM_CSGCR21_DAE      (8)
#define BM_EIM_CSGCR21_DAE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR21_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR21_DAE)
#else
#define BF_EIM_CSGCR21_DAE(v)   (((v) << 8) & BM_EIM_CSGCR21_DAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAE field to a new value.
#define BW_EIM_CSGCR21_DAE(v)   BF_CS1(EIM_CSGCR21, DAE, v)
#endif


/* --- Register HW_EIM_CSGCR21, field DAP[9:9] (RW)
 *
 * Data Acknowledge Polarity. This bit indicates DTACK memory pin assertion state, active-low or
 * active-high, while executing an async access using DTACK signal from the external device. DAP is
 * cleared by a hardware reset.
 *
 * Values:
 * 0 - DTACK signal is active high
 * 1 - DTACK signal is active low
 */

#define BP_EIM_CSGCR21_DAP      (9)
#define BM_EIM_CSGCR21_DAP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR21_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR21_DAP)
#else
#define BF_EIM_CSGCR21_DAP(v)   (((v) << 9) & BM_EIM_CSGCR21_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAP field to a new value.
#define BW_EIM_CSGCR21_DAP(v)   BF_CS1(EIM_CSGCR21, DAP, v)
#endif


/* --- Register HW_EIM_CSGCR21, field MUX16_BYP_GRANT[12:12] (RW)
 *
 * Muxed 16 bypass grant. This bit when asserted causes EIM to bypass the grant/ack. arbitration
 * with NFC (only for 16 bit muxed mode accesses). The reset value for EIM_CS0GCR2[MUX16_BYP_GRANT]
 * = EIM_BOOT[12]. For EIM_CS1GCR2 - EIM_CS5GCR2, MUX16_BYP_GRANT reset value is 1.
 *
 * Values:
 * 0 - EIM waits for grant before driving a 16 bit muxed mode access to the memory.
 * 1 - EIM ignores the grant signal and immediately drives a 16 bit muxed mode access to the memory.
 */

#define BP_EIM_CSGCR21_MUX16_BYP_GRANT      (12)
#define BM_EIM_CSGCR21_MUX16_BYP_GRANT      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR21_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR21_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR21_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR21_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUX16_BYP_GRANT field to a new value.
#define BW_EIM_CSGCR21_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR21, MUX16_BYP_GRANT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR11 - Chip Select n Read Configuration Register 1 1 (RW)
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
} hw_eim_csrcr11_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR11 register
 */
#define HW_EIM_CSRCR11_ADDR      (REGS_EIM_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR11           (*(volatile hw_eim_csrcr11_t *) HW_EIM_CSRCR11_ADDR)
#define HW_EIM_CSRCR11_RD()      (HW_EIM_CSRCR11.U)
#define HW_EIM_CSRCR11_WR(v)     (HW_EIM_CSRCR11.U = (v))
#define HW_EIM_CSRCR11_SET(v)    (HW_EIM_CSRCR11_WR(HW_EIM_CSRCR11_RD() |  (v)))
#define HW_EIM_CSRCR11_CLR(v)    (HW_EIM_CSRCR11_WR(HW_EIM_CSRCR11_RD() & ~(v)))
#define HW_EIM_CSRCR11_TOG(v)    (HW_EIM_CSRCR11_WR(HW_EIM_CSRCR11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR11 bitfields
 */

/* --- Register HW_EIM_CSRCR11, field RCSN[2:0] (RW)
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

#define BP_EIM_CSRCR11_RCSN      (0)
#define BM_EIM_CSRCR11_RCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR11_RCSN)
#else
#define BF_EIM_CSRCR11_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR11_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSN field to a new value.
#define BW_EIM_CSRCR11_RCSN(v)   BF_CS1(EIM_CSRCR11, RCSN, v)
#endif


/* --- Register HW_EIM_CSRCR11, field RCSA[6:4] (RW)
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

#define BP_EIM_CSRCR11_RCSA      (4)
#define BM_EIM_CSRCR11_RCSA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR11_RCSA)
#else
#define BF_EIM_CSRCR11_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR11_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSA field to a new value.
#define BW_EIM_CSRCR11_RCSA(v)   BF_CS1(EIM_CSRCR11, RCSA, v)
#endif


/* --- Register HW_EIM_CSRCR11, field OEN[10:8] (RW)
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

#define BP_EIM_CSRCR11_OEN      (8)
#define BM_EIM_CSRCR11_OEN      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR11_OEN)
#else
#define BF_EIM_CSRCR11_OEN(v)   (((v) << 8) & BM_EIM_CSRCR11_OEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEN field to a new value.
#define BW_EIM_CSRCR11_OEN(v)   BF_CS1(EIM_CSRCR11, OEN, v)
#endif


/* --- Register HW_EIM_CSRCR11, field OEA[14:12] (RW)
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

#define BP_EIM_CSRCR11_OEA      (12)
#define BM_EIM_CSRCR11_OEA      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR11_OEA)
#else
#define BF_EIM_CSRCR11_OEA(v)   (((v) << 12) & BM_EIM_CSRCR11_OEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEA field to a new value.
#define BW_EIM_CSRCR11_OEA(v)   BF_CS1(EIM_CSRCR11, OEA, v)
#endif


/* --- Register HW_EIM_CSRCR11, field RADVN[18:16] (RW)
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

#define BP_EIM_CSRCR11_RADVN      (16)
#define BM_EIM_CSRCR11_RADVN      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR11_RADVN)
#else
#define BF_EIM_CSRCR11_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR11_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVN field to a new value.
#define BW_EIM_CSRCR11_RADVN(v)   BF_CS1(EIM_CSRCR11, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR11, field RAL[19:19] (RW)
 *
 * Read ADV Low. This bit field determine ADV signal negation time. When RAL=1, RADVN bit field is
 * ignored and ADV signal will stay asserted until end of access. When RAL=0 negation of ADV signal
 * is according to RADVN bit field configuration. The reset value of EIM_CS0RCR1[RAL] = EIM_BOOT[3].
 * RAL is cleared by a hardware reset for EIM_CS1RCR1 - EIM_CS5RCR1.
 */

#define BP_EIM_CSRCR11_RAL      (19)
#define BM_EIM_CSRCR11_RAL      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR11_RAL)
#else
#define BF_EIM_CSRCR11_RAL(v)   (((v) << 19) & BM_EIM_CSRCR11_RAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RAL field to a new value.
#define BW_EIM_CSRCR11_RAL(v)   BF_CS1(EIM_CSRCR11, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR11, field RADVA[22:20] (RW)
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

#define BP_EIM_CSRCR11_RADVA      (20)
#define BM_EIM_CSRCR11_RADVA      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR11_RADVA)
#else
#define BF_EIM_CSRCR11_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR11_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVA field to a new value.
#define BW_EIM_CSRCR11_RADVA(v)   BF_CS1(EIM_CSRCR11, RADVA, v)
#endif


/* --- Register HW_EIM_CSRCR11, field RWSC[29:24] (RW)
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

#define BP_EIM_CSRCR11_RWSC      (24)
#define BM_EIM_CSRCR11_RWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR11_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR11_RWSC)
#else
#define BF_EIM_CSRCR11_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR11_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWSC field to a new value.
#define BW_EIM_CSRCR11_RWSC(v)   BF_CS1(EIM_CSRCR11, RWSC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR21 - Chip Select n Read Configuration Register 2 1 (RW)
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
} hw_eim_csrcr21_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR21 register
 */
#define HW_EIM_CSRCR21_ADDR      (REGS_EIM_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR21           (*(volatile hw_eim_csrcr21_t *) HW_EIM_CSRCR21_ADDR)
#define HW_EIM_CSRCR21_RD()      (HW_EIM_CSRCR21.U)
#define HW_EIM_CSRCR21_WR(v)     (HW_EIM_CSRCR21.U = (v))
#define HW_EIM_CSRCR21_SET(v)    (HW_EIM_CSRCR21_WR(HW_EIM_CSRCR21_RD() |  (v)))
#define HW_EIM_CSRCR21_CLR(v)    (HW_EIM_CSRCR21_WR(HW_EIM_CSRCR21_RD() & ~(v)))
#define HW_EIM_CSRCR21_TOG(v)    (HW_EIM_CSRCR21_WR(HW_EIM_CSRCR21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR21 bitfields
 */

/* --- Register HW_EIM_CSRCR21, field RBEN[2:0] (RW)
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

#define BP_EIM_CSRCR21_RBEN      (0)
#define BM_EIM_CSRCR21_RBEN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR21_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR21_RBEN)
#else
#define BF_EIM_CSRCR21_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR21_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEN field to a new value.
#define BW_EIM_CSRCR21_RBEN(v)   BF_CS1(EIM_CSRCR21, RBEN, v)
#endif


/* --- Register HW_EIM_CSRCR21, field RBE[3:3] (RW)
 *
 * Read BE enable. This bit field determines if BE will be asserted during read access.
 *
 * Values:
 * 0 - - BE are disabled during read access.
 * 1- - BE are enable during read access according to value of RBEA & RBEN bit fields.
 */

#define BP_EIM_CSRCR21_RBE      (3)
#define BM_EIM_CSRCR21_RBE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR21_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR21_RBE)
#else
#define BF_EIM_CSRCR21_RBE(v)   (((v) << 3) & BM_EIM_CSRCR21_RBE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBE field to a new value.
#define BW_EIM_CSRCR21_RBE(v)   BF_CS1(EIM_CSRCR21, RBE, v)
#endif


/* --- Register HW_EIM_CSRCR21, field RBEA[6:4] (RW)
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

#define BP_EIM_CSRCR21_RBEA      (4)
#define BM_EIM_CSRCR21_RBEA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR21_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR21_RBEA)
#else
#define BF_EIM_CSRCR21_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR21_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEA field to a new value.
#define BW_EIM_CSRCR21_RBEA(v)   BF_CS1(EIM_CSRCR21, RBEA, v)
#endif


/* --- Register HW_EIM_CSRCR21, field RL[9:8] (RW)
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

#define BP_EIM_CSRCR21_RL      (8)
#define BM_EIM_CSRCR21_RL      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR21_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR21_RL)
#else
#define BF_EIM_CSRCR21_RL(v)   (((v) << 8) & BM_EIM_CSRCR21_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_EIM_CSRCR21_RL(v)   BF_CS1(EIM_CSRCR21, RL, v)
#endif


/* --- Register HW_EIM_CSRCR21, field PAT[14:12] (RW)
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

#define BP_EIM_CSRCR21_PAT      (12)
#define BM_EIM_CSRCR21_PAT      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR21_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR21_PAT)
#else
#define BF_EIM_CSRCR21_PAT(v)   (((v) << 12) & BM_EIM_CSRCR21_PAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT field to a new value.
#define BW_EIM_CSRCR21_PAT(v)   BF_CS1(EIM_CSRCR21, PAT, v)
#endif


/* --- Register HW_EIM_CSRCR21, field APR[15:15] (RW)
 *
 * Asynchronous Page Read. This bit field determine the asynchronous read mode to the external
 * device. When APR=0, the async. read access is done as single word (where word is defined by the
 * DSZ field). when APR=1, the async. read access executed as page read. page size is according to
 * BL field config., RCSN,RBEN,OEN and RADVN are being ignored. APR is cleared by a hardware reset
 * for EIM_CS1GCR1 - EIM_CS5GCR1. SRD=0 and MUM=0 must apply when APR=1
 */

#define BP_EIM_CSRCR21_APR      (15)
#define BM_EIM_CSRCR21_APR      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR21_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR21_APR)
#else
#define BF_EIM_CSRCR21_APR(v)   (((v) << 15) & BM_EIM_CSRCR21_APR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the APR field to a new value.
#define BW_EIM_CSRCR21_APR(v)   BF_CS1(EIM_CSRCR21, APR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR11 - Chip Select n Write Configuration Register 1 1 (RW)
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
} hw_eim_cswcr11_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR11 register
 */
#define HW_EIM_CSWCR11_ADDR      (REGS_EIM_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR11           (*(volatile hw_eim_cswcr11_t *) HW_EIM_CSWCR11_ADDR)
#define HW_EIM_CSWCR11_RD()      (HW_EIM_CSWCR11.U)
#define HW_EIM_CSWCR11_WR(v)     (HW_EIM_CSWCR11.U = (v))
#define HW_EIM_CSWCR11_SET(v)    (HW_EIM_CSWCR11_WR(HW_EIM_CSWCR11_RD() |  (v)))
#define HW_EIM_CSWCR11_CLR(v)    (HW_EIM_CSWCR11_WR(HW_EIM_CSWCR11_RD() & ~(v)))
#define HW_EIM_CSWCR11_TOG(v)    (HW_EIM_CSWCR11_WR(HW_EIM_CSWCR11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR11 bitfields
 */

/* --- Register HW_EIM_CSWCR11, field WCSN[2:0] (RW)
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

#define BP_EIM_CSWCR11_WCSN      (0)
#define BM_EIM_CSWCR11_WCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR11_WCSN)
#else
#define BF_EIM_CSWCR11_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR11_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSN field to a new value.
#define BW_EIM_CSWCR11_WCSN(v)   BF_CS1(EIM_CSWCR11, WCSN, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WCSA[5:3] (RW)
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

#define BP_EIM_CSWCR11_WCSA      (3)
#define BM_EIM_CSWCR11_WCSA      (0x00000038)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR11_WCSA)
#else
#define BF_EIM_CSWCR11_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR11_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSA field to a new value.
#define BW_EIM_CSWCR11_WCSA(v)   BF_CS1(EIM_CSWCR11, WCSA, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WEN[8:6] (RW)
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

#define BP_EIM_CSWCR11_WEN      (6)
#define BM_EIM_CSWCR11_WEN      (0x000001c0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR11_WEN)
#else
#define BF_EIM_CSWCR11_WEN(v)   (((v) << 6) & BM_EIM_CSWCR11_WEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEN field to a new value.
#define BW_EIM_CSWCR11_WEN(v)   BF_CS1(EIM_CSWCR11, WEN, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WEA[11:9] (RW)
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

#define BP_EIM_CSWCR11_WEA      (9)
#define BM_EIM_CSWCR11_WEA      (0x00000e00)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR11_WEA)
#else
#define BF_EIM_CSWCR11_WEA(v)   (((v) << 9) & BM_EIM_CSWCR11_WEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEA field to a new value.
#define BW_EIM_CSWCR11_WEA(v)   BF_CS1(EIM_CSWCR11, WEA, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WBEN[14:12] (RW)
 *
 * BE[3:0] Negation. This bit field determines when BE[3:0] bus signal is negated during write
 * cycles in async. mode only (SWR=0), according to the settings shown below. This bit field is
 * ignored when SWR=1. BEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEN is 2.
 * For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings: 000 0 EIM clock cycles between
 * end of access and WE negation 001 1 EIM clock cycles between end of access and WE negation 010 2
 * EIM clock cycles between end of access and WE negation 111 7 EIM clock cycles between end of
 * access and WE negation
 */

#define BP_EIM_CSWCR11_WBEN      (12)
#define BM_EIM_CSWCR11_WBEN      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR11_WBEN)
#else
#define BF_EIM_CSWCR11_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR11_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEN field to a new value.
#define BW_EIM_CSWCR11_WBEN(v)   BF_CS1(EIM_CSWCR11, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR11, field WBEA[17:15] (RW)
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

#define BP_EIM_CSWCR11_WBEA      (15)
#define BM_EIM_CSWCR11_WBEA      (0x00038000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR11_WBEA)
#else
#define BF_EIM_CSWCR11_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR11_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEA field to a new value.
#define BW_EIM_CSWCR11_WBEA(v)   BF_CS1(EIM_CSWCR11, WBEA, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WADVN[20:18] (RW)
 *
 * ADV Negation. This bit field determines when ADV signal to memory is negated during write
 * accesses. When SWR=1 (synchronous write mode), ADV negation occurs according to the following
 * formula: (WADVN + WADVA + BCD + BCS + 1) EIM clock cycles. When asynchronous read mode is applied
 * (SWR=0) ADV negation occurs according to the following formula: (WADVN + WADVA + 1) EIM clock
 * cycles. Reset value for EIM_CS0WCR for WADVN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is
 * 000. This field should be configured so ADV negation will occur before the end of access. For ADV
 * negation at the same time as the end of access, S/W should set the WAL bit.
 */

#define BP_EIM_CSWCR11_WADVN      (18)
#define BM_EIM_CSWCR11_WADVN      (0x001c0000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR11_WADVN)
#else
#define BF_EIM_CSWCR11_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR11_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVN field to a new value.
#define BW_EIM_CSWCR11_WADVN(v)   BF_CS1(EIM_CSWCR11, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR11, field WADVA[23:21] (RW)
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

#define BP_EIM_CSWCR11_WADVA      (21)
#define BM_EIM_CSWCR11_WADVA      (0x00e00000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR11_WADVA)
#else
#define BF_EIM_CSWCR11_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR11_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVA field to a new value.
#define BW_EIM_CSWCR11_WADVA(v)   BF_CS1(EIM_CSWCR11, WADVA, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WWSC[29:24] (RW)
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

#define BP_EIM_CSWCR11_WWSC      (24)
#define BM_EIM_CSWCR11_WWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR11_WWSC)
#else
#define BF_EIM_CSWCR11_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR11_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WWSC field to a new value.
#define BW_EIM_CSWCR11_WWSC(v)   BF_CS1(EIM_CSWCR11, WWSC, v)
#endif


/* --- Register HW_EIM_CSWCR11, field WBED[30:30] (RW)
 *
 * Write Byte Enable Disable. When asserted this bit prevent from IPP_DO_BE_B[x] to be asserted
 * during write accesses.This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR11_WBED      (30)
#define BM_EIM_CSWCR11_WBED      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR11_WBED)
#else
#define BF_EIM_CSWCR11_WBED(v)   (((v) << 30) & BM_EIM_CSWCR11_WBED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBED field to a new value.
#define BW_EIM_CSWCR11_WBED(v)   BF_CS1(EIM_CSWCR11, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR11, field WAL[31:31] (RW)
 *
 * Write ADV Low. This bit field determine ADV signal negation time in write accesses. When WAL=1,
 * WADVN bit field is ignored and ADV signal will stay asserted until end of access. When WAL=0
 * negation of ADV signal is according to WADVN bit field configuration. The reset value of
 * CS0WCR1[WAL] = EIM_BOOT[3]. This field is cleared by a hardware reset for CS1WCR1 - CS5WCR1.
 */

#define BP_EIM_CSWCR11_WAL      (31)
#define BM_EIM_CSWCR11_WAL      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR11_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR11_WAL)
#else
#define BF_EIM_CSWCR11_WAL(v)   (((v) << 31) & BM_EIM_CSWCR11_WAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAL field to a new value.
#define BW_EIM_CSWCR11_WAL(v)   BF_CS1(EIM_CSWCR11, WAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR21 - Chip Select n Write Configuration Register 2 1 (RW)
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
} hw_eim_cswcr21_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR21 register
 */
#define HW_EIM_CSWCR21_ADDR      (REGS_EIM_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR21           (*(volatile hw_eim_cswcr21_t *) HW_EIM_CSWCR21_ADDR)
#define HW_EIM_CSWCR21_RD()      (HW_EIM_CSWCR21.U)
#define HW_EIM_CSWCR21_WR(v)     (HW_EIM_CSWCR21.U = (v))
#define HW_EIM_CSWCR21_SET(v)    (HW_EIM_CSWCR21_WR(HW_EIM_CSWCR21_RD() |  (v)))
#define HW_EIM_CSWCR21_CLR(v)    (HW_EIM_CSWCR21_WR(HW_EIM_CSWCR21_RD() & ~(v)))
#define HW_EIM_CSWCR21_TOG(v)    (HW_EIM_CSWCR21_WR(HW_EIM_CSWCR21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR21 bitfields
 */

/* --- Register HW_EIM_CSWCR21, field WBCDD[0:0] (RW)
 *
 * Write Burst Clock Divisor Decrement. If this bit is asserted and BCD value is 0 sync. write
 * access will be preformed as if BCD value is 1.When this bit is negated or BCD value is not 0 this
 * bit has no affect. This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR21_WBCDD      (0)
#define BM_EIM_CSWCR21_WBCDD      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR21_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR21_WBCDD)
#else
#define BF_EIM_CSWCR21_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR21_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCDD field to a new value.
#define BW_EIM_CSWCR21_WBCDD(v)   BF_CS1(EIM_CSWCR21, WBCDD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR12 - Chip Select n General Configuration Register 1 2 (RW)
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
} hw_eim_csgcr12_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR12 register
 */
#define HW_EIM_CSGCR12_ADDR      (REGS_EIM_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR12           (*(volatile hw_eim_csgcr12_t *) HW_EIM_CSGCR12_ADDR)
#define HW_EIM_CSGCR12_RD()      (HW_EIM_CSGCR12.U)
#define HW_EIM_CSGCR12_WR(v)     (HW_EIM_CSGCR12.U = (v))
#define HW_EIM_CSGCR12_SET(v)    (HW_EIM_CSGCR12_WR(HW_EIM_CSGCR12_RD() |  (v)))
#define HW_EIM_CSGCR12_CLR(v)    (HW_EIM_CSGCR12_WR(HW_EIM_CSGCR12_RD() & ~(v)))
#define HW_EIM_CSGCR12_TOG(v)    (HW_EIM_CSGCR12_WR(HW_EIM_CSGCR12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR12 bitfields
 */

/* --- Register HW_EIM_CSGCR12, field CSEN[0:0] (RW)
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

#define BP_EIM_CSGCR12_CSEN      (0)
#define BM_EIM_CSGCR12_CSEN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR12_CSEN)
#else
#define BF_EIM_CSGCR12_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR12_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSEN field to a new value.
#define BW_EIM_CSGCR12_CSEN(v)   BF_CS1(EIM_CSGCR12, CSEN, v)
#endif


/* --- Register HW_EIM_CSGCR12, field SWR[1:1] (RW)
 *
 * Synchronous Write Data. This bit field determine the write accesses mode to the External device
 * of the chip select. The External device should be configured to the same mode as this bit
 * implicates. SWR is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - write accesses are in Asynchronous mode
 * 1 - write accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR12_SWR      (1)
#define BM_EIM_CSGCR12_SWR      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR12_SWR)
#else
#define BF_EIM_CSGCR12_SWR(v)   (((v) << 1) & BM_EIM_CSGCR12_SWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_EIM_CSGCR12_SWR(v)   BF_CS1(EIM_CSGCR12, SWR, v)
#endif


/* --- Register HW_EIM_CSGCR12, field SRD[2:2] (RW)
 *
 * Synchronous Read Data. This bit field determine the read accesses mode to the External device of
 * the chip select. The External device should be configured to the same mode as this bit
 * implicates. SRD is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - read accesses are in Asynchronous mode
 * 1 - read accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR12_SRD      (2)
#define BM_EIM_CSGCR12_SRD      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR12_SRD)
#else
#define BF_EIM_CSGCR12_SRD(v)   (((v) << 2) & BM_EIM_CSGCR12_SRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRD field to a new value.
#define BW_EIM_CSGCR12_SRD(v)   BF_CS1(EIM_CSGCR12, SRD, v)
#endif


/* --- Register HW_EIM_CSGCR12, field MUM[3:3] (RW)
 *
 * Multiplexed Mode. This bit determines the address/data multiplexed mode for asynchronous and
 * synchronous accesses for 8 bit, 16 bit or 32 bit devices (DSZ config. dependent). The reset value
 * for EIM_CS0GCR1[MUM] = EIM_BOOT[2]. For EIM_CS1GCR1 - EIM_CS5GCR1 the reset value is 0.
 *
 * Values:
 * 0 - Multiplexed Mode disable
 * 1 - Multiplexed Mode enable
 */

#define BP_EIM_CSGCR12_MUM      (3)
#define BM_EIM_CSGCR12_MUM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR12_MUM)
#else
#define BF_EIM_CSGCR12_MUM(v)   (((v) << 3) & BM_EIM_CSGCR12_MUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUM field to a new value.
#define BW_EIM_CSGCR12_MUM(v)   BF_CS1(EIM_CSGCR12, MUM, v)
#endif


/* --- Register HW_EIM_CSGCR12, field WFL[4:4] (RW)
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

#define BP_EIM_CSGCR12_WFL      (4)
#define BM_EIM_CSGCR12_WFL      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR12_WFL)
#else
#define BF_EIM_CSGCR12_WFL(v)   (((v) << 4) & BM_EIM_CSGCR12_WFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WFL field to a new value.
#define BW_EIM_CSGCR12_WFL(v)   BF_CS1(EIM_CSGCR12, WFL, v)
#endif


/* --- Register HW_EIM_CSGCR12, field RFL[5:5] (RW)
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

#define BP_EIM_CSGCR12_RFL      (5)
#define BM_EIM_CSGCR12_RFL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR12_RFL)
#else
#define BF_EIM_CSGCR12_RFL(v)   (((v) << 5) & BM_EIM_CSGCR12_RFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFL field to a new value.
#define BW_EIM_CSGCR12_RFL(v)   BF_CS1(EIM_CSGCR12, RFL, v)
#endif


/* --- Register HW_EIM_CSGCR12, field CRE[6:6] (RW)
 *
 * Configuration Register Enable. This bit indicates CRE memory pin state while executing a memory
 * register set command to PSRAM external device. CRE is cleared by a hardware reset.
 *
 * Values:
 * 0 - CRE signal use is disable
 * 1 - CRE signal use is enable
 */

#define BP_EIM_CSGCR12_CRE      (6)
#define BM_EIM_CSGCR12_CRE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR12_CRE)
#else
#define BF_EIM_CSGCR12_CRE(v)   (((v) << 6) & BM_EIM_CSGCR12_CRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRE field to a new value.
#define BW_EIM_CSGCR12_CRE(v)   BF_CS1(EIM_CSGCR12, CRE, v)
#endif


/* --- Register HW_EIM_CSGCR12, field CREP[7:7] (RW)
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

#define BP_EIM_CSGCR12_CREP      (7)
#define BM_EIM_CSGCR12_CREP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR12_CREP)
#else
#define BF_EIM_CSGCR12_CREP(v)   (((v) << 7) & BM_EIM_CSGCR12_CREP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CREP field to a new value.
#define BW_EIM_CSGCR12_CREP(v)   BF_CS1(EIM_CSGCR12, CREP, v)
#endif


/* --- Register HW_EIM_CSGCR12, field BL[10:8] (RW)
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

#define BP_EIM_CSGCR12_BL      (8)
#define BM_EIM_CSGCR12_BL      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR12_BL)
#else
#define BF_EIM_CSGCR12_BL(v)   (((v) << 8) & BM_EIM_CSGCR12_BL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BL field to a new value.
#define BW_EIM_CSGCR12_BL(v)   BF_CS1(EIM_CSGCR12, BL, v)
#endif


/* --- Register HW_EIM_CSGCR12, field WC[11:11] (RW)
 *
 * Write Continuous. The WI bit indicates that write access to the memory are always continuous
 * accesses regardless of the BL field value. WI is cleared by hardware reset.
 *
 * Values:
 * 0 - Write access burst length occurs according to BL value.
 * 1 - Write access burst length is continuous.
 */

#define BP_EIM_CSGCR12_WC      (11)
#define BM_EIM_CSGCR12_WC      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR12_WC)
#else
#define BF_EIM_CSGCR12_WC(v)   (((v) << 11) & BM_EIM_CSGCR12_WC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WC field to a new value.
#define BW_EIM_CSGCR12_WC(v)   BF_CS1(EIM_CSGCR12, WC, v)
#endif


/* --- Register HW_EIM_CSGCR12, field BCD[13:12] (RW)
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

#define BP_EIM_CSGCR12_BCD      (12)
#define BM_EIM_CSGCR12_BCD      (0x00003000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR12_BCD)
#else
#define BF_EIM_CSGCR12_BCD(v)   (((v) << 12) & BM_EIM_CSGCR12_BCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCD field to a new value.
#define BW_EIM_CSGCR12_BCD(v)   BF_CS1(EIM_CSGCR12, BCD, v)
#endif


/* --- Register HW_EIM_CSGCR12, field BCS[15:14] (RW)
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

#define BP_EIM_CSGCR12_BCS      (14)
#define BM_EIM_CSGCR12_BCS      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR12_BCS)
#else
#define BF_EIM_CSGCR12_BCS(v)   (((v) << 14) & BM_EIM_CSGCR12_BCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCS field to a new value.
#define BW_EIM_CSGCR12_BCS(v)   BF_CS1(EIM_CSGCR12, BCS, v)
#endif


/* --- Register HW_EIM_CSGCR12, field DSZ[18:16] (RW)
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

#define BP_EIM_CSGCR12_DSZ      (16)
#define BM_EIM_CSGCR12_DSZ      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR12_DSZ)
#else
#define BF_EIM_CSGCR12_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR12_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSZ field to a new value.
#define BW_EIM_CSGCR12_DSZ(v)   BF_CS1(EIM_CSGCR12, DSZ, v)
#endif


/* --- Register HW_EIM_CSGCR12, field SP[19:19] (RW)
 *
 * Supervisor Protect. This bit prevents accesses to the address range defined by the corresponding
 * chip select when the access is attempted in the User mode. SP is cleared by a hardware reset.
 *
 * Values:
 * 0 - User mode accesses are allowed in the memory range defined by chip select.
 * 1 - User mode accesses are prohibited. All attempts to access an address mapped by this chip select in
 *     User mode results in an error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR12_SP      (19)
#define BM_EIM_CSGCR12_SP      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR12_SP)
#else
#define BF_EIM_CSGCR12_SP(v)   (((v) << 19) & BM_EIM_CSGCR12_SP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SP field to a new value.
#define BW_EIM_CSGCR12_SP(v)   BF_CS1(EIM_CSGCR12, SP, v)
#endif


/* --- Register HW_EIM_CSGCR12, field CSREC[22:20] (RW)
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

#define BP_EIM_CSGCR12_CSREC      (20)
#define BM_EIM_CSGCR12_CSREC      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR12_CSREC)
#else
#define BF_EIM_CSGCR12_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR12_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSREC field to a new value.
#define BW_EIM_CSGCR12_CSREC(v)   BF_CS1(EIM_CSGCR12, CSREC, v)
#endif


/* --- Register HW_EIM_CSGCR12, field AUS[23:23] (RW)
 *
 * Address UnShifted. This bit indicates an unshifted mode for address assertion for the relevant
 * chip select accesses. AUS bit is cleared by hardware reset. The reset value for EIM_CS0GCR1[AUS]
 * = EIM_BOOT[10]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value of AUS is 0.
 *
 * Values:
 * 0 - Address shifted according to port size (DSZ config.)
 * 1 - Address unshifted
 */

#define BP_EIM_CSGCR12_AUS      (23)
#define BM_EIM_CSGCR12_AUS      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR12_AUS)
#else
#define BF_EIM_CSGCR12_AUS(v)   (((v) << 23) & BM_EIM_CSGCR12_AUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUS field to a new value.
#define BW_EIM_CSGCR12_AUS(v)   BF_CS1(EIM_CSGCR12, AUS, v)
#endif


/* --- Register HW_EIM_CSGCR12, field GBC[26:24] (RW)
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

#define BP_EIM_CSGCR12_GBC      (24)
#define BM_EIM_CSGCR12_GBC      (0x07000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR12_GBC)
#else
#define BF_EIM_CSGCR12_GBC(v)   (((v) << 24) & BM_EIM_CSGCR12_GBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBC field to a new value.
#define BW_EIM_CSGCR12_GBC(v)   BF_CS1(EIM_CSGCR12, GBC, v)
#endif


/* --- Register HW_EIM_CSGCR12, field WP[27:27] (RW)
 *
 * Write Protect. This bit prevents writes to the address range defined by the corresponding chip
 * select. WP is cleared by a hardware reset.
 *
 * Values:
 * 0 - Writes are allowed in the memory range defined by chip.
 * 1 - Writes are prohibited. All attempts to write to an address mapped by this chip select result in a
 *     error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR12_WP      (27)
#define BM_EIM_CSGCR12_WP      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR12_WP)
#else
#define BF_EIM_CSGCR12_WP(v)   (((v) << 27) & BM_EIM_CSGCR12_WP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WP field to a new value.
#define BW_EIM_CSGCR12_WP(v)   BF_CS1(EIM_CSGCR12, WP, v)
#endif


/* --- Register HW_EIM_CSGCR12, field PSZ[31:28] (RW)
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

#define BP_EIM_CSGCR12_PSZ      (28)
#define BM_EIM_CSGCR12_PSZ      (0xf0000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR12_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR12_PSZ)
#else
#define BF_EIM_CSGCR12_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR12_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSZ field to a new value.
#define BW_EIM_CSGCR12_PSZ(v)   BF_CS1(EIM_CSGCR12, PSZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR22 - Chip Select n General Configuration Register 2 2 (RW)
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
} hw_eim_csgcr22_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR22 register
 */
#define HW_EIM_CSGCR22_ADDR      (REGS_EIM_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR22           (*(volatile hw_eim_csgcr22_t *) HW_EIM_CSGCR22_ADDR)
#define HW_EIM_CSGCR22_RD()      (HW_EIM_CSGCR22.U)
#define HW_EIM_CSGCR22_WR(v)     (HW_EIM_CSGCR22.U = (v))
#define HW_EIM_CSGCR22_SET(v)    (HW_EIM_CSGCR22_WR(HW_EIM_CSGCR22_RD() |  (v)))
#define HW_EIM_CSGCR22_CLR(v)    (HW_EIM_CSGCR22_WR(HW_EIM_CSGCR22_RD() & ~(v)))
#define HW_EIM_CSGCR22_TOG(v)    (HW_EIM_CSGCR22_WR(HW_EIM_CSGCR22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR22 bitfields
 */

/* --- Register HW_EIM_CSGCR22, field ADH[1:0] (RW)
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

#define BP_EIM_CSGCR22_ADH      (0)
#define BM_EIM_CSGCR22_ADH      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR22_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR22_ADH)
#else
#define BF_EIM_CSGCR22_ADH(v)   (((v) << 0) & BM_EIM_CSGCR22_ADH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADH field to a new value.
#define BW_EIM_CSGCR22_ADH(v)   BF_CS1(EIM_CSGCR22, ADH, v)
#endif


/* --- Register HW_EIM_CSGCR22, field DAPS[7:4] (RW)
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

#define BP_EIM_CSGCR22_DAPS      (4)
#define BM_EIM_CSGCR22_DAPS      (0x000000f0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR22_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR22_DAPS)
#else
#define BF_EIM_CSGCR22_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR22_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAPS field to a new value.
#define BW_EIM_CSGCR22_DAPS(v)   BF_CS1(EIM_CSGCR22, DAPS, v)
#endif


/* --- Register HW_EIM_CSGCR22, field DAE[8:8] (RW)
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

#define BP_EIM_CSGCR22_DAE      (8)
#define BM_EIM_CSGCR22_DAE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR22_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR22_DAE)
#else
#define BF_EIM_CSGCR22_DAE(v)   (((v) << 8) & BM_EIM_CSGCR22_DAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAE field to a new value.
#define BW_EIM_CSGCR22_DAE(v)   BF_CS1(EIM_CSGCR22, DAE, v)
#endif


/* --- Register HW_EIM_CSGCR22, field DAP[9:9] (RW)
 *
 * Data Acknowledge Polarity. This bit indicates DTACK memory pin assertion state, active-low or
 * active-high, while executing an async access using DTACK signal from the external device. DAP is
 * cleared by a hardware reset.
 *
 * Values:
 * 0 - DTACK signal is active high
 * 1 - DTACK signal is active low
 */

#define BP_EIM_CSGCR22_DAP      (9)
#define BM_EIM_CSGCR22_DAP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR22_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR22_DAP)
#else
#define BF_EIM_CSGCR22_DAP(v)   (((v) << 9) & BM_EIM_CSGCR22_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAP field to a new value.
#define BW_EIM_CSGCR22_DAP(v)   BF_CS1(EIM_CSGCR22, DAP, v)
#endif


/* --- Register HW_EIM_CSGCR22, field MUX16_BYP_GRANT[12:12] (RW)
 *
 * Muxed 16 bypass grant. This bit when asserted causes EIM to bypass the grant/ack. arbitration
 * with NFC (only for 16 bit muxed mode accesses). The reset value for EIM_CS0GCR2[MUX16_BYP_GRANT]
 * = EIM_BOOT[12]. For EIM_CS1GCR2 - EIM_CS5GCR2, MUX16_BYP_GRANT reset value is 1.
 *
 * Values:
 * 0 - EIM waits for grant before driving a 16 bit muxed mode access to the memory.
 * 1 - EIM ignores the grant signal and immediately drives a 16 bit muxed mode access to the memory.
 */

#define BP_EIM_CSGCR22_MUX16_BYP_GRANT      (12)
#define BM_EIM_CSGCR22_MUX16_BYP_GRANT      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR22_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR22_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR22_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR22_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUX16_BYP_GRANT field to a new value.
#define BW_EIM_CSGCR22_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR22, MUX16_BYP_GRANT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR12 - Chip Select n Read Configuration Register 1 2 (RW)
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
} hw_eim_csrcr12_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR12 register
 */
#define HW_EIM_CSRCR12_ADDR      (REGS_EIM_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR12           (*(volatile hw_eim_csrcr12_t *) HW_EIM_CSRCR12_ADDR)
#define HW_EIM_CSRCR12_RD()      (HW_EIM_CSRCR12.U)
#define HW_EIM_CSRCR12_WR(v)     (HW_EIM_CSRCR12.U = (v))
#define HW_EIM_CSRCR12_SET(v)    (HW_EIM_CSRCR12_WR(HW_EIM_CSRCR12_RD() |  (v)))
#define HW_EIM_CSRCR12_CLR(v)    (HW_EIM_CSRCR12_WR(HW_EIM_CSRCR12_RD() & ~(v)))
#define HW_EIM_CSRCR12_TOG(v)    (HW_EIM_CSRCR12_WR(HW_EIM_CSRCR12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR12 bitfields
 */

/* --- Register HW_EIM_CSRCR12, field RCSN[2:0] (RW)
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

#define BP_EIM_CSRCR12_RCSN      (0)
#define BM_EIM_CSRCR12_RCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR12_RCSN)
#else
#define BF_EIM_CSRCR12_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR12_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSN field to a new value.
#define BW_EIM_CSRCR12_RCSN(v)   BF_CS1(EIM_CSRCR12, RCSN, v)
#endif


/* --- Register HW_EIM_CSRCR12, field RCSA[6:4] (RW)
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

#define BP_EIM_CSRCR12_RCSA      (4)
#define BM_EIM_CSRCR12_RCSA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR12_RCSA)
#else
#define BF_EIM_CSRCR12_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR12_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSA field to a new value.
#define BW_EIM_CSRCR12_RCSA(v)   BF_CS1(EIM_CSRCR12, RCSA, v)
#endif


/* --- Register HW_EIM_CSRCR12, field OEN[10:8] (RW)
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

#define BP_EIM_CSRCR12_OEN      (8)
#define BM_EIM_CSRCR12_OEN      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR12_OEN)
#else
#define BF_EIM_CSRCR12_OEN(v)   (((v) << 8) & BM_EIM_CSRCR12_OEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEN field to a new value.
#define BW_EIM_CSRCR12_OEN(v)   BF_CS1(EIM_CSRCR12, OEN, v)
#endif


/* --- Register HW_EIM_CSRCR12, field OEA[14:12] (RW)
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

#define BP_EIM_CSRCR12_OEA      (12)
#define BM_EIM_CSRCR12_OEA      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR12_OEA)
#else
#define BF_EIM_CSRCR12_OEA(v)   (((v) << 12) & BM_EIM_CSRCR12_OEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEA field to a new value.
#define BW_EIM_CSRCR12_OEA(v)   BF_CS1(EIM_CSRCR12, OEA, v)
#endif


/* --- Register HW_EIM_CSRCR12, field RADVN[18:16] (RW)
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

#define BP_EIM_CSRCR12_RADVN      (16)
#define BM_EIM_CSRCR12_RADVN      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR12_RADVN)
#else
#define BF_EIM_CSRCR12_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR12_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVN field to a new value.
#define BW_EIM_CSRCR12_RADVN(v)   BF_CS1(EIM_CSRCR12, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR12, field RAL[19:19] (RW)
 *
 * Read ADV Low. This bit field determine ADV signal negation time. When RAL=1, RADVN bit field is
 * ignored and ADV signal will stay asserted until end of access. When RAL=0 negation of ADV signal
 * is according to RADVN bit field configuration. The reset value of EIM_CS0RCR1[RAL] = EIM_BOOT[3].
 * RAL is cleared by a hardware reset for EIM_CS1RCR1 - EIM_CS5RCR1.
 */

#define BP_EIM_CSRCR12_RAL      (19)
#define BM_EIM_CSRCR12_RAL      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR12_RAL)
#else
#define BF_EIM_CSRCR12_RAL(v)   (((v) << 19) & BM_EIM_CSRCR12_RAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RAL field to a new value.
#define BW_EIM_CSRCR12_RAL(v)   BF_CS1(EIM_CSRCR12, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR12, field RADVA[22:20] (RW)
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

#define BP_EIM_CSRCR12_RADVA      (20)
#define BM_EIM_CSRCR12_RADVA      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR12_RADVA)
#else
#define BF_EIM_CSRCR12_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR12_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVA field to a new value.
#define BW_EIM_CSRCR12_RADVA(v)   BF_CS1(EIM_CSRCR12, RADVA, v)
#endif


/* --- Register HW_EIM_CSRCR12, field RWSC[29:24] (RW)
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

#define BP_EIM_CSRCR12_RWSC      (24)
#define BM_EIM_CSRCR12_RWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR12_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR12_RWSC)
#else
#define BF_EIM_CSRCR12_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR12_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWSC field to a new value.
#define BW_EIM_CSRCR12_RWSC(v)   BF_CS1(EIM_CSRCR12, RWSC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR22 - Chip Select n Read Configuration Register 2 2 (RW)
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
} hw_eim_csrcr22_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR22 register
 */
#define HW_EIM_CSRCR22_ADDR      (REGS_EIM_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR22           (*(volatile hw_eim_csrcr22_t *) HW_EIM_CSRCR22_ADDR)
#define HW_EIM_CSRCR22_RD()      (HW_EIM_CSRCR22.U)
#define HW_EIM_CSRCR22_WR(v)     (HW_EIM_CSRCR22.U = (v))
#define HW_EIM_CSRCR22_SET(v)    (HW_EIM_CSRCR22_WR(HW_EIM_CSRCR22_RD() |  (v)))
#define HW_EIM_CSRCR22_CLR(v)    (HW_EIM_CSRCR22_WR(HW_EIM_CSRCR22_RD() & ~(v)))
#define HW_EIM_CSRCR22_TOG(v)    (HW_EIM_CSRCR22_WR(HW_EIM_CSRCR22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR22 bitfields
 */

/* --- Register HW_EIM_CSRCR22, field RBEN[2:0] (RW)
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

#define BP_EIM_CSRCR22_RBEN      (0)
#define BM_EIM_CSRCR22_RBEN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR22_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR22_RBEN)
#else
#define BF_EIM_CSRCR22_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR22_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEN field to a new value.
#define BW_EIM_CSRCR22_RBEN(v)   BF_CS1(EIM_CSRCR22, RBEN, v)
#endif


/* --- Register HW_EIM_CSRCR22, field RBE[3:3] (RW)
 *
 * Read BE enable. This bit field determines if BE will be asserted during read access.
 *
 * Values:
 * 0 - - BE are disabled during read access.
 * 1- - BE are enable during read access according to value of RBEA & RBEN bit fields.
 */

#define BP_EIM_CSRCR22_RBE      (3)
#define BM_EIM_CSRCR22_RBE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR22_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR22_RBE)
#else
#define BF_EIM_CSRCR22_RBE(v)   (((v) << 3) & BM_EIM_CSRCR22_RBE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBE field to a new value.
#define BW_EIM_CSRCR22_RBE(v)   BF_CS1(EIM_CSRCR22, RBE, v)
#endif


/* --- Register HW_EIM_CSRCR22, field RBEA[6:4] (RW)
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

#define BP_EIM_CSRCR22_RBEA      (4)
#define BM_EIM_CSRCR22_RBEA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR22_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR22_RBEA)
#else
#define BF_EIM_CSRCR22_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR22_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEA field to a new value.
#define BW_EIM_CSRCR22_RBEA(v)   BF_CS1(EIM_CSRCR22, RBEA, v)
#endif


/* --- Register HW_EIM_CSRCR22, field RL[9:8] (RW)
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

#define BP_EIM_CSRCR22_RL      (8)
#define BM_EIM_CSRCR22_RL      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR22_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR22_RL)
#else
#define BF_EIM_CSRCR22_RL(v)   (((v) << 8) & BM_EIM_CSRCR22_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_EIM_CSRCR22_RL(v)   BF_CS1(EIM_CSRCR22, RL, v)
#endif


/* --- Register HW_EIM_CSRCR22, field PAT[14:12] (RW)
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

#define BP_EIM_CSRCR22_PAT      (12)
#define BM_EIM_CSRCR22_PAT      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR22_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR22_PAT)
#else
#define BF_EIM_CSRCR22_PAT(v)   (((v) << 12) & BM_EIM_CSRCR22_PAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT field to a new value.
#define BW_EIM_CSRCR22_PAT(v)   BF_CS1(EIM_CSRCR22, PAT, v)
#endif


/* --- Register HW_EIM_CSRCR22, field APR[15:15] (RW)
 *
 * Asynchronous Page Read. This bit field determine the asynchronous read mode to the external
 * device. When APR=0, the async. read access is done as single word (where word is defined by the
 * DSZ field). when APR=1, the async. read access executed as page read. page size is according to
 * BL field config., RCSN,RBEN,OEN and RADVN are being ignored. APR is cleared by a hardware reset
 * for EIM_CS1GCR1 - EIM_CS5GCR1. SRD=0 and MUM=0 must apply when APR=1
 */

#define BP_EIM_CSRCR22_APR      (15)
#define BM_EIM_CSRCR22_APR      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR22_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR22_APR)
#else
#define BF_EIM_CSRCR22_APR(v)   (((v) << 15) & BM_EIM_CSRCR22_APR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the APR field to a new value.
#define BW_EIM_CSRCR22_APR(v)   BF_CS1(EIM_CSRCR22, APR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR12 - Chip Select n Write Configuration Register 1 2 (RW)
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
} hw_eim_cswcr12_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR12 register
 */
#define HW_EIM_CSWCR12_ADDR      (REGS_EIM_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR12           (*(volatile hw_eim_cswcr12_t *) HW_EIM_CSWCR12_ADDR)
#define HW_EIM_CSWCR12_RD()      (HW_EIM_CSWCR12.U)
#define HW_EIM_CSWCR12_WR(v)     (HW_EIM_CSWCR12.U = (v))
#define HW_EIM_CSWCR12_SET(v)    (HW_EIM_CSWCR12_WR(HW_EIM_CSWCR12_RD() |  (v)))
#define HW_EIM_CSWCR12_CLR(v)    (HW_EIM_CSWCR12_WR(HW_EIM_CSWCR12_RD() & ~(v)))
#define HW_EIM_CSWCR12_TOG(v)    (HW_EIM_CSWCR12_WR(HW_EIM_CSWCR12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR12 bitfields
 */

/* --- Register HW_EIM_CSWCR12, field WCSN[2:0] (RW)
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

#define BP_EIM_CSWCR12_WCSN      (0)
#define BM_EIM_CSWCR12_WCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR12_WCSN)
#else
#define BF_EIM_CSWCR12_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR12_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSN field to a new value.
#define BW_EIM_CSWCR12_WCSN(v)   BF_CS1(EIM_CSWCR12, WCSN, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WCSA[5:3] (RW)
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

#define BP_EIM_CSWCR12_WCSA      (3)
#define BM_EIM_CSWCR12_WCSA      (0x00000038)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR12_WCSA)
#else
#define BF_EIM_CSWCR12_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR12_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSA field to a new value.
#define BW_EIM_CSWCR12_WCSA(v)   BF_CS1(EIM_CSWCR12, WCSA, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WEN[8:6] (RW)
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

#define BP_EIM_CSWCR12_WEN      (6)
#define BM_EIM_CSWCR12_WEN      (0x000001c0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR12_WEN)
#else
#define BF_EIM_CSWCR12_WEN(v)   (((v) << 6) & BM_EIM_CSWCR12_WEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEN field to a new value.
#define BW_EIM_CSWCR12_WEN(v)   BF_CS1(EIM_CSWCR12, WEN, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WEA[11:9] (RW)
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

#define BP_EIM_CSWCR12_WEA      (9)
#define BM_EIM_CSWCR12_WEA      (0x00000e00)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR12_WEA)
#else
#define BF_EIM_CSWCR12_WEA(v)   (((v) << 9) & BM_EIM_CSWCR12_WEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEA field to a new value.
#define BW_EIM_CSWCR12_WEA(v)   BF_CS1(EIM_CSWCR12, WEA, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WBEN[14:12] (RW)
 *
 * BE[3:0] Negation. This bit field determines when BE[3:0] bus signal is negated during write
 * cycles in async. mode only (SWR=0), according to the settings shown below. This bit field is
 * ignored when SWR=1. BEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEN is 2.
 * For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings: 000 0 EIM clock cycles between
 * end of access and WE negation 001 1 EIM clock cycles between end of access and WE negation 010 2
 * EIM clock cycles between end of access and WE negation 111 7 EIM clock cycles between end of
 * access and WE negation
 */

#define BP_EIM_CSWCR12_WBEN      (12)
#define BM_EIM_CSWCR12_WBEN      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR12_WBEN)
#else
#define BF_EIM_CSWCR12_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR12_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEN field to a new value.
#define BW_EIM_CSWCR12_WBEN(v)   BF_CS1(EIM_CSWCR12, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR12, field WBEA[17:15] (RW)
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

#define BP_EIM_CSWCR12_WBEA      (15)
#define BM_EIM_CSWCR12_WBEA      (0x00038000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR12_WBEA)
#else
#define BF_EIM_CSWCR12_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR12_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEA field to a new value.
#define BW_EIM_CSWCR12_WBEA(v)   BF_CS1(EIM_CSWCR12, WBEA, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WADVN[20:18] (RW)
 *
 * ADV Negation. This bit field determines when ADV signal to memory is negated during write
 * accesses. When SWR=1 (synchronous write mode), ADV negation occurs according to the following
 * formula: (WADVN + WADVA + BCD + BCS + 1) EIM clock cycles. When asynchronous read mode is applied
 * (SWR=0) ADV negation occurs according to the following formula: (WADVN + WADVA + 1) EIM clock
 * cycles. Reset value for EIM_CS0WCR for WADVN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is
 * 000. This field should be configured so ADV negation will occur before the end of access. For ADV
 * negation at the same time as the end of access, S/W should set the WAL bit.
 */

#define BP_EIM_CSWCR12_WADVN      (18)
#define BM_EIM_CSWCR12_WADVN      (0x001c0000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR12_WADVN)
#else
#define BF_EIM_CSWCR12_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR12_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVN field to a new value.
#define BW_EIM_CSWCR12_WADVN(v)   BF_CS1(EIM_CSWCR12, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR12, field WADVA[23:21] (RW)
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

#define BP_EIM_CSWCR12_WADVA      (21)
#define BM_EIM_CSWCR12_WADVA      (0x00e00000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR12_WADVA)
#else
#define BF_EIM_CSWCR12_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR12_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVA field to a new value.
#define BW_EIM_CSWCR12_WADVA(v)   BF_CS1(EIM_CSWCR12, WADVA, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WWSC[29:24] (RW)
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

#define BP_EIM_CSWCR12_WWSC      (24)
#define BM_EIM_CSWCR12_WWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR12_WWSC)
#else
#define BF_EIM_CSWCR12_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR12_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WWSC field to a new value.
#define BW_EIM_CSWCR12_WWSC(v)   BF_CS1(EIM_CSWCR12, WWSC, v)
#endif


/* --- Register HW_EIM_CSWCR12, field WBED[30:30] (RW)
 *
 * Write Byte Enable Disable. When asserted this bit prevent from IPP_DO_BE_B[x] to be asserted
 * during write accesses.This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR12_WBED      (30)
#define BM_EIM_CSWCR12_WBED      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR12_WBED)
#else
#define BF_EIM_CSWCR12_WBED(v)   (((v) << 30) & BM_EIM_CSWCR12_WBED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBED field to a new value.
#define BW_EIM_CSWCR12_WBED(v)   BF_CS1(EIM_CSWCR12, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR12, field WAL[31:31] (RW)
 *
 * Write ADV Low. This bit field determine ADV signal negation time in write accesses. When WAL=1,
 * WADVN bit field is ignored and ADV signal will stay asserted until end of access. When WAL=0
 * negation of ADV signal is according to WADVN bit field configuration. The reset value of
 * CS0WCR1[WAL] = EIM_BOOT[3]. This field is cleared by a hardware reset for CS1WCR1 - CS5WCR1.
 */

#define BP_EIM_CSWCR12_WAL      (31)
#define BM_EIM_CSWCR12_WAL      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR12_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR12_WAL)
#else
#define BF_EIM_CSWCR12_WAL(v)   (((v) << 31) & BM_EIM_CSWCR12_WAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAL field to a new value.
#define BW_EIM_CSWCR12_WAL(v)   BF_CS1(EIM_CSWCR12, WAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR22 - Chip Select n Write Configuration Register 2 2 (RW)
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
} hw_eim_cswcr22_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR22 register
 */
#define HW_EIM_CSWCR22_ADDR      (REGS_EIM_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR22           (*(volatile hw_eim_cswcr22_t *) HW_EIM_CSWCR22_ADDR)
#define HW_EIM_CSWCR22_RD()      (HW_EIM_CSWCR22.U)
#define HW_EIM_CSWCR22_WR(v)     (HW_EIM_CSWCR22.U = (v))
#define HW_EIM_CSWCR22_SET(v)    (HW_EIM_CSWCR22_WR(HW_EIM_CSWCR22_RD() |  (v)))
#define HW_EIM_CSWCR22_CLR(v)    (HW_EIM_CSWCR22_WR(HW_EIM_CSWCR22_RD() & ~(v)))
#define HW_EIM_CSWCR22_TOG(v)    (HW_EIM_CSWCR22_WR(HW_EIM_CSWCR22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR22 bitfields
 */

/* --- Register HW_EIM_CSWCR22, field WBCDD[0:0] (RW)
 *
 * Write Burst Clock Divisor Decrement. If this bit is asserted and BCD value is 0 sync. write
 * access will be preformed as if BCD value is 1.When this bit is negated or BCD value is not 0 this
 * bit has no affect. This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR22_WBCDD      (0)
#define BM_EIM_CSWCR22_WBCDD      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR22_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR22_WBCDD)
#else
#define BF_EIM_CSWCR22_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR22_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCDD field to a new value.
#define BW_EIM_CSWCR22_WBCDD(v)   BF_CS1(EIM_CSWCR22, WBCDD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR13 - Chip Select n General Configuration Register 1 3 (RW)
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
} hw_eim_csgcr13_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR13 register
 */
#define HW_EIM_CSGCR13_ADDR      (REGS_EIM_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR13           (*(volatile hw_eim_csgcr13_t *) HW_EIM_CSGCR13_ADDR)
#define HW_EIM_CSGCR13_RD()      (HW_EIM_CSGCR13.U)
#define HW_EIM_CSGCR13_WR(v)     (HW_EIM_CSGCR13.U = (v))
#define HW_EIM_CSGCR13_SET(v)    (HW_EIM_CSGCR13_WR(HW_EIM_CSGCR13_RD() |  (v)))
#define HW_EIM_CSGCR13_CLR(v)    (HW_EIM_CSGCR13_WR(HW_EIM_CSGCR13_RD() & ~(v)))
#define HW_EIM_CSGCR13_TOG(v)    (HW_EIM_CSGCR13_WR(HW_EIM_CSGCR13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR13 bitfields
 */

/* --- Register HW_EIM_CSGCR13, field CSEN[0:0] (RW)
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

#define BP_EIM_CSGCR13_CSEN      (0)
#define BM_EIM_CSGCR13_CSEN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_CSEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR13_CSEN)
#else
#define BF_EIM_CSGCR13_CSEN(v)   (((v) << 0) & BM_EIM_CSGCR13_CSEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSEN field to a new value.
#define BW_EIM_CSGCR13_CSEN(v)   BF_CS1(EIM_CSGCR13, CSEN, v)
#endif


/* --- Register HW_EIM_CSGCR13, field SWR[1:1] (RW)
 *
 * Synchronous Write Data. This bit field determine the write accesses mode to the External device
 * of the chip select. The External device should be configured to the same mode as this bit
 * implicates. SWR is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - write accesses are in Asynchronous mode
 * 1 - write accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR13_SWR      (1)
#define BM_EIM_CSGCR13_SWR      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_SWR(v)   ((((reg32_t) v) << 1) & BM_EIM_CSGCR13_SWR)
#else
#define BF_EIM_CSGCR13_SWR(v)   (((v) << 1) & BM_EIM_CSGCR13_SWR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SWR field to a new value.
#define BW_EIM_CSGCR13_SWR(v)   BF_CS1(EIM_CSGCR13, SWR, v)
#endif


/* --- Register HW_EIM_CSGCR13, field SRD[2:2] (RW)
 *
 * Synchronous Read Data. This bit field determine the read accesses mode to the External device of
 * the chip select. The External device should be configured to the same mode as this bit
 * implicates. SRD is cleared by a hardware reset. Sync. accesses supported only for 16/32 bit port.
 *
 * Values:
 * 0 - read accesses are in Asynchronous mode
 * 1 - read accesses are in Synchronous mode
 */

#define BP_EIM_CSGCR13_SRD      (2)
#define BM_EIM_CSGCR13_SRD      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_SRD(v)   ((((reg32_t) v) << 2) & BM_EIM_CSGCR13_SRD)
#else
#define BF_EIM_CSGCR13_SRD(v)   (((v) << 2) & BM_EIM_CSGCR13_SRD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRD field to a new value.
#define BW_EIM_CSGCR13_SRD(v)   BF_CS1(EIM_CSGCR13, SRD, v)
#endif


/* --- Register HW_EIM_CSGCR13, field MUM[3:3] (RW)
 *
 * Multiplexed Mode. This bit determines the address/data multiplexed mode for asynchronous and
 * synchronous accesses for 8 bit, 16 bit or 32 bit devices (DSZ config. dependent). The reset value
 * for EIM_CS0GCR1[MUM] = EIM_BOOT[2]. For EIM_CS1GCR1 - EIM_CS5GCR1 the reset value is 0.
 *
 * Values:
 * 0 - Multiplexed Mode disable
 * 1 - Multiplexed Mode enable
 */

#define BP_EIM_CSGCR13_MUM      (3)
#define BM_EIM_CSGCR13_MUM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_MUM(v)   ((((reg32_t) v) << 3) & BM_EIM_CSGCR13_MUM)
#else
#define BF_EIM_CSGCR13_MUM(v)   (((v) << 3) & BM_EIM_CSGCR13_MUM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUM field to a new value.
#define BW_EIM_CSGCR13_MUM(v)   BF_CS1(EIM_CSGCR13, MUM, v)
#endif


/* --- Register HW_EIM_CSGCR13, field WFL[4:4] (RW)
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

#define BP_EIM_CSGCR13_WFL      (4)
#define BM_EIM_CSGCR13_WFL      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_WFL(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR13_WFL)
#else
#define BF_EIM_CSGCR13_WFL(v)   (((v) << 4) & BM_EIM_CSGCR13_WFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WFL field to a new value.
#define BW_EIM_CSGCR13_WFL(v)   BF_CS1(EIM_CSGCR13, WFL, v)
#endif


/* --- Register HW_EIM_CSGCR13, field RFL[5:5] (RW)
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

#define BP_EIM_CSGCR13_RFL      (5)
#define BM_EIM_CSGCR13_RFL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_RFL(v)   ((((reg32_t) v) << 5) & BM_EIM_CSGCR13_RFL)
#else
#define BF_EIM_CSGCR13_RFL(v)   (((v) << 5) & BM_EIM_CSGCR13_RFL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RFL field to a new value.
#define BW_EIM_CSGCR13_RFL(v)   BF_CS1(EIM_CSGCR13, RFL, v)
#endif


/* --- Register HW_EIM_CSGCR13, field CRE[6:6] (RW)
 *
 * Configuration Register Enable. This bit indicates CRE memory pin state while executing a memory
 * register set command to PSRAM external device. CRE is cleared by a hardware reset.
 *
 * Values:
 * 0 - CRE signal use is disable
 * 1 - CRE signal use is enable
 */

#define BP_EIM_CSGCR13_CRE      (6)
#define BM_EIM_CSGCR13_CRE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_CRE(v)   ((((reg32_t) v) << 6) & BM_EIM_CSGCR13_CRE)
#else
#define BF_EIM_CSGCR13_CRE(v)   (((v) << 6) & BM_EIM_CSGCR13_CRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRE field to a new value.
#define BW_EIM_CSGCR13_CRE(v)   BF_CS1(EIM_CSGCR13, CRE, v)
#endif


/* --- Register HW_EIM_CSGCR13, field CREP[7:7] (RW)
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

#define BP_EIM_CSGCR13_CREP      (7)
#define BM_EIM_CSGCR13_CREP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_CREP(v)   ((((reg32_t) v) << 7) & BM_EIM_CSGCR13_CREP)
#else
#define BF_EIM_CSGCR13_CREP(v)   (((v) << 7) & BM_EIM_CSGCR13_CREP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CREP field to a new value.
#define BW_EIM_CSGCR13_CREP(v)   BF_CS1(EIM_CSGCR13, CREP, v)
#endif


/* --- Register HW_EIM_CSGCR13, field BL[10:8] (RW)
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

#define BP_EIM_CSGCR13_BL      (8)
#define BM_EIM_CSGCR13_BL      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_BL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR13_BL)
#else
#define BF_EIM_CSGCR13_BL(v)   (((v) << 8) & BM_EIM_CSGCR13_BL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BL field to a new value.
#define BW_EIM_CSGCR13_BL(v)   BF_CS1(EIM_CSGCR13, BL, v)
#endif


/* --- Register HW_EIM_CSGCR13, field WC[11:11] (RW)
 *
 * Write Continuous. The WI bit indicates that write access to the memory are always continuous
 * accesses regardless of the BL field value. WI is cleared by hardware reset.
 *
 * Values:
 * 0 - Write access burst length occurs according to BL value.
 * 1 - Write access burst length is continuous.
 */

#define BP_EIM_CSGCR13_WC      (11)
#define BM_EIM_CSGCR13_WC      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_WC(v)   ((((reg32_t) v) << 11) & BM_EIM_CSGCR13_WC)
#else
#define BF_EIM_CSGCR13_WC(v)   (((v) << 11) & BM_EIM_CSGCR13_WC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WC field to a new value.
#define BW_EIM_CSGCR13_WC(v)   BF_CS1(EIM_CSGCR13, WC, v)
#endif


/* --- Register HW_EIM_CSGCR13, field BCD[13:12] (RW)
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

#define BP_EIM_CSGCR13_BCD      (12)
#define BM_EIM_CSGCR13_BCD      (0x00003000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_BCD(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR13_BCD)
#else
#define BF_EIM_CSGCR13_BCD(v)   (((v) << 12) & BM_EIM_CSGCR13_BCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCD field to a new value.
#define BW_EIM_CSGCR13_BCD(v)   BF_CS1(EIM_CSGCR13, BCD, v)
#endif


/* --- Register HW_EIM_CSGCR13, field BCS[15:14] (RW)
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

#define BP_EIM_CSGCR13_BCS      (14)
#define BM_EIM_CSGCR13_BCS      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_BCS(v)   ((((reg32_t) v) << 14) & BM_EIM_CSGCR13_BCS)
#else
#define BF_EIM_CSGCR13_BCS(v)   (((v) << 14) & BM_EIM_CSGCR13_BCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCS field to a new value.
#define BW_EIM_CSGCR13_BCS(v)   BF_CS1(EIM_CSGCR13, BCS, v)
#endif


/* --- Register HW_EIM_CSGCR13, field DSZ[18:16] (RW)
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

#define BP_EIM_CSGCR13_DSZ      (16)
#define BM_EIM_CSGCR13_DSZ      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_DSZ(v)   ((((reg32_t) v) << 16) & BM_EIM_CSGCR13_DSZ)
#else
#define BF_EIM_CSGCR13_DSZ(v)   (((v) << 16) & BM_EIM_CSGCR13_DSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DSZ field to a new value.
#define BW_EIM_CSGCR13_DSZ(v)   BF_CS1(EIM_CSGCR13, DSZ, v)
#endif


/* --- Register HW_EIM_CSGCR13, field SP[19:19] (RW)
 *
 * Supervisor Protect. This bit prevents accesses to the address range defined by the corresponding
 * chip select when the access is attempted in the User mode. SP is cleared by a hardware reset.
 *
 * Values:
 * 0 - User mode accesses are allowed in the memory range defined by chip select.
 * 1 - User mode accesses are prohibited. All attempts to access an address mapped by this chip select in
 *     User mode results in an error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR13_SP      (19)
#define BM_EIM_CSGCR13_SP      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_SP(v)   ((((reg32_t) v) << 19) & BM_EIM_CSGCR13_SP)
#else
#define BF_EIM_CSGCR13_SP(v)   (((v) << 19) & BM_EIM_CSGCR13_SP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SP field to a new value.
#define BW_EIM_CSGCR13_SP(v)   BF_CS1(EIM_CSGCR13, SP, v)
#endif


/* --- Register HW_EIM_CSGCR13, field CSREC[22:20] (RW)
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

#define BP_EIM_CSGCR13_CSREC      (20)
#define BM_EIM_CSGCR13_CSREC      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_CSREC(v)   ((((reg32_t) v) << 20) & BM_EIM_CSGCR13_CSREC)
#else
#define BF_EIM_CSGCR13_CSREC(v)   (((v) << 20) & BM_EIM_CSGCR13_CSREC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSREC field to a new value.
#define BW_EIM_CSGCR13_CSREC(v)   BF_CS1(EIM_CSGCR13, CSREC, v)
#endif


/* --- Register HW_EIM_CSGCR13, field AUS[23:23] (RW)
 *
 * Address UnShifted. This bit indicates an unshifted mode for address assertion for the relevant
 * chip select accesses. AUS bit is cleared by hardware reset. The reset value for EIM_CS0GCR1[AUS]
 * = EIM_BOOT[10]. For EIM_CS1GCR1 - EIM_CS5GCR1, the reset value of AUS is 0.
 *
 * Values:
 * 0 - Address shifted according to port size (DSZ config.)
 * 1 - Address unshifted
 */

#define BP_EIM_CSGCR13_AUS      (23)
#define BM_EIM_CSGCR13_AUS      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_AUS(v)   ((((reg32_t) v) << 23) & BM_EIM_CSGCR13_AUS)
#else
#define BF_EIM_CSGCR13_AUS(v)   (((v) << 23) & BM_EIM_CSGCR13_AUS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AUS field to a new value.
#define BW_EIM_CSGCR13_AUS(v)   BF_CS1(EIM_CSGCR13, AUS, v)
#endif


/* --- Register HW_EIM_CSGCR13, field GBC[26:24] (RW)
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

#define BP_EIM_CSGCR13_GBC      (24)
#define BM_EIM_CSGCR13_GBC      (0x07000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_GBC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSGCR13_GBC)
#else
#define BF_EIM_CSGCR13_GBC(v)   (((v) << 24) & BM_EIM_CSGCR13_GBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBC field to a new value.
#define BW_EIM_CSGCR13_GBC(v)   BF_CS1(EIM_CSGCR13, GBC, v)
#endif


/* --- Register HW_EIM_CSGCR13, field WP[27:27] (RW)
 *
 * Write Protect. This bit prevents writes to the address range defined by the corresponding chip
 * select. WP is cleared by a hardware reset.
 *
 * Values:
 * 0 - Writes are allowed in the memory range defined by chip.
 * 1 - Writes are prohibited. All attempts to write to an address mapped by this chip select result in a
 *     error response and no assertion of the chip select output.
 */

#define BP_EIM_CSGCR13_WP      (27)
#define BM_EIM_CSGCR13_WP      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_WP(v)   ((((reg32_t) v) << 27) & BM_EIM_CSGCR13_WP)
#else
#define BF_EIM_CSGCR13_WP(v)   (((v) << 27) & BM_EIM_CSGCR13_WP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WP field to a new value.
#define BW_EIM_CSGCR13_WP(v)   BF_CS1(EIM_CSGCR13, WP, v)
#endif


/* --- Register HW_EIM_CSGCR13, field PSZ[31:28] (RW)
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

#define BP_EIM_CSGCR13_PSZ      (28)
#define BM_EIM_CSGCR13_PSZ      (0xf0000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR13_PSZ(v)   ((((reg32_t) v) << 28) & BM_EIM_CSGCR13_PSZ)
#else
#define BF_EIM_CSGCR13_PSZ(v)   (((v) << 28) & BM_EIM_CSGCR13_PSZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSZ field to a new value.
#define BW_EIM_CSGCR13_PSZ(v)   BF_CS1(EIM_CSGCR13, PSZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSGCR23 - Chip Select n General Configuration Register 2 3 (RW)
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
} hw_eim_csgcr23_t;
#endif

/*
 * constants & macros for entire EIM_CSGCR23 register
 */
#define HW_EIM_CSGCR23_ADDR      (REGS_EIM_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSGCR23           (*(volatile hw_eim_csgcr23_t *) HW_EIM_CSGCR23_ADDR)
#define HW_EIM_CSGCR23_RD()      (HW_EIM_CSGCR23.U)
#define HW_EIM_CSGCR23_WR(v)     (HW_EIM_CSGCR23.U = (v))
#define HW_EIM_CSGCR23_SET(v)    (HW_EIM_CSGCR23_WR(HW_EIM_CSGCR23_RD() |  (v)))
#define HW_EIM_CSGCR23_CLR(v)    (HW_EIM_CSGCR23_WR(HW_EIM_CSGCR23_RD() & ~(v)))
#define HW_EIM_CSGCR23_TOG(v)    (HW_EIM_CSGCR23_WR(HW_EIM_CSGCR23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSGCR23 bitfields
 */

/* --- Register HW_EIM_CSGCR23, field ADH[1:0] (RW)
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

#define BP_EIM_CSGCR23_ADH      (0)
#define BM_EIM_CSGCR23_ADH      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR23_ADH(v)   ((((reg32_t) v) << 0) & BM_EIM_CSGCR23_ADH)
#else
#define BF_EIM_CSGCR23_ADH(v)   (((v) << 0) & BM_EIM_CSGCR23_ADH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADH field to a new value.
#define BW_EIM_CSGCR23_ADH(v)   BF_CS1(EIM_CSGCR23, ADH, v)
#endif


/* --- Register HW_EIM_CSGCR23, field DAPS[7:4] (RW)
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

#define BP_EIM_CSGCR23_DAPS      (4)
#define BM_EIM_CSGCR23_DAPS      (0x000000f0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR23_DAPS(v)   ((((reg32_t) v) << 4) & BM_EIM_CSGCR23_DAPS)
#else
#define BF_EIM_CSGCR23_DAPS(v)   (((v) << 4) & BM_EIM_CSGCR23_DAPS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAPS field to a new value.
#define BW_EIM_CSGCR23_DAPS(v)   BF_CS1(EIM_CSGCR23, DAPS, v)
#endif


/* --- Register HW_EIM_CSGCR23, field DAE[8:8] (RW)
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

#define BP_EIM_CSGCR23_DAE      (8)
#define BM_EIM_CSGCR23_DAE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR23_DAE(v)   ((((reg32_t) v) << 8) & BM_EIM_CSGCR23_DAE)
#else
#define BF_EIM_CSGCR23_DAE(v)   (((v) << 8) & BM_EIM_CSGCR23_DAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAE field to a new value.
#define BW_EIM_CSGCR23_DAE(v)   BF_CS1(EIM_CSGCR23, DAE, v)
#endif


/* --- Register HW_EIM_CSGCR23, field DAP[9:9] (RW)
 *
 * Data Acknowledge Polarity. This bit indicates DTACK memory pin assertion state, active-low or
 * active-high, while executing an async access using DTACK signal from the external device. DAP is
 * cleared by a hardware reset.
 *
 * Values:
 * 0 - DTACK signal is active high
 * 1 - DTACK signal is active low
 */

#define BP_EIM_CSGCR23_DAP      (9)
#define BM_EIM_CSGCR23_DAP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR23_DAP(v)   ((((reg32_t) v) << 9) & BM_EIM_CSGCR23_DAP)
#else
#define BF_EIM_CSGCR23_DAP(v)   (((v) << 9) & BM_EIM_CSGCR23_DAP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DAP field to a new value.
#define BW_EIM_CSGCR23_DAP(v)   BF_CS1(EIM_CSGCR23, DAP, v)
#endif


/* --- Register HW_EIM_CSGCR23, field MUX16_BYP_GRANT[12:12] (RW)
 *
 * Muxed 16 bypass grant. This bit when asserted causes EIM to bypass the grant/ack. arbitration
 * with NFC (only for 16 bit muxed mode accesses). The reset value for EIM_CS0GCR2[MUX16_BYP_GRANT]
 * = EIM_BOOT[12]. For EIM_CS1GCR2 - EIM_CS5GCR2, MUX16_BYP_GRANT reset value is 1.
 *
 * Values:
 * 0 - EIM waits for grant before driving a 16 bit muxed mode access to the memory.
 * 1 - EIM ignores the grant signal and immediately drives a 16 bit muxed mode access to the memory.
 */

#define BP_EIM_CSGCR23_MUX16_BYP_GRANT      (12)
#define BM_EIM_CSGCR23_MUX16_BYP_GRANT      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSGCR23_MUX16_BYP_GRANT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSGCR23_MUX16_BYP_GRANT)
#else
#define BF_EIM_CSGCR23_MUX16_BYP_GRANT(v)   (((v) << 12) & BM_EIM_CSGCR23_MUX16_BYP_GRANT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MUX16_BYP_GRANT field to a new value.
#define BW_EIM_CSGCR23_MUX16_BYP_GRANT(v)   BF_CS1(EIM_CSGCR23, MUX16_BYP_GRANT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR13 - Chip Select n Read Configuration Register 1 3 (RW)
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
} hw_eim_csrcr13_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR13 register
 */
#define HW_EIM_CSRCR13_ADDR      (REGS_EIM_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR13           (*(volatile hw_eim_csrcr13_t *) HW_EIM_CSRCR13_ADDR)
#define HW_EIM_CSRCR13_RD()      (HW_EIM_CSRCR13.U)
#define HW_EIM_CSRCR13_WR(v)     (HW_EIM_CSRCR13.U = (v))
#define HW_EIM_CSRCR13_SET(v)    (HW_EIM_CSRCR13_WR(HW_EIM_CSRCR13_RD() |  (v)))
#define HW_EIM_CSRCR13_CLR(v)    (HW_EIM_CSRCR13_WR(HW_EIM_CSRCR13_RD() & ~(v)))
#define HW_EIM_CSRCR13_TOG(v)    (HW_EIM_CSRCR13_WR(HW_EIM_CSRCR13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR13 bitfields
 */

/* --- Register HW_EIM_CSRCR13, field RCSN[2:0] (RW)
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

#define BP_EIM_CSRCR13_RCSN      (0)
#define BM_EIM_CSRCR13_RCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_RCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR13_RCSN)
#else
#define BF_EIM_CSRCR13_RCSN(v)   (((v) << 0) & BM_EIM_CSRCR13_RCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSN field to a new value.
#define BW_EIM_CSRCR13_RCSN(v)   BF_CS1(EIM_CSRCR13, RCSN, v)
#endif


/* --- Register HW_EIM_CSRCR13, field RCSA[6:4] (RW)
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

#define BP_EIM_CSRCR13_RCSA      (4)
#define BM_EIM_CSRCR13_RCSA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_RCSA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR13_RCSA)
#else
#define BF_EIM_CSRCR13_RCSA(v)   (((v) << 4) & BM_EIM_CSRCR13_RCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCSA field to a new value.
#define BW_EIM_CSRCR13_RCSA(v)   BF_CS1(EIM_CSRCR13, RCSA, v)
#endif


/* --- Register HW_EIM_CSRCR13, field OEN[10:8] (RW)
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

#define BP_EIM_CSRCR13_OEN      (8)
#define BM_EIM_CSRCR13_OEN      (0x00000700)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_OEN(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR13_OEN)
#else
#define BF_EIM_CSRCR13_OEN(v)   (((v) << 8) & BM_EIM_CSRCR13_OEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEN field to a new value.
#define BW_EIM_CSRCR13_OEN(v)   BF_CS1(EIM_CSRCR13, OEN, v)
#endif


/* --- Register HW_EIM_CSRCR13, field OEA[14:12] (RW)
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

#define BP_EIM_CSRCR13_OEA      (12)
#define BM_EIM_CSRCR13_OEA      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_OEA(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR13_OEA)
#else
#define BF_EIM_CSRCR13_OEA(v)   (((v) << 12) & BM_EIM_CSRCR13_OEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OEA field to a new value.
#define BW_EIM_CSRCR13_OEA(v)   BF_CS1(EIM_CSRCR13, OEA, v)
#endif


/* --- Register HW_EIM_CSRCR13, field RADVN[18:16] (RW)
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

#define BP_EIM_CSRCR13_RADVN      (16)
#define BM_EIM_CSRCR13_RADVN      (0x00070000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_RADVN(v)   ((((reg32_t) v) << 16) & BM_EIM_CSRCR13_RADVN)
#else
#define BF_EIM_CSRCR13_RADVN(v)   (((v) << 16) & BM_EIM_CSRCR13_RADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVN field to a new value.
#define BW_EIM_CSRCR13_RADVN(v)   BF_CS1(EIM_CSRCR13, RADVN, v)
#endif

/* --- Register HW_EIM_CSRCR13, field RAL[19:19] (RW)
 *
 * Read ADV Low. This bit field determine ADV signal negation time. When RAL=1, RADVN bit field is
 * ignored and ADV signal will stay asserted until end of access. When RAL=0 negation of ADV signal
 * is according to RADVN bit field configuration. The reset value of EIM_CS0RCR1[RAL] = EIM_BOOT[3].
 * RAL is cleared by a hardware reset for EIM_CS1RCR1 - EIM_CS5RCR1.
 */

#define BP_EIM_CSRCR13_RAL      (19)
#define BM_EIM_CSRCR13_RAL      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_RAL(v)   ((((reg32_t) v) << 19) & BM_EIM_CSRCR13_RAL)
#else
#define BF_EIM_CSRCR13_RAL(v)   (((v) << 19) & BM_EIM_CSRCR13_RAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RAL field to a new value.
#define BW_EIM_CSRCR13_RAL(v)   BF_CS1(EIM_CSRCR13, RAL, v)
#endif

/* --- Register HW_EIM_CSRCR13, field RADVA[22:20] (RW)
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

#define BP_EIM_CSRCR13_RADVA      (20)
#define BM_EIM_CSRCR13_RADVA      (0x00700000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_RADVA(v)   ((((reg32_t) v) << 20) & BM_EIM_CSRCR13_RADVA)
#else
#define BF_EIM_CSRCR13_RADVA(v)   (((v) << 20) & BM_EIM_CSRCR13_RADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RADVA field to a new value.
#define BW_EIM_CSRCR13_RADVA(v)   BF_CS1(EIM_CSRCR13, RADVA, v)
#endif


/* --- Register HW_EIM_CSRCR13, field RWSC[29:24] (RW)
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

#define BP_EIM_CSRCR13_RWSC      (24)
#define BM_EIM_CSRCR13_RWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR13_RWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSRCR13_RWSC)
#else
#define BF_EIM_CSRCR13_RWSC(v)   (((v) << 24) & BM_EIM_CSRCR13_RWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RWSC field to a new value.
#define BW_EIM_CSRCR13_RWSC(v)   BF_CS1(EIM_CSRCR13, RWSC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSRCR23 - Chip Select n Read Configuration Register 2 3 (RW)
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
} hw_eim_csrcr23_t;
#endif

/*
 * constants & macros for entire EIM_CSRCR23 register
 */
#define HW_EIM_CSRCR23_ADDR      (REGS_EIM_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSRCR23           (*(volatile hw_eim_csrcr23_t *) HW_EIM_CSRCR23_ADDR)
#define HW_EIM_CSRCR23_RD()      (HW_EIM_CSRCR23.U)
#define HW_EIM_CSRCR23_WR(v)     (HW_EIM_CSRCR23.U = (v))
#define HW_EIM_CSRCR23_SET(v)    (HW_EIM_CSRCR23_WR(HW_EIM_CSRCR23_RD() |  (v)))
#define HW_EIM_CSRCR23_CLR(v)    (HW_EIM_CSRCR23_WR(HW_EIM_CSRCR23_RD() & ~(v)))
#define HW_EIM_CSRCR23_TOG(v)    (HW_EIM_CSRCR23_WR(HW_EIM_CSRCR23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSRCR23 bitfields
 */

/* --- Register HW_EIM_CSRCR23, field RBEN[2:0] (RW)
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

#define BP_EIM_CSRCR23_RBEN      (0)
#define BM_EIM_CSRCR23_RBEN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR23_RBEN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSRCR23_RBEN)
#else
#define BF_EIM_CSRCR23_RBEN(v)   (((v) << 0) & BM_EIM_CSRCR23_RBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEN field to a new value.
#define BW_EIM_CSRCR23_RBEN(v)   BF_CS1(EIM_CSRCR23, RBEN, v)
#endif


/* --- Register HW_EIM_CSRCR23, field RBE[3:3] (RW)
 *
 * Read BE enable. This bit field determines if BE will be asserted during read access.
 *
 * Values:
 * 0 - - BE are disabled during read access.
 * 1- - BE are enable during read access according to value of RBEA & RBEN bit fields.
 */

#define BP_EIM_CSRCR23_RBE      (3)
#define BM_EIM_CSRCR23_RBE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR23_RBE(v)   ((((reg32_t) v) << 3) & BM_EIM_CSRCR23_RBE)
#else
#define BF_EIM_CSRCR23_RBE(v)   (((v) << 3) & BM_EIM_CSRCR23_RBE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBE field to a new value.
#define BW_EIM_CSRCR23_RBE(v)   BF_CS1(EIM_CSRCR23, RBE, v)
#endif


/* --- Register HW_EIM_CSRCR23, field RBEA[6:4] (RW)
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

#define BP_EIM_CSRCR23_RBEA      (4)
#define BM_EIM_CSRCR23_RBEA      (0x00000070)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR23_RBEA(v)   ((((reg32_t) v) << 4) & BM_EIM_CSRCR23_RBEA)
#else
#define BF_EIM_CSRCR23_RBEA(v)   (((v) << 4) & BM_EIM_CSRCR23_RBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RBEA field to a new value.
#define BW_EIM_CSRCR23_RBEA(v)   BF_CS1(EIM_CSRCR23, RBEA, v)
#endif


/* --- Register HW_EIM_CSRCR23, field RL[9:8] (RW)
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

#define BP_EIM_CSRCR23_RL      (8)
#define BM_EIM_CSRCR23_RL      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR23_RL(v)   ((((reg32_t) v) << 8) & BM_EIM_CSRCR23_RL)
#else
#define BF_EIM_CSRCR23_RL(v)   (((v) << 8) & BM_EIM_CSRCR23_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_EIM_CSRCR23_RL(v)   BF_CS1(EIM_CSRCR23, RL, v)
#endif


/* --- Register HW_EIM_CSRCR23, field PAT[14:12] (RW)
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

#define BP_EIM_CSRCR23_PAT      (12)
#define BM_EIM_CSRCR23_PAT      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR23_PAT(v)   ((((reg32_t) v) << 12) & BM_EIM_CSRCR23_PAT)
#else
#define BF_EIM_CSRCR23_PAT(v)   (((v) << 12) & BM_EIM_CSRCR23_PAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAT field to a new value.
#define BW_EIM_CSRCR23_PAT(v)   BF_CS1(EIM_CSRCR23, PAT, v)
#endif


/* --- Register HW_EIM_CSRCR23, field APR[15:15] (RW)
 *
 * Asynchronous Page Read. This bit field determine the asynchronous read mode to the external
 * device. When APR=0, the async. read access is done as single word (where word is defined by the
 * DSZ field). when APR=1, the async. read access executed as page read. page size is according to
 * BL field config., RCSN,RBEN,OEN and RADVN are being ignored. APR is cleared by a hardware reset
 * for EIM_CS1GCR1 - EIM_CS5GCR1. SRD=0 and MUM=0 must apply when APR=1
 */

#define BP_EIM_CSRCR23_APR      (15)
#define BM_EIM_CSRCR23_APR      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSRCR23_APR(v)   ((((reg32_t) v) << 15) & BM_EIM_CSRCR23_APR)
#else
#define BF_EIM_CSRCR23_APR(v)   (((v) << 15) & BM_EIM_CSRCR23_APR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the APR field to a new value.
#define BW_EIM_CSRCR23_APR(v)   BF_CS1(EIM_CSRCR23, APR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR13 - Chip Select n Write Configuration Register 1 3 (RW)
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
} hw_eim_cswcr13_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR13 register
 */
#define HW_EIM_CSWCR13_ADDR      (REGS_EIM_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR13           (*(volatile hw_eim_cswcr13_t *) HW_EIM_CSWCR13_ADDR)
#define HW_EIM_CSWCR13_RD()      (HW_EIM_CSWCR13.U)
#define HW_EIM_CSWCR13_WR(v)     (HW_EIM_CSWCR13.U = (v))
#define HW_EIM_CSWCR13_SET(v)    (HW_EIM_CSWCR13_WR(HW_EIM_CSWCR13_RD() |  (v)))
#define HW_EIM_CSWCR13_CLR(v)    (HW_EIM_CSWCR13_WR(HW_EIM_CSWCR13_RD() & ~(v)))
#define HW_EIM_CSWCR13_TOG(v)    (HW_EIM_CSWCR13_WR(HW_EIM_CSWCR13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR13 bitfields
 */

/* --- Register HW_EIM_CSWCR13, field WCSN[2:0] (RW)
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

#define BP_EIM_CSWCR13_WCSN      (0)
#define BM_EIM_CSWCR13_WCSN      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WCSN(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR13_WCSN)
#else
#define BF_EIM_CSWCR13_WCSN(v)   (((v) << 0) & BM_EIM_CSWCR13_WCSN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSN field to a new value.
#define BW_EIM_CSWCR13_WCSN(v)   BF_CS1(EIM_CSWCR13, WCSN, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WCSA[5:3] (RW)
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

#define BP_EIM_CSWCR13_WCSA      (3)
#define BM_EIM_CSWCR13_WCSA      (0x00000038)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WCSA(v)   ((((reg32_t) v) << 3) & BM_EIM_CSWCR13_WCSA)
#else
#define BF_EIM_CSWCR13_WCSA(v)   (((v) << 3) & BM_EIM_CSWCR13_WCSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WCSA field to a new value.
#define BW_EIM_CSWCR13_WCSA(v)   BF_CS1(EIM_CSWCR13, WCSA, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WEN[8:6] (RW)
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

#define BP_EIM_CSWCR13_WEN      (6)
#define BM_EIM_CSWCR13_WEN      (0x000001c0)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WEN(v)   ((((reg32_t) v) << 6) & BM_EIM_CSWCR13_WEN)
#else
#define BF_EIM_CSWCR13_WEN(v)   (((v) << 6) & BM_EIM_CSWCR13_WEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEN field to a new value.
#define BW_EIM_CSWCR13_WEN(v)   BF_CS1(EIM_CSWCR13, WEN, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WEA[11:9] (RW)
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

#define BP_EIM_CSWCR13_WEA      (9)
#define BM_EIM_CSWCR13_WEA      (0x00000e00)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WEA(v)   ((((reg32_t) v) << 9) & BM_EIM_CSWCR13_WEA)
#else
#define BF_EIM_CSWCR13_WEA(v)   (((v) << 9) & BM_EIM_CSWCR13_WEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEA field to a new value.
#define BW_EIM_CSWCR13_WEA(v)   BF_CS1(EIM_CSWCR13, WEA, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WBEN[14:12] (RW)
 *
 * BE[3:0] Negation. This bit field determines when BE[3:0] bus signal is negated during write
 * cycles in async. mode only (SWR=0), according to the settings shown below. This bit field is
 * ignored when SWR=1. BEN is cleared by a hardware reset. Reset value for EIM_CS0WCR for WBEN is 2.
 * For EIM_CS1WCR - EIM_CS5WCR reset value is 000. Example settings: 000 0 EIM clock cycles between
 * end of access and WE negation 001 1 EIM clock cycles between end of access and WE negation 010 2
 * EIM clock cycles between end of access and WE negation 111 7 EIM clock cycles between end of
 * access and WE negation
 */

#define BP_EIM_CSWCR13_WBEN      (12)
#define BM_EIM_CSWCR13_WBEN      (0x00007000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WBEN(v)   ((((reg32_t) v) << 12) & BM_EIM_CSWCR13_WBEN)
#else
#define BF_EIM_CSWCR13_WBEN(v)   (((v) << 12) & BM_EIM_CSWCR13_WBEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEN field to a new value.
#define BW_EIM_CSWCR13_WBEN(v)   BF_CS1(EIM_CSWCR13, WBEN, v)
#endif

/* --- Register HW_EIM_CSWCR13, field WBEA[17:15] (RW)
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

#define BP_EIM_CSWCR13_WBEA      (15)
#define BM_EIM_CSWCR13_WBEA      (0x00038000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WBEA(v)   ((((reg32_t) v) << 15) & BM_EIM_CSWCR13_WBEA)
#else
#define BF_EIM_CSWCR13_WBEA(v)   (((v) << 15) & BM_EIM_CSWCR13_WBEA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBEA field to a new value.
#define BW_EIM_CSWCR13_WBEA(v)   BF_CS1(EIM_CSWCR13, WBEA, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WADVN[20:18] (RW)
 *
 * ADV Negation. This bit field determines when ADV signal to memory is negated during write
 * accesses. When SWR=1 (synchronous write mode), ADV negation occurs according to the following
 * formula: (WADVN + WADVA + BCD + BCS + 1) EIM clock cycles. When asynchronous read mode is applied
 * (SWR=0) ADV negation occurs according to the following formula: (WADVN + WADVA + 1) EIM clock
 * cycles. Reset value for EIM_CS0WCR for WADVN is 2. For EIM_CS1WCR - EIM_CS5WCR reset value is
 * 000. This field should be configured so ADV negation will occur before the end of access. For ADV
 * negation at the same time as the end of access, S/W should set the WAL bit.
 */

#define BP_EIM_CSWCR13_WADVN      (18)
#define BM_EIM_CSWCR13_WADVN      (0x001c0000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WADVN(v)   ((((reg32_t) v) << 18) & BM_EIM_CSWCR13_WADVN)
#else
#define BF_EIM_CSWCR13_WADVN(v)   (((v) << 18) & BM_EIM_CSWCR13_WADVN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVN field to a new value.
#define BW_EIM_CSWCR13_WADVN(v)   BF_CS1(EIM_CSWCR13, WADVN, v)
#endif

/* --- Register HW_EIM_CSWCR13, field WADVA[23:21] (RW)
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

#define BP_EIM_CSWCR13_WADVA      (21)
#define BM_EIM_CSWCR13_WADVA      (0x00e00000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WADVA(v)   ((((reg32_t) v) << 21) & BM_EIM_CSWCR13_WADVA)
#else
#define BF_EIM_CSWCR13_WADVA(v)   (((v) << 21) & BM_EIM_CSWCR13_WADVA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WADVA field to a new value.
#define BW_EIM_CSWCR13_WADVA(v)   BF_CS1(EIM_CSWCR13, WADVA, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WWSC[29:24] (RW)
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

#define BP_EIM_CSWCR13_WWSC      (24)
#define BM_EIM_CSWCR13_WWSC      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WWSC(v)   ((((reg32_t) v) << 24) & BM_EIM_CSWCR13_WWSC)
#else
#define BF_EIM_CSWCR13_WWSC(v)   (((v) << 24) & BM_EIM_CSWCR13_WWSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WWSC field to a new value.
#define BW_EIM_CSWCR13_WWSC(v)   BF_CS1(EIM_CSWCR13, WWSC, v)
#endif


/* --- Register HW_EIM_CSWCR13, field WBED[30:30] (RW)
 *
 * Write Byte Enable Disable. When asserted this bit prevent from IPP_DO_BE_B[x] to be asserted
 * during write accesses.This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR13_WBED      (30)
#define BM_EIM_CSWCR13_WBED      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WBED(v)   ((((reg32_t) v) << 30) & BM_EIM_CSWCR13_WBED)
#else
#define BF_EIM_CSWCR13_WBED(v)   (((v) << 30) & BM_EIM_CSWCR13_WBED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBED field to a new value.
#define BW_EIM_CSWCR13_WBED(v)   BF_CS1(EIM_CSWCR13, WBED, v)
#endif

/* --- Register HW_EIM_CSWCR13, field WAL[31:31] (RW)
 *
 * Write ADV Low. This bit field determine ADV signal negation time in write accesses. When WAL=1,
 * WADVN bit field is ignored and ADV signal will stay asserted until end of access. When WAL=0
 * negation of ADV signal is according to WADVN bit field configuration. The reset value of
 * CS0WCR1[WAL] = EIM_BOOT[3]. This field is cleared by a hardware reset for CS1WCR1 - CS5WCR1.
 */

#define BP_EIM_CSWCR13_WAL      (31)
#define BM_EIM_CSWCR13_WAL      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR13_WAL(v)   ((((reg32_t) v) << 31) & BM_EIM_CSWCR13_WAL)
#else
#define BF_EIM_CSWCR13_WAL(v)   (((v) << 31) & BM_EIM_CSWCR13_WAL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WAL field to a new value.
#define BW_EIM_CSWCR13_WAL(v)   BF_CS1(EIM_CSWCR13, WAL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_EIM_CSWCR23 - Chip Select n Write Configuration Register 2 3 (RW)
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
} hw_eim_cswcr23_t;
#endif

/*
 * constants & macros for entire EIM_CSWCR23 register
 */
#define HW_EIM_CSWCR23_ADDR      (REGS_EIM_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_EIM_CSWCR23           (*(volatile hw_eim_cswcr23_t *) HW_EIM_CSWCR23_ADDR)
#define HW_EIM_CSWCR23_RD()      (HW_EIM_CSWCR23.U)
#define HW_EIM_CSWCR23_WR(v)     (HW_EIM_CSWCR23.U = (v))
#define HW_EIM_CSWCR23_SET(v)    (HW_EIM_CSWCR23_WR(HW_EIM_CSWCR23_RD() |  (v)))
#define HW_EIM_CSWCR23_CLR(v)    (HW_EIM_CSWCR23_WR(HW_EIM_CSWCR23_RD() & ~(v)))
#define HW_EIM_CSWCR23_TOG(v)    (HW_EIM_CSWCR23_WR(HW_EIM_CSWCR23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual EIM_CSWCR23 bitfields
 */

/* --- Register HW_EIM_CSWCR23, field WBCDD[0:0] (RW)
 *
 * Write Burst Clock Divisor Decrement. If this bit is asserted and BCD value is 0 sync. write
 * access will be preformed as if BCD value is 1.When this bit is negated or BCD value is not 0 this
 * bit has no affect. This bit is cleared by hardware reset.
 */

#define BP_EIM_CSWCR23_WBCDD      (0)
#define BM_EIM_CSWCR23_WBCDD      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_CSWCR23_WBCDD(v)   ((((reg32_t) v) << 0) & BM_EIM_CSWCR23_WBCDD)
#else
#define BF_EIM_CSWCR23_WBCDD(v)   (((v) << 0) & BM_EIM_CSWCR23_WBCDD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WBCDD field to a new value.
#define BW_EIM_CSWCR23_WBCDD(v)   BF_CS1(EIM_CSWCR23, WBCDD, v)
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

/* --- Register HW_EIM_WCR, field BCM[0:0] (RW)
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

#define BP_EIM_WCR_BCM      (0)
#define BM_EIM_WCR_BCM      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_BCM(v)   ((((reg32_t) v) << 0) & BM_EIM_WCR_BCM)
#else
#define BF_EIM_WCR_BCM(v)   (((v) << 0) & BM_EIM_WCR_BCM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BCM field to a new value.
#define BW_EIM_WCR_BCM(v)   BF_CS1(EIM_WCR, BCM, v)
#endif


/* --- Register HW_EIM_WCR, field GBCD[2:1] (RW)
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

#define BP_EIM_WCR_GBCD      (1)
#define BM_EIM_WCR_GBCD      (0x00000006)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_GBCD(v)   ((((reg32_t) v) << 1) & BM_EIM_WCR_GBCD)
#else
#define BF_EIM_WCR_GBCD(v)   (((v) << 1) & BM_EIM_WCR_GBCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GBCD field to a new value.
#define BW_EIM_WCR_GBCD(v)   BF_CS1(EIM_WCR, GBCD, v)
#endif


/* --- Register HW_EIM_WCR, field INTEN[4:4] (RW)
 *
 * Interrupt Enable. When this bit is set the External signal RDY_INT as active interrupt. When
 * interrupt occurs, INT bit at the WCR will be set and t EIM_EXT_INT signal will be asserted
 * correspondingly. This bit is cleared by a hardware reset.
 *
 * Values:
 * 0 - External interrupt Disable
 * 1 - External interrupt Enable
 */

#define BP_EIM_WCR_INTEN      (4)
#define BM_EIM_WCR_INTEN      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTEN(v)   ((((reg32_t) v) << 4) & BM_EIM_WCR_INTEN)
#else
#define BF_EIM_WCR_INTEN(v)   (((v) << 4) & BM_EIM_WCR_INTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTEN field to a new value.
#define BW_EIM_WCR_INTEN(v)   BF_CS1(EIM_WCR, INTEN, v)
#endif


/* --- Register HW_EIM_WCR, field INTPOL[5:5] (RW)
 *
 * Interrupt Polarity. This bit field determines the polarity of the external device interrupt.
 *
 * Values:
 * 0 - External interrupt polarity is active low
 * 1 - External interrupt polarity is active high
 */

#define BP_EIM_WCR_INTPOL      (5)
#define BM_EIM_WCR_INTPOL      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTPOL(v)   ((((reg32_t) v) << 5) & BM_EIM_WCR_INTPOL)
#else
#define BF_EIM_WCR_INTPOL(v)   (((v) << 5) & BM_EIM_WCR_INTPOL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INTPOL field to a new value.
#define BW_EIM_WCR_INTPOL(v)   BF_CS1(EIM_WCR, INTPOL, v)
#endif


/* --- Register HW_EIM_WCR, field WDOG_EN[8:8] (RW)
 *
 * Memory WDog enable. This bit controls the operation of the wdog counter that terminates the EIM
 * access.
 *
 * Values:
 * 0 - Memory WDog is Disabled
 * 1 - Memory WDog is Enabled
 */

#define BP_EIM_WCR_WDOG_EN      (8)
#define BM_EIM_WCR_WDOG_EN      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_EN(v)   ((((reg32_t) v) << 8) & BM_EIM_WCR_WDOG_EN)
#else
#define BF_EIM_WCR_WDOG_EN(v)   (((v) << 8) & BM_EIM_WCR_WDOG_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WDOG_EN field to a new value.
#define BW_EIM_WCR_WDOG_EN(v)   BF_CS1(EIM_WCR, WDOG_EN, v)
#endif


/* --- Register HW_EIM_WCR, field WDOG_LIMIT[10:9] (RW)
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

#define BP_EIM_WCR_WDOG_LIMIT      (9)
#define BM_EIM_WCR_WDOG_LIMIT      (0x00000600)

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

/* --- Register HW_EIM_WIAR, field IPS_REQ[0:0] (RW)
 *
 * IPS request. The Master requests to access one of the IPS registers. During such access the EIM
 * should not perform any AXI/memory accesses. The EIM finishes the AXI accesses that already starts
 * and asserts the IPS_ACK bit.
 *
 * Values:
 * 0 - No Master requests ips access
 * 1 - Master requests ips access
 */

#define BP_EIM_WIAR_IPS_REQ      (0)
#define BM_EIM_WIAR_IPS_REQ      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_REQ(v)   ((((reg32_t) v) << 0) & BM_EIM_WIAR_IPS_REQ)
#else
#define BF_EIM_WIAR_IPS_REQ(v)   (((v) << 0) & BM_EIM_WIAR_IPS_REQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IPS_REQ field to a new value.
#define BW_EIM_WIAR_IPS_REQ(v)   BF_CS1(EIM_WIAR, IPS_REQ, v)
#endif


/* --- Register HW_EIM_WIAR, field IPS_ACK[1:1] (RW)
 *
 * IPS ACK. The EIM is ready for ips access. There is no active AXI access and no new AXI access is
 * accepted till this bit is cleared. This bit is cleared by the master after it completes the ips
 * accesses.
 *
 * Values:
 * 0 - Master cannot access ips.
 * 1 - Master can access ips.
 */

#define BP_EIM_WIAR_IPS_ACK      (1)
#define BM_EIM_WIAR_IPS_ACK      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_ACK(v)   ((((reg32_t) v) << 1) & BM_EIM_WIAR_IPS_ACK)
#else
#define BF_EIM_WIAR_IPS_ACK(v)   (((v) << 1) & BM_EIM_WIAR_IPS_ACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IPS_ACK field to a new value.
#define BW_EIM_WIAR_IPS_ACK(v)   BF_CS1(EIM_WIAR, IPS_ACK, v)
#endif


/* --- Register HW_EIM_WIAR, field INT[2:2] (RW)
 *
 * Interrupt. This bit indicates interrupt assertion by an external device according to RDY_INT
 * signal. When polling this bit, INT=0 indicates interrupt not occurred and INT=1 indicates
 * assertion of the external device interrupt. This bit is cleared by a hardware reset.
 */

#define BP_EIM_WIAR_INT      (2)
#define BM_EIM_WIAR_INT      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_INT(v)   ((((reg32_t) v) << 2) & BM_EIM_WIAR_INT)
#else
#define BF_EIM_WIAR_INT(v)   (((v) << 2) & BM_EIM_WIAR_INT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INT field to a new value.
#define BW_EIM_WIAR_INT(v)   BF_CS1(EIM_WIAR, INT, v)
#endif

/* --- Register HW_EIM_WIAR, field ERRST[3:3] (RW)
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

#define BP_EIM_WIAR_ERRST      (3)
#define BM_EIM_WIAR_ERRST      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ERRST(v)   ((((reg32_t) v) << 3) & BM_EIM_WIAR_ERRST)
#else
#define BF_EIM_WIAR_ERRST(v)   (((v) << 3) & BM_EIM_WIAR_ERRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERRST field to a new value.
#define BW_EIM_WIAR_ERRST(v)   BF_CS1(EIM_WIAR, ERRST, v)
#endif


/* --- Register HW_EIM_WIAR, field ACLK_EN[4:4] (RW)
 *
 * ACLK enable. This bit gates the ACLK for the EIM except from FFs that get ipg_aclk_s. After reset
 * ACLK is enabled.
 *
 * Values:
 * 0 - ACLK is disabled
 * 1 - ACLK is enabled
 */

#define BP_EIM_WIAR_ACLK_EN      (4)
#define BM_EIM_WIAR_ACLK_EN      (0x00000010)

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
        unsigned ERROR_ADDR : 32; //!< Error Address. This bit field holds the AXI address of the last access that caused error. This register is read only register.
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

/* --- Register HW_EIM_EAR, field ERROR_ADDR[31:0] (RW)
 *
 * Error Address. This bit field holds the AXI address of the last access that caused error. This
 * register is read only register.
 */

#define BP_EIM_EAR_ERROR_ADDR      (0)
#define BM_EIM_EAR_ERROR_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_EIM_EAR_ERROR_ADDR(v)   ((((reg32_t) v) << 0) & BM_EIM_EAR_ERROR_ADDR)
#else
#define BF_EIM_EAR_ERROR_ADDR(v)   (((v) << 0) & BM_EIM_EAR_ERROR_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_ADDR field to a new value.
#define BW_EIM_EAR_ERROR_ADDR(v)   BF_CS1(EIM_EAR, ERROR_ADDR, v)
#endif


/*!
 * @brief All EIM module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_eim_csgcr10_t CSGCR10; //!< Chip Select n General Configuration Register 1 0
    volatile hw_eim_csgcr20_t CSGCR20; //!< Chip Select n General Configuration Register 2 0
    volatile hw_eim_csrcr10_t CSRCR10; //!< Chip Select n Read Configuration Register 1 0
    volatile hw_eim_csrcr20_t CSRCR20; //!< Chip Select n Read Configuration Register 2 0
    volatile hw_eim_cswcr10_t CSWCR10; //!< Chip Select n Write Configuration Register 1 0
    volatile hw_eim_cswcr20_t CSWCR20; //!< Chip Select n Write Configuration Register 2 0
    volatile hw_eim_csgcr11_t CSGCR11; //!< Chip Select n General Configuration Register 1 1
    volatile hw_eim_csgcr21_t CSGCR21; //!< Chip Select n General Configuration Register 2 1
    volatile hw_eim_csrcr11_t CSRCR11; //!< Chip Select n Read Configuration Register 1 1
    volatile hw_eim_csrcr21_t CSRCR21; //!< Chip Select n Read Configuration Register 2 1
    volatile hw_eim_cswcr11_t CSWCR11; //!< Chip Select n Write Configuration Register 1 1
    volatile hw_eim_cswcr21_t CSWCR21; //!< Chip Select n Write Configuration Register 2 1
    volatile hw_eim_csgcr12_t CSGCR12; //!< Chip Select n General Configuration Register 1 2
    volatile hw_eim_csgcr22_t CSGCR22; //!< Chip Select n General Configuration Register 2 2
    volatile hw_eim_csrcr12_t CSRCR12; //!< Chip Select n Read Configuration Register 1 2
    volatile hw_eim_csrcr22_t CSRCR22; //!< Chip Select n Read Configuration Register 2 2
    volatile hw_eim_cswcr12_t CSWCR12; //!< Chip Select n Write Configuration Register 1 2
    volatile hw_eim_cswcr22_t CSWCR22; //!< Chip Select n Write Configuration Register 2 2
    volatile hw_eim_csgcr13_t CSGCR13; //!< Chip Select n General Configuration Register 1 3
    volatile hw_eim_csgcr23_t CSGCR23; //!< Chip Select n General Configuration Register 2 3
    volatile hw_eim_csrcr13_t CSRCR13; //!< Chip Select n Read Configuration Register 1 3
    volatile hw_eim_csrcr23_t CSRCR23; //!< Chip Select n Read Configuration Register 2 3
    volatile hw_eim_cswcr13_t CSWCR13; //!< Chip Select n Write Configuration Register 1 3
    volatile hw_eim_cswcr23_t CSWCR23; //!< Chip Select n Write Configuration Register 2 3
    reg32_t _reserved0[12];
    volatile hw_eim_wcr_t WCR; //!< EIM Configuration Register
    volatile hw_eim_wiar_t WIAR; //!< EIM IP Access Register
    volatile hw_eim_ear_t EAR; //!< Error Address Register
} hw_eim_t;
#endif

//! @brief Macro to access all EIM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_EIM(0)</code>.
#define HW_EIM     (*(volatile hw_eim_t *) REGS_EIM_BASE)


#endif // _EIM_H
