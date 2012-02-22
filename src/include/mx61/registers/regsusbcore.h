/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USBC_H
#define _USBC_H

#include "regs.h"

#ifndef REGS_USBC_BASE
#define REGS_USBC_BASE (REGS_BASE + 0x02184000)
#endif


/*!
 * @brief HW_USBC__ID - Identification register
 *
 * The ID register identifies the USB 2.0 OTG High-Speed core and its revision.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ID : 6; //!< Configuration number.  This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG High-Speed core.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned NID : 6; //!< Complement version of ID
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned REVISION : 8; //!< Revision number of the controller core.
        unsigned RESERVED2 : 8; //!< Reserved
    } B;
} hw_usbc__id_t;
#endif

/*
 * constants & macros for entire USBC__ID register
 */
#define HW_USBC__ID_ADDR      (REGS_USBC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__ID           (*(volatile hw_usbc__id_t *) HW_USBC__ID_ADDR)
#define HW_USBC__ID_RD()      (HW_USBC__ID.U)
#define HW_USBC__ID_WR(v)     (HW_USBC__ID.U = (v))
#define HW_USBC__ID_SET(v)    (HW_USBC__ID_WR(HW_USBC__ID_RD() |  (v)))
#define HW_USBC__ID_CLR(v)    (HW_USBC__ID_WR(HW_USBC__ID_RD() & ~(v)))
#define HW_USBC__ID_TOG(v)    (HW_USBC__ID_WR(HW_USBC__ID_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__ID bitfields
 */

/* --- Register HW_USBC__ID, field ID
 *
 * Configuration number.  This number is set to 0x05 and indicates that the peripheral is USB 2.0
 * OTG High-Speed core.
 */

#define BP_USBC__ID_ID      0
#define BM_USBC__ID_ID      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ID_ID(v)   ((((reg32_t) v) << 0) & BM_USBC__ID_ID)
#else
#define BF_USBC__ID_ID(v)   (((v) << 0) & BM_USBC__ID_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__ID_ID(v)   BF_CS1(USBC__ID, ID, v)
#endif

/* --- Register HW_USBC__ID, field NID
 *
 * Complement version of ID
 */

#define BP_USBC__ID_NID      8
#define BM_USBC__ID_NID      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ID_NID(v)   ((((reg32_t) v) << 8) & BM_USBC__ID_NID)
#else
#define BF_USBC__ID_NID(v)   (((v) << 8) & BM_USBC__ID_NID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__ID_NID(v)   BF_CS1(USBC__ID, NID, v)
#endif

/* --- Register HW_USBC__ID, field REVISION
 *
 * Revision number of the controller core.
 */

#define BP_USBC__ID_REVISION      16
#define BM_USBC__ID_REVISION      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ID_REVISION(v)   ((((reg32_t) v) << 16) & BM_USBC__ID_REVISION)
#else
#define BF_USBC__ID_REVISION(v)   (((v) << 16) & BM_USBC__ID_REVISION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__ID_REVISION(v)   BF_CS1(USBC__ID, REVISION, v)
#endif

/*!
 * @brief HW_USBC__HWGENERAL - Hardware General
 *
 * General hardware parameters as defined in System Level Issues and Core Configuration.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned PHYW : 2; //!< Data width of the transciever connected to the controller core.  For OTG controller core reset value is '11b';  For Host1/Host2/Host3 controller core, reset value is '00b'.  For OTG/Host1/Host2/Host3 controller core, reset value is '11b'.  For OTG/Host1/Host2/Host3 controller core, reset value is '01b'.
        unsigned PHYM : 3; //!< Transciever type  For OTG/Host1/Host2/Host3 controller core, reset value is '7h'.  For OTG controller core, reset value is '0h';  For Host1/Host2/Host3 controller core, reset value is '7h'.  For OTG controller core, reset value is '0h';  For Host1/Host2/Host3 controller core, reset value is '4h'.
        unsigned SM : 2; //!< Serial interface mode capability  For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.  For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.  For OTG/Host1/Host2/Host3 controller core, reset value is '00b'.
        unsigned RESERVED1 : 21; //!< Reserved
    } B;
} hw_usbc__hwgeneral_t;
#endif

/*
 * constants & macros for entire USBC__HWGENERAL register
 */
#define HW_USBC__HWGENERAL_ADDR      (REGS_USBC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWGENERAL           (*(volatile hw_usbc__hwgeneral_t *) HW_USBC__HWGENERAL_ADDR)
#define HW_USBC__HWGENERAL_RD()      (HW_USBC__HWGENERAL.U)
#define HW_USBC__HWGENERAL_WR(v)     (HW_USBC__HWGENERAL.U = (v))
#define HW_USBC__HWGENERAL_SET(v)    (HW_USBC__HWGENERAL_WR(HW_USBC__HWGENERAL_RD() |  (v)))
#define HW_USBC__HWGENERAL_CLR(v)    (HW_USBC__HWGENERAL_WR(HW_USBC__HWGENERAL_RD() & ~(v)))
#define HW_USBC__HWGENERAL_TOG(v)    (HW_USBC__HWGENERAL_WR(HW_USBC__HWGENERAL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HWGENERAL bitfields
 */

/* --- Register HW_USBC__HWGENERAL, field PHYW
 *
 * Data width of the transciever connected to the controller core.  For OTG controller core reset
 * value is '11b';  For Host1/Host2/Host3 controller core, reset value is '00b'.  For
 * OTG/Host1/Host2/Host3 controller core, reset value is '11b'.  For OTG/Host1/Host2/Host3
 * controller core, reset value is '01b'.
 */

#define BP_USBC__HWGENERAL_PHYW      4
#define BM_USBC__HWGENERAL_PHYW      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWGENERAL_PHYW(v)   ((((reg32_t) v) << 4) & BM_USBC__HWGENERAL_PHYW)
#else
#define BF_USBC__HWGENERAL_PHYW(v)   (((v) << 4) & BM_USBC__HWGENERAL_PHYW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWGENERAL_PHYW(v)   BF_CS1(USBC__HWGENERAL, PHYW, v)
#endif

/* --- Register HW_USBC__HWGENERAL, field PHYM
 *
 * Transciever type  For OTG/Host1/Host2/Host3 controller core, reset value is '7h'.  For OTG
 * controller core, reset value is '0h';  For Host1/Host2/Host3 controller core, reset value is
 * '7h'.  For OTG controller core, reset value is '0h';  For Host1/Host2/Host3 controller core,
 * reset value is '4h'.
 */

#define BP_USBC__HWGENERAL_PHYM      6
#define BM_USBC__HWGENERAL_PHYM      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWGENERAL_PHYM(v)   ((((reg32_t) v) << 6) & BM_USBC__HWGENERAL_PHYM)
#else
#define BF_USBC__HWGENERAL_PHYM(v)   (((v) << 6) & BM_USBC__HWGENERAL_PHYM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWGENERAL_PHYM(v)   BF_CS1(USBC__HWGENERAL, PHYM, v)
#endif

/* --- Register HW_USBC__HWGENERAL, field SM
 *
 * Serial interface mode capability  For OTG/Host1/Host2/Host3 controller core, reset value is
 * '10b'.  For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.  For
 * OTG/Host1/Host2/Host3 controller core, reset value is '00b'.
 */

#define BP_USBC__HWGENERAL_SM      9
#define BM_USBC__HWGENERAL_SM      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWGENERAL_SM(v)   ((((reg32_t) v) << 9) & BM_USBC__HWGENERAL_SM)
#else
#define BF_USBC__HWGENERAL_SM(v)   (((v) << 9) & BM_USBC__HWGENERAL_SM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWGENERAL_SM(v)   BF_CS1(USBC__HWGENERAL, SM, v)
#endif

/*!
 * @brief HW_USBC__HWHOST - Host Hardware Parameters
 *
 * Host hardware parameters as defined in System Level Issues and Core Configuration.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HC : 1; //!< Host Capable.  All 4 controller cores support host operation mode.
        unsigned NPORT : 3; //!< The Nmber of downstream ports supported by the host controller is NPORT+1.  As all 4 controller cores are single port, these bits are set to '000b'.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__hwhost_t;
#endif

/*
 * constants & macros for entire USBC__HWHOST register
 */
#define HW_USBC__HWHOST_ADDR      (REGS_USBC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWHOST           (*(volatile hw_usbc__hwhost_t *) HW_USBC__HWHOST_ADDR)
#define HW_USBC__HWHOST_RD()      (HW_USBC__HWHOST.U)
#define HW_USBC__HWHOST_WR(v)     (HW_USBC__HWHOST.U = (v))
#define HW_USBC__HWHOST_SET(v)    (HW_USBC__HWHOST_WR(HW_USBC__HWHOST_RD() |  (v)))
#define HW_USBC__HWHOST_CLR(v)    (HW_USBC__HWHOST_WR(HW_USBC__HWHOST_RD() & ~(v)))
#define HW_USBC__HWHOST_TOG(v)    (HW_USBC__HWHOST_WR(HW_USBC__HWHOST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HWHOST bitfields
 */

/* --- Register HW_USBC__HWHOST, field HC
 *
 * Host Capable.  All 4 controller cores support host operation mode.
 */

#define BP_USBC__HWHOST_HC      0
#define BM_USBC__HWHOST_HC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWHOST_HC(v)   ((((reg32_t) v) << 0) & BM_USBC__HWHOST_HC)
#else
#define BF_USBC__HWHOST_HC(v)   (((v) << 0) & BM_USBC__HWHOST_HC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWHOST_HC(v)   BF_CS1(USBC__HWHOST, HC, v)
#endif

/* --- Register HW_USBC__HWHOST, field NPORT
 *
 * The Nmber of downstream ports supported by the host controller is NPORT+1.  As all 4 controller
 * cores are single port, these bits are set to '000b'.
 */

#define BP_USBC__HWHOST_NPORT      1
#define BM_USBC__HWHOST_NPORT      0x0000000e

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWHOST_NPORT(v)   ((((reg32_t) v) << 1) & BM_USBC__HWHOST_NPORT)
#else
#define BF_USBC__HWHOST_NPORT(v)   (((v) << 1) & BM_USBC__HWHOST_NPORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWHOST_NPORT(v)   BF_CS1(USBC__HWHOST, NPORT, v)
#endif

/*!
 * @brief HW_USBC_UOG_HWDEVICE - Device Hardware Parameters
 *
 * Device hardware parameters are as defined in System Level Issues and Core Configuration.  This
 * register is only available in OTG core.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DC : 1; //!< Device Capable.
        unsigned DEVEP : 5; //!< Device Endpoint Number  OTG controller core has 8 Endpoints.
        unsigned RESERVED0 : 26; //!< Reserved
    } B;
} hw_usbc_uog_hwdevice_t;
#endif

/*
 * constants & macros for entire USBC_UOG_HWDEVICE register
 */
#define HW_USBC_UOG_HWDEVICE_ADDR      (REGS_USBC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_HWDEVICE           (*(volatile hw_usbc_uog_hwdevice_t *) HW_USBC_UOG_HWDEVICE_ADDR)
#define HW_USBC_UOG_HWDEVICE_RD()      (HW_USBC_UOG_HWDEVICE.U)
#define HW_USBC_UOG_HWDEVICE_WR(v)     (HW_USBC_UOG_HWDEVICE.U = (v))
#define HW_USBC_UOG_HWDEVICE_SET(v)    (HW_USBC_UOG_HWDEVICE_WR(HW_USBC_UOG_HWDEVICE_RD() |  (v)))
#define HW_USBC_UOG_HWDEVICE_CLR(v)    (HW_USBC_UOG_HWDEVICE_WR(HW_USBC_UOG_HWDEVICE_RD() & ~(v)))
#define HW_USBC_UOG_HWDEVICE_TOG(v)    (HW_USBC_UOG_HWDEVICE_WR(HW_USBC_UOG_HWDEVICE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_HWDEVICE bitfields
 */

/* --- Register HW_USBC_UOG_HWDEVICE, field DC
 *
 * Device Capable.
 */

#define BP_USBC_UOG_HWDEVICE_DC      0
#define BM_USBC_UOG_HWDEVICE_DC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_HWDEVICE_DC(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_HWDEVICE_DC)
#else
#define BF_USBC_UOG_HWDEVICE_DC(v)   (((v) << 0) & BM_USBC_UOG_HWDEVICE_DC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_HWDEVICE_DC(v)   BF_CS1(USBC_UOG_HWDEVICE, DC, v)
#endif

/* --- Register HW_USBC_UOG_HWDEVICE, field DEVEP
 *
 * Device Endpoint Number  OTG controller core has 8 Endpoints.
 */

#define BP_USBC_UOG_HWDEVICE_DEVEP      1
#define BM_USBC_UOG_HWDEVICE_DEVEP      0x0000003e

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_HWDEVICE_DEVEP(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_HWDEVICE_DEVEP)
#else
#define BF_USBC_UOG_HWDEVICE_DEVEP(v)   (((v) << 1) & BM_USBC_UOG_HWDEVICE_DEVEP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_HWDEVICE_DEVEP(v)   BF_CS1(USBC_UOG_HWDEVICE, DEVEP, v)
#endif

/*!
 * @brief HW_USBC__HWTXBUF - TX Buffer Hardware Parameters
 *
 * TX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TXBURST : 8; //!< Default burst size for memory to TX buffer transfer.  This is reset value of TXPBURST bits in USB core regsiter UOG_BURSTSIZE.  Please see .
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned TXCHANADD : 8; //!< TX Buffer size is: (2^TXCHANADD) * 4 Bytes.  These bits are set to '08h', so buffer size is 256*4 Bytes.  For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX Buffers.  For Host1/Host2/Host3 controller core, there is only one TX Buffer.
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc__hwtxbuf_t;
#endif

/*
 * constants & macros for entire USBC__HWTXBUF register
 */
#define HW_USBC__HWTXBUF_ADDR      (REGS_USBC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWTXBUF           (*(volatile hw_usbc__hwtxbuf_t *) HW_USBC__HWTXBUF_ADDR)
#define HW_USBC__HWTXBUF_RD()      (HW_USBC__HWTXBUF.U)
#define HW_USBC__HWTXBUF_WR(v)     (HW_USBC__HWTXBUF.U = (v))
#define HW_USBC__HWTXBUF_SET(v)    (HW_USBC__HWTXBUF_WR(HW_USBC__HWTXBUF_RD() |  (v)))
#define HW_USBC__HWTXBUF_CLR(v)    (HW_USBC__HWTXBUF_WR(HW_USBC__HWTXBUF_RD() & ~(v)))
#define HW_USBC__HWTXBUF_TOG(v)    (HW_USBC__HWTXBUF_WR(HW_USBC__HWTXBUF_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HWTXBUF bitfields
 */

/* --- Register HW_USBC__HWTXBUF, field TXBURST
 *
 * Default burst size for memory to TX buffer transfer.  This is reset value of TXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE.  Please see .
 */

#define BP_USBC__HWTXBUF_TXBURST      0
#define BM_USBC__HWTXBUF_TXBURST      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWTXBUF_TXBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__HWTXBUF_TXBURST)
#else
#define BF_USBC__HWTXBUF_TXBURST(v)   (((v) << 0) & BM_USBC__HWTXBUF_TXBURST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWTXBUF_TXBURST(v)   BF_CS1(USBC__HWTXBUF, TXBURST, v)
#endif

/* --- Register HW_USBC__HWTXBUF, field TXCHANADD
 *
 * TX Buffer size is: (2^TXCHANADD) * 4 Bytes.  These bits are set to '08h', so buffer size is 256*4
 * Bytes.  For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX
 * Buffers.  For Host1/Host2/Host3 controller core, there is only one TX Buffer.
 */

#define BP_USBC__HWTXBUF_TXCHANADD      16
#define BM_USBC__HWTXBUF_TXCHANADD      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWTXBUF_TXCHANADD(v)   ((((reg32_t) v) << 16) & BM_USBC__HWTXBUF_TXCHANADD)
#else
#define BF_USBC__HWTXBUF_TXCHANADD(v)   (((v) << 16) & BM_USBC__HWTXBUF_TXCHANADD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWTXBUF_TXCHANADD(v)   BF_CS1(USBC__HWTXBUF, TXCHANADD, v)
#endif

/*!
 * @brief HW_USBC__HWRXBUF - RX Buffer Hardware Parameters
 *
 * RX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RXBURST : 8; //!< Default burst size for memory to RX buffer transfer.  This is reset value of RXPBURST bits in USB core regsiter UOG_BURSTSIZE.  Please see .
        unsigned RXADD : 8; //!< Buffer total size for all receive endpoints is (2^RXADD).  RX Buffer size is: (2^RXADD) * 4 Bytes.  These bits are set to '08h', so buffer size is 256*4 Bytes.  For OTG controller core, there is one RX Buffer, shared by 8 Endpoints.  For Host1/Host2/Host3 controller core, there is only one RX Buffer.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usbc__hwrxbuf_t;
#endif

/*
 * constants & macros for entire USBC__HWRXBUF register
 */
#define HW_USBC__HWRXBUF_ADDR      (REGS_USBC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWRXBUF           (*(volatile hw_usbc__hwrxbuf_t *) HW_USBC__HWRXBUF_ADDR)
#define HW_USBC__HWRXBUF_RD()      (HW_USBC__HWRXBUF.U)
#define HW_USBC__HWRXBUF_WR(v)     (HW_USBC__HWRXBUF.U = (v))
#define HW_USBC__HWRXBUF_SET(v)    (HW_USBC__HWRXBUF_WR(HW_USBC__HWRXBUF_RD() |  (v)))
#define HW_USBC__HWRXBUF_CLR(v)    (HW_USBC__HWRXBUF_WR(HW_USBC__HWRXBUF_RD() & ~(v)))
#define HW_USBC__HWRXBUF_TOG(v)    (HW_USBC__HWRXBUF_WR(HW_USBC__HWRXBUF_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HWRXBUF bitfields
 */

/* --- Register HW_USBC__HWRXBUF, field RXBURST
 *
 * Default burst size for memory to RX buffer transfer.  This is reset value of RXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE.  Please see .
 */

#define BP_USBC__HWRXBUF_RXBURST      0
#define BM_USBC__HWRXBUF_RXBURST      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWRXBUF_RXBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__HWRXBUF_RXBURST)
#else
#define BF_USBC__HWRXBUF_RXBURST(v)   (((v) << 0) & BM_USBC__HWRXBUF_RXBURST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWRXBUF_RXBURST(v)   BF_CS1(USBC__HWRXBUF, RXBURST, v)
#endif

/* --- Register HW_USBC__HWRXBUF, field RXADD
 *
 * Buffer total size for all receive endpoints is (2^RXADD).  RX Buffer size is: (2^RXADD) * 4
 * Bytes.  These bits are set to '08h', so buffer size is 256*4 Bytes.  For OTG controller core,
 * there is one RX Buffer, shared by 8 Endpoints.  For Host1/Host2/Host3 controller core, there is
 * only one RX Buffer.
 */

#define BP_USBC__HWRXBUF_RXADD      8
#define BM_USBC__HWRXBUF_RXADD      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HWRXBUF_RXADD(v)   ((((reg32_t) v) << 8) & BM_USBC__HWRXBUF_RXADD)
#else
#define BF_USBC__HWRXBUF_RXADD(v)   (((v) << 8) & BM_USBC__HWRXBUF_RXADD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HWRXBUF_RXADD(v)   BF_CS1(USBC__HWRXBUF, RXADD, v)
#endif

/*!
 * @brief HW_USBC__GPTIMER0LD - General Purpose Timer #0 Load
 *
 * This register controls load value of the count timer in register n_GPTIMER0CTRL. Please see .
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value  These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'.  This value represents the time in microseconds minus 1 for the timer duration.  Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7.  Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer0ld_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0LD register
 */
#define HW_USBC__GPTIMER0LD_ADDR      (REGS_USBC_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0LD           (*(volatile hw_usbc__gptimer0ld_t *) HW_USBC__GPTIMER0LD_ADDR)
#define HW_USBC__GPTIMER0LD_RD()      (HW_USBC__GPTIMER0LD.U)
#define HW_USBC__GPTIMER0LD_WR(v)     (HW_USBC__GPTIMER0LD.U = (v))
#define HW_USBC__GPTIMER0LD_SET(v)    (HW_USBC__GPTIMER0LD_WR(HW_USBC__GPTIMER0LD_RD() |  (v)))
#define HW_USBC__GPTIMER0LD_CLR(v)    (HW_USBC__GPTIMER0LD_WR(HW_USBC__GPTIMER0LD_RD() & ~(v)))
#define HW_USBC__GPTIMER0LD_TOG(v)    (HW_USBC__GPTIMER0LD_WR(HW_USBC__GPTIMER0LD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__GPTIMER0LD bitfields
 */

/* --- Register HW_USBC__GPTIMER0LD, field GPTLD
 *
 * General Purpose Timer Load Value  These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'.  This value represents the time in microseconds minus 1 for the timer duration.
 * Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7.  Max value is 0xFFFFFF or
 * 16.777215 seconds.
 */

#define BP_USBC__GPTIMER0LD_GPTLD      0
#define BM_USBC__GPTIMER0LD_GPTLD      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0LD_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0LD_GPTLD)
#else
#define BF_USBC__GPTIMER0LD_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER0LD_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER0LD_GPTLD(v)   BF_CS1(USBC__GPTIMER0LD, GPTLD, v)
#endif

/*!
 * @brief HW_USBC__GPTIMER0CTRL - General Purpose Timer #0 Controller
 *
 * This register contains the control for this countdown timer and a data field can be queried
 * to determine the running count value. This timer has granularity on 1 us and can be
 * programmed to a little over 16 seconds. There are two counter modes which are described in
 * the register table below. When the timer counter value transitions to zero, an interrupt
 * could be generated if enable.  Interrupt status bit is TI0 bit in n_USBSTS register (See ),
 * interrupt enable bit is TIE0 bit in n_USBINTR                             register. (See .)
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter.  This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode  In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software;  In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run  GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer0ctrl_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0CTRL register
 */
#define HW_USBC__GPTIMER0CTRL_ADDR      (REGS_USBC_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0CTRL           (*(volatile hw_usbc__gptimer0ctrl_t *) HW_USBC__GPTIMER0CTRL_ADDR)
#define HW_USBC__GPTIMER0CTRL_RD()      (HW_USBC__GPTIMER0CTRL.U)
#define HW_USBC__GPTIMER0CTRL_WR(v)     (HW_USBC__GPTIMER0CTRL.U = (v))
#define HW_USBC__GPTIMER0CTRL_SET(v)    (HW_USBC__GPTIMER0CTRL_WR(HW_USBC__GPTIMER0CTRL_RD() |  (v)))
#define HW_USBC__GPTIMER0CTRL_CLR(v)    (HW_USBC__GPTIMER0CTRL_WR(HW_USBC__GPTIMER0CTRL_RD() & ~(v)))
#define HW_USBC__GPTIMER0CTRL_TOG(v)    (HW_USBC__GPTIMER0CTRL_WR(HW_USBC__GPTIMER0CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__GPTIMER0CTRL bitfields
 */

/* --- Register HW_USBC__GPTIMER0CTRL, field GPTCNT
 *
 * General Purpose Timer Counter.  This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER0CTRL_GPTCNT      0
#define BM_USBC__GPTIMER0CTRL_GPTCNT      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRL_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0CTRL_GPTCNT)
#else
#define BF_USBC__GPTIMER0CTRL_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER0CTRL_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER0CTRL_GPTCNT(v)   BF_CS1(USBC__GPTIMER0CTRL, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRL, field GPTMODE
 *
 * General Purpose Timer Mode  In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software;  In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 */

#define BP_USBC__GPTIMER0CTRL_GPTMODE      24
#define BM_USBC__GPTIMER0CTRL_GPTMODE      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRL_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER0CTRL_GPTMODE)
#else
#define BF_USBC__GPTIMER0CTRL_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER0CTRL_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER0CTRL_GPTMODE(v)   BF_CS1(USBC__GPTIMER0CTRL, GPTMODE, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRL, field GPTRST
 *
 * General Purpose Timer Reset
 */

#define BP_USBC__GPTIMER0CTRL_GPTRST      30
#define BM_USBC__GPTIMER0CTRL_GPTRST      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRL_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER0CTRL_GPTRST)
#else
#define BF_USBC__GPTIMER0CTRL_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER0CTRL_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER0CTRL_GPTRST(v)   BF_CS1(USBC__GPTIMER0CTRL, GPTRST, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRL, field GPTRUN
 *
 * General Purpose Timer Run  GPTCNT bits are not effected when setting or clearing this bit.
 */

#define BP_USBC__GPTIMER0CTRL_GPTRUN      31
#define BM_USBC__GPTIMER0CTRL_GPTRUN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRL_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER0CTRL_GPTRUN)
#else
#define BF_USBC__GPTIMER0CTRL_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER0CTRL_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER0CTRL_GPTRUN(v)   BF_CS1(USBC__GPTIMER0CTRL, GPTRUN, v)
#endif

/*!
 * @brief HW_USBC__GPTIMER1LD - General Purpose Timer #1 Load
 *
 * This register controls load value of the count timer in register n_GPTIMER1CTRL. Please see .
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value  These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'.  This value represents the time in microseconds minus 1 for the timer duration.  Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7.  Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer1ld_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1LD register
 */
#define HW_USBC__GPTIMER1LD_ADDR      (REGS_USBC_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1LD           (*(volatile hw_usbc__gptimer1ld_t *) HW_USBC__GPTIMER1LD_ADDR)
#define HW_USBC__GPTIMER1LD_RD()      (HW_USBC__GPTIMER1LD.U)
#define HW_USBC__GPTIMER1LD_WR(v)     (HW_USBC__GPTIMER1LD.U = (v))
#define HW_USBC__GPTIMER1LD_SET(v)    (HW_USBC__GPTIMER1LD_WR(HW_USBC__GPTIMER1LD_RD() |  (v)))
#define HW_USBC__GPTIMER1LD_CLR(v)    (HW_USBC__GPTIMER1LD_WR(HW_USBC__GPTIMER1LD_RD() & ~(v)))
#define HW_USBC__GPTIMER1LD_TOG(v)    (HW_USBC__GPTIMER1LD_WR(HW_USBC__GPTIMER1LD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__GPTIMER1LD bitfields
 */

/* --- Register HW_USBC__GPTIMER1LD, field GPTLD
 *
 * General Purpose Timer Load Value  These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'.  This value represents the time in microseconds minus 1 for the timer duration.
 * Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7.  Max value is 0xFFFFFF or
 * 16.777215 seconds.
 */

#define BP_USBC__GPTIMER1LD_GPTLD      0
#define BM_USBC__GPTIMER1LD_GPTLD      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1LD_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1LD_GPTLD)
#else
#define BF_USBC__GPTIMER1LD_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER1LD_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER1LD_GPTLD(v)   BF_CS1(USBC__GPTIMER1LD, GPTLD, v)
#endif

/*!
 * @brief HW_USBC__GPTIMER1CTRL - General Purpose Timer #1 Controller
 *
 * This register contains the control for this countdown timer and a data field can be queried
 * to determine the running count value. This timer has granularity on 1 us and can be
 * programmed to a little over 16 seconds. There are two counter modes which are described in
 * the register table below. When the timer counter value transitions to zero, an interrupt
 * could be generated if enable.  Interrupt status bit is TI1 bit in UOG_USBSTS register (See ),
 * interrupt enable bit is TIE1 bit in n_USBINTR                             register (See ).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter.  This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode  In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run  GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer1ctrl_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1CTRL register
 */
#define HW_USBC__GPTIMER1CTRL_ADDR      (REGS_USBC_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1CTRL           (*(volatile hw_usbc__gptimer1ctrl_t *) HW_USBC__GPTIMER1CTRL_ADDR)
#define HW_USBC__GPTIMER1CTRL_RD()      (HW_USBC__GPTIMER1CTRL.U)
#define HW_USBC__GPTIMER1CTRL_WR(v)     (HW_USBC__GPTIMER1CTRL.U = (v))
#define HW_USBC__GPTIMER1CTRL_SET(v)    (HW_USBC__GPTIMER1CTRL_WR(HW_USBC__GPTIMER1CTRL_RD() |  (v)))
#define HW_USBC__GPTIMER1CTRL_CLR(v)    (HW_USBC__GPTIMER1CTRL_WR(HW_USBC__GPTIMER1CTRL_RD() & ~(v)))
#define HW_USBC__GPTIMER1CTRL_TOG(v)    (HW_USBC__GPTIMER1CTRL_WR(HW_USBC__GPTIMER1CTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__GPTIMER1CTRL bitfields
 */

/* --- Register HW_USBC__GPTIMER1CTRL, field GPTCNT
 *
 * General Purpose Timer Counter.  This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER1CTRL_GPTCNT      0
#define BM_USBC__GPTIMER1CTRL_GPTCNT      0x00ffffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRL_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1CTRL_GPTCNT)
#else
#define BF_USBC__GPTIMER1CTRL_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER1CTRL_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER1CTRL_GPTCNT(v)   BF_CS1(USBC__GPTIMER1CTRL, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRL, field GPTMODE
 *
 * General Purpose Timer Mode  In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop                                 until the counter is reset by software. In
 * repeat mode, the timer will count down to                                 zero, generate an
 * interrupt and automatically reload the counter value from GPTLD bits
 * to start again.
 */

#define BP_USBC__GPTIMER1CTRL_GPTMODE      24
#define BM_USBC__GPTIMER1CTRL_GPTMODE      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRL_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER1CTRL_GPTMODE)
#else
#define BF_USBC__GPTIMER1CTRL_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER1CTRL_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER1CTRL_GPTMODE(v)   BF_CS1(USBC__GPTIMER1CTRL, GPTMODE, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRL, field GPTRST
 *
 * General Purpose Timer Reset
 */

#define BP_USBC__GPTIMER1CTRL_GPTRST      30
#define BM_USBC__GPTIMER1CTRL_GPTRST      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRL_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER1CTRL_GPTRST)
#else
#define BF_USBC__GPTIMER1CTRL_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER1CTRL_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER1CTRL_GPTRST(v)   BF_CS1(USBC__GPTIMER1CTRL, GPTRST, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRL, field GPTRUN
 *
 * General Purpose Timer Run  GPTCNT bits are not effected when setting or clearing this bit.
 */

#define BP_USBC__GPTIMER1CTRL_GPTRUN      31
#define BM_USBC__GPTIMER1CTRL_GPTRUN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRL_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER1CTRL_GPTRUN)
#else
#define BF_USBC__GPTIMER1CTRL_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER1CTRL_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__GPTIMER1CTRL_GPTRUN(v)   BF_CS1(USBC__GPTIMER1CTRL, GPTRUN, v)
#endif

