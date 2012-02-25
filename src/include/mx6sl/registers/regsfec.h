/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _FEC_H
#define _FEC_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_FEC_EIR - Ethernet interrupt event register
 * - HW_FEC_EIMR - Ethernet interrupt mask register
 * - HW_FEC_RDAR - Receive descriptor active register
 * - HW_FEC_TDAR - Transmit descriptor active register
 * - HW_FEC_ECR - Ethernet control register
 * - HW_FEC_MMFR - MII management frame register
 * - HW_FEC_MSCR - MII speed control register
 * - HW_FEC_MIBC - MIB control register
 * - HW_FEC_RCR - Receive control register
 * - HW_FEC_TCR - Transmit control register
 * - HW_FEC_PALR - Physical address low register
 * - HW_FEC_PAUR - Physical address upper register
 * - HW_FEC_OPDR - Opcode and pause duration register
 * - HW_FEC_IAUR - Descriptor individual address upper register
 * - HW_FEC_IALR - Descriptor individual address lower register
 * - HW_FEC_GAUR - Descriptor group address upper register
 * - HW_FEC_GALR - Descriptor group address lower register
 * - HW_FEC_TFWR - Transmit FIFO watermark register
 * - HW_FEC_FRBR - FIFO receive bound register
 * - HW_FEC_FRSR - FIFO receive FIFO start registers
 * - HW_FEC_ERDSR - Receive buffer descriptor ring start register
 * - HW_FEC_ETDSR - Transmit buffer descriptor ring start register
 * - HW_FEC_EMRBR - Maximum receive buffer size register
 *
 * hw_fec_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_FEC_BASE
#define REGS_FEC_BASE (0x02188000) //!< Base address for FEC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_EIR - Ethernet interrupt event register (RW)
 *
 * The FEC_EIR bit assignments are shown below. When an event occurs that sets a bit in the FEC_EIR,
 * an interrupt is generated if the corresponding bit in the interrupt mask register (FEC_EIMR) is
 * also set. The bit in the FEC_EIR is cleared if a one is written to that bit position; writing
 * zero has no effect. This register is cleared upon hardware reset.  Interrupts can be divided into
 * three classes as follows:   Interrupts that occur in normal operation: these include GRA, TXF,
 * TXB, RXF, RXB, and MII.  Interrupts that result from errors or problems detected in the network
 * or transceiver: these include HBERR, BABR, BABT, LC, and RL.  Interrupts that result from
 * internal errors are EBERR and UN.   For access, should I write: 'Access: User read/write' --
 * CThron  Some of the error interrupts are independently counted in the MIB block counters. The
 * correspondence between interrupts and counters is shown in the following table. Software can
 * choose to mask off the interrupts because these errors are visible to network management through
 * the MIB counters.   Error Interrupts and Block Counters        Interrupt    Counter(s)
 * HBERR    IEEE_T_SQE      BABR    RMON_R_OVERSIZE (good CRC), RMON_R_JAB (bad CRC)      BABT
 * RMON_T_OVERSIZE (good CRC), RMON_T_JAB (bad CRC)      LATE_COL    IEEE_T_LCOL      COL_RETRY_LIM
 * IEEE_T_EXCOL      XFIFO_UN    IEEE_T_MACERR
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 19; //!< Reserved, read as 0
        unsigned UN : 1; //!< Transmit FIFO underrun. This bit indicates that the transmit FIFO became empty before the complete frame was transmitted. A bad CRC is appended to the frame fragment and the remainder of the frame is discarded.
        unsigned RL : 1; //!< Collision retry limit. This bit indicates that a collision occurred on each of 16 successive attempts to transmit the frame. The frame is discarded without being transmitted and transmission of the next frame commences. Can only occur in half-duplex mode.
        unsigned LC : 1; //!< Late collision. This bit indicates that a collision occurred beyond the collision window (slot time) in half-duplex mode. The frame is truncated with a bad CRC and the remainder of the frame is discarded.
        unsigned EBERR : 1; //!< Ethernet bus error. This bit indicates that a system bus error occurred when a DMA transaction was underway. The EBERR interrupt will occur if the ipm_err signal asserts on the IPbus magenta interface during a DMA transaction. When the EBERR bit is set, FEC_ECR[ETHER_EN] is cleared, halting frame processing by the FEC_ When this occurs software needs to insure that the FIFO controller and DMA are also soft reset.
        unsigned MII : 1; //!< MII interrupt. This bit indicates that the MII has completed the data transfer requested.
        unsigned RXB : 1; //!< Receive buffer interrupt. This bit indicates that a receive buffer descriptor has been updated that was not the last in the frame.
        unsigned RXF : 1; //!< Receive frame interrupt. This bit indicates that a frame has been received and that the last corresponding buffer descriptor has been updated.
        unsigned TXB : 1; //!< Transmit buffer interrupt. This bit indicates that a transmit buffer descriptor has been updated.
        unsigned TXF : 1; //!< Transmit frame interrupt. This bit indicates that a frame has been transmitted and that the last corresponding buffer descriptor has been updated.
        unsigned GRA : 1; //!< Graceful stop complete. This interrupt is asserted for one of three reasons. Graceful stop means that the transmitter is put into a pause state after completion of the frame currently being transmitted. 1) A graceful stop, which was initiated by the setting of the FEC_TCR[GTS] bit is now complete. 2) A graceful stop, which was initiated by the setting of the FEC_TCR[TFC_PAUSE] bit is now complete. 3) A graceful stop, which was initiated by the reception of a valid full-duplex flow control "pause" frame is now complete. See the "Full-Duplex Flow Control" section of the Functional Description chapter.
        unsigned BABT : 1; //!< Babbling transmit error. This bit indicates that the transmitted frame length has exceeded FEC_RCR[MAX_FL] bytes. This condition is usually caused by a frame that is too long being placed into the transmit data buffer(s). Truncation does not occur.
        unsigned BABR : 1; //!< Babbling receive error. This bit indicates a frame was received with length in excess of FEC_RCR[MAX_FL] bytes.
        unsigned HBERR : 1; //!< Heartbeat error. This interrupt indicates that HBC is set in the FEC_TCR register and that the COL input was not asserted within the Heartbeat window following a transmission.
    } B;
} hw_fec_eir_t;
#endif

/*
 * constants & macros for entire FEC_EIR register
 */
#define HW_FEC_EIR_ADDR      (REGS_FEC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_EIR           (*(volatile hw_fec_eir_t *) HW_FEC_EIR_ADDR)
#define HW_FEC_EIR_RD()      (HW_FEC_EIR.U)
#define HW_FEC_EIR_WR(v)     (HW_FEC_EIR.U = (v))
#define HW_FEC_EIR_SET(v)    (HW_FEC_EIR_WR(HW_FEC_EIR_RD() |  (v)))
#define HW_FEC_EIR_CLR(v)    (HW_FEC_EIR_WR(HW_FEC_EIR_RD() & ~(v)))
#define HW_FEC_EIR_TOG(v)    (HW_FEC_EIR_WR(HW_FEC_EIR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_EIR bitfields
 */

/* --- Register HW_FEC_EIR, field UN[19:19] (RW)
 *
 * Transmit FIFO underrun. This bit indicates that the transmit FIFO became empty before the
 * complete frame was transmitted. A bad CRC is appended to the frame fragment and the remainder of
 * the frame is discarded.
 */

#define BP_FEC_EIR_UN      (19)
#define BM_FEC_EIR_UN      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_UN(v)   ((((reg32_t) v) << 19) & BM_FEC_EIR_UN)
#else
#define BF_FEC_EIR_UN(v)   (((v) << 19) & BM_FEC_EIR_UN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UN field to a new value.
#define BW_FEC_EIR_UN(v)   BF_CS1(FEC_EIR, UN, v)
#endif

/* --- Register HW_FEC_EIR, field RL[20:20] (RW)
 *
 * Collision retry limit. This bit indicates that a collision occurred on each of 16 successive
 * attempts to transmit the frame. The frame is discarded without being transmitted and transmission
 * of the next frame commences. Can only occur in half-duplex mode.
 */

#define BP_FEC_EIR_RL      (20)
#define BM_FEC_EIR_RL      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_RL(v)   ((((reg32_t) v) << 20) & BM_FEC_EIR_RL)
#else
#define BF_FEC_EIR_RL(v)   (((v) << 20) & BM_FEC_EIR_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_FEC_EIR_RL(v)   BF_CS1(FEC_EIR, RL, v)
#endif

/* --- Register HW_FEC_EIR, field LC[21:21] (RW)
 *
 * Late collision. This bit indicates that a collision occurred beyond the collision window (slot
 * time) in half-duplex mode. The frame is truncated with a bad CRC and the remainder of the frame
 * is discarded.
 */

#define BP_FEC_EIR_LC      (21)
#define BM_FEC_EIR_LC      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_LC(v)   ((((reg32_t) v) << 21) & BM_FEC_EIR_LC)
#else
#define BF_FEC_EIR_LC(v)   (((v) << 21) & BM_FEC_EIR_LC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LC field to a new value.
#define BW_FEC_EIR_LC(v)   BF_CS1(FEC_EIR, LC, v)
#endif

/* --- Register HW_FEC_EIR, field EBERR[22:22] (RW)
 *
 * Ethernet bus error. This bit indicates that a system bus error occurred when a DMA transaction
 * was underway. The EBERR interrupt will occur if the ipm_err signal asserts on the IPbus magenta
 * interface during a DMA transaction. When the EBERR bit is set, FEC_ECR[ETHER_EN] is cleared,
 * halting frame processing by the FEC_ When this occurs software needs to insure that the FIFO
 * controller and DMA are also soft reset.
 */

#define BP_FEC_EIR_EBERR      (22)
#define BM_FEC_EIR_EBERR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_EBERR(v)   ((((reg32_t) v) << 22) & BM_FEC_EIR_EBERR)
#else
#define BF_FEC_EIR_EBERR(v)   (((v) << 22) & BM_FEC_EIR_EBERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EBERR field to a new value.
#define BW_FEC_EIR_EBERR(v)   BF_CS1(FEC_EIR, EBERR, v)
#endif

/* --- Register HW_FEC_EIR, field MII[23:23] (RW)
 *
 * MII interrupt. This bit indicates that the MII has completed the data transfer requested.
 */

#define BP_FEC_EIR_MII      (23)
#define BM_FEC_EIR_MII      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_MII(v)   ((((reg32_t) v) << 23) & BM_FEC_EIR_MII)
#else
#define BF_FEC_EIR_MII(v)   (((v) << 23) & BM_FEC_EIR_MII)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MII field to a new value.
#define BW_FEC_EIR_MII(v)   BF_CS1(FEC_EIR, MII, v)
#endif

/* --- Register HW_FEC_EIR, field RXB[24:24] (RW)
 *
 * Receive buffer interrupt. This bit indicates that a receive buffer descriptor has been updated
 * that was not the last in the frame.
 */

#define BP_FEC_EIR_RXB      (24)
#define BM_FEC_EIR_RXB      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_RXB(v)   ((((reg32_t) v) << 24) & BM_FEC_EIR_RXB)
#else
#define BF_FEC_EIR_RXB(v)   (((v) << 24) & BM_FEC_EIR_RXB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXB field to a new value.
#define BW_FEC_EIR_RXB(v)   BF_CS1(FEC_EIR, RXB, v)
#endif

/* --- Register HW_FEC_EIR, field RXF[25:25] (RW)
 *
 * Receive frame interrupt. This bit indicates that a frame has been received and that the last
 * corresponding buffer descriptor has been updated.
 */

#define BP_FEC_EIR_RXF      (25)
#define BM_FEC_EIR_RXF      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_RXF(v)   ((((reg32_t) v) << 25) & BM_FEC_EIR_RXF)
#else
#define BF_FEC_EIR_RXF(v)   (((v) << 25) & BM_FEC_EIR_RXF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXF field to a new value.
#define BW_FEC_EIR_RXF(v)   BF_CS1(FEC_EIR, RXF, v)
#endif

/* --- Register HW_FEC_EIR, field TXB[26:26] (RW)
 *
 * Transmit buffer interrupt. This bit indicates that a transmit buffer descriptor has been updated.
 */

#define BP_FEC_EIR_TXB      (26)
#define BM_FEC_EIR_TXB      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_TXB(v)   ((((reg32_t) v) << 26) & BM_FEC_EIR_TXB)
#else
#define BF_FEC_EIR_TXB(v)   (((v) << 26) & BM_FEC_EIR_TXB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXB field to a new value.
#define BW_FEC_EIR_TXB(v)   BF_CS1(FEC_EIR, TXB, v)
#endif

