/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#include "io.h"
/*!
 * @file usb_registers.h
 * @brief USB controller registers and bit definitions.
 *
 */
#ifndef __USB_REGISTERS__
#define __USB_REGISTERS__

typedef struct usbRegisters
{
	volatile uint32_t USB_ID;
	volatile uint32_t USB_HWGENERAL;
	volatile uint32_t USB_HWHOST;
	volatile uint32_t USB_HWDEVICE;
	volatile uint32_t USB_HWTXBUF;
	volatile uint32_t USB_HWRXBUF;
	volatile uint8_t  unused1[0x90 - 0x18];
	volatile uint32_t USB_SBUSCFG;
	volatile uint8_t  unused2[0x100 - 0x94];
	volatile uint8_t  USB_CAPLENGTH;
	volatile uint8_t  unused3;
	volatile uint16_t USB_HCIVERSION;
	volatile uint32_t USB_HCSPARAMS;
	volatile uint32_t USB_HCCPARAMS;
	volatile uint8_t  unused4[0x122 - 0x10C];
	volatile uint16_t USB_DCIVERSION;
	volatile uint32_t USB_DCCPARAMS;
	volatile uint8_t  unused5[0x140 - 0x128];
	volatile uint32_t USB_USBCMD;
	volatile uint32_t USB_USBSTS;
	volatile uint32_t USB_USBINTR;
	volatile uint32_t USB_FRINDEX;
	volatile uint8_t  unused6[4];
	volatile uint32_t USB_PERIODICLISTBASE; /* also USB_DEVICEADDR */
	volatile uint32_t USB_ASYNCLISTADDR; /* also USB_ENDPOINTLISTADDR */
	volatile uint32_t USB_TTCTRL;
	volatile uint32_t USB_BURSTSIZE;
	volatile uint32_t USB_TXFILLTUNING; /* 0x164 */
	volatile uint8_t  unused7[0x170 - 0x168];
	volatile uint32_t USB_ULPIVIEPORT;  /* 0x170 */
	volatile uint8_t  unused8[0x178 - 0x174];
	volatile uint32_t USB_ENDPTNAK;
	volatile uint32_t USB_ENDPTNAKEN;
	volatile uint32_t USB_CONFIGFLAG;
	volatile uint32_t USB_PORTSC;
	volatile uint8_t  unused9[0x1A4 - 0x188];
	volatile uint32_t USB_OTGSC;
	volatile uint32_t USB_USBMODE;
	volatile uint32_t USB_ENDPTSETUPSTAT;
	volatile uint32_t USB_ENDPTPRIME;
	volatile uint32_t USB_ENDPTFLUSH;
	volatile uint32_t USB_ENDPTSTATUS;
	volatile uint32_t USB_ENDPTCOMPLETE;
	volatile uint32_t USB_ENDPTCTRL[8];
} usbRegisters_t;

/*! USB_DEVICEADDR and USB_PERIODICLISTBASE share the same address */
#define USB_DEVICEADDR			USB_PERIODICLISTBASE
/*!  USB_ENDPOINTLISTADDR and USB_ASYNCLISTADDR share the same address */
#define USB_ENDPOINTLISTADDR	USB_ASYNCLISTADDR

/* Bit definitions and macros for USB_ID */
#define USB_ID_ID(x)                     (((x)&0x3F)<<0)
#define USB_ID_NID(x)                    (((x)&0x3F)<<0x8)
#define USB_ID_REVISION(x)               (((x)&0xFF)<<0x10)

/* Bit definitions and macros for USB_HWGENERAL */
#define USB_HWGENERAL_RT                 (0x1)
#define USB_HWGENERAL_CLKC(x)            (((x)&0x3)<<0x1)
#define USB_HWGENERAL_BWT                (0x8)
#define USB_HWGENERAL_PHYW(x)            (((x)&0x3)<<0x4)
#define USB_HWGENERAL_PHYM(x)            (((x)&0x7)<<0x6)
#define USB_HWGENERAL_SM(x)              (((x)&0x3)<<0x9)

/* Bit definitions and macros for USB_HWHOST */
#define USB_HWHOST_HC                    (0x1)
#define USB_HWHOST_NPORT(x)              (((x)&0x7)<<0x1)
#define USB_HWHOST_TTASY(x)              (((x)&0xFF)<<0x10)
#define USB_HWHOST_TTPER(x)              (((x)&0xFF)<<0x18)

/* Bit definitions and macros for USB_HWDEVICE */
#define USB_HWDEVICE_DC                  (0x1)
#define USB_HWDEVICE_DEVEP(x)            (((x)&0x1F)<<0x1)