/*!
 * @brief HW_USBC__SBUSCFG - System Bus Config
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AHBBRST : 3; //!< AHB master interface Burst configuration  These bits controls AHB master transfer type sequence (or priority).  This register overrides n_BURSTSIZE register when its value is not zero.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_usbc__sbuscfg_t;
#endif

/*
 * constants & macros for entire USBC__SBUSCFG register
 */
#define HW_USBC__SBUSCFG_ADDR      (REGS_USBC_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__SBUSCFG           (*(volatile hw_usbc__sbuscfg_t *) HW_USBC__SBUSCFG_ADDR)
#define HW_USBC__SBUSCFG_RD()      (HW_USBC__SBUSCFG.U)
#define HW_USBC__SBUSCFG_WR(v)     (HW_USBC__SBUSCFG.U = (v))
#define HW_USBC__SBUSCFG_SET(v)    (HW_USBC__SBUSCFG_WR(HW_USBC__SBUSCFG_RD() |  (v)))
#define HW_USBC__SBUSCFG_CLR(v)    (HW_USBC__SBUSCFG_WR(HW_USBC__SBUSCFG_RD() & ~(v)))
#define HW_USBC__SBUSCFG_TOG(v)    (HW_USBC__SBUSCFG_WR(HW_USBC__SBUSCFG_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__SBUSCFG bitfields
 */

/* --- Register HW_USBC__SBUSCFG, field AHBBRST
 *
 * AHB master interface Burst configuration  These bits controls AHB master transfer type sequence
 * (or priority).  This register overrides n_BURSTSIZE register when its value is not zero.
 */

#define BP_USBC__SBUSCFG_AHBBRST      0
#define BM_USBC__SBUSCFG_AHBBRST      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USBC__SBUSCFG_AHBBRST(v)   ((((reg32_t) v) << 0) & BM_USBC__SBUSCFG_AHBBRST)
#else
#define BF_USBC__SBUSCFG_AHBBRST(v)   (((v) << 0) & BM_USBC__SBUSCFG_AHBBRST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__SBUSCFG_AHBBRST(v)   BF_CS1(USBC__SBUSCFG, AHBBRST, v)
#endif

/*!
 * @brief HW_USBC__CAPLENGTH - Capability Register Length
 *
 * The following figure Capability Register Length (n_CAPLENGTH) indicates the offset that
 * should be added to the register base address at the beginning of the Operational
 * Register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg8_t  U;
    struct
    {
        unsigned char CAPLENGTH : 8; //!< These bits are used as an offset to add to register base to find the beginning of the Operational Register. Default value is '40h'.
    } B;
} hw_usbc__caplength_t;
#endif

/*
 * constants & macros for entire USBC__CAPLENGTH register
 */
#define HW_USBC__CAPLENGTH_ADDR      (REGS_USBC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__CAPLENGTH           (*(volatile hw_usbc__caplength_t *) HW_USBC__CAPLENGTH_ADDR)
#define HW_USBC__CAPLENGTH_RD()      (HW_USBC__CAPLENGTH.U)
#define HW_USBC__CAPLENGTH_WR(v)     (HW_USBC__CAPLENGTH.U = (v))
#define HW_USBC__CAPLENGTH_SET(v)    (HW_USBC__CAPLENGTH_WR(HW_USBC__CAPLENGTH_RD() |  (v)))
#define HW_USBC__CAPLENGTH_CLR(v)    (HW_USBC__CAPLENGTH_WR(HW_USBC__CAPLENGTH_RD() & ~(v)))
#define HW_USBC__CAPLENGTH_TOG(v)    (HW_USBC__CAPLENGTH_WR(HW_USBC__CAPLENGTH_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__CAPLENGTH bitfields
 */

/* --- Register HW_USBC__CAPLENGTH, field CAPLENGTH
 *
 * These bits are used as an offset to add to register base to find the beginning of the
 * Operational Register. Default value is '40h'.
 */

#define BP_USBC__CAPLENGTH_CAPLENGTH      0
#define BM_USBC__CAPLENGTH_CAPLENGTH      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__CAPLENGTH_CAPLENGTH(v)   ((((reg32_t) v) << 0) & BM_USBC__CAPLENGTH_CAPLENGTH)
#else
#define BF_USBC__CAPLENGTH_CAPLENGTH(v)   (((v) << 0) & BM_USBC__CAPLENGTH_CAPLENGTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__CAPLENGTH_CAPLENGTH(v)   BF_CS1(USBC__CAPLENGTH, CAPLENGTH, v)
#endif

/*!
 * @brief HW_USBC__HCIVERSION - Host Controller Interface Version
 *
 * The following figure shows the Host Interface version number (n_HCIVERSION), which is a
 * 2-byte register containing a BCD encoding of the EHCI revision number supported by this host
 * controller. The most significant byte of this register represents a major revision and the
 * least significant byte is the minor revision.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short HCIVERSION : 16; //!< Host Controller Interface Version Number  Default value is '10h', which means EHCI rev1.0.
    } B;
} hw_usbc__hciversion_t;
#endif

/*
 * constants & macros for entire USBC__HCIVERSION register
 */
#define HW_USBC__HCIVERSION_ADDR      (REGS_USBC_BASE + 0x102)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCIVERSION           (*(volatile hw_usbc__hciversion_t *) HW_USBC__HCIVERSION_ADDR)
#define HW_USBC__HCIVERSION_RD()      (HW_USBC__HCIVERSION.U)
#define HW_USBC__HCIVERSION_WR(v)     (HW_USBC__HCIVERSION.U = (v))
#define HW_USBC__HCIVERSION_SET(v)    (HW_USBC__HCIVERSION_WR(HW_USBC__HCIVERSION_RD() |  (v)))
#define HW_USBC__HCIVERSION_CLR(v)    (HW_USBC__HCIVERSION_WR(HW_USBC__HCIVERSION_RD() & ~(v)))
#define HW_USBC__HCIVERSION_TOG(v)    (HW_USBC__HCIVERSION_WR(HW_USBC__HCIVERSION_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HCIVERSION bitfields
 */

/* --- Register HW_USBC__HCIVERSION, field HCIVERSION
 *
 * Host Controller Interface Version Number  Default value is '10h', which means EHCI rev1.0.
 */

#define BP_USBC__HCIVERSION_HCIVERSION      0
#define BM_USBC__HCIVERSION_HCIVERSION      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCIVERSION_HCIVERSION(v)   ((((reg32_t) v) << 0) & BM_USBC__HCIVERSION_HCIVERSION)
#else
#define BF_USBC__HCIVERSION_HCIVERSION(v)   (((v) << 0) & BM_USBC__HCIVERSION_HCIVERSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCIVERSION_HCIVERSION(v)   BF_CS1(USBC__HCIVERSION, HCIVERSION, v)
#endif

/*!
 * @brief HW_USBC__HCSPARAMS - Host Controller Structural Parameters
 *
 * The following figure shows the port steering logic capabilities of Host Control Structural
 * Parameters (n_HCSPARAMS).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned N_PORTS : 4; //!< Number of downstream ports. This field specifies the number of physical downstream ports implemented on this host controller. The value of this field determines how many port registers are addressable in the Operational Register.  Valid values are in the range of 1h to Fh. A zero in this field is undefined.  These bits are always set to '0001b' because all 4 controller cores are Single-Port Host.
        unsigned PPC : 1; //!< Port Power Control  This field indicates whether the host controller implementation includes port power control. A one indicates the ports have port power switches. A zero indicates the ports do not have port power switches. The value of this field affects the functionality of the Port Power field in each port status and control register
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned N_PCC : 4; //!< Number of Ports per Companion Controller  This field indicates the number of ports supported per internal Companion Controller. It is used to indicate the port routing configuration to the system software.  For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and the last two are routed to companion controller 2. The number in this field must be consistent with N_PORTS and N_CC.  These bits are '0000b' in all 4 controller core.
        unsigned N_CC : 4; //!< Number of Companion Controller (N_CC).  This field indicates the number of companion controllers associated with this USB2.0 host controller.  These bits are '0000b' in all 4 controller core.
        unsigned PI : 1; //!< Port Indicators (P INDICATOR)  This bit indicates whether the ports support port indicator control. When set to one, the port status and control registers include a read/writeable field for controlling the state of the port indicator  This bit is "1b" in all 4 controller core.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned N_PTT : 4; //!< Number of Ports per Transaction Translator (N_PTT). Default value '0000b'  This field indicates the number of ports assigned to each transaction translator within the USB2.0 host controller.  These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned N_TT : 4; //!< Number of Transaction Translators (N_TT). Default value '0000b'  This field indicates the number of embedded transaction translators associated with the USB2.0 host controller.  These bits would be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_usbc__hcsparams_t;
#endif

/*
 * constants & macros for entire USBC__HCSPARAMS register
 */
#define HW_USBC__HCSPARAMS_ADDR      (REGS_USBC_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCSPARAMS           (*(volatile hw_usbc__hcsparams_t *) HW_USBC__HCSPARAMS_ADDR)
#define HW_USBC__HCSPARAMS_RD()      (HW_USBC__HCSPARAMS.U)
#define HW_USBC__HCSPARAMS_WR(v)     (HW_USBC__HCSPARAMS.U = (v))
#define HW_USBC__HCSPARAMS_SET(v)    (HW_USBC__HCSPARAMS_WR(HW_USBC__HCSPARAMS_RD() |  (v)))
#define HW_USBC__HCSPARAMS_CLR(v)    (HW_USBC__HCSPARAMS_WR(HW_USBC__HCSPARAMS_RD() & ~(v)))
#define HW_USBC__HCSPARAMS_TOG(v)    (HW_USBC__HCSPARAMS_WR(HW_USBC__HCSPARAMS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HCSPARAMS bitfields
 */

/* --- Register HW_USBC__HCSPARAMS, field N_PORTS
 *
 * Number of downstream ports. This field specifies the number of physical downstream ports
 * implemented on this host controller. The value of this field determines how many port
 * registers are addressable in the Operational Register.  Valid values are in the range of 1h to
 * Fh. A zero in this field is undefined.  These bits are always set to '0001b' because all 4
 * controller cores are Single-Port                                 Host.
 */

#define BP_USBC__HCSPARAMS_N_PORTS      0
#define BM_USBC__HCSPARAMS_N_PORTS      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_N_PORTS(v)   ((((reg32_t) v) << 0) & BM_USBC__HCSPARAMS_N_PORTS)
#else
#define BF_USBC__HCSPARAMS_N_PORTS(v)   (((v) << 0) & BM_USBC__HCSPARAMS_N_PORTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_N_PORTS(v)   BF_CS1(USBC__HCSPARAMS, N_PORTS, v)
#endif

/* --- Register HW_USBC__HCSPARAMS, field PPC
 *
 * Port Power Control  This field indicates whether the host controller implementation includes port
 * power                                 control. A one indicates the ports have port power
 * switches. A zero indicates the ports                                 do not have port power
 * switches. The value of this field affects the functionality of
 * the Port Power field in each port status and control register
 */

#define BP_USBC__HCSPARAMS_PPC      4
#define BM_USBC__HCSPARAMS_PPC      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_PPC(v)   ((((reg32_t) v) << 4) & BM_USBC__HCSPARAMS_PPC)
#else
#define BF_USBC__HCSPARAMS_PPC(v)   (((v) << 4) & BM_USBC__HCSPARAMS_PPC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_PPC(v)   BF_CS1(USBC__HCSPARAMS, PPC, v)
#endif

/* --- Register HW_USBC__HCSPARAMS, field N_PCC
 *
 * Number of Ports per Companion Controller  This field indicates the number of ports supported per
 * internal Companion Controller. It                                 is used to indicate the port
 * routing configuration to the system software.  For example, if N_PORTS has a value of 6 and N_CC
 * has a value of 2 then N_PCC could have                                 a value of 3. The
 * convention is that the first N_PCC ports are assumed to be routed to
 * companion controller 1, the next N_PCC ports to companion controller 2, etc. In the
 * previous example, the N_PCC could have been 4, where the first 4 are routed to companion
 * controller 1 and the last two are routed to companion controller 2. The number in this
 * field must be consistent with N_PORTS and N_CC.  These bits are '0000b' in all 4 controller core.
 */

#define BP_USBC__HCSPARAMS_N_PCC      8
#define BM_USBC__HCSPARAMS_N_PCC      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_N_PCC(v)   ((((reg32_t) v) << 8) & BM_USBC__HCSPARAMS_N_PCC)
#else
#define BF_USBC__HCSPARAMS_N_PCC(v)   (((v) << 8) & BM_USBC__HCSPARAMS_N_PCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_N_PCC(v)   BF_CS1(USBC__HCSPARAMS, N_PCC, v)
#endif

/* --- Register HW_USBC__HCSPARAMS, field N_CC
 *
 * Number of Companion Controller (N_CC).  This field indicates the number of companion controllers
 * associated with this USB2.0 host                                 controller.  These bits are
 * '0000b' in all 4 controller core.
 */

#define BP_USBC__HCSPARAMS_N_CC      12
#define BM_USBC__HCSPARAMS_N_CC      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_N_CC(v)   ((((reg32_t) v) << 12) & BM_USBC__HCSPARAMS_N_CC)
#else
#define BF_USBC__HCSPARAMS_N_CC(v)   (((v) << 12) & BM_USBC__HCSPARAMS_N_CC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_N_CC(v)   BF_CS1(USBC__HCSPARAMS, N_CC, v)
#endif

/* --- Register HW_USBC__HCSPARAMS, field PI
 *
 * Port Indicators (P INDICATOR)  This bit indicates whether the ports support port indicator
 * control. When set to one, the                                 port status and control registers
 * include a read/writeable field for controlling the                                 state of the
 * port indicator  This bit is "1b" in all 4 controller core.
 */

#define BP_USBC__HCSPARAMS_PI      16
#define BM_USBC__HCSPARAMS_PI      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_PI(v)   ((((reg32_t) v) << 16) & BM_USBC__HCSPARAMS_PI)
#else
#define BF_USBC__HCSPARAMS_PI(v)   (((v) << 16) & BM_USBC__HCSPARAMS_PI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_PI(v)   BF_CS1(USBC__HCSPARAMS, PI, v)
#endif

/* --- Register HW_USBC__HCSPARAMS, field N_PTT
 *
 * Number of Ports per Transaction Translator (N_PTT). Default value '0000b'  This field indicates
 * the number of ports assigned to each transaction translator within
 * the USB2.0 host controller.  These bits would be set to equal N_PORTS for Multi-Port Host, and
 * '0000b' for Single-Port                                 Host.
 */

#define BP_USBC__HCSPARAMS_N_PTT      20
#define BM_USBC__HCSPARAMS_N_PTT      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_N_PTT(v)   ((((reg32_t) v) << 20) & BM_USBC__HCSPARAMS_N_PTT)
#else
#define BF_USBC__HCSPARAMS_N_PTT(v)   (((v) << 20) & BM_USBC__HCSPARAMS_N_PTT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_N_PTT(v)   BF_CS1(USBC__HCSPARAMS, N_PTT, v)
#endif

/* --- Register HW_USBC__HCSPARAMS, field N_TT
 *
 * Number of Transaction Translators (N_TT). Default value '0000b'  This field indicates the number
 * of embedded transaction translators associated with the                                 USB2.0
 * host controller.  These bits would be set to '0001b' for Multi-Port Host, and '0000b' for Single-
 * Port                                 Host.
 */

#define BP_USBC__HCSPARAMS_N_TT      24
#define BM_USBC__HCSPARAMS_N_TT      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCSPARAMS_N_TT(v)   ((((reg32_t) v) << 24) & BM_USBC__HCSPARAMS_N_TT)
#else
#define BF_USBC__HCSPARAMS_N_TT(v)   (((v) << 24) & BM_USBC__HCSPARAMS_N_TT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCSPARAMS_N_TT(v)   BF_CS1(USBC__HCSPARAMS, N_TT, v)
#endif

/*!
 * @brief HW_USBC__HCCPARAMS - Host Controller Capability Parameters
 *
 * This register identifies multiple mode control (time-base bit functionality), addressing
 * capability.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADC : 1; //!< 64-bit Addressing Capability  This bit is set '0b' in all 4 controller core, no 64-bit addressing capability is supported.
        unsigned PFL : 1; //!< Programmable Frame List Flag  If this bit is set to zero, then the system software must use a frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size field is a read-only register and must be set to zero.  If set to a one, then the system software can specify and use a smaller frame list and configure the host controller via the USBCMD register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This requirement ensures that the frame list is always physically contiguous.  This bit is set '1b' in all 4 controller core.
        unsigned ASP : 1; //!< Asynchronous Schedule Park Capability  If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register.  This bit is set '1b' in all 4 controller core.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned IST : 4; //!< Isochronous Scheduling Threshold.  This field indicates, relative to the current position of the executing host controller, where software can reliably update the isochronous schedule. When bit [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a host controller can hold a set of isochronous data structures (one or more) before flushing the state. When bit [7] is a one, then host software assumes the host controller may cache an isochronous data structure for an entire frame.  These bits are set '00h' in all 4 controller core.
        unsigned EECP : 8; //!< EHCI Extended Capabilities Pointer.  This field indicates the existence of a capabilities list. A value of 00h indicates no extended capabilities are implemented. A non-zero value in this register indicates the offset in PCI configuration space of the first EHCI extended capability. The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI header defined for this class of device.  These bits are set '00h' in all 4 controller core.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_usbc__hccparams_t;
#endif

/*
 * constants & macros for entire USBC__HCCPARAMS register
 */
#define HW_USBC__HCCPARAMS_ADDR      (REGS_USBC_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCCPARAMS           (*(volatile hw_usbc__hccparams_t *) HW_USBC__HCCPARAMS_ADDR)
#define HW_USBC__HCCPARAMS_RD()      (HW_USBC__HCCPARAMS.U)
#define HW_USBC__HCCPARAMS_WR(v)     (HW_USBC__HCCPARAMS.U = (v))
#define HW_USBC__HCCPARAMS_SET(v)    (HW_USBC__HCCPARAMS_WR(HW_USBC__HCCPARAMS_RD() |  (v)))
#define HW_USBC__HCCPARAMS_CLR(v)    (HW_USBC__HCCPARAMS_WR(HW_USBC__HCCPARAMS_RD() & ~(v)))
#define HW_USBC__HCCPARAMS_TOG(v)    (HW_USBC__HCCPARAMS_WR(HW_USBC__HCCPARAMS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__HCCPARAMS bitfields
 */

/* --- Register HW_USBC__HCCPARAMS, field ADC
 *
 * 64-bit Addressing Capability  This bit is set '0b' in all 4 controller core, no 64-bit addressing
 * capability is                                 supported.
 */

#define BP_USBC__HCCPARAMS_ADC      0
#define BM_USBC__HCCPARAMS_ADC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCCPARAMS_ADC(v)   ((((reg32_t) v) << 0) & BM_USBC__HCCPARAMS_ADC)
#else
#define BF_USBC__HCCPARAMS_ADC(v)   (((v) << 0) & BM_USBC__HCCPARAMS_ADC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCCPARAMS_ADC(v)   BF_CS1(USBC__HCCPARAMS, ADC, v)
#endif

/* --- Register HW_USBC__HCCPARAMS, field PFL
 *
 * Programmable Frame List Flag  If this bit is set to zero, then the system software must use a
 * frame list length of 1024                                 elements with this host controller. The
 * USBCMD register Frame List Size field is a                                 read-only register and
 * must be set to zero.  If set to a one, then the system software can specify and use a smaller
 * frame list and                                 configure the host controller via the USBCMD
 * register Frame List Size field. The frame                                 list must always be
 * aligned on a 4K-page boundary. This requirement ensures that the
 * frame list is always physically contiguous.  This bit is set '1b' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMS_PFL      1
#define BM_USBC__HCCPARAMS_PFL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCCPARAMS_PFL(v)   ((((reg32_t) v) << 1) & BM_USBC__HCCPARAMS_PFL)
#else
#define BF_USBC__HCCPARAMS_PFL(v)   (((v) << 1) & BM_USBC__HCCPARAMS_PFL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCCPARAMS_PFL(v)   BF_CS1(USBC__HCCPARAMS, PFL, v)
#endif

/* --- Register HW_USBC__HCCPARAMS, field ASP
 *
 * Asynchronous Schedule Park Capability  If this bit is set to a one, then the host controller
 * supports the park feature for                                 high-speed queue heads in the
 * Asynchronous Schedule. The feature can be disabled or                                 enabled and
 * set to a specific level by using the Asynchronous Schedule Park Mode
 * Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD
 * register.  This bit is set '1b' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMS_ASP      2
#define BM_USBC__HCCPARAMS_ASP      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCCPARAMS_ASP(v)   ((((reg32_t) v) << 2) & BM_USBC__HCCPARAMS_ASP)
#else
#define BF_USBC__HCCPARAMS_ASP(v)   (((v) << 2) & BM_USBC__HCCPARAMS_ASP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCCPARAMS_ASP(v)   BF_CS1(USBC__HCCPARAMS, ASP, v)
#endif

/* --- Register HW_USBC__HCCPARAMS, field IST
 *
 * Isochronous Scheduling Threshold.  This field indicates, relative to the current position of the
 * executing host controller,                                 where software can reliably update the
 * isochronous schedule. When bit [7] is zero, the                                 value of the
 * least significant 3 bits indicates the number of micro-frames a host
 * controller can hold a set of isochronous data structures (one or more) before flushing
 * the state. When bit [7] is a one, then host software assumes the host controller may
 * cache an isochronous data structure for an entire frame.  These bits are set '00h' in all 4
 * controller core.
 */

#define BP_USBC__HCCPARAMS_IST      4
#define BM_USBC__HCCPARAMS_IST      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCCPARAMS_IST(v)   ((((reg32_t) v) << 4) & BM_USBC__HCCPARAMS_IST)
#else
#define BF_USBC__HCCPARAMS_IST(v)   (((v) << 4) & BM_USBC__HCCPARAMS_IST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCCPARAMS_IST(v)   BF_CS1(USBC__HCCPARAMS, IST, v)
#endif

/* --- Register HW_USBC__HCCPARAMS, field EECP
 *
 * EHCI Extended Capabilities Pointer.  This field indicates the existence of a capabilities list. A
 * value of 00h indicates no                                 extended capabilities are implemented.
 * A non-zero value in this register indicates the                                 offset in PCI
 * configuration space of the first EHCI extended capability. The pointer
 * value must be 40h or greater if implemented to maintain the consistency of the PCI
 * header defined for this class of device.  These bits are set '00h' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMS_EECP      8
#define BM_USBC__HCCPARAMS_EECP      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__HCCPARAMS_EECP(v)   ((((reg32_t) v) << 8) & BM_USBC__HCCPARAMS_EECP)
#else
#define BF_USBC__HCCPARAMS_EECP(v)   (((v) << 8) & BM_USBC__HCCPARAMS_EECP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__HCCPARAMS_EECP(v)   BF_CS1(USBC__HCCPARAMS, EECP, v)
#endif

/*!
 * @brief HW_USBC_UOG_DCIVERSION - Device Controller Interface Version
 *
 * This register indicates the two-byte BCD encoding of the device controller interface version
 * number.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg16_t  U;
    struct
    {
        unsigned short DCIVERSION : 16; //!< Device Controller Interface Version Number  Default value is '01h', which means rev0.1.
    } B;
} hw_usbc_uog_dciversion_t;
#endif

/*
 * constants & macros for entire USBC_UOG_DCIVERSION register
 */
#define HW_USBC_UOG_DCIVERSION_ADDR      (REGS_USBC_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_DCIVERSION           (*(volatile hw_usbc_uog_dciversion_t *) HW_USBC_UOG_DCIVERSION_ADDR)
#define HW_USBC_UOG_DCIVERSION_RD()      (HW_USBC_UOG_DCIVERSION.U)
#define HW_USBC_UOG_DCIVERSION_WR(v)     (HW_USBC_UOG_DCIVERSION.U = (v))
#define HW_USBC_UOG_DCIVERSION_SET(v)    (HW_USBC_UOG_DCIVERSION_WR(HW_USBC_UOG_DCIVERSION_RD() |  (v)))
#define HW_USBC_UOG_DCIVERSION_CLR(v)    (HW_USBC_UOG_DCIVERSION_WR(HW_USBC_UOG_DCIVERSION_RD() & ~(v)))
#define HW_USBC_UOG_DCIVERSION_TOG(v)    (HW_USBC_UOG_DCIVERSION_WR(HW_USBC_UOG_DCIVERSION_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_DCIVERSION bitfields
 */

/* --- Register HW_USBC_UOG_DCIVERSION, field DCIVERSION
 *
 * Device Controller Interface Version Number  Default value is '01h', which means rev0.1.
 */

#define BP_USBC_UOG_DCIVERSION_DCIVERSION      0
#define BM_USBC_UOG_DCIVERSION_DCIVERSION      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_DCIVERSION_DCIVERSION(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_DCIVERSION_DCIVERSION)
#else
#define BF_USBC_UOG_DCIVERSION_DCIVERSION(v)   (((v) << 0) & BM_USBC_UOG_DCIVERSION_DCIVERSION)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_DCIVERSION_DCIVERSION(v)   BF_CS1(USBC_UOG_DCIVERSION, DCIVERSION, v)
#endif

/*!
 * @brief HW_USBC_UOG_DCCPARAMS - Device Controller Capability Parameters
 *
 * These fields describe the overall device capability of the controller.  This register is only
 * available in OTG controller core.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DEN : 5; //!< Device Endpoint Number  This field indicates the number of endpoints built into the device controller. If this controller is not device capable, then this field will be zero. Valid values are 0 - 15.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned DC : 1; //!< Device Capable  When this bit is 1, this controller is capable of operating as a USB 2.0 device.
        unsigned HC : 1; //!< Host Capable  When this bit is 1, this controller is capable of operating as an EHCI compatible USB 2.0 host controller.
        unsigned RESERVED1 : 23; //!< Reserved
    } B;
} hw_usbc_uog_dccparams_t;
#endif

/*
 * constants & macros for entire USBC_UOG_DCCPARAMS register
 */
#define HW_USBC_UOG_DCCPARAMS_ADDR      (REGS_USBC_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_DCCPARAMS           (*(volatile hw_usbc_uog_dccparams_t *) HW_USBC_UOG_DCCPARAMS_ADDR)
#define HW_USBC_UOG_DCCPARAMS_RD()      (HW_USBC_UOG_DCCPARAMS.U)
#define HW_USBC_UOG_DCCPARAMS_WR(v)     (HW_USBC_UOG_DCCPARAMS.U = (v))
#define HW_USBC_UOG_DCCPARAMS_SET(v)    (HW_USBC_UOG_DCCPARAMS_WR(HW_USBC_UOG_DCCPARAMS_RD() |  (v)))
#define HW_USBC_UOG_DCCPARAMS_CLR(v)    (HW_USBC_UOG_DCCPARAMS_WR(HW_USBC_UOG_DCCPARAMS_RD() & ~(v)))
#define HW_USBC_UOG_DCCPARAMS_TOG(v)    (HW_USBC_UOG_DCCPARAMS_WR(HW_USBC_UOG_DCCPARAMS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_DCCPARAMS bitfields
 */

/* --- Register HW_USBC_UOG_DCCPARAMS, field DEN
 *
 * Device Endpoint Number  This field indicates the number of endpoints built into the device
 * controller. If this                                 controller is not device capable, then this
 * field will be zero. Valid values are 0 -                                 15.
 */

#define BP_USBC_UOG_DCCPARAMS_DEN      0
#define BM_USBC_UOG_DCCPARAMS_DEN      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_DCCPARAMS_DEN(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_DCCPARAMS_DEN)
#else
#define BF_USBC_UOG_DCCPARAMS_DEN(v)   (((v) << 0) & BM_USBC_UOG_DCCPARAMS_DEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_DCCPARAMS_DEN(v)   BF_CS1(USBC_UOG_DCCPARAMS, DEN, v)
#endif

/* --- Register HW_USBC_UOG_DCCPARAMS, field DC
 *
 * Device Capable  When this bit is 1, this controller is capable of operating as a USB 2.0 device.
 */

#define BP_USBC_UOG_DCCPARAMS_DC      7
#define BM_USBC_UOG_DCCPARAMS_DC      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_DCCPARAMS_DC(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_DCCPARAMS_DC)
#else
#define BF_USBC_UOG_DCCPARAMS_DC(v)   (((v) << 7) & BM_USBC_UOG_DCCPARAMS_DC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_DCCPARAMS_DC(v)   BF_CS1(USBC_UOG_DCCPARAMS, DC, v)
#endif

/* --- Register HW_USBC_UOG_DCCPARAMS, field HC
 *
 * Host Capable  When this bit is 1, this controller is capable of operating as an EHCI compatible
 * USB 2.0                                 host controller.
 */

#define BP_USBC_UOG_DCCPARAMS_HC      8
#define BM_USBC_UOG_DCCPARAMS_HC      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_DCCPARAMS_HC(v)   ((((reg32_t) v) << 8) & BM_USBC_UOG_DCCPARAMS_HC)
#else
#define BF_USBC_UOG_DCCPARAMS_HC(v)   (((v) << 8) & BM_USBC_UOG_DCCPARAMS_HC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_DCCPARAMS_HC(v)   BF_CS1(USBC_UOG_DCCPARAMS, HC, v)
#endif