/* --- Register HW_FEC_EIR, field TXF[27:27] (RW)
 *
 * Transmit frame interrupt. This bit indicates that a frame has been transmitted and that the last
 * corresponding buffer descriptor has been updated.
 */

#define BP_FEC_EIR_TXF      (27)
#define BM_FEC_EIR_TXF      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_TXF(v)   ((((reg32_t) v) << 27) & BM_FEC_EIR_TXF)
#else
#define BF_FEC_EIR_TXF(v)   (((v) << 27) & BM_FEC_EIR_TXF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXF field to a new value.
#define BW_FEC_EIR_TXF(v)   BF_CS1(FEC_EIR, TXF, v)
#endif

/* --- Register HW_FEC_EIR, field GRA[28:28] (RW)
 *
 * Graceful stop complete. This interrupt is asserted for one of three reasons. Graceful stop means
 * that the transmitter is put into a pause state after completion of the frame currently being
 * transmitted. 1) A graceful stop, which was initiated by the setting of the FEC_TCR[GTS] bit is
 * now complete. 2) A graceful stop, which was initiated by the setting of the FEC_TCR[TFC_PAUSE]
 * bit is now complete. 3) A graceful stop, which was initiated by the reception of a valid full-
 * duplex flow control "pause" frame is now complete. See the "Full-Duplex Flow Control" section of
 * the Functional Description chapter.
 */

#define BP_FEC_EIR_GRA      (28)
#define BM_FEC_EIR_GRA      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_GRA(v)   ((((reg32_t) v) << 28) & BM_FEC_EIR_GRA)
#else
#define BF_FEC_EIR_GRA(v)   (((v) << 28) & BM_FEC_EIR_GRA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GRA field to a new value.
#define BW_FEC_EIR_GRA(v)   BF_CS1(FEC_EIR, GRA, v)
#endif

/* --- Register HW_FEC_EIR, field BABT[29:29] (RW)
 *
 * Babbling transmit error. This bit indicates that the transmitted frame length has exceeded
 * FEC_RCR[MAX_FL] bytes. This condition is usually caused by a frame that is too long being placed
 * into the transmit data buffer(s). Truncation does not occur.
 */

#define BP_FEC_EIR_BABT      (29)
#define BM_FEC_EIR_BABT      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_BABT(v)   ((((reg32_t) v) << 29) & BM_FEC_EIR_BABT)
#else
#define BF_FEC_EIR_BABT(v)   (((v) << 29) & BM_FEC_EIR_BABT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BABT field to a new value.
#define BW_FEC_EIR_BABT(v)   BF_CS1(FEC_EIR, BABT, v)
#endif

/* --- Register HW_FEC_EIR, field BABR[30:30] (RW)
 *
 * Babbling receive error. This bit indicates a frame was received with length in excess of
 * FEC_RCR[MAX_FL] bytes.
 */

#define BP_FEC_EIR_BABR      (30)
#define BM_FEC_EIR_BABR      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_BABR(v)   ((((reg32_t) v) << 30) & BM_FEC_EIR_BABR)
#else
#define BF_FEC_EIR_BABR(v)   (((v) << 30) & BM_FEC_EIR_BABR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BABR field to a new value.
#define BW_FEC_EIR_BABR(v)   BF_CS1(FEC_EIR, BABR, v)
#endif

/* --- Register HW_FEC_EIR, field HBERR[31:31] (RW)
 *
 * Heartbeat error. This interrupt indicates that HBC is set in the FEC_TCR register and that the
 * COL input was not asserted within the Heartbeat window following a transmission.
 */

#define BP_FEC_EIR_HBERR      (31)
#define BM_FEC_EIR_HBERR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIR_HBERR(v)   ((((reg32_t) v) << 31) & BM_FEC_EIR_HBERR)
#else
#define BF_FEC_EIR_HBERR(v)   (((v) << 31) & BM_FEC_EIR_HBERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBERR field to a new value.
#define BW_FEC_EIR_HBERR(v)   BF_CS1(FEC_EIR, HBERR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_EIMR - Ethernet interrupt mask register (RW)
 *
 * The FEC_EIMR controls which of the interrupt events flagged in the FEC_EIR are allowed to
 * generate actual interrupts. If the corresponding bits in both the FEC_EIR and FEC_EIMR are set,
 * the interrupt is signaled to the ARM platform. The interrupt signal remains asserted until a 1 is
 * written to the FEC_EIR bit (write 1 to clear) or a 0 is written to the FEC_EIMR bit. This
 * register is cleared upon a hardware reset.  The FEC_EIMR bit assignments are the same as for the
 * FEC_EIR.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 19; //!< Reserved, read as 0
        unsigned UN : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned RL : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned LC : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned EBERR : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned MII : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned RXB : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned RXF : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned TXB : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned TXF : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned GRA : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned BABT : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned BABR : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
        unsigned HBERR : 1; //!< Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt. At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding FEC_EIMR bit is cleared.
    } B;
} hw_fec_eimr_t;
#endif

/*
 * constants & macros for entire FEC_EIMR register
 */
#define HW_FEC_EIMR_ADDR      (REGS_FEC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_EIMR           (*(volatile hw_fec_eimr_t *) HW_FEC_EIMR_ADDR)
#define HW_FEC_EIMR_RD()      (HW_FEC_EIMR.U)
#define HW_FEC_EIMR_WR(v)     (HW_FEC_EIMR.U = (v))
#define HW_FEC_EIMR_SET(v)    (HW_FEC_EIMR_WR(HW_FEC_EIMR_RD() |  (v)))
#define HW_FEC_EIMR_CLR(v)    (HW_FEC_EIMR_WR(HW_FEC_EIMR_RD() & ~(v)))
#define HW_FEC_EIMR_TOG(v)    (HW_FEC_EIMR_WR(HW_FEC_EIMR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_EIMR bitfields
 */

/* --- Register HW_FEC_EIMR, field UN[19:19] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_UN      (19)
#define BM_FEC_EIMR_UN      (0x00080000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_UN(v)   ((((reg32_t) v) << 19) & BM_FEC_EIMR_UN)
#else
#define BF_FEC_EIMR_UN(v)   (((v) << 19) & BM_FEC_EIMR_UN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the UN field to a new value.
#define BW_FEC_EIMR_UN(v)   BF_CS1(FEC_EIMR, UN, v)
#endif


/* --- Register HW_FEC_EIMR, field RL[20:20] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_RL      (20)
#define BM_FEC_EIMR_RL      (0x00100000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_RL(v)   ((((reg32_t) v) << 20) & BM_FEC_EIMR_RL)
#else
#define BF_FEC_EIMR_RL(v)   (((v) << 20) & BM_FEC_EIMR_RL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_FEC_EIMR_RL(v)   BF_CS1(FEC_EIMR, RL, v)
#endif


/* --- Register HW_FEC_EIMR, field LC[21:21] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_LC      (21)
#define BM_FEC_EIMR_LC      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_LC(v)   ((((reg32_t) v) << 21) & BM_FEC_EIMR_LC)
#else
#define BF_FEC_EIMR_LC(v)   (((v) << 21) & BM_FEC_EIMR_LC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LC field to a new value.
#define BW_FEC_EIMR_LC(v)   BF_CS1(FEC_EIMR, LC, v)
#endif


/* --- Register HW_FEC_EIMR, field EBERR[22:22] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_EBERR      (22)
#define BM_FEC_EIMR_EBERR      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_EBERR(v)   ((((reg32_t) v) << 22) & BM_FEC_EIMR_EBERR)
#else
#define BF_FEC_EIMR_EBERR(v)   (((v) << 22) & BM_FEC_EIMR_EBERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EBERR field to a new value.
#define BW_FEC_EIMR_EBERR(v)   BF_CS1(FEC_EIMR, EBERR, v)
#endif


/* --- Register HW_FEC_EIMR, field MII[23:23] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_MII      (23)
#define BM_FEC_EIMR_MII      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_MII(v)   ((((reg32_t) v) << 23) & BM_FEC_EIMR_MII)
#else
#define BF_FEC_EIMR_MII(v)   (((v) << 23) & BM_FEC_EIMR_MII)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MII field to a new value.
#define BW_FEC_EIMR_MII(v)   BF_CS1(FEC_EIMR, MII, v)
#endif


/* --- Register HW_FEC_EIMR, field RXB[24:24] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_RXB      (24)
#define BM_FEC_EIMR_RXB      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_RXB(v)   ((((reg32_t) v) << 24) & BM_FEC_EIMR_RXB)
#else
#define BF_FEC_EIMR_RXB(v)   (((v) << 24) & BM_FEC_EIMR_RXB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXB field to a new value.
#define BW_FEC_EIMR_RXB(v)   BF_CS1(FEC_EIMR, RXB, v)
#endif


/* --- Register HW_FEC_EIMR, field RXF[25:25] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_RXF      (25)
#define BM_FEC_EIMR_RXF      (0x02000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_RXF(v)   ((((reg32_t) v) << 25) & BM_FEC_EIMR_RXF)
#else
#define BF_FEC_EIMR_RXF(v)   (((v) << 25) & BM_FEC_EIMR_RXF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXF field to a new value.
#define BW_FEC_EIMR_RXF(v)   BF_CS1(FEC_EIMR, RXF, v)
#endif


/* --- Register HW_FEC_EIMR, field TXB[26:26] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_TXB      (26)
#define BM_FEC_EIMR_TXB      (0x04000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_TXB(v)   ((((reg32_t) v) << 26) & BM_FEC_EIMR_TXB)
#else
#define BF_FEC_EIMR_TXB(v)   (((v) << 26) & BM_FEC_EIMR_TXB)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXB field to a new value.
#define BW_FEC_EIMR_TXB(v)   BF_CS1(FEC_EIMR, TXB, v)
#endif


/* --- Register HW_FEC_EIMR, field TXF[27:27] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_TXF      (27)
#define BM_FEC_EIMR_TXF      (0x08000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_TXF(v)   ((((reg32_t) v) << 27) & BM_FEC_EIMR_TXF)
#else
#define BF_FEC_EIMR_TXF(v)   (((v) << 27) & BM_FEC_EIMR_TXF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TXF field to a new value.
#define BW_FEC_EIMR_TXF(v)   BF_CS1(FEC_EIMR, TXF, v)
#endif


/* --- Register HW_FEC_EIMR, field GRA[28:28] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_GRA      (28)
#define BM_FEC_EIMR_GRA      (0x10000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_GRA(v)   ((((reg32_t) v) << 28) & BM_FEC_EIMR_GRA)
#else
#define BF_FEC_EIMR_GRA(v)   (((v) << 28) & BM_FEC_EIMR_GRA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GRA field to a new value.
#define BW_FEC_EIMR_GRA(v)   BF_CS1(FEC_EIMR, GRA, v)
#endif


/* --- Register HW_FEC_EIMR, field BABT[29:29] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_BABT      (29)
#define BM_FEC_EIMR_BABT      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_BABT(v)   ((((reg32_t) v) << 29) & BM_FEC_EIMR_BABT)
#else
#define BF_FEC_EIMR_BABT(v)   (((v) << 29) & BM_FEC_EIMR_BABT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BABT field to a new value.
#define BW_FEC_EIMR_BABT(v)   BF_CS1(FEC_EIMR, BABT, v)
#endif


/* --- Register HW_FEC_EIMR, field BABR[30:30] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_BABR      (30)
#define BM_FEC_EIMR_BABR      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_BABR(v)   ((((reg32_t) v) << 30) & BM_FEC_EIMR_BABR)
#else
#define BF_FEC_EIMR_BABR(v)   (((v) << 30) & BM_FEC_EIMR_BABR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BABR field to a new value.
#define BW_FEC_EIMR_BABR(v)   BF_CS1(FEC_EIMR, BABR, v)
#endif


/* --- Register HW_FEC_EIMR, field HBERR[31:31] (RW)
 *
 * Interrupt mask. Each bit corresponds to an interrupt source defined by the FEC_EIR register. The
 * corresponding FEC_EIMR bit determines whether an interrupt condition can generate an interrupt.
 * At every system clock, the FEC_EIR samples the signal generated by the interrupting source. The
 * corresponding FEC_EIR bit reflects the state of the interrupt signal even if the corresponding
 * FEC_EIMR bit is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_FEC_EIMR_HBERR      (31)
#define BM_FEC_EIMR_HBERR      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EIMR_HBERR(v)   ((((reg32_t) v) << 31) & BM_FEC_EIMR_HBERR)
#else
#define BF_FEC_EIMR_HBERR(v)   (((v) << 31) & BM_FEC_EIMR_HBERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBERR field to a new value.
#define BW_FEC_EIMR_HBERR(v)   BF_CS1(FEC_EIMR, HBERR, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_RDAR - Receive descriptor active register (RW)
 *
 * FEC_RDAR is a user-writeable command register which indicates that the receive descriptor ring
 * has been updated, and that empty receive buffers have been produced by the driver with the empty
 * bit set.  The FEC_RDAR[R_DES_ACTIVE] bit is set whenever the register is written, independent of
 * the data actually written by the user. When set, the FEC polls the receive descriptor ring and
 * processes receive frames (provided FEC_ECR[ETHER_EN] is also set to 1). After the FEC polls a
 * receive descriptor whose empty bit is not set, then the FEC clears the FEC_RDAR[R_DES_ACTIVE] bit
 * and ceases receive descriptor ring polling until the user sets the bit again, signifying that
 * additional descriptors have been placed into the receive descriptor ring.  The FEC_RDAR is
 * cleared at reset, and when FEC_ECR[ETHER_EN] is cleared.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 24; //!< Reserved, read as 0
        unsigned R_DES_ACTIVE : 1; //!< Set to one when this register is written, regardless of the value written. Cleared by the FEC device when the FEC polls a receive descriptor whose empty bit is not set. Also cleared when FEC_ECR[ETHER_EN] is cleared.
        unsigned RESERVED1 : 7; //!< Reserved, read as 0
    } B;
} hw_fec_rdar_t;
#endif

/*
 * constants & macros for entire FEC_RDAR register
 */