/* Bit definitions and macros for USB_HWTXBUF */
#define USB_HWTXBUF_TXBURST(x)           (((x)&0xFF)<<0)
#define USB_HWTXBUF_TXADD(x)             (((x)&0xFF)<<0x8)
#define USB_HWTXBUF_TXCHANADD(x)         (((x)&0xFF)<<0x10)
#define USB_HWTXBUF_TXLC                 (0x80000000)

/* Bit definitions and macros for USB_HWRXBUF */
#define USB_HWRXBUF_RXBURST(x)           (((x)&0xFF)<<0)
#define USB_HWRXBUF_RXADD(x)             (((x)&0xFF)<<0x8)

/* Bit definitions and macros for USB_HCIVERSION */
#define USB_HCIVERSION_HCIVERSION(x)     (((x)&0xFFFF)<<0)

/* Bit definitions and macros for USB_CAPLENGTH */
#define USB_CAPLENGTH_CAPLENGTH(x)       (((x)&0xFF)<<0)

/* Bit definitions and macros for USB_HCSPARAMS */
#define USB_HCSPARAMS_N_PORTS(x)         (((x)&0xF)<<0)
#define USB_HCSPARAMS_PPC                (0x10)
#define USB_HCSPARAMS_N_PCC(x)           (((x)&0xF)<<0x8)
#define USB_HCSPARAMS_N_CC(x)            (((x)&0xF)<<0xC)
#define USB_HCSPARAMS_PI                 (0x10000)
#define USB_HCSPARAMS_N_PTT(x)           (((x)&0xF)<<0x14)
#define USB_HCSPARAMS_N_TT(x)            (((x)&0xF)<<0x18)

/* Bit definitions and macros for USB_HCCPARAMS */
#define USB_HCCPARAMS_ADC                (0x1)
#define USB_HCCPARAMS_PFL                (0x2)
#define USB_HCCPARAMS_ASP                (0x4)
#define USB_HCCPARAMS_IST(x)             (((x)&0xF)<<0x4)
#define USB_HCCPARAMS_EECP(x)            (((x)&0xFF)<<0x8)

/* Bit definitions and macros for USB_DCIVERSION */
#define USB_DCIVERSION_DCIVERSION(x)     (((x)&0xFFFF)<<0)

/* Bit definitions and macros for USB_DCCPARAMS */
#define USB_DCCPARAMS_DEN(x)             (((x)&0x1F)<<0)
#define USB_DCCPARAMS_DC                 (0x80)
#define USB_DCCPARAMS_HC                 (0x100)

/* Bit definitions and macros for USB_USBCMD */
#define USB_USBCMD_RS                    (0x1)
#define USB_USBCMD_RST                   (0x2)
#define USB_USBCMD_FS0                   (0x4)
#define USB_USBCMD_FS1                   (0x8)
#define USB_USBCMD_PSE                   (0x10)
#define USB_USBCMD_ASE                   (0x20)
#define USB_USBCMD_IAA                   (0x40)
#define USB_USBCMD_LR                    (0x80)
#define USB_USBCMD_ASP(x)                (((x)&0x3)<<0x8)
#define USB_USBCMD_ASPE                  (0x800)
#define USB_USBCMD_SUTW                  (0x2000)
#define USB_USBCMD_ATDTW                 (0x4000)
#define USB_USBCMD_FS2                   (0x8000)
#define USB_USBCMD_ITC(x)                (((x)&0xFF)<<0x10)
#define USB_USBCMD_ITC_IMM               (0)
#define USB_USBCMD_ITC_1                 (0x10000)
#define USB_USBCMD_ITC_2                 (0x20000)
#define USB_USBCMD_ITC_4                 (0x40000)
#define USB_USBCMD_ITC_8                 (0x80000)
#define USB_USBCMD_ITC_16                (0x100000)
#define USB_USBCMD_ITC_32                (0x200000)
#define USB_USBCMD_ITC_40                (0x400000)
#define USB_USBCMD_FS_1024               (0)
#define USB_USBCMD_FS_512                (0x4)
#define USB_USBCMD_FS_256                (0x8)
#define USB_USBCMD_FS_128                (0xC)
#define USB_USBCMD_FS_64                 (0x8000)
#define USB_USBCMD_FS_32                 (0x8004)
#define USB_USBCMD_FS_16                 (0x8008)
#define USB_USBCMD_FS_8                  (0x800C)
#define USB_USBCMD_FS_MASK               (0x0000800C)

