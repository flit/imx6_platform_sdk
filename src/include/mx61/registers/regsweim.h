/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _EIM_H
#define _EIM_H

#include "regs.h"

#ifndef REGS_EIM_BASE
#define REGS_EIM_BASE (REGS_BASE + 0x021b8000)
#endif


/*!
 * @brief HW_EIM_WCR - EIM Configuration Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BCM : 1; //!< Burst Clock Mode. This bit selects the burst clock mode of operation. It is used for system debug mode.  BCM is cleared by a hardware reset.  The BCLK frequency in this mode is according to GBCD bit field.  The BCLK phase is opposite to the EIM clock in this mode if GBCD is 0.  This bit should be used only in async. accesses. No sync access can be executed if this bit is set.  When this bit is set bcd field shouldn't be configured to 0.
        unsigned GBCD : 2; //!< General Burst Clock Divisor. When BCM bit is set, this bit field contains the value used to program the burst clock divisor for Continuous BCLK generation. The other BCD bit fields for each chip select are ignored. It is used to divide the internal AXI bus frequency. When BCM=0 GBCD bit field has no influence. GBCD is cleared by a hardware reset.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned INTEN : 1; //!< Interrupt Enable. When this bit is set the External signal RDY_INT as active interrupt. When interrupt occurs, INT bit at the WCR will be set and t EIM_EXT_INT signal will be asserted correspondingly. This bit is cleared by a hardware reset.
        unsigned INTPOL : 1; //!< Interrupt Polarity. This bit field determines the polarity of the external device interrupt.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned WDOG_EN : 1; //!< Memory WDog enable.  This bit controls the operation of the wdog counter that terminates the EIM access.
        unsigned WDOG_LIMIT : 2; //!< Memory Watch Dog (WDog) cycle limit.  This bit field determines the number of BCLK cycles (ACLK cycles in dtack mode) before the wdog counter terminates the access and send an error response to the master.
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

/* --- Register HW_EIM_WCR, field BCM
 *
 * Burst Clock Mode. This bit selects the burst clock mode of operation.
 * It is used for system debug mode.  BCM is cleared by a hardware reset.  The BCLK frequency in
 * this mode is according to GBCD bit                                 field.  The BCLK phase is
 * opposite to the EIM clock in this mode if GBCD                                 is 0.  This bit
 * should be used only in async. accesses. No sync access                                 can be
 * executed if this bit is set.  When this bit is set bcd field shouldn't be configured to
 * 0.
 */

#define BP_EIM_WCR_BCM      0
#define BM_EIM_WCR_BCM      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_BCM(v)   ((((reg32_t) v) << 0) & BM_EIM_WCR_BCM)
#else
#define BF_EIM_WCR_BCM(v)   (((v) << 0) & BM_EIM_WCR_BCM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_BCM(v)   BF_CS1(EIM_WCR, BCM, v)
#endif

/* --- Register HW_EIM_WCR, field GBCD
 *
 * General Burst Clock Divisor. When BCM bit is set, this bit field
 * contains the value used to program the burst clock divisor for
 * Continuous BCLK generation. The other BCD bit fields for each chip
 * select are ignored. It is used to divide the internal AXI bus
 * frequency. When BCM=0 GBCD bit field has no influence. GBCD is
 * cleared by a hardware reset.
 */

#define BP_EIM_WCR_GBCD      1
#define BM_EIM_WCR_GBCD      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_GBCD(v)   ((((reg32_t) v) << 1) & BM_EIM_WCR_GBCD)
#else
#define BF_EIM_WCR_GBCD(v)   (((v) << 1) & BM_EIM_WCR_GBCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_GBCD(v)   BF_CS1(EIM_WCR, GBCD, v)
#endif

/* --- Register HW_EIM_WCR, field INTEN
 *
 * Interrupt Enable. When this bit is set the External signal RDY_INT as
 * active interrupt. When interrupt occurs, INT bit at the WCR will be
 * set and t EIM_EXT_INT signal will be asserted correspondingly. This
 * bit is cleared by a hardware reset.
 */