#define HW_FEC_RDAR_ADDR      (REGS_FEC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_RDAR           (*(volatile hw_fec_rdar_t *) HW_FEC_RDAR_ADDR)
#define HW_FEC_RDAR_RD()      (HW_FEC_RDAR.U)
#define HW_FEC_RDAR_WR(v)     (HW_FEC_RDAR.U = (v))
#define HW_FEC_RDAR_SET(v)    (HW_FEC_RDAR_WR(HW_FEC_RDAR_RD() |  (v)))
#define HW_FEC_RDAR_CLR(v)    (HW_FEC_RDAR_WR(HW_FEC_RDAR_RD() & ~(v)))
#define HW_FEC_RDAR_TOG(v)    (HW_FEC_RDAR_WR(HW_FEC_RDAR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_RDAR bitfields
 */

/* --- Register HW_FEC_RDAR, field R_DES_ACTIVE[24:24] (RW)
 *
 * Set to one when this register is written, regardless of the value written. Cleared by the FEC
 * device when the FEC polls a receive descriptor whose empty bit is not set. Also cleared when
 * FEC_ECR[ETHER_EN] is cleared.
 */

#define BP_FEC_RDAR_R_DES_ACTIVE      (24)
#define BM_FEC_RDAR_R_DES_ACTIVE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RDAR_R_DES_ACTIVE(v)   ((((reg32_t) v) << 24) & BM_FEC_RDAR_R_DES_ACTIVE)
#else
#define BF_FEC_RDAR_R_DES_ACTIVE(v)   (((v) << 24) & BM_FEC_RDAR_R_DES_ACTIVE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the R_DES_ACTIVE field to a new value.
#define BW_FEC_RDAR_R_DES_ACTIVE(v)   BF_CS1(FEC_RDAR, R_DES_ACTIVE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_TDAR - Transmit descriptor active register (RW)
 *
 * The FEC_TDAR is a command register, written to by the user, to indicate that the transmit
 * descriptor ring has been updated (transmit buffers have been produced by the driver with the
 * ready bit set in the buffer descriptor).  Whenever the register is written the
 * FEC_TDAR[X_DES_ACTIVE] bit is set to 1, independent of the data actually written by the user.
 * When set, the FEC polls the transmit descriptor ring and process transmit frames (provided
 * FEC_ECR[ETHER_EN] is also set to 1). After the FEC polls a transmit descriptor whose ready bit is
 * not set, then the FEC clears the FEC_TDAR[X_DES_ACTIVE] bit and ceases transmit descriptor ring
 * polling until the user sets the bit again, signifying additional descriptors have been placed
 * into the transmit descriptor ring.  The FEC_TDAR is cleared at reset, when FEC_ECR[ETHER_EN] is
 * cleared, or when FEC_ECR[RESET] is set to 1.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 24; //!< Reserved, read as 0
        unsigned X_DES_ACTIVE : 1; //!< Set to one when this register is written, regardless of the value written. Cleared by the FEC device when the FEC polls a transmit descriptor whose ready bit is not set. Also cleared when FEC_ECR[ETHER_EN] is cleared.
        unsigned RESERVED1 : 7; //!< Reserved, read as 0
    } B;
} hw_fec_tdar_t;
#endif

/*
 * constants & macros for entire FEC_TDAR register
 */
#define HW_FEC_TDAR_ADDR      (REGS_FEC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_TDAR           (*(volatile hw_fec_tdar_t *) HW_FEC_TDAR_ADDR)
#define HW_FEC_TDAR_RD()      (HW_FEC_TDAR.U)
#define HW_FEC_TDAR_WR(v)     (HW_FEC_TDAR.U = (v))
#define HW_FEC_TDAR_SET(v)    (HW_FEC_TDAR_WR(HW_FEC_TDAR_RD() |  (v)))
#define HW_FEC_TDAR_CLR(v)    (HW_FEC_TDAR_WR(HW_FEC_TDAR_RD() & ~(v)))
#define HW_FEC_TDAR_TOG(v)    (HW_FEC_TDAR_WR(HW_FEC_TDAR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_TDAR bitfields
 */

/* --- Register HW_FEC_TDAR, field X_DES_ACTIVE[24:24] (RW)
 *
 * Set to one when this register is written, regardless of the value written. Cleared by the FEC
 * device when the FEC polls a transmit descriptor whose ready bit is not set. Also cleared when
 * FEC_ECR[ETHER_EN] is cleared.
 */

#define BP_FEC_TDAR_X_DES_ACTIVE      (24)
#define BM_FEC_TDAR_X_DES_ACTIVE      (0x01000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_TDAR_X_DES_ACTIVE(v)   ((((reg32_t) v) << 24) & BM_FEC_TDAR_X_DES_ACTIVE)
#else
#define BF_FEC_TDAR_X_DES_ACTIVE(v)   (((v) << 24) & BM_FEC_TDAR_X_DES_ACTIVE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X_DES_ACTIVE field to a new value.
#define BW_FEC_TDAR_X_DES_ACTIVE(v)   BF_CS1(FEC_TDAR, X_DES_ACTIVE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_ECR - Ethernet control register (RW)
 *
 * The ECR is used to enable/disable the FEC_ ECR is a read/write user register, though both fields
 * in this register can also be altered by hardware.  I have greyed the reserved bits. Please verify
 * -- CThron
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESET : 1; //!< When this bit is set, the equivalent of a hardware reset is performed but it is local to the FEC_ ETHER_EN is cleared and all other FEC registers take their reset values. Also, any transmission/reception currently in progress is abruptly aborted. This bit is automatically cleared by hardware during the reset sequence. The reset sequence takes approximately 8 system clock cycles after RESET is written with a 1.
        unsigned ETHER_EN : 1; //!< When this bit is set, the FEC is enabled, and reception and transmission are possible. When this bit is cleared, reception is immediately stopped and transmission is stopped after a bad CRC is appended to any currently transmitted frame. The buffer descriptor(s) for an aborted transmit frame are not updated after clearing this bit. When ETHER_EN is cleared, the DMA, buffer descriptor, and FIFO control logic are reset, including the buffer descriptor and FIFO pointers. The ETHER_EN bit is altered by hardware under the following conditions: FEC_ECR[RESET] is set by software, in which case ETHER_EN is cleared an error condition causes the FEC_EIR[EBERR] bit to set, in which case ETHER_EN is cleared
        unsigned RESERVED0 : 30; //!< Reserved.
    } B;
} hw_fec_ecr_t;
#endif

/*
 * constants & macros for entire FEC_ECR register
 */
#define HW_FEC_ECR_ADDR      (REGS_FEC_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_ECR           (*(volatile hw_fec_ecr_t *) HW_FEC_ECR_ADDR)
#define HW_FEC_ECR_RD()      (HW_FEC_ECR.U)
#define HW_FEC_ECR_WR(v)     (HW_FEC_ECR.U = (v))
#define HW_FEC_ECR_SET(v)    (HW_FEC_ECR_WR(HW_FEC_ECR_RD() |  (v)))
#define HW_FEC_ECR_CLR(v)    (HW_FEC_ECR_WR(HW_FEC_ECR_RD() & ~(v)))
#define HW_FEC_ECR_TOG(v)    (HW_FEC_ECR_WR(HW_FEC_ECR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_ECR bitfields
 */

/* --- Register HW_FEC_ECR, field RESET[0:0] (RW)
 *
 * When this bit is set, the equivalent of a hardware reset is performed but it is local to the FEC_
 * ETHER_EN is cleared and all other FEC registers take their reset values. Also, any
 * transmission/reception currently in progress is abruptly aborted. This bit is automatically
 * cleared by hardware during the reset sequence. The reset sequence takes approximately 8 system
 * clock cycles after RESET is written with a 1.
 */

#define BP_FEC_ECR_RESET      (0)
#define BM_FEC_ECR_RESET      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_ECR_RESET(v)   ((((reg32_t) v) << 0) & BM_FEC_ECR_RESET)
#else
#define BF_FEC_ECR_RESET(v)   (((v) << 0) & BM_FEC_ECR_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_FEC_ECR_RESET(v)   BF_CS1(FEC_ECR, RESET, v)
#endif

/* --- Register HW_FEC_ECR, field ETHER_EN[1:1] (RW)
 *
 * When this bit is set, the FEC is enabled, and reception and transmission are possible. When this
 * bit is cleared, reception is immediately stopped and transmission is stopped after a bad CRC is
 * appended to any currently transmitted frame. The buffer descriptor(s) for an aborted transmit
 * frame are not updated after clearing this bit. When ETHER_EN is cleared, the DMA, buffer
 * descriptor, and FIFO control logic are reset, including the buffer descriptor and FIFO pointers.
 * The ETHER_EN bit is altered by hardware under the following conditions: FEC_ECR[RESET] is set by
 * software, in which case ETHER_EN is cleared an error condition causes the FEC_EIR[EBERR] bit to
 * set, in which case ETHER_EN is cleared
 */