/*!
 * @brief HW_USBC__USBCMD - USB Command Register
 *
 * The Command Register indicates the command to be executed by the serial bus host/device
 * controller. Writing to the register causes a command to be executed.  *: ASPE,ASP[1],ASP[0] reset
 * value: '0b' for OTG core; '1b' for Host1/Host2/Host3 core.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RS : 1; //!< Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop.  Host operation mode:  When set to '1b', the Controller proceeds with the execution of the schedule. The Controller continues execution as long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the current transaction on the USB and then halts. The HC Halted bit in the status register indicates when the Controller has finished the transaction and has entered the stopped state. Software should not write a one to this field unless the controller is in the Halted state (that is, HCHalted in the USBSTS register is a one).  Device operation mode:  Writing a one to this bit will cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is not directly connected to the pull-up enable, as the pull-up will become disabled upon transitioning into high-speed mode. Software should use this bit to prevent an attach event before the controller has been properly initialized. Writing a 0 to this will cause a detach event.
        unsigned RST : 1; //!< Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register.  Host operation mode:  When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Any transaction currently in progress on USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset an actively running host controller will result in undefined behavior.  Device operation mode:  When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Writing a one to this bit when the device is in the attached state is not recommended, because the effect on an attached host is undefined. In order to ensure that the device is not in an attached state before initiating a device controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be set to 0.
        unsigned FS : 2; //!< See description at bit 15
        unsigned PSE : 1; //!< Periodic Schedule Enable- Read/Write. Default 0b.  This bit controls whether the host controller skips processing the Periodic Schedule.  Only the host controller uses this bit.  Values Meaning
        unsigned ASE : 1; //!< Asynchronous Schedule Enable - Read/Write. Default 0b.  This bit controls whether the host controller skips processing the Asynchronous Schedule.  Only the host controller uses this bit.  Values Meaning
        unsigned IAA : 1; //!< Interrupt on Async Advance Doorbell - Read/Write.  This bit is used as a doorbell by software to tell the host controller to issue an interrupt the next time it advances asynchronous schedule. Software must write a 1 to this bit to ring the doorbell.  When the host controller has evicted all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then the host controller will assert an interrupt at the next interrupt threshold.  The host controller sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS register to one. Software should not write a one to this bit when the asynchronous schedule is inactive. Doing so will yield undefined results.  This bit is only used in host mode. Writing a one to this bit when device mode is selected will have undefined results.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ASP : 2; //!< Asynchronous Schedule Park Mode Count - Read/Write.  If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults to zero and is Read-Only. It contains a count of the number of successive transactions the host controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not write a zero to this bit when Park Mode Enable is a one as this will result in undefined behavior.  This field is set to 3h in all 4 controller core.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ASPE : 1; //!< Asynchronous Schedule Park Mode Enable - Read/Write.  If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is one, Park mode is enabled. When this bit is a zero, Park mode is disabled.  This field is set to '1b' in this implementation.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned SUTW : 1; //!< Setup TripWire - Read/Write. [device mode only]  This bit is used as a semaphore to ensure that the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a hazard when new setup data arrives while the DCD is copying the setup data payload from the QH for a previous setup packet. This bit is set and cleared by software.  This bit would also be cleared by hardware when a hazard detected.   For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned ATDTW : 1; //!< Add dTD TripWire - Read/Write. [device mode only]  This bit is used as a semaphore to ensure proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and cleared by software.  This bit would also be cleared by hardware when state machine is hazard region for which adding a dTD to a primed endpoint may go unrecognized.   For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned FS1 : 1; //!< See also bits 3-2  Frame List Size - (Read/Write or Read Only). [host mode only]  This field is Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one.  This field specifies the size of the frame list that controls which bits in the Frame Index Register should be used for the Frame List Current index.  This field is made up from USBCMD bits 15, 3 and 2.  Value Meaning
        unsigned ITC : 8; //!< Interrupt Threshold Control -Read/Write.  The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below.  Value Maximum Interrupt Interval
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc__usbcmd_t;
#endif

/*
 * constants & macros for entire USBC__USBCMD register
 */
#define HW_USBC__USBCMD_ADDR      (REGS_USBC_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBCMD           (*(volatile hw_usbc__usbcmd_t *) HW_USBC__USBCMD_ADDR)
#define HW_USBC__USBCMD_RD()      (HW_USBC__USBCMD.U)
#define HW_USBC__USBCMD_WR(v)     (HW_USBC__USBCMD.U = (v))
#define HW_USBC__USBCMD_SET(v)    (HW_USBC__USBCMD_WR(HW_USBC__USBCMD_RD() |  (v)))
#define HW_USBC__USBCMD_CLR(v)    (HW_USBC__USBCMD_WR(HW_USBC__USBCMD_RD() & ~(v)))
#define HW_USBC__USBCMD_TOG(v)    (HW_USBC__USBCMD_WR(HW_USBC__USBCMD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__USBCMD bitfields
 */

/* --- Register HW_USBC__USBCMD, field RS
 *
 * Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop.  Host operation mode:  When set to '1b',
 * the Controller proceeds with the execution of the schedule. The
 * Controller continues execution as long as this bit is set to a one. When this bit is set
 * to 0, the Host Controller completes the current transaction on the USB and then halts.
 * The HC Halted bit in the status register indicates when the Controller has finished the
 * transaction and has entered the stopped state. Software should not write a one to this
 * field unless the controller is in the Halted state (that is, HCHalted in the USBSTS
 * register is a one).  Device operation mode:  Writing a one to this bit will cause the controller
 * to enable a pull-up on D+ and                                 initiate an attach event. This
 * control bit is not directly connected to the pull-up                                 enable, as
 * the pull-up will become disabled upon transitioning into high-speed mode.
 * Software should use this bit to prevent an attach event before the controller has been
 * properly initialized. Writing a 0 to this will cause a detach event.
 */

#define BP_USBC__USBCMD_RS      0
#define BM_USBC__USBCMD_RS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_RS(v)   ((((reg32_t) v) << 0) & BM_USBC__USBCMD_RS)
#else
#define BF_USBC__USBCMD_RS(v)   (((v) << 0) & BM_USBC__USBCMD_RS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_RS(v)   BF_CS1(USBC__USBCMD, RS, v)
#endif

/* --- Register HW_USBC__USBCMD, field RST
 *
 * Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller.
 * This bit is set to zero by the Host/Device Controller when the reset process is
 * complete. Software cannot terminate the reset process early by writing a zero to this
 * register.  Host operation mode:  When software writes a one to this bit, the Controller resets
 * its internal pipelines,                                 timers, counters, state machines etc. to
 * their initial value. Any transaction currently                                 in progress on USB
 * is immediately terminated. A USB reset is not driven on downstream
 * ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS
 * register is a zero. Attempting to reset an actively running host controller will result
 * in undefined behavior.  Device operation mode:  When software writes a one to this bit, the
 * Controller resets its internal pipelines,                                 timers, counters, state
 * machines etc. to their initial value. Writing a one to this bit
 * when the device is in the attached state is not recommended, because the effect on an
 * attached host is undefined. In order to ensure that the device is not in an attached
 * state before initiating a device controller reset, all primed endpoints should be
 * flushed and the USBCMD Run/Stop bit should be set to 0.
 */

#define BP_USBC__USBCMD_RST      1
#define BM_USBC__USBCMD_RST      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_RST(v)   ((((reg32_t) v) << 1) & BM_USBC__USBCMD_RST)
#else
#define BF_USBC__USBCMD_RST(v)   (((v) << 1) & BM_USBC__USBCMD_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_RST(v)   BF_CS1(USBC__USBCMD, RST, v)
#endif

/* --- Register HW_USBC__USBCMD, field FS
 *
 * See description at bit 15
 */

#define BP_USBC__USBCMD_FS      2
#define BM_USBC__USBCMD_FS      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_FS(v)   ((((reg32_t) v) << 2) & BM_USBC__USBCMD_FS)
#else
#define BF_USBC__USBCMD_FS(v)   (((v) << 2) & BM_USBC__USBCMD_FS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_FS(v)   BF_CS1(USBC__USBCMD, FS, v)
#endif

/* --- Register HW_USBC__USBCMD, field PSE
 *
 * Periodic Schedule Enable- Read/Write. Default 0b.  This bit controls whether the host controller
 * skips processing the Periodic Schedule.  Only the host controller uses this bit.  Values Meaning
 */

#define BP_USBC__USBCMD_PSE      4
#define BM_USBC__USBCMD_PSE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_PSE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBCMD_PSE)
#else
#define BF_USBC__USBCMD_PSE(v)   (((v) << 4) & BM_USBC__USBCMD_PSE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_PSE(v)   BF_CS1(USBC__USBCMD, PSE, v)
#endif

/* --- Register HW_USBC__USBCMD, field ASE
 *
 * Asynchronous Schedule Enable - Read/Write. Default 0b.  This bit controls whether the host
 * controller skips processing the Asynchronous                                 Schedule.  Only the
 * host controller uses this bit.  Values Meaning
 */

#define BP_USBC__USBCMD_ASE      5
#define BM_USBC__USBCMD_ASE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_ASE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBCMD_ASE)
#else
#define BF_USBC__USBCMD_ASE(v)   (((v) << 5) & BM_USBC__USBCMD_ASE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_ASE(v)   BF_CS1(USBC__USBCMD, ASE, v)
#endif

/* --- Register HW_USBC__USBCMD, field IAA
 *
 * Interrupt on Async Advance Doorbell - Read/Write.  This bit is used as a doorbell by software to
 * tell the host controller to issue an                                 interrupt the next time it
 * advances asynchronous schedule. Software must write a 1 to                                 this
 * bit to ring the doorbell.  When the host controller has evicted all appropriate cached schedule
 * states, it sets the                                 Interrupt on Async Advance status bit in the
 * USBSTS register. If the Interrupt on Sync                                 Advance Enable bit in
 * the USBINTR register is one, then the host controller will assert
 * an interrupt at the next interrupt threshold.  The host controller sets this bit to zero after it
 * has set the Interrupt on Sync Advance                                 status bit in the USBSTS
 * register to one. Software should not write a one to this bit                                 when
 * the asynchronous schedule is inactive. Doing so will yield undefined results.  This bit is only
 * used in host mode. Writing a one to this bit when device mode is
 * selected will have undefined results.
 */

#define BP_USBC__USBCMD_IAA      6
#define BM_USBC__USBCMD_IAA      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_IAA(v)   ((((reg32_t) v) << 6) & BM_USBC__USBCMD_IAA)
#else
#define BF_USBC__USBCMD_IAA(v)   (((v) << 6) & BM_USBC__USBCMD_IAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_IAA(v)   BF_CS1(USBC__USBCMD, IAA, v)
#endif

/* --- Register HW_USBC__USBCMD, field ASP
 *
 * Asynchronous Schedule Park Mode Count - Read/Write.  If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then                                 this field defaults to 3h
 * and is R/W. Otherwise it defaults to zero and is Read-Only. It
 * contains a count of the number of successive transactions the host controller is allowed
 * to execute from a high-speed queue head on the Asynchronous schedule before continuing
 * traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not
 * write a zero to this bit when Park Mode Enable is a one as this will result in
 * undefined behavior.  This field is set to 3h in all 4 controller core.
 */

#define BP_USBC__USBCMD_ASP      8
#define BM_USBC__USBCMD_ASP      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_ASP(v)   ((((reg32_t) v) << 8) & BM_USBC__USBCMD_ASP)
#else
#define BF_USBC__USBCMD_ASP(v)   (((v) << 8) & BM_USBC__USBCMD_ASP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_ASP(v)   BF_CS1(USBC__USBCMD, ASP, v)
#endif

/* --- Register HW_USBC__USBCMD, field ASPE
 *
 * Asynchronous Schedule Park Mode Enable - Read/Write.  If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then                                 this bit defaults to a 1h
 * and is R/W. Otherwise the bit must be a zero and is RO.                                 Software
 * uses this bit to enable or disable Park mode. When this bit is one, Park mode
 * is enabled. When this bit is a zero, Park mode is disabled.  This field is set to '1b' in this
 * implementation.
 */

#define BP_USBC__USBCMD_ASPE      11
#define BM_USBC__USBCMD_ASPE      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_ASPE(v)   ((((reg32_t) v) << 11) & BM_USBC__USBCMD_ASPE)
#else
#define BF_USBC__USBCMD_ASPE(v)   (((v) << 11) & BM_USBC__USBCMD_ASPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_ASPE(v)   BF_CS1(USBC__USBCMD, ASPE, v)
#endif

/* --- Register HW_USBC__USBCMD, field SUTW
 *
 * Setup TripWire - Read/Write. [device mode only]  This bit is used as a semaphore to ensure that
 * the setup data payload of 8 bytes is                                 extracted from a QH by the
 * DCD without being corrupted. If the setup lockout mode is off
 * (SLOM bit in USB core register n_USBMODE, see )                                 then there is a
 * hazard when new setup data arrives while the DCD is copying the setup
 * data payload from the QH for a previous setup packet. This bit is set and cleared by
 * software.  This bit would also be cleared by hardware when a hazard detected.   For more
 * information on the use of this bit, see the Device
 * Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference
 * manual.
 */

#define BP_USBC__USBCMD_SUTW      13
#define BM_USBC__USBCMD_SUTW      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_SUTW(v)   ((((reg32_t) v) << 13) & BM_USBC__USBCMD_SUTW)
#else
#define BF_USBC__USBCMD_SUTW(v)   (((v) << 13) & BM_USBC__USBCMD_SUTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_SUTW(v)   BF_CS1(USBC__USBCMD, SUTW, v)
#endif

/* --- Register HW_USBC__USBCMD, field ATDTW
 *
 * Add dTD TripWire - Read/Write. [device mode only]  This bit is used as a semaphore to ensure
 * proper addition of a new dTD to an active                                 (primed) endpoint's
 * linked list. This bit is set and cleared by software.  This bit would also be cleared by hardware
 * when state machine is hazard region for which                                 adding a dTD to a
 * primed endpoint may go unrecognized.   For more information on the use of this bit, see the
 * Device                                     Operational Model section of the USB-HS OTG High-Speed
 * USB On-The-Go DEV reference                                     manual.
 */

#define BP_USBC__USBCMD_ATDTW      14
#define BM_USBC__USBCMD_ATDTW      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_ATDTW(v)   ((((reg32_t) v) << 14) & BM_USBC__USBCMD_ATDTW)
#else
#define BF_USBC__USBCMD_ATDTW(v)   (((v) << 14) & BM_USBC__USBCMD_ATDTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_ATDTW(v)   BF_CS1(USBC__USBCMD, ATDTW, v)
#endif

/* --- Register HW_USBC__USBCMD, field FS
 *
 * See also bits 3-2  Frame List Size - (Read/Write or Read Only). [host mode only]  This field is
 * Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers
 * is set to one.  This field specifies the size of the frame list that controls which bits in the
 * Frame                                 Index Register should be used for the Frame List Current
 * index.  This field is made up from USBCMD bits 15, 3 and 2.  Value Meaning
 */

#define BP_USBC__USBCMD_FS      15
#define BM_USBC__USBCMD_FS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_FS(v)   ((((reg32_t) v) << 15) & BM_USBC__USBCMD_FS)
#else
#define BF_USBC__USBCMD_FS(v)   (((v) << 15) & BM_USBC__USBCMD_FS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_FS(v)   BF_CS1(USBC__USBCMD, FS, v)
#endif

/* --- Register HW_USBC__USBCMD, field ITC
 *
 * Interrupt Threshold Control -Read/Write.  The system software uses this field to set the maximum
 * rate at which the host/device                                 controller will issue interrupts.
 * ITC contains the maximum interrupt interval measured                                 in micro-
 * frames. Valid values are shown below.  Value Maximum Interrupt Interval
 */

#define BP_USBC__USBCMD_ITC      16
#define BM_USBC__USBCMD_ITC      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMD_ITC(v)   ((((reg32_t) v) << 16) & BM_USBC__USBCMD_ITC)
#else
#define BF_USBC__USBCMD_ITC(v)   (((v) << 16) & BM_USBC__USBCMD_ITC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBCMD_ITC(v)   BF_CS1(USBC__USBCMD, ITC, v)
#endif

/*!
 * @brief HW_USBC__USBSTS - USB Status Register
 *
 * This register indicates various states of the Host/Device Controller and any pending
 * interrupts. This register does not indicate status resulting from a transaction on the
 * serial bus.  *HCH bit reset value: '0b' for OTG core, '1b' for Host1/Host2/Host3 core.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned UI : 1; //!< USB Interrupt (USBINT) - R/WC.  This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set.  This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        unsigned UEI : 1; //!< USB Error Interrupt (USBERRINT) - R/WC.  When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set  See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e. 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus, Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of host error interrupt conditions.  See section Device Error Matrix in the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.  The device controller detects resume signaling only.
        unsigned PCI : 1; //!< Port Change Detect - R/WC.  The Host Controller sets this bit to a one when on any port a Connect Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the result of a J-K transition on the suspended port.  The Device Controller sets this bit to a one when the port controller enters the full or high-speed operational state. When the port controller exits the full or high-speed operation states due to Reset or Suspend events, the notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
        unsigned FRI : 1; //!< Frame List Rollover - R/WC.  The Host Controller sets this bit to a one when the Frame List Index rolls over from its maximum value to zero. The exact value at which the rollover occurs depends on the frame list size. For example. If the frame list size (as programmed in the Frame List Size field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every time FHINDEX [12] toggles.  Only used in host operation mode.
        unsigned SEI : 1; //!< System Error- R/WC.  This bit is will be set to '1b' when an Error response is seen to a read on the system interface.
        unsigned AAI : 1; //!< Interrupt on Async Advance - R/WC.  System software can force the host controller to issue an interrupt the next time the host controller advances the asynchronous schedule by writing a one to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit indicates the assertion of that interrupt source.  Only used in host operation mode.
        unsigned URI : 1; //!< USB Reset Received - R/WC.  When the device controller detects a USB Reset and enters the default state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset Received status bit.  Only used in device operation mode.
        unsigned SRI : 1; //!< SOF Received - R/WC.  When the device controller detects a Start Of (micro) Frame, this bit will be set to a one. When a SOF is extremely late, the device controller will automatically set this bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is received.  Because the device controller is initialized to FS before connect, this bit will be set at an interval of 1ms during the prelude to connect and chirp.  In host mode, this bit will be set every 125us and can be used by host controller driver as a time base.  Software writes a 1 to this bit to clear it.
        unsigned SLI : 1; //!< DCSuspend - R/WC.  When a controller enters a suspend state from an active state, this bit will be set to a one. The device controller clears the bit upon exiting from a suspend state.  Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPII : 1; //!< ULPI Interrupt - R/WC.  This bit will be set '1b' by hardware when there is an event completion in ULPI viewport.  This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HCH : 1; //!< HCHaIted - Read Only.  This bit is a zero whenever the Run/Stop bit is a one. The Controller sets this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either by software or by the Controller hardware (for example, an internal error).  Only used in the host operation mode.  Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core.  This is because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
        unsigned RCL : 1; //!< Reclamation - Read Only.  This is a read-only status bit used to detect an empty asynchronous schedule.  Only used in the host operation mode.
        unsigned PS : 1; //!< Periodic Schedule Status - Read Only.  This bit reports the current real status of the Periodic Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Periodic Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either enabled (1) or disabled (0).  Only used in the host operation mode.
        unsigned AS : 1; //!< Asynchronous Schedule Status - Read Only.  This bit reports the current real status of the Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same value, the Asynchronous Schedule is either enabled (1) or disabled (0).  Only used in the host operation mode.
        unsigned NAKI : 1; //!< NAK Interrupt Bit--RO.  This bit is set by hardware when for a particular endpoint both the TX/RX Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
        unsigned RESERVED2 : 7; //!< Reserved
        unsigned TI0 : 1; //!< General Purpose Timer Interrupt 0(GPTINT0)--R/WC.  This bit is set when the counter in the GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
        unsigned TI1 : 1; //!< General Purpose Timer Interrupt 1(GPTINT1)--R/WC.  This bit is set when the counter in the GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
        unsigned RESERVED3 : 6; //!< Reserved
    } B;
} hw_usbc__usbsts_t;
#endif

/*
 * constants & macros for entire USBC__USBSTS register
 */
#define HW_USBC__USBSTS_ADDR      (REGS_USBC_BASE + 0x144)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBSTS           (*(volatile hw_usbc__usbsts_t *) HW_USBC__USBSTS_ADDR)
#define HW_USBC__USBSTS_RD()      (HW_USBC__USBSTS.U)
#define HW_USBC__USBSTS_WR(v)     (HW_USBC__USBSTS.U = (v))
#define HW_USBC__USBSTS_SET(v)    (HW_USBC__USBSTS_WR(HW_USBC__USBSTS_RD() |  (v)))
#define HW_USBC__USBSTS_CLR(v)    (HW_USBC__USBSTS_WR(HW_USBC__USBSTS_RD() & ~(v)))
#define HW_USBC__USBSTS_TOG(v)    (HW_USBC__USBSTS_WR(HW_USBC__USBSTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__USBSTS bitfields
 */

/* --- Register HW_USBC__USBSTS, field UI
 *
 * USB Interrupt (USBINT) - R/WC.  This bit is set by the Host/Device Controller when the cause of
 * an interrupt is a                                 completion of a USB transaction where the
 * Transfer Descriptor (TD) has an interrupt on                                 complete (IOC) bit
 * set.  This bit is also set by the Host/Device Controller when a short packet is detected. A
 * short packet is when the actual number of bytes received was less than the expected
 * number of bytes.
 */

#define BP_USBC__USBSTS_UI      0
#define BM_USBC__USBSTS_UI      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_UI(v)   ((((reg32_t) v) << 0) & BM_USBC__USBSTS_UI)
#else
#define BF_USBC__USBSTS_UI(v)   (((v) << 0) & BM_USBC__USBSTS_UI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_UI(v)   BF_CS1(USBC__USBSTS, UI, v)
#endif

/* --- Register HW_USBC__USBSTS, field UEI
 *
 * USB Error Interrupt (USBERRINT) - R/WC.  When completion of a USB transaction results in an error
 * condition, this bit is set by                                 the Host/Device Controller. This
 * bit is set along with the USBINT bit, if the TD on                                 which the
 * error interrupt occurred also had its interrupt on complete (IOC) bit set  See Section (Reference
 * Host Operation Model: Transfer/Transaction                                 Based Interrupt - i.e.
 * 4.15.1 in EHCI Enhanced Host Controller Interface Specification
 * for Universal Serial Bus, Revision 0.95, November 2000, Intel Corporation.
 * http://www.intel.com) for a complete list of host error interrupt conditions.  See section Device
 * Error Matrix in the USB-HS OTG High-Speed USB                                 On-The-Go DEV
 * reference manual.  The device controller detects resume signaling only.
 */

#define BP_USBC__USBSTS_UEI      1
#define BM_USBC__USBSTS_UEI      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_UEI(v)   ((((reg32_t) v) << 1) & BM_USBC__USBSTS_UEI)
#else
#define BF_USBC__USBSTS_UEI(v)   (((v) << 1) & BM_USBC__USBSTS_UEI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_UEI(v)   BF_CS1(USBC__USBSTS, UEI, v)
#endif

/* --- Register HW_USBC__USBSTS, field PCI
 *
 * Port Change Detect - R/WC.  The Host Controller sets this bit to a one when on any port a Connect
 * Status occurs, a                                 Port Enable/Disable Change occurs, or the Force
 * Port Resume bit is set as the result of                                 a J-K transition on the
 * suspended port.  The Device Controller sets this bit to a one when the port controller enters the
 * full or                                 high-speed operational state. When the port controller
 * exits the full or high-speed                                 operation states due to Reset or
 * Suspend events, the notification mechanisms are the USB                                 Reset
 * Received bit and the DCSuspend bits respectively.
 */

#define BP_USBC__USBSTS_PCI      2
#define BM_USBC__USBSTS_PCI      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_PCI(v)   ((((reg32_t) v) << 2) & BM_USBC__USBSTS_PCI)
#else
#define BF_USBC__USBSTS_PCI(v)   (((v) << 2) & BM_USBC__USBSTS_PCI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_PCI(v)   BF_CS1(USBC__USBSTS, PCI, v)
#endif

/* --- Register HW_USBC__USBSTS, field FRI
 *
 * Frame List Rollover - R/WC.  The Host Controller sets this bit to a one when the Frame List Index
 * rolls over from its                                 maximum value to zero. The exact value at
 * which the rollover occurs depends on the frame                                 list size. For
 * example. If the frame list size (as programmed in the Frame List Size
 * field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every
 * time FRINDEX [13] toggles. Similarly, if the size is 512, the Host Controller sets this
 * bit to a one every time FHINDEX [12] toggles.  Only used in host operation mode.
 */

#define BP_USBC__USBSTS_FRI      3
#define BM_USBC__USBSTS_FRI      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_FRI(v)   ((((reg32_t) v) << 3) & BM_USBC__USBSTS_FRI)
#else
#define BF_USBC__USBSTS_FRI(v)   (((v) << 3) & BM_USBC__USBSTS_FRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_FRI(v)   BF_CS1(USBC__USBSTS, FRI, v)
#endif

/* --- Register HW_USBC__USBSTS, field SEI
 *
 * System Error- R/WC.  This bit is will be set to '1b' when an Error response is seen to a read on
 * the system                                 interface.
 */

#define BP_USBC__USBSTS_SEI      4
#define BM_USBC__USBSTS_SEI      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_SEI(v)   ((((reg32_t) v) << 4) & BM_USBC__USBSTS_SEI)
#else
#define BF_USBC__USBSTS_SEI(v)   (((v) << 4) & BM_USBC__USBSTS_SEI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_SEI(v)   BF_CS1(USBC__USBSTS, SEI, v)
#endif

/* --- Register HW_USBC__USBSTS, field AAI
 *
 * Interrupt on Async Advance - R/WC.  System software can force the host controller to issue an
 * interrupt the next time the                                 host controller advances the
 * asynchronous schedule by writing a one to the Interrupt on                                 Async
 * Advance Doorbell bit in the n_USBCMD register. This status bit indicates the
 * assertion of that interrupt source.  Only used in host operation mode.
 */

#define BP_USBC__USBSTS_AAI      5
#define BM_USBC__USBSTS_AAI      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_AAI(v)   ((((reg32_t) v) << 5) & BM_USBC__USBSTS_AAI)
#else
#define BF_USBC__USBSTS_AAI(v)   (((v) << 5) & BM_USBC__USBSTS_AAI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_AAI(v)   BF_CS1(USBC__USBSTS, AAI, v)
#endif

/* --- Register HW_USBC__USBSTS, field URI
 *
 * USB Reset Received - R/WC.  When the device controller detects a USB Reset and enters the default
 * state, this bit                                 will be set to a one. Software can write a 1 to
 * this bit to clear the USB Reset Received                                 status bit.  Only used
 * in device operation mode.
 */

#define BP_USBC__USBSTS_URI      6
#define BM_USBC__USBSTS_URI      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_URI(v)   ((((reg32_t) v) << 6) & BM_USBC__USBSTS_URI)
#else
#define BF_USBC__USBSTS_URI(v)   (((v) << 6) & BM_USBC__USBSTS_URI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_URI(v)   BF_CS1(USBC__USBSTS, URI, v)
#endif

/* --- Register HW_USBC__USBSTS, field SRI
 *
 * SOF Received - R/WC.  When the device controller detects a Start Of (micro) Frame, this bit will
 * be set to a                                 one. When a SOF is extremely late, the device
 * controller will automatically set this bit                                 to indicate that an
 * SOF was expected. Therefore, this bit will be set roughly every 1ms
 * in device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF
 * that is received.  Because the device controller is initialized to FS before connect, this bit
 * will be set                                 at an interval of 1ms during the prelude to connect
 * and chirp.  In host mode, this bit will be set every 125us and can be used by host controller
 * driver                                 as a time base.  Software writes a 1 to this bit to clear
 * it.
 */

#define BP_USBC__USBSTS_SRI      7
#define BM_USBC__USBSTS_SRI      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_SRI(v)   ((((reg32_t) v) << 7) & BM_USBC__USBSTS_SRI)
#else
#define BF_USBC__USBSTS_SRI(v)   (((v) << 7) & BM_USBC__USBSTS_SRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_SRI(v)   BF_CS1(USBC__USBSTS, SRI, v)
#endif

/* --- Register HW_USBC__USBSTS, field SLI
 *
 * DCSuspend - R/WC.  When a controller enters a suspend state from an active state, this bit will
 * be set to a                                 one. The device controller clears the bit upon
 * exiting from a suspend state.  Only used in device operation mode.
 */

#define BP_USBC__USBSTS_SLI      8
#define BM_USBC__USBSTS_SLI      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_SLI(v)   ((((reg32_t) v) << 8) & BM_USBC__USBSTS_SLI)
#else
#define BF_USBC__USBSTS_SLI(v)   (((v) << 8) & BM_USBC__USBSTS_SLI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_SLI(v)   BF_CS1(USBC__USBSTS, SLI, v)
#endif

/* --- Register HW_USBC__USBSTS, field ULPII
 *
 * ULPI Interrupt - R/WC.  This bit will be set '1b' by hardware when there is an event completion
 * in ULPI                                 viewport.  This bit is usable only if the controller
 * support UPLI interface mode.
 */

#define BP_USBC__USBSTS_ULPII      10
#define BM_USBC__USBSTS_ULPII      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_ULPII(v)   ((((reg32_t) v) << 10) & BM_USBC__USBSTS_ULPII)
#else
#define BF_USBC__USBSTS_ULPII(v)   (((v) << 10) & BM_USBC__USBSTS_ULPII)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_ULPII(v)   BF_CS1(USBC__USBSTS, ULPII, v)
#endif

/* --- Register HW_USBC__USBSTS, field HCH
 *
 * HCHaIted - Read Only.  This bit is a zero whenever the Run/Stop bit is a one. The Controller sets
 * this bit to                                 one after it has stopped executing because of the
 * Run/Stop bit being set to 0, either by                                 software or by the
 * Controller hardware (for example, an internal error).  Only used in the host operation mode.
 * Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core.  This is because OTG
 * core is not operating as host in default. Please see CM bit in
 * UOG_USBMODE register.
 */

#define BP_USBC__USBSTS_HCH      12
#define BM_USBC__USBSTS_HCH      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_HCH(v)   ((((reg32_t) v) << 12) & BM_USBC__USBSTS_HCH)
#else
#define BF_USBC__USBSTS_HCH(v)   (((v) << 12) & BM_USBC__USBSTS_HCH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_HCH(v)   BF_CS1(USBC__USBSTS, HCH, v)
#endif

/* --- Register HW_USBC__USBSTS, field RCL
 *
 * Reclamation - Read Only.  This is a read-only status bit used to detect an empty asynchronous
 * schedule.  Only used in the host operation mode.
 */

#define BP_USBC__USBSTS_RCL      13
#define BM_USBC__USBSTS_RCL      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_RCL(v)   ((((reg32_t) v) << 13) & BM_USBC__USBSTS_RCL)
#else
#define BF_USBC__USBSTS_RCL(v)   (((v) << 13) & BM_USBC__USBSTS_RCL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_RCL(v)   BF_CS1(USBC__USBSTS, RCL, v)
#endif

/* --- Register HW_USBC__USBSTS, field PS
 *
 * Periodic Schedule Status - Read Only.  This bit reports the current real status of the Periodic
 * Schedule. When set to zero the                                 periodic schedule is disabled, and
 * if set to one the status is enabled. The Host                                 Controller is not
 * required to immediately disable or enable the Periodic Schedule when
 * software transitions the Periodic Schedule Enable bit in the USBCMD register. When this
 * bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is
 * either enabled (1) or disabled (0).  Only used in the host operation mode.
 */

