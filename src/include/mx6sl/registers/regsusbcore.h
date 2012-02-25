/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USBC_H
#define _USBC_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_USBC__IDUOG - Identification register UOG
 * - HW_USBC__HWGENERALUOG - Hardware General UOG
 * - HW_USBC__HWHOSTUOG - Host Hardware Parameters UOG
 * - HW_USBC_UOG_HWDEVICE - Device Hardware Parameters
 * - HW_USBC__HWTXBUFUOG - TX Buffer Hardware Parameters UOG
 * - HW_USBC__HWRXBUFUOG - RX Buffer Hardware Parameters UOG
 * - HW_USBC__GPTIMER0LDUOG - General Purpose Timer #0 Load UOG
 * - HW_USBC__GPTIMER0CTRLUOG - General Purpose Timer #0 Controller UOG
 * - HW_USBC__GPTIMER1LDUOG - General Purpose Timer #1 Load UOG
 * - HW_USBC__GPTIMER1CTRLUOG - General Purpose Timer #1 Controller UOG
 * - HW_USBC__SBUSCFGUOG - System Bus Config UOG
 * - HW_USBC__CAPLENGTHUOG - Capability Register Length UOG
 * - HW_USBC__HCIVERSIONUOG - Host Controller Interface Version UOG
 * - HW_USBC__HCSPARAMSUOG - Host Controller Structural Parameters UOG
 * - HW_USBC__HCCPARAMSUOG - Host Controller Capability Parameters UOG
 * - HW_USBC_UOG_DCIVERSION - Device Controller Interface Version
 * - HW_USBC_UOG_DCCPARAMS - Device Controller Capability Parameters
 * - HW_USBC__USBCMDUOG - USB Command Register UOG
 * - HW_USBC__USBSTSUOG - USB Status Register UOG
 * - HW_USBC__USBINTRUOG - Interrupt Enable Register UOG
 * - HW_USBC__FRINDEXUOG - USB Frame Index UOG
 * - HW_USBC__PERIODICLISTBASEUOG - Frame List Base Address UOG
 * - HW_USBC__ASYNCLISTADDRUOG - Next Asynch. Address UOG
 * - HW_USBC__BURSTSIZEUOG - Programmable Burst Size UOG
 * - HW_USBC__TXFILLTUNINGUOG - TX FIFO Fill Tuning UOG
 * - HW_USBC__IC_USBUOG - IC_USB enable and voltage negotiation UOG
 * - HW_USBC_UOG_ENDPTNAK - Endpoint NAK
 * - HW_USBC_UOG_ENDPTNAKEN - Endpoint Nake Enable
 * - HW_USBC__PORTSC1UOG - Port Status & Control UOG
 * - HW_USBC_UOG_OTGSC - On-The-Go Status & control
 * - HW_USBC__USBMODEUOG - USB Device Mode UOG
 * - HW_USBC_UOG_ENDPTSETUPSTAT - Endpoint Setup Status
 * - HW_USBC_UOG_ENDPTPRIME - Endpoint Initialization
 * - HW_USBC_UOG_ENDPTFLUSH - Endpoint De-Initialize
 * - HW_USBC_UOG_ENDPTSTAT - Endpoint Status
 * - HW_USBC_UOG_ENDPTCOMPLETE - Endpoint Complete
 * - HW_USBC_UOG_ENDPTCTRL0 - Endpoint Control0
 * - HW_USBC_UOG_ENDPTCTRL1 - Endpoint Controln 1
 * - HW_USBC_UOG_ENDPTCTRL2 - Endpoint Controln 2
 * - HW_USBC_UOG_ENDPTCTRL3 - Endpoint Controln 3
 * - HW_USBC_UOG_ENDPTCTRL4 - Endpoint Controln 4
 * - HW_USBC_UOG_ENDPTCTRL5 - Endpoint Controln 5
 * - HW_USBC_UOG_ENDPTCTRL6 - Endpoint Controln 6
 * - HW_USBC_UOG_ENDPTCTRL7 - Endpoint Controln 7
 * - HW_USBC__IDUH1 - Identification register UH1
 * - HW_USBC__HWGENERALUH1 - Hardware General UH1
 * - HW_USBC__HWHOSTUH1 - Host Hardware Parameters UH1
 * - HW_USBC__HWTXBUFUH1 - TX Buffer Hardware Parameters UH1
 * - HW_USBC__HWRXBUFUH1 - RX Buffer Hardware Parameters UH1
 * - HW_USBC__GPTIMER0LDUH1 - General Purpose Timer #0 Load UH1
 * - HW_USBC__GPTIMER0CTRLUH1 - General Purpose Timer #0 Controller UH1
 * - HW_USBC__GPTIMER1LDUH1 - General Purpose Timer #1 Load UH1
 * - HW_USBC__GPTIMER1CTRLUH1 - General Purpose Timer #1 Controller UH1
 * - HW_USBC__SBUSCFGUH1 - System Bus Config UH1
 * - HW_USBC__CAPLENGTHUH1 - Capability Register Length UH1
 * - HW_USBC__HCIVERSIONUH1 - Host Controller Interface Version UH1
 * - HW_USBC__HCSPARAMSUH1 - Host Controller Structural Parameters UH1
 * - HW_USBC__HCCPARAMSUH1 - Host Controller Capability Parameters UH1
 * - HW_USBC__USBCMDUH1 - USB Command Register UH1
 * - HW_USBC__USBSTSUH1 - USB Status Register UH1
 * - HW_USBC__USBINTRUH1 - Interrupt Enable Register UH1
 * - HW_USBC__FRINDEXUH1 - USB Frame Index UH1
 * - HW_USBC__PERIODICLISTBASEUH1 - Frame List Base Address UH1
 * - HW_USBC__ASYNCLISTADDRUH1 - Next Asynch. Address UH1
 * - HW_USBC__BURSTSIZEUH1 - Programmable Burst Size UH1
 * - HW_USBC__TXFILLTUNINGUH1 - TX FIFO Fill Tuning UH1
 * - HW_USBC__IC_USBUH1 - IC_USB enable and voltage negotiation UH1
 * - HW_USBC__PORTSC1UH1 - Port Status & Control UH1
 * - HW_USBC__USBMODEUH1 - USB Device Mode UH1
 * - HW_USBC__IDUH2 - Identification register UH2
 * - HW_USBC__HWGENERALUH2 - Hardware General UH2
 * - HW_USBC__HWHOSTUH2 - Host Hardware Parameters UH2
 * - HW_USBC__HWTXBUFUH2 - TX Buffer Hardware Parameters UH2
 * - HW_USBC__HWRXBUFUH2 - RX Buffer Hardware Parameters UH2
 * - HW_USBC__GPTIMER0LDUH2 - General Purpose Timer #0 Load UH2
 * - HW_USBC__GPTIMER0CTRLUH2 - General Purpose Timer #0 Controller UH2
 * - HW_USBC__GPTIMER1LDUH2 - General Purpose Timer #1 Load UH2
 * - HW_USBC__GPTIMER1CTRLUH2 - General Purpose Timer #1 Controller UH2
 * - HW_USBC__SBUSCFGUH2 - System Bus Config UH2
 * - HW_USBC__CAPLENGTHUH2 - Capability Register Length UH2
 * - HW_USBC__HCIVERSIONUH2 - Host Controller Interface Version UH2
 * - HW_USBC__HCSPARAMSUH2 - Host Controller Structural Parameters UH2
 * - HW_USBC__HCCPARAMSUH2 - Host Controller Capability Parameters UH2
 * - HW_USBC__USBCMDUH2 - USB Command Register UH2
 * - HW_USBC__USBSTSUH2 - USB Status Register UH2
 * - HW_USBC__USBINTRUH2 - Interrupt Enable Register UH2
 * - HW_USBC__FRINDEXUH2 - USB Frame Index UH2
 * - HW_USBC__PERIODICLISTBASEUH2 - Frame List Base Address UH2
 * - HW_USBC__ASYNCLISTADDRUH2 - Next Asynch. Address UH2
 * - HW_USBC__BURSTSIZEUH2 - Programmable Burst Size UH2
 * - HW_USBC__TXFILLTUNINGUH2 - TX FIFO Fill Tuning UH2
 * - HW_USBC__IC_USBUH2 - IC_USB enable and voltage negotiation UH2
 * - HW_USBC__PORTSC1UH2 - Port Status & Control UH2
 * - HW_USBC__USBMODEUH2 - USB Device Mode UH2
 * - HW_USBC__IDUH3 - Identification register UH3
 * - HW_USBC__HWGENERALUH3 - Hardware General UH3
 * - HW_USBC__HWHOSTUH3 - Host Hardware Parameters UH3
 * - HW_USBC__HWTXBUFUH3 - TX Buffer Hardware Parameters UH3
 * - HW_USBC__HWRXBUFUH3 - RX Buffer Hardware Parameters UH3
 * - HW_USBC__GPTIMER0LDUH3 - General Purpose Timer #0 Load UH3
 * - HW_USBC__GPTIMER0CTRLUH3 - General Purpose Timer #0 Controller UH3
 * - HW_USBC__GPTIMER1LDUH3 - General Purpose Timer #1 Load UH3
 * - HW_USBC__GPTIMER1CTRLUH3 - General Purpose Timer #1 Controller UH3
 * - HW_USBC__SBUSCFGUH3 - System Bus Config UH3
 * - HW_USBC__CAPLENGTHUH3 - Capability Register Length UH3
 * - HW_USBC__HCIVERSIONUH3 - Host Controller Interface Version UH3
 * - HW_USBC__HCSPARAMSUH3 - Host Controller Structural Parameters UH3
 * - HW_USBC__HCCPARAMSUH3 - Host Controller Capability Parameters UH3
 * - HW_USBC__USBCMDUH3 - USB Command Register UH3
 * - HW_USBC__USBSTSUH3 - USB Status Register UH3
 * - HW_USBC__USBINTRUH3 - Interrupt Enable Register UH3
 * - HW_USBC__FRINDEXUH3 - USB Frame Index UH3
 * - HW_USBC__PERIODICLISTBASEUH3 - Frame List Base Address UH3
 * - HW_USBC__ASYNCLISTADDRUH3 - Next Asynch. Address UH3
 * - HW_USBC__BURSTSIZEUH3 - Programmable Burst Size UH3
 * - HW_USBC__TXFILLTUNINGUH3 - TX FIFO Fill Tuning UH3
 * - HW_USBC__IC_USBUH3 - IC_USB enable and voltage negotiation UH3
 * - HW_USBC__PORTSC1UH3 - Port Status & Control UH3
 * - HW_USBC__USBMODEUH3 - USB Device Mode UH3
 *
 * hw_usbc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_USBC_BASE
#define REGS_USBC_BASE (0x02184000) //!< Base address for USBC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IDUOG - Identification register UOG (RO)
 *
 * The ID register identifies the USB 2.0 OTG High-Speed core and its revision.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ID : 6; //!< Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG High-Speed core.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned NID : 6; //!< Complement version of ID
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned REVISION : 8; //!< Revision number of the controller core.
        unsigned RESERVED2 : 8; //!< Reserved
    } B;
} hw_usbc__iduog_t;
#endif

/*
 * constants & macros for entire USBC__IDUOG register
 */
#define HW_USBC__IDUOG_ADDR      (REGS_USBC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IDUOG           (*(volatile hw_usbc__iduog_t *) HW_USBC__IDUOG_ADDR)
#define HW_USBC__IDUOG_RD()      (HW_USBC__IDUOG.U)
#endif

/*
 * constants & macros for individual USBC__IDUOG bitfields
 */

/* --- Register HW_USBC__IDUOG, field ID[5:0] (RO)
 *
 * Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG
 * High-Speed core.
 */

#define BP_USBC__IDUOG_ID      (0)
#define BM_USBC__IDUOG_ID      (0x0000003f)

/* --- Register HW_USBC__IDUOG, field NID[13:8] (RO)
 *
 * Complement version of ID
 */

#define BP_USBC__IDUOG_NID      (8)
#define BM_USBC__IDUOG_NID      (0x00003f00)

/* --- Register HW_USBC__IDUOG, field REVISION[23:16] (RO)
 *
 * Revision number of the controller core.
 */

#define BP_USBC__IDUOG_REVISION      (16)
#define BM_USBC__IDUOG_REVISION      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWGENERALUOG - Hardware General UOG (RO)
 *
 * General hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned PHYW : 2; //!< Data width of the transciever connected to the controller core. For OTG controller core reset value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller core, reset value is '01b'.
        unsigned PHYM : 3; //!< Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '4h'.
        unsigned SM : 2; //!< Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '00b'.
        unsigned RESERVED1 : 21; //!< Reserved
    } B;
} hw_usbc__hwgeneraluog_t;
#endif

/*
 * constants & macros for entire USBC__HWGENERALUOG register
 */
#define HW_USBC__HWGENERALUOG_ADDR      (REGS_USBC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWGENERALUOG           (*(volatile hw_usbc__hwgeneraluog_t *) HW_USBC__HWGENERALUOG_ADDR)
#define HW_USBC__HWGENERALUOG_RD()      (HW_USBC__HWGENERALUOG.U)
#endif

/*
 * constants & macros for individual USBC__HWGENERALUOG bitfields
 */

/* --- Register HW_USBC__HWGENERALUOG, field PHYW[5:4] (RO)
 *
 * Data width of the transciever connected to the controller core. For OTG controller core reset
 * value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For
 * OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller
 * core, reset value is '01b'.
 *
 * Values:
 * 00 - 8 bit wide data bus [60MHz clock from the transciever]
 * 01 - 16 bit wide data bus [30MHZ clock from the transciever]
 * 10 - software programmable reset to 8-bit width
 * 11 - software programmable reset to 16-bit width
 */

#define BP_USBC__HWGENERALUOG_PHYW      (4)
#define BM_USBC__HWGENERALUOG_PHYW      (0x00000030)


/* --- Register HW_USBC__HWGENERALUOG, field PHYM[8:6] (RO)
 *
 * Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG
 * controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'.
 * For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value
 * is '4h'.
 *
 * Values:
 * 000 - UTMI/UMTI+
 * 001 - ULPI DDR
 * 010 - ULPI
 * 011 - Serial Only
 * 100 - Software programmable - reset to UTMI/UTMI+
 * 101 - Software programmable - reset to ULPI DDR
 * 110 - Software programmable - reset to ULPI
 * 111 - Software programmable - reset to Serial
 * 1000 - IC-USB
 * 1001 - Software programmable - reset to IC-USB
 * 1010 - HSIC
 * 1011 - Software programmable - reset to HSIC
 */

#define BP_USBC__HWGENERALUOG_PHYM      (6)
#define BM_USBC__HWGENERALUOG_PHYM      (0x000001c0)


/* --- Register HW_USBC__HWGENERALUOG, field SM[10:9] (RO)
 *
 * Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.
 * For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3
 * controller core, reset value is '00b'.
 *
 * Values:
 * 00 - No Serial Engine, always use parallel signalling.
 * 01 - Serial Engine present, always use serial signalling for FS/LS.
 * 10 - Software programmable - Reset to use parallel signalling for FS/LS
 * 11 - Software programmable - Reset to use serial signalling for FS/LS
 */

#define BP_USBC__HWGENERALUOG_SM      (9)
#define BM_USBC__HWGENERALUOG_SM      (0x00000600)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWHOSTUOG - Host Hardware Parameters UOG (RO)
 *
 * Host hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HC : 1; //!< Host Capable. All 4 controller cores support host operation mode.
        unsigned NPORT : 3; //!< The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller cores are single port, these bits are set to '000b'.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__hwhostuog_t;
#endif

/*
 * constants & macros for entire USBC__HWHOSTUOG register
 */
#define HW_USBC__HWHOSTUOG_ADDR      (REGS_USBC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWHOSTUOG           (*(volatile hw_usbc__hwhostuog_t *) HW_USBC__HWHOSTUOG_ADDR)
#define HW_USBC__HWHOSTUOG_RD()      (HW_USBC__HWHOSTUOG.U)
#endif

/*
 * constants & macros for individual USBC__HWHOSTUOG bitfields
 */

/* --- Register HW_USBC__HWHOSTUOG, field HC[0:0] (RO)
 *
 * Host Capable. All 4 controller cores support host operation mode.
 *
 * Values:
 * 0 - not support
 * 1 - support host operation mode
 */

#define BP_USBC__HWHOSTUOG_HC      (0)
#define BM_USBC__HWHOSTUOG_HC      (0x00000001)


/* --- Register HW_USBC__HWHOSTUOG, field NPORT[3:1] (RO)
 *
 * The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller
 * cores are single port, these bits are set to '000b'.
 */

#define BP_USBC__HWHOSTUOG_NPORT      (1)
#define BM_USBC__HWHOSTUOG_NPORT      (0x0000000e)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_HWDEVICE - Device Hardware Parameters (RO)
 *
 * Device hardware parameters are as defined in System Level Issues and Core Configuration.  This
 * register is only available in OTG core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DC : 1; //!< Device Capable.
        unsigned DEVEP : 5; //!< Device Endpoint Number OTG controller core has 8 Endpoints.
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
#endif

/*
 * constants & macros for individual USBC_UOG_HWDEVICE bitfields
 */

/* --- Register HW_USBC_UOG_HWDEVICE, field DC[0:0] (RO)
 *
 * Device Capable.
 *
 * Values:
 * 0 - not support
 * 1 - support device operation mode
 */

#define BP_USBC_UOG_HWDEVICE_DC      (0)
#define BM_USBC_UOG_HWDEVICE_DC      (0x00000001)


/* --- Register HW_USBC_UOG_HWDEVICE, field DEVEP[5:1] (RO)
 *
 * Device Endpoint Number OTG controller core has 8 Endpoints.
 */

#define BP_USBC_UOG_HWDEVICE_DEVEP      (1)
#define BM_USBC_UOG_HWDEVICE_DEVEP      (0x0000003e)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWTXBUFUOG - TX Buffer Hardware Parameters UOG (RO)
 *
 * TX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXBURST : 8; //!< Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned TXCHANADD : 8; //!< TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc__hwtxbufuog_t;
#endif

/*
 * constants & macros for entire USBC__HWTXBUFUOG register
 */
#define HW_USBC__HWTXBUFUOG_ADDR      (REGS_USBC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWTXBUFUOG           (*(volatile hw_usbc__hwtxbufuog_t *) HW_USBC__HWTXBUFUOG_ADDR)
#define HW_USBC__HWTXBUFUOG_RD()      (HW_USBC__HWTXBUFUOG.U)
#endif

/*
 * constants & macros for individual USBC__HWTXBUFUOG bitfields
 */

/* --- Register HW_USBC__HWTXBUFUOG, field TXBURST[7:0] (RO)
 *
 * Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWTXBUFUOG_TXBURST      (0)
#define BM_USBC__HWTXBUFUOG_TXBURST      (0x000000ff)

/* --- Register HW_USBC__HWTXBUFUOG, field TXCHANADD[23:16] (RO)
 *
 * TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4
 * Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX
 * Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
 */

#define BP_USBC__HWTXBUFUOG_TXCHANADD      (16)
#define BM_USBC__HWTXBUFUOG_TXCHANADD      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWRXBUFUOG - RX Buffer Hardware Parameters UOG (RO)
 *
 * RX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXBURST : 8; //!< Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RXADD : 8; //!< Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX Buffer.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usbc__hwrxbufuog_t;
#endif

/*
 * constants & macros for entire USBC__HWRXBUFUOG register
 */
#define HW_USBC__HWRXBUFUOG_ADDR      (REGS_USBC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWRXBUFUOG           (*(volatile hw_usbc__hwrxbufuog_t *) HW_USBC__HWRXBUFUOG_ADDR)
#define HW_USBC__HWRXBUFUOG_RD()      (HW_USBC__HWRXBUFUOG.U)
#endif

/*
 * constants & macros for individual USBC__HWRXBUFUOG bitfields
 */

/* --- Register HW_USBC__HWRXBUFUOG, field RXBURST[7:0] (RO)
 *
 * Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWRXBUFUOG_RXBURST      (0)
#define BM_USBC__HWRXBUFUOG_RXBURST      (0x000000ff)

/* --- Register HW_USBC__HWRXBUFUOG, field RXADD[15:8] (RO)
 *
 * Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes.
 * These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one
 * RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX
 * Buffer.
 */

#define BP_USBC__HWRXBUFUOG_RXADD      (8)
#define BM_USBC__HWRXBUFUOG_RXADD      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0LDUOG - General Purpose Timer #0 Load UOG (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER0CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer0lduog_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0LDUOG register
 */
#define HW_USBC__GPTIMER0LDUOG_ADDR      (REGS_USBC_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0LDUOG           (*(volatile hw_usbc__gptimer0lduog_t *) HW_USBC__GPTIMER0LDUOG_ADDR)
#define HW_USBC__GPTIMER0LDUOG_RD()      (HW_USBC__GPTIMER0LDUOG.U)
#define HW_USBC__GPTIMER0LDUOG_WR(v)     (HW_USBC__GPTIMER0LDUOG.U = (v))
#define HW_USBC__GPTIMER0LDUOG_SET(v)    (HW_USBC__GPTIMER0LDUOG_WR(HW_USBC__GPTIMER0LDUOG_RD() |  (v)))
#define HW_USBC__GPTIMER0LDUOG_CLR(v)    (HW_USBC__GPTIMER0LDUOG_WR(HW_USBC__GPTIMER0LDUOG_RD() & ~(v)))
#define HW_USBC__GPTIMER0LDUOG_TOG(v)    (HW_USBC__GPTIMER0LDUOG_WR(HW_USBC__GPTIMER0LDUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0LDUOG bitfields
 */

/* --- Register HW_USBC__GPTIMER0LDUOG, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER0LDUOG_GPTLD      (0)
#define BM_USBC__GPTIMER0LDUOG_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0LDUOG_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0LDUOG_GPTLD)
#else
#define BF_USBC__GPTIMER0LDUOG_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER0LDUOG_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER0LDUOG_GPTLD(v)   BF_CS1(USBC__GPTIMER0LDUOG, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0CTRLUOG - General Purpose Timer #0 Controller UOG (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI0 bit in n_USBSTS register (See ), interrupt enable bit is
 * TIE0 bit in n_USBINTR register. (See .)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer0ctrluog_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0CTRLUOG register
 */
#define HW_USBC__GPTIMER0CTRLUOG_ADDR      (REGS_USBC_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0CTRLUOG           (*(volatile hw_usbc__gptimer0ctrluog_t *) HW_USBC__GPTIMER0CTRLUOG_ADDR)
#define HW_USBC__GPTIMER0CTRLUOG_RD()      (HW_USBC__GPTIMER0CTRLUOG.U)
#define HW_USBC__GPTIMER0CTRLUOG_WR(v)     (HW_USBC__GPTIMER0CTRLUOG.U = (v))
#define HW_USBC__GPTIMER0CTRLUOG_SET(v)    (HW_USBC__GPTIMER0CTRLUOG_WR(HW_USBC__GPTIMER0CTRLUOG_RD() |  (v)))
#define HW_USBC__GPTIMER0CTRLUOG_CLR(v)    (HW_USBC__GPTIMER0CTRLUOG_WR(HW_USBC__GPTIMER0CTRLUOG_RD() & ~(v)))
#define HW_USBC__GPTIMER0CTRLUOG_TOG(v)    (HW_USBC__GPTIMER0CTRLUOG_WR(HW_USBC__GPTIMER0CTRLUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0CTRLUOG bitfields
 */

/* --- Register HW_USBC__GPTIMER0CTRLUOG, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER0CTRLUOG_GPTCNT      (0)
#define BM_USBC__GPTIMER0CTRLUOG_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUOG_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0CTRLUOG_GPTCNT)
#else
#define BF_USBC__GPTIMER0CTRLUOG_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER0CTRLUOG_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER0CTRLUOG_GPTCNT(v)   BF_CS1(USBC__GPTIMER0CTRLUOG, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRLUOG, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER0CTRLUOG_GPTMODE      (24)
#define BM_USBC__GPTIMER0CTRLUOG_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUOG_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER0CTRLUOG_GPTMODE)
#else
#define BF_USBC__GPTIMER0CTRLUOG_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER0CTRLUOG_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER0CTRLUOG_GPTMODE(v)   BF_CS1(USBC__GPTIMER0CTRLUOG, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUOG, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in n_GPTIMER0LD
 */

#define BP_USBC__GPTIMER0CTRLUOG_GPTRST      (30)
#define BM_USBC__GPTIMER0CTRLUOG_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUOG_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER0CTRLUOG_GPTRST)
#else
#define BF_USBC__GPTIMER0CTRLUOG_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER0CTRLUOG_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER0CTRLUOG_GPTRST(v)   BF_CS1(USBC__GPTIMER0CTRLUOG, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUOG, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER0CTRLUOG_GPTRUN      (31)
#define BM_USBC__GPTIMER0CTRLUOG_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUOG_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER0CTRLUOG_GPTRUN)
#else
#define BF_USBC__GPTIMER0CTRLUOG_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER0CTRLUOG_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER0CTRLUOG_GPTRUN(v)   BF_CS1(USBC__GPTIMER0CTRLUOG, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1LDUOG - General Purpose Timer #1 Load UOG (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER1CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer1lduog_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1LDUOG register
 */
#define HW_USBC__GPTIMER1LDUOG_ADDR      (REGS_USBC_BASE + 0x88)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1LDUOG           (*(volatile hw_usbc__gptimer1lduog_t *) HW_USBC__GPTIMER1LDUOG_ADDR)
#define HW_USBC__GPTIMER1LDUOG_RD()      (HW_USBC__GPTIMER1LDUOG.U)
#define HW_USBC__GPTIMER1LDUOG_WR(v)     (HW_USBC__GPTIMER1LDUOG.U = (v))
#define HW_USBC__GPTIMER1LDUOG_SET(v)    (HW_USBC__GPTIMER1LDUOG_WR(HW_USBC__GPTIMER1LDUOG_RD() |  (v)))
#define HW_USBC__GPTIMER1LDUOG_CLR(v)    (HW_USBC__GPTIMER1LDUOG_WR(HW_USBC__GPTIMER1LDUOG_RD() & ~(v)))
#define HW_USBC__GPTIMER1LDUOG_TOG(v)    (HW_USBC__GPTIMER1LDUOG_WR(HW_USBC__GPTIMER1LDUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1LDUOG bitfields
 */

/* --- Register HW_USBC__GPTIMER1LDUOG, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER1LDUOG_GPTLD      (0)
#define BM_USBC__GPTIMER1LDUOG_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1LDUOG_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1LDUOG_GPTLD)
#else
#define BF_USBC__GPTIMER1LDUOG_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER1LDUOG_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER1LDUOG_GPTLD(v)   BF_CS1(USBC__GPTIMER1LDUOG, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1CTRLUOG - General Purpose Timer #1 Controller UOG (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI1 bit in UOG_USBSTS register (See ), interrupt enable bit is
 * TIE1 bit in n_USBINTR register (See ).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer1ctrluog_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1CTRLUOG register
 */
#define HW_USBC__GPTIMER1CTRLUOG_ADDR      (REGS_USBC_BASE + 0x8c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1CTRLUOG           (*(volatile hw_usbc__gptimer1ctrluog_t *) HW_USBC__GPTIMER1CTRLUOG_ADDR)
#define HW_USBC__GPTIMER1CTRLUOG_RD()      (HW_USBC__GPTIMER1CTRLUOG.U)
#define HW_USBC__GPTIMER1CTRLUOG_WR(v)     (HW_USBC__GPTIMER1CTRLUOG.U = (v))
#define HW_USBC__GPTIMER1CTRLUOG_SET(v)    (HW_USBC__GPTIMER1CTRLUOG_WR(HW_USBC__GPTIMER1CTRLUOG_RD() |  (v)))
#define HW_USBC__GPTIMER1CTRLUOG_CLR(v)    (HW_USBC__GPTIMER1CTRLUOG_WR(HW_USBC__GPTIMER1CTRLUOG_RD() & ~(v)))
#define HW_USBC__GPTIMER1CTRLUOG_TOG(v)    (HW_USBC__GPTIMER1CTRLUOG_WR(HW_USBC__GPTIMER1CTRLUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1CTRLUOG bitfields
 */

/* --- Register HW_USBC__GPTIMER1CTRLUOG, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER1CTRLUOG_GPTCNT      (0)
#define BM_USBC__GPTIMER1CTRLUOG_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUOG_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1CTRLUOG_GPTCNT)
#else
#define BF_USBC__GPTIMER1CTRLUOG_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER1CTRLUOG_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER1CTRLUOG_GPTCNT(v)   BF_CS1(USBC__GPTIMER1CTRLUOG, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRLUOG, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER1CTRLUOG_GPTMODE      (24)
#define BM_USBC__GPTIMER1CTRLUOG_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUOG_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER1CTRLUOG_GPTMODE)
#else
#define BF_USBC__GPTIMER1CTRLUOG_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER1CTRLUOG_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER1CTRLUOG_GPTMODE(v)   BF_CS1(USBC__GPTIMER1CTRLUOG, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUOG, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in UOG_GPTIMER0LD
 */

#define BP_USBC__GPTIMER1CTRLUOG_GPTRST      (30)
#define BM_USBC__GPTIMER1CTRLUOG_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUOG_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER1CTRLUOG_GPTRST)
#else
#define BF_USBC__GPTIMER1CTRLUOG_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER1CTRLUOG_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER1CTRLUOG_GPTRST(v)   BF_CS1(USBC__GPTIMER1CTRLUOG, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUOG, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER1CTRLUOG_GPTRUN      (31)
#define BM_USBC__GPTIMER1CTRLUOG_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUOG_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER1CTRLUOG_GPTRUN)
#else
#define BF_USBC__GPTIMER1CTRLUOG_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER1CTRLUOG_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER1CTRLUOG_GPTRUN(v)   BF_CS1(USBC__GPTIMER1CTRLUOG, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__SBUSCFGUOG - System Bus Config UOG (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned AHBBRST : 3; //!< AHB master interface Burst configuration These bits controls AHB master transfer type sequence (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_usbc__sbuscfguog_t;
#endif

/*
 * constants & macros for entire USBC__SBUSCFGUOG register
 */
#define HW_USBC__SBUSCFGUOG_ADDR      (REGS_USBC_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__SBUSCFGUOG           (*(volatile hw_usbc__sbuscfguog_t *) HW_USBC__SBUSCFGUOG_ADDR)
#define HW_USBC__SBUSCFGUOG_RD()      (HW_USBC__SBUSCFGUOG.U)
#define HW_USBC__SBUSCFGUOG_WR(v)     (HW_USBC__SBUSCFGUOG.U = (v))
#define HW_USBC__SBUSCFGUOG_SET(v)    (HW_USBC__SBUSCFGUOG_WR(HW_USBC__SBUSCFGUOG_RD() |  (v)))
#define HW_USBC__SBUSCFGUOG_CLR(v)    (HW_USBC__SBUSCFGUOG_WR(HW_USBC__SBUSCFGUOG_RD() & ~(v)))
#define HW_USBC__SBUSCFGUOG_TOG(v)    (HW_USBC__SBUSCFGUOG_WR(HW_USBC__SBUSCFGUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__SBUSCFGUOG bitfields
 */

/* --- Register HW_USBC__SBUSCFGUOG, field AHBBRST[2:0] (RW)
 *
 * AHB master interface Burst configuration These bits controls AHB master transfer type sequence
 * (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
 *
 * Values:
 * 000 - Incremental burst of unspecified length only
 * 001 - INCR4 burst, then single transfer
 * 010 - INCR8 burst, INCR4 burst, then single transfer
 * 011 - INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 * 100 - Reserved, don't use
 * 101 - INCR4 burst, then incremental burst of unspecified length
 * 110 - INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 * 111 - INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */

#define BP_USBC__SBUSCFGUOG_AHBBRST      (0)
#define BM_USBC__SBUSCFGUOG_AHBBRST      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__SBUSCFGUOG_AHBBRST(v)   ((((reg32_t) v) << 0) & BM_USBC__SBUSCFGUOG_AHBBRST)
#else
#define BF_USBC__SBUSCFGUOG_AHBBRST(v)   (((v) << 0) & BM_USBC__SBUSCFGUOG_AHBBRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBBRST field to a new value.
#define BW_USBC__SBUSCFGUOG_AHBBRST(v)   BF_CS1(USBC__SBUSCFGUOG, AHBBRST, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__CAPLENGTHUOG - Capability Register Length UOG (RO)
 *
 * The following figure Capability Register Length (n_CAPLENGTH) indicates the offset that should be
 * added to the register base address at the beginning of the Operational Register.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CAPLENGTH : 8; //!< These bits are used as an offset to add to register base to find the beginning of the Operational Register. Default value is '40h'.
    } B;
} hw_usbc__caplengthuog_t;
#endif

/*
 * constants & macros for entire USBC__CAPLENGTHUOG register
 */
#define HW_USBC__CAPLENGTHUOG_ADDR      (REGS_USBC_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__CAPLENGTHUOG           (*(volatile hw_usbc__caplengthuog_t *) HW_USBC__CAPLENGTHUOG_ADDR)
#define HW_USBC__CAPLENGTHUOG_RD()      (HW_USBC__CAPLENGTHUOG.U)
#endif

/*
 * constants & macros for individual USBC__CAPLENGTHUOG bitfields
 */

/* --- Register HW_USBC__CAPLENGTHUOG, field CAPLENGTH[7:0] (RO)
 *
 * These bits are used as an offset to add to register base to find the beginning of the Operational
 * Register. Default value is '40h'.
 */

#define BP_USBC__CAPLENGTHUOG_CAPLENGTH      (0)
#define BM_USBC__CAPLENGTHUOG_CAPLENGTH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCIVERSIONUOG - Host Controller Interface Version UOG (RO)
 *
 * The following figure shows the Host Interface version number (n_HCIVERSION), which is a 2-byte
 * register containing a BCD encoding of the EHCI revision number supported by this host controller.
 * The most significant byte of this register represents a major revision and the least significant
 * byte is the minor revision.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HCIVERSION : 16; //!< Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
    } B;
} hw_usbc__hciversionuog_t;
#endif

/*
 * constants & macros for entire USBC__HCIVERSIONUOG register
 */
#define HW_USBC__HCIVERSIONUOG_ADDR      (REGS_USBC_BASE + 0x102)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCIVERSIONUOG           (*(volatile hw_usbc__hciversionuog_t *) HW_USBC__HCIVERSIONUOG_ADDR)
#define HW_USBC__HCIVERSIONUOG_RD()      (HW_USBC__HCIVERSIONUOG.U)
#endif

/*
 * constants & macros for individual USBC__HCIVERSIONUOG bitfields
 */

/* --- Register HW_USBC__HCIVERSIONUOG, field HCIVERSION[15:0] (RO)
 *
 * Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
 */

#define BP_USBC__HCIVERSIONUOG_HCIVERSION      (0)
#define BM_USBC__HCIVERSIONUOG_HCIVERSION      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCSPARAMSUOG - Host Controller Structural Parameters UOG (RO)
 *
 * The following figure shows the port steering logic capabilities of Host Control Structural
 * Parameters (n_HCSPARAMS).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned N_PORTS : 4; //!< Number of downstream ports. This field specifies the number of physical downstream ports implemented on this host controller. The value of this field determines how many port registers are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in this field is undefined. These bits are always set to '0001b' because all 4 controller cores are Single-Port Host.
        unsigned PPC : 1; //!< Port Power Control This field indicates whether the host controller implementation includes port power control. A one indicates the ports have port power switches. A zero indicates the ports do not have port power switches. The value of this field affects the functionality of the Port Power field in each port status and control register
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned N_PCC : 4; //!< Number of Ports per Companion Controller This field indicates the number of ports supported per internal Companion Controller. It is used to indicate the port routing configuration to the system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and the last two are routed to companion controller 2. The number in this field must be consistent with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
        unsigned N_CC : 4; //!< Number of Companion Controller (N_CC). This field indicates the number of companion controllers associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
        unsigned PI : 1; //!< Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator control. When set to one, the port status and control registers include a read/writeable field for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned N_PTT : 4; //!< Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates the number of ports assigned to each transaction translator within the USB2.0 host controller. These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned N_TT : 4; //!< Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number of embedded transaction translators associated with the USB2.0 host controller. These bits would be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_usbc__hcsparamsuog_t;
#endif

/*
 * constants & macros for entire USBC__HCSPARAMSUOG register
 */
#define HW_USBC__HCSPARAMSUOG_ADDR      (REGS_USBC_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCSPARAMSUOG           (*(volatile hw_usbc__hcsparamsuog_t *) HW_USBC__HCSPARAMSUOG_ADDR)
#define HW_USBC__HCSPARAMSUOG_RD()      (HW_USBC__HCSPARAMSUOG.U)
#endif

/*
 * constants & macros for individual USBC__HCSPARAMSUOG bitfields
 */

/* --- Register HW_USBC__HCSPARAMSUOG, field N_PORTS[3:0] (RO)
 *
 * Number of downstream ports. This field specifies the number of physical downstream ports
 * implemented on this host controller. The value of this field determines how many port registers
 * are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in
 * this field is undefined. These bits are always set to '0001b' because all 4 controller cores are
 * Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUOG_N_PORTS      (0)
#define BM_USBC__HCSPARAMSUOG_N_PORTS      (0x0000000f)

/* --- Register HW_USBC__HCSPARAMSUOG, field PPC[4:4] (RO)
 *
 * Port Power Control This field indicates whether the host controller implementation includes port
 * power control. A one indicates the ports have port power switches. A zero indicates the ports do
 * not have port power switches. The value of this field affects the functionality of the Port Power
 * field in each port status and control register
 */

#define BP_USBC__HCSPARAMSUOG_PPC      (4)
#define BM_USBC__HCSPARAMSUOG_PPC      (0x00000010)

/* --- Register HW_USBC__HCSPARAMSUOG, field N_PCC[11:8] (RO)
 *
 * Number of Ports per Companion Controller This field indicates the number of ports supported per
 * internal Companion Controller. It is used to indicate the port routing configuration to the
 * system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC
 * could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to
 * companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous
 * example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and
 * the last two are routed to companion controller 2. The number in this field must be consistent
 * with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUOG_N_PCC      (8)
#define BM_USBC__HCSPARAMSUOG_N_PCC      (0x00000f00)

/* --- Register HW_USBC__HCSPARAMSUOG, field N_CC[15:12] (RO)
 *
 * Number of Companion Controller (N_CC). This field indicates the number of companion controllers
 * associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
 *
 * Values:
 * 0 - There is no internal Companion Controller and port-ownership hand-off is not supported.
 * 1 - There are internal companion controller(s) and port-ownership hand-offs is supported.
 */

#define BP_USBC__HCSPARAMSUOG_N_CC      (12)
#define BM_USBC__HCSPARAMSUOG_N_CC      (0x0000f000)


/* --- Register HW_USBC__HCSPARAMSUOG, field PI[16:16] (RO)
 *
 * Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator
 * control. When set to one, the port status and control registers include a read/writeable field
 * for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUOG_PI      (16)
#define BM_USBC__HCSPARAMSUOG_PI      (0x00010000)

/* --- Register HW_USBC__HCSPARAMSUOG, field N_PTT[23:20] (RO)
 *
 * Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates
 * the number of ports assigned to each transaction translator within the USB2.0 host controller.
 * These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUOG_N_PTT      (20)
#define BM_USBC__HCSPARAMSUOG_N_PTT      (0x00f00000)

/* --- Register HW_USBC__HCSPARAMSUOG, field N_TT[27:24] (RO)
 *
 * Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number
 * of embedded transaction translators associated with the USB2.0 host controller. These bits would
 * be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUOG_N_TT      (24)
#define BM_USBC__HCSPARAMSUOG_N_TT      (0x0f000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCCPARAMSUOG - Host Controller Capability Parameters UOG (RO)
 *
 * This register identifies multiple mode control (time-base bit functionality), addressing
 * capability.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADC : 1; //!< 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing capability is supported.
        unsigned PFL : 1; //!< Programmable Frame List Flag If this bit is set to zero, then the system software must use a frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size field is a read-only register and must be set to zero. If set to a one, then the system software can specify and use a smaller frame list and configure the host controller via the USBCMD register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in all 4 controller core.
        unsigned ASP : 1; //!< Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is set '1b' in all 4 controller core.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned IST : 4; //!< Isochronous Scheduling Threshold. This field indicates, relative to the current position of the executing host controller, where software can reliably update the isochronous schedule. When bit [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a host controller can hold a set of isochronous data structures (one or more) before flushing the state. When bit [7] is a one, then host software assumes the host controller may cache an isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller core.
        unsigned EECP : 8; //!< EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A value of 00h indicates no extended capabilities are implemented. A non-zero value in this register indicates the offset in PCI configuration space of the first EHCI extended capability. The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI header defined for this class of device. These bits are set '00h' in all 4 controller core.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_usbc__hccparamsuog_t;
#endif

/*
 * constants & macros for entire USBC__HCCPARAMSUOG register
 */
#define HW_USBC__HCCPARAMSUOG_ADDR      (REGS_USBC_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCCPARAMSUOG           (*(volatile hw_usbc__hccparamsuog_t *) HW_USBC__HCCPARAMSUOG_ADDR)
#define HW_USBC__HCCPARAMSUOG_RD()      (HW_USBC__HCCPARAMSUOG.U)
#endif

/*
 * constants & macros for individual USBC__HCCPARAMSUOG bitfields
 */

/* --- Register HW_USBC__HCCPARAMSUOG, field ADC[0:0] (RO)
 *
 * 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing
 * capability is supported.
 */

#define BP_USBC__HCCPARAMSUOG_ADC      (0)
#define BM_USBC__HCCPARAMSUOG_ADC      (0x00000001)

/* --- Register HW_USBC__HCCPARAMSUOG, field PFL[1:1] (RO)
 *
 * Programmable Frame List Flag If this bit is set to zero, then the system software must use a
 * frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size
 * field is a read-only register and must be set to zero. If set to a one, then the system software
 * can specify and use a smaller frame list and configure the host controller via the USBCMD
 * register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This
 * requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in
 * all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUOG_PFL      (1)
#define BM_USBC__HCCPARAMSUOG_PFL      (0x00000002)

/* --- Register HW_USBC__HCCPARAMSUOG, field ASP[2:2] (RO)
 *
 * Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller
 * supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature
 * can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park
 * Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is
 * set '1b' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUOG_ASP      (2)
#define BM_USBC__HCCPARAMSUOG_ASP      (0x00000004)

/* --- Register HW_USBC__HCCPARAMSUOG, field IST[7:4] (RO)
 *
 * Isochronous Scheduling Threshold. This field indicates, relative to the current position of the
 * executing host controller, where software can reliably update the isochronous schedule. When bit
 * [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a
 * host controller can hold a set of isochronous data structures (one or more) before flushing the
 * state. When bit [7] is a one, then host software assumes the host controller may cache an
 * isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller
 * core.
 */

#define BP_USBC__HCCPARAMSUOG_IST      (4)
#define BM_USBC__HCCPARAMSUOG_IST      (0x000000f0)

/* --- Register HW_USBC__HCCPARAMSUOG, field EECP[15:8] (RO)
 *
 * EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A
 * value of 00h indicates no extended capabilities are implemented. A non-zero value in this
 * register indicates the offset in PCI configuration space of the first EHCI extended capability.
 * The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI
 * header defined for this class of device. These bits are set '00h' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUOG_EECP      (8)
#define BM_USBC__HCCPARAMSUOG_EECP      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_DCIVERSION - Device Controller Interface Version (RO)
 *
 * This register indicates the two-byte BCD encoding of the device controller interface version
 * number.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short DCIVERSION : 16; //!< Device Controller Interface Version Number Default value is '01h', which means rev0.1.
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
#endif

/*
 * constants & macros for individual USBC_UOG_DCIVERSION bitfields
 */

/* --- Register HW_USBC_UOG_DCIVERSION, field DCIVERSION[15:0] (RO)
 *
 * Device Controller Interface Version Number Default value is '01h', which means rev0.1.
 */

#define BP_USBC_UOG_DCIVERSION_DCIVERSION      (0)
#define BM_USBC_UOG_DCIVERSION_DCIVERSION      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_DCCPARAMS - Device Controller Capability Parameters (RO)
 *
 * These fields describe the overall device capability of the controller.  This register is only
 * available in OTG controller core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DEN : 5; //!< Device Endpoint Number This field indicates the number of endpoints built into the device controller. If this controller is not device capable, then this field will be zero. Valid values are 0 - 15.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned DC : 1; //!< Device Capable When this bit is 1, this controller is capable of operating as a USB 2.0 device.
        unsigned HC : 1; //!< Host Capable When this bit is 1, this controller is capable of operating as an EHCI compatible USB 2.0 host controller.
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
#endif

/*
 * constants & macros for individual USBC_UOG_DCCPARAMS bitfields
 */

/* --- Register HW_USBC_UOG_DCCPARAMS, field DEN[4:0] (RO)
 *
 * Device Endpoint Number This field indicates the number of endpoints built into the device
 * controller. If this controller is not device capable, then this field will be zero. Valid values
 * are 0 - 15.
 */

#define BP_USBC_UOG_DCCPARAMS_DEN      (0)
#define BM_USBC_UOG_DCCPARAMS_DEN      (0x0000001f)

/* --- Register HW_USBC_UOG_DCCPARAMS, field DC[7:7] (RO)
 *
 * Device Capable When this bit is 1, this controller is capable of operating as a USB 2.0 device.
 */

#define BP_USBC_UOG_DCCPARAMS_DC      (7)
#define BM_USBC_UOG_DCCPARAMS_DC      (0x00000080)

/* --- Register HW_USBC_UOG_DCCPARAMS, field HC[8:8] (RO)
 *
 * Host Capable When this bit is 1, this controller is capable of operating as an EHCI compatible
 * USB 2.0 host controller.
 */

#define BP_USBC_UOG_DCCPARAMS_HC      (8)
#define BM_USBC_UOG_DCCPARAMS_HC      (0x00000100)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBCMDUOG - USB Command Register UOG (RW)
 *
 * The Command Register indicates the command to be executed by the serial bus host/device
 * controller. Writing to the register causes a command to be executed.  *: ASPE,ASP[1],ASP[0] reset
 * value: '0b' for OTG core; '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RS : 1; //!< Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the Controller proceeds with the execution of the schedule. The Controller continues execution as long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the current transaction on the USB and then halts. The HC Halted bit in the status register indicates when the Controller has finished the transaction and has entered the stopped state. Software should not write a one to this field unless the controller is in the Halted state (that is, HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is not directly connected to the pull-up enable, as the pull-up will become disabled upon transitioning into high-speed mode. Software should use this bit to prevent an attach event before the controller has been properly initialized. Writing a 0 to this will cause a detach event.
        unsigned RST : 1; //!< Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register. Host operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Any transaction currently in progress on USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset an actively running host controller will result in undefined behavior. Device operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Writing a one to this bit when the device is in the attached state is not recommended, because the effect on an attached host is undefined. In order to ensure that the device is not in an attached state before initiating a device controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be set to 0.
        unsigned FS : 2; //!< See description at bit 15
        unsigned PSE : 1; //!< Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
        unsigned ASE : 1; //!< Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host controller skips processing the Asynchronous Schedule. Only the host controller uses this bit. Values Meaning
        unsigned IAA : 1; //!< Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to tell the host controller to issue an interrupt the next time it advances asynchronous schedule. Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then the host controller will assert an interrupt at the next interrupt threshold. The host controller sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS register to one. Software should not write a one to this bit when the asynchronous schedule is inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a one to this bit when device mode is selected will have undefined results.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ASP : 2; //!< Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults to zero and is Read-Only. It contains a count of the number of successive transactions the host controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not write a zero to this bit when Park Mode Enable is a one as this will result in undefined behavior. This field is set to 3h in all 4 controller core.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ASPE : 1; //!< Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to '1b' in this implementation.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned SUTW : 1; //!< Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a hazard when new setup data arrives while the DCD is copying the setup data payload from the QH for a previous setup packet. This bit is set and cleared by software. This bit would also be cleared by hardware when a hazard detected. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned ATDTW : 1; //!< Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and cleared by software. This bit would also be cleared by hardware when state machine is hazard region for which adding a dTD to a primed endpoint may go unrecognized. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned FS1 : 1; //!< See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This field specifies the size of the frame list that controls which bits in the Frame Index Register should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and 2. Value Meaning
        unsigned ITC : 8; //!< Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum Interrupt Interval
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc__usbcmduog_t;
#endif

/*
 * constants & macros for entire USBC__USBCMDUOG register
 */
#define HW_USBC__USBCMDUOG_ADDR      (REGS_USBC_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBCMDUOG           (*(volatile hw_usbc__usbcmduog_t *) HW_USBC__USBCMDUOG_ADDR)
#define HW_USBC__USBCMDUOG_RD()      (HW_USBC__USBCMDUOG.U)
#define HW_USBC__USBCMDUOG_WR(v)     (HW_USBC__USBCMDUOG.U = (v))
#define HW_USBC__USBCMDUOG_SET(v)    (HW_USBC__USBCMDUOG_WR(HW_USBC__USBCMDUOG_RD() |  (v)))
#define HW_USBC__USBCMDUOG_CLR(v)    (HW_USBC__USBCMDUOG_WR(HW_USBC__USBCMDUOG_RD() & ~(v)))
#define HW_USBC__USBCMDUOG_TOG(v)    (HW_USBC__USBCMDUOG_WR(HW_USBC__USBCMDUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBCMDUOG bitfields
 */

/* --- Register HW_USBC__USBCMDUOG, field RS[0:0] (RW)
 *
 * Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the
 * Controller proceeds with the execution of the schedule. The Controller continues execution as
 * long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the
 * current transaction on the USB and then halts. The HC Halted bit in the status register indicates
 * when the Controller has finished the transaction and has entered the stopped state. Software
 * should not write a one to this field unless the controller is in the Halted state (that is,
 * HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will
 * cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is
 * not directly connected to the pull-up enable, as the pull-up will become disabled upon
 * transitioning into high-speed mode. Software should use this bit to prevent an attach event
 * before the controller has been properly initialized. Writing a 0 to this will cause a detach
 * event.
 */

#define BP_USBC__USBCMDUOG_RS      (0)
#define BM_USBC__USBCMDUOG_RS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_RS(v)   ((((reg32_t) v) << 0) & BM_USBC__USBCMDUOG_RS)
#else
#define BF_USBC__USBCMDUOG_RS(v)   (((v) << 0) & BM_USBC__USBCMDUOG_RS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RS field to a new value.
#define BW_USBC__USBCMDUOG_RS(v)   BF_CS1(USBC__USBCMDUOG, RS, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field RST[1:1] (RW)
 *
 * Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit
 * is set to zero by the Host/Device Controller when the reset process is complete. Software cannot
 * terminate the reset process early by writing a zero to this register. Host operation mode: When
 * software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Any transaction currently in progress on
 * USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not
 * set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset
 * an actively running host controller will result in undefined behavior. Device operation mode:
 * When software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Writing a one to this bit when the device
 * is in the attached state is not recommended, because the effect on an attached host is undefined.
 * In order to ensure that the device is not in an attached state before initiating a device
 * controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be
 * set to 0.
 */

#define BP_USBC__USBCMDUOG_RST      (1)
#define BM_USBC__USBCMDUOG_RST      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_RST(v)   ((((reg32_t) v) << 1) & BM_USBC__USBCMDUOG_RST)
#else
#define BF_USBC__USBCMDUOG_RST(v)   (((v) << 1) & BM_USBC__USBCMDUOG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RST field to a new value.
#define BW_USBC__USBCMDUOG_RST(v)   BF_CS1(USBC__USBCMDUOG, RST, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field FS[3:2] (RW)
 *
 * See description at bit 15
 */

#define BP_USBC__USBCMDUOG_FS      (2)
#define BM_USBC__USBCMDUOG_FS      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_FS(v)   ((((reg32_t) v) << 2) & BM_USBC__USBCMDUOG_FS)
#else
#define BF_USBC__USBCMDUOG_FS(v)   (((v) << 2) & BM_USBC__USBCMDUOG_FS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS field to a new value.
#define BW_USBC__USBCMDUOG_FS(v)   BF_CS1(USBC__USBCMDUOG, FS, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field PSE[4:4] (RW)
 *
 * Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller
 * skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
 *
 * Values:
 * 0 - Do not process the Periodic Schedule
 * 1 - Use the PERIODICLISTBASE register to access the Periodic Schedule.
 */

#define BP_USBC__USBCMDUOG_PSE      (4)
#define BM_USBC__USBCMDUOG_PSE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_PSE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBCMDUOG_PSE)
#else
#define BF_USBC__USBCMDUOG_PSE(v)   (((v) << 4) & BM_USBC__USBCMDUOG_PSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSE field to a new value.
#define BW_USBC__USBCMDUOG_PSE(v)   BF_CS1(USBC__USBCMDUOG, PSE, v)
#endif


/* --- Register HW_USBC__USBCMDUOG, field ASE[5:5] (RW)
 *
 * Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host
 * controller skips processing the Asynchronous Schedule. Only the host controller uses this bit.
 * Values Meaning
 *
 * Values:
 * 0 - Do not process the Asynchronous Schedule.
 * 1 - Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
 */

#define BP_USBC__USBCMDUOG_ASE      (5)
#define BM_USBC__USBCMDUOG_ASE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_ASE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBCMDUOG_ASE)
#else
#define BF_USBC__USBCMDUOG_ASE(v)   (((v) << 5) & BM_USBC__USBCMDUOG_ASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASE field to a new value.
#define BW_USBC__USBCMDUOG_ASE(v)   BF_CS1(USBC__USBCMDUOG, ASE, v)
#endif


/* --- Register HW_USBC__USBCMDUOG, field IAA[6:6] (RW)
 *
 * Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to
 * tell the host controller to issue an interrupt the next time it advances asynchronous schedule.
 * Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted
 * all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the
 * USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then
 * the host controller will assert an interrupt at the next interrupt threshold. The host controller
 * sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS
 * register to one. Software should not write a one to this bit when the asynchronous schedule is
 * inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a
 * one to this bit when device mode is selected will have undefined results.
 */

#define BP_USBC__USBCMDUOG_IAA      (6)
#define BM_USBC__USBCMDUOG_IAA      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_IAA(v)   ((((reg32_t) v) << 6) & BM_USBC__USBCMDUOG_IAA)
#else
#define BF_USBC__USBCMDUOG_IAA(v)   (((v) << 6) & BM_USBC__USBCMDUOG_IAA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IAA field to a new value.
#define BW_USBC__USBCMDUOG_IAA(v)   BF_CS1(USBC__USBCMDUOG, IAA, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field ASP[9:8] (RW)
 *
 * Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults
 * to zero and is Read-Only. It contains a count of the number of successive transactions the host
 * controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before
 * continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not
 * write a zero to this bit when Park Mode Enable is a one as this will result in undefined
 * behavior. This field is set to 3h in all 4 controller core.
 */

#define BP_USBC__USBCMDUOG_ASP      (8)
#define BM_USBC__USBCMDUOG_ASP      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_ASP(v)   ((((reg32_t) v) << 8) & BM_USBC__USBCMDUOG_ASP)
#else
#define BF_USBC__USBCMDUOG_ASP(v)   (((v) << 8) & BM_USBC__USBCMDUOG_ASP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP field to a new value.
#define BW_USBC__USBCMDUOG_ASP(v)   BF_CS1(USBC__USBCMDUOG, ASP, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field ASPE[11:11] (RW)
 *
 * Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit
 * must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is
 * one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to
 * '1b' in this implementation.
 */

#define BP_USBC__USBCMDUOG_ASPE      (11)
#define BM_USBC__USBCMDUOG_ASPE      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_ASPE(v)   ((((reg32_t) v) << 11) & BM_USBC__USBCMDUOG_ASPE)
#else
#define BF_USBC__USBCMDUOG_ASPE(v)   (((v) << 11) & BM_USBC__USBCMDUOG_ASPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASPE field to a new value.
#define BW_USBC__USBCMDUOG_ASPE(v)   BF_CS1(USBC__USBCMDUOG, ASPE, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field SUTW[13:13] (RW)
 *
 * Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that
 * the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If
 * the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a
 * hazard when new setup data arrives while the DCD is copying the setup data payload from the QH
 * for a previous setup packet. This bit is set and cleared by software. This bit would also be
 * cleared by hardware when a hazard detected. For more information on the use of this bit, see the
 * Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUOG_SUTW      (13)
#define BM_USBC__USBCMDUOG_SUTW      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_SUTW(v)   ((((reg32_t) v) << 13) & BM_USBC__USBCMDUOG_SUTW)
#else
#define BF_USBC__USBCMDUOG_SUTW(v)   (((v) << 13) & BM_USBC__USBCMDUOG_SUTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUTW field to a new value.
#define BW_USBC__USBCMDUOG_SUTW(v)   BF_CS1(USBC__USBCMDUOG, SUTW, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field ATDTW[14:14] (RW)
 *
 * Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure
 * proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and
 * cleared by software. This bit would also be cleared by hardware when state machine is hazard
 * region for which adding a dTD to a primed endpoint may go unrecognized. For more information on
 * the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUOG_ATDTW      (14)
#define BM_USBC__USBCMDUOG_ATDTW      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_ATDTW(v)   ((((reg32_t) v) << 14) & BM_USBC__USBCMDUOG_ATDTW)
#else
#define BF_USBC__USBCMDUOG_ATDTW(v)   (((v) << 14) & BM_USBC__USBCMDUOG_ATDTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATDTW field to a new value.
#define BW_USBC__USBCMDUOG_ATDTW(v)   BF_CS1(USBC__USBCMDUOG, ATDTW, v)
#endif

/* --- Register HW_USBC__USBCMDUOG, field FS1[15:15] (RW)
 *
 * See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is
 * Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This
 * field specifies the size of the frame list that controls which bits in the Frame Index Register
 * should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and
 * 2. Value Meaning
 *
 * Values:
 * 000 - 1024 elements (4096 bytes) Default value
 * 001 - 512 elements (2048 bytes)
 * 010 - 256 elements (1024 bytes)
 * 011 - 128 elements (512 bytes)
 * 100 - 64 elements (256 bytes)
 * 101 - 32 elements (128 bytes)
 * 110 - 16 elements (64 bytes)
 * 111 - 8 elements (32 bytes)
 */

#define BP_USBC__USBCMDUOG_FS1      (15)
#define BM_USBC__USBCMDUOG_FS1      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_FS1(v)   ((((reg32_t) v) << 15) & BM_USBC__USBCMDUOG_FS1)
#else
#define BF_USBC__USBCMDUOG_FS1(v)   (((v) << 15) & BM_USBC__USBCMDUOG_FS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS1 field to a new value.
#define BW_USBC__USBCMDUOG_FS1(v)   BF_CS1(USBC__USBCMDUOG, FS1, v)
#endif


/* --- Register HW_USBC__USBCMDUOG, field ITC[23:16] (RW)
 *
 * Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum
 * rate at which the host/device controller will issue interrupts. ITC contains the maximum
 * interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum
 * Interrupt Interval
 *
 * Values:
 * 0x00 - Immediate (no threshold)
 * 0x01 - 1 micro-frame
 * 0x02 - 2 micro-frames
 * 0x04 - 4 micro-frames
 * 0x08 - 8 micro-frames
 * 0x10 - 16 micro-frames
 * 0x20 - 32 micro-frames
 * 0x40 - 64 micro-frames
 */

#define BP_USBC__USBCMDUOG_ITC      (16)
#define BM_USBC__USBCMDUOG_ITC      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUOG_ITC(v)   ((((reg32_t) v) << 16) & BM_USBC__USBCMDUOG_ITC)
#else
#define BF_USBC__USBCMDUOG_ITC(v)   (((v) << 16) & BM_USBC__USBCMDUOG_ITC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ITC field to a new value.
#define BW_USBC__USBCMDUOG_ITC(v)   BF_CS1(USBC__USBCMDUOG, ITC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBSTSUOG - USB Status Register UOG (RW)
 *
 * This register indicates various states of the Host/Device Controller and any pending interrupts.
 * This register does not indicate status resulting from a transaction on the serial bus.  *HCH bit
 * reset value: '0b' for OTG core, '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UI : 1; //!< USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        unsigned UEI : 1; //!< USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e. 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus, Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB On-The-Go DEV reference manual. The device controller detects resume signaling only.
        unsigned PCI : 1; //!< Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the result of a J-K transition on the suspended port. The Device Controller sets this bit to a one when the port controller enters the full or high-speed operational state. When the port controller exits the full or high-speed operation states due to Reset or Suspend events, the notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
        unsigned FRI : 1; //!< Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index rolls over from its maximum value to zero. The exact value at which the rollover occurs depends on the frame list size. For example. If the frame list size (as programmed in the Frame List Size field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every time FHINDEX [12] toggles. Only used in host operation mode.
        unsigned SEI : 1; //!< System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on the system interface.
        unsigned AAI : 1; //!< Interrupt on Async Advance - R/WC. System software can force the host controller to issue an interrupt the next time the host controller advances the asynchronous schedule by writing a one to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit indicates the assertion of that interrupt source. Only used in host operation mode.
        unsigned URI : 1; //!< USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset Received status bit. Only used in device operation mode.
        unsigned SRI : 1; //!< SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will be set to a one. When a SOF is extremely late, the device controller will automatically set this bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is received. Because the device controller is initialized to FS before connect, this bit will be set at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set every 125us and can be used by host controller driver as a time base. Software writes a 1 to this bit to clear it.
        unsigned SLI : 1; //!< DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be set to a one. The device controller clears the bit upon exiting from a suspend state. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPII : 1; //!< ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HCH : 1; //!< HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either by software or by the Controller hardware (for example, an internal error). Only used in the host operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
        unsigned RCL : 1; //!< Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous schedule. Only used in the host operation mode.
        unsigned PS : 1; //!< Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Periodic Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned AS : 1; //!< Asynchronous Schedule Status - Read Only. This bit reports the current real status of the Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned NAKI : 1; //!< NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
        unsigned RESERVED2 : 7; //!< Reserved
        unsigned TI0 : 1; //!< General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
        unsigned TI1 : 1; //!< General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
        unsigned RESERVED3 : 6; //!< Reserved
    } B;
} hw_usbc__usbstsuog_t;
#endif

/*
 * constants & macros for entire USBC__USBSTSUOG register
 */
#define HW_USBC__USBSTSUOG_ADDR      (REGS_USBC_BASE + 0x144)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBSTSUOG           (*(volatile hw_usbc__usbstsuog_t *) HW_USBC__USBSTSUOG_ADDR)
#define HW_USBC__USBSTSUOG_RD()      (HW_USBC__USBSTSUOG.U)
#define HW_USBC__USBSTSUOG_WR(v)     (HW_USBC__USBSTSUOG.U = (v))
#define HW_USBC__USBSTSUOG_SET(v)    (HW_USBC__USBSTSUOG_WR(HW_USBC__USBSTSUOG_RD() |  (v)))
#define HW_USBC__USBSTSUOG_CLR(v)    (HW_USBC__USBSTSUOG_WR(HW_USBC__USBSTSUOG_RD() & ~(v)))
#define HW_USBC__USBSTSUOG_TOG(v)    (HW_USBC__USBSTSUOG_WR(HW_USBC__USBSTSUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBSTSUOG bitfields
 */

/* --- Register HW_USBC__USBSTSUOG, field UI[0:0] (RW)
 *
 * USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an
 * interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an
 * interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a
 * short packet is detected. A short packet is when the actual number of bytes received was less
 * than the expected number of bytes.
 */

#define BP_USBC__USBSTSUOG_UI      (0)
#define BM_USBC__USBSTSUOG_UI      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_UI(v)   ((((reg32_t) v) << 0) & BM_USBC__USBSTSUOG_UI)
#else
#define BF_USBC__USBSTSUOG_UI(v)   (((v) << 0) & BM_USBC__USBSTSUOG_UI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UI field to a new value.
#define BW_USBC__USBSTSUOG_UI(v)   BF_CS1(USBC__USBSTSUOG, UI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field UEI[1:1] (RW)
 *
 * USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error
 * condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT
 * bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit
 * set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e.
 * 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus,
 * Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of
 * host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual. The device controller detects resume signaling only.
 */

#define BP_USBC__USBSTSUOG_UEI      (1)
#define BM_USBC__USBSTSUOG_UEI      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_UEI(v)   ((((reg32_t) v) << 1) & BM_USBC__USBSTSUOG_UEI)
#else
#define BF_USBC__USBSTSUOG_UEI(v)   (((v) << 1) & BM_USBC__USBSTSUOG_UEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEI field to a new value.
#define BW_USBC__USBSTSUOG_UEI(v)   BF_CS1(USBC__USBSTSUOG, UEI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field PCI[2:2] (RW)
 *
 * Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect
 * Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the
 * result of a J-K transition on the suspended port. The Device Controller sets this bit to a one
 * when the port controller enters the full or high-speed operational state. When the port
 * controller exits the full or high-speed operation states due to Reset or Suspend events, the
 * notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
 */

#define BP_USBC__USBSTSUOG_PCI      (2)
#define BM_USBC__USBSTSUOG_PCI      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_PCI(v)   ((((reg32_t) v) << 2) & BM_USBC__USBSTSUOG_PCI)
#else
#define BF_USBC__USBSTSUOG_PCI(v)   (((v) << 2) & BM_USBC__USBSTSUOG_PCI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCI field to a new value.
#define BW_USBC__USBSTSUOG_PCI(v)   BF_CS1(USBC__USBSTSUOG, PCI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field FRI[3:3] (RW)
 *
 * Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index
 * rolls over from its maximum value to zero. The exact value at which the rollover occurs depends
 * on the frame list size. For example. If the frame list size (as programmed in the Frame List Size
 * field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX
 * [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every
 * time FHINDEX [12] toggles. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUOG_FRI      (3)
#define BM_USBC__USBSTSUOG_FRI      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_FRI(v)   ((((reg32_t) v) << 3) & BM_USBC__USBSTSUOG_FRI)
#else
#define BF_USBC__USBSTSUOG_FRI(v)   (((v) << 3) & BM_USBC__USBSTSUOG_FRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRI field to a new value.
#define BW_USBC__USBSTSUOG_FRI(v)   BF_CS1(USBC__USBSTSUOG, FRI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field SEI[4:4] (RW)
 *
 * System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on
 * the system interface.
 */

#define BP_USBC__USBSTSUOG_SEI      (4)
#define BM_USBC__USBSTSUOG_SEI      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_SEI(v)   ((((reg32_t) v) << 4) & BM_USBC__USBSTSUOG_SEI)
#else
#define BF_USBC__USBSTSUOG_SEI(v)   (((v) << 4) & BM_USBC__USBSTSUOG_SEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEI field to a new value.
#define BW_USBC__USBSTSUOG_SEI(v)   BF_CS1(USBC__USBSTSUOG, SEI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field AAI[5:5] (RW)
 *
 * Interrupt on Async Advance - R/WC. System software can force the host controller to issue an
 * interrupt the next time the host controller advances the asynchronous schedule by writing a one
 * to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit
 * indicates the assertion of that interrupt source. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUOG_AAI      (5)
#define BM_USBC__USBSTSUOG_AAI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_AAI(v)   ((((reg32_t) v) << 5) & BM_USBC__USBSTSUOG_AAI)
#else
#define BF_USBC__USBSTSUOG_AAI(v)   (((v) << 5) & BM_USBC__USBSTSUOG_AAI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAI field to a new value.
#define BW_USBC__USBSTSUOG_AAI(v)   BF_CS1(USBC__USBSTSUOG, AAI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field URI[6:6] (RW)
 *
 * USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default
 * state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset
 * Received status bit. Only used in device operation mode.
 */

#define BP_USBC__USBSTSUOG_URI      (6)
#define BM_USBC__USBSTSUOG_URI      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_URI(v)   ((((reg32_t) v) << 6) & BM_USBC__USBSTSUOG_URI)
#else
#define BF_USBC__USBSTSUOG_URI(v)   (((v) << 6) & BM_USBC__USBSTSUOG_URI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URI field to a new value.
#define BW_USBC__USBSTSUOG_URI(v)   BF_CS1(USBC__USBSTSUOG, URI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field SRI[7:7] (RW)
 *
 * SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will
 * be set to a one. When a SOF is extremely late, the device controller will automatically set this
 * bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in
 * device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is
 * received. Because the device controller is initialized to FS before connect, this bit will be set
 * at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set
 * every 125us and can be used by host controller driver as a time base. Software writes a 1 to this
 * bit to clear it.
 */

#define BP_USBC__USBSTSUOG_SRI      (7)
#define BM_USBC__USBSTSUOG_SRI      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_SRI(v)   ((((reg32_t) v) << 7) & BM_USBC__USBSTSUOG_SRI)
#else
#define BF_USBC__USBSTSUOG_SRI(v)   (((v) << 7) & BM_USBC__USBSTSUOG_SRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRI field to a new value.
#define BW_USBC__USBSTSUOG_SRI(v)   BF_CS1(USBC__USBSTSUOG, SRI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field SLI[8:8] (RW)
 *
 * DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be
 * set to a one. The device controller clears the bit upon exiting from a suspend state. Only used
 * in device operation mode.
 */

#define BP_USBC__USBSTSUOG_SLI      (8)
#define BM_USBC__USBSTSUOG_SLI      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_SLI(v)   ((((reg32_t) v) << 8) & BM_USBC__USBSTSUOG_SLI)
#else
#define BF_USBC__USBSTSUOG_SLI(v)   (((v) << 8) & BM_USBC__USBSTSUOG_SLI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLI field to a new value.
#define BW_USBC__USBSTSUOG_SLI(v)   BF_CS1(USBC__USBSTSUOG, SLI, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field ULPII[10:10] (RW)
 *
 * ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in
 * ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
 */

#define BP_USBC__USBSTSUOG_ULPII      (10)
#define BM_USBC__USBSTSUOG_ULPII      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_ULPII(v)   ((((reg32_t) v) << 10) & BM_USBC__USBSTSUOG_ULPII)
#else
#define BF_USBC__USBSTSUOG_ULPII(v)   (((v) << 10) & BM_USBC__USBSTSUOG_ULPII)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPII field to a new value.
#define BW_USBC__USBSTSUOG_ULPII(v)   BF_CS1(USBC__USBSTSUOG, ULPII, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field HCH[12:12] (RW)
 *
 * HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets
 * this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either
 * by software or by the Controller hardware (for example, an internal error). Only used in the host
 * operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is
 * because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
 */

#define BP_USBC__USBSTSUOG_HCH      (12)
#define BM_USBC__USBSTSUOG_HCH      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_HCH(v)   ((((reg32_t) v) << 12) & BM_USBC__USBSTSUOG_HCH)
#else
#define BF_USBC__USBSTSUOG_HCH(v)   (((v) << 12) & BM_USBC__USBSTSUOG_HCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCH field to a new value.
#define BW_USBC__USBSTSUOG_HCH(v)   BF_CS1(USBC__USBSTSUOG, HCH, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field RCL[13:13] (RW)
 *
 * Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous
 * schedule. Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUOG_RCL      (13)
#define BM_USBC__USBSTSUOG_RCL      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_RCL(v)   ((((reg32_t) v) << 13) & BM_USBC__USBSTSUOG_RCL)
#else
#define BF_USBC__USBSTSUOG_RCL(v)   (((v) << 13) & BM_USBC__USBSTSUOG_RCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCL field to a new value.
#define BW_USBC__USBSTSUOG_RCL(v)   BF_CS1(USBC__USBSTSUOG, RCL, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field PS[14:14] (RW)
 *
 * Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic
 * Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is
 * enabled. The Host Controller is not required to immediately disable or enable the Periodic
 * Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When
 * this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either
 * enabled (1) or disabled (0). Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUOG_PS      (14)
#define BM_USBC__USBSTSUOG_PS      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_PS(v)   ((((reg32_t) v) << 14) & BM_USBC__USBSTSUOG_PS)
#else
#define BF_USBC__USBSTSUOG_PS(v)   (((v) << 14) & BM_USBC__USBSTSUOG_PS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PS field to a new value.
#define BW_USBC__USBSTSUOG_PS(v)   BF_CS1(USBC__USBSTSUOG, PS, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field AS[15:15] (RW)
 *
 * Asynchronous Schedule Status - Read Only. This bit reports the current real status of the
 * Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set
 * to one the status is enabled. The Host Controller is not required to immediately disable or
 * enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit
 * in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same
 * value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host
 * operation mode.
 */

#define BP_USBC__USBSTSUOG_AS      (15)
#define BM_USBC__USBSTSUOG_AS      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_AS(v)   ((((reg32_t) v) << 15) & BM_USBC__USBSTSUOG_AS)
#else
#define BF_USBC__USBSTSUOG_AS(v)   (((v) << 15) & BM_USBC__USBSTSUOG_AS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AS field to a new value.
#define BW_USBC__USBSTSUOG_AS(v)   BF_CS1(USBC__USBSTSUOG, AS, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field NAKI[16:16] (RO)
 *
 * NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX
 * Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is
 * automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
 */

#define BP_USBC__USBSTSUOG_NAKI      (16)
#define BM_USBC__USBSTSUOG_NAKI      (0x00010000)

/* --- Register HW_USBC__USBSTSUOG, field TI0[24:24] (RW)
 *
 * General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the
 * GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
 */

#define BP_USBC__USBSTSUOG_TI0      (24)
#define BM_USBC__USBSTSUOG_TI0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_TI0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBSTSUOG_TI0)
#else
#define BF_USBC__USBSTSUOG_TI0(v)   (((v) << 24) & BM_USBC__USBSTSUOG_TI0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI0 field to a new value.
#define BW_USBC__USBSTSUOG_TI0(v)   BF_CS1(USBC__USBSTSUOG, TI0, v)
#endif

/* --- Register HW_USBC__USBSTSUOG, field TI1[25:25] (RW)
 *
 * General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the
 * GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
 */

#define BP_USBC__USBSTSUOG_TI1      (25)
#define BM_USBC__USBSTSUOG_TI1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUOG_TI1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBSTSUOG_TI1)
#else
#define BF_USBC__USBSTSUOG_TI1(v)   (((v) << 25) & BM_USBC__USBSTSUOG_TI1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI1 field to a new value.
#define BW_USBC__USBSTSUOG_TI1(v)   BF_CS1(USBC__USBSTSUOG, TI1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBINTRUOG - Interrupt Enable Register UOG (RW)
 *
 * The interrupts to software are enabled with this register. An interrupt is generated when a bit
 * is set and the corresponding interrupt source is active. The USB Status register (n_USBSTS) still
 * shows interrupt sources even if they are disabled by the n_USBINTR register, allowing polling of
 * interrupt events by the software.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UE : 1; //!< USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned UEE : 1; //!< USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned PCE : 1; //!< Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned FRE : 1; //!< Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned SEE : 1; //!< System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned AAE : 1; //!< Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned URE : 1; //!< USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned SRE : 1; //!< SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned SLE : 1; //!< Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPIE : 1; //!< ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the controller will issue an interrupt. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 5; //!< These bits are reserved and should be set to zero.
        unsigned NAKE : 1; //!< NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned UAIE : 1; //!< USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned UPIE : 1; //!< USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned RESERVED3 : 4; //!< Reserved
        unsigned TIE0 : 1; //!< General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned TIE1 : 1; //!< General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED4 : 6; //!< Reserved
    } B;
} hw_usbc__usbintruog_t;
#endif

/*
 * constants & macros for entire USBC__USBINTRUOG register
 */
#define HW_USBC__USBINTRUOG_ADDR      (REGS_USBC_BASE + 0x148)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBINTRUOG           (*(volatile hw_usbc__usbintruog_t *) HW_USBC__USBINTRUOG_ADDR)
#define HW_USBC__USBINTRUOG_RD()      (HW_USBC__USBINTRUOG.U)
#define HW_USBC__USBINTRUOG_WR(v)     (HW_USBC__USBINTRUOG.U = (v))
#define HW_USBC__USBINTRUOG_SET(v)    (HW_USBC__USBINTRUOG_WR(HW_USBC__USBINTRUOG_RD() |  (v)))
#define HW_USBC__USBINTRUOG_CLR(v)    (HW_USBC__USBINTRUOG_WR(HW_USBC__USBINTRUOG_RD() & ~(v)))
#define HW_USBC__USBINTRUOG_TOG(v)    (HW_USBC__USBINTRUOG_WR(HW_USBC__USBINTRUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBINTRUOG bitfields
 */

/* --- Register HW_USBC__USBINTRUOG, field UE[0:0] (RW)
 *
 * USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_UE      (0)
#define BM_USBC__USBINTRUOG_UE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_UE(v)   ((((reg32_t) v) << 0) & BM_USBC__USBINTRUOG_UE)
#else
#define BF_USBC__USBINTRUOG_UE(v)   (((v) << 0) & BM_USBC__USBINTRUOG_UE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UE field to a new value.
#define BW_USBC__USBINTRUOG_UE(v)   BF_CS1(USBC__USBINTRUOG, UE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field UEE[1:1] (RW)
 *
 * USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_UEE      (1)
#define BM_USBC__USBINTRUOG_UEE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_UEE(v)   ((((reg32_t) v) << 1) & BM_USBC__USBINTRUOG_UEE)
#else
#define BF_USBC__USBINTRUOG_UEE(v)   (((v) << 1) & BM_USBC__USBINTRUOG_UEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEE field to a new value.
#define BW_USBC__USBINTRUOG_UEE(v)   BF_CS1(USBC__USBINTRUOG, UEE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field PCE[2:2] (RW)
 *
 * Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is
 * a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_PCE      (2)
#define BM_USBC__USBINTRUOG_PCE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_PCE(v)   ((((reg32_t) v) << 2) & BM_USBC__USBINTRUOG_PCE)
#else
#define BF_USBC__USBINTRUOG_PCE(v)   (((v) << 2) & BM_USBC__USBINTRUOG_PCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCE field to a new value.
#define BW_USBC__USBINTRUOG_PCE(v)   BF_CS1(USBC__USBINTRUOG, PCE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field FRE[3:3] (RW)
 *
 * Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is
 * a one the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUOG_FRE      (3)
#define BM_USBC__USBINTRUOG_FRE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_FRE(v)   ((((reg32_t) v) << 3) & BM_USBC__USBINTRUOG_FRE)
#else
#define BF_USBC__USBINTRUOG_FRE(v)   (((v) << 3) & BM_USBC__USBINTRUOG_FRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRE field to a new value.
#define BW_USBC__USBINTRUOG_FRE(v)   BF_CS1(USBC__USBINTRUOG, FRE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field SEE[4:4] (RW)
 *
 * System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUOG_SEE      (4)
#define BM_USBC__USBINTRUOG_SEE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_SEE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBINTRUOG_SEE)
#else
#define BF_USBC__USBINTRUOG_SEE(v)   (((v) << 4) & BM_USBC__USBINTRUOG_SEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEE field to a new value.
#define BW_USBC__USBINTRUOG_SEE(v)   BF_CS1(USBC__USBINTRUOG, SEE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field AAE[5:5] (RW)
 *
 * Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUOG_AAE      (5)
#define BM_USBC__USBINTRUOG_AAE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_AAE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBINTRUOG_AAE)
#else
#define BF_USBC__USBINTRUOG_AAE(v)   (((v) << 5) & BM_USBC__USBINTRUOG_AAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAE field to a new value.
#define BW_USBC__USBINTRUOG_AAE(v)   BF_CS1(USBC__USBINTRUOG, AAE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field URE[6:6] (RW)
 *
 * USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one
 * the controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUOG_URE      (6)
#define BM_USBC__USBINTRUOG_URE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_URE(v)   ((((reg32_t) v) << 6) & BM_USBC__USBINTRUOG_URE)
#else
#define BF_USBC__USBINTRUOG_URE(v)   (((v) << 6) & BM_USBC__USBINTRUOG_URE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URE field to a new value.
#define BW_USBC__USBINTRUOG_URE(v)   BF_CS1(USBC__USBINTRUOG, URE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field SRE[7:7] (RW)
 *
 * SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one
 * the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_SRE      (7)
#define BM_USBC__USBINTRUOG_SRE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_SRE(v)   ((((reg32_t) v) << 7) & BM_USBC__USBINTRUOG_SRE)
#else
#define BF_USBC__USBINTRUOG_SRE(v)   (((v) << 7) & BM_USBC__USBINTRUOG_SRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRE field to a new value.
#define BW_USBC__USBINTRUOG_SRE(v)   BF_CS1(USBC__USBINTRUOG, SRE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field SLE[8:8] (RW)
 *
 * Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the
 * controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUOG_SLE      (8)
#define BM_USBC__USBINTRUOG_SLE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_SLE(v)   ((((reg32_t) v) << 8) & BM_USBC__USBINTRUOG_SLE)
#else
#define BF_USBC__USBINTRUOG_SLE(v)   (((v) << 8) & BM_USBC__USBINTRUOG_SLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLE field to a new value.
#define BW_USBC__USBINTRUOG_SLE(v)   BF_CS1(USBC__USBINTRUOG, SLE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field ULPIE[10:10] (RW)
 *
 * ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the
 * controller will issue an interrupt. This bit is usable only if the controller support UPLI
 * interface mode.
 */

#define BP_USBC__USBINTRUOG_ULPIE      (10)
#define BM_USBC__USBINTRUOG_ULPIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_ULPIE(v)   ((((reg32_t) v) << 10) & BM_USBC__USBINTRUOG_ULPIE)
#else
#define BF_USBC__USBINTRUOG_ULPIE(v)   (((v) << 10) & BM_USBC__USBINTRUOG_ULPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPIE field to a new value.
#define BW_USBC__USBINTRUOG_ULPIE(v)   BF_CS1(USBC__USBINTRUOG, ULPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field NAKE[16:16] (RW)
 *
 * NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_NAKE      (16)
#define BM_USBC__USBINTRUOG_NAKE      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_NAKE(v)   ((((reg32_t) v) << 16) & BM_USBC__USBINTRUOG_NAKE)
#else
#define BF_USBC__USBINTRUOG_NAKE(v)   (((v) << 16) & BM_USBC__USBINTRUOG_NAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NAKE field to a new value.
#define BW_USBC__USBINTRUOG_NAKE(v)   BF_CS1(USBC__USBINTRUOG, NAKE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field UAIE[18:18] (RW)
 *
 * USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS
 * register is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUOG_UAIE      (18)
#define BM_USBC__USBINTRUOG_UAIE      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_UAIE(v)   ((((reg32_t) v) << 18) & BM_USBC__USBINTRUOG_UAIE)
#else
#define BF_USBC__USBINTRUOG_UAIE(v)   (((v) << 18) & BM_USBC__USBINTRUOG_UAIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UAIE field to a new value.
#define BW_USBC__USBINTRUOG_UAIE(v)   BF_CS1(USBC__USBINTRUOG, UAIE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field UPIE[19:19] (RW)
 *
 * USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register
 * is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUOG_UPIE      (19)
#define BM_USBC__USBINTRUOG_UPIE      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_UPIE(v)   ((((reg32_t) v) << 19) & BM_USBC__USBINTRUOG_UPIE)
#else
#define BF_USBC__USBINTRUOG_UPIE(v)   (((v) << 19) & BM_USBC__USBINTRUOG_UPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UPIE field to a new value.
#define BW_USBC__USBINTRUOG_UPIE(v)   BF_CS1(USBC__USBINTRUOG, UPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field TIE0[24:24] (RW)
 *
 * General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_TIE0      (24)
#define BM_USBC__USBINTRUOG_TIE0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_TIE0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBINTRUOG_TIE0)
#else
#define BF_USBC__USBINTRUOG_TIE0(v)   (((v) << 24) & BM_USBC__USBINTRUOG_TIE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE0 field to a new value.
#define BW_USBC__USBINTRUOG_TIE0(v)   BF_CS1(USBC__USBINTRUOG, TIE0, v)
#endif

/* --- Register HW_USBC__USBINTRUOG, field TIE1[25:25] (RW)
 *
 * General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUOG_TIE1      (25)
#define BM_USBC__USBINTRUOG_TIE1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUOG_TIE1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBINTRUOG_TIE1)
#else
#define BF_USBC__USBINTRUOG_TIE1(v)   (((v) << 25) & BM_USBC__USBINTRUOG_TIE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE1 field to a new value.
#define BW_USBC__USBINTRUOG_TIE1(v)   BF_CS1(USBC__USBINTRUOG, TIE1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__FRINDEXUOG - USB Frame Index UOG (RW)
 *
 * This register is used by the host controller to index the periodic frame list. The register
 * updates every 125 microseconds (once each micro-frame). Bits [N: 3] are used to select a
 * particular entry in the Periodic Frame List during periodic schedule execution. The number of
 * bits used for the index depends on the size of the frame list as set by system software in the
 * Frame List Size field in the n_USBCMD register.  This register must be written as a DWord. Byte
 * writes produce-undefined results. This register cannot be written unless the Host Controller is
 * in the 'Halted' state as indicated by the HCHalted bit. A write to this register while the
 * Run/Stop hit is set to a one produces undefined results. Writes to this register also affect the
 * SOF value.  In device mode this register is read only and, the device controller updates the
 * FRINDEX [13:3] register from the frame number indicated by the SOF marker. Whenever a SOF is
 * received by the USB bus, FRINDEX [13:3] will be checked against the SOF marker. If FRINDEX [13:3]
 * is different from the SOF marker, FRINDEX [13:3] will be set to the SOF value and FRINDEX [2:0]
 * will be set to zero (that is, SOF for 1 ms frame). If FRINDEX [13:3] is equal to the SOF value,
 * FRINDEX [2:0] will be increment (that is, SOF for 125 us micro-frame.).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FRINDEX : 14; //!< Frame Index. The value, in this register, increments at the end of each time frame (micro-frame). Bits [N: 3] are used for the Frame List current index. This means that each location of the frame list is accessed 8 times (frames or micro-frames) before moving to the next index. The following illustrates values of N based on the value of the Frame List Size field in the USBCMD register, when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is the current frame number of the last frame transmitted. It is not used as an index. In either mode bits 2:0 indicate the current microframe.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_usbc__frindexuog_t;
#endif

/*
 * constants & macros for entire USBC__FRINDEXUOG register
 */
#define HW_USBC__FRINDEXUOG_ADDR      (REGS_USBC_BASE + 0x14c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__FRINDEXUOG           (*(volatile hw_usbc__frindexuog_t *) HW_USBC__FRINDEXUOG_ADDR)
#define HW_USBC__FRINDEXUOG_RD()      (HW_USBC__FRINDEXUOG.U)
#define HW_USBC__FRINDEXUOG_WR(v)     (HW_USBC__FRINDEXUOG.U = (v))
#define HW_USBC__FRINDEXUOG_SET(v)    (HW_USBC__FRINDEXUOG_WR(HW_USBC__FRINDEXUOG_RD() |  (v)))
#define HW_USBC__FRINDEXUOG_CLR(v)    (HW_USBC__FRINDEXUOG_WR(HW_USBC__FRINDEXUOG_RD() & ~(v)))
#define HW_USBC__FRINDEXUOG_TOG(v)    (HW_USBC__FRINDEXUOG_WR(HW_USBC__FRINDEXUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__FRINDEXUOG bitfields
 */

/* --- Register HW_USBC__FRINDEXUOG, field FRINDEX[13:0] (RW)
 *
 * Frame Index. The value, in this register, increments at the end of each time frame (micro-frame).
 * Bits [N: 3] are used for the Frame List current index. This means that each location of the frame
 * list is accessed 8 times (frames or micro-frames) before moving to the next index. The following
 * illustrates values of N based on the value of the Frame List Size field in the USBCMD register,
 * when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is
 * the current frame number of the last frame transmitted. It is not used as an index. In either
 * mode bits 2:0 indicate the current microframe.
 *
 * Values:
 * 000 - (1024) 12
 * 001 - (512) 11
 * 010 - (256) 10
 * 011 - (128) 9
 * 100 - (64) 8
 * 101 - (32) 7
 * 110 - (16) 6
 * 111 - (8) 5
 */

#define BP_USBC__FRINDEXUOG_FRINDEX      (0)
#define BM_USBC__FRINDEXUOG_FRINDEX      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__FRINDEXUOG_FRINDEX(v)   ((((reg32_t) v) << 0) & BM_USBC__FRINDEXUOG_FRINDEX)
#else
#define BF_USBC__FRINDEXUOG_FRINDEX(v)   (((v) << 0) & BM_USBC__FRINDEXUOG_FRINDEX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRINDEX field to a new value.
#define BW_USBC__FRINDEXUOG_FRINDEX(v)   BF_CS1(USBC__FRINDEXUOG, FRINDEX, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PERIODICLISTBASEUOG - Frame List Base Address UOG (RW)
 *
 * Host Controller only  This 32-bit register contains the beginning address of the Periodic Frame
 * List in the system memory. HCD loads this register prior to starting the schedule execution by
 * the Host Controller. The memory structure referenced by this physical memory pointer is assumed
 * to be 4-Kbyte aligned. The contents of this register are combined with the Frame Index Register
 * (UOG_FRINDEX) to enable the Host Controller to step through the Periodic Frame List in sequence.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 12; //!< Reserved
        unsigned BASEADR : 20; //!< Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only used by the host controller.
    } B;
} hw_usbc__periodiclistbaseuog_t;
#endif

/*
 * constants & macros for entire USBC__PERIODICLISTBASEUOG register
 */
#define HW_USBC__PERIODICLISTBASEUOG_ADDR      (REGS_USBC_BASE + 0x154)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PERIODICLISTBASEUOG           (*(volatile hw_usbc__periodiclistbaseuog_t *) HW_USBC__PERIODICLISTBASEUOG_ADDR)
#define HW_USBC__PERIODICLISTBASEUOG_RD()      (HW_USBC__PERIODICLISTBASEUOG.U)
#define HW_USBC__PERIODICLISTBASEUOG_WR(v)     (HW_USBC__PERIODICLISTBASEUOG.U = (v))
#define HW_USBC__PERIODICLISTBASEUOG_SET(v)    (HW_USBC__PERIODICLISTBASEUOG_WR(HW_USBC__PERIODICLISTBASEUOG_RD() |  (v)))
#define HW_USBC__PERIODICLISTBASEUOG_CLR(v)    (HW_USBC__PERIODICLISTBASEUOG_WR(HW_USBC__PERIODICLISTBASEUOG_RD() & ~(v)))
#define HW_USBC__PERIODICLISTBASEUOG_TOG(v)    (HW_USBC__PERIODICLISTBASEUOG_WR(HW_USBC__PERIODICLISTBASEUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PERIODICLISTBASEUOG bitfields
 */

/* --- Register HW_USBC__PERIODICLISTBASEUOG, field BASEADR[31:12] (RW)
 *
 * Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only
 * used by the host controller.
 */

#define BP_USBC__PERIODICLISTBASEUOG_BASEADR      (12)
#define BM_USBC__PERIODICLISTBASEUOG_BASEADR      (0xfffff000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PERIODICLISTBASEUOG_BASEADR(v)   ((((reg32_t) v) << 12) & BM_USBC__PERIODICLISTBASEUOG_BASEADR)
#else
#define BF_USBC__PERIODICLISTBASEUOG_BASEADR(v)   (((v) << 12) & BM_USBC__PERIODICLISTBASEUOG_BASEADR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASEADR field to a new value.
#define BW_USBC__PERIODICLISTBASEUOG_BASEADR(v)   BF_CS1(USBC__PERIODICLISTBASEUOG, BASEADR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__ASYNCLISTADDRUOG - Next Asynch. Address UOG (RW)
 *
 * Host Controller only  This 32-bit register contains the address of the next asynchronous queue
 * head to be executed by the host. Bits [4:0] of this register cannot be modified by the system
 * software and will always return a zero when read.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned ASYBASE : 27; //!< Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively. This field may only reference a Queue Head (QH). Only used by the host controller.
    } B;
} hw_usbc__asynclistaddruog_t;
#endif

/*
 * constants & macros for entire USBC__ASYNCLISTADDRUOG register
 */
#define HW_USBC__ASYNCLISTADDRUOG_ADDR      (REGS_USBC_BASE + 0x158)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__ASYNCLISTADDRUOG           (*(volatile hw_usbc__asynclistaddruog_t *) HW_USBC__ASYNCLISTADDRUOG_ADDR)
#define HW_USBC__ASYNCLISTADDRUOG_RD()      (HW_USBC__ASYNCLISTADDRUOG.U)
#define HW_USBC__ASYNCLISTADDRUOG_WR(v)     (HW_USBC__ASYNCLISTADDRUOG.U = (v))
#define HW_USBC__ASYNCLISTADDRUOG_SET(v)    (HW_USBC__ASYNCLISTADDRUOG_WR(HW_USBC__ASYNCLISTADDRUOG_RD() |  (v)))
#define HW_USBC__ASYNCLISTADDRUOG_CLR(v)    (HW_USBC__ASYNCLISTADDRUOG_WR(HW_USBC__ASYNCLISTADDRUOG_RD() & ~(v)))
#define HW_USBC__ASYNCLISTADDRUOG_TOG(v)    (HW_USBC__ASYNCLISTADDRUOG_WR(HW_USBC__ASYNCLISTADDRUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__ASYNCLISTADDRUOG bitfields
 */

/* --- Register HW_USBC__ASYNCLISTADDRUOG, field ASYBASE[31:5] (RW)
 *
 * Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively.
 * This field may only reference a Queue Head (QH). Only used by the host controller.
 */

#define BP_USBC__ASYNCLISTADDRUOG_ASYBASE      (5)
#define BM_USBC__ASYNCLISTADDRUOG_ASYBASE      (0xffffffe0)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ASYNCLISTADDRUOG_ASYBASE(v)   ((((reg32_t) v) << 5) & BM_USBC__ASYNCLISTADDRUOG_ASYBASE)
#else
#define BF_USBC__ASYNCLISTADDRUOG_ASYBASE(v)   (((v) << 5) & BM_USBC__ASYNCLISTADDRUOG_ASYBASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASYBASE field to a new value.
#define BW_USBC__ASYNCLISTADDRUOG_ASYBASE(v)   BF_CS1(USBC__ASYNCLISTADDRUOG, ASYBASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__BURSTSIZEUOG - Programmable Burst Size UOG (RW)
 *
 * This register is used to control the burst size used during data movement on the AHB master
 * interface. This register is ignored if AHBBRST bits in SBUSCFG register is non-zero value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXPBURST : 8; //!< Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from the USB bus to system memory.
        unsigned TXPBURST : 9; //!< Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from system memory to the USB bus.
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_usbc__burstsizeuog_t;
#endif

/*
 * constants & macros for entire USBC__BURSTSIZEUOG register
 */
#define HW_USBC__BURSTSIZEUOG_ADDR      (REGS_USBC_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__BURSTSIZEUOG           (*(volatile hw_usbc__burstsizeuog_t *) HW_USBC__BURSTSIZEUOG_ADDR)
#define HW_USBC__BURSTSIZEUOG_RD()      (HW_USBC__BURSTSIZEUOG.U)
#define HW_USBC__BURSTSIZEUOG_WR(v)     (HW_USBC__BURSTSIZEUOG.U = (v))
#define HW_USBC__BURSTSIZEUOG_SET(v)    (HW_USBC__BURSTSIZEUOG_WR(HW_USBC__BURSTSIZEUOG_RD() |  (v)))
#define HW_USBC__BURSTSIZEUOG_CLR(v)    (HW_USBC__BURSTSIZEUOG_WR(HW_USBC__BURSTSIZEUOG_RD() & ~(v)))
#define HW_USBC__BURSTSIZEUOG_TOG(v)    (HW_USBC__BURSTSIZEUOG_WR(HW_USBC__BURSTSIZEUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__BURSTSIZEUOG bitfields
 */

/* --- Register HW_USBC__BURSTSIZEUOG, field RXPBURST[7:0] (RW)
 *
 * Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from the
 * USB bus to system memory.
 */

#define BP_USBC__BURSTSIZEUOG_RXPBURST      (0)
#define BM_USBC__BURSTSIZEUOG_RXPBURST      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUOG_RXPBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__BURSTSIZEUOG_RXPBURST)
#else
#define BF_USBC__BURSTSIZEUOG_RXPBURST(v)   (((v) << 0) & BM_USBC__BURSTSIZEUOG_RXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUOG_RXPBURST(v)   BF_CS1(USBC__BURSTSIZEUOG, RXPBURST, v)
#endif

/* --- Register HW_USBC__BURSTSIZEUOG, field TXPBURST[16:8] (RW)
 *
 * Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from
 * system memory to the USB bus.
 */

#define BP_USBC__BURSTSIZEUOG_TXPBURST      (8)
#define BM_USBC__BURSTSIZEUOG_TXPBURST      (0x0001ff00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUOG_TXPBURST(v)   ((((reg32_t) v) << 8) & BM_USBC__BURSTSIZEUOG_TXPBURST)
#else
#define BF_USBC__BURSTSIZEUOG_TXPBURST(v)   (((v) << 8) & BM_USBC__BURSTSIZEUOG_TXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUOG_TXPBURST(v)   BF_CS1(USBC__BURSTSIZEUOG, TXPBURST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__TXFILLTUNINGUOG - TX FIFO Fill Tuning UOG (RW)
 *
 * The fields in this register control performance tuning associated with how the host controller
 * posts data to the TX latency FIFO before moving the data onto the USB bus. The specific areas of
 * performance include the how much data to post into the FIFO and an estimate for how long that
 * operation should take in the target system.  Definitions:  T 0 = Standard packet overhead  T 1 =
 * Time to send data payload  T ff = Time to fetch packet into TX FIFO up to specified level.  T s =
 * Total Packet Flight Time (send-only) packet  T s = T 0 + T 1   T p = Total Packet Time (fetch and
 * send) packet  T p = T ff + T 0 + T 1   Upon discovery of a transmit (OUT/SETUP) packet in the
 * data structures, host controller checks to ensure T  p  remains before the end of the
 * [micro]frame. If so it proceeds to pre-fill the TX FIFO. If at anytime during the pre-fill
 * operation the time remaining the [micro]frame is < T  s  then the packet attempt ceases and the
 * packet is tried at a later time. Although this is not an error condition and the host controller
 * will eventually recover, a mark will be made the scheduler health counter to note the occurrence
 * of a "back-off" event. When a back-off event is detected, the partial packet fetched may need to
 * be discarded from the latency buffer to make room for periodic traffic that will begin after the
 * next SOF. Too many back-off events can waste bandwidth and power on the system bus and thus
 * should be minimized (not necessarily eliminated). Back-offs can be minimized with use of the
 * n_TSCHHEALTH ( T  ff ) described below.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXSCHOH : 8; //!< Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to the schedule time estimator described above as Tff. As an approximation, the value chosen for this register should limit the number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a highly utilized bus. Choosing a value that is too high for this register is not desired as it can needlessly reduce USB utilization. The time unit represented in this register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned TXSCHHEALTH : 5; //!< Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of time to send the packet before the next Start-Of-Frame. This health counter measures the number of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the counter and this counter will max. at 31. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXFIFOTHRES : 6; //!< FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum value is 2 and this value should be a low as possible to maximize USB performance. A higher value can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO may underrun because the data transferred from the latency FIFO to USB occurs before it can be replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED1 : 10; //!< Reserved
    } B;
} hw_usbc__txfilltuninguog_t;
#endif

/*
 * constants & macros for entire USBC__TXFILLTUNINGUOG register
 */
#define HW_USBC__TXFILLTUNINGUOG_ADDR      (REGS_USBC_BASE + 0x164)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__TXFILLTUNINGUOG           (*(volatile hw_usbc__txfilltuninguog_t *) HW_USBC__TXFILLTUNINGUOG_ADDR)
#define HW_USBC__TXFILLTUNINGUOG_RD()      (HW_USBC__TXFILLTUNINGUOG.U)
#define HW_USBC__TXFILLTUNINGUOG_WR(v)     (HW_USBC__TXFILLTUNINGUOG.U = (v))
#define HW_USBC__TXFILLTUNINGUOG_SET(v)    (HW_USBC__TXFILLTUNINGUOG_WR(HW_USBC__TXFILLTUNINGUOG_RD() |  (v)))
#define HW_USBC__TXFILLTUNINGUOG_CLR(v)    (HW_USBC__TXFILLTUNINGUOG_WR(HW_USBC__TXFILLTUNINGUOG_RD() & ~(v)))
#define HW_USBC__TXFILLTUNINGUOG_TOG(v)    (HW_USBC__TXFILLTUNINGUOG_WR(HW_USBC__TXFILLTUNINGUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__TXFILLTUNINGUOG bitfields
 */

/* --- Register HW_USBC__TXFILLTUNINGUOG, field TXSCHOH[7:0] (RW)
 *
 * Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to
 * the schedule time estimator described above as Tff. As an approximation, the value chosen for
 * this register should limit the number of back-off events captured in the TXSCHHEALTH to less than
 * 10 per second in a highly utilized bus. Choosing a value that is too high for this register is
 * not desired as it can needlessly reduce USB utilization. The time unit represented in this
 * register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in
 * this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is
 * '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUOG_TXSCHOH      (0)
#define BM_USBC__TXFILLTUNINGUOG_TXSCHOH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUOG_TXSCHOH(v)   ((((reg32_t) v) << 0) & BM_USBC__TXFILLTUNINGUOG_TXSCHOH)
#else
#define BF_USBC__TXFILLTUNINGUOG_TXSCHOH(v)   (((v) << 0) & BM_USBC__TXFILLTUNINGUOG_TXSCHOH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHOH field to a new value.
#define BW_USBC__TXFILLTUNINGUOG_TXSCHOH(v)   BF_CS1(USBC__TXFILLTUNINGUOG, TXSCHOH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUOG, field TXSCHHEALTH[12:8] (RW)
 *
 * Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller
 * fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of
 * time to send the packet before the next Start-Of-Frame. This health counter measures the number
 * of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register
 * will clear the counter and this counter will max. at 31. Default value is '08h' for OTG
 * controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUOG_TXSCHHEALTH      (8)
#define BM_USBC__TXFILLTUNINGUOG_TXSCHHEALTH      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUOG_TXSCHHEALTH(v)   ((((reg32_t) v) << 8) & BM_USBC__TXFILLTUNINGUOG_TXSCHHEALTH)
#else
#define BF_USBC__TXFILLTUNINGUOG_TXSCHHEALTH(v)   (((v) << 8) & BM_USBC__TXFILLTUNINGUOG_TXSCHHEALTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHHEALTH field to a new value.
#define BW_USBC__TXFILLTUNINGUOG_TXSCHHEALTH(v)   BF_CS1(USBC__TXFILLTUNINGUOG, TXSCHHEALTH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUOG, field TXFIFOTHRES[21:16] (RW)
 *
 * FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are
 * posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum
 * value is 2 and this value should be a low as possible to maximize USB performance. A higher value
 * can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO
 * may underrun because the data transferred from the latency FIFO to USB occurs before it can be
 * replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE
 * register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3
 * controller core.
 */

#define BP_USBC__TXFILLTUNINGUOG_TXFIFOTHRES      (16)
#define BM_USBC__TXFILLTUNINGUOG_TXFIFOTHRES      (0x003f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUOG_TXFIFOTHRES(v)   ((((reg32_t) v) << 16) & BM_USBC__TXFILLTUNINGUOG_TXFIFOTHRES)
#else
#define BF_USBC__TXFILLTUNINGUOG_TXFIFOTHRES(v)   (((v) << 16) & BM_USBC__TXFILLTUNINGUOG_TXFIFOTHRES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFOTHRES field to a new value.
#define BW_USBC__TXFILLTUNINGUOG_TXFIFOTHRES(v)   BF_CS1(USBC__TXFILLTUNINGUOG, TXFIFOTHRES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IC_USBUOG - IC_USB enable and voltage negotiation UOG (RW)
 *
 * This register enable and controls the IC-USB FS/LS transceiver.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IC_VDD1 : 3; //!< These bits indicates which voltage is being supplied to the peripheral This field is read-only and set to 000 in case of a device controller.
        unsigned IC1 : 1; //!< Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1 is enabled, IOMUX must set the DP/DM pad into loopback mode.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__ic_usbuog_t;
#endif

/*
 * constants & macros for entire USBC__IC_USBUOG register
 */
#define HW_USBC__IC_USBUOG_ADDR      (REGS_USBC_BASE + 0x16c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IC_USBUOG           (*(volatile hw_usbc__ic_usbuog_t *) HW_USBC__IC_USBUOG_ADDR)
#define HW_USBC__IC_USBUOG_RD()      (HW_USBC__IC_USBUOG.U)
#define HW_USBC__IC_USBUOG_WR(v)     (HW_USBC__IC_USBUOG.U = (v))
#define HW_USBC__IC_USBUOG_SET(v)    (HW_USBC__IC_USBUOG_WR(HW_USBC__IC_USBUOG_RD() |  (v)))
#define HW_USBC__IC_USBUOG_CLR(v)    (HW_USBC__IC_USBUOG_WR(HW_USBC__IC_USBUOG_RD() & ~(v)))
#define HW_USBC__IC_USBUOG_TOG(v)    (HW_USBC__IC_USBUOG_WR(HW_USBC__IC_USBUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__IC_USBUOG bitfields
 */

/* --- Register HW_USBC__IC_USBUOG, field IC_VDD1[2:0] (RW)
 *
 * These bits indicates which voltage is being supplied to the peripheral This field is read-only
 * and set to 000 in case of a device controller.
 *
 * Values:
 * 000 - No voltage
 * 001 - 1.0 V
 * 010 - 1.2 V
 * 011 - 1.5 V
 * 100 - 1.8 V
 * 101 - 3.0 V
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_USBC__IC_USBUOG_IC_VDD1      (0)
#define BM_USBC__IC_USBUOG_IC_VDD1      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUOG_IC_VDD1(v)   ((((reg32_t) v) << 0) & BM_USBC__IC_USBUOG_IC_VDD1)
#else
#define BF_USBC__IC_USBUOG_IC_VDD1(v)   (((v) << 0) & BM_USBC__IC_USBUOG_IC_VDD1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC_VDD1 field to a new value.
#define BW_USBC__IC_USBUOG_IC_VDD1(v)   BF_CS1(USBC__IC_USBUOG, IC_VDD1, v)
#endif


/* --- Register HW_USBC__IC_USBUOG, field IC1[3:3] (RW)
 *
 * Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB
 * interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1
 * is enabled, IOMUX must set the DP/DM pad into loopback mode.
 */

#define BP_USBC__IC_USBUOG_IC1      (3)
#define BM_USBC__IC_USBUOG_IC1      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUOG_IC1(v)   ((((reg32_t) v) << 3) & BM_USBC__IC_USBUOG_IC1)
#else
#define BF_USBC__IC_USBUOG_IC1(v)   (((v) << 3) & BM_USBC__IC_USBUOG_IC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC1 field to a new value.
#define BW_USBC__IC_USBUOG_IC1(v)   BF_CS1(USBC__IC_USBUOG, IC1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTNAK - Endpoint NAK (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EPRN : 8; //!< RX Endpoint NAK - R/WC. Each RX endpoint has 1 bit in this field. The bit is set when the device sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit [N] - Endpoint #[N], N is 0-7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned EPTN : 8; //!< TX Endpoint NAK - R/WC. Each TX endpoint has 1 bit in this field. The bit is set when the device sends a NAK handshake on a received IN token for the corresponding endpoint. Bit [N] - Endpoint #[N], N is 0-7
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

/* --- Register HW_USBC_UOG_ENDPTNAK, field EPRN[7:0] (RW)
 *
 * RX Endpoint NAK - R/WC. Each RX endpoint has 1 bit in this field. The bit is set when the device
 * sends a NAK handshake on a received OUT or PING token for the corresponding endpoint. Bit [N] -
 * Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAK_EPRN      (0)
#define BM_USBC_UOG_ENDPTNAK_EPRN      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAK_EPRN(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTNAK_EPRN)
#else
#define BF_USBC_UOG_ENDPTNAK_EPRN(v)   (((v) << 0) & BM_USBC_UOG_ENDPTNAK_EPRN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EPRN field to a new value.
#define BW_USBC_UOG_ENDPTNAK_EPRN(v)   BF_CS1(USBC_UOG_ENDPTNAK, EPRN, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTNAK, field EPTN[23:16] (RW)
 *
 * TX Endpoint NAK - R/WC. Each TX endpoint has 1 bit in this field. The bit is set when the device
 * sends a NAK handshake on a received IN token for the corresponding endpoint. Bit [N] - Endpoint
 * #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAK_EPTN      (16)
#define BM_USBC_UOG_ENDPTNAK_EPTN      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAK_EPTN(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTNAK_EPTN)
#else
#define BF_USBC_UOG_ENDPTNAK_EPTN(v)   (((v) << 16) & BM_USBC_UOG_ENDPTNAK_EPTN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EPTN field to a new value.
#define BW_USBC_UOG_ENDPTNAK_EPTN(v)   BF_CS1(USBC_UOG_ENDPTNAK, EPTN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTNAKEN - Endpoint Nake Enable (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EPRNE : 8; //!< RX Endpoint NAK Enable - R/W. Each bit is an enable bit for the corresponding RX Endpoint NAK bit. If this bit is set and the corresponding RX Endpoint NAK bit is set, the NAK Interrupt bit is set. Bit [N] - Endpoint #[N], N is 0-7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned EPTNE : 8; //!< TX Endpoint NAK Enable - R/W. Each bit is an enable bit for the corresponding TX Endpoint NAK bit. If this bit is set and the corresponding TX Endpoint NAK bit is set, the NAK Interrupt bit is set. Bit [N] - Endpoint #[N], N is 0-7
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

/* --- Register HW_USBC_UOG_ENDPTNAKEN, field EPRNE[7:0] (RW)
 *
 * RX Endpoint NAK Enable - R/W. Each bit is an enable bit for the corresponding RX Endpoint NAK
 * bit. If this bit is set and the corresponding RX Endpoint NAK bit is set, the NAK Interrupt bit
 * is set. Bit [N] - Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAKEN_EPRNE      (0)
#define BM_USBC_UOG_ENDPTNAKEN_EPRNE      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAKEN_EPRNE(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTNAKEN_EPRNE)
#else
#define BF_USBC_UOG_ENDPTNAKEN_EPRNE(v)   (((v) << 0) & BM_USBC_UOG_ENDPTNAKEN_EPRNE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EPRNE field to a new value.
#define BW_USBC_UOG_ENDPTNAKEN_EPRNE(v)   BF_CS1(USBC_UOG_ENDPTNAKEN, EPRNE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTNAKEN, field EPTNE[23:16] (RW)
 *
 * TX Endpoint NAK Enable - R/W. Each bit is an enable bit for the corresponding TX Endpoint NAK
 * bit. If this bit is set and the corresponding TX Endpoint NAK bit is set, the NAK Interrupt bit
 * is set. Bit [N] - Endpoint #[N], N is 0-7
 */

#define BP_USBC_UOG_ENDPTNAKEN_EPTNE      (16)
#define BM_USBC_UOG_ENDPTNAKEN_EPTNE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTNAKEN_EPTNE(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTNAKEN_EPTNE)
#else
#define BF_USBC_UOG_ENDPTNAKEN_EPTNE(v)   (((v) << 16) & BM_USBC_UOG_ENDPTNAKEN_EPTNE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EPTNE field to a new value.
#define BW_USBC_UOG_ENDPTNAKEN_EPTNE(v)   BF_CS1(USBC_UOG_ENDPTNAKEN, EPTNE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PORTSC1UOG - Port Status & Control UOG (RW)
 *
 * Host Controller  A host controller could implement one to eight port status and control
 * registers. The number is determined by N_PORTs bits in HWSPARAMs register (please see ). Software
 * could read this parameter register to determine how many ports need service.  All 4 controller
 * cores are Single-Port Host, so there is only one port status and control register for each
 * controller core.  This register is only reset by power on reset or controller core reset. The
 * initial conditions of a port are:   No device connected  Port disabled   If the port supports
 * power control, this state remains until port power is supplied (by software).  Device Controller
 * A device controller has only port register one (PORTSC1) and it does not support power control.
 * Port control in device mode is only used for status port reset, suspend, and current connect
 * status. It is also used to initiate test mode or force signaling and allows software to put the
 * PHY into low power suspend mode and disable the PHY clock.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CCS : 1; //!< Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is present. Default = 0. This value reflects the current state of the port, and may not correspond directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached. Default=0. A one indicates that the device successfully attached and is operating in either high speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates that the device did not attach successfully or was forcibly disconnected by the software writing a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or suspended.
        unsigned CSC : 1; //!< Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device controller sets this bit for all changes to the port device connect status, even if system software has not cleared an existing connect status change. For example, the insertion status changes twice before system software has cleared the changed condition, hub hardware will be 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode: This bit is undefined in device controller mode.
        unsigned PE : 1; //!< Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be enabled by the host controller as a part of the reset and enable. Software cannot enable a port by writing a one to this field. Ports can be disabled by either a fault condition (disconnect event or other fault condition) or by the host software. Note that the bit status does not change until the port state actually changes. There may be a delay in disabling or enabling a port due to other host controller and bus events. When the port is disabled, (0b) downstream propagation of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In Device Mode: The device port is always enabled, so this bit is always '1b'.
        unsigned PEC : 1; //!< Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is always '0b'.
        unsigned OCA : 1; //!< Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero when the over current condition is removed. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned OCC : 1; //!< Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to Over-current Active. Software can clear this bit by writing a one to this bit position. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned FPR : 1; //!< Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state) detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will automatically change to zero after the resume sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the resume duration is timed in the driver. Note that when the Host controller owns the port, the resume sequence follows the defined sequence documented in the USB Specification Revision 2.0. The resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no affect because the port controller will time the resume operation clear the bit the port control state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or more, software must set this bit to one to drive resume signaling before clearing. The Device Controller will set this bit to one if a J-to-K transition is detected while the port is in the Suspend state. The bit will be cleared when the device returns to normal operation. Also, when this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the USBSTS register is also set to one.
        unsigned SUSP : 1; //!< Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend When in suspend state, downstream propagation of data is blocked on this port, except for port reset. The blocking occurs at the end of the current transaction if a transaction was in progress when this bit was written to 1. In the suspend state, the port is sensitive to resume detection. Note that the bit status does not change until the port is suspended and that there may be a delay in suspending a port if there is a transaction currently in progress on the The host controller will unconditionally set this bit to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write of zero to this bit. If host software sets this bit to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only. In device mode this bit is a read only status bit.
        unsigned PR : 1; //!< Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset. 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence as defined in the USB Specification Revision 2.0 is started. This bit will automatically change to zero after the reset sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the reset duration is timed in the driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
        unsigned HSP : 1; //!< High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the port is in high-speed mode and if set to zero, the host/device connected to the port is not in a high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
        unsigned LS : 2; //!< Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D- (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not necessary (unlike EHCI), because the port controller state machine and the port routing manage the connection of LS and FS. In device mode, the use of linestate by the device controller driver is not necessary. The encoding of the bits are: Bits [11:10] Meaning
        unsigned PP : 1; //!< Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP Operation 0 1b Read Only - Host controller does not have port power control switches. Each port is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not available on a port (that is, PP equals a 0), the port is non-functional and will not report attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is a one, the PP bit in each affected port may be transitional by the host controller driver from a one to a zero (removing power from the port). This feature is implemented in all 4 controller cores (PPC = 1).
        unsigned PO : 1; //!< Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever the Configured bit is zero System software uses this field to release ownership of the port to a selected host controller (in the event that the attached device is not a high-speed device). Software writes a one to this bit when the attached device is not a high-speed device. A one in this bit means that an internal companion controller owns and controls the port. Port owner handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
        unsigned PIC : 2; //!< Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0 for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit Value Meaning
        unsigned PTC : 4; //!< Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS} values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point. Low speed operations are not supported as a peripheral device. Any other value than zero indicates that the port is operating in test mode. Value Specific Test
        unsigned WKCN : 1; //!< Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKDC : 1; //!< Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device disconnects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKOC : 1; //!< Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one enables the port to be sensitive to over-current conditions as wake-up events. This field is zero if Port Power( ) is zero.
        unsigned PHCD : 1; //!< PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock. The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically when the host initials resume. Before forcing a resume from the device, the device controller driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the downstream device has been put into suspend mode or when no downstream device is connected. Low power suspend is completely under the control of software.
        unsigned PFSC : 1; //!< Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port to identify itself as High Speed.
        unsigned PTS : 1; //!< See description at bits 31-30
        unsigned PSPD : 2; //!< Port Speed - Read Only. This register field indicates the speed at which the port is operating. For HS mode operation in the host controller and HS/FS operation in the device controller the port routing steers data to the Protocol engine. For FS and LS mode operation in the host controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction Translator.
        unsigned PTW : 1; //!< Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16 selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0 selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0; For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver Width This bit has no effect if serial interface engine is used. These register bits are implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3 core, it is Read-Only. Reset value is '1b'.
        unsigned STS : 1; //!< Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver interface is selected for FS and LS operation. The Serial Interface Engine can be used in combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for future operation and is a placeholder adding dynamic use of the serial engine in accord with UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita, OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select - Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value. Serial Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value.
        unsigned PTS1 : 2; //!< Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30, bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE = 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 - Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7; For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b" Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC All USB port interface modes are listed in this field description, but not all are supported. For detail feature of each controller core, please see . The behaviour is unknown when unsupported interface mode is selected.
    } B;
} hw_usbc__portsc1uog_t;
#endif

/*
 * constants & macros for entire USBC__PORTSC1UOG register
 */
#define HW_USBC__PORTSC1UOG_ADDR      (REGS_USBC_BASE + 0x184)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PORTSC1UOG           (*(volatile hw_usbc__portsc1uog_t *) HW_USBC__PORTSC1UOG_ADDR)
#define HW_USBC__PORTSC1UOG_RD()      (HW_USBC__PORTSC1UOG.U)
#define HW_USBC__PORTSC1UOG_WR(v)     (HW_USBC__PORTSC1UOG.U = (v))
#define HW_USBC__PORTSC1UOG_SET(v)    (HW_USBC__PORTSC1UOG_WR(HW_USBC__PORTSC1UOG_RD() |  (v)))
#define HW_USBC__PORTSC1UOG_CLR(v)    (HW_USBC__PORTSC1UOG_WR(HW_USBC__PORTSC1UOG_RD() & ~(v)))
#define HW_USBC__PORTSC1UOG_TOG(v)    (HW_USBC__PORTSC1UOG_WR(HW_USBC__PORTSC1UOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PORTSC1UOG bitfields
 */

/* --- Register HW_USBC__PORTSC1UOG, field CCS[0:0] (RW)
 *
 * Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is
 * present. Default = 0. This value reflects the current state of the port, and may not correspond
 * directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is
 * zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached.
 * Default=0. A one indicates that the device successfully attached and is operating in either high
 * speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates
 * that the device did not attach successfully or was forcibly disconnected by the software writing
 * a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or
 * suspended.
 */

#define BP_USBC__PORTSC1UOG_CCS      (0)
#define BM_USBC__PORTSC1UOG_CCS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_CCS(v)   ((((reg32_t) v) << 0) & BM_USBC__PORTSC1UOG_CCS)
#else
#define BF_USBC__PORTSC1UOG_CCS(v)   (((v) << 0) & BM_USBC__PORTSC1UOG_CCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CCS field to a new value.
#define BW_USBC__PORTSC1UOG_CCS(v)   BF_CS1(USBC__PORTSC1UOG, CCS, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field CSC[1:1] (RW)
 *
 * Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host
 * Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device
 * controller sets this bit for all changes to the port device connect status, even if system
 * software has not cleared an existing connect status change. For example, the insertion status
 * changes twice before system software has cleared the changed condition, hub hardware will be
 * 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by
 * writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode:
 * This bit is undefined in device controller mode.
 */

#define BP_USBC__PORTSC1UOG_CSC      (1)
#define BM_USBC__PORTSC1UOG_CSC      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_CSC(v)   ((((reg32_t) v) << 1) & BM_USBC__PORTSC1UOG_CSC)
#else
#define BF_USBC__PORTSC1UOG_CSC(v)   (((v) << 1) & BM_USBC__PORTSC1UOG_CSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC field to a new value.
#define BW_USBC__PORTSC1UOG_CSC(v)   BF_CS1(USBC__PORTSC1UOG, CSC, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PE[2:2] (RW)
 *
 * Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be
 * enabled by the host controller as a part of the reset and enable. Software cannot enable a port
 * by writing a one to this field. Ports can be disabled by either a fault condition (disconnect
 * event or other fault condition) or by the host software. Note that the bit status does not change
 * until the port state actually changes. There may be a delay in disabling or enabling a port due
 * to other host controller and bus events. When the port is disabled, (0b) downstream propagation
 * of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In
 * Device Mode: The device port is always enabled, so this bit is always '1b'.
 */

#define BP_USBC__PORTSC1UOG_PE      (2)
#define BM_USBC__PORTSC1UOG_PE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PE(v)   ((((reg32_t) v) << 2) & BM_USBC__PORTSC1UOG_PE)
#else
#define BF_USBC__PORTSC1UOG_PE(v)   (((v) << 2) & BM_USBC__PORTSC1UOG_PE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PE field to a new value.
#define BW_USBC__PORTSC1UOG_PE(v)   BF_CS1(USBC__PORTSC1UOG, PE, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PEC[3:3] (RW)
 *
 * Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default
 * = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to
 * disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See
 * Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is
 * zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is
 * always '0b'.
 */

#define BP_USBC__PORTSC1UOG_PEC      (3)
#define BM_USBC__PORTSC1UOG_PEC      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PEC(v)   ((((reg32_t) v) << 3) & BM_USBC__PORTSC1UOG_PEC)
#else
#define BF_USBC__PORTSC1UOG_PEC(v)   (((v) << 3) & BM_USBC__PORTSC1UOG_PEC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PEC field to a new value.
#define BW_USBC__PORTSC1UOG_PEC(v)   BF_CS1(USBC__PORTSC1UOG, PEC, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field OCA[4:4] (RW)
 *
 * Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero
 * when the over current condition is removed. For host/OTG implementations the user can provide
 * over-current detection to the vbus_pwr_fault input for this condition. For device-only
 * implementations this bit shall always be 0.
 *
 * Values:
 * 0 - This port does not have an over-current condition.
 * 1 - This port currently has an over-current condition
 */

#define BP_USBC__PORTSC1UOG_OCA      (4)
#define BM_USBC__PORTSC1UOG_OCA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_OCA(v)   ((((reg32_t) v) << 4) & BM_USBC__PORTSC1UOG_OCA)
#else
#define BF_USBC__PORTSC1UOG_OCA(v)   (((v) << 4) & BM_USBC__PORTSC1UOG_OCA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCA field to a new value.
#define BW_USBC__PORTSC1UOG_OCA(v)   BF_CS1(USBC__PORTSC1UOG, OCA, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field OCC[5:5] (RW)
 *
 * Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to
 * Over-current Active. Software can clear this bit by writing a one to this bit position. For
 * host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input
 * for this condition. For device-only implementations this bit shall always be 0.
 */

#define BP_USBC__PORTSC1UOG_OCC      (5)
#define BM_USBC__PORTSC1UOG_OCC      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_OCC(v)   ((((reg32_t) v) << 5) & BM_USBC__PORTSC1UOG_OCC)
#else
#define BF_USBC__PORTSC1UOG_OCC(v)   (((v) << 5) & BM_USBC__PORTSC1UOG_OCC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCC field to a new value.
#define BW_USBC__PORTSC1UOG_OCC(v)   BF_CS1(USBC__PORTSC1UOG, OCC, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field FPR[6:6] (RW)
 *
 * Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state)
 * detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume
 * signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the
 * port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is
 * detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will
 * automatically change to zero after the resume sequence is complete. This behavior is different
 * from EHCI where the host controller driver is required to set this bit to a zero after the resume
 * duration is timed in the driver. Note that when the Host controller owns the port, the resume
 * sequence follows the defined sequence documented in the USB Specification Revision 2.0. The
 * resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This
 * bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no
 * affect because the port controller will time the resume operation clear the bit the port control
 * state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This
 * bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or
 * more, software must set this bit to one to drive resume signaling before clearing. The Device
 * Controller will set this bit to one if a J-to-K transition is detected while the port is in the
 * Suspend state. The bit will be cleared when the device returns to normal operation. Also, when
 * this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the
 * USBSTS register is also set to one.
 */

#define BP_USBC__PORTSC1UOG_FPR      (6)
#define BM_USBC__PORTSC1UOG_FPR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_FPR(v)   ((((reg32_t) v) << 6) & BM_USBC__PORTSC1UOG_FPR)
#else
#define BF_USBC__PORTSC1UOG_FPR(v)   (((v) << 6) & BM_USBC__PORTSC1UOG_FPR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FPR field to a new value.
#define BW_USBC__PORTSC1UOG_FPR(v)   BF_CS1(USBC__PORTSC1UOG, FPR, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field SUSP[7:7] (RW)
 *
 * Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend
 * state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the
 * port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend
 * When in suspend state, downstream propagation of data is blocked on this port, except for port
 * reset. The blocking occurs at the end of the current transaction if a transaction was in progress
 * when this bit was written to 1. In the suspend state, the port is sensitive to resume detection.
 * Note that the bit status does not change until the port is suspended and that there may be a
 * delay in suspending a port if there is a transaction currently in progress on the The host
 * controller will unconditionally set this bit to zero when software sets the Force Port Resume bit
 * to zero. The host controller ignores a write of zero to this bit. If host software sets this bit
 * to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are
 * undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only.
 * In device mode this bit is a read only status bit.
 */

#define BP_USBC__PORTSC1UOG_SUSP      (7)
#define BM_USBC__PORTSC1UOG_SUSP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_SUSP(v)   ((((reg32_t) v) << 7) & BM_USBC__PORTSC1UOG_SUSP)
#else
#define BF_USBC__PORTSC1UOG_SUSP(v)   (((v) << 7) & BM_USBC__PORTSC1UOG_SUSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSP field to a new value.
#define BW_USBC__PORTSC1UOG_SUSP(v)   BF_CS1(USBC__PORTSC1UOG, SUSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PR[8:8] (RW)
 *
 * Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset.
 * 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence
 * as defined in the USB Specification Revision 2.0 is started. This bit will automatically change
 * to zero after the reset sequence is complete. This behavior is different from EHCI where the host
 * controller driver is required to set this bit to a zero after the reset duration is timed in the
 * driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also
 * indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UOG_PR      (8)
#define BM_USBC__PORTSC1UOG_PR      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PR(v)   ((((reg32_t) v) << 8) & BM_USBC__PORTSC1UOG_PR)
#else
#define BF_USBC__PORTSC1UOG_PR(v)   (((v) << 8) & BM_USBC__PORTSC1UOG_PR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PR field to a new value.
#define BW_USBC__PORTSC1UOG_PR(v)   BF_CS1(USBC__PORTSC1UOG, PR, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field HSP[9:9] (RW)
 *
 * High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the
 * port is in high-speed mode and if set to zero, the host/device connected to the port is not in a
 * high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
 */

#define BP_USBC__PORTSC1UOG_HSP      (9)
#define BM_USBC__PORTSC1UOG_HSP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_HSP(v)   ((((reg32_t) v) << 9) & BM_USBC__PORTSC1UOG_HSP)
#else
#define BF_USBC__PORTSC1UOG_HSP(v)   (((v) << 9) & BM_USBC__PORTSC1UOG_HSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSP field to a new value.
#define BW_USBC__PORTSC1UOG_HSP(v)   BF_CS1(USBC__PORTSC1UOG, HSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field LS[11:10] (RW)
 *
 * Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D-
 * (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not
 * necessary (unlike EHCI), because the port controller state machine and the port routing manage
 * the connection of LS and FS. In device mode, the use of linestate by the device controller driver
 * is not necessary. The encoding of the bits are: Bits [11:10] Meaning
 *
 * Values:
 * 00 - SE0
 * 01 - K-state
 * 10 - J-state
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UOG_LS      (10)
#define BM_USBC__PORTSC1UOG_LS      (0x00000c00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_LS(v)   ((((reg32_t) v) << 10) & BM_USBC__PORTSC1UOG_LS)
#else
#define BF_USBC__PORTSC1UOG_LS(v)   (((v) << 10) & BM_USBC__PORTSC1UOG_LS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LS field to a new value.
#define BW_USBC__PORTSC1UOG_LS(v)   BF_CS1(USBC__PORTSC1UOG, LS, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field PP[12:12] (RW)
 *
 * Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the
 * Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP
 * Operation 0 1b Read Only - Host controller does not have port power control switches. Each port
 * is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control
 * switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not
 * available on a port (that is, PP equals a 0), the port is non-functional and will not report
 * attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is
 * a one, the PP bit in each affected port may be transitional by the host controller driver from a
 * one to a zero (removing power from the port). This feature is implemented in all 4 controller
 * cores (PPC = 1).
 */

#define BP_USBC__PORTSC1UOG_PP      (12)
#define BM_USBC__PORTSC1UOG_PP      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PP(v)   ((((reg32_t) v) << 12) & BM_USBC__PORTSC1UOG_PP)
#else
#define BF_USBC__PORTSC1UOG_PP(v)   (((v) << 12) & BM_USBC__PORTSC1UOG_PP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PP field to a new value.
#define BW_USBC__PORTSC1UOG_PP(v)   BF_CS1(USBC__PORTSC1UOG, PP, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PO[13:13] (RW)
 *
 * Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit
 * in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever
 * the Configured bit is zero System software uses this field to release ownership of the port to a
 * selected host controller (in the event that the attached device is not a high-speed device).
 * Software writes a one to this bit when the attached device is not a high-speed device. A one in
 * this bit means that an internal companion controller owns and controls the port. Port owner
 * handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
 */

#define BP_USBC__PORTSC1UOG_PO      (13)
#define BM_USBC__PORTSC1UOG_PO      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PO(v)   ((((reg32_t) v) << 13) & BM_USBC__PORTSC1UOG_PO)
#else
#define BF_USBC__PORTSC1UOG_PO(v)   (((v) << 13) & BM_USBC__PORTSC1UOG_PO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PO field to a new value.
#define BW_USBC__PORTSC1UOG_PO(v)   BF_CS1(USBC__PORTSC1UOG, PO, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PIC[15:14] (RW)
 *
 * Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the
 * P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0
 * for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit
 * Value Meaning
 *
 * Values:
 * 00 - Port indicators are off
 * 01 - Amber
 * 10 - Green
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UOG_PIC      (14)
#define BM_USBC__PORTSC1UOG_PIC      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PIC(v)   ((((reg32_t) v) << 14) & BM_USBC__PORTSC1UOG_PIC)
#else
#define BF_USBC__PORTSC1UOG_PIC(v)   (((v) << 14) & BM_USBC__PORTSC1UOG_PIC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIC field to a new value.
#define BW_USBC__PORTSC1UOG_PIC(v)   BF_CS1(USBC__PORTSC1UOG, PIC, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field PTC[19:16] (RW)
 *
 * Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model
 * for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each
 * test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support
 * specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS}
 * values will force the port into the connected and enabled state at the selected speed. Writing
 * the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally
 * from that point. Low speed operations are not supported as a peripheral device. Any other value
 * than zero indicates that the port is operating in test mode. Value Specific Test
 *
 * Values:
 * 0000 - TEST_MODE_DISABLE
 * 0001 - J_STATE
 * 0010 - K_STATE
 * 0011 - SE0 (host) / NAK (device)
 * 0100 - Packet
 * 0101 - FORCE_ENABLE_HS
 * 0110 - FORCE_ENABLE_FS
 * 0111 - FORCE_ENABLE_LS
 * 1000-1111 - Reserved
 */

#define BP_USBC__PORTSC1UOG_PTC      (16)
#define BM_USBC__PORTSC1UOG_PTC      (0x000f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PTC(v)   ((((reg32_t) v) << 16) & BM_USBC__PORTSC1UOG_PTC)
#else
#define BF_USBC__PORTSC1UOG_PTC(v)   (((v) << 16) & BM_USBC__PORTSC1UOG_PTC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTC field to a new value.
#define BW_USBC__PORTSC1UOG_PTC(v)   BF_CS1(USBC__PORTSC1UOG, PTC, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field WKCN[20:20] (RW)
 *
 * Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the
 * port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is
 * zero or in device mode.
 */

#define BP_USBC__PORTSC1UOG_WKCN      (20)
#define BM_USBC__PORTSC1UOG_WKCN      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_WKCN(v)   ((((reg32_t) v) << 20) & BM_USBC__PORTSC1UOG_WKCN)
#else
#define BF_USBC__PORTSC1UOG_WKCN(v)   (((v) << 20) & BM_USBC__PORTSC1UOG_WKCN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKCN field to a new value.
#define BW_USBC__PORTSC1UOG_WKCN(v)   BF_CS1(USBC__PORTSC1UOG, WKCN, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field WKDC[21:21] (RW)
 *
 * Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one
 * enables the port to be sensitive to device disconnects as wake-up events. This field is zero if
 * Port Power( ) is zero or in device mode.
 */

#define BP_USBC__PORTSC1UOG_WKDC      (21)
#define BM_USBC__PORTSC1UOG_WKDC      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_WKDC(v)   ((((reg32_t) v) << 21) & BM_USBC__PORTSC1UOG_WKDC)
#else
#define BF_USBC__PORTSC1UOG_WKDC(v)   (((v) << 21) & BM_USBC__PORTSC1UOG_WKDC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKDC field to a new value.
#define BW_USBC__PORTSC1UOG_WKDC(v)   BF_CS1(USBC__PORTSC1UOG, WKDC, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field WKOC[22:22] (RW)
 *
 * Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one
 * enables the port to be sensitive to over-current conditions as wake-up events. This field is zero
 * if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UOG_WKOC      (22)
#define BM_USBC__PORTSC1UOG_WKOC      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_WKOC(v)   ((((reg32_t) v) << 22) & BM_USBC__PORTSC1UOG_WKOC)
#else
#define BF_USBC__PORTSC1UOG_WKOC(v)   (((v) << 22) & BM_USBC__PORTSC1UOG_WKOC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKOC field to a new value.
#define BW_USBC__PORTSC1UOG_WKOC(v)   BF_CS1(USBC__PORTSC1UOG, WKOC, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PHCD[23:23] (RW)
 *
 * PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set
 * to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock.
 * The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY
 * can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host
 * has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically
 * when the host initials resume. Before forcing a resume from the device, the device controller
 * driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the
 * downstream device has been put into suspend mode or when no downstream device is connected. Low
 * power suspend is completely under the control of software.
 *
 * Values:
 * 0 - Enable PHY clock
 * 1 - Disable PHY clock
 */

#define BP_USBC__PORTSC1UOG_PHCD      (23)
#define BM_USBC__PORTSC1UOG_PHCD      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PHCD(v)   ((((reg32_t) v) << 23) & BM_USBC__PORTSC1UOG_PHCD)
#else
#define BF_USBC__PORTSC1UOG_PHCD(v)   (((v) << 23) & BM_USBC__PORTSC1UOG_PHCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHCD field to a new value.
#define BW_USBC__PORTSC1UOG_PHCD(v)   BF_CS1(USBC__PORTSC1UOG, PHCD, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field PFSC[24:24] (RW)
 *
 * Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port
 * will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port
 * to identify itself as High Speed.
 *
 * Values:
 * 0 - Normal operation
 * 1 - Forced to full speed
 */

#define BP_USBC__PORTSC1UOG_PFSC      (24)
#define BM_USBC__PORTSC1UOG_PFSC      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PFSC(v)   ((((reg32_t) v) << 24) & BM_USBC__PORTSC1UOG_PFSC)
#else
#define BF_USBC__PORTSC1UOG_PFSC(v)   (((v) << 24) & BM_USBC__PORTSC1UOG_PFSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFSC field to a new value.
#define BW_USBC__PORTSC1UOG_PFSC(v)   BF_CS1(USBC__PORTSC1UOG, PFSC, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field PTS[25:25] (RW)
 *
 * See description at bits 31-30
 */

#define BP_USBC__PORTSC1UOG_PTS      (25)
#define BM_USBC__PORTSC1UOG_PTS      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PTS(v)   ((((reg32_t) v) << 25) & BM_USBC__PORTSC1UOG_PTS)
#else
#define BF_USBC__PORTSC1UOG_PTS(v)   (((v) << 25) & BM_USBC__PORTSC1UOG_PTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS field to a new value.
#define BW_USBC__PORTSC1UOG_PTS(v)   BF_CS1(USBC__PORTSC1UOG, PTS, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PSPD[27:26] (RW)
 *
 * Port Speed - Read Only. This register field indicates the speed at which the port is operating.
 * For HS mode operation in the host controller and HS/FS operation in the device controller the
 * port routing steers data to the Protocol engine. For FS and LS mode operation in the host
 * controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction
 * Translator.
 *
 * Values:
 * 00 - Full Speed
 * 01 - Low Speed
 * 10 - High Speed
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UOG_PSPD      (26)
#define BM_USBC__PORTSC1UOG_PSPD      (0x0c000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PSPD(v)   ((((reg32_t) v) << 26) & BM_USBC__PORTSC1UOG_PSPD)
#else
#define BF_USBC__PORTSC1UOG_PSPD(v)   (((v) << 26) & BM_USBC__PORTSC1UOG_PSPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSPD field to a new value.
#define BW_USBC__PORTSC1UOG_PSPD(v)   BF_CS1(USBC__PORTSC1UOG, PSPD, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field PTW[28:28] (RW)
 *
 * Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI
 * transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16
 * selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0
 * selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI
 * interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined
 * in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0;
 * For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver
 * Width This bit has no effect if serial interface engine is used. These register bits are
 * implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For
 * Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For
 * OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3
 * core, it is Read-Only. Reset value is '1b'.
 *
 * Values:
 * 1 - Select the 8-bit UTMI interface [60MHz]
 * 2 - Select the 16-bit UTMI interface [30MHz]
 */

#define BP_USBC__PORTSC1UOG_PTW      (28)
#define BM_USBC__PORTSC1UOG_PTW      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PTW(v)   ((((reg32_t) v) << 28) & BM_USBC__PORTSC1UOG_PTW)
#else
#define BF_USBC__PORTSC1UOG_PTW(v)   (((v) << 28) & BM_USBC__PORTSC1UOG_PTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTW field to a new value.
#define BW_USBC__PORTSC1UOG_PTW(v)   BF_CS1(USBC__PORTSC1UOG, PTW, v)
#endif


/* --- Register HW_USBC__PORTSC1UOG, field STS[29:29] (RW)
 *
 * Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver
 * interface is selected for FS and LS operation. The Serial Interface Engine can be used in
 * combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the
 * parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel
 * Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial
 * Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for
 * future operation and is a placeholder adding dynamic use of the serial engine in accord with
 * UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification
 * VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita,
 * OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select -
 * Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals
 * is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface
 * to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b',
 * serial interface engine will be used instead of parallel interface signals. This bit has no
 * effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will
 * use the serial interface engine for FS/LS signaling regardless of this bit value. Serial
 * Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0
 * Parallel Interface signals is selected Serial Interface Engine can be used in combination with
 * UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface
 * signals. When this bit is set '1b', serial interface engine will be used instead of parallel
 * interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface.
 * The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless
 * of this bit value.
 */

#define BP_USBC__PORTSC1UOG_STS      (29)
#define BM_USBC__PORTSC1UOG_STS      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_STS(v)   ((((reg32_t) v) << 29) & BM_USBC__PORTSC1UOG_STS)
#else
#define BF_USBC__PORTSC1UOG_STS(v)   (((v) << 29) & BM_USBC__PORTSC1UOG_STS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STS field to a new value.
#define BW_USBC__PORTSC1UOG_STS(v)   BF_CS1(USBC__PORTSC1UOG, STS, v)
#endif

/* --- Register HW_USBC__PORTSC1UOG, field PTS1[31:30] (RW)
 *
 * Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the
 * configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is
 * selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If
 * VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30,
 * bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE =
 * 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 -
 * Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is
 * not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7;
 * For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver
 * Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3
 * core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b"
 * Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25,
 * bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only.
 * Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field
 * {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY
 * /IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register
 * bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For
 * Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}:
 * "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b"
 * HSIC All USB port interface modes are listed in this field description, but not all are
 * supported. For detail feature of each controller core, please see . The behaviour is unknown when
 * unsupported interface mode is selected.
 */

#define BP_USBC__PORTSC1UOG_PTS1      (30)
#define BM_USBC__PORTSC1UOG_PTS1      (0xc0000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UOG_PTS1(v)   ((((reg32_t) v) << 30) & BM_USBC__PORTSC1UOG_PTS1)
#else
#define BF_USBC__PORTSC1UOG_PTS1(v)   (((v) << 30) & BM_USBC__PORTSC1UOG_PTS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS1 field to a new value.
#define BW_USBC__PORTSC1UOG_PTS1(v)   BF_CS1(USBC__PORTSC1UOG, PTS1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_OTGSC - On-The-Go Status & control (RW)
 *
 * This register is availabe only in OTG controller core. It has four sections:   OTG Interrupt
 * enables (Read/Write)  OTG Interrupt status (Read/Write to Clear)  OTG Status inputs (Read Only)
 * OTG Controls (Read/Write)   The status inputs are debounced using a 1 ms time constant. Values on
 * the status inputs that do not persist for more than 1 ms does not cause an update of the status
 * input register, or cause an OTG interrupt.  See also register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VD : 1; //!< VBUS_Discharge - Read/Write. Setting this bit causes VBus to discharge through a resistor.
        unsigned VC : 1; //!< VBUS Charge - Read/Write. Setting this bit causes the VBus line to be charged. This is used for VBus pulsing during SRP.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned OT : 1; //!< OTG Termination - Read/Write. This bit must be set when the OTG device is in device mode, this controls the pulldown on DM.
        unsigned DP : 1; //!< Data Pulsing - Read/Write. Setting this bit causes the pullup on DP to be asserted for data pulsing during SRP.
        unsigned IDPU : 1; //!< ID Pullup - Read/Write This bit provide control over the ID pull-up resister; 0 = off, 1 = on [default]. When this bit is 0, the ID input will not be sampled.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned ID : 1; //!< USB ID - Read Only. 0 = A device, 1 = B device
        unsigned AVV : 1; //!< A VBus Valid - Read Only. Indicates VBus is above the A VBus valid threshold.
        unsigned ASV : 1; //!< A Session Valid - Read Only. Indicates VBus is above the A session valid threshold.
        unsigned BSV : 1; //!< B Session Valid - Read Only. Indicates VBus is above the B session valid threshold.
        unsigned BSE : 1; //!< B Session End - Read Only. Indicates VBus is below the B session end threshold.
        unsigned _1MST : 1; //!< 1 millisecond timer toggle - Read Only. This bit toggles once per millisecond.
        unsigned DPS : 1; //!< Data Bus Pulsing Status - Read Only. A '1' indicates data bus pulsing is being detected on the port.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned IDIS : 1; //!< USB ID Interrupt Status - Read/Write. This bit is set when a change on the ID input has been detected. Software must write a one to clear this bit.
        unsigned AVVIS : 1; //!< A VBus Valid Interrupt Status - Read/Write to Clear. This bit is set when VBus has either risen above or fallen below the VBus valid threshold (4.4 VDC) on an A device. Software must write a one to clear this bit.
        unsigned ASVIS : 1; //!< A Session Valid Interrupt Status - Read/Write to Clear. This bit is set when VBus has either risen above or fallen below the A session valid threshold (0.8 VDC). Software must write a one to clear this bit.
        unsigned BSVIS : 1; //!< B Session Valid Interrupt Status - Read/Write to Clear. This bit is set when VBus has either risen above or fallen below the B session valid threshold (0.8 VDC). Software must write a one to clear this bit.
        unsigned BSEIS : 1; //!< B Session End Interrupt Status - Read/Write to Clear. This bit is set when VBus has fallen below the B session end threshold. Software must write a one to clear this bit
        unsigned _1MSS : 1; //!< 1 millisecond timer Interrupt Status - Read/Write to Clear. This bit is set once every millisecond. Software must write a one to clear this bit.
        unsigned DPIS : 1; //!< Data Pulse Interrupt Status - Read/Write to Clear. This bit is set when data bus pulsing occurs on DP or DM. Data bus pulsing is only detected when USBMODE.CM = Host (11) and PORTSC1(0)[PP] = 0. Software must write a one to clear this bit.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned IDIE : 1; //!< USB ID Interrupt Enable - Read/Write. Setting this bit enables the USB ID interrupt.
        unsigned AVVIE : 1; //!< A VBus Valid Interrupt Enable - Read/Write. Setting this bit enables the A VBus valid interrupt.
        unsigned ASVIE : 1; //!< A Session Valid Interrupt Enable - Read/Write. Setting this bit enables the A session valid interrupt.
        unsigned BSVIE : 1; //!< B Session Valid Interrupt Enable - Read/Write. Setting this bit enables the B session valid interrupt.
        unsigned BSEIE : 1; //!< B Session End Interrupt Enable - Read/Write. Setting this bit enables the B session end interrupt.
        unsigned _1MSE : 1; //!< 1 millisecond timer Interrupt Enable - Read/Write
        unsigned DPIE : 1; //!< Data Pulse Interrupt Enable
        unsigned RESERVED4 : 1; //!< Reserved
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

/* --- Register HW_USBC_UOG_OTGSC, field VD[0:0] (RW)
 *
 * VBUS_Discharge - Read/Write. Setting this bit causes VBus to discharge through a resistor.
 */

#define BP_USBC_UOG_OTGSC_VD      (0)
#define BM_USBC_UOG_OTGSC_VD      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_VD(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_OTGSC_VD)
#else
#define BF_USBC_UOG_OTGSC_VD(v)   (((v) << 0) & BM_USBC_UOG_OTGSC_VD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VD field to a new value.
#define BW_USBC_UOG_OTGSC_VD(v)   BF_CS1(USBC_UOG_OTGSC, VD, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field VC[1:1] (RW)
 *
 * VBUS Charge - Read/Write. Setting this bit causes the VBus line to be charged. This is used for
 * VBus pulsing during SRP.
 */

#define BP_USBC_UOG_OTGSC_VC      (1)
#define BM_USBC_UOG_OTGSC_VC      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_VC(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_OTGSC_VC)
#else
#define BF_USBC_UOG_OTGSC_VC(v)   (((v) << 1) & BM_USBC_UOG_OTGSC_VC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VC field to a new value.
#define BW_USBC_UOG_OTGSC_VC(v)   BF_CS1(USBC_UOG_OTGSC, VC, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field OT[3:3] (RW)
 *
 * OTG Termination - Read/Write. This bit must be set when the OTG device is in device mode, this
 * controls the pulldown on DM.
 */

#define BP_USBC_UOG_OTGSC_OT      (3)
#define BM_USBC_UOG_OTGSC_OT      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_OT(v)   ((((reg32_t) v) << 3) & BM_USBC_UOG_OTGSC_OT)
#else
#define BF_USBC_UOG_OTGSC_OT(v)   (((v) << 3) & BM_USBC_UOG_OTGSC_OT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OT field to a new value.
#define BW_USBC_UOG_OTGSC_OT(v)   BF_CS1(USBC_UOG_OTGSC, OT, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DP[4:4] (RW)
 *
 * Data Pulsing - Read/Write. Setting this bit causes the pullup on DP to be asserted for data
 * pulsing during SRP.
 */

#define BP_USBC_UOG_OTGSC_DP      (4)
#define BM_USBC_UOG_OTGSC_DP      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DP(v)   ((((reg32_t) v) << 4) & BM_USBC_UOG_OTGSC_DP)
#else
#define BF_USBC_UOG_OTGSC_DP(v)   (((v) << 4) & BM_USBC_UOG_OTGSC_DP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DP field to a new value.
#define BW_USBC_UOG_OTGSC_DP(v)   BF_CS1(USBC_UOG_OTGSC, DP, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field IDPU[5:5] (RW)
 *
 * ID Pullup - Read/Write This bit provide control over the ID pull-up resister; 0 = off, 1 = on
 * [default]. When this bit is 0, the ID input will not be sampled.
 */

#define BP_USBC_UOG_OTGSC_IDPU      (5)
#define BM_USBC_UOG_OTGSC_IDPU      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_IDPU(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_OTGSC_IDPU)
#else
#define BF_USBC_UOG_OTGSC_IDPU(v)   (((v) << 5) & BM_USBC_UOG_OTGSC_IDPU)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDPU field to a new value.
#define BW_USBC_UOG_OTGSC_IDPU(v)   BF_CS1(USBC_UOG_OTGSC, IDPU, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ID[8:8] (RW)
 *
 * USB ID - Read Only. 0 = A device, 1 = B device
 */

#define BP_USBC_UOG_OTGSC_ID      (8)
#define BM_USBC_UOG_OTGSC_ID      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ID(v)   ((((reg32_t) v) << 8) & BM_USBC_UOG_OTGSC_ID)
#else
#define BF_USBC_UOG_OTGSC_ID(v)   (((v) << 8) & BM_USBC_UOG_OTGSC_ID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ID field to a new value.
#define BW_USBC_UOG_OTGSC_ID(v)   BF_CS1(USBC_UOG_OTGSC, ID, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field AVV[9:9] (RW)
 *
 * A VBus Valid - Read Only. Indicates VBus is above the A VBus valid threshold.
 */

#define BP_USBC_UOG_OTGSC_AVV      (9)
#define BM_USBC_UOG_OTGSC_AVV      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_AVV(v)   ((((reg32_t) v) << 9) & BM_USBC_UOG_OTGSC_AVV)
#else
#define BF_USBC_UOG_OTGSC_AVV(v)   (((v) << 9) & BM_USBC_UOG_OTGSC_AVV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVV field to a new value.
#define BW_USBC_UOG_OTGSC_AVV(v)   BF_CS1(USBC_UOG_OTGSC, AVV, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ASV[10:10] (RW)
 *
 * A Session Valid - Read Only. Indicates VBus is above the A session valid threshold.
 */

#define BP_USBC_UOG_OTGSC_ASV      (10)
#define BM_USBC_UOG_OTGSC_ASV      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ASV(v)   ((((reg32_t) v) << 10) & BM_USBC_UOG_OTGSC_ASV)
#else
#define BF_USBC_UOG_OTGSC_ASV(v)   (((v) << 10) & BM_USBC_UOG_OTGSC_ASV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASV field to a new value.
#define BW_USBC_UOG_OTGSC_ASV(v)   BF_CS1(USBC_UOG_OTGSC, ASV, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSV[11:11] (RW)
 *
 * B Session Valid - Read Only. Indicates VBus is above the B session valid threshold.
 */

#define BP_USBC_UOG_OTGSC_BSV      (11)
#define BM_USBC_UOG_OTGSC_BSV      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSV(v)   ((((reg32_t) v) << 11) & BM_USBC_UOG_OTGSC_BSV)
#else
#define BF_USBC_UOG_OTGSC_BSV(v)   (((v) << 11) & BM_USBC_UOG_OTGSC_BSV)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BSV field to a new value.
#define BW_USBC_UOG_OTGSC_BSV(v)   BF_CS1(USBC_UOG_OTGSC, BSV, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSE[12:12] (RW)
 *
 * B Session End - Read Only. Indicates VBus is below the B session end threshold.
 */

#define BP_USBC_UOG_OTGSC_BSE      (12)
#define BM_USBC_UOG_OTGSC_BSE      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSE(v)   ((((reg32_t) v) << 12) & BM_USBC_UOG_OTGSC_BSE)
#else
#define BF_USBC_UOG_OTGSC_BSE(v)   (((v) << 12) & BM_USBC_UOG_OTGSC_BSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BSE field to a new value.
#define BW_USBC_UOG_OTGSC_BSE(v)   BF_CS1(USBC_UOG_OTGSC, BSE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field _1MST[13:13] (RW)
 *
 * 1 millisecond timer toggle - Read Only. This bit toggles once per millisecond.
 */

#define BP_USBC_UOG_OTGSC__1MST      (13)
#define BM_USBC_UOG_OTGSC__1MST      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC__1MST(v)   ((((reg32_t) v) << 13) & BM_USBC_UOG_OTGSC__1MST)
#else
#define BF_USBC_UOG_OTGSC__1MST(v)   (((v) << 13) & BM_USBC_UOG_OTGSC__1MST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the _1MST field to a new value.
#define BW_USBC_UOG_OTGSC__1MST(v)   BF_CS1(USBC_UOG_OTGSC, _1MST, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DPS[14:14] (RW)
 *
 * Data Bus Pulsing Status - Read Only. A '1' indicates data bus pulsing is being detected on the
 * port.
 */

#define BP_USBC_UOG_OTGSC_DPS      (14)
#define BM_USBC_UOG_OTGSC_DPS      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DPS(v)   ((((reg32_t) v) << 14) & BM_USBC_UOG_OTGSC_DPS)
#else
#define BF_USBC_UOG_OTGSC_DPS(v)   (((v) << 14) & BM_USBC_UOG_OTGSC_DPS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPS field to a new value.
#define BW_USBC_UOG_OTGSC_DPS(v)   BF_CS1(USBC_UOG_OTGSC, DPS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field IDIS[16:16] (RW)
 *
 * USB ID Interrupt Status - Read/Write. This bit is set when a change on the ID input has been
 * detected. Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_IDIS      (16)
#define BM_USBC_UOG_OTGSC_IDIS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_IDIS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_OTGSC_IDIS)
#else
#define BF_USBC_UOG_OTGSC_IDIS(v)   (((v) << 16) & BM_USBC_UOG_OTGSC_IDIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDIS field to a new value.
#define BW_USBC_UOG_OTGSC_IDIS(v)   BF_CS1(USBC_UOG_OTGSC, IDIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field AVVIS[17:17] (RW)
 *
 * A VBus Valid Interrupt Status - Read/Write to Clear. This bit is set when VBus has either risen
 * above or fallen below the VBus valid threshold (4.4 VDC) on an A device. Software must write a
 * one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_AVVIS      (17)
#define BM_USBC_UOG_OTGSC_AVVIS      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_AVVIS(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_OTGSC_AVVIS)
#else
#define BF_USBC_UOG_OTGSC_AVVIS(v)   (((v) << 17) & BM_USBC_UOG_OTGSC_AVVIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVVIS field to a new value.
#define BW_USBC_UOG_OTGSC_AVVIS(v)   BF_CS1(USBC_UOG_OTGSC, AVVIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ASVIS[18:18] (RW)
 *
 * A Session Valid Interrupt Status - Read/Write to Clear. This bit is set when VBus has either
 * risen above or fallen below the A session valid threshold (0.8 VDC). Software must write a one to
 * clear this bit.
 */

#define BP_USBC_UOG_OTGSC_ASVIS      (18)
#define BM_USBC_UOG_OTGSC_ASVIS      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ASVIS(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_OTGSC_ASVIS)
#else
#define BF_USBC_UOG_OTGSC_ASVIS(v)   (((v) << 18) & BM_USBC_UOG_OTGSC_ASVIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASVIS field to a new value.
#define BW_USBC_UOG_OTGSC_ASVIS(v)   BF_CS1(USBC_UOG_OTGSC, ASVIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSVIS[19:19] (RW)
 *
 * B Session Valid Interrupt Status - Read/Write to Clear. This bit is set when VBus has either
 * risen above or fallen below the B session valid threshold (0.8 VDC). Software must write a one to
 * clear this bit.
 */

#define BP_USBC_UOG_OTGSC_BSVIS      (19)
#define BM_USBC_UOG_OTGSC_BSVIS      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSVIS(v)   ((((reg32_t) v) << 19) & BM_USBC_UOG_OTGSC_BSVIS)
#else
#define BF_USBC_UOG_OTGSC_BSVIS(v)   (((v) << 19) & BM_USBC_UOG_OTGSC_BSVIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BSVIS field to a new value.
#define BW_USBC_UOG_OTGSC_BSVIS(v)   BF_CS1(USBC_UOG_OTGSC, BSVIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSEIS[20:20] (RW)
 *
 * B Session End Interrupt Status - Read/Write to Clear. This bit is set when VBus has fallen below
 * the B session end threshold. Software must write a one to clear this bit
 */

#define BP_USBC_UOG_OTGSC_BSEIS      (20)
#define BM_USBC_UOG_OTGSC_BSEIS      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSEIS(v)   ((((reg32_t) v) << 20) & BM_USBC_UOG_OTGSC_BSEIS)
#else
#define BF_USBC_UOG_OTGSC_BSEIS(v)   (((v) << 20) & BM_USBC_UOG_OTGSC_BSEIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BSEIS field to a new value.
#define BW_USBC_UOG_OTGSC_BSEIS(v)   BF_CS1(USBC_UOG_OTGSC, BSEIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field _1MSS[21:21] (RW)
 *
 * 1 millisecond timer Interrupt Status - Read/Write to Clear. This bit is set once every
 * millisecond. Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC__1MSS      (21)
#define BM_USBC_UOG_OTGSC__1MSS      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC__1MSS(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_OTGSC__1MSS)
#else
#define BF_USBC_UOG_OTGSC__1MSS(v)   (((v) << 21) & BM_USBC_UOG_OTGSC__1MSS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the _1MSS field to a new value.
#define BW_USBC_UOG_OTGSC__1MSS(v)   BF_CS1(USBC_UOG_OTGSC, _1MSS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DPIS[22:22] (RW)
 *
 * Data Pulse Interrupt Status - Read/Write to Clear. This bit is set when data bus pulsing occurs
 * on DP or DM. Data bus pulsing is only detected when USBMODE.CM = Host (11) and PORTSC1(0)[PP] =
 * 0. Software must write a one to clear this bit.
 */

#define BP_USBC_UOG_OTGSC_DPIS      (22)
#define BM_USBC_UOG_OTGSC_DPIS      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DPIS(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_OTGSC_DPIS)
#else
#define BF_USBC_UOG_OTGSC_DPIS(v)   (((v) << 22) & BM_USBC_UOG_OTGSC_DPIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPIS field to a new value.
#define BW_USBC_UOG_OTGSC_DPIS(v)   BF_CS1(USBC_UOG_OTGSC, DPIS, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field IDIE[24:24] (RW)
 *
 * USB ID Interrupt Enable - Read/Write. Setting this bit enables the USB ID interrupt.
 */

#define BP_USBC_UOG_OTGSC_IDIE      (24)
#define BM_USBC_UOG_OTGSC_IDIE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_IDIE(v)   ((((reg32_t) v) << 24) & BM_USBC_UOG_OTGSC_IDIE)
#else
#define BF_USBC_UOG_OTGSC_IDIE(v)   (((v) << 24) & BM_USBC_UOG_OTGSC_IDIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IDIE field to a new value.
#define BW_USBC_UOG_OTGSC_IDIE(v)   BF_CS1(USBC_UOG_OTGSC, IDIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field AVVIE[25:25] (RW)
 *
 * A VBus Valid Interrupt Enable - Read/Write. Setting this bit enables the A VBus valid interrupt.
 */

#define BP_USBC_UOG_OTGSC_AVVIE      (25)
#define BM_USBC_UOG_OTGSC_AVVIE      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_AVVIE(v)   ((((reg32_t) v) << 25) & BM_USBC_UOG_OTGSC_AVVIE)
#else
#define BF_USBC_UOG_OTGSC_AVVIE(v)   (((v) << 25) & BM_USBC_UOG_OTGSC_AVVIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AVVIE field to a new value.
#define BW_USBC_UOG_OTGSC_AVVIE(v)   BF_CS1(USBC_UOG_OTGSC, AVVIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field ASVIE[26:26] (RW)
 *
 * A Session Valid Interrupt Enable - Read/Write. Setting this bit enables the A session valid
 * interrupt.
 */

#define BP_USBC_UOG_OTGSC_ASVIE      (26)
#define BM_USBC_UOG_OTGSC_ASVIE      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_ASVIE(v)   ((((reg32_t) v) << 26) & BM_USBC_UOG_OTGSC_ASVIE)
#else
#define BF_USBC_UOG_OTGSC_ASVIE(v)   (((v) << 26) & BM_USBC_UOG_OTGSC_ASVIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASVIE field to a new value.
#define BW_USBC_UOG_OTGSC_ASVIE(v)   BF_CS1(USBC_UOG_OTGSC, ASVIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSVIE[27:27] (RW)
 *
 * B Session Valid Interrupt Enable - Read/Write. Setting this bit enables the B session valid
 * interrupt.
 */

#define BP_USBC_UOG_OTGSC_BSVIE      (27)
#define BM_USBC_UOG_OTGSC_BSVIE      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSVIE(v)   ((((reg32_t) v) << 27) & BM_USBC_UOG_OTGSC_BSVIE)
#else
#define BF_USBC_UOG_OTGSC_BSVIE(v)   (((v) << 27) & BM_USBC_UOG_OTGSC_BSVIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BSVIE field to a new value.
#define BW_USBC_UOG_OTGSC_BSVIE(v)   BF_CS1(USBC_UOG_OTGSC, BSVIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field BSEIE[28:28] (RW)
 *
 * B Session End Interrupt Enable - Read/Write. Setting this bit enables the B session end
 * interrupt.
 */

#define BP_USBC_UOG_OTGSC_BSEIE      (28)
#define BM_USBC_UOG_OTGSC_BSEIE      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_BSEIE(v)   ((((reg32_t) v) << 28) & BM_USBC_UOG_OTGSC_BSEIE)
#else
#define BF_USBC_UOG_OTGSC_BSEIE(v)   (((v) << 28) & BM_USBC_UOG_OTGSC_BSEIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BSEIE field to a new value.
#define BW_USBC_UOG_OTGSC_BSEIE(v)   BF_CS1(USBC_UOG_OTGSC, BSEIE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field _1MSE[29:29] (RW)
 *
 * 1 millisecond timer Interrupt Enable - Read/Write
 */

#define BP_USBC_UOG_OTGSC__1MSE      (29)
#define BM_USBC_UOG_OTGSC__1MSE      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC__1MSE(v)   ((((reg32_t) v) << 29) & BM_USBC_UOG_OTGSC__1MSE)
#else
#define BF_USBC_UOG_OTGSC__1MSE(v)   (((v) << 29) & BM_USBC_UOG_OTGSC__1MSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the _1MSE field to a new value.
#define BW_USBC_UOG_OTGSC__1MSE(v)   BF_CS1(USBC_UOG_OTGSC, _1MSE, v)
#endif

/* --- Register HW_USBC_UOG_OTGSC, field DPIE[30:30] (RW)
 *
 * Data Pulse Interrupt Enable
 */

#define BP_USBC_UOG_OTGSC_DPIE      (30)
#define BM_USBC_UOG_OTGSC_DPIE      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_OTGSC_DPIE(v)   ((((reg32_t) v) << 30) & BM_USBC_UOG_OTGSC_DPIE)
#else
#define BF_USBC_UOG_OTGSC_DPIE(v)   (((v) << 30) & BM_USBC_UOG_OTGSC_DPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPIE field to a new value.
#define BW_USBC_UOG_OTGSC_DPIE(v)   BF_CS1(USBC_UOG_OTGSC, DPIE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBMODEUOG - USB Device Mode UOG (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CM : 2; //!< Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device only implementations. For those designs that contain both host & device capability, the controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. For combination host/device controllers, this register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core, reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
        unsigned ES : 1; //!< Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to match the host microprocessor. The bit fields in the microprocessor interface and the data structures are unaffected by the value of this bit because they are based upon the 32-bit word. Bit Meaning
        unsigned SLOM : 1; //!< Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
        unsigned SDIS : 1; //!< Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX and TX buffers are sufficient to contain an entire packet that the standard double buffering scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets received are responded to with a NYET handshake when stream disable is active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to characterize the adjustments needed for the scheduler when using this feature. The use of this feature substantially limits of the overall USB performance that can be achieved.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_usbc__usbmodeuog_t;
#endif

/*
 * constants & macros for entire USBC__USBMODEUOG register
 */
#define HW_USBC__USBMODEUOG_ADDR      (REGS_USBC_BASE + 0x1a8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBMODEUOG           (*(volatile hw_usbc__usbmodeuog_t *) HW_USBC__USBMODEUOG_ADDR)
#define HW_USBC__USBMODEUOG_RD()      (HW_USBC__USBMODEUOG.U)
#define HW_USBC__USBMODEUOG_WR(v)     (HW_USBC__USBMODEUOG.U = (v))
#define HW_USBC__USBMODEUOG_SET(v)    (HW_USBC__USBMODEUOG_WR(HW_USBC__USBMODEUOG_RD() |  (v)))
#define HW_USBC__USBMODEUOG_CLR(v)    (HW_USBC__USBMODEUOG_WR(HW_USBC__USBMODEUOG_RD() & ~(v)))
#define HW_USBC__USBMODEUOG_TOG(v)    (HW_USBC__USBMODEUOG_WR(HW_USBC__USBMODEUOG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBMODEUOG bitfields
 */

/* --- Register HW_USBC__USBMODEUOG, field CM[1:0] (RW)
 *
 * Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device
 * only implementations. For those designs that contain both host & device capability, the
 * controller defaults to an idle state and needs to be initialized to the desired operating mode
 * after reset. For combination host/device controllers, this register can only be written once
 * after reset. If it is necessary to switch modes, software must reset the controller by writing to
 * the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core,
 * reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
 *
 * Values:
 * 00 - Idle [Default for combination host/device]
 * 01 - Reserved
 * 10 - Device Controller [Default for device only controller]
 * 11 - Host Controller [Default for host only controller]
 */

#define BP_USBC__USBMODEUOG_CM      (0)
#define BM_USBC__USBMODEUOG_CM      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUOG_CM(v)   ((((reg32_t) v) << 0) & BM_USBC__USBMODEUOG_CM)
#else
#define BF_USBC__USBMODEUOG_CM(v)   (((v) << 0) & BM_USBC__USBMODEUOG_CM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CM field to a new value.
#define BW_USBC__USBMODEUOG_CM(v)   BF_CS1(USBC__USBMODEUOG, CM, v)
#endif


/* --- Register HW_USBC__USBMODEUOG, field ES[2:2] (RW)
 *
 * Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to
 * match the host microprocessor. The bit fields in the microprocessor interface and the data
 * structures are unaffected by the value of this bit because they are based upon the 32-bit word.
 * Bit Meaning
 *
 * Values:
 * 0 - Little Endian [Default]
 * 1 - Big Endian
 */

#define BP_USBC__USBMODEUOG_ES      (2)
#define BM_USBC__USBMODEUOG_ES      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUOG_ES(v)   ((((reg32_t) v) << 2) & BM_USBC__USBMODEUOG_ES)
#else
#define BF_USBC__USBMODEUOG_ES(v)   (((v) << 2) & BM_USBC__USBMODEUOG_ES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ES field to a new value.
#define BW_USBC__USBMODEUOG_ES(v)   BF_CS1(USBC__USBMODEUOG, ES, v)
#endif


/* --- Register HW_USBC__USBMODEUOG, field SLOM[3:3] (RW)
 *
 * Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
 *
 * Values:
 * 0 - Setup Lockouts On (default);
 * 1 - Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in .
 */

#define BP_USBC__USBMODEUOG_SLOM      (3)
#define BM_USBC__USBMODEUOG_SLOM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUOG_SLOM(v)   ((((reg32_t) v) << 3) & BM_USBC__USBMODEUOG_SLOM)
#else
#define BF_USBC__USBMODEUOG_SLOM(v)   (((v) << 3) & BM_USBC__USBMODEUOG_SLOM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLOM field to a new value.
#define BW_USBC__USBMODEUOG_SLOM(v)   BF_CS1(USBC__USBMODEUOG, SLOM, v)
#endif


/* --- Register HW_USBC__USBMODEUOG, field SDIS[4:4] (RW)
 *
 * Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables
 * double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX
 * and TX buffers are sufficient to contain an entire packet that the standard double buffering
 * scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High
 * Speed Mode, all packets received are responded to with a NYET handshake when stream disable is
 * active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are
 * eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the
 * entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled
 * to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO
 * becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to
 * characterize the adjustments needed for the scheduler when using this feature. The use of this
 * feature substantially limits of the overall USB performance that can be achieved.
 */

#define BP_USBC__USBMODEUOG_SDIS      (4)
#define BM_USBC__USBMODEUOG_SDIS      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUOG_SDIS(v)   ((((reg32_t) v) << 4) & BM_USBC__USBMODEUOG_SDIS)
#else
#define BF_USBC__USBMODEUOG_SDIS(v)   (((v) << 4) & BM_USBC__USBMODEUOG_SDIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SDIS field to a new value.
#define BW_USBC__USBMODEUOG_SDIS(v)   BF_CS1(USBC__USBMODEUOG, SDIS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTSETUPSTAT - Endpoint Setup Status (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENDPTSETUPSTAT : 16; //!< Setup Endpoint Status. For every setup transaction that is received, a corresponding bit in this register is set to one. Software must clear or acknowledge the setup transfer by writing a one to a respective bit after it has read the setup data from Queue head. The response to a setup packet as in the order of operations and total response time is crucial to limit bus time outs while the setup lock our mechanism is engaged. See in the Device Operational Model. This register is only used in device mode.
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

/* --- Register HW_USBC_UOG_ENDPTSETUPSTAT, field ENDPTSETUPSTAT[15:0] (RW)
 *
 * Setup Endpoint Status. For every setup transaction that is received, a corresponding bit in this
 * register is set to one. Software must clear or acknowledge the setup transfer by writing a one to
 * a respective bit after it has read the setup data from Queue head. The response to a setup packet
 * as in the order of operations and total response time is crucial to limit bus time outs while the
 * setup lock our mechanism is engaged. See in the Device Operational Model. This register is only
 * used in device mode.
 */

#define BP_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT      (0)
#define BM_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT)
#else
#define BF_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT(v)   (((v) << 0) & BM_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPTSETUPSTAT field to a new value.
#define BW_USBC_UOG_ENDPTSETUPSTAT_ENDPTSETUPSTAT(v)   BF_CS1(USBC_UOG_ENDPTSETUPSTAT, ENDPTSETUPSTAT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTPRIME - Endpoint Initialization (RW)
 *
 * This register is only used in device mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PERB : 8; //!< Prime Endpoint Receive Buffer - R/WS. For each endpoint, a corresponding bit is used to request a buffer prepare for a receive operation for when a USB host initiates a USB OUT transaction. Software should write a one to the corresponding bit whenever posting a new transfer descriptor to an endpoint. Hardware automatically uses this bit to begin parsing for a new transfer descriptor from the queue head and prepare a receive buffer. Hardware clears this bit when the associated endpoint(s) is (are) successfully primed. These bits are momentarily set by hardware during hardware re-priming operations when a dTD is retired, and the dQH is updated. PERB[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned PETB : 8; //!< Prime Endpoint Transmit Buffer - R/WS. For each endpoint a corresponding bit is used to request that a buffer prepared for a transmit operation in order to respond to a USB IN/INTERRUPT transaction. Software should write a one to the corresponding bit when posting a new transfer descriptor to an endpoint. Hardware automatically uses this bit to begin parsing for a new transfer descriptor from the queue head and prepare a transmit buffer. Hardware clears this bit when the associated endpoint(s) is (are) successfully primed. These bits are momentarily set by hardware during hardware re-priming operations when a dTD is retired, and the dQH is updated. PETB[N] - Endpoint #N, N is in 0..7
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

/* --- Register HW_USBC_UOG_ENDPTPRIME, field PERB[7:0] (RW)
 *
 * Prime Endpoint Receive Buffer - R/WS. For each endpoint, a corresponding bit is used to request a
 * buffer prepare for a receive operation for when a USB host initiates a USB OUT transaction.
 * Software should write a one to the corresponding bit whenever posting a new transfer descriptor
 * to an endpoint. Hardware automatically uses this bit to begin parsing for a new transfer
 * descriptor from the queue head and prepare a receive buffer. Hardware clears this bit when the
 * associated endpoint(s) is (are) successfully primed. These bits are momentarily set by hardware
 * during hardware re-priming operations when a dTD is retired, and the dQH is updated. PERB[N] -
 * Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTPRIME_PERB      (0)
#define BM_USBC_UOG_ENDPTPRIME_PERB      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTPRIME_PERB(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTPRIME_PERB)
#else
#define BF_USBC_UOG_ENDPTPRIME_PERB(v)   (((v) << 0) & BM_USBC_UOG_ENDPTPRIME_PERB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PERB field to a new value.
#define BW_USBC_UOG_ENDPTPRIME_PERB(v)   BF_CS1(USBC_UOG_ENDPTPRIME, PERB, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTPRIME, field PETB[23:16] (RW)
 *
 * Prime Endpoint Transmit Buffer - R/WS. For each endpoint a corresponding bit is used to request
 * that a buffer prepared for a transmit operation in order to respond to a USB IN/INTERRUPT
 * transaction. Software should write a one to the corresponding bit when posting a new transfer
 * descriptor to an endpoint. Hardware automatically uses this bit to begin parsing for a new
 * transfer descriptor from the queue head and prepare a transmit buffer. Hardware clears this bit
 * when the associated endpoint(s) is (are) successfully primed. These bits are momentarily set by
 * hardware during hardware re-priming operations when a dTD is retired, and the dQH is updated.
 * PETB[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTPRIME_PETB      (16)
#define BM_USBC_UOG_ENDPTPRIME_PETB      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTPRIME_PETB(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTPRIME_PETB)
#else
#define BF_USBC_UOG_ENDPTPRIME_PETB(v)   (((v) << 16) & BM_USBC_UOG_ENDPTPRIME_PETB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PETB field to a new value.
#define BW_USBC_UOG_ENDPTPRIME_PETB(v)   BF_CS1(USBC_UOG_ENDPTPRIME, PETB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTFLUSH - Endpoint De-Initialize (RW)
 *
 * This register is only used in device mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FERB : 8; //!< Flush Endpoint Receive Buffer - R/WS. Writing one to a bit(s) causes the assocUOGiated endpoint(s) to clear any primed buffers. If a packet is in progress for one of the associated endpoints, then that transfer continues until completion. Hardware clears this register after the endpoint flush operation is successful. FERB[N] - Endpoint #N, N is in 0..7\
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned FETB : 8; //!< Flush Endpoint Transmit Buffer - R/WS. Writing one to a bit(s) in this register causes the associated endpoint(s) to clear any primed buffers. If a packet is in progress for one of the associated endpoints, then that transfer continues until completion. Hardware clears this register after the endpoint flush operation is successful. FETB[N] - Endpoint #N, N is in 0..7
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

/* --- Register HW_USBC_UOG_ENDPTFLUSH, field FERB[7:0] (RW)
 *
 * Flush Endpoint Receive Buffer - R/WS. Writing one to a bit(s) causes the assocUOGiated
 * endpoint(s) to clear any primed buffers. If a packet is in progress for one of the associated
 * endpoints, then that transfer continues until completion. Hardware clears this register after the
 * endpoint flush operation is successful. FERB[N] - Endpoint #N, N is in 0..7\
 */

#define BP_USBC_UOG_ENDPTFLUSH_FERB      (0)
#define BM_USBC_UOG_ENDPTFLUSH_FERB      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTFLUSH_FERB(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTFLUSH_FERB)
#else
#define BF_USBC_UOG_ENDPTFLUSH_FERB(v)   (((v) << 0) & BM_USBC_UOG_ENDPTFLUSH_FERB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FERB field to a new value.
#define BW_USBC_UOG_ENDPTFLUSH_FERB(v)   BF_CS1(USBC_UOG_ENDPTFLUSH, FERB, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTFLUSH, field FETB[23:16] (RW)
 *
 * Flush Endpoint Transmit Buffer - R/WS. Writing one to a bit(s) in this register causes the
 * associated endpoint(s) to clear any primed buffers. If a packet is in progress for one of the
 * associated endpoints, then that transfer continues until completion. Hardware clears this
 * register after the endpoint flush operation is successful. FETB[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTFLUSH_FETB      (16)
#define BM_USBC_UOG_ENDPTFLUSH_FETB      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTFLUSH_FETB(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTFLUSH_FETB)
#else
#define BF_USBC_UOG_ENDPTFLUSH_FETB(v)   (((v) << 16) & BM_USBC_UOG_ENDPTFLUSH_FETB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FETB field to a new value.
#define BW_USBC_UOG_ENDPTFLUSH_FETB(v)   BF_CS1(USBC_UOG_ENDPTFLUSH, FETB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTSTAT - Endpoint Status (RO)
 *
 * This register is only used in device mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ERBR : 8; //!< Endpoint Receive Buffer Ready -- Read Only. One bit for each endpoint indicates status of the respective endpoint buffer. This bit is set to a one by the hardware as a response to receiving a command from a corresponding bit in the ENDPRIME register. There is always a delay between setting a bit in the ENDPRIME register and endpoint indicating ready. This delay time varies based upon the current USB traffic and the number of bits set in the ENDPRIME register. Buffer ready is cleared by USB reset, by the USB DMA system, or through the ENDPTFLUSH register. These bits are momentarily cleared by hardware during hardware endpoint re-priming operations when a dTD is retired, and the dQH is updated. ERBR[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned ETBR : 8; //!< Endpoint Transmit Buffer Ready -- Read Only. One bit for each endpoint indicates status of the respective endpoint buffer. This bit is set to one by the hardware as a response to receiving a command from a corresponding bit in the ENDPTPRIME register. There is always a delay between setting a bit in the ENDPTPRIME register and endpoint indicating ready. This delay time varies based upon the current USB traffic and the number of bits set in the ENDPRIME register. Buffer ready is cleared by USB reset, by the USB DMA system, or through the ENDPTFLUSH register. These bits are momentarily cleared by hardware during hardware endpoint re-priming operations when a dTD is retired, and the dQH is updated. ETBR[N] - Endpoint #N, N is in 0..7
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
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTSTAT bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTSTAT, field ERBR[7:0] (RO)
 *
 * Endpoint Receive Buffer Ready -- Read Only. One bit for each endpoint indicates status of the
 * respective endpoint buffer. This bit is set to a one by the hardware as a response to receiving a
 * command from a corresponding bit in the ENDPRIME register. There is always a delay between
 * setting a bit in the ENDPRIME register and endpoint indicating ready. This delay time varies
 * based upon the current USB traffic and the number of bits set in the ENDPRIME register. Buffer
 * ready is cleared by USB reset, by the USB DMA system, or through the ENDPTFLUSH register. These
 * bits are momentarily cleared by hardware during hardware endpoint re-priming operations when a
 * dTD is retired, and the dQH is updated. ERBR[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTSTAT_ERBR      (0)
#define BM_USBC_UOG_ENDPTSTAT_ERBR      (0x000000ff)

/* --- Register HW_USBC_UOG_ENDPTSTAT, field ETBR[23:16] (RO)
 *
 * Endpoint Transmit Buffer Ready -- Read Only. One bit for each endpoint indicates status of the
 * respective endpoint buffer. This bit is set to one by the hardware as a response to receiving a
 * command from a corresponding bit in the ENDPTPRIME register. There is always a delay between
 * setting a bit in the ENDPTPRIME register and endpoint indicating ready. This delay time varies
 * based upon the current USB traffic and the number of bits set in the ENDPRIME register. Buffer
 * ready is cleared by USB reset, by the USB DMA system, or through the ENDPTFLUSH register. These
 * bits are momentarily cleared by hardware during hardware endpoint re-priming operations when a
 * dTD is retired, and the dQH is updated. ETBR[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTSTAT_ETBR      (16)
#define BM_USBC_UOG_ENDPTSTAT_ETBR      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCOMPLETE - Endpoint Complete (RW)
 *
 * This register is only used in device mode.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ERCE : 8; //!< Endpoint Receive Complete Event - RW/C. Each bit indicates a received event (OUT/SETUP) occurred and software should read the corresponding endpoint queue to determine the transfer status. If the corresponding IOC bit is set in the Transfer Descriptor, then this bit is set simultaneously with the USBINT . Writing one clears the corresponding bit in this register. ERCE[N] - Endpoint #N, N is in 0..7
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned ETCE : 8; //!< Endpoint Transmit Complete Event - R/WC. Each bit indicates a transmit event (IN/INTERRUPT) occurred and software should read the corresponding endpoint queue to determine the endpoint status. If the corresponding IOC bit is set in the Transfer Descriptor, then this bit is set simultaneously with the USBINT . Writing one clears the corresponding bit in this register. ETCE[N] - Endpoint #N, N is in 0..7
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

/* --- Register HW_USBC_UOG_ENDPTCOMPLETE, field ERCE[7:0] (RW)
 *
 * Endpoint Receive Complete Event - RW/C. Each bit indicates a received event (OUT/SETUP) occurred
 * and software should read the corresponding endpoint queue to determine the transfer status. If
 * the corresponding IOC bit is set in the Transfer Descriptor, then this bit is set simultaneously
 * with the USBINT . Writing one clears the corresponding bit in this register. ERCE[N] - Endpoint
 * #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTCOMPLETE_ERCE      (0)
#define BM_USBC_UOG_ENDPTCOMPLETE_ERCE      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCOMPLETE_ERCE(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCOMPLETE_ERCE)
#else
#define BF_USBC_UOG_ENDPTCOMPLETE_ERCE(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCOMPLETE_ERCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERCE field to a new value.
#define BW_USBC_UOG_ENDPTCOMPLETE_ERCE(v)   BF_CS1(USBC_UOG_ENDPTCOMPLETE, ERCE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCOMPLETE, field ETCE[23:16] (RW)
 *
 * Endpoint Transmit Complete Event - R/WC. Each bit indicates a transmit event (IN/INTERRUPT)
 * occurred and software should read the corresponding endpoint queue to determine the endpoint
 * status. If the corresponding IOC bit is set in the Transfer Descriptor, then this bit is set
 * simultaneously with the USBINT . Writing one clears the corresponding bit in this register.
 * ETCE[N] - Endpoint #N, N is in 0..7
 */

#define BP_USBC_UOG_ENDPTCOMPLETE_ETCE      (16)
#define BM_USBC_UOG_ENDPTCOMPLETE_ETCE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCOMPLETE_ETCE(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCOMPLETE_ETCE)
#else
#define BF_USBC_UOG_ENDPTCOMPLETE_ETCE(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCOMPLETE_ETCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ETCE field to a new value.
#define BW_USBC_UOG_ENDPTCOMPLETE_ETCE(v)   BF_CS1(USBC_UOG_ENDPTCOMPLETE, ETCE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL0 - Endpoint Control0 (RW)
 *
 * Every Device implements Endpoint 0 as a control endpoint.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues returning STALL until the bit is cleared by software or it is automatically cleared upon receipt of a new SETUP request.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control Endpoint0 is fixed as a Control End Point.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned RXE : 1; //!< RX Endpoint Enable 1 Enabled Endpoint0 is always enabled.
        unsigned RESERVED2 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK [Default] 1 End Point Stalled Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues returning STALL until the bit is cleared by software or it is automatically cleared upon receipt of a new SETUP request.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 - Control Endpoint0 is fixed as a Control End Point.
        unsigned RESERVED4 : 3; //!< Reserved
        unsigned TXE : 1; //!< TX Endpoint Enable 1 Enabled Endpoint0 is always enabled.
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

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled Software can write a
 * one to this bit to force the endpoint to return a STALL handshake to the Host. It continues
 * returning STALL until the bit is cleared by software or it is automatically cleared upon receipt
 * of a new SETUP request.
 */

#define BP_USBC_UOG_ENDPTCTRL0_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL0_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL0_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL0_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL0_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL0_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control Endpoint0 is fixed as a Control End Point.
 */

#define BP_USBC_UOG_ENDPTCTRL0_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL0_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL0_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL0_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL0_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL0_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 1 Enabled Endpoint0 is always enabled.
 */

#define BP_USBC_UOG_ENDPTCTRL0_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL0_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL0_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL0_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL0_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL0_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK [Default] 1 End Point Stalled Software can write a
 * one to this bit to force the endpoint to return a STALL handshake to the Host. It continues
 * returning STALL until the bit is cleared by software or it is automatically cleared upon receipt
 * of a new SETUP request.
 */

#define BP_USBC_UOG_ENDPTCTRL0_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL0_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL0_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL0_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL0_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL0_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 - Control Endpoint0 is fixed as a Control End Point.
 */

#define BP_USBC_UOG_ENDPTCTRL0_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL0_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL0_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL0_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL0_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL0_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL0, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 1 Enabled Endpoint0 is always enabled.
 */

#define BP_USBC_UOG_ENDPTCTRL0_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL0_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL0_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL0_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL0_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL0_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL0_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL0, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL1 - Endpoint Controln 1 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl1_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL1 register
 */
#define HW_USBC_UOG_ENDPTCTRL1_ADDR      (REGS_USBC_BASE + 0x1c4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL1           (*(volatile hw_usbc_uog_endptctrl1_t *) HW_USBC_UOG_ENDPTCTRL1_ADDR)
#define HW_USBC_UOG_ENDPTCTRL1_RD()      (HW_USBC_UOG_ENDPTCTRL1.U)
#define HW_USBC_UOG_ENDPTCTRL1_WR(v)     (HW_USBC_UOG_ENDPTCTRL1.U = (v))
#define HW_USBC_UOG_ENDPTCTRL1_SET(v)    (HW_USBC_UOG_ENDPTCTRL1_WR(HW_USBC_UOG_ENDPTCTRL1_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL1_CLR(v)    (HW_USBC_UOG_ENDPTCTRL1_WR(HW_USBC_UOG_ENDPTCTRL1_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL1_TOG(v)    (HW_USBC_UOG_ENDPTCTRL1_WR(HW_USBC_UOG_ENDPTCTRL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL1 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL1_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL1_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL1_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL1_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL1_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL1_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL1_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL1_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL1_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL1_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL1_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL1_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL1_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL1_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL1_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL1_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL1_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL1_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL1_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL1_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL1_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL1_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL1_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL1_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL1_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL1_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL1_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL1_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL1_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL1_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL1_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL1_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL1_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL1_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL1_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL1_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL1_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL1_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL1_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL1_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL1_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL1_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL1_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL1_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL1_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL1_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL1_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL1_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL1_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL1_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL1_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL1_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL1_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL1_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL1_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL1, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL1_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL1_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL1_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL1_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL1_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL1_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL1_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL1, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL2 - Endpoint Controln 2 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl2_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL2 register
 */
#define HW_USBC_UOG_ENDPTCTRL2_ADDR      (REGS_USBC_BASE + 0x1c8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL2           (*(volatile hw_usbc_uog_endptctrl2_t *) HW_USBC_UOG_ENDPTCTRL2_ADDR)
#define HW_USBC_UOG_ENDPTCTRL2_RD()      (HW_USBC_UOG_ENDPTCTRL2.U)
#define HW_USBC_UOG_ENDPTCTRL2_WR(v)     (HW_USBC_UOG_ENDPTCTRL2.U = (v))
#define HW_USBC_UOG_ENDPTCTRL2_SET(v)    (HW_USBC_UOG_ENDPTCTRL2_WR(HW_USBC_UOG_ENDPTCTRL2_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL2_CLR(v)    (HW_USBC_UOG_ENDPTCTRL2_WR(HW_USBC_UOG_ENDPTCTRL2_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL2_TOG(v)    (HW_USBC_UOG_ENDPTCTRL2_WR(HW_USBC_UOG_ENDPTCTRL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL2 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL2_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL2_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL2_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL2_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL2_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL2_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL2_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL2_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL2_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL2_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL2_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL2_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL2_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL2_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL2_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL2_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL2_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL2_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL2_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL2_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL2_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL2_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL2_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL2_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL2_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL2_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL2_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL2_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL2_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL2_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL2_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL2_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL2_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL2_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL2_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL2_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL2_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL2_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL2_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL2_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL2_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL2_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL2_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL2_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL2_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL2_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL2_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL2_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL2_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL2_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL2_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL2_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL2_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL2_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL2_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL2, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL2_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL2_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL2_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL2_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL2_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL2_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL2_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL2, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL3 - Endpoint Controln 3 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl3_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL3 register
 */
#define HW_USBC_UOG_ENDPTCTRL3_ADDR      (REGS_USBC_BASE + 0x1cc)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL3           (*(volatile hw_usbc_uog_endptctrl3_t *) HW_USBC_UOG_ENDPTCTRL3_ADDR)
#define HW_USBC_UOG_ENDPTCTRL3_RD()      (HW_USBC_UOG_ENDPTCTRL3.U)
#define HW_USBC_UOG_ENDPTCTRL3_WR(v)     (HW_USBC_UOG_ENDPTCTRL3.U = (v))
#define HW_USBC_UOG_ENDPTCTRL3_SET(v)    (HW_USBC_UOG_ENDPTCTRL3_WR(HW_USBC_UOG_ENDPTCTRL3_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL3_CLR(v)    (HW_USBC_UOG_ENDPTCTRL3_WR(HW_USBC_UOG_ENDPTCTRL3_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL3_TOG(v)    (HW_USBC_UOG_ENDPTCTRL3_WR(HW_USBC_UOG_ENDPTCTRL3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL3 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL3_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL3_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL3_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL3_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL3_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL3_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL3_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL3_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL3_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL3_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL3_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL3_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL3_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL3_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL3_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL3_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL3_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL3_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL3_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL3_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL3_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL3_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL3_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL3_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL3_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL3_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL3_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL3_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL3_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL3_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL3_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL3_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL3_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL3_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL3_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL3_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL3_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL3_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL3_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL3_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL3_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL3_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL3_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL3_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL3_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL3_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL3_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL3_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL3_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL3_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL3_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL3_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL3_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL3_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL3_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL3, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL3_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL3_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL3_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL3_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL3_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL3_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL3_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL3, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL4 - Endpoint Controln 4 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl4_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL4 register
 */
#define HW_USBC_UOG_ENDPTCTRL4_ADDR      (REGS_USBC_BASE + 0x1d0)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL4           (*(volatile hw_usbc_uog_endptctrl4_t *) HW_USBC_UOG_ENDPTCTRL4_ADDR)
#define HW_USBC_UOG_ENDPTCTRL4_RD()      (HW_USBC_UOG_ENDPTCTRL4.U)
#define HW_USBC_UOG_ENDPTCTRL4_WR(v)     (HW_USBC_UOG_ENDPTCTRL4.U = (v))
#define HW_USBC_UOG_ENDPTCTRL4_SET(v)    (HW_USBC_UOG_ENDPTCTRL4_WR(HW_USBC_UOG_ENDPTCTRL4_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL4_CLR(v)    (HW_USBC_UOG_ENDPTCTRL4_WR(HW_USBC_UOG_ENDPTCTRL4_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL4_TOG(v)    (HW_USBC_UOG_ENDPTCTRL4_WR(HW_USBC_UOG_ENDPTCTRL4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL4 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL4_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL4_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL4_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL4_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL4_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL4_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL4_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL4_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL4_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL4_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL4_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL4_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL4_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL4_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL4_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL4_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL4_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL4_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL4_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL4_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL4_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL4_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL4_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL4_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL4_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL4_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL4_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL4_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL4_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL4_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL4_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL4_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL4_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL4_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL4_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL4_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL4_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL4_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL4_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL4_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL4_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL4_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL4_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL4_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL4_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL4_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL4_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL4_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL4_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL4_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL4_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL4_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL4_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL4_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL4_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL4, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL4_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL4_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL4_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL4_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL4_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL4_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL4_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL4, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL5 - Endpoint Controln 5 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl5_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL5 register
 */
#define HW_USBC_UOG_ENDPTCTRL5_ADDR      (REGS_USBC_BASE + 0x1d4)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL5           (*(volatile hw_usbc_uog_endptctrl5_t *) HW_USBC_UOG_ENDPTCTRL5_ADDR)
#define HW_USBC_UOG_ENDPTCTRL5_RD()      (HW_USBC_UOG_ENDPTCTRL5.U)
#define HW_USBC_UOG_ENDPTCTRL5_WR(v)     (HW_USBC_UOG_ENDPTCTRL5.U = (v))
#define HW_USBC_UOG_ENDPTCTRL5_SET(v)    (HW_USBC_UOG_ENDPTCTRL5_WR(HW_USBC_UOG_ENDPTCTRL5_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL5_CLR(v)    (HW_USBC_UOG_ENDPTCTRL5_WR(HW_USBC_UOG_ENDPTCTRL5_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL5_TOG(v)    (HW_USBC_UOG_ENDPTCTRL5_WR(HW_USBC_UOG_ENDPTCTRL5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL5 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL5_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL5_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL5_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL5_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL5_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL5_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL5_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL5_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL5_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL5_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL5_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL5_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL5_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL5_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL5_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL5_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL5_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL5_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL5_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL5_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL5_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL5_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL5_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL5_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL5_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL5_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL5_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL5_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL5_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL5_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL5_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL5_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL5_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL5_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL5_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL5_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL5_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL5_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL5_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL5_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL5_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL5_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL5_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL5_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL5_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL5_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL5_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL5_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL5_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL5_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL5_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL5_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL5_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL5_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL5_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL5, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL5_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL5_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL5_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL5_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL5_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL5_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL5_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL5, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL6 - Endpoint Controln 6 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl6_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL6 register
 */
#define HW_USBC_UOG_ENDPTCTRL6_ADDR      (REGS_USBC_BASE + 0x1d8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL6           (*(volatile hw_usbc_uog_endptctrl6_t *) HW_USBC_UOG_ENDPTCTRL6_ADDR)
#define HW_USBC_UOG_ENDPTCTRL6_RD()      (HW_USBC_UOG_ENDPTCTRL6.U)
#define HW_USBC_UOG_ENDPTCTRL6_WR(v)     (HW_USBC_UOG_ENDPTCTRL6.U = (v))
#define HW_USBC_UOG_ENDPTCTRL6_SET(v)    (HW_USBC_UOG_ENDPTCTRL6_WR(HW_USBC_UOG_ENDPTCTRL6_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL6_CLR(v)    (HW_USBC_UOG_ENDPTCTRL6_WR(HW_USBC_UOG_ENDPTCTRL6_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL6_TOG(v)    (HW_USBC_UOG_ENDPTCTRL6_WR(HW_USBC_UOG_ENDPTCTRL6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL6 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL6_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL6_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL6_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL6_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL6_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL6_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL6_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL6_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL6_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL6_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL6_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL6_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL6_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL6_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL6_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL6_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL6_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL6_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL6_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL6_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL6_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL6_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL6_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL6_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL6_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL6_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL6_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL6_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL6_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL6_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL6_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL6_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL6_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL6_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL6_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL6_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL6_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL6_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL6_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL6_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL6_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL6_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL6_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL6_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL6_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL6_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL6_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL6_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL6_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL6_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL6_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL6_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL6_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL6_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL6_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL6, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL6_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL6_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL6_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL6_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL6_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL6_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL6_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL6, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC_UOG_ENDPTCTRL7 - Endpoint Controln 7 (RW)
 *
 * There is a UOG_ENDPTCTRLx register for each endpoint in a device.  If one endpoint direction is
 * enabled and the paired endpoint of opposite direction is disabled then the unused direction type
 * must be changed from the default control-type to any other type (that is Bulk-type). leaving an
 * unconfigured endpoint control causes undefined behavior for the data pid tracking on the active
 * endpoint/direction.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXS : 1; //!< RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above.
        unsigned RXD : 1; //!< RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should always be written as zero.
        unsigned RXT : 2; //!< RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned RXI : 1; //!< RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always accept data packet regardless of their data PID.
        unsigned RXR : 1; //!< RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the host and device.
        unsigned RXE : 1; //!< RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned TXS : 1; //!< TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by software or automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is not set immediately after writing a '1' to it. Please follow this procedure: continually write this STALL bit until it is set or until a new setup has ben received by checking the associated ENDPTSETUPSTAT bit.
        unsigned TXD : 1; //!< TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always be written as 0.
        unsigned TXT : 2; //!< TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TXI : 1; //!< TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is only used for test and should always be written as zero. Writing a one to this bit causes this endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
        unsigned TXR : 1; //!< TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received for this Endpoint, software must write a one to this bit in order to synchronize the data PID's between the Host and device.
        unsigned TXE : 1; //!< TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has been configured.
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc_uog_endptctrl7_t;
#endif

/*
 * constants & macros for entire USBC_UOG_ENDPTCTRL7 register
 */
#define HW_USBC_UOG_ENDPTCTRL7_ADDR      (REGS_USBC_BASE + 0x1dc)

#ifndef __LANGUAGE_ASM__
#define HW_USBC_UOG_ENDPTCTRL7           (*(volatile hw_usbc_uog_endptctrl7_t *) HW_USBC_UOG_ENDPTCTRL7_ADDR)
#define HW_USBC_UOG_ENDPTCTRL7_RD()      (HW_USBC_UOG_ENDPTCTRL7.U)
#define HW_USBC_UOG_ENDPTCTRL7_WR(v)     (HW_USBC_UOG_ENDPTCTRL7.U = (v))
#define HW_USBC_UOG_ENDPTCTRL7_SET(v)    (HW_USBC_UOG_ENDPTCTRL7_WR(HW_USBC_UOG_ENDPTCTRL7_RD() |  (v)))
#define HW_USBC_UOG_ENDPTCTRL7_CLR(v)    (HW_USBC_UOG_ENDPTCTRL7_WR(HW_USBC_UOG_ENDPTCTRL7_RD() & ~(v)))
#define HW_USBC_UOG_ENDPTCTRL7_TOG(v)    (HW_USBC_UOG_ENDPTCTRL7_WR(HW_USBC_UOG_ENDPTCTRL7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC_UOG_ENDPTCTRL7 bitfields
 */

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field RXS[0:0] (RW)
 *
 * RX Endpoint Stall - Read/Write 0 End Point OK. [Default] 1 End Point Stalled This bit is set
 * automatically upon receipt of a SETUP request if this Endpoint is not configured as a Control
 * Endpoint. It is cleared automatically upon receipt a SETUP request if this Endpoint is configured
 * as a Control Endpoint, Software can write a one to this bit to force the endpoint to return a
 * STALL handshake to the Host. It continues to returning STALL until this bit is either cleared by
 * software or automatically cleared as above.
 */

#define BP_USBC_UOG_ENDPTCTRL7_RXS      (0)
#define BM_USBC_UOG_ENDPTCTRL7_RXS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_RXS(v)   ((((reg32_t) v) << 0) & BM_USBC_UOG_ENDPTCTRL7_RXS)
#else
#define BF_USBC_UOG_ENDPTCTRL7_RXS(v)   (((v) << 0) & BM_USBC_UOG_ENDPTCTRL7_RXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_RXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, RXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field RXD[1:1] (RW)
 *
 * RX Endpoint Data Sink - Read/Write - TBD 0 Dual Port Memory Buffer/DMA Engine [Default] Should
 * always be written as zero.
 */

#define BP_USBC_UOG_ENDPTCTRL7_RXD      (1)
#define BM_USBC_UOG_ENDPTCTRL7_RXD      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_RXD(v)   ((((reg32_t) v) << 1) & BM_USBC_UOG_ENDPTCTRL7_RXD)
#else
#define BF_USBC_UOG_ENDPTCTRL7_RXD(v)   (((v) << 1) & BM_USBC_UOG_ENDPTCTRL7_RXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_RXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, RXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field RXT[3:2] (RW)
 *
 * RX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Reserved
 */

#define BP_USBC_UOG_ENDPTCTRL7_RXT      (2)
#define BM_USBC_UOG_ENDPTCTRL7_RXT      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_RXT(v)   ((((reg32_t) v) << 2) & BM_USBC_UOG_ENDPTCTRL7_RXT)
#else
#define BF_USBC_UOG_ENDPTCTRL7_RXT(v)   (((v) << 2) & BM_USBC_UOG_ENDPTCTRL7_RXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_RXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, RXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field RXI[5:5] (RW)
 *
 * RX Data Toggle Inhibit 0 Disabled [Default] 1 Enabled This bit is only used for test and should
 * always be written as zero. Writing a one to this bit causes this endpoint to ignore the data
 * toggle sequence and always accept data packet regardless of their data PID.
 */

#define BP_USBC_UOG_ENDPTCTRL7_RXI      (5)
#define BM_USBC_UOG_ENDPTCTRL7_RXI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_RXI(v)   ((((reg32_t) v) << 5) & BM_USBC_UOG_ENDPTCTRL7_RXI)
#else
#define BF_USBC_UOG_ENDPTCTRL7_RXI(v)   (((v) << 5) & BM_USBC_UOG_ENDPTCTRL7_RXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_RXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, RXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field RXR[6:6] (RW)
 *
 * RX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL7_RXR      (6)
#define BM_USBC_UOG_ENDPTCTRL7_RXR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_RXR(v)   ((((reg32_t) v) << 6) & BM_USBC_UOG_ENDPTCTRL7_RXR)
#else
#define BF_USBC_UOG_ENDPTCTRL7_RXR(v)   (((v) << 6) & BM_USBC_UOG_ENDPTCTRL7_RXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_RXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, RXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field RXE[7:7] (RW)
 *
 * RX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL7_RXE      (7)
#define BM_USBC_UOG_ENDPTCTRL7_RXE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_RXE(v)   ((((reg32_t) v) << 7) & BM_USBC_UOG_ENDPTCTRL7_RXE)
#else
#define BF_USBC_UOG_ENDPTCTRL7_RXE(v)   (((v) << 7) & BM_USBC_UOG_ENDPTCTRL7_RXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_RXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, RXE, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field TXS[16:16] (RW)
 *
 * TX Endpoint Stall - Read/Write 0 End Point OK 1 End Point Stalled This bit is set automatically
 * upon receipt of a SETUP request if this Endpoint is not configured as a Control Endpoint. It is
 * cleared automatically upon receipt of a SETUP request if this Endpoint is configured as a Control
 * Endpoint. Software can write a one to this bit to force the endpoint to return a STALL handshake
 * to the Host. It continues to returning STALL until this bit is either cleared by software or
 * automatically cleared as above. For CONTROL type endpoint, there is a slight delay (50 clocks
 * max) between the ENDPTSETUPSTAT begin cleared and hardware continuing to clear this bit. In most
 * systems, it is unlikely the DCD software will observe this delay. Take care that the STALL bit is
 * not set immediately after writing a '1' to it. Please follow this procedure: continually write
 * this STALL bit until it is set or until a new setup has ben received by checking the associated
 * ENDPTSETUPSTAT bit.
 */

#define BP_USBC_UOG_ENDPTCTRL7_TXS      (16)
#define BM_USBC_UOG_ENDPTCTRL7_TXS      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_TXS(v)   ((((reg32_t) v) << 16) & BM_USBC_UOG_ENDPTCTRL7_TXS)
#else
#define BF_USBC_UOG_ENDPTCTRL7_TXS(v)   (((v) << 16) & BM_USBC_UOG_ENDPTCTRL7_TXS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXS field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_TXS(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, TXS, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field TXD[17:17] (RW)
 *
 * TX Endpoint Data Source - Read/Write 0 Dual Port Memory Buffer/DMA Engine [DEFAULT] Should always
 * be written as 0.
 */

#define BP_USBC_UOG_ENDPTCTRL7_TXD      (17)
#define BM_USBC_UOG_ENDPTCTRL7_TXD      (0x00020000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_TXD(v)   ((((reg32_t) v) << 17) & BM_USBC_UOG_ENDPTCTRL7_TXD)
#else
#define BF_USBC_UOG_ENDPTCTRL7_TXD(v)   (((v) << 17) & BM_USBC_UOG_ENDPTCTRL7_TXD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXD field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_TXD(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, TXD, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field TXT[19:18] (RW)
 *
 * TX Endpoint Type - Read/Write 00 Control 01 Isochronous 10 Bulk 11 Interrupt
 */

#define BP_USBC_UOG_ENDPTCTRL7_TXT      (18)
#define BM_USBC_UOG_ENDPTCTRL7_TXT      (0x000c0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_TXT(v)   ((((reg32_t) v) << 18) & BM_USBC_UOG_ENDPTCTRL7_TXT)
#else
#define BF_USBC_UOG_ENDPTCTRL7_TXT(v)   (((v) << 18) & BM_USBC_UOG_ENDPTCTRL7_TXT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXT field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_TXT(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, TXT, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field TXI[21:21] (RW)
 *
 * TX Data Toggle Inhibit 0 PID Sequencing Enabled. [Default] 1 PID Sequencing Disabled. This bit is
 * only used for test and should always be written as zero. Writing a one to this bit causes this
 * endpoint to ignore the data toggle sequence and always transmit DATA0 for a data packet.
 */

#define BP_USBC_UOG_ENDPTCTRL7_TXI      (21)
#define BM_USBC_UOG_ENDPTCTRL7_TXI      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_TXI(v)   ((((reg32_t) v) << 21) & BM_USBC_UOG_ENDPTCTRL7_TXI)
#else
#define BF_USBC_UOG_ENDPTCTRL7_TXI(v)   (((v) << 21) & BM_USBC_UOG_ENDPTCTRL7_TXI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXI field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_TXI(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, TXI, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field TXR[22:22] (RW)
 *
 * TX Data Toggle Reset (WS) Write 1 - Reset PID Sequence Whenever a configuration event is received
 * for this Endpoint, software must write a one to this bit in order to synchronize the data PID's
 * between the Host and device.
 */

#define BP_USBC_UOG_ENDPTCTRL7_TXR      (22)
#define BM_USBC_UOG_ENDPTCTRL7_TXR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_TXR(v)   ((((reg32_t) v) << 22) & BM_USBC_UOG_ENDPTCTRL7_TXR)
#else
#define BF_USBC_UOG_ENDPTCTRL7_TXR(v)   (((v) << 22) & BM_USBC_UOG_ENDPTCTRL7_TXR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXR field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_TXR(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, TXR, v)
#endif

/* --- Register HW_USBC_UOG_ENDPTCTRL7, field TXE[23:23] (RW)
 *
 * TX Endpoint Enable 0 Disabled [Default] 1 Enabled An Endpoint should be enabled only after it has
 * been configured.
 */

#define BP_USBC_UOG_ENDPTCTRL7_TXE      (23)
#define BM_USBC_UOG_ENDPTCTRL7_TXE      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC_UOG_ENDPTCTRL7_TXE(v)   ((((reg32_t) v) << 23) & BM_USBC_UOG_ENDPTCTRL7_TXE)
#else
#define BF_USBC_UOG_ENDPTCTRL7_TXE(v)   (((v) << 23) & BM_USBC_UOG_ENDPTCTRL7_TXE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXE field to a new value.
#define BW_USBC_UOG_ENDPTCTRL7_TXE(v)   BF_CS1(USBC_UOG_ENDPTCTRL7, TXE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IDUH1 - Identification register UH1 (RO)
 *
 * The ID register identifies the USB 2.0 OTG High-Speed core and its revision.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ID : 6; //!< Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG High-Speed core.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned NID : 6; //!< Complement version of ID
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned REVISION : 8; //!< Revision number of the controller core.
        unsigned RESERVED2 : 8; //!< Reserved
    } B;
} hw_usbc__iduh1_t;
#endif

/*
 * constants & macros for entire USBC__IDUH1 register
 */
#define HW_USBC__IDUH1_ADDR      (REGS_USBC_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IDUH1           (*(volatile hw_usbc__iduh1_t *) HW_USBC__IDUH1_ADDR)
#define HW_USBC__IDUH1_RD()      (HW_USBC__IDUH1.U)
#endif

/*
 * constants & macros for individual USBC__IDUH1 bitfields
 */

/* --- Register HW_USBC__IDUH1, field ID[5:0] (RO)
 *
 * Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG
 * High-Speed core.
 */

#define BP_USBC__IDUH1_ID      (0)
#define BM_USBC__IDUH1_ID      (0x0000003f)

/* --- Register HW_USBC__IDUH1, field NID[13:8] (RO)
 *
 * Complement version of ID
 */

#define BP_USBC__IDUH1_NID      (8)
#define BM_USBC__IDUH1_NID      (0x00003f00)

/* --- Register HW_USBC__IDUH1, field REVISION[23:16] (RO)
 *
 * Revision number of the controller core.
 */

#define BP_USBC__IDUH1_REVISION      (16)
#define BM_USBC__IDUH1_REVISION      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWGENERALUH1 - Hardware General UH1 (RO)
 *
 * General hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned PHYW : 2; //!< Data width of the transciever connected to the controller core. For OTG controller core reset value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller core, reset value is '01b'.
        unsigned PHYM : 3; //!< Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '4h'.
        unsigned SM : 2; //!< Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '00b'.
        unsigned RESERVED1 : 21; //!< Reserved
    } B;
} hw_usbc__hwgeneraluh1_t;
#endif

/*
 * constants & macros for entire USBC__HWGENERALUH1 register
 */
#define HW_USBC__HWGENERALUH1_ADDR      (REGS_USBC_BASE + 0x204)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWGENERALUH1           (*(volatile hw_usbc__hwgeneraluh1_t *) HW_USBC__HWGENERALUH1_ADDR)
#define HW_USBC__HWGENERALUH1_RD()      (HW_USBC__HWGENERALUH1.U)
#endif

/*
 * constants & macros for individual USBC__HWGENERALUH1 bitfields
 */

/* --- Register HW_USBC__HWGENERALUH1, field PHYW[5:4] (RO)
 *
 * Data width of the transciever connected to the controller core. For OTG controller core reset
 * value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For
 * OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller
 * core, reset value is '01b'.
 *
 * Values:
 * 00 - 8 bit wide data bus [60MHz clock from the transciever]
 * 01 - 16 bit wide data bus [30MHZ clock from the transciever]
 * 10 - software programmable reset to 8-bit width
 * 11 - software programmable reset to 16-bit width
 */

#define BP_USBC__HWGENERALUH1_PHYW      (4)
#define BM_USBC__HWGENERALUH1_PHYW      (0x00000030)


/* --- Register HW_USBC__HWGENERALUH1, field PHYM[8:6] (RO)
 *
 * Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG
 * controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'.
 * For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value
 * is '4h'.
 *
 * Values:
 * 000 - UTMI/UMTI+
 * 001 - ULPI DDR
 * 010 - ULPI
 * 011 - Serial Only
 * 100 - Software programmable - reset to UTMI/UTMI+
 * 101 - Software programmable - reset to ULPI DDR
 * 110 - Software programmable - reset to ULPI
 * 111 - Software programmable - reset to Serial
 * 1000 - IC-USB
 * 1001 - Software programmable - reset to IC-USB
 * 1010 - HSIC
 * 1011 - Software programmable - reset to HSIC
 */

#define BP_USBC__HWGENERALUH1_PHYM      (6)
#define BM_USBC__HWGENERALUH1_PHYM      (0x000001c0)


/* --- Register HW_USBC__HWGENERALUH1, field SM[10:9] (RO)
 *
 * Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.
 * For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3
 * controller core, reset value is '00b'.
 *
 * Values:
 * 00 - No Serial Engine, always use parallel signalling.
 * 01 - Serial Engine present, always use serial signalling for FS/LS.
 * 10 - Software programmable - Reset to use parallel signalling for FS/LS
 * 11 - Software programmable - Reset to use serial signalling for FS/LS
 */

#define BP_USBC__HWGENERALUH1_SM      (9)
#define BM_USBC__HWGENERALUH1_SM      (0x00000600)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWHOSTUH1 - Host Hardware Parameters UH1 (RO)
 *
 * Host hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HC : 1; //!< Host Capable. All 4 controller cores support host operation mode.
        unsigned NPORT : 3; //!< The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller cores are single port, these bits are set to '000b'.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__hwhostuh1_t;
#endif

/*
 * constants & macros for entire USBC__HWHOSTUH1 register
 */
#define HW_USBC__HWHOSTUH1_ADDR      (REGS_USBC_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWHOSTUH1           (*(volatile hw_usbc__hwhostuh1_t *) HW_USBC__HWHOSTUH1_ADDR)
#define HW_USBC__HWHOSTUH1_RD()      (HW_USBC__HWHOSTUH1.U)
#endif

/*
 * constants & macros for individual USBC__HWHOSTUH1 bitfields
 */

/* --- Register HW_USBC__HWHOSTUH1, field HC[0:0] (RO)
 *
 * Host Capable. All 4 controller cores support host operation mode.
 *
 * Values:
 * 0 - not support
 * 1 - support host operation mode
 */

#define BP_USBC__HWHOSTUH1_HC      (0)
#define BM_USBC__HWHOSTUH1_HC      (0x00000001)


/* --- Register HW_USBC__HWHOSTUH1, field NPORT[3:1] (RO)
 *
 * The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller
 * cores are single port, these bits are set to '000b'.
 */

#define BP_USBC__HWHOSTUH1_NPORT      (1)
#define BM_USBC__HWHOSTUH1_NPORT      (0x0000000e)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWTXBUFUH1 - TX Buffer Hardware Parameters UH1 (RO)
 *
 * TX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXBURST : 8; //!< Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned TXCHANADD : 8; //!< TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc__hwtxbufuh1_t;
#endif

/*
 * constants & macros for entire USBC__HWTXBUFUH1 register
 */
#define HW_USBC__HWTXBUFUH1_ADDR      (REGS_USBC_BASE + 0x210)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWTXBUFUH1           (*(volatile hw_usbc__hwtxbufuh1_t *) HW_USBC__HWTXBUFUH1_ADDR)
#define HW_USBC__HWTXBUFUH1_RD()      (HW_USBC__HWTXBUFUH1.U)
#endif

/*
 * constants & macros for individual USBC__HWTXBUFUH1 bitfields
 */

/* --- Register HW_USBC__HWTXBUFUH1, field TXBURST[7:0] (RO)
 *
 * Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWTXBUFUH1_TXBURST      (0)
#define BM_USBC__HWTXBUFUH1_TXBURST      (0x000000ff)

/* --- Register HW_USBC__HWTXBUFUH1, field TXCHANADD[23:16] (RO)
 *
 * TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4
 * Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX
 * Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
 */

#define BP_USBC__HWTXBUFUH1_TXCHANADD      (16)
#define BM_USBC__HWTXBUFUH1_TXCHANADD      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWRXBUFUH1 - RX Buffer Hardware Parameters UH1 (RO)
 *
 * RX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXBURST : 8; //!< Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RXADD : 8; //!< Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX Buffer.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usbc__hwrxbufuh1_t;
#endif

/*
 * constants & macros for entire USBC__HWRXBUFUH1 register
 */
#define HW_USBC__HWRXBUFUH1_ADDR      (REGS_USBC_BASE + 0x214)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWRXBUFUH1           (*(volatile hw_usbc__hwrxbufuh1_t *) HW_USBC__HWRXBUFUH1_ADDR)
#define HW_USBC__HWRXBUFUH1_RD()      (HW_USBC__HWRXBUFUH1.U)
#endif

/*
 * constants & macros for individual USBC__HWRXBUFUH1 bitfields
 */

/* --- Register HW_USBC__HWRXBUFUH1, field RXBURST[7:0] (RO)
 *
 * Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWRXBUFUH1_RXBURST      (0)
#define BM_USBC__HWRXBUFUH1_RXBURST      (0x000000ff)

/* --- Register HW_USBC__HWRXBUFUH1, field RXADD[15:8] (RO)
 *
 * Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes.
 * These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one
 * RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX
 * Buffer.
 */

#define BP_USBC__HWRXBUFUH1_RXADD      (8)
#define BM_USBC__HWRXBUFUH1_RXADD      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0LDUH1 - General Purpose Timer #0 Load UH1 (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER0CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer0lduh1_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0LDUH1 register
 */
#define HW_USBC__GPTIMER0LDUH1_ADDR      (REGS_USBC_BASE + 0x280)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0LDUH1           (*(volatile hw_usbc__gptimer0lduh1_t *) HW_USBC__GPTIMER0LDUH1_ADDR)
#define HW_USBC__GPTIMER0LDUH1_RD()      (HW_USBC__GPTIMER0LDUH1.U)
#define HW_USBC__GPTIMER0LDUH1_WR(v)     (HW_USBC__GPTIMER0LDUH1.U = (v))
#define HW_USBC__GPTIMER0LDUH1_SET(v)    (HW_USBC__GPTIMER0LDUH1_WR(HW_USBC__GPTIMER0LDUH1_RD() |  (v)))
#define HW_USBC__GPTIMER0LDUH1_CLR(v)    (HW_USBC__GPTIMER0LDUH1_WR(HW_USBC__GPTIMER0LDUH1_RD() & ~(v)))
#define HW_USBC__GPTIMER0LDUH1_TOG(v)    (HW_USBC__GPTIMER0LDUH1_WR(HW_USBC__GPTIMER0LDUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0LDUH1 bitfields
 */

/* --- Register HW_USBC__GPTIMER0LDUH1, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER0LDUH1_GPTLD      (0)
#define BM_USBC__GPTIMER0LDUH1_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0LDUH1_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0LDUH1_GPTLD)
#else
#define BF_USBC__GPTIMER0LDUH1_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER0LDUH1_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER0LDUH1_GPTLD(v)   BF_CS1(USBC__GPTIMER0LDUH1, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0CTRLUH1 - General Purpose Timer #0 Controller UH1 (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI0 bit in n_USBSTS register (See ), interrupt enable bit is
 * TIE0 bit in n_USBINTR register. (See .)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer0ctrluh1_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0CTRLUH1 register
 */
#define HW_USBC__GPTIMER0CTRLUH1_ADDR      (REGS_USBC_BASE + 0x284)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0CTRLUH1           (*(volatile hw_usbc__gptimer0ctrluh1_t *) HW_USBC__GPTIMER0CTRLUH1_ADDR)
#define HW_USBC__GPTIMER0CTRLUH1_RD()      (HW_USBC__GPTIMER0CTRLUH1.U)
#define HW_USBC__GPTIMER0CTRLUH1_WR(v)     (HW_USBC__GPTIMER0CTRLUH1.U = (v))
#define HW_USBC__GPTIMER0CTRLUH1_SET(v)    (HW_USBC__GPTIMER0CTRLUH1_WR(HW_USBC__GPTIMER0CTRLUH1_RD() |  (v)))
#define HW_USBC__GPTIMER0CTRLUH1_CLR(v)    (HW_USBC__GPTIMER0CTRLUH1_WR(HW_USBC__GPTIMER0CTRLUH1_RD() & ~(v)))
#define HW_USBC__GPTIMER0CTRLUH1_TOG(v)    (HW_USBC__GPTIMER0CTRLUH1_WR(HW_USBC__GPTIMER0CTRLUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0CTRLUH1 bitfields
 */

/* --- Register HW_USBC__GPTIMER0CTRLUH1, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER0CTRLUH1_GPTCNT      (0)
#define BM_USBC__GPTIMER0CTRLUH1_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH1_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0CTRLUH1_GPTCNT)
#else
#define BF_USBC__GPTIMER0CTRLUH1_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER0CTRLUH1_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER0CTRLUH1_GPTCNT(v)   BF_CS1(USBC__GPTIMER0CTRLUH1, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRLUH1, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER0CTRLUH1_GPTMODE      (24)
#define BM_USBC__GPTIMER0CTRLUH1_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH1_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER0CTRLUH1_GPTMODE)
#else
#define BF_USBC__GPTIMER0CTRLUH1_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER0CTRLUH1_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER0CTRLUH1_GPTMODE(v)   BF_CS1(USBC__GPTIMER0CTRLUH1, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUH1, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in n_GPTIMER0LD
 */

#define BP_USBC__GPTIMER0CTRLUH1_GPTRST      (30)
#define BM_USBC__GPTIMER0CTRLUH1_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH1_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER0CTRLUH1_GPTRST)
#else
#define BF_USBC__GPTIMER0CTRLUH1_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER0CTRLUH1_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER0CTRLUH1_GPTRST(v)   BF_CS1(USBC__GPTIMER0CTRLUH1, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUH1, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER0CTRLUH1_GPTRUN      (31)
#define BM_USBC__GPTIMER0CTRLUH1_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH1_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER0CTRLUH1_GPTRUN)
#else
#define BF_USBC__GPTIMER0CTRLUH1_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER0CTRLUH1_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER0CTRLUH1_GPTRUN(v)   BF_CS1(USBC__GPTIMER0CTRLUH1, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1LDUH1 - General Purpose Timer #1 Load UH1 (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER1CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer1lduh1_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1LDUH1 register
 */
#define HW_USBC__GPTIMER1LDUH1_ADDR      (REGS_USBC_BASE + 0x288)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1LDUH1           (*(volatile hw_usbc__gptimer1lduh1_t *) HW_USBC__GPTIMER1LDUH1_ADDR)
#define HW_USBC__GPTIMER1LDUH1_RD()      (HW_USBC__GPTIMER1LDUH1.U)
#define HW_USBC__GPTIMER1LDUH1_WR(v)     (HW_USBC__GPTIMER1LDUH1.U = (v))
#define HW_USBC__GPTIMER1LDUH1_SET(v)    (HW_USBC__GPTIMER1LDUH1_WR(HW_USBC__GPTIMER1LDUH1_RD() |  (v)))
#define HW_USBC__GPTIMER1LDUH1_CLR(v)    (HW_USBC__GPTIMER1LDUH1_WR(HW_USBC__GPTIMER1LDUH1_RD() & ~(v)))
#define HW_USBC__GPTIMER1LDUH1_TOG(v)    (HW_USBC__GPTIMER1LDUH1_WR(HW_USBC__GPTIMER1LDUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1LDUH1 bitfields
 */

/* --- Register HW_USBC__GPTIMER1LDUH1, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER1LDUH1_GPTLD      (0)
#define BM_USBC__GPTIMER1LDUH1_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1LDUH1_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1LDUH1_GPTLD)
#else
#define BF_USBC__GPTIMER1LDUH1_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER1LDUH1_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER1LDUH1_GPTLD(v)   BF_CS1(USBC__GPTIMER1LDUH1, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1CTRLUH1 - General Purpose Timer #1 Controller UH1 (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI1 bit in UOG_USBSTS register (See ), interrupt enable bit is
 * TIE1 bit in n_USBINTR register (See ).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer1ctrluh1_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1CTRLUH1 register
 */
#define HW_USBC__GPTIMER1CTRLUH1_ADDR      (REGS_USBC_BASE + 0x28c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1CTRLUH1           (*(volatile hw_usbc__gptimer1ctrluh1_t *) HW_USBC__GPTIMER1CTRLUH1_ADDR)
#define HW_USBC__GPTIMER1CTRLUH1_RD()      (HW_USBC__GPTIMER1CTRLUH1.U)
#define HW_USBC__GPTIMER1CTRLUH1_WR(v)     (HW_USBC__GPTIMER1CTRLUH1.U = (v))
#define HW_USBC__GPTIMER1CTRLUH1_SET(v)    (HW_USBC__GPTIMER1CTRLUH1_WR(HW_USBC__GPTIMER1CTRLUH1_RD() |  (v)))
#define HW_USBC__GPTIMER1CTRLUH1_CLR(v)    (HW_USBC__GPTIMER1CTRLUH1_WR(HW_USBC__GPTIMER1CTRLUH1_RD() & ~(v)))
#define HW_USBC__GPTIMER1CTRLUH1_TOG(v)    (HW_USBC__GPTIMER1CTRLUH1_WR(HW_USBC__GPTIMER1CTRLUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1CTRLUH1 bitfields
 */

/* --- Register HW_USBC__GPTIMER1CTRLUH1, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER1CTRLUH1_GPTCNT      (0)
#define BM_USBC__GPTIMER1CTRLUH1_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH1_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1CTRLUH1_GPTCNT)
#else
#define BF_USBC__GPTIMER1CTRLUH1_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER1CTRLUH1_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER1CTRLUH1_GPTCNT(v)   BF_CS1(USBC__GPTIMER1CTRLUH1, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRLUH1, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER1CTRLUH1_GPTMODE      (24)
#define BM_USBC__GPTIMER1CTRLUH1_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH1_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER1CTRLUH1_GPTMODE)
#else
#define BF_USBC__GPTIMER1CTRLUH1_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER1CTRLUH1_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER1CTRLUH1_GPTMODE(v)   BF_CS1(USBC__GPTIMER1CTRLUH1, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUH1, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in UOG_GPTIMER0LD
 */

#define BP_USBC__GPTIMER1CTRLUH1_GPTRST      (30)
#define BM_USBC__GPTIMER1CTRLUH1_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH1_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER1CTRLUH1_GPTRST)
#else
#define BF_USBC__GPTIMER1CTRLUH1_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER1CTRLUH1_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER1CTRLUH1_GPTRST(v)   BF_CS1(USBC__GPTIMER1CTRLUH1, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUH1, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER1CTRLUH1_GPTRUN      (31)
#define BM_USBC__GPTIMER1CTRLUH1_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH1_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER1CTRLUH1_GPTRUN)
#else
#define BF_USBC__GPTIMER1CTRLUH1_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER1CTRLUH1_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER1CTRLUH1_GPTRUN(v)   BF_CS1(USBC__GPTIMER1CTRLUH1, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__SBUSCFGUH1 - System Bus Config UH1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned AHBBRST : 3; //!< AHB master interface Burst configuration These bits controls AHB master transfer type sequence (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_usbc__sbuscfguh1_t;
#endif

/*
 * constants & macros for entire USBC__SBUSCFGUH1 register
 */
#define HW_USBC__SBUSCFGUH1_ADDR      (REGS_USBC_BASE + 0x290)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__SBUSCFGUH1           (*(volatile hw_usbc__sbuscfguh1_t *) HW_USBC__SBUSCFGUH1_ADDR)
#define HW_USBC__SBUSCFGUH1_RD()      (HW_USBC__SBUSCFGUH1.U)
#define HW_USBC__SBUSCFGUH1_WR(v)     (HW_USBC__SBUSCFGUH1.U = (v))
#define HW_USBC__SBUSCFGUH1_SET(v)    (HW_USBC__SBUSCFGUH1_WR(HW_USBC__SBUSCFGUH1_RD() |  (v)))
#define HW_USBC__SBUSCFGUH1_CLR(v)    (HW_USBC__SBUSCFGUH1_WR(HW_USBC__SBUSCFGUH1_RD() & ~(v)))
#define HW_USBC__SBUSCFGUH1_TOG(v)    (HW_USBC__SBUSCFGUH1_WR(HW_USBC__SBUSCFGUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__SBUSCFGUH1 bitfields
 */

/* --- Register HW_USBC__SBUSCFGUH1, field AHBBRST[2:0] (RW)
 *
 * AHB master interface Burst configuration These bits controls AHB master transfer type sequence
 * (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
 *
 * Values:
 * 000 - Incremental burst of unspecified length only
 * 001 - INCR4 burst, then single transfer
 * 010 - INCR8 burst, INCR4 burst, then single transfer
 * 011 - INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 * 100 - Reserved, don't use
 * 101 - INCR4 burst, then incremental burst of unspecified length
 * 110 - INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 * 111 - INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */

#define BP_USBC__SBUSCFGUH1_AHBBRST      (0)
#define BM_USBC__SBUSCFGUH1_AHBBRST      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__SBUSCFGUH1_AHBBRST(v)   ((((reg32_t) v) << 0) & BM_USBC__SBUSCFGUH1_AHBBRST)
#else
#define BF_USBC__SBUSCFGUH1_AHBBRST(v)   (((v) << 0) & BM_USBC__SBUSCFGUH1_AHBBRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBBRST field to a new value.
#define BW_USBC__SBUSCFGUH1_AHBBRST(v)   BF_CS1(USBC__SBUSCFGUH1, AHBBRST, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__CAPLENGTHUH1 - Capability Register Length UH1 (RO)
 *
 * The following figure Capability Register Length (n_CAPLENGTH) indicates the offset that should be
 * added to the register base address at the beginning of the Operational Register.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CAPLENGTH : 8; //!< These bits are used as an offset to add to register base to find the beginning of the Operational Register. Default value is '40h'.
    } B;
} hw_usbc__caplengthuh1_t;
#endif

/*
 * constants & macros for entire USBC__CAPLENGTHUH1 register
 */
#define HW_USBC__CAPLENGTHUH1_ADDR      (REGS_USBC_BASE + 0x300)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__CAPLENGTHUH1           (*(volatile hw_usbc__caplengthuh1_t *) HW_USBC__CAPLENGTHUH1_ADDR)
#define HW_USBC__CAPLENGTHUH1_RD()      (HW_USBC__CAPLENGTHUH1.U)
#endif

/*
 * constants & macros for individual USBC__CAPLENGTHUH1 bitfields
 */

/* --- Register HW_USBC__CAPLENGTHUH1, field CAPLENGTH[7:0] (RO)
 *
 * These bits are used as an offset to add to register base to find the beginning of the Operational
 * Register. Default value is '40h'.
 */

#define BP_USBC__CAPLENGTHUH1_CAPLENGTH      (0)
#define BM_USBC__CAPLENGTHUH1_CAPLENGTH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCIVERSIONUH1 - Host Controller Interface Version UH1 (RO)
 *
 * The following figure shows the Host Interface version number (n_HCIVERSION), which is a 2-byte
 * register containing a BCD encoding of the EHCI revision number supported by this host controller.
 * The most significant byte of this register represents a major revision and the least significant
 * byte is the minor revision.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HCIVERSION : 16; //!< Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
    } B;
} hw_usbc__hciversionuh1_t;
#endif

/*
 * constants & macros for entire USBC__HCIVERSIONUH1 register
 */
#define HW_USBC__HCIVERSIONUH1_ADDR      (REGS_USBC_BASE + 0x302)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCIVERSIONUH1           (*(volatile hw_usbc__hciversionuh1_t *) HW_USBC__HCIVERSIONUH1_ADDR)
#define HW_USBC__HCIVERSIONUH1_RD()      (HW_USBC__HCIVERSIONUH1.U)
#endif

/*
 * constants & macros for individual USBC__HCIVERSIONUH1 bitfields
 */

/* --- Register HW_USBC__HCIVERSIONUH1, field HCIVERSION[15:0] (RO)
 *
 * Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
 */

#define BP_USBC__HCIVERSIONUH1_HCIVERSION      (0)
#define BM_USBC__HCIVERSIONUH1_HCIVERSION      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCSPARAMSUH1 - Host Controller Structural Parameters UH1 (RO)
 *
 * The following figure shows the port steering logic capabilities of Host Control Structural
 * Parameters (n_HCSPARAMS).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned N_PORTS : 4; //!< Number of downstream ports. This field specifies the number of physical downstream ports implemented on this host controller. The value of this field determines how many port registers are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in this field is undefined. These bits are always set to '0001b' because all 4 controller cores are Single-Port Host.
        unsigned PPC : 1; //!< Port Power Control This field indicates whether the host controller implementation includes port power control. A one indicates the ports have port power switches. A zero indicates the ports do not have port power switches. The value of this field affects the functionality of the Port Power field in each port status and control register
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned N_PCC : 4; //!< Number of Ports per Companion Controller This field indicates the number of ports supported per internal Companion Controller. It is used to indicate the port routing configuration to the system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and the last two are routed to companion controller 2. The number in this field must be consistent with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
        unsigned N_CC : 4; //!< Number of Companion Controller (N_CC). This field indicates the number of companion controllers associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
        unsigned PI : 1; //!< Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator control. When set to one, the port status and control registers include a read/writeable field for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned N_PTT : 4; //!< Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates the number of ports assigned to each transaction translator within the USB2.0 host controller. These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned N_TT : 4; //!< Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number of embedded transaction translators associated with the USB2.0 host controller. These bits would be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_usbc__hcsparamsuh1_t;
#endif

/*
 * constants & macros for entire USBC__HCSPARAMSUH1 register
 */
#define HW_USBC__HCSPARAMSUH1_ADDR      (REGS_USBC_BASE + 0x304)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCSPARAMSUH1           (*(volatile hw_usbc__hcsparamsuh1_t *) HW_USBC__HCSPARAMSUH1_ADDR)
#define HW_USBC__HCSPARAMSUH1_RD()      (HW_USBC__HCSPARAMSUH1.U)
#endif

/*
 * constants & macros for individual USBC__HCSPARAMSUH1 bitfields
 */

/* --- Register HW_USBC__HCSPARAMSUH1, field N_PORTS[3:0] (RO)
 *
 * Number of downstream ports. This field specifies the number of physical downstream ports
 * implemented on this host controller. The value of this field determines how many port registers
 * are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in
 * this field is undefined. These bits are always set to '0001b' because all 4 controller cores are
 * Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH1_N_PORTS      (0)
#define BM_USBC__HCSPARAMSUH1_N_PORTS      (0x0000000f)

/* --- Register HW_USBC__HCSPARAMSUH1, field PPC[4:4] (RO)
 *
 * Port Power Control This field indicates whether the host controller implementation includes port
 * power control. A one indicates the ports have port power switches. A zero indicates the ports do
 * not have port power switches. The value of this field affects the functionality of the Port Power
 * field in each port status and control register
 */

#define BP_USBC__HCSPARAMSUH1_PPC      (4)
#define BM_USBC__HCSPARAMSUH1_PPC      (0x00000010)

/* --- Register HW_USBC__HCSPARAMSUH1, field N_PCC[11:8] (RO)
 *
 * Number of Ports per Companion Controller This field indicates the number of ports supported per
 * internal Companion Controller. It is used to indicate the port routing configuration to the
 * system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC
 * could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to
 * companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous
 * example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and
 * the last two are routed to companion controller 2. The number in this field must be consistent
 * with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUH1_N_PCC      (8)
#define BM_USBC__HCSPARAMSUH1_N_PCC      (0x00000f00)

/* --- Register HW_USBC__HCSPARAMSUH1, field N_CC[15:12] (RO)
 *
 * Number of Companion Controller (N_CC). This field indicates the number of companion controllers
 * associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
 *
 * Values:
 * 0 - There is no internal Companion Controller and port-ownership hand-off is not supported.
 * 1 - There are internal companion controller(s) and port-ownership hand-offs is supported.
 */

#define BP_USBC__HCSPARAMSUH1_N_CC      (12)
#define BM_USBC__HCSPARAMSUH1_N_CC      (0x0000f000)


/* --- Register HW_USBC__HCSPARAMSUH1, field PI[16:16] (RO)
 *
 * Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator
 * control. When set to one, the port status and control registers include a read/writeable field
 * for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUH1_PI      (16)
#define BM_USBC__HCSPARAMSUH1_PI      (0x00010000)

/* --- Register HW_USBC__HCSPARAMSUH1, field N_PTT[23:20] (RO)
 *
 * Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates
 * the number of ports assigned to each transaction translator within the USB2.0 host controller.
 * These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH1_N_PTT      (20)
#define BM_USBC__HCSPARAMSUH1_N_PTT      (0x00f00000)

/* --- Register HW_USBC__HCSPARAMSUH1, field N_TT[27:24] (RO)
 *
 * Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number
 * of embedded transaction translators associated with the USB2.0 host controller. These bits would
 * be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH1_N_TT      (24)
#define BM_USBC__HCSPARAMSUH1_N_TT      (0x0f000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCCPARAMSUH1 - Host Controller Capability Parameters UH1 (RO)
 *
 * This register identifies multiple mode control (time-base bit functionality), addressing
 * capability.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADC : 1; //!< 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing capability is supported.
        unsigned PFL : 1; //!< Programmable Frame List Flag If this bit is set to zero, then the system software must use a frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size field is a read-only register and must be set to zero. If set to a one, then the system software can specify and use a smaller frame list and configure the host controller via the USBCMD register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in all 4 controller core.
        unsigned ASP : 1; //!< Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is set '1b' in all 4 controller core.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned IST : 4; //!< Isochronous Scheduling Threshold. This field indicates, relative to the current position of the executing host controller, where software can reliably update the isochronous schedule. When bit [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a host controller can hold a set of isochronous data structures (one or more) before flushing the state. When bit [7] is a one, then host software assumes the host controller may cache an isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller core.
        unsigned EECP : 8; //!< EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A value of 00h indicates no extended capabilities are implemented. A non-zero value in this register indicates the offset in PCI configuration space of the first EHCI extended capability. The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI header defined for this class of device. These bits are set '00h' in all 4 controller core.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_usbc__hccparamsuh1_t;
#endif

/*
 * constants & macros for entire USBC__HCCPARAMSUH1 register
 */
#define HW_USBC__HCCPARAMSUH1_ADDR      (REGS_USBC_BASE + 0x308)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCCPARAMSUH1           (*(volatile hw_usbc__hccparamsuh1_t *) HW_USBC__HCCPARAMSUH1_ADDR)
#define HW_USBC__HCCPARAMSUH1_RD()      (HW_USBC__HCCPARAMSUH1.U)
#endif

/*
 * constants & macros for individual USBC__HCCPARAMSUH1 bitfields
 */

/* --- Register HW_USBC__HCCPARAMSUH1, field ADC[0:0] (RO)
 *
 * 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing
 * capability is supported.
 */

#define BP_USBC__HCCPARAMSUH1_ADC      (0)
#define BM_USBC__HCCPARAMSUH1_ADC      (0x00000001)

/* --- Register HW_USBC__HCCPARAMSUH1, field PFL[1:1] (RO)
 *
 * Programmable Frame List Flag If this bit is set to zero, then the system software must use a
 * frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size
 * field is a read-only register and must be set to zero. If set to a one, then the system software
 * can specify and use a smaller frame list and configure the host controller via the USBCMD
 * register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This
 * requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in
 * all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH1_PFL      (1)
#define BM_USBC__HCCPARAMSUH1_PFL      (0x00000002)

/* --- Register HW_USBC__HCCPARAMSUH1, field ASP[2:2] (RO)
 *
 * Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller
 * supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature
 * can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park
 * Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is
 * set '1b' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH1_ASP      (2)
#define BM_USBC__HCCPARAMSUH1_ASP      (0x00000004)

/* --- Register HW_USBC__HCCPARAMSUH1, field IST[7:4] (RO)
 *
 * Isochronous Scheduling Threshold. This field indicates, relative to the current position of the
 * executing host controller, where software can reliably update the isochronous schedule. When bit
 * [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a
 * host controller can hold a set of isochronous data structures (one or more) before flushing the
 * state. When bit [7] is a one, then host software assumes the host controller may cache an
 * isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller
 * core.
 */

#define BP_USBC__HCCPARAMSUH1_IST      (4)
#define BM_USBC__HCCPARAMSUH1_IST      (0x000000f0)

/* --- Register HW_USBC__HCCPARAMSUH1, field EECP[15:8] (RO)
 *
 * EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A
 * value of 00h indicates no extended capabilities are implemented. A non-zero value in this
 * register indicates the offset in PCI configuration space of the first EHCI extended capability.
 * The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI
 * header defined for this class of device. These bits are set '00h' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH1_EECP      (8)
#define BM_USBC__HCCPARAMSUH1_EECP      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBCMDUH1 - USB Command Register UH1 (RW)
 *
 * The Command Register indicates the command to be executed by the serial bus host/device
 * controller. Writing to the register causes a command to be executed.  *: ASPE,ASP[1],ASP[0] reset
 * value: '0b' for OTG core; '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RS : 1; //!< Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the Controller proceeds with the execution of the schedule. The Controller continues execution as long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the current transaction on the USB and then halts. The HC Halted bit in the status register indicates when the Controller has finished the transaction and has entered the stopped state. Software should not write a one to this field unless the controller is in the Halted state (that is, HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is not directly connected to the pull-up enable, as the pull-up will become disabled upon transitioning into high-speed mode. Software should use this bit to prevent an attach event before the controller has been properly initialized. Writing a 0 to this will cause a detach event.
        unsigned RST : 1; //!< Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register. Host operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Any transaction currently in progress on USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset an actively running host controller will result in undefined behavior. Device operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Writing a one to this bit when the device is in the attached state is not recommended, because the effect on an attached host is undefined. In order to ensure that the device is not in an attached state before initiating a device controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be set to 0.
        unsigned FS : 2; //!< See description at bit 15
        unsigned PSE : 1; //!< Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
        unsigned ASE : 1; //!< Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host controller skips processing the Asynchronous Schedule. Only the host controller uses this bit. Values Meaning
        unsigned IAA : 1; //!< Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to tell the host controller to issue an interrupt the next time it advances asynchronous schedule. Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then the host controller will assert an interrupt at the next interrupt threshold. The host controller sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS register to one. Software should not write a one to this bit when the asynchronous schedule is inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a one to this bit when device mode is selected will have undefined results.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ASP : 2; //!< Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults to zero and is Read-Only. It contains a count of the number of successive transactions the host controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not write a zero to this bit when Park Mode Enable is a one as this will result in undefined behavior. This field is set to 3h in all 4 controller core.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ASPE : 1; //!< Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to '1b' in this implementation.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned SUTW : 1; //!< Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a hazard when new setup data arrives while the DCD is copying the setup data payload from the QH for a previous setup packet. This bit is set and cleared by software. This bit would also be cleared by hardware when a hazard detected. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned ATDTW : 1; //!< Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and cleared by software. This bit would also be cleared by hardware when state machine is hazard region for which adding a dTD to a primed endpoint may go unrecognized. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned FS1 : 1; //!< See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This field specifies the size of the frame list that controls which bits in the Frame Index Register should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and 2. Value Meaning
        unsigned ITC : 8; //!< Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum Interrupt Interval
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc__usbcmduh1_t;
#endif

/*
 * constants & macros for entire USBC__USBCMDUH1 register
 */
#define HW_USBC__USBCMDUH1_ADDR      (REGS_USBC_BASE + 0x340)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBCMDUH1           (*(volatile hw_usbc__usbcmduh1_t *) HW_USBC__USBCMDUH1_ADDR)
#define HW_USBC__USBCMDUH1_RD()      (HW_USBC__USBCMDUH1.U)
#define HW_USBC__USBCMDUH1_WR(v)     (HW_USBC__USBCMDUH1.U = (v))
#define HW_USBC__USBCMDUH1_SET(v)    (HW_USBC__USBCMDUH1_WR(HW_USBC__USBCMDUH1_RD() |  (v)))
#define HW_USBC__USBCMDUH1_CLR(v)    (HW_USBC__USBCMDUH1_WR(HW_USBC__USBCMDUH1_RD() & ~(v)))
#define HW_USBC__USBCMDUH1_TOG(v)    (HW_USBC__USBCMDUH1_WR(HW_USBC__USBCMDUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBCMDUH1 bitfields
 */

/* --- Register HW_USBC__USBCMDUH1, field RS[0:0] (RW)
 *
 * Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the
 * Controller proceeds with the execution of the schedule. The Controller continues execution as
 * long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the
 * current transaction on the USB and then halts. The HC Halted bit in the status register indicates
 * when the Controller has finished the transaction and has entered the stopped state. Software
 * should not write a one to this field unless the controller is in the Halted state (that is,
 * HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will
 * cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is
 * not directly connected to the pull-up enable, as the pull-up will become disabled upon
 * transitioning into high-speed mode. Software should use this bit to prevent an attach event
 * before the controller has been properly initialized. Writing a 0 to this will cause a detach
 * event.
 */

#define BP_USBC__USBCMDUH1_RS      (0)
#define BM_USBC__USBCMDUH1_RS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_RS(v)   ((((reg32_t) v) << 0) & BM_USBC__USBCMDUH1_RS)
#else
#define BF_USBC__USBCMDUH1_RS(v)   (((v) << 0) & BM_USBC__USBCMDUH1_RS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RS field to a new value.
#define BW_USBC__USBCMDUH1_RS(v)   BF_CS1(USBC__USBCMDUH1, RS, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field RST[1:1] (RW)
 *
 * Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit
 * is set to zero by the Host/Device Controller when the reset process is complete. Software cannot
 * terminate the reset process early by writing a zero to this register. Host operation mode: When
 * software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Any transaction currently in progress on
 * USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not
 * set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset
 * an actively running host controller will result in undefined behavior. Device operation mode:
 * When software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Writing a one to this bit when the device
 * is in the attached state is not recommended, because the effect on an attached host is undefined.
 * In order to ensure that the device is not in an attached state before initiating a device
 * controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be
 * set to 0.
 */

#define BP_USBC__USBCMDUH1_RST      (1)
#define BM_USBC__USBCMDUH1_RST      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_RST(v)   ((((reg32_t) v) << 1) & BM_USBC__USBCMDUH1_RST)
#else
#define BF_USBC__USBCMDUH1_RST(v)   (((v) << 1) & BM_USBC__USBCMDUH1_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RST field to a new value.
#define BW_USBC__USBCMDUH1_RST(v)   BF_CS1(USBC__USBCMDUH1, RST, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field FS[3:2] (RW)
 *
 * See description at bit 15
 */

#define BP_USBC__USBCMDUH1_FS      (2)
#define BM_USBC__USBCMDUH1_FS      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_FS(v)   ((((reg32_t) v) << 2) & BM_USBC__USBCMDUH1_FS)
#else
#define BF_USBC__USBCMDUH1_FS(v)   (((v) << 2) & BM_USBC__USBCMDUH1_FS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS field to a new value.
#define BW_USBC__USBCMDUH1_FS(v)   BF_CS1(USBC__USBCMDUH1, FS, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field PSE[4:4] (RW)
 *
 * Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller
 * skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
 *
 * Values:
 * 0 - Do not process the Periodic Schedule
 * 1 - Use the PERIODICLISTBASE register to access the Periodic Schedule.
 */

#define BP_USBC__USBCMDUH1_PSE      (4)
#define BM_USBC__USBCMDUH1_PSE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_PSE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBCMDUH1_PSE)
#else
#define BF_USBC__USBCMDUH1_PSE(v)   (((v) << 4) & BM_USBC__USBCMDUH1_PSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSE field to a new value.
#define BW_USBC__USBCMDUH1_PSE(v)   BF_CS1(USBC__USBCMDUH1, PSE, v)
#endif


/* --- Register HW_USBC__USBCMDUH1, field ASE[5:5] (RW)
 *
 * Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host
 * controller skips processing the Asynchronous Schedule. Only the host controller uses this bit.
 * Values Meaning
 *
 * Values:
 * 0 - Do not process the Asynchronous Schedule.
 * 1 - Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
 */

#define BP_USBC__USBCMDUH1_ASE      (5)
#define BM_USBC__USBCMDUH1_ASE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_ASE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBCMDUH1_ASE)
#else
#define BF_USBC__USBCMDUH1_ASE(v)   (((v) << 5) & BM_USBC__USBCMDUH1_ASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASE field to a new value.
#define BW_USBC__USBCMDUH1_ASE(v)   BF_CS1(USBC__USBCMDUH1, ASE, v)
#endif


/* --- Register HW_USBC__USBCMDUH1, field IAA[6:6] (RW)
 *
 * Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to
 * tell the host controller to issue an interrupt the next time it advances asynchronous schedule.
 * Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted
 * all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the
 * USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then
 * the host controller will assert an interrupt at the next interrupt threshold. The host controller
 * sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS
 * register to one. Software should not write a one to this bit when the asynchronous schedule is
 * inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a
 * one to this bit when device mode is selected will have undefined results.
 */

#define BP_USBC__USBCMDUH1_IAA      (6)
#define BM_USBC__USBCMDUH1_IAA      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_IAA(v)   ((((reg32_t) v) << 6) & BM_USBC__USBCMDUH1_IAA)
#else
#define BF_USBC__USBCMDUH1_IAA(v)   (((v) << 6) & BM_USBC__USBCMDUH1_IAA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IAA field to a new value.
#define BW_USBC__USBCMDUH1_IAA(v)   BF_CS1(USBC__USBCMDUH1, IAA, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field ASP[9:8] (RW)
 *
 * Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults
 * to zero and is Read-Only. It contains a count of the number of successive transactions the host
 * controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before
 * continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not
 * write a zero to this bit when Park Mode Enable is a one as this will result in undefined
 * behavior. This field is set to 3h in all 4 controller core.
 */

#define BP_USBC__USBCMDUH1_ASP      (8)
#define BM_USBC__USBCMDUH1_ASP      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_ASP(v)   ((((reg32_t) v) << 8) & BM_USBC__USBCMDUH1_ASP)
#else
#define BF_USBC__USBCMDUH1_ASP(v)   (((v) << 8) & BM_USBC__USBCMDUH1_ASP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP field to a new value.
#define BW_USBC__USBCMDUH1_ASP(v)   BF_CS1(USBC__USBCMDUH1, ASP, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field ASPE[11:11] (RW)
 *
 * Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit
 * must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is
 * one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to
 * '1b' in this implementation.
 */

#define BP_USBC__USBCMDUH1_ASPE      (11)
#define BM_USBC__USBCMDUH1_ASPE      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_ASPE(v)   ((((reg32_t) v) << 11) & BM_USBC__USBCMDUH1_ASPE)
#else
#define BF_USBC__USBCMDUH1_ASPE(v)   (((v) << 11) & BM_USBC__USBCMDUH1_ASPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASPE field to a new value.
#define BW_USBC__USBCMDUH1_ASPE(v)   BF_CS1(USBC__USBCMDUH1, ASPE, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field SUTW[13:13] (RW)
 *
 * Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that
 * the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If
 * the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a
 * hazard when new setup data arrives while the DCD is copying the setup data payload from the QH
 * for a previous setup packet. This bit is set and cleared by software. This bit would also be
 * cleared by hardware when a hazard detected. For more information on the use of this bit, see the
 * Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUH1_SUTW      (13)
#define BM_USBC__USBCMDUH1_SUTW      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_SUTW(v)   ((((reg32_t) v) << 13) & BM_USBC__USBCMDUH1_SUTW)
#else
#define BF_USBC__USBCMDUH1_SUTW(v)   (((v) << 13) & BM_USBC__USBCMDUH1_SUTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUTW field to a new value.
#define BW_USBC__USBCMDUH1_SUTW(v)   BF_CS1(USBC__USBCMDUH1, SUTW, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field ATDTW[14:14] (RW)
 *
 * Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure
 * proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and
 * cleared by software. This bit would also be cleared by hardware when state machine is hazard
 * region for which adding a dTD to a primed endpoint may go unrecognized. For more information on
 * the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUH1_ATDTW      (14)
#define BM_USBC__USBCMDUH1_ATDTW      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_ATDTW(v)   ((((reg32_t) v) << 14) & BM_USBC__USBCMDUH1_ATDTW)
#else
#define BF_USBC__USBCMDUH1_ATDTW(v)   (((v) << 14) & BM_USBC__USBCMDUH1_ATDTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATDTW field to a new value.
#define BW_USBC__USBCMDUH1_ATDTW(v)   BF_CS1(USBC__USBCMDUH1, ATDTW, v)
#endif

/* --- Register HW_USBC__USBCMDUH1, field FS1[15:15] (RW)
 *
 * See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is
 * Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This
 * field specifies the size of the frame list that controls which bits in the Frame Index Register
 * should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and
 * 2. Value Meaning
 *
 * Values:
 * 000 - 1024 elements (4096 bytes) Default value
 * 001 - 512 elements (2048 bytes)
 * 010 - 256 elements (1024 bytes)
 * 011 - 128 elements (512 bytes)
 * 100 - 64 elements (256 bytes)
 * 101 - 32 elements (128 bytes)
 * 110 - 16 elements (64 bytes)
 * 111 - 8 elements (32 bytes)
 */

#define BP_USBC__USBCMDUH1_FS1      (15)
#define BM_USBC__USBCMDUH1_FS1      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_FS1(v)   ((((reg32_t) v) << 15) & BM_USBC__USBCMDUH1_FS1)
#else
#define BF_USBC__USBCMDUH1_FS1(v)   (((v) << 15) & BM_USBC__USBCMDUH1_FS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS1 field to a new value.
#define BW_USBC__USBCMDUH1_FS1(v)   BF_CS1(USBC__USBCMDUH1, FS1, v)
#endif


/* --- Register HW_USBC__USBCMDUH1, field ITC[23:16] (RW)
 *
 * Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum
 * rate at which the host/device controller will issue interrupts. ITC contains the maximum
 * interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum
 * Interrupt Interval
 *
 * Values:
 * 0x00 - Immediate (no threshold)
 * 0x01 - 1 micro-frame
 * 0x02 - 2 micro-frames
 * 0x04 - 4 micro-frames
 * 0x08 - 8 micro-frames
 * 0x10 - 16 micro-frames
 * 0x20 - 32 micro-frames
 * 0x40 - 64 micro-frames
 */

#define BP_USBC__USBCMDUH1_ITC      (16)
#define BM_USBC__USBCMDUH1_ITC      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH1_ITC(v)   ((((reg32_t) v) << 16) & BM_USBC__USBCMDUH1_ITC)
#else
#define BF_USBC__USBCMDUH1_ITC(v)   (((v) << 16) & BM_USBC__USBCMDUH1_ITC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ITC field to a new value.
#define BW_USBC__USBCMDUH1_ITC(v)   BF_CS1(USBC__USBCMDUH1, ITC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBSTSUH1 - USB Status Register UH1 (RW)
 *
 * This register indicates various states of the Host/Device Controller and any pending interrupts.
 * This register does not indicate status resulting from a transaction on the serial bus.  *HCH bit
 * reset value: '0b' for OTG core, '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UI : 1; //!< USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        unsigned UEI : 1; //!< USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e. 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus, Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB On-The-Go DEV reference manual. The device controller detects resume signaling only.
        unsigned PCI : 1; //!< Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the result of a J-K transition on the suspended port. The Device Controller sets this bit to a one when the port controller enters the full or high-speed operational state. When the port controller exits the full or high-speed operation states due to Reset or Suspend events, the notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
        unsigned FRI : 1; //!< Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index rolls over from its maximum value to zero. The exact value at which the rollover occurs depends on the frame list size. For example. If the frame list size (as programmed in the Frame List Size field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every time FHINDEX [12] toggles. Only used in host operation mode.
        unsigned SEI : 1; //!< System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on the system interface.
        unsigned AAI : 1; //!< Interrupt on Async Advance - R/WC. System software can force the host controller to issue an interrupt the next time the host controller advances the asynchronous schedule by writing a one to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit indicates the assertion of that interrupt source. Only used in host operation mode.
        unsigned URI : 1; //!< USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset Received status bit. Only used in device operation mode.
        unsigned SRI : 1; //!< SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will be set to a one. When a SOF is extremely late, the device controller will automatically set this bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is received. Because the device controller is initialized to FS before connect, this bit will be set at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set every 125us and can be used by host controller driver as a time base. Software writes a 1 to this bit to clear it.
        unsigned SLI : 1; //!< DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be set to a one. The device controller clears the bit upon exiting from a suspend state. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPII : 1; //!< ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HCH : 1; //!< HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either by software or by the Controller hardware (for example, an internal error). Only used in the host operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
        unsigned RCL : 1; //!< Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous schedule. Only used in the host operation mode.
        unsigned PS : 1; //!< Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Periodic Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned AS : 1; //!< Asynchronous Schedule Status - Read Only. This bit reports the current real status of the Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned NAKI : 1; //!< NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
        unsigned RESERVED2 : 7; //!< Reserved
        unsigned TI0 : 1; //!< General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
        unsigned TI1 : 1; //!< General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
        unsigned RESERVED3 : 6; //!< Reserved
    } B;
} hw_usbc__usbstsuh1_t;
#endif

/*
 * constants & macros for entire USBC__USBSTSUH1 register
 */
#define HW_USBC__USBSTSUH1_ADDR      (REGS_USBC_BASE + 0x344)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBSTSUH1           (*(volatile hw_usbc__usbstsuh1_t *) HW_USBC__USBSTSUH1_ADDR)
#define HW_USBC__USBSTSUH1_RD()      (HW_USBC__USBSTSUH1.U)
#define HW_USBC__USBSTSUH1_WR(v)     (HW_USBC__USBSTSUH1.U = (v))
#define HW_USBC__USBSTSUH1_SET(v)    (HW_USBC__USBSTSUH1_WR(HW_USBC__USBSTSUH1_RD() |  (v)))
#define HW_USBC__USBSTSUH1_CLR(v)    (HW_USBC__USBSTSUH1_WR(HW_USBC__USBSTSUH1_RD() & ~(v)))
#define HW_USBC__USBSTSUH1_TOG(v)    (HW_USBC__USBSTSUH1_WR(HW_USBC__USBSTSUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBSTSUH1 bitfields
 */

/* --- Register HW_USBC__USBSTSUH1, field UI[0:0] (RW)
 *
 * USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an
 * interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an
 * interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a
 * short packet is detected. A short packet is when the actual number of bytes received was less
 * than the expected number of bytes.
 */

#define BP_USBC__USBSTSUH1_UI      (0)
#define BM_USBC__USBSTSUH1_UI      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_UI(v)   ((((reg32_t) v) << 0) & BM_USBC__USBSTSUH1_UI)
#else
#define BF_USBC__USBSTSUH1_UI(v)   (((v) << 0) & BM_USBC__USBSTSUH1_UI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UI field to a new value.
#define BW_USBC__USBSTSUH1_UI(v)   BF_CS1(USBC__USBSTSUH1, UI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field UEI[1:1] (RW)
 *
 * USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error
 * condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT
 * bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit
 * set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e.
 * 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus,
 * Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of
 * host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual. The device controller detects resume signaling only.
 */

#define BP_USBC__USBSTSUH1_UEI      (1)
#define BM_USBC__USBSTSUH1_UEI      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_UEI(v)   ((((reg32_t) v) << 1) & BM_USBC__USBSTSUH1_UEI)
#else
#define BF_USBC__USBSTSUH1_UEI(v)   (((v) << 1) & BM_USBC__USBSTSUH1_UEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEI field to a new value.
#define BW_USBC__USBSTSUH1_UEI(v)   BF_CS1(USBC__USBSTSUH1, UEI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field PCI[2:2] (RW)
 *
 * Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect
 * Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the
 * result of a J-K transition on the suspended port. The Device Controller sets this bit to a one
 * when the port controller enters the full or high-speed operational state. When the port
 * controller exits the full or high-speed operation states due to Reset or Suspend events, the
 * notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
 */

#define BP_USBC__USBSTSUH1_PCI      (2)
#define BM_USBC__USBSTSUH1_PCI      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_PCI(v)   ((((reg32_t) v) << 2) & BM_USBC__USBSTSUH1_PCI)
#else
#define BF_USBC__USBSTSUH1_PCI(v)   (((v) << 2) & BM_USBC__USBSTSUH1_PCI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCI field to a new value.
#define BW_USBC__USBSTSUH1_PCI(v)   BF_CS1(USBC__USBSTSUH1, PCI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field FRI[3:3] (RW)
 *
 * Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index
 * rolls over from its maximum value to zero. The exact value at which the rollover occurs depends
 * on the frame list size. For example. If the frame list size (as programmed in the Frame List Size
 * field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX
 * [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every
 * time FHINDEX [12] toggles. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUH1_FRI      (3)
#define BM_USBC__USBSTSUH1_FRI      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_FRI(v)   ((((reg32_t) v) << 3) & BM_USBC__USBSTSUH1_FRI)
#else
#define BF_USBC__USBSTSUH1_FRI(v)   (((v) << 3) & BM_USBC__USBSTSUH1_FRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRI field to a new value.
#define BW_USBC__USBSTSUH1_FRI(v)   BF_CS1(USBC__USBSTSUH1, FRI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field SEI[4:4] (RW)
 *
 * System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on
 * the system interface.
 */

#define BP_USBC__USBSTSUH1_SEI      (4)
#define BM_USBC__USBSTSUH1_SEI      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_SEI(v)   ((((reg32_t) v) << 4) & BM_USBC__USBSTSUH1_SEI)
#else
#define BF_USBC__USBSTSUH1_SEI(v)   (((v) << 4) & BM_USBC__USBSTSUH1_SEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEI field to a new value.
#define BW_USBC__USBSTSUH1_SEI(v)   BF_CS1(USBC__USBSTSUH1, SEI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field AAI[5:5] (RW)
 *
 * Interrupt on Async Advance - R/WC. System software can force the host controller to issue an
 * interrupt the next time the host controller advances the asynchronous schedule by writing a one
 * to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit
 * indicates the assertion of that interrupt source. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUH1_AAI      (5)
#define BM_USBC__USBSTSUH1_AAI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_AAI(v)   ((((reg32_t) v) << 5) & BM_USBC__USBSTSUH1_AAI)
#else
#define BF_USBC__USBSTSUH1_AAI(v)   (((v) << 5) & BM_USBC__USBSTSUH1_AAI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAI field to a new value.
#define BW_USBC__USBSTSUH1_AAI(v)   BF_CS1(USBC__USBSTSUH1, AAI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field URI[6:6] (RW)
 *
 * USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default
 * state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset
 * Received status bit. Only used in device operation mode.
 */

#define BP_USBC__USBSTSUH1_URI      (6)
#define BM_USBC__USBSTSUH1_URI      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_URI(v)   ((((reg32_t) v) << 6) & BM_USBC__USBSTSUH1_URI)
#else
#define BF_USBC__USBSTSUH1_URI(v)   (((v) << 6) & BM_USBC__USBSTSUH1_URI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URI field to a new value.
#define BW_USBC__USBSTSUH1_URI(v)   BF_CS1(USBC__USBSTSUH1, URI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field SRI[7:7] (RW)
 *
 * SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will
 * be set to a one. When a SOF is extremely late, the device controller will automatically set this
 * bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in
 * device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is
 * received. Because the device controller is initialized to FS before connect, this bit will be set
 * at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set
 * every 125us and can be used by host controller driver as a time base. Software writes a 1 to this
 * bit to clear it.
 */

#define BP_USBC__USBSTSUH1_SRI      (7)
#define BM_USBC__USBSTSUH1_SRI      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_SRI(v)   ((((reg32_t) v) << 7) & BM_USBC__USBSTSUH1_SRI)
#else
#define BF_USBC__USBSTSUH1_SRI(v)   (((v) << 7) & BM_USBC__USBSTSUH1_SRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRI field to a new value.
#define BW_USBC__USBSTSUH1_SRI(v)   BF_CS1(USBC__USBSTSUH1, SRI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field SLI[8:8] (RW)
 *
 * DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be
 * set to a one. The device controller clears the bit upon exiting from a suspend state. Only used
 * in device operation mode.
 */

#define BP_USBC__USBSTSUH1_SLI      (8)
#define BM_USBC__USBSTSUH1_SLI      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_SLI(v)   ((((reg32_t) v) << 8) & BM_USBC__USBSTSUH1_SLI)
#else
#define BF_USBC__USBSTSUH1_SLI(v)   (((v) << 8) & BM_USBC__USBSTSUH1_SLI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLI field to a new value.
#define BW_USBC__USBSTSUH1_SLI(v)   BF_CS1(USBC__USBSTSUH1, SLI, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field ULPII[10:10] (RW)
 *
 * ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in
 * ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
 */

#define BP_USBC__USBSTSUH1_ULPII      (10)
#define BM_USBC__USBSTSUH1_ULPII      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_ULPII(v)   ((((reg32_t) v) << 10) & BM_USBC__USBSTSUH1_ULPII)
#else
#define BF_USBC__USBSTSUH1_ULPII(v)   (((v) << 10) & BM_USBC__USBSTSUH1_ULPII)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPII field to a new value.
#define BW_USBC__USBSTSUH1_ULPII(v)   BF_CS1(USBC__USBSTSUH1, ULPII, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field HCH[12:12] (RW)
 *
 * HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets
 * this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either
 * by software or by the Controller hardware (for example, an internal error). Only used in the host
 * operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is
 * because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
 */

#define BP_USBC__USBSTSUH1_HCH      (12)
#define BM_USBC__USBSTSUH1_HCH      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_HCH(v)   ((((reg32_t) v) << 12) & BM_USBC__USBSTSUH1_HCH)
#else
#define BF_USBC__USBSTSUH1_HCH(v)   (((v) << 12) & BM_USBC__USBSTSUH1_HCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCH field to a new value.
#define BW_USBC__USBSTSUH1_HCH(v)   BF_CS1(USBC__USBSTSUH1, HCH, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field RCL[13:13] (RW)
 *
 * Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous
 * schedule. Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUH1_RCL      (13)
#define BM_USBC__USBSTSUH1_RCL      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_RCL(v)   ((((reg32_t) v) << 13) & BM_USBC__USBSTSUH1_RCL)
#else
#define BF_USBC__USBSTSUH1_RCL(v)   (((v) << 13) & BM_USBC__USBSTSUH1_RCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCL field to a new value.
#define BW_USBC__USBSTSUH1_RCL(v)   BF_CS1(USBC__USBSTSUH1, RCL, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field PS[14:14] (RW)
 *
 * Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic
 * Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is
 * enabled. The Host Controller is not required to immediately disable or enable the Periodic
 * Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When
 * this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either
 * enabled (1) or disabled (0). Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUH1_PS      (14)
#define BM_USBC__USBSTSUH1_PS      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_PS(v)   ((((reg32_t) v) << 14) & BM_USBC__USBSTSUH1_PS)
#else
#define BF_USBC__USBSTSUH1_PS(v)   (((v) << 14) & BM_USBC__USBSTSUH1_PS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PS field to a new value.
#define BW_USBC__USBSTSUH1_PS(v)   BF_CS1(USBC__USBSTSUH1, PS, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field AS[15:15] (RW)
 *
 * Asynchronous Schedule Status - Read Only. This bit reports the current real status of the
 * Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set
 * to one the status is enabled. The Host Controller is not required to immediately disable or
 * enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit
 * in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same
 * value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host
 * operation mode.
 */

#define BP_USBC__USBSTSUH1_AS      (15)
#define BM_USBC__USBSTSUH1_AS      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_AS(v)   ((((reg32_t) v) << 15) & BM_USBC__USBSTSUH1_AS)
#else
#define BF_USBC__USBSTSUH1_AS(v)   (((v) << 15) & BM_USBC__USBSTSUH1_AS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AS field to a new value.
#define BW_USBC__USBSTSUH1_AS(v)   BF_CS1(USBC__USBSTSUH1, AS, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field NAKI[16:16] (RO)
 *
 * NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX
 * Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is
 * automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
 */

#define BP_USBC__USBSTSUH1_NAKI      (16)
#define BM_USBC__USBSTSUH1_NAKI      (0x00010000)

/* --- Register HW_USBC__USBSTSUH1, field TI0[24:24] (RW)
 *
 * General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the
 * GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
 */

#define BP_USBC__USBSTSUH1_TI0      (24)
#define BM_USBC__USBSTSUH1_TI0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_TI0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBSTSUH1_TI0)
#else
#define BF_USBC__USBSTSUH1_TI0(v)   (((v) << 24) & BM_USBC__USBSTSUH1_TI0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI0 field to a new value.
#define BW_USBC__USBSTSUH1_TI0(v)   BF_CS1(USBC__USBSTSUH1, TI0, v)
#endif

/* --- Register HW_USBC__USBSTSUH1, field TI1[25:25] (RW)
 *
 * General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the
 * GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
 */

#define BP_USBC__USBSTSUH1_TI1      (25)
#define BM_USBC__USBSTSUH1_TI1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH1_TI1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBSTSUH1_TI1)
#else
#define BF_USBC__USBSTSUH1_TI1(v)   (((v) << 25) & BM_USBC__USBSTSUH1_TI1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI1 field to a new value.
#define BW_USBC__USBSTSUH1_TI1(v)   BF_CS1(USBC__USBSTSUH1, TI1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBINTRUH1 - Interrupt Enable Register UH1 (RW)
 *
 * The interrupts to software are enabled with this register. An interrupt is generated when a bit
 * is set and the corresponding interrupt source is active. The USB Status register (n_USBSTS) still
 * shows interrupt sources even if they are disabled by the n_USBINTR register, allowing polling of
 * interrupt events by the software.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UE : 1; //!< USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned UEE : 1; //!< USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned PCE : 1; //!< Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned FRE : 1; //!< Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned SEE : 1; //!< System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned AAE : 1; //!< Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned URE : 1; //!< USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned SRE : 1; //!< SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned SLE : 1; //!< Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPIE : 1; //!< ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the controller will issue an interrupt. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 5; //!< These bits are reserved and should be set to zero.
        unsigned NAKE : 1; //!< NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned UAIE : 1; //!< USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned UPIE : 1; //!< USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned RESERVED3 : 4; //!< Reserved
        unsigned TIE0 : 1; //!< General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned TIE1 : 1; //!< General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED4 : 6; //!< Reserved
    } B;
} hw_usbc__usbintruh1_t;
#endif

/*
 * constants & macros for entire USBC__USBINTRUH1 register
 */
#define HW_USBC__USBINTRUH1_ADDR      (REGS_USBC_BASE + 0x348)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBINTRUH1           (*(volatile hw_usbc__usbintruh1_t *) HW_USBC__USBINTRUH1_ADDR)
#define HW_USBC__USBINTRUH1_RD()      (HW_USBC__USBINTRUH1.U)
#define HW_USBC__USBINTRUH1_WR(v)     (HW_USBC__USBINTRUH1.U = (v))
#define HW_USBC__USBINTRUH1_SET(v)    (HW_USBC__USBINTRUH1_WR(HW_USBC__USBINTRUH1_RD() |  (v)))
#define HW_USBC__USBINTRUH1_CLR(v)    (HW_USBC__USBINTRUH1_WR(HW_USBC__USBINTRUH1_RD() & ~(v)))
#define HW_USBC__USBINTRUH1_TOG(v)    (HW_USBC__USBINTRUH1_WR(HW_USBC__USBINTRUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBINTRUH1 bitfields
 */

/* --- Register HW_USBC__USBINTRUH1, field UE[0:0] (RW)
 *
 * USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_UE      (0)
#define BM_USBC__USBINTRUH1_UE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_UE(v)   ((((reg32_t) v) << 0) & BM_USBC__USBINTRUH1_UE)
#else
#define BF_USBC__USBINTRUH1_UE(v)   (((v) << 0) & BM_USBC__USBINTRUH1_UE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UE field to a new value.
#define BW_USBC__USBINTRUH1_UE(v)   BF_CS1(USBC__USBINTRUH1, UE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field UEE[1:1] (RW)
 *
 * USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_UEE      (1)
#define BM_USBC__USBINTRUH1_UEE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_UEE(v)   ((((reg32_t) v) << 1) & BM_USBC__USBINTRUH1_UEE)
#else
#define BF_USBC__USBINTRUH1_UEE(v)   (((v) << 1) & BM_USBC__USBINTRUH1_UEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEE field to a new value.
#define BW_USBC__USBINTRUH1_UEE(v)   BF_CS1(USBC__USBINTRUH1, UEE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field PCE[2:2] (RW)
 *
 * Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is
 * a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_PCE      (2)
#define BM_USBC__USBINTRUH1_PCE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_PCE(v)   ((((reg32_t) v) << 2) & BM_USBC__USBINTRUH1_PCE)
#else
#define BF_USBC__USBINTRUH1_PCE(v)   (((v) << 2) & BM_USBC__USBINTRUH1_PCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCE field to a new value.
#define BW_USBC__USBINTRUH1_PCE(v)   BF_CS1(USBC__USBINTRUH1, PCE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field FRE[3:3] (RW)
 *
 * Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is
 * a one the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH1_FRE      (3)
#define BM_USBC__USBINTRUH1_FRE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_FRE(v)   ((((reg32_t) v) << 3) & BM_USBC__USBINTRUH1_FRE)
#else
#define BF_USBC__USBINTRUH1_FRE(v)   (((v) << 3) & BM_USBC__USBINTRUH1_FRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRE field to a new value.
#define BW_USBC__USBINTRUH1_FRE(v)   BF_CS1(USBC__USBINTRUH1, FRE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field SEE[4:4] (RW)
 *
 * System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH1_SEE      (4)
#define BM_USBC__USBINTRUH1_SEE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_SEE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBINTRUH1_SEE)
#else
#define BF_USBC__USBINTRUH1_SEE(v)   (((v) << 4) & BM_USBC__USBINTRUH1_SEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEE field to a new value.
#define BW_USBC__USBINTRUH1_SEE(v)   BF_CS1(USBC__USBINTRUH1, SEE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field AAE[5:5] (RW)
 *
 * Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH1_AAE      (5)
#define BM_USBC__USBINTRUH1_AAE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_AAE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBINTRUH1_AAE)
#else
#define BF_USBC__USBINTRUH1_AAE(v)   (((v) << 5) & BM_USBC__USBINTRUH1_AAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAE field to a new value.
#define BW_USBC__USBINTRUH1_AAE(v)   BF_CS1(USBC__USBINTRUH1, AAE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field URE[6:6] (RW)
 *
 * USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one
 * the controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUH1_URE      (6)
#define BM_USBC__USBINTRUH1_URE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_URE(v)   ((((reg32_t) v) << 6) & BM_USBC__USBINTRUH1_URE)
#else
#define BF_USBC__USBINTRUH1_URE(v)   (((v) << 6) & BM_USBC__USBINTRUH1_URE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URE field to a new value.
#define BW_USBC__USBINTRUH1_URE(v)   BF_CS1(USBC__USBINTRUH1, URE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field SRE[7:7] (RW)
 *
 * SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one
 * the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_SRE      (7)
#define BM_USBC__USBINTRUH1_SRE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_SRE(v)   ((((reg32_t) v) << 7) & BM_USBC__USBINTRUH1_SRE)
#else
#define BF_USBC__USBINTRUH1_SRE(v)   (((v) << 7) & BM_USBC__USBINTRUH1_SRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRE field to a new value.
#define BW_USBC__USBINTRUH1_SRE(v)   BF_CS1(USBC__USBINTRUH1, SRE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field SLE[8:8] (RW)
 *
 * Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the
 * controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUH1_SLE      (8)
#define BM_USBC__USBINTRUH1_SLE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_SLE(v)   ((((reg32_t) v) << 8) & BM_USBC__USBINTRUH1_SLE)
#else
#define BF_USBC__USBINTRUH1_SLE(v)   (((v) << 8) & BM_USBC__USBINTRUH1_SLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLE field to a new value.
#define BW_USBC__USBINTRUH1_SLE(v)   BF_CS1(USBC__USBINTRUH1, SLE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field ULPIE[10:10] (RW)
 *
 * ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the
 * controller will issue an interrupt. This bit is usable only if the controller support UPLI
 * interface mode.
 */

#define BP_USBC__USBINTRUH1_ULPIE      (10)
#define BM_USBC__USBINTRUH1_ULPIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_ULPIE(v)   ((((reg32_t) v) << 10) & BM_USBC__USBINTRUH1_ULPIE)
#else
#define BF_USBC__USBINTRUH1_ULPIE(v)   (((v) << 10) & BM_USBC__USBINTRUH1_ULPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPIE field to a new value.
#define BW_USBC__USBINTRUH1_ULPIE(v)   BF_CS1(USBC__USBINTRUH1, ULPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field NAKE[16:16] (RW)
 *
 * NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_NAKE      (16)
#define BM_USBC__USBINTRUH1_NAKE      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_NAKE(v)   ((((reg32_t) v) << 16) & BM_USBC__USBINTRUH1_NAKE)
#else
#define BF_USBC__USBINTRUH1_NAKE(v)   (((v) << 16) & BM_USBC__USBINTRUH1_NAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NAKE field to a new value.
#define BW_USBC__USBINTRUH1_NAKE(v)   BF_CS1(USBC__USBINTRUH1, NAKE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field UAIE[18:18] (RW)
 *
 * USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS
 * register is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUH1_UAIE      (18)
#define BM_USBC__USBINTRUH1_UAIE      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_UAIE(v)   ((((reg32_t) v) << 18) & BM_USBC__USBINTRUH1_UAIE)
#else
#define BF_USBC__USBINTRUH1_UAIE(v)   (((v) << 18) & BM_USBC__USBINTRUH1_UAIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UAIE field to a new value.
#define BW_USBC__USBINTRUH1_UAIE(v)   BF_CS1(USBC__USBINTRUH1, UAIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field UPIE[19:19] (RW)
 *
 * USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register
 * is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUH1_UPIE      (19)
#define BM_USBC__USBINTRUH1_UPIE      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_UPIE(v)   ((((reg32_t) v) << 19) & BM_USBC__USBINTRUH1_UPIE)
#else
#define BF_USBC__USBINTRUH1_UPIE(v)   (((v) << 19) & BM_USBC__USBINTRUH1_UPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UPIE field to a new value.
#define BW_USBC__USBINTRUH1_UPIE(v)   BF_CS1(USBC__USBINTRUH1, UPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field TIE0[24:24] (RW)
 *
 * General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_TIE0      (24)
#define BM_USBC__USBINTRUH1_TIE0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_TIE0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBINTRUH1_TIE0)
#else
#define BF_USBC__USBINTRUH1_TIE0(v)   (((v) << 24) & BM_USBC__USBINTRUH1_TIE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE0 field to a new value.
#define BW_USBC__USBINTRUH1_TIE0(v)   BF_CS1(USBC__USBINTRUH1, TIE0, v)
#endif

/* --- Register HW_USBC__USBINTRUH1, field TIE1[25:25] (RW)
 *
 * General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH1_TIE1      (25)
#define BM_USBC__USBINTRUH1_TIE1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH1_TIE1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBINTRUH1_TIE1)
#else
#define BF_USBC__USBINTRUH1_TIE1(v)   (((v) << 25) & BM_USBC__USBINTRUH1_TIE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE1 field to a new value.
#define BW_USBC__USBINTRUH1_TIE1(v)   BF_CS1(USBC__USBINTRUH1, TIE1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__FRINDEXUH1 - USB Frame Index UH1 (RW)
 *
 * This register is used by the host controller to index the periodic frame list. The register
 * updates every 125 microseconds (once each micro-frame). Bits [N: 3] are used to select a
 * particular entry in the Periodic Frame List during periodic schedule execution. The number of
 * bits used for the index depends on the size of the frame list as set by system software in the
 * Frame List Size field in the n_USBCMD register.  This register must be written as a DWord. Byte
 * writes produce-undefined results. This register cannot be written unless the Host Controller is
 * in the 'Halted' state as indicated by the HCHalted bit. A write to this register while the
 * Run/Stop hit is set to a one produces undefined results. Writes to this register also affect the
 * SOF value.  In device mode this register is read only and, the device controller updates the
 * FRINDEX [13:3] register from the frame number indicated by the SOF marker. Whenever a SOF is
 * received by the USB bus, FRINDEX [13:3] will be checked against the SOF marker. If FRINDEX [13:3]
 * is different from the SOF marker, FRINDEX [13:3] will be set to the SOF value and FRINDEX [2:0]
 * will be set to zero (that is, SOF for 1 ms frame). If FRINDEX [13:3] is equal to the SOF value,
 * FRINDEX [2:0] will be increment (that is, SOF for 125 us micro-frame.).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FRINDEX : 14; //!< Frame Index. The value, in this register, increments at the end of each time frame (micro-frame). Bits [N: 3] are used for the Frame List current index. This means that each location of the frame list is accessed 8 times (frames or micro-frames) before moving to the next index. The following illustrates values of N based on the value of the Frame List Size field in the USBCMD register, when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is the current frame number of the last frame transmitted. It is not used as an index. In either mode bits 2:0 indicate the current microframe.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_usbc__frindexuh1_t;
#endif

/*
 * constants & macros for entire USBC__FRINDEXUH1 register
 */
#define HW_USBC__FRINDEXUH1_ADDR      (REGS_USBC_BASE + 0x34c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__FRINDEXUH1           (*(volatile hw_usbc__frindexuh1_t *) HW_USBC__FRINDEXUH1_ADDR)
#define HW_USBC__FRINDEXUH1_RD()      (HW_USBC__FRINDEXUH1.U)
#define HW_USBC__FRINDEXUH1_WR(v)     (HW_USBC__FRINDEXUH1.U = (v))
#define HW_USBC__FRINDEXUH1_SET(v)    (HW_USBC__FRINDEXUH1_WR(HW_USBC__FRINDEXUH1_RD() |  (v)))
#define HW_USBC__FRINDEXUH1_CLR(v)    (HW_USBC__FRINDEXUH1_WR(HW_USBC__FRINDEXUH1_RD() & ~(v)))
#define HW_USBC__FRINDEXUH1_TOG(v)    (HW_USBC__FRINDEXUH1_WR(HW_USBC__FRINDEXUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__FRINDEXUH1 bitfields
 */

/* --- Register HW_USBC__FRINDEXUH1, field FRINDEX[13:0] (RW)
 *
 * Frame Index. The value, in this register, increments at the end of each time frame (micro-frame).
 * Bits [N: 3] are used for the Frame List current index. This means that each location of the frame
 * list is accessed 8 times (frames or micro-frames) before moving to the next index. The following
 * illustrates values of N based on the value of the Frame List Size field in the USBCMD register,
 * when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is
 * the current frame number of the last frame transmitted. It is not used as an index. In either
 * mode bits 2:0 indicate the current microframe.
 *
 * Values:
 * 000 - (1024) 12
 * 001 - (512) 11
 * 010 - (256) 10
 * 011 - (128) 9
 * 100 - (64) 8
 * 101 - (32) 7
 * 110 - (16) 6
 * 111 - (8) 5
 */

#define BP_USBC__FRINDEXUH1_FRINDEX      (0)
#define BM_USBC__FRINDEXUH1_FRINDEX      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__FRINDEXUH1_FRINDEX(v)   ((((reg32_t) v) << 0) & BM_USBC__FRINDEXUH1_FRINDEX)
#else
#define BF_USBC__FRINDEXUH1_FRINDEX(v)   (((v) << 0) & BM_USBC__FRINDEXUH1_FRINDEX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRINDEX field to a new value.
#define BW_USBC__FRINDEXUH1_FRINDEX(v)   BF_CS1(USBC__FRINDEXUH1, FRINDEX, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PERIODICLISTBASEUH1 - Frame List Base Address UH1 (RW)
 *
 * Host Controller only  This 32-bit register contains the beginning address of the Periodic Frame
 * List in the system memory. HCD loads this register prior to starting the schedule execution by
 * the Host Controller. The memory structure referenced by this physical memory pointer is assumed
 * to be 4-Kbyte aligned. The contents of this register are combined with the Frame Index Register
 * (UOG_FRINDEX) to enable the Host Controller to step through the Periodic Frame List in sequence.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 12; //!< Reserved
        unsigned BASEADR : 20; //!< Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only used by the host controller.
    } B;
} hw_usbc__periodiclistbaseuh1_t;
#endif

/*
 * constants & macros for entire USBC__PERIODICLISTBASEUH1 register
 */
#define HW_USBC__PERIODICLISTBASEUH1_ADDR      (REGS_USBC_BASE + 0x354)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PERIODICLISTBASEUH1           (*(volatile hw_usbc__periodiclistbaseuh1_t *) HW_USBC__PERIODICLISTBASEUH1_ADDR)
#define HW_USBC__PERIODICLISTBASEUH1_RD()      (HW_USBC__PERIODICLISTBASEUH1.U)
#define HW_USBC__PERIODICLISTBASEUH1_WR(v)     (HW_USBC__PERIODICLISTBASEUH1.U = (v))
#define HW_USBC__PERIODICLISTBASEUH1_SET(v)    (HW_USBC__PERIODICLISTBASEUH1_WR(HW_USBC__PERIODICLISTBASEUH1_RD() |  (v)))
#define HW_USBC__PERIODICLISTBASEUH1_CLR(v)    (HW_USBC__PERIODICLISTBASEUH1_WR(HW_USBC__PERIODICLISTBASEUH1_RD() & ~(v)))
#define HW_USBC__PERIODICLISTBASEUH1_TOG(v)    (HW_USBC__PERIODICLISTBASEUH1_WR(HW_USBC__PERIODICLISTBASEUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PERIODICLISTBASEUH1 bitfields
 */

/* --- Register HW_USBC__PERIODICLISTBASEUH1, field BASEADR[31:12] (RW)
 *
 * Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only
 * used by the host controller.
 */

#define BP_USBC__PERIODICLISTBASEUH1_BASEADR      (12)
#define BM_USBC__PERIODICLISTBASEUH1_BASEADR      (0xfffff000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PERIODICLISTBASEUH1_BASEADR(v)   ((((reg32_t) v) << 12) & BM_USBC__PERIODICLISTBASEUH1_BASEADR)
#else
#define BF_USBC__PERIODICLISTBASEUH1_BASEADR(v)   (((v) << 12) & BM_USBC__PERIODICLISTBASEUH1_BASEADR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASEADR field to a new value.
#define BW_USBC__PERIODICLISTBASEUH1_BASEADR(v)   BF_CS1(USBC__PERIODICLISTBASEUH1, BASEADR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__ASYNCLISTADDRUH1 - Next Asynch. Address UH1 (RW)
 *
 * Host Controller only  This 32-bit register contains the address of the next asynchronous queue
 * head to be executed by the host. Bits [4:0] of this register cannot be modified by the system
 * software and will always return a zero when read.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned ASYBASE : 27; //!< Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively. This field may only reference a Queue Head (QH). Only used by the host controller.
    } B;
} hw_usbc__asynclistaddruh1_t;
#endif

/*
 * constants & macros for entire USBC__ASYNCLISTADDRUH1 register
 */
#define HW_USBC__ASYNCLISTADDRUH1_ADDR      (REGS_USBC_BASE + 0x358)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__ASYNCLISTADDRUH1           (*(volatile hw_usbc__asynclistaddruh1_t *) HW_USBC__ASYNCLISTADDRUH1_ADDR)
#define HW_USBC__ASYNCLISTADDRUH1_RD()      (HW_USBC__ASYNCLISTADDRUH1.U)
#define HW_USBC__ASYNCLISTADDRUH1_WR(v)     (HW_USBC__ASYNCLISTADDRUH1.U = (v))
#define HW_USBC__ASYNCLISTADDRUH1_SET(v)    (HW_USBC__ASYNCLISTADDRUH1_WR(HW_USBC__ASYNCLISTADDRUH1_RD() |  (v)))
#define HW_USBC__ASYNCLISTADDRUH1_CLR(v)    (HW_USBC__ASYNCLISTADDRUH1_WR(HW_USBC__ASYNCLISTADDRUH1_RD() & ~(v)))
#define HW_USBC__ASYNCLISTADDRUH1_TOG(v)    (HW_USBC__ASYNCLISTADDRUH1_WR(HW_USBC__ASYNCLISTADDRUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__ASYNCLISTADDRUH1 bitfields
 */

/* --- Register HW_USBC__ASYNCLISTADDRUH1, field ASYBASE[31:5] (RW)
 *
 * Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively.
 * This field may only reference a Queue Head (QH). Only used by the host controller.
 */

#define BP_USBC__ASYNCLISTADDRUH1_ASYBASE      (5)
#define BM_USBC__ASYNCLISTADDRUH1_ASYBASE      (0xffffffe0)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ASYNCLISTADDRUH1_ASYBASE(v)   ((((reg32_t) v) << 5) & BM_USBC__ASYNCLISTADDRUH1_ASYBASE)
#else
#define BF_USBC__ASYNCLISTADDRUH1_ASYBASE(v)   (((v) << 5) & BM_USBC__ASYNCLISTADDRUH1_ASYBASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASYBASE field to a new value.
#define BW_USBC__ASYNCLISTADDRUH1_ASYBASE(v)   BF_CS1(USBC__ASYNCLISTADDRUH1, ASYBASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__BURSTSIZEUH1 - Programmable Burst Size UH1 (RW)
 *
 * This register is used to control the burst size used during data movement on the AHB master
 * interface. This register is ignored if AHBBRST bits in SBUSCFG register is non-zero value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXPBURST : 8; //!< Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from the USB bus to system memory.
        unsigned TXPBURST : 9; //!< Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from system memory to the USB bus.
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_usbc__burstsizeuh1_t;
#endif

/*
 * constants & macros for entire USBC__BURSTSIZEUH1 register
 */
#define HW_USBC__BURSTSIZEUH1_ADDR      (REGS_USBC_BASE + 0x360)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__BURSTSIZEUH1           (*(volatile hw_usbc__burstsizeuh1_t *) HW_USBC__BURSTSIZEUH1_ADDR)
#define HW_USBC__BURSTSIZEUH1_RD()      (HW_USBC__BURSTSIZEUH1.U)
#define HW_USBC__BURSTSIZEUH1_WR(v)     (HW_USBC__BURSTSIZEUH1.U = (v))
#define HW_USBC__BURSTSIZEUH1_SET(v)    (HW_USBC__BURSTSIZEUH1_WR(HW_USBC__BURSTSIZEUH1_RD() |  (v)))
#define HW_USBC__BURSTSIZEUH1_CLR(v)    (HW_USBC__BURSTSIZEUH1_WR(HW_USBC__BURSTSIZEUH1_RD() & ~(v)))
#define HW_USBC__BURSTSIZEUH1_TOG(v)    (HW_USBC__BURSTSIZEUH1_WR(HW_USBC__BURSTSIZEUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__BURSTSIZEUH1 bitfields
 */

/* --- Register HW_USBC__BURSTSIZEUH1, field RXPBURST[7:0] (RW)
 *
 * Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from the
 * USB bus to system memory.
 */

#define BP_USBC__BURSTSIZEUH1_RXPBURST      (0)
#define BM_USBC__BURSTSIZEUH1_RXPBURST      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUH1_RXPBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__BURSTSIZEUH1_RXPBURST)
#else
#define BF_USBC__BURSTSIZEUH1_RXPBURST(v)   (((v) << 0) & BM_USBC__BURSTSIZEUH1_RXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUH1_RXPBURST(v)   BF_CS1(USBC__BURSTSIZEUH1, RXPBURST, v)
#endif

/* --- Register HW_USBC__BURSTSIZEUH1, field TXPBURST[16:8] (RW)
 *
 * Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from
 * system memory to the USB bus.
 */

#define BP_USBC__BURSTSIZEUH1_TXPBURST      (8)
#define BM_USBC__BURSTSIZEUH1_TXPBURST      (0x0001ff00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUH1_TXPBURST(v)   ((((reg32_t) v) << 8) & BM_USBC__BURSTSIZEUH1_TXPBURST)
#else
#define BF_USBC__BURSTSIZEUH1_TXPBURST(v)   (((v) << 8) & BM_USBC__BURSTSIZEUH1_TXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUH1_TXPBURST(v)   BF_CS1(USBC__BURSTSIZEUH1, TXPBURST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__TXFILLTUNINGUH1 - TX FIFO Fill Tuning UH1 (RW)
 *
 * The fields in this register control performance tuning associated with how the host controller
 * posts data to the TX latency FIFO before moving the data onto the USB bus. The specific areas of
 * performance include the how much data to post into the FIFO and an estimate for how long that
 * operation should take in the target system.  Definitions:  T 0 = Standard packet overhead  T 1 =
 * Time to send data payload  T ff = Time to fetch packet into TX FIFO up to specified level.  T s =
 * Total Packet Flight Time (send-only) packet  T s = T 0 + T 1   T p = Total Packet Time (fetch and
 * send) packet  T p = T ff + T 0 + T 1   Upon discovery of a transmit (OUT/SETUP) packet in the
 * data structures, host controller checks to ensure T  p  remains before the end of the
 * [micro]frame. If so it proceeds to pre-fill the TX FIFO. If at anytime during the pre-fill
 * operation the time remaining the [micro]frame is < T  s  then the packet attempt ceases and the
 * packet is tried at a later time. Although this is not an error condition and the host controller
 * will eventually recover, a mark will be made the scheduler health counter to note the occurrence
 * of a "back-off" event. When a back-off event is detected, the partial packet fetched may need to
 * be discarded from the latency buffer to make room for periodic traffic that will begin after the
 * next SOF. Too many back-off events can waste bandwidth and power on the system bus and thus
 * should be minimized (not necessarily eliminated). Back-offs can be minimized with use of the
 * n_TSCHHEALTH ( T  ff ) described below.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXSCHOH : 8; //!< Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to the schedule time estimator described above as Tff. As an approximation, the value chosen for this register should limit the number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a highly utilized bus. Choosing a value that is too high for this register is not desired as it can needlessly reduce USB utilization. The time unit represented in this register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned TXSCHHEALTH : 5; //!< Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of time to send the packet before the next Start-Of-Frame. This health counter measures the number of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the counter and this counter will max. at 31. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXFIFOTHRES : 6; //!< FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum value is 2 and this value should be a low as possible to maximize USB performance. A higher value can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO may underrun because the data transferred from the latency FIFO to USB occurs before it can be replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED1 : 10; //!< Reserved
    } B;
} hw_usbc__txfilltuninguh1_t;
#endif

/*
 * constants & macros for entire USBC__TXFILLTUNINGUH1 register
 */
#define HW_USBC__TXFILLTUNINGUH1_ADDR      (REGS_USBC_BASE + 0x364)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__TXFILLTUNINGUH1           (*(volatile hw_usbc__txfilltuninguh1_t *) HW_USBC__TXFILLTUNINGUH1_ADDR)
#define HW_USBC__TXFILLTUNINGUH1_RD()      (HW_USBC__TXFILLTUNINGUH1.U)
#define HW_USBC__TXFILLTUNINGUH1_WR(v)     (HW_USBC__TXFILLTUNINGUH1.U = (v))
#define HW_USBC__TXFILLTUNINGUH1_SET(v)    (HW_USBC__TXFILLTUNINGUH1_WR(HW_USBC__TXFILLTUNINGUH1_RD() |  (v)))
#define HW_USBC__TXFILLTUNINGUH1_CLR(v)    (HW_USBC__TXFILLTUNINGUH1_WR(HW_USBC__TXFILLTUNINGUH1_RD() & ~(v)))
#define HW_USBC__TXFILLTUNINGUH1_TOG(v)    (HW_USBC__TXFILLTUNINGUH1_WR(HW_USBC__TXFILLTUNINGUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__TXFILLTUNINGUH1 bitfields
 */

/* --- Register HW_USBC__TXFILLTUNINGUH1, field TXSCHOH[7:0] (RW)
 *
 * Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to
 * the schedule time estimator described above as Tff. As an approximation, the value chosen for
 * this register should limit the number of back-off events captured in the TXSCHHEALTH to less than
 * 10 per second in a highly utilized bus. Choosing a value that is too high for this register is
 * not desired as it can needlessly reduce USB utilization. The time unit represented in this
 * register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in
 * this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is
 * '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUH1_TXSCHOH      (0)
#define BM_USBC__TXFILLTUNINGUH1_TXSCHOH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH1_TXSCHOH(v)   ((((reg32_t) v) << 0) & BM_USBC__TXFILLTUNINGUH1_TXSCHOH)
#else
#define BF_USBC__TXFILLTUNINGUH1_TXSCHOH(v)   (((v) << 0) & BM_USBC__TXFILLTUNINGUH1_TXSCHOH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHOH field to a new value.
#define BW_USBC__TXFILLTUNINGUH1_TXSCHOH(v)   BF_CS1(USBC__TXFILLTUNINGUH1, TXSCHOH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUH1, field TXSCHHEALTH[12:8] (RW)
 *
 * Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller
 * fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of
 * time to send the packet before the next Start-Of-Frame. This health counter measures the number
 * of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register
 * will clear the counter and this counter will max. at 31. Default value is '08h' for OTG
 * controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUH1_TXSCHHEALTH      (8)
#define BM_USBC__TXFILLTUNINGUH1_TXSCHHEALTH      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH1_TXSCHHEALTH(v)   ((((reg32_t) v) << 8) & BM_USBC__TXFILLTUNINGUH1_TXSCHHEALTH)
#else
#define BF_USBC__TXFILLTUNINGUH1_TXSCHHEALTH(v)   (((v) << 8) & BM_USBC__TXFILLTUNINGUH1_TXSCHHEALTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHHEALTH field to a new value.
#define BW_USBC__TXFILLTUNINGUH1_TXSCHHEALTH(v)   BF_CS1(USBC__TXFILLTUNINGUH1, TXSCHHEALTH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUH1, field TXFIFOTHRES[21:16] (RW)
 *
 * FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are
 * posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum
 * value is 2 and this value should be a low as possible to maximize USB performance. A higher value
 * can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO
 * may underrun because the data transferred from the latency FIFO to USB occurs before it can be
 * replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE
 * register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3
 * controller core.
 */

#define BP_USBC__TXFILLTUNINGUH1_TXFIFOTHRES      (16)
#define BM_USBC__TXFILLTUNINGUH1_TXFIFOTHRES      (0x003f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH1_TXFIFOTHRES(v)   ((((reg32_t) v) << 16) & BM_USBC__TXFILLTUNINGUH1_TXFIFOTHRES)
#else
#define BF_USBC__TXFILLTUNINGUH1_TXFIFOTHRES(v)   (((v) << 16) & BM_USBC__TXFILLTUNINGUH1_TXFIFOTHRES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFOTHRES field to a new value.
#define BW_USBC__TXFILLTUNINGUH1_TXFIFOTHRES(v)   BF_CS1(USBC__TXFILLTUNINGUH1, TXFIFOTHRES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IC_USBUH1 - IC_USB enable and voltage negotiation UH1 (RW)
 *
 * This register enable and controls the IC-USB FS/LS transceiver.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IC_VDD1 : 3; //!< These bits indicates which voltage is being supplied to the peripheral This field is read-only and set to 000 in case of a device controller.
        unsigned IC1 : 1; //!< Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1 is enabled, IOMUX must set the DP/DM pad into loopback mode.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__ic_usbuh1_t;
#endif

/*
 * constants & macros for entire USBC__IC_USBUH1 register
 */
#define HW_USBC__IC_USBUH1_ADDR      (REGS_USBC_BASE + 0x36c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IC_USBUH1           (*(volatile hw_usbc__ic_usbuh1_t *) HW_USBC__IC_USBUH1_ADDR)
#define HW_USBC__IC_USBUH1_RD()      (HW_USBC__IC_USBUH1.U)
#define HW_USBC__IC_USBUH1_WR(v)     (HW_USBC__IC_USBUH1.U = (v))
#define HW_USBC__IC_USBUH1_SET(v)    (HW_USBC__IC_USBUH1_WR(HW_USBC__IC_USBUH1_RD() |  (v)))
#define HW_USBC__IC_USBUH1_CLR(v)    (HW_USBC__IC_USBUH1_WR(HW_USBC__IC_USBUH1_RD() & ~(v)))
#define HW_USBC__IC_USBUH1_TOG(v)    (HW_USBC__IC_USBUH1_WR(HW_USBC__IC_USBUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__IC_USBUH1 bitfields
 */

/* --- Register HW_USBC__IC_USBUH1, field IC_VDD1[2:0] (RW)
 *
 * These bits indicates which voltage is being supplied to the peripheral This field is read-only
 * and set to 000 in case of a device controller.
 *
 * Values:
 * 000 - No voltage
 * 001 - 1.0 V
 * 010 - 1.2 V
 * 011 - 1.5 V
 * 100 - 1.8 V
 * 101 - 3.0 V
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_USBC__IC_USBUH1_IC_VDD1      (0)
#define BM_USBC__IC_USBUH1_IC_VDD1      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUH1_IC_VDD1(v)   ((((reg32_t) v) << 0) & BM_USBC__IC_USBUH1_IC_VDD1)
#else
#define BF_USBC__IC_USBUH1_IC_VDD1(v)   (((v) << 0) & BM_USBC__IC_USBUH1_IC_VDD1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC_VDD1 field to a new value.
#define BW_USBC__IC_USBUH1_IC_VDD1(v)   BF_CS1(USBC__IC_USBUH1, IC_VDD1, v)
#endif


/* --- Register HW_USBC__IC_USBUH1, field IC1[3:3] (RW)
 *
 * Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB
 * interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1
 * is enabled, IOMUX must set the DP/DM pad into loopback mode.
 */

#define BP_USBC__IC_USBUH1_IC1      (3)
#define BM_USBC__IC_USBUH1_IC1      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUH1_IC1(v)   ((((reg32_t) v) << 3) & BM_USBC__IC_USBUH1_IC1)
#else
#define BF_USBC__IC_USBUH1_IC1(v)   (((v) << 3) & BM_USBC__IC_USBUH1_IC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC1 field to a new value.
#define BW_USBC__IC_USBUH1_IC1(v)   BF_CS1(USBC__IC_USBUH1, IC1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PORTSC1UH1 - Port Status & Control UH1 (RW)
 *
 * Host Controller  A host controller could implement one to eight port status and control
 * registers. The number is determined by N_PORTs bits in HWSPARAMs register (please see ). Software
 * could read this parameter register to determine how many ports need service.  All 4 controller
 * cores are Single-Port Host, so there is only one port status and control register for each
 * controller core.  This register is only reset by power on reset or controller core reset. The
 * initial conditions of a port are:   No device connected  Port disabled   If the port supports
 * power control, this state remains until port power is supplied (by software).  Device Controller
 * A device controller has only port register one (PORTSC1) and it does not support power control.
 * Port control in device mode is only used for status port reset, suspend, and current connect
 * status. It is also used to initiate test mode or force signaling and allows software to put the
 * PHY into low power suspend mode and disable the PHY clock.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CCS : 1; //!< Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is present. Default = 0. This value reflects the current state of the port, and may not correspond directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached. Default=0. A one indicates that the device successfully attached and is operating in either high speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates that the device did not attach successfully or was forcibly disconnected by the software writing a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or suspended.
        unsigned CSC : 1; //!< Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device controller sets this bit for all changes to the port device connect status, even if system software has not cleared an existing connect status change. For example, the insertion status changes twice before system software has cleared the changed condition, hub hardware will be 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode: This bit is undefined in device controller mode.
        unsigned PE : 1; //!< Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be enabled by the host controller as a part of the reset and enable. Software cannot enable a port by writing a one to this field. Ports can be disabled by either a fault condition (disconnect event or other fault condition) or by the host software. Note that the bit status does not change until the port state actually changes. There may be a delay in disabling or enabling a port due to other host controller and bus events. When the port is disabled, (0b) downstream propagation of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In Device Mode: The device port is always enabled, so this bit is always '1b'.
        unsigned PEC : 1; //!< Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is always '0b'.
        unsigned OCA : 1; //!< Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero when the over current condition is removed. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned OCC : 1; //!< Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to Over-current Active. Software can clear this bit by writing a one to this bit position. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned FPR : 1; //!< Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state) detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will automatically change to zero after the resume sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the resume duration is timed in the driver. Note that when the Host controller owns the port, the resume sequence follows the defined sequence documented in the USB Specification Revision 2.0. The resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no affect because the port controller will time the resume operation clear the bit the port control state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or more, software must set this bit to one to drive resume signaling before clearing. The Device Controller will set this bit to one if a J-to-K transition is detected while the port is in the Suspend state. The bit will be cleared when the device returns to normal operation. Also, when this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the USBSTS register is also set to one.
        unsigned SUSP : 1; //!< Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend When in suspend state, downstream propagation of data is blocked on this port, except for port reset. The blocking occurs at the end of the current transaction if a transaction was in progress when this bit was written to 1. In the suspend state, the port is sensitive to resume detection. Note that the bit status does not change until the port is suspended and that there may be a delay in suspending a port if there is a transaction currently in progress on the The host controller will unconditionally set this bit to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write of zero to this bit. If host software sets this bit to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only. In device mode this bit is a read only status bit.
        unsigned PR : 1; //!< Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset. 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence as defined in the USB Specification Revision 2.0 is started. This bit will automatically change to zero after the reset sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the reset duration is timed in the driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
        unsigned HSP : 1; //!< High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the port is in high-speed mode and if set to zero, the host/device connected to the port is not in a high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
        unsigned LS : 2; //!< Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D- (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not necessary (unlike EHCI), because the port controller state machine and the port routing manage the connection of LS and FS. In device mode, the use of linestate by the device controller driver is not necessary. The encoding of the bits are: Bits [11:10] Meaning
        unsigned PP : 1; //!< Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP Operation 0 1b Read Only - Host controller does not have port power control switches. Each port is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not available on a port (that is, PP equals a 0), the port is non-functional and will not report attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is a one, the PP bit in each affected port may be transitional by the host controller driver from a one to a zero (removing power from the port). This feature is implemented in all 4 controller cores (PPC = 1).
        unsigned PO : 1; //!< Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever the Configured bit is zero System software uses this field to release ownership of the port to a selected host controller (in the event that the attached device is not a high-speed device). Software writes a one to this bit when the attached device is not a high-speed device. A one in this bit means that an internal companion controller owns and controls the port. Port owner handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
        unsigned PIC : 2; //!< Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0 for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit Value Meaning
        unsigned PTC : 4; //!< Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS} values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point. Low speed operations are not supported as a peripheral device. Any other value than zero indicates that the port is operating in test mode. Value Specific Test
        unsigned WKCN : 1; //!< Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKDC : 1; //!< Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device disconnects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKOC : 1; //!< Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one enables the port to be sensitive to over-current conditions as wake-up events. This field is zero if Port Power( ) is zero.
        unsigned PHCD : 1; //!< PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock. The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically when the host initials resume. Before forcing a resume from the device, the device controller driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the downstream device has been put into suspend mode or when no downstream device is connected. Low power suspend is completely under the control of software.
        unsigned PFSC : 1; //!< Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port to identify itself as High Speed.
        unsigned PTS : 1; //!< See description at bits 31-30
        unsigned PSPD : 2; //!< Port Speed - Read Only. This register field indicates the speed at which the port is operating. For HS mode operation in the host controller and HS/FS operation in the device controller the port routing steers data to the Protocol engine. For FS and LS mode operation in the host controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction Translator.
        unsigned PTW : 1; //!< Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16 selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0 selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0; For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver Width This bit has no effect if serial interface engine is used. These register bits are implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3 core, it is Read-Only. Reset value is '1b'.
        unsigned STS : 1; //!< Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver interface is selected for FS and LS operation. The Serial Interface Engine can be used in combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for future operation and is a placeholder adding dynamic use of the serial engine in accord with UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita, OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select - Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value. Serial Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value.
        unsigned PTS1 : 2; //!< Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30, bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE = 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 - Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7; For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b" Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC All USB port interface modes are listed in this field description, but not all are supported. For detail feature of each controller core, please see . The behaviour is unknown when unsupported interface mode is selected.
    } B;
} hw_usbc__portsc1uh1_t;
#endif

/*
 * constants & macros for entire USBC__PORTSC1UH1 register
 */
#define HW_USBC__PORTSC1UH1_ADDR      (REGS_USBC_BASE + 0x384)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PORTSC1UH1           (*(volatile hw_usbc__portsc1uh1_t *) HW_USBC__PORTSC1UH1_ADDR)
#define HW_USBC__PORTSC1UH1_RD()      (HW_USBC__PORTSC1UH1.U)
#define HW_USBC__PORTSC1UH1_WR(v)     (HW_USBC__PORTSC1UH1.U = (v))
#define HW_USBC__PORTSC1UH1_SET(v)    (HW_USBC__PORTSC1UH1_WR(HW_USBC__PORTSC1UH1_RD() |  (v)))
#define HW_USBC__PORTSC1UH1_CLR(v)    (HW_USBC__PORTSC1UH1_WR(HW_USBC__PORTSC1UH1_RD() & ~(v)))
#define HW_USBC__PORTSC1UH1_TOG(v)    (HW_USBC__PORTSC1UH1_WR(HW_USBC__PORTSC1UH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PORTSC1UH1 bitfields
 */

/* --- Register HW_USBC__PORTSC1UH1, field CCS[0:0] (RW)
 *
 * Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is
 * present. Default = 0. This value reflects the current state of the port, and may not correspond
 * directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is
 * zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached.
 * Default=0. A one indicates that the device successfully attached and is operating in either high
 * speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates
 * that the device did not attach successfully or was forcibly disconnected by the software writing
 * a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or
 * suspended.
 */

#define BP_USBC__PORTSC1UH1_CCS      (0)
#define BM_USBC__PORTSC1UH1_CCS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_CCS(v)   ((((reg32_t) v) << 0) & BM_USBC__PORTSC1UH1_CCS)
#else
#define BF_USBC__PORTSC1UH1_CCS(v)   (((v) << 0) & BM_USBC__PORTSC1UH1_CCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CCS field to a new value.
#define BW_USBC__PORTSC1UH1_CCS(v)   BF_CS1(USBC__PORTSC1UH1, CCS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field CSC[1:1] (RW)
 *
 * Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host
 * Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device
 * controller sets this bit for all changes to the port device connect status, even if system
 * software has not cleared an existing connect status change. For example, the insertion status
 * changes twice before system software has cleared the changed condition, hub hardware will be
 * 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by
 * writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode:
 * This bit is undefined in device controller mode.
 */

#define BP_USBC__PORTSC1UH1_CSC      (1)
#define BM_USBC__PORTSC1UH1_CSC      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_CSC(v)   ((((reg32_t) v) << 1) & BM_USBC__PORTSC1UH1_CSC)
#else
#define BF_USBC__PORTSC1UH1_CSC(v)   (((v) << 1) & BM_USBC__PORTSC1UH1_CSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC field to a new value.
#define BW_USBC__PORTSC1UH1_CSC(v)   BF_CS1(USBC__PORTSC1UH1, CSC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PE[2:2] (RW)
 *
 * Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be
 * enabled by the host controller as a part of the reset and enable. Software cannot enable a port
 * by writing a one to this field. Ports can be disabled by either a fault condition (disconnect
 * event or other fault condition) or by the host software. Note that the bit status does not change
 * until the port state actually changes. There may be a delay in disabling or enabling a port due
 * to other host controller and bus events. When the port is disabled, (0b) downstream propagation
 * of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In
 * Device Mode: The device port is always enabled, so this bit is always '1b'.
 */

#define BP_USBC__PORTSC1UH1_PE      (2)
#define BM_USBC__PORTSC1UH1_PE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PE(v)   ((((reg32_t) v) << 2) & BM_USBC__PORTSC1UH1_PE)
#else
#define BF_USBC__PORTSC1UH1_PE(v)   (((v) << 2) & BM_USBC__PORTSC1UH1_PE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PE field to a new value.
#define BW_USBC__PORTSC1UH1_PE(v)   BF_CS1(USBC__PORTSC1UH1, PE, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PEC[3:3] (RW)
 *
 * Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default
 * = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to
 * disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See
 * Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is
 * zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is
 * always '0b'.
 */

#define BP_USBC__PORTSC1UH1_PEC      (3)
#define BM_USBC__PORTSC1UH1_PEC      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PEC(v)   ((((reg32_t) v) << 3) & BM_USBC__PORTSC1UH1_PEC)
#else
#define BF_USBC__PORTSC1UH1_PEC(v)   (((v) << 3) & BM_USBC__PORTSC1UH1_PEC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PEC field to a new value.
#define BW_USBC__PORTSC1UH1_PEC(v)   BF_CS1(USBC__PORTSC1UH1, PEC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field OCA[4:4] (RW)
 *
 * Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero
 * when the over current condition is removed. For host/OTG implementations the user can provide
 * over-current detection to the vbus_pwr_fault input for this condition. For device-only
 * implementations this bit shall always be 0.
 *
 * Values:
 * 0 - This port does not have an over-current condition.
 * 1 - This port currently has an over-current condition
 */

#define BP_USBC__PORTSC1UH1_OCA      (4)
#define BM_USBC__PORTSC1UH1_OCA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_OCA(v)   ((((reg32_t) v) << 4) & BM_USBC__PORTSC1UH1_OCA)
#else
#define BF_USBC__PORTSC1UH1_OCA(v)   (((v) << 4) & BM_USBC__PORTSC1UH1_OCA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCA field to a new value.
#define BW_USBC__PORTSC1UH1_OCA(v)   BF_CS1(USBC__PORTSC1UH1, OCA, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field OCC[5:5] (RW)
 *
 * Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to
 * Over-current Active. Software can clear this bit by writing a one to this bit position. For
 * host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input
 * for this condition. For device-only implementations this bit shall always be 0.
 */

#define BP_USBC__PORTSC1UH1_OCC      (5)
#define BM_USBC__PORTSC1UH1_OCC      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_OCC(v)   ((((reg32_t) v) << 5) & BM_USBC__PORTSC1UH1_OCC)
#else
#define BF_USBC__PORTSC1UH1_OCC(v)   (((v) << 5) & BM_USBC__PORTSC1UH1_OCC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCC field to a new value.
#define BW_USBC__PORTSC1UH1_OCC(v)   BF_CS1(USBC__PORTSC1UH1, OCC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field FPR[6:6] (RW)
 *
 * Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state)
 * detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume
 * signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the
 * port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is
 * detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will
 * automatically change to zero after the resume sequence is complete. This behavior is different
 * from EHCI where the host controller driver is required to set this bit to a zero after the resume
 * duration is timed in the driver. Note that when the Host controller owns the port, the resume
 * sequence follows the defined sequence documented in the USB Specification Revision 2.0. The
 * resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This
 * bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no
 * affect because the port controller will time the resume operation clear the bit the port control
 * state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This
 * bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or
 * more, software must set this bit to one to drive resume signaling before clearing. The Device
 * Controller will set this bit to one if a J-to-K transition is detected while the port is in the
 * Suspend state. The bit will be cleared when the device returns to normal operation. Also, when
 * this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the
 * USBSTS register is also set to one.
 */

#define BP_USBC__PORTSC1UH1_FPR      (6)
#define BM_USBC__PORTSC1UH1_FPR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_FPR(v)   ((((reg32_t) v) << 6) & BM_USBC__PORTSC1UH1_FPR)
#else
#define BF_USBC__PORTSC1UH1_FPR(v)   (((v) << 6) & BM_USBC__PORTSC1UH1_FPR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FPR field to a new value.
#define BW_USBC__PORTSC1UH1_FPR(v)   BF_CS1(USBC__PORTSC1UH1, FPR, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field SUSP[7:7] (RW)
 *
 * Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend
 * state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the
 * port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend
 * When in suspend state, downstream propagation of data is blocked on this port, except for port
 * reset. The blocking occurs at the end of the current transaction if a transaction was in progress
 * when this bit was written to 1. In the suspend state, the port is sensitive to resume detection.
 * Note that the bit status does not change until the port is suspended and that there may be a
 * delay in suspending a port if there is a transaction currently in progress on the The host
 * controller will unconditionally set this bit to zero when software sets the Force Port Resume bit
 * to zero. The host controller ignores a write of zero to this bit. If host software sets this bit
 * to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are
 * undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only.
 * In device mode this bit is a read only status bit.
 */

#define BP_USBC__PORTSC1UH1_SUSP      (7)
#define BM_USBC__PORTSC1UH1_SUSP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_SUSP(v)   ((((reg32_t) v) << 7) & BM_USBC__PORTSC1UH1_SUSP)
#else
#define BF_USBC__PORTSC1UH1_SUSP(v)   (((v) << 7) & BM_USBC__PORTSC1UH1_SUSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSP field to a new value.
#define BW_USBC__PORTSC1UH1_SUSP(v)   BF_CS1(USBC__PORTSC1UH1, SUSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PR[8:8] (RW)
 *
 * Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset.
 * 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence
 * as defined in the USB Specification Revision 2.0 is started. This bit will automatically change
 * to zero after the reset sequence is complete. This behavior is different from EHCI where the host
 * controller driver is required to set this bit to a zero after the reset duration is timed in the
 * driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also
 * indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UH1_PR      (8)
#define BM_USBC__PORTSC1UH1_PR      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PR(v)   ((((reg32_t) v) << 8) & BM_USBC__PORTSC1UH1_PR)
#else
#define BF_USBC__PORTSC1UH1_PR(v)   (((v) << 8) & BM_USBC__PORTSC1UH1_PR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PR field to a new value.
#define BW_USBC__PORTSC1UH1_PR(v)   BF_CS1(USBC__PORTSC1UH1, PR, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field HSP[9:9] (RW)
 *
 * High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the
 * port is in high-speed mode and if set to zero, the host/device connected to the port is not in a
 * high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
 */

#define BP_USBC__PORTSC1UH1_HSP      (9)
#define BM_USBC__PORTSC1UH1_HSP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_HSP(v)   ((((reg32_t) v) << 9) & BM_USBC__PORTSC1UH1_HSP)
#else
#define BF_USBC__PORTSC1UH1_HSP(v)   (((v) << 9) & BM_USBC__PORTSC1UH1_HSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSP field to a new value.
#define BW_USBC__PORTSC1UH1_HSP(v)   BF_CS1(USBC__PORTSC1UH1, HSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field LS[11:10] (RW)
 *
 * Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D-
 * (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not
 * necessary (unlike EHCI), because the port controller state machine and the port routing manage
 * the connection of LS and FS. In device mode, the use of linestate by the device controller driver
 * is not necessary. The encoding of the bits are: Bits [11:10] Meaning
 *
 * Values:
 * 00 - SE0
 * 01 - K-state
 * 10 - J-state
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH1_LS      (10)
#define BM_USBC__PORTSC1UH1_LS      (0x00000c00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_LS(v)   ((((reg32_t) v) << 10) & BM_USBC__PORTSC1UH1_LS)
#else
#define BF_USBC__PORTSC1UH1_LS(v)   (((v) << 10) & BM_USBC__PORTSC1UH1_LS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LS field to a new value.
#define BW_USBC__PORTSC1UH1_LS(v)   BF_CS1(USBC__PORTSC1UH1, LS, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field PP[12:12] (RW)
 *
 * Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the
 * Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP
 * Operation 0 1b Read Only - Host controller does not have port power control switches. Each port
 * is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control
 * switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not
 * available on a port (that is, PP equals a 0), the port is non-functional and will not report
 * attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is
 * a one, the PP bit in each affected port may be transitional by the host controller driver from a
 * one to a zero (removing power from the port). This feature is implemented in all 4 controller
 * cores (PPC = 1).
 */

#define BP_USBC__PORTSC1UH1_PP      (12)
#define BM_USBC__PORTSC1UH1_PP      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PP(v)   ((((reg32_t) v) << 12) & BM_USBC__PORTSC1UH1_PP)
#else
#define BF_USBC__PORTSC1UH1_PP(v)   (((v) << 12) & BM_USBC__PORTSC1UH1_PP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PP field to a new value.
#define BW_USBC__PORTSC1UH1_PP(v)   BF_CS1(USBC__PORTSC1UH1, PP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PO[13:13] (RW)
 *
 * Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit
 * in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever
 * the Configured bit is zero System software uses this field to release ownership of the port to a
 * selected host controller (in the event that the attached device is not a high-speed device).
 * Software writes a one to this bit when the attached device is not a high-speed device. A one in
 * this bit means that an internal companion controller owns and controls the port. Port owner
 * handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
 */

#define BP_USBC__PORTSC1UH1_PO      (13)
#define BM_USBC__PORTSC1UH1_PO      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PO(v)   ((((reg32_t) v) << 13) & BM_USBC__PORTSC1UH1_PO)
#else
#define BF_USBC__PORTSC1UH1_PO(v)   (((v) << 13) & BM_USBC__PORTSC1UH1_PO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PO field to a new value.
#define BW_USBC__PORTSC1UH1_PO(v)   BF_CS1(USBC__PORTSC1UH1, PO, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PIC[15:14] (RW)
 *
 * Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the
 * P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0
 * for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit
 * Value Meaning
 *
 * Values:
 * 00 - Port indicators are off
 * 01 - Amber
 * 10 - Green
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH1_PIC      (14)
#define BM_USBC__PORTSC1UH1_PIC      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PIC(v)   ((((reg32_t) v) << 14) & BM_USBC__PORTSC1UH1_PIC)
#else
#define BF_USBC__PORTSC1UH1_PIC(v)   (((v) << 14) & BM_USBC__PORTSC1UH1_PIC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIC field to a new value.
#define BW_USBC__PORTSC1UH1_PIC(v)   BF_CS1(USBC__PORTSC1UH1, PIC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field PTC[19:16] (RW)
 *
 * Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model
 * for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each
 * test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support
 * specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS}
 * values will force the port into the connected and enabled state at the selected speed. Writing
 * the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally
 * from that point. Low speed operations are not supported as a peripheral device. Any other value
 * than zero indicates that the port is operating in test mode. Value Specific Test
 *
 * Values:
 * 0000 - TEST_MODE_DISABLE
 * 0001 - J_STATE
 * 0010 - K_STATE
 * 0011 - SE0 (host) / NAK (device)
 * 0100 - Packet
 * 0101 - FORCE_ENABLE_HS
 * 0110 - FORCE_ENABLE_FS
 * 0111 - FORCE_ENABLE_LS
 * 1000-1111 - Reserved
 */

#define BP_USBC__PORTSC1UH1_PTC      (16)
#define BM_USBC__PORTSC1UH1_PTC      (0x000f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PTC(v)   ((((reg32_t) v) << 16) & BM_USBC__PORTSC1UH1_PTC)
#else
#define BF_USBC__PORTSC1UH1_PTC(v)   (((v) << 16) & BM_USBC__PORTSC1UH1_PTC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTC field to a new value.
#define BW_USBC__PORTSC1UH1_PTC(v)   BF_CS1(USBC__PORTSC1UH1, PTC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field WKCN[20:20] (RW)
 *
 * Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the
 * port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is
 * zero or in device mode.
 */

#define BP_USBC__PORTSC1UH1_WKCN      (20)
#define BM_USBC__PORTSC1UH1_WKCN      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_WKCN(v)   ((((reg32_t) v) << 20) & BM_USBC__PORTSC1UH1_WKCN)
#else
#define BF_USBC__PORTSC1UH1_WKCN(v)   (((v) << 20) & BM_USBC__PORTSC1UH1_WKCN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKCN field to a new value.
#define BW_USBC__PORTSC1UH1_WKCN(v)   BF_CS1(USBC__PORTSC1UH1, WKCN, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field WKDC[21:21] (RW)
 *
 * Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one
 * enables the port to be sensitive to device disconnects as wake-up events. This field is zero if
 * Port Power( ) is zero or in device mode.
 */

#define BP_USBC__PORTSC1UH1_WKDC      (21)
#define BM_USBC__PORTSC1UH1_WKDC      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_WKDC(v)   ((((reg32_t) v) << 21) & BM_USBC__PORTSC1UH1_WKDC)
#else
#define BF_USBC__PORTSC1UH1_WKDC(v)   (((v) << 21) & BM_USBC__PORTSC1UH1_WKDC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKDC field to a new value.
#define BW_USBC__PORTSC1UH1_WKDC(v)   BF_CS1(USBC__PORTSC1UH1, WKDC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field WKOC[22:22] (RW)
 *
 * Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one
 * enables the port to be sensitive to over-current conditions as wake-up events. This field is zero
 * if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UH1_WKOC      (22)
#define BM_USBC__PORTSC1UH1_WKOC      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_WKOC(v)   ((((reg32_t) v) << 22) & BM_USBC__PORTSC1UH1_WKOC)
#else
#define BF_USBC__PORTSC1UH1_WKOC(v)   (((v) << 22) & BM_USBC__PORTSC1UH1_WKOC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKOC field to a new value.
#define BW_USBC__PORTSC1UH1_WKOC(v)   BF_CS1(USBC__PORTSC1UH1, WKOC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PHCD[23:23] (RW)
 *
 * PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set
 * to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock.
 * The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY
 * can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host
 * has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically
 * when the host initials resume. Before forcing a resume from the device, the device controller
 * driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the
 * downstream device has been put into suspend mode or when no downstream device is connected. Low
 * power suspend is completely under the control of software.
 *
 * Values:
 * 0 - Enable PHY clock
 * 1 - Disable PHY clock
 */

#define BP_USBC__PORTSC1UH1_PHCD      (23)
#define BM_USBC__PORTSC1UH1_PHCD      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PHCD(v)   ((((reg32_t) v) << 23) & BM_USBC__PORTSC1UH1_PHCD)
#else
#define BF_USBC__PORTSC1UH1_PHCD(v)   (((v) << 23) & BM_USBC__PORTSC1UH1_PHCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHCD field to a new value.
#define BW_USBC__PORTSC1UH1_PHCD(v)   BF_CS1(USBC__PORTSC1UH1, PHCD, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field PFSC[24:24] (RW)
 *
 * Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port
 * will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port
 * to identify itself as High Speed.
 *
 * Values:
 * 0 - Normal operation
 * 1 - Forced to full speed
 */

#define BP_USBC__PORTSC1UH1_PFSC      (24)
#define BM_USBC__PORTSC1UH1_PFSC      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PFSC(v)   ((((reg32_t) v) << 24) & BM_USBC__PORTSC1UH1_PFSC)
#else
#define BF_USBC__PORTSC1UH1_PFSC(v)   (((v) << 24) & BM_USBC__PORTSC1UH1_PFSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFSC field to a new value.
#define BW_USBC__PORTSC1UH1_PFSC(v)   BF_CS1(USBC__PORTSC1UH1, PFSC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field PTS[25:25] (RW)
 *
 * See description at bits 31-30
 */

#define BP_USBC__PORTSC1UH1_PTS      (25)
#define BM_USBC__PORTSC1UH1_PTS      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PTS(v)   ((((reg32_t) v) << 25) & BM_USBC__PORTSC1UH1_PTS)
#else
#define BF_USBC__PORTSC1UH1_PTS(v)   (((v) << 25) & BM_USBC__PORTSC1UH1_PTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS field to a new value.
#define BW_USBC__PORTSC1UH1_PTS(v)   BF_CS1(USBC__PORTSC1UH1, PTS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PSPD[27:26] (RW)
 *
 * Port Speed - Read Only. This register field indicates the speed at which the port is operating.
 * For HS mode operation in the host controller and HS/FS operation in the device controller the
 * port routing steers data to the Protocol engine. For FS and LS mode operation in the host
 * controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction
 * Translator.
 *
 * Values:
 * 00 - Full Speed
 * 01 - Low Speed
 * 10 - High Speed
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH1_PSPD      (26)
#define BM_USBC__PORTSC1UH1_PSPD      (0x0c000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PSPD(v)   ((((reg32_t) v) << 26) & BM_USBC__PORTSC1UH1_PSPD)
#else
#define BF_USBC__PORTSC1UH1_PSPD(v)   (((v) << 26) & BM_USBC__PORTSC1UH1_PSPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSPD field to a new value.
#define BW_USBC__PORTSC1UH1_PSPD(v)   BF_CS1(USBC__PORTSC1UH1, PSPD, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field PTW[28:28] (RW)
 *
 * Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI
 * transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16
 * selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0
 * selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI
 * interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined
 * in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0;
 * For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver
 * Width This bit has no effect if serial interface engine is used. These register bits are
 * implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For
 * Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For
 * OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3
 * core, it is Read-Only. Reset value is '1b'.
 *
 * Values:
 * 1 - Select the 8-bit UTMI interface [60MHz]
 * 2 - Select the 16-bit UTMI interface [30MHz]
 */

#define BP_USBC__PORTSC1UH1_PTW      (28)
#define BM_USBC__PORTSC1UH1_PTW      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PTW(v)   ((((reg32_t) v) << 28) & BM_USBC__PORTSC1UH1_PTW)
#else
#define BF_USBC__PORTSC1UH1_PTW(v)   (((v) << 28) & BM_USBC__PORTSC1UH1_PTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTW field to a new value.
#define BW_USBC__PORTSC1UH1_PTW(v)   BF_CS1(USBC__PORTSC1UH1, PTW, v)
#endif


/* --- Register HW_USBC__PORTSC1UH1, field STS[29:29] (RW)
 *
 * Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver
 * interface is selected for FS and LS operation. The Serial Interface Engine can be used in
 * combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the
 * parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel
 * Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial
 * Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for
 * future operation and is a placeholder adding dynamic use of the serial engine in accord with
 * UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification
 * VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita,
 * OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select -
 * Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals
 * is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface
 * to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b',
 * serial interface engine will be used instead of parallel interface signals. This bit has no
 * effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will
 * use the serial interface engine for FS/LS signaling regardless of this bit value. Serial
 * Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0
 * Parallel Interface signals is selected Serial Interface Engine can be used in combination with
 * UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface
 * signals. When this bit is set '1b', serial interface engine will be used instead of parallel
 * interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface.
 * The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless
 * of this bit value.
 */

#define BP_USBC__PORTSC1UH1_STS      (29)
#define BM_USBC__PORTSC1UH1_STS      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_STS(v)   ((((reg32_t) v) << 29) & BM_USBC__PORTSC1UH1_STS)
#else
#define BF_USBC__PORTSC1UH1_STS(v)   (((v) << 29) & BM_USBC__PORTSC1UH1_STS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STS field to a new value.
#define BW_USBC__PORTSC1UH1_STS(v)   BF_CS1(USBC__PORTSC1UH1, STS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH1, field PTS1[31:30] (RW)
 *
 * Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the
 * configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is
 * selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If
 * VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30,
 * bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE =
 * 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 -
 * Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is
 * not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7;
 * For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver
 * Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3
 * core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b"
 * Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25,
 * bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only.
 * Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field
 * {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY
 * /IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register
 * bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For
 * Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}:
 * "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b"
 * HSIC All USB port interface modes are listed in this field description, but not all are
 * supported. For detail feature of each controller core, please see . The behaviour is unknown when
 * unsupported interface mode is selected.
 */

#define BP_USBC__PORTSC1UH1_PTS1      (30)
#define BM_USBC__PORTSC1UH1_PTS1      (0xc0000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH1_PTS1(v)   ((((reg32_t) v) << 30) & BM_USBC__PORTSC1UH1_PTS1)
#else
#define BF_USBC__PORTSC1UH1_PTS1(v)   (((v) << 30) & BM_USBC__PORTSC1UH1_PTS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS1 field to a new value.
#define BW_USBC__PORTSC1UH1_PTS1(v)   BF_CS1(USBC__PORTSC1UH1, PTS1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBMODEUH1 - USB Device Mode UH1 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CM : 2; //!< Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device only implementations. For those designs that contain both host & device capability, the controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. For combination host/device controllers, this register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core, reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
        unsigned ES : 1; //!< Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to match the host microprocessor. The bit fields in the microprocessor interface and the data structures are unaffected by the value of this bit because they are based upon the 32-bit word. Bit Meaning
        unsigned SLOM : 1; //!< Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
        unsigned SDIS : 1; //!< Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX and TX buffers are sufficient to contain an entire packet that the standard double buffering scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets received are responded to with a NYET handshake when stream disable is active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to characterize the adjustments needed for the scheduler when using this feature. The use of this feature substantially limits of the overall USB performance that can be achieved.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_usbc__usbmodeuh1_t;
#endif

/*
 * constants & macros for entire USBC__USBMODEUH1 register
 */
#define HW_USBC__USBMODEUH1_ADDR      (REGS_USBC_BASE + 0x3a8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBMODEUH1           (*(volatile hw_usbc__usbmodeuh1_t *) HW_USBC__USBMODEUH1_ADDR)
#define HW_USBC__USBMODEUH1_RD()      (HW_USBC__USBMODEUH1.U)
#define HW_USBC__USBMODEUH1_WR(v)     (HW_USBC__USBMODEUH1.U = (v))
#define HW_USBC__USBMODEUH1_SET(v)    (HW_USBC__USBMODEUH1_WR(HW_USBC__USBMODEUH1_RD() |  (v)))
#define HW_USBC__USBMODEUH1_CLR(v)    (HW_USBC__USBMODEUH1_WR(HW_USBC__USBMODEUH1_RD() & ~(v)))
#define HW_USBC__USBMODEUH1_TOG(v)    (HW_USBC__USBMODEUH1_WR(HW_USBC__USBMODEUH1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBMODEUH1 bitfields
 */

/* --- Register HW_USBC__USBMODEUH1, field CM[1:0] (RW)
 *
 * Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device
 * only implementations. For those designs that contain both host & device capability, the
 * controller defaults to an idle state and needs to be initialized to the desired operating mode
 * after reset. For combination host/device controllers, this register can only be written once
 * after reset. If it is necessary to switch modes, software must reset the controller by writing to
 * the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core,
 * reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
 *
 * Values:
 * 00 - Idle [Default for combination host/device]
 * 01 - Reserved
 * 10 - Device Controller [Default for device only controller]
 * 11 - Host Controller [Default for host only controller]
 */

#define BP_USBC__USBMODEUH1_CM      (0)
#define BM_USBC__USBMODEUH1_CM      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH1_CM(v)   ((((reg32_t) v) << 0) & BM_USBC__USBMODEUH1_CM)
#else
#define BF_USBC__USBMODEUH1_CM(v)   (((v) << 0) & BM_USBC__USBMODEUH1_CM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CM field to a new value.
#define BW_USBC__USBMODEUH1_CM(v)   BF_CS1(USBC__USBMODEUH1, CM, v)
#endif


/* --- Register HW_USBC__USBMODEUH1, field ES[2:2] (RW)
 *
 * Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to
 * match the host microprocessor. The bit fields in the microprocessor interface and the data
 * structures are unaffected by the value of this bit because they are based upon the 32-bit word.
 * Bit Meaning
 *
 * Values:
 * 0 - Little Endian [Default]
 * 1 - Big Endian
 */

#define BP_USBC__USBMODEUH1_ES      (2)
#define BM_USBC__USBMODEUH1_ES      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH1_ES(v)   ((((reg32_t) v) << 2) & BM_USBC__USBMODEUH1_ES)
#else
#define BF_USBC__USBMODEUH1_ES(v)   (((v) << 2) & BM_USBC__USBMODEUH1_ES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ES field to a new value.
#define BW_USBC__USBMODEUH1_ES(v)   BF_CS1(USBC__USBMODEUH1, ES, v)
#endif


/* --- Register HW_USBC__USBMODEUH1, field SLOM[3:3] (RW)
 *
 * Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
 *
 * Values:
 * 0 - Setup Lockouts On (default);
 * 1 - Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in .
 */

#define BP_USBC__USBMODEUH1_SLOM      (3)
#define BM_USBC__USBMODEUH1_SLOM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH1_SLOM(v)   ((((reg32_t) v) << 3) & BM_USBC__USBMODEUH1_SLOM)
#else
#define BF_USBC__USBMODEUH1_SLOM(v)   (((v) << 3) & BM_USBC__USBMODEUH1_SLOM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLOM field to a new value.
#define BW_USBC__USBMODEUH1_SLOM(v)   BF_CS1(USBC__USBMODEUH1, SLOM, v)
#endif


/* --- Register HW_USBC__USBMODEUH1, field SDIS[4:4] (RW)
 *
 * Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables
 * double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX
 * and TX buffers are sufficient to contain an entire packet that the standard double buffering
 * scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High
 * Speed Mode, all packets received are responded to with a NYET handshake when stream disable is
 * active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are
 * eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the
 * entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled
 * to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO
 * becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to
 * characterize the adjustments needed for the scheduler when using this feature. The use of this
 * feature substantially limits of the overall USB performance that can be achieved.
 */

#define BP_USBC__USBMODEUH1_SDIS      (4)
#define BM_USBC__USBMODEUH1_SDIS      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH1_SDIS(v)   ((((reg32_t) v) << 4) & BM_USBC__USBMODEUH1_SDIS)
#else
#define BF_USBC__USBMODEUH1_SDIS(v)   (((v) << 4) & BM_USBC__USBMODEUH1_SDIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SDIS field to a new value.
#define BW_USBC__USBMODEUH1_SDIS(v)   BF_CS1(USBC__USBMODEUH1, SDIS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IDUH2 - Identification register UH2 (RO)
 *
 * The ID register identifies the USB 2.0 OTG High-Speed core and its revision.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ID : 6; //!< Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG High-Speed core.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned NID : 6; //!< Complement version of ID
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned REVISION : 8; //!< Revision number of the controller core.
        unsigned RESERVED2 : 8; //!< Reserved
    } B;
} hw_usbc__iduh2_t;
#endif

/*
 * constants & macros for entire USBC__IDUH2 register
 */
#define HW_USBC__IDUH2_ADDR      (REGS_USBC_BASE + 0x400)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IDUH2           (*(volatile hw_usbc__iduh2_t *) HW_USBC__IDUH2_ADDR)
#define HW_USBC__IDUH2_RD()      (HW_USBC__IDUH2.U)
#endif

/*
 * constants & macros for individual USBC__IDUH2 bitfields
 */

/* --- Register HW_USBC__IDUH2, field ID[5:0] (RO)
 *
 * Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG
 * High-Speed core.
 */

#define BP_USBC__IDUH2_ID      (0)
#define BM_USBC__IDUH2_ID      (0x0000003f)

/* --- Register HW_USBC__IDUH2, field NID[13:8] (RO)
 *
 * Complement version of ID
 */

#define BP_USBC__IDUH2_NID      (8)
#define BM_USBC__IDUH2_NID      (0x00003f00)

/* --- Register HW_USBC__IDUH2, field REVISION[23:16] (RO)
 *
 * Revision number of the controller core.
 */

#define BP_USBC__IDUH2_REVISION      (16)
#define BM_USBC__IDUH2_REVISION      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWGENERALUH2 - Hardware General UH2 (RO)
 *
 * General hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned PHYW : 2; //!< Data width of the transciever connected to the controller core. For OTG controller core reset value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller core, reset value is '01b'.
        unsigned PHYM : 3; //!< Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '4h'.
        unsigned SM : 2; //!< Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '00b'.
        unsigned RESERVED1 : 21; //!< Reserved
    } B;
} hw_usbc__hwgeneraluh2_t;
#endif

/*
 * constants & macros for entire USBC__HWGENERALUH2 register
 */
#define HW_USBC__HWGENERALUH2_ADDR      (REGS_USBC_BASE + 0x404)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWGENERALUH2           (*(volatile hw_usbc__hwgeneraluh2_t *) HW_USBC__HWGENERALUH2_ADDR)
#define HW_USBC__HWGENERALUH2_RD()      (HW_USBC__HWGENERALUH2.U)
#endif

/*
 * constants & macros for individual USBC__HWGENERALUH2 bitfields
 */

/* --- Register HW_USBC__HWGENERALUH2, field PHYW[5:4] (RO)
 *
 * Data width of the transciever connected to the controller core. For OTG controller core reset
 * value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For
 * OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller
 * core, reset value is '01b'.
 *
 * Values:
 * 00 - 8 bit wide data bus [60MHz clock from the transciever]
 * 01 - 16 bit wide data bus [30MHZ clock from the transciever]
 * 10 - software programmable reset to 8-bit width
 * 11 - software programmable reset to 16-bit width
 */

#define BP_USBC__HWGENERALUH2_PHYW      (4)
#define BM_USBC__HWGENERALUH2_PHYW      (0x00000030)


/* --- Register HW_USBC__HWGENERALUH2, field PHYM[8:6] (RO)
 *
 * Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG
 * controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'.
 * For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value
 * is '4h'.
 *
 * Values:
 * 000 - UTMI/UMTI+
 * 001 - ULPI DDR
 * 010 - ULPI
 * 011 - Serial Only
 * 100 - Software programmable - reset to UTMI/UTMI+
 * 101 - Software programmable - reset to ULPI DDR
 * 110 - Software programmable - reset to ULPI
 * 111 - Software programmable - reset to Serial
 * 1000 - IC-USB
 * 1001 - Software programmable - reset to IC-USB
 * 1010 - HSIC
 * 1011 - Software programmable - reset to HSIC
 */

#define BP_USBC__HWGENERALUH2_PHYM      (6)
#define BM_USBC__HWGENERALUH2_PHYM      (0x000001c0)


/* --- Register HW_USBC__HWGENERALUH2, field SM[10:9] (RO)
 *
 * Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.
 * For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3
 * controller core, reset value is '00b'.
 *
 * Values:
 * 00 - No Serial Engine, always use parallel signalling.
 * 01 - Serial Engine present, always use serial signalling for FS/LS.
 * 10 - Software programmable - Reset to use parallel signalling for FS/LS
 * 11 - Software programmable - Reset to use serial signalling for FS/LS
 */

#define BP_USBC__HWGENERALUH2_SM      (9)
#define BM_USBC__HWGENERALUH2_SM      (0x00000600)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWHOSTUH2 - Host Hardware Parameters UH2 (RO)
 *
 * Host hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HC : 1; //!< Host Capable. All 4 controller cores support host operation mode.
        unsigned NPORT : 3; //!< The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller cores are single port, these bits are set to '000b'.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__hwhostuh2_t;
#endif

/*
 * constants & macros for entire USBC__HWHOSTUH2 register
 */
#define HW_USBC__HWHOSTUH2_ADDR      (REGS_USBC_BASE + 0x408)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWHOSTUH2           (*(volatile hw_usbc__hwhostuh2_t *) HW_USBC__HWHOSTUH2_ADDR)
#define HW_USBC__HWHOSTUH2_RD()      (HW_USBC__HWHOSTUH2.U)
#endif

/*
 * constants & macros for individual USBC__HWHOSTUH2 bitfields
 */

/* --- Register HW_USBC__HWHOSTUH2, field HC[0:0] (RO)
 *
 * Host Capable. All 4 controller cores support host operation mode.
 *
 * Values:
 * 0 - not support
 * 1 - support host operation mode
 */

#define BP_USBC__HWHOSTUH2_HC      (0)
#define BM_USBC__HWHOSTUH2_HC      (0x00000001)


/* --- Register HW_USBC__HWHOSTUH2, field NPORT[3:1] (RO)
 *
 * The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller
 * cores are single port, these bits are set to '000b'.
 */

#define BP_USBC__HWHOSTUH2_NPORT      (1)
#define BM_USBC__HWHOSTUH2_NPORT      (0x0000000e)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWTXBUFUH2 - TX Buffer Hardware Parameters UH2 (RO)
 *
 * TX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXBURST : 8; //!< Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned TXCHANADD : 8; //!< TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc__hwtxbufuh2_t;
#endif

/*
 * constants & macros for entire USBC__HWTXBUFUH2 register
 */
#define HW_USBC__HWTXBUFUH2_ADDR      (REGS_USBC_BASE + 0x410)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWTXBUFUH2           (*(volatile hw_usbc__hwtxbufuh2_t *) HW_USBC__HWTXBUFUH2_ADDR)
#define HW_USBC__HWTXBUFUH2_RD()      (HW_USBC__HWTXBUFUH2.U)
#endif

/*
 * constants & macros for individual USBC__HWTXBUFUH2 bitfields
 */

/* --- Register HW_USBC__HWTXBUFUH2, field TXBURST[7:0] (RO)
 *
 * Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWTXBUFUH2_TXBURST      (0)
#define BM_USBC__HWTXBUFUH2_TXBURST      (0x000000ff)

/* --- Register HW_USBC__HWTXBUFUH2, field TXCHANADD[23:16] (RO)
 *
 * TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4
 * Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX
 * Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
 */

#define BP_USBC__HWTXBUFUH2_TXCHANADD      (16)
#define BM_USBC__HWTXBUFUH2_TXCHANADD      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWRXBUFUH2 - RX Buffer Hardware Parameters UH2 (RO)
 *
 * RX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXBURST : 8; //!< Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RXADD : 8; //!< Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX Buffer.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usbc__hwrxbufuh2_t;
#endif

/*
 * constants & macros for entire USBC__HWRXBUFUH2 register
 */
#define HW_USBC__HWRXBUFUH2_ADDR      (REGS_USBC_BASE + 0x414)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWRXBUFUH2           (*(volatile hw_usbc__hwrxbufuh2_t *) HW_USBC__HWRXBUFUH2_ADDR)
#define HW_USBC__HWRXBUFUH2_RD()      (HW_USBC__HWRXBUFUH2.U)
#endif

/*
 * constants & macros for individual USBC__HWRXBUFUH2 bitfields
 */

/* --- Register HW_USBC__HWRXBUFUH2, field RXBURST[7:0] (RO)
 *
 * Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWRXBUFUH2_RXBURST      (0)
#define BM_USBC__HWRXBUFUH2_RXBURST      (0x000000ff)

/* --- Register HW_USBC__HWRXBUFUH2, field RXADD[15:8] (RO)
 *
 * Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes.
 * These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one
 * RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX
 * Buffer.
 */

#define BP_USBC__HWRXBUFUH2_RXADD      (8)
#define BM_USBC__HWRXBUFUH2_RXADD      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0LDUH2 - General Purpose Timer #0 Load UH2 (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER0CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer0lduh2_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0LDUH2 register
 */
#define HW_USBC__GPTIMER0LDUH2_ADDR      (REGS_USBC_BASE + 0x480)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0LDUH2           (*(volatile hw_usbc__gptimer0lduh2_t *) HW_USBC__GPTIMER0LDUH2_ADDR)
#define HW_USBC__GPTIMER0LDUH2_RD()      (HW_USBC__GPTIMER0LDUH2.U)
#define HW_USBC__GPTIMER0LDUH2_WR(v)     (HW_USBC__GPTIMER0LDUH2.U = (v))
#define HW_USBC__GPTIMER0LDUH2_SET(v)    (HW_USBC__GPTIMER0LDUH2_WR(HW_USBC__GPTIMER0LDUH2_RD() |  (v)))
#define HW_USBC__GPTIMER0LDUH2_CLR(v)    (HW_USBC__GPTIMER0LDUH2_WR(HW_USBC__GPTIMER0LDUH2_RD() & ~(v)))
#define HW_USBC__GPTIMER0LDUH2_TOG(v)    (HW_USBC__GPTIMER0LDUH2_WR(HW_USBC__GPTIMER0LDUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0LDUH2 bitfields
 */

/* --- Register HW_USBC__GPTIMER0LDUH2, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER0LDUH2_GPTLD      (0)
#define BM_USBC__GPTIMER0LDUH2_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0LDUH2_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0LDUH2_GPTLD)
#else
#define BF_USBC__GPTIMER0LDUH2_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER0LDUH2_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER0LDUH2_GPTLD(v)   BF_CS1(USBC__GPTIMER0LDUH2, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0CTRLUH2 - General Purpose Timer #0 Controller UH2 (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI0 bit in n_USBSTS register (See ), interrupt enable bit is
 * TIE0 bit in n_USBINTR register. (See .)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer0ctrluh2_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0CTRLUH2 register
 */
#define HW_USBC__GPTIMER0CTRLUH2_ADDR      (REGS_USBC_BASE + 0x484)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0CTRLUH2           (*(volatile hw_usbc__gptimer0ctrluh2_t *) HW_USBC__GPTIMER0CTRLUH2_ADDR)
#define HW_USBC__GPTIMER0CTRLUH2_RD()      (HW_USBC__GPTIMER0CTRLUH2.U)
#define HW_USBC__GPTIMER0CTRLUH2_WR(v)     (HW_USBC__GPTIMER0CTRLUH2.U = (v))
#define HW_USBC__GPTIMER0CTRLUH2_SET(v)    (HW_USBC__GPTIMER0CTRLUH2_WR(HW_USBC__GPTIMER0CTRLUH2_RD() |  (v)))
#define HW_USBC__GPTIMER0CTRLUH2_CLR(v)    (HW_USBC__GPTIMER0CTRLUH2_WR(HW_USBC__GPTIMER0CTRLUH2_RD() & ~(v)))
#define HW_USBC__GPTIMER0CTRLUH2_TOG(v)    (HW_USBC__GPTIMER0CTRLUH2_WR(HW_USBC__GPTIMER0CTRLUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0CTRLUH2 bitfields
 */

/* --- Register HW_USBC__GPTIMER0CTRLUH2, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER0CTRLUH2_GPTCNT      (0)
#define BM_USBC__GPTIMER0CTRLUH2_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH2_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0CTRLUH2_GPTCNT)
#else
#define BF_USBC__GPTIMER0CTRLUH2_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER0CTRLUH2_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER0CTRLUH2_GPTCNT(v)   BF_CS1(USBC__GPTIMER0CTRLUH2, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRLUH2, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER0CTRLUH2_GPTMODE      (24)
#define BM_USBC__GPTIMER0CTRLUH2_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH2_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER0CTRLUH2_GPTMODE)
#else
#define BF_USBC__GPTIMER0CTRLUH2_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER0CTRLUH2_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER0CTRLUH2_GPTMODE(v)   BF_CS1(USBC__GPTIMER0CTRLUH2, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUH2, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in n_GPTIMER0LD
 */

#define BP_USBC__GPTIMER0CTRLUH2_GPTRST      (30)
#define BM_USBC__GPTIMER0CTRLUH2_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH2_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER0CTRLUH2_GPTRST)
#else
#define BF_USBC__GPTIMER0CTRLUH2_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER0CTRLUH2_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER0CTRLUH2_GPTRST(v)   BF_CS1(USBC__GPTIMER0CTRLUH2, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUH2, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER0CTRLUH2_GPTRUN      (31)
#define BM_USBC__GPTIMER0CTRLUH2_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH2_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER0CTRLUH2_GPTRUN)
#else
#define BF_USBC__GPTIMER0CTRLUH2_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER0CTRLUH2_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER0CTRLUH2_GPTRUN(v)   BF_CS1(USBC__GPTIMER0CTRLUH2, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1LDUH2 - General Purpose Timer #1 Load UH2 (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER1CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer1lduh2_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1LDUH2 register
 */
#define HW_USBC__GPTIMER1LDUH2_ADDR      (REGS_USBC_BASE + 0x488)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1LDUH2           (*(volatile hw_usbc__gptimer1lduh2_t *) HW_USBC__GPTIMER1LDUH2_ADDR)
#define HW_USBC__GPTIMER1LDUH2_RD()      (HW_USBC__GPTIMER1LDUH2.U)
#define HW_USBC__GPTIMER1LDUH2_WR(v)     (HW_USBC__GPTIMER1LDUH2.U = (v))
#define HW_USBC__GPTIMER1LDUH2_SET(v)    (HW_USBC__GPTIMER1LDUH2_WR(HW_USBC__GPTIMER1LDUH2_RD() |  (v)))
#define HW_USBC__GPTIMER1LDUH2_CLR(v)    (HW_USBC__GPTIMER1LDUH2_WR(HW_USBC__GPTIMER1LDUH2_RD() & ~(v)))
#define HW_USBC__GPTIMER1LDUH2_TOG(v)    (HW_USBC__GPTIMER1LDUH2_WR(HW_USBC__GPTIMER1LDUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1LDUH2 bitfields
 */

/* --- Register HW_USBC__GPTIMER1LDUH2, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER1LDUH2_GPTLD      (0)
#define BM_USBC__GPTIMER1LDUH2_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1LDUH2_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1LDUH2_GPTLD)
#else
#define BF_USBC__GPTIMER1LDUH2_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER1LDUH2_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER1LDUH2_GPTLD(v)   BF_CS1(USBC__GPTIMER1LDUH2, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1CTRLUH2 - General Purpose Timer #1 Controller UH2 (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI1 bit in UOG_USBSTS register (See ), interrupt enable bit is
 * TIE1 bit in n_USBINTR register (See ).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer1ctrluh2_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1CTRLUH2 register
 */
#define HW_USBC__GPTIMER1CTRLUH2_ADDR      (REGS_USBC_BASE + 0x48c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1CTRLUH2           (*(volatile hw_usbc__gptimer1ctrluh2_t *) HW_USBC__GPTIMER1CTRLUH2_ADDR)
#define HW_USBC__GPTIMER1CTRLUH2_RD()      (HW_USBC__GPTIMER1CTRLUH2.U)
#define HW_USBC__GPTIMER1CTRLUH2_WR(v)     (HW_USBC__GPTIMER1CTRLUH2.U = (v))
#define HW_USBC__GPTIMER1CTRLUH2_SET(v)    (HW_USBC__GPTIMER1CTRLUH2_WR(HW_USBC__GPTIMER1CTRLUH2_RD() |  (v)))
#define HW_USBC__GPTIMER1CTRLUH2_CLR(v)    (HW_USBC__GPTIMER1CTRLUH2_WR(HW_USBC__GPTIMER1CTRLUH2_RD() & ~(v)))
#define HW_USBC__GPTIMER1CTRLUH2_TOG(v)    (HW_USBC__GPTIMER1CTRLUH2_WR(HW_USBC__GPTIMER1CTRLUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1CTRLUH2 bitfields
 */

/* --- Register HW_USBC__GPTIMER1CTRLUH2, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER1CTRLUH2_GPTCNT      (0)
#define BM_USBC__GPTIMER1CTRLUH2_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH2_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1CTRLUH2_GPTCNT)
#else
#define BF_USBC__GPTIMER1CTRLUH2_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER1CTRLUH2_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER1CTRLUH2_GPTCNT(v)   BF_CS1(USBC__GPTIMER1CTRLUH2, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRLUH2, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER1CTRLUH2_GPTMODE      (24)
#define BM_USBC__GPTIMER1CTRLUH2_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH2_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER1CTRLUH2_GPTMODE)
#else
#define BF_USBC__GPTIMER1CTRLUH2_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER1CTRLUH2_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER1CTRLUH2_GPTMODE(v)   BF_CS1(USBC__GPTIMER1CTRLUH2, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUH2, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in UOG_GPTIMER0LD
 */

#define BP_USBC__GPTIMER1CTRLUH2_GPTRST      (30)
#define BM_USBC__GPTIMER1CTRLUH2_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH2_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER1CTRLUH2_GPTRST)
#else
#define BF_USBC__GPTIMER1CTRLUH2_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER1CTRLUH2_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER1CTRLUH2_GPTRST(v)   BF_CS1(USBC__GPTIMER1CTRLUH2, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUH2, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER1CTRLUH2_GPTRUN      (31)
#define BM_USBC__GPTIMER1CTRLUH2_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH2_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER1CTRLUH2_GPTRUN)
#else
#define BF_USBC__GPTIMER1CTRLUH2_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER1CTRLUH2_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER1CTRLUH2_GPTRUN(v)   BF_CS1(USBC__GPTIMER1CTRLUH2, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__SBUSCFGUH2 - System Bus Config UH2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned AHBBRST : 3; //!< AHB master interface Burst configuration These bits controls AHB master transfer type sequence (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_usbc__sbuscfguh2_t;
#endif

/*
 * constants & macros for entire USBC__SBUSCFGUH2 register
 */
#define HW_USBC__SBUSCFGUH2_ADDR      (REGS_USBC_BASE + 0x490)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__SBUSCFGUH2           (*(volatile hw_usbc__sbuscfguh2_t *) HW_USBC__SBUSCFGUH2_ADDR)
#define HW_USBC__SBUSCFGUH2_RD()      (HW_USBC__SBUSCFGUH2.U)
#define HW_USBC__SBUSCFGUH2_WR(v)     (HW_USBC__SBUSCFGUH2.U = (v))
#define HW_USBC__SBUSCFGUH2_SET(v)    (HW_USBC__SBUSCFGUH2_WR(HW_USBC__SBUSCFGUH2_RD() |  (v)))
#define HW_USBC__SBUSCFGUH2_CLR(v)    (HW_USBC__SBUSCFGUH2_WR(HW_USBC__SBUSCFGUH2_RD() & ~(v)))
#define HW_USBC__SBUSCFGUH2_TOG(v)    (HW_USBC__SBUSCFGUH2_WR(HW_USBC__SBUSCFGUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__SBUSCFGUH2 bitfields
 */

/* --- Register HW_USBC__SBUSCFGUH2, field AHBBRST[2:0] (RW)
 *
 * AHB master interface Burst configuration These bits controls AHB master transfer type sequence
 * (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
 *
 * Values:
 * 000 - Incremental burst of unspecified length only
 * 001 - INCR4 burst, then single transfer
 * 010 - INCR8 burst, INCR4 burst, then single transfer
 * 011 - INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 * 100 - Reserved, don't use
 * 101 - INCR4 burst, then incremental burst of unspecified length
 * 110 - INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 * 111 - INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */

#define BP_USBC__SBUSCFGUH2_AHBBRST      (0)
#define BM_USBC__SBUSCFGUH2_AHBBRST      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__SBUSCFGUH2_AHBBRST(v)   ((((reg32_t) v) << 0) & BM_USBC__SBUSCFGUH2_AHBBRST)
#else
#define BF_USBC__SBUSCFGUH2_AHBBRST(v)   (((v) << 0) & BM_USBC__SBUSCFGUH2_AHBBRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBBRST field to a new value.
#define BW_USBC__SBUSCFGUH2_AHBBRST(v)   BF_CS1(USBC__SBUSCFGUH2, AHBBRST, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__CAPLENGTHUH2 - Capability Register Length UH2 (RO)
 *
 * The following figure Capability Register Length (n_CAPLENGTH) indicates the offset that should be
 * added to the register base address at the beginning of the Operational Register.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CAPLENGTH : 8; //!< These bits are used as an offset to add to register base to find the beginning of the Operational Register. Default value is '40h'.
    } B;
} hw_usbc__caplengthuh2_t;
#endif

/*
 * constants & macros for entire USBC__CAPLENGTHUH2 register
 */
#define HW_USBC__CAPLENGTHUH2_ADDR      (REGS_USBC_BASE + 0x500)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__CAPLENGTHUH2           (*(volatile hw_usbc__caplengthuh2_t *) HW_USBC__CAPLENGTHUH2_ADDR)
#define HW_USBC__CAPLENGTHUH2_RD()      (HW_USBC__CAPLENGTHUH2.U)
#endif

/*
 * constants & macros for individual USBC__CAPLENGTHUH2 bitfields
 */

/* --- Register HW_USBC__CAPLENGTHUH2, field CAPLENGTH[7:0] (RO)
 *
 * These bits are used as an offset to add to register base to find the beginning of the Operational
 * Register. Default value is '40h'.
 */

#define BP_USBC__CAPLENGTHUH2_CAPLENGTH      (0)
#define BM_USBC__CAPLENGTHUH2_CAPLENGTH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCIVERSIONUH2 - Host Controller Interface Version UH2 (RO)
 *
 * The following figure shows the Host Interface version number (n_HCIVERSION), which is a 2-byte
 * register containing a BCD encoding of the EHCI revision number supported by this host controller.
 * The most significant byte of this register represents a major revision and the least significant
 * byte is the minor revision.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HCIVERSION : 16; //!< Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
    } B;
} hw_usbc__hciversionuh2_t;
#endif

/*
 * constants & macros for entire USBC__HCIVERSIONUH2 register
 */
#define HW_USBC__HCIVERSIONUH2_ADDR      (REGS_USBC_BASE + 0x502)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCIVERSIONUH2           (*(volatile hw_usbc__hciversionuh2_t *) HW_USBC__HCIVERSIONUH2_ADDR)
#define HW_USBC__HCIVERSIONUH2_RD()      (HW_USBC__HCIVERSIONUH2.U)
#endif

/*
 * constants & macros for individual USBC__HCIVERSIONUH2 bitfields
 */

/* --- Register HW_USBC__HCIVERSIONUH2, field HCIVERSION[15:0] (RO)
 *
 * Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
 */

#define BP_USBC__HCIVERSIONUH2_HCIVERSION      (0)
#define BM_USBC__HCIVERSIONUH2_HCIVERSION      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCSPARAMSUH2 - Host Controller Structural Parameters UH2 (RO)
 *
 * The following figure shows the port steering logic capabilities of Host Control Structural
 * Parameters (n_HCSPARAMS).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned N_PORTS : 4; //!< Number of downstream ports. This field specifies the number of physical downstream ports implemented on this host controller. The value of this field determines how many port registers are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in this field is undefined. These bits are always set to '0001b' because all 4 controller cores are Single-Port Host.
        unsigned PPC : 1; //!< Port Power Control This field indicates whether the host controller implementation includes port power control. A one indicates the ports have port power switches. A zero indicates the ports do not have port power switches. The value of this field affects the functionality of the Port Power field in each port status and control register
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned N_PCC : 4; //!< Number of Ports per Companion Controller This field indicates the number of ports supported per internal Companion Controller. It is used to indicate the port routing configuration to the system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and the last two are routed to companion controller 2. The number in this field must be consistent with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
        unsigned N_CC : 4; //!< Number of Companion Controller (N_CC). This field indicates the number of companion controllers associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
        unsigned PI : 1; //!< Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator control. When set to one, the port status and control registers include a read/writeable field for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned N_PTT : 4; //!< Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates the number of ports assigned to each transaction translator within the USB2.0 host controller. These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned N_TT : 4; //!< Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number of embedded transaction translators associated with the USB2.0 host controller. These bits would be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_usbc__hcsparamsuh2_t;
#endif

/*
 * constants & macros for entire USBC__HCSPARAMSUH2 register
 */
#define HW_USBC__HCSPARAMSUH2_ADDR      (REGS_USBC_BASE + 0x504)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCSPARAMSUH2           (*(volatile hw_usbc__hcsparamsuh2_t *) HW_USBC__HCSPARAMSUH2_ADDR)
#define HW_USBC__HCSPARAMSUH2_RD()      (HW_USBC__HCSPARAMSUH2.U)
#endif

/*
 * constants & macros for individual USBC__HCSPARAMSUH2 bitfields
 */

/* --- Register HW_USBC__HCSPARAMSUH2, field N_PORTS[3:0] (RO)
 *
 * Number of downstream ports. This field specifies the number of physical downstream ports
 * implemented on this host controller. The value of this field determines how many port registers
 * are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in
 * this field is undefined. These bits are always set to '0001b' because all 4 controller cores are
 * Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH2_N_PORTS      (0)
#define BM_USBC__HCSPARAMSUH2_N_PORTS      (0x0000000f)

/* --- Register HW_USBC__HCSPARAMSUH2, field PPC[4:4] (RO)
 *
 * Port Power Control This field indicates whether the host controller implementation includes port
 * power control. A one indicates the ports have port power switches. A zero indicates the ports do
 * not have port power switches. The value of this field affects the functionality of the Port Power
 * field in each port status and control register
 */

#define BP_USBC__HCSPARAMSUH2_PPC      (4)
#define BM_USBC__HCSPARAMSUH2_PPC      (0x00000010)

/* --- Register HW_USBC__HCSPARAMSUH2, field N_PCC[11:8] (RO)
 *
 * Number of Ports per Companion Controller This field indicates the number of ports supported per
 * internal Companion Controller. It is used to indicate the port routing configuration to the
 * system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC
 * could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to
 * companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous
 * example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and
 * the last two are routed to companion controller 2. The number in this field must be consistent
 * with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUH2_N_PCC      (8)
#define BM_USBC__HCSPARAMSUH2_N_PCC      (0x00000f00)

/* --- Register HW_USBC__HCSPARAMSUH2, field N_CC[15:12] (RO)
 *
 * Number of Companion Controller (N_CC). This field indicates the number of companion controllers
 * associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
 *
 * Values:
 * 0 - There is no internal Companion Controller and port-ownership hand-off is not supported.
 * 1 - There are internal companion controller(s) and port-ownership hand-offs is supported.
 */

#define BP_USBC__HCSPARAMSUH2_N_CC      (12)
#define BM_USBC__HCSPARAMSUH2_N_CC      (0x0000f000)


/* --- Register HW_USBC__HCSPARAMSUH2, field PI[16:16] (RO)
 *
 * Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator
 * control. When set to one, the port status and control registers include a read/writeable field
 * for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUH2_PI      (16)
#define BM_USBC__HCSPARAMSUH2_PI      (0x00010000)

/* --- Register HW_USBC__HCSPARAMSUH2, field N_PTT[23:20] (RO)
 *
 * Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates
 * the number of ports assigned to each transaction translator within the USB2.0 host controller.
 * These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH2_N_PTT      (20)
#define BM_USBC__HCSPARAMSUH2_N_PTT      (0x00f00000)

/* --- Register HW_USBC__HCSPARAMSUH2, field N_TT[27:24] (RO)
 *
 * Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number
 * of embedded transaction translators associated with the USB2.0 host controller. These bits would
 * be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH2_N_TT      (24)
#define BM_USBC__HCSPARAMSUH2_N_TT      (0x0f000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCCPARAMSUH2 - Host Controller Capability Parameters UH2 (RO)
 *
 * This register identifies multiple mode control (time-base bit functionality), addressing
 * capability.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADC : 1; //!< 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing capability is supported.
        unsigned PFL : 1; //!< Programmable Frame List Flag If this bit is set to zero, then the system software must use a frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size field is a read-only register and must be set to zero. If set to a one, then the system software can specify and use a smaller frame list and configure the host controller via the USBCMD register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in all 4 controller core.
        unsigned ASP : 1; //!< Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is set '1b' in all 4 controller core.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned IST : 4; //!< Isochronous Scheduling Threshold. This field indicates, relative to the current position of the executing host controller, where software can reliably update the isochronous schedule. When bit [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a host controller can hold a set of isochronous data structures (one or more) before flushing the state. When bit [7] is a one, then host software assumes the host controller may cache an isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller core.
        unsigned EECP : 8; //!< EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A value of 00h indicates no extended capabilities are implemented. A non-zero value in this register indicates the offset in PCI configuration space of the first EHCI extended capability. The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI header defined for this class of device. These bits are set '00h' in all 4 controller core.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_usbc__hccparamsuh2_t;
#endif

/*
 * constants & macros for entire USBC__HCCPARAMSUH2 register
 */
#define HW_USBC__HCCPARAMSUH2_ADDR      (REGS_USBC_BASE + 0x508)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCCPARAMSUH2           (*(volatile hw_usbc__hccparamsuh2_t *) HW_USBC__HCCPARAMSUH2_ADDR)
#define HW_USBC__HCCPARAMSUH2_RD()      (HW_USBC__HCCPARAMSUH2.U)
#endif

/*
 * constants & macros for individual USBC__HCCPARAMSUH2 bitfields
 */

/* --- Register HW_USBC__HCCPARAMSUH2, field ADC[0:0] (RO)
 *
 * 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing
 * capability is supported.
 */

#define BP_USBC__HCCPARAMSUH2_ADC      (0)
#define BM_USBC__HCCPARAMSUH2_ADC      (0x00000001)

/* --- Register HW_USBC__HCCPARAMSUH2, field PFL[1:1] (RO)
 *
 * Programmable Frame List Flag If this bit is set to zero, then the system software must use a
 * frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size
 * field is a read-only register and must be set to zero. If set to a one, then the system software
 * can specify and use a smaller frame list and configure the host controller via the USBCMD
 * register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This
 * requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in
 * all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH2_PFL      (1)
#define BM_USBC__HCCPARAMSUH2_PFL      (0x00000002)

/* --- Register HW_USBC__HCCPARAMSUH2, field ASP[2:2] (RO)
 *
 * Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller
 * supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature
 * can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park
 * Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is
 * set '1b' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH2_ASP      (2)
#define BM_USBC__HCCPARAMSUH2_ASP      (0x00000004)

/* --- Register HW_USBC__HCCPARAMSUH2, field IST[7:4] (RO)
 *
 * Isochronous Scheduling Threshold. This field indicates, relative to the current position of the
 * executing host controller, where software can reliably update the isochronous schedule. When bit
 * [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a
 * host controller can hold a set of isochronous data structures (one or more) before flushing the
 * state. When bit [7] is a one, then host software assumes the host controller may cache an
 * isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller
 * core.
 */

#define BP_USBC__HCCPARAMSUH2_IST      (4)
#define BM_USBC__HCCPARAMSUH2_IST      (0x000000f0)

/* --- Register HW_USBC__HCCPARAMSUH2, field EECP[15:8] (RO)
 *
 * EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A
 * value of 00h indicates no extended capabilities are implemented. A non-zero value in this
 * register indicates the offset in PCI configuration space of the first EHCI extended capability.
 * The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI
 * header defined for this class of device. These bits are set '00h' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH2_EECP      (8)
#define BM_USBC__HCCPARAMSUH2_EECP      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBCMDUH2 - USB Command Register UH2 (RW)
 *
 * The Command Register indicates the command to be executed by the serial bus host/device
 * controller. Writing to the register causes a command to be executed.  *: ASPE,ASP[1],ASP[0] reset
 * value: '0b' for OTG core; '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RS : 1; //!< Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the Controller proceeds with the execution of the schedule. The Controller continues execution as long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the current transaction on the USB and then halts. The HC Halted bit in the status register indicates when the Controller has finished the transaction and has entered the stopped state. Software should not write a one to this field unless the controller is in the Halted state (that is, HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is not directly connected to the pull-up enable, as the pull-up will become disabled upon transitioning into high-speed mode. Software should use this bit to prevent an attach event before the controller has been properly initialized. Writing a 0 to this will cause a detach event.
        unsigned RST : 1; //!< Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register. Host operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Any transaction currently in progress on USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset an actively running host controller will result in undefined behavior. Device operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Writing a one to this bit when the device is in the attached state is not recommended, because the effect on an attached host is undefined. In order to ensure that the device is not in an attached state before initiating a device controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be set to 0.
        unsigned FS : 2; //!< See description at bit 15
        unsigned PSE : 1; //!< Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
        unsigned ASE : 1; //!< Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host controller skips processing the Asynchronous Schedule. Only the host controller uses this bit. Values Meaning
        unsigned IAA : 1; //!< Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to tell the host controller to issue an interrupt the next time it advances asynchronous schedule. Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then the host controller will assert an interrupt at the next interrupt threshold. The host controller sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS register to one. Software should not write a one to this bit when the asynchronous schedule is inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a one to this bit when device mode is selected will have undefined results.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ASP : 2; //!< Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults to zero and is Read-Only. It contains a count of the number of successive transactions the host controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not write a zero to this bit when Park Mode Enable is a one as this will result in undefined behavior. This field is set to 3h in all 4 controller core.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ASPE : 1; //!< Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to '1b' in this implementation.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned SUTW : 1; //!< Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a hazard when new setup data arrives while the DCD is copying the setup data payload from the QH for a previous setup packet. This bit is set and cleared by software. This bit would also be cleared by hardware when a hazard detected. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned ATDTW : 1; //!< Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and cleared by software. This bit would also be cleared by hardware when state machine is hazard region for which adding a dTD to a primed endpoint may go unrecognized. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned FS1 : 1; //!< See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This field specifies the size of the frame list that controls which bits in the Frame Index Register should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and 2. Value Meaning
        unsigned ITC : 8; //!< Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum Interrupt Interval
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc__usbcmduh2_t;
#endif

/*
 * constants & macros for entire USBC__USBCMDUH2 register
 */
#define HW_USBC__USBCMDUH2_ADDR      (REGS_USBC_BASE + 0x540)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBCMDUH2           (*(volatile hw_usbc__usbcmduh2_t *) HW_USBC__USBCMDUH2_ADDR)
#define HW_USBC__USBCMDUH2_RD()      (HW_USBC__USBCMDUH2.U)
#define HW_USBC__USBCMDUH2_WR(v)     (HW_USBC__USBCMDUH2.U = (v))
#define HW_USBC__USBCMDUH2_SET(v)    (HW_USBC__USBCMDUH2_WR(HW_USBC__USBCMDUH2_RD() |  (v)))
#define HW_USBC__USBCMDUH2_CLR(v)    (HW_USBC__USBCMDUH2_WR(HW_USBC__USBCMDUH2_RD() & ~(v)))
#define HW_USBC__USBCMDUH2_TOG(v)    (HW_USBC__USBCMDUH2_WR(HW_USBC__USBCMDUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBCMDUH2 bitfields
 */

/* --- Register HW_USBC__USBCMDUH2, field RS[0:0] (RW)
 *
 * Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the
 * Controller proceeds with the execution of the schedule. The Controller continues execution as
 * long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the
 * current transaction on the USB and then halts. The HC Halted bit in the status register indicates
 * when the Controller has finished the transaction and has entered the stopped state. Software
 * should not write a one to this field unless the controller is in the Halted state (that is,
 * HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will
 * cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is
 * not directly connected to the pull-up enable, as the pull-up will become disabled upon
 * transitioning into high-speed mode. Software should use this bit to prevent an attach event
 * before the controller has been properly initialized. Writing a 0 to this will cause a detach
 * event.
 */

#define BP_USBC__USBCMDUH2_RS      (0)
#define BM_USBC__USBCMDUH2_RS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_RS(v)   ((((reg32_t) v) << 0) & BM_USBC__USBCMDUH2_RS)
#else
#define BF_USBC__USBCMDUH2_RS(v)   (((v) << 0) & BM_USBC__USBCMDUH2_RS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RS field to a new value.
#define BW_USBC__USBCMDUH2_RS(v)   BF_CS1(USBC__USBCMDUH2, RS, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field RST[1:1] (RW)
 *
 * Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit
 * is set to zero by the Host/Device Controller when the reset process is complete. Software cannot
 * terminate the reset process early by writing a zero to this register. Host operation mode: When
 * software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Any transaction currently in progress on
 * USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not
 * set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset
 * an actively running host controller will result in undefined behavior. Device operation mode:
 * When software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Writing a one to this bit when the device
 * is in the attached state is not recommended, because the effect on an attached host is undefined.
 * In order to ensure that the device is not in an attached state before initiating a device
 * controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be
 * set to 0.
 */

#define BP_USBC__USBCMDUH2_RST      (1)
#define BM_USBC__USBCMDUH2_RST      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_RST(v)   ((((reg32_t) v) << 1) & BM_USBC__USBCMDUH2_RST)
#else
#define BF_USBC__USBCMDUH2_RST(v)   (((v) << 1) & BM_USBC__USBCMDUH2_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RST field to a new value.
#define BW_USBC__USBCMDUH2_RST(v)   BF_CS1(USBC__USBCMDUH2, RST, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field FS[3:2] (RW)
 *
 * See description at bit 15
 */

#define BP_USBC__USBCMDUH2_FS      (2)
#define BM_USBC__USBCMDUH2_FS      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_FS(v)   ((((reg32_t) v) << 2) & BM_USBC__USBCMDUH2_FS)
#else
#define BF_USBC__USBCMDUH2_FS(v)   (((v) << 2) & BM_USBC__USBCMDUH2_FS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS field to a new value.
#define BW_USBC__USBCMDUH2_FS(v)   BF_CS1(USBC__USBCMDUH2, FS, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field PSE[4:4] (RW)
 *
 * Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller
 * skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
 *
 * Values:
 * 0 - Do not process the Periodic Schedule
 * 1 - Use the PERIODICLISTBASE register to access the Periodic Schedule.
 */

#define BP_USBC__USBCMDUH2_PSE      (4)
#define BM_USBC__USBCMDUH2_PSE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_PSE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBCMDUH2_PSE)
#else
#define BF_USBC__USBCMDUH2_PSE(v)   (((v) << 4) & BM_USBC__USBCMDUH2_PSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSE field to a new value.
#define BW_USBC__USBCMDUH2_PSE(v)   BF_CS1(USBC__USBCMDUH2, PSE, v)
#endif


/* --- Register HW_USBC__USBCMDUH2, field ASE[5:5] (RW)
 *
 * Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host
 * controller skips processing the Asynchronous Schedule. Only the host controller uses this bit.
 * Values Meaning
 *
 * Values:
 * 0 - Do not process the Asynchronous Schedule.
 * 1 - Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
 */

#define BP_USBC__USBCMDUH2_ASE      (5)
#define BM_USBC__USBCMDUH2_ASE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_ASE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBCMDUH2_ASE)
#else
#define BF_USBC__USBCMDUH2_ASE(v)   (((v) << 5) & BM_USBC__USBCMDUH2_ASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASE field to a new value.
#define BW_USBC__USBCMDUH2_ASE(v)   BF_CS1(USBC__USBCMDUH2, ASE, v)
#endif


/* --- Register HW_USBC__USBCMDUH2, field IAA[6:6] (RW)
 *
 * Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to
 * tell the host controller to issue an interrupt the next time it advances asynchronous schedule.
 * Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted
 * all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the
 * USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then
 * the host controller will assert an interrupt at the next interrupt threshold. The host controller
 * sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS
 * register to one. Software should not write a one to this bit when the asynchronous schedule is
 * inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a
 * one to this bit when device mode is selected will have undefined results.
 */

#define BP_USBC__USBCMDUH2_IAA      (6)
#define BM_USBC__USBCMDUH2_IAA      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_IAA(v)   ((((reg32_t) v) << 6) & BM_USBC__USBCMDUH2_IAA)
#else
#define BF_USBC__USBCMDUH2_IAA(v)   (((v) << 6) & BM_USBC__USBCMDUH2_IAA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IAA field to a new value.
#define BW_USBC__USBCMDUH2_IAA(v)   BF_CS1(USBC__USBCMDUH2, IAA, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field ASP[9:8] (RW)
 *
 * Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults
 * to zero and is Read-Only. It contains a count of the number of successive transactions the host
 * controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before
 * continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not
 * write a zero to this bit when Park Mode Enable is a one as this will result in undefined
 * behavior. This field is set to 3h in all 4 controller core.
 */

#define BP_USBC__USBCMDUH2_ASP      (8)
#define BM_USBC__USBCMDUH2_ASP      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_ASP(v)   ((((reg32_t) v) << 8) & BM_USBC__USBCMDUH2_ASP)
#else
#define BF_USBC__USBCMDUH2_ASP(v)   (((v) << 8) & BM_USBC__USBCMDUH2_ASP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP field to a new value.
#define BW_USBC__USBCMDUH2_ASP(v)   BF_CS1(USBC__USBCMDUH2, ASP, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field ASPE[11:11] (RW)
 *
 * Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit
 * must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is
 * one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to
 * '1b' in this implementation.
 */

#define BP_USBC__USBCMDUH2_ASPE      (11)
#define BM_USBC__USBCMDUH2_ASPE      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_ASPE(v)   ((((reg32_t) v) << 11) & BM_USBC__USBCMDUH2_ASPE)
#else
#define BF_USBC__USBCMDUH2_ASPE(v)   (((v) << 11) & BM_USBC__USBCMDUH2_ASPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASPE field to a new value.
#define BW_USBC__USBCMDUH2_ASPE(v)   BF_CS1(USBC__USBCMDUH2, ASPE, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field SUTW[13:13] (RW)
 *
 * Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that
 * the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If
 * the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a
 * hazard when new setup data arrives while the DCD is copying the setup data payload from the QH
 * for a previous setup packet. This bit is set and cleared by software. This bit would also be
 * cleared by hardware when a hazard detected. For more information on the use of this bit, see the
 * Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUH2_SUTW      (13)
#define BM_USBC__USBCMDUH2_SUTW      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_SUTW(v)   ((((reg32_t) v) << 13) & BM_USBC__USBCMDUH2_SUTW)
#else
#define BF_USBC__USBCMDUH2_SUTW(v)   (((v) << 13) & BM_USBC__USBCMDUH2_SUTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUTW field to a new value.
#define BW_USBC__USBCMDUH2_SUTW(v)   BF_CS1(USBC__USBCMDUH2, SUTW, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field ATDTW[14:14] (RW)
 *
 * Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure
 * proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and
 * cleared by software. This bit would also be cleared by hardware when state machine is hazard
 * region for which adding a dTD to a primed endpoint may go unrecognized. For more information on
 * the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUH2_ATDTW      (14)
#define BM_USBC__USBCMDUH2_ATDTW      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_ATDTW(v)   ((((reg32_t) v) << 14) & BM_USBC__USBCMDUH2_ATDTW)
#else
#define BF_USBC__USBCMDUH2_ATDTW(v)   (((v) << 14) & BM_USBC__USBCMDUH2_ATDTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATDTW field to a new value.
#define BW_USBC__USBCMDUH2_ATDTW(v)   BF_CS1(USBC__USBCMDUH2, ATDTW, v)
#endif

/* --- Register HW_USBC__USBCMDUH2, field FS1[15:15] (RW)
 *
 * See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is
 * Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This
 * field specifies the size of the frame list that controls which bits in the Frame Index Register
 * should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and
 * 2. Value Meaning
 *
 * Values:
 * 000 - 1024 elements (4096 bytes) Default value
 * 001 - 512 elements (2048 bytes)
 * 010 - 256 elements (1024 bytes)
 * 011 - 128 elements (512 bytes)
 * 100 - 64 elements (256 bytes)
 * 101 - 32 elements (128 bytes)
 * 110 - 16 elements (64 bytes)
 * 111 - 8 elements (32 bytes)
 */

#define BP_USBC__USBCMDUH2_FS1      (15)
#define BM_USBC__USBCMDUH2_FS1      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_FS1(v)   ((((reg32_t) v) << 15) & BM_USBC__USBCMDUH2_FS1)
#else
#define BF_USBC__USBCMDUH2_FS1(v)   (((v) << 15) & BM_USBC__USBCMDUH2_FS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS1 field to a new value.
#define BW_USBC__USBCMDUH2_FS1(v)   BF_CS1(USBC__USBCMDUH2, FS1, v)
#endif


/* --- Register HW_USBC__USBCMDUH2, field ITC[23:16] (RW)
 *
 * Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum
 * rate at which the host/device controller will issue interrupts. ITC contains the maximum
 * interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum
 * Interrupt Interval
 *
 * Values:
 * 0x00 - Immediate (no threshold)
 * 0x01 - 1 micro-frame
 * 0x02 - 2 micro-frames
 * 0x04 - 4 micro-frames
 * 0x08 - 8 micro-frames
 * 0x10 - 16 micro-frames
 * 0x20 - 32 micro-frames
 * 0x40 - 64 micro-frames
 */

#define BP_USBC__USBCMDUH2_ITC      (16)
#define BM_USBC__USBCMDUH2_ITC      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH2_ITC(v)   ((((reg32_t) v) << 16) & BM_USBC__USBCMDUH2_ITC)
#else
#define BF_USBC__USBCMDUH2_ITC(v)   (((v) << 16) & BM_USBC__USBCMDUH2_ITC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ITC field to a new value.
#define BW_USBC__USBCMDUH2_ITC(v)   BF_CS1(USBC__USBCMDUH2, ITC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBSTSUH2 - USB Status Register UH2 (RW)
 *
 * This register indicates various states of the Host/Device Controller and any pending interrupts.
 * This register does not indicate status resulting from a transaction on the serial bus.  *HCH bit
 * reset value: '0b' for OTG core, '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UI : 1; //!< USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        unsigned UEI : 1; //!< USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e. 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus, Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB On-The-Go DEV reference manual. The device controller detects resume signaling only.
        unsigned PCI : 1; //!< Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the result of a J-K transition on the suspended port. The Device Controller sets this bit to a one when the port controller enters the full or high-speed operational state. When the port controller exits the full or high-speed operation states due to Reset or Suspend events, the notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
        unsigned FRI : 1; //!< Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index rolls over from its maximum value to zero. The exact value at which the rollover occurs depends on the frame list size. For example. If the frame list size (as programmed in the Frame List Size field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every time FHINDEX [12] toggles. Only used in host operation mode.
        unsigned SEI : 1; //!< System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on the system interface.
        unsigned AAI : 1; //!< Interrupt on Async Advance - R/WC. System software can force the host controller to issue an interrupt the next time the host controller advances the asynchronous schedule by writing a one to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit indicates the assertion of that interrupt source. Only used in host operation mode.
        unsigned URI : 1; //!< USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset Received status bit. Only used in device operation mode.
        unsigned SRI : 1; //!< SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will be set to a one. When a SOF is extremely late, the device controller will automatically set this bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is received. Because the device controller is initialized to FS before connect, this bit will be set at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set every 125us and can be used by host controller driver as a time base. Software writes a 1 to this bit to clear it.
        unsigned SLI : 1; //!< DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be set to a one. The device controller clears the bit upon exiting from a suspend state. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPII : 1; //!< ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HCH : 1; //!< HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either by software or by the Controller hardware (for example, an internal error). Only used in the host operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
        unsigned RCL : 1; //!< Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous schedule. Only used in the host operation mode.
        unsigned PS : 1; //!< Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Periodic Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned AS : 1; //!< Asynchronous Schedule Status - Read Only. This bit reports the current real status of the Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned NAKI : 1; //!< NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
        unsigned RESERVED2 : 7; //!< Reserved
        unsigned TI0 : 1; //!< General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
        unsigned TI1 : 1; //!< General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
        unsigned RESERVED3 : 6; //!< Reserved
    } B;
} hw_usbc__usbstsuh2_t;
#endif

/*
 * constants & macros for entire USBC__USBSTSUH2 register
 */
#define HW_USBC__USBSTSUH2_ADDR      (REGS_USBC_BASE + 0x544)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBSTSUH2           (*(volatile hw_usbc__usbstsuh2_t *) HW_USBC__USBSTSUH2_ADDR)
#define HW_USBC__USBSTSUH2_RD()      (HW_USBC__USBSTSUH2.U)
#define HW_USBC__USBSTSUH2_WR(v)     (HW_USBC__USBSTSUH2.U = (v))
#define HW_USBC__USBSTSUH2_SET(v)    (HW_USBC__USBSTSUH2_WR(HW_USBC__USBSTSUH2_RD() |  (v)))
#define HW_USBC__USBSTSUH2_CLR(v)    (HW_USBC__USBSTSUH2_WR(HW_USBC__USBSTSUH2_RD() & ~(v)))
#define HW_USBC__USBSTSUH2_TOG(v)    (HW_USBC__USBSTSUH2_WR(HW_USBC__USBSTSUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBSTSUH2 bitfields
 */

/* --- Register HW_USBC__USBSTSUH2, field UI[0:0] (RW)
 *
 * USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an
 * interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an
 * interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a
 * short packet is detected. A short packet is when the actual number of bytes received was less
 * than the expected number of bytes.
 */

#define BP_USBC__USBSTSUH2_UI      (0)
#define BM_USBC__USBSTSUH2_UI      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_UI(v)   ((((reg32_t) v) << 0) & BM_USBC__USBSTSUH2_UI)
#else
#define BF_USBC__USBSTSUH2_UI(v)   (((v) << 0) & BM_USBC__USBSTSUH2_UI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UI field to a new value.
#define BW_USBC__USBSTSUH2_UI(v)   BF_CS1(USBC__USBSTSUH2, UI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field UEI[1:1] (RW)
 *
 * USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error
 * condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT
 * bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit
 * set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e.
 * 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus,
 * Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of
 * host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual. The device controller detects resume signaling only.
 */

#define BP_USBC__USBSTSUH2_UEI      (1)
#define BM_USBC__USBSTSUH2_UEI      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_UEI(v)   ((((reg32_t) v) << 1) & BM_USBC__USBSTSUH2_UEI)
#else
#define BF_USBC__USBSTSUH2_UEI(v)   (((v) << 1) & BM_USBC__USBSTSUH2_UEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEI field to a new value.
#define BW_USBC__USBSTSUH2_UEI(v)   BF_CS1(USBC__USBSTSUH2, UEI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field PCI[2:2] (RW)
 *
 * Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect
 * Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the
 * result of a J-K transition on the suspended port. The Device Controller sets this bit to a one
 * when the port controller enters the full or high-speed operational state. When the port
 * controller exits the full or high-speed operation states due to Reset or Suspend events, the
 * notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
 */

#define BP_USBC__USBSTSUH2_PCI      (2)
#define BM_USBC__USBSTSUH2_PCI      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_PCI(v)   ((((reg32_t) v) << 2) & BM_USBC__USBSTSUH2_PCI)
#else
#define BF_USBC__USBSTSUH2_PCI(v)   (((v) << 2) & BM_USBC__USBSTSUH2_PCI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCI field to a new value.
#define BW_USBC__USBSTSUH2_PCI(v)   BF_CS1(USBC__USBSTSUH2, PCI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field FRI[3:3] (RW)
 *
 * Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index
 * rolls over from its maximum value to zero. The exact value at which the rollover occurs depends
 * on the frame list size. For example. If the frame list size (as programmed in the Frame List Size
 * field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX
 * [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every
 * time FHINDEX [12] toggles. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUH2_FRI      (3)
#define BM_USBC__USBSTSUH2_FRI      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_FRI(v)   ((((reg32_t) v) << 3) & BM_USBC__USBSTSUH2_FRI)
#else
#define BF_USBC__USBSTSUH2_FRI(v)   (((v) << 3) & BM_USBC__USBSTSUH2_FRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRI field to a new value.
#define BW_USBC__USBSTSUH2_FRI(v)   BF_CS1(USBC__USBSTSUH2, FRI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field SEI[4:4] (RW)
 *
 * System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on
 * the system interface.
 */

#define BP_USBC__USBSTSUH2_SEI      (4)
#define BM_USBC__USBSTSUH2_SEI      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_SEI(v)   ((((reg32_t) v) << 4) & BM_USBC__USBSTSUH2_SEI)
#else
#define BF_USBC__USBSTSUH2_SEI(v)   (((v) << 4) & BM_USBC__USBSTSUH2_SEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEI field to a new value.
#define BW_USBC__USBSTSUH2_SEI(v)   BF_CS1(USBC__USBSTSUH2, SEI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field AAI[5:5] (RW)
 *
 * Interrupt on Async Advance - R/WC. System software can force the host controller to issue an
 * interrupt the next time the host controller advances the asynchronous schedule by writing a one
 * to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit
 * indicates the assertion of that interrupt source. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUH2_AAI      (5)
#define BM_USBC__USBSTSUH2_AAI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_AAI(v)   ((((reg32_t) v) << 5) & BM_USBC__USBSTSUH2_AAI)
#else
#define BF_USBC__USBSTSUH2_AAI(v)   (((v) << 5) & BM_USBC__USBSTSUH2_AAI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAI field to a new value.
#define BW_USBC__USBSTSUH2_AAI(v)   BF_CS1(USBC__USBSTSUH2, AAI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field URI[6:6] (RW)
 *
 * USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default
 * state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset
 * Received status bit. Only used in device operation mode.
 */

#define BP_USBC__USBSTSUH2_URI      (6)
#define BM_USBC__USBSTSUH2_URI      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_URI(v)   ((((reg32_t) v) << 6) & BM_USBC__USBSTSUH2_URI)
#else
#define BF_USBC__USBSTSUH2_URI(v)   (((v) << 6) & BM_USBC__USBSTSUH2_URI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URI field to a new value.
#define BW_USBC__USBSTSUH2_URI(v)   BF_CS1(USBC__USBSTSUH2, URI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field SRI[7:7] (RW)
 *
 * SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will
 * be set to a one. When a SOF is extremely late, the device controller will automatically set this
 * bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in
 * device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is
 * received. Because the device controller is initialized to FS before connect, this bit will be set
 * at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set
 * every 125us and can be used by host controller driver as a time base. Software writes a 1 to this
 * bit to clear it.
 */

#define BP_USBC__USBSTSUH2_SRI      (7)
#define BM_USBC__USBSTSUH2_SRI      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_SRI(v)   ((((reg32_t) v) << 7) & BM_USBC__USBSTSUH2_SRI)
#else
#define BF_USBC__USBSTSUH2_SRI(v)   (((v) << 7) & BM_USBC__USBSTSUH2_SRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRI field to a new value.
#define BW_USBC__USBSTSUH2_SRI(v)   BF_CS1(USBC__USBSTSUH2, SRI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field SLI[8:8] (RW)
 *
 * DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be
 * set to a one. The device controller clears the bit upon exiting from a suspend state. Only used
 * in device operation mode.
 */

#define BP_USBC__USBSTSUH2_SLI      (8)
#define BM_USBC__USBSTSUH2_SLI      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_SLI(v)   ((((reg32_t) v) << 8) & BM_USBC__USBSTSUH2_SLI)
#else
#define BF_USBC__USBSTSUH2_SLI(v)   (((v) << 8) & BM_USBC__USBSTSUH2_SLI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLI field to a new value.
#define BW_USBC__USBSTSUH2_SLI(v)   BF_CS1(USBC__USBSTSUH2, SLI, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field ULPII[10:10] (RW)
 *
 * ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in
 * ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
 */

#define BP_USBC__USBSTSUH2_ULPII      (10)
#define BM_USBC__USBSTSUH2_ULPII      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_ULPII(v)   ((((reg32_t) v) << 10) & BM_USBC__USBSTSUH2_ULPII)
#else
#define BF_USBC__USBSTSUH2_ULPII(v)   (((v) << 10) & BM_USBC__USBSTSUH2_ULPII)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPII field to a new value.
#define BW_USBC__USBSTSUH2_ULPII(v)   BF_CS1(USBC__USBSTSUH2, ULPII, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field HCH[12:12] (RW)
 *
 * HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets
 * this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either
 * by software or by the Controller hardware (for example, an internal error). Only used in the host
 * operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is
 * because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
 */

#define BP_USBC__USBSTSUH2_HCH      (12)
#define BM_USBC__USBSTSUH2_HCH      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_HCH(v)   ((((reg32_t) v) << 12) & BM_USBC__USBSTSUH2_HCH)
#else
#define BF_USBC__USBSTSUH2_HCH(v)   (((v) << 12) & BM_USBC__USBSTSUH2_HCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCH field to a new value.
#define BW_USBC__USBSTSUH2_HCH(v)   BF_CS1(USBC__USBSTSUH2, HCH, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field RCL[13:13] (RW)
 *
 * Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous
 * schedule. Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUH2_RCL      (13)
#define BM_USBC__USBSTSUH2_RCL      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_RCL(v)   ((((reg32_t) v) << 13) & BM_USBC__USBSTSUH2_RCL)
#else
#define BF_USBC__USBSTSUH2_RCL(v)   (((v) << 13) & BM_USBC__USBSTSUH2_RCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCL field to a new value.
#define BW_USBC__USBSTSUH2_RCL(v)   BF_CS1(USBC__USBSTSUH2, RCL, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field PS[14:14] (RW)
 *
 * Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic
 * Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is
 * enabled. The Host Controller is not required to immediately disable or enable the Periodic
 * Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When
 * this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either
 * enabled (1) or disabled (0). Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUH2_PS      (14)
#define BM_USBC__USBSTSUH2_PS      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_PS(v)   ((((reg32_t) v) << 14) & BM_USBC__USBSTSUH2_PS)
#else
#define BF_USBC__USBSTSUH2_PS(v)   (((v) << 14) & BM_USBC__USBSTSUH2_PS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PS field to a new value.
#define BW_USBC__USBSTSUH2_PS(v)   BF_CS1(USBC__USBSTSUH2, PS, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field AS[15:15] (RW)
 *
 * Asynchronous Schedule Status - Read Only. This bit reports the current real status of the
 * Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set
 * to one the status is enabled. The Host Controller is not required to immediately disable or
 * enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit
 * in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same
 * value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host
 * operation mode.
 */

#define BP_USBC__USBSTSUH2_AS      (15)
#define BM_USBC__USBSTSUH2_AS      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_AS(v)   ((((reg32_t) v) << 15) & BM_USBC__USBSTSUH2_AS)
#else
#define BF_USBC__USBSTSUH2_AS(v)   (((v) << 15) & BM_USBC__USBSTSUH2_AS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AS field to a new value.
#define BW_USBC__USBSTSUH2_AS(v)   BF_CS1(USBC__USBSTSUH2, AS, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field NAKI[16:16] (RO)
 *
 * NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX
 * Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is
 * automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
 */

#define BP_USBC__USBSTSUH2_NAKI      (16)
#define BM_USBC__USBSTSUH2_NAKI      (0x00010000)

/* --- Register HW_USBC__USBSTSUH2, field TI0[24:24] (RW)
 *
 * General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the
 * GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
 */

#define BP_USBC__USBSTSUH2_TI0      (24)
#define BM_USBC__USBSTSUH2_TI0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_TI0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBSTSUH2_TI0)
#else
#define BF_USBC__USBSTSUH2_TI0(v)   (((v) << 24) & BM_USBC__USBSTSUH2_TI0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI0 field to a new value.
#define BW_USBC__USBSTSUH2_TI0(v)   BF_CS1(USBC__USBSTSUH2, TI0, v)
#endif

/* --- Register HW_USBC__USBSTSUH2, field TI1[25:25] (RW)
 *
 * General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the
 * GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
 */

#define BP_USBC__USBSTSUH2_TI1      (25)
#define BM_USBC__USBSTSUH2_TI1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH2_TI1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBSTSUH2_TI1)
#else
#define BF_USBC__USBSTSUH2_TI1(v)   (((v) << 25) & BM_USBC__USBSTSUH2_TI1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI1 field to a new value.
#define BW_USBC__USBSTSUH2_TI1(v)   BF_CS1(USBC__USBSTSUH2, TI1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBINTRUH2 - Interrupt Enable Register UH2 (RW)
 *
 * The interrupts to software are enabled with this register. An interrupt is generated when a bit
 * is set and the corresponding interrupt source is active. The USB Status register (n_USBSTS) still
 * shows interrupt sources even if they are disabled by the n_USBINTR register, allowing polling of
 * interrupt events by the software.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UE : 1; //!< USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned UEE : 1; //!< USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned PCE : 1; //!< Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned FRE : 1; //!< Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned SEE : 1; //!< System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned AAE : 1; //!< Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned URE : 1; //!< USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned SRE : 1; //!< SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned SLE : 1; //!< Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPIE : 1; //!< ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the controller will issue an interrupt. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 5; //!< These bits are reserved and should be set to zero.
        unsigned NAKE : 1; //!< NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned UAIE : 1; //!< USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned UPIE : 1; //!< USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned RESERVED3 : 4; //!< Reserved
        unsigned TIE0 : 1; //!< General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned TIE1 : 1; //!< General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED4 : 6; //!< Reserved
    } B;
} hw_usbc__usbintruh2_t;
#endif

/*
 * constants & macros for entire USBC__USBINTRUH2 register
 */
#define HW_USBC__USBINTRUH2_ADDR      (REGS_USBC_BASE + 0x548)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBINTRUH2           (*(volatile hw_usbc__usbintruh2_t *) HW_USBC__USBINTRUH2_ADDR)
#define HW_USBC__USBINTRUH2_RD()      (HW_USBC__USBINTRUH2.U)
#define HW_USBC__USBINTRUH2_WR(v)     (HW_USBC__USBINTRUH2.U = (v))
#define HW_USBC__USBINTRUH2_SET(v)    (HW_USBC__USBINTRUH2_WR(HW_USBC__USBINTRUH2_RD() |  (v)))
#define HW_USBC__USBINTRUH2_CLR(v)    (HW_USBC__USBINTRUH2_WR(HW_USBC__USBINTRUH2_RD() & ~(v)))
#define HW_USBC__USBINTRUH2_TOG(v)    (HW_USBC__USBINTRUH2_WR(HW_USBC__USBINTRUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBINTRUH2 bitfields
 */

/* --- Register HW_USBC__USBINTRUH2, field UE[0:0] (RW)
 *
 * USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_UE      (0)
#define BM_USBC__USBINTRUH2_UE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_UE(v)   ((((reg32_t) v) << 0) & BM_USBC__USBINTRUH2_UE)
#else
#define BF_USBC__USBINTRUH2_UE(v)   (((v) << 0) & BM_USBC__USBINTRUH2_UE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UE field to a new value.
#define BW_USBC__USBINTRUH2_UE(v)   BF_CS1(USBC__USBINTRUH2, UE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field UEE[1:1] (RW)
 *
 * USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_UEE      (1)
#define BM_USBC__USBINTRUH2_UEE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_UEE(v)   ((((reg32_t) v) << 1) & BM_USBC__USBINTRUH2_UEE)
#else
#define BF_USBC__USBINTRUH2_UEE(v)   (((v) << 1) & BM_USBC__USBINTRUH2_UEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEE field to a new value.
#define BW_USBC__USBINTRUH2_UEE(v)   BF_CS1(USBC__USBINTRUH2, UEE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field PCE[2:2] (RW)
 *
 * Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is
 * a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_PCE      (2)
#define BM_USBC__USBINTRUH2_PCE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_PCE(v)   ((((reg32_t) v) << 2) & BM_USBC__USBINTRUH2_PCE)
#else
#define BF_USBC__USBINTRUH2_PCE(v)   (((v) << 2) & BM_USBC__USBINTRUH2_PCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCE field to a new value.
#define BW_USBC__USBINTRUH2_PCE(v)   BF_CS1(USBC__USBINTRUH2, PCE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field FRE[3:3] (RW)
 *
 * Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is
 * a one the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH2_FRE      (3)
#define BM_USBC__USBINTRUH2_FRE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_FRE(v)   ((((reg32_t) v) << 3) & BM_USBC__USBINTRUH2_FRE)
#else
#define BF_USBC__USBINTRUH2_FRE(v)   (((v) << 3) & BM_USBC__USBINTRUH2_FRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRE field to a new value.
#define BW_USBC__USBINTRUH2_FRE(v)   BF_CS1(USBC__USBINTRUH2, FRE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field SEE[4:4] (RW)
 *
 * System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH2_SEE      (4)
#define BM_USBC__USBINTRUH2_SEE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_SEE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBINTRUH2_SEE)
#else
#define BF_USBC__USBINTRUH2_SEE(v)   (((v) << 4) & BM_USBC__USBINTRUH2_SEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEE field to a new value.
#define BW_USBC__USBINTRUH2_SEE(v)   BF_CS1(USBC__USBINTRUH2, SEE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field AAE[5:5] (RW)
 *
 * Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH2_AAE      (5)
#define BM_USBC__USBINTRUH2_AAE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_AAE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBINTRUH2_AAE)
#else
#define BF_USBC__USBINTRUH2_AAE(v)   (((v) << 5) & BM_USBC__USBINTRUH2_AAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAE field to a new value.
#define BW_USBC__USBINTRUH2_AAE(v)   BF_CS1(USBC__USBINTRUH2, AAE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field URE[6:6] (RW)
 *
 * USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one
 * the controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUH2_URE      (6)
#define BM_USBC__USBINTRUH2_URE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_URE(v)   ((((reg32_t) v) << 6) & BM_USBC__USBINTRUH2_URE)
#else
#define BF_USBC__USBINTRUH2_URE(v)   (((v) << 6) & BM_USBC__USBINTRUH2_URE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URE field to a new value.
#define BW_USBC__USBINTRUH2_URE(v)   BF_CS1(USBC__USBINTRUH2, URE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field SRE[7:7] (RW)
 *
 * SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one
 * the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_SRE      (7)
#define BM_USBC__USBINTRUH2_SRE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_SRE(v)   ((((reg32_t) v) << 7) & BM_USBC__USBINTRUH2_SRE)
#else
#define BF_USBC__USBINTRUH2_SRE(v)   (((v) << 7) & BM_USBC__USBINTRUH2_SRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRE field to a new value.
#define BW_USBC__USBINTRUH2_SRE(v)   BF_CS1(USBC__USBINTRUH2, SRE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field SLE[8:8] (RW)
 *
 * Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the
 * controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUH2_SLE      (8)
#define BM_USBC__USBINTRUH2_SLE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_SLE(v)   ((((reg32_t) v) << 8) & BM_USBC__USBINTRUH2_SLE)
#else
#define BF_USBC__USBINTRUH2_SLE(v)   (((v) << 8) & BM_USBC__USBINTRUH2_SLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLE field to a new value.
#define BW_USBC__USBINTRUH2_SLE(v)   BF_CS1(USBC__USBINTRUH2, SLE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field ULPIE[10:10] (RW)
 *
 * ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the
 * controller will issue an interrupt. This bit is usable only if the controller support UPLI
 * interface mode.
 */

#define BP_USBC__USBINTRUH2_ULPIE      (10)
#define BM_USBC__USBINTRUH2_ULPIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_ULPIE(v)   ((((reg32_t) v) << 10) & BM_USBC__USBINTRUH2_ULPIE)
#else
#define BF_USBC__USBINTRUH2_ULPIE(v)   (((v) << 10) & BM_USBC__USBINTRUH2_ULPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPIE field to a new value.
#define BW_USBC__USBINTRUH2_ULPIE(v)   BF_CS1(USBC__USBINTRUH2, ULPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field NAKE[16:16] (RW)
 *
 * NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_NAKE      (16)
#define BM_USBC__USBINTRUH2_NAKE      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_NAKE(v)   ((((reg32_t) v) << 16) & BM_USBC__USBINTRUH2_NAKE)
#else
#define BF_USBC__USBINTRUH2_NAKE(v)   (((v) << 16) & BM_USBC__USBINTRUH2_NAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NAKE field to a new value.
#define BW_USBC__USBINTRUH2_NAKE(v)   BF_CS1(USBC__USBINTRUH2, NAKE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field UAIE[18:18] (RW)
 *
 * USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS
 * register is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUH2_UAIE      (18)
#define BM_USBC__USBINTRUH2_UAIE      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_UAIE(v)   ((((reg32_t) v) << 18) & BM_USBC__USBINTRUH2_UAIE)
#else
#define BF_USBC__USBINTRUH2_UAIE(v)   (((v) << 18) & BM_USBC__USBINTRUH2_UAIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UAIE field to a new value.
#define BW_USBC__USBINTRUH2_UAIE(v)   BF_CS1(USBC__USBINTRUH2, UAIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field UPIE[19:19] (RW)
 *
 * USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register
 * is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUH2_UPIE      (19)
#define BM_USBC__USBINTRUH2_UPIE      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_UPIE(v)   ((((reg32_t) v) << 19) & BM_USBC__USBINTRUH2_UPIE)
#else
#define BF_USBC__USBINTRUH2_UPIE(v)   (((v) << 19) & BM_USBC__USBINTRUH2_UPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UPIE field to a new value.
#define BW_USBC__USBINTRUH2_UPIE(v)   BF_CS1(USBC__USBINTRUH2, UPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field TIE0[24:24] (RW)
 *
 * General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_TIE0      (24)
#define BM_USBC__USBINTRUH2_TIE0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_TIE0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBINTRUH2_TIE0)
#else
#define BF_USBC__USBINTRUH2_TIE0(v)   (((v) << 24) & BM_USBC__USBINTRUH2_TIE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE0 field to a new value.
#define BW_USBC__USBINTRUH2_TIE0(v)   BF_CS1(USBC__USBINTRUH2, TIE0, v)
#endif

/* --- Register HW_USBC__USBINTRUH2, field TIE1[25:25] (RW)
 *
 * General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH2_TIE1      (25)
#define BM_USBC__USBINTRUH2_TIE1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH2_TIE1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBINTRUH2_TIE1)
#else
#define BF_USBC__USBINTRUH2_TIE1(v)   (((v) << 25) & BM_USBC__USBINTRUH2_TIE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE1 field to a new value.
#define BW_USBC__USBINTRUH2_TIE1(v)   BF_CS1(USBC__USBINTRUH2, TIE1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__FRINDEXUH2 - USB Frame Index UH2 (RW)
 *
 * This register is used by the host controller to index the periodic frame list. The register
 * updates every 125 microseconds (once each micro-frame). Bits [N: 3] are used to select a
 * particular entry in the Periodic Frame List during periodic schedule execution. The number of
 * bits used for the index depends on the size of the frame list as set by system software in the
 * Frame List Size field in the n_USBCMD register.  This register must be written as a DWord. Byte
 * writes produce-undefined results. This register cannot be written unless the Host Controller is
 * in the 'Halted' state as indicated by the HCHalted bit. A write to this register while the
 * Run/Stop hit is set to a one produces undefined results. Writes to this register also affect the
 * SOF value.  In device mode this register is read only and, the device controller updates the
 * FRINDEX [13:3] register from the frame number indicated by the SOF marker. Whenever a SOF is
 * received by the USB bus, FRINDEX [13:3] will be checked against the SOF marker. If FRINDEX [13:3]
 * is different from the SOF marker, FRINDEX [13:3] will be set to the SOF value and FRINDEX [2:0]
 * will be set to zero (that is, SOF for 1 ms frame). If FRINDEX [13:3] is equal to the SOF value,
 * FRINDEX [2:0] will be increment (that is, SOF for 125 us micro-frame.).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FRINDEX : 14; //!< Frame Index. The value, in this register, increments at the end of each time frame (micro-frame). Bits [N: 3] are used for the Frame List current index. This means that each location of the frame list is accessed 8 times (frames or micro-frames) before moving to the next index. The following illustrates values of N based on the value of the Frame List Size field in the USBCMD register, when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is the current frame number of the last frame transmitted. It is not used as an index. In either mode bits 2:0 indicate the current microframe.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_usbc__frindexuh2_t;
#endif

/*
 * constants & macros for entire USBC__FRINDEXUH2 register
 */
#define HW_USBC__FRINDEXUH2_ADDR      (REGS_USBC_BASE + 0x54c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__FRINDEXUH2           (*(volatile hw_usbc__frindexuh2_t *) HW_USBC__FRINDEXUH2_ADDR)
#define HW_USBC__FRINDEXUH2_RD()      (HW_USBC__FRINDEXUH2.U)
#define HW_USBC__FRINDEXUH2_WR(v)     (HW_USBC__FRINDEXUH2.U = (v))
#define HW_USBC__FRINDEXUH2_SET(v)    (HW_USBC__FRINDEXUH2_WR(HW_USBC__FRINDEXUH2_RD() |  (v)))
#define HW_USBC__FRINDEXUH2_CLR(v)    (HW_USBC__FRINDEXUH2_WR(HW_USBC__FRINDEXUH2_RD() & ~(v)))
#define HW_USBC__FRINDEXUH2_TOG(v)    (HW_USBC__FRINDEXUH2_WR(HW_USBC__FRINDEXUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__FRINDEXUH2 bitfields
 */

/* --- Register HW_USBC__FRINDEXUH2, field FRINDEX[13:0] (RW)
 *
 * Frame Index. The value, in this register, increments at the end of each time frame (micro-frame).
 * Bits [N: 3] are used for the Frame List current index. This means that each location of the frame
 * list is accessed 8 times (frames or micro-frames) before moving to the next index. The following
 * illustrates values of N based on the value of the Frame List Size field in the USBCMD register,
 * when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is
 * the current frame number of the last frame transmitted. It is not used as an index. In either
 * mode bits 2:0 indicate the current microframe.
 *
 * Values:
 * 000 - (1024) 12
 * 001 - (512) 11
 * 010 - (256) 10
 * 011 - (128) 9
 * 100 - (64) 8
 * 101 - (32) 7
 * 110 - (16) 6
 * 111 - (8) 5
 */

#define BP_USBC__FRINDEXUH2_FRINDEX      (0)
#define BM_USBC__FRINDEXUH2_FRINDEX      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__FRINDEXUH2_FRINDEX(v)   ((((reg32_t) v) << 0) & BM_USBC__FRINDEXUH2_FRINDEX)
#else
#define BF_USBC__FRINDEXUH2_FRINDEX(v)   (((v) << 0) & BM_USBC__FRINDEXUH2_FRINDEX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRINDEX field to a new value.
#define BW_USBC__FRINDEXUH2_FRINDEX(v)   BF_CS1(USBC__FRINDEXUH2, FRINDEX, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PERIODICLISTBASEUH2 - Frame List Base Address UH2 (RW)
 *
 * Host Controller only  This 32-bit register contains the beginning address of the Periodic Frame
 * List in the system memory. HCD loads this register prior to starting the schedule execution by
 * the Host Controller. The memory structure referenced by this physical memory pointer is assumed
 * to be 4-Kbyte aligned. The contents of this register are combined with the Frame Index Register
 * (UOG_FRINDEX) to enable the Host Controller to step through the Periodic Frame List in sequence.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 12; //!< Reserved
        unsigned BASEADR : 20; //!< Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only used by the host controller.
    } B;
} hw_usbc__periodiclistbaseuh2_t;
#endif

/*
 * constants & macros for entire USBC__PERIODICLISTBASEUH2 register
 */
#define HW_USBC__PERIODICLISTBASEUH2_ADDR      (REGS_USBC_BASE + 0x554)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PERIODICLISTBASEUH2           (*(volatile hw_usbc__periodiclistbaseuh2_t *) HW_USBC__PERIODICLISTBASEUH2_ADDR)
#define HW_USBC__PERIODICLISTBASEUH2_RD()      (HW_USBC__PERIODICLISTBASEUH2.U)
#define HW_USBC__PERIODICLISTBASEUH2_WR(v)     (HW_USBC__PERIODICLISTBASEUH2.U = (v))
#define HW_USBC__PERIODICLISTBASEUH2_SET(v)    (HW_USBC__PERIODICLISTBASEUH2_WR(HW_USBC__PERIODICLISTBASEUH2_RD() |  (v)))
#define HW_USBC__PERIODICLISTBASEUH2_CLR(v)    (HW_USBC__PERIODICLISTBASEUH2_WR(HW_USBC__PERIODICLISTBASEUH2_RD() & ~(v)))
#define HW_USBC__PERIODICLISTBASEUH2_TOG(v)    (HW_USBC__PERIODICLISTBASEUH2_WR(HW_USBC__PERIODICLISTBASEUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PERIODICLISTBASEUH2 bitfields
 */

/* --- Register HW_USBC__PERIODICLISTBASEUH2, field BASEADR[31:12] (RW)
 *
 * Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only
 * used by the host controller.
 */

#define BP_USBC__PERIODICLISTBASEUH2_BASEADR      (12)
#define BM_USBC__PERIODICLISTBASEUH2_BASEADR      (0xfffff000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PERIODICLISTBASEUH2_BASEADR(v)   ((((reg32_t) v) << 12) & BM_USBC__PERIODICLISTBASEUH2_BASEADR)
#else
#define BF_USBC__PERIODICLISTBASEUH2_BASEADR(v)   (((v) << 12) & BM_USBC__PERIODICLISTBASEUH2_BASEADR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASEADR field to a new value.
#define BW_USBC__PERIODICLISTBASEUH2_BASEADR(v)   BF_CS1(USBC__PERIODICLISTBASEUH2, BASEADR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__ASYNCLISTADDRUH2 - Next Asynch. Address UH2 (RW)
 *
 * Host Controller only  This 32-bit register contains the address of the next asynchronous queue
 * head to be executed by the host. Bits [4:0] of this register cannot be modified by the system
 * software and will always return a zero when read.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned ASYBASE : 27; //!< Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively. This field may only reference a Queue Head (QH). Only used by the host controller.
    } B;
} hw_usbc__asynclistaddruh2_t;
#endif

/*
 * constants & macros for entire USBC__ASYNCLISTADDRUH2 register
 */
#define HW_USBC__ASYNCLISTADDRUH2_ADDR      (REGS_USBC_BASE + 0x558)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__ASYNCLISTADDRUH2           (*(volatile hw_usbc__asynclistaddruh2_t *) HW_USBC__ASYNCLISTADDRUH2_ADDR)
#define HW_USBC__ASYNCLISTADDRUH2_RD()      (HW_USBC__ASYNCLISTADDRUH2.U)
#define HW_USBC__ASYNCLISTADDRUH2_WR(v)     (HW_USBC__ASYNCLISTADDRUH2.U = (v))
#define HW_USBC__ASYNCLISTADDRUH2_SET(v)    (HW_USBC__ASYNCLISTADDRUH2_WR(HW_USBC__ASYNCLISTADDRUH2_RD() |  (v)))
#define HW_USBC__ASYNCLISTADDRUH2_CLR(v)    (HW_USBC__ASYNCLISTADDRUH2_WR(HW_USBC__ASYNCLISTADDRUH2_RD() & ~(v)))
#define HW_USBC__ASYNCLISTADDRUH2_TOG(v)    (HW_USBC__ASYNCLISTADDRUH2_WR(HW_USBC__ASYNCLISTADDRUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__ASYNCLISTADDRUH2 bitfields
 */

/* --- Register HW_USBC__ASYNCLISTADDRUH2, field ASYBASE[31:5] (RW)
 *
 * Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively.
 * This field may only reference a Queue Head (QH). Only used by the host controller.
 */

#define BP_USBC__ASYNCLISTADDRUH2_ASYBASE      (5)
#define BM_USBC__ASYNCLISTADDRUH2_ASYBASE      (0xffffffe0)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ASYNCLISTADDRUH2_ASYBASE(v)   ((((reg32_t) v) << 5) & BM_USBC__ASYNCLISTADDRUH2_ASYBASE)
#else
#define BF_USBC__ASYNCLISTADDRUH2_ASYBASE(v)   (((v) << 5) & BM_USBC__ASYNCLISTADDRUH2_ASYBASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASYBASE field to a new value.
#define BW_USBC__ASYNCLISTADDRUH2_ASYBASE(v)   BF_CS1(USBC__ASYNCLISTADDRUH2, ASYBASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__BURSTSIZEUH2 - Programmable Burst Size UH2 (RW)
 *
 * This register is used to control the burst size used during data movement on the AHB master
 * interface. This register is ignored if AHBBRST bits in SBUSCFG register is non-zero value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXPBURST : 8; //!< Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from the USB bus to system memory.
        unsigned TXPBURST : 9; //!< Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from system memory to the USB bus.
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_usbc__burstsizeuh2_t;
#endif

/*
 * constants & macros for entire USBC__BURSTSIZEUH2 register
 */
#define HW_USBC__BURSTSIZEUH2_ADDR      (REGS_USBC_BASE + 0x560)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__BURSTSIZEUH2           (*(volatile hw_usbc__burstsizeuh2_t *) HW_USBC__BURSTSIZEUH2_ADDR)
#define HW_USBC__BURSTSIZEUH2_RD()      (HW_USBC__BURSTSIZEUH2.U)
#define HW_USBC__BURSTSIZEUH2_WR(v)     (HW_USBC__BURSTSIZEUH2.U = (v))
#define HW_USBC__BURSTSIZEUH2_SET(v)    (HW_USBC__BURSTSIZEUH2_WR(HW_USBC__BURSTSIZEUH2_RD() |  (v)))
#define HW_USBC__BURSTSIZEUH2_CLR(v)    (HW_USBC__BURSTSIZEUH2_WR(HW_USBC__BURSTSIZEUH2_RD() & ~(v)))
#define HW_USBC__BURSTSIZEUH2_TOG(v)    (HW_USBC__BURSTSIZEUH2_WR(HW_USBC__BURSTSIZEUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__BURSTSIZEUH2 bitfields
 */

/* --- Register HW_USBC__BURSTSIZEUH2, field RXPBURST[7:0] (RW)
 *
 * Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from the
 * USB bus to system memory.
 */

#define BP_USBC__BURSTSIZEUH2_RXPBURST      (0)
#define BM_USBC__BURSTSIZEUH2_RXPBURST      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUH2_RXPBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__BURSTSIZEUH2_RXPBURST)
#else
#define BF_USBC__BURSTSIZEUH2_RXPBURST(v)   (((v) << 0) & BM_USBC__BURSTSIZEUH2_RXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUH2_RXPBURST(v)   BF_CS1(USBC__BURSTSIZEUH2, RXPBURST, v)
#endif

/* --- Register HW_USBC__BURSTSIZEUH2, field TXPBURST[16:8] (RW)
 *
 * Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from
 * system memory to the USB bus.
 */

#define BP_USBC__BURSTSIZEUH2_TXPBURST      (8)
#define BM_USBC__BURSTSIZEUH2_TXPBURST      (0x0001ff00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUH2_TXPBURST(v)   ((((reg32_t) v) << 8) & BM_USBC__BURSTSIZEUH2_TXPBURST)
#else
#define BF_USBC__BURSTSIZEUH2_TXPBURST(v)   (((v) << 8) & BM_USBC__BURSTSIZEUH2_TXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUH2_TXPBURST(v)   BF_CS1(USBC__BURSTSIZEUH2, TXPBURST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__TXFILLTUNINGUH2 - TX FIFO Fill Tuning UH2 (RW)
 *
 * The fields in this register control performance tuning associated with how the host controller
 * posts data to the TX latency FIFO before moving the data onto the USB bus. The specific areas of
 * performance include the how much data to post into the FIFO and an estimate for how long that
 * operation should take in the target system.  Definitions:  T 0 = Standard packet overhead  T 1 =
 * Time to send data payload  T ff = Time to fetch packet into TX FIFO up to specified level.  T s =
 * Total Packet Flight Time (send-only) packet  T s = T 0 + T 1   T p = Total Packet Time (fetch and
 * send) packet  T p = T ff + T 0 + T 1   Upon discovery of a transmit (OUT/SETUP) packet in the
 * data structures, host controller checks to ensure T  p  remains before the end of the
 * [micro]frame. If so it proceeds to pre-fill the TX FIFO. If at anytime during the pre-fill
 * operation the time remaining the [micro]frame is < T  s  then the packet attempt ceases and the
 * packet is tried at a later time. Although this is not an error condition and the host controller
 * will eventually recover, a mark will be made the scheduler health counter to note the occurrence
 * of a "back-off" event. When a back-off event is detected, the partial packet fetched may need to
 * be discarded from the latency buffer to make room for periodic traffic that will begin after the
 * next SOF. Too many back-off events can waste bandwidth and power on the system bus and thus
 * should be minimized (not necessarily eliminated). Back-offs can be minimized with use of the
 * n_TSCHHEALTH ( T  ff ) described below.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXSCHOH : 8; //!< Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to the schedule time estimator described above as Tff. As an approximation, the value chosen for this register should limit the number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a highly utilized bus. Choosing a value that is too high for this register is not desired as it can needlessly reduce USB utilization. The time unit represented in this register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned TXSCHHEALTH : 5; //!< Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of time to send the packet before the next Start-Of-Frame. This health counter measures the number of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the counter and this counter will max. at 31. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXFIFOTHRES : 6; //!< FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum value is 2 and this value should be a low as possible to maximize USB performance. A higher value can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO may underrun because the data transferred from the latency FIFO to USB occurs before it can be replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED1 : 10; //!< Reserved
    } B;
} hw_usbc__txfilltuninguh2_t;
#endif

/*
 * constants & macros for entire USBC__TXFILLTUNINGUH2 register
 */
#define HW_USBC__TXFILLTUNINGUH2_ADDR      (REGS_USBC_BASE + 0x564)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__TXFILLTUNINGUH2           (*(volatile hw_usbc__txfilltuninguh2_t *) HW_USBC__TXFILLTUNINGUH2_ADDR)
#define HW_USBC__TXFILLTUNINGUH2_RD()      (HW_USBC__TXFILLTUNINGUH2.U)
#define HW_USBC__TXFILLTUNINGUH2_WR(v)     (HW_USBC__TXFILLTUNINGUH2.U = (v))
#define HW_USBC__TXFILLTUNINGUH2_SET(v)    (HW_USBC__TXFILLTUNINGUH2_WR(HW_USBC__TXFILLTUNINGUH2_RD() |  (v)))
#define HW_USBC__TXFILLTUNINGUH2_CLR(v)    (HW_USBC__TXFILLTUNINGUH2_WR(HW_USBC__TXFILLTUNINGUH2_RD() & ~(v)))
#define HW_USBC__TXFILLTUNINGUH2_TOG(v)    (HW_USBC__TXFILLTUNINGUH2_WR(HW_USBC__TXFILLTUNINGUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__TXFILLTUNINGUH2 bitfields
 */

/* --- Register HW_USBC__TXFILLTUNINGUH2, field TXSCHOH[7:0] (RW)
 *
 * Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to
 * the schedule time estimator described above as Tff. As an approximation, the value chosen for
 * this register should limit the number of back-off events captured in the TXSCHHEALTH to less than
 * 10 per second in a highly utilized bus. Choosing a value that is too high for this register is
 * not desired as it can needlessly reduce USB utilization. The time unit represented in this
 * register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in
 * this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is
 * '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUH2_TXSCHOH      (0)
#define BM_USBC__TXFILLTUNINGUH2_TXSCHOH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH2_TXSCHOH(v)   ((((reg32_t) v) << 0) & BM_USBC__TXFILLTUNINGUH2_TXSCHOH)
#else
#define BF_USBC__TXFILLTUNINGUH2_TXSCHOH(v)   (((v) << 0) & BM_USBC__TXFILLTUNINGUH2_TXSCHOH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHOH field to a new value.
#define BW_USBC__TXFILLTUNINGUH2_TXSCHOH(v)   BF_CS1(USBC__TXFILLTUNINGUH2, TXSCHOH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUH2, field TXSCHHEALTH[12:8] (RW)
 *
 * Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller
 * fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of
 * time to send the packet before the next Start-Of-Frame. This health counter measures the number
 * of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register
 * will clear the counter and this counter will max. at 31. Default value is '08h' for OTG
 * controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUH2_TXSCHHEALTH      (8)
#define BM_USBC__TXFILLTUNINGUH2_TXSCHHEALTH      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH2_TXSCHHEALTH(v)   ((((reg32_t) v) << 8) & BM_USBC__TXFILLTUNINGUH2_TXSCHHEALTH)
#else
#define BF_USBC__TXFILLTUNINGUH2_TXSCHHEALTH(v)   (((v) << 8) & BM_USBC__TXFILLTUNINGUH2_TXSCHHEALTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHHEALTH field to a new value.
#define BW_USBC__TXFILLTUNINGUH2_TXSCHHEALTH(v)   BF_CS1(USBC__TXFILLTUNINGUH2, TXSCHHEALTH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUH2, field TXFIFOTHRES[21:16] (RW)
 *
 * FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are
 * posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum
 * value is 2 and this value should be a low as possible to maximize USB performance. A higher value
 * can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO
 * may underrun because the data transferred from the latency FIFO to USB occurs before it can be
 * replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE
 * register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3
 * controller core.
 */

#define BP_USBC__TXFILLTUNINGUH2_TXFIFOTHRES      (16)
#define BM_USBC__TXFILLTUNINGUH2_TXFIFOTHRES      (0x003f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH2_TXFIFOTHRES(v)   ((((reg32_t) v) << 16) & BM_USBC__TXFILLTUNINGUH2_TXFIFOTHRES)
#else
#define BF_USBC__TXFILLTUNINGUH2_TXFIFOTHRES(v)   (((v) << 16) & BM_USBC__TXFILLTUNINGUH2_TXFIFOTHRES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFOTHRES field to a new value.
#define BW_USBC__TXFILLTUNINGUH2_TXFIFOTHRES(v)   BF_CS1(USBC__TXFILLTUNINGUH2, TXFIFOTHRES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IC_USBUH2 - IC_USB enable and voltage negotiation UH2 (RW)
 *
 * This register enable and controls the IC-USB FS/LS transceiver.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IC_VDD1 : 3; //!< These bits indicates which voltage is being supplied to the peripheral This field is read-only and set to 000 in case of a device controller.
        unsigned IC1 : 1; //!< Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1 is enabled, IOMUX must set the DP/DM pad into loopback mode.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__ic_usbuh2_t;
#endif

/*
 * constants & macros for entire USBC__IC_USBUH2 register
 */
#define HW_USBC__IC_USBUH2_ADDR      (REGS_USBC_BASE + 0x56c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IC_USBUH2           (*(volatile hw_usbc__ic_usbuh2_t *) HW_USBC__IC_USBUH2_ADDR)
#define HW_USBC__IC_USBUH2_RD()      (HW_USBC__IC_USBUH2.U)
#define HW_USBC__IC_USBUH2_WR(v)     (HW_USBC__IC_USBUH2.U = (v))
#define HW_USBC__IC_USBUH2_SET(v)    (HW_USBC__IC_USBUH2_WR(HW_USBC__IC_USBUH2_RD() |  (v)))
#define HW_USBC__IC_USBUH2_CLR(v)    (HW_USBC__IC_USBUH2_WR(HW_USBC__IC_USBUH2_RD() & ~(v)))
#define HW_USBC__IC_USBUH2_TOG(v)    (HW_USBC__IC_USBUH2_WR(HW_USBC__IC_USBUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__IC_USBUH2 bitfields
 */

/* --- Register HW_USBC__IC_USBUH2, field IC_VDD1[2:0] (RW)
 *
 * These bits indicates which voltage is being supplied to the peripheral This field is read-only
 * and set to 000 in case of a device controller.
 *
 * Values:
 * 000 - No voltage
 * 001 - 1.0 V
 * 010 - 1.2 V
 * 011 - 1.5 V
 * 100 - 1.8 V
 * 101 - 3.0 V
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_USBC__IC_USBUH2_IC_VDD1      (0)
#define BM_USBC__IC_USBUH2_IC_VDD1      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUH2_IC_VDD1(v)   ((((reg32_t) v) << 0) & BM_USBC__IC_USBUH2_IC_VDD1)
#else
#define BF_USBC__IC_USBUH2_IC_VDD1(v)   (((v) << 0) & BM_USBC__IC_USBUH2_IC_VDD1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC_VDD1 field to a new value.
#define BW_USBC__IC_USBUH2_IC_VDD1(v)   BF_CS1(USBC__IC_USBUH2, IC_VDD1, v)
#endif


/* --- Register HW_USBC__IC_USBUH2, field IC1[3:3] (RW)
 *
 * Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB
 * interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1
 * is enabled, IOMUX must set the DP/DM pad into loopback mode.
 */

#define BP_USBC__IC_USBUH2_IC1      (3)
#define BM_USBC__IC_USBUH2_IC1      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUH2_IC1(v)   ((((reg32_t) v) << 3) & BM_USBC__IC_USBUH2_IC1)
#else
#define BF_USBC__IC_USBUH2_IC1(v)   (((v) << 3) & BM_USBC__IC_USBUH2_IC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC1 field to a new value.
#define BW_USBC__IC_USBUH2_IC1(v)   BF_CS1(USBC__IC_USBUH2, IC1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PORTSC1UH2 - Port Status & Control UH2 (RW)
 *
 * Host Controller  A host controller could implement one to eight port status and control
 * registers. The number is determined by N_PORTs bits in HWSPARAMs register (please see ). Software
 * could read this parameter register to determine how many ports need service.  All 4 controller
 * cores are Single-Port Host, so there is only one port status and control register for each
 * controller core.  This register is only reset by power on reset or controller core reset. The
 * initial conditions of a port are:   No device connected  Port disabled   If the port supports
 * power control, this state remains until port power is supplied (by software).  Device Controller
 * A device controller has only port register one (PORTSC1) and it does not support power control.
 * Port control in device mode is only used for status port reset, suspend, and current connect
 * status. It is also used to initiate test mode or force signaling and allows software to put the
 * PHY into low power suspend mode and disable the PHY clock.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CCS : 1; //!< Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is present. Default = 0. This value reflects the current state of the port, and may not correspond directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached. Default=0. A one indicates that the device successfully attached and is operating in either high speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates that the device did not attach successfully or was forcibly disconnected by the software writing a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or suspended.
        unsigned CSC : 1; //!< Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device controller sets this bit for all changes to the port device connect status, even if system software has not cleared an existing connect status change. For example, the insertion status changes twice before system software has cleared the changed condition, hub hardware will be 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode: This bit is undefined in device controller mode.
        unsigned PE : 1; //!< Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be enabled by the host controller as a part of the reset and enable. Software cannot enable a port by writing a one to this field. Ports can be disabled by either a fault condition (disconnect event or other fault condition) or by the host software. Note that the bit status does not change until the port state actually changes. There may be a delay in disabling or enabling a port due to other host controller and bus events. When the port is disabled, (0b) downstream propagation of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In Device Mode: The device port is always enabled, so this bit is always '1b'.
        unsigned PEC : 1; //!< Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is always '0b'.
        unsigned OCA : 1; //!< Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero when the over current condition is removed. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned OCC : 1; //!< Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to Over-current Active. Software can clear this bit by writing a one to this bit position. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned FPR : 1; //!< Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state) detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will automatically change to zero after the resume sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the resume duration is timed in the driver. Note that when the Host controller owns the port, the resume sequence follows the defined sequence documented in the USB Specification Revision 2.0. The resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no affect because the port controller will time the resume operation clear the bit the port control state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or more, software must set this bit to one to drive resume signaling before clearing. The Device Controller will set this bit to one if a J-to-K transition is detected while the port is in the Suspend state. The bit will be cleared when the device returns to normal operation. Also, when this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the USBSTS register is also set to one.
        unsigned SUSP : 1; //!< Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend When in suspend state, downstream propagation of data is blocked on this port, except for port reset. The blocking occurs at the end of the current transaction if a transaction was in progress when this bit was written to 1. In the suspend state, the port is sensitive to resume detection. Note that the bit status does not change until the port is suspended and that there may be a delay in suspending a port if there is a transaction currently in progress on the The host controller will unconditionally set this bit to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write of zero to this bit. If host software sets this bit to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only. In device mode this bit is a read only status bit.
        unsigned PR : 1; //!< Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset. 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence as defined in the USB Specification Revision 2.0 is started. This bit will automatically change to zero after the reset sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the reset duration is timed in the driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
        unsigned HSP : 1; //!< High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the port is in high-speed mode and if set to zero, the host/device connected to the port is not in a high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
        unsigned LS : 2; //!< Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D- (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not necessary (unlike EHCI), because the port controller state machine and the port routing manage the connection of LS and FS. In device mode, the use of linestate by the device controller driver is not necessary. The encoding of the bits are: Bits [11:10] Meaning
        unsigned PP : 1; //!< Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP Operation 0 1b Read Only - Host controller does not have port power control switches. Each port is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not available on a port (that is, PP equals a 0), the port is non-functional and will not report attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is a one, the PP bit in each affected port may be transitional by the host controller driver from a one to a zero (removing power from the port). This feature is implemented in all 4 controller cores (PPC = 1).
        unsigned PO : 1; //!< Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever the Configured bit is zero System software uses this field to release ownership of the port to a selected host controller (in the event that the attached device is not a high-speed device). Software writes a one to this bit when the attached device is not a high-speed device. A one in this bit means that an internal companion controller owns and controls the port. Port owner handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
        unsigned PIC : 2; //!< Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0 for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit Value Meaning
        unsigned PTC : 4; //!< Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS} values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point. Low speed operations are not supported as a peripheral device. Any other value than zero indicates that the port is operating in test mode. Value Specific Test
        unsigned WKCN : 1; //!< Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKDC : 1; //!< Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device disconnects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKOC : 1; //!< Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one enables the port to be sensitive to over-current conditions as wake-up events. This field is zero if Port Power( ) is zero.
        unsigned PHCD : 1; //!< PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock. The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically when the host initials resume. Before forcing a resume from the device, the device controller driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the downstream device has been put into suspend mode or when no downstream device is connected. Low power suspend is completely under the control of software.
        unsigned PFSC : 1; //!< Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port to identify itself as High Speed.
        unsigned PTS : 1; //!< See description at bits 31-30
        unsigned PSPD : 2; //!< Port Speed - Read Only. This register field indicates the speed at which the port is operating. For HS mode operation in the host controller and HS/FS operation in the device controller the port routing steers data to the Protocol engine. For FS and LS mode operation in the host controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction Translator.
        unsigned PTW : 1; //!< Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16 selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0 selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0; For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver Width This bit has no effect if serial interface engine is used. These register bits are implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3 core, it is Read-Only. Reset value is '1b'.
        unsigned STS : 1; //!< Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver interface is selected for FS and LS operation. The Serial Interface Engine can be used in combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for future operation and is a placeholder adding dynamic use of the serial engine in accord with UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita, OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select - Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value. Serial Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value.
        unsigned PTS1 : 2; //!< Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30, bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE = 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 - Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7; For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b" Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC All USB port interface modes are listed in this field description, but not all are supported. For detail feature of each controller core, please see . The behaviour is unknown when unsupported interface mode is selected.
    } B;
} hw_usbc__portsc1uh2_t;
#endif

/*
 * constants & macros for entire USBC__PORTSC1UH2 register
 */
#define HW_USBC__PORTSC1UH2_ADDR      (REGS_USBC_BASE + 0x584)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PORTSC1UH2           (*(volatile hw_usbc__portsc1uh2_t *) HW_USBC__PORTSC1UH2_ADDR)
#define HW_USBC__PORTSC1UH2_RD()      (HW_USBC__PORTSC1UH2.U)
#define HW_USBC__PORTSC1UH2_WR(v)     (HW_USBC__PORTSC1UH2.U = (v))
#define HW_USBC__PORTSC1UH2_SET(v)    (HW_USBC__PORTSC1UH2_WR(HW_USBC__PORTSC1UH2_RD() |  (v)))
#define HW_USBC__PORTSC1UH2_CLR(v)    (HW_USBC__PORTSC1UH2_WR(HW_USBC__PORTSC1UH2_RD() & ~(v)))
#define HW_USBC__PORTSC1UH2_TOG(v)    (HW_USBC__PORTSC1UH2_WR(HW_USBC__PORTSC1UH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PORTSC1UH2 bitfields
 */

/* --- Register HW_USBC__PORTSC1UH2, field CCS[0:0] (RW)
 *
 * Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is
 * present. Default = 0. This value reflects the current state of the port, and may not correspond
 * directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is
 * zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached.
 * Default=0. A one indicates that the device successfully attached and is operating in either high
 * speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates
 * that the device did not attach successfully or was forcibly disconnected by the software writing
 * a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or
 * suspended.
 */

#define BP_USBC__PORTSC1UH2_CCS      (0)
#define BM_USBC__PORTSC1UH2_CCS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_CCS(v)   ((((reg32_t) v) << 0) & BM_USBC__PORTSC1UH2_CCS)
#else
#define BF_USBC__PORTSC1UH2_CCS(v)   (((v) << 0) & BM_USBC__PORTSC1UH2_CCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CCS field to a new value.
#define BW_USBC__PORTSC1UH2_CCS(v)   BF_CS1(USBC__PORTSC1UH2, CCS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field CSC[1:1] (RW)
 *
 * Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host
 * Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device
 * controller sets this bit for all changes to the port device connect status, even if system
 * software has not cleared an existing connect status change. For example, the insertion status
 * changes twice before system software has cleared the changed condition, hub hardware will be
 * 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by
 * writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode:
 * This bit is undefined in device controller mode.
 */

#define BP_USBC__PORTSC1UH2_CSC      (1)
#define BM_USBC__PORTSC1UH2_CSC      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_CSC(v)   ((((reg32_t) v) << 1) & BM_USBC__PORTSC1UH2_CSC)
#else
#define BF_USBC__PORTSC1UH2_CSC(v)   (((v) << 1) & BM_USBC__PORTSC1UH2_CSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC field to a new value.
#define BW_USBC__PORTSC1UH2_CSC(v)   BF_CS1(USBC__PORTSC1UH2, CSC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PE[2:2] (RW)
 *
 * Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be
 * enabled by the host controller as a part of the reset and enable. Software cannot enable a port
 * by writing a one to this field. Ports can be disabled by either a fault condition (disconnect
 * event or other fault condition) or by the host software. Note that the bit status does not change
 * until the port state actually changes. There may be a delay in disabling or enabling a port due
 * to other host controller and bus events. When the port is disabled, (0b) downstream propagation
 * of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In
 * Device Mode: The device port is always enabled, so this bit is always '1b'.
 */

#define BP_USBC__PORTSC1UH2_PE      (2)
#define BM_USBC__PORTSC1UH2_PE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PE(v)   ((((reg32_t) v) << 2) & BM_USBC__PORTSC1UH2_PE)
#else
#define BF_USBC__PORTSC1UH2_PE(v)   (((v) << 2) & BM_USBC__PORTSC1UH2_PE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PE field to a new value.
#define BW_USBC__PORTSC1UH2_PE(v)   BF_CS1(USBC__PORTSC1UH2, PE, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PEC[3:3] (RW)
 *
 * Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default
 * = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to
 * disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See
 * Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is
 * zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is
 * always '0b'.
 */

#define BP_USBC__PORTSC1UH2_PEC      (3)
#define BM_USBC__PORTSC1UH2_PEC      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PEC(v)   ((((reg32_t) v) << 3) & BM_USBC__PORTSC1UH2_PEC)
#else
#define BF_USBC__PORTSC1UH2_PEC(v)   (((v) << 3) & BM_USBC__PORTSC1UH2_PEC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PEC field to a new value.
#define BW_USBC__PORTSC1UH2_PEC(v)   BF_CS1(USBC__PORTSC1UH2, PEC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field OCA[4:4] (RW)
 *
 * Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero
 * when the over current condition is removed. For host/OTG implementations the user can provide
 * over-current detection to the vbus_pwr_fault input for this condition. For device-only
 * implementations this bit shall always be 0.
 *
 * Values:
 * 0 - This port does not have an over-current condition.
 * 1 - This port currently has an over-current condition
 */

#define BP_USBC__PORTSC1UH2_OCA      (4)
#define BM_USBC__PORTSC1UH2_OCA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_OCA(v)   ((((reg32_t) v) << 4) & BM_USBC__PORTSC1UH2_OCA)
#else
#define BF_USBC__PORTSC1UH2_OCA(v)   (((v) << 4) & BM_USBC__PORTSC1UH2_OCA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCA field to a new value.
#define BW_USBC__PORTSC1UH2_OCA(v)   BF_CS1(USBC__PORTSC1UH2, OCA, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field OCC[5:5] (RW)
 *
 * Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to
 * Over-current Active. Software can clear this bit by writing a one to this bit position. For
 * host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input
 * for this condition. For device-only implementations this bit shall always be 0.
 */

#define BP_USBC__PORTSC1UH2_OCC      (5)
#define BM_USBC__PORTSC1UH2_OCC      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_OCC(v)   ((((reg32_t) v) << 5) & BM_USBC__PORTSC1UH2_OCC)
#else
#define BF_USBC__PORTSC1UH2_OCC(v)   (((v) << 5) & BM_USBC__PORTSC1UH2_OCC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCC field to a new value.
#define BW_USBC__PORTSC1UH2_OCC(v)   BF_CS1(USBC__PORTSC1UH2, OCC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field FPR[6:6] (RW)
 *
 * Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state)
 * detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume
 * signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the
 * port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is
 * detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will
 * automatically change to zero after the resume sequence is complete. This behavior is different
 * from EHCI where the host controller driver is required to set this bit to a zero after the resume
 * duration is timed in the driver. Note that when the Host controller owns the port, the resume
 * sequence follows the defined sequence documented in the USB Specification Revision 2.0. The
 * resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This
 * bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no
 * affect because the port controller will time the resume operation clear the bit the port control
 * state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This
 * bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or
 * more, software must set this bit to one to drive resume signaling before clearing. The Device
 * Controller will set this bit to one if a J-to-K transition is detected while the port is in the
 * Suspend state. The bit will be cleared when the device returns to normal operation. Also, when
 * this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the
 * USBSTS register is also set to one.
 */

#define BP_USBC__PORTSC1UH2_FPR      (6)
#define BM_USBC__PORTSC1UH2_FPR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_FPR(v)   ((((reg32_t) v) << 6) & BM_USBC__PORTSC1UH2_FPR)
#else
#define BF_USBC__PORTSC1UH2_FPR(v)   (((v) << 6) & BM_USBC__PORTSC1UH2_FPR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FPR field to a new value.
#define BW_USBC__PORTSC1UH2_FPR(v)   BF_CS1(USBC__PORTSC1UH2, FPR, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field SUSP[7:7] (RW)
 *
 * Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend
 * state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the
 * port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend
 * When in suspend state, downstream propagation of data is blocked on this port, except for port
 * reset. The blocking occurs at the end of the current transaction if a transaction was in progress
 * when this bit was written to 1. In the suspend state, the port is sensitive to resume detection.
 * Note that the bit status does not change until the port is suspended and that there may be a
 * delay in suspending a port if there is a transaction currently in progress on the The host
 * controller will unconditionally set this bit to zero when software sets the Force Port Resume bit
 * to zero. The host controller ignores a write of zero to this bit. If host software sets this bit
 * to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are
 * undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only.
 * In device mode this bit is a read only status bit.
 */

#define BP_USBC__PORTSC1UH2_SUSP      (7)
#define BM_USBC__PORTSC1UH2_SUSP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_SUSP(v)   ((((reg32_t) v) << 7) & BM_USBC__PORTSC1UH2_SUSP)
#else
#define BF_USBC__PORTSC1UH2_SUSP(v)   (((v) << 7) & BM_USBC__PORTSC1UH2_SUSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSP field to a new value.
#define BW_USBC__PORTSC1UH2_SUSP(v)   BF_CS1(USBC__PORTSC1UH2, SUSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PR[8:8] (RW)
 *
 * Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset.
 * 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence
 * as defined in the USB Specification Revision 2.0 is started. This bit will automatically change
 * to zero after the reset sequence is complete. This behavior is different from EHCI where the host
 * controller driver is required to set this bit to a zero after the reset duration is timed in the
 * driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also
 * indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UH2_PR      (8)
#define BM_USBC__PORTSC1UH2_PR      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PR(v)   ((((reg32_t) v) << 8) & BM_USBC__PORTSC1UH2_PR)
#else
#define BF_USBC__PORTSC1UH2_PR(v)   (((v) << 8) & BM_USBC__PORTSC1UH2_PR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PR field to a new value.
#define BW_USBC__PORTSC1UH2_PR(v)   BF_CS1(USBC__PORTSC1UH2, PR, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field HSP[9:9] (RW)
 *
 * High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the
 * port is in high-speed mode and if set to zero, the host/device connected to the port is not in a
 * high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
 */

#define BP_USBC__PORTSC1UH2_HSP      (9)
#define BM_USBC__PORTSC1UH2_HSP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_HSP(v)   ((((reg32_t) v) << 9) & BM_USBC__PORTSC1UH2_HSP)
#else
#define BF_USBC__PORTSC1UH2_HSP(v)   (((v) << 9) & BM_USBC__PORTSC1UH2_HSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSP field to a new value.
#define BW_USBC__PORTSC1UH2_HSP(v)   BF_CS1(USBC__PORTSC1UH2, HSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field LS[11:10] (RW)
 *
 * Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D-
 * (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not
 * necessary (unlike EHCI), because the port controller state machine and the port routing manage
 * the connection of LS and FS. In device mode, the use of linestate by the device controller driver
 * is not necessary. The encoding of the bits are: Bits [11:10] Meaning
 *
 * Values:
 * 00 - SE0
 * 01 - K-state
 * 10 - J-state
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH2_LS      (10)
#define BM_USBC__PORTSC1UH2_LS      (0x00000c00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_LS(v)   ((((reg32_t) v) << 10) & BM_USBC__PORTSC1UH2_LS)
#else
#define BF_USBC__PORTSC1UH2_LS(v)   (((v) << 10) & BM_USBC__PORTSC1UH2_LS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LS field to a new value.
#define BW_USBC__PORTSC1UH2_LS(v)   BF_CS1(USBC__PORTSC1UH2, LS, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field PP[12:12] (RW)
 *
 * Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the
 * Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP
 * Operation 0 1b Read Only - Host controller does not have port power control switches. Each port
 * is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control
 * switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not
 * available on a port (that is, PP equals a 0), the port is non-functional and will not report
 * attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is
 * a one, the PP bit in each affected port may be transitional by the host controller driver from a
 * one to a zero (removing power from the port). This feature is implemented in all 4 controller
 * cores (PPC = 1).
 */

#define BP_USBC__PORTSC1UH2_PP      (12)
#define BM_USBC__PORTSC1UH2_PP      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PP(v)   ((((reg32_t) v) << 12) & BM_USBC__PORTSC1UH2_PP)
#else
#define BF_USBC__PORTSC1UH2_PP(v)   (((v) << 12) & BM_USBC__PORTSC1UH2_PP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PP field to a new value.
#define BW_USBC__PORTSC1UH2_PP(v)   BF_CS1(USBC__PORTSC1UH2, PP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PO[13:13] (RW)
 *
 * Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit
 * in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever
 * the Configured bit is zero System software uses this field to release ownership of the port to a
 * selected host controller (in the event that the attached device is not a high-speed device).
 * Software writes a one to this bit when the attached device is not a high-speed device. A one in
 * this bit means that an internal companion controller owns and controls the port. Port owner
 * handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
 */

#define BP_USBC__PORTSC1UH2_PO      (13)
#define BM_USBC__PORTSC1UH2_PO      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PO(v)   ((((reg32_t) v) << 13) & BM_USBC__PORTSC1UH2_PO)
#else
#define BF_USBC__PORTSC1UH2_PO(v)   (((v) << 13) & BM_USBC__PORTSC1UH2_PO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PO field to a new value.
#define BW_USBC__PORTSC1UH2_PO(v)   BF_CS1(USBC__PORTSC1UH2, PO, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PIC[15:14] (RW)
 *
 * Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the
 * P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0
 * for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit
 * Value Meaning
 *
 * Values:
 * 00 - Port indicators are off
 * 01 - Amber
 * 10 - Green
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH2_PIC      (14)
#define BM_USBC__PORTSC1UH2_PIC      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PIC(v)   ((((reg32_t) v) << 14) & BM_USBC__PORTSC1UH2_PIC)
#else
#define BF_USBC__PORTSC1UH2_PIC(v)   (((v) << 14) & BM_USBC__PORTSC1UH2_PIC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIC field to a new value.
#define BW_USBC__PORTSC1UH2_PIC(v)   BF_CS1(USBC__PORTSC1UH2, PIC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field PTC[19:16] (RW)
 *
 * Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model
 * for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each
 * test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support
 * specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS}
 * values will force the port into the connected and enabled state at the selected speed. Writing
 * the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally
 * from that point. Low speed operations are not supported as a peripheral device. Any other value
 * than zero indicates that the port is operating in test mode. Value Specific Test
 *
 * Values:
 * 0000 - TEST_MODE_DISABLE
 * 0001 - J_STATE
 * 0010 - K_STATE
 * 0011 - SE0 (host) / NAK (device)
 * 0100 - Packet
 * 0101 - FORCE_ENABLE_HS
 * 0110 - FORCE_ENABLE_FS
 * 0111 - FORCE_ENABLE_LS
 * 1000-1111 - Reserved
 */

#define BP_USBC__PORTSC1UH2_PTC      (16)
#define BM_USBC__PORTSC1UH2_PTC      (0x000f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PTC(v)   ((((reg32_t) v) << 16) & BM_USBC__PORTSC1UH2_PTC)
#else
#define BF_USBC__PORTSC1UH2_PTC(v)   (((v) << 16) & BM_USBC__PORTSC1UH2_PTC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTC field to a new value.
#define BW_USBC__PORTSC1UH2_PTC(v)   BF_CS1(USBC__PORTSC1UH2, PTC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field WKCN[20:20] (RW)
 *
 * Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the
 * port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is
 * zero or in device mode.
 */

#define BP_USBC__PORTSC1UH2_WKCN      (20)
#define BM_USBC__PORTSC1UH2_WKCN      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_WKCN(v)   ((((reg32_t) v) << 20) & BM_USBC__PORTSC1UH2_WKCN)
#else
#define BF_USBC__PORTSC1UH2_WKCN(v)   (((v) << 20) & BM_USBC__PORTSC1UH2_WKCN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKCN field to a new value.
#define BW_USBC__PORTSC1UH2_WKCN(v)   BF_CS1(USBC__PORTSC1UH2, WKCN, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field WKDC[21:21] (RW)
 *
 * Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one
 * enables the port to be sensitive to device disconnects as wake-up events. This field is zero if
 * Port Power( ) is zero or in device mode.
 */

#define BP_USBC__PORTSC1UH2_WKDC      (21)
#define BM_USBC__PORTSC1UH2_WKDC      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_WKDC(v)   ((((reg32_t) v) << 21) & BM_USBC__PORTSC1UH2_WKDC)
#else
#define BF_USBC__PORTSC1UH2_WKDC(v)   (((v) << 21) & BM_USBC__PORTSC1UH2_WKDC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKDC field to a new value.
#define BW_USBC__PORTSC1UH2_WKDC(v)   BF_CS1(USBC__PORTSC1UH2, WKDC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field WKOC[22:22] (RW)
 *
 * Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one
 * enables the port to be sensitive to over-current conditions as wake-up events. This field is zero
 * if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UH2_WKOC      (22)
#define BM_USBC__PORTSC1UH2_WKOC      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_WKOC(v)   ((((reg32_t) v) << 22) & BM_USBC__PORTSC1UH2_WKOC)
#else
#define BF_USBC__PORTSC1UH2_WKOC(v)   (((v) << 22) & BM_USBC__PORTSC1UH2_WKOC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKOC field to a new value.
#define BW_USBC__PORTSC1UH2_WKOC(v)   BF_CS1(USBC__PORTSC1UH2, WKOC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PHCD[23:23] (RW)
 *
 * PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set
 * to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock.
 * The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY
 * can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host
 * has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically
 * when the host initials resume. Before forcing a resume from the device, the device controller
 * driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the
 * downstream device has been put into suspend mode or when no downstream device is connected. Low
 * power suspend is completely under the control of software.
 *
 * Values:
 * 0 - Enable PHY clock
 * 1 - Disable PHY clock
 */

#define BP_USBC__PORTSC1UH2_PHCD      (23)
#define BM_USBC__PORTSC1UH2_PHCD      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PHCD(v)   ((((reg32_t) v) << 23) & BM_USBC__PORTSC1UH2_PHCD)
#else
#define BF_USBC__PORTSC1UH2_PHCD(v)   (((v) << 23) & BM_USBC__PORTSC1UH2_PHCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHCD field to a new value.
#define BW_USBC__PORTSC1UH2_PHCD(v)   BF_CS1(USBC__PORTSC1UH2, PHCD, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field PFSC[24:24] (RW)
 *
 * Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port
 * will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port
 * to identify itself as High Speed.
 *
 * Values:
 * 0 - Normal operation
 * 1 - Forced to full speed
 */

#define BP_USBC__PORTSC1UH2_PFSC      (24)
#define BM_USBC__PORTSC1UH2_PFSC      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PFSC(v)   ((((reg32_t) v) << 24) & BM_USBC__PORTSC1UH2_PFSC)
#else
#define BF_USBC__PORTSC1UH2_PFSC(v)   (((v) << 24) & BM_USBC__PORTSC1UH2_PFSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFSC field to a new value.
#define BW_USBC__PORTSC1UH2_PFSC(v)   BF_CS1(USBC__PORTSC1UH2, PFSC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field PTS[25:25] (RW)
 *
 * See description at bits 31-30
 */

#define BP_USBC__PORTSC1UH2_PTS      (25)
#define BM_USBC__PORTSC1UH2_PTS      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PTS(v)   ((((reg32_t) v) << 25) & BM_USBC__PORTSC1UH2_PTS)
#else
#define BF_USBC__PORTSC1UH2_PTS(v)   (((v) << 25) & BM_USBC__PORTSC1UH2_PTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS field to a new value.
#define BW_USBC__PORTSC1UH2_PTS(v)   BF_CS1(USBC__PORTSC1UH2, PTS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PSPD[27:26] (RW)
 *
 * Port Speed - Read Only. This register field indicates the speed at which the port is operating.
 * For HS mode operation in the host controller and HS/FS operation in the device controller the
 * port routing steers data to the Protocol engine. For FS and LS mode operation in the host
 * controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction
 * Translator.
 *
 * Values:
 * 00 - Full Speed
 * 01 - Low Speed
 * 10 - High Speed
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH2_PSPD      (26)
#define BM_USBC__PORTSC1UH2_PSPD      (0x0c000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PSPD(v)   ((((reg32_t) v) << 26) & BM_USBC__PORTSC1UH2_PSPD)
#else
#define BF_USBC__PORTSC1UH2_PSPD(v)   (((v) << 26) & BM_USBC__PORTSC1UH2_PSPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSPD field to a new value.
#define BW_USBC__PORTSC1UH2_PSPD(v)   BF_CS1(USBC__PORTSC1UH2, PSPD, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field PTW[28:28] (RW)
 *
 * Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI
 * transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16
 * selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0
 * selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI
 * interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined
 * in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0;
 * For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver
 * Width This bit has no effect if serial interface engine is used. These register bits are
 * implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For
 * Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For
 * OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3
 * core, it is Read-Only. Reset value is '1b'.
 *
 * Values:
 * 1 - Select the 8-bit UTMI interface [60MHz]
 * 2 - Select the 16-bit UTMI interface [30MHz]
 */

#define BP_USBC__PORTSC1UH2_PTW      (28)
#define BM_USBC__PORTSC1UH2_PTW      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PTW(v)   ((((reg32_t) v) << 28) & BM_USBC__PORTSC1UH2_PTW)
#else
#define BF_USBC__PORTSC1UH2_PTW(v)   (((v) << 28) & BM_USBC__PORTSC1UH2_PTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTW field to a new value.
#define BW_USBC__PORTSC1UH2_PTW(v)   BF_CS1(USBC__PORTSC1UH2, PTW, v)
#endif


/* --- Register HW_USBC__PORTSC1UH2, field STS[29:29] (RW)
 *
 * Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver
 * interface is selected for FS and LS operation. The Serial Interface Engine can be used in
 * combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the
 * parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel
 * Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial
 * Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for
 * future operation and is a placeholder adding dynamic use of the serial engine in accord with
 * UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification
 * VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita,
 * OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select -
 * Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals
 * is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface
 * to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b',
 * serial interface engine will be used instead of parallel interface signals. This bit has no
 * effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will
 * use the serial interface engine for FS/LS signaling regardless of this bit value. Serial
 * Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0
 * Parallel Interface signals is selected Serial Interface Engine can be used in combination with
 * UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface
 * signals. When this bit is set '1b', serial interface engine will be used instead of parallel
 * interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface.
 * The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless
 * of this bit value.
 */

#define BP_USBC__PORTSC1UH2_STS      (29)
#define BM_USBC__PORTSC1UH2_STS      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_STS(v)   ((((reg32_t) v) << 29) & BM_USBC__PORTSC1UH2_STS)
#else
#define BF_USBC__PORTSC1UH2_STS(v)   (((v) << 29) & BM_USBC__PORTSC1UH2_STS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STS field to a new value.
#define BW_USBC__PORTSC1UH2_STS(v)   BF_CS1(USBC__PORTSC1UH2, STS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH2, field PTS1[31:30] (RW)
 *
 * Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the
 * configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is
 * selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If
 * VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30,
 * bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE =
 * 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 -
 * Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is
 * not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7;
 * For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver
 * Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3
 * core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b"
 * Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25,
 * bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only.
 * Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field
 * {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY
 * /IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register
 * bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For
 * Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}:
 * "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b"
 * HSIC All USB port interface modes are listed in this field description, but not all are
 * supported. For detail feature of each controller core, please see . The behaviour is unknown when
 * unsupported interface mode is selected.
 */

#define BP_USBC__PORTSC1UH2_PTS1      (30)
#define BM_USBC__PORTSC1UH2_PTS1      (0xc0000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH2_PTS1(v)   ((((reg32_t) v) << 30) & BM_USBC__PORTSC1UH2_PTS1)
#else
#define BF_USBC__PORTSC1UH2_PTS1(v)   (((v) << 30) & BM_USBC__PORTSC1UH2_PTS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS1 field to a new value.
#define BW_USBC__PORTSC1UH2_PTS1(v)   BF_CS1(USBC__PORTSC1UH2, PTS1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBMODEUH2 - USB Device Mode UH2 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CM : 2; //!< Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device only implementations. For those designs that contain both host & device capability, the controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. For combination host/device controllers, this register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core, reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
        unsigned ES : 1; //!< Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to match the host microprocessor. The bit fields in the microprocessor interface and the data structures are unaffected by the value of this bit because they are based upon the 32-bit word. Bit Meaning
        unsigned SLOM : 1; //!< Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
        unsigned SDIS : 1; //!< Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX and TX buffers are sufficient to contain an entire packet that the standard double buffering scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets received are responded to with a NYET handshake when stream disable is active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to characterize the adjustments needed for the scheduler when using this feature. The use of this feature substantially limits of the overall USB performance that can be achieved.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_usbc__usbmodeuh2_t;
#endif

/*
 * constants & macros for entire USBC__USBMODEUH2 register
 */
#define HW_USBC__USBMODEUH2_ADDR      (REGS_USBC_BASE + 0x5a8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBMODEUH2           (*(volatile hw_usbc__usbmodeuh2_t *) HW_USBC__USBMODEUH2_ADDR)
#define HW_USBC__USBMODEUH2_RD()      (HW_USBC__USBMODEUH2.U)
#define HW_USBC__USBMODEUH2_WR(v)     (HW_USBC__USBMODEUH2.U = (v))
#define HW_USBC__USBMODEUH2_SET(v)    (HW_USBC__USBMODEUH2_WR(HW_USBC__USBMODEUH2_RD() |  (v)))
#define HW_USBC__USBMODEUH2_CLR(v)    (HW_USBC__USBMODEUH2_WR(HW_USBC__USBMODEUH2_RD() & ~(v)))
#define HW_USBC__USBMODEUH2_TOG(v)    (HW_USBC__USBMODEUH2_WR(HW_USBC__USBMODEUH2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBMODEUH2 bitfields
 */

/* --- Register HW_USBC__USBMODEUH2, field CM[1:0] (RW)
 *
 * Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device
 * only implementations. For those designs that contain both host & device capability, the
 * controller defaults to an idle state and needs to be initialized to the desired operating mode
 * after reset. For combination host/device controllers, this register can only be written once
 * after reset. If it is necessary to switch modes, software must reset the controller by writing to
 * the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core,
 * reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
 *
 * Values:
 * 00 - Idle [Default for combination host/device]
 * 01 - Reserved
 * 10 - Device Controller [Default for device only controller]
 * 11 - Host Controller [Default for host only controller]
 */

#define BP_USBC__USBMODEUH2_CM      (0)
#define BM_USBC__USBMODEUH2_CM      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH2_CM(v)   ((((reg32_t) v) << 0) & BM_USBC__USBMODEUH2_CM)
#else
#define BF_USBC__USBMODEUH2_CM(v)   (((v) << 0) & BM_USBC__USBMODEUH2_CM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CM field to a new value.
#define BW_USBC__USBMODEUH2_CM(v)   BF_CS1(USBC__USBMODEUH2, CM, v)
#endif


/* --- Register HW_USBC__USBMODEUH2, field ES[2:2] (RW)
 *
 * Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to
 * match the host microprocessor. The bit fields in the microprocessor interface and the data
 * structures are unaffected by the value of this bit because they are based upon the 32-bit word.
 * Bit Meaning
 *
 * Values:
 * 0 - Little Endian [Default]
 * 1 - Big Endian
 */

#define BP_USBC__USBMODEUH2_ES      (2)
#define BM_USBC__USBMODEUH2_ES      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH2_ES(v)   ((((reg32_t) v) << 2) & BM_USBC__USBMODEUH2_ES)
#else
#define BF_USBC__USBMODEUH2_ES(v)   (((v) << 2) & BM_USBC__USBMODEUH2_ES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ES field to a new value.
#define BW_USBC__USBMODEUH2_ES(v)   BF_CS1(USBC__USBMODEUH2, ES, v)
#endif


/* --- Register HW_USBC__USBMODEUH2, field SLOM[3:3] (RW)
 *
 * Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
 *
 * Values:
 * 0 - Setup Lockouts On (default);
 * 1 - Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in .
 */

#define BP_USBC__USBMODEUH2_SLOM      (3)
#define BM_USBC__USBMODEUH2_SLOM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH2_SLOM(v)   ((((reg32_t) v) << 3) & BM_USBC__USBMODEUH2_SLOM)
#else
#define BF_USBC__USBMODEUH2_SLOM(v)   (((v) << 3) & BM_USBC__USBMODEUH2_SLOM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLOM field to a new value.
#define BW_USBC__USBMODEUH2_SLOM(v)   BF_CS1(USBC__USBMODEUH2, SLOM, v)
#endif


/* --- Register HW_USBC__USBMODEUH2, field SDIS[4:4] (RW)
 *
 * Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables
 * double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX
 * and TX buffers are sufficient to contain an entire packet that the standard double buffering
 * scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High
 * Speed Mode, all packets received are responded to with a NYET handshake when stream disable is
 * active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are
 * eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the
 * entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled
 * to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO
 * becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to
 * characterize the adjustments needed for the scheduler when using this feature. The use of this
 * feature substantially limits of the overall USB performance that can be achieved.
 */

#define BP_USBC__USBMODEUH2_SDIS      (4)
#define BM_USBC__USBMODEUH2_SDIS      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH2_SDIS(v)   ((((reg32_t) v) << 4) & BM_USBC__USBMODEUH2_SDIS)
#else
#define BF_USBC__USBMODEUH2_SDIS(v)   (((v) << 4) & BM_USBC__USBMODEUH2_SDIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SDIS field to a new value.
#define BW_USBC__USBMODEUH2_SDIS(v)   BF_CS1(USBC__USBMODEUH2, SDIS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IDUH3 - Identification register UH3 (RO)
 *
 * The ID register identifies the USB 2.0 OTG High-Speed core and its revision.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ID : 6; //!< Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG High-Speed core.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned NID : 6; //!< Complement version of ID
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned REVISION : 8; //!< Revision number of the controller core.
        unsigned RESERVED2 : 8; //!< Reserved
    } B;
} hw_usbc__iduh3_t;
#endif

/*
 * constants & macros for entire USBC__IDUH3 register
 */
#define HW_USBC__IDUH3_ADDR      (REGS_USBC_BASE + 0x600)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IDUH3           (*(volatile hw_usbc__iduh3_t *) HW_USBC__IDUH3_ADDR)
#define HW_USBC__IDUH3_RD()      (HW_USBC__IDUH3.U)
#endif

/*
 * constants & macros for individual USBC__IDUH3 bitfields
 */

/* --- Register HW_USBC__IDUH3, field ID[5:0] (RO)
 *
 * Configuration number. This number is set to 0x05 and indicates that the peripheral is USB 2.0 OTG
 * High-Speed core.
 */

#define BP_USBC__IDUH3_ID      (0)
#define BM_USBC__IDUH3_ID      (0x0000003f)

/* --- Register HW_USBC__IDUH3, field NID[13:8] (RO)
 *
 * Complement version of ID
 */

#define BP_USBC__IDUH3_NID      (8)
#define BM_USBC__IDUH3_NID      (0x00003f00)

/* --- Register HW_USBC__IDUH3, field REVISION[23:16] (RO)
 *
 * Revision number of the controller core.
 */

#define BP_USBC__IDUH3_REVISION      (16)
#define BM_USBC__IDUH3_REVISION      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWGENERALUH3 - Hardware General UH3 (RO)
 *
 * General hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned PHYW : 2; //!< Data width of the transciever connected to the controller core. For OTG controller core reset value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller core, reset value is '01b'.
        unsigned PHYM : 3; //!< Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'. For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '4h'.
        unsigned SM : 2; //!< Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3 controller core, reset value is '00b'.
        unsigned RESERVED1 : 21; //!< Reserved
    } B;
} hw_usbc__hwgeneraluh3_t;
#endif

/*
 * constants & macros for entire USBC__HWGENERALUH3 register
 */
#define HW_USBC__HWGENERALUH3_ADDR      (REGS_USBC_BASE + 0x604)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWGENERALUH3           (*(volatile hw_usbc__hwgeneraluh3_t *) HW_USBC__HWGENERALUH3_ADDR)
#define HW_USBC__HWGENERALUH3_RD()      (HW_USBC__HWGENERALUH3.U)
#endif

/*
 * constants & macros for individual USBC__HWGENERALUH3 bitfields
 */

/* --- Register HW_USBC__HWGENERALUH3, field PHYW[5:4] (RO)
 *
 * Data width of the transciever connected to the controller core. For OTG controller core reset
 * value is '11b'; For Host1/Host2/Host3 controller core, reset value is '00b'. For
 * OTG/Host1/Host2/Host3 controller core, reset value is '11b'. For OTG/Host1/Host2/Host3 controller
 * core, reset value is '01b'.
 *
 * Values:
 * 00 - 8 bit wide data bus [60MHz clock from the transciever]
 * 01 - 16 bit wide data bus [30MHZ clock from the transciever]
 * 10 - software programmable reset to 8-bit width
 * 11 - software programmable reset to 16-bit width
 */

#define BP_USBC__HWGENERALUH3_PHYW      (4)
#define BM_USBC__HWGENERALUH3_PHYW      (0x00000030)


/* --- Register HW_USBC__HWGENERALUH3, field PHYM[8:6] (RO)
 *
 * Transciever type For OTG/Host1/Host2/Host3 controller core, reset value is '7h'. For OTG
 * controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value is '7h'.
 * For OTG controller core, reset value is '0h'; For Host1/Host2/Host3 controller core, reset value
 * is '4h'.
 *
 * Values:
 * 000 - UTMI/UMTI+
 * 001 - ULPI DDR
 * 010 - ULPI
 * 011 - Serial Only
 * 100 - Software programmable - reset to UTMI/UTMI+
 * 101 - Software programmable - reset to ULPI DDR
 * 110 - Software programmable - reset to ULPI
 * 111 - Software programmable - reset to Serial
 * 1000 - IC-USB
 * 1001 - Software programmable - reset to IC-USB
 * 1010 - HSIC
 * 1011 - Software programmable - reset to HSIC
 */

#define BP_USBC__HWGENERALUH3_PHYM      (6)
#define BM_USBC__HWGENERALUH3_PHYM      (0x000001c0)


/* --- Register HW_USBC__HWGENERALUH3, field SM[10:9] (RO)
 *
 * Serial interface mode capability For OTG/Host1/Host2/Host3 controller core, reset value is '10b'.
 * For OTG/Host1/Host2/Host3 controller core, reset value is '10b'. For OTG/Host1/Host2/Host3
 * controller core, reset value is '00b'.
 *
 * Values:
 * 00 - No Serial Engine, always use parallel signalling.
 * 01 - Serial Engine present, always use serial signalling for FS/LS.
 * 10 - Software programmable - Reset to use parallel signalling for FS/LS
 * 11 - Software programmable - Reset to use serial signalling for FS/LS
 */

#define BP_USBC__HWGENERALUH3_SM      (9)
#define BM_USBC__HWGENERALUH3_SM      (0x00000600)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWHOSTUH3 - Host Hardware Parameters UH3 (RO)
 *
 * Host hardware parameters as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HC : 1; //!< Host Capable. All 4 controller cores support host operation mode.
        unsigned NPORT : 3; //!< The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller cores are single port, these bits are set to '000b'.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__hwhostuh3_t;
#endif

/*
 * constants & macros for entire USBC__HWHOSTUH3 register
 */
#define HW_USBC__HWHOSTUH3_ADDR      (REGS_USBC_BASE + 0x608)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWHOSTUH3           (*(volatile hw_usbc__hwhostuh3_t *) HW_USBC__HWHOSTUH3_ADDR)
#define HW_USBC__HWHOSTUH3_RD()      (HW_USBC__HWHOSTUH3.U)
#endif

/*
 * constants & macros for individual USBC__HWHOSTUH3 bitfields
 */

/* --- Register HW_USBC__HWHOSTUH3, field HC[0:0] (RO)
 *
 * Host Capable. All 4 controller cores support host operation mode.
 *
 * Values:
 * 0 - not support
 * 1 - support host operation mode
 */

#define BP_USBC__HWHOSTUH3_HC      (0)
#define BM_USBC__HWHOSTUH3_HC      (0x00000001)


/* --- Register HW_USBC__HWHOSTUH3, field NPORT[3:1] (RO)
 *
 * The Nmber of downstream ports supported by the host controller is NPORT+1. As all 4 controller
 * cores are single port, these bits are set to '000b'.
 */

#define BP_USBC__HWHOSTUH3_NPORT      (1)
#define BM_USBC__HWHOSTUH3_NPORT      (0x0000000e)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWTXBUFUH3 - TX Buffer Hardware Parameters UH3 (RO)
 *
 * TX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXBURST : 8; //!< Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned TXCHANADD : 8; //!< TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_usbc__hwtxbufuh3_t;
#endif

/*
 * constants & macros for entire USBC__HWTXBUFUH3 register
 */
#define HW_USBC__HWTXBUFUH3_ADDR      (REGS_USBC_BASE + 0x610)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWTXBUFUH3           (*(volatile hw_usbc__hwtxbufuh3_t *) HW_USBC__HWTXBUFUH3_ADDR)
#define HW_USBC__HWTXBUFUH3_RD()      (HW_USBC__HWTXBUFUH3.U)
#endif

/*
 * constants & macros for individual USBC__HWTXBUFUH3 bitfields
 */

/* --- Register HW_USBC__HWTXBUFUH3, field TXBURST[7:0] (RO)
 *
 * Default burst size for memory to TX buffer transfer. This is reset value of TXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWTXBUFUH3_TXBURST      (0)
#define BM_USBC__HWTXBUFUH3_TXBURST      (0x000000ff)

/* --- Register HW_USBC__HWTXBUFUH3, field TXCHANADD[23:16] (RO)
 *
 * TX Buffer size is: (2^TXCHANADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4
 * Bytes. For OTG controller core, there is one TX Buffer for each endpoint, so totally 8 TX
 * Buffers. For Host1/Host2/Host3 controller core, there is only one TX Buffer.
 */

#define BP_USBC__HWTXBUFUH3_TXCHANADD      (16)
#define BM_USBC__HWTXBUFUH3_TXCHANADD      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HWRXBUFUH3 - RX Buffer Hardware Parameters UH3 (RO)
 *
 * RX buffer hardware parameters are as defined in System Level Issues and Core Configuration.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXBURST : 8; //!< Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB core regsiter UOG_BURSTSIZE. Please see .
        unsigned RXADD : 8; //!< Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes. These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX Buffer.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usbc__hwrxbufuh3_t;
#endif

/*
 * constants & macros for entire USBC__HWRXBUFUH3 register
 */
#define HW_USBC__HWRXBUFUH3_ADDR      (REGS_USBC_BASE + 0x614)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HWRXBUFUH3           (*(volatile hw_usbc__hwrxbufuh3_t *) HW_USBC__HWRXBUFUH3_ADDR)
#define HW_USBC__HWRXBUFUH3_RD()      (HW_USBC__HWRXBUFUH3.U)
#endif

/*
 * constants & macros for individual USBC__HWRXBUFUH3 bitfields
 */

/* --- Register HW_USBC__HWRXBUFUH3, field RXBURST[7:0] (RO)
 *
 * Default burst size for memory to RX buffer transfer. This is reset value of RXPBURST bits in USB
 * core regsiter UOG_BURSTSIZE. Please see .
 */

#define BP_USBC__HWRXBUFUH3_RXBURST      (0)
#define BM_USBC__HWRXBUFUH3_RXBURST      (0x000000ff)

/* --- Register HW_USBC__HWRXBUFUH3, field RXADD[15:8] (RO)
 *
 * Buffer total size for all receive endpoints is (2^RXADD). RX Buffer size is: (2^RXADD) * 4 Bytes.
 * These bits are set to '08h', so buffer size is 256*4 Bytes. For OTG controller core, there is one
 * RX Buffer, shared by 8 Endpoints. For Host1/Host2/Host3 controller core, there is only one RX
 * Buffer.
 */

#define BP_USBC__HWRXBUFUH3_RXADD      (8)
#define BM_USBC__HWRXBUFUH3_RXADD      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0LDUH3 - General Purpose Timer #0 Load UH3 (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER0CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer0lduh3_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0LDUH3 register
 */
#define HW_USBC__GPTIMER0LDUH3_ADDR      (REGS_USBC_BASE + 0x680)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0LDUH3           (*(volatile hw_usbc__gptimer0lduh3_t *) HW_USBC__GPTIMER0LDUH3_ADDR)
#define HW_USBC__GPTIMER0LDUH3_RD()      (HW_USBC__GPTIMER0LDUH3.U)
#define HW_USBC__GPTIMER0LDUH3_WR(v)     (HW_USBC__GPTIMER0LDUH3.U = (v))
#define HW_USBC__GPTIMER0LDUH3_SET(v)    (HW_USBC__GPTIMER0LDUH3_WR(HW_USBC__GPTIMER0LDUH3_RD() |  (v)))
#define HW_USBC__GPTIMER0LDUH3_CLR(v)    (HW_USBC__GPTIMER0LDUH3_WR(HW_USBC__GPTIMER0LDUH3_RD() & ~(v)))
#define HW_USBC__GPTIMER0LDUH3_TOG(v)    (HW_USBC__GPTIMER0LDUH3_WR(HW_USBC__GPTIMER0LDUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0LDUH3 bitfields
 */

/* --- Register HW_USBC__GPTIMER0LDUH3, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER0LDUH3_GPTLD      (0)
#define BM_USBC__GPTIMER0LDUH3_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0LDUH3_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0LDUH3_GPTLD)
#else
#define BF_USBC__GPTIMER0LDUH3_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER0LDUH3_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER0LDUH3_GPTLD(v)   BF_CS1(USBC__GPTIMER0LDUH3, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER0CTRLUH3 - General Purpose Timer #0 Controller UH3 (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI0 bit in n_USBSTS register (See ), interrupt enable bit is
 * TIE0 bit in n_USBINTR register. (See .)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer0ctrluh3_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER0CTRLUH3 register
 */
#define HW_USBC__GPTIMER0CTRLUH3_ADDR      (REGS_USBC_BASE + 0x684)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER0CTRLUH3           (*(volatile hw_usbc__gptimer0ctrluh3_t *) HW_USBC__GPTIMER0CTRLUH3_ADDR)
#define HW_USBC__GPTIMER0CTRLUH3_RD()      (HW_USBC__GPTIMER0CTRLUH3.U)
#define HW_USBC__GPTIMER0CTRLUH3_WR(v)     (HW_USBC__GPTIMER0CTRLUH3.U = (v))
#define HW_USBC__GPTIMER0CTRLUH3_SET(v)    (HW_USBC__GPTIMER0CTRLUH3_WR(HW_USBC__GPTIMER0CTRLUH3_RD() |  (v)))
#define HW_USBC__GPTIMER0CTRLUH3_CLR(v)    (HW_USBC__GPTIMER0CTRLUH3_WR(HW_USBC__GPTIMER0CTRLUH3_RD() & ~(v)))
#define HW_USBC__GPTIMER0CTRLUH3_TOG(v)    (HW_USBC__GPTIMER0CTRLUH3_WR(HW_USBC__GPTIMER0CTRLUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER0CTRLUH3 bitfields
 */

/* --- Register HW_USBC__GPTIMER0CTRLUH3, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER0CTRLUH3_GPTCNT      (0)
#define BM_USBC__GPTIMER0CTRLUH3_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH3_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER0CTRLUH3_GPTCNT)
#else
#define BF_USBC__GPTIMER0CTRLUH3_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER0CTRLUH3_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER0CTRLUH3_GPTCNT(v)   BF_CS1(USBC__GPTIMER0CTRLUH3, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER0CTRLUH3, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software; In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER0CTRLUH3_GPTMODE      (24)
#define BM_USBC__GPTIMER0CTRLUH3_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH3_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER0CTRLUH3_GPTMODE)
#else
#define BF_USBC__GPTIMER0CTRLUH3_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER0CTRLUH3_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER0CTRLUH3_GPTMODE(v)   BF_CS1(USBC__GPTIMER0CTRLUH3, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUH3, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in n_GPTIMER0LD
 */

#define BP_USBC__GPTIMER0CTRLUH3_GPTRST      (30)
#define BM_USBC__GPTIMER0CTRLUH3_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH3_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER0CTRLUH3_GPTRST)
#else
#define BF_USBC__GPTIMER0CTRLUH3_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER0CTRLUH3_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER0CTRLUH3_GPTRST(v)   BF_CS1(USBC__GPTIMER0CTRLUH3, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER0CTRLUH3, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER0CTRLUH3_GPTRUN      (31)
#define BM_USBC__GPTIMER0CTRLUH3_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER0CTRLUH3_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER0CTRLUH3_GPTRUN)
#else
#define BF_USBC__GPTIMER0CTRLUH3_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER0CTRLUH3_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER0CTRLUH3_GPTRUN(v)   BF_CS1(USBC__GPTIMER0CTRLUH3, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1LDUH3 - General Purpose Timer #1 Load UH3 (RW)
 *
 * This register controls load value of the count timer in register n_GPTIMER1CTRL. Please see .
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTLD : 24; //!< General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example: for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215 seconds.
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_usbc__gptimer1lduh3_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1LDUH3 register
 */
#define HW_USBC__GPTIMER1LDUH3_ADDR      (REGS_USBC_BASE + 0x688)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1LDUH3           (*(volatile hw_usbc__gptimer1lduh3_t *) HW_USBC__GPTIMER1LDUH3_ADDR)
#define HW_USBC__GPTIMER1LDUH3_RD()      (HW_USBC__GPTIMER1LDUH3.U)
#define HW_USBC__GPTIMER1LDUH3_WR(v)     (HW_USBC__GPTIMER1LDUH3.U = (v))
#define HW_USBC__GPTIMER1LDUH3_SET(v)    (HW_USBC__GPTIMER1LDUH3_WR(HW_USBC__GPTIMER1LDUH3_RD() |  (v)))
#define HW_USBC__GPTIMER1LDUH3_CLR(v)    (HW_USBC__GPTIMER1LDUH3_WR(HW_USBC__GPTIMER1LDUH3_RD() & ~(v)))
#define HW_USBC__GPTIMER1LDUH3_TOG(v)    (HW_USBC__GPTIMER1LDUH3_WR(HW_USBC__GPTIMER1LDUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1LDUH3 bitfields
 */

/* --- Register HW_USBC__GPTIMER1LDUH3, field GPTLD[23:0] (RW)
 *
 * General Purpose Timer Load Value These bit fields are loaded to GPTCNT bits when GPTRST bit is
 * set '1b'. This value represents the time in microseconds minus 1 for the timer duration. Example:
 * for a one millisecond timer, load 1000-1=999 or 0x0003E7. Max value is 0xFFFFFF or 16.777215
 * seconds.
 */

#define BP_USBC__GPTIMER1LDUH3_GPTLD      (0)
#define BM_USBC__GPTIMER1LDUH3_GPTLD      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1LDUH3_GPTLD(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1LDUH3_GPTLD)
#else
#define BF_USBC__GPTIMER1LDUH3_GPTLD(v)   (((v) << 0) & BM_USBC__GPTIMER1LDUH3_GPTLD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTLD field to a new value.
#define BW_USBC__GPTIMER1LDUH3_GPTLD(v)   BF_CS1(USBC__GPTIMER1LDUH3, GPTLD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__GPTIMER1CTRLUH3 - General Purpose Timer #1 Controller UH3 (RW)
 *
 * This register contains the control for this countdown timer and a data field can be queried to
 * determine the running count value. This timer has granularity on 1 us and can be programmed to a
 * little over 16 seconds. There are two counter modes which are described in the register table
 * below. When the timer counter value transitions to zero, an interrupt could be generated if
 * enable.  Interrupt status bit is TI1 bit in UOG_USBSTS register (See ), interrupt enable bit is
 * TIE1 bit in n_USBINTR register (See ).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPTCNT : 24; //!< General Purpose Timer Counter. This field is the count value of the countdown timer.
        unsigned GPTMODE : 1; //!< General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to start again.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned GPTRST : 1; //!< General Purpose Timer Reset
        unsigned GPTRUN : 1; //!< General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
    } B;
} hw_usbc__gptimer1ctrluh3_t;
#endif

/*
 * constants & macros for entire USBC__GPTIMER1CTRLUH3 register
 */
#define HW_USBC__GPTIMER1CTRLUH3_ADDR      (REGS_USBC_BASE + 0x68c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__GPTIMER1CTRLUH3           (*(volatile hw_usbc__gptimer1ctrluh3_t *) HW_USBC__GPTIMER1CTRLUH3_ADDR)
#define HW_USBC__GPTIMER1CTRLUH3_RD()      (HW_USBC__GPTIMER1CTRLUH3.U)
#define HW_USBC__GPTIMER1CTRLUH3_WR(v)     (HW_USBC__GPTIMER1CTRLUH3.U = (v))
#define HW_USBC__GPTIMER1CTRLUH3_SET(v)    (HW_USBC__GPTIMER1CTRLUH3_WR(HW_USBC__GPTIMER1CTRLUH3_RD() |  (v)))
#define HW_USBC__GPTIMER1CTRLUH3_CLR(v)    (HW_USBC__GPTIMER1CTRLUH3_WR(HW_USBC__GPTIMER1CTRLUH3_RD() & ~(v)))
#define HW_USBC__GPTIMER1CTRLUH3_TOG(v)    (HW_USBC__GPTIMER1CTRLUH3_WR(HW_USBC__GPTIMER1CTRLUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__GPTIMER1CTRLUH3 bitfields
 */

/* --- Register HW_USBC__GPTIMER1CTRLUH3, field GPTCNT[23:0] (RW)
 *
 * General Purpose Timer Counter. This field is the count value of the countdown timer.
 */

#define BP_USBC__GPTIMER1CTRLUH3_GPTCNT      (0)
#define BM_USBC__GPTIMER1CTRLUH3_GPTCNT      (0x00ffffff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH3_GPTCNT(v)   ((((reg32_t) v) << 0) & BM_USBC__GPTIMER1CTRLUH3_GPTCNT)
#else
#define BF_USBC__GPTIMER1CTRLUH3_GPTCNT(v)   (((v) << 0) & BM_USBC__GPTIMER1CTRLUH3_GPTCNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTCNT field to a new value.
#define BW_USBC__GPTIMER1CTRLUH3_GPTCNT(v)   BF_CS1(USBC__GPTIMER1CTRLUH3, GPTCNT, v)
#endif

/* --- Register HW_USBC__GPTIMER1CTRLUH3, field GPTMODE[24:24] (RW)
 *
 * General Purpose Timer Mode In one shot mode, the timer will count down to zero, generate an
 * interrupt, and stop until the counter is reset by software. In repeat mode, the timer will count
 * down to zero, generate an interrupt and automatically reload the counter value from GPTLD bits to
 * start again.
 *
 * Values:
 * 0 - One Shot Mode
 * 1 - Repeat Mode
 */

#define BP_USBC__GPTIMER1CTRLUH3_GPTMODE      (24)
#define BM_USBC__GPTIMER1CTRLUH3_GPTMODE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH3_GPTMODE(v)   ((((reg32_t) v) << 24) & BM_USBC__GPTIMER1CTRLUH3_GPTMODE)
#else
#define BF_USBC__GPTIMER1CTRLUH3_GPTMODE(v)   (((v) << 24) & BM_USBC__GPTIMER1CTRLUH3_GPTMODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTMODE field to a new value.
#define BW_USBC__GPTIMER1CTRLUH3_GPTMODE(v)   BF_CS1(USBC__GPTIMER1CTRLUH3, GPTMODE, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUH3, field GPTRST[30:30] (RW)
 *
 * General Purpose Timer Reset
 *
 * Values:
 * 0 - No action
 * 1 - Load counter value from GPTLD bits in UOG_GPTIMER0LD
 */

#define BP_USBC__GPTIMER1CTRLUH3_GPTRST      (30)
#define BM_USBC__GPTIMER1CTRLUH3_GPTRST      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH3_GPTRST(v)   ((((reg32_t) v) << 30) & BM_USBC__GPTIMER1CTRLUH3_GPTRST)
#else
#define BF_USBC__GPTIMER1CTRLUH3_GPTRST(v)   (((v) << 30) & BM_USBC__GPTIMER1CTRLUH3_GPTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRST field to a new value.
#define BW_USBC__GPTIMER1CTRLUH3_GPTRST(v)   BF_CS1(USBC__GPTIMER1CTRLUH3, GPTRST, v)
#endif


/* --- Register HW_USBC__GPTIMER1CTRLUH3, field GPTRUN[31:31] (RW)
 *
 * General Purpose Timer Run GPTCNT bits are not effected when setting or clearing this bit.
 *
 * Values:
 * 0 - Stop counting
 * 1 - Run
 */

#define BP_USBC__GPTIMER1CTRLUH3_GPTRUN      (31)
#define BM_USBC__GPTIMER1CTRLUH3_GPTRUN      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__GPTIMER1CTRLUH3_GPTRUN(v)   ((((reg32_t) v) << 31) & BM_USBC__GPTIMER1CTRLUH3_GPTRUN)
#else
#define BF_USBC__GPTIMER1CTRLUH3_GPTRUN(v)   (((v) << 31) & BM_USBC__GPTIMER1CTRLUH3_GPTRUN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GPTRUN field to a new value.
#define BW_USBC__GPTIMER1CTRLUH3_GPTRUN(v)   BF_CS1(USBC__GPTIMER1CTRLUH3, GPTRUN, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__SBUSCFGUH3 - System Bus Config UH3 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned AHBBRST : 3; //!< AHB master interface Burst configuration These bits controls AHB master transfer type sequence (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_usbc__sbuscfguh3_t;
#endif

/*
 * constants & macros for entire USBC__SBUSCFGUH3 register
 */
#define HW_USBC__SBUSCFGUH3_ADDR      (REGS_USBC_BASE + 0x690)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__SBUSCFGUH3           (*(volatile hw_usbc__sbuscfguh3_t *) HW_USBC__SBUSCFGUH3_ADDR)
#define HW_USBC__SBUSCFGUH3_RD()      (HW_USBC__SBUSCFGUH3.U)
#define HW_USBC__SBUSCFGUH3_WR(v)     (HW_USBC__SBUSCFGUH3.U = (v))
#define HW_USBC__SBUSCFGUH3_SET(v)    (HW_USBC__SBUSCFGUH3_WR(HW_USBC__SBUSCFGUH3_RD() |  (v)))
#define HW_USBC__SBUSCFGUH3_CLR(v)    (HW_USBC__SBUSCFGUH3_WR(HW_USBC__SBUSCFGUH3_RD() & ~(v)))
#define HW_USBC__SBUSCFGUH3_TOG(v)    (HW_USBC__SBUSCFGUH3_WR(HW_USBC__SBUSCFGUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__SBUSCFGUH3 bitfields
 */

/* --- Register HW_USBC__SBUSCFGUH3, field AHBBRST[2:0] (RW)
 *
 * AHB master interface Burst configuration These bits controls AHB master transfer type sequence
 * (or priority). This register overrides n_BURSTSIZE register when its value is not zero.
 *
 * Values:
 * 000 - Incremental burst of unspecified length only
 * 001 - INCR4 burst, then single transfer
 * 010 - INCR8 burst, INCR4 burst, then single transfer
 * 011 - INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 * 100 - Reserved, don't use
 * 101 - INCR4 burst, then incremental burst of unspecified length
 * 110 - INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 * 111 - INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */

#define BP_USBC__SBUSCFGUH3_AHBBRST      (0)
#define BM_USBC__SBUSCFGUH3_AHBBRST      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__SBUSCFGUH3_AHBBRST(v)   ((((reg32_t) v) << 0) & BM_USBC__SBUSCFGUH3_AHBBRST)
#else
#define BF_USBC__SBUSCFGUH3_AHBBRST(v)   (((v) << 0) & BM_USBC__SBUSCFGUH3_AHBBRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AHBBRST field to a new value.
#define BW_USBC__SBUSCFGUH3_AHBBRST(v)   BF_CS1(USBC__SBUSCFGUH3, AHBBRST, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__CAPLENGTHUH3 - Capability Register Length UH3 (RO)
 *
 * The following figure Capability Register Length (n_CAPLENGTH) indicates the offset that should be
 * added to the register base address at the beginning of the Operational Register.
 */
typedef union
{
    reg8_t U;
    struct
    {
        unsigned char CAPLENGTH : 8; //!< These bits are used as an offset to add to register base to find the beginning of the Operational Register. Default value is '40h'.
    } B;
} hw_usbc__caplengthuh3_t;
#endif

/*
 * constants & macros for entire USBC__CAPLENGTHUH3 register
 */
#define HW_USBC__CAPLENGTHUH3_ADDR      (REGS_USBC_BASE + 0x700)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__CAPLENGTHUH3           (*(volatile hw_usbc__caplengthuh3_t *) HW_USBC__CAPLENGTHUH3_ADDR)
#define HW_USBC__CAPLENGTHUH3_RD()      (HW_USBC__CAPLENGTHUH3.U)
#endif

/*
 * constants & macros for individual USBC__CAPLENGTHUH3 bitfields
 */

/* --- Register HW_USBC__CAPLENGTHUH3, field CAPLENGTH[7:0] (RO)
 *
 * These bits are used as an offset to add to register base to find the beginning of the Operational
 * Register. Default value is '40h'.
 */

#define BP_USBC__CAPLENGTHUH3_CAPLENGTH      (0)
#define BM_USBC__CAPLENGTHUH3_CAPLENGTH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCIVERSIONUH3 - Host Controller Interface Version UH3 (RO)
 *
 * The following figure shows the Host Interface version number (n_HCIVERSION), which is a 2-byte
 * register containing a BCD encoding of the EHCI revision number supported by this host controller.
 * The most significant byte of this register represents a major revision and the least significant
 * byte is the minor revision.
 */
typedef union
{
    reg16_t U;
    struct
    {
        unsigned short HCIVERSION : 16; //!< Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
    } B;
} hw_usbc__hciversionuh3_t;
#endif

/*
 * constants & macros for entire USBC__HCIVERSIONUH3 register
 */
#define HW_USBC__HCIVERSIONUH3_ADDR      (REGS_USBC_BASE + 0x702)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCIVERSIONUH3           (*(volatile hw_usbc__hciversionuh3_t *) HW_USBC__HCIVERSIONUH3_ADDR)
#define HW_USBC__HCIVERSIONUH3_RD()      (HW_USBC__HCIVERSIONUH3.U)
#endif

/*
 * constants & macros for individual USBC__HCIVERSIONUH3 bitfields
 */

/* --- Register HW_USBC__HCIVERSIONUH3, field HCIVERSION[15:0] (RO)
 *
 * Host Controller Interface Version Number Default value is '10h', which means EHCI rev1.0.
 */

#define BP_USBC__HCIVERSIONUH3_HCIVERSION      (0)
#define BM_USBC__HCIVERSIONUH3_HCIVERSION      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCSPARAMSUH3 - Host Controller Structural Parameters UH3 (RO)
 *
 * The following figure shows the port steering logic capabilities of Host Control Structural
 * Parameters (n_HCSPARAMS).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned N_PORTS : 4; //!< Number of downstream ports. This field specifies the number of physical downstream ports implemented on this host controller. The value of this field determines how many port registers are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in this field is undefined. These bits are always set to '0001b' because all 4 controller cores are Single-Port Host.
        unsigned PPC : 1; //!< Port Power Control This field indicates whether the host controller implementation includes port power control. A one indicates the ports have port power switches. A zero indicates the ports do not have port power switches. The value of this field affects the functionality of the Port Power field in each port status and control register
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned N_PCC : 4; //!< Number of Ports per Companion Controller This field indicates the number of ports supported per internal Companion Controller. It is used to indicate the port routing configuration to the system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and the last two are routed to companion controller 2. The number in this field must be consistent with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
        unsigned N_CC : 4; //!< Number of Companion Controller (N_CC). This field indicates the number of companion controllers associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
        unsigned PI : 1; //!< Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator control. When set to one, the port status and control registers include a read/writeable field for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned N_PTT : 4; //!< Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates the number of ports assigned to each transaction translator within the USB2.0 host controller. These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned N_TT : 4; //!< Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number of embedded transaction translators associated with the USB2.0 host controller. These bits would be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
        unsigned RESERVED2 : 4; //!< Reserved
    } B;
} hw_usbc__hcsparamsuh3_t;
#endif

/*
 * constants & macros for entire USBC__HCSPARAMSUH3 register
 */
#define HW_USBC__HCSPARAMSUH3_ADDR      (REGS_USBC_BASE + 0x704)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCSPARAMSUH3           (*(volatile hw_usbc__hcsparamsuh3_t *) HW_USBC__HCSPARAMSUH3_ADDR)
#define HW_USBC__HCSPARAMSUH3_RD()      (HW_USBC__HCSPARAMSUH3.U)
#endif

/*
 * constants & macros for individual USBC__HCSPARAMSUH3 bitfields
 */

/* --- Register HW_USBC__HCSPARAMSUH3, field N_PORTS[3:0] (RO)
 *
 * Number of downstream ports. This field specifies the number of physical downstream ports
 * implemented on this host controller. The value of this field determines how many port registers
 * are addressable in the Operational Register. Valid values are in the range of 1h to Fh. A zero in
 * this field is undefined. These bits are always set to '0001b' because all 4 controller cores are
 * Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH3_N_PORTS      (0)
#define BM_USBC__HCSPARAMSUH3_N_PORTS      (0x0000000f)

/* --- Register HW_USBC__HCSPARAMSUH3, field PPC[4:4] (RO)
 *
 * Port Power Control This field indicates whether the host controller implementation includes port
 * power control. A one indicates the ports have port power switches. A zero indicates the ports do
 * not have port power switches. The value of this field affects the functionality of the Port Power
 * field in each port status and control register
 */

#define BP_USBC__HCSPARAMSUH3_PPC      (4)
#define BM_USBC__HCSPARAMSUH3_PPC      (0x00000010)

/* --- Register HW_USBC__HCSPARAMSUH3, field N_PCC[11:8] (RO)
 *
 * Number of Ports per Companion Controller This field indicates the number of ports supported per
 * internal Companion Controller. It is used to indicate the port routing configuration to the
 * system software. For example, if N_PORTS has a value of 6 and N_CC has a value of 2 then N_PCC
 * could have a value of 3. The convention is that the first N_PCC ports are assumed to be routed to
 * companion controller 1, the next N_PCC ports to companion controller 2, etc. In the previous
 * example, the N_PCC could have been 4, where the first 4 are routed to companion controller 1 and
 * the last two are routed to companion controller 2. The number in this field must be consistent
 * with N_PORTS and N_CC. These bits are '0000b' in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUH3_N_PCC      (8)
#define BM_USBC__HCSPARAMSUH3_N_PCC      (0x00000f00)

/* --- Register HW_USBC__HCSPARAMSUH3, field N_CC[15:12] (RO)
 *
 * Number of Companion Controller (N_CC). This field indicates the number of companion controllers
 * associated with this USB2.0 host controller. These bits are '0000b' in all 4 controller core.
 *
 * Values:
 * 0 - There is no internal Companion Controller and port-ownership hand-off is not supported.
 * 1 - There are internal companion controller(s) and port-ownership hand-offs is supported.
 */

#define BP_USBC__HCSPARAMSUH3_N_CC      (12)
#define BM_USBC__HCSPARAMSUH3_N_CC      (0x0000f000)


/* --- Register HW_USBC__HCSPARAMSUH3, field PI[16:16] (RO)
 *
 * Port Indicators (P INDICATOR) This bit indicates whether the ports support port indicator
 * control. When set to one, the port status and control registers include a read/writeable field
 * for controlling the state of the port indicator This bit is "1b" in all 4 controller core.
 */

#define BP_USBC__HCSPARAMSUH3_PI      (16)
#define BM_USBC__HCSPARAMSUH3_PI      (0x00010000)

/* --- Register HW_USBC__HCSPARAMSUH3, field N_PTT[23:20] (RO)
 *
 * Number of Ports per Transaction Translator (N_PTT). Default value '0000b' This field indicates
 * the number of ports assigned to each transaction translator within the USB2.0 host controller.
 * These bits would be set to equal N_PORTS for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH3_N_PTT      (20)
#define BM_USBC__HCSPARAMSUH3_N_PTT      (0x00f00000)

/* --- Register HW_USBC__HCSPARAMSUH3, field N_TT[27:24] (RO)
 *
 * Number of Transaction Translators (N_TT). Default value '0000b' This field indicates the number
 * of embedded transaction translators associated with the USB2.0 host controller. These bits would
 * be set to '0001b' for Multi-Port Host, and '0000b' for Single-Port Host.
 */

#define BP_USBC__HCSPARAMSUH3_N_TT      (24)
#define BM_USBC__HCSPARAMSUH3_N_TT      (0x0f000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__HCCPARAMSUH3 - Host Controller Capability Parameters UH3 (RO)
 *
 * This register identifies multiple mode control (time-base bit functionality), addressing
 * capability.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADC : 1; //!< 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing capability is supported.
        unsigned PFL : 1; //!< Programmable Frame List Flag If this bit is set to zero, then the system software must use a frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size field is a read-only register and must be set to zero. If set to a one, then the system software can specify and use a smaller frame list and configure the host controller via the USBCMD register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in all 4 controller core.
        unsigned ASP : 1; //!< Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is set '1b' in all 4 controller core.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned IST : 4; //!< Isochronous Scheduling Threshold. This field indicates, relative to the current position of the executing host controller, where software can reliably update the isochronous schedule. When bit [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a host controller can hold a set of isochronous data structures (one or more) before flushing the state. When bit [7] is a one, then host software assumes the host controller may cache an isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller core.
        unsigned EECP : 8; //!< EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A value of 00h indicates no extended capabilities are implemented. A non-zero value in this register indicates the offset in PCI configuration space of the first EHCI extended capability. The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI header defined for this class of device. These bits are set '00h' in all 4 controller core.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_usbc__hccparamsuh3_t;
#endif

/*
 * constants & macros for entire USBC__HCCPARAMSUH3 register
 */
#define HW_USBC__HCCPARAMSUH3_ADDR      (REGS_USBC_BASE + 0x708)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__HCCPARAMSUH3           (*(volatile hw_usbc__hccparamsuh3_t *) HW_USBC__HCCPARAMSUH3_ADDR)
#define HW_USBC__HCCPARAMSUH3_RD()      (HW_USBC__HCCPARAMSUH3.U)
#endif

/*
 * constants & macros for individual USBC__HCCPARAMSUH3 bitfields
 */

/* --- Register HW_USBC__HCCPARAMSUH3, field ADC[0:0] (RO)
 *
 * 64-bit Addressing Capability This bit is set '0b' in all 4 controller core, no 64-bit addressing
 * capability is supported.
 */

#define BP_USBC__HCCPARAMSUH3_ADC      (0)
#define BM_USBC__HCCPARAMSUH3_ADC      (0x00000001)

/* --- Register HW_USBC__HCCPARAMSUH3, field PFL[1:1] (RO)
 *
 * Programmable Frame List Flag If this bit is set to zero, then the system software must use a
 * frame list length of 1024 elements with this host controller. The USBCMD register Frame List Size
 * field is a read-only register and must be set to zero. If set to a one, then the system software
 * can specify and use a smaller frame list and configure the host controller via the USBCMD
 * register Frame List Size field. The frame list must always be aligned on a 4K-page boundary. This
 * requirement ensures that the frame list is always physically contiguous. This bit is set '1b' in
 * all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH3_PFL      (1)
#define BM_USBC__HCCPARAMSUH3_PFL      (0x00000002)

/* --- Register HW_USBC__HCCPARAMSUH3, field ASP[2:2] (RO)
 *
 * Asynchronous Schedule Park Capability If this bit is set to a one, then the host controller
 * supports the park feature for high-speed queue heads in the Asynchronous Schedule. The feature
 * can be disabled or enabled and set to a specific level by using the Asynchronous Schedule Park
 * Mode Enable and Asynchronous Schedule Park Mode Count fields in the USBCMD register. This bit is
 * set '1b' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH3_ASP      (2)
#define BM_USBC__HCCPARAMSUH3_ASP      (0x00000004)

/* --- Register HW_USBC__HCCPARAMSUH3, field IST[7:4] (RO)
 *
 * Isochronous Scheduling Threshold. This field indicates, relative to the current position of the
 * executing host controller, where software can reliably update the isochronous schedule. When bit
 * [7] is zero, the value of the least significant 3 bits indicates the number of micro-frames a
 * host controller can hold a set of isochronous data structures (one or more) before flushing the
 * state. When bit [7] is a one, then host software assumes the host controller may cache an
 * isochronous data structure for an entire frame. These bits are set '00h' in all 4 controller
 * core.
 */

#define BP_USBC__HCCPARAMSUH3_IST      (4)
#define BM_USBC__HCCPARAMSUH3_IST      (0x000000f0)

/* --- Register HW_USBC__HCCPARAMSUH3, field EECP[15:8] (RO)
 *
 * EHCI Extended Capabilities Pointer. This field indicates the existence of a capabilities list. A
 * value of 00h indicates no extended capabilities are implemented. A non-zero value in this
 * register indicates the offset in PCI configuration space of the first EHCI extended capability.
 * The pointer value must be 40h or greater if implemented to maintain the consistency of the PCI
 * header defined for this class of device. These bits are set '00h' in all 4 controller core.
 */

#define BP_USBC__HCCPARAMSUH3_EECP      (8)
#define BM_USBC__HCCPARAMSUH3_EECP      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBCMDUH3 - USB Command Register UH3 (RW)
 *
 * The Command Register indicates the command to be executed by the serial bus host/device
 * controller. Writing to the register causes a command to be executed.  *: ASPE,ASP[1],ASP[0] reset
 * value: '0b' for OTG core; '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RS : 1; //!< Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the Controller proceeds with the execution of the schedule. The Controller continues execution as long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the current transaction on the USB and then halts. The HC Halted bit in the status register indicates when the Controller has finished the transaction and has entered the stopped state. Software should not write a one to this field unless the controller is in the Halted state (that is, HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is not directly connected to the pull-up enable, as the pull-up will become disabled upon transitioning into high-speed mode. Software should use this bit to prevent an attach event before the controller has been properly initialized. Writing a 0 to this will cause a detach event.
        unsigned RST : 1; //!< Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit is set to zero by the Host/Device Controller when the reset process is complete. Software cannot terminate the reset process early by writing a zero to this register. Host operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Any transaction currently in progress on USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset an actively running host controller will result in undefined behavior. Device operation mode: When software writes a one to this bit, the Controller resets its internal pipelines, timers, counters, state machines etc. to their initial value. Writing a one to this bit when the device is in the attached state is not recommended, because the effect on an attached host is undefined. In order to ensure that the device is not in an attached state before initiating a device controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be set to 0.
        unsigned FS : 2; //!< See description at bit 15
        unsigned PSE : 1; //!< Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
        unsigned ASE : 1; //!< Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host controller skips processing the Asynchronous Schedule. Only the host controller uses this bit. Values Meaning
        unsigned IAA : 1; //!< Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to tell the host controller to issue an interrupt the next time it advances asynchronous schedule. Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then the host controller will assert an interrupt at the next interrupt threshold. The host controller sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS register to one. Software should not write a one to this bit when the asynchronous schedule is inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a one to this bit when device mode is selected will have undefined results.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ASP : 2; //!< Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults to zero and is Read-Only. It contains a count of the number of successive transactions the host controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not write a zero to this bit when Park Mode Enable is a one as this will result in undefined behavior. This field is set to 3h in all 4 controller core.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ASPE : 1; //!< Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to '1b' in this implementation.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned SUTW : 1; //!< Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a hazard when new setup data arrives while the DCD is copying the setup data payload from the QH for a previous setup packet. This bit is set and cleared by software. This bit would also be cleared by hardware when a hazard detected. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned ATDTW : 1; //!< Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and cleared by software. This bit would also be cleared by hardware when state machine is hazard region for which adding a dTD to a primed endpoint may go unrecognized. For more information on the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
        unsigned FS1 : 1; //!< See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This field specifies the size of the frame list that controls which bits in the Frame Index Register should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and 2. Value Meaning
        unsigned ITC : 8; //!< Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum rate at which the host/device controller will issue interrupts. ITC contains the maximum interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum Interrupt Interval
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_usbc__usbcmduh3_t;
#endif

/*
 * constants & macros for entire USBC__USBCMDUH3 register
 */
#define HW_USBC__USBCMDUH3_ADDR      (REGS_USBC_BASE + 0x740)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBCMDUH3           (*(volatile hw_usbc__usbcmduh3_t *) HW_USBC__USBCMDUH3_ADDR)
#define HW_USBC__USBCMDUH3_RD()      (HW_USBC__USBCMDUH3.U)
#define HW_USBC__USBCMDUH3_WR(v)     (HW_USBC__USBCMDUH3.U = (v))
#define HW_USBC__USBCMDUH3_SET(v)    (HW_USBC__USBCMDUH3_WR(HW_USBC__USBCMDUH3_RD() |  (v)))
#define HW_USBC__USBCMDUH3_CLR(v)    (HW_USBC__USBCMDUH3_WR(HW_USBC__USBCMDUH3_RD() & ~(v)))
#define HW_USBC__USBCMDUH3_TOG(v)    (HW_USBC__USBCMDUH3_WR(HW_USBC__USBCMDUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBCMDUH3 bitfields
 */

/* --- Register HW_USBC__USBCMDUH3, field RS[0:0] (RW)
 *
 * Run/Stop (RS) - Read/Write. Default 0b. 1=Run. 0=Stop. Host operation mode: When set to '1b', the
 * Controller proceeds with the execution of the schedule. The Controller continues execution as
 * long as this bit is set to a one. When this bit is set to 0, the Host Controller completes the
 * current transaction on the USB and then halts. The HC Halted bit in the status register indicates
 * when the Controller has finished the transaction and has entered the stopped state. Software
 * should not write a one to this field unless the controller is in the Halted state (that is,
 * HCHalted in the USBSTS register is a one). Device operation mode: Writing a one to this bit will
 * cause the controller to enable a pull-up on D+ and initiate an attach event. This control bit is
 * not directly connected to the pull-up enable, as the pull-up will become disabled upon
 * transitioning into high-speed mode. Software should use this bit to prevent an attach event
 * before the controller has been properly initialized. Writing a 0 to this will cause a detach
 * event.
 */

#define BP_USBC__USBCMDUH3_RS      (0)
#define BM_USBC__USBCMDUH3_RS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_RS(v)   ((((reg32_t) v) << 0) & BM_USBC__USBCMDUH3_RS)
#else
#define BF_USBC__USBCMDUH3_RS(v)   (((v) << 0) & BM_USBC__USBCMDUH3_RS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RS field to a new value.
#define BW_USBC__USBCMDUH3_RS(v)   BF_CS1(USBC__USBCMDUH3, RS, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field RST[1:1] (RW)
 *
 * Controller Reset (RESET) - Read/Write. Software uses this bit to reset the controller. This bit
 * is set to zero by the Host/Device Controller when the reset process is complete. Software cannot
 * terminate the reset process early by writing a zero to this register. Host operation mode: When
 * software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Any transaction currently in progress on
 * USB is immediately terminated. A USB reset is not driven on downstream ports. Software should not
 * set this bit to a one when the HCHalted bit in the USBSTS register is a zero. Attempting to reset
 * an actively running host controller will result in undefined behavior. Device operation mode:
 * When software writes a one to this bit, the Controller resets its internal pipelines, timers,
 * counters, state machines etc. to their initial value. Writing a one to this bit when the device
 * is in the attached state is not recommended, because the effect on an attached host is undefined.
 * In order to ensure that the device is not in an attached state before initiating a device
 * controller reset, all primed endpoints should be flushed and the USBCMD Run/Stop bit should be
 * set to 0.
 */

#define BP_USBC__USBCMDUH3_RST      (1)
#define BM_USBC__USBCMDUH3_RST      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_RST(v)   ((((reg32_t) v) << 1) & BM_USBC__USBCMDUH3_RST)
#else
#define BF_USBC__USBCMDUH3_RST(v)   (((v) << 1) & BM_USBC__USBCMDUH3_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RST field to a new value.
#define BW_USBC__USBCMDUH3_RST(v)   BF_CS1(USBC__USBCMDUH3, RST, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field FS[3:2] (RW)
 *
 * See description at bit 15
 */

#define BP_USBC__USBCMDUH3_FS      (2)
#define BM_USBC__USBCMDUH3_FS      (0x0000000c)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_FS(v)   ((((reg32_t) v) << 2) & BM_USBC__USBCMDUH3_FS)
#else
#define BF_USBC__USBCMDUH3_FS(v)   (((v) << 2) & BM_USBC__USBCMDUH3_FS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS field to a new value.
#define BW_USBC__USBCMDUH3_FS(v)   BF_CS1(USBC__USBCMDUH3, FS, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field PSE[4:4] (RW)
 *
 * Periodic Schedule Enable- Read/Write. Default 0b. This bit controls whether the host controller
 * skips processing the Periodic Schedule. Only the host controller uses this bit. Values Meaning
 *
 * Values:
 * 0 - Do not process the Periodic Schedule
 * 1 - Use the PERIODICLISTBASE register to access the Periodic Schedule.
 */

#define BP_USBC__USBCMDUH3_PSE      (4)
#define BM_USBC__USBCMDUH3_PSE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_PSE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBCMDUH3_PSE)
#else
#define BF_USBC__USBCMDUH3_PSE(v)   (((v) << 4) & BM_USBC__USBCMDUH3_PSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSE field to a new value.
#define BW_USBC__USBCMDUH3_PSE(v)   BF_CS1(USBC__USBCMDUH3, PSE, v)
#endif


/* --- Register HW_USBC__USBCMDUH3, field ASE[5:5] (RW)
 *
 * Asynchronous Schedule Enable - Read/Write. Default 0b. This bit controls whether the host
 * controller skips processing the Asynchronous Schedule. Only the host controller uses this bit.
 * Values Meaning
 *
 * Values:
 * 0 - Do not process the Asynchronous Schedule.
 * 1 - Use the ASYNCLISTADDR register to access the Asynchronous Schedule.
 */

#define BP_USBC__USBCMDUH3_ASE      (5)
#define BM_USBC__USBCMDUH3_ASE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_ASE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBCMDUH3_ASE)
#else
#define BF_USBC__USBCMDUH3_ASE(v)   (((v) << 5) & BM_USBC__USBCMDUH3_ASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASE field to a new value.
#define BW_USBC__USBCMDUH3_ASE(v)   BF_CS1(USBC__USBCMDUH3, ASE, v)
#endif


/* --- Register HW_USBC__USBCMDUH3, field IAA[6:6] (RW)
 *
 * Interrupt on Async Advance Doorbell - Read/Write. This bit is used as a doorbell by software to
 * tell the host controller to issue an interrupt the next time it advances asynchronous schedule.
 * Software must write a 1 to this bit to ring the doorbell. When the host controller has evicted
 * all appropriate cached schedule states, it sets the Interrupt on Async Advance status bit in the
 * USBSTS register. If the Interrupt on Sync Advance Enable bit in the USBINTR register is one, then
 * the host controller will assert an interrupt at the next interrupt threshold. The host controller
 * sets this bit to zero after it has set the Interrupt on Sync Advance status bit in the USBSTS
 * register to one. Software should not write a one to this bit when the asynchronous schedule is
 * inactive. Doing so will yield undefined results. This bit is only used in host mode. Writing a
 * one to this bit when device mode is selected will have undefined results.
 */

#define BP_USBC__USBCMDUH3_IAA      (6)
#define BM_USBC__USBCMDUH3_IAA      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_IAA(v)   ((((reg32_t) v) << 6) & BM_USBC__USBCMDUH3_IAA)
#else
#define BF_USBC__USBCMDUH3_IAA(v)   (((v) << 6) & BM_USBC__USBCMDUH3_IAA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IAA field to a new value.
#define BW_USBC__USBCMDUH3_IAA(v)   BF_CS1(USBC__USBCMDUH3, IAA, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field ASP[9:8] (RW)
 *
 * Asynchronous Schedule Park Mode Count - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this field defaults to 3h and is R/W. Otherwise it defaults
 * to zero and is Read-Only. It contains a count of the number of successive transactions the host
 * controller is allowed to execute from a high-speed queue head on the Asynchronous schedule before
 * continuing traversal of the Asynchronous schedule. Valid values are 1h to 3h. Software must not
 * write a zero to this bit when Park Mode Enable is a one as this will result in undefined
 * behavior. This field is set to 3h in all 4 controller core.
 */

#define BP_USBC__USBCMDUH3_ASP      (8)
#define BM_USBC__USBCMDUH3_ASP      (0x00000300)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_ASP(v)   ((((reg32_t) v) << 8) & BM_USBC__USBCMDUH3_ASP)
#else
#define BF_USBC__USBCMDUH3_ASP(v)   (((v) << 8) & BM_USBC__USBCMDUH3_ASP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASP field to a new value.
#define BW_USBC__USBCMDUH3_ASP(v)   BF_CS1(USBC__USBCMDUH3, ASP, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field ASPE[11:11] (RW)
 *
 * Asynchronous Schedule Park Mode Enable - Read/Write. If the Asynchronous Park Capability bit in
 * the HCCPARAMS register is a one, then this bit defaults to a 1h and is R/W. Otherwise the bit
 * must be a zero and is RO. Software uses this bit to enable or disable Park mode. When this bit is
 * one, Park mode is enabled. When this bit is a zero, Park mode is disabled. This field is set to
 * '1b' in this implementation.
 */

#define BP_USBC__USBCMDUH3_ASPE      (11)
#define BM_USBC__USBCMDUH3_ASPE      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_ASPE(v)   ((((reg32_t) v) << 11) & BM_USBC__USBCMDUH3_ASPE)
#else
#define BF_USBC__USBCMDUH3_ASPE(v)   (((v) << 11) & BM_USBC__USBCMDUH3_ASPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASPE field to a new value.
#define BW_USBC__USBCMDUH3_ASPE(v)   BF_CS1(USBC__USBCMDUH3, ASPE, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field SUTW[13:13] (RW)
 *
 * Setup TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure that
 * the setup data payload of 8 bytes is extracted from a QH by the DCD without being corrupted. If
 * the setup lockout mode is off (SLOM bit in USB core register n_USBMODE, see ) then there is a
 * hazard when new setup data arrives while the DCD is copying the setup data payload from the QH
 * for a previous setup packet. This bit is set and cleared by software. This bit would also be
 * cleared by hardware when a hazard detected. For more information on the use of this bit, see the
 * Device Operational Model section of the USB-HS OTG High-Speed USB On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUH3_SUTW      (13)
#define BM_USBC__USBCMDUH3_SUTW      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_SUTW(v)   ((((reg32_t) v) << 13) & BM_USBC__USBCMDUH3_SUTW)
#else
#define BF_USBC__USBCMDUH3_SUTW(v)   (((v) << 13) & BM_USBC__USBCMDUH3_SUTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUTW field to a new value.
#define BW_USBC__USBCMDUH3_SUTW(v)   BF_CS1(USBC__USBCMDUH3, SUTW, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field ATDTW[14:14] (RW)
 *
 * Add dTD TripWire - Read/Write. [device mode only] This bit is used as a semaphore to ensure
 * proper addition of a new dTD to an active (primed) endpoint's linked list. This bit is set and
 * cleared by software. This bit would also be cleared by hardware when state machine is hazard
 * region for which adding a dTD to a primed endpoint may go unrecognized. For more information on
 * the use of this bit, see the Device Operational Model section of the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual.
 */

#define BP_USBC__USBCMDUH3_ATDTW      (14)
#define BM_USBC__USBCMDUH3_ATDTW      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_ATDTW(v)   ((((reg32_t) v) << 14) & BM_USBC__USBCMDUH3_ATDTW)
#else
#define BF_USBC__USBCMDUH3_ATDTW(v)   (((v) << 14) & BM_USBC__USBCMDUH3_ATDTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ATDTW field to a new value.
#define BW_USBC__USBCMDUH3_ATDTW(v)   BF_CS1(USBC__USBCMDUH3, ATDTW, v)
#endif

/* --- Register HW_USBC__USBCMDUH3, field FS1[15:15] (RW)
 *
 * See also bits 3-2 Frame List Size - (Read/Write or Read Only). [host mode only] This field is
 * Read/Write only if Programmable Frame List Flag in the HCCPARAMS registers is set to one. This
 * field specifies the size of the frame list that controls which bits in the Frame Index Register
 * should be used for the Frame List Current index. This field is made up from USBCMD bits 15, 3 and
 * 2. Value Meaning
 *
 * Values:
 * 000 - 1024 elements (4096 bytes) Default value
 * 001 - 512 elements (2048 bytes)
 * 010 - 256 elements (1024 bytes)
 * 011 - 128 elements (512 bytes)
 * 100 - 64 elements (256 bytes)
 * 101 - 32 elements (128 bytes)
 * 110 - 16 elements (64 bytes)
 * 111 - 8 elements (32 bytes)
 */

#define BP_USBC__USBCMDUH3_FS1      (15)
#define BM_USBC__USBCMDUH3_FS1      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_FS1(v)   ((((reg32_t) v) << 15) & BM_USBC__USBCMDUH3_FS1)
#else
#define BF_USBC__USBCMDUH3_FS1(v)   (((v) << 15) & BM_USBC__USBCMDUH3_FS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FS1 field to a new value.
#define BW_USBC__USBCMDUH3_FS1(v)   BF_CS1(USBC__USBCMDUH3, FS1, v)
#endif


/* --- Register HW_USBC__USBCMDUH3, field ITC[23:16] (RW)
 *
 * Interrupt Threshold Control -Read/Write. The system software uses this field to set the maximum
 * rate at which the host/device controller will issue interrupts. ITC contains the maximum
 * interrupt interval measured in micro-frames. Valid values are shown below. Value Maximum
 * Interrupt Interval
 *
 * Values:
 * 0x00 - Immediate (no threshold)
 * 0x01 - 1 micro-frame
 * 0x02 - 2 micro-frames
 * 0x04 - 4 micro-frames
 * 0x08 - 8 micro-frames
 * 0x10 - 16 micro-frames
 * 0x20 - 32 micro-frames
 * 0x40 - 64 micro-frames
 */

#define BP_USBC__USBCMDUH3_ITC      (16)
#define BM_USBC__USBCMDUH3_ITC      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBCMDUH3_ITC(v)   ((((reg32_t) v) << 16) & BM_USBC__USBCMDUH3_ITC)
#else
#define BF_USBC__USBCMDUH3_ITC(v)   (((v) << 16) & BM_USBC__USBCMDUH3_ITC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ITC field to a new value.
#define BW_USBC__USBCMDUH3_ITC(v)   BF_CS1(USBC__USBCMDUH3, ITC, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBSTSUH3 - USB Status Register UH3 (RW)
 *
 * This register indicates various states of the Host/Device Controller and any pending interrupts.
 * This register does not indicate status resulting from a transaction on the serial bus.  *HCH bit
 * reset value: '0b' for OTG core, '1b' for Host1/Host2/Host3 core.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UI : 1; //!< USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a short packet is detected. A short packet is when the actual number of bytes received was less than the expected number of bytes.
        unsigned UEI : 1; //!< USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e. 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus, Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB On-The-Go DEV reference manual. The device controller detects resume signaling only.
        unsigned PCI : 1; //!< Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the result of a J-K transition on the suspended port. The Device Controller sets this bit to a one when the port controller enters the full or high-speed operational state. When the port controller exits the full or high-speed operation states due to Reset or Suspend events, the notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
        unsigned FRI : 1; //!< Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index rolls over from its maximum value to zero. The exact value at which the rollover occurs depends on the frame list size. For example. If the frame list size (as programmed in the Frame List Size field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every time FHINDEX [12] toggles. Only used in host operation mode.
        unsigned SEI : 1; //!< System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on the system interface.
        unsigned AAI : 1; //!< Interrupt on Async Advance - R/WC. System software can force the host controller to issue an interrupt the next time the host controller advances the asynchronous schedule by writing a one to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit indicates the assertion of that interrupt source. Only used in host operation mode.
        unsigned URI : 1; //!< USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset Received status bit. Only used in device operation mode.
        unsigned SRI : 1; //!< SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will be set to a one. When a SOF is extremely late, the device controller will automatically set this bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is received. Because the device controller is initialized to FS before connect, this bit will be set at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set every 125us and can be used by host controller driver as a time base. Software writes a 1 to this bit to clear it.
        unsigned SLI : 1; //!< DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be set to a one. The device controller clears the bit upon exiting from a suspend state. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPII : 1; //!< ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HCH : 1; //!< HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either by software or by the Controller hardware (for example, an internal error). Only used in the host operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
        unsigned RCL : 1; //!< Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous schedule. Only used in the host operation mode.
        unsigned PS : 1; //!< Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Periodic Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned AS : 1; //!< Asynchronous Schedule Status - Read Only. This bit reports the current real status of the Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set to one the status is enabled. The Host Controller is not required to immediately disable or enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host operation mode.
        unsigned NAKI : 1; //!< NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
        unsigned RESERVED2 : 7; //!< Reserved
        unsigned TI0 : 1; //!< General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
        unsigned TI1 : 1; //!< General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
        unsigned RESERVED3 : 6; //!< Reserved
    } B;
} hw_usbc__usbstsuh3_t;
#endif

/*
 * constants & macros for entire USBC__USBSTSUH3 register
 */
#define HW_USBC__USBSTSUH3_ADDR      (REGS_USBC_BASE + 0x744)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBSTSUH3           (*(volatile hw_usbc__usbstsuh3_t *) HW_USBC__USBSTSUH3_ADDR)
#define HW_USBC__USBSTSUH3_RD()      (HW_USBC__USBSTSUH3.U)
#define HW_USBC__USBSTSUH3_WR(v)     (HW_USBC__USBSTSUH3.U = (v))
#define HW_USBC__USBSTSUH3_SET(v)    (HW_USBC__USBSTSUH3_WR(HW_USBC__USBSTSUH3_RD() |  (v)))
#define HW_USBC__USBSTSUH3_CLR(v)    (HW_USBC__USBSTSUH3_WR(HW_USBC__USBSTSUH3_RD() & ~(v)))
#define HW_USBC__USBSTSUH3_TOG(v)    (HW_USBC__USBSTSUH3_WR(HW_USBC__USBSTSUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBSTSUH3 bitfields
 */

/* --- Register HW_USBC__USBSTSUH3, field UI[0:0] (RW)
 *
 * USB Interrupt (USBINT) - R/WC. This bit is set by the Host/Device Controller when the cause of an
 * interrupt is a completion of a USB transaction where the Transfer Descriptor (TD) has an
 * interrupt on complete (IOC) bit set. This bit is also set by the Host/Device Controller when a
 * short packet is detected. A short packet is when the actual number of bytes received was less
 * than the expected number of bytes.
 */

#define BP_USBC__USBSTSUH3_UI      (0)
#define BM_USBC__USBSTSUH3_UI      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_UI(v)   ((((reg32_t) v) << 0) & BM_USBC__USBSTSUH3_UI)
#else
#define BF_USBC__USBSTSUH3_UI(v)   (((v) << 0) & BM_USBC__USBSTSUH3_UI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UI field to a new value.
#define BW_USBC__USBSTSUH3_UI(v)   BF_CS1(USBC__USBSTSUH3, UI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field UEI[1:1] (RW)
 *
 * USB Error Interrupt (USBERRINT) - R/WC. When completion of a USB transaction results in an error
 * condition, this bit is set by the Host/Device Controller. This bit is set along with the USBINT
 * bit, if the TD on which the error interrupt occurred also had its interrupt on complete (IOC) bit
 * set See Section (Reference Host Operation Model: Transfer/Transaction Based Interrupt - i.e.
 * 4.15.1 in EHCI Enhanced Host Controller Interface Specification for Universal Serial Bus,
 * Revision 0.95, November 2000, Intel Corporation. http://www.intel.com) for a complete list of
 * host error interrupt conditions. See section Device Error Matrix in the USB-HS OTG High-Speed USB
 * On-The-Go DEV reference manual. The device controller detects resume signaling only.
 */

#define BP_USBC__USBSTSUH3_UEI      (1)
#define BM_USBC__USBSTSUH3_UEI      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_UEI(v)   ((((reg32_t) v) << 1) & BM_USBC__USBSTSUH3_UEI)
#else
#define BF_USBC__USBSTSUH3_UEI(v)   (((v) << 1) & BM_USBC__USBSTSUH3_UEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEI field to a new value.
#define BW_USBC__USBSTSUH3_UEI(v)   BF_CS1(USBC__USBSTSUH3, UEI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field PCI[2:2] (RW)
 *
 * Port Change Detect - R/WC. The Host Controller sets this bit to a one when on any port a Connect
 * Status occurs, a Port Enable/Disable Change occurs, or the Force Port Resume bit is set as the
 * result of a J-K transition on the suspended port. The Device Controller sets this bit to a one
 * when the port controller enters the full or high-speed operational state. When the port
 * controller exits the full or high-speed operation states due to Reset or Suspend events, the
 * notification mechanisms are the USB Reset Received bit and the DCSuspend bits respectively.
 */

#define BP_USBC__USBSTSUH3_PCI      (2)
#define BM_USBC__USBSTSUH3_PCI      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_PCI(v)   ((((reg32_t) v) << 2) & BM_USBC__USBSTSUH3_PCI)
#else
#define BF_USBC__USBSTSUH3_PCI(v)   (((v) << 2) & BM_USBC__USBSTSUH3_PCI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCI field to a new value.
#define BW_USBC__USBSTSUH3_PCI(v)   BF_CS1(USBC__USBSTSUH3, PCI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field FRI[3:3] (RW)
 *
 * Frame List Rollover - R/WC. The Host Controller sets this bit to a one when the Frame List Index
 * rolls over from its maximum value to zero. The exact value at which the rollover occurs depends
 * on the frame list size. For example. If the frame list size (as programmed in the Frame List Size
 * field of the UOG_USBCMD register) is 1024, the Frame Index Register rolls over every time FRINDEX
 * [13] toggles. Similarly, if the size is 512, the Host Controller sets this bit to a one every
 * time FHINDEX [12] toggles. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUH3_FRI      (3)
#define BM_USBC__USBSTSUH3_FRI      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_FRI(v)   ((((reg32_t) v) << 3) & BM_USBC__USBSTSUH3_FRI)
#else
#define BF_USBC__USBSTSUH3_FRI(v)   (((v) << 3) & BM_USBC__USBSTSUH3_FRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRI field to a new value.
#define BW_USBC__USBSTSUH3_FRI(v)   BF_CS1(USBC__USBSTSUH3, FRI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field SEI[4:4] (RW)
 *
 * System Error- R/WC. This bit is will be set to '1b' when an Error response is seen to a read on
 * the system interface.
 */

#define BP_USBC__USBSTSUH3_SEI      (4)
#define BM_USBC__USBSTSUH3_SEI      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_SEI(v)   ((((reg32_t) v) << 4) & BM_USBC__USBSTSUH3_SEI)
#else
#define BF_USBC__USBSTSUH3_SEI(v)   (((v) << 4) & BM_USBC__USBSTSUH3_SEI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEI field to a new value.
#define BW_USBC__USBSTSUH3_SEI(v)   BF_CS1(USBC__USBSTSUH3, SEI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field AAI[5:5] (RW)
 *
 * Interrupt on Async Advance - R/WC. System software can force the host controller to issue an
 * interrupt the next time the host controller advances the asynchronous schedule by writing a one
 * to the Interrupt on Async Advance Doorbell bit in the n_USBCMD register. This status bit
 * indicates the assertion of that interrupt source. Only used in host operation mode.
 */

#define BP_USBC__USBSTSUH3_AAI      (5)
#define BM_USBC__USBSTSUH3_AAI      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_AAI(v)   ((((reg32_t) v) << 5) & BM_USBC__USBSTSUH3_AAI)
#else
#define BF_USBC__USBSTSUH3_AAI(v)   (((v) << 5) & BM_USBC__USBSTSUH3_AAI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAI field to a new value.
#define BW_USBC__USBSTSUH3_AAI(v)   BF_CS1(USBC__USBSTSUH3, AAI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field URI[6:6] (RW)
 *
 * USB Reset Received - R/WC. When the device controller detects a USB Reset and enters the default
 * state, this bit will be set to a one. Software can write a 1 to this bit to clear the USB Reset
 * Received status bit. Only used in device operation mode.
 */

#define BP_USBC__USBSTSUH3_URI      (6)
#define BM_USBC__USBSTSUH3_URI      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_URI(v)   ((((reg32_t) v) << 6) & BM_USBC__USBSTSUH3_URI)
#else
#define BF_USBC__USBSTSUH3_URI(v)   (((v) << 6) & BM_USBC__USBSTSUH3_URI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URI field to a new value.
#define BW_USBC__USBSTSUH3_URI(v)   BF_CS1(USBC__USBSTSUH3, URI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field SRI[7:7] (RW)
 *
 * SOF Received - R/WC. When the device controller detects a Start Of (micro) Frame, this bit will
 * be set to a one. When a SOF is extremely late, the device controller will automatically set this
 * bit to indicate that an SOF was expected. Therefore, this bit will be set roughly every 1ms in
 * device FS mode and every 125ms in HS mode and will be synchronized to the actual SOF that is
 * received. Because the device controller is initialized to FS before connect, this bit will be set
 * at an interval of 1ms during the prelude to connect and chirp. In host mode, this bit will be set
 * every 125us and can be used by host controller driver as a time base. Software writes a 1 to this
 * bit to clear it.
 */

#define BP_USBC__USBSTSUH3_SRI      (7)
#define BM_USBC__USBSTSUH3_SRI      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_SRI(v)   ((((reg32_t) v) << 7) & BM_USBC__USBSTSUH3_SRI)
#else
#define BF_USBC__USBSTSUH3_SRI(v)   (((v) << 7) & BM_USBC__USBSTSUH3_SRI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRI field to a new value.
#define BW_USBC__USBSTSUH3_SRI(v)   BF_CS1(USBC__USBSTSUH3, SRI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field SLI[8:8] (RW)
 *
 * DCSuspend - R/WC. When a controller enters a suspend state from an active state, this bit will be
 * set to a one. The device controller clears the bit upon exiting from a suspend state. Only used
 * in device operation mode.
 */

#define BP_USBC__USBSTSUH3_SLI      (8)
#define BM_USBC__USBSTSUH3_SLI      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_SLI(v)   ((((reg32_t) v) << 8) & BM_USBC__USBSTSUH3_SLI)
#else
#define BF_USBC__USBSTSUH3_SLI(v)   (((v) << 8) & BM_USBC__USBSTSUH3_SLI)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLI field to a new value.
#define BW_USBC__USBSTSUH3_SLI(v)   BF_CS1(USBC__USBSTSUH3, SLI, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field ULPII[10:10] (RW)
 *
 * ULPI Interrupt - R/WC. This bit will be set '1b' by hardware when there is an event completion in
 * ULPI viewport. This bit is usable only if the controller support UPLI interface mode.
 */

#define BP_USBC__USBSTSUH3_ULPII      (10)
#define BM_USBC__USBSTSUH3_ULPII      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_ULPII(v)   ((((reg32_t) v) << 10) & BM_USBC__USBSTSUH3_ULPII)
#else
#define BF_USBC__USBSTSUH3_ULPII(v)   (((v) << 10) & BM_USBC__USBSTSUH3_ULPII)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPII field to a new value.
#define BW_USBC__USBSTSUH3_ULPII(v)   BF_CS1(USBC__USBSTSUH3, ULPII, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field HCH[12:12] (RW)
 *
 * HCHaIted - Read Only. This bit is a zero whenever the Run/Stop bit is a one. The Controller sets
 * this bit to one after it has stopped executing because of the Run/Stop bit being set to 0, either
 * by software or by the Controller hardware (for example, an internal error). Only used in the host
 * operation mode. Default value is '0b' for OTG core, and '1b' for Host1/Host2/Host3 core. This is
 * because OTG core is not operating as host in default. Please see CM bit in UOG_USBMODE register.
 */

#define BP_USBC__USBSTSUH3_HCH      (12)
#define BM_USBC__USBSTSUH3_HCH      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_HCH(v)   ((((reg32_t) v) << 12) & BM_USBC__USBSTSUH3_HCH)
#else
#define BF_USBC__USBSTSUH3_HCH(v)   (((v) << 12) & BM_USBC__USBSTSUH3_HCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HCH field to a new value.
#define BW_USBC__USBSTSUH3_HCH(v)   BF_CS1(USBC__USBSTSUH3, HCH, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field RCL[13:13] (RW)
 *
 * Reclamation - Read Only. This is a read-only status bit used to detect an empty asynchronous
 * schedule. Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUH3_RCL      (13)
#define BM_USBC__USBSTSUH3_RCL      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_RCL(v)   ((((reg32_t) v) << 13) & BM_USBC__USBSTSUH3_RCL)
#else
#define BF_USBC__USBSTSUH3_RCL(v)   (((v) << 13) & BM_USBC__USBSTSUH3_RCL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RCL field to a new value.
#define BW_USBC__USBSTSUH3_RCL(v)   BF_CS1(USBC__USBSTSUH3, RCL, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field PS[14:14] (RW)
 *
 * Periodic Schedule Status - Read Only. This bit reports the current real status of the Periodic
 * Schedule. When set to zero the periodic schedule is disabled, and if set to one the status is
 * enabled. The Host Controller is not required to immediately disable or enable the Periodic
 * Schedule when software transitions the Periodic Schedule Enable bit in the USBCMD register. When
 * this bit and the Periodic Schedule Enable bit are the same value, the Periodic Schedule is either
 * enabled (1) or disabled (0). Only used in the host operation mode.
 */

#define BP_USBC__USBSTSUH3_PS      (14)
#define BM_USBC__USBSTSUH3_PS      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_PS(v)   ((((reg32_t) v) << 14) & BM_USBC__USBSTSUH3_PS)
#else
#define BF_USBC__USBSTSUH3_PS(v)   (((v) << 14) & BM_USBC__USBSTSUH3_PS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PS field to a new value.
#define BW_USBC__USBSTSUH3_PS(v)   BF_CS1(USBC__USBSTSUH3, PS, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field AS[15:15] (RW)
 *
 * Asynchronous Schedule Status - Read Only. This bit reports the current real status of the
 * Asynchronous Schedule. When set to zero the asynchronous schedule status is disabled and if set
 * to one the status is enabled. The Host Controller is not required to immediately disable or
 * enable the Asynchronous Schedule when software transitions the Asynchronous Schedule Enable bit
 * in the USBCMD register. When this bit and the Asynchronous Schedule Enable bit are the same
 * value, the Asynchronous Schedule is either enabled (1) or disabled (0). Only used in the host
 * operation mode.
 */

#define BP_USBC__USBSTSUH3_AS      (15)
#define BM_USBC__USBSTSUH3_AS      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_AS(v)   ((((reg32_t) v) << 15) & BM_USBC__USBSTSUH3_AS)
#else
#define BF_USBC__USBSTSUH3_AS(v)   (((v) << 15) & BM_USBC__USBSTSUH3_AS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AS field to a new value.
#define BW_USBC__USBSTSUH3_AS(v)   BF_CS1(USBC__USBSTSUH3, AS, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field NAKI[16:16] (RO)
 *
 * NAK Interrupt Bit--RO. This bit is set by hardware when for a particular endpoint both the TX/RX
 * Endpoint NAK bit and corresponding TX/RX Endpoint NAK Enable bit are set. This bit is
 * automatically cleared by hardware when all Enabled TX/RX Endpoint NAK bits are cleared.
 */

#define BP_USBC__USBSTSUH3_NAKI      (16)
#define BM_USBC__USBSTSUH3_NAKI      (0x00010000)

/* --- Register HW_USBC__USBSTSUH3, field TI0[24:24] (RW)
 *
 * General Purpose Timer Interrupt 0(GPTINT0)--R/WC. This bit is set when the counter in the
 * GPTIMER0CTRL register transitions to zero, writing a one to this bit clears it.
 */

#define BP_USBC__USBSTSUH3_TI0      (24)
#define BM_USBC__USBSTSUH3_TI0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_TI0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBSTSUH3_TI0)
#else
#define BF_USBC__USBSTSUH3_TI0(v)   (((v) << 24) & BM_USBC__USBSTSUH3_TI0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI0 field to a new value.
#define BW_USBC__USBSTSUH3_TI0(v)   BF_CS1(USBC__USBSTSUH3, TI0, v)
#endif

/* --- Register HW_USBC__USBSTSUH3, field TI1[25:25] (RW)
 *
 * General Purpose Timer Interrupt 1(GPTINT1)--R/WC. This bit is set when the counter in the
 * GPTIMER1CTRL register transitions to zero, writing a one to this bit will clear it.
 */

#define BP_USBC__USBSTSUH3_TI1      (25)
#define BM_USBC__USBSTSUH3_TI1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBSTSUH3_TI1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBSTSUH3_TI1)
#else
#define BF_USBC__USBSTSUH3_TI1(v)   (((v) << 25) & BM_USBC__USBSTSUH3_TI1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TI1 field to a new value.
#define BW_USBC__USBSTSUH3_TI1(v)   BF_CS1(USBC__USBSTSUH3, TI1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBINTRUH3 - Interrupt Enable Register UH3 (RW)
 *
 * The interrupts to software are enabled with this register. An interrupt is generated when a bit
 * is set and the corresponding interrupt source is active. The USB Status register (n_USBSTS) still
 * shows interrupt sources even if they are disabled by the n_USBINTR register, allowing polling of
 * interrupt events by the software.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned UE : 1; //!< USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned UEE : 1; //!< USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned PCE : 1; //!< Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned FRE : 1; //!< Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned SEE : 1; //!< System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned AAE : 1; //!< Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one the controller will issue an interrupt. Only used in host operation mode.
        unsigned URE : 1; //!< USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned SRE : 1; //!< SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned SLE : 1; //!< Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the controller will issue an interrupt. Only used in device operation mode.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ULPIE : 1; //!< ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the controller will issue an interrupt. This bit is usable only if the controller support UPLI interface mode.
        unsigned RESERVED1 : 5; //!< These bits are reserved and should be set to zero.
        unsigned NAKE : 1; //!< NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned UAIE : 1; //!< USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned UPIE : 1; //!< USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register is one, host controller will issue an interrupt at the next interrupt threshold.
        unsigned RESERVED3 : 4; //!< Reserved
        unsigned TIE0 : 1; //!< General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned TIE1 : 1; //!< General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS register is a one the controller will issue an interrupt.
        unsigned RESERVED4 : 6; //!< Reserved
    } B;
} hw_usbc__usbintruh3_t;
#endif

/*
 * constants & macros for entire USBC__USBINTRUH3 register
 */
#define HW_USBC__USBINTRUH3_ADDR      (REGS_USBC_BASE + 0x748)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBINTRUH3           (*(volatile hw_usbc__usbintruh3_t *) HW_USBC__USBINTRUH3_ADDR)
#define HW_USBC__USBINTRUH3_RD()      (HW_USBC__USBINTRUH3.U)
#define HW_USBC__USBINTRUH3_WR(v)     (HW_USBC__USBINTRUH3.U = (v))
#define HW_USBC__USBINTRUH3_SET(v)    (HW_USBC__USBINTRUH3_WR(HW_USBC__USBINTRUH3_RD() |  (v)))
#define HW_USBC__USBINTRUH3_CLR(v)    (HW_USBC__USBINTRUH3_WR(HW_USBC__USBINTRUH3_RD() & ~(v)))
#define HW_USBC__USBINTRUH3_TOG(v)    (HW_USBC__USBINTRUH3_WR(HW_USBC__USBINTRUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBINTRUH3 bitfields
 */

/* --- Register HW_USBC__USBINTRUH3, field UE[0:0] (RW)
 *
 * USB Interrupt Enalbe When this bit is one and the UI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_UE      (0)
#define BM_USBC__USBINTRUH3_UE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_UE(v)   ((((reg32_t) v) << 0) & BM_USBC__USBINTRUH3_UE)
#else
#define BF_USBC__USBINTRUH3_UE(v)   (((v) << 0) & BM_USBC__USBINTRUH3_UE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UE field to a new value.
#define BW_USBC__USBINTRUH3_UE(v)   BF_CS1(USBC__USBINTRUH3, UE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field UEE[1:1] (RW)
 *
 * USB Error Interrupt Enable When this bit is one and the UEI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_UEE      (1)
#define BM_USBC__USBINTRUH3_UEE      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_UEE(v)   ((((reg32_t) v) << 1) & BM_USBC__USBINTRUH3_UEE)
#else
#define BF_USBC__USBINTRUH3_UEE(v)   (((v) << 1) & BM_USBC__USBINTRUH3_UEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UEE field to a new value.
#define BW_USBC__USBINTRUH3_UEE(v)   BF_CS1(USBC__USBINTRUH3, UEE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field PCE[2:2] (RW)
 *
 * Port Change Detect Interrupt Enable When this bit is one and the PCI bit in n_USBSTS register is
 * a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_PCE      (2)
#define BM_USBC__USBINTRUH3_PCE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_PCE(v)   ((((reg32_t) v) << 2) & BM_USBC__USBINTRUH3_PCE)
#else
#define BF_USBC__USBINTRUH3_PCE(v)   (((v) << 2) & BM_USBC__USBINTRUH3_PCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PCE field to a new value.
#define BW_USBC__USBINTRUH3_PCE(v)   BF_CS1(USBC__USBINTRUH3, PCE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field FRE[3:3] (RW)
 *
 * Frame List Rollover Interrupt Enable When this bit is one and the FRI bit in n_USBSTS register is
 * a one the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH3_FRE      (3)
#define BM_USBC__USBINTRUH3_FRE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_FRE(v)   ((((reg32_t) v) << 3) & BM_USBC__USBINTRUH3_FRE)
#else
#define BF_USBC__USBINTRUH3_FRE(v)   (((v) << 3) & BM_USBC__USBINTRUH3_FRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRE field to a new value.
#define BW_USBC__USBINTRUH3_FRE(v)   BF_CS1(USBC__USBINTRUH3, FRE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field SEE[4:4] (RW)
 *
 * System Error Interrupt Enable When this bit is one and the SEI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH3_SEE      (4)
#define BM_USBC__USBINTRUH3_SEE      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_SEE(v)   ((((reg32_t) v) << 4) & BM_USBC__USBINTRUH3_SEE)
#else
#define BF_USBC__USBINTRUH3_SEE(v)   (((v) << 4) & BM_USBC__USBINTRUH3_SEE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SEE field to a new value.
#define BW_USBC__USBINTRUH3_SEE(v)   BF_CS1(USBC__USBINTRUH3, SEE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field AAE[5:5] (RW)
 *
 * Async Advance Interrupt Enable When this bit is one and the AAI bit in n_USBSTS register is a one
 * the controller will issue an interrupt. Only used in host operation mode.
 */

#define BP_USBC__USBINTRUH3_AAE      (5)
#define BM_USBC__USBINTRUH3_AAE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_AAE(v)   ((((reg32_t) v) << 5) & BM_USBC__USBINTRUH3_AAE)
#else
#define BF_USBC__USBINTRUH3_AAE(v)   (((v) << 5) & BM_USBC__USBINTRUH3_AAE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the AAE field to a new value.
#define BW_USBC__USBINTRUH3_AAE(v)   BF_CS1(USBC__USBINTRUH3, AAE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field URE[6:6] (RW)
 *
 * USB Reset Interrupt Enable When this bit is one and the URI bit in n_UOG_USBSTS register is a one
 * the controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUH3_URE      (6)
#define BM_USBC__USBINTRUH3_URE      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_URE(v)   ((((reg32_t) v) << 6) & BM_USBC__USBINTRUH3_URE)
#else
#define BF_USBC__USBINTRUH3_URE(v)   (((v) << 6) & BM_USBC__USBINTRUH3_URE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the URE field to a new value.
#define BW_USBC__USBINTRUH3_URE(v)   BF_CS1(USBC__USBINTRUH3, URE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field SRE[7:7] (RW)
 *
 * SOF Received Interrupt Enable When this bit is one and the SRI bit in n_USBSTS register is a one
 * the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_SRE      (7)
#define BM_USBC__USBINTRUH3_SRE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_SRE(v)   ((((reg32_t) v) << 7) & BM_USBC__USBINTRUH3_SRE)
#else
#define BF_USBC__USBINTRUH3_SRE(v)   (((v) << 7) & BM_USBC__USBINTRUH3_SRE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SRE field to a new value.
#define BW_USBC__USBINTRUH3_SRE(v)   BF_CS1(USBC__USBINTRUH3, SRE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field SLE[8:8] (RW)
 *
 * Sleep Interrupt Enable When this bit is one and the SLI bit in n_n_USBSTS register is a one the
 * controller will issue an interrupt. Only used in device operation mode.
 */

#define BP_USBC__USBINTRUH3_SLE      (8)
#define BM_USBC__USBINTRUH3_SLE      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_SLE(v)   ((((reg32_t) v) << 8) & BM_USBC__USBINTRUH3_SLE)
#else
#define BF_USBC__USBINTRUH3_SLE(v)   (((v) << 8) & BM_USBC__USBINTRUH3_SLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLE field to a new value.
#define BW_USBC__USBINTRUH3_SLE(v)   BF_CS1(USBC__USBINTRUH3, SLE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field ULPIE[10:10] (RW)
 *
 * ULPI Interrupt Enable When this bit is one and the UPLII bit in n_USBSTS register is a one the
 * controller will issue an interrupt. This bit is usable only if the controller support UPLI
 * interface mode.
 */

#define BP_USBC__USBINTRUH3_ULPIE      (10)
#define BM_USBC__USBINTRUH3_ULPIE      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_ULPIE(v)   ((((reg32_t) v) << 10) & BM_USBC__USBINTRUH3_ULPIE)
#else
#define BF_USBC__USBINTRUH3_ULPIE(v)   (((v) << 10) & BM_USBC__USBINTRUH3_ULPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPIE field to a new value.
#define BW_USBC__USBINTRUH3_ULPIE(v)   BF_CS1(USBC__USBINTRUH3, ULPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field NAKE[16:16] (RW)
 *
 * NAK Interrupt Enable When this bit is one and the NAKI bit in n_USBSTS register is a one the
 * controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_NAKE      (16)
#define BM_USBC__USBINTRUH3_NAKE      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_NAKE(v)   ((((reg32_t) v) << 16) & BM_USBC__USBINTRUH3_NAKE)
#else
#define BF_USBC__USBINTRUH3_NAKE(v)   (((v) << 16) & BM_USBC__USBINTRUH3_NAKE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NAKE field to a new value.
#define BW_USBC__USBINTRUH3_NAKE(v)   BF_CS1(USBC__USBINTRUH3, NAKE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field UAIE[18:18] (RW)
 *
 * USB Host Asynchronous Interrupt Enable When this bit is one, and the UAI bit in the n_USBSTS
 * register is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUH3_UAIE      (18)
#define BM_USBC__USBINTRUH3_UAIE      (0x00040000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_UAIE(v)   ((((reg32_t) v) << 18) & BM_USBC__USBINTRUH3_UAIE)
#else
#define BF_USBC__USBINTRUH3_UAIE(v)   (((v) << 18) & BM_USBC__USBINTRUH3_UAIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UAIE field to a new value.
#define BW_USBC__USBINTRUH3_UAIE(v)   BF_CS1(USBC__USBINTRUH3, UAIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field UPIE[19:19] (RW)
 *
 * USB Host Periodic Interrupt Enable When this bit is one, and the UPI bit in the n_USBSTS register
 * is one, host controller will issue an interrupt at the next interrupt threshold.
 */

#define BP_USBC__USBINTRUH3_UPIE      (19)
#define BM_USBC__USBINTRUH3_UPIE      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_UPIE(v)   ((((reg32_t) v) << 19) & BM_USBC__USBINTRUH3_UPIE)
#else
#define BF_USBC__USBINTRUH3_UPIE(v)   (((v) << 19) & BM_USBC__USBINTRUH3_UPIE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UPIE field to a new value.
#define BW_USBC__USBINTRUH3_UPIE(v)   BF_CS1(USBC__USBINTRUH3, UPIE, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field TIE0[24:24] (RW)
 *
 * General Purpose Timer #0 Interrupt Enable When this bit is one and the TI0 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_TIE0      (24)
#define BM_USBC__USBINTRUH3_TIE0      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_TIE0(v)   ((((reg32_t) v) << 24) & BM_USBC__USBINTRUH3_TIE0)
#else
#define BF_USBC__USBINTRUH3_TIE0(v)   (((v) << 24) & BM_USBC__USBINTRUH3_TIE0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE0 field to a new value.
#define BW_USBC__USBINTRUH3_TIE0(v)   BF_CS1(USBC__USBINTRUH3, TIE0, v)
#endif

/* --- Register HW_USBC__USBINTRUH3, field TIE1[25:25] (RW)
 *
 * General Purpose Timer #1 Interrupt Enable When this bit is one and the TI1 bit in n_USBSTS
 * register is a one the controller will issue an interrupt.
 */

#define BP_USBC__USBINTRUH3_TIE1      (25)
#define BM_USBC__USBINTRUH3_TIE1      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBINTRUH3_TIE1(v)   ((((reg32_t) v) << 25) & BM_USBC__USBINTRUH3_TIE1)
#else
#define BF_USBC__USBINTRUH3_TIE1(v)   (((v) << 25) & BM_USBC__USBINTRUH3_TIE1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE1 field to a new value.
#define BW_USBC__USBINTRUH3_TIE1(v)   BF_CS1(USBC__USBINTRUH3, TIE1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__FRINDEXUH3 - USB Frame Index UH3 (RW)
 *
 * This register is used by the host controller to index the periodic frame list. The register
 * updates every 125 microseconds (once each micro-frame). Bits [N: 3] are used to select a
 * particular entry in the Periodic Frame List during periodic schedule execution. The number of
 * bits used for the index depends on the size of the frame list as set by system software in the
 * Frame List Size field in the n_USBCMD register.  This register must be written as a DWord. Byte
 * writes produce-undefined results. This register cannot be written unless the Host Controller is
 * in the 'Halted' state as indicated by the HCHalted bit. A write to this register while the
 * Run/Stop hit is set to a one produces undefined results. Writes to this register also affect the
 * SOF value.  In device mode this register is read only and, the device controller updates the
 * FRINDEX [13:3] register from the frame number indicated by the SOF marker. Whenever a SOF is
 * received by the USB bus, FRINDEX [13:3] will be checked against the SOF marker. If FRINDEX [13:3]
 * is different from the SOF marker, FRINDEX [13:3] will be set to the SOF value and FRINDEX [2:0]
 * will be set to zero (that is, SOF for 1 ms frame). If FRINDEX [13:3] is equal to the SOF value,
 * FRINDEX [2:0] will be increment (that is, SOF for 125 us micro-frame.).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned FRINDEX : 14; //!< Frame Index. The value, in this register, increments at the end of each time frame (micro-frame). Bits [N: 3] are used for the Frame List current index. This means that each location of the frame list is accessed 8 times (frames or micro-frames) before moving to the next index. The following illustrates values of N based on the value of the Frame List Size field in the USBCMD register, when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is the current frame number of the last frame transmitted. It is not used as an index. In either mode bits 2:0 indicate the current microframe.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_usbc__frindexuh3_t;
#endif

/*
 * constants & macros for entire USBC__FRINDEXUH3 register
 */
#define HW_USBC__FRINDEXUH3_ADDR      (REGS_USBC_BASE + 0x74c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__FRINDEXUH3           (*(volatile hw_usbc__frindexuh3_t *) HW_USBC__FRINDEXUH3_ADDR)
#define HW_USBC__FRINDEXUH3_RD()      (HW_USBC__FRINDEXUH3.U)
#define HW_USBC__FRINDEXUH3_WR(v)     (HW_USBC__FRINDEXUH3.U = (v))
#define HW_USBC__FRINDEXUH3_SET(v)    (HW_USBC__FRINDEXUH3_WR(HW_USBC__FRINDEXUH3_RD() |  (v)))
#define HW_USBC__FRINDEXUH3_CLR(v)    (HW_USBC__FRINDEXUH3_WR(HW_USBC__FRINDEXUH3_RD() & ~(v)))
#define HW_USBC__FRINDEXUH3_TOG(v)    (HW_USBC__FRINDEXUH3_WR(HW_USBC__FRINDEXUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__FRINDEXUH3 bitfields
 */

/* --- Register HW_USBC__FRINDEXUH3, field FRINDEX[13:0] (RW)
 *
 * Frame Index. The value, in this register, increments at the end of each time frame (micro-frame).
 * Bits [N: 3] are used for the Frame List current index. This means that each location of the frame
 * list is accessed 8 times (frames or micro-frames) before moving to the next index. The following
 * illustrates values of N based on the value of the Frame List Size field in the USBCMD register,
 * when used in host mode. USBCMD [Frame List Size] Number Elements N In device mode the value is
 * the current frame number of the last frame transmitted. It is not used as an index. In either
 * mode bits 2:0 indicate the current microframe.
 *
 * Values:
 * 000 - (1024) 12
 * 001 - (512) 11
 * 010 - (256) 10
 * 011 - (128) 9
 * 100 - (64) 8
 * 101 - (32) 7
 * 110 - (16) 6
 * 111 - (8) 5
 */

#define BP_USBC__FRINDEXUH3_FRINDEX      (0)
#define BM_USBC__FRINDEXUH3_FRINDEX      (0x00003fff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__FRINDEXUH3_FRINDEX(v)   ((((reg32_t) v) << 0) & BM_USBC__FRINDEXUH3_FRINDEX)
#else
#define BF_USBC__FRINDEXUH3_FRINDEX(v)   (((v) << 0) & BM_USBC__FRINDEXUH3_FRINDEX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRINDEX field to a new value.
#define BW_USBC__FRINDEXUH3_FRINDEX(v)   BF_CS1(USBC__FRINDEXUH3, FRINDEX, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PERIODICLISTBASEUH3 - Frame List Base Address UH3 (RW)
 *
 * Host Controller only  This 32-bit register contains the beginning address of the Periodic Frame
 * List in the system memory. HCD loads this register prior to starting the schedule execution by
 * the Host Controller. The memory structure referenced by this physical memory pointer is assumed
 * to be 4-Kbyte aligned. The contents of this register are combined with the Frame Index Register
 * (UOG_FRINDEX) to enable the Host Controller to step through the Periodic Frame List in sequence.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 12; //!< Reserved
        unsigned BASEADR : 20; //!< Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only used by the host controller.
    } B;
} hw_usbc__periodiclistbaseuh3_t;
#endif

/*
 * constants & macros for entire USBC__PERIODICLISTBASEUH3 register
 */
#define HW_USBC__PERIODICLISTBASEUH3_ADDR      (REGS_USBC_BASE + 0x754)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PERIODICLISTBASEUH3           (*(volatile hw_usbc__periodiclistbaseuh3_t *) HW_USBC__PERIODICLISTBASEUH3_ADDR)
#define HW_USBC__PERIODICLISTBASEUH3_RD()      (HW_USBC__PERIODICLISTBASEUH3.U)
#define HW_USBC__PERIODICLISTBASEUH3_WR(v)     (HW_USBC__PERIODICLISTBASEUH3.U = (v))
#define HW_USBC__PERIODICLISTBASEUH3_SET(v)    (HW_USBC__PERIODICLISTBASEUH3_WR(HW_USBC__PERIODICLISTBASEUH3_RD() |  (v)))
#define HW_USBC__PERIODICLISTBASEUH3_CLR(v)    (HW_USBC__PERIODICLISTBASEUH3_WR(HW_USBC__PERIODICLISTBASEUH3_RD() & ~(v)))
#define HW_USBC__PERIODICLISTBASEUH3_TOG(v)    (HW_USBC__PERIODICLISTBASEUH3_WR(HW_USBC__PERIODICLISTBASEUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PERIODICLISTBASEUH3 bitfields
 */

/* --- Register HW_USBC__PERIODICLISTBASEUH3, field BASEADR[31:12] (RW)
 *
 * Base Address (Low). These bits correspond to memory address signals [31:12], respectively. Only
 * used by the host controller.
 */

#define BP_USBC__PERIODICLISTBASEUH3_BASEADR      (12)
#define BM_USBC__PERIODICLISTBASEUH3_BASEADR      (0xfffff000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PERIODICLISTBASEUH3_BASEADR(v)   ((((reg32_t) v) << 12) & BM_USBC__PERIODICLISTBASEUH3_BASEADR)
#else
#define BF_USBC__PERIODICLISTBASEUH3_BASEADR(v)   (((v) << 12) & BM_USBC__PERIODICLISTBASEUH3_BASEADR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASEADR field to a new value.
#define BW_USBC__PERIODICLISTBASEUH3_BASEADR(v)   BF_CS1(USBC__PERIODICLISTBASEUH3, BASEADR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__ASYNCLISTADDRUH3 - Next Asynch. Address UH3 (RW)
 *
 * Host Controller only  This 32-bit register contains the address of the next asynchronous queue
 * head to be executed by the host. Bits [4:0] of this register cannot be modified by the system
 * software and will always return a zero when read.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned ASYBASE : 27; //!< Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively. This field may only reference a Queue Head (QH). Only used by the host controller.
    } B;
} hw_usbc__asynclistaddruh3_t;
#endif

/*
 * constants & macros for entire USBC__ASYNCLISTADDRUH3 register
 */
#define HW_USBC__ASYNCLISTADDRUH3_ADDR      (REGS_USBC_BASE + 0x758)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__ASYNCLISTADDRUH3           (*(volatile hw_usbc__asynclistaddruh3_t *) HW_USBC__ASYNCLISTADDRUH3_ADDR)
#define HW_USBC__ASYNCLISTADDRUH3_RD()      (HW_USBC__ASYNCLISTADDRUH3.U)
#define HW_USBC__ASYNCLISTADDRUH3_WR(v)     (HW_USBC__ASYNCLISTADDRUH3.U = (v))
#define HW_USBC__ASYNCLISTADDRUH3_SET(v)    (HW_USBC__ASYNCLISTADDRUH3_WR(HW_USBC__ASYNCLISTADDRUH3_RD() |  (v)))
#define HW_USBC__ASYNCLISTADDRUH3_CLR(v)    (HW_USBC__ASYNCLISTADDRUH3_WR(HW_USBC__ASYNCLISTADDRUH3_RD() & ~(v)))
#define HW_USBC__ASYNCLISTADDRUH3_TOG(v)    (HW_USBC__ASYNCLISTADDRUH3_WR(HW_USBC__ASYNCLISTADDRUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__ASYNCLISTADDRUH3 bitfields
 */

/* --- Register HW_USBC__ASYNCLISTADDRUH3, field ASYBASE[31:5] (RW)
 *
 * Link Pointer Low (LPL). These bits correspond to memory address signals [31:5], respectively.
 * This field may only reference a Queue Head (QH). Only used by the host controller.
 */

#define BP_USBC__ASYNCLISTADDRUH3_ASYBASE      (5)
#define BM_USBC__ASYNCLISTADDRUH3_ASYBASE      (0xffffffe0)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__ASYNCLISTADDRUH3_ASYBASE(v)   ((((reg32_t) v) << 5) & BM_USBC__ASYNCLISTADDRUH3_ASYBASE)
#else
#define BF_USBC__ASYNCLISTADDRUH3_ASYBASE(v)   (((v) << 5) & BM_USBC__ASYNCLISTADDRUH3_ASYBASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ASYBASE field to a new value.
#define BW_USBC__ASYNCLISTADDRUH3_ASYBASE(v)   BF_CS1(USBC__ASYNCLISTADDRUH3, ASYBASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__BURSTSIZEUH3 - Programmable Burst Size UH3 (RW)
 *
 * This register is used to control the burst size used during data movement on the AHB master
 * interface. This register is ignored if AHBBRST bits in SBUSCFG register is non-zero value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RXPBURST : 8; //!< Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from the USB bus to system memory.
        unsigned TXPBURST : 9; //!< Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This register represents the maximum length of a the burst in 32-bit words while moving data from system memory to the USB bus.
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_usbc__burstsizeuh3_t;
#endif

/*
 * constants & macros for entire USBC__BURSTSIZEUH3 register
 */
#define HW_USBC__BURSTSIZEUH3_ADDR      (REGS_USBC_BASE + 0x760)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__BURSTSIZEUH3           (*(volatile hw_usbc__burstsizeuh3_t *) HW_USBC__BURSTSIZEUH3_ADDR)
#define HW_USBC__BURSTSIZEUH3_RD()      (HW_USBC__BURSTSIZEUH3.U)
#define HW_USBC__BURSTSIZEUH3_WR(v)     (HW_USBC__BURSTSIZEUH3.U = (v))
#define HW_USBC__BURSTSIZEUH3_SET(v)    (HW_USBC__BURSTSIZEUH3_WR(HW_USBC__BURSTSIZEUH3_RD() |  (v)))
#define HW_USBC__BURSTSIZEUH3_CLR(v)    (HW_USBC__BURSTSIZEUH3_WR(HW_USBC__BURSTSIZEUH3_RD() & ~(v)))
#define HW_USBC__BURSTSIZEUH3_TOG(v)    (HW_USBC__BURSTSIZEUH3_WR(HW_USBC__BURSTSIZEUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__BURSTSIZEUH3 bitfields
 */

/* --- Register HW_USBC__BURSTSIZEUH3, field RXPBURST[7:0] (RW)
 *
 * Programmable RX Burst Size. Default value is determined by TXBURST bits in n_HWRXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from the
 * USB bus to system memory.
 */

#define BP_USBC__BURSTSIZEUH3_RXPBURST      (0)
#define BM_USBC__BURSTSIZEUH3_RXPBURST      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUH3_RXPBURST(v)   ((((reg32_t) v) << 0) & BM_USBC__BURSTSIZEUH3_RXPBURST)
#else
#define BF_USBC__BURSTSIZEUH3_RXPBURST(v)   (((v) << 0) & BM_USBC__BURSTSIZEUH3_RXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUH3_RXPBURST(v)   BF_CS1(USBC__BURSTSIZEUH3, RXPBURST, v)
#endif

/* --- Register HW_USBC__BURSTSIZEUH3, field TXPBURST[16:8] (RW)
 *
 * Programmable TX Burst Size. Default value is determined by TXBURST bits in n_HWTXBUF. This
 * register represents the maximum length of a the burst in 32-bit words while moving data from
 * system memory to the USB bus.
 */

#define BP_USBC__BURSTSIZEUH3_TXPBURST      (8)
#define BM_USBC__BURSTSIZEUH3_TXPBURST      (0x0001ff00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__BURSTSIZEUH3_TXPBURST(v)   ((((reg32_t) v) << 8) & BM_USBC__BURSTSIZEUH3_TXPBURST)
#else
#define BF_USBC__BURSTSIZEUH3_TXPBURST(v)   (((v) << 8) & BM_USBC__BURSTSIZEUH3_TXPBURST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPBURST field to a new value.
#define BW_USBC__BURSTSIZEUH3_TXPBURST(v)   BF_CS1(USBC__BURSTSIZEUH3, TXPBURST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__TXFILLTUNINGUH3 - TX FIFO Fill Tuning UH3 (RW)
 *
 * The fields in this register control performance tuning associated with how the host controller
 * posts data to the TX latency FIFO before moving the data onto the USB bus. The specific areas of
 * performance include the how much data to post into the FIFO and an estimate for how long that
 * operation should take in the target system.  Definitions:  T 0 = Standard packet overhead  T 1 =
 * Time to send data payload  T ff = Time to fetch packet into TX FIFO up to specified level.  T s =
 * Total Packet Flight Time (send-only) packet  T s = T 0 + T 1   T p = Total Packet Time (fetch and
 * send) packet  T p = T ff + T 0 + T 1   Upon discovery of a transmit (OUT/SETUP) packet in the
 * data structures, host controller checks to ensure T  p  remains before the end of the
 * [micro]frame. If so it proceeds to pre-fill the TX FIFO. If at anytime during the pre-fill
 * operation the time remaining the [micro]frame is < T  s  then the packet attempt ceases and the
 * packet is tried at a later time. Although this is not an error condition and the host controller
 * will eventually recover, a mark will be made the scheduler health counter to note the occurrence
 * of a "back-off" event. When a back-off event is detected, the partial packet fetched may need to
 * be discarded from the latency buffer to make room for periodic traffic that will begin after the
 * next SOF. Too many back-off events can waste bandwidth and power on the system bus and thus
 * should be minimized (not necessarily eliminated). Back-offs can be minimized with use of the
 * n_TSCHHEALTH ( T  ff ) described below.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TXSCHOH : 8; //!< Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to the schedule time estimator described above as Tff. As an approximation, the value chosen for this register should limit the number of back-off events captured in the TXSCHHEALTH to less than 10 per second in a highly utilized bus. Choosing a value that is too high for this register is not desired as it can needlessly reduce USB utilization. The time unit represented in this register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned TXSCHHEALTH : 5; //!< Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of time to send the packet before the next Start-Of-Frame. This health counter measures the number of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register will clear the counter and this counter will max. at 31. Default value is '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned TXFIFOTHRES : 6; //!< FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum value is 2 and this value should be a low as possible to maximize USB performance. A higher value can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO may underrun because the data transferred from the latency FIFO to USB occurs before it can be replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3 controller core.
        unsigned RESERVED1 : 10; //!< Reserved
    } B;
} hw_usbc__txfilltuninguh3_t;
#endif

/*
 * constants & macros for entire USBC__TXFILLTUNINGUH3 register
 */
#define HW_USBC__TXFILLTUNINGUH3_ADDR      (REGS_USBC_BASE + 0x764)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__TXFILLTUNINGUH3           (*(volatile hw_usbc__txfilltuninguh3_t *) HW_USBC__TXFILLTUNINGUH3_ADDR)
#define HW_USBC__TXFILLTUNINGUH3_RD()      (HW_USBC__TXFILLTUNINGUH3.U)
#define HW_USBC__TXFILLTUNINGUH3_WR(v)     (HW_USBC__TXFILLTUNINGUH3.U = (v))
#define HW_USBC__TXFILLTUNINGUH3_SET(v)    (HW_USBC__TXFILLTUNINGUH3_WR(HW_USBC__TXFILLTUNINGUH3_RD() |  (v)))
#define HW_USBC__TXFILLTUNINGUH3_CLR(v)    (HW_USBC__TXFILLTUNINGUH3_WR(HW_USBC__TXFILLTUNINGUH3_RD() & ~(v)))
#define HW_USBC__TXFILLTUNINGUH3_TOG(v)    (HW_USBC__TXFILLTUNINGUH3_WR(HW_USBC__TXFILLTUNINGUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__TXFILLTUNINGUH3 bitfields
 */

/* --- Register HW_USBC__TXFILLTUNINGUH3, field TXSCHOH[7:0] (RW)
 *
 * Scheduler Overhead. (Read/Write) [Default = 0] This register adds an additional fixed offset to
 * the schedule time estimator described above as Tff. As an approximation, the value chosen for
 * this register should limit the number of back-off events captured in the TXSCHHEALTH to less than
 * 10 per second in a highly utilized bus. Choosing a value that is too high for this register is
 * not desired as it can needlessly reduce USB utilization. The time unit represented in this
 * register is 1.267us when a device is connected in High-Speed Mode. The time unit represented in
 * this register is 6.333us when a device is connected in Low/Full Speed Mode. Default value is
 * '08h' for OTG controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUH3_TXSCHOH      (0)
#define BM_USBC__TXFILLTUNINGUH3_TXSCHOH      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH3_TXSCHOH(v)   ((((reg32_t) v) << 0) & BM_USBC__TXFILLTUNINGUH3_TXSCHOH)
#else
#define BF_USBC__TXFILLTUNINGUH3_TXSCHOH(v)   (((v) << 0) & BM_USBC__TXFILLTUNINGUH3_TXSCHOH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHOH field to a new value.
#define BW_USBC__TXFILLTUNINGUH3_TXSCHOH(v)   BF_CS1(USBC__TXFILLTUNINGUH3, TXSCHOH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUH3, field TXSCHHEALTH[12:8] (RW)
 *
 * Scheduler Health Counter. (Read/Write To Clear) This register increments when the host controller
 * fails to fill the TX latency FIFO to the level programmed by TXFIFOTHRES before running out of
 * time to send the packet before the next Start-Of-Frame. This health counter measures the number
 * of times this occurs to provide feedback to selecting a proper TXSCHOH. Writing to this register
 * will clear the counter and this counter will max. at 31. Default value is '08h' for OTG
 * controller core, and '00h' for Host1/Host2/Host3 controller core.
 */

#define BP_USBC__TXFILLTUNINGUH3_TXSCHHEALTH      (8)
#define BM_USBC__TXFILLTUNINGUH3_TXSCHHEALTH      (0x00001f00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH3_TXSCHHEALTH(v)   ((((reg32_t) v) << 8) & BM_USBC__TXFILLTUNINGUH3_TXSCHHEALTH)
#else
#define BF_USBC__TXFILLTUNINGUH3_TXSCHHEALTH(v)   (((v) << 8) & BM_USBC__TXFILLTUNINGUH3_TXSCHHEALTH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXSCHHEALTH field to a new value.
#define BW_USBC__TXFILLTUNINGUH3_TXSCHHEALTH(v)   BF_CS1(USBC__TXFILLTUNINGUH3, TXSCHHEALTH, v)
#endif

/* --- Register HW_USBC__TXFILLTUNINGUH3, field TXFIFOTHRES[21:16] (RW)
 *
 * FIFO Burst Threshold. (Read/Write) This register controls the number of data bursts that are
 * posted to the TX latency FIFO in host mode before the packet begins on to the bus. The minimum
 * value is 2 and this value should be a low as possible to maximize USB performance. A higher value
 * can be used in systems with unpredictable latency and/or insufficient bandwidth where the FIFO
 * may underrun because the data transferred from the latency FIFO to USB occurs before it can be
 * replenished from system memory. This value is ignored if the Stream Disable bit in UOG_USBMODE
 * register is set. Default value is '00h' for OTG controller core, and '02h' for Host1/Host2/Host3
 * controller core.
 */

#define BP_USBC__TXFILLTUNINGUH3_TXFIFOTHRES      (16)
#define BM_USBC__TXFILLTUNINGUH3_TXFIFOTHRES      (0x003f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__TXFILLTUNINGUH3_TXFIFOTHRES(v)   ((((reg32_t) v) << 16) & BM_USBC__TXFILLTUNINGUH3_TXFIFOTHRES)
#else
#define BF_USBC__TXFILLTUNINGUH3_TXFIFOTHRES(v)   (((v) << 16) & BM_USBC__TXFILLTUNINGUH3_TXFIFOTHRES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXFIFOTHRES field to a new value.
#define BW_USBC__TXFILLTUNINGUH3_TXFIFOTHRES(v)   BF_CS1(USBC__TXFILLTUNINGUH3, TXFIFOTHRES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__IC_USBUH3 - IC_USB enable and voltage negotiation UH3 (RW)
 *
 * This register enable and controls the IC-USB FS/LS transceiver.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IC_VDD1 : 3; //!< These bits indicates which voltage is being supplied to the peripheral This field is read-only and set to 000 in case of a device controller.
        unsigned IC1 : 1; //!< Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1 is enabled, IOMUX must set the DP/DM pad into loopback mode.
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usbc__ic_usbuh3_t;
#endif

/*
 * constants & macros for entire USBC__IC_USBUH3 register
 */
#define HW_USBC__IC_USBUH3_ADDR      (REGS_USBC_BASE + 0x76c)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__IC_USBUH3           (*(volatile hw_usbc__ic_usbuh3_t *) HW_USBC__IC_USBUH3_ADDR)
#define HW_USBC__IC_USBUH3_RD()      (HW_USBC__IC_USBUH3.U)
#define HW_USBC__IC_USBUH3_WR(v)     (HW_USBC__IC_USBUH3.U = (v))
#define HW_USBC__IC_USBUH3_SET(v)    (HW_USBC__IC_USBUH3_WR(HW_USBC__IC_USBUH3_RD() |  (v)))
#define HW_USBC__IC_USBUH3_CLR(v)    (HW_USBC__IC_USBUH3_WR(HW_USBC__IC_USBUH3_RD() & ~(v)))
#define HW_USBC__IC_USBUH3_TOG(v)    (HW_USBC__IC_USBUH3_WR(HW_USBC__IC_USBUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__IC_USBUH3 bitfields
 */

/* --- Register HW_USBC__IC_USBUH3, field IC_VDD1[2:0] (RW)
 *
 * These bits indicates which voltage is being supplied to the peripheral This field is read-only
 * and set to 000 in case of a device controller.
 *
 * Values:
 * 000 - No voltage
 * 001 - 1.0 V
 * 010 - 1.2 V
 * 011 - 1.5 V
 * 100 - 1.8 V
 * 101 - 3.0 V
 * 110 - Reserved
 * 111 - Reserved
 */

#define BP_USBC__IC_USBUH3_IC_VDD1      (0)
#define BM_USBC__IC_USBUH3_IC_VDD1      (0x00000007)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUH3_IC_VDD1(v)   ((((reg32_t) v) << 0) & BM_USBC__IC_USBUH3_IC_VDD1)
#else
#define BF_USBC__IC_USBUH3_IC_VDD1(v)   (((v) << 0) & BM_USBC__IC_USBUH3_IC_VDD1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC_VDD1 field to a new value.
#define BW_USBC__IC_USBUH3_IC_VDD1(v)   BF_CS1(USBC__IC_USBUH3, IC_VDD1, v)
#endif


/* --- Register HW_USBC__IC_USBUH3, field IC1[3:3] (RW)
 *
 * Inter-Chip transceiver enable. This bits enable the Inter-Chip transceiver. To enable IC-USB
 * interface, PTS bits in PORTSC1 registers also need to be set correspondingly. Please see . If IC1
 * is enabled, IOMUX must set the DP/DM pad into loopback mode.
 */

#define BP_USBC__IC_USBUH3_IC1      (3)
#define BM_USBC__IC_USBUH3_IC1      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__IC_USBUH3_IC1(v)   ((((reg32_t) v) << 3) & BM_USBC__IC_USBUH3_IC1)
#else
#define BF_USBC__IC_USBUH3_IC1(v)   (((v) << 3) & BM_USBC__IC_USBUH3_IC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IC1 field to a new value.
#define BW_USBC__IC_USBUH3_IC1(v)   BF_CS1(USBC__IC_USBUH3, IC1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__PORTSC1UH3 - Port Status & Control UH3 (RW)
 *
 * Host Controller  A host controller could implement one to eight port status and control
 * registers. The number is determined by N_PORTs bits in HWSPARAMs register (please see ). Software
 * could read this parameter register to determine how many ports need service.  All 4 controller
 * cores are Single-Port Host, so there is only one port status and control register for each
 * controller core.  This register is only reset by power on reset or controller core reset. The
 * initial conditions of a port are:   No device connected  Port disabled   If the port supports
 * power control, this state remains until port power is supplied (by software).  Device Controller
 * A device controller has only port register one (PORTSC1) and it does not support power control.
 * Port control in device mode is only used for status port reset, suspend, and current connect
 * status. It is also used to initiate test mode or force signaling and allows software to put the
 * PHY into low power suspend mode and disable the PHY clock.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CCS : 1; //!< Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is present. Default = 0. This value reflects the current state of the port, and may not correspond directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached. Default=0. A one indicates that the device successfully attached and is operating in either high speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates that the device did not attach successfully or was forcibly disconnected by the software writing a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or suspended.
        unsigned CSC : 1; //!< Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device controller sets this bit for all changes to the port device connect status, even if system software has not cleared an existing connect status change. For example, the insertion status changes twice before system software has cleared the changed condition, hub hardware will be 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode: This bit is undefined in device controller mode.
        unsigned PE : 1; //!< Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be enabled by the host controller as a part of the reset and enable. Software cannot enable a port by writing a one to this field. Ports can be disabled by either a fault condition (disconnect event or other fault condition) or by the host software. Note that the bit status does not change until the port state actually changes. There may be a delay in disabling or enabling a port due to other host controller and bus events. When the port is disabled, (0b) downstream propagation of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In Device Mode: The device port is always enabled, so this bit is always '1b'.
        unsigned PEC : 1; //!< Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is always '0b'.
        unsigned OCA : 1; //!< Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero when the over current condition is removed. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned OCC : 1; //!< Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to Over-current Active. Software can clear this bit by writing a one to this bit position. For host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input for this condition. For device-only implementations this bit shall always be 0.
        unsigned FPR : 1; //!< Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state) detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will automatically change to zero after the resume sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the resume duration is timed in the driver. Note that when the Host controller owns the port, the resume sequence follows the defined sequence documented in the USB Specification Revision 2.0. The resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no affect because the port controller will time the resume operation clear the bit the port control state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or more, software must set this bit to one to drive resume signaling before clearing. The Device Controller will set this bit to one if a J-to-K transition is detected while the port is in the Suspend state. The bit will be cleared when the device returns to normal operation. Also, when this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the USBSTS register is also set to one.
        unsigned SUSP : 1; //!< Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend When in suspend state, downstream propagation of data is blocked on this port, except for port reset. The blocking occurs at the end of the current transaction if a transaction was in progress when this bit was written to 1. In the suspend state, the port is sensitive to resume detection. Note that the bit status does not change until the port is suspended and that there may be a delay in suspending a port if there is a transaction currently in progress on the The host controller will unconditionally set this bit to zero when software sets the Force Port Resume bit to zero. The host controller ignores a write of zero to this bit. If host software sets this bit to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only. In device mode this bit is a read only status bit.
        unsigned PR : 1; //!< Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset. 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence as defined in the USB Specification Revision 2.0 is started. This bit will automatically change to zero after the reset sequence is complete. This behavior is different from EHCI where the host controller driver is required to set this bit to a zero after the reset duration is timed in the driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
        unsigned HSP : 1; //!< High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the port is in high-speed mode and if set to zero, the host/device connected to the port is not in a high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
        unsigned LS : 2; //!< Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D- (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not necessary (unlike EHCI), because the port controller state machine and the port routing manage the connection of LS and FS. In device mode, the use of linestate by the device controller driver is not necessary. The encoding of the bits are: Bits [11:10] Meaning
        unsigned PP : 1; //!< Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP Operation 0 1b Read Only - Host controller does not have port power control switches. Each port is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not available on a port (that is, PP equals a 0), the port is non-functional and will not report attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is a one, the PP bit in each affected port may be transitional by the host controller driver from a one to a zero (removing power from the port). This feature is implemented in all 4 controller cores (PPC = 1).
        unsigned PO : 1; //!< Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever the Configured bit is zero System software uses this field to release ownership of the port to a selected host controller (in the event that the attached device is not a high-speed device). Software writes a one to this bit when the attached device is not a high-speed device. A one in this bit means that an internal companion controller owns and controls the port. Port owner handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
        unsigned PIC : 2; //!< Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0 for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit Value Meaning
        unsigned PTC : 4; //!< Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS} values will force the port into the connected and enabled state at the selected speed. Writing the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally from that point. Low speed operations are not supported as a peripheral device. Any other value than zero indicates that the port is operating in test mode. Value Specific Test
        unsigned WKCN : 1; //!< Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKDC : 1; //!< Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the port to be sensitive to device disconnects as wake-up events. This field is zero if Port Power( ) is zero or in device mode.
        unsigned WKOC : 1; //!< Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one enables the port to be sensitive to over-current conditions as wake-up events. This field is zero if Port Power( ) is zero.
        unsigned PHCD : 1; //!< PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock. The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically when the host initials resume. Before forcing a resume from the device, the device controller driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the downstream device has been put into suspend mode or when no downstream device is connected. Low power suspend is completely under the control of software.
        unsigned PFSC : 1; //!< Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port to identify itself as High Speed.
        unsigned PTS : 1; //!< See description at bits 31-30
        unsigned PSPD : 2; //!< Port Speed - Read Only. This register field indicates the speed at which the port is operating. For HS mode operation in the host controller and HS/FS operation in the device controller the port routing steers data to the Protocol engine. For FS and LS mode operation in the host controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction Translator.
        unsigned PTW : 1; //!< Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16 selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0 selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0; For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver Width This bit has no effect if serial interface engine is used. These register bits are implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3 core, it is Read-Only. Reset value is '1b'.
        unsigned STS : 1; //!< Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver interface is selected for FS and LS operation. The Serial Interface Engine can be used in combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for future operation and is a placeholder adding dynamic use of the serial engine in accord with UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita, OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select - Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value. Serial Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface signals. When this bit is set '1b', serial interface engine will be used instead of parallel interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless of this bit value.
        unsigned PTS1 : 2; //!< Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30, bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE = 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 - Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7; For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b" Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b" HSIC All USB port interface modes are listed in this field description, but not all are supported. For detail feature of each controller core, please see . The behaviour is unknown when unsupported interface mode is selected.
    } B;
} hw_usbc__portsc1uh3_t;
#endif

/*
 * constants & macros for entire USBC__PORTSC1UH3 register
 */
#define HW_USBC__PORTSC1UH3_ADDR      (REGS_USBC_BASE + 0x784)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__PORTSC1UH3           (*(volatile hw_usbc__portsc1uh3_t *) HW_USBC__PORTSC1UH3_ADDR)
#define HW_USBC__PORTSC1UH3_RD()      (HW_USBC__PORTSC1UH3.U)
#define HW_USBC__PORTSC1UH3_WR(v)     (HW_USBC__PORTSC1UH3.U = (v))
#define HW_USBC__PORTSC1UH3_SET(v)    (HW_USBC__PORTSC1UH3_WR(HW_USBC__PORTSC1UH3_RD() |  (v)))
#define HW_USBC__PORTSC1UH3_CLR(v)    (HW_USBC__PORTSC1UH3_WR(HW_USBC__PORTSC1UH3_RD() & ~(v)))
#define HW_USBC__PORTSC1UH3_TOG(v)    (HW_USBC__PORTSC1UH3_WR(HW_USBC__PORTSC1UH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__PORTSC1UH3 bitfields
 */

/* --- Register HW_USBC__PORTSC1UH3, field CCS[0:0] (RW)
 *
 * Current Connect Status-Read Only. In Host Mode: 1=Device is present on port. 0=No device is
 * present. Default = 0. This value reflects the current state of the port, and may not correspond
 * directly to the event that caused the Connect Status Change bit (Bit 1) to be set. This field is
 * zero if Port Power( ) is zero in host mode. In Device Mode: 1=Attached. 0=Not Attached.
 * Default=0. A one indicates that the device successfully attached and is operating in either high
 * speed or full speed as indicated by the High Speed Port bit in this register. A zero indicates
 * that the device did not attach successfully or was forcibly disconnected by the software writing
 * a zero to the Run bit in the USBCMD register. It does not state the device being disconnected or
 * suspended.
 */

#define BP_USBC__PORTSC1UH3_CCS      (0)
#define BM_USBC__PORTSC1UH3_CCS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_CCS(v)   ((((reg32_t) v) << 0) & BM_USBC__PORTSC1UH3_CCS)
#else
#define BF_USBC__PORTSC1UH3_CCS(v)   (((v) << 0) & BM_USBC__PORTSC1UH3_CCS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CCS field to a new value.
#define BW_USBC__PORTSC1UH3_CCS(v)   BF_CS1(USBC__PORTSC1UH3, CCS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field CSC[1:1] (RW)
 *
 * Connect Status Change-R/WC. 1 =Change in Current Connect Status. 0=No change. Default 0. In Host
 * Mode: Indicates a change has occurred in the port's Current Connect Status. The host/device
 * controller sets this bit for all changes to the port device connect status, even if system
 * software has not cleared an existing connect status change. For example, the insertion status
 * changes twice before system software has cleared the changed condition, hub hardware will be
 * 'setting' an already-set bit (that is, the bit will remain set). Software clears this bit by
 * writing a one to it. This field is zero if Port Power( ) is zero in host mode. In Device Mode:
 * This bit is undefined in device controller mode.
 */

#define BP_USBC__PORTSC1UH3_CSC      (1)
#define BM_USBC__PORTSC1UH3_CSC      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_CSC(v)   ((((reg32_t) v) << 1) & BM_USBC__PORTSC1UH3_CSC)
#else
#define BF_USBC__PORTSC1UH3_CSC(v)   (((v) << 1) & BM_USBC__PORTSC1UH3_CSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC field to a new value.
#define BW_USBC__PORTSC1UH3_CSC(v)   BF_CS1(USBC__PORTSC1UH3, CSC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PE[2:2] (RW)
 *
 * Port Enabled/Disabled-Read/Write. 1=Enable. 0=Disable. Default 0. In Host Mode: Ports can only be
 * enabled by the host controller as a part of the reset and enable. Software cannot enable a port
 * by writing a one to this field. Ports can be disabled by either a fault condition (disconnect
 * event or other fault condition) or by the host software. Note that the bit status does not change
 * until the port state actually changes. There may be a delay in disabling or enabling a port due
 * to other host controller and bus events. When the port is disabled, (0b) downstream propagation
 * of data is blocked except for reset. This field is zero if Port Power( ) is zero in host mode. In
 * Device Mode: The device port is always enabled, so this bit is always '1b'.
 */

#define BP_USBC__PORTSC1UH3_PE      (2)
#define BM_USBC__PORTSC1UH3_PE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PE(v)   ((((reg32_t) v) << 2) & BM_USBC__PORTSC1UH3_PE)
#else
#define BF_USBC__PORTSC1UH3_PE(v)   (((v) << 2) & BM_USBC__PORTSC1UH3_PE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PE field to a new value.
#define BW_USBC__PORTSC1UH3_PE(v)   BF_CS1(USBC__PORTSC1UH3, PE, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PEC[3:3] (RW)
 *
 * Port Enable/Disable Change-R/WC. 1=Port enabled/disabled status has changed. 0=No change. Default
 * = 0. In Host Mode: For the root hub, this bit is set to a one only when a port is disabled due to
 * disconnect on the port or due to the appropriate conditions existing at the EOF2 point (See
 * Chapter 11 of the USB Specification). Software clears this by writing a one to it. This field is
 * zero if Port Power( ) is zero. In Device mode: The device port is always enabled, so this bit is
 * always '0b'.
 */

#define BP_USBC__PORTSC1UH3_PEC      (3)
#define BM_USBC__PORTSC1UH3_PEC      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PEC(v)   ((((reg32_t) v) << 3) & BM_USBC__PORTSC1UH3_PEC)
#else
#define BF_USBC__PORTSC1UH3_PEC(v)   (((v) << 3) & BM_USBC__PORTSC1UH3_PEC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PEC field to a new value.
#define BW_USBC__PORTSC1UH3_PEC(v)   BF_CS1(USBC__PORTSC1UH3, PEC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field OCA[4:4] (RW)
 *
 * Over-current Active-Read Only. Default 0. This bit will automatically transition from one to zero
 * when the over current condition is removed. For host/OTG implementations the user can provide
 * over-current detection to the vbus_pwr_fault input for this condition. For device-only
 * implementations this bit shall always be 0.
 *
 * Values:
 * 0 - This port does not have an over-current condition.
 * 1 - This port currently has an over-current condition
 */

#define BP_USBC__PORTSC1UH3_OCA      (4)
#define BM_USBC__PORTSC1UH3_OCA      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_OCA(v)   ((((reg32_t) v) << 4) & BM_USBC__PORTSC1UH3_OCA)
#else
#define BF_USBC__PORTSC1UH3_OCA(v)   (((v) << 4) & BM_USBC__PORTSC1UH3_OCA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCA field to a new value.
#define BW_USBC__PORTSC1UH3_OCA(v)   BF_CS1(USBC__PORTSC1UH3, OCA, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field OCC[5:5] (RW)
 *
 * Over-current Change-R/WC. Default=0. This bit is set '1b' by hardware when there is a change to
 * Over-current Active. Software can clear this bit by writing a one to this bit position. For
 * host/OTG implementations the user can provide over-current detection to the vbus_pwr_fault input
 * for this condition. For device-only implementations this bit shall always be 0.
 */

#define BP_USBC__PORTSC1UH3_OCC      (5)
#define BM_USBC__PORTSC1UH3_OCC      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_OCC(v)   ((((reg32_t) v) << 5) & BM_USBC__PORTSC1UH3_OCC)
#else
#define BF_USBC__PORTSC1UH3_OCC(v)   (((v) << 5) & BM_USBC__PORTSC1UH3_OCC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OCC field to a new value.
#define BW_USBC__PORTSC1UH3_OCC(v)   BF_CS1(USBC__PORTSC1UH3, OCC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field FPR[6:6] (RW)
 *
 * Force Port Resume -Read/Write. 1= Resume detected/driven on port. 0=No resume (K-state)
 * detected/driven on port. Default = 0. In Host Mode: Software sets this bit to one to drive resume
 * signaling. The Host Controller sets this bit to one if a J-to-K transition is detected while the
 * port is in the Suspend state. When this bit transitions to a one because a J-to-K transition is
 * detected, the Port Change Detect bit in the USBSTS register is also set to one. This bit will
 * automatically change to zero after the resume sequence is complete. This behavior is different
 * from EHCI where the host controller driver is required to set this bit to a zero after the resume
 * duration is timed in the driver. Note that when the Host controller owns the port, the resume
 * sequence follows the defined sequence documented in the USB Specification Revision 2.0. The
 * resume signaling (Full-speed 'K') is driven on the port as long as this bit remains a one. This
 * bit will remain a one until the port has switched to the high-speed idle. Writing a zero has no
 * affect because the port controller will time the resume operation clear the bit the port control
 * state switches to HS or FS idle. This field is zero if Port Power( ) is zero in host mode. This
 * bit is not-EHCI compatible. In Device mode: After the device has been in Suspend State for 5ms or
 * more, software must set this bit to one to drive resume signaling before clearing. The Device
 * Controller will set this bit to one if a J-to-K transition is detected while the port is in the
 * Suspend state. The bit will be cleared when the device returns to normal operation. Also, when
 * this bit wil be cleared because a K-to-J transition detected, the Port Change Detect bit in the
 * USBSTS register is also set to one.
 */

#define BP_USBC__PORTSC1UH3_FPR      (6)
#define BM_USBC__PORTSC1UH3_FPR      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_FPR(v)   ((((reg32_t) v) << 6) & BM_USBC__PORTSC1UH3_FPR)
#else
#define BF_USBC__PORTSC1UH3_FPR(v)   (((v) << 6) & BM_USBC__PORTSC1UH3_FPR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FPR field to a new value.
#define BW_USBC__PORTSC1UH3_FPR(v)   BF_CS1(USBC__PORTSC1UH3, FPR, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field SUSP[7:7] (RW)
 *
 * Suspend - Read/Write or Read Only. Default = 0b. 1=Port in suspend state. 0=Port not in suspend
 * state. In Host Mode: Read/Write. Port Enabled Bit and Suspend bit of this register define the
 * port states as follows: Bits [Port Enabled, Suspend] Port State 0x Disable 10 Enable 11 Suspend
 * When in suspend state, downstream propagation of data is blocked on this port, except for port
 * reset. The blocking occurs at the end of the current transaction if a transaction was in progress
 * when this bit was written to 1. In the suspend state, the port is sensitive to resume detection.
 * Note that the bit status does not change until the port is suspended and that there may be a
 * delay in suspending a port if there is a transaction currently in progress on the The host
 * controller will unconditionally set this bit to zero when software sets the Force Port Resume bit
 * to zero. The host controller ignores a write of zero to this bit. If host software sets this bit
 * to a one when the port is not enabled (that is, Port enabled bit is a zero) the results are
 * undefined. This field is zero if Port Power( ) is zero in host mode. In Device Mode: Read Only.
 * In device mode this bit is a read only status bit.
 */

#define BP_USBC__PORTSC1UH3_SUSP      (7)
#define BM_USBC__PORTSC1UH3_SUSP      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_SUSP(v)   ((((reg32_t) v) << 7) & BM_USBC__PORTSC1UH3_SUSP)
#else
#define BF_USBC__PORTSC1UH3_SUSP(v)   (((v) << 7) & BM_USBC__PORTSC1UH3_SUSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUSP field to a new value.
#define BW_USBC__PORTSC1UH3_SUSP(v)   BF_CS1(USBC__PORTSC1UH3, SUSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PR[8:8] (RW)
 *
 * Port Reset - Read/Write or Read Only. Default = 0b. In Host Mode: Read/Write. 1=Port is in Reset.
 * 0=Port is not in Reset. Default 0. When software writes a one to this bit the bus-reset sequence
 * as defined in the USB Specification Revision 2.0 is started. This bit will automatically change
 * to zero after the reset sequence is complete. This behavior is different from EHCI where the host
 * controller driver is required to set this bit to a zero after the reset duration is timed in the
 * driver. In Device Mode: This bit is a read only status bit. Device reset from the USB bus is also
 * indicated in the USBSTS register. This field is zero if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UH3_PR      (8)
#define BM_USBC__PORTSC1UH3_PR      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PR(v)   ((((reg32_t) v) << 8) & BM_USBC__PORTSC1UH3_PR)
#else
#define BF_USBC__PORTSC1UH3_PR(v)   (((v) << 8) & BM_USBC__PORTSC1UH3_PR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PR field to a new value.
#define BW_USBC__PORTSC1UH3_PR(v)   BF_CS1(USBC__PORTSC1UH3, PR, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field HSP[9:9] (RW)
 *
 * High-Speed Port - Read Only. Default = 0b. When the bit is one, the host/device connected to the
 * port is in high-speed mode and if set to zero, the host/device connected to the port is not in a
 * high-speed mode. HSP is redundant with PSPD(bit 27, 26) but remained for compatibility.
 */

#define BP_USBC__PORTSC1UH3_HSP      (9)
#define BM_USBC__PORTSC1UH3_HSP      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_HSP(v)   ((((reg32_t) v) << 9) & BM_USBC__PORTSC1UH3_HSP)
#else
#define BF_USBC__PORTSC1UH3_HSP(v)   (((v) << 9) & BM_USBC__PORTSC1UH3_HSP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSP field to a new value.
#define BW_USBC__PORTSC1UH3_HSP(v)   BF_CS1(USBC__PORTSC1UH3, HSP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field LS[11:10] (RW)
 *
 * Line Status-Read Only. These bits reflect the current logical levels of the D+ (bit 11) and D-
 * (bit 10) signal lines. In host mode, the use of linestate by the host controller driver is not
 * necessary (unlike EHCI), because the port controller state machine and the port routing manage
 * the connection of LS and FS. In device mode, the use of linestate by the device controller driver
 * is not necessary. The encoding of the bits are: Bits [11:10] Meaning
 *
 * Values:
 * 00 - SE0
 * 01 - K-state
 * 10 - J-state
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH3_LS      (10)
#define BM_USBC__PORTSC1UH3_LS      (0x00000c00)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_LS(v)   ((((reg32_t) v) << 10) & BM_USBC__PORTSC1UH3_LS)
#else
#define BF_USBC__PORTSC1UH3_LS(v)   (((v) << 10) & BM_USBC__PORTSC1UH3_LS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LS field to a new value.
#define BW_USBC__PORTSC1UH3_LS(v)   BF_CS1(USBC__PORTSC1UH3, LS, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field PP[12:12] (RW)
 *
 * Port Power (PP)-Read/Write or Read Only. The function of this bit depends on the value of the
 * Port Power Switching (PPC) field in the HCSPARAMS register. The behavior is as follows: PPC PP
 * Operation 0 1b Read Only - Host controller does not have port power control switches. Each port
 * is hard-wired to power. 1 1b/0b - Read/Write. Host/OTG controller requires port power control
 * switches. This bit represents the current setting of the switch (0=off, 1=on). When power is not
 * available on a port (that is, PP equals a 0), the port is non-functional and will not report
 * attaches, detaches, etc. When an over-current condition is detected on a powered port and PPC is
 * a one, the PP bit in each affected port may be transitional by the host controller driver from a
 * one to a zero (removing power from the port). This feature is implemented in all 4 controller
 * cores (PPC = 1).
 */

#define BP_USBC__PORTSC1UH3_PP      (12)
#define BM_USBC__PORTSC1UH3_PP      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PP(v)   ((((reg32_t) v) << 12) & BM_USBC__PORTSC1UH3_PP)
#else
#define BF_USBC__PORTSC1UH3_PP(v)   (((v) << 12) & BM_USBC__PORTSC1UH3_PP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PP field to a new value.
#define BW_USBC__PORTSC1UH3_PP(v)   BF_CS1(USBC__PORTSC1UH3, PP, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PO[13:13] (RW)
 *
 * Port Owner-Read/Write. Default = 0. This bit unconditionally goes to a 0 when the configured bit
 * in the CONFIGFLAG register makes a 0 to 1 transition. This bit unconditionally goes to 1 whenever
 * the Configured bit is zero System software uses this field to release ownership of the port to a
 * selected host controller (in the event that the attached device is not a high-speed device).
 * Software writes a one to this bit when the attached device is not a high-speed device. A one in
 * this bit means that an internal companion controller owns and controls the port. Port owner
 * handoff is not supported in all 4 controller cores, therefore this bit will always be 0.
 */

#define BP_USBC__PORTSC1UH3_PO      (13)
#define BM_USBC__PORTSC1UH3_PO      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PO(v)   ((((reg32_t) v) << 13) & BM_USBC__PORTSC1UH3_PO)
#else
#define BF_USBC__PORTSC1UH3_PO(v)   (((v) << 13) & BM_USBC__PORTSC1UH3_PO)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PO field to a new value.
#define BW_USBC__PORTSC1UH3_PO(v)   BF_CS1(USBC__PORTSC1UH3, PO, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PIC[15:14] (RW)
 *
 * Port Indicator Control - Read/Write. Default = Ob. Writing to this field has no effect if the
 * P_INDICATOR bit in the HCSPARAMS register is a zero. Refer to the USB Specification Revision 2.0
 * for a description on how these bits are to be used. This field is zero if Port Power is zero. Bit
 * Value Meaning
 *
 * Values:
 * 00 - Port indicators are off
 * 01 - Amber
 * 10 - Green
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH3_PIC      (14)
#define BM_USBC__PORTSC1UH3_PIC      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PIC(v)   ((((reg32_t) v) << 14) & BM_USBC__PORTSC1UH3_PIC)
#else
#define BF_USBC__PORTSC1UH3_PIC(v)   (((v) << 14) & BM_USBC__PORTSC1UH3_PIC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PIC field to a new value.
#define BW_USBC__PORTSC1UH3_PIC(v)   BF_CS1(USBC__PORTSC1UH3, PIC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field PTC[19:16] (RW)
 *
 * Port Test Control - Read/Write. Default = 0000b. Refer to Section 4.14 for the operational model
 * for using these test modes and the USB Specification Revision 2.0, Chapter 7 for details on each
 * test mode. The FORCE_ENABLE_FS and FORCE ENABLE_LS are extensions to the test mode support
 * specified in the EHCI specification. Writing the PTC field to any of the FORCE_ENABLE_{HS/FS/LS}
 * values will force the port into the connected and enabled state at the selected speed. Writing
 * the PTC field back to TEST_MODE_DISABLE will allow the port state machines to progress normally
 * from that point. Low speed operations are not supported as a peripheral device. Any other value
 * than zero indicates that the port is operating in test mode. Value Specific Test
 *
 * Values:
 * 0000 - TEST_MODE_DISABLE
 * 0001 - J_STATE
 * 0010 - K_STATE
 * 0011 - SE0 (host) / NAK (device)
 * 0100 - Packet
 * 0101 - FORCE_ENABLE_HS
 * 0110 - FORCE_ENABLE_FS
 * 0111 - FORCE_ENABLE_LS
 * 1000-1111 - Reserved
 */

#define BP_USBC__PORTSC1UH3_PTC      (16)
#define BM_USBC__PORTSC1UH3_PTC      (0x000f0000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PTC(v)   ((((reg32_t) v) << 16) & BM_USBC__PORTSC1UH3_PTC)
#else
#define BF_USBC__PORTSC1UH3_PTC(v)   (((v) << 16) & BM_USBC__PORTSC1UH3_PTC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTC field to a new value.
#define BW_USBC__PORTSC1UH3_PTC(v)   BF_CS1(USBC__PORTSC1UH3, PTC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field WKCN[20:20] (RW)
 *
 * Wake on Connect Enable (WKCNNT_E) - Read/Write. Default=0b. Writing this bit to a one enables the
 * port to be sensitive to device connects as wake-up events. This field is zero if Port Power( ) is
 * zero or in device mode.
 */

#define BP_USBC__PORTSC1UH3_WKCN      (20)
#define BM_USBC__PORTSC1UH3_WKCN      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_WKCN(v)   ((((reg32_t) v) << 20) & BM_USBC__PORTSC1UH3_WKCN)
#else
#define BF_USBC__PORTSC1UH3_WKCN(v)   (((v) << 20) & BM_USBC__PORTSC1UH3_WKCN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKCN field to a new value.
#define BW_USBC__PORTSC1UH3_WKCN(v)   BF_CS1(USBC__PORTSC1UH3, WKCN, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field WKDC[21:21] (RW)
 *
 * Wake on Disconnect Enable (WKDSCNNT_E) - Read/Write. Default=0b. Writing this bit to a one
 * enables the port to be sensitive to device disconnects as wake-up events. This field is zero if
 * Port Power( ) is zero or in device mode.
 */

#define BP_USBC__PORTSC1UH3_WKDC      (21)
#define BM_USBC__PORTSC1UH3_WKDC      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_WKDC(v)   ((((reg32_t) v) << 21) & BM_USBC__PORTSC1UH3_WKDC)
#else
#define BF_USBC__PORTSC1UH3_WKDC(v)   (((v) << 21) & BM_USBC__PORTSC1UH3_WKDC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKDC field to a new value.
#define BW_USBC__PORTSC1UH3_WKDC(v)   BF_CS1(USBC__PORTSC1UH3, WKDC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field WKOC[22:22] (RW)
 *
 * Wake on Over-current Enable (WKOC_E) - Read/Write. Default = 0b. Writing this bit to a one
 * enables the port to be sensitive to over-current conditions as wake-up events. This field is zero
 * if Port Power( ) is zero.
 */

#define BP_USBC__PORTSC1UH3_WKOC      (22)
#define BM_USBC__PORTSC1UH3_WKOC      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_WKOC(v)   ((((reg32_t) v) << 22) & BM_USBC__PORTSC1UH3_WKOC)
#else
#define BF_USBC__PORTSC1UH3_WKOC(v)   (((v) << 22) & BM_USBC__PORTSC1UH3_WKOC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WKOC field to a new value.
#define BW_USBC__PORTSC1UH3_WKOC(v)   BF_CS1(USBC__PORTSC1UH3, WKOC, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PHCD[23:23] (RW)
 *
 * PHY Low Power Suspend - Clock Disable (PLPSCD) - Read/Write. Default = 0b. When this bit is set
 * to '1b', the PHY clock is disabled. Reading this bit will indicate the status of the PHY clock.
 * The PHY clock cannot be disabled if it is being used as the system clock. In device mode, The PHY
 * can be put into Low Power Suspend when the device is not running (USBCMD Run/Stop=0b) or the host
 * has signaled suspend (PORTSC1 SUSPEND=1b). PHY Low power suspend will be cleared automatically
 * when the host initials resume. Before forcing a resume from the device, the device controller
 * driver must clear this bit. In host mode, the PHY can be put into Low Power Suspend when the
 * downstream device has been put into suspend mode or when no downstream device is connected. Low
 * power suspend is completely under the control of software.
 *
 * Values:
 * 0 - Enable PHY clock
 * 1 - Disable PHY clock
 */

#define BP_USBC__PORTSC1UH3_PHCD      (23)
#define BM_USBC__PORTSC1UH3_PHCD      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PHCD(v)   ((((reg32_t) v) << 23) & BM_USBC__PORTSC1UH3_PHCD)
#else
#define BF_USBC__PORTSC1UH3_PHCD(v)   (((v) << 23) & BM_USBC__PORTSC1UH3_PHCD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHCD field to a new value.
#define BW_USBC__PORTSC1UH3_PHCD(v)   BF_CS1(USBC__PORTSC1UH3, PHCD, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field PFSC[24:24] (RW)
 *
 * Port Force Full Speed Connect - Read/Write. Default = 0b. When this bit is set to '1b', the port
 * will be forced to only connect at Full Speed, It disables the chirp sequence that allows the port
 * to identify itself as High Speed.
 *
 * Values:
 * 0 - Normal operation
 * 1 - Forced to full speed
 */

#define BP_USBC__PORTSC1UH3_PFSC      (24)
#define BM_USBC__PORTSC1UH3_PFSC      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PFSC(v)   ((((reg32_t) v) << 24) & BM_USBC__PORTSC1UH3_PFSC)
#else
#define BF_USBC__PORTSC1UH3_PFSC(v)   (((v) << 24) & BM_USBC__PORTSC1UH3_PFSC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PFSC field to a new value.
#define BW_USBC__PORTSC1UH3_PFSC(v)   BF_CS1(USBC__PORTSC1UH3, PFSC, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field PTS[25:25] (RW)
 *
 * See description at bits 31-30
 */

#define BP_USBC__PORTSC1UH3_PTS      (25)
#define BM_USBC__PORTSC1UH3_PTS      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PTS(v)   ((((reg32_t) v) << 25) & BM_USBC__PORTSC1UH3_PTS)
#else
#define BF_USBC__PORTSC1UH3_PTS(v)   (((v) << 25) & BM_USBC__PORTSC1UH3_PTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS field to a new value.
#define BW_USBC__PORTSC1UH3_PTS(v)   BF_CS1(USBC__PORTSC1UH3, PTS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PSPD[27:26] (RW)
 *
 * Port Speed - Read Only. This register field indicates the speed at which the port is operating.
 * For HS mode operation in the host controller and HS/FS operation in the device controller the
 * port routing steers data to the Protocol engine. For FS and LS mode operation in the host
 * controller, the port routing steers data to the Protocol Engine w/ Embedded Transaction
 * Translator.
 *
 * Values:
 * 00 - Full Speed
 * 01 - Low Speed
 * 10 - High Speed
 * 11 - Undefined
 */

#define BP_USBC__PORTSC1UH3_PSPD      (26)
#define BM_USBC__PORTSC1UH3_PSPD      (0x0c000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PSPD(v)   ((((reg32_t) v) << 26) & BM_USBC__PORTSC1UH3_PSPD)
#else
#define BF_USBC__PORTSC1UH3_PSPD(v)   (((v) << 26) & BM_USBC__PORTSC1UH3_PSPD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PSPD field to a new value.
#define BW_USBC__PORTSC1UH3_PSPD(v)   BF_CS1(USBC__PORTSC1UH3, PSPD, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field PTW[28:28] (RW)
 *
 * Parallel Transceiver Width - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY8_16 to control whether the data bus width of the UTMI
 * transceiver interface. If VUSB_HS_PHY8_16 is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY8_16 is 2 or 3 then this bit is read/write. This bit is reset to 1 if VUSB_HS_PHY8_16
 * selects a default UTMI interface width of 16-bits else it is reset to 0. Writing this bit to 0
 * selects the 8-bit [60MHz] UTMI interface. Writing this bit to 1 selects the 16-bit [30MHz] UTMI
 * interface. This bit has no effect if the Serial interfaces are selected. This bit is not defined
 * in the EHCI specification. VUSB_HS_PHY16_8 parameter: For Elvis, OTG: 3, Host1/Host2/Host3: 0;
 * For Rita, OTG/Host1/Host2/Host3: 3; For Arik, OTG/Host1/Host2/Host3: 1; Parallel Transceiver
 * Width This bit has no effect if serial interface engine is used. These register bits are
 * implementation dependent. For OTG controller core: it is Read/Write. Reset value is '1b'; For
 * Host1/Host2/Host3 controller core, it is Read-Only. Reset value is '0b'. For
 * OTG/Host1/Host2/Host3 core, it is Read/Write. Reset value is '1b'. For OTG/Host1/Host2/Host3
 * core, it is Read-Only. Reset value is '1b'.
 *
 * Values:
 * 1 - Select the 8-bit UTMI interface [60MHz]
 * 2 - Select the 16-bit UTMI interface [30MHz]
 */

#define BP_USBC__PORTSC1UH3_PTW      (28)
#define BM_USBC__PORTSC1UH3_PTW      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PTW(v)   ((((reg32_t) v) << 28) & BM_USBC__PORTSC1UH3_PTW)
#else
#define BF_USBC__PORTSC1UH3_PTW(v)   (((v) << 28) & BM_USBC__PORTSC1UH3_PTW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTW field to a new value.
#define BW_USBC__PORTSC1UH3_PTW(v)   BF_CS1(USBC__PORTSC1UH3, PTW, v)
#endif


/* --- Register HW_USBC__PORTSC1UH3, field STS[29:29] (RW)
 *
 * Serial Transceiver Select - Read/Write. This register bit is used in conjunction with the
 * configuration constant VUSB_HS_PHY_SERIAL to control whether the parallel or serial transceiver
 * interface is selected for FS and LS operation. The Serial Interface Engine can be used in
 * combination with the UTMI+ or ULPI physical interface to provide FS/LS signaling instead of the
 * parallel interface. If VUSB_HS_PHY_SERIAL is set for 0 or 1 then this bit is read only. If
 * VUSB_HS_PHY_SERIAL is 3 or 4 then this bit is read/write. This bit has no effect unless Parallel
 * Transceiver Select is set to UTMI+ or ULPI. The Serial/1.1 physical interface will use the Serial
 * Interface Engine for FS/LS signaling regardless of this bit value. Note: This bit is reserved for
 * future operation and is a placeholder adding dynamic use of the serial engine in accord with
 * UMTI+ and ULPI characterization logic. This bit is not defined in the EHCI specification
 * VUSB_HS_PHY_SERIAL parameter: For Elivs,OTG/Host1/Host2/Host3 core: 2 For Rita,
 * OTG/Host1/Host2/Host3 core: 2 For Arik, OTG/Host1/Host2/Host3 core: 0 Serial Transceiver Select -
 * Read/Write. Reset value is 0b. 1 Serial Interface Engine is selected 0 Parallel Interface signals
 * is selected Serial Interface Engine can be used in combination with UTMI+/ULPI physical interface
 * to provide FS/LS signaling instead of the parallel interface signals. When this bit is set '1b',
 * serial interface engine will be used instead of parallel interface signals. This bit has no
 * effect unless PTS bits is set to select UTMI+/ULPI interface. The Serial/USB1.1 PHY/IC-USB will
 * use the serial interface engine for FS/LS signaling regardless of this bit value. Serial
 * Transceiver Select - Read-Only. Reset value is 0b. 1 Serial Interface Engine is selected 0
 * Parallel Interface signals is selected Serial Interface Engine can be used in combination with
 * UTMI+/ULPI physical interface to provide FS/LS signaling instead of the Parallel Interface
 * signals. When this bit is set '1b', serial interface engine will be used instead of parallel
 * interface signals. This bit has no effect unless PTS bits is set to select UTMI+/ULPI interface.
 * The Serial/USB1.1 PHY/IC-USB will use the serial interface engine for FS/LS signaling regardless
 * of this bit value.
 */

#define BP_USBC__PORTSC1UH3_STS      (29)
#define BM_USBC__PORTSC1UH3_STS      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_STS(v)   ((((reg32_t) v) << 29) & BM_USBC__PORTSC1UH3_STS)
#else
#define BF_USBC__PORTSC1UH3_STS(v)   (((v) << 29) & BM_USBC__PORTSC1UH3_STS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the STS field to a new value.
#define BW_USBC__PORTSC1UH3_STS(v)   BF_CS1(USBC__PORTSC1UH3, STS, v)
#endif

/* --- Register HW_USBC__PORTSC1UH3, field PTS1[31:30] (RW)
 *
 * Parallel Transceiver Select - Read/Write. This register bit pair is used in conjunction with the
 * configuration constant VUSB_HS_PHY_TYPE to control which parallel transceiver interface is
 * selected. If VUSB_HS_PHY_TYPE is set for 0,1,2, 3, 8 or 10 then this bit is read only. If
 * VUSB_HS_PHY_TYPE is 4,5, 6, 7, 9 or 11then this bit is read/write. Bit field {bit25, bit30,
 * bit31} is reset to: "000b" if VUSB_HS_PHY_TYPE = 0,4 - UTMI/UTMI+ "001b" if VUSB_HS_PHY_TYPE =
 * 1,5 - Reserved "010b" if VUSB_HS_PHY_TYPE = 2,6 - ULPI "011b" if VUSB_HS_PHY_TYPE = 3,7,8,9 -
 * Serial/1.1 PHY/IC USB(FS Only) "100b" if VUSB_HS_PHY_TYPE = 10,11 - UTMI for HSIC PHY This bit is
 * not defined in the EHCI specification. VUSB_HS_PHY_TYPE parameter: For Elvis, OTG/Host core: 7;
 * For Rita, OTG core: 0, Host core: 7 For Arik, OTG core: 0, Host core: 4 Parallel Transceiver
 * Select (bit31, bi30). These register bits are implementation dependent. For OTG/Host1/Host2/Host3
 * core, it is Read/Write. Reset value is '11b'. Bit field { bit31, bit30}: "00b" UTMI/UTMI+ "01b"
 * Reserved "10b" ULPI "11b" Serial/USB 1.1 PHY/IC-USB (FS Only) Parallel Transceiver Select (bit25,
 * bit31, bi30). These register bits are implementation dependent. For OTG core, it's Read-Only.
 * Reset value is 000b. For Host1/Host2/Host3 core, it's Read/Write. Reset value is 011b. Bit field
 * {bit25, bit31, bit30}: "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY
 * /IC-USB (FS Only) "100b" HSIC Parallel Transceiver Select (bit25, bit31, bi30). These register
 * bits are implementation dependent. For OTG core, it is Read-Only. Reset value is 000b. For
 * Host1/Host2/Host3 core, it is Read/Write. Reset value is 000b. Bit field {bit25, bit31, bit30}:
 * "000b" UTMI/UTMI+ "001b" Reserved "010b" ULPI "011b" Serial/USB 1.1 PHY/IC-USB (FS Only) "100b"
 * HSIC All USB port interface modes are listed in this field description, but not all are
 * supported. For detail feature of each controller core, please see . The behaviour is unknown when
 * unsupported interface mode is selected.
 */

#define BP_USBC__PORTSC1UH3_PTS1      (30)
#define BM_USBC__PORTSC1UH3_PTS1      (0xc0000000)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__PORTSC1UH3_PTS1(v)   ((((reg32_t) v) << 30) & BM_USBC__PORTSC1UH3_PTS1)
#else
#define BF_USBC__PORTSC1UH3_PTS1(v)   (((v) << 30) & BM_USBC__PORTSC1UH3_PTS1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PTS1 field to a new value.
#define BW_USBC__PORTSC1UH3_PTS1(v)   BF_CS1(USBC__PORTSC1UH3, PTS1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USBC__USBMODEUH3 - USB Device Mode UH3 (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CM : 2; //!< Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device only implementations. For those designs that contain both host & device capability, the controller defaults to an idle state and needs to be initialized to the desired operating mode after reset. For combination host/device controllers, this register can only be written once after reset. If it is necessary to switch modes, software must reset the controller by writing to the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core, reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
        unsigned ES : 1; //!< Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to match the host microprocessor. The bit fields in the microprocessor interface and the data structures are unaffected by the value of this bit because they are based upon the 32-bit word. Bit Meaning
        unsigned SLOM : 1; //!< Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
        unsigned SDIS : 1; //!< Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX and TX buffers are sufficient to contain an entire packet that the standard double buffering scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High Speed Mode, all packets received are responded to with a NYET handshake when stream disable is active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to characterize the adjustments needed for the scheduler when using this feature. The use of this feature substantially limits of the overall USB performance that can be achieved.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RESERVED2 : 16; //!< Reserved
    } B;
} hw_usbc__usbmodeuh3_t;
#endif

/*
 * constants & macros for entire USBC__USBMODEUH3 register
 */
#define HW_USBC__USBMODEUH3_ADDR      (REGS_USBC_BASE + 0x7a8)

#ifndef __LANGUAGE_ASM__
#define HW_USBC__USBMODEUH3           (*(volatile hw_usbc__usbmodeuh3_t *) HW_USBC__USBMODEUH3_ADDR)
#define HW_USBC__USBMODEUH3_RD()      (HW_USBC__USBMODEUH3.U)
#define HW_USBC__USBMODEUH3_WR(v)     (HW_USBC__USBMODEUH3.U = (v))
#define HW_USBC__USBMODEUH3_SET(v)    (HW_USBC__USBMODEUH3_WR(HW_USBC__USBMODEUH3_RD() |  (v)))
#define HW_USBC__USBMODEUH3_CLR(v)    (HW_USBC__USBMODEUH3_WR(HW_USBC__USBMODEUH3_RD() & ~(v)))
#define HW_USBC__USBMODEUH3_TOG(v)    (HW_USBC__USBMODEUH3_WR(HW_USBC__USBMODEUH3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual USBC__USBMODEUH3 bitfields
 */

/* --- Register HW_USBC__USBMODEUH3, field CM[1:0] (RW)
 *
 * Controller Mode - R/WO. Controller mode is defaulted to the proper mode for host only and device
 * only implementations. For those designs that contain both host & device capability, the
 * controller defaults to an idle state and needs to be initialized to the desired operating mode
 * after reset. For combination host/device controllers, this register can only be written once
 * after reset. If it is necessary to switch modes, software must reset the controller by writing to
 * the RESET bit in the USBCMD register before reprogramming this register. For OTG controller core,
 * reset value is '00b'. For Host1/Host2/Host3 controller core, reset value is '11b'. Bit Meaning
 *
 * Values:
 * 00 - Idle [Default for combination host/device]
 * 01 - Reserved
 * 10 - Device Controller [Default for device only controller]
 * 11 - Host Controller [Default for host only controller]
 */

#define BP_USBC__USBMODEUH3_CM      (0)
#define BM_USBC__USBMODEUH3_CM      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH3_CM(v)   ((((reg32_t) v) << 0) & BM_USBC__USBMODEUH3_CM)
#else
#define BF_USBC__USBMODEUH3_CM(v)   (((v) << 0) & BM_USBC__USBMODEUH3_CM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CM field to a new value.
#define BW_USBC__USBMODEUH3_CM(v)   BF_CS1(USBC__USBMODEUH3, CM, v)
#endif


/* --- Register HW_USBC__USBMODEUH3, field ES[2:2] (RW)
 *
 * Endian Select - Read/Write. This bit can change the byte alignment of the transfer buffers to
 * match the host microprocessor. The bit fields in the microprocessor interface and the data
 * structures are unaffected by the value of this bit because they are based upon the 32-bit word.
 * Bit Meaning
 *
 * Values:
 * 0 - Little Endian [Default]
 * 1 - Big Endian
 */

#define BP_USBC__USBMODEUH3_ES      (2)
#define BM_USBC__USBMODEUH3_ES      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH3_ES(v)   ((((reg32_t) v) << 2) & BM_USBC__USBMODEUH3_ES)
#else
#define BF_USBC__USBMODEUH3_ES(v)   (((v) << 2) & BM_USBC__USBMODEUH3_ES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ES field to a new value.
#define BW_USBC__USBMODEUH3_ES(v)   BF_CS1(USBC__USBMODEUH3, ES, v)
#endif


/* --- Register HW_USBC__USBMODEUH3, field SLOM[3:3] (RW)
 *
 * Setup Lockout Mode. In device mode, this bit controls behavior of the setup lock mechanism. See .
 *
 * Values:
 * 0 - Setup Lockouts On (default);
 * 1 - Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in .
 */

#define BP_USBC__USBMODEUH3_SLOM      (3)
#define BM_USBC__USBMODEUH3_SLOM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH3_SLOM(v)   ((((reg32_t) v) << 3) & BM_USBC__USBMODEUH3_SLOM)
#else
#define BF_USBC__USBMODEUH3_SLOM(v)   (((v) << 3) & BM_USBC__USBMODEUH3_SLOM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SLOM field to a new value.
#define BW_USBC__USBMODEUH3_SLOM(v)   BF_CS1(USBC__USBMODEUH3, SLOM, v)
#endif


/* --- Register HW_USBC__USBMODEUH3, field SDIS[4:4] (RW)
 *
 * Stream Disable Mode. (0 - Inactive [default]; 1 - Active) Device Mode: Setting to a '1' disables
 * double priming on both RX and TX for low bandwidth systems. This mode ensures that when the RX
 * and TX buffers are sufficient to contain an entire packet that the standard double buffering
 * scheme is disabled to prevent overruns/underruns in bandwidth limited systems. Note: In High
 * Speed Mode, all packets received are responded to with a NYET handshake when stream disable is
 * active. Host Mode: Setting to a '1' ensures that overruns/underruns of the latency FIFO are
 * eliminated for low bandwidth systems where the RX and TX buffers are sufficient to contain the
 * entire packet. Enabling stream disable also has the effect of ensuring the TX latency is filled
 * to capacity before the packet is launched onto the USB. Time duration to pre-fill the FIFO
 * becomes significant when stream disable is active. See and TXTTFILLTUNING [MPH Only] to
 * characterize the adjustments needed for the scheduler when using this feature. The use of this
 * feature substantially limits of the overall USB performance that can be achieved.
 */

#define BP_USBC__USBMODEUH3_SDIS      (4)
#define BM_USBC__USBMODEUH3_SDIS      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_USBC__USBMODEUH3_SDIS(v)   ((((reg32_t) v) << 4) & BM_USBC__USBMODEUH3_SDIS)
#else
#define BF_USBC__USBMODEUH3_SDIS(v)   (((v) << 4) & BM_USBC__USBMODEUH3_SDIS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SDIS field to a new value.
#define BW_USBC__USBMODEUH3_SDIS(v)   BF_CS1(USBC__USBMODEUH3, SDIS, v)
#endif


/*!
 * @brief All USBC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_usbc__iduog_t _IDUOG; //!< Identification register UOG
    volatile hw_usbc__hwgeneraluog_t _HWGENERALUOG; //!< Hardware General UOG
    volatile hw_usbc__hwhostuog_t _HWHOSTUOG; //!< Host Hardware Parameters UOG
    volatile hw_usbc_uog_hwdevice_t UOG_HWDEVICE; //!< Device Hardware Parameters
    volatile hw_usbc__hwtxbufuog_t _HWTXBUFUOG; //!< TX Buffer Hardware Parameters UOG
    volatile hw_usbc__hwrxbufuog_t _HWRXBUFUOG; //!< RX Buffer Hardware Parameters UOG
    reg32_t _reserved0[26];
    volatile hw_usbc__gptimer0lduog_t _GPTIMER0LDUOG; //!< General Purpose Timer #0 Load UOG
    volatile hw_usbc__gptimer0ctrluog_t _GPTIMER0CTRLUOG; //!< General Purpose Timer #0 Controller UOG
    volatile hw_usbc__gptimer1lduog_t _GPTIMER1LDUOG; //!< General Purpose Timer #1 Load UOG
    volatile hw_usbc__gptimer1ctrluog_t _GPTIMER1CTRLUOG; //!< General Purpose Timer #1 Controller UOG
    volatile hw_usbc__sbuscfguog_t _SBUSCFGUOG; //!< System Bus Config UOG
    reg32_t _reserved1[27];
    volatile hw_usbc__caplengthuog_t _CAPLENGTHUOG; //!< Capability Register Length UOG
    reg8_t _reserved2;
    volatile hw_usbc__hciversionuog_t _HCIVERSIONUOG; //!< Host Controller Interface Version UOG
    volatile hw_usbc__hcsparamsuog_t _HCSPARAMSUOG; //!< Host Controller Structural Parameters UOG
    volatile hw_usbc__hccparamsuog_t _HCCPARAMSUOG; //!< Host Controller Capability Parameters UOG
    reg32_t _reserved3[5];
    volatile hw_usbc_uog_dciversion_t UOG_DCIVERSION; //!< Device Controller Interface Version
    reg16_t _reserved4;
    volatile hw_usbc_uog_dccparams_t UOG_DCCPARAMS; //!< Device Controller Capability Parameters
    reg32_t _reserved5[6];
    volatile hw_usbc__usbcmduog_t _USBCMDUOG; //!< USB Command Register UOG
    volatile hw_usbc__usbstsuog_t _USBSTSUOG; //!< USB Status Register UOG
    volatile hw_usbc__usbintruog_t _USBINTRUOG; //!< Interrupt Enable Register UOG
    volatile hw_usbc__frindexuog_t _FRINDEXUOG; //!< USB Frame Index UOG
    reg32_t _reserved6;
    volatile hw_usbc__periodiclistbaseuog_t _PERIODICLISTBASEUOG; //!< Frame List Base Address UOG
    volatile hw_usbc__asynclistaddruog_t _ASYNCLISTADDRUOG; //!< Next Asynch. Address UOG
    reg32_t _reserved7;
    volatile hw_usbc__burstsizeuog_t _BURSTSIZEUOG; //!< Programmable Burst Size UOG
    volatile hw_usbc__txfilltuninguog_t _TXFILLTUNINGUOG; //!< TX FIFO Fill Tuning UOG
    reg32_t _reserved8;
    volatile hw_usbc__ic_usbuog_t _IC_USBUOG; //!< IC_USB enable and voltage negotiation UOG
    reg32_t _reserved9[2];
    volatile hw_usbc_uog_endptnak_t UOG_ENDPTNAK; //!< Endpoint NAK
    volatile hw_usbc_uog_endptnaken_t UOG_ENDPTNAKEN; //!< Endpoint Nake Enable
    reg32_t _reserved10;
    volatile hw_usbc__portsc1uog_t _PORTSC1UOG; //!< Port Status & Control UOG
    reg32_t _reserved11[7];
    volatile hw_usbc_uog_otgsc_t UOG_OTGSC; //!< On-The-Go Status & control
    volatile hw_usbc__usbmodeuog_t _USBMODEUOG; //!< USB Device Mode UOG
    volatile hw_usbc_uog_endptsetupstat_t UOG_ENDPTSETUPSTAT; //!< Endpoint Setup Status
    volatile hw_usbc_uog_endptprime_t UOG_ENDPTPRIME; //!< Endpoint Initialization
    volatile hw_usbc_uog_endptflush_t UOG_ENDPTFLUSH; //!< Endpoint De-Initialize
    volatile hw_usbc_uog_endptstat_t UOG_ENDPTSTAT; //!< Endpoint Status
    volatile hw_usbc_uog_endptcomplete_t UOG_ENDPTCOMPLETE; //!< Endpoint Complete
    volatile hw_usbc_uog_endptctrl0_t UOG_ENDPTCTRL0; //!< Endpoint Control0
    volatile hw_usbc_uog_endptctrl1_t UOG_ENDPTCTRL1; //!< Endpoint Controln 1
    volatile hw_usbc_uog_endptctrl2_t UOG_ENDPTCTRL2; //!< Endpoint Controln 2
    volatile hw_usbc_uog_endptctrl3_t UOG_ENDPTCTRL3; //!< Endpoint Controln 3
    volatile hw_usbc_uog_endptctrl4_t UOG_ENDPTCTRL4; //!< Endpoint Controln 4
    volatile hw_usbc_uog_endptctrl5_t UOG_ENDPTCTRL5; //!< Endpoint Controln 5
    volatile hw_usbc_uog_endptctrl6_t UOG_ENDPTCTRL6; //!< Endpoint Controln 6
    volatile hw_usbc_uog_endptctrl7_t UOG_ENDPTCTRL7; //!< Endpoint Controln 7
    reg32_t _reserved12[8];
    volatile hw_usbc__iduh1_t _IDUH1; //!< Identification register UH1
    volatile hw_usbc__hwgeneraluh1_t _HWGENERALUH1; //!< Hardware General UH1
    volatile hw_usbc__hwhostuh1_t _HWHOSTUH1; //!< Host Hardware Parameters UH1
    reg32_t _reserved13;
    volatile hw_usbc__hwtxbufuh1_t _HWTXBUFUH1; //!< TX Buffer Hardware Parameters UH1
    volatile hw_usbc__hwrxbufuh1_t _HWRXBUFUH1; //!< RX Buffer Hardware Parameters UH1
    reg32_t _reserved14[26];
    volatile hw_usbc__gptimer0lduh1_t _GPTIMER0LDUH1; //!< General Purpose Timer #0 Load UH1
    volatile hw_usbc__gptimer0ctrluh1_t _GPTIMER0CTRLUH1; //!< General Purpose Timer #0 Controller UH1
    volatile hw_usbc__gptimer1lduh1_t _GPTIMER1LDUH1; //!< General Purpose Timer #1 Load UH1
    volatile hw_usbc__gptimer1ctrluh1_t _GPTIMER1CTRLUH1; //!< General Purpose Timer #1 Controller UH1
    volatile hw_usbc__sbuscfguh1_t _SBUSCFGUH1; //!< System Bus Config UH1
    reg32_t _reserved15[27];
    volatile hw_usbc__caplengthuh1_t _CAPLENGTHUH1; //!< Capability Register Length UH1
    reg8_t _reserved16;
    volatile hw_usbc__hciversionuh1_t _HCIVERSIONUH1; //!< Host Controller Interface Version UH1
    volatile hw_usbc__hcsparamsuh1_t _HCSPARAMSUH1; //!< Host Controller Structural Parameters UH1
    volatile hw_usbc__hccparamsuh1_t _HCCPARAMSUH1; //!< Host Controller Capability Parameters UH1
    reg32_t _reserved17[13];
    volatile hw_usbc__usbcmduh1_t _USBCMDUH1; //!< USB Command Register UH1
    volatile hw_usbc__usbstsuh1_t _USBSTSUH1; //!< USB Status Register UH1
    volatile hw_usbc__usbintruh1_t _USBINTRUH1; //!< Interrupt Enable Register UH1
    volatile hw_usbc__frindexuh1_t _FRINDEXUH1; //!< USB Frame Index UH1
    reg32_t _reserved18;
    volatile hw_usbc__periodiclistbaseuh1_t _PERIODICLISTBASEUH1; //!< Frame List Base Address UH1
    volatile hw_usbc__asynclistaddruh1_t _ASYNCLISTADDRUH1; //!< Next Asynch. Address UH1
    reg32_t _reserved19;
    volatile hw_usbc__burstsizeuh1_t _BURSTSIZEUH1; //!< Programmable Burst Size UH1
    volatile hw_usbc__txfilltuninguh1_t _TXFILLTUNINGUH1; //!< TX FIFO Fill Tuning UH1
    reg32_t _reserved20;
    volatile hw_usbc__ic_usbuh1_t _IC_USBUH1; //!< IC_USB enable and voltage negotiation UH1
    reg32_t _reserved21[5];
    volatile hw_usbc__portsc1uh1_t _PORTSC1UH1; //!< Port Status & Control UH1
    reg32_t _reserved22[8];
    volatile hw_usbc__usbmodeuh1_t _USBMODEUH1; //!< USB Device Mode UH1
    reg32_t _reserved23[21];
    volatile hw_usbc__iduh2_t _IDUH2; //!< Identification register UH2
    volatile hw_usbc__hwgeneraluh2_t _HWGENERALUH2; //!< Hardware General UH2
    volatile hw_usbc__hwhostuh2_t _HWHOSTUH2; //!< Host Hardware Parameters UH2
    reg32_t _reserved24;
    volatile hw_usbc__hwtxbufuh2_t _HWTXBUFUH2; //!< TX Buffer Hardware Parameters UH2
    volatile hw_usbc__hwrxbufuh2_t _HWRXBUFUH2; //!< RX Buffer Hardware Parameters UH2
    reg32_t _reserved25[26];
    volatile hw_usbc__gptimer0lduh2_t _GPTIMER0LDUH2; //!< General Purpose Timer #0 Load UH2
    volatile hw_usbc__gptimer0ctrluh2_t _GPTIMER0CTRLUH2; //!< General Purpose Timer #0 Controller UH2
    volatile hw_usbc__gptimer1lduh2_t _GPTIMER1LDUH2; //!< General Purpose Timer #1 Load UH2
    volatile hw_usbc__gptimer1ctrluh2_t _GPTIMER1CTRLUH2; //!< General Purpose Timer #1 Controller UH2
    volatile hw_usbc__sbuscfguh2_t _SBUSCFGUH2; //!< System Bus Config UH2
    reg32_t _reserved26[27];
    volatile hw_usbc__caplengthuh2_t _CAPLENGTHUH2; //!< Capability Register Length UH2
    reg8_t _reserved27;
    volatile hw_usbc__hciversionuh2_t _HCIVERSIONUH2; //!< Host Controller Interface Version UH2
    volatile hw_usbc__hcsparamsuh2_t _HCSPARAMSUH2; //!< Host Controller Structural Parameters UH2
    volatile hw_usbc__hccparamsuh2_t _HCCPARAMSUH2; //!< Host Controller Capability Parameters UH2
    reg32_t _reserved28[13];
    volatile hw_usbc__usbcmduh2_t _USBCMDUH2; //!< USB Command Register UH2
    volatile hw_usbc__usbstsuh2_t _USBSTSUH2; //!< USB Status Register UH2
    volatile hw_usbc__usbintruh2_t _USBINTRUH2; //!< Interrupt Enable Register UH2
    volatile hw_usbc__frindexuh2_t _FRINDEXUH2; //!< USB Frame Index UH2
    reg32_t _reserved29;
    volatile hw_usbc__periodiclistbaseuh2_t _PERIODICLISTBASEUH2; //!< Frame List Base Address UH2
    volatile hw_usbc__asynclistaddruh2_t _ASYNCLISTADDRUH2; //!< Next Asynch. Address UH2
    reg32_t _reserved30;
    volatile hw_usbc__burstsizeuh2_t _BURSTSIZEUH2; //!< Programmable Burst Size UH2
    volatile hw_usbc__txfilltuninguh2_t _TXFILLTUNINGUH2; //!< TX FIFO Fill Tuning UH2
    reg32_t _reserved31;
    volatile hw_usbc__ic_usbuh2_t _IC_USBUH2; //!< IC_USB enable and voltage negotiation UH2
    reg32_t _reserved32[5];
    volatile hw_usbc__portsc1uh2_t _PORTSC1UH2; //!< Port Status & Control UH2
    reg32_t _reserved33[8];
    volatile hw_usbc__usbmodeuh2_t _USBMODEUH2; //!< USB Device Mode UH2
    reg32_t _reserved34[21];
    volatile hw_usbc__iduh3_t _IDUH3; //!< Identification register UH3
    volatile hw_usbc__hwgeneraluh3_t _HWGENERALUH3; //!< Hardware General UH3
    volatile hw_usbc__hwhostuh3_t _HWHOSTUH3; //!< Host Hardware Parameters UH3
    reg32_t _reserved35;
    volatile hw_usbc__hwtxbufuh3_t _HWTXBUFUH3; //!< TX Buffer Hardware Parameters UH3
    volatile hw_usbc__hwrxbufuh3_t _HWRXBUFUH3; //!< RX Buffer Hardware Parameters UH3
    reg32_t _reserved36[26];
    volatile hw_usbc__gptimer0lduh3_t _GPTIMER0LDUH3; //!< General Purpose Timer #0 Load UH3
    volatile hw_usbc__gptimer0ctrluh3_t _GPTIMER0CTRLUH3; //!< General Purpose Timer #0 Controller UH3
    volatile hw_usbc__gptimer1lduh3_t _GPTIMER1LDUH3; //!< General Purpose Timer #1 Load UH3
    volatile hw_usbc__gptimer1ctrluh3_t _GPTIMER1CTRLUH3; //!< General Purpose Timer #1 Controller UH3
    volatile hw_usbc__sbuscfguh3_t _SBUSCFGUH3; //!< System Bus Config UH3
    reg32_t _reserved37[27];
    volatile hw_usbc__caplengthuh3_t _CAPLENGTHUH3; //!< Capability Register Length UH3
    reg8_t _reserved38;
    volatile hw_usbc__hciversionuh3_t _HCIVERSIONUH3; //!< Host Controller Interface Version UH3
    volatile hw_usbc__hcsparamsuh3_t _HCSPARAMSUH3; //!< Host Controller Structural Parameters UH3
    volatile hw_usbc__hccparamsuh3_t _HCCPARAMSUH3; //!< Host Controller Capability Parameters UH3
    reg32_t _reserved39[13];
    volatile hw_usbc__usbcmduh3_t _USBCMDUH3; //!< USB Command Register UH3
    volatile hw_usbc__usbstsuh3_t _USBSTSUH3; //!< USB Status Register UH3
    volatile hw_usbc__usbintruh3_t _USBINTRUH3; //!< Interrupt Enable Register UH3
    volatile hw_usbc__frindexuh3_t _FRINDEXUH3; //!< USB Frame Index UH3
    reg32_t _reserved40;
    volatile hw_usbc__periodiclistbaseuh3_t _PERIODICLISTBASEUH3; //!< Frame List Base Address UH3
    volatile hw_usbc__asynclistaddruh3_t _ASYNCLISTADDRUH3; //!< Next Asynch. Address UH3
    reg32_t _reserved41;
    volatile hw_usbc__burstsizeuh3_t _BURSTSIZEUH3; //!< Programmable Burst Size UH3
    volatile hw_usbc__txfilltuninguh3_t _TXFILLTUNINGUH3; //!< TX FIFO Fill Tuning UH3
    reg32_t _reserved42;
    volatile hw_usbc__ic_usbuh3_t _IC_USBUH3; //!< IC_USB enable and voltage negotiation UH3
    reg32_t _reserved43[5];
    volatile hw_usbc__portsc1uh3_t _PORTSC1UH3; //!< Port Status & Control UH3
    reg32_t _reserved44[8];
    volatile hw_usbc__usbmodeuh3_t _USBMODEUH3; //!< USB Device Mode UH3
} hw_usbc_t;
#endif

//! @brief Macro to access all USBC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USBC(0)</code>.
#define HW_USBC     (*(volatile hw_usbc_t *) REGS_USBC_BASE)


#endif // _USBC_H