#define BP_FEC_ECR_ETHER_EN      (1)
#define BM_FEC_ECR_ETHER_EN      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_ECR_ETHER_EN(v)   ((((reg32_t) v) << 1) & BM_FEC_ECR_ETHER_EN)
#else
#define BF_FEC_ECR_ETHER_EN(v)   (((v) << 1) & BM_FEC_ECR_ETHER_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ETHER_EN field to a new value.
#define BW_FEC_ECR_ETHER_EN(v)   BF_CS1(FEC_ECR, ETHER_EN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_MMFR - MII management frame register (RW)
 *
 * The FEC_MMFR is used to communicate with the attached MII compatible PHY device(s), providing
 * read/write access to their MII registers. Performing a write to FEC_MMFR causes a management
 * frame to be generated unless the MII-SPEED field of the FEC_MSCR has been set to 0, in which case
 * FEC_MSCR is set to a non-zero value and an MII frame is generated with the data previously
 * written to FEC_MMFR. This allows FEC_MMFR and FEC_MSCR to be programmed in either order if the
 * MII-SPEED field of FEC_MSCR is zero (for further details see ).  The FEC_MMFR does not reset to a
 * definite value. So how is the reset value determined? Is it unaffected by reset? Then ' n ' in
 * the Reset row should be changed to ' u '-- CThron  To perform a read or write operation on the
 * MII Management Interface, the FEC_MMFR must be written to by the user. To generate a valid read
 * or write management frame, the ST field must be written with a 01 pattern, and the TA field must
 * be written with a 10. If other patterns are written to these fields, a frame is generated but
 * does not comply with the IEEE 802.3 MII definition.  To generate an IEEE 802.3-compliant MII
 * management interface write frame (write to a PHY register), the user must write {01 01 PHYAD
 * REGAD 10 DATA} to the bit fields of the FEC_MMFR, as shown in . Writing this pattern causes the
 * control logic to shift out the data in the FEC_MMFR following a preamble generated by the control
 * state machine. During this time the contents of the FEC_MMFR is altered as the contents are
 * serially shifted and is unpredictable if read by the user. After the write management frame
 * operation has completed, the MII interrupt is generated. At this time the contents of the
 * FEC_MMFR matches the original value written.  To generate an MII management interface read frame
 * (read a PHY register) the user must write {01 10 PHYAD REGAD 10 XXXX} to the bit fields of the
 * FEC_MMFR shown in (the contents of the 4-bit DATA field are arbitrary). Writing this pattern
 * causes the control logic to shift out the data in the FEC_MMFR following a preamble generated by
 * the control state machine. During this time the contents of the FEC_MMFR is altered as the
 * contents are serially shifted, and is unpredictable if read by the user. After the read
 * management frame operation has completed, the MII interrupt is generated. At this time the
 * contents of the FEC_MMFR matches the original value written except for the DATA field whose
 * contents have been replaced by the value read from the PHY register.  If the FEC_MMFR is written
 * to while frame generation is in progress, the frame contents is altered. Software uses the
 * MII_STATUS register and/or the MII interrupt to avoid writing to the FEC_MMFR while frame
 * generation is in progress.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 16; //!< Management frame data. This is the field for data to be written to or read from the PHY register.
        unsigned TA : 2; //!< Turn around. This field must be programmed to 10 to generate a valid MII management frame.
        unsigned RA : 5; //!< Register address. This field specifies one of up to 32 registers within the specified PHY device.
        unsigned PA : 5; //!< PHY address. This field specifies one of up to 32 attached PHY devices.
        unsigned OP : 2; //!< Operation code. This field must be programmed to 10 (read) or 01 (write) to generate a valid MII management frame. A value of 11 produces "read" frame operation while a value of 00 produces "write" frame operation, but these frames is not MII compliant.
        unsigned ST : 2; //!< Start of frame delimiter. These bits must be programmed to 01 for a valid MII management frame.
    } B;
} hw_fec_mmfr_t;
#endif

/*
 * constants & macros for entire FEC_MMFR register
 */
#define HW_FEC_MMFR_ADDR      (REGS_FEC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_MMFR           (*(volatile hw_fec_mmfr_t *) HW_FEC_MMFR_ADDR)
#define HW_FEC_MMFR_RD()      (HW_FEC_MMFR.U)
#define HW_FEC_MMFR_WR(v)     (HW_FEC_MMFR.U = (v))
#define HW_FEC_MMFR_SET(v)    (HW_FEC_MMFR_WR(HW_FEC_MMFR_RD() |  (v)))
#define HW_FEC_MMFR_CLR(v)    (HW_FEC_MMFR_WR(HW_FEC_MMFR_RD() & ~(v)))
#define HW_FEC_MMFR_TOG(v)    (HW_FEC_MMFR_WR(HW_FEC_MMFR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_MMFR bitfields
 */

/* --- Register HW_FEC_MMFR, field DATA[15:0] (RW)
 *
 * Management frame data. This is the field for data to be written to or read from the PHY register.
 */

#define BP_FEC_MMFR_DATA      (0)
#define BM_FEC_MMFR_DATA      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MMFR_DATA(v)   ((((reg32_t) v) << 0) & BM_FEC_MMFR_DATA)
#else
#define BF_FEC_MMFR_DATA(v)   (((v) << 0) & BM_FEC_MMFR_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_FEC_MMFR_DATA(v)   BF_CS1(FEC_MMFR, DATA, v)
#endif

/* --- Register HW_FEC_MMFR, field TA[17:16] (RW)
 *
 * Turn around. This field must be programmed to 10 to generate a valid MII management frame.
 */

#define BP_FEC_MMFR_TA      (16)
#define BM_FEC_MMFR_TA      (0x00030000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MMFR_TA(v)   ((((reg32_t) v) << 16) & BM_FEC_MMFR_TA)
#else
#define BF_FEC_MMFR_TA(v)   (((v) << 16) & BM_FEC_MMFR_TA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TA field to a new value.
#define BW_FEC_MMFR_TA(v)   BF_CS1(FEC_MMFR, TA, v)
#endif

/* --- Register HW_FEC_MMFR, field RA[22:18] (RW)
 *
 * Register address. This field specifies one of up to 32 registers within the specified PHY device.
 */

#define BP_FEC_MMFR_RA      (18)
#define BM_FEC_MMFR_RA      (0x007c0000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MMFR_RA(v)   ((((reg32_t) v) << 18) & BM_FEC_MMFR_RA)
#else
#define BF_FEC_MMFR_RA(v)   (((v) << 18) & BM_FEC_MMFR_RA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RA field to a new value.
#define BW_FEC_MMFR_RA(v)   BF_CS1(FEC_MMFR, RA, v)
#endif

/* --- Register HW_FEC_MMFR, field PA[27:23] (RW)
 *
 * PHY address. This field specifies one of up to 32 attached PHY devices.
 */

#define BP_FEC_MMFR_PA      (23)
#define BM_FEC_MMFR_PA      (0x0f800000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MMFR_PA(v)   ((((reg32_t) v) << 23) & BM_FEC_MMFR_PA)
#else
#define BF_FEC_MMFR_PA(v)   (((v) << 23) & BM_FEC_MMFR_PA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PA field to a new value.
#define BW_FEC_MMFR_PA(v)   BF_CS1(FEC_MMFR, PA, v)
#endif

/* --- Register HW_FEC_MMFR, field OP[29:28] (RW)
 *
 * Operation code. This field must be programmed to 10 (read) or 01 (write) to generate a valid MII
 * management frame. A value of 11 produces "read" frame operation while a value of 00 produces
 * "write" frame operation, but these frames is not MII compliant.
 */

#define BP_FEC_MMFR_OP      (28)
#define BM_FEC_MMFR_OP      (0x30000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MMFR_OP(v)   ((((reg32_t) v) << 28) & BM_FEC_MMFR_OP)
#else
#define BF_FEC_MMFR_OP(v)   (((v) << 28) & BM_FEC_MMFR_OP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OP field to a new value.
#define BW_FEC_MMFR_OP(v)   BF_CS1(FEC_MMFR, OP, v)
#endif

/* --- Register HW_FEC_MMFR, field ST[31:30] (RW)
 *
 * Start of frame delimiter. These bits must be programmed to 01 for a valid MII management frame.
 */

#define BP_FEC_MMFR_ST      (30)
#define BM_FEC_MMFR_ST      (0xc0000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MMFR_ST(v)   ((((reg32_t) v) << 30) & BM_FEC_MMFR_ST)
#else
#define BF_FEC_MMFR_ST(v)   (((v) << 30) & BM_FEC_MMFR_ST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ST field to a new value.
#define BW_FEC_MMFR_ST(v)   BF_CS1(FEC_MMFR, ST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_MSCR - MII speed control register (RW)
 *
 * The FEC_MSCR provides control of the frequency of the MII clock (FEC_MDC signal), and allows a
 * preamble drop on the MII management frame , and provides observability (intended for
 * manufacturing test) of an internal counter used in generating the FEC_MDC clock signal .  The
 * MII_SPEED field must be programmed with a value to provide an FEC_MDC frequency of less than or
 * equal to 2.5 MHz to be compliant with the IEEE 802.3 MII specification. The MII_SPEED must be set
 * to a non-zero value in order to generate a read or write management frame. After the management
 * frame is complete the FEC_MSCR can optionally be set to zero to turn off the FEC_MDC. The FEC_MDC
 * generated has a 50% duty cycle except when MII_SPEED is changed during operation (change takes
 * effect following either a rising or falling edge of FEC_MDC).  The FEC_MDC frequency depends on
 * both the system clock frequency and the MII_SPEED register. If the system clock is 25 MHz,
 * programming the MII_SPEED register to 0x0000_0005 results in an FEC_MDC frequency of 25 MHz *
 * 1/10 = 2.5 MHz. A table showing optimum values for MII_SPEED for different system clock
 * frequencies is provided below.   Programming Examples for FEC_MSCR         System Clock Frequency
 * MII_SPEED (field in reg)    FEC_MDC frequency        25 MHz    0x5    2.5 MHz      33 MHz    0x7
 * 2.36 MHz      40 MHz    0x8    2.5 MHz      50 MHz    0xA    2.5 MHz      66 MHz    0xD    2.54
 * MHz
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Reserved, read as 0
        unsigned MII_SPEED : 6; //!< MII_SPEED controls the frequency of the MII management interface clock (FEC_MDC) relative to the system clock. A value of 0 in this field "turns off" the FEC_MDC and leave it in low voltage state. Any non-zero value results in the FEC_MDC frequency of 1/(MII_SPEED*2) of the system clock frequency.
        unsigned DIS_PREAMBLE : 1; //!< Asserting this bit causes preamble (0xFFFF_FFFF) not to be prepended to the MII management frame. The MII standard allows the preamble to be dropped if the attached PHY device(s) does not require it.
        unsigned RESERVED1 : 24; //!< Reserved, read as 0
    } B;
} hw_fec_mscr_t;
#endif

/*
 * constants & macros for entire FEC_MSCR register
 */
#define HW_FEC_MSCR_ADDR      (REGS_FEC_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_MSCR           (*(volatile hw_fec_mscr_t *) HW_FEC_MSCR_ADDR)
#define HW_FEC_MSCR_RD()      (HW_FEC_MSCR.U)
#define HW_FEC_MSCR_WR(v)     (HW_FEC_MSCR.U = (v))
#define HW_FEC_MSCR_SET(v)    (HW_FEC_MSCR_WR(HW_FEC_MSCR_RD() |  (v)))
#define HW_FEC_MSCR_CLR(v)    (HW_FEC_MSCR_WR(HW_FEC_MSCR_RD() & ~(v)))
#define HW_FEC_MSCR_TOG(v)    (HW_FEC_MSCR_WR(HW_FEC_MSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_MSCR bitfields
 */

/* --- Register HW_FEC_MSCR, field MII_SPEED[6:1] (RW)
 *
 * MII_SPEED controls the frequency of the MII management interface clock (FEC_MDC) relative to the
 * system clock. A value of 0 in this field "turns off" the FEC_MDC and leave it in low voltage
 * state. Any non-zero value results in the FEC_MDC frequency of 1/(MII_SPEED*2) of the system clock
 * frequency.
 */

#define BP_FEC_MSCR_MII_SPEED      (1)
#define BM_FEC_MSCR_MII_SPEED      (0x0000007e)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MSCR_MII_SPEED(v)   ((((reg32_t) v) << 1) & BM_FEC_MSCR_MII_SPEED)
#else
#define BF_FEC_MSCR_MII_SPEED(v)   (((v) << 1) & BM_FEC_MSCR_MII_SPEED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MII_SPEED field to a new value.
#define BW_FEC_MSCR_MII_SPEED(v)   BF_CS1(FEC_MSCR, MII_SPEED, v)
#endif

/* --- Register HW_FEC_MSCR, field DIS_PREAMBLE[7:7] (RW)
 *
 * Asserting this bit causes preamble (0xFFFF_FFFF) not to be prepended to the MII management frame.
 * The MII standard allows the preamble to be dropped if the attached PHY device(s) does not require
 * it.
 */

#define BP_FEC_MSCR_DIS_PREAMBLE      (7)
#define BM_FEC_MSCR_DIS_PREAMBLE      (0x00000080)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MSCR_DIS_PREAMBLE(v)   ((((reg32_t) v) << 7) & BM_FEC_MSCR_DIS_PREAMBLE)
#else
#define BF_FEC_MSCR_DIS_PREAMBLE(v)   (((v) << 7) & BM_FEC_MSCR_DIS_PREAMBLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS_PREAMBLE field to a new value.
#define BW_FEC_MSCR_DIS_PREAMBLE(v)   BF_CS1(FEC_MSCR, DIS_PREAMBLE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_MIBC - MIB control register (RW)
 *
 * The MIB control register is a read/write register used to provide control of and to observe the
 * state of the Message Information Block (MIB). This register is accessed by user software if there
 * is a need to disable the MIB operation. For example, in order to clear all MIB counters in RAM
 * the user disables the MIB, then clears all the MIB RAM locations, then enables the MIB. The
 * MIB_DISABLE bit is reset to 1. See for the locations of the MIB counters.  [The figure showed
 * MIB_IDLE as read/write. I have changed to read-only, according to the field description table--
 * CT]
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 30; //!< Reserved.
        unsigned MB_IDLE : 1; //!< A read-only status bit. If set the MIB block is not currently updating any MIB counters.
        unsigned MIB_DISABLE : 1; //!< A read/write control bit. If set, the MIB logic halts and not update any MIB counters.
    } B;
} hw_fec_mibc_t;
#endif