/* Bit definitions and macros for USB_USBSTS */
#define USB_USBSTS_UI                    (0x1)
#define USB_USBSTS_UEI                   (0x2)
#define USB_USBSTS_PCI                   (0x4)
#define USB_USBSTS_FRI                   (0x8)
#define USB_USBSTS_SEI                   (0x10)
#define USB_USBSTS_AAI                   (0x20)
#define USB_USBSTS_URI                   (0x40)
#define USB_USBSTS_SRI                   (0x80)
#define USB_USBSTS_SLI                   (0x100)
#define USB_USBSTS_HCH                   (0x1000)
#define USB_USBSTS_RCL                   (0x2000)
#define USB_USBSTS_PS                    (0x4000)
#define USB_USBSTS_AS                    (0x8000)
#define USB_USBSTS_UAI					 (0x40000)
#define USB_USBSTS_UPI					 (0x80000)

/* Bit definitions and macros for USB_USBINTR */
#define USB_USBINTR_UE                   (0x1)
#define USB_USBINTR_UEE                  (0x2)
#define USB_USBINTR_PCE                  (0x4)
#define USB_USBINTR_FRE                  (0x8)
#define USB_USBINTR_SEE                  (0x10)
#define USB_USBINTR_AAE                  (0x20)
#define USB_USBINTR_URE                  (0x40)
#define USB_USBINTR_SRE                  (0x80)
#define USB_USBINTR_SLE                  (0x100)

/* Bit definitions and macros for USB_FRINDEX */
#define USB_FRINDEX_FRINDEX(x)           (((x)&0x3FFF)<<0)

/* Bit definitions and macros for USB_PERIODICLISTBASE */
#define USB_PERIODICLISTBASE_PERBASE(x)  (((x)&0xFFFFF)<<0xC)

/* Bit definitions and macros for USB_DEVICEADDR */
#define USB_DEVICEADDR_USBADR(x)         (((x)&0x7F)<<0x19)

/* Bit definitions and macros for USB_ENDPOINTLISTADDR */
#define USB_ENDPOINTLISTADDR_EPBASE(x)   (((x)&0x1FFFFF)<<0xB)

/* Bit definitions and macros for USB_ASYNCLISTADDR */
#define USB_ASYNCLISTADDR_ASYBASE(x)     (((x)&0x7FFFFFF)<<0x5)

/* Bit definitions and macros for USB_TTCTRL */
#define USB_TTCTRL_TTHA(x)               (((x)&0x7F)<<0x18)

/* Bit definitions and macros for USB_BURSTSIZE */
#define USB_BURSTSIZE_RXPBURST(x)        (((x)&0xFF)<<0)
#define USB_BURSTSIZE_TXPBURST(x)        (((x)&0xFF)<<0x8)

/* Bit definitions and macros for USB_TXFILLTUNING */
#define USB_TXFILLTUNING_TXSCHOH(x)      (((x)&0xFF)<<0)
#define USB_TXFILLTUNING_TXSCHHEALTH(x)  (((x)&0x1F)<<0x8)
#define USB_TXFILLTUNING_TXFIFOTHRES(x)  (((x)&0x3F)<<0x10)

/* Bit definitions and macros for USB_CONFIGFLAG */
#define USB_CONFIGFLAG_CONFIGFLAG(x)     (((x)&0xFFFFFFFF)<<0)