#define BP_EIM_WCR_INTEN      4
#define BM_EIM_WCR_INTEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTEN(v)   ((((reg32_t) v) << 4) & BM_EIM_WCR_INTEN)
#else
#define BF_EIM_WCR_INTEN(v)   (((v) << 4) & BM_EIM_WCR_INTEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_INTEN(v)   BF_CS1(EIM_WCR, INTEN, v)
#endif

/* --- Register HW_EIM_WCR, field INTPOL
 *
 * Interrupt Polarity. This bit field determines the polarity of the
 * external device interrupt.
 */

#define BP_EIM_WCR_INTPOL      5
#define BM_EIM_WCR_INTPOL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_INTPOL(v)   ((((reg32_t) v) << 5) & BM_EIM_WCR_INTPOL)
#else
#define BF_EIM_WCR_INTPOL(v)   (((v) << 5) & BM_EIM_WCR_INTPOL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_INTPOL(v)   BF_CS1(EIM_WCR, INTPOL, v)
#endif

/* --- Register HW_EIM_WCR, field WDOG_EN
 *
 * Memory WDog enable.  This bit controls the operation of the wdog counter that terminates
 * the EIM access.
 */

#define BP_EIM_WCR_WDOG_EN      8
#define BM_EIM_WCR_WDOG_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_EN(v)   ((((reg32_t) v) << 8) & BM_EIM_WCR_WDOG_EN)
#else
#define BF_EIM_WCR_WDOG_EN(v)   (((v) << 8) & BM_EIM_WCR_WDOG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_WDOG_EN(v)   BF_CS1(EIM_WCR, WDOG_EN, v)
#endif

/* --- Register HW_EIM_WCR, field WDOG_LIMIT
 *
 * Memory Watch Dog (WDog) cycle limit.  This bit field determines the number of BCLK cycles (ACLK
 * cycles in                                 dtack mode) before the wdog counter terminates the
 * access and send                                 an error response to the master.
 */

#define BP_EIM_WCR_WDOG_LIMIT      9
#define BM_EIM_WCR_WDOG_LIMIT      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WCR_WDOG_LIMIT(v)   ((((reg32_t) v) << 9) & BM_EIM_WCR_WDOG_LIMIT)
#else
#define BF_EIM_WCR_WDOG_LIMIT(v)   (((v) << 9) & BM_EIM_WCR_WDOG_LIMIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WCR_WDOG_LIMIT(v)   BF_CS1(EIM_WCR, WDOG_LIMIT, v)
#endif

/*!
 * @brief HW_EIM_WIAR - EIM IP Access Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPS_REQ : 1; //!< IPS request. The Master requests to access one of the IPS registers. During such access the EIM should not perform any AXI/memory accesses. The EIM finishes the AXI accesses that already starts and asserts the IPS_ACK bit.
        unsigned IPS_ACK : 1; //!< IPS ACK. The EIM is ready for ips access. There is no active AXI access and no new AXI access is accepted till this bit is cleared. This bit is cleared by the master after it completes the ips accesses.
        unsigned INT : 1; //!< Interrupt. This bit indicates interrupt assertion by an external device according to RDY_INT signal. When polling this bit, INT=0 indicates interrupt not occurred and INT=1 indicates assertion of the external device interrupt. This bit is cleared by a hardware reset.
        unsigned ERRST : 1; //!< READY After Reset. This bit controls the initial ready/busy status for external devices on CS0 immediately after hardware reset. This is a sticky bit which is cleared once the RDY_INT signal is asserted by the external device.  When ERRST = 1 the first fetch access from EIM to the external device located on CS0 will be pending until RDY_INT signal indicates that the external device is ready, then EIM will execute the access.  Reset value for ERRST is EIM_BOOT[4].
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

/* --- Register HW_EIM_WIAR, field IPS_REQ
 *
 * IPS request. The Master requests to access one of the IPS
 * registers. During such access the EIM should not perform any
 * AXI/memory accesses. The EIM finishes the AXI accesses that already
 * starts and asserts the IPS_ACK bit.
 */

#define BP_EIM_WIAR_IPS_REQ      0
#define BM_EIM_WIAR_IPS_REQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_REQ(v)   ((((reg32_t) v) << 0) & BM_EIM_WIAR_IPS_REQ)
#else
#define BF_EIM_WIAR_IPS_REQ(v)   (((v) << 0) & BM_EIM_WIAR_IPS_REQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_IPS_REQ(v)   BF_CS1(EIM_WIAR, IPS_REQ, v)
#endif