/*
 * constants & macros for entire FEC_MIBC register
 */
#define HW_FEC_MIBC_ADDR      (REGS_FEC_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_MIBC           (*(volatile hw_fec_mibc_t *) HW_FEC_MIBC_ADDR)
#define HW_FEC_MIBC_RD()      (HW_FEC_MIBC.U)
#define HW_FEC_MIBC_WR(v)     (HW_FEC_MIBC.U = (v))
#define HW_FEC_MIBC_SET(v)    (HW_FEC_MIBC_WR(HW_FEC_MIBC_RD() |  (v)))
#define HW_FEC_MIBC_CLR(v)    (HW_FEC_MIBC_WR(HW_FEC_MIBC_RD() & ~(v)))
#define HW_FEC_MIBC_TOG(v)    (HW_FEC_MIBC_WR(HW_FEC_MIBC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_MIBC bitfields
 */

/* --- Register HW_FEC_MIBC, field MB_IDLE[30:30] (RO)
 *
 * A read-only status bit. If set the MIB block is not currently updating any MIB counters.
 */

#define BP_FEC_MIBC_MB_IDLE      (30)
#define BM_FEC_MIBC_MB_IDLE      (0x40000000)

/* --- Register HW_FEC_MIBC, field MIB_DISABLE[31:31] (RW)
 *
 * A read/write control bit. If set, the MIB logic halts and not update any MIB counters.
 */

#define BP_FEC_MIBC_MIB_DISABLE      (31)
#define BM_FEC_MIBC_MIB_DISABLE      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_MIBC_MIB_DISABLE(v)   ((((reg32_t) v) << 31) & BM_FEC_MIBC_MIB_DISABLE)
#else
#define BF_FEC_MIBC_MIB_DISABLE(v)   (((v) << 31) & BM_FEC_MIBC_MIB_DISABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MIB_DISABLE field to a new value.
#define BW_FEC_MIBC_MIB_DISABLE(v)   BF_CS1(FEC_MIBC, MIB_DISABLE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_RCR - Receive control register (RW)
 *
 * The FEC_RCR is programmed by the user, and controls the operational mode of the receive block. It
 * can only be written to when FEC_ECR[ETHER_EN] = 0 (that is, during initialization).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned LOOP : 1; //!< Internal loopback.When LOOP is set to 1, transmitted frames are looped back internal to the device and the transmit output signals are not asserted. The system clock is substituted for the FEC_TX_CLK when LOOP is set to 1. DRT must be set to zero when setting LOOP to 1.
        unsigned DRT : 1; //!< Disable receive on transmit.
        unsigned MII_MODE : 1; //!< Media independent interface mode. Selects external interface mode. Setting this bit to one selects MII mode, setting this bit equal to zero selects 7-wire mode (used only for serial 10 Mbps). This bit controls the interface mode for both transmit and receive blocks.
        unsigned PROM : 1; //!< Promiscuous mode. All frames are accepted regardless of address matching.
        unsigned BC_REJ : 1; //!< Broadcast frame reject. When BC_REJ is set to 1, frames with DA (destination address) = 0xFF_FF_FF_FF_FF_FF are rejected unless the PROM bit is set to 1. If both BC_REJ and PROM are set to 1, then frames with broadcast DA is accepted and the M (MISS) bit is set in the receive buffer descriptor.
        unsigned FCE : 1; //!< Flow control enable. When FCE is set to 1, the receiver detects pause frames. Upon pause frame detection, the transmitter stops transmitting data frames for a given duration.
        unsigned RESERVED0 : 10; //!< Reserved, read as 0
        unsigned MAX_FL : 11; //!< Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL causes the BABT interrupt to occur. Receive Frames longer than MAX_FL causes the BABR interrupt to occur and sets the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported).
        unsigned RESERVED1 : 5; //!< Reserved, read as 0
    } B;
} hw_fec_rcr_t;
#endif

/*
 * constants & macros for entire FEC_RCR register
 */
#define HW_FEC_RCR_ADDR      (REGS_FEC_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_RCR           (*(volatile hw_fec_rcr_t *) HW_FEC_RCR_ADDR)
#define HW_FEC_RCR_RD()      (HW_FEC_RCR.U)
#define HW_FEC_RCR_WR(v)     (HW_FEC_RCR.U = (v))
#define HW_FEC_RCR_SET(v)    (HW_FEC_RCR_WR(HW_FEC_RCR_RD() |  (v)))
#define HW_FEC_RCR_CLR(v)    (HW_FEC_RCR_WR(HW_FEC_RCR_RD() & ~(v)))
#define HW_FEC_RCR_TOG(v)    (HW_FEC_RCR_WR(HW_FEC_RCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_RCR bitfields
 */

/* --- Register HW_FEC_RCR, field LOOP[0:0] (RW)
 *
 * Internal loopback.When LOOP is set to 1, transmitted frames are looped back internal to the
 * device and the transmit output signals are not asserted. The system clock is substituted for the
 * FEC_TX_CLK when LOOP is set to 1. DRT must be set to zero when setting LOOP to 1.
 */

#define BP_FEC_RCR_LOOP      (0)
#define BM_FEC_RCR_LOOP      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_LOOP(v)   ((((reg32_t) v) << 0) & BM_FEC_RCR_LOOP)
#else
#define BF_FEC_RCR_LOOP(v)   (((v) << 0) & BM_FEC_RCR_LOOP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOP field to a new value.
#define BW_FEC_RCR_LOOP(v)   BF_CS1(FEC_RCR, LOOP, v)
#endif

/* --- Register HW_FEC_RCR, field DRT[1:1] (RW)
 *
 * Disable receive on transmit.
 *
 * Values:
 * 0 - Receive path operates independently of transmit (use for full-duplex or to monitor transmit activity
 *     in half-duplex mode).
 * 1 - Disable reception of frames while transmitting (normally used for half-duplex mode).
 */

#define BP_FEC_RCR_DRT      (1)
#define BM_FEC_RCR_DRT      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_DRT(v)   ((((reg32_t) v) << 1) & BM_FEC_RCR_DRT)
#else
#define BF_FEC_RCR_DRT(v)   (((v) << 1) & BM_FEC_RCR_DRT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DRT field to a new value.
#define BW_FEC_RCR_DRT(v)   BF_CS1(FEC_RCR, DRT, v)
#endif


/* --- Register HW_FEC_RCR, field MII_MODE[2:2] (RW)
 *
 * Media independent interface mode. Selects external interface mode. Setting this bit to one
 * selects MII mode, setting this bit equal to zero selects 7-wire mode (used only for serial 10
 * Mbps). This bit controls the interface mode for both transmit and receive blocks.
 */

#define BP_FEC_RCR_MII_MODE      (2)
#define BM_FEC_RCR_MII_MODE      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_MII_MODE(v)   ((((reg32_t) v) << 2) & BM_FEC_RCR_MII_MODE)
#else
#define BF_FEC_RCR_MII_MODE(v)   (((v) << 2) & BM_FEC_RCR_MII_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MII_MODE field to a new value.
#define BW_FEC_RCR_MII_MODE(v)   BF_CS1(FEC_RCR, MII_MODE, v)
#endif

/* --- Register HW_FEC_RCR, field PROM[3:3] (RW)
 *
 * Promiscuous mode. All frames are accepted regardless of address matching.
 */

#define BP_FEC_RCR_PROM      (3)
#define BM_FEC_RCR_PROM      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_PROM(v)   ((((reg32_t) v) << 3) & BM_FEC_RCR_PROM)
#else
#define BF_FEC_RCR_PROM(v)   (((v) << 3) & BM_FEC_RCR_PROM)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PROM field to a new value.
#define BW_FEC_RCR_PROM(v)   BF_CS1(FEC_RCR, PROM, v)
#endif

/* --- Register HW_FEC_RCR, field BC_REJ[4:4] (RW)
 *
 * Broadcast frame reject. When BC_REJ is set to 1, frames with DA (destination address) =
 * 0xFF_FF_FF_FF_FF_FF are rejected unless the PROM bit is set to 1. If both BC_REJ and PROM are set
 * to 1, then frames with broadcast DA is accepted and the M (MISS) bit is set in the receive buffer
 * descriptor.
 */

#define BP_FEC_RCR_BC_REJ      (4)
#define BM_FEC_RCR_BC_REJ      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_BC_REJ(v)   ((((reg32_t) v) << 4) & BM_FEC_RCR_BC_REJ)
#else
#define BF_FEC_RCR_BC_REJ(v)   (((v) << 4) & BM_FEC_RCR_BC_REJ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BC_REJ field to a new value.
#define BW_FEC_RCR_BC_REJ(v)   BF_CS1(FEC_RCR, BC_REJ, v)
#endif

/* --- Register HW_FEC_RCR, field FCE[5:5] (RW)
 *
 * Flow control enable. When FCE is set to 1, the receiver detects pause frames. Upon pause frame
 * detection, the transmitter stops transmitting data frames for a given duration.
 */

#define BP_FEC_RCR_FCE      (5)
#define BM_FEC_RCR_FCE      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_FCE(v)   ((((reg32_t) v) << 5) & BM_FEC_RCR_FCE)
#else
#define BF_FEC_RCR_FCE(v)   (((v) << 5) & BM_FEC_RCR_FCE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FCE field to a new value.
#define BW_FEC_RCR_FCE(v)   BF_CS1(FEC_RCR, FCE, v)
#endif

/* --- Register HW_FEC_RCR, field MAX_FL[26:16] (RW)
 *
 * Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the
 * CRC at the end of the frame. Transmit frames longer than MAX_FL causes the BABT interrupt to
 * occur. Receive Frames longer than MAX_FL causes the BABR interrupt to occur and sets the LG bit
 * in the end of frame receive buffer descriptor. The recommended default value to be programmed by
 * the user is 1518 or 1522 (if VLAN Tags are supported).
 */

#define BP_FEC_RCR_MAX_FL      (16)
#define BM_FEC_RCR_MAX_FL      (0x07ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_RCR_MAX_FL(v)   ((((reg32_t) v) << 16) & BM_FEC_RCR_MAX_FL)
#else
#define BF_FEC_RCR_MAX_FL(v)   (((v) << 16) & BM_FEC_RCR_MAX_FL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MAX_FL field to a new value.
#define BW_FEC_RCR_MAX_FL(v)   BF_CS1(FEC_RCR, MAX_FL, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_TCR - Transmit control register (RW)
 *
 * This register is read/write, and is written by the user to configure the transmit block. Bits
 * [2:1] must only be modified when FEC_ECR[ETHER_EN] = 0 (that is, during initialization). This
 * register is cleared at system reset.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GTS : 1; //!< Graceful transmit stop. When GTS is set to 1, the FEC stops transmission after any frame that is currently being transmitted is complete and the GRA interrupt in the FEC_EIR register is asserted. If frame transmission is not currently underway, the GRA interrupt is asserted immediately. After transmission has completed, a "restart" can be accomplished by clearing the GTS bit. The next frame in the transmit FIFO is then transmitted. If an early collision occurs during transmission when GTS = 1, transmission stops after the collision. The frame is transmitted again after GTS is cleared. There can be old frames in the transmit FIFO that is transmitted when GTS is reasserted. To avoid this, clear FEC_ECR[ETHER_EN] following the GRA interrupt.
        unsigned HBC : 1; //!< Heartbeat control. When HBC is set to 1, the heartbeat check is performed after end of transmission and the HB bit in the status register is set if the collision input does not assert within the heartbeat window. This bit must only be modified when ETHER_EN is cleared.
        unsigned FDEN : 1; //!< Full duplex enable. When FDEN is set to 1, frames are transmitted independent of carrier sense and collision inputs. This bit must only be modified when ETHER_EN is cleared.
        unsigned TFC_PAUSE : 1; //!< Transmit frame control pause. When this bit is set to 1, a pause frame is transmitted according to the following steps: 1. FEC stops transmission of data frames after the current transmission is complete. 2. The GRA interrupt in the FEC_EIR register is asserted. 3. With transmission of data frames stopped, the FEC transmits a MAC control pause frame. 4. The FEC clears the TFC_PAUSE bit and resume transmitting data frames. The FEC can still transmit a MAC control pause frame when the transmitter is paused due to user assertion of GTS or reception of a pause frame.
        unsigned RFC_PAUSE : 1; //!< Receive frame control pause. This read-only status bit is set to 1 when a full-duplex flow control pause frame has been received and the transmitter is paused for the duration defined in this pause frame. This bit automatically clears when the pause duration is complete.
        unsigned RESERVED0 : 27; //!< Reserved read as 0
    } B;
} hw_fec_tcr_t;
#endif