/* Bit definitions and macros for USB_PORTSC */
#define USB_PORTSC_CCS                   (0x1)
#define USB_PORTSC_CSC                   (0x2)
#define USB_PORTSC_PE                    (0x4)
#define USB_PORTSC_PEC                   (0x8)
#define USB_PORTSC_OCA                   (0x10)
#define USB_PORTSC_OCC                   (0x20)
#define USB_PORTSC_FPR                   (0x40)
#define USB_PORTSC_SUSP                  (0x80)
#define USB_PORTSC_PR                    (0x100)
#define USB_PORTSC_LS(x)                 (((x)&0x3)<<0xA)
#define USB_PORTSC_LS_SE0                (0)
#define USB_PORTSC_LS_JSTATE             (0x400)
#define USB_PORTSC_LS_KSTATE             (0x800)
#define USB_PORTSC_PP                    (0x1000)
#define USB_PORTSC_PO                    (0x2000)
#define USB_PORTSC_PIC(x)                (((x)&0x3)<<0xE)
#define USB_PORTSC_PIC_OFF               (0)
#define USB_PORTSC_PIC_AMBER             (0x4000)
#define USB_PORTSC_PIC_GREEN             (0x8000)
#define USB_PORTSC_PTC(x)                (((x)&0xF)<<0x10)
#define USB_PORTSC_PTC_DISABLE           (0)
#define USB_PORTSC_PTC_JSTATE            (0x10000)
#define USB_PORTSC_PTC_KSTATE            (0x20000)
#define USB_PORTSC_PTC_SEQ_NAK           (0x30000)
#define USB_PORTSC_PTC_PACKET            (0x40000)
#define USB_PORTSC_PTC_FORCE_ENABLE      (0x50000)
#define USB_PORTSC_WKCN                  (0x100000)
#define USB_PORTSC_WKDS                  (0x200000)
#define USB_PORTSC_WKOC                  (0x400000)
#define USB_PORTSC_PHCD                  (0x800000)
#define USB_PORTSC_PFSC                  (0x1000000)
#define USB_PORTSC_PSPD(x)               (((x)&0x3)<<0x1A)
#define USB_PORTSC_PSPD_FULL             (0)
#define USB_PORTSC_PSPD_LOW              (0x4000000)
#define USB_PORTSC_PSPD_HIGH             (0x8000000)
#define USB_PORTSC_PTW                   (0x10000000)
#define USB_PORTSC_PTS(x)                (((x)&0x3)<<0x1E)
#define USB_PORTSC_PTS_UTMI              (0)
#define USB_PORTSC_PTS_ULPI              (2 << 30)
#define USB_PORTSC_PTS_SER               (3 << 30)

/* Bit definitions and macros for USB_OTGSC */
#define USB_OTGSC_VD                     (0x1)
#define USB_OTGSC_VC                     (0x2)
#define USB_OTGSC_OT                     (0x8)
#define USB_OTGSC_DP                     (0x10)
#define USB_OTGSC_IDPU                   (0x20)
#define USB_OTGSC_ID                     (0x100)
#define USB_OTGSC_AVV                    (0x200)
#define USB_OTGSC_ASV                    (0x400)
#define USB_OTGSC_BSV                    (0x800)
#define USB_OTGSC_BSE                    (0x1000)
#define USB_OTGSC_1msT                   (0x2000)
#define USB_OTGSC_DPS                    (0x4000)
#define USB_OTGSC_IDIS                   (0x10000)
#define USB_OTGSC_AVVIS                  (0x20000)
#define USB_OTGSC_ASVIS                  (0x40000)
#define USB_OTGSC_BSVIS                  (0x80000)
#define USB_OTGSC_BSEIS                  (0x100000)
#define USB_OTGSC_1msS                   (0x200000)
#define USB_OTGSC_DPIS                   (0x400000)
#define USB_OTGSC_IDIE                   (0x1000000)
#define USB_OTGSC_AVVIE                  (0x2000000)
#define USB_OTGSC_ASVIE                  (0x4000000)
#define USB_OTGSC_BSVIE                  (0x8000000)
#define USB_OTGSC_BSEIE                  (0x10000000)
#define USB_OTGSC_1msE                   (0x20000000)
#define USB_OTGSC_DPIE                   (0x40000000)
#define USB_OTGSC_CLEAR                  (0x7F0000)
#define USB_OTGSC_ENABLE_ALL             (0x7F000000)

/* Bit definitions and macros for USB_USBMODE */
#define USB_USBMODE_CM(x)                (((x)&0x3)<<0)
#define USB_USBMODE_CM_IDLE              (0)
#define USB_USBMODE_CM_DEVICE            (0x2)
#define USB_USBMODE_CM_HOST              (0x3)
#define USB_USBMODE_ES					 (0x4)
#define USB_USBMODE_SLOM                 (0x8)
#define USB_USBMODE_SDIS                 (0x10)
/* Bit definitions and macros for USB_ENDPTSETUPSTAT */
#define USB_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x) (((x)&0xF)<<0)

/* Bit definitions and macros for USB_ENDPTPRIME */
#define USB_ENDPTPRIME_PERB0             (0x1)
#define USB_ENDPTPRIME_PERB1             (0x2)
#define USB_ENDPTPRIME_PERB2             (0x4)
#define USB_ENDPTPRIME_PERB3             (0x8)
#define USB_ENDPTPRIME_PETB0             (0x10000)
#define USB_ENDPTPRIME_PETB1             (0x20000)
#define USB_ENDPTPRIME_PETB2             (0x40000)
#define USB_ENDPTPRIME_PETB3             (0x80000)
#define USB_ENDPTPRIME_PERB(x)           (((x)&0x3F)<<0)
#define USB_ENDPTPRIME_PETB(x)           (((x)&0x3F)<<0x10)