#define BP_USBC__USBSTS_PS      14
#define BM_USBC__USBSTS_PS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_PS(v)   ((((reg32_t) v) << 14) & BM_USBC__USBSTS_PS)
#else
#define BF_USBC__USBSTS_PS(v)   (((v) << 14) & BM_USBC__USBSTS_PS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_PS(v)   BF_CS1(USBC__USBSTS, PS, v)
#endif

/* --- Register HW_USBC__USBSTS, field AS
 *
 * Asynchronous Schedule Status - Read Only.  This bit reports the current real status of the
 * Asynchronous Schedule. When set to zero                                 the asynchronous schedule
 * status is disabled and if set to one the status is enabled.                                 The
 * Host Controller is not required to immediately disable or enable the Asynchronous
 * Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD
 * register. When this bit and the Asynchronous Schedule Enable bit are the same value, the
 * Asynchronous Schedule is either enabled (1) or disabled (0).  Only used in the host operation
 * mode.
 */

#define BP_USBC__USBSTS_AS      15
#define BM_USBC__USBSTS_AS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_AS(v)   ((((reg32_t) v) << 15) & BM_USBC__USBSTS_AS)
#else
#define BF_USBC__USBSTS_AS(v)   (((v) << 15) & BM_USBC__USBSTS_AS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_AS(v)   BF_CS1(USBC__USBSTS, AS, v)
#endif

/* --- Register HW_USBC__USBSTS, field NAKI
 *
 * NAK Interrupt Bit--RO.  This bit is set by hardware when for a particular endpoint both the TX/RX
 * Endpoint NAK                                 bit and corresponding TX/RX Endpoint NAK Enable bit
 * are set. This bit is automatically                                 cleared by hardware when all
 * Enabled TX/RX Endpoint NAK bits are cleared.
 */

#define BP_USBC__USBSTS_NAKI      16
#define BM_USBC__USBSTS_NAKI      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_NAKI(v)   ((((reg32_t) v) << 16) & BM_USBC__USBSTS_NAKI)
#else
#define BF_USBC__USBSTS_NAKI(v)   (((v) << 16) & BM_USBC__USBSTS_NAKI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_NAKI(v)   BF_CS1(USBC__USBSTS, NAKI, v)
#endif

/* --- Register HW_USBC__USBSTS, field TI0
 *
 * General Purpose Timer Interrupt 0(GPTINT0)--R/WC.  This bit is set when the counter in the
 * GPTIMER0CTRL register transitions to zero,                                 writing a one to this
 * bit clears it.
 */

#define BP_USBC__USBSTS_TI0      24
#define BM_USBC__USBSTS_TI0      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_TI0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBSTS_TI0)
#else
#define BF_USBC__USBSTS_TI0(v)   (((v) << 24) & BM_USBC__USBSTS_TI0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_TI0(v)   BF_CS1(USBC__USBSTS, TI0, v)
#endif

/* --- Register HW_USBC__USBSTS, field TI1
 *
 * General Purpose Timer Interrupt 1(GPTINT1)--R/WC.  This bit is set when the counter in the
 * GPTIMER1CTRL register transitions to zero,                                 writing a one to this
 * bit will clear it.
 */

#define BP_USBC__USBSTS_TI1      25
#define BM_USBC__USBSTS_TI1      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTS_TI1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBSTS_TI1)
#else
#define BF_USBC__USBSTS_TI1(v)   (((v) << 25) & BM_USBC__USBSTS_TI1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBSTS_TI1(v)   BF_CS1(USBC__USBSTS, TI1, v)
#endif

/*!
 * @brief HW_USBC__USBINTR - Interrupt Enable Register
 *
 * The interrupts to software are enabled with this register. An interrupt is generated when a
 * bit is set and the corresponding interrupt source is active. The USB Status register
 * (n_USBSTS) still shows interrupt sources even if they are disabled by the n_USBINTR
 * register, allowing polling of interrupt events by the software.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned UE : 1; //!< USB Interrupt Enalbe  When this bit is one and the UI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned UEE : 1; //!< USB Error Interrupt Enable  When this bit is one and the UEI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned PCE : 1; //!< Port Change Detect Interrupt Enable  When this bit is one and the PCI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned FRE : 1; //!< Frame List Rollover Interrupt Enable  When this bit is one and the FRI bit in n_USBSTS register is a one the controller will issue an interrupt.  Only used in host operation mode.
        unsigned SEE : 1; //!< System Error Interrupt Enable  When this bit is one and the SEI bit in n_USBSTS register is a one the controller will issue an interrupt.  Only used in host operation mode.
        unsigned AAE : 1; //!< Async Advance Interrupt Enable  When this bit is one and the AAI bit in n_USBSTS register is a one the controller will issue an interrupt.  Only used in host operation mode.
        unsigned URE : 1; //!< USB Reset Interrupt Enable  When this bit is one and the URI bit in n_UOG_USBSTS register is a one the controller will issue an interrupt.  Only used in device operation mode.
        unsigned SRE : 1; //!< SOF Received Interrupt Enable  When this bit is one and the SRI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned SLE : 1; //!< Sleep Interrupt Enable  When this bit is one and the SLI bit in n_n_USBSTS register is a one the controller will issue an interrupt.  Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPIE : 1; //!< ULPI Interrupt Enable  When this bit is one and the UPLII bit in n_USBSTS register is a one the controller will issue an interrupt.  This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 5; //!< These bits are reserved and should be set to zero.
        unsigned NAKE : 1; //!< NAK Interrupt Enable  When this bit is one and the NAKI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned UAIE : 1; //!< USB Host Asynchronous Interrupt Enable  When this bit is one, and the UAI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned UPIE : 1; //!< USB Host Periodic Interrupt Enable  When this bit is one, and the UPI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned RESERVED3 : 4; //!< Reserved
        unsigned TIE0 : 1; //!< General Purpose Timer #0 Interrupt Enable  When this bit is one and the TI0 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned TIE1 : 1; //!< General Purpose Timer #1 Interrupt Enable  When this bit is one and the TI1 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED4 : 6; //!< Reserved
    } B;
} hw_usbc__usbintr_t;
#endif

/*
 * constants & macros for entire USBC__USBINTR register
 */
#define HW_USBC__USBINTR_ADDR      (REGS_USBC_BASE + 0x148)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBINTR           (*(volatile hw_usbc__usbintr_t *) HW_USBC__USBINTR_ADDR)
#define HW_USBC__USBINTR_RD()      (HW_USBC__USBINTR.U)
#define HW_USBC__USBINTR_WR(v)     (HW_USBC__USBINTR.U = (v))
#define HW_USBC__USBINTR_SET(v)    (HW_USBC__USBINTR_WR(HW_USBC__USBINTR_RD() |  (v)))
#define HW_USBC__USBINTR_CLR(v)    (HW_USBC__USBINTR_WR(HW_USBC__USBINTR_RD() & ~(v)))
#define HW_USBC__USBINTR_TOG(v)    (HW_USBC__USBINTR_WR(HW_USBC__USBINTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__USBINTR bitfields
 */

/* --- Register HW_USBC__USBINTR, field UE
 *
 * USB Interrupt Enalbe  When this bit is one and the UI bit in n_USBSTS register is a one the
 * controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_UE      0
#define BM_USBC__USBINTR_UE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_UE(v)   ((((reg32_t) v) << 0) & BM_USBC__USBINTR_UE)
#else
#define BF_USBC__USBINTR_UE(v)   (((v) << 0) & BM_USBC__USBINTR_UE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_UE(v)   BF_CS1(USBC__USBINTR, UE, v)
#endif

/* --- Register HW_USBC__USBINTR, field UEE
 *
 * USB Error Interrupt Enable  When this bit is one and the UEI bit in n_USBSTS register is a one
 * the controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_UEE      1
#define BM_USBC__USBINTR_UEE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_UEE(v)   ((((reg32_t) v) << 1) & BM_USBC__USBINTR_UEE)
#else
#define BF_USBC__USBINTR_UEE(v)   (((v) << 1) & BM_USBC__USBINTR_UEE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_UEE(v)   BF_CS1(USBC__USBINTR, UEE, v)
#endif

/* --- Register HW_USBC__USBINTR, field PCE
 *
 * Port Change Detect Interrupt Enable  When this bit is one and the PCI bit in n_USBSTS register is
 * a one the controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_PCE      2
#define BM_USBC__USBINTR_PCE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_PCE(v)   ((((reg32_t) v) << 2) & BM_USBC__USBINTR_PCE)
#else
#define BF_USBC__USBINTR_PCE(v)   (((v) << 2) & BM_USBC__USBINTR_PCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_PCE(v)   BF_CS1(USBC__USBINTR, PCE, v)
#endif

/* --- Register HW_USBC__USBINTR, field FRE
 *
 * Frame List Rollover Interrupt Enable  When this bit is one and the FRI bit in n_USBSTS register
 * is a one the controller will                                 issue an interrupt.  Only used in
 * host operation mode.
 */

#define BP_USBC__USBINTR_FRE      3
#define BM_USBC__USBINTR_FRE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_FRE(v)   ((((reg32_t) v) << 3) & BM_USBC__USBINTR_FRE)
#else
#define BF_USBC__USBINTR_FRE(v)   (((v) << 3) & BM_USBC__USBINTR_FRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_FRE(v)   BF_CS1(USBC__USBINTR, FRE, v)
#endif

/* --- Register HW_USBC__USBINTR, field SEE
 *
 * System Error Interrupt Enable  When this bit is one and the SEI bit in n_USBSTS register is a one
 * the controller will                                 issue an interrupt.  Only used in host
 * operation mode.
 */

#define BP_USBC__USBINTR_SEE      4
#define BM_USBC__USBINTR_SEE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_SEE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBINTR_SEE)
#else
#define BF_USBC__USBINTR_SEE(v)   (((v) << 4) & BM_USBC__USBINTR_SEE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_SEE(v)   BF_CS1(USBC__USBINTR, SEE, v)
#endif

/* --- Register HW_USBC__USBINTR, field AAE
 *
 * Async Advance Interrupt Enable  When this bit is one and the AAI bit in n_USBSTS register is a
 * one the controller will                                 issue an interrupt.  Only used in host
 * operation mode.
 */

#define BP_USBC__USBINTR_AAE      5
#define BM_USBC__USBINTR_AAE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_AAE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBINTR_AAE)
#else
#define BF_USBC__USBINTR_AAE(v)   (((v) << 5) & BM_USBC__USBINTR_AAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_AAE(v)   BF_CS1(USBC__USBINTR, AAE, v)
#endif

/* --- Register HW_USBC__USBINTR, field URE
 *
 * USB Reset Interrupt Enable  When this bit is one and the URI bit in n_UOG_USBSTS register is a
 * one the controller                                 will issue an interrupt.  Only used in device
 * operation mode.
 */

#define BP_USBC__USBINTR_URE      6
#define BM_USBC__USBINTR_URE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_URE(v)   ((((reg32_t) v) << 6) & BM_USBC__USBINTR_URE)
#else
#define BF_USBC__USBINTR_URE(v)   (((v) << 6) & BM_USBC__USBINTR_URE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_URE(v)   BF_CS1(USBC__USBINTR, URE, v)
#endif

/* --- Register HW_USBC__USBINTR, field SRE
 *
 * SOF Received Interrupt Enable  When this bit is one and the SRI bit in n_USBSTS register is a one
 * the controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_SRE      7
#define BM_USBC__USBINTR_SRE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_SRE(v)   ((((reg32_t) v) << 7) & BM_USBC__USBINTR_SRE)
#else
#define BF_USBC__USBINTR_SRE(v)   (((v) << 7) & BM_USBC__USBINTR_SRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_SRE(v)   BF_CS1(USBC__USBINTR, SRE, v)
#endif

/* --- Register HW_USBC__USBINTR, field SLE
 *
 * Sleep Interrupt Enable  When this bit is one and the SLI bit in n_n_USBSTS register is a one the
 * controller                                 will issue an interrupt.  Only used in device
 * operation mode.
 */

#define BP_USBC__USBINTR_SLE      8
#define BM_USBC__USBINTR_SLE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_SLE(v)   ((((reg32_t) v) << 8) & BM_USBC__USBINTR_SLE)
#else
#define BF_USBC__USBINTR_SLE(v)   (((v) << 8) & BM_USBC__USBINTR_SLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_SLE(v)   BF_CS1(USBC__USBINTR, SLE, v)
#endif

/* --- Register HW_USBC__USBINTR, field ULPIE
 *
 * ULPI Interrupt Enable  When this bit is one and the UPLII bit in n_USBSTS register is a one the
 * controller                                 will issue an interrupt.  This bit is usable only if
 * the controller support UPLI interface mode.
 */

#define BP_USBC__USBINTR_ULPIE      10
#define BM_USBC__USBINTR_ULPIE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_ULPIE(v)   ((((reg32_t) v) << 10) & BM_USBC__USBINTR_ULPIE)
#else
#define BF_USBC__USBINTR_ULPIE(v)   (((v) << 10) & BM_USBC__USBINTR_ULPIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_ULPIE(v)   BF_CS1(USBC__USBINTR, ULPIE, v)
#endif

/* --- Register HW_USBC__USBINTR, field NAKE
 *
 * NAK Interrupt Enable  When this bit is one and the NAKI bit in n_USBSTS register is a one the
 * controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_NAKE      16
#define BM_USBC__USBINTR_NAKE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_NAKE(v)   ((((reg32_t) v) << 16) & BM_USBC__USBINTR_NAKE)
#else
#define BF_USBC__USBINTR_NAKE(v)   (((v) << 16) & BM_USBC__USBINTR_NAKE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_NAKE(v)   BF_CS1(USBC__USBINTR, NAKE, v)
#endif

/* --- Register HW_USBC__USBINTR, field UAIE
 *
 * USB Host Asynchronous Interrupt Enable  When this bit is one, and the UAI bit in the n_USBSTS
 * register is one, host controller                                 will issue an interrupt at the
 * next interrupt threshold.
 */

#define BP_USBC__USBINTR_UAIE      18
#define BM_USBC__USBINTR_UAIE      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_UAIE(v)   ((((reg32_t) v) << 18) & BM_USBC__USBINTR_UAIE)
#else
#define BF_USBC__USBINTR_UAIE(v)   (((v) << 18) & BM_USBC__USBINTR_UAIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_UAIE(v)   BF_CS1(USBC__USBINTR, UAIE, v)
#endif

/* --- Register HW_USBC__USBINTR, field UPIE
 *
 * USB Host Periodic Interrupt Enable  When this bit is one, and the UPI bit in the n_USBSTS
 * register is one, host controller                                 will issue an interrupt at the
 * next interrupt threshold.
 */

#define BP_USBC__USBINTR_UPIE      19
#define BM_USBC__USBINTR_UPIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_UPIE(v)   ((((reg32_t) v) << 19) & BM_USBC__USBINTR_UPIE)
#else
#define BF_USBC__USBINTR_UPIE(v)   (((v) << 19) & BM_USBC__USBINTR_UPIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_UPIE(v)   BF_CS1(USBC__USBINTR, UPIE, v)
#endif

/* --- Register HW_USBC__USBINTR, field TIE0
 *
 * General Purpose Timer #0 Interrupt Enable  When this bit is one and the TI0 bit in n_USBSTS
 * register is a one the controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_TIE0      24
#define BM_USBC__USBINTR_TIE0      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_TIE0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBINTR_TIE0)
#else
#define BF_USBC__USBINTR_TIE0(v)   (((v) << 24) & BM_USBC__USBINTR_TIE0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_TIE0(v)   BF_CS1(USBC__USBINTR, TIE0, v)
#endif

/* --- Register HW_USBC__USBINTR, field TIE1
 *
 * General Purpose Timer #1 Interrupt Enable  When this bit is one and the TI1 bit in n_USBSTS
 * register is a one the controller will                                 issue an interrupt.
 */

#define BP_USBC__USBINTR_TIE1      25
#define BM_USBC__USBINTR_TIE1      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTR_TIE1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBINTR_TIE1)
#else
#define BF_USBC__USBINTR_TIE1(v)   (((v) << 25) & BM_USBC__USBINTR_TIE1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBINTR_TIE1(v)   BF_CS1(USBC__USBINTR, TIE1, v)
#endif

/*!
 * @brief HW_USBC__FRINDEX - USB Frame Index
 *
 * This register is used by the host controller to index the periodic frame list. The register
 * updates every 125 microseconds (once each micro-frame). Bits [N: 3] are used to select a
 * particular entry in the Periodic Frame List during periodic schedule execution. The number
 * of bits used for the index depends on the size of the frame list as set by system software
 * in the Frame List Size field in the n_USBCMD register.  This register must be written as a DWord.
 * Byte writes produce-undefined results. This                             register cannot be
 * written unless the Host Controller is in the 'Halted' state as indicated
 * by the HCHalted bit. A write to this register while the Run/Stop hit is set to a one
 * produces undefined results. Writes to this register also affect the SOF value.  In device mode
 * this register is read only and, the device controller updates the FRINDEX
 * [13:3] register from the frame number indicated by the SOF marker. Whenever a SOF is
 * received by the USB bus, FRINDEX [13:3] will be checked against the SOF marker. If FRINDEX
 * [13:3] is different from the SOF marker, FRINDEX [13:3] will be set to the SOF value and
 * FRINDEX [2:0] will be set to zero (that is, SOF for 1 ms frame). If FRINDEX [13:3] is equal
 * to the SOF value, FRINDEX [2:0] will be increment (that is, SOF for 125 us
 * micro-frame.).
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FRINDEX : 14; //!< Frame Index.  The value, in this register, increments at the end of each time frame (micro-frame). Bits [N: 3] are used for the Frame List current index. This means that each location of the frame list is accessed 8 times (frames or micro-frames) before moving to the next index.  The following illustrates values of N based on the value of the Frame List Size field in the USBCMD register, when used in host mode.  USBCMD [Frame List Size] Number Elements N  In device mode the value is the current frame number of the last frame transmitted. It is not used as an index.  In either mode bits 2:0 indicate the current microframe.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_usbc__frindex_t;
#endif

/*
 * constants & macros for entire USBC__FRINDEX register
 */
#define HW_USBC__FRINDEX_ADDR      (REGS_USBC_BASE + 0x14c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__FRINDEX           (*(volatile hw_usbc__frindex_t *) HW_USBC__FRINDEX_ADDR)
#define HW_USBC__FRINDEX_RD()      (HW_USBC__FRINDEX.U)
#define HW_USBC__FRINDEX_WR(v)     (HW_USBC__FRINDEX.U = (v))
#define HW_USBC__FRINDEX_SET(v)    (HW_USBC__FRINDEX_WR(HW_USBC__FRINDEX_RD() |  (v)))
#define HW_USBC__FRINDEX_CLR(v)    (HW_USBC__FRINDEX_WR(HW_USBC__FRINDEX_RD() & ~(v)))
#define HW_USBC__FRINDEX_TOG(v)    (HW_USBC__FRINDEX_WR(HW_USBC__FRINDEX_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__FRINDEX bitfields
 */

/* --- Register HW_USBC__FRINDEX, field FRINDEX
 *
 * Frame Index.  The value, in this register, increments at the end of each time frame (micro-
 * frame). Bits                                 [N: 3] are used for the Frame List current index.
 * This means that each location of the                                 frame list is accessed 8
 * times (frames or micro-frames) before moving to the next index.  The following illustrates values
 * of N based on the value of the Frame List Size field in                                 the
 * USBCMD register, when used in host mode.  USBCMD [Frame List Size] Number Elements N  In device
 * mode the value is the current frame number of the last frame transmitted. It is
 * not used as an index.  In either mode bits 2:0 indicate the current microframe.
 */

#define BP_USBC__FRINDEX_FRINDEX      0
#define BM_USBC__FRINDEX_FRINDEX      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__FRINDEX_FRINDEX(v)   ((((reg32_t) v) << 0) & BM_USBC__FRINDEX_FRINDEX)
#else
#define BF_USBC__FRINDEX_FRINDEX(v)   (((v) << 0) & BM_USBC__FRINDEX_FRINDEX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__FRINDEX_FRINDEX(v)   BF_CS1(USBC__FRINDEX, FRINDEX, v)
#endif

/*!
 * @brief HW_USBC__PERIODICLISTBASE - Frame List Base Address
 *
 * Host Controller only  This 32-bit register contains the beginning address of the Periodic Frame
 * List in the system                             memory. HCD loads this register prior to starting
 * the schedule execution by the Host                             Controller. The memory structure
 * referenced by this physical memory pointer is assumed to be                             4-Kbyte
 * aligned. The contents of this register are combined with the Frame Index Register
 * (UOG_FRINDEX) to enable the Host Controller to step through the Periodic Frame List in
 * sequence.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 12; //!< Reserved
        unsigned BASEADR : 20; //!< Base Address (Low).  These bits correspond to memory address signals [31:12], respectively.  Only used by the host controller.
    } B;
} hw_usbc__periodiclistbase_t;
#endif

/*
 * constants & macros for entire USBC__PERIODICLISTBASE register
 */
#define HW_USBC__PERIODICLISTBASE_ADDR      (REGS_USBC_BASE + 0x154)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PERIODICLISTBASE           (*(volatile hw_usbc__periodiclistbase_t *) HW_USBC__PERIODICLISTBASE_ADDR)
#define HW_USBC__PERIODICLISTBASE_RD()      (HW_USBC__PERIODICLISTBASE.U)
#define HW_USBC__PERIODICLISTBASE_WR(v)     (HW_USBC__PERIODICLISTBASE.U = (v))
#define HW_USBC__PERIODICLISTBASE_SET(v)    (HW_USBC__PERIODICLISTBASE_WR(HW_USBC__PERIODICLISTBASE_RD() |  (v)))
#define HW_USBC__PERIODICLISTBASE_CLR(v)    (HW_USBC__PERIODICLISTBASE_WR(HW_USBC__PERIODICLISTBASE_RD() & ~(v)))
#define HW_USBC__PERIODICLISTBASE_TOG(v)    (HW_USBC__PERIODICLISTBASE_WR(HW_USBC__PERIODICLISTBASE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__PERIODICLISTBASE bitfields
 */

/* --- Register HW_USBC__PERIODICLISTBASE, field BASEADR
 *
 * Base Address (Low).  These bits correspond to memory address signals [31:12], respectively.  Only
 * used by the host controller.
 */

#define BP_USBC__PERIODICLISTBASE_BASEADR      12
#define BM_USBC__PERIODICLISTBASE_BASEADR      0xfffff000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PERIODICLISTBASE_BASEADR(v)   ((((reg32_t) v) << 12) & BM_USBC__PERIODICLISTBASE_BASEADR)
#else
#define BF_USBC__PERIODICLISTBASE_BASEADR(v)   (((v) << 12) & BM_USBC__PERIODICLISTBASE_BASEADR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PERIODICLISTBASE_BASEADR(v)   BF_CS1(USBC__PERIODICLISTBASE, BASEADR, v)
#endif

/*!
 * @brief HW_USBC_UOG_DEVICEADDR - Device Address
 *
 * Device Controller only  The upper seven bits of this register represent the device address. After
 * any controller                             reset or a USB reset, the device address is set to the
 * default address (0). The default                             address will match all incoming
 * addresses. Software shall reprogram the address after                             receiving a
 * SET_ADDRESS descriptor.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 24; //!< Reserved
        unsigned USBADRA : 1; //!< Device Address Advance. Default=0.  When this bit is '0', any writes to USBADR are instantaneous. When this bit is written to a '1' at the same time or before USBADR is written, the write to the USBADR field is staged and held in a hidden register. After an IN occurs on endpoint 0 and is ACKed, USBADR will be loaded from the holding register.  Hardware will automatically clear this bit on the following conditions:  1) IN is ACKed to endpoint 0. (USBADR is updated from staging register).  2) OUT/SETUP occur to endpoint 0. (USBADR is not updated).  3) Device Reset occurs (USBADR is reset to 0).  After the status phase of the SET_ADDRESS descriptor, the DCD has 2 ms to program the USBADR field. This mechanism will ensure this specification is met when the DCD can not write of the device address within 2ms from the SET_ADDRESS status phase. If the DCD writes the USBADR with USBADRA=1 after the SET_ADDRESS data phase (before the prime of the status phase), the USBADR will be programmed instantly at the correct time and meet the 2ms USB requirement.
        unsigned USBADR : 7; //!< Device Address.  These bits correspond to the USB device address
    } B;
} hw_usbc_uog_deviceaddr_t;
#endif

/*
 * constants & macros for entire USBC_UOG_DEVICEADDR register
 */
#define HW_USBC_UOG_DEVICEADDR_ADDR      (REGS_USBC_BASE + 0x154)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_DEVICEADDR           (*(volatile hw_usbc_uog_deviceaddr_t *) HW_USBC_UOG_DEVICEADDR_ADDR)
#define HW_USBC_UOG_DEVICEADDR_RD()      (HW_USBC_UOG_DEVICEADDR.U)
#define HW_USBC_UOG_DEVICEADDR_WR(v)     (HW_USBC_UOG_DEVICEADDR.U = (v))
#define HW_USBC_UOG_DEVICEADDR_SET(v)    (HW_USBC_UOG_DEVICEADDR_WR(HW_USBC_UOG_DEVICEADDR_RD() |  (v)))
#define HW_USBC_UOG_DEVICEADDR_CLR(v)    (HW_USBC_UOG_DEVICEADDR_WR(HW_USBC_UOG_DEVICEADDR_RD() & ~(v)))
#define HW_USBC_UOG_DEVICEADDR_TOG(v)    (HW_USBC_UOG_DEVICEADDR_WR(HW_USBC_UOG_DEVICEADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_DEVICEADDR bitfields
 */

/* --- Register HW_USBC_UOG_DEVICEADDR, field USBADRA
 *
 * Device Address Advance. Default=0.  When this bit is '0', any writes to USBADR are instantaneous.
 * When this bit is written to                                 a '1' at the same time or before
 * USBADR is written, the write to the USBADR field is                                 staged and
 * held in a hidden register. After an IN occurs on endpoint 0 and is ACKed,
 * USBADR will be loaded from the holding register.  Hardware will automatically clear this bit on
 * the following conditions:  1) IN is ACKed to endpoint 0. (USBADR is updated from staging
 * register).  2) OUT/SETUP occur to endpoint 0. (USBADR is not updated).  3) Device Reset occurs
 * (USBADR is reset to 0).  After the status phase of the SET_ADDRESS descriptor, the DCD has 2 ms
 * to program the                                 USBADR field. This mechanism will ensure this
 * specification is met when the DCD can not                                 write of the device
 * address within 2ms from the SET_ADDRESS status phase. If the DCD
 * writes the USBADR with USBADRA=1 after the SET_ADDRESS data phase (before the prime of
 * the status phase), the USBADR will be programmed instantly at the correct time and meet
 * the 2ms USB requirement.
 */

#define BP_USBC_UOG_DEVICEADDR_USBADRA      24
#define BM_USBC_UOG_DEVICEADDR_USBADRA      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_DEVICEADDR_USBADRA(v)   ((((reg32_t) v) << 24) & BM_USBC_UOG_DEVICEADDR_USBADRA)
#else
#define BF_USBC_UOG_DEVICEADDR_USBADRA(v)   (((v) << 24) & BM_USBC_UOG_DEVICEADDR_USBADRA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_DEVICEADDR_USBADRA(v)   BF_CS1(USBC_UOG_DEVICEADDR, USBADRA, v)
#endif

/* --- Register HW_USBC_UOG_DEVICEADDR, field USBADR
 *
 * Device Address.  These bits correspond to the USB device address
 */

#define BP_USBC_UOG_DEVICEADDR_USBADR      25
#define BM_USBC_UOG_DEVICEADDR_USBADR      0xfe000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_DEVICEADDR_USBADR(v)   ((((reg32_t) v) << 25) & BM_USBC_UOG_DEVICEADDR_USBADR)
#else
#define BF_USBC_UOG_DEVICEADDR_USBADR(v)   (((v) << 25) & BM_USBC_UOG_DEVICEADDR_USBADR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_DEVICEADDR_USBADR(v)   BF_CS1(USBC_UOG_DEVICEADDR, USBADR, v)
#endif

/*!
 * @brief HW_USBC__ASYNCLISTADDR - Next Asynch. Address
 *
 * Host Controller only  This 32-bit register contains the address of the next asynchronous queue
 * head to be executed                             by the host. Bits [4:0] of this register cannot
 * be modified by the system software and will                             always return a zero when
 * read.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned ASYBASE : 27; //!< Link Pointer Low (LPL).  These bits correspond to memory address signals [31:5], respectively. This field may only reference a Queue Head (QH).  Only used by the host controller.
    } B;
} hw_usbc__asynclistaddr_t;
#endif

/*
 * constants & macros for entire USBC__ASYNCLISTADDR register
 */
#define HW_USBC__ASYNCLISTADDR_ADDR      (REGS_USBC_BASE + 0x158)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__ASYNCLISTADDR           (*(volatile hw_usbc__asynclistaddr_t *) HW_USBC__ASYNCLISTADDR_ADDR)
#define HW_USBC__ASYNCLISTADDR_RD()      (HW_USBC__ASYNCLISTADDR.U)
#define HW_USBC__ASYNCLISTADDR_WR(v)     (HW_USBC__ASYNCLISTADDR.U = (v))
#define HW_USBC__ASYNCLISTADDR_SET(v)    (HW_USBC__ASYNCLISTADDR_WR(HW_USBC__ASYNCLISTADDR_RD() |  (v)))
#define HW_USBC__ASYNCLISTADDR_CLR(v)    (HW_USBC__ASYNCLISTADDR_WR(HW_USBC__ASYNCLISTADDR_RD() & ~(v)))
#define HW_USBC__ASYNCLISTADDR_TOG(v)    (HW_USBC__ASYNCLISTADDR_WR(HW_USBC__ASYNCLISTADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__ASYNCLISTADDR bitfields
 */

/* --- Register HW_USBC__ASYNCLISTADDR, field ASYBASE
 *
 * Link Pointer Low (LPL).  These bits correspond to memory address signals [31:5], respectively.
 * This field may only                                 reference a Queue Head (QH).  Only used by
 * the host controller.
 */

#define BP_USBC__ASYNCLISTADDR_ASYBASE      5
#define BM_USBC__ASYNCLISTADDR_ASYBASE      0xffffffe0

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ASYNCLISTADDR_ASYBASE(v)   ((((reg32_t) v) << 5) & BM_USBC__ASYNCLISTADDR_ASYBASE)
#else
#define BF_USBC__ASYNCLISTADDR_ASYBASE(v)   (((v) << 5) & BM_USBC__ASYNCLISTADDR_ASYBASE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__ASYNCLISTADDR_ASYBASE(v)   BF_CS1(USBC__ASYNCLISTADDR, ASYBASE, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTLISTADDR - Endpoint List Address
 *
 * Device Controller only  In device mode, this register contains the address of the top of the
 * endpoint list in system                             memory. Bits [10:0] of this register cannot
 * be modified by the system software and will                             always return a zero when
 * read.  The memory structure referenced by this physical memory pointer is assumed 64-byte.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 11; //!< Reserved
        unsigned EPBASE : 21; //!< Endpoint List Pointer(Low). These bits correspond to memory address signals [31:11], respectively. This field will reference a list of up to 32 Queue Head (OH) (that is, one queue head per endpoint & direction).
    } B;
} hw_usbc_uog_endptlistaddr_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTLISTADDR register
 */