/*
 * constants & macros for entire FEC_TCR register
 */
#define HW_FEC_TCR_ADDR      (REGS_FEC_BASE + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_TCR           (*(volatile hw_fec_tcr_t *) HW_FEC_TCR_ADDR)
#define HW_FEC_TCR_RD()      (HW_FEC_TCR.U)
#define HW_FEC_TCR_WR(v)     (HW_FEC_TCR.U = (v))
#define HW_FEC_TCR_SET(v)    (HW_FEC_TCR_WR(HW_FEC_TCR_RD() |  (v)))
#define HW_FEC_TCR_CLR(v)    (HW_FEC_TCR_WR(HW_FEC_TCR_RD() & ~(v)))
#define HW_FEC_TCR_TOG(v)    (HW_FEC_TCR_WR(HW_FEC_TCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_TCR bitfields
 */

/* --- Register HW_FEC_TCR, field GTS[0:0] (RW)
 *
 * Graceful transmit stop. When GTS is set to 1, the FEC stops transmission after any frame that is
 * currently being transmitted is complete and the GRA interrupt in the FEC_EIR register is
 * asserted. If frame transmission is not currently underway, the GRA interrupt is asserted
 * immediately. After transmission has completed, a "restart" can be accomplished by clearing the
 * GTS bit. The next frame in the transmit FIFO is then transmitted. If an early collision occurs
 * during transmission when GTS = 1, transmission stops after the collision. The frame is
 * transmitted again after GTS is cleared. There can be old frames in the transmit FIFO that is
 * transmitted when GTS is reasserted. To avoid this, clear FEC_ECR[ETHER_EN] following the GRA
 * interrupt.
 *
 * Values:
 * 0 - Graceful transmit stop is not enabled
 * 1 - Graceful transmit stop is enabled.
 */

#define BP_FEC_TCR_GTS      (0)
#define BM_FEC_TCR_GTS      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_TCR_GTS(v)   ((((reg32_t) v) << 0) & BM_FEC_TCR_GTS)
#else
#define BF_FEC_TCR_GTS(v)   (((v) << 0) & BM_FEC_TCR_GTS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GTS field to a new value.
#define BW_FEC_TCR_GTS(v)   BF_CS1(FEC_TCR, GTS, v)
#endif


/* --- Register HW_FEC_TCR, field HBC[1:1] (RW)
 *
 * Heartbeat control. When HBC is set to 1, the heartbeat check is performed after end of
 * transmission and the HB bit in the status register is set if the collision input does not assert
 * within the heartbeat window. This bit must only be modified when ETHER_EN is cleared.
 *
 * Values:
 * 0 - Heartbeat check is not performed after end of transmission
 * 1 - Heartbeat check is performed after end of transmission
 */

#define BP_FEC_TCR_HBC      (1)
#define BM_FEC_TCR_HBC      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_TCR_HBC(v)   ((((reg32_t) v) << 1) & BM_FEC_TCR_HBC)
#else
#define BF_FEC_TCR_HBC(v)   (((v) << 1) & BM_FEC_TCR_HBC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBC field to a new value.
#define BW_FEC_TCR_HBC(v)   BF_CS1(FEC_TCR, HBC, v)
#endif


/* --- Register HW_FEC_TCR, field FDEN[2:2] (RW)
 *
 * Full duplex enable. When FDEN is set to 1, frames are transmitted independent of carrier sense
 * and collision inputs. This bit must only be modified when ETHER_EN is cleared.
 *
 * Values:
 * 0 - Full duplex is not enabled
 * 1 - Full duplex is enabled
 */

#define BP_FEC_TCR_FDEN      (2)
#define BM_FEC_TCR_FDEN      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_TCR_FDEN(v)   ((((reg32_t) v) << 2) & BM_FEC_TCR_FDEN)
#else
#define BF_FEC_TCR_FDEN(v)   (((v) << 2) & BM_FEC_TCR_FDEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FDEN field to a new value.
#define BW_FEC_TCR_FDEN(v)   BF_CS1(FEC_TCR, FDEN, v)
#endif


/* --- Register HW_FEC_TCR, field TFC_PAUSE[3:3] (RW)
 *
 * Transmit frame control pause. When this bit is set to 1, a pause frame is transmitted according
 * to the following steps: 1. FEC stops transmission of data frames after the current transmission
 * is complete. 2. The GRA interrupt in the FEC_EIR register is asserted. 3. With transmission of
 * data frames stopped, the FEC transmits a MAC control pause frame. 4. The FEC clears the TFC_PAUSE
 * bit and resume transmitting data frames. The FEC can still transmit a MAC control pause frame
 * when the transmitter is paused due to user assertion of GTS or reception of a pause frame.
 *
 * Values:
 * 0 - No pause frame is transmitted
 * 1 - Pause frame is transmitted
 */

#define BP_FEC_TCR_TFC_PAUSE      (3)
#define BM_FEC_TCR_TFC_PAUSE      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_TCR_TFC_PAUSE(v)   ((((reg32_t) v) << 3) & BM_FEC_TCR_TFC_PAUSE)
#else
#define BF_FEC_TCR_TFC_PAUSE(v)   (((v) << 3) & BM_FEC_TCR_TFC_PAUSE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TFC_PAUSE field to a new value.
#define BW_FEC_TCR_TFC_PAUSE(v)   BF_CS1(FEC_TCR, TFC_PAUSE, v)
#endif


/* --- Register HW_FEC_TCR, field RFC_PAUSE[4:4] (RO)
 *
 * Receive frame control pause. This read-only status bit is set to 1 when a full-duplex flow
 * control pause frame has been received and the transmitter is paused for the duration defined in
 * this pause frame. This bit automatically clears when the pause duration is complete.
 *
 * Values:
 * 0 - Transmitter is not paused
 * 1 - Transmitter is paused after reception of full-duplex flow control pause frame
 */

#define BP_FEC_TCR_RFC_PAUSE      (4)
#define BM_FEC_TCR_RFC_PAUSE      (0x00000010)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_PALR - Physical address low register (RW)
 *
 * The FEC_PALR is written by the user, and contains the lower 32 bits (bytes 0,1,2,3) of the 48-bit
 * address used in the address recognition process to check for possible match between the DA field
 * of receive frames and an individual DA. This register is also used for bytes 0 through 3 of the
 * 6-byte source address field when transmitting pause frames. This register is unaffected by reset
 * and must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PADDR1 : 32; //!< Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the source address field in pause frames.
    } B;
} hw_fec_palr_t;
#endif

/*
 * constants & macros for entire FEC_PALR register
 */
#define HW_FEC_PALR_ADDR      (REGS_FEC_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_PALR           (*(volatile hw_fec_palr_t *) HW_FEC_PALR_ADDR)
#define HW_FEC_PALR_RD()      (HW_FEC_PALR.U)
#define HW_FEC_PALR_WR(v)     (HW_FEC_PALR.U = (v))
#define HW_FEC_PALR_SET(v)    (HW_FEC_PALR_WR(HW_FEC_PALR_RD() |  (v)))
#define HW_FEC_PALR_CLR(v)    (HW_FEC_PALR_WR(HW_FEC_PALR_RD() & ~(v)))
#define HW_FEC_PALR_TOG(v)    (HW_FEC_PALR_WR(HW_FEC_PALR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_PALR bitfields
 */

/* --- Register HW_FEC_PALR, field PADDR1[31:0] (RW)
 *
 * Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual
 * address to be used for exact match, and the source address field in pause frames.
 */

#define BP_FEC_PALR_PADDR1      (0)
#define BM_FEC_PALR_PADDR1      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_PALR_PADDR1(v)   ((((reg32_t) v) << 0) & BM_FEC_PALR_PADDR1)
#else
#define BF_FEC_PALR_PADDR1(v)   (((v) << 0) & BM_FEC_PALR_PADDR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PADDR1 field to a new value.
#define BW_FEC_PALR_PADDR1(v)   BF_CS1(FEC_PALR, PADDR1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_PAUR - Physical address upper register (RW)
 *
 * The FEC_PAUR is written by the user, and contains the upper 16 bits (bytes 4 and 5) of the 48-bit
 * address used in the address recognition process to check for possible match between the DA field
 * of receive frames and an individual DA. In addition, this register is used in bytes 4 and 5 of
 * the 6-byte source address field when transmitting pause frames. Bits 15:0 of FEC_PAUR contain a
 * constant type field (0x8808) used for transmission of pause frames. This register is unaffected
 * by reset, and bits 31:16 must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TYPE : 16; //!< Type field in pause frames. This field has a constant value of 0x8808.
        unsigned PADDR2 : 16; //!< Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the source address field in pause frames.
    } B;
} hw_fec_paur_t;
#endif

/*
 * constants & macros for entire FEC_PAUR register
 */
#define HW_FEC_PAUR_ADDR      (REGS_FEC_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_PAUR           (*(volatile hw_fec_paur_t *) HW_FEC_PAUR_ADDR)
#define HW_FEC_PAUR_RD()      (HW_FEC_PAUR.U)
#define HW_FEC_PAUR_WR(v)     (HW_FEC_PAUR.U = (v))
#define HW_FEC_PAUR_SET(v)    (HW_FEC_PAUR_WR(HW_FEC_PAUR_RD() |  (v)))
#define HW_FEC_PAUR_CLR(v)    (HW_FEC_PAUR_WR(HW_FEC_PAUR_RD() & ~(v)))
#define HW_FEC_PAUR_TOG(v)    (HW_FEC_PAUR_WR(HW_FEC_PAUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_PAUR bitfields
 */

/* --- Register HW_FEC_PAUR, field TYPE[15:0] (RO)
 *
 * Type field in pause frames. This field has a constant value of 0x8808.
 */

#define BP_FEC_PAUR_TYPE      (0)
#define BM_FEC_PAUR_TYPE      (0x0000ffff)

/* --- Register HW_FEC_PAUR, field PADDR2[31:16] (RW)
 *
 * Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact
 * match, and the source address field in pause frames.
 */

#define BP_FEC_PAUR_PADDR2      (16)
#define BM_FEC_PAUR_PADDR2      (0xffff0000)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_PAUR_PADDR2(v)   ((((reg32_t) v) << 16) & BM_FEC_PAUR_PADDR2)
#else
#define BF_FEC_PAUR_PADDR2(v)   (((v) << 16) & BM_FEC_PAUR_PADDR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PADDR2 field to a new value.
#define BW_FEC_PAUR_PADDR2(v)   BF_CS1(FEC_PAUR, PADDR2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_OPDR - Opcode and pause duration register (RW)
 *
 * FEC_OPDR contains the 16-bit Opcode, and 16-bit pause duration fields used in transmission of a
 * pause frame. The Opcode field is a constant value, 0x0001. When another node detects a pause
 * frame, that node pauses transmission for the duration specified in the pause duration field. This
 * register is not reset and must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PAUSE_DUR : 16; //!< Pause duration field used in pause frames.
        unsigned OPCODE : 16; //!< Opcode field used in pause frames. These bits are a constant, 0x0001.
    } B;
} hw_fec_opdr_t;
#endif

/*
 * constants & macros for entire FEC_OPDR register
 */
#define HW_FEC_OPDR_ADDR      (REGS_FEC_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_OPDR           (*(volatile hw_fec_opdr_t *) HW_FEC_OPDR_ADDR)
#define HW_FEC_OPDR_RD()      (HW_FEC_OPDR.U)
#define HW_FEC_OPDR_WR(v)     (HW_FEC_OPDR.U = (v))
#define HW_FEC_OPDR_SET(v)    (HW_FEC_OPDR_WR(HW_FEC_OPDR_RD() |  (v)))
#define HW_FEC_OPDR_CLR(v)    (HW_FEC_OPDR_WR(HW_FEC_OPDR_RD() & ~(v)))
#define HW_FEC_OPDR_TOG(v)    (HW_FEC_OPDR_WR(HW_FEC_OPDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_OPDR bitfields
 */

/* --- Register HW_FEC_OPDR, field PAUSE_DUR[15:0] (RW)
 *
 * Pause duration field used in pause frames.
 */