/* Bit definitions and macros for USB_ENDPTFLUSH */
#define USB_ENDPTFLUSH_FERB0             (0x1)
#define USB_ENDPTFLUSH_FERB1             (0x2)
#define USB_ENDPTFLUSH_FERB2             (0x4)
#define USB_ENDPTFLUSH_FERB3             (0x8)
#define USB_ENDPTFLUSH_FETB0             (0x10000)
#define USB_ENDPTFLUSH_FETB1             (0x20000)
#define USB_ENDPTFLUSH_FETB2             (0x40000)
#define USB_ENDPTFLUSH_FETB3             (0x80000)
#define USB_ENDPTFLUSH_FERB(x)           (((x)&0x3F)<<0)
#define USB_ENDPTFLUSH_FETB(x)           (((x)&0x3F)<<0x10)

/* Bit definitions and macros for USB_ENDPTSTATUS */
#define USB_ENDPTSTATUS_ERBR0            (0x1)
#define USB_ENDPTSTATUS_ERBR1            (0x2)
#define USB_ENDPTSTATUS_ERBR2            (0x4)
#define USB_ENDPTSTATUS_ERBR3            (0x8)
#define USB_ENDPTSTATUS_ETBR0            (0x10000)
#define USB_ENDPTSTATUS_ETBR1            (0x20000)
#define USB_ENDPTSTATUS_ETBR2            (0x40000)
#define USB_ENDPTSTATUS_ETBR3            (0x80000)
#define USB_ENDPTSTATUS_ERBR(x)          (((x)&0x3F)<<0)
#define USB_ENDPTSTATUS_ETBR(x)          (((x)&0x3F)<<0x10)

/* Bit definitions and macros for USB_ENDPTCOMPLETE */
#define USB_ENDPTCOMPLETE_ERCE0          (0x1)
#define USB_ENDPTCOMPLETE_ERCE1          (0x2)
#define USB_ENDPTCOMPLETE_ERCE2          (0x4)
#define USB_ENDPTCOMPLETE_ERCE3          (0x8)
#define USB_ENDPTCOMPLETE_ETCE0          (0x10000)
#define USB_ENDPTCOMPLETE_ETCE1          (0x20000)
#define USB_ENDPTCOMPLETE_ETCE2          (0x40000)
#define USB_ENDPTCOMPLETE_ETCE3          (0x80000)
#define USB_ENDPTCOMPLETE_ERCE(x)        (((x)&0x3F)<<0)
#define USB_ENDPTCOMPLETE_ETCE(x)        (((x)&0x3F)<<0x10)

/* Bit definitions and macros for USB_ENDPTCTRL0 */
#define USB_ENDPTCTRL0_RXS               (0x1)
#define USB_ENDPTCTRL0_RXT(x)            (((x)&0x3)<<0x2)
#define USB_ENDPTCTRL0_RXE               (0x80)
#define USB_ENDPTCTRL0_TXS               (0x10000)
#define USB_ENDPTCTRL0_TXT(x)            (((x)&0x3)<<0x12)
#define USB_ENDPTCTRL0_TXE               (0x800000)

/* Bit definitions and macros for USB_ENDPTCTRL */
#define USB_ENDPTCTRL_RXS                (0x1)
#define USB_ENDPTCTRL_RXD                (0x2)
#define USB_ENDPTCTRL_RXT(x)             (((x)&0x3)<<0x2)
#define USB_ENDPTCTRL_RXT_CONTROL        (0)
#define USB_ENDPTCTRL_RXT_ISO            (0x4)
#define USB_ENDPTCTRL_RXT_BULK           (0x8)
#define USB_ENDPTCTRL_RXT_INT            (0xC)
#define USB_ENDPTCTRL_RXI                (0x20)
#define USB_ENDPTCTRL_RXR                (0x40)
#define USB_ENDPTCTRL_RXE                (0x80)
#define USB_ENDPTCTRL_TXS                (0x10000)
#define USB_ENDPTCTRL_TXD                (0x20000)
#define USB_ENDPTCTRL_TXT(x)             (((x)&0x3)<<0x12)
#define USB_ENDPTCTRL_TXT_CONTROL        (0)
#define USB_ENDPTCTRL_TXT_ISO            (0x40000)
#define USB_ENDPTCTRL_TXT_BULK           (0x80000)
#define USB_ENDPTCTRL_TXT_INT            (0xC0000)
#define USB_ENDPTCTRL_TXI                (0x200000)
#define USB_ENDPTCTRL_TXR                (0x400000)
#define USB_ENDPTCTRL_TXE                (0x800000)

#endif /* __USB_REGISTER_STRUCT__*/