#define HW_USBC_UOG_ENDPTLISTADDR_ADDR      (REGS_USBC_BASE + 0x158)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTLISTADDR           (*(volatile hw_usbc_uog_endptlistaddr_t *) HW_USBC_UOG_ENDPTLISTADDR_ADDR)
#define HW_USBC_UOG_ENDPTLISTADDR_RD()      (HW_USBC_UOG_ENDPTLISTADDR.U)
#define HW_USBC_UOG_ENDPTLISTADDR_WR(v)     (HW_USBC_UOG_ENDPTLISTADDR.U = (v))
#define HW_USBC_UOG_ENDPTLISTADDR_SET(v)    (HW_USBC_UOG_ENDPTLISTADDR_WR(HW_USBC_UOG_ENDPTLISTADDR_RD() |  (v)))
#define HW_USBC_UOG_ENDPTLISTADDR_CLR(v)    (HW_USBC_UOG_ENDPTLISTADDR_WR(HW_USBC_UOG_ENDPTLISTADDR_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTLISTADDR_TOG(v)    (HW_USBC_UOG_ENDPTLISTADDR_WR(HW_USBC_UOG_ENDPTLISTADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTLISTADDR bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTLISTADDR, field EPBASE
 *
 * Endpoint List Pointer(Low). These bits correspond to memory address signals [31:11],
 * respectively. This field will reference a list of up to 32 Queue Head (OH) (that is, one
 * queue head per endpoint & direction).
 */

#define BP_USBC_UOG_ENDPTLISTADDR_EPBASE      11
#define BM_USBC_UOG_ENDPTLISTADDR_EPBASE      0xfffff800

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTLISTADDR_EPBASE(v)   ((((reg32_t) v) << 11) & BM_USBC_UOG_ENDPTLISTADDR_EPBASE)
#else
#define BF_USBC_UOG_ENDPTLISTADDR_EPBASE(v)   (((v) << 11) & BM_USBC_UOG_ENDPTLISTADDR_EPBASE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTLISTADDR_EPBASE(v)   BF_CS1(USBC_UOG_ENDPTLISTADDR, EPBASE, v)
#endif

/*!
 * @brief HW_USBC__BURSTSIZE - Programmable Burst Size
 *
 * This register is used to control the burst size used during data movement on the AHB master
 * interface. This register is ignored if AHBBRST bits in SBUSCFG register is non-zero
 * value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RXPBURST : 8; //!< Programmable RX Burst Size.  Default value is determined by TXBURST bits in n_HWRXBUF.  This register represents the maximum length of a the burst in 32-bit words while moving data from the USB bus to system memory.
        unsigned TXPBURST : 9; //!< Programmable TX Burst Size.  Default value is determined by TXBURST bits in n_HWTXBUF.  This register represents the maximum length of a the burst in 32-bit words while moving data from system memory to the USB bus.
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_usbc__burstsize_t;
#endif

/*
 * constants & macros for entire USBC__BURSTSIZE register
 */
#define HW_USBC__BURSTSIZE_ADDR      (REGS_USBC_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__BURSTSIZE           (*(volatile hw_usbc__burstsize_t *) HW_USBC__BURSTSIZE_ADDR)
#define HW_USBC__BURSTSIZE_RD()      (HW_USBC__BURSTSIZE.U)
#define HW_USBC__BURSTSIZE_WR(v)     (HW_USBC__BURSTSIZE.U = (v))
#define HW_USBC__BURSTSIZE_SET(v)    (HW_USBC__BURSTSIZE_WR(HW_USBC__BURSTSIZE_RD() |  (v)))
#define HW_USBC__BURSTSIZE_CLR(v)    (HW_USBC__BURSTSIZE_WR(HW_USBC__BURSTSIZE_RD() & ~(v)))
#define HW_USBC__BURSTSIZE_TOG(v)    (HW_USBC__BURSTSIZE_WR(HW_USBC__BURSTSIZE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__BURSTSIZE bitfields
 */

/* --- Register HW_USBC__BURSTSIZE, field RXPBURST
 *
 * Programmable RX Burst Size.  Default value is determined by TXBURST bits in n_HWRXBUF.  This
 * register represents the maximum length of a the burst in 32-bit words while moving
 * data from the USB bus to system memory.
 */

#define BP_USBC__BURSTSIZE_RXPBURST      0
#define BM_USBC__BURSTSIZE_RXPBURST      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZE_RXPBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__BURSTSIZE_RXPBURST)
#else
#define BF_USBC__BURSTSIZE_RXPBURST(v)   (((v) << 0) & BM_USBC__BURSTSIZE_RXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__BURSTSIZE_RXPBURST(v)   BF_CS1(USBC__BURSTSIZE, RXPBURST, v)
#endif

/* --- Register HW_USBC__BURSTSIZE, field TXPBURST
 *
 * Programmable TX Burst Size.  Default value is determined by TXBURST bits in n_HWTXBUF.  This
 * register represents the maximum length of a the burst in 32-bit words while moving
 * data from system memory to the USB bus.
 */

#define BP_USBC__BURSTSIZE_TXPBURST      8
#define BM_USBC__BURSTSIZE_TXPBURST      0x0001ff00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZE_TXPBURST(v)   ((((reg32_t) v) << 8) & BM_USBC__BURSTSIZE_TXPBURST)
#else
#define BF_USBC__BURSTSIZE_TXPBURST(v)   (((v) << 8) & BM_USBC__BURSTSIZE_TXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__BURSTSIZE_TXPBURST(v)   BF_CS1(USBC__BURSTSIZE, TXPBURST, v)
#endif

/*!
 * @brief HW_USBC__TXFILLTUNING - TX FIFO Fill Tuning
 *
 * The fields in this register control performance tuning associated with how the host
 * controller posts data to the TX latency FIFO before moving the data onto the USB bus. The
 * specific areas of performance include the how much data to post into the FIFO and an
 * estimate for how long that operation should take in the target system.  Definitions:  T 0 =
 * Standard packet overhead  T 1 = Time to send data payload  T ff = Time to fetch packet into TX
 * FIFO up to specified level.  T s = Total Packet Flight Time (send-only) packet  T s = T 0 + T 1
 * T p = Total Packet Time (fetch and send) packet  T p = T ff + T 0 + T 1   Upon discovery of a
 * transmit (OUT/SETUP) packet in the data structures, host controller
 * checks to ensure T  p  remains before the end of the [micro]frame. If
 * so it proceeds to pre-fill the TX FIFO. If at anytime during the pre-fill operation the time
 * remaining the [micro]frame is < T  s  then the packet attempt                             ceases
 * and the packet is tried at a later time. Although this is not an error condition and
 * the host controller will eventually recover, a mark will be made the scheduler health
 * counter to note the occurrence of a "back-off" event. When a back-off event is detected, the
 * partial packet fetched may need to be discarded from the latency buffer to make room for
 * periodic traffic that will begin after the next SOF. Too many back-off events can waste
 * bandwidth and power on the system bus and thus should be minimized (not necessarily
 * eliminated). Back-offs can be minimized with use of the n_TSCHHEALTH
 * ( T  ff ) described below.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TXSCHOH : 8; //!< Scheduler Overhead. (Read/Write) [Default = 0]  This register adds an additional fixed offset to the schedule time estimator described above as Tff. As an approximation, the value chosen for this register should limit the number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a highly utilized bus. Choosing a value that is too high for this register is not desired as it can needlessly reduce USB utilization. The time unit represented in this register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in this register is 6.333us when a device is connected in Low/Full Speed Mode.  Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned TXSCHHEALTH : 5; //!< Scheduler Health Counter. (Read/Write To Clear)  This register increments when the host controller fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of time to send the packet before the next Start-Of-Frame. This health counter measures the number of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the counter and this counter will max. at 31.  Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXFIFOTHRES : 6; //!< FIFO Burst Threshold. (Read/Write)  This register controls the number of data bursts that are posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum value is 2 and this value should be a low as possible to maximize USB performance. A higher value can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO may underrun because the data transferred from the latency FIFO to USB occurs before it can be replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE register is set.  Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED1 : 10; //!< Reserved
    } B;
} hw_usbc__txfilltuning_t;
#endif

/*
 * constants & macros for entire USBC__TXFILLTUNING register
 */
#define HW_USBC__TXFILLTUNING_ADDR      (REGS_USBC_BASE + 0x164)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__TXFILLTUNING           (*(volatile hw_usbc__txfilltuning_t *) HW_USBC__TXFILLTUNING_ADDR)
#define HW_USBC__TXFILLTUNING_RD()      (HW_USBC__TXFILLTUNING.U)
#define HW_USBC__TXFILLTUNING_WR(v)     (HW_USBC__TXFILLTUNING.U = (v))
#define HW_USBC__TXFILLTUNING_SET(v)    (HW_USBC__TXFILLTUNING_WR(HW_USBC__TXFILLTUNING_RD() |  (v)))
#define HW_USBC__TXFILLTUNING_CLR(v)    (HW_USBC__TXFILLTUNING_WR(HW_USBC__TXFILLTUNING_RD() & ~(v)))
#define HW_USBC__TXFILLTUNING_TOG(v)    (HW_USBC__TXFILLTUNING_WR(HW_USBC__TXFILLTUNING_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__TXFILLTUNING bitfields
 */

/* --- Register HW_USBC__TXFILLTUNING, field TXSCHOH
 *
 * Scheduler Overhead. (Read/Write) [Default = 0]  This register adds an additional fixed offset to
 * the schedule time estimator described                                 above as Tff. As an
 * approximation, the value chosen for this register should limit the
 * number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a
 * highly utilized bus. Choosing a value that is too high for this register is not desired
 * as it can needlessly reduce USB utilization. The time unit represented in this register
 * is 1.267us when a device is connected in High-Speed Mode. The time unit represented in
 * this register is 6.333us when a device is connected in Low/Full Speed Mode.  Default value is
 * '08h' for OTG controller core, and '00h' for Host1/Host2/Host3
 * controller core.
 */

#define BP_USBC__TXFILLTUNING_TXSCHOH      0
#define BM_USBC__TXFILLTUNING_TXSCHOH      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNING_TXSCHOH(v)   ((((reg32_t) v) << 0) & BM_USBC__TXFILLTUNING_TXSCHOH)
#else
#define BF_USBC__TXFILLTUNING_TXSCHOH(v)   (((v) << 0) & BM_USBC__TXFILLTUNING_TXSCHOH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__TXFILLTUNING_TXSCHOH(v)   BF_CS1(USBC__TXFILLTUNING, TXSCHOH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNING, field TXSCHHEALTH
 *
 * Scheduler Health Counter. (Read/Write To Clear)  This register increments when the host
 * controller fails to fill the TX latency FIFO to                                 the level
 * programmed by TXFIFOTHRES before running out of time to send the packet before
 * the next Start-Of-Frame. This health counter measures the number of times this occurs to
 * provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the
 * counter and this counter will max. at 31.  Default value is '08h' for OTG controller core, and
 * '00h' for Host1/Host2/Host3                                 controller core.
 */

#define BP_USBC__TXFILLTUNING_TXSCHHEALTH      8
#define BM_USBC__TXFILLTUNING_TXSCHHEALTH      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNING_TXSCHHEALTH(v)   ((((reg32_t) v) << 8) & BM_USBC__TXFILLTUNING_TXSCHHEALTH)
#else
#define BF_USBC__TXFILLTUNING_TXSCHHEALTH(v)   (((v) << 8) & BM_USBC__TXFILLTUNING_TXSCHHEALTH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__TXFILLTUNING_TXSCHHEALTH(v)   BF_CS1(USBC__TXFILLTUNING, TXSCHHEALTH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNING, field TXFIFOTHRES
 *
 * FIFO Burst Threshold. (Read/Write)  This register controls the number of data bursts that are
 * posted to the TX latency FIFO                                 in host mode before the packet
 * begins on to the bus. The minimum value is 2 and this                                 value
 * should be a low as possible to maximize USB performance. A higher value can be
 * used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO
 * may underrun because the data transferred from the latency FIFO to USB occurs before it
 * can be replenished from system memory. This value is ignored if the Stream Disable bit
 * in UOG_USBMODE register is set.  Default value is '00h' for OTG controller core, and '02h' for
 * Host1/Host2/Host3                                 controller core.
 */

#define BP_USBC__TXFILLTUNING_TXFIFOTHRES      16
#define BM_USBC__TXFILLTUNING_TXFIFOTHRES      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNING_TXFIFOTHRES(v)   ((((reg32_t) v) << 16) & BM_USBC__TXFILLTUNING_TXFIFOTHRES)
#else
#define BF_USBC__TXFILLTUNING_TXFIFOTHRES(v)   (((v) << 16) & BM_USBC__TXFILLTUNING_TXFIFOTHRES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__TXFILLTUNING_TXFIFOTHRES(v)   BF_CS1(USBC__TXFILLTUNING, TXFIFOTHRES, v)
#endif

/*!
 * @brief HW_USBC__IC_USB - IC_USB enable and voltage negotiation
 *
 * This register enable and controls the IC-USB FS/LS transceiver.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IC_VDD1 : 3; //!< These bits indicates which voltage is being supplied to the peripheral  This field is read-only and set to 000 in case of a device controller.
        unsigned IC1 : 1; //!< Inter-Chip transceiver enable.  This bits enable the Inter-Chip transceiver. To enable IC-USB interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see .  If IC1 is enabled, IOMUX must set the DP/DM pad into loopback mode.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__ic_usb_t;
#endif

/*
 * constants & macros for entire USBC__IC_USB register
 */
#define HW_USBC__IC_USB_ADDR      (REGS_USBC_BASE + 0x16c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IC_USB           (*(volatile hw_usbc__ic_usb_t *) HW_USBC__IC_USB_ADDR)
#define HW_USBC__IC_USB_RD()      (HW_USBC__IC_USB.U)
#define HW_USBC__IC_USB_WR(v)     (HW_USBC__IC_USB.U = (v))
#define HW_USBC__IC_USB_SET(v)    (HW_USBC__IC_USB_WR(HW_USBC__IC_USB_RD() |  (v)))
#define HW_USBC__IC_USB_CLR(v)    (HW_USBC__IC_USB_WR(HW_USBC__IC_USB_RD() & ~(v)))
#define HW_USBC__IC_USB_TOG(v)    (HW_USBC__IC_USB_WR(HW_USBC__IC_USB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__IC_USB bitfields
 */

/* --- Register HW_USBC__IC_USB, field IC_VDD1
 *
 * These bits indicates which voltage is being supplied to the peripheral  This field is read-only
 * and set to 000 in case of a device controller.
 */

#define BP_USBC__IC_USB_IC_VDD1      0
#define BM_USBC__IC_USB_IC_VDD1      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USB_IC_VDD1(v)   ((((reg32_t) v) << 0) & BM_USBC__IC_USB_IC_VDD1)
#else
#define BF_USBC__IC_USB_IC_VDD1(v)   (((v) << 0) & BM_USBC__IC_USB_IC_VDD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__IC_USB_IC_VDD1(v)   BF_CS1(USBC__IC_USB, IC_VDD1, v)
#endif

/* --- Register HW_USBC__IC_USB, field IC1
 *
 * Inter-Chip transceiver enable.  This bits enable the Inter-Chip transceiver. To enable IC-USB
 * interface, PTS bits in                                 PORTSC1 registers also need to be set
 * correspondingly. Please see .  If IC1 is enabled, IOMUX must set the DP/DM pad into loopback
 * mode.
 */

#define BP_USBC__IC_USB_IC1      3
#define BM_USBC__IC_USB_IC1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USB_IC1(v)   ((((reg32_t) v) << 3) & BM_USBC__IC_USB_IC1)
#else
#define BF_USBC__IC_USB_IC1(v)   (((v) << 3) & BM_USBC__IC_USB_IC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__IC_USB_IC1(v)   BF_CS1(USBC__IC_USB, IC1, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTNAK - Endpoint NAK
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EPRN : 8; //!< RX Endpoint NAK - R/WC.  Each RX endpoint has 1 bit in this field. The bit is set when the  device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint.  Bit [N] - Endpoint #[N], N is 0-7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned EPTN : 8; //!< TX Endpoint NAK - R/WC.  Each TX endpoint has 1 bit in this field. The bit is set when the  device sends a NAK handshake on a received IN token for the corresponding endpoint.  Bit [N] - Endpoint #[N], N is 0-7
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptnak_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTNAK register
 */
#define HW_USBC_UOG_ENDPTNAK_ADDR      (REGS_USBC_BASE + 0x178)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTNAK           (*(volatile hw_usbc_uog_endptnak_t *) HW_USBC_UOG_ENDPTNAK_ADDR)
#define HW_USBC_UOG_ENDPTNAK_RD()      (HW_USBC_UOG_ENDPTNAK.U)
#define HW_USBC_UOG_ENDPTNAK_WR(v)     (HW_USBC_UOG_ENDPTNAK.U = (v))
#define HW_USBC_UOG_ENDPTNAK_SET(v)    (HW_USBC_UOG_ENDPTNAK_WR(HW_USBC_UOG_ENDPTNAK_RD() |  (v)))
#define HW_USBC_UOG_ENDPTNAK_CLR(v)    (HW_USBC_UOG_ENDPTNAK_WR(HW_USBC_UOG_ENDPTNAK_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTNAK_TOG(v)    (HW_USBC_UOG_ENDPTNAK_WR(HW_USBC_UOG_ENDPTNAK_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTNAK bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTNAK, field EPRN
 *
 * RX Endpoint NAK - R/WC.  Each RX endpoint has 1 bit in this field. The bit is set when the
 * device sends a NAK handshake on a received OUT or PING token for the corresponding
 * endpoint.  Bit [N] - Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAK_EPRN      0
#define BM_USBC_UOG_ENDPTNAK_EPRN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAK_EPRN(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTNAK_EPRN)
#else
#define BF_USBC_UOG_ENDPTNAK_EPRN(v)   (((v) << 0) & BM_USBC_UOG_ENDPTNAK_EPRN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTNAK_EPRN(v)   BF_CS1(USBC_UOG_ENDPTNAK, EPRN, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTNAK, field EPTN
 *
 * TX Endpoint NAK - R/WC.  Each TX endpoint has 1 bit in this field. The bit is set when the
 * device sends a NAK handshake on a received IN token for the corresponding endpoint.  Bit [N] -
 * Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAK_EPTN      16
#define BM_USBC_UOG_ENDPTNAK_EPTN      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAK_EPTN(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTNAK_EPTN)
#else
#define BF_USBC_UOG_ENDPTNAK_EPTN(v)   (((v) << 16) & BM_USBC_UOG_ENDPTNAK_EPTN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTNAK_EPTN(v)   BF_CS1(USBC_UOG_ENDPTNAK, EPTN, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTNAKEN - Endpoint Nake Enable
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EPRNE : 8; //!< RX Endpoint NAK Enable - R/W.  Each bit is an enable bit for the corresponding RX Endpoint NAK bit. If this bit is set and the corresponding RX Endpoint NAK bit is set, the NAK Interrupt bit is set.  Bit [N] - Endpoint #[N], N is 0-7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned EPTNE : 8; //!< TX Endpoint NAK Enable - R/W.  Each bit is an enable bit for the corresponding TX Endpoint NAK bit. If this bit is set and the corresponding TX Endpoint NAK bit is set, the NAK Interrupt bit is set.  Bit [N] - Endpoint #[N], N is 0-7
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptnaken_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTNAKEN register
 */
#define HW_USBC_UOG_ENDPTNAKEN_ADDR      (REGS_USBC_BASE + 0x17c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTNAKEN           (*(volatile hw_usbc_uog_endptnaken_t *) HW_USBC_UOG_ENDPTNAKEN_ADDR)
#define HW_USBC_UOG_ENDPTNAKEN_RD()      (HW_USBC_UOG_ENDPTNAKEN.U)
#define HW_USBC_UOG_ENDPTNAKEN_WR(v)     (HW_USBC_UOG_ENDPTNAKEN.U = (v))
#define HW_USBC_UOG_ENDPTNAKEN_SET(v)    (HW_USBC_UOG_ENDPTNAKEN_WR(HW_USBC_UOG_ENDPTNAKEN_RD() |  (v)))
#define HW_USBC_UOG_ENDPTNAKEN_CLR(v)    (HW_USBC_UOG_ENDPTNAKEN_WR(HW_USBC_UOG_ENDPTNAKEN_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTNAKEN_TOG(v)    (HW_USBC_UOG_ENDPTNAKEN_WR(HW_USBC_UOG_ENDPTNAKEN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTNAKEN bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTNAKEN, field EPRNE
 *
 * RX Endpoint NAK Enable - R/W.  Each bit is an enable bit for the corresponding RX Endpoint NAK
 * bit. If this bit is set                                 and the corresponding RX Endpoint NAK bit
 * is set, the NAK Interrupt bit is set.  Bit [N] - Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAKEN_EPRNE      0
#define BM_USBC_UOG_ENDPTNAKEN_EPRNE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAKEN_EPRNE(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTNAKEN_EPRNE)
#else
#define BF_USBC_UOG_ENDPTNAKEN_EPRNE(v)   (((v) << 0) & BM_USBC_UOG_ENDPTNAKEN_EPRNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTNAKEN_EPRNE(v)   BF_CS1(USBC_UOG_ENDPTNAKEN, EPRNE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTNAKEN, field EPTNE
 *
 * TX Endpoint NAK Enable - R/W.  Each bit is an enable bit for the corresponding TX Endpoint NAK
 * bit. If this bit is set                                 and the corresponding TX Endpoint NAK bit
 * is set, the NAK Interrupt bit is set.  Bit [N] - Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAKEN_EPTNE      16
#define BM_USBC_UOG_ENDPTNAKEN_EPTNE      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAKEN_EPTNE(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTNAKEN_EPTNE)
#else
#define BF_USBC_UOG_ENDPTNAKEN_EPTNE(v)   (((v) << 16) & BM_USBC_UOG_ENDPTNAKEN_EPTNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTNAKEN_EPTNE(v)   BF_CS1(USBC_UOG_ENDPTNAKEN, EPTNE, v)
#endif

/*!
 * @brief HW_USBC__PORTSC1 - Port Status & Control
 *
 * Host Controller  A host controller could implement one to eight port status and control
 * registers. The number                             is determined by N_PORTs bits in HWSPARAMs
 * register (please see ). Software could read this parameter register to
 * determine how many ports need service.  All 4 controller cores are Single-Port Host, so there is
 * only one port status and control                             register for each controller core.
 * This register is only reset by power on reset or controller core reset. The initial
 * conditions of a port are:   No device connected  Port disabled   If the port supports power
 * control, this state remains until port power is supplied (by
 * software).  Device Controller  A device controller has only port register one (PORTSC1) and it
 * does not support power                             control. Port control in device mode is only
 * used for status port reset, suspend, and                             current connect status. It
 * is also used to initiate test mode or force signaling and allows
 * software to put the PHY into low power suspend mode and disable the PHY clock.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCS : 1; //!< Current Connect Status-Read Only.  In Host Mode:  1=Device is present on port. 0=No device is present. Default = 0. This value reflects the current state of the port, and may not correspond directly to the event that caused the Connect Status Change bit (Bit 1) to be set.  This field is zero if Port Power(   ) is zero in host mode.  In Device Mode:  1=Attached. 0=Not Attached. Default=0. A one indicates that the device successfully attached and is operating in either high speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates that the device did not attach successfully or was forcibly disconnected by the software writing a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or suspended.
        unsigned CSC : 1; //!< Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0.  In Host Mode:  Indicates a change has occurred in the port's Current Connect Status. The host/device controller sets this bit for all changes to the port device connect status, even if system software has not cleared an existing connect status change. For example, the insertion status changes twice before system software has cleared the changed condition, hub hardware will be 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by writing a one to it.  This field is zero if Port Power(   ) is zero in host mode.  In Device Mode:  This bit is undefined in device controller mode.
        unsigned PE : 1; //!< Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0.  In Host Mode:  Ports can only be enabled by the host controller as a part of the reset and enable. Software cannot enable a port by writing a one to this field. Ports can be disabled by either a fault condition (disconnect event or other fault condition) or by the host software. Note that the bit status does not change until the port state actually changes. There may be a delay in disabling or enabling a port due to other host controller and bus events.  When the port is disabled, (0b) downstream propagation of data is blocked except for reset.  This field is zero if Port Power(   ) is zero in host mode.  In Device Mode:  The device port is always enabled, so this bit is always '1b'.
        unsigned PEC : 1; //!< Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default = 0.  In Host Mode:  For the root hub, this bit is set to a one only when a port is disabled due to disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See Chapter 11 of the USB Specification). Software clears this by writing a one to it.  This field is zero if Port Power(   ) is zero.  In Device mode:  The device port is always enabled, so this bit is always '0b'.
        unsigned OCA : 1; //!< Over-current Active-Read Only. Default 0.  This bit will automatically transition from one to zero when the over current condition is removed.  For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition.  For device-only implementations this bit shall always be 0.
        unsigned OCC : 1; //!< Over-current Change-R/WC. Default=0.  This bit is set '1b' by hardware when there is a change to Over-current Active. Software can clear this bit by writing a one to this bit position.  For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition.   For device-only implementations this bit shall always be 0.
        unsigned FPR : 1; //!< Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state) detected/driven on port. Default = 0.  In Host Mode:  Software sets this bit to one to drive resume signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will automatically change to zero after the resume sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the resume duration is timed in the driver.   Note that when the Host controller owns the port, the resume sequence follows the defined sequence documented in the USB Specification Revision 2.0. The resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no affect because the port controller will time the resume operation clear the bit the port control state switches to HS or FS idle.  This field is zero if Port Power(   ) is zero in host mode.  This bit is not-EHCI compatible.  In Device mode:  After the device has been in Suspend State for 5ms or more, software must set this bit to one to drive resume signaling before clearing. The Device Controller will set this bit to one if a J-to-K transition is detected while the port is in the Suspend state. The bit will be cleared when the device returns to normal operation. Also, when this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the USBSTS register is also set to one.
        unsigned SUSP : 1; //!< Suspend - Read/Write or Read Only. Default = 0b.  1=Port in suspend state. 0=Port not in suspend state.  In Host Mode: Read/Write.  Port Enabled Bit and Suspend bit of this register define the port states as follows:  Bits [Port Enabled, Suspend] Port State  0x Disable  10 Enable  11 Suspend  When in suspend state, downstream propagation of data is blocked on this port, except for port reset. The blocking occurs at the end of the current transaction if a transaction was in progress when this bit was written to 1. In the suspend state, the port is sensitive to resume detection. Note that the bit status does not change until the port is suspended and that there may be a delay in suspending a port if there is a transaction currently in progress on the  The host controller will unconditionally set this bit to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write of zero to this bit.  If host software sets this bit to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are undefined.  This field is zero if Port Power(   ) is zero in host mode.  In Device Mode: Read Only.  In device mode this bit is a read only status bit.
        unsigned PR : 1; //!< Port Reset - Read/Write or Read Only. Default = 0b.  In Host Mode: Read/Write. 1=Port is in Reset. 0=Port is not in Reset. Default 0.  When software writes a one to this bit the bus-reset sequence as defined in the USB Specification Revision 2.0 is started. This bit will automatically change to zero after the reset sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the reset duration is timed in the driver.   In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also indicated in the USBSTS register.  This field is zero if Port Power(   ) is zero.
        unsigned HSP : 1; //!< High-Speed Port - Read Only. Default = 0b.  When the bit is one, the host/device connected to the port is in high-speed mode and if set to zero, the host/device connected to the port is not in a high-speed mode.  HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
        unsigned LS : 2; //!< Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D- (bit 10) signal lines.  In host mode, the use of linestate by the host controller driver is not necessary (unlike EHCI), because the port controller state machine and the port routing manage the connection of LS and FS.  In device mode, the use of linestate by the device controller driver is not necessary.  The encoding of the bits are:  Bits [11:10] Meaning
        unsigned PP : 1; //!< Port Power (PP)-Read/Write or Read Only.  The function of this bit depends on the value of the Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows:  PPC PP Operation  0 1b Read Only - Host controller does not have port power control switches. Each port is hard-wired to power.   1 1b/0b - Read/Write. Host/OTG controller requires port power control switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not available on a port (that is, PP equals a 0), the port is non-functional and will not report attaches, detaches, etc.   When an over-current condition is detected on a powered port and PPC is a one, the PP bit in each affected port may be transitional by the host controller driver from a one to a zero (removing power from the port).  This feature is implemented in all 4 controller cores (PPC = 1).
        unsigned PO : 1; //!< Port Owner-Read/Write. Default = 0.  This bit unconditionally goes to a 0 when the configured bit in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever the Configured bit is zero System software uses this field to release ownership of the port to a selected host controller (in the event that the attached device is not a high-speed device). Software writes a one to this bit when the attached device is not a high-speed device. A one in this bit means that an internal companion controller owns and controls the port.  Port owner handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
        unsigned PIC : 2; //!< Port Indicator Control - Read/Write. Default = Ob.  Writing to this field has no effect if the P_INDICATOR bit in the HCSPARAMS register is a zero.  Refer to the USB Specification Revision 2.0 for a description on how these bits are to be used.  This field is zero if Port Power is zero.  Bit Value Meaning
        unsigned PTC : 4; //!< Port Test Control - Read/Write. Default = 0000b.  Refer to Section 4.14 for the operational model for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each test mode.  The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS} values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point.   Low speed operations are not supported as a peripheral device.   Any other value than zero indicates that the port is operating in test mode.  Value Specific Test
        unsigned WKCN : 1; //!< Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b.  Writing this bit to a one enables the port to be sensitive to device connects as wake-up events.  This field is zero if Port Power(   ) is zero or in device mode.
        unsigned WKDC : 1; //!< Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device disconnects as wake-up events.  This field is zero if Port Power(   ) is zero or in device mode.
        unsigned WKOC : 1; //!< Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b.  Writing this bit to a one enables the port to be sensitive to over-current conditions as wake-up events.  This field is zero if Port Power(   ) is zero.
        unsigned PHCD : 1; //!< PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b.  When this bit is set to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock.  The PHY clock cannot be disabled if it is being used as the system clock.  In device mode, The PHY can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically when the host initials resume. Before forcing a resume from the device, the device controller driver must clear this bit.  In host mode, the PHY can be put into Low Power Suspend when the downstream device has been put into suspend mode or when no downstream device is connected. Low power suspend is completely under the control of software.
        unsigned PFSC : 1; //!< Port Force Full Speed Connect - Read/Write. Default = 0b.  When this bit is set to '1b', the port will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port to identify itself as High Speed.
        unsigned PTS : 1; //!< See description at bits 31-30
        unsigned PSPD : 2; //!< Port Speed - Read Only.  This register field indicates the speed at which the port is operating.  For HS mode operation in the host controller and HS/FS operation in the device controller the port routing steers data to the Protocol engine. For FS and LS mode operation in the host controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction Translator.
        unsigned PTW : 1; //!< Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16 selects a default UTMI interface width of 16-bits else it is reset to 0.  Writing this bit to 0 selects the 8-bit [60MHz] UTMI interface.  Writing this bit to 1 selects the 16-bit [30MHz] UTMI interface.  This bit has no effect if the Serial interfaces are selected.  This bit is not defined in the EHCI specification.  VUSB_HS_PHY16_8 parameter:  For Elvis, OTG: 3, Host1/Host2/Host3: 0;  For Rita, OTG/Host1/Host2/Host3: 3;  For Arik, OTG/Host1/Host2/Host3: 1;  Parallel Transceiver Width  This bit has no effect if serial interface engine is used.  These register bits are implementation dependent.  For OTG controller core: it is Read/Write. Reset value is '1b'; For Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'.  For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'.  For OTG/Host1/Host2/Host3 core, it is Read-Only. Reset value is '1b'.
        unsigned STS : 1; //!< Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver interface is selected for FS and LS operation. The Serial Interface Engine can be used in combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write.  This bit has no effect unless Parallel Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial Interface Engine for FS/LS signaling regardless of this bit value.  Note: This bit is reserved for future operation and is a placeholder adding dynamic use of the serial engine in accord with UMTI+ and ULPI characterization logic.  This bit is not defined in the EHCI specification  VUSB_HS_PHY_SERIAL parameter:  For Elivs,OTG/Host1/Host2/Host3 core: 2  For Rita, OTG/Host1/Host2/Host3 core: 2  For Arik, OTG/Host1/Host2/Host3 core: 0  Serial Transceiver Select - Read/Write. Reset value is 0b.  1 Serial Interface Engine is selected  0 Parallel Interface signals is selected  Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the parallel interface signals.  When this bit is set '1b', serial interface engine will be used instead of parallel interface signals.  This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface.  The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value.  Serial Transceiver Select - Read-Only. Reset value is 0b.  1 Serial Interface Engine is selected  0 Parallel Interface signals is selected  Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface signals.  When this bit is set '1b', serial interface engine will be used instead of parallel interface signals.  This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface.   The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value.
        unsigned PTS1 : 2; //!< Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write.  Bit field {bit25, bit30, bit31} is reset to:  "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+  "001b" if VUSB_HS_PHY_TYPE = 1,5 - Reserved  "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI  "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 - Serial/1.1 PHY/IC USB(FS Only)  "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY  This bit is not defined in the EHCI specification.  VUSB_HS_PHY_TYPE parameter:  For Elvis, OTG/Host core: 7;  For Rita, OTG core: 0, Host core: 7  For Arik, OTG core: 0, Host core: 4  Parallel Transceiver Select (bit31, bi30). These register bits are implementation dependent.  For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '11b'.  Bit field { bit31, bit30}:  "00b" UTMI/UTMI+  "01b" Reserved  "10b" ULPI  "11b" Serial/USB 1.1 PHY/IC-USB (FS Only)  Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent.  For OTG core, it's Read-Only. Reset value is 000b.  For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b.  Bit field {bit25, bit31, bit30}:  "000b" UTMI/UTMI+  "001b" Reserved  "010b" ULPI  "011b" Serial/USB 1.1 PHY/IC-USB (FS Only)  "100b" HSIC  Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent.  For OTG core, it is Read-Only. Reset value is 000b.  For Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b.  Bit field {bit25, bit31, bit30}:  "000b" UTMI/UTMI+  "001b" Reserved  "010b" ULPI  "011b" Serial/USB 1.1 PHY/IC-USB (FS Only)  "100b" HSIC  All USB port interface modes are listed in this field description, but not all are supported. For detail feature of each controller core, please see . The behaviour is unknown when unsupported interface mode is selected.
    } B;
} hw_usbc__portsc1_t;
#endif

/*
 * constants & macros for entire USBC__PORTSC1 register
 */