#define BP_FEC_OPDR_PAUSE_DUR      (0)
#define BM_FEC_OPDR_PAUSE_DUR      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_OPDR_PAUSE_DUR(v)   ((((reg32_t) v) << 0) & BM_FEC_OPDR_PAUSE_DUR)
#else
#define BF_FEC_OPDR_PAUSE_DUR(v)   (((v) << 0) & BM_FEC_OPDR_PAUSE_DUR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PAUSE_DUR field to a new value.
#define BW_FEC_OPDR_PAUSE_DUR(v)   BF_CS1(FEC_OPDR, PAUSE_DUR, v)
#endif

/* --- Register HW_FEC_OPDR, field OPCODE[31:16] (RO)
 *
 * Opcode field used in pause frames. These bits are a constant, 0x0001.
 */

#define BP_FEC_OPDR_OPCODE      (16)
#define BM_FEC_OPDR_OPCODE      (0xffff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_IAUR - Descriptor individual address upper register (RW)
 *
 * The FEC_IAUR is written by the user, and contains the upper 32 bits of the 64-bit individual
 * address hash table used in the address recognition process to check for possible match between
 * the DA field of receive frames and an individual DA. This register is unaffected by reset, and
 * must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IADDR1 : 32; //!< The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32.
    } B;
} hw_fec_iaur_t;
#endif

/*
 * constants & macros for entire FEC_IAUR register
 */
#define HW_FEC_IAUR_ADDR      (REGS_FEC_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_IAUR           (*(volatile hw_fec_iaur_t *) HW_FEC_IAUR_ADDR)
#define HW_FEC_IAUR_RD()      (HW_FEC_IAUR.U)
#define HW_FEC_IAUR_WR(v)     (HW_FEC_IAUR.U = (v))
#define HW_FEC_IAUR_SET(v)    (HW_FEC_IAUR_WR(HW_FEC_IAUR_RD() |  (v)))
#define HW_FEC_IAUR_CLR(v)    (HW_FEC_IAUR_WR(HW_FEC_IAUR_RD() & ~(v)))
#define HW_FEC_IAUR_TOG(v)    (HW_FEC_IAUR_WR(HW_FEC_IAUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_IAUR bitfields
 */

/* --- Register HW_FEC_IAUR, field IADDR1[31:0] (RW)
 *
 * The upper 32 bits of the 64-bit hash table used in the address recognition process for receive
 * frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1
 * contains hash index bit 32.
 */

#define BP_FEC_IAUR_IADDR1      (0)
#define BM_FEC_IAUR_IADDR1      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_IAUR_IADDR1(v)   ((((reg32_t) v) << 0) & BM_FEC_IAUR_IADDR1)
#else
#define BF_FEC_IAUR_IADDR1(v)   (((v) << 0) & BM_FEC_IAUR_IADDR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IADDR1 field to a new value.
#define BW_FEC_IAUR_IADDR1(v)   BF_CS1(FEC_IAUR, IADDR1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_IALR - Descriptor individual address lower register (RW)
 *
 * The FEC_IALR is written by the user, and contains the lower 32 bits of the 64-bit individual
 * address hash table used in the address recognition process to check for possible match with the
 * DA field of receive frames with an individual DA. This register is unaffected by reset, and must
 * be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IADDR2 : 32; //!< The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0.
    } B;
} hw_fec_ialr_t;
#endif

/*
 * constants & macros for entire FEC_IALR register
 */
#define HW_FEC_IALR_ADDR      (REGS_FEC_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_IALR           (*(volatile hw_fec_ialr_t *) HW_FEC_IALR_ADDR)
#define HW_FEC_IALR_RD()      (HW_FEC_IALR.U)
#define HW_FEC_IALR_WR(v)     (HW_FEC_IALR.U = (v))
#define HW_FEC_IALR_SET(v)    (HW_FEC_IALR_WR(HW_FEC_IALR_RD() |  (v)))
#define HW_FEC_IALR_CLR(v)    (HW_FEC_IALR_WR(HW_FEC_IALR_RD() & ~(v)))
#define HW_FEC_IALR_TOG(v)    (HW_FEC_IALR_WR(HW_FEC_IALR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_IALR bitfields
 */

/* --- Register HW_FEC_IALR, field IADDR2[31:0] (RW)
 *
 * The lower 32 bits of the 64-bit hash table used in the address recognition process for receive
 * frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2
 * contains hash index bit 0.
 */

#define BP_FEC_IALR_IADDR2      (0)
#define BM_FEC_IALR_IADDR2      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_IALR_IADDR2(v)   ((((reg32_t) v) << 0) & BM_FEC_IALR_IADDR2)
#else
#define BF_FEC_IALR_IADDR2(v)   (((v) << 0) & BM_FEC_IALR_IADDR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IADDR2 field to a new value.
#define BW_FEC_IALR_IADDR2(v)   BF_CS1(FEC_IALR, IADDR2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_GAUR - Descriptor group address upper register (RW)
 *
 * The FEC_GAUR is written by the user, and contains the upper 32 bits of the 64-bit hash table used
 * in the address recognition process for receive frames with a multicast address. This register
 * must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GADDR1 : 32; //!< The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32.
    } B;
} hw_fec_gaur_t;
#endif

/*
 * constants & macros for entire FEC_GAUR register
 */
#define HW_FEC_GAUR_ADDR      (REGS_FEC_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_GAUR           (*(volatile hw_fec_gaur_t *) HW_FEC_GAUR_ADDR)
#define HW_FEC_GAUR_RD()      (HW_FEC_GAUR.U)
#define HW_FEC_GAUR_WR(v)     (HW_FEC_GAUR.U = (v))
#define HW_FEC_GAUR_SET(v)    (HW_FEC_GAUR_WR(HW_FEC_GAUR_RD() |  (v)))
#define HW_FEC_GAUR_CLR(v)    (HW_FEC_GAUR_WR(HW_FEC_GAUR_RD() & ~(v)))
#define HW_FEC_GAUR_TOG(v)    (HW_FEC_GAUR_WR(HW_FEC_GAUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_GAUR bitfields
 */

/* --- Register HW_FEC_GAUR, field GADDR1[31:0] (RW)
 *
 * The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address
 * recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash
 * index bit 63. Bit 0 of GADDR1 contains hash index bit 32.
 */

#define BP_FEC_GAUR_GADDR1      (0)
#define BM_FEC_GAUR_GADDR1      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_GAUR_GADDR1(v)   ((((reg32_t) v) << 0) & BM_FEC_GAUR_GADDR1)
#else
#define BF_FEC_GAUR_GADDR1(v)   (((v) << 0) & BM_FEC_GAUR_GADDR1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GADDR1 field to a new value.
#define BW_FEC_GAUR_GADDR1(v)   BF_CS1(FEC_GAUR, GADDR1, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_GALR - Descriptor group address lower register (RW)
 *
 * The FEC_GALR is written by the user, and contains the lower 32 bits of the 64-bit hash table used
 * in the address recognition process for receive frames with a multicast address. This register
 * must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GADDR2 : 32; //!< The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0.
    } B;
} hw_fec_galr_t;
#endif

/*
 * constants & macros for entire FEC_GALR register
 */
#define HW_FEC_GALR_ADDR      (REGS_FEC_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_GALR           (*(volatile hw_fec_galr_t *) HW_FEC_GALR_ADDR)
#define HW_FEC_GALR_RD()      (HW_FEC_GALR.U)
#define HW_FEC_GALR_WR(v)     (HW_FEC_GALR.U = (v))
#define HW_FEC_GALR_SET(v)    (HW_FEC_GALR_WR(HW_FEC_GALR_RD() |  (v)))
#define HW_FEC_GALR_CLR(v)    (HW_FEC_GALR_WR(HW_FEC_GALR_RD() & ~(v)))
#define HW_FEC_GALR_TOG(v)    (HW_FEC_GALR_WR(HW_FEC_GALR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_GALR bitfields
 */

/* --- Register HW_FEC_GALR, field GADDR2[31:0] (RW)
 *
 * The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address
 * recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash
 * index bit 31. Bit 0 of GADDR2 contains hash index bit 0.
 */

#define BP_FEC_GALR_GADDR2      (0)
#define BM_FEC_GALR_GADDR2      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_GALR_GADDR2(v)   ((((reg32_t) v) << 0) & BM_FEC_GALR_GADDR2)
#else
#define BF_FEC_GALR_GADDR2(v)   (((v) << 0) & BM_FEC_GALR_GADDR2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GADDR2 field to a new value.
#define BW_FEC_GALR_GADDR2(v)   BF_CS1(FEC_GALR, GADDR2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_TFWR - Transmit FIFO watermark register (RW)
 *
 * The FEC_TFWR is programmed by the user to control the amount of data required in the transmit
 * FIFO before transmission of a frame can begin. This allows the user to minimize transmit latency
 * (FEC_TFWR[1:0] = 0 n ) or allow for larger bus access latency (FEC_TFWR[1:0] = 11) due to
 * contention for the system bus. Setting the watermark to a high value minimizes the risk of
 * transmit FIFO underrun due to contention for the system bus. In some use cases the byte counts
 * associated with the FEC_TFWR field need to be modified to match system requirements, such as the
 * worst-case bus access latency by the transmit data DMA channel.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned X_WMRK : 2; //!< Number of bytes written to transmit FIFO before transmission of a frame begins
        unsigned RESERVED0 : 30; //!< Reserved, read as 0
    } B;
} hw_fec_tfwr_t;
#endif

/*
 * constants & macros for entire FEC_TFWR register
 */
#define HW_FEC_TFWR_ADDR      (REGS_FEC_BASE + 0x144)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_TFWR           (*(volatile hw_fec_tfwr_t *) HW_FEC_TFWR_ADDR)
#define HW_FEC_TFWR_RD()      (HW_FEC_TFWR.U)
#define HW_FEC_TFWR_WR(v)     (HW_FEC_TFWR.U = (v))
#define HW_FEC_TFWR_SET(v)    (HW_FEC_TFWR_WR(HW_FEC_TFWR_RD() |  (v)))
#define HW_FEC_TFWR_CLR(v)    (HW_FEC_TFWR_WR(HW_FEC_TFWR_RD() & ~(v)))
#define HW_FEC_TFWR_TOG(v)    (HW_FEC_TFWR_WR(HW_FEC_TFWR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_TFWR bitfields
 */

/* --- Register HW_FEC_TFWR, field X_WMRK[1:0] (RW)
 *
 * Number of bytes written to transmit FIFO before transmission of a frame begins
 *
 * Values:
 * 0x - 64 bytes written
 * 10 - 128 bytes written
 * 11 - 192 bytes written
 */

#define BP_FEC_TFWR_X_WMRK      (0)
#define BM_FEC_TFWR_X_WMRK      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_TFWR_X_WMRK(v)   ((((reg32_t) v) << 0) & BM_FEC_TFWR_X_WMRK)
#else
#define BF_FEC_TFWR_X_WMRK(v)   (((v) << 0) & BM_FEC_TFWR_X_WMRK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X_WMRK field to a new value.
#define BW_FEC_TFWR_X_WMRK(v)   BF_CS1(FEC_TFWR, X_WMRK, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_FRBR - FIFO receive bound register (RO)
 *
 * The FEC_FRBR register can be read to determine the upper address bound of the FIFO RAM. Drivers
 * can use this value, along with the FEC_FRSR to appropriately divide the available FIFO RAM
 * between the transmit and receive data paths.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved, read as 0.
        unsigned R_BOUND : 8; //!< Read-only. Highest valid FIFO RAM address.
        unsigned RESERVED1 : 22; //!< Reserved, read as 0 (except bit 10, which is read as 1).
    } B;
} hw_fec_frbr_t;
#endif

/*
 * constants & macros for entire FEC_FRBR register
 */
#define HW_FEC_FRBR_ADDR      (REGS_FEC_BASE + 0x14c)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_FRBR           (*(volatile hw_fec_frbr_t *) HW_FEC_FRBR_ADDR)
#define HW_FEC_FRBR_RD()      (HW_FEC_FRBR.U)
#endif

/*
 * constants & macros for individual FEC_FRBR bitfields
 */

/* --- Register HW_FEC_FRBR, field R_BOUND[9:2] (RO)
 *
 * Read-only. Highest valid FIFO RAM address.
 */