/* --- Register HW_EIM_WIAR, field IPS_ACK
 *
 * IPS ACK. The EIM is ready for ips access. There is no active AXI
 * access and no new AXI access is accepted till this bit is cleared.
 * This bit is cleared by the master after it completes the ips
 * accesses.
 */

#define BP_EIM_WIAR_IPS_ACK      1
#define BM_EIM_WIAR_IPS_ACK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_IPS_ACK(v)   ((((reg32_t) v) << 1) & BM_EIM_WIAR_IPS_ACK)
#else
#define BF_EIM_WIAR_IPS_ACK(v)   (((v) << 1) & BM_EIM_WIAR_IPS_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_IPS_ACK(v)   BF_CS1(EIM_WIAR, IPS_ACK, v)
#endif

/* --- Register HW_EIM_WIAR, field INT
 *
 * Interrupt. This bit indicates interrupt assertion by an external
 * device according to RDY_INT signal. When polling this bit, INT=0
 * indicates interrupt not occurred and INT=1 indicates assertion of
 * the external device interrupt. This bit is cleared by a hardware
 * reset.
 */

#define BP_EIM_WIAR_INT      2
#define BM_EIM_WIAR_INT      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_INT(v)   ((((reg32_t) v) << 2) & BM_EIM_WIAR_INT)
#else
#define BF_EIM_WIAR_INT(v)   (((v) << 2) & BM_EIM_WIAR_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_INT(v)   BF_CS1(EIM_WIAR, INT, v)
#endif

/* --- Register HW_EIM_WIAR, field ERRST
 *
 * READY After Reset. This bit controls the initial ready/busy status
 * for external devices on CS0 immediately after hardware reset. This
 * is a sticky bit which is cleared once the RDY_INT signal is asserted
 * by the external device.  When ERRST = 1 the first fetch access from EIM to the external device
 * located on CS0 will be pending until RDY_INT signal indicates that
 * the external device is ready, then EIM will execute the access.  Reset value for ERRST is
 * EIM_BOOT[4].
 */

#define BP_EIM_WIAR_ERRST      3
#define BM_EIM_WIAR_ERRST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ERRST(v)   ((((reg32_t) v) << 3) & BM_EIM_WIAR_ERRST)
#else
#define BF_EIM_WIAR_ERRST(v)   (((v) << 3) & BM_EIM_WIAR_ERRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_ERRST(v)   BF_CS1(EIM_WIAR, ERRST, v)
#endif

/* --- Register HW_EIM_WIAR, field ACLK_EN
 *
 * ACLK enable. This bit gates the ACLK for the EIM except from FFs that
 * get ipg_aclk_s. After reset ACLK is enabled.
 */

#define BP_EIM_WIAR_ACLK_EN      4
#define BM_EIM_WIAR_ACLK_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_EIM_WIAR_ACLK_EN(v)   ((((reg32_t) v) << 4) & BM_EIM_WIAR_ACLK_EN)
#else
#define BF_EIM_WIAR_ACLK_EN(v)   (((v) << 4) & BM_EIM_WIAR_ACLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_WIAR_ACLK_EN(v)   BF_CS1(EIM_WIAR, ACLK_EN, v)
#endif

/*!
 * @brief HW_EIM_EAR - Error Address Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
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

/* --- Register HW_EIM_EAR, field ERROR
 *
 * Error Address. This bit field holds the AXI address of the last
 * access that caused error. This register is read only register.
 */

#define BP_EIM_EAR_ERROR      0
#define BM_EIM_EAR_ERROR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_EIM_EAR_ERROR(v)   ((((reg32_t) v) << 0) & BM_EIM_EAR_ERROR)
#else
#define BF_EIM_EAR_ERROR(v)   (((v) << 0) & BM_EIM_EAR_ERROR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_EIM_EAR_ERROR(v)   BF_CS1(EIM_EAR, ERROR, v)
#endif



/*!
 * @brief All EIM module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0[36];
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