#define HW_USBC__PORTSC1_ADDR      (REGS_USBC_BASE + 0x184)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PORTSC1           (*(volatile hw_usbc__portsc1_t *) HW_USBC__PORTSC1_ADDR)
#define HW_USBC__PORTSC1_RD()      (HW_USBC__PORTSC1.U)
#define HW_USBC__PORTSC1_WR(v)     (HW_USBC__PORTSC1.U = (v))
#define HW_USBC__PORTSC1_SET(v)    (HW_USBC__PORTSC1_WR(HW_USBC__PORTSC1_RD() |  (v)))
#define HW_USBC__PORTSC1_CLR(v)    (HW_USBC__PORTSC1_WR(HW_USBC__PORTSC1_RD() & ~(v)))
#define HW_USBC__PORTSC1_TOG(v)    (HW_USBC__PORTSC1_WR(HW_USBC__PORTSC1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__PORTSC1 bitfields
 */

/* --- Register HW_USBC__PORTSC1, field CCS
 *
 * Current Connect Status-Read Only.  In Host Mode:  1=Device is present on port. 0=No device is
 * present. Default = 0. This value reflects the                                 current state of
 * the port, and may not correspond directly to the event that caused the Connect Status Change bit
 * (Bit 1) to be set.  This field is zero if Port Power(   ) is zero in host mode.  In Device Mode:
 * 1=Attached. 0=Not Attached. Default=0. A one indicates that the device successfully
 * attached and is operating in either high speed or full speed as indicated by the High
 * Speed Port bit in this register. A zero indicates that the device did not attach
 * successfully or was forcibly disconnected by the software writing a zero to the Run bit
 * in the USBCMD register. It does not state the device being disconnected or
 * suspended.
 */

#define BP_USBC__PORTSC1_CCS      0
#define BM_USBC__PORTSC1_CCS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_CCS(v)   ((((reg32_t) v) << 0) & BM_USBC__PORTSC1_CCS)
#else
#define BF_USBC__PORTSC1_CCS(v)   (((v) << 0) & BM_USBC__PORTSC1_CCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_CCS(v)   BF_CS1(USBC__PORTSC1, CCS, v)
#endif

/* --- Register HW_USBC__PORTSC1, field CSC
 *
 * Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default
 * 0.  In Host Mode:  Indicates a change has occurred in the port's Current Connect Status. The
 * host/device                                 controller sets this bit for all changes to the port
 * device connect status, even if                                 system software has not cleared an
 * existing connect status change. For example, the                                 insertion status
 * changes twice before system software has cleared the changed condition,
 * hub hardware will be 'setting' an already-set bit (that is, the bit will remain set).
 * Software clears this bit by writing a one to it.  This field is zero if Port Power(   ) is zero
 * in host mode.  In Device Mode:  This bit is undefined in device controller mode.
 */

#define BP_USBC__PORTSC1_CSC      1
#define BM_USBC__PORTSC1_CSC      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_CSC(v)   ((((reg32_t) v) << 1) & BM_USBC__PORTSC1_CSC)
#else
#define BF_USBC__PORTSC1_CSC(v)   (((v) << 1) & BM_USBC__PORTSC1_CSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_CSC(v)   BF_CS1(USBC__PORTSC1, CSC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PE
 *
 * Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0.  In Host Mode:  Ports can only
 * be enabled by the host controller as a part of the reset and enable.
 * Software cannot enable a port by writing a one to this field. Ports can be disabled by
 * either a fault condition (disconnect event or other fault condition) or by the host
 * software. Note that the bit status does not change until the port state actually
 * changes. There may be a delay in disabling or enabling a port due to other host
 * controller and bus events.  When the port is disabled, (0b) downstream propagation of data is
 * blocked except for                                 reset.  This field is zero if Port Power(   )
 * is zero in host mode.  In Device Mode:  The device port is always enabled, so this bit is always
 * '1b'.
 */

#define BP_USBC__PORTSC1_PE      2
#define BM_USBC__PORTSC1_PE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PE(v)   ((((reg32_t) v) << 2) & BM_USBC__PORTSC1_PE)
#else
#define BF_USBC__PORTSC1_PE(v)   (((v) << 2) & BM_USBC__PORTSC1_PE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PE(v)   BF_CS1(USBC__PORTSC1, PE, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PEC
 *
 * Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change.
 * Default = 0.  In Host Mode:  For the root hub, this bit is set to a one only when a port is
 * disabled due to disconnect                                 on the port or due to the appropriate
 * conditions existing at the EOF2 point (See Chapter                                 11 of the USB
 * Specification). Software clears this by writing a one to it.  This field is zero if Port Power(
 * ) is zero.  In Device mode:  The device port is always enabled, so this bit is always '0b'.
 */

#define BP_USBC__PORTSC1_PEC      3
#define BM_USBC__PORTSC1_PEC      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PEC(v)   ((((reg32_t) v) << 3) & BM_USBC__PORTSC1_PEC)
#else
#define BF_USBC__PORTSC1_PEC(v)   (((v) << 3) & BM_USBC__PORTSC1_PEC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PEC(v)   BF_CS1(USBC__PORTSC1, PEC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field OCA
 *
 * Over-current Active-Read Only. Default 0.  This bit will automatically transition from one to
 * zero when the over current condition                                 is removed.  For host/OTG
 * implementations the user can provide over-current                                 detection to
 * the vbus_pwr_fault input for this condition.  For device-only implementations this bit shall
 * always be 0.
 */

#define BP_USBC__PORTSC1_OCA      4
#define BM_USBC__PORTSC1_OCA      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_OCA(v)   ((((reg32_t) v) << 4) & BM_USBC__PORTSC1_OCA)
#else
#define BF_USBC__PORTSC1_OCA(v)   (((v) << 4) & BM_USBC__PORTSC1_OCA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_OCA(v)   BF_CS1(USBC__PORTSC1, OCA, v)
#endif

/* --- Register HW_USBC__PORTSC1, field OCC
 *
 * Over-current Change-R/WC. Default=0.  This bit is set '1b' by hardware when there is a change to
 * Over-current Active. Software                                 can clear this bit by writing a one
 * to this bit position.  For host/OTG implementations the user can provide over-current
 * detection to the vbus_pwr_fault input for this condition.   For device-only implementations this
 * bit shall always be 0.
 */

#define BP_USBC__PORTSC1_OCC      5
#define BM_USBC__PORTSC1_OCC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_OCC(v)   ((((reg32_t) v) << 5) & BM_USBC__PORTSC1_OCC)
#else
#define BF_USBC__PORTSC1_OCC(v)   (((v) << 5) & BM_USBC__PORTSC1_OCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_OCC(v)   BF_CS1(USBC__PORTSC1, OCC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field FPR
 *
 * Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state)
 * detected/driven on port. Default = 0.  In Host Mode:  Software sets this bit to one to drive
 * resume signaling. The Host Controller sets this                                 bit to one if a
 * J-to-K transition is detected while the port is in the Suspend state.
 * When this bit transitions to a one because a J-to-K transition is detected, the Port
 * Change Detect bit in the USBSTS register is also set to one. This bit will
 * automatically change to zero after the resume sequence is complete. This behavior is
 * different from EHCI where the host controller driver is required to set this bit to
 * a zero after the resume duration is timed in the driver.   Note that when the Host controller
 * owns the port, the resume sequence follows the defined                                 sequence
 * documented in the USB Specification Revision 2.0. The resume signaling
 * (Full-speed 'K') is driven on the port as long as this bit remains a one. This bit will
 * remain a one until the port has switched to the high-speed idle. Writing a zero has no
 * affect because the port controller will time the resume operation clear the bit the port
 * control state switches to HS or FS idle.  This field is zero if Port Power(   ) is zero in host
 * mode.  This bit is not-EHCI compatible.  In Device mode:  After the device has been in Suspend
 * State for 5ms or more, software must set this bit to                                 one to drive
 * resume signaling before clearing. The Device Controller will set this bit
 * to one if a J-to-K transition is detected while the port is in the Suspend state. The
 * bit will be cleared when the device returns to normal operation. Also, when this bit
 * wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the USBSTS
 * register is also set to one.
 */

#define BP_USBC__PORTSC1_FPR      6
#define BM_USBC__PORTSC1_FPR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_FPR(v)   ((((reg32_t) v) << 6) & BM_USBC__PORTSC1_FPR)
#else
#define BF_USBC__PORTSC1_FPR(v)   (((v) << 6) & BM_USBC__PORTSC1_FPR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_FPR(v)   BF_CS1(USBC__PORTSC1, FPR, v)
#endif

/* --- Register HW_USBC__PORTSC1, field SUSP
 *
 * Suspend - Read/Write or Read Only. Default = 0b.  1=Port in suspend state. 0=Port not in suspend
 * state.  In Host Mode: Read/Write.  Port Enabled Bit and Suspend bit of this register define the
 * port states as follows:  Bits [Port Enabled, Suspend] Port State  0x Disable  10 Enable  11
 * Suspend  When in suspend state, downstream propagation of data is blocked on this port, except
 * for                                 port reset. The blocking occurs at the end of the current
 * transaction if a transaction                                 was in progress when this bit was
 * written to 1. In the suspend state, the port is                                 sensitive to
 * resume detection. Note that the bit status does not change until the port
 * is suspended and that there may be a delay in suspending a port if there is a
 * transaction currently in progress on the  The host controller will unconditionally set this bit
 * to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write
 * of zero to                                 this bit.  If host software sets this bit to a one
 * when the port is not enabled (that is, Port                                     enabled bit is a
 * zero) the results are undefined.  This field is zero if Port Power(   ) is zero in host mode.  In
 * Device Mode: Read Only.  In device mode this bit is a read only status bit.
 */

#define BP_USBC__PORTSC1_SUSP      7
#define BM_USBC__PORTSC1_SUSP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_SUSP(v)   ((((reg32_t) v) << 7) & BM_USBC__PORTSC1_SUSP)
#else
#define BF_USBC__PORTSC1_SUSP(v)   (((v) << 7) & BM_USBC__PORTSC1_SUSP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_SUSP(v)   BF_CS1(USBC__PORTSC1, SUSP, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PR
 *
 * Port Reset - Read/Write or Read Only. Default = 0b.  In Host Mode: Read/Write. 1=Port is in
 * Reset. 0=Port is not in Reset. Default 0.  When software writes a one to this bit the bus-reset
 * sequence as defined in the USB                                 Specification Revision 2.0 is
 * started. This bit will automatically change to zero                                     after the
 * reset sequence is complete. This behavior is different from EHCI where the
 * host controller driver is required to set this bit to a zero after the reset
 * duration is timed in the driver.   In Device Mode: This bit is a read only status bit. Device
 * reset from the USB bus is also                                 indicated in the USBSTS register.
 * This field is zero if Port Power(   ) is zero.
 */

#define BP_USBC__PORTSC1_PR      8
#define BM_USBC__PORTSC1_PR      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PR(v)   ((((reg32_t) v) << 8) & BM_USBC__PORTSC1_PR)
#else
#define BF_USBC__PORTSC1_PR(v)   (((v) << 8) & BM_USBC__PORTSC1_PR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PR(v)   BF_CS1(USBC__PORTSC1, PR, v)
#endif

/* --- Register HW_USBC__PORTSC1, field HSP
 *
 * High-Speed Port - Read Only. Default = 0b.  When the bit is one, the host/device connected to the
 * port is in high-speed mode and if                                 set to zero, the host/device
 * connected to the port is not in a high-speed mode.  HSP is redundant with PSPD(bit 27, 26) but
 * remained for compatibility.
 */

#define BP_USBC__PORTSC1_HSP      9
#define BM_USBC__PORTSC1_HSP      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_HSP(v)   ((((reg32_t) v) << 9) & BM_USBC__PORTSC1_HSP)
#else
#define BF_USBC__PORTSC1_HSP(v)   (((v) << 9) & BM_USBC__PORTSC1_HSP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_HSP(v)   BF_CS1(USBC__PORTSC1, HSP, v)
#endif

/* --- Register HW_USBC__PORTSC1, field LS
 *
 * Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11)
 * and D- (bit 10) signal lines.  In host mode, the use of linestate by the host controller driver
 * is not necessary (unlike                                 EHCI), because the port controller state
 * machine and the port routing manage the                                 connection of LS and FS.
 * In device mode, the use of linestate by the device controller driver is not
 * necessary.  The encoding of the bits are:  Bits [11:10] Meaning
 */

#define BP_USBC__PORTSC1_LS      10
#define BM_USBC__PORTSC1_LS      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_LS(v)   ((((reg32_t) v) << 10) & BM_USBC__PORTSC1_LS)
#else
#define BF_USBC__PORTSC1_LS(v)   (((v) << 10) & BM_USBC__PORTSC1_LS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_LS(v)   BF_CS1(USBC__PORTSC1, LS, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PP
 *
 * Port Power (PP)-Read/Write or Read Only.  The function of this bit depends on the value of the
 * Port Power Switching (PPC) field in                                 the HCSPARAMS register. The
 * behavior is as follows:  PPC PP Operation  0 1b Read Only - Host controller does not have port
 * power control switches. Each port                                     is hard-wired to power.   1
 * 1b/0b - Read/Write. Host/OTG controller requires port power control switches. This
 * bit represents the current setting of the switch (0=off, 1=on). When power is not
 * available on a port (that is, PP equals a 0), the port is non-functional and will
 * not report attaches, detaches, etc.   When an over-current condition is detected on a powered
 * port and PPC is a one, the PP bit                                 in each affected port may be
 * transitional by the host controller driver from a one to a                                 zero
 * (removing power from the port).  This feature is implemented in all 4 controller cores (PPC = 1).
 */

#define BP_USBC__PORTSC1_PP      12
#define BM_USBC__PORTSC1_PP      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PP(v)   ((((reg32_t) v) << 12) & BM_USBC__PORTSC1_PP)
#else
#define BF_USBC__PORTSC1_PP(v)   (((v) << 12) & BM_USBC__PORTSC1_PP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PP(v)   BF_CS1(USBC__PORTSC1, PP, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PO
 *
 * Port Owner-Read/Write. Default = 0.  This bit unconditionally goes to a 0 when the configured bit
 * in the CONFIGFLAG register                                 makes a 0 to 1 transition. This bit
 * unconditionally goes to 1 whenever the Configured                                 bit is zero
 * System software uses this field to release ownership of the port to a
 * selected host controller (in the event that the attached device is not a high-speed
 * device). Software writes a one to this bit when the attached device is not a high-speed
 * device. A one in this bit means that an internal companion controller owns and controls
 * the port.  Port owner handoff is not supported in all 4 controller cores, therefore this bit will
 * always be 0.
 */

#define BP_USBC__PORTSC1_PO      13
#define BM_USBC__PORTSC1_PO      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PO(v)   ((((reg32_t) v) << 13) & BM_USBC__PORTSC1_PO)
#else
#define BF_USBC__PORTSC1_PO(v)   (((v) << 13) & BM_USBC__PORTSC1_PO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PO(v)   BF_CS1(USBC__PORTSC1, PO, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PIC
 *
 * Port Indicator Control - Read/Write. Default = Ob.  Writing to this field has no effect if the
 * P_INDICATOR bit in the HCSPARAMS register is a                                 zero.  Refer to
 * the USB Specification Revision 2.0 for a description on how these bits are to be
 * used.  This field is zero if Port Power is zero.  Bit Value Meaning
 */

#define BP_USBC__PORTSC1_PIC      14
#define BM_USBC__PORTSC1_PIC      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PIC(v)   ((((reg32_t) v) << 14) & BM_USBC__PORTSC1_PIC)
#else
#define BF_USBC__PORTSC1_PIC(v)   (((v) << 14) & BM_USBC__PORTSC1_PIC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PIC(v)   BF_CS1(USBC__PORTSC1, PIC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PTC
 *
 * Port Test Control - Read/Write. Default = 0000b.  Refer to Section 4.14 for the operational model
 * for using these test modes and the USB                                 Specification Revision
 * 2.0, Chapter 7 for details on each test mode.  The FORCE_ENABLE_FS and FORCE ENABLE_LS are
 * extensions to the test mode support specified                                 in the EHCI
 * specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS}
 * values will force the port into the connected and enabled state at the selected speed.
 * Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to
 * progress normally from that point.   Low speed operations are not supported as a peripheral
 * device.   Any other value than zero indicates that the port is operating in test mode.  Value
 * Specific Test
 */

#define BP_USBC__PORTSC1_PTC      16
#define BM_USBC__PORTSC1_PTC      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PTC(v)   ((((reg32_t) v) << 16) & BM_USBC__PORTSC1_PTC)
#else
#define BF_USBC__PORTSC1_PTC(v)   (((v) << 16) & BM_USBC__PORTSC1_PTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PTC(v)   BF_CS1(USBC__PORTSC1, PTC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field WKCN
 *
 * Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b.  Writing this bit to a one enables
 * the port to be sensitive to device connects as wake-up                                 events.
 * This field is zero if Port Power(   ) is zero or in device mode.
 */

#define BP_USBC__PORTSC1_WKCN      20
#define BM_USBC__PORTSC1_WKCN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_WKCN(v)   ((((reg32_t) v) << 20) & BM_USBC__PORTSC1_WKCN)
#else
#define BF_USBC__PORTSC1_WKCN(v)   (((v) << 20) & BM_USBC__PORTSC1_WKCN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_WKCN(v)   BF_CS1(USBC__PORTSC1, WKCN, v)
#endif

/* --- Register HW_USBC__PORTSC1, field WKDC
 *
 * Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a
 * one enables the port to be sensitive to device disconnects as wake-up events.  This field is zero
 * if Port Power(   ) is zero or in device mode.
 */

#define BP_USBC__PORTSC1_WKDC      21
#define BM_USBC__PORTSC1_WKDC      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_WKDC(v)   ((((reg32_t) v) << 21) & BM_USBC__PORTSC1_WKDC)
#else
#define BF_USBC__PORTSC1_WKDC(v)   (((v) << 21) & BM_USBC__PORTSC1_WKDC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_WKDC(v)   BF_CS1(USBC__PORTSC1, WKDC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field WKOC
 *
 * Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b.  Writing this bit to a one
 * enables the port to be sensitive to over-current conditions as
 * wake-up events.  This field is zero if Port Power(   ) is zero.
 */

#define BP_USBC__PORTSC1_WKOC      22
#define BM_USBC__PORTSC1_WKOC      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_WKOC(v)   ((((reg32_t) v) << 22) & BM_USBC__PORTSC1_WKOC)
#else
#define BF_USBC__PORTSC1_WKOC(v)   (((v) << 22) & BM_USBC__PORTSC1_WKOC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_WKOC(v)   BF_CS1(USBC__PORTSC1, WKOC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PHCD
 *
 * PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b.  When this bit is set
 * to '1b', the PHY clock is disabled. Reading this bit will indicate
 * the status of the PHY clock.  The PHY clock cannot be disabled if it is being used as the system
 * clock.  In device mode, The PHY can be put into Low Power Suspend when the device is not running
 * (USBCMD Run/Stop=0b) or the host has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low
 * power suspend will be cleared automatically when the host initials resume. Before
 * forcing a resume from the device, the device controller driver must clear this bit.  In host
 * mode, the PHY can be put into Low Power Suspend when the downstream device has
 * been put into suspend mode or when no downstream device is connected. Low power suspend
 * is completely under the control of software.
 */

#define BP_USBC__PORTSC1_PHCD      23
#define BM_USBC__PORTSC1_PHCD      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PHCD(v)   ((((reg32_t) v) << 23) & BM_USBC__PORTSC1_PHCD)
#else
#define BF_USBC__PORTSC1_PHCD(v)   (((v) << 23) & BM_USBC__PORTSC1_PHCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PHCD(v)   BF_CS1(USBC__PORTSC1, PHCD, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PFSC
 *
 * Port Force Full Speed Connect - Read/Write. Default = 0b.  When this bit is set to '1b', the port
 * will be forced to only connect at Full Speed, It                                 disables the
 * chirp sequence that allows the port to identify itself as High Speed.
 */

#define BP_USBC__PORTSC1_PFSC      24
#define BM_USBC__PORTSC1_PFSC      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PFSC(v)   ((((reg32_t) v) << 24) & BM_USBC__PORTSC1_PFSC)
#else
#define BF_USBC__PORTSC1_PFSC(v)   (((v) << 24) & BM_USBC__PORTSC1_PFSC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PFSC(v)   BF_CS1(USBC__PORTSC1, PFSC, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PTS
 *
 * See description at bits 31-30
 */

#define BP_USBC__PORTSC1_PTS      25
#define BM_USBC__PORTSC1_PTS      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PTS(v)   ((((reg32_t) v) << 25) & BM_USBC__PORTSC1_PTS)
#else
#define BF_USBC__PORTSC1_PTS(v)   (((v) << 25) & BM_USBC__PORTSC1_PTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PTS(v)   BF_CS1(USBC__PORTSC1, PTS, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PSPD
 *
 * Port Speed - Read Only.  This register field indicates the speed at which the port is operating.
 * For HS mode operation in the host controller and HS/FS operation in
 * the device controller the port routing steers data to the Protocol engine. For FS and LS
 * mode operation in the host controller, the port routing steers data to the Protocol
 * Engine w/ Embedded Transaction Translator.
 */

#define BP_USBC__PORTSC1_PSPD      26
#define BM_USBC__PORTSC1_PSPD      0x0c000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PSPD(v)   ((((reg32_t) v) << 26) & BM_USBC__PORTSC1_PSPD)
#else
#define BF_USBC__PORTSC1_PSPD(v)   (((v) << 26) & BM_USBC__PORTSC1_PSPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PSPD(v)   BF_CS1(USBC__PORTSC1, PSPD, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PTW
 *
 * Parallel Transceiver Width - Read/Write. This register bit is used in
 * conjunction with the configuration constant VUSB_HS_PHY8_16 to control whether the data
 * bus width of the UTMI transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then
 * this bit is read only. If VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This
 * bit is reset to 1 if VUSB_HS_PHY8_16 selects a default UTMI interface width of 16-bits
 * else it is reset to 0.  Writing this bit to 0 selects the 8-bit [60MHz] UTMI interface.  Writing
 * this bit to 1 selects the 16-bit [30MHz] UTMI interface.  This bit has no effect if the Serial
 * interfaces are selected.  This bit is not defined in the EHCI specification.  VUSB_HS_PHY16_8
 * parameter:  For Elvis, OTG: 3, Host1/Host2/Host3: 0;  For Rita, OTG/Host1/Host2/Host3: 3;  For
 * Arik, OTG/Host1/Host2/Host3: 1;  Parallel Transceiver Width  This bit has no effect if serial
 * interface engine is used.  These register bits are implementation dependent.  For OTG controller
 * core: it is Read/Write. Reset value is '1b'; For
 * Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'.  For
 * OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is
 * '1b'.  For OTG/Host1/Host2/Host3 core, it is Read-Only. Reset value is
 * '1b'.
 */

#define BP_USBC__PORTSC1_PTW      28
#define BM_USBC__PORTSC1_PTW      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PTW(v)   ((((reg32_t) v) << 28) & BM_USBC__PORTSC1_PTW)
#else
#define BF_USBC__PORTSC1_PTW(v)   (((v) << 28) & BM_USBC__PORTSC1_PTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PTW(v)   BF_CS1(USBC__PORTSC1, PTW, v)
#endif

/* --- Register HW_USBC__PORTSC1, field STS
 *
 * Serial Transceiver Select - Read/Write. This register bit is used in
 * conjunction with the configuration constant VUSB_HS_PHY_SERIAL to control whether the
 * parallel or serial transceiver interface is selected for FS and LS operation. The Serial
 * Interface Engine can be used in combination with the UTMI+ or ULPI physical interface to
 * provide FS/LS signaling instead of the parallel interface. If VUSB_HS_PHY_SERIAL is set
 * for 0 or 1 then this bit is read only. If VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is
 * read/write.  This bit has no effect unless Parallel Transceiver Select is set to
 * UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial Interface Engine
 * for FS/LS signaling regardless of this bit value.  Note: This bit is reserved for future
 * operation and is a placeholder                                 adding dynamic use of the serial
 * engine in accord with UMTI+ and ULPI characterization                                 logic.
 * This bit is not defined in the EHCI specification  VUSB_HS_PHY_SERIAL parameter:  For
 * Elivs,OTG/Host1/Host2/Host3 core: 2  For Rita, OTG/Host1/Host2/Host3 core: 2  For Arik,
 * OTG/Host1/Host2/Host3 core: 0  Serial Transceiver Select - Read/Write. Reset value is
 * 0b.  1 Serial Interface Engine is selected  0 Parallel Interface signals is selected  Serial
 * Interface Engine can be used in combination with                                 UTMI+/ULPI
 * physical interface to provide FS/LS signaling instead of the parallel
 * interface signals.  When this bit is set '1b', serial interface engine will be
 * used instead of parallel interface signals.  This bit has no effect unless PTS bits is set to
 * select                                 UTMI+/ULPI interface.  The Serial/USB1.1 PHY/IC-USB will
 * use the serial interface                                 engine for FS/LS signaling regardless of
 * this bit value.  Serial Transceiver Select - Read-Only. Reset value is 0b.  1 Serial Interface
 * Engine is selected  0 Parallel Interface signals is selected  Serial Interface Engine can be used
 * in combination with UTMI+/ULPI                                 physical interface to provide
 * FS/LS signaling instead of the Parallel Interface                                 signals.  When
 * this bit is set '1b', serial interface engine will be used
 * instead of parallel interface signals.  This bit has no effect unless PTS bits is set to select
 * UTMI+/ULPI                                 interface.   The Serial/USB1.1 PHY/IC-USB will use the
 * serial interface                                     engine for FS/LS signaling regardless of
 * this bit value.
 */

#define BP_USBC__PORTSC1_STS      29
#define BM_USBC__PORTSC1_STS      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_STS(v)   ((((reg32_t) v) << 29) & BM_USBC__PORTSC1_STS)
#else
#define BF_USBC__PORTSC1_STS(v)   (((v) << 29) & BM_USBC__PORTSC1_STS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_STS(v)   BF_CS1(USBC__PORTSC1, STS, v)
#endif