#define BP_FEC_FRBR_R_BOUND      (2)
#define BM_FEC_FRBR_R_BOUND      (0x000003fc)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_FRSR - FIFO receive FIFO start registers (RW)
 *
 * FEC_FRSR is an 8-bit register programmed by the user to indicate the starting address of the
 * receive FIFO. FEC_FRSR marks the boundary between the transmit and receive FIFOs. The transmit
 * FIFO uses addresses from the start of the FIFO to the location four bytes before the address
 * programmed into the FEC_FRSR. The receive FIFO uses the addresses from FEC_FRSR to FEC_FRBR
 * inclusive.  The default value of the receive FIFO starting address is 0x40. This is the value
 * assigned by hardware at reset.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved, read as 0.
        unsigned R_FSTART : 8; //!< Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs.
        unsigned RESERVED1 : 22; //!< Reserved, read as 0 (except bit 10, which is read as 1).
    } B;
} hw_fec_frsr_t;
#endif

/*
 * constants & macros for entire FEC_FRSR register
 */
#define HW_FEC_FRSR_ADDR      (REGS_FEC_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_FRSR           (*(volatile hw_fec_frsr_t *) HW_FEC_FRSR_ADDR)
#define HW_FEC_FRSR_RD()      (HW_FEC_FRSR.U)
#define HW_FEC_FRSR_WR(v)     (HW_FEC_FRSR.U = (v))
#define HW_FEC_FRSR_SET(v)    (HW_FEC_FRSR_WR(HW_FEC_FRSR_RD() |  (v)))
#define HW_FEC_FRSR_CLR(v)    (HW_FEC_FRSR_WR(HW_FEC_FRSR_RD() & ~(v)))
#define HW_FEC_FRSR_TOG(v)    (HW_FEC_FRSR_WR(HW_FEC_FRSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_FRSR bitfields
 */

/* --- Register HW_FEC_FRSR, field R_FSTART[9:2] (RW)
 *
 * Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs.
 */

#define BP_FEC_FRSR_R_FSTART      (2)
#define BM_FEC_FRSR_R_FSTART      (0x000003fc)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_FRSR_R_FSTART(v)   ((((reg32_t) v) << 2) & BM_FEC_FRSR_R_FSTART)
#else
#define BF_FEC_FRSR_R_FSTART(v)   (((v) << 2) & BM_FEC_FRSR_R_FSTART)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the R_FSTART field to a new value.
#define BW_FEC_FRSR_R_FSTART(v)   BF_CS1(FEC_FRSR, R_FSTART, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_ERDSR - Receive buffer descriptor ring start register (RW)
 *
 * The register is written by the user, and provides a pointer to the start of the circular receive
 * buffer descriptor queue in external memory. This pointer must be 128-bit aligned (that is, evenly
 * divisible by 16).  Does the above paragraph mean that R_DES_START provides the pointer in units
 * of 32 bits? If so, this should be made clear -- CThron  This register is unaffected by reset and
 * must be initialized by the user prior to operation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved, read as 0
        unsigned R_DES_START : 30; //!< Pointer to start of receive buffer descriptor queue.
    } B;
} hw_fec_erdsr_t;
#endif

/*
 * constants & macros for entire FEC_ERDSR register
 */
#define HW_FEC_ERDSR_ADDR      (REGS_FEC_BASE + 0x180)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_ERDSR           (*(volatile hw_fec_erdsr_t *) HW_FEC_ERDSR_ADDR)
#define HW_FEC_ERDSR_RD()      (HW_FEC_ERDSR.U)
#define HW_FEC_ERDSR_WR(v)     (HW_FEC_ERDSR.U = (v))
#define HW_FEC_ERDSR_SET(v)    (HW_FEC_ERDSR_WR(HW_FEC_ERDSR_RD() |  (v)))
#define HW_FEC_ERDSR_CLR(v)    (HW_FEC_ERDSR_WR(HW_FEC_ERDSR_RD() & ~(v)))
#define HW_FEC_ERDSR_TOG(v)    (HW_FEC_ERDSR_WR(HW_FEC_ERDSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_ERDSR bitfields
 */

/* --- Register HW_FEC_ERDSR, field R_DES_START[31:2] (RW)
 *
 * Pointer to start of receive buffer descriptor queue.
 */

#define BP_FEC_ERDSR_R_DES_START      (2)
#define BM_FEC_ERDSR_R_DES_START      (0xfffffffc)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_ERDSR_R_DES_START(v)   ((((reg32_t) v) << 2) & BM_FEC_ERDSR_R_DES_START)
#else
#define BF_FEC_ERDSR_R_DES_START(v)   (((v) << 2) & BM_FEC_ERDSR_R_DES_START)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the R_DES_START field to a new value.
#define BW_FEC_ERDSR_R_DES_START(v)   BF_CS1(FEC_ERDSR, R_DES_START, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_ETDSR - Transmit buffer descriptor ring start register (RW)
 *
 * The register is written by the user, and provides a pointer to the start of the circular transmit
 * buffer descriptor queue in external memory. This pointer must be 128-bit aligned (that is, evenly
 * divisible by 16).  Does the above paragraph mean that X_DES_START provides the pointer in units
 * of 32 bits? If so, this should be made clear -- CThron  This register is unaffected by reset and
 * must be initialized by the user prior to operation.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved, read as 0
        unsigned X_DES_START : 30; //!< Pointer to start of transmit buffer descriptor queue.
    } B;
} hw_fec_etdsr_t;
#endif

/*
 * constants & macros for entire FEC_ETDSR register
 */
#define HW_FEC_ETDSR_ADDR      (REGS_FEC_BASE + 0x184)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_ETDSR           (*(volatile hw_fec_etdsr_t *) HW_FEC_ETDSR_ADDR)
#define HW_FEC_ETDSR_RD()      (HW_FEC_ETDSR.U)
#define HW_FEC_ETDSR_WR(v)     (HW_FEC_ETDSR.U = (v))
#define HW_FEC_ETDSR_SET(v)    (HW_FEC_ETDSR_WR(HW_FEC_ETDSR_RD() |  (v)))
#define HW_FEC_ETDSR_CLR(v)    (HW_FEC_ETDSR_WR(HW_FEC_ETDSR_RD() & ~(v)))
#define HW_FEC_ETDSR_TOG(v)    (HW_FEC_ETDSR_WR(HW_FEC_ETDSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_ETDSR bitfields
 */

/* --- Register HW_FEC_ETDSR, field X_DES_START[31:2] (RW)
 *
 * Pointer to start of transmit buffer descriptor queue.
 */

#define BP_FEC_ETDSR_X_DES_START      (2)
#define BM_FEC_ETDSR_X_DES_START      (0xfffffffc)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_ETDSR_X_DES_START(v)   ((((reg32_t) v) << 2) & BM_FEC_ETDSR_X_DES_START)
#else
#define BF_FEC_ETDSR_X_DES_START(v)   (((v) << 2) & BM_FEC_ETDSR_X_DES_START)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the X_DES_START field to a new value.
#define BW_FEC_ETDSR_X_DES_START(v)   BF_CS1(FEC_ETDSR, X_DES_START, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FEC_EMRBR - Maximum receive buffer size register (RW)
 *
 * The FEC_EMRBR is a user-programmable register which dictates the maximum size of all receive
 * buffers. Note that because receive frames is truncated at 2k-1(2047) bytes, bits 31-11 are not
 * used. The programmed value accounts for the fact that the receive CRC is always written into the
 * last receive buffer. To allow one maximum size frame per buffer, FEC_EMRBR must be set to
 * FEC_RCR[MAX_FL] or larger. The FEC_EMRBR must be evenly divisible by 16. To ensure this, bits 3-0
 * are forced low, and hence only bits 10-4 are actually used. To minimize bus utilization
 * (descriptor fetches) it is recommended that FEC_EMRBR be greater than or equal to 256 bytes.  The
 * FEC_EMRBR is unaffected by reset, and must be initialized by the user.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved, is written to 0 by the host processor.
        unsigned R_BUF_SIZE : 7; //!< Receive buffer size.
        unsigned RESERVED1 : 21; //!< Reserved, is written to 0 by the host processor.
    } B;
} hw_fec_emrbr_t;
#endif

/*
 * constants & macros for entire FEC_EMRBR register
 */
#define HW_FEC_EMRBR_ADDR      (REGS_FEC_BASE + 0x188)

#ifndef __LANGUAGE_ASM__
#define HW_FEC_EMRBR           (*(volatile hw_fec_emrbr_t *) HW_FEC_EMRBR_ADDR)
#define HW_FEC_EMRBR_RD()      (HW_FEC_EMRBR.U)
#define HW_FEC_EMRBR_WR(v)     (HW_FEC_EMRBR.U = (v))
#define HW_FEC_EMRBR_SET(v)    (HW_FEC_EMRBR_WR(HW_FEC_EMRBR_RD() |  (v)))
#define HW_FEC_EMRBR_CLR(v)    (HW_FEC_EMRBR_WR(HW_FEC_EMRBR_RD() & ~(v)))
#define HW_FEC_EMRBR_TOG(v)    (HW_FEC_EMRBR_WR(HW_FEC_EMRBR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual FEC_EMRBR bitfields
 */

/* --- Register HW_FEC_EMRBR, field R_BUF_SIZE[10:4] (RW)
 *
 * Receive buffer size.
 */

#define BP_FEC_EMRBR_R_BUF_SIZE      (4)
#define BM_FEC_EMRBR_R_BUF_SIZE      (0x000007f0)

#ifndef __LANGUAGE_ASM__
#define BF_FEC_EMRBR_R_BUF_SIZE(v)   ((((reg32_t) v) << 4) & BM_FEC_EMRBR_R_BUF_SIZE)
#else
#define BF_FEC_EMRBR_R_BUF_SIZE(v)   (((v) << 4) & BM_FEC_EMRBR_R_BUF_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the R_BUF_SIZE field to a new value.
#define BW_FEC_EMRBR_R_BUF_SIZE(v)   BF_CS1(FEC_EMRBR, R_BUF_SIZE, v)
#endif


/*!
 * @brief All FEC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    reg32_t _reserved0;
    volatile hw_fec_eir_t EIR; //!< Ethernet interrupt event register
    volatile hw_fec_eimr_t EIMR; //!< Ethernet interrupt mask register
    reg32_t _reserved1;
    volatile hw_fec_rdar_t RDAR; //!< Receive descriptor active register
    volatile hw_fec_tdar_t TDAR; //!< Transmit descriptor active register
    reg32_t _reserved2[3];
    volatile hw_fec_ecr_t ECR; //!< Ethernet control register
    reg32_t _reserved3[6];
    volatile hw_fec_mmfr_t MMFR; //!< MII management frame register
    volatile hw_fec_mscr_t MSCR; //!< MII speed control register
    reg32_t _reserved4[7];
    volatile hw_fec_mibc_t MIBC; //!< MIB control register
    reg32_t _reserved5[7];
    volatile hw_fec_rcr_t RCR; //!< Receive control register
    reg32_t _reserved6[15];
    volatile hw_fec_tcr_t TCR; //!< Transmit control register
    reg32_t _reserved7[7];
    volatile hw_fec_palr_t PALR; //!< Physical address low register
    volatile hw_fec_paur_t PAUR; //!< Physical address upper register
    volatile hw_fec_opdr_t OPDR; //!< Opcode and pause duration register
    reg32_t _reserved8[10];
    volatile hw_fec_iaur_t IAUR; //!< Descriptor individual address upper register
    volatile hw_fec_ialr_t IALR; //!< Descriptor individual address lower register
    volatile hw_fec_gaur_t GAUR; //!< Descriptor group address upper register
    volatile hw_fec_galr_t GALR; //!< Descriptor group address lower register
    reg32_t _reserved9[7];
    volatile hw_fec_tfwr_t TFWR; //!< Transmit FIFO watermark register
    reg32_t _reserved10;
    volatile hw_fec_frbr_t FRBR; //!< FIFO receive bound register
    volatile hw_fec_frsr_t FRSR; //!< FIFO receive FIFO start registers
    reg32_t _reserved11[11];
    volatile hw_fec_erdsr_t ERDSR; //!< Receive buffer descriptor ring start register
    volatile hw_fec_etdsr_t ETDSR; //!< Transmit buffer descriptor ring start register
    volatile hw_fec_emrbr_t EMRBR; //!< Maximum receive buffer size register
} hw_fec_t;
#endif

//! @brief Macro to access all FEC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_FEC(0)</code>.
#define HW_FEC     (*(volatile hw_fec_t *) REGS_FEC_BASE)


#endif // _FEC_H