/* --- Register HW_USBC__PORTSC1, field PTS
 *
 * Parallel Transceiver Select - Read/Write. This register bit pair is
 * used in conjunction with the configuration constant VUSB_HS_PHY_TYPE to control which
 * parallel transceiver interface is selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8
 * or 10 then this bit is read only. If VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit
 * is read/write.  Bit field {bit25, bit30, bit31} is reset to:  "000b" if VUSB_HS_PHY_TYPE = 0,4 -
 * UTMI/UTMI+  "001b" if VUSB_HS_PHY_TYPE = 1,5 - Reserved  "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI
 * "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 - Serial/1.1 PHY/IC USB(FS
 * Only)  "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY  This bit is not defined in the
 * EHCI specification.  VUSB_HS_PHY_TYPE parameter:  For Elvis, OTG/Host core: 7;  For Rita, OTG
 * core: 0, Host core: 7  For Arik, OTG core: 0, Host core: 4  Parallel Transceiver Select (bit31,
 * bi30). These register bits are                                 implementation dependent.  For
 * OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is
 * '11b'.  Bit field { bit31, bit30}:  "00b" UTMI/UTMI+  "01b" Reserved  "10b" ULPI  "11b"
 * Serial/USB 1.1 PHY/IC-USB (FS Only)  Parallel Transceiver Select (bit25, bit31, bi30). These
 * register bits                                 are implementation dependent.  For OTG core, it's
 * Read-Only. Reset value is 000b.  For Host1/Host2/Host3 core, it's Read/Write. Reset value is
 * 011b.  Bit field {bit25, bit31, bit30}:  "000b" UTMI/UTMI+  "001b" Reserved  "010b" ULPI  "011b"
 * Serial/USB 1.1 PHY/IC-USB (FS Only)  "100b" HSIC  Parallel Transceiver Select (bit25, bit31,
 * bi30). These register bits                                 are implementation dependent.  For OTG
 * core, it is Read-Only. Reset value is 000b.  For Host1/Host2/Host3 core, it is Read/Write. Reset
 * value is                                 000b.  Bit field {bit25, bit31, bit30}:  "000b"
 * UTMI/UTMI+  "001b" Reserved  "010b" ULPI  "011b" Serial/USB 1.1 PHY/IC-USB (FS Only)  "100b" HSIC
 * All USB port interface modes are listed in this field description, but not all are
 * supported. For detail feature of each controller core, please see . The behaviour is unknown when
 * unsupported                                 interface mode is selected.
 */

#define BP_USBC__PORTSC1_PTS      30
#define BM_USBC__PORTSC1_PTS      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1_PTS(v)   ((((reg32_t) v) << 30) & BM_USBC__PORTSC1_PTS)
#else
#define BF_USBC__PORTSC1_PTS(v)   (((v) << 30) & BM_USBC__PORTSC1_PTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__PORTSC1_PTS(v)   BF_CS1(USBC__PORTSC1, PTS, v)
#endif

/*!
 * @brief HW_USBC_UOG_OTGSC - On-The-Go Status & control
 *
 * This register is availabe only in OTG controller core. It has four sections:   OTG Interrupt
 * enables (Read/Write)  OTG Interrupt status (Read/Write to Clear)  OTG Status inputs (Read Only)
 * OTG Controls (Read/Write)   The status inputs are debounced using a 1 ms time constant. Values on
 * the status inputs that                             do not persist for more than 1 ms does not
 * cause an update of the status input register, or                             cause an OTG
 * interrupt.  See also register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned VD : 1; //!< VBUS_Discharge - Read/Write.  Setting this bit causes VBus to discharge through a resistor.
        unsigned VC : 1; //!< VBUS Charge - Read/Write.  Setting this bit causes the VBus line to be charged. This is used for VBus pulsing during SRP.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned OT : 1; //!< OTG Termination - Read/Write.  This bit must be set when the OTG device is in device mode, this controls the pulldown on DM.
        unsigned DP : 1; //!< Data Pulsing - Read/Write.  Setting this bit causes the pullup on DP to be asserted for data pulsing during SRP.
        unsigned IDPU : 1; //!< ID Pullup - Read/Write  This bit provide control over the ID pull-up resister; 0 = off, 1 = on [default]. When this bit is 0, the ID input will not be sampled.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned ID : 1; //!< USB ID - Read Only.  0 = A device, 1 = B device
        unsigned AVV : 1; //!< A VBus Valid - Read Only.  Indicates VBus is above the A VBus valid threshold.
        unsigned ASV : 1; //!< A Session Valid - Read Only.  Indicates VBus is above the A session valid threshold.
        unsigned BSV : 1; //!< B Session Valid - Read Only.  Indicates VBus is above the B session valid threshold.
        unsigned BSE : 1; //!< B Session End - Read Only.  Indicates VBus is below the B session end threshold.
        unsigned RESERVED2 : 1; //!< 1 millisecond timer toggle - Read Only.  This bit toggles once per millisecond.
        unsigned DPS : 1; //!< Data Bus Pulsing Status - Read Only.  A '1' indicates data bus pulsing is being detected on the port.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned IDIS : 1; //!< USB ID Interrupt Status - Read/Write.  This bit is set when a change on the ID input has been detected.  Software must write a one to clear this bit.
        unsigned AVVIS : 1; //!< A VBus Valid Interrupt Status - Read/Write to Clear.  This bit is set when VBus has either risen above or fallen below the VBus valid threshold (4.4 VDC) on an A device.  Software must write a one to clear this bit.
        unsigned ASVIS : 1; //!< A Session Valid Interrupt Status - Read/Write to Clear.  This bit is set when VBus has either risen above or fallen below the A session valid threshold (0.8 VDC).  Software must write a one to clear this bit.
        unsigned BSVIS : 1; //!< B Session Valid Interrupt Status - Read/Write to Clear.  This bit is set when VBus has either risen above or fallen below the B session valid threshold (0.8 VDC).  Software must write a one to clear this bit.
        unsigned BSEIS : 1; //!< B Session End Interrupt Status - Read/Write to Clear.  This bit is set when VBus has fallen below the B session end threshold. Software must write a one to clear this bit
        unsigned RESERVED4 : 1; //!< 1 millisecond timer Interrupt Status - Read/Write to Clear.  This bit is set once every millisecond.  Software must write a one to clear this bit.
        unsigned DPIS : 1; //!< Data Pulse Interrupt Status - Read/Write to Clear.  This bit is set when data bus pulsing occurs on DP or DM. Data bus pulsing is only detected when USBMODE.CM = Host (11) and PORTSC1(0)[PP] = 0.  Software must write a one to clear this bit.
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned IDIE : 1; //!< USB ID Interrupt Enable - Read/Write.  Setting this bit enables the USB ID interrupt.
        unsigned AVVIE : 1; //!< A VBus Valid Interrupt Enable - Read/Write.  Setting this bit enables the A VBus valid interrupt.
        unsigned ASVIE : 1; //!< A Session Valid Interrupt Enable - Read/Write.  Setting this bit enables the A session valid interrupt.
        unsigned BSVIE : 1; //!< B Session Valid Interrupt Enable - Read/Write.  Setting this bit enables the B session valid interrupt.
        unsigned BSEIE : 1; //!< B Session End Interrupt Enable - Read/Write.  Setting this bit enables the B session end interrupt.
        unsigned RESERVED6 : 1; //!< 1 millisecond timer Interrupt Enable - Read/Write
        unsigned DPIE : 1; //!< Data Pulse Interrupt Enable
        unsigned RESERVED7 : 1; //!< Reserved
    } B;
} hw_usbc_uog_otgsc_t;
#endif

/*
 * constants & macros for entire USBC_UOG_OTGSC register
 */
#define HW_USBC_UOG_OTGSC_ADDR      (REGS_USBC_BASE + 0x1a4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_OTGSC           (*(volatile hw_usbc_uog_otgsc_t *) HW_USBC_UOG_OTGSC_ADDR)
#define HW_USBC_UOG_OTGSC_RD()      (HW_USBC_UOG_OTGSC.U)
#define HW_USBC_UOG_OTGSC_WR(v)     (HW_USBC_UOG_OTGSC.U = (v))
#define HW_USBC_UOG_OTGSC_SET(v)    (HW_USBC_UOG_OTGSC_WR(HW_USBC_UOG_OTGSC_RD() |  (v)))
#define HW_USBC_UOG_OTGSC_CLR(v)    (HW_USBC_UOG_OTGSC_WR(HW_USBC_UOG_OTGSC_RD() & ~(v)))
#define HW_USBC_UOG_OTGSC_TOG(v)    (HW_USBC_UOG_OTGSC_WR(HW_USBC_UOG_OTGSC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_OTGSC bitfields
 */

/* --- Register HW_USBC_UOG_OTGSC, field VD
 *
 * VBUS_Discharge - Read/Write.  Setting this bit causes VBus to discharge through a resistor.
 */

#define BP_USBC_UOG_OTGSC_VD      0
#define BM_USBC_UOG_OTGSC_VD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_VD(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_OTGSC_VD)
#else
#define BF_USBC_UOG_OTGSC_VD(v)   (((v) << 0) & BM_USBC_UOG_OTGSC_VD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_VD(v)   BF_CS1(USBC_UOG_OTGSC, VD, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field VC
 *
 * VBUS Charge - Read/Write.  Setting this bit causes the VBus line to be charged. This is used for
 * VBus pulsing during                                 SRP.
 */

#define BP_USBC_UOG_OTGSC_VC      1
#define BM_USBC_UOG_OTGSC_VC      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_VC(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_OTGSC_VC)
#else
#define BF_USBC_UOG_OTGSC_VC(v)   (((v) << 1) & BM_USBC_UOG_OTGSC_VC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_VC(v)   BF_CS1(USBC_UOG_OTGSC, VC, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field OT
 *
 * OTG Termination - Read/Write.  This bit must be set when the OTG device is in device mode, this
 * controls the pulldown on DM.
 */

#define BP_USBC_UOG_OTGSC_OT      3
#define BM_USBC_UOG_OTGSC_OT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_OT(v)   ((((reg32_t) v) << 3) & BM_USBC_UOG_OTGSC_OT)
#else
#define BF_USBC_UOG_OTGSC_OT(v)   (((v) << 3) & BM_USBC_UOG_OTGSC_OT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_OT(v)   BF_CS1(USBC_UOG_OTGSC, OT, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DP
 *
 * Data Pulsing - Read/Write.  Setting this bit causes the pullup on DP to be asserted for data
 * pulsing during SRP.
 */

#define BP_USBC_UOG_OTGSC_DP      4
#define BM_USBC_UOG_OTGSC_DP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DP(v)   ((((reg32_t) v) << 4) & BM_USBC_UOG_OTGSC_DP)
#else
#define BF_USBC_UOG_OTGSC_DP(v)   (((v) << 4) & BM_USBC_UOG_OTGSC_DP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_DP(v)   BF_CS1(USBC_UOG_OTGSC, DP, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field IDPU
 *
 * ID Pullup - Read/Write  This bit provide control over the ID pull-up resister; 0 = off, 1 = on
 * [default]. When                                 this bit is 0, the ID input will not be sampled.
 */

#define BP_USBC_UOG_OTGSC_IDPU      5
#define BM_USBC_UOG_OTGSC_IDPU      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_IDPU(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_OTGSC_IDPU)
#else
#define BF_USBC_UOG_OTGSC_IDPU(v)   (((v) << 5) & BM_USBC_UOG_OTGSC_IDPU)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_IDPU(v)   BF_CS1(USBC_UOG_OTGSC, IDPU, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ID
 *
 * USB ID - Read Only.  0 = A device, 1 = B device
 */

#define BP_USBC_UOG_OTGSC_ID      8
#define BM_USBC_UOG_OTGSC_ID      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ID(v)   ((((reg32_t) v) << 8) & BM_USBC_UOG_OTGSC_ID)
#else
#define BF_USBC_UOG_OTGSC_ID(v)   (((v) << 8) & BM_USBC_UOG_OTGSC_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_ID(v)   BF_CS1(USBC_UOG_OTGSC, ID, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field AVV
 *
 * A VBus Valid - Read Only.  Indicates VBus is above the A VBus valid threshold.
 */

#define BP_USBC_UOG_OTGSC_AVV      9
#define BM_USBC_UOG_OTGSC_AVV      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_AVV(v)   ((((reg32_t) v) << 9) & BM_USBC_UOG_OTGSC_AVV)
#else
#define BF_USBC_UOG_OTGSC_AVV(v)   (((v) << 9) & BM_USBC_UOG_OTGSC_AVV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_AVV(v)   BF_CS1(USBC_UOG_OTGSC, AVV, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ASV
 *
 * A Session Valid - Read Only.  Indicates VBus is above the A session valid threshold.
 */

#define BP_USBC_UOG_OTGSC_ASV      10
#define BM_USBC_UOG_OTGSC_ASV      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ASV(v)   ((((reg32_t) v) << 10) & BM_USBC_UOG_OTGSC_ASV)
#else
#define BF_USBC_UOG_OTGSC_ASV(v)   (((v) << 10) & BM_USBC_UOG_OTGSC_ASV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_ASV(v)   BF_CS1(USBC_UOG_OTGSC, ASV, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSV
 *
 * B Session Valid - Read Only.  Indicates VBus is above the B session valid threshold.
 */

#define BP_USBC_UOG_OTGSC_BSV      11
#define BM_USBC_UOG_OTGSC_BSV      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSV(v)   ((((reg32_t) v) << 11) & BM_USBC_UOG_OTGSC_BSV)
#else
#define BF_USBC_UOG_OTGSC_BSV(v)   (((v) << 11) & BM_USBC_UOG_OTGSC_BSV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_BSV(v)   BF_CS1(USBC_UOG_OTGSC, BSV, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSE
 *
 * B Session End - Read Only.  Indicates VBus is below the B session end threshold.
 */

#define BP_USBC_UOG_OTGSC_BSE      12
#define BM_USBC_UOG_OTGSC_BSE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSE(v)   ((((reg32_t) v) << 12) & BM_USBC_UOG_OTGSC_BSE)
#else
#define BF_USBC_UOG_OTGSC_BSE(v)   (((v) << 12) & BM_USBC_UOG_OTGSC_BSE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_BSE(v)   BF_CS1(USBC_UOG_OTGSC, BSE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DPS
 *
 * Data Bus Pulsing Status - Read Only.  A '1' indicates data bus pulsing is being detected on the
 * port.
 */

#define BP_USBC_UOG_OTGSC_DPS      14
#define BM_USBC_UOG_OTGSC_DPS      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DPS(v)   ((((reg32_t) v) << 14) & BM_USBC_UOG_OTGSC_DPS)
#else
#define BF_USBC_UOG_OTGSC_DPS(v)   (((v) << 14) & BM_USBC_UOG_OTGSC_DPS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_DPS(v)   BF_CS1(USBC_UOG_OTGSC, DPS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field IDIS
 *
 * USB ID Interrupt Status - Read/Write.  This bit is set when a change on the ID input has been
 * detected.  Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_IDIS      16
#define BM_USBC_UOG_OTGSC_IDIS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_IDIS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_OTGSC_IDIS)
#else
#define BF_USBC_UOG_OTGSC_IDIS(v)   (((v) << 16) & BM_USBC_UOG_OTGSC_IDIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_IDIS(v)   BF_CS1(USBC_UOG_OTGSC, IDIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field AVVIS
 *
 * A VBus Valid Interrupt Status - Read/Write to Clear.  This bit is set when VBus has either risen
 * above or fallen below the VBus valid threshold                                 (4.4 VDC) on an A
 * device.  Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_AVVIS      17
#define BM_USBC_UOG_OTGSC_AVVIS      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_AVVIS(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_OTGSC_AVVIS)
#else
#define BF_USBC_UOG_OTGSC_AVVIS(v)   (((v) << 17) & BM_USBC_UOG_OTGSC_AVVIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_AVVIS(v)   BF_CS1(USBC_UOG_OTGSC, AVVIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ASVIS
 *
 * A Session Valid Interrupt Status - Read/Write to Clear.  This bit is set when VBus has either
 * risen above or fallen below the A session valid                                 threshold (0.8
 * VDC).  Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_ASVIS      18
#define BM_USBC_UOG_OTGSC_ASVIS      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ASVIS(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_OTGSC_ASVIS)
#else
#define BF_USBC_UOG_OTGSC_ASVIS(v)   (((v) << 18) & BM_USBC_UOG_OTGSC_ASVIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_ASVIS(v)   BF_CS1(USBC_UOG_OTGSC, ASVIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSVIS
 *
 * B Session Valid Interrupt Status - Read/Write to Clear.  This bit is set when VBus has either
 * risen above or fallen below the B session valid                                 threshold (0.8
 * VDC).  Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_BSVIS      19
#define BM_USBC_UOG_OTGSC_BSVIS      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSVIS(v)   ((((reg32_t) v) << 19) & BM_USBC_UOG_OTGSC_BSVIS)
#else
#define BF_USBC_UOG_OTGSC_BSVIS(v)   (((v) << 19) & BM_USBC_UOG_OTGSC_BSVIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_BSVIS(v)   BF_CS1(USBC_UOG_OTGSC, BSVIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSEIS
 *
 * B Session End Interrupt Status - Read/Write to Clear.  This bit is set when VBus has fallen below
 * the B session end threshold. Software must                                 write a one to clear
 * this bit
 */

#define BP_USBC_UOG_OTGSC_BSEIS      20
#define BM_USBC_UOG_OTGSC_BSEIS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSEIS(v)   ((((reg32_t) v) << 20) & BM_USBC_UOG_OTGSC_BSEIS)
#else
#define BF_USBC_UOG_OTGSC_BSEIS(v)   (((v) << 20) & BM_USBC_UOG_OTGSC_BSEIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_BSEIS(v)   BF_CS1(USBC_UOG_OTGSC, BSEIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DPIS
 *
 * Data Pulse Interrupt Status - Read/Write to Clear.  This bit is set when data bus pulsing occurs
 * on DP or DM. Data bus pulsing is only                                 detected when USBMODE.CM =
 * Host (11) and PORTSC1(0)[PP] = 0.  Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_DPIS      22
#define BM_USBC_UOG_OTGSC_DPIS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DPIS(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_OTGSC_DPIS)
#else
#define BF_USBC_UOG_OTGSC_DPIS(v)   (((v) << 22) & BM_USBC_UOG_OTGSC_DPIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_DPIS(v)   BF_CS1(USBC_UOG_OTGSC, DPIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field IDIE
 *
 * USB ID Interrupt Enable - Read/Write.  Setting this bit enables the USB ID interrupt.
 */

#define BP_USBC_UOG_OTGSC_IDIE      24
#define BM_USBC_UOG_OTGSC_IDIE      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_IDIE(v)   ((((reg32_t) v) << 24) & BM_USBC_UOG_OTGSC_IDIE)
#else
#define BF_USBC_UOG_OTGSC_IDIE(v)   (((v) << 24) & BM_USBC_UOG_OTGSC_IDIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_IDIE(v)   BF_CS1(USBC_UOG_OTGSC, IDIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field AVVIE
 *
 * A VBus Valid Interrupt Enable - Read/Write.  Setting this bit enables the A VBus valid interrupt.
 */

#define BP_USBC_UOG_OTGSC_AVVIE      25
#define BM_USBC_UOG_OTGSC_AVVIE      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_AVVIE(v)   ((((reg32_t) v) << 25) & BM_USBC_UOG_OTGSC_AVVIE)
#else
#define BF_USBC_UOG_OTGSC_AVVIE(v)   (((v) << 25) & BM_USBC_UOG_OTGSC_AVVIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_AVVIE(v)   BF_CS1(USBC_UOG_OTGSC, AVVIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ASVIE
 *
 * A Session Valid Interrupt Enable - Read/Write.  Setting this bit enables the A session valid
 * interrupt.
 */

#define BP_USBC_UOG_OTGSC_ASVIE      26
#define BM_USBC_UOG_OTGSC_ASVIE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ASVIE(v)   ((((reg32_t) v) << 26) & BM_USBC_UOG_OTGSC_ASVIE)
#else
#define BF_USBC_UOG_OTGSC_ASVIE(v)   (((v) << 26) & BM_USBC_UOG_OTGSC_ASVIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_ASVIE(v)   BF_CS1(USBC_UOG_OTGSC, ASVIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSVIE
 *
 * B Session Valid Interrupt Enable - Read/Write.  Setting this bit enables the B session valid
 * interrupt.
 */

#define BP_USBC_UOG_OTGSC_BSVIE      27
#define BM_USBC_UOG_OTGSC_BSVIE      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSVIE(v)   ((((reg32_t) v) << 27) & BM_USBC_UOG_OTGSC_BSVIE)
#else
#define BF_USBC_UOG_OTGSC_BSVIE(v)   (((v) << 27) & BM_USBC_UOG_OTGSC_BSVIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_BSVIE(v)   BF_CS1(USBC_UOG_OTGSC, BSVIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSEIE
 *
 * B Session End Interrupt Enable - Read/Write.  Setting this bit enables the B session end
 * interrupt.
 */

#define BP_USBC_UOG_OTGSC_BSEIE      28
#define BM_USBC_UOG_OTGSC_BSEIE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSEIE(v)   ((((reg32_t) v) << 28) & BM_USBC_UOG_OTGSC_BSEIE)
#else
#define BF_USBC_UOG_OTGSC_BSEIE(v)   (((v) << 28) & BM_USBC_UOG_OTGSC_BSEIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_BSEIE(v)   BF_CS1(USBC_UOG_OTGSC, BSEIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DPIE
 *
 * Data Pulse Interrupt Enable
 */

#define BP_USBC_UOG_OTGSC_DPIE      30
#define BM_USBC_UOG_OTGSC_DPIE      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DPIE(v)   ((((reg32_t) v) << 30) & BM_USBC_UOG_OTGSC_DPIE)
#else
#define BF_USBC_UOG_OTGSC_DPIE(v)   (((v) << 30) & BM_USBC_UOG_OTGSC_DPIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_OTGSC_DPIE(v)   BF_CS1(USBC_UOG_OTGSC, DPIE, v)
#endif

/*!
 * @brief HW_USBC__USBMODE - USB Device Mode
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CM : 2; //!< Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device only implementations. For those designs that contain both host & device capability, the controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. For combination host/device controllers, this register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register.  For OTG controller core, reset value is '00b'.  For Host1/Host2/Host3 controller core, reset value is '11b'.  Bit Meaning
        unsigned ES : 1; //!< Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to match the host microprocessor. The bit fields in the microprocessor interface and the data structures are unaffected by the value of this bit because they are based upon the 32-bit word.  Bit Meaning
        unsigned SLOM : 1; //!< Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
        unsigned SDIS : 1; //!< Stream Disable Mode. (0 - Inactive [default]; 1 - Active)  Device Mode: Setting to a '1' disables double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX and TX buffers are sufficient to contain an entire packet that the standard double buffering scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets received are responded to with a NYET handshake when stream disable is active.  Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled to capacity before the packet is launched onto the USB.  Time duration to pre-fill the FIFO becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to characterize the adjustments needed for the scheduler when using this feature.  The use of this feature substantially limits of the overall USB performance that can be achieved.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_usbc__usbmode_t;
#endif

/*
 * constants & macros for entire USBC__USBMODE register
 */
#define HW_USBC__USBMODE_ADDR      (REGS_USBC_BASE + 0x1a8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBMODE           (*(volatile hw_usbc__usbmode_t *) HW_USBC__USBMODE_ADDR)
#define HW_USBC__USBMODE_RD()      (HW_USBC__USBMODE.U)
#define HW_USBC__USBMODE_WR(v)     (HW_USBC__USBMODE.U = (v))
#define HW_USBC__USBMODE_SET(v)    (HW_USBC__USBMODE_WR(HW_USBC__USBMODE_RD() |  (v)))
#define HW_USBC__USBMODE_CLR(v)    (HW_USBC__USBMODE_WR(HW_USBC__USBMODE_RD() & ~(v)))
#define HW_USBC__USBMODE_TOG(v)    (HW_USBC__USBMODE_WR(HW_USBC__USBMODE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC__USBMODE bitfields
 */

/* --- Register HW_USBC__USBMODE, field CM
 *
 * Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and
 * device only implementations. For those designs that contain both host & device
 * capability, the controller defaults to an idle state and needs to be initialized to the
 * desired operating mode after reset. For combination host/device controllers, this
 * register can only be written once after reset. If it is necessary to switch modes,
 * software must reset the controller by writing to the RESET bit in the USBCMD
 * register before reprogramming this register.  For OTG controller core, reset value is '00b'.  For
 * Host1/Host2/Host3 controller core, reset value is '11b'.  Bit Meaning
 */

#define BP_USBC__USBMODE_CM      0
#define BM_USBC__USBMODE_CM      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODE_CM(v)   ((((reg32_t) v) << 0) & BM_USBC__USBMODE_CM)
#else
#define BF_USBC__USBMODE_CM(v)   (((v) << 0) & BM_USBC__USBMODE_CM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBMODE_CM(v)   BF_CS1(USBC__USBMODE, CM, v)
#endif

/* --- Register HW_USBC__USBMODE, field ES
 *
 * Endian Select - Read/Write. This bit can change the byte alignment of the transfer
 * buffers to match the host microprocessor. The bit fields in the microprocessor interface
 * and the data structures are unaffected by the value of this bit because they are based
 * upon the 32-bit word.  Bit Meaning
 */

#define BP_USBC__USBMODE_ES      2
#define BM_USBC__USBMODE_ES      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODE_ES(v)   ((((reg32_t) v) << 2) & BM_USBC__USBMODE_ES)
#else
#define BF_USBC__USBMODE_ES(v)   (((v) << 2) & BM_USBC__USBMODE_ES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBMODE_ES(v)   BF_CS1(USBC__USBMODE, ES, v)
#endif

/* --- Register HW_USBC__USBMODE, field SLOM
 *
 * Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock
 * mechanism. See .
 */

#define BP_USBC__USBMODE_SLOM      3
#define BM_USBC__USBMODE_SLOM      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODE_SLOM(v)   ((((reg32_t) v) << 3) & BM_USBC__USBMODE_SLOM)
#else
#define BF_USBC__USBMODE_SLOM(v)   (((v) << 3) & BM_USBC__USBMODE_SLOM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBMODE_SLOM(v)   BF_CS1(USBC__USBMODE, SLOM, v)
#endif

/* --- Register HW_USBC__USBMODE, field SDIS
 *
 * Stream Disable Mode. (0 - Inactive [default]; 1 - Active)  Device Mode: Setting to a '1' disables
 * double priming on both RX and TX for low bandwidth                                 systems. This
 * mode ensures that when the RX and TX buffers are sufficient to contain an
 * entire packet that the standard double buffering scheme is disabled to prevent
 * overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets
 * received are responded to with a NYET handshake when stream disable is active.  Host Mode:
 * Setting to a '1' ensures that overruns/underruns of the latency FIFO are
 * eliminated for low bandwidth systems where the RX and TX buffers are sufficient to
 * contain the entire packet. Enabling stream disable also has the effect of ensuring the
 * TX latency is filled to capacity before the packet is launched onto the USB.  Time duration to
 * pre-fill the FIFO becomes significant when stream disable is active.
 * See and TXTTFILLTUNING [MPH Only] to                                 characterize the adjustments
 * needed for the scheduler when using this feature.  The use of this feature substantially limits
 * of the overall USB performance that can                                 be achieved.
 */

#define BP_USBC__USBMODE_SDIS      4
#define BM_USBC__USBMODE_SDIS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODE_SDIS(v)   ((((reg32_t) v) << 4) & BM_USBC__USBMODE_SDIS)
#else
#define BF_USBC__USBMODE_SDIS(v)   (((v) << 4) & BM_USBC__USBMODE_SDIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC__USBMODE_SDIS(v)   BF_CS1(USBC__USBMODE, SDIS, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTSETUPSTAT - Endpoint Setup Status
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ENDPTSETUPSTAT : 16; //!< Setup Endpoint Status. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lock our mechanism is engaged. See in the Device Operational Model.  This register is only used in device mode.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usbc_uog_endptsetupstat_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTSETUPSTAT register
 */
#define HW_USBC_UOG_ENDPTSETUPSTAT_ADDR      (REGS_USBC_BASE + 0x1ac)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTSETUPSTAT           (*(volatile hw_usbc_uog_endptsetupstat_t *) HW_USBC_UOG_ENDPTSETUPSTAT_ADDR)
#define HW_USBC_UOG_ENDPTSETUPSTAT_RD()      (HW_USBC_UOG_ENDPTSETUPSTAT.U)
#define HW_USBC_UOG_ENDPTSETUPSTAT_WR(v)     (HW_USBC_UOG_ENDPTSETUPSTAT.U = (v))
#define HW_USBC_UOG_ENDPTSETUPSTAT_SET(v)    (HW_USBC_UOG_ENDPTSETUPSTAT_WR(HW_USBC_UOG_ENDPTSETUPSTAT_RD() |  (v)))
#define HW_USBC_UOG_ENDPTSETUPSTAT_CLR(v)    (HW_USBC_UOG_ENDPTSETUPSTAT_WR(HW_USBC_UOG_ENDPTSETUPSTAT_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTSETUPSTAT_TOG(v)    (HW_USBC_UOG_ENDPTSETUPSTAT_WR(HW_USBC_UOG_ENDPTSETUPSTAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTSETUPSTAT bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTSETUPSTAT, field ENDPTSETUPSTAT
 *
 * Setup Endpoint Status. For every setup transaction that is received, a corresponding bit
 * in this register is set to one. Software must clear or acknowledge the setup transfer by
 * writing a one to a respective bit after it has read the setup data from Queue head. The
 * response to a setup packet as in the order of operations and total response time is
 * crucial to limit bus time outs while the setup lock our mechanism is engaged. See in the Device
 * Operational Model.  This register is only used in device mode.
 */

#define BP_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT      0
#define BM_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT)
#else
#define BF_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT(v)   (((v) << 0) & BM_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT(v)   BF_CS1(USBC_UOG_ENDPTSETUPSTAT, ENDPTSETUPSTAT, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTPRIME - Endpoint Initialization
 *
 * This register is only used in device mode.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PERB : 8; //!< Prime Endpoint Receive Buffer - R/WS. For each endpoint, a corresponding bit is used to request a buffer prepare for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware automatically uses this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware clears this bit when the associated endpoint(s) is (are) successfully primed.  These bits are momentarily set by hardware during hardware re-priming operations when a dTD is retired, and the dQH is updated.  PERB[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned PETB : 8; //!< Prime Endpoint Transmit Buffer - R/WS. For each endpoint a corresponding bit is used to request that a buffer prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware automatically uses this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware clears this bit when the associated endpoint(s) is (are) successfully primed.  These bits are momentarily set by hardware during hardware re-priming operations when a dTD is retired, and the dQH is updated.  PETB[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptprime_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTPRIME register
 */
#define HW_USBC_UOG_ENDPTPRIME_ADDR      (REGS_USBC_BASE + 0x1b0)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTPRIME           (*(volatile hw_usbc_uog_endptprime_t *) HW_USBC_UOG_ENDPTPRIME_ADDR)
#define HW_USBC_UOG_ENDPTPRIME_RD()      (HW_USBC_UOG_ENDPTPRIME.U)
#define HW_USBC_UOG_ENDPTPRIME_WR(v)     (HW_USBC_UOG_ENDPTPRIME.U = (v))
#define HW_USBC_UOG_ENDPTPRIME_SET(v)    (HW_USBC_UOG_ENDPTPRIME_WR(HW_USBC_UOG_ENDPTPRIME_RD() |  (v)))
#define HW_USBC_UOG_ENDPTPRIME_CLR(v)    (HW_USBC_UOG_ENDPTPRIME_WR(HW_USBC_UOG_ENDPTPRIME_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTPRIME_TOG(v)    (HW_USBC_UOG_ENDPTPRIME_WR(HW_USBC_UOG_ENDPTPRIME_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTPRIME bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTPRIME, field PERB
 *
 * Prime Endpoint Receive Buffer - R/WS. For each endpoint, a corresponding bit is used to
 * request a buffer prepare for a receive operation for when a USB host initiates a USB OUT
 * transaction. Software should write a one to the corresponding bit whenever posting a new
 * transfer descriptor to an endpoint. Hardware automatically uses this bit to begin
 * parsing for a new transfer descriptor from the queue head and prepare a receive buffer.
 * Hardware clears this bit when the associated endpoint(s) is (are) successfully
 * primed.  These bits are momentarily set by hardware during hardware re-priming operations when
 * a dTD is retired, and the dQH is updated.  PERB[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTPRIME_PERB      0
#define BM_USBC_UOG_ENDPTPRIME_PERB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTPRIME_PERB(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTPRIME_PERB)
#else
#define BF_USBC_UOG_ENDPTPRIME_PERB(v)   (((v) << 0) & BM_USBC_UOG_ENDPTPRIME_PERB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTPRIME_PERB(v)   BF_CS1(USBC_UOG_ENDPTPRIME, PERB, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTPRIME, field PETB
 *
 * Prime Endpoint Transmit Buffer - R/WS. For each endpoint a corresponding bit is used to
 * request that a buffer prepared for a transmit operation in order to respond to a USB
 * IN/INTERRUPT transaction. Software should write a one to the corresponding bit when
 * posting a new transfer descriptor to an endpoint. Hardware automatically uses this bit
 * to begin parsing for a new transfer descriptor from the queue head and prepare a
 * transmit buffer. Hardware clears this bit when the associated endpoint(s) is (are)
 * successfully primed.  These bits are momentarily set by hardware during hardware re-priming
 * operations when                                 a dTD is retired, and the dQH is updated.
 * PETB[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTPRIME_PETB      16
#define BM_USBC_UOG_ENDPTPRIME_PETB      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTPRIME_PETB(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTPRIME_PETB)
#else
#define BF_USBC_UOG_ENDPTPRIME_PETB(v)   (((v) << 16) & BM_USBC_UOG_ENDPTPRIME_PETB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTPRIME_PETB(v)   BF_CS1(USBC_UOG_ENDPTPRIME, PETB, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTFLUSH - Endpoint De-Initialize
 *
 * This register is only used in device mode.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FERB : 8; //!< Flush Endpoint Receive Buffer - R/WS. Writing one to a bit(s) causes the assocUOGiated endpoint(s) to clear any primed buffers. If a packet is in progress for one of the associated endpoints, then that transfer continues until completion. Hardware clears this register after the endpoint flush operation is successful.  FERB[N] - Endpoint #N, N is in 0..7\
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned FETB : 8; //!< Flush Endpoint Transmit Buffer - R/WS. Writing one to a bit(s) in this register causes the associated endpoint(s) to clear any primed buffers. If a packet is in progress for one of the associated endpoints, then that transfer continues until completion. Hardware clears this register after the endpoint flush operation is successful.  FETB[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptflush_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTFLUSH register
 */
#define HW_USBC_UOG_ENDPTFLUSH_ADDR      (REGS_USBC_BASE + 0x1b4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTFLUSH           (*(volatile hw_usbc_uog_endptflush_t *) HW_USBC_UOG_ENDPTFLUSH_ADDR)
#define HW_USBC_UOG_ENDPTFLUSH_RD()      (HW_USBC_UOG_ENDPTFLUSH.U)
#define HW_USBC_UOG_ENDPTFLUSH_WR(v)     (HW_USBC_UOG_ENDPTFLUSH.U = (v))
#define HW_USBC_UOG_ENDPTFLUSH_SET(v)    (HW_USBC_UOG_ENDPTFLUSH_WR(HW_USBC_UOG_ENDPTFLUSH_RD() |  (v)))
#define HW_USBC_UOG_ENDPTFLUSH_CLR(v)    (HW_USBC_UOG_ENDPTFLUSH_WR(HW_USBC_UOG_ENDPTFLUSH_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTFLUSH_TOG(v)    (HW_USBC_UOG_ENDPTFLUSH_WR(HW_USBC_UOG_ENDPTFLUSH_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTFLUSH bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTFLUSH, field FERB
 *
 * Flush Endpoint Receive Buffer - R/WS. Writing one to a bit(s) causes the assocUOGiated
 * endpoint(s) to clear any primed buffers. If a packet is in progress for one of the
 * associated endpoints, then that transfer continues until completion. Hardware clears
 * this register after the endpoint flush operation is successful.  FERB[N] - Endpoint #N, N is in
 * 0..7\
 */

#define BP_USBC_UOG_ENDPTFLUSH_FERB      0
#define BM_USBC_UOG_ENDPTFLUSH_FERB      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTFLUSH_FERB(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTFLUSH_FERB)
#else
#define BF_USBC_UOG_ENDPTFLUSH_FERB(v)   (((v) << 0) & BM_USBC_UOG_ENDPTFLUSH_FERB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTFLUSH_FERB(v)   BF_CS1(USBC_UOG_ENDPTFLUSH, FERB, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTFLUSH, field FETB
 *
 * Flush Endpoint Transmit Buffer - R/WS. Writing one to a bit(s) in this register causes
 * the associated endpoint(s) to clear any primed buffers. If a packet is in progress for
 * one of the associated endpoints, then that transfer continues until completion. Hardware
 * clears this register after the endpoint flush operation is successful.  FETB[N] - Endpoint #N, N
 * is in 0..7
 */

#define BP_USBC_UOG_ENDPTFLUSH_FETB      16
#define BM_USBC_UOG_ENDPTFLUSH_FETB      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTFLUSH_FETB(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTFLUSH_FETB)
#else
#define BF_USBC_UOG_ENDPTFLUSH_FETB(v)   (((v) << 16) & BM_USBC_UOG_ENDPTFLUSH_FETB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTFLUSH_FETB(v)   BF_CS1(USBC_UOG_ENDPTFLUSH, FETB, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTSTAT - Endpoint Status
 *
 * This register is only used in device mode.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ERBR : 8; //!< Endpoint Receive Buffer Ready -- Read Only. One bit for each endpoint indicates status of the respective endpoint buffer. This bit is set to a one by the hardware as a response to receiving a command from a corresponding bit in the ENDPRIME register. There is always a delay between setting a bit in the ENDPRIME register and endpoint indicating ready. This delay time varies based upon the current USB traffic and the number of bits set in the ENDPRIME register. Buffer ready is cleared by USB reset, by the USB DMA system, or through the ENDPTFLUSH register.  These bits are momentarily cleared by hardware during hardware endpoint re-priming operations when a dTD is retired, and the dQH is updated.  ERBR[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned ETBR : 8; //!< Endpoint Transmit Buffer Ready -- Read Only. One bit for each endpoint indicates status of the respective endpoint buffer. This bit is set to one by the hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. There is always a delay between setting a bit in the ENDPTPRIME register and endpoint indicating ready. This delay time varies based upon the current USB traffic and the number of bits set in the ENDPRIME register. Buffer ready is cleared by USB reset, by the USB DMA system, or through the ENDPTFLUSH register.  These bits are momentarily cleared by hardware during hardware endpoint re-priming operations when a dTD is retired, and the dQH is updated.  ETBR[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptstat_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTSTAT register
 */
#define HW_USBC_UOG_ENDPTSTAT_ADDR      (REGS_USBC_BASE + 0x1b8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTSTAT           (*(volatile hw_usbc_uog_endptstat_t *) HW_USBC_UOG_ENDPTSTAT_ADDR)
#define HW_USBC_UOG_ENDPTSTAT_RD()      (HW_USBC_UOG_ENDPTSTAT.U)
#define HW_USBC_UOG_ENDPTSTAT_WR(v)     (HW_USBC_UOG_ENDPTSTAT.U = (v))
#define HW_USBC_UOG_ENDPTSTAT_SET(v)    (HW_USBC_UOG_ENDPTSTAT_WR(HW_USBC_UOG_ENDPTSTAT_RD() |  (v)))
#define HW_USBC_UOG_ENDPTSTAT_CLR(v)    (HW_USBC_UOG_ENDPTSTAT_WR(HW_USBC_UOG_ENDPTSTAT_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTSTAT_TOG(v)    (HW_USBC_UOG_ENDPTSTAT_WR(HW_USBC_UOG_ENDPTSTAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTSTAT bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTSTAT, field ERBR
 *
 * Endpoint Receive Buffer Ready -- Read Only. One bit for each endpoint indicates status of
 * the respective endpoint buffer. This bit is set to a one by the hardware as a response
 * to receiving a command from a corresponding bit in the ENDPRIME register. There is
 * always a delay between setting a bit in the ENDPRIME register and endpoint indicating
 * ready. This delay time varies based upon the current USB traffic and the number of bits
 * set in the ENDPRIME register. Buffer ready is cleared by USB reset, by the USB DMA
 * system, or through the ENDPTFLUSH register.  These bits are momentarily cleared by hardware
 * during hardware endpoint re-priming                                 operations when a dTD is
 * retired, and the dQH is updated.  ERBR[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTSTAT_ERBR      0
#define BM_USBC_UOG_ENDPTSTAT_ERBR      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTSTAT_ERBR(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTSTAT_ERBR)
#else
#define BF_USBC_UOG_ENDPTSTAT_ERBR(v)   (((v) << 0) & BM_USBC_UOG_ENDPTSTAT_ERBR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTSTAT_ERBR(v)   BF_CS1(USBC_UOG_ENDPTSTAT, ERBR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTSTAT, field ETBR
 *
 * Endpoint Transmit Buffer Ready -- Read Only. One bit for each endpoint indicates status
 * of the respective endpoint buffer. This bit is set to one by the hardware as a response
 * to receiving a command from a corresponding bit in the ENDPTPRIME register. There is
 * always a delay between setting a bit in the ENDPTPRIME register and endpoint indicating
 * ready. This delay time varies based upon the current USB traffic and the number of bits
 * set in the ENDPRIME register. Buffer ready is cleared by USB reset, by the USB DMA
 * system, or through the ENDPTFLUSH register.  These bits are momentarily cleared by hardware
 * during hardware endpoint re-priming                                 operations when a dTD is
 * retired, and the dQH is updated.  ETBR[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTSTAT_ETBR      16
#define BM_USBC_UOG_ENDPTSTAT_ETBR      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTSTAT_ETBR(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTSTAT_ETBR)
#else
#define BF_USBC_UOG_ENDPTSTAT_ETBR(v)   (((v) << 16) & BM_USBC_UOG_ENDPTSTAT_ETBR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTSTAT_ETBR(v)   BF_CS1(USBC_UOG_ENDPTSTAT, ETBR, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTCOMPLETE - Endpoint Complete
 *
 * This register is only used in device mode.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ERCE : 8; //!< Endpoint Receive Complete Event - RW/C. Each bit indicates a received event (OUT/SETUP) occurred and software should read the corresponding endpoint queue to determine the transfer status. If the corresponding IOC bit is set in the Transfer Descriptor, then this bit is set simultaneously with the USBINT . Writing one clears the corresponding bit in this register.  ERCE[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned ETCE : 8; //!< Endpoint Transmit Complete Event - R/WC. Each bit indicates a transmit event (IN/INTERRUPT) occurred and software should read the corresponding endpoint queue to determine the endpoint status. If the corresponding IOC bit is set in the Transfer Descriptor, then this bit is set simultaneously with the USBINT . Writing one clears the corresponding bit in this register.  ETCE[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptcomplete_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCOMPLETE register
 */
#define HW_USBC_UOG_ENDPTCOMPLETE_ADDR      (REGS_USBC_BASE + 0x1bc)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCOMPLETE           (*(volatile hw_usbc_uog_endptcomplete_t *) HW_USBC_UOG_ENDPTCOMPLETE_ADDR)
#define HW_USBC_UOG_ENDPTCOMPLETE_RD()      (HW_USBC_UOG_ENDPTCOMPLETE.U)
#define HW_USBC_UOG_ENDPTCOMPLETE_WR(v)     (HW_USBC_UOG_ENDPTCOMPLETE.U = (v))
#define HW_USBC_UOG_ENDPTCOMPLETE_SET(v)    (HW_USBC_UOG_ENDPTCOMPLETE_WR(HW_USBC_UOG_ENDPTCOMPLETE_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCOMPLETE_CLR(v)    (HW_USBC_UOG_ENDPTCOMPLETE_WR(HW_USBC_UOG_ENDPTCOMPLETE_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCOMPLETE_TOG(v)    (HW_USBC_UOG_ENDPTCOMPLETE_WR(HW_USBC_UOG_ENDPTCOMPLETE_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTCOMPLETE bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCOMPLETE, field ERCE
 *
 * Endpoint Receive Complete Event - RW/C. Each bit indicates a received event (OUT/SETUP)
 * occurred and software should read the corresponding endpoint queue to determine the
 * transfer status. If the corresponding IOC bit is set in the Transfer Descriptor, then
 * this bit is set simultaneously with the USBINT . Writing one clears the
 * corresponding bit in this register.  ERCE[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTCOMPLETE_ERCE      0
#define BM_USBC_UOG_ENDPTCOMPLETE_ERCE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCOMPLETE_ERCE(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCOMPLETE_ERCE)
#else
#define BF_USBC_UOG_ENDPTCOMPLETE_ERCE(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCOMPLETE_ERCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCOMPLETE_ERCE(v)   BF_CS1(USBC_UOG_ENDPTCOMPLETE, ERCE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCOMPLETE, field ETCE
 *
 * Endpoint Transmit Complete Event - R/WC. Each bit indicates a transmit event
 * (IN/INTERRUPT) occurred and software should read the corresponding endpoint queue to
 * determine the endpoint status. If the corresponding IOC bit is set in the Transfer
 * Descriptor, then this bit is set simultaneously with the USBINT . Writing one
 * clears the corresponding bit in this register.  ETCE[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTCOMPLETE_ETCE      16
#define BM_USBC_UOG_ENDPTCOMPLETE_ETCE      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCOMPLETE_ETCE(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCOMPLETE_ETCE)
#else
#define BF_USBC_UOG_ENDPTCOMPLETE_ETCE(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCOMPLETE_ETCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCOMPLETE_ETCE(v)   BF_CS1(USBC_UOG_ENDPTCOMPLETE, ETCE, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTCTRL0 - Endpoint Control0
 *
 * Every Device implements Endpoint 0 as a control endpoint.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write  0 End Point OK. [Default]  1 End Point Stalled  Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues returning STALL until the bit is cleared by software or it is automatically cleared upon receipt of a new SETUP request.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write  00 Control  Endpoint0 is fixed as a Control End Point.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned RXE : 1; //!< RX Endpoint Enable  1 Enabled  Endpoint0 is always enabled.
        unsigned RESERVED2 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write  0 End Point OK [Default]  1 End Point Stalled  Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues returning STALL until the bit is cleared by software or it is automatically cleared upon receipt of a new SETUP request.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write  00 - Control  Endpoint0 is fixed as a Control End Point.
        unsigned RESERVED4 : 3; //!< Reserved
        unsigned TXE : 1; //!< TX Endpoint Enable  1 Enabled  Endpoint0 is always enabled.
        unsigned RESERVED5 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl0_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL0 register
 */
#define HW_USBC_UOG_ENDPTCTRL0_ADDR      (REGS_USBC_BASE + 0x1c0)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL0           (*(volatile hw_usbc_uog_endptctrl0_t *) HW_USBC_UOG_ENDPTCTRL0_ADDR)
#define HW_USBC_UOG_ENDPTCTRL0_RD()      (HW_USBC_UOG_ENDPTCTRL0.U)
#define HW_USBC_UOG_ENDPTCTRL0_WR(v)     (HW_USBC_UOG_ENDPTCTRL0.U = (v))
#define HW_USBC_UOG_ENDPTCTRL0_SET(v)    (HW_USBC_UOG_ENDPTCTRL0_WR(HW_USBC_UOG_ENDPTCTRL0_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL0_CLR(v)    (HW_USBC_UOG_ENDPTCTRL0_WR(HW_USBC_UOG_ENDPTCTRL0_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL0_TOG(v)    (HW_USBC_UOG_ENDPTCTRL0_WR(HW_USBC_UOG_ENDPTCTRL0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL0 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field RXS
 *
 * RX Endpoint Stall - Read/Write  0 End Point OK. [Default]  1 End Point Stalled  Software can
 * write a one to this bit to force the endpoint to return a STALL handshake to
 * the Host. It continues returning STALL until the bit is cleared by software or it is
 * automatically cleared upon receipt of a new SETUP request.
 */

#define BP_USBC_UOG_ENDPTCTRL0_RXS      0
#define BM_USBC_UOG_ENDPTCTRL0_RXS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL0_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL0_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL0_RXS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL0_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field RXT
 *
 * RX Endpoint Type - Read/Write  00 Control  Endpoint0 is fixed as a Control End Point.
 */

#define BP_USBC_UOG_ENDPTCTRL0_RXT      2
#define BM_USBC_UOG_ENDPTCTRL0_RXT      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL0_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL0_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL0_RXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL0_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field RXE
 *
 * RX Endpoint Enable  1 Enabled  Endpoint0 is always enabled.
 */

#define BP_USBC_UOG_ENDPTCTRL0_RXE      7
#define BM_USBC_UOG_ENDPTCTRL0_RXE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL0_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL0_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL0_RXE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL0_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field TXS
 *
 * TX Endpoint Stall - Read/Write  0 End Point OK [Default]  1 End Point Stalled  Software can write
 * a one to this bit to force the endpoint to return a STALL handshake to
 * the Host. It continues returning STALL until the bit is cleared by software or it is
 * automatically cleared upon receipt of a new SETUP request.
 */

#define BP_USBC_UOG_ENDPTCTRL0_TXS      16
#define BM_USBC_UOG_ENDPTCTRL0_TXS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL0_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL0_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL0_TXS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL0_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field TXT
 *
 * TX Endpoint Type - Read/Write  00 - Control  Endpoint0 is fixed as a Control End Point.
 */

#define BP_USBC_UOG_ENDPTCTRL0_TXT      18
#define BM_USBC_UOG_ENDPTCTRL0_TXT      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL0_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL0_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL0_TXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL0_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field TXE
 *
 * TX Endpoint Enable  1 Enabled  Endpoint0 is always enabled.
 */

#define BP_USBC_UOG_ENDPTCTRL0_TXE      23
#define BM_USBC_UOG_ENDPTCTRL0_TXE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL0_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL0_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL0_TXE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL0_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, TXE, v)
#endif

/*!
 * @brief HW_USBC_UOG_ENDPTCTRL - Endpoint Controln
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is                             disabled
 * then the unused direction type must be changed from the default control-type to any
 * other type (that is Bulk-type). leaving an unconfigured endpoint control causes undefined
 * behavior for the data pid tracking on the active endpoint/direction.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write  0 End Point OK. [Default]  1 End Point Stalled  This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint,  Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD  0 Dual Port Memory Buffer/DMA Engine [Default]  Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write  00 Control  01 Isochronous  10 Bulk  11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit  0 Disabled [Default]  1 Enabled  This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS)  Write 1 - Reset PID Sequence  Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable  0 Disabled [Default]  1 Enabled  An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write  0 End Point OK  1 End Point Stalled  This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint.  Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.  For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write  0 Dual Port Memory Buffer/DMA Engine [DEFAULT]  Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write  00 Control  01 Isochronous  10 Bulk  11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit  0 PID Sequencing Enabled. [Default]  1 PID Sequencing Disabled.  This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS)  Write 1 - Reset PID Sequence  Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable  0 Disabled [Default]  1 Enabled  An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL register
 */
#define HW_USBC_UOG_ENDPTCTRL_ADDR      (REGS_USBC_BASE + 0x1c4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL           (*(volatile hw_usbc_uog_endptctrl_t *) HW_USBC_UOG_ENDPTCTRL_ADDR)
#define HW_USBC_UOG_ENDPTCTRL_RD()      (HW_USBC_UOG_ENDPTCTRL.U)
#define HW_USBC_UOG_ENDPTCTRL_WR(v)     (HW_USBC_UOG_ENDPTCTRL.U = (v))
#define HW_USBC_UOG_ENDPTCTRL_SET(v)    (HW_USBC_UOG_ENDPTCTRL_WR(HW_USBC_UOG_ENDPTCTRL_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL_CLR(v)    (HW_USBC_UOG_ENDPTCTRL_WR(HW_USBC_UOG_ENDPTCTRL_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL_TOG(v)    (HW_USBC_UOG_ENDPTCTRL_WR(HW_USBC_UOG_ENDPTCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL, field RXS
 *
 * RX Endpoint Stall - Read/Write  0 End Point OK. [Default]  1 End Point Stalled  This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not
 * configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP
 * request if this Endpoint is configured as a Control Endpoint,  Software can write a one to this
 * bit to force the endpoint to return a STALL handshake to                                 the
 * Host. It continues to returning STALL until this bit is either cleared by software
 * or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL_RXS      0
#define BM_USBC_UOG_ENDPTCTRL_RXS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL_RXS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field RXD
 *
 * RX Endpoint Data Sink - Read/Write - TBD  0 Dual Port Memory Buffer/DMA Engine [Default]  Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL_RXD      1
#define BM_USBC_UOG_ENDPTCTRL_RXD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL_RXD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field RXT
 *
 * RX Endpoint Type - Read/Write  00 Control  01 Isochronous  10 Bulk  11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL_RXT      2
#define BM_USBC_UOG_ENDPTCTRL_RXT      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL_RXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field RXI
 *
 * RX Data Toggle Inhibit  0 Disabled [Default]  1 Enabled  This bit is only used for test and
 * should always be written as zero. Writing a one to                                 this bit
 * causes this endpoint to ignore the data toggle sequence and always accept data
 * packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL_RXI      5
#define BM_USBC_UOG_ENDPTCTRL_RXI      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL_RXI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field RXR
 *
 * RX Data Toggle Reset (WS)  Write 1 - Reset PID Sequence  Whenever a configuration event is
 * received for this Endpoint, software must write a one                                 to this bit
 * in order to synchronize the data PID's between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL_RXR      6
#define BM_USBC_UOG_ENDPTCTRL_RXR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL_RXR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field RXE
 *
 * RX Endpoint Enable  0 Disabled [Default]  1 Enabled  An Endpoint should be enabled only after it
 * has been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL_RXE      7
#define BM_USBC_UOG_ENDPTCTRL_RXE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL_RXE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field TXS
 *
 * TX Endpoint Stall - Read/Write  0 End Point OK  1 End Point Stalled  This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not
 * configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP
 * request if this Endpoint is configured as a Control Endpoint.  Software can write a one to this
 * bit to force the endpoint to return a STALL handshake to                                 the
 * Host. It continues to returning STALL until this bit is either cleared by software
 * or automatically cleared as above.  For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the                                 ENDPTSETUPSTAT begin cleared and hardware
 * continuing to clear this bit. In most systems,                                 it is unlikely the
 * DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually
 * write this STALL bit until it is set or until a new setup has ben received by checking
 * the associated ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL_TXS      16
#define BM_USBC_UOG_ENDPTCTRL_TXS      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL_TXS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field TXD
 *
 * TX Endpoint Data Source - Read/Write  0 Dual Port Memory Buffer/DMA Engine [DEFAULT]  Should
 * always be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL_TXD      17
#define BM_USBC_UOG_ENDPTCTRL_TXD      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL_TXD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field TXT
 *
 * TX Endpoint Type - Read/Write  00 Control  01 Isochronous  10 Bulk  11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL_TXT      18
#define BM_USBC_UOG_ENDPTCTRL_TXT      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL_TXT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field TXI
 *
 * TX Data Toggle Inhibit  0 PID Sequencing Enabled. [Default]  1 PID Sequencing Disabled.  This bit
 * is only used for test and should always be written as zero. Writing a one to
 * this bit causes this endpoint to ignore the data toggle sequence and always transmit
 * DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL_TXI      21
#define BM_USBC_UOG_ENDPTCTRL_TXI      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL_TXI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field TXR
 *
 * TX Data Toggle Reset (WS)  Write 1 - Reset PID Sequence  Whenever a configuration event is
 * received for this Endpoint, software must write a one                                 to this bit
 * in order to synchronize the data PID's between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL_TXR      22
#define BM_USBC_UOG_ENDPTCTRL_TXR      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL_TXR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL, field TXE
 *
 * TX Endpoint Enable  0 Disabled [Default]  1 Enabled  An Endpoint should be enabled only after it
 * has been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL_TXE      23
#define BM_USBC_UOG_ENDPTCTRL_TXE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL_TXE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USBC_UOG_ENDPTCTRL_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL, TXE, v)
#endif



/*!
 * @brief All USBC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_usbc__id_t _ID; //!< Identification register
    volatile hw_usbc__hwgeneral_t _HWGENERAL; //!< Hardware General
    volatile hw_usbc__hwhost_t _HWHOST; //!< Host Hardware Parameters
    volatile hw_usbc_uog_hwdevice_t UOG_HWDEVICE; //!< Device Hardware Parameters
    volatile hw_usbc__hwtxbuf_t _HWTXBUF; //!< TX Buffer Hardware Parameters
    volatile hw_usbc__hwrxbuf_t _HWRXBUF; //!< RX Buffer Hardware Parameters
    reg32_t _reserved0[26];
    volatile hw_usbc__gptimer0ld_t _GPTIMER0LD; //!< General Purpose Timer #0 Load
    volatile hw_usbc__gptimer0ctrl_t _GPTIMER0CTRL; //!< General Purpose Timer #0 Controller
    volatile hw_usbc__gptimer1ld_t _GPTIMER1LD; //!< General Purpose Timer #1 Load
    volatile hw_usbc__gptimer1ctrl_t _GPTIMER1CTRL; //!< General Purpose Timer #1 Controller
    volatile hw_usbc__sbuscfg_t _SBUSCFG; //!< System Bus Config
    reg32_t _reserved1[27];
    volatile hw_usbc__caplength_t _CAPLENGTH; //!< Capability Register Length
    reg8_t _reserved2;
    volatile hw_usbc__hciversion_t _HCIVERSION; //!< Host Controller Interface Version
    volatile hw_usbc__hcsparams_t _HCSPARAMS; //!< Host Controller Structural Parameters
    volatile hw_usbc__hccparams_t _HCCPARAMS; //!< Host Controller Capability Parameters
    reg32_t _reserved3[5];
    volatile hw_usbc_uog_dciversion_t UOG_DCIVERSION; //!< Device Controller Interface Version
    reg16_t _reserved4;
    volatile hw_usbc_uog_dccparams_t UOG_DCCPARAMS; //!< Device Controller Capability Parameters
    reg32_t _reserved5[6];
    volatile hw_usbc__usbcmd_t _USBCMD; //!< USB Command Register
    volatile hw_usbc__usbsts_t _USBSTS; //!< USB Status Register
    volatile hw_usbc__usbintr_t _USBINTR; //!< Interrupt Enable Register
    volatile hw_usbc__frindex_t _FRINDEX; //!< USB Frame Index
    reg32_t _reserved6;
    volatile hw_usbc__periodiclistbase_t _PERIODICLISTBASE; //!< Frame List Base Address
    volatile hw_usbc_uog_deviceaddr_t UOG_DEVICEADDR; //!< Device Address
    volatile hw_usbc__asynclistaddr_t _ASYNCLISTADDR; //!< Next Asynch. Address
    volatile hw_usbc_uog_endptlistaddr_t UOG_ENDPTLISTADDR; //!< Endpoint List Address
    volatile hw_usbc__burstsize_t _BURSTSIZE; //!< Programmable Burst Size
    volatile hw_usbc__txfilltuning_t _TXFILLTUNING; //!< TX FIFO Fill Tuning
    volatile hw_usbc__ic_usb_t _IC_USB; //!< IC_USB enable and voltage negotiation
    reg32_t _reserved7[2];
    volatile hw_usbc_uog_endptnak_t UOG_ENDPTNAK; //!< Endpoint NAK
    volatile hw_usbc_uog_endptnaken_t UOG_ENDPTNAKEN; //!< Endpoint Nake Enable
    reg32_t _reserved8;
    volatile hw_usbc__portsc1_t _PORTSC1; //!< Port Status & Control
    reg32_t _reserved9[7];
    volatile hw_usbc_uog_otgsc_t UOG_OTGSC; //!< On-The-Go Status & control
    volatile hw_usbc__usbmode_t _USBMODE; //!< USB Device Mode
    volatile hw_usbc_uog_endptsetupstat_t UOG_ENDPTSETUPSTAT; //!< Endpoint Setup Status
    volatile hw_usbc_uog_endptprime_t UOG_ENDPTPRIME; //!< Endpoint Initialization
    volatile hw_usbc_uog_endptflush_t UOG_ENDPTFLUSH; //!< Endpoint De-Initialize
    volatile hw_usbc_uog_endptstat_t UOG_ENDPTSTAT; //!< Endpoint Status
    volatile hw_usbc_uog_endptcomplete_t UOG_ENDPTCOMPLETE; //!< Endpoint Complete
    volatile hw_usbc_uog_endptctrl0_t UOG_ENDPTCTRL0; //!< Endpoint Control0
    volatile hw_usbc_uog_endptctrl_t UOG_ENDPTCTRL; //!< Endpoint Controln
} hw_usbc_t
#endif

//! @brief Macro to access all USBC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USBC(0)</code>.
#define HW_USBC     (*(volatile hw_usbc_t *) REGS_USBC_BASE)


#endif // _USBC_H
