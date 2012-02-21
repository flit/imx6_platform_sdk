/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USDHC_H
#define _USDHC_H

#include "regs.h"

#ifndef REGS_USDHC_BASE
#define REGS_USDHC0_BASE (REGS_BASE + 0x02190000)
#define REGS_USDHC1_BASE (REGS_BASE + 0x02194000)
#define REGS_USDHC2_BASE (REGS_BASE + 0x02198000)
#define REGS_USDHC3_BASE (REGS_BASE + 0x0219c000)
#define REGS_USDHC_BASE(x) ( x == 0 ? REGS_USDHC0_BASE : x == 1 ? REGS_USDHC1_BASE : x == 2 ? REGS_USDHC2_BASE : x == 3 ? REGS_USDHC3_BASE : 0xffff0000)
#endif


/*!
 * @brief HW_USDHC_DS_ADDR - DMA System Address
 *
 * This register contains the physical system memory address used for DMA
 * transfers.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned DS_ADDR : 30; //!< DMA System Address:  This register contains the 32-bit system memory address for a DMA transfer. Since the address must be word (4 bytes) align, the least 2 bits are reserved, always 0. When the uSDHC stops a DMA transfer, this register points to the system address of the next contiguous data position. It can be accessed only when no transaction is executing (i.e. after a transaction has stopped). Read operation during transfers may return an invalid value. The Host Driver shall initialize this register before starting a DMA transaction. After DMA has stopped, the system address of the next contiguous data position can be read from this register.  This register is protected during a data transfer. When data lines are active, write to this register is ignored. The Host driver shall wait, until the DLA bit in the Present State register is cleared, before writing to this register.  The uSDHC internal DMA does not support a virtual memory system. It only supports continuous physical memory access. And due to AHB burst limitations, if the burst must cross the 1 KB boundary, uSDHC will automatically change SEQ burst type to NSEQ.  Since this register supports dynamic address reflecting, when TC bit is set, it automatically alters the value of internal address counter, so SW cannot change this register when TC bit is set. Such restriction is also listed in .
    } B;
} hw_usdhc_ds_addr_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DS_ADDR register
 */
#define HW_USDHC_DS_ADDR_ADDR(x)      (REGS_USDHC_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DS_ADDR(x)           (*(volatile hw_usdhc_ds_addr_t *) HW_USDHC_DS_ADDR_ADDR(x))
#define HW_USDHC_DS_ADDR_RD(x)        (HW_USDHC_DS_ADDR(x).U)
#define HW_USDHC_DS_ADDR_WR(x, v)     (HW_USDHC_DS_ADDR(x).U = (v))
#define HW_USDHC_DS_ADDR_SET(x, v)    (HW_USDHC_DS_ADDR_WR(x, HW_USDHC_DS_ADDR_RD(x) |  (v)))
#define HW_USDHC_DS_ADDR_CLR(x, v)    (HW_USDHC_DS_ADDR_WR(x, HW_USDHC_DS_ADDR_RD(x) & ~(v)))
#define HW_USDHC_DS_ADDR_TOG(x, v)    (HW_USDHC_DS_ADDR_WR(x, HW_USDHC_DS_ADDR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DS_ADDR bitfields
 */

/* --- Register HW_USDHC_DS_ADDR, field DS_ADDR
 *
 * DMA System Address:  This register contains the 32-bit system memory address for a DMA
 * transfer. Since the address must be word (4 bytes) align, the least
 * 2 bits are reserved, always 0. When the uSDHC stops a DMA transfer,
 * this register points to the system address of the next contiguous
 * data position. It can be accessed only when no transaction is
 * executing (i.e. after a transaction has stopped). Read operation
 * during transfers may return an invalid value. The Host Driver shall
 * initialize this register before starting a DMA transaction. After
 * DMA has stopped, the system address of the next contiguous data
 * position can be read from this register.  This register is protected during a data transfer. When
 * data lines                                 are active, write to this register is ignored. The
 * Host driver shall                                 wait, until the DLA bit in the Present State
 * register is cleared,                                 before writing to this register.  The uSDHC
 * internal DMA does not support a virtual memory system. It                                 only
 * supports continuous physical memory access. And due to AHB                                 burst
 * limitations, if the burst must cross the 1 KB boundary, uSDHC
 * will automatically change SEQ burst type to NSEQ.  Since this register supports dynamic address
 * reflecting, when TC bit                                 is set, it automatically alters the value
 * of internal address                                 counter, so SW cannot change this register
 * when TC bit is set. Such                                 restriction is also listed in .
 */

#define BP_USDHC_DS_ADDR_DS_ADDR      2
#define BM_USDHC_DS_ADDR_DS_ADDR      0xfffffffc

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DS_ADDR_DS_ADDR(v)   ((((reg32_t) v) << 2) & BM_USDHC_DS_ADDR_DS_ADDR)
#else
#define BF_USDHC_DS_ADDR_DS_ADDR(v)   (((v) << 2) & BM_USDHC_DS_ADDR_DS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DS_ADDR_DS_ADDR(v)   BF_CS1(USDHC_DS_ADDR, DS_ADDR, v)
#endif

/*!
 * @brief HW_USDHC_BLK_ATT - Block Attributes
 *
 * This register is used to configure the number of data blocks and the
 * number of bytes in each block.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BLKSIZE : 13; //!< Transfer Block Size:  This register specifies the block size for block data transfers. Values ranging from 1 byte up to the maximum buffer size can be set. It can be accessed only when no transaction is executing (i.e. after a transaction has stopped). Read operations during transfers may return an invalid value, and write operations will be ignored.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned BLKCNT : 16; //!< Blocks Count For Current Transfer:  This register is enabled when the Block Count Enable bit in the Transfer Mode register is set to 1 and is valid only for multiple block transfers. For single block transfer, this register will always read as 1. The Host Driver shall set this register to a value between 1 and the maximum block count. The uSDHC decrements the block count after each block transfer and stops when the count reaches zero. Setting the block count to 0 results in no data blocks being transferred.  This register should be accessed only when no transaction is executing (i.e. after transactions are stopped). During data transfer, read operations on this register may return an invalid value and write operations are ignored.  When saving transfer content as a result of a Suspend command, the number of blocks yet to be transferred can be determined by reading this register. The reading of this register should be applied after transfer is paused by stop at block gap operation and before sending the command marked as suspend. This is because when Suspend command is sent out, uSDHC will regard the current transfer is aborted and change BLKCNT register back to its original value instead of keeping the dynamical indicator of remained block count.  When restoring transfer content prior to issuing a Resume command, the Host Driver shall restore the previously saved block count.  Although the BLKCNT field is 0 after reset, the read of reset value is 0x1. This is because when MSBSEL bit is 鈥?鈥? indicating a single block transfer, the read value of BLKCNT is always 1.
    } B;
} hw_usdhc_blk_att_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_BLK_ATT register
 */
#define HW_USDHC_BLK_ATT_ADDR(x)      (REGS_USDHC_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_BLK_ATT(x)           (*(volatile hw_usdhc_blk_att_t *) HW_USDHC_BLK_ATT_ADDR(x))
#define HW_USDHC_BLK_ATT_RD(x)        (HW_USDHC_BLK_ATT(x).U)
#define HW_USDHC_BLK_ATT_WR(x, v)     (HW_USDHC_BLK_ATT(x).U = (v))
#define HW_USDHC_BLK_ATT_SET(x, v)    (HW_USDHC_BLK_ATT_WR(x, HW_USDHC_BLK_ATT_RD(x) |  (v)))
#define HW_USDHC_BLK_ATT_CLR(x, v)    (HW_USDHC_BLK_ATT_WR(x, HW_USDHC_BLK_ATT_RD(x) & ~(v)))
#define HW_USDHC_BLK_ATT_TOG(x, v)    (HW_USDHC_BLK_ATT_WR(x, HW_USDHC_BLK_ATT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_BLK_ATT bitfields
 */

/* --- Register HW_USDHC_BLK_ATT, field BLKSIZE
 *
 * Transfer Block Size:  This register specifies the block size for block data transfers.
 * Values ranging from 1 byte up to the maximum buffer size can be set.
 * It can be accessed only when no transaction is executing (i.e. after
 * a transaction has stopped). Read operations during transfers may
 * return an invalid value, and write operations will be ignored.
 */

#define BP_USDHC_BLK_ATT_BLKSIZE      0
#define BM_USDHC_BLK_ATT_BLKSIZE      0x00001fff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_BLK_ATT_BLKSIZE(v)   ((((reg32_t) v) << 0) & BM_USDHC_BLK_ATT_BLKSIZE)
#else
#define BF_USDHC_BLK_ATT_BLKSIZE(v)   (((v) << 0) & BM_USDHC_BLK_ATT_BLKSIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_BLK_ATT_BLKSIZE(v)   BF_CS1(USDHC_BLK_ATT, BLKSIZE, v)
#endif

/* --- Register HW_USDHC_BLK_ATT, field BLKCNT
 *
 * Blocks Count For Current Transfer:  This register is enabled when the Block Count Enable bit in
 * the                                 Transfer Mode register is set to 1 and is valid only for
 * multiple                                 block transfers. For single block transfer, this
 * register will                                 always read as 1. The Host Driver shall set this
 * register to a value                                 between 1 and the maximum block count. The
 * uSDHC decrements the                                 block count after each block transfer and
 * stops when the count                                 reaches zero. Setting the block count to 0
 * results in no data blocks                                 being transferred.  This register
 * should be accessed only when no transaction is                                 executing (i.e.
 * after transactions are stopped). During data                                 transfer, read
 * operations on this register may return an invalid                                 value and write
 * operations are ignored.  When saving transfer content as a result of a Suspend command, the
 * number of blocks yet to be transferred can be determined by reading
 * this register. The reading of this register should be applied after
 * transfer is paused by stop at block gap operation and before sending
 * the command marked as suspend. This is because when Suspend command
 * is sent out, uSDHC will regard the current transfer is aborted and
 * change BLKCNT register back to its original value instead of keeping
 * the dynamical indicator of remained block count.  When restoring transfer content prior to
 * issuing a Resume command,                             the Host Driver shall restore the
 * previously saved block count.  Although the BLKCNT field is 0 after reset, the read of reset
 * value is 0x1. This is because when MSBSEL bit is 鈥?鈥? indicating a single block transfer, the
 * read value of BLKCNT is always 1.
 */

#define BP_USDHC_BLK_ATT_BLKCNT      16
#define BM_USDHC_BLK_ATT_BLKCNT      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_BLK_ATT_BLKCNT(v)   ((((reg32_t) v) << 16) & BM_USDHC_BLK_ATT_BLKCNT)
#else
#define BF_USDHC_BLK_ATT_BLKCNT(v)   (((v) << 16) & BM_USDHC_BLK_ATT_BLKCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_BLK_ATT_BLKCNT(v)   BF_CS1(USDHC_BLK_ATT, BLKCNT, v)
#endif

/*!
 * @brief HW_USDHC_CMD_ARG - Command Argument
 *
 * This register contains the SD/MMC Command Argument.  .
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDARG : 32; //!< Command Argument:  The SD/MMC Command Argument is specified as bits 39-8 of the Command Format in the SD or MMC Specification.This register is write protected when the Command Inhibit (CMD) bit in the Present State register is set.
    } B;
} hw_usdhc_cmd_arg_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_ARG register
 */
#define HW_USDHC_CMD_ARG_ADDR(x)      (REGS_USDHC_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_ARG(x)           (*(volatile hw_usdhc_cmd_arg_t *) HW_USDHC_CMD_ARG_ADDR(x))
#define HW_USDHC_CMD_ARG_RD(x)        (HW_USDHC_CMD_ARG(x).U)
#define HW_USDHC_CMD_ARG_WR(x, v)     (HW_USDHC_CMD_ARG(x).U = (v))
#define HW_USDHC_CMD_ARG_SET(x, v)    (HW_USDHC_CMD_ARG_WR(x, HW_USDHC_CMD_ARG_RD(x) |  (v)))
#define HW_USDHC_CMD_ARG_CLR(x, v)    (HW_USDHC_CMD_ARG_WR(x, HW_USDHC_CMD_ARG_RD(x) & ~(v)))
#define HW_USDHC_CMD_ARG_TOG(x, v)    (HW_USDHC_CMD_ARG_WR(x, HW_USDHC_CMD_ARG_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_ARG bitfields
 */

/* --- Register HW_USDHC_CMD_ARG, field CMDARG
 *
 * Command Argument:  The SD/MMC Command Argument is specified as bits 39-8 of the Command
 * Format in the SD or MMC Specification.This register is write
 * protected when the Command Inhibit (CMD) bit in the Present State
 * register is set.
 */

#define BP_USDHC_CMD_ARG_CMDARG      0
#define BM_USDHC_CMD_ARG_CMDARG      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_ARG_CMDARG(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_ARG_CMDARG)
#else
#define BF_USDHC_CMD_ARG_CMDARG(v)   (((v) << 0) & BM_USDHC_CMD_ARG_CMDARG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_ARG_CMDARG(v)   BF_CS1(USDHC_CMD_ARG, CMDARG, v)
#endif

/*!
 * @brief HW_USDHC_CMD_XFR_TYP - Command Transfer Type
 *
 * This register is used to control the operation of data transfers. The
 * Host Driver shall set this register before issuing a command followed by
 * a data transfer, or before issuing a Resume command. To prevent data
 * loss, the uSDHC prevents writing to the bits, that are involved in the
 * data transfer of this register, when data transfer is active. These bits
 * are DPSEL, MBSEL, DTDSEL, AC12EN, BCEN and DMAEN.  The Host Driver shall check the Command
 * Inhibit DAT bit (CDIHB) and the                             Command Inhibit CMD bit (CIHB) in the
 * Present State register before                             writing to this register. When the
 * CDIHB bit in the Present State                             register is set, any attempt to send a
 * command with data by writing to                             this register is ignored; when the
 * CIHB bit is set, any write to this                             register is ignored.  On sending
 * commands with data transfer invovled, it is mandatory that the                             block
 * size is non-zero. Besides, block count must also be non-zero, or
 * indicated as single block transfer (bit 5 of this register is '0' when
 * written), or block count is disabled (bit 1 of this register is '0' when
 * written), otherwise uSDHC will ignore the sending of this command and do
 * nothing. For write command, with all above restrictions, it is also
 * mandatory that the write protect switch is not active (WPSPL bit of
 * Present State Register is '1), otherwise uSDHC will also ignore the
 * command.  If the commands with data transfer does not receive the response in 64
 * clock cycles, i.e., response time-out, uSDHC will regard the external
 * device does not accept the command and abort the data transfer. In this
 * scenario, the driver should issue the command again to re-try the
 * transfer. It is also possible that for some reason the card responds the
 * command but uSDHC does not receive the response, and if it is internal
 * DMA (either simple DMA or ADMA) read operation, the external system
 * memory is over-written by the internal DMA with data sent back from the
 * card.  The table below shows the summary of how register settings determine the
 * type of data transfer.   Transfer Type Register Setting for Various Transfer
 * Types          Multi/Single Block                                             Select    Block
 * Count Enable    Block Count    Function        0    Don't Care    Don't Care    Single Transfer
 * 1    0    Don't Care    Infinite Transfer      1    1    Positive Number    Multiple Transfer
 * 1    1    Zero    No Data Transfer       The table belowshows the relationship between the
 * Command Index Check                             Enable and the Command CRC Check Enable, in
 * regards to the Response Type                             bits as well as the name of the response
 * type.   Relationship Between Parameters and the Name of the Response
 * Type          Response Type    Index Check Enable    CRC Check Enable    Name of Response Type
 * 00    0    0    No Response      01    0    1    R2      10    0    0    R3,R4      10    1    1
 * R1,R5,R6      11    1    1    R1b,R5b        In the SDIO specification, response type notation
 * for R5b is not                                 defined. R5 includes R5b in the SDIO
 * specification. But R5b is                                 defined in this specification to
 * specify that the uSDHC will check                                 the busy status after receiving
 * a response. For example, usually                                 CMD52 is used with R5, but the
 * I/O abort command shall be used with                                 R5b.  The CRC field for R3
 * and R4 is expected to be all 1 bits. The CRC                                 check shall be
 * disabled for these response types.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned RSPTYP : 2; //!< Response Type Select:
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned CCCEN : 1; //!< Command CRC Check Enable:  If this bit is set to 1, the uSDHC shall check the CRC field in the response. If an error is detected, it is reported as a Command CRC Error. If this bit is set to 0, the CRC field is not checked. The number of bits checked by the CRC field value changes according to the length of the response. (Refer to RSPTYP[1:0] and .)
        unsigned CICEN : 1; //!< Command Index Check Enable:  If this bit is set to 1, the uSDHC will check the Index field in the response to see if it has the same value as the command index. If it is not, it is reported as a Command Index Error. If this bit is set to 0, the Index field is not checked.
        unsigned DPSEL : 1; //!< Data Present Select:  This bit is set to 1 to indicate that data is present and shall be transferred using the DAT line. It is set to 0 for the following:   Commands using only the CMD line (e.g. CMD52).  Commands with no data transfer, but using the busy signal on DAT[0] line (R1b or R5b e.g. CMD38)   Note: In resume command, this bit shall be set, and other bits in this register shall be set the same as when the transfer was initially launched. When the Write Protect switch is on, (i.e. the WPSPL bit is active as '0'), any command with a write operation will be ignored. That is to say, when this bit is set, while the DTDSEL bit is 0, writes to the register Transfer Type are ignored.
        unsigned CMDTYP : 2; //!< Command Type:  There are three types of special commands: Suspend, Resume and Abort. These bits shall be set to 00b for all other commands.   Suspend Command: If the Suspend command succeeds, the uSDHC shall assume that the card bus has been released and that it is possible to issue the next command which uses the DAT line. Since the uSDHC does not monitor the content of command response, it does not know if the Suspend command succeeded or not. It is the Host Driver's responsibility to check the status of the Suspend command and send another command marked as Suspend to inform the uSDHC that a Suspend command was successfully issued. Refer to for more details. After the end bit of command is sent, the uSDHC de-asserts Read Wait for read transactions and stops checking busy for write transactions. In 4-bit mode, the interrupt cycle starts. If the Suspend command fails, the uSDHC will maintain its current state, and the Host Driver shall restart the transfer by setting the Continue Request bit in the Protocol Control register.  Resume Command: The Host Driver re-starts the data transfer by restoring the registers saved before sending the Suspend Command and then sends the Resume Command. The uSDHC will check for a pending busy state before starting write transfers.  Abort Command: If this command is set when executing a read transfer, the uSDHC will stop reads to the buffer. If this command is set when executing a write transfer, the uSDHC will stop driving the DAT line. After issuing the Abort command, the Host Driver should issue a software reset (Abort Transaction).
        unsigned CMDINX : 6; //!< Command Index:  These bits shall be set to the command number that is specified in bits 45-40 of the Command-Format in the SD Memory Card Physical Layer Specification and SDIO Card Specification.
        unsigned RESERVED2 : 2; //!< Reserved
    } B;
} hw_usdhc_cmd_xfr_typ_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_XFR_TYP register
 */
#define HW_USDHC_CMD_XFR_TYP_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_XFR_TYP(x)           (*(volatile hw_usdhc_cmd_xfr_typ_t *) HW_USDHC_CMD_XFR_TYP_ADDR(x))
#define HW_USDHC_CMD_XFR_TYP_RD(x)        (HW_USDHC_CMD_XFR_TYP(x).U)
#define HW_USDHC_CMD_XFR_TYP_WR(x, v)     (HW_USDHC_CMD_XFR_TYP(x).U = (v))
#define HW_USDHC_CMD_XFR_TYP_SET(x, v)    (HW_USDHC_CMD_XFR_TYP_WR(x, HW_USDHC_CMD_XFR_TYP_RD(x) |  (v)))
#define HW_USDHC_CMD_XFR_TYP_CLR(x, v)    (HW_USDHC_CMD_XFR_TYP_WR(x, HW_USDHC_CMD_XFR_TYP_RD(x) & ~(v)))
#define HW_USDHC_CMD_XFR_TYP_TOG(x, v)    (HW_USDHC_CMD_XFR_TYP_WR(x, HW_USDHC_CMD_XFR_TYP_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_XFR_TYP bitfields
 */

/* --- Register HW_USDHC_CMD_XFR_TYP, field RSPTYP
 *
 * Response Type Select:
 */

#define BP_USDHC_CMD_XFR_TYP_RSPTYP      16
#define BM_USDHC_CMD_XFR_TYP_RSPTYP      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_RSPTYP(v)   ((((reg32_t) v) << 16) & BM_USDHC_CMD_XFR_TYP_RSPTYP)
#else
#define BF_USDHC_CMD_XFR_TYP_RSPTYP(v)   (((v) << 16) & BM_USDHC_CMD_XFR_TYP_RSPTYP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_RSPTYP(v)   BF_CS1(USDHC_CMD_XFR_TYP, RSPTYP, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CCCEN
 *
 * Command CRC Check Enable:  If this bit is set to 1, the uSDHC shall check the CRC field in the
 * response. If an error is detected, it is reported as a Command CRC
 * Error. If this bit is set to 0, the CRC field is not checked. The
 * number of bits checked by the CRC field value changes according to
 * the length of the response. (Refer to RSPTYP[1:0] and .)
 */

#define BP_USDHC_CMD_XFR_TYP_CCCEN      19
#define BM_USDHC_CMD_XFR_TYP_CCCEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CCCEN(v)   ((((reg32_t) v) << 19) & BM_USDHC_CMD_XFR_TYP_CCCEN)
#else
#define BF_USDHC_CMD_XFR_TYP_CCCEN(v)   (((v) << 19) & BM_USDHC_CMD_XFR_TYP_CCCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CCCEN(v)   BF_CS1(USDHC_CMD_XFR_TYP, CCCEN, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CICEN
 *
 * Command Index Check Enable:  If this bit is set to 1, the uSDHC will check the Index field in the
 * response to see if it has the same value as the command index. If it
 * is not, it is reported as a Command Index Error. If this bit is set
 * to 0, the Index field is not checked.
 */

#define BP_USDHC_CMD_XFR_TYP_CICEN      20
#define BM_USDHC_CMD_XFR_TYP_CICEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CICEN(v)   ((((reg32_t) v) << 20) & BM_USDHC_CMD_XFR_TYP_CICEN)
#else
#define BF_USDHC_CMD_XFR_TYP_CICEN(v)   (((v) << 20) & BM_USDHC_CMD_XFR_TYP_CICEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CICEN(v)   BF_CS1(USDHC_CMD_XFR_TYP, CICEN, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field DPSEL
 *
 * Data Present Select:  This bit is set to 1 to indicate that data is present and shall be
 * transferred using the DAT line. It is set to 0 for the                                 following:
 * Commands using only the CMD line (e.g. CMD52).  Commands with no data transfer, but using the
 * busy signal on                                     DAT[0] line (R1b or R5b e.g. CMD38)   Note: In
 * resume command, this bit shall be set, and other bits in                                 this
 * register shall be set the same as when the transfer was                                 initially
 * launched. When the Write Protect switch is on, (i.e. the                                 WPSPL
 * bit is active as '0'), any command with a write operation will                                 be
 * ignored. That is to say, when this bit is set, while the DTDSEL
 * bit is 0, writes to the register Transfer Type are ignored.
 */

#define BP_USDHC_CMD_XFR_TYP_DPSEL      21
#define BM_USDHC_CMD_XFR_TYP_DPSEL      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_DPSEL(v)   ((((reg32_t) v) << 21) & BM_USDHC_CMD_XFR_TYP_DPSEL)
#else
#define BF_USDHC_CMD_XFR_TYP_DPSEL(v)   (((v) << 21) & BM_USDHC_CMD_XFR_TYP_DPSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_DPSEL(v)   BF_CS1(USDHC_CMD_XFR_TYP, DPSEL, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CMDTYP
 *
 * Command Type:  There are three types of special commands: Suspend, Resume and Abort.
 * These bits shall be set to 00b for all other commands.   Suspend Command: If the Suspend command
 * succeeds, the uSDHC                                     shall assume that the card bus has been
 * released and that it is                                     possible to issue the next command
 * which uses the DAT line.                                     Since the uSDHC does not monitor the
 * content of command                                     response, it does not know if the Suspend
 * command succeeded or                                     not. It is the Host Driver's
 * responsibility to check the status                                     of the Suspend command and
 * send another command marked as                                     Suspend to inform the uSDHC
 * that a Suspend command was                                     successfully issued. Refer to for
 * more details. After the end bit of                                     command is sent, the uSDHC
 * de-asserts Read Wait for read                                     transactions and stops checking
 * busy for write transactions. In                                     4-bit mode, the interrupt
 * cycle starts. If the Suspend command                                     fails, the uSDHC will
 * maintain its current state, and the Host                                     Driver shall restart
 * the transfer by setting the Continue                                     Request bit in the
 * Protocol Control register.  Resume Command: The Host Driver re-starts the data transfer by
 * restoring the registers saved before sending the Suspend Command
 * and then sends the Resume Command. The uSDHC will check for a
 * pending busy state before starting write transfers.  Abort Command: If this command is set when
 * executing a read                                     transfer, the uSDHC will stop reads to the
 * buffer. If this                                     command is set when executing a write
 * transfer, the uSDHC will                                     stop driving the DAT line. After
 * issuing the Abort command, the                                     Host Driver should issue a
 * software reset (Abort Transaction).
 */

#define BP_USDHC_CMD_XFR_TYP_CMDTYP      22
#define BM_USDHC_CMD_XFR_TYP_CMDTYP      0x00c00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CMDTYP(v)   ((((reg32_t) v) << 22) & BM_USDHC_CMD_XFR_TYP_CMDTYP)
#else
#define BF_USDHC_CMD_XFR_TYP_CMDTYP(v)   (((v) << 22) & BM_USDHC_CMD_XFR_TYP_CMDTYP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CMDTYP(v)   BF_CS1(USDHC_CMD_XFR_TYP, CMDTYP, v)
#endif

/* --- Register HW_USDHC_CMD_XFR_TYP, field CMDINX
 *
 * Command Index:  These bits shall be set to the command number that is specified in
 * bits 45-40 of the Command-Format in the SD Memory Card Physical
 * Layer Specification and SDIO Card Specification.
 */

#define BP_USDHC_CMD_XFR_TYP_CMDINX      24
#define BM_USDHC_CMD_XFR_TYP_CMDINX      0x3f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_XFR_TYP_CMDINX(v)   ((((reg32_t) v) << 24) & BM_USDHC_CMD_XFR_TYP_CMDINX)
#else
#define BF_USDHC_CMD_XFR_TYP_CMDINX(v)   (((v) << 24) & BM_USDHC_CMD_XFR_TYP_CMDINX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_XFR_TYP_CMDINX(v)   BF_CS1(USDHC_CMD_XFR_TYP, CMDINX, v)
#endif

/*!
 * @brief HW_USDHC_CMD_RSP0 - Command Response0
 *
 * This register is used to store part 0 of the response bits from the
 * card.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP0 : 32; //!< Command Response 0:  Refer to for the mapping of command responses from the SD Bus to this register for each response type.
    } B;
} hw_usdhc_cmd_rsp0_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP0 register
 */
#define HW_USDHC_CMD_RSP0_ADDR(x)      (REGS_USDHC_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP0(x)           (*(volatile hw_usdhc_cmd_rsp0_t *) HW_USDHC_CMD_RSP0_ADDR(x))
#define HW_USDHC_CMD_RSP0_RD(x)        (HW_USDHC_CMD_RSP0(x).U)
#define HW_USDHC_CMD_RSP0_WR(x, v)     (HW_USDHC_CMD_RSP0(x).U = (v))
#define HW_USDHC_CMD_RSP0_SET(x, v)    (HW_USDHC_CMD_RSP0_WR(x, HW_USDHC_CMD_RSP0_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP0_CLR(x, v)    (HW_USDHC_CMD_RSP0_WR(x, HW_USDHC_CMD_RSP0_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP0_TOG(x, v)    (HW_USDHC_CMD_RSP0_WR(x, HW_USDHC_CMD_RSP0_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP0 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP0, field CMDRSP0
 *
 * Command Response 0:  Refer to for the                                 mapping of command
 * responses from the SD Bus to this register for                                 each response
 * type.
 */

#define BP_USDHC_CMD_RSP0_CMDRSP0      0
#define BM_USDHC_CMD_RSP0_CMDRSP0      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP0_CMDRSP0(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP0_CMDRSP0)
#else
#define BF_USDHC_CMD_RSP0_CMDRSP0(v)   (((v) << 0) & BM_USDHC_CMD_RSP0_CMDRSP0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP0_CMDRSP0(v)   BF_CS1(USDHC_CMD_RSP0, CMDRSP0, v)
#endif

/*!
 * @brief HW_USDHC_CMD_RSP1 - Command Response1
 *
 * This register is used to store part 1 of the response bits from the
 * card.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP1 : 32; //!< Command Response 1:  Refer to for the mapping of command responses from the SD Bus to this register for each response type.
    } B;
} hw_usdhc_cmd_rsp1_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP1 register
 */
#define HW_USDHC_CMD_RSP1_ADDR(x)      (REGS_USDHC_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP1(x)           (*(volatile hw_usdhc_cmd_rsp1_t *) HW_USDHC_CMD_RSP1_ADDR(x))
#define HW_USDHC_CMD_RSP1_RD(x)        (HW_USDHC_CMD_RSP1(x).U)
#define HW_USDHC_CMD_RSP1_WR(x, v)     (HW_USDHC_CMD_RSP1(x).U = (v))
#define HW_USDHC_CMD_RSP1_SET(x, v)    (HW_USDHC_CMD_RSP1_WR(x, HW_USDHC_CMD_RSP1_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP1_CLR(x, v)    (HW_USDHC_CMD_RSP1_WR(x, HW_USDHC_CMD_RSP1_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP1_TOG(x, v)    (HW_USDHC_CMD_RSP1_WR(x, HW_USDHC_CMD_RSP1_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP1 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP1, field CMDRSP1
 *
 * Command Response 1:  Refer to for the                                 mapping of command
 * responses from the SD Bus to this register for                                 each response
 * type.
 */

#define BP_USDHC_CMD_RSP1_CMDRSP1      0
#define BM_USDHC_CMD_RSP1_CMDRSP1      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP1_CMDRSP1(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP1_CMDRSP1)
#else
#define BF_USDHC_CMD_RSP1_CMDRSP1(v)   (((v) << 0) & BM_USDHC_CMD_RSP1_CMDRSP1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP1_CMDRSP1(v)   BF_CS1(USDHC_CMD_RSP1, CMDRSP1, v)
#endif

/*!
 * @brief HW_USDHC_CMD_RSP2 - Command Response2
 *
 * This register is used to store part 2 of the response bits from the
 * card.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP2 : 32; //!< Command Response 2:  Refer to for the mapping of command responses from the SD Bus to this register for each response type.
    } B;
} hw_usdhc_cmd_rsp2_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP2 register
 */
#define HW_USDHC_CMD_RSP2_ADDR(x)      (REGS_USDHC_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP2(x)           (*(volatile hw_usdhc_cmd_rsp2_t *) HW_USDHC_CMD_RSP2_ADDR(x))
#define HW_USDHC_CMD_RSP2_RD(x)        (HW_USDHC_CMD_RSP2(x).U)
#define HW_USDHC_CMD_RSP2_WR(x, v)     (HW_USDHC_CMD_RSP2(x).U = (v))
#define HW_USDHC_CMD_RSP2_SET(x, v)    (HW_USDHC_CMD_RSP2_WR(x, HW_USDHC_CMD_RSP2_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP2_CLR(x, v)    (HW_USDHC_CMD_RSP2_WR(x, HW_USDHC_CMD_RSP2_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP2_TOG(x, v)    (HW_USDHC_CMD_RSP2_WR(x, HW_USDHC_CMD_RSP2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP2 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP2, field CMDRSP2
 *
 * Command Response 2:  Refer to for the                                 mapping of command
 * responses from the SD Bus to this register for                                 each response
 * type.
 */

#define BP_USDHC_CMD_RSP2_CMDRSP2      0
#define BM_USDHC_CMD_RSP2_CMDRSP2      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP2_CMDRSP2(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP2_CMDRSP2)
#else
#define BF_USDHC_CMD_RSP2_CMDRSP2(v)   (((v) << 0) & BM_USDHC_CMD_RSP2_CMDRSP2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP2_CMDRSP2(v)   BF_CS1(USDHC_CMD_RSP2, CMDRSP2, v)
#endif

/*!
 * @brief HW_USDHC_CMD_RSP3 - Command Response3
 *
 * This register is used to store part 3 of the response bits from the
 * card.  The table below describes the mapping of command responses from the SD
 * Bus to Command Response registers for each response type. In the table,
 * R[ ] refers to a bit range within the response data as transmitted on
 * the SD Bus.   Response Bit Definition for Each Response Type          Response Type    Meaning of
 * Response    Response Field    Response Register        R1,R1b (normal
 * response)    Card Status    R[39:8]    CMDRSP0      R1b (Auto CMD12
 * response)    Card Status for Auto                                             CMD12    R[39:8]
 * CMDRSP3      R2 (CID, CSD register)    CID/CSD register
 * [127:8]    R[127:8]    {CMDRSP3[23:0],  CMDRSP2,  CMDRSP1,  CMDRSP0}      R3 (OCR register)
 * OCR register for memory    R[39:8]    CMDRSP0      R4 (OCR register)    OCR register for I/O
 * etc.    R[39:8]    CMDRSP0      R5, R5b    SDIO response    R[39:8]    CMDRSP0      R6 (Publish
 * RCA)    New Published RCA[31:16] and card
 * status[15:0]    R[39:9]    CMDRSP0       This table shows that most responses with a length of 48
 * (R[47:0]) have                             32-bits of the response data (R[39:8]) stored in the
 * CMDRSP0 register.                             Responses of type R1b (Auto CMD12 responses) have
 * response data bits                             (R[39:8]) stored in the CMDRSP3 register.
 * Responses with length 136                             (R[135:0]) have 120-bits of the response
 * data (R[127:8]) stored in the                             CMDRSP0, 1, 2, and 3 registers.  To be
 * able to read the response status efficiently, the uSDHC only stores
 * part of the response data in the Command Response registers. This
 * enables the Host Driver to efficiently read 32-bits of response data in
 * one read cycle on a 32-bit bus system. Parts of the response, the Index
 * field and the CRC, are checked by the uSDHC (as specified by the Command
 * Index Check Enable and the Command CRC Check Enable bits in the Transfer
 * Type register) and generate an error interrupt if any error is detected.
 * The bit range for the CRC check depends on the response length. If the
 * response length is 48, the uSDHC will check R[47:1], and if the response
 * length is 136 the uSDHC will check R[119:1].  Since the uSDHC may have a multiple block data
 * transfer executing                             concurrently with a CMD_wo_DAT command, the uSDHC
 * stores the Auto CMD12                             response in the CMDRSP3 register. The
 * CMD_wo_DAT response is stored in                             CMDRSP0. This allows the uSDHC to
 * avoid overwriting the Auto CMD12                             response with the CMD_wo_DAT and
 * vice versa. When the uSDHC modifies                             part of the Command Response
 * registers, as shown in the table above, it                             preserves the unmodified
 * bits.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMDRSP3 : 32; //!< Command Response 3:  Refer to for the mapping of command responses from the SD Bus to this register for each response type.
    } B;
} hw_usdhc_cmd_rsp3_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CMD_RSP3 register
 */
#define HW_USDHC_CMD_RSP3_ADDR(x)      (REGS_USDHC_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CMD_RSP3(x)           (*(volatile hw_usdhc_cmd_rsp3_t *) HW_USDHC_CMD_RSP3_ADDR(x))
#define HW_USDHC_CMD_RSP3_RD(x)        (HW_USDHC_CMD_RSP3(x).U)
#define HW_USDHC_CMD_RSP3_WR(x, v)     (HW_USDHC_CMD_RSP3(x).U = (v))
#define HW_USDHC_CMD_RSP3_SET(x, v)    (HW_USDHC_CMD_RSP3_WR(x, HW_USDHC_CMD_RSP3_RD(x) |  (v)))
#define HW_USDHC_CMD_RSP3_CLR(x, v)    (HW_USDHC_CMD_RSP3_WR(x, HW_USDHC_CMD_RSP3_RD(x) & ~(v)))
#define HW_USDHC_CMD_RSP3_TOG(x, v)    (HW_USDHC_CMD_RSP3_WR(x, HW_USDHC_CMD_RSP3_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CMD_RSP3 bitfields
 */

/* --- Register HW_USDHC_CMD_RSP3, field CMDRSP3
 *
 * Command Response 3:  Refer to for the                                 mapping of command
 * responses from the SD Bus to this register for                                 each response
 * type.
 */

#define BP_USDHC_CMD_RSP3_CMDRSP3      0
#define BM_USDHC_CMD_RSP3_CMDRSP3      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CMD_RSP3_CMDRSP3(v)   ((((reg32_t) v) << 0) & BM_USDHC_CMD_RSP3_CMDRSP3)
#else
#define BF_USDHC_CMD_RSP3_CMDRSP3(v)   (((v) << 0) & BM_USDHC_CMD_RSP3_CMDRSP3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CMD_RSP3_CMDRSP3(v)   BF_CS1(USDHC_CMD_RSP3, CMDRSP3, v)
#endif

/*!
 * @brief HW_USDHC_DATA_BUFF_ACC_PORT - Data Buffer Access Port
 *
 * This is a 32-bit data port register used to access the internal
 * buffer.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DATCONT : 32; //!< Data Content:  The Buffer Data Port register is for 32-bit data access by the ARM platform or the external DMA. When the internal DMA is enabled, any write to this register is ignored, and any read from this register will always yield 0s.
    } B;
} hw_usdhc_data_buff_acc_port_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DATA_BUFF_ACC_PORT register
 */
#define HW_USDHC_DATA_BUFF_ACC_PORT_ADDR(x)      (REGS_USDHC_BASE(x) + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DATA_BUFF_ACC_PORT(x)           (*(volatile hw_usdhc_data_buff_acc_port_t *) HW_USDHC_DATA_BUFF_ACC_PORT_ADDR(x))
#define HW_USDHC_DATA_BUFF_ACC_PORT_RD(x)        (HW_USDHC_DATA_BUFF_ACC_PORT(x).U)
#define HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, v)     (HW_USDHC_DATA_BUFF_ACC_PORT(x).U = (v))
#define HW_USDHC_DATA_BUFF_ACC_PORT_SET(x, v)    (HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, HW_USDHC_DATA_BUFF_ACC_PORT_RD(x) |  (v)))
#define HW_USDHC_DATA_BUFF_ACC_PORT_CLR(x, v)    (HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, HW_USDHC_DATA_BUFF_ACC_PORT_RD(x) & ~(v)))
#define HW_USDHC_DATA_BUFF_ACC_PORT_TOG(x, v)    (HW_USDHC_DATA_BUFF_ACC_PORT_WR(x, HW_USDHC_DATA_BUFF_ACC_PORT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DATA_BUFF_ACC_PORT bitfields
 */

/* --- Register HW_USDHC_DATA_BUFF_ACC_PORT, field DATCONT
 *
 * Data Content:  The Buffer Data Port register is for 32-bit data access by the ARM platform or
 * the external DMA. When the internal DMA is enabled, any write to
 * this register is ignored, and any read from this register will
 * always yield 0s.
 */

#define BP_USDHC_DATA_BUFF_ACC_PORT_DATCONT      0
#define BM_USDHC_DATA_BUFF_ACC_PORT_DATCONT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DATA_BUFF_ACC_PORT_DATCONT(v)   ((((reg32_t) v) << 0) & BM_USDHC_DATA_BUFF_ACC_PORT_DATCONT)
#else
#define BF_USDHC_DATA_BUFF_ACC_PORT_DATCONT(v)   (((v) << 0) & BM_USDHC_DATA_BUFF_ACC_PORT_DATCONT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DATA_BUFF_ACC_PORT_DATCONT(v)   BF_CS1(USDHC_DATA_BUFF_ACC_PORT, DATCONT, v)
#endif

/*!
 * @brief HW_USDHC_PRES_STATE - Present State
 *
 * The Host Driver can get status of the uSDHC from this 32-bit read only
 * register.   The Host Driver can issue CMD0, CMD12, CMD13 (for memory) and CMD52
 * (for SDIO) when the DAT lines are busy during a data transfer. These
 * commands can be issued when Command Inhibit (CMD) is set to zero.
 * Other commands shall be issued when Command Inhibit (DAT) is set to
 * zero. Possible changes to the SD Physical Specification may add
 * other commands to this list in the future.  Note: the reset value of Present State Register
 * depend on testbench                                 connectivity.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CIHB : 1; //!< Command Inhibit (CMD):  If this status bit is 0, it indicates that the CMD line is not in use and the uSDHC can issue a SD/MMC Command using the CMD line.  This bit is set also immediately after the Transfer Type register is written. This bit is cleared when the command response is received. Even if the Command Inhibit (DAT) is set to 1, Commands using only the CMD line can be issued if this bit is 0. Changing from 1 to 0 generates a Command Complete interrupt in the Interrupt Status register. If the uSDHC cannot issue the command because of a command conflict error (Refer to Command CRC Error) or because of a Command Not Issued By Auto CMD12 Error, this bit will remain 1 and the Command Complete is not set. The Status of issuing an Auto CMD12 does not show on this bit.
        unsigned CDIHB : 1; //!< Command Inhibit (DAT):  This status bit is generated if either the DAT Line Active or the Read Transfer Active is set to 1. If this bit is 0, it indicates that the uSDHC can issue the next SD/MMC Command. Commands with a busy signal belong to Command Inhibit (DAT) (e.g. R1b, R5b type). Except in the case when the command busy is finished, changing from 1 to 0 generates a Transfer Complete interrupt in the Interrupt Status register.  Note: The SD Host Driver can save registers for a suspend transaction after this bit has changed from 1 to 0.
        unsigned DLA : 1; //!< Data Line Active  This status bit indicates whether one of the DAT lines on the SD Bus is in use.  In the case of read transactions:  This status indicates if a read transfer is executing on the SD Bus. Changes in this value from 1 to 0, between data blocks, generates a Block Gap Event interrupt in the Interrupt Status register.  This bit will be set in either of the following cases:   After the end bit of the read command.  When writing a 1 to the Continue Request bit in the Protocol Control register to restart a read transfer.   This bit will be cleared in either of the following cases:  (1) When the end bit of the last data block is sent from the SD Bus to the uSDHC.  (2) When the Read Wait state is stopped by a Suspend command and the DAT2 line is released.  The uSDHC will wait at the next block gap by driving Read Wait at the start of the interrupt cycle. If the Read Wait signal is already driven (data buffer cannot receive data), the uSDHC can wait for a current block gap by continuing to drive the Read Wait signal. It is necessary to support Read Wait in order to use the suspend / resume function. This bit will remain 1 during Read Wait.  In the case of write transactions:  This status indicates that a write transfer is executing on the SD Bus. Changes in this value from 1 to 0 generate a Transfer Complete interrupt in the Interrupt Status register.  This bit will be set in either of the following cases:   After the end bit of the write command.  When writing to 1 to the Continue Request bit in the Protocol Control register to continue a write transfer.   This bit will be cleared in either of the following cases:   When the SD card releases Write Busy of the last data block, the uSDHC will also detect if the output is not busy. If the SD card does not drive the busy signal after the CRC status is received, the uSDHC shall assume the card drive "Not Busy".  When the SD card releases write busy, prior to waiting for write transfer, and as a result of a Stop At Block Gap Request.   In the case of command with busy pending:  This status indicates that a busy state follows the command and the data line is in use. This bit will be cleared when the DAT0 line is released.
        unsigned SDSTB : 1; //!< SD Clock Stable  This status bit indicates that the internal card clock is stable. This bit is for the Host Driver to poll clock status when changing the clock frequency. It is recommended to clear SDCLKEN bit in System Control register to remove glitch on the card clock when the frequency is changing.   Before changing clock divisor value(SDCLKFS or DVS), Host Driver should make sure the SDSTB bit is high.
        unsigned IPGOFF : 1; //!< ipg_clk Gated Off Internally:  This status bit indicates that the ipg_clk is internally gated off. This bit is for the Host Driver to debug.
        unsigned HCKOFF : 1; //!< hclk Gated Off Internally:  This status bit indicates that the hclk is internally gated off. This bit is for the Host Driver to debug during a data transfer.
        unsigned PEROFF : 1; //!< ipg_perclk Gated Off Internally:  This status bit indicates that the ipg_perclk is internally gated off. This bit is for the Host Driver to debug transaction on the SD bus. When INITA bit is set, uSDHC sending 80 clock cycles to the card, the SDCLKEN bit must be '1' to enable the output card clock, otherwise the ipg_perclk will never be gate off, so ipg_perclk and ipg_clk will be always active.
        unsigned SDOFF : 1; //!< SD Clock Gated Off Internally:  This status bit indicates that the SD Clock is internally gated off, because of buffer over/under-run or read pause without read wait assertion, or the driver has cleared SDCLKEN bit to stop the SD clock. This bit is for the Host Driver to debug data transaction on the SD bus.
        unsigned WTA : 1; //!< Write Transfer Active:  This status bit indicates a write transfer is active. If this bit is 0, it means no valid write data exists in the uSDHC.  This bit is set in either of the following cases:   After the end bit of the write command.  When writing 1 to the Continue Request bit in the Protocol Control register to restart a write transfer.   This bit is cleared in either of the following cases:   After getting the CRC status of the last data block as specified by the transfer count (Single and Multiple).  After getting the CRC status of any block where data transmission is about to be stopped by a Stop At Block Gap Request.   During a write transaction, a Block Gap Event interrupt is generated when this bit is changed to 0, as result of the Stop At Block Gap Request being set. This status is useful for the Host Driver in determining when to issue commands during Write Busy state.
        unsigned RTA : 1; //!< Read Transfer Active:  This status bit is used for detecting completion of a read transfer.  This bit is set for either of the following conditions:   After the end bit of the read command.  When writing a 1 to the Continue Request bit in the Protocol Control register to restart a read transfer.   A Transfer Complete interrupt is generated when this bit changes to 0. This bit is cleared for either of the following conditions:   When the last data block as specified by block length is transferred to the System, i.e. all data are read away from uSDHC internal buffer.  When all valid data blocks have been transferred from uSDHC internal buffer to the System and no current block transfers are being sent as a result of the Stop At Block Gap Request being set to 1.
        unsigned BWEN : 1; //!< Buffer Write Enable:  This status bit is used for non-DMA write transfers. The uSDHC implements an internal buffer to transfer data efficiently. This read only flag indicates if space is available for write data. If this bit is 1, valid data greater than the watermark level can be written to the buffer. A change of this bit from 1 to 0 occurs when some writes to the buffer(write DATPORT(Base + 0x20)) are made and the buffer hasn't valid space greater than the watermake level. . A change of this bit from 0 to 1 occurs when the buffer can hold valid data greater than the write watermark level and the Buffer Write Ready interrupt is generated and enabled.
        unsigned BREN : 1; //!< Buffer Read Enable:  This status bit is used for non-DMA read transfers. The uSDHC implements an internal buffer to transfer data efficiently. This read only flag indicates that valid data exists in the host side buffer. If this bit is high, valid data greater than the watermark level exist in the buffer. A change of this bit from 1 to 0 occurs when some reads from the buffer(read DATPORT(Base + 0x20)) are made and the buffer hasn't valid data greater than the watermake level. A change of this bit from 0 to1 occurs when there is enough valid data ready in the buffer and the Buffer Read Ready interrupt has been generated and enabled.
        unsigned RTR : 1; //!< Re-Tuning Request: (only for SD3.0 SDR104 mode)  Host Controller may request Host Driver to execute re-tuning sequence by setting this bit when the data window is shifted by temperature drift and a tuned sampling point does not have a good margin to receive correct data.  This bit is cleared when a command is issued with setting Execute Tuning bit in MIXER_CTRL register.  Changing of this bit from 0 to 1 generates Re-Tuning Event. Refer to Interrupt status registers for more delail.  This bit isn't set to 1 if Sampling Clock Select in the MIXER_CTRL register is set to 0 (using fixed sampling clock).
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned CINST : 1; //!< Card Inserted:  This bit indicates whether a card has been inserted. The uSDHC debounces this signal so that the Host Driver will not need to wait for it to stabilize. Changing from a 0 to 1 generates a Card Insertion interrupt in the Interrupt Status register. Changing from a 1 to 0 generates a Card Removal interrupt in the Interrupt Status register. A write to the Force Event Register does not effect this bit.  The Software Reset For All in the System Control register does not effect this bit.A software reset does not effect this bit.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned CDPL : 1; //!< Card Detect Pin Level:  This bit reflects the inverse value of the SD_CD# pin for the card socket. Debouncing is not performed on this bit. This bit may be valid, but is not guaranteed, because of propagation delay. Use of this bit is limited to testing since it must be debounced by software. A software reset does not effect this bit. A write to the Force Event Register does not effect this bit. The reset value is effected by the external card detection pin. This bit shows the value on the SD_CD# pin (i.e. when a card is inserted in the socket, it is 0 on the SD_CD# input, and consequently the CDPL reads 1.)
        unsigned WPSPL : 1; //!< Write Protect Switch Pin Level:  The Write Protect Switch is supported for memory and combo cards.This bit reflects the inverted value of the SD_WP pin of the card socket. A software reset does not affect this bit. The reset value is effected by the external write protect switch. If the SD_WP pin is not used, it should be tied low, so that the reset value of this bit is high and write is enabled.
        unsigned RESERVED2 : 3; //!< Reserved
        unsigned CLSL : 1; //!< CMD Line Signal Level:  This status is used to check the CMD line level to recover from errors, and for debugging. The reset value is effected by the external pull-up/pull-down resistor, by default, the read value of this bit after reset is 1'b1, when the command line is pulled up.
        unsigned DLSL : 8; //!< DAT[7:0] Line Signal Level:  This status is used to check the DAT line level to recover from errors, and for debugging.This is especially useful in detecting the busy signal level from DAT[0]. The reset value is effected by the external pull-up/pull-down resistors. By default, the read value of this bit field after reset is 8'b11110111, when DAT[3] is pulled down and the other lines are pulled up.  DAT[7]: Data 7 line signal level  DAT[6]: Data 6 line signal level  DAT[5]: Data 5 line signal level  DAT[4]: Data 4 line signal level  DAT[3]: Data 3 line signal level  DAT[2]: Data 2 line signal level  DAT[1]: Data 1 line signal level  DAT[0]: Data 0 line signal level
    } B;
} hw_usdhc_pres_state_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_PRES_STATE register
 */
#define HW_USDHC_PRES_STATE_ADDR(x)      (REGS_USDHC_BASE(x) + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_PRES_STATE(x)           (*(volatile hw_usdhc_pres_state_t *) HW_USDHC_PRES_STATE_ADDR(x))
#define HW_USDHC_PRES_STATE_RD(x)        (HW_USDHC_PRES_STATE(x).U)
#define HW_USDHC_PRES_STATE_WR(x, v)     (HW_USDHC_PRES_STATE(x).U = (v))
#define HW_USDHC_PRES_STATE_SET(x, v)    (HW_USDHC_PRES_STATE_WR(x, HW_USDHC_PRES_STATE_RD(x) |  (v)))
#define HW_USDHC_PRES_STATE_CLR(x, v)    (HW_USDHC_PRES_STATE_WR(x, HW_USDHC_PRES_STATE_RD(x) & ~(v)))
#define HW_USDHC_PRES_STATE_TOG(x, v)    (HW_USDHC_PRES_STATE_WR(x, HW_USDHC_PRES_STATE_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_PRES_STATE bitfields
 */

/* --- Register HW_USDHC_PRES_STATE, field CIHB
 *
 * Command Inhibit (CMD):  If this status bit is 0, it indicates that the CMD line is not in use
 * and the uSDHC can issue a SD/MMC Command using the CMD line.  This bit is set also immediately
 * after the Transfer Type register is                                 written. This bit is cleared
 * when the command response is received.                                 Even if the Command
 * Inhibit (DAT) is set to 1, Commands using only                                 the CMD line can
 * be issued if this bit is 0. Changing from 1 to 0                                 generates a
 * Command Complete interrupt in the Interrupt Status                                 register. If
 * the uSDHC cannot issue the command because of a command                                 conflict
 * error (Refer to Command CRC Error) or because of a Command                                 Not
 * Issued By Auto CMD12 Error, this bit will remain 1 and the
 * Command Complete is not set. The Status of issuing an Auto CMD12
 * does not show on this bit.
 */

#define BP_USDHC_PRES_STATE_CIHB      0
#define BM_USDHC_PRES_STATE_CIHB      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CIHB(v)   ((((reg32_t) v) << 0) & BM_USDHC_PRES_STATE_CIHB)
#else
#define BF_USDHC_PRES_STATE_CIHB(v)   (((v) << 0) & BM_USDHC_PRES_STATE_CIHB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CIHB(v)   BF_CS1(USDHC_PRES_STATE, CIHB, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CDIHB
 *
 * Command Inhibit (DAT):  This status bit is generated if either the DAT Line Active or the
 * Read Transfer Active is set to 1. If this bit is 0, it indicates
 * that the uSDHC can issue the next SD/MMC Command. Commands with a
 * busy signal belong to Command Inhibit (DAT) (e.g. R1b, R5b type).
 * Except in the case when the command busy is finished, changing from
 * 1 to 0 generates a Transfer Complete interrupt in the Interrupt
 * Status register.  Note: The SD Host Driver can save registers for a suspend transaction
 * after this bit has changed from 1 to 0.
 */

#define BP_USDHC_PRES_STATE_CDIHB      1
#define BM_USDHC_PRES_STATE_CDIHB      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CDIHB(v)   ((((reg32_t) v) << 1) & BM_USDHC_PRES_STATE_CDIHB)
#else
#define BF_USDHC_PRES_STATE_CDIHB(v)   (((v) << 1) & BM_USDHC_PRES_STATE_CDIHB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CDIHB(v)   BF_CS1(USDHC_PRES_STATE, CDIHB, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field DLA
 *
 * Data Line Active  This status bit indicates whether one of the DAT lines on the SD Bus
 * is in use.  In the case of read transactions:  This status indicates if a read transfer is
 * executing on the SD Bus.                                 Changes in this value from 1 to 0,
 * between data blocks, generates a                                 Block Gap Event interrupt in the
 * Interrupt Status register.  This bit will be set in either of the following cases:   After the
 * end bit of the read command.  When writing a 1 to the Continue Request bit in the Protocol
 * Control register to restart a read transfer.   This bit will be cleared in either of the
 * following cases:  (1) When the end bit of the last data block is sent from the SD Bus
 * to the uSDHC.  (2) When the Read Wait state is stopped by a Suspend command and the
 * DAT2 line is released.  The uSDHC will wait at the next block gap by driving Read Wait at the
 * start of the interrupt cycle. If the Read Wait signal is already
 * driven (data buffer cannot receive data), the uSDHC can wait for a
 * current block gap by continuing to drive the Read Wait signal. It is
 * necessary to support Read Wait in order to use the suspend / resume
 * function. This bit will remain 1 during Read Wait.  In the case of write transactions:  This
 * status indicates that a write transfer is executing on the SD
 * Bus. Changes in this value from 1 to 0 generate a Transfer Complete
 * interrupt in the Interrupt Status register.  This bit will be set in either of the following
 * cases:   After the end bit of the write command.  When writing to 1 to the Continue Request bit
 * in the Protocol                                     Control register to continue a write
 * transfer.   This bit will be cleared in either of the following cases:   When the SD card
 * releases Write Busy of the last data block, the                                     uSDHC will
 * also detect if the output is not busy. If the SD card                                     does
 * not drive the busy signal after the CRC status is received,
 * the uSDHC shall assume the card drive "Not Busy".  When the SD card releases write busy, prior to
 * waiting for write                                     transfer, and as a result of a Stop At
 * Block Gap Request.   In the case of command with busy pending:  This status indicates that a busy
 * state follows the command and the                                 data line is in use. This bit
 * will be cleared when the DAT0 line is                                 released.
 */

#define BP_USDHC_PRES_STATE_DLA      2
#define BM_USDHC_PRES_STATE_DLA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_DLA(v)   ((((reg32_t) v) << 2) & BM_USDHC_PRES_STATE_DLA)
#else
#define BF_USDHC_PRES_STATE_DLA(v)   (((v) << 2) & BM_USDHC_PRES_STATE_DLA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_DLA(v)   BF_CS1(USDHC_PRES_STATE, DLA, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field SDSTB
 *
 * SD Clock Stable  This status bit indicates that the internal card clock is stable.
 * This bit is for the Host Driver to poll clock status when changing
 * the clock frequency. It is recommended to clear SDCLKEN bit in
 * System Control register to remove glitch on the card clock when the
 * frequency is changing.   Before changing clock divisor value(SDCLKFS or DVS), Host Driver
 * should make sure the SDSTB bit is high.
 */

#define BP_USDHC_PRES_STATE_SDSTB      3
#define BM_USDHC_PRES_STATE_SDSTB      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_SDSTB(v)   ((((reg32_t) v) << 3) & BM_USDHC_PRES_STATE_SDSTB)
#else
#define BF_USDHC_PRES_STATE_SDSTB(v)   (((v) << 3) & BM_USDHC_PRES_STATE_SDSTB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_SDSTB(v)   BF_CS1(USDHC_PRES_STATE, SDSTB, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field IPGOFF
 *
 * ipg_clk Gated Off Internally:  This status bit indicates that the ipg_clk is internally gated
 * off.                                 This bit is for the Host Driver to debug.
 */

#define BP_USDHC_PRES_STATE_IPGOFF      4
#define BM_USDHC_PRES_STATE_IPGOFF      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_IPGOFF(v)   ((((reg32_t) v) << 4) & BM_USDHC_PRES_STATE_IPGOFF)
#else
#define BF_USDHC_PRES_STATE_IPGOFF(v)   (((v) << 4) & BM_USDHC_PRES_STATE_IPGOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_IPGOFF(v)   BF_CS1(USDHC_PRES_STATE, IPGOFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field HCKOFF
 *
 * hclk Gated Off Internally:  This status bit indicates that the hclk is internally gated off. This
 * bit is for the Host Driver to debug during a data transfer.
 */

#define BP_USDHC_PRES_STATE_HCKOFF      5
#define BM_USDHC_PRES_STATE_HCKOFF      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_HCKOFF(v)   ((((reg32_t) v) << 5) & BM_USDHC_PRES_STATE_HCKOFF)
#else
#define BF_USDHC_PRES_STATE_HCKOFF(v)   (((v) << 5) & BM_USDHC_PRES_STATE_HCKOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_HCKOFF(v)   BF_CS1(USDHC_PRES_STATE, HCKOFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field PEROFF
 *
 * ipg_perclk Gated Off Internally:  This status bit indicates that the ipg_perclk is internally
 * gated                                 off. This bit is for the Host Driver to debug transaction
 * on the SD                                 bus. When INITA bit is set, uSDHC sending 80 clock
 * cycles to the                                 card, the SDCLKEN bit must be '1' to enable the
 * output card clock,                                 otherwise the ipg_perclk will never be gate
 * off, so ipg_perclk and                                 ipg_clk will be always active.
 */

#define BP_USDHC_PRES_STATE_PEROFF      6
#define BM_USDHC_PRES_STATE_PEROFF      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_PEROFF(v)   ((((reg32_t) v) << 6) & BM_USDHC_PRES_STATE_PEROFF)
#else
#define BF_USDHC_PRES_STATE_PEROFF(v)   (((v) << 6) & BM_USDHC_PRES_STATE_PEROFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_PEROFF(v)   BF_CS1(USDHC_PRES_STATE, PEROFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field SDOFF
 *
 * SD Clock Gated Off Internally:  This status bit indicates that the SD Clock is internally gated
 * off,                                 because of buffer over/under-run or read pause without read
 * wait                                 assertion, or the driver has cleared SDCLKEN bit to stop the
 * SD                                 clock. This bit is for the Host Driver to debug data
 * transaction on                                 the SD bus.
 */

#define BP_USDHC_PRES_STATE_SDOFF      7
#define BM_USDHC_PRES_STATE_SDOFF      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_SDOFF(v)   ((((reg32_t) v) << 7) & BM_USDHC_PRES_STATE_SDOFF)
#else
#define BF_USDHC_PRES_STATE_SDOFF(v)   (((v) << 7) & BM_USDHC_PRES_STATE_SDOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_SDOFF(v)   BF_CS1(USDHC_PRES_STATE, SDOFF, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field WTA
 *
 * Write Transfer Active:  This status bit indicates a write transfer is active. If this bit is
 * 0, it means no valid write data exists in the uSDHC.  This bit is set in either of the following
 * cases:   After the end bit of the write command.  When writing 1 to the Continue Request bit in
 * the Protocol                                     Control register to restart a write transfer.
 * This bit is cleared in either of the following cases:   After getting the CRC status of the last
 * data block as specified                                     by the transfer count (Single and
 * Multiple).  After getting the CRC status of any block where data
 * transmission is about to be stopped by a Stop At Block Gap
 * Request.   During a write transaction, a Block Gap Event interrupt is generated
 * when this bit is changed to 0, as result of the Stop At Block Gap
 * Request being set. This status is useful for the Host Driver in
 * determining when to issue commands during Write Busy state.
 */

#define BP_USDHC_PRES_STATE_WTA      8
#define BM_USDHC_PRES_STATE_WTA      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_WTA(v)   ((((reg32_t) v) << 8) & BM_USDHC_PRES_STATE_WTA)
#else
#define BF_USDHC_PRES_STATE_WTA(v)   (((v) << 8) & BM_USDHC_PRES_STATE_WTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_WTA(v)   BF_CS1(USDHC_PRES_STATE, WTA, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field RTA
 *
 * Read Transfer Active:  This status bit is used for detecting completion of a read
 * transfer.  This bit is set for either of the following conditions:   After the end bit of the
 * read command.  When writing a 1 to the Continue Request bit in the Protocol
 * Control register to restart a read transfer.   A Transfer Complete interrupt is generated when
 * this bit changes to                                 0. This bit is cleared for either of the
 * following conditions:   When the last data block as specified by block length is
 * transferred to the System, i.e. all data are read away from
 * uSDHC internal buffer.  When all valid data blocks have been transferred from uSDHC
 * internal buffer to the System and no current block transfers are
 * being sent as a result of the Stop At Block Gap Request being
 * set to 1.
 */

#define BP_USDHC_PRES_STATE_RTA      9
#define BM_USDHC_PRES_STATE_RTA      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_RTA(v)   ((((reg32_t) v) << 9) & BM_USDHC_PRES_STATE_RTA)
#else
#define BF_USDHC_PRES_STATE_RTA(v)   (((v) << 9) & BM_USDHC_PRES_STATE_RTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_RTA(v)   BF_CS1(USDHC_PRES_STATE, RTA, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field BWEN
 *
 * Buffer Write Enable:  This status bit is used for non-DMA write transfers. The uSDHC
 * implements an internal buffer to transfer data efficiently. This
 * read only flag indicates if space is available for write data. If
 * this bit is 1, valid data greater than the watermark level can be
 * written to the buffer. A change of this bit from 1 to 0 occurs when
 * some writes to the buffer(write DATPORT(Base + 0x20)) are made and
 * the buffer hasn't valid space greater than the watermake level. . A
 * change of this bit from 0 to 1 occurs when the buffer can hold valid
 * data greater than the write watermark level and the Buffer Write
 * Ready interrupt is generated and enabled.
 */

#define BP_USDHC_PRES_STATE_BWEN      10
#define BM_USDHC_PRES_STATE_BWEN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_BWEN(v)   ((((reg32_t) v) << 10) & BM_USDHC_PRES_STATE_BWEN)
#else
#define BF_USDHC_PRES_STATE_BWEN(v)   (((v) << 10) & BM_USDHC_PRES_STATE_BWEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_BWEN(v)   BF_CS1(USDHC_PRES_STATE, BWEN, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field BREN
 *
 * Buffer Read Enable:  This status bit is used for non-DMA read transfers. The uSDHC
 * implements an internal buffer to transfer data efficiently. This
 * read only flag indicates that valid data exists in the host side
 * buffer. If this bit is high, valid data greater than the watermark
 * level exist in the buffer. A change of this bit from 1 to 0 occurs
 * when some reads from the buffer(read DATPORT(Base + 0x20)) are made
 * and the buffer hasn't valid data greater than the watermake level. A
 * change of this bit from 0 to1 occurs when there is enough valid data
 * ready in the buffer and the Buffer Read Ready interrupt has been
 * generated and enabled.
 */

#define BP_USDHC_PRES_STATE_BREN      11
#define BM_USDHC_PRES_STATE_BREN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_BREN(v)   ((((reg32_t) v) << 11) & BM_USDHC_PRES_STATE_BREN)
#else
#define BF_USDHC_PRES_STATE_BREN(v)   (((v) << 11) & BM_USDHC_PRES_STATE_BREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_BREN(v)   BF_CS1(USDHC_PRES_STATE, BREN, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field RTR
 *
 * Re-Tuning Request: (only for SD3.0 SDR104 mode)  Host Controller may request Host Driver to
 * execute re-tuning sequence                                 by setting this bit when the data
 * window is shifted by temperature                                 drift and a tuned sampling point
 * does not have a good margin to                                 receive correct data.  This bit is
 * cleared when a command is issued with setting Execute                                 Tuning bit
 * in MIXER_CTRL register.  Changing of this bit from 0 to 1 generates Re-Tuning Event. Refer to
 * Interrupt status registers for more delail.  This bit isn't set to 1 if Sampling Clock Select in
 * the MIXER_CTRL                                 register is set to 0 (using fixed sampling clock).
 */

#define BP_USDHC_PRES_STATE_RTR      12
#define BM_USDHC_PRES_STATE_RTR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_RTR(v)   ((((reg32_t) v) << 12) & BM_USDHC_PRES_STATE_RTR)
#else
#define BF_USDHC_PRES_STATE_RTR(v)   (((v) << 12) & BM_USDHC_PRES_STATE_RTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_RTR(v)   BF_CS1(USDHC_PRES_STATE, RTR, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CINST
 *
 * Card Inserted:  This bit indicates whether a card has been inserted. The uSDHC
 * debounces this signal so that the Host Driver will not need to wait
 * for it to stabilize. Changing from a 0 to 1 generates a Card
 * Insertion interrupt in the Interrupt Status register. Changing from
 * a 1 to 0 generates a Card Removal interrupt in the Interrupt Status
 * register. A write to the Force Event Register does not effect this
 * bit.  The Software Reset For All in the System Control register does not
 * effect this bit.A software reset does not effect this bit.
 */

#define BP_USDHC_PRES_STATE_CINST      16
#define BM_USDHC_PRES_STATE_CINST      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CINST(v)   ((((reg32_t) v) << 16) & BM_USDHC_PRES_STATE_CINST)
#else
#define BF_USDHC_PRES_STATE_CINST(v)   (((v) << 16) & BM_USDHC_PRES_STATE_CINST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CINST(v)   BF_CS1(USDHC_PRES_STATE, CINST, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CDPL
 *
 * Card Detect Pin Level:  This bit reflects the inverse value of the SD_CD# pin for the card
 * socket. Debouncing is not performed on this bit. This bit may be
 * valid, but is not guaranteed, because of propagation delay. Use of
 * this bit is limited to testing since it must be debounced by
 * software. A software reset does not effect this bit. A write to the
 * Force Event Register does not effect this bit. The reset value is
 * effected by the external card detection pin. This bit shows the
 * value on the SD_CD# pin (i.e. when a card is inserted in the socket,
 * it is 0 on the SD_CD# input, and consequently the CDPL reads 1.)
 */

#define BP_USDHC_PRES_STATE_CDPL      18
#define BM_USDHC_PRES_STATE_CDPL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CDPL(v)   ((((reg32_t) v) << 18) & BM_USDHC_PRES_STATE_CDPL)
#else
#define BF_USDHC_PRES_STATE_CDPL(v)   (((v) << 18) & BM_USDHC_PRES_STATE_CDPL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CDPL(v)   BF_CS1(USDHC_PRES_STATE, CDPL, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field WPSPL
 *
 * Write Protect Switch Pin Level:  The Write Protect Switch is supported for memory and combo
 * cards.This                                 bit reflects the inverted value of the SD_WP pin of
 * the card socket.                                 A software reset does not affect this bit. The
 * reset value is                                 effected by the external write protect switch. If
 * the SD_WP pin is                                 not used, it should be tied low, so that the
 * reset value of this bit                                 is high and write is enabled.
 */

#define BP_USDHC_PRES_STATE_WPSPL      19
#define BM_USDHC_PRES_STATE_WPSPL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_WPSPL(v)   ((((reg32_t) v) << 19) & BM_USDHC_PRES_STATE_WPSPL)
#else
#define BF_USDHC_PRES_STATE_WPSPL(v)   (((v) << 19) & BM_USDHC_PRES_STATE_WPSPL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_WPSPL(v)   BF_CS1(USDHC_PRES_STATE, WPSPL, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field CLSL
 *
 * CMD Line Signal Level:  This status is used to check the CMD line level to recover from
 * errors, and for debugging. The reset value is effected by the
 * external pull-up/pull-down resistor, by default, the read value of
 * this bit after reset is 1'b1, when the command line is pulled                                 up.
 */

#define BP_USDHC_PRES_STATE_CLSL      23
#define BM_USDHC_PRES_STATE_CLSL      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_CLSL(v)   ((((reg32_t) v) << 23) & BM_USDHC_PRES_STATE_CLSL)
#else
#define BF_USDHC_PRES_STATE_CLSL(v)   (((v) << 23) & BM_USDHC_PRES_STATE_CLSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_CLSL(v)   BF_CS1(USDHC_PRES_STATE, CLSL, v)
#endif

/* --- Register HW_USDHC_PRES_STATE, field DLSL
 *
 * DAT[7:0] Line Signal Level:  This status is used to check the DAT line level to recover from
 * errors, and for debugging.This is especially useful in detecting the
 * busy signal level from DAT[0]. The reset value is effected by the
 * external pull-up/pull-down resistors. By default, the read value of
 * this bit field after reset is 8'b11110111, when DAT[3] is pulled
 * down and the other lines are pulled up.  DAT[7]: Data 7 line signal level  DAT[6]: Data 6 line
 * signal level  DAT[5]: Data 5 line signal level  DAT[4]: Data 4 line signal level  DAT[3]: Data 3
 * line signal level  DAT[2]: Data 2 line signal level  DAT[1]: Data 1 line signal level  DAT[0]:
 * Data 0 line signal level
 */

#define BP_USDHC_PRES_STATE_DLSL      24
#define BM_USDHC_PRES_STATE_DLSL      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PRES_STATE_DLSL(v)   ((((reg32_t) v) << 24) & BM_USDHC_PRES_STATE_DLSL)
#else
#define BF_USDHC_PRES_STATE_DLSL(v)   (((v) << 24) & BM_USDHC_PRES_STATE_DLSL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PRES_STATE_DLSL(v)   BF_CS1(USDHC_PRES_STATE, DLSL, v)
#endif

/*!
 * @brief HW_USDHC_PROT_CTRL - Protocol Control
 *
 * There are three cases to restart the transfer after stop at the block
 * gap. Which case is appropriate depends on whether the uSDHC issues a
 * Suspend command or the SD card accepts the Suspend command.   If the Host Driver does not issue a
 * Suspend command, the Continue                                 Request shall be used to restart
 * the transfer.  If the Host Driver issues a Suspend command and the SD card accepts
 * it, a Resume command shall be used to restart the transfer.  If the Host Driver issues a Suspend
 * command and the SD card does not                                 accept it, the Continue Request
 * shall be used to restart the                                 transfer.   Any time Stop At Block
 * Gap Request stops the data transfer, the Host                             Driver shall wait for a
 * Transfer Complete (in the Interrupt Status                             register), before
 * attempting to restart the transfer. When restarting                             the data transfer
 * by Continue Request, the Host Driver shall clear the                             Stop At Block
 * Gap Request before or simultaneously.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LCTL : 1; //!< LED Control:  This bit, fully controlled by the Host Driver, is used to caution the user not to remove the card while the card is being accessed. If the software is going to issue multiple SD commands, this bit can be set during all these transactions. It is not necessary to change for each transaction. When the software issues multiple SD commands, setting the bit once before the first command is sufficient: it is not necessary to reset the bit between commands.
        unsigned DTW : 2; //!< Data Transfer Width:  This bit selects the data width of the SD bus for a data transfer. The Host Driver shall set it to match the data width of the card. Possible Data transfer Width is 1-bit, 4-bits or 8-bits.
        unsigned D3CD : 1; //!< DAT3 as Card Detection Pin:  If this bit is set, DAT3 should be pulled down to act as a card detection pin. Be cautious when using this feature, because DAT3 is also a chip-select for the SPI mode. A pull-down on this pin and CMD0 may set the card into the SPI mode, which the uSDHC does not support.
        unsigned EMODE : 2; //!< Endian Mode:  The uSDHC supports all four endian modes in data transfer. Refer to " for more details.
        unsigned CDTL : 1; //!< Card Detect Test Level:  This is bit is enabled while the Card Detection Signal Selection is set to 1 and it indicates card insertion.
        unsigned CDSS : 1; //!< Card Detect Signal Selection:  This bit selects the source for the card detection.
        unsigned DMASEL : 2; //!< DMA Select:  This field is valid while DMA (SDMA or ADMA) is enabled and selects the DMA operation.
        unsigned RESERVED0 : 6; //!< Reserved
        unsigned SABGREQ : 1; //!< Stop At Block Gap Request:  This bit is used to stop executing a transaction at the next block gap for both DMA and non-DMA transfers. Until the Transfer Complete is set to 1, indicating a transfer completion, the Host Driver shall leave this bit set to 1. Clearing both the Stop At Block Gap Request and Continue Request does not cause the transaction to restart. Read Wait is used to stop the read transaction at the block gap. The uSDHC will honor the Stop At Block Gap Request for write transfers, but for read transfers it requires that the SDIO card support Read Wait. Therefore, the Host Driver shall not set this bit during read transfers unless the SDIO card supports Read Wait and has set the Read Wait Control to 1, otherwise the uSDHC will stop the SD bus clock to pause the read operation during block gap. In the case of write transfers in which the Host Driver writes data to the Data Port register, the Host Driver shall set this bit after all block data is written. If this bit is set to 1, the Host Driver shall not write data to the Data Port register after a block is sent. Once this bit is set, the Host Driver shall not clear this bit before the Transfer Complete bit in Interrupt Status Register is set, otherwise the uSDHCs behavior is undefined.  This bit effects Read Transfer Active, Write Transfer Active, DAT Line Active and Command Inhibit (DAT) in the Present State register.
        unsigned CREQ : 1; //!< Continue Request:  This bit is used to restart a transaction which was stopped using the Stop At Block Gap Request. When a Suspend operation is not accepted by the card, it is also by setting this bit to restart the paused transfer. To cancel stop at the block gap, set Stop At Block Gap Request to 0 and set this bit to 1 to restart the transfer.  The uSDHC automatically clears this bit, therefore it is not necessary for the Host Driver to set this bit to 0. If both Stop At Block Gap Request and this bit are 1, the continue request is ignored.
        unsigned RWCTL : 1; //!< Read Wait Control:  The read wait function is optional for SDIO cards. If the card supports read wait, set this bit to enable use of the read wait protocol to stop read data using the DAT[2] line. Otherwise the uSDHC has to stop the SD Clock to hold read data, which restricts commands generation. When the Host Driver detects an SDIO card insertion, it shall set this bit according to the CCCR of the card. If the card does not support read wait, this bit shall never be set to 1, otherwise DAT line conflicts may occur. If this bit is set to 0, stop at block gap during read operation is also supported, but the uSDHC will stop the SD Clock to pause reading operation.
        unsigned IABG : 1; //!< Interrupt At Block Gap:  This bit is valid only in 4-bit mode, of the SDIO card, and selects a sample point in the interrupt cycle. Setting to 1 enables interrupt detection at the block gap for a multiple block transfer. Setting to 0 disables interrupt detection during a multiple block transfer. If the SDIO card can't signal an interrupt during a multiple block transfer, this bit should be set to 0 to avoid an inadvertent interrupt. When the Host Driver detects an SDIO card insertion, it shall set this bit according to the CCCR of the card.
        unsigned RD_DONE_NO_8CLK : 1; //!< Read done no 8 clock:    According to the SD/MMC spec, for read data transaction, 8 clocks are needed after the end bit of the last data block. So, by default(RD_DONE_NO_8CLK=0), 8 clocks will be active after the end bit of the last read data transaction.    However, this 8 clocks should not be active if user wants to use stop at block gap(include the auto stop at block gap in boot mode) feature for read and the RWCTL bit(bit18) is not enabled. In this case, software should set RD_DONE_NO_8CLK to avoid this 8 clocks. Otherwise, the device may send extra data to uSDHC while uSDHC ignores these data.    In a summary, this bit should be set only if the use case needs to use stop at block gap feature while the device can't support the read wait feature.
        unsigned RD_WAIT_POINT : 3; //!< Read wait point :  This is only for debug purpose.  As a Host controller, uSDHC should pause the SDHC_CLK or assert the DAT[2](if read wait feature is supported by the device) to avoid the device to send extra data. The SDHC_CLK should be paused or the DAT[2] should be asserted in two clock cycles after the end bit of the last transaction. Meanwhile, because the uSDHC controller has async FIFO between the card interface and the internal state machine, we need this "Read wait point" configuration to overcome the latency which is introduced by this async FIFO.  The default value is 0x4, which should be accurately overcome the latency.
        unsigned WECINT : 1; //!< Wakeup Event Enable On Card Interrupt:  This bit enables a wakeup event, via a Card Interrupt, in the Interrupt Status register. This bit can be set to 1 if FN_WUS (Wake Up Support) in CIS is set to 1. When this bit is set, the Card Interrupt Status and the uSDHC interrupt can be asserted without SD_CLK toggling. When the wakeup feature is not enabled, the SD_CLK must be active in order to assert the Card Interrupt Status and the uSDHC interrupt.
        unsigned WECINS : 1; //!< Wakeup Event Enable On SD Card Insertion:  This bit enables a wakeup event, via a Card Insertion, in the Interrupt Status register. FN_WUS (Wake Up Support) in CIS does not effect this bit. When this bit is set, the Card Insertion Status and the uSDHC interrupt can be asserted without SD_CLK toggling. When the wakeup feature is not enabled, the SD_CLK must be active in order to assert the Card Insertion Status and the uSDHC interrupt.
        unsigned WECRM : 1; //!< Wakeup Event Enable On SD Card Removal:  This bit enables a wakeup event, via a Card Removal, in the Interrupt Status register. FN_WUS (Wake Up Support) in CIS does not effect this bit. When this bit is set, the Card Removal Status and the uSDHC interrupt can be asserted without SD_CLK toggling. When the wakeup feature is not enabled, the SD_CLK must be active in order to assert the Card Removal Status and the uSDHC interrupt.
        unsigned BURST_LEN_EN : 3; //!< BURST length enable for INCR, INCR4/INCR8/INCR16, INCR4-WRAP/INCR8-WRAP/INCR16-WRAP  This is used to enable/disable the burst length for the external AHB2AXI bridge. It's useful especially for INCR transfer because without burst length indicator, the AHB2AXI bridge doesn't know the burst length in advance. Without burst length indicator, AHB INCR transfers can only be converted to SINGLEs in AXI side.
        unsigned NON_EXACT_BLK_RD : 1; //!< Current block read is non-exact block read. It's only used for SDIO.
        unsigned RD_NO8CLK_EN : 1; //!< Only for debug.  enable S/W RD_DONE_NO_8CLK bit
    } B;
} hw_usdhc_prot_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_PROT_CTRL register
 */
#define HW_USDHC_PROT_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_PROT_CTRL(x)           (*(volatile hw_usdhc_prot_ctrl_t *) HW_USDHC_PROT_CTRL_ADDR(x))
#define HW_USDHC_PROT_CTRL_RD(x)        (HW_USDHC_PROT_CTRL(x).U)
#define HW_USDHC_PROT_CTRL_WR(x, v)     (HW_USDHC_PROT_CTRL(x).U = (v))
#define HW_USDHC_PROT_CTRL_SET(x, v)    (HW_USDHC_PROT_CTRL_WR(x, HW_USDHC_PROT_CTRL_RD(x) |  (v)))
#define HW_USDHC_PROT_CTRL_CLR(x, v)    (HW_USDHC_PROT_CTRL_WR(x, HW_USDHC_PROT_CTRL_RD(x) & ~(v)))
#define HW_USDHC_PROT_CTRL_TOG(x, v)    (HW_USDHC_PROT_CTRL_WR(x, HW_USDHC_PROT_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_PROT_CTRL bitfields
 */

/* --- Register HW_USDHC_PROT_CTRL, field LCTL
 *
 * LED Control:  This bit, fully controlled by the Host Driver, is used to caution the
 * user not to remove the card while the card is being accessed. If the
 * software is going to issue multiple SD commands, this bit can be set
 * during all these transactions. It is not necessary to change for
 * each transaction. When the software issues multiple SD commands,
 * setting the bit once before the first command is sufficient: it is
 * not necessary to reset the bit between commands.
 */

#define BP_USDHC_PROT_CTRL_LCTL      0
#define BM_USDHC_PROT_CTRL_LCTL      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_LCTL(v)   ((((reg32_t) v) << 0) & BM_USDHC_PROT_CTRL_LCTL)
#else
#define BF_USDHC_PROT_CTRL_LCTL(v)   (((v) << 0) & BM_USDHC_PROT_CTRL_LCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_LCTL(v)   BF_CS1(USDHC_PROT_CTRL, LCTL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field DTW
 *
 * Data Transfer Width:  This bit selects the data width of the SD bus for a data transfer.
 * The Host Driver shall set it to match the data width of the card.
 * Possible Data transfer Width is 1-bit, 4-bits or 8-bits.
 */

#define BP_USDHC_PROT_CTRL_DTW      1
#define BM_USDHC_PROT_CTRL_DTW      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_DTW(v)   ((((reg32_t) v) << 1) & BM_USDHC_PROT_CTRL_DTW)
#else
#define BF_USDHC_PROT_CTRL_DTW(v)   (((v) << 1) & BM_USDHC_PROT_CTRL_DTW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_DTW(v)   BF_CS1(USDHC_PROT_CTRL, DTW, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field D3CD
 *
 * DAT3 as Card Detection Pin:  If this bit is set, DAT3 should be pulled down to act as a card
 * detection pin. Be cautious when using this feature, because DAT3 is
 * also a chip-select for the SPI mode. A pull-down on this pin and
 * CMD0 may set the card into the SPI mode, which the uSDHC does not
 * support.
 */

#define BP_USDHC_PROT_CTRL_D3CD      3
#define BM_USDHC_PROT_CTRL_D3CD      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_D3CD(v)   ((((reg32_t) v) << 3) & BM_USDHC_PROT_CTRL_D3CD)
#else
#define BF_USDHC_PROT_CTRL_D3CD(v)   (((v) << 3) & BM_USDHC_PROT_CTRL_D3CD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_D3CD(v)   BF_CS1(USDHC_PROT_CTRL, D3CD, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field EMODE
 *
 * Endian Mode:  The uSDHC supports all four endian modes in data transfer. Refer to " for more
 * details.
 */

#define BP_USDHC_PROT_CTRL_EMODE      4
#define BM_USDHC_PROT_CTRL_EMODE      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_EMODE(v)   ((((reg32_t) v) << 4) & BM_USDHC_PROT_CTRL_EMODE)
#else
#define BF_USDHC_PROT_CTRL_EMODE(v)   (((v) << 4) & BM_USDHC_PROT_CTRL_EMODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_EMODE(v)   BF_CS1(USDHC_PROT_CTRL, EMODE, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field CDTL
 *
 * Card Detect Test Level:  This is bit is enabled while the Card Detection Signal Selection is
 * set to 1 and it indicates card insertion.
 */

#define BP_USDHC_PROT_CTRL_CDTL      6
#define BM_USDHC_PROT_CTRL_CDTL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_CDTL(v)   ((((reg32_t) v) << 6) & BM_USDHC_PROT_CTRL_CDTL)
#else
#define BF_USDHC_PROT_CTRL_CDTL(v)   (((v) << 6) & BM_USDHC_PROT_CTRL_CDTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_CDTL(v)   BF_CS1(USDHC_PROT_CTRL, CDTL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field CDSS
 *
 * Card Detect Signal Selection:  This bit selects the source for the card detection.
 */

#define BP_USDHC_PROT_CTRL_CDSS      7
#define BM_USDHC_PROT_CTRL_CDSS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_CDSS(v)   ((((reg32_t) v) << 7) & BM_USDHC_PROT_CTRL_CDSS)
#else
#define BF_USDHC_PROT_CTRL_CDSS(v)   (((v) << 7) & BM_USDHC_PROT_CTRL_CDSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_CDSS(v)   BF_CS1(USDHC_PROT_CTRL, CDSS, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field DMASEL
 *
 * DMA Select:  This field is valid while DMA (SDMA or ADMA) is enabled and selects
 * the DMA operation.
 */

#define BP_USDHC_PROT_CTRL_DMASEL      8
#define BM_USDHC_PROT_CTRL_DMASEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_DMASEL(v)   ((((reg32_t) v) << 8) & BM_USDHC_PROT_CTRL_DMASEL)
#else
#define BF_USDHC_PROT_CTRL_DMASEL(v)   (((v) << 8) & BM_USDHC_PROT_CTRL_DMASEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_DMASEL(v)   BF_CS1(USDHC_PROT_CTRL, DMASEL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field SABGREQ
 *
 * Stop At Block Gap Request:  This bit is used to stop executing a transaction at the next block
 * gap for both DMA and non-DMA transfers. Until the Transfer Complete
 * is set to 1, indicating a transfer completion, the Host Driver shall
 * leave this bit set to 1. Clearing both the Stop At Block Gap Request
 * and Continue Request does not cause the transaction to restart. Read
 * Wait is used to stop the read transaction at the block gap. The
 * uSDHC will honor the Stop At Block Gap Request for write transfers,
 * but for read transfers it requires that the SDIO card support Read
 * Wait. Therefore, the Host Driver shall not set this bit during read
 * transfers unless the SDIO card supports Read Wait and has set the
 * Read Wait Control to 1, otherwise the uSDHC will stop the SD bus
 * clock to pause the read operation during block gap. In the case of
 * write transfers in which the Host Driver writes data to the Data
 * Port register, the Host Driver shall set this bit after all block
 * data is written. If this bit is set to 1, the Host Driver shall not
 * write data to the Data Port register after a block is sent. Once
 * this bit is set, the Host Driver shall not clear this bit before the
 * Transfer Complete bit in Interrupt Status Register is set, otherwise
 * the uSDHCs behavior is undefined.  This bit effects Read Transfer Active, Write Transfer Active,
 * DAT                                 Line Active and Command Inhibit (DAT) in the Present State
 * register.
 */

#define BP_USDHC_PROT_CTRL_SABGREQ      16
#define BM_USDHC_PROT_CTRL_SABGREQ      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_SABGREQ(v)   ((((reg32_t) v) << 16) & BM_USDHC_PROT_CTRL_SABGREQ)
#else
#define BF_USDHC_PROT_CTRL_SABGREQ(v)   (((v) << 16) & BM_USDHC_PROT_CTRL_SABGREQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_SABGREQ(v)   BF_CS1(USDHC_PROT_CTRL, SABGREQ, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field CREQ
 *
 * Continue Request:  This bit is used to restart a transaction which was stopped using the
 * Stop At Block Gap Request. When a Suspend operation is not accepted
 * by the card, it is also by setting this bit to restart the paused
 * transfer. To cancel stop at the block gap, set Stop At Block Gap
 * Request to 0 and set this bit to 1 to restart the transfer.  The uSDHC automatically clears this
 * bit, therefore it is not                                 necessary for the Host Driver to set
 * this bit to 0. If both Stop At                                 Block Gap Request and this bit are
 * 1, the continue request is                                 ignored.
 */

#define BP_USDHC_PROT_CTRL_CREQ      17
#define BM_USDHC_PROT_CTRL_CREQ      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_CREQ(v)   ((((reg32_t) v) << 17) & BM_USDHC_PROT_CTRL_CREQ)
#else
#define BF_USDHC_PROT_CTRL_CREQ(v)   (((v) << 17) & BM_USDHC_PROT_CTRL_CREQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_CREQ(v)   BF_CS1(USDHC_PROT_CTRL, CREQ, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RWCTL
 *
 * Read Wait Control:  The read wait function is optional for SDIO cards. If the card
 * supports read wait, set this bit to enable use of the read wait
 * protocol to stop read data using the DAT[2] line. Otherwise the
 * uSDHC has to stop the SD Clock to hold read data, which restricts
 * commands generation. When the Host Driver detects an SDIO card
 * insertion, it shall set this bit according to the CCCR of the card.
 * If the card does not support read wait, this bit shall never be set
 * to 1, otherwise DAT line conflicts may occur. If this bit is set to
 * 0, stop at block gap during read operation is also supported, but
 * the uSDHC will stop the SD Clock to pause reading operation.
 */

#define BP_USDHC_PROT_CTRL_RWCTL      18
#define BM_USDHC_PROT_CTRL_RWCTL      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RWCTL(v)   ((((reg32_t) v) << 18) & BM_USDHC_PROT_CTRL_RWCTL)
#else
#define BF_USDHC_PROT_CTRL_RWCTL(v)   (((v) << 18) & BM_USDHC_PROT_CTRL_RWCTL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RWCTL(v)   BF_CS1(USDHC_PROT_CTRL, RWCTL, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field IABG
 *
 * Interrupt At Block Gap:  This bit is valid only in 4-bit mode, of the SDIO card, and selects a
 * sample point in the interrupt cycle. Setting to 1 enables interrupt
 * detection at the block gap for a multiple block transfer. Setting to
 * 0 disables interrupt detection during a multiple block transfer. If
 * the SDIO card can't signal an interrupt during a multiple block
 * transfer, this bit should be set to 0 to avoid an inadvertent
 * interrupt. When the Host Driver detects an SDIO card insertion, it
 * shall set this bit according to the CCCR of the card.
 */

#define BP_USDHC_PROT_CTRL_IABG      19
#define BM_USDHC_PROT_CTRL_IABG      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_IABG(v)   ((((reg32_t) v) << 19) & BM_USDHC_PROT_CTRL_IABG)
#else
#define BF_USDHC_PROT_CTRL_IABG(v)   (((v) << 19) & BM_USDHC_PROT_CTRL_IABG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_IABG(v)   BF_CS1(USDHC_PROT_CTRL, IABG, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RD_DONE_NO_8CLK
 *
 * Read done no 8 clock:    According to the SD/MMC spec, for read data transaction, 8 clocks
 * are needed after the end bit of the last data block. So, by
 * default(RD_DONE_NO_8CLK=0), 8 clocks will be active after the
 * end bit of the last read data transaction.    However, this 8 clocks should not be active if user
 * wants to use                                     stop at block gap(include the auto stop at block
 * gap in boot                                     mode) feature for read and the RWCTL bit(bit18)
 * is not enabled.                                     In this case, software should set
 * RD_DONE_NO_8CLK to avoid this                                     8 clocks. Otherwise, the device
 * may send extra data to uSDHC                                     while uSDHC ignores these data.
 * In a summary, this bit should be set only if the use case needs
 * to use stop at block gap feature while the device can't support
 * the read wait feature.
 */

#define BP_USDHC_PROT_CTRL_RD_DONE_NO_8CLK      20
#define BM_USDHC_PROT_CTRL_RD_DONE_NO_8CLK      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RD_DONE_NO_8CLK(v)   ((((reg32_t) v) << 20) & BM_USDHC_PROT_CTRL_RD_DONE_NO_8CLK)
#else
#define BF_USDHC_PROT_CTRL_RD_DONE_NO_8CLK(v)   (((v) << 20) & BM_USDHC_PROT_CTRL_RD_DONE_NO_8CLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RD_DONE_NO_8CLK(v)   BF_CS1(USDHC_PROT_CTRL, RD_DONE_NO_8CLK, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RD_WAIT_POINT
 *
 * Read wait point :  This is only for debug purpose.  As a Host controller, uSDHC should pause the
 * SDHC_CLK or assert the                                 DAT[2](if read wait feature is supported
 * by the device) to avoid the                                 device to send extra data. The
 * SDHC_CLK should be paused or the                                 DAT[2] should be asserted in two
 * clock cycles after the end bit of                                 the last transaction.
 * Meanwhile, because the uSDHC controller has                                 async FIFO between
 * the card interface and the internal state                                 machine, we need this
 * "Read wait point" configuration to overcome                                 the latency which is
 * introduced by this async FIFO.  The default value is 0x4, which should be accurately overcome the
 * latency.
 */

#define BP_USDHC_PROT_CTRL_RD_WAIT_POINT      21
#define BM_USDHC_PROT_CTRL_RD_WAIT_POINT      0x00e00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RD_WAIT_POINT(v)   ((((reg32_t) v) << 21) & BM_USDHC_PROT_CTRL_RD_WAIT_POINT)
#else
#define BF_USDHC_PROT_CTRL_RD_WAIT_POINT(v)   (((v) << 21) & BM_USDHC_PROT_CTRL_RD_WAIT_POINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RD_WAIT_POINT(v)   BF_CS1(USDHC_PROT_CTRL, RD_WAIT_POINT, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field WECINT
 *
 * Wakeup Event Enable On Card Interrupt:  This bit enables a wakeup event, via a Card Interrupt, in
 * the                                 Interrupt Status register. This bit can be set to 1 if FN_WUS
 * (Wake                                 Up Support) in CIS is set to 1. When this bit is set, the
 * Card                                 Interrupt Status and the uSDHC interrupt can be asserted
 * without                                 SD_CLK toggling. When the wakeup feature is not enabled,
 * the SD_CLK                                 must be active in order to assert the Card Interrupt
 * Status and the                                 uSDHC interrupt.
 */

#define BP_USDHC_PROT_CTRL_WECINT      24
#define BM_USDHC_PROT_CTRL_WECINT      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_WECINT(v)   ((((reg32_t) v) << 24) & BM_USDHC_PROT_CTRL_WECINT)
#else
#define BF_USDHC_PROT_CTRL_WECINT(v)   (((v) << 24) & BM_USDHC_PROT_CTRL_WECINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_WECINT(v)   BF_CS1(USDHC_PROT_CTRL, WECINT, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field WECINS
 *
 * Wakeup Event Enable On SD Card Insertion:  This bit enables a wakeup event, via a Card Insertion,
 * in the                                 Interrupt Status register. FN_WUS (Wake Up Support) in CIS
 * does not                                 effect this bit. When this bit is set, the Card
 * Insertion Status and                                 the uSDHC interrupt can be asserted without
 * SD_CLK toggling. When                                 the wakeup feature is not enabled, the
 * SD_CLK must be active in                                 order to assert the Card Insertion
 * Status and the uSDHC                                 interrupt.
 */

#define BP_USDHC_PROT_CTRL_WECINS      25
#define BM_USDHC_PROT_CTRL_WECINS      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_WECINS(v)   ((((reg32_t) v) << 25) & BM_USDHC_PROT_CTRL_WECINS)
#else
#define BF_USDHC_PROT_CTRL_WECINS(v)   (((v) << 25) & BM_USDHC_PROT_CTRL_WECINS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_WECINS(v)   BF_CS1(USDHC_PROT_CTRL, WECINS, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field WECRM
 *
 * Wakeup Event Enable On SD Card Removal:  This bit enables a wakeup event, via a Card Removal, in
 * the Interrupt                                 Status register. FN_WUS (Wake Up Support) in CIS
 * does not effect                                 this bit. When this bit is set, the Card Removal
 * Status and the                                 uSDHC interrupt can be asserted without SD_CLK
 * toggling. When the                                 wakeup feature is not enabled, the SD_CLK must
 * be active in order to                                 assert the Card Removal Status and the
 * uSDHC interrupt.
 */

#define BP_USDHC_PROT_CTRL_WECRM      26
#define BM_USDHC_PROT_CTRL_WECRM      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_WECRM(v)   ((((reg32_t) v) << 26) & BM_USDHC_PROT_CTRL_WECRM)
#else
#define BF_USDHC_PROT_CTRL_WECRM(v)   (((v) << 26) & BM_USDHC_PROT_CTRL_WECRM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_WECRM(v)   BF_CS1(USDHC_PROT_CTRL, WECRM, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field BURST_LEN_EN
 *
 * BURST length enable for INCR, INCR4/INCR8/INCR16,
 * INCR4-WRAP/INCR8-WRAP/INCR16-WRAP  This is used to enable/disable the burst length for the
 * external                                 AHB2AXI bridge. It's useful especially for INCR transfer
 * because                                 without burst length indicator, the AHB2AXI bridge
 * doesn't know the                                 burst length in advance. Without burst length
 * indicator, AHB INCR                                 transfers can only be converted to SINGLEs in
 * AXI side.
 */

#define BP_USDHC_PROT_CTRL_BURST_LEN_EN      27
#define BM_USDHC_PROT_CTRL_BURST_LEN_EN      0x38000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_BURST_LEN_EN(v)   ((((reg32_t) v) << 27) & BM_USDHC_PROT_CTRL_BURST_LEN_EN)
#else
#define BF_USDHC_PROT_CTRL_BURST_LEN_EN(v)   (((v) << 27) & BM_USDHC_PROT_CTRL_BURST_LEN_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_BURST_LEN_EN(v)   BF_CS1(USDHC_PROT_CTRL, BURST_LEN_EN, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field NON_EXACT_BLK_RD
 *
 * Current block read is non-exact block read. It's only used for
 * SDIO.
 */

#define BP_USDHC_PROT_CTRL_NON_EXACT_BLK_RD      30
#define BM_USDHC_PROT_CTRL_NON_EXACT_BLK_RD      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_NON_EXACT_BLK_RD(v)   ((((reg32_t) v) << 30) & BM_USDHC_PROT_CTRL_NON_EXACT_BLK_RD)
#else
#define BF_USDHC_PROT_CTRL_NON_EXACT_BLK_RD(v)   (((v) << 30) & BM_USDHC_PROT_CTRL_NON_EXACT_BLK_RD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_NON_EXACT_BLK_RD(v)   BF_CS1(USDHC_PROT_CTRL, NON_EXACT_BLK_RD, v)
#endif

/* --- Register HW_USDHC_PROT_CTRL, field RD_NO8CLK_EN
 *
 * Only for debug.  enable S/W RD_DONE_NO_8CLK bit
 */

#define BP_USDHC_PROT_CTRL_RD_NO8CLK_EN      31
#define BM_USDHC_PROT_CTRL_RD_NO8CLK_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_PROT_CTRL_RD_NO8CLK_EN(v)   ((((reg32_t) v) << 31) & BM_USDHC_PROT_CTRL_RD_NO8CLK_EN)
#else
#define BF_USDHC_PROT_CTRL_RD_NO8CLK_EN(v)   (((v) << 31) & BM_USDHC_PROT_CTRL_RD_NO8CLK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_PROT_CTRL_RD_NO8CLK_EN(v)   BF_CS1(USDHC_PROT_CTRL, RD_NO8CLK_EN, v)
#endif

/*!
 * @brief HW_USDHC_SYS_CTRL - System Control
 *
 * .
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned IPGEN : 1; //!< IPG Clock Enable:  It's not implemented in uSDHC IP.
        unsigned HCKEN : 1; //!< HCLK Enable:  It's not implemented in uSDHC IP.
        unsigned PEREN : 1; //!< Perpherial Clock Enable  It's not implemented in uSDHC IP.
        unsigned SDCLKEN : 1; //!< SD Clock Enable  It's not implemented in uSDHC IP.
        unsigned DVS : 4; //!< Divisor:  This register is used to provide a more exact divisor to generate the desired SD clock frequency. Note the divider can even support odd divisor without deterioration of duty cycle.   Before changing clock divisor value(SDCLKFS or DVS), Host Driver should make sure the SDSTB bit is high.   The setting are as following:
        unsigned SDCLKFS : 8; //!< SDCLK Frequency Select:  This register is used to select the frequency of the SDCLK pin. The frequency is not programmed directly, rather this register holds the prescaler (this register) and divisor (next register) of the Base Clock Frequency register.   I  n Single Data Rate mode(DDR_EN bit of MIXERCTRL is '0')   Only the following settings are allowed:  80h) Base clock divided by 256  40h) Base clock divided by 128  20h) Base clock divided by 64  10h) Base clock divided by 32  08h) Base clock divided by 16  04h) Base clock divided by 8  02h) Base clock divided by 4  01h) Base clock divided by 2  00h) Base clock divided by 1   W  hile in Dual Data Rate mode(DDR_EN bit of MIXERCTRL is '1')    Only the following settings are allowed:    80h) Base clock divided by 512    40h) Base clock divided by 256    20h) Base clock divided by 128    10h) Base clock divided by 64    08h) Base clock divided by 32    04h) Base clock divided by 16    02h) Base clock divided by 8    01h) Base clock divided by 4    00h) Base clock divided by  2    W  hen S/W changes the DDR_EN bit, SDCLKFS may need to be changed also  !   In Single Data Rate mode, setting 00h bypasses the frequency prescaler of the SD Clock.  Multiple bits must not be set, or the behavior of this prescaler is undefined. The two default divider values can be calculated by the frequency of ipg_perclk and the following Divisor bits.  The frequency of SDCLK is set by the following formula:  Clock Frequency = (Base Clock) / (prescaler x divisor)  For example, in Single Data Rate mode, if the Base Clock Frequency is 96 MHz, and the target frequency is 25 MHz, then choosing the prescaler value of 01h and divisor value of 1h will yield 24 MHz, which is the nearest frequency less than or equal to the target. Similarly, to approach a clock value of 400 kHz, the prescaler value of 08h and divisor value of eh yields the exact clock value of 400 kHz.  The reset value of this bit field is 80h, so if the input Base Clock (ipg_perclk) is about 96 MHz, the default SD Clock after reset is 375 kHz.  According to the SD Physical Specification Version 1.1 and the SDIO Card Specification Version 1.2, the maximum SD Clock frequency is 50 MHz and shall never exceed this limit.   B  efore changing clock divisor value(SDCLKFS or DVS), Host Driver should make sure the SDSTB bit is high.    If setting SDCLKFS and DVS can generate same clock frequency,(For example, in SDR mode, SDCLKFS = 01h is same as DVS = 01h.) SDCLKFS is highly recommended.
        unsigned DTOCV : 4; //!< Data Timeout Counter Value:  This value determines the interval by which DAT line timeouts are detected. Refer to the Data Timeout Error bit in the Interrupt Status register for information on factors that dictate time-out generation. Time-out clock frequency will be generated by dividing the base clock SDCLK value by this value.  The Host Driver can clear the Data Timeout Error Status Enable (in the Interrupt Status Enable register) to prevent inadvertent time-out events.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned RST_FIFO : 1; //!< Reset the Async FIFO:  Reset the Async FIFO between card interface and the internal logic. It's only used for debugging. Software should not tough it.
        unsigned IPP_RST_N : 1; //!< This register's value will be output to CARD from pad directly for hardware reset of the card if card support this feature.
        unsigned RSTA : 1; //!< Software Reset For ALL:  This reset effects the entire Host Controller except for the card detection circuit. Register bits of type ROC, RW, RW1C, RWAC are cleared. During its initialization, the Host Driver shall set this bit to 1 to reset the uSDHC. The uSDHC shall reset this bit to 0 when the capabilities registers are valid and the Host Driver can read them. Additional use of Software Reset For All does not affect the value of the Capabilities registers. After this bit is set, it is recommended that the Host Driver reset the external card and re-initialize it.  In tuning process, after every CMD19 is finished,  this bit will be set to resett the uSDHC.
        unsigned RSTC : 1; //!< Software Reset For CMD Line:  Only part of the command circuit is reset.  The following registers and bits are cleared by this bit:   Present State register Command Inhibit (CMD)  Interrupt Status register Command Complete
        unsigned RSTD : 1; //!< Software Reset For DAT Line:  Only part of the data circuit is reset. DMA circuit is also reset.  The following registers and bits are cleared by this bit:   Data Port register  Buffer is cleared and initialized.Present State register  Buffer Read Enable  Buffer Write Enable  Read Transfer Active  Write Transfer Active  DAT Line Active  Command Inhibit (DAT) Protocol Control register  Continue Request  Stop At Block Gap Request Interrupt Status register  Buffer Read Ready  Buffer Write Ready  DMA Interrupt  Block Gap Event  Transfer Complete
        unsigned INITA : 1; //!< Initialization Active:  When this bit is set, 80 SD-Clocks are sent to the card. After the 80 clocks are sent, this bit is self cleared. This bit is very useful during the card power-up period when 74 SD-Clocks are needed and the clock auto gating feature is enabled. Writing 1 to this bit when this bit is already 1 has no effect. Writing 0 to this bit at any time has no effect. When either of the CIHB and CDIHB bits in the Present State Register are set, writing 1 to this bit is ignored (i.e. when command line or data lines are active, write to this bit is not allowed). On the otherhand, when this bit is set, i.e., during intialization active period, it is allowed to issue command, and the command bit stream will appear on the CMD pad after all 80 clock cycles are done. So when this command ends, the driver can make sure the 80 clock cycles are sent out. This is very useful when the driver needs send 80 cycles to the card and does not want to wait till this bit is self cleared.
        unsigned RESERVED1 : 4; //!< Reserved
    } B;
} hw_usdhc_sys_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_SYS_CTRL register
 */
#define HW_USDHC_SYS_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_SYS_CTRL(x)           (*(volatile hw_usdhc_sys_ctrl_t *) HW_USDHC_SYS_CTRL_ADDR(x))
#define HW_USDHC_SYS_CTRL_RD(x)        (HW_USDHC_SYS_CTRL(x).U)
#define HW_USDHC_SYS_CTRL_WR(x, v)     (HW_USDHC_SYS_CTRL(x).U = (v))
#define HW_USDHC_SYS_CTRL_SET(x, v)    (HW_USDHC_SYS_CTRL_WR(x, HW_USDHC_SYS_CTRL_RD(x) |  (v)))
#define HW_USDHC_SYS_CTRL_CLR(x, v)    (HW_USDHC_SYS_CTRL_WR(x, HW_USDHC_SYS_CTRL_RD(x) & ~(v)))
#define HW_USDHC_SYS_CTRL_TOG(x, v)    (HW_USDHC_SYS_CTRL_WR(x, HW_USDHC_SYS_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_SYS_CTRL bitfields
 */

/* --- Register HW_USDHC_SYS_CTRL, field IPGEN
 *
 * IPG Clock Enable:  It's not implemented in uSDHC IP.
 */

#define BP_USDHC_SYS_CTRL_IPGEN      0
#define BM_USDHC_SYS_CTRL_IPGEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_IPGEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_SYS_CTRL_IPGEN)
#else
#define BF_USDHC_SYS_CTRL_IPGEN(v)   (((v) << 0) & BM_USDHC_SYS_CTRL_IPGEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_IPGEN(v)   BF_CS1(USDHC_SYS_CTRL, IPGEN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field HCKEN
 *
 * HCLK Enable:  It's not implemented in uSDHC IP.
 */

#define BP_USDHC_SYS_CTRL_HCKEN      1
#define BM_USDHC_SYS_CTRL_HCKEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_HCKEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_SYS_CTRL_HCKEN)
#else
#define BF_USDHC_SYS_CTRL_HCKEN(v)   (((v) << 1) & BM_USDHC_SYS_CTRL_HCKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_HCKEN(v)   BF_CS1(USDHC_SYS_CTRL, HCKEN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field PEREN
 *
 * Perpherial Clock Enable  It's not implemented in uSDHC IP.
 */

#define BP_USDHC_SYS_CTRL_PEREN      2
#define BM_USDHC_SYS_CTRL_PEREN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_PEREN(v)   ((((reg32_t) v) << 2) & BM_USDHC_SYS_CTRL_PEREN)
#else
#define BF_USDHC_SYS_CTRL_PEREN(v)   (((v) << 2) & BM_USDHC_SYS_CTRL_PEREN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_PEREN(v)   BF_CS1(USDHC_SYS_CTRL, PEREN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field SDCLKEN
 *
 * SD Clock Enable  It's not implemented in uSDHC IP.
 */

#define BP_USDHC_SYS_CTRL_SDCLKEN      3
#define BM_USDHC_SYS_CTRL_SDCLKEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_SDCLKEN(v)   ((((reg32_t) v) << 3) & BM_USDHC_SYS_CTRL_SDCLKEN)
#else
#define BF_USDHC_SYS_CTRL_SDCLKEN(v)   (((v) << 3) & BM_USDHC_SYS_CTRL_SDCLKEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_SDCLKEN(v)   BF_CS1(USDHC_SYS_CTRL, SDCLKEN, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field DVS
 *
 * Divisor:  This register is used to provide a more exact divisor to generate the
 * desired SD clock frequency. Note the divider can even support odd
 * divisor without deterioration of duty cycle.   Before changing clock divisor value(SDCLKFS or
 * DVS), Host Driver                                     should make sure the SDSTB bit is high.
 * The setting are as following:
 */

#define BP_USDHC_SYS_CTRL_DVS      4
#define BM_USDHC_SYS_CTRL_DVS      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_DVS(v)   ((((reg32_t) v) << 4) & BM_USDHC_SYS_CTRL_DVS)
#else
#define BF_USDHC_SYS_CTRL_DVS(v)   (((v) << 4) & BM_USDHC_SYS_CTRL_DVS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_DVS(v)   BF_CS1(USDHC_SYS_CTRL, DVS, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field SDCLKFS
 *
 * SDCLK Frequency Select:  This register is used to select the frequency of the SDCLK pin. The
 * frequency is not programmed directly, rather this register holds the
 * prescaler (this register) and divisor (next register) of the Base
 * Clock Frequency register.   I  n Single Data Rate mode(DDR_EN bit of MIXERCTRL is '0')   Only the
 * following settings are allowed:  80h) Base clock divided by 256  40h) Base clock divided by 128
 * 20h) Base clock divided by 64  10h) Base clock divided by 32  08h) Base clock divided by 16  04h)
 * Base clock divided by 8  02h) Base clock divided by 4  01h) Base clock divided by 2  00h) Base
 * clock divided by 1   W  hile in Dual Data Rate mode(DDR_EN bit of MIXERCTRL is '1')    Only the
 * following settings are allowed:    80h) Base clock divided by 512    40h) Base clock divided by
 * 256    20h) Base clock divided by 128    10h) Base clock divided by 64    08h) Base clock divided
 * by 32    04h) Base clock divided by 16    02h) Base clock divided by 8    01h) Base clock divided
 * by 4    00h) Base clock divided by  2    W  hen S/W changes the DDR_EN bit, SDCLKFS may need to
 * be changed                                     also  !   In Single Data Rate mode, setting 00h
 * bypasses the frequency                                 prescaler of the SD Clock.  Multiple bits
 * must not be set, or the behavior of this prescaler is                                 undefined.
 * The two default divider values can be calculated by the                                 frequency
 * of ipg_perclk and the following Divisor bits.  The frequency of SDCLK is set by the following
 * formula:  Clock Frequency = (Base Clock) / (prescaler x divisor)  For example, in Single Data
 * Rate mode, if the Base Clock Frequency is                                 96 MHz, and the target
 * frequency is 25 MHz, then choosing the                                 prescaler value of 01h and
 * divisor value of 1h will yield 24 MHz,                                 which is the nearest
 * frequency less than or equal to the target.                                 Similarly, to
 * approach a clock value of 400 kHz, the prescaler value                                 of 08h and
 * divisor value of eh yields the exact clock value of 400                                 kHz.  The
 * reset value of this bit field is 80h, so if the input Base Clock
 * (ipg_perclk) is about 96 MHz, the default SD Clock after reset is
 * 375 kHz.  According to the SD Physical Specification Version 1.1 and the SDIO
 * Card Specification Version 1.2, the maximum SD Clock frequency is 50
 * MHz and shall never exceed this limit.   B  efore changing clock divisor value(SDCLKFS or DVS),
 * Host Driver                                     should make sure the SDSTB bit is high.    If
 * setting SDCLKFS and DVS can generate same clock frequency,(For
 * example, in SDR mode, SDCLKFS = 01h is same as DVS = 01h.)
 * SDCLKFS is highly recommended.
 */

#define BP_USDHC_SYS_CTRL_SDCLKFS      8
#define BM_USDHC_SYS_CTRL_SDCLKFS      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_SDCLKFS(v)   ((((reg32_t) v) << 8) & BM_USDHC_SYS_CTRL_SDCLKFS)
#else
#define BF_USDHC_SYS_CTRL_SDCLKFS(v)   (((v) << 8) & BM_USDHC_SYS_CTRL_SDCLKFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_SDCLKFS(v)   BF_CS1(USDHC_SYS_CTRL, SDCLKFS, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field DTOCV
 *
 * Data Timeout Counter Value:  This value determines the interval by which DAT line timeouts are
 * detected. Refer to the Data Timeout Error bit in the Interrupt
 * Status register for information on factors that dictate time-out
 * generation. Time-out clock frequency will be generated by dividing
 * the base clock SDCLK value by this value.  The Host Driver can clear the Data Timeout Error
 * Status Enable (in                                 the Interrupt Status Enable register) to
 * prevent inadvertent                                 time-out events.
 */

#define BP_USDHC_SYS_CTRL_DTOCV      16
#define BM_USDHC_SYS_CTRL_DTOCV      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_DTOCV(v)   ((((reg32_t) v) << 16) & BM_USDHC_SYS_CTRL_DTOCV)
#else
#define BF_USDHC_SYS_CTRL_DTOCV(v)   (((v) << 16) & BM_USDHC_SYS_CTRL_DTOCV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_DTOCV(v)   BF_CS1(USDHC_SYS_CTRL, DTOCV, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RST_FIFO
 *
 * Reset the Async FIFO:  Reset the Async FIFO between card interface and the internal logic.
 * It's only used for debugging. Software should not tough it.
 */

#define BP_USDHC_SYS_CTRL_RST_FIFO      22
#define BM_USDHC_SYS_CTRL_RST_FIFO      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RST_FIFO(v)   ((((reg32_t) v) << 22) & BM_USDHC_SYS_CTRL_RST_FIFO)
#else
#define BF_USDHC_SYS_CTRL_RST_FIFO(v)   (((v) << 22) & BM_USDHC_SYS_CTRL_RST_FIFO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RST_FIFO(v)   BF_CS1(USDHC_SYS_CTRL, RST_FIFO, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field IPP_RST_N
 *
 * This register's value will be output to CARD from pad directly for
 * hardware reset of the card if card support this feature.
 */

#define BP_USDHC_SYS_CTRL_IPP_RST_N      23
#define BM_USDHC_SYS_CTRL_IPP_RST_N      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_IPP_RST_N(v)   ((((reg32_t) v) << 23) & BM_USDHC_SYS_CTRL_IPP_RST_N)
#else
#define BF_USDHC_SYS_CTRL_IPP_RST_N(v)   (((v) << 23) & BM_USDHC_SYS_CTRL_IPP_RST_N)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_IPP_RST_N(v)   BF_CS1(USDHC_SYS_CTRL, IPP_RST_N, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RSTA
 *
 * Software Reset For ALL:  This reset effects the entire Host Controller except for the card
 * detection circuit. Register bits of type ROC, RW, RW1C, RWAC are
 * cleared. During its initialization, the Host Driver shall set this
 * bit to 1 to reset the uSDHC. The uSDHC shall reset this bit to 0
 * when the capabilities registers are valid and the Host Driver can
 * read them. Additional use of Software Reset For All does not affect
 * the value of the Capabilities registers. After this bit is set, it
 * is recommended that the Host Driver reset the external card and
 * re-initialize it.  In tuning process, after every CMD19 is finished,  this bit will be set to
 * resett the uSDHC.
 */

#define BP_USDHC_SYS_CTRL_RSTA      24
#define BM_USDHC_SYS_CTRL_RSTA      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RSTA(v)   ((((reg32_t) v) << 24) & BM_USDHC_SYS_CTRL_RSTA)
#else
#define BF_USDHC_SYS_CTRL_RSTA(v)   (((v) << 24) & BM_USDHC_SYS_CTRL_RSTA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RSTA(v)   BF_CS1(USDHC_SYS_CTRL, RSTA, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RSTC
 *
 * Software Reset For CMD Line:  Only part of the command circuit is reset.  The following registers
 * and bits are cleared by this bit:   Present State register Command Inhibit (CMD)  Interrupt
 * Status register Command Complete
 */

#define BP_USDHC_SYS_CTRL_RSTC      25
#define BM_USDHC_SYS_CTRL_RSTC      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RSTC(v)   ((((reg32_t) v) << 25) & BM_USDHC_SYS_CTRL_RSTC)
#else
#define BF_USDHC_SYS_CTRL_RSTC(v)   (((v) << 25) & BM_USDHC_SYS_CTRL_RSTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RSTC(v)   BF_CS1(USDHC_SYS_CTRL, RSTC, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field RSTD
 *
 * Software Reset For DAT Line:  Only part of the data circuit is reset. DMA circuit is also reset.
 * The following registers and bits are cleared by this bit:   Data Port register  Buffer is cleared
 * and initialized.Present State register  Buffer Read Enable  Buffer Write Enable  Read Transfer
 * Active  Write Transfer Active  DAT Line Active  Command Inhibit (DAT) Protocol Control register
 * Continue Request  Stop At Block Gap Request Interrupt Status register  Buffer Read Ready  Buffer
 * Write Ready  DMA Interrupt  Block Gap Event  Transfer Complete
 */

#define BP_USDHC_SYS_CTRL_RSTD      26
#define BM_USDHC_SYS_CTRL_RSTD      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_RSTD(v)   ((((reg32_t) v) << 26) & BM_USDHC_SYS_CTRL_RSTD)
#else
#define BF_USDHC_SYS_CTRL_RSTD(v)   (((v) << 26) & BM_USDHC_SYS_CTRL_RSTD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_RSTD(v)   BF_CS1(USDHC_SYS_CTRL, RSTD, v)
#endif

/* --- Register HW_USDHC_SYS_CTRL, field INITA
 *
 * Initialization Active:  When this bit is set, 80 SD-Clocks are sent to the card. After the 80
 * clocks are sent, this bit is self cleared. This bit is very useful
 * during the card power-up period when 74 SD-Clocks are needed and the
 * clock auto gating feature is enabled. Writing 1 to this bit when
 * this bit is already 1 has no effect. Writing 0 to this bit at any
 * time has no effect. When either of the CIHB and CDIHB bits in the
 * Present State Register are set, writing 1 to this bit is ignored
 * (i.e. when command line or data lines are active, write to this bit
 * is not allowed). On the otherhand, when this bit is set, i.e.,
 * during intialization active period, it is allowed to issue command,
 * and the command bit stream will appear on the CMD pad after all 80
 * clock cycles are done. So when this command ends, the driver can
 * make sure the 80 clock cycles are sent out. This is very useful when
 * the driver needs send 80 cycles to the card and does not want to
 * wait till this bit is self cleared.
 */

#define BP_USDHC_SYS_CTRL_INITA      27
#define BM_USDHC_SYS_CTRL_INITA      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_SYS_CTRL_INITA(v)   ((((reg32_t) v) << 27) & BM_USDHC_SYS_CTRL_INITA)
#else
#define BF_USDHC_SYS_CTRL_INITA(v)   (((v) << 27) & BM_USDHC_SYS_CTRL_INITA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_SYS_CTRL_INITA(v)   BF_CS1(USDHC_SYS_CTRL, INITA, v)
#endif

/*!
 * @brief HW_USDHC_INT_STATUS - Interrupt Status
 *
 * An interrupt is generated when the Normal Interrupt Signal Enable is
 * enabled and at least one of the status bits is set to 1. For all bits,
 * writing 1 to a bit clears it; writing to 0 keeps the bit unchanged. More
 * than one status can be cleared with a single register write. For Card
 * Interrupt, before writing 1 to clear, it is required that the card stops
 * asserting the interrupt, meaning that when the Card Driver services the
 * interrupt condition, otherwise the CINT bit will be asserted again.  The table below shows the
 * relationship between the Command Timeout Error                             and the Command
 * Complete.   uSDHC Status for Command Timeout Error/Command Complete Bit
 * Combinations         Command Complete    Command Timeout Error    Meaning of the Status        0
 * 0    X      X    1    Response not received within 64
 * SDCLK cycles      1    0    Response received       The table below shows the relationship
 * between the Transfer Complete and                             the Data Timeout Error.   uSDHC
 * Status for Data Timeout Error/Transfer Complete Bit                                 Combinations
 * Transfer Complete    Data Timeout Error    Meaning of the Status        0    0    X      0    1
 * Timeout occurred during                                                 transfer      1    X
 * Data Transfer Complete       The table below shows the relationship between the Command CRC Error
 * and                             Command Timeout Error.   uSDHC Status for Command CRC
 * Error/Command Timeout Error Bit                                 Combinations         Command
 * Complete    Command Timeout Error    Meaning of the Status        0    0    No error      0    1
 * Response Timeout Error      1    0    Response CRC Error      1    1    CMD line conflict
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CC : 1; //!< Command Complete:  This bit is set when you receive the end bit of the command response (except Auto CMD12). Refer to the Command Inhibit (CMD) in the Present State register.  This bit will be not asserted in tuning process.
        unsigned TC : 1; //!< Transfer Complete:  This bit is set when a read or write transfer is completed.  In the case of a Read Transaction: This bit is set at the falling edge of the Read Transfer Active Status. There are two cases in which this interrupt is generated. The first is when a data transfer is completed as specified by the data length (after the last data has been read to the Host System). The second is when data has stopped at the block gap and completed the data transfer by setting the Stop At Block Gap Request bit in the Protocol Control register (after valid data has been read to the Host System).  In the case of a Write Transaction: This bit is set at the falling edge of the DAT Line Active Status. There are two cases in which this interrupt is generated. The first is when the last data is written to the SD card as specified by the data length and the busy signal is released. The second is when data transfers are stopped at the block gap, by setting the Stop At Block Gap Request bit in the Protocol Control register, and the data transfers are completed. (after valid data is written to the SD card and the busy signal released).  This bit will be not asserted in tuning process.
        unsigned BGE : 1; //!< Block Gap Event:  If the Stop At Block Gap Request bit in the Protocol Control register is set, this bit is set when a read or write transaction is stopped at a block gap. If Stop At Block Gap Request is not set to 1, this bit is not set to 1.  In the case of a Read Transaction: This bit is set at the falling edge of the DAT Line Active Status (When the transaction is stopped at SD Bus timing). The Read Wait must be supported in order to use this function.  In the case of Write Transaction: This bit is set at the falling edge of Write Transfer Active Status (After getting CRC status at SD Bus timing).
        unsigned DINT : 1; //!< DMA Interrupt:  Occurs only when the internal DMA finishes the data transfer successfully. Whenever errors occur during data transfer, this bit will not be set. Instead, the DMAE bit will be set. Either Simple DMA or ADMA finishes data transferring, this bit will be set.
        unsigned BWR : 1; //!< Buffer Write Ready:  This status bit is set if the Buffer Write Enable bit, in the Present State register, changes from 0 to 1. Refer to the Buffer Write Enable bit in the Present State register for additional information.
        unsigned BRR : 1; //!< Buffer Read Ready:  This status bit is set if the Buffer Read Enable bit, in the Present State register, changes from 0 to 1. Refer to the Buffer Read Enable bit in the Present State register for additional information.  This bit indicates that cmd19 is finished in tuning process.
        unsigned CINS : 1; //!< Card Insertion:  This status bit is set if the Card Inserted bit in the Present State register changes from 0 to 1. When the Host Driver writes this bit to 1 to clear this status, the status of the Card Inserted in the Present State register should be confirmed. Because the card state may possibly be changed when the Host Driver clears this bit and the interrupt event may not be generated. When this bit is cleared, it will be set again if a card is inserted. In order to leave it cleared, clear the Card Inserted Status Enable bit in Interrupt Status Enable register.
        unsigned CRM : 1; //!< Card Removal:  This status bit is set if the Card Inserted bit in the Present State register changes from 1 to 0. When the Host Driver writes this bit to 1 to clear this status, the status of the Card Inserted in the Present State register should be confirmed. Because the card state may possibly be changed when the Host Driver clears this bit and the interrupt event may not be generated. When this bit is cleared, it will be set again if no card is inserted. In order to leave it cleared, clear the Card Removal Status Enable bit in Interrupt Status Enable register.
        unsigned CINT : 1; //!< Card Interrupt:  This status bit is set when an interrupt signal is detected from the external card. In 1-bit mode, the uSDHC will detect the Card Interrupt without the SD Clock to support wakeup. In 4-bit mode, the card interrupt signal is sampled during the interrupt cycle, so the interrupt from card can only be sampled during interrupt cycle, introducing some delay between the interrupt signal from the SDIO card and the interrupt to the Host System. Writing this bit to 1 can clear this bit, but as the interrupt factor from the SDIO card does not clear, this bit is set again. In order to clear this bit, it is required to reset the interrupt factor from the external card followed by a writing 1 to this bit.   When this status has been set, and the Host Driver needs to service this interrupt, the Card Interrupt Signal Enable in the Interrupt Signal Enable register should be 0 to stop driving the interrupt signal to the Host System. After completion of the card interrupt service (It should reset the interrupt factors in the SDIO card and the interrupt signal may not be asserted), write 1 to clear this bit, set the Card Interrupt Signal Enable to 1, and start sampling the interrupt signal again.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RTE : 1; //!< Re-Tuning Event: (only for SD3.0 SDR104 mode)  This status is set if Re-Tuning Request in the Present State register changes from 0 to 1. Host Controller requests Host Driver to perform re-tuning for next data transfer. Current data transfer (not large block count) can be completed without re-tuning.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned TP : 1; //!< Tuning Pass:(only for SD3.0 SDR104 mode)  Current CMD19 transfer is done successfully. That is, current sampling point is correct.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned CTOE : 1; //!< Command Timeout Error:  Occurs only if no response is returned within 64 SDCLK cycles from the end bit of the command. If the uSDHC detects a CMD line conflict, in which case a Command CRC Error shall also be set (as shown in ), this bit shall be set without waiting for 64 SDCLK cycles. This is because the command will be aborted by the uSDHC.  This bit will be not asserted in tuning process.
        unsigned CCE : 1; //!< Command CRC Error:  Command CRC Error is generated in two cases.   If a response is returned and the Command Timeout Error is set to 0 (indicating no time-out), this bit is set when detecting a CRC error in the command response.  The uSDHC detects a CMD line conflict by monitoring the CMD line when a command is issued. If the uSDHC drives the CMD line to 1, but detects 0 on the CMD line at the next SDCLK edge, then the uSDHC shall abort the command (Stop driving CMD line) and set this bit to 1. The Command Timeout Error shall also be set to 1 to distinguish CMD line conflict.   This bit will be not asserted in tuning process.
        unsigned CEBE : 1; //!< Command End Bit Error:  Occurs when detecting that the end bit of a command response is 0.  This bit will be not asserted in tuning process.
        unsigned CIE : 1; //!< Command Index Error:  Occurs if a Command Index error occurs in the command response.  This bit will be not asserted in tuning process.
        unsigned DTOE : 1; //!< Data Timeout Error:  Occurs when detecting one of following time-out conditions.   Busy time-out for R1b,R5b type  Busy time-out after Write CRC status  Read Data time-out.   This bit will be not asserted in tuning process.
        unsigned DCE : 1; //!< Data CRC Error:  Occurs when detecting a CRC error when transferring read data, which uses the DAT line, or when detecting the Write CRC status having a value other than 010.  This bit will be not asserted in tuning process.
        unsigned DEBE : 1; //!< Data End Bit Error:  Occurs either when detecting 0 at the end bit position of read data, which uses the DAT line, or at the end bit position of the CRC.  This bit will be not asserted in tuning process.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned AC12E : 1; //!< Auto CMD12 Error:  Occurs when detecting that one of the bits in the Auto CMD12 Error Status register has changed from 0 to 1. This bit is set to 1, not only when the errors in Auto CMD12 occur, but also when the Auto CMD12 is not executed due to the previous command error.
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned TNE : 1; //!< Tuning Error: (only for SD3.0 SDR104 mode)  This bit is set when an unrecoverable error is detected in a tuning circuit. By detecting Tuning Error, Host Driver needs to abort a command executeing and perform tuning.
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned DMAE : 1; //!< DMA Error:  Occurs when an Internal DMA transfer has failed. This bit is set to 1, when some error occurs in the data transfer. This error can be caused by either Simple DMA or ADMA, depending on which DMA is in use. The value in DMA System Address register is the next fetch address where the error occurs. Since any error corrupts the whole data block, the Host Driver shall re-start the transfer from the corrupted block boundary. The address of the block boundary can be calculated either from the current DS_ADDR value or from the remaining number of blocks and the block size.
        unsigned RESERVED6 : 3; //!< Reserved
    } B;
} hw_usdhc_int_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_INT_STATUS register
 */
#define HW_USDHC_INT_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_INT_STATUS(x)           (*(volatile hw_usdhc_int_status_t *) HW_USDHC_INT_STATUS_ADDR(x))
#define HW_USDHC_INT_STATUS_RD(x)        (HW_USDHC_INT_STATUS(x).U)
#define HW_USDHC_INT_STATUS_WR(x, v)     (HW_USDHC_INT_STATUS(x).U = (v))
#define HW_USDHC_INT_STATUS_SET(x, v)    (HW_USDHC_INT_STATUS_WR(x, HW_USDHC_INT_STATUS_RD(x) |  (v)))
#define HW_USDHC_INT_STATUS_CLR(x, v)    (HW_USDHC_INT_STATUS_WR(x, HW_USDHC_INT_STATUS_RD(x) & ~(v)))
#define HW_USDHC_INT_STATUS_TOG(x, v)    (HW_USDHC_INT_STATUS_WR(x, HW_USDHC_INT_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_INT_STATUS bitfields
 */

/* --- Register HW_USDHC_INT_STATUS, field CC
 *
 * Command Complete:  This bit is set when you receive the end bit of the command response
 * (except Auto CMD12). Refer to the Command Inhibit (CMD) in the
 * Present State register.  This bit will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_CC      0
#define BM_USDHC_INT_STATUS_CC      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CC(v)   ((((reg32_t) v) << 0) & BM_USDHC_INT_STATUS_CC)
#else
#define BF_USDHC_INT_STATUS_CC(v)   (((v) << 0) & BM_USDHC_INT_STATUS_CC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CC(v)   BF_CS1(USDHC_INT_STATUS, CC, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field TC
 *
 * Transfer Complete:  This bit is set when a read or write transfer is completed.  In the case of a
 * Read Transaction: This bit is set at the falling                                 edge of the Read
 * Transfer Active Status. There are two cases in                                 which this
 * interrupt is generated. The first is when a data transfer                                 is
 * completed as specified by the data length (after the last data
 * has been read to the Host System). The second is when data has
 * stopped at the block gap and completed the data transfer by setting
 * the Stop At Block Gap Request bit in the Protocol Control register
 * (after valid data has been read to the Host System).  In the case of a Write Transaction: This
 * bit is set at the falling                                 edge of the DAT Line Active Status.
 * There are two cases in which                                 this interrupt is generated. The
 * first is when the last data is                                 written to the SD card as
 * specified by the data length and the busy                                 signal is released. The
 * second is when data transfers are stopped at                                 the block gap, by
 * setting the Stop At Block Gap Request bit in the                                 Protocol Control
 * register, and the data transfers are completed.                                 (after valid data
 * is written to the SD card and the busy signal                                 released).  This
 * bit will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_TC      1
#define BM_USDHC_INT_STATUS_TC      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_TC(v)   ((((reg32_t) v) << 1) & BM_USDHC_INT_STATUS_TC)
#else
#define BF_USDHC_INT_STATUS_TC(v)   (((v) << 1) & BM_USDHC_INT_STATUS_TC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_TC(v)   BF_CS1(USDHC_INT_STATUS, TC, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field BGE
 *
 * Block Gap Event:  If the Stop At Block Gap Request bit in the Protocol Control register
 * is set, this bit is set when a read or write transaction is stopped
 * at a block gap. If Stop At Block Gap Request is not set to 1, this
 * bit is not set to 1.  In the case of a Read Transaction: This bit is set at the falling
 * edge of the DAT Line Active Status (When the transaction is stopped
 * at SD Bus timing). The Read Wait must be supported in order to use
 * this function.  In the case of Write Transaction: This bit is set at the falling edge
 * of Write Transfer Active Status (After getting CRC status at SD Bus
 * timing).
 */

#define BP_USDHC_INT_STATUS_BGE      2
#define BM_USDHC_INT_STATUS_BGE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_BGE(v)   ((((reg32_t) v) << 2) & BM_USDHC_INT_STATUS_BGE)
#else
#define BF_USDHC_INT_STATUS_BGE(v)   (((v) << 2) & BM_USDHC_INT_STATUS_BGE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_BGE(v)   BF_CS1(USDHC_INT_STATUS, BGE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DINT
 *
 * DMA Interrupt:  Occurs only when the internal DMA finishes the data transfer
 * successfully. Whenever errors occur during data transfer, this bit
 * will not be set. Instead, the DMAE bit will be set. Either Simple
 * DMA or ADMA finishes data transferring, this bit will be set.
 */

#define BP_USDHC_INT_STATUS_DINT      3
#define BM_USDHC_INT_STATUS_DINT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DINT(v)   ((((reg32_t) v) << 3) & BM_USDHC_INT_STATUS_DINT)
#else
#define BF_USDHC_INT_STATUS_DINT(v)   (((v) << 3) & BM_USDHC_INT_STATUS_DINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DINT(v)   BF_CS1(USDHC_INT_STATUS, DINT, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field BWR
 *
 * Buffer Write Ready:  This status bit is set if the Buffer Write Enable bit, in the Present
 * State register, changes from 0 to 1. Refer to the Buffer Write
 * Enable bit in the Present State register for additional
 * information.
 */

#define BP_USDHC_INT_STATUS_BWR      4
#define BM_USDHC_INT_STATUS_BWR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_BWR(v)   ((((reg32_t) v) << 4) & BM_USDHC_INT_STATUS_BWR)
#else
#define BF_USDHC_INT_STATUS_BWR(v)   (((v) << 4) & BM_USDHC_INT_STATUS_BWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_BWR(v)   BF_CS1(USDHC_INT_STATUS, BWR, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field BRR
 *
 * Buffer Read Ready:  This status bit is set if the Buffer Read Enable bit, in the Present
 * State register, changes from 0 to 1. Refer to the Buffer Read Enable
 * bit in the Present State register for additional information.  This bit indicates that cmd19 is
 * finished in tuning process.
 */

#define BP_USDHC_INT_STATUS_BRR      5
#define BM_USDHC_INT_STATUS_BRR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_BRR(v)   ((((reg32_t) v) << 5) & BM_USDHC_INT_STATUS_BRR)
#else
#define BF_USDHC_INT_STATUS_BRR(v)   (((v) << 5) & BM_USDHC_INT_STATUS_BRR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_BRR(v)   BF_CS1(USDHC_INT_STATUS, BRR, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CINS
 *
 * Card Insertion:  This status bit is set if the Card Inserted bit in the Present State
 * register changes from 0 to 1. When the Host Driver writes this bit
 * to 1 to clear this status, the status of the Card Inserted in the
 * Present State register should be confirmed. Because the card state
 * may possibly be changed when the Host Driver clears this bit and the
 * interrupt event may not be generated. When this bit is cleared, it
 * will be set again if a card is inserted. In order to leave it
 * cleared, clear the Card Inserted Status Enable bit in Interrupt
 * Status Enable register.
 */

#define BP_USDHC_INT_STATUS_CINS      6
#define BM_USDHC_INT_STATUS_CINS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CINS(v)   ((((reg32_t) v) << 6) & BM_USDHC_INT_STATUS_CINS)
#else
#define BF_USDHC_INT_STATUS_CINS(v)   (((v) << 6) & BM_USDHC_INT_STATUS_CINS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CINS(v)   BF_CS1(USDHC_INT_STATUS, CINS, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CRM
 *
 * Card Removal:  This status bit is set if the Card Inserted bit in the Present State
 * register changes from 1 to 0. When the Host Driver writes this bit
 * to 1 to clear this status, the status of the Card Inserted in the
 * Present State register should be confirmed. Because the card state
 * may possibly be changed when the Host Driver clears this bit and the
 * interrupt event may not be generated. When this bit is cleared, it
 * will be set again if no card is inserted. In order to leave it
 * cleared, clear the Card Removal Status Enable bit in Interrupt
 * Status Enable register.
 */

#define BP_USDHC_INT_STATUS_CRM      7
#define BM_USDHC_INT_STATUS_CRM      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CRM(v)   ((((reg32_t) v) << 7) & BM_USDHC_INT_STATUS_CRM)
#else
#define BF_USDHC_INT_STATUS_CRM(v)   (((v) << 7) & BM_USDHC_INT_STATUS_CRM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CRM(v)   BF_CS1(USDHC_INT_STATUS, CRM, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CINT
 *
 * Card Interrupt:  This status bit is set when an interrupt signal is detected from the
 * external card. In 1-bit mode, the uSDHC will detect the Card
 * Interrupt without the SD Clock to support wakeup. In 4-bit mode, the
 * card interrupt signal is sampled during the interrupt cycle, so the
 * interrupt from card can only be sampled during interrupt cycle,
 * introducing some delay between the                                 interrupt signal from the SDIO
 * card and the interrupt to the Host                                 System. Writing this bit to 1
 * can clear this bit, but as the                                 interrupt factor from the SDIO
 * card does not clear, this bit is set                                 again. In order to clear
 * this bit, it is required to reset the                                 interrupt factor from the
 * external card followed by a writing 1 to                                 this bit.   When this
 * status has been set, and the Host Driver needs to service                                 this
 * interrupt, the Card Interrupt Signal Enable in the Interrupt
 * Signal Enable register should be 0 to stop driving the interrupt
 * signal to the Host System. After completion of the card interrupt
 * service (It should reset the interrupt factors in the SDIO card and
 * the interrupt signal may not be asserted), write 1 to clear this
 * bit, set the Card Interrupt Signal Enable to 1, and start sampling
 * the interrupt signal again.
 */

#define BP_USDHC_INT_STATUS_CINT      8
#define BM_USDHC_INT_STATUS_CINT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CINT(v)   ((((reg32_t) v) << 8) & BM_USDHC_INT_STATUS_CINT)
#else
#define BF_USDHC_INT_STATUS_CINT(v)   (((v) << 8) & BM_USDHC_INT_STATUS_CINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CINT(v)   BF_CS1(USDHC_INT_STATUS, CINT, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field RTE
 *
 * Re-Tuning Event: (only for SD3.0 SDR104 mode)  This status is set if Re-Tuning Request in the
 * Present State register                                 changes from 0 to 1. Host Controller
 * requests Host Driver to perform                                 re-tuning for next data transfer.
 * Current data transfer (not large                                 block count) can be completed
 * without re-tuning.
 */

#define BP_USDHC_INT_STATUS_RTE      12
#define BM_USDHC_INT_STATUS_RTE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_RTE(v)   ((((reg32_t) v) << 12) & BM_USDHC_INT_STATUS_RTE)
#else
#define BF_USDHC_INT_STATUS_RTE(v)   (((v) << 12) & BM_USDHC_INT_STATUS_RTE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_RTE(v)   BF_CS1(USDHC_INT_STATUS, RTE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field TP
 *
 * Tuning Pass:(only for SD3.0 SDR104 mode)  Current CMD19 transfer is done successfully. That is,
 * current                                 sampling point is correct.
 */

#define BP_USDHC_INT_STATUS_TP      14
#define BM_USDHC_INT_STATUS_TP      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_TP(v)   ((((reg32_t) v) << 14) & BM_USDHC_INT_STATUS_TP)
#else
#define BF_USDHC_INT_STATUS_TP(v)   (((v) << 14) & BM_USDHC_INT_STATUS_TP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_TP(v)   BF_CS1(USDHC_INT_STATUS, TP, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CTOE
 *
 * Command Timeout Error:  Occurs only if no response is returned within 64 SDCLK cycles from
 * the end bit of the command. If the uSDHC detects a CMD line
 * conflict, in which case a Command CRC Error shall also be set (as
 * shown in ), this bit                                 shall be set without waiting for 64 SDCLK
 * cycles. This is because                                 the command will be aborted by the uSDHC.
 * This bit will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_CTOE      16
#define BM_USDHC_INT_STATUS_CTOE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CTOE(v)   ((((reg32_t) v) << 16) & BM_USDHC_INT_STATUS_CTOE)
#else
#define BF_USDHC_INT_STATUS_CTOE(v)   (((v) << 16) & BM_USDHC_INT_STATUS_CTOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CTOE(v)   BF_CS1(USDHC_INT_STATUS, CTOE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CCE
 *
 * Command CRC Error:  Command CRC Error is generated in two cases.   If a response is returned and
 * the Command Timeout Error is set                                     to 0 (indicating no time-
 * out), this bit is set when detecting a                                     CRC error in the
 * command response.  The uSDHC detects a CMD line conflict by monitoring the CMD line
 * when a command is issued. If the uSDHC drives the CMD line to 1,
 * but detects 0 on the CMD line at the next SDCLK edge, then the
 * uSDHC shall abort the command (Stop driving CMD line) and set
 * this bit to 1. The Command Timeout Error shall also be set to 1
 * to distinguish CMD line conflict.   This bit will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_CCE      17
#define BM_USDHC_INT_STATUS_CCE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CCE(v)   ((((reg32_t) v) << 17) & BM_USDHC_INT_STATUS_CCE)
#else
#define BF_USDHC_INT_STATUS_CCE(v)   (((v) << 17) & BM_USDHC_INT_STATUS_CCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CCE(v)   BF_CS1(USDHC_INT_STATUS, CCE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CEBE
 *
 * Command End Bit Error:  Occurs when detecting that the end bit of a command response is
 * 0.  This bit will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_CEBE      18
#define BM_USDHC_INT_STATUS_CEBE      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CEBE(v)   ((((reg32_t) v) << 18) & BM_USDHC_INT_STATUS_CEBE)
#else
#define BF_USDHC_INT_STATUS_CEBE(v)   (((v) << 18) & BM_USDHC_INT_STATUS_CEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CEBE(v)   BF_CS1(USDHC_INT_STATUS, CEBE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field CIE
 *
 * Command Index Error:  Occurs if a Command Index error occurs in the command response.  This bit
 * will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_CIE      19
#define BM_USDHC_INT_STATUS_CIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_CIE(v)   ((((reg32_t) v) << 19) & BM_USDHC_INT_STATUS_CIE)
#else
#define BF_USDHC_INT_STATUS_CIE(v)   (((v) << 19) & BM_USDHC_INT_STATUS_CIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_CIE(v)   BF_CS1(USDHC_INT_STATUS, CIE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DTOE
 *
 * Data Timeout Error:  Occurs when detecting one of following time-out conditions.   Busy time-out
 * for R1b,R5b type  Busy time-out after Write CRC status  Read Data time-out.   This bit will be
 * not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_DTOE      20
#define BM_USDHC_INT_STATUS_DTOE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DTOE(v)   ((((reg32_t) v) << 20) & BM_USDHC_INT_STATUS_DTOE)
#else
#define BF_USDHC_INT_STATUS_DTOE(v)   (((v) << 20) & BM_USDHC_INT_STATUS_DTOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DTOE(v)   BF_CS1(USDHC_INT_STATUS, DTOE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DCE
 *
 * Data CRC Error:  Occurs when detecting a CRC error when transferring read data, which
 * uses the DAT line, or when detecting the Write CRC status having a
 * value other than 010.  This bit will be not asserted in tuning process.
 */

#define BP_USDHC_INT_STATUS_DCE      21
#define BM_USDHC_INT_STATUS_DCE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DCE(v)   ((((reg32_t) v) << 21) & BM_USDHC_INT_STATUS_DCE)
#else
#define BF_USDHC_INT_STATUS_DCE(v)   (((v) << 21) & BM_USDHC_INT_STATUS_DCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DCE(v)   BF_CS1(USDHC_INT_STATUS, DCE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DEBE
 *
 * Data End Bit Error:  Occurs either when detecting 0 at the end bit position of read data,
 * which uses the DAT line, or at the end bit position of the CRC.  This bit will be not asserted in
 * tuning process.
 */

#define BP_USDHC_INT_STATUS_DEBE      22
#define BM_USDHC_INT_STATUS_DEBE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DEBE(v)   ((((reg32_t) v) << 22) & BM_USDHC_INT_STATUS_DEBE)
#else
#define BF_USDHC_INT_STATUS_DEBE(v)   (((v) << 22) & BM_USDHC_INT_STATUS_DEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DEBE(v)   BF_CS1(USDHC_INT_STATUS, DEBE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field AC12E
 *
 * Auto CMD12 Error:  Occurs when detecting that one of the bits in the Auto CMD12 Error
 * Status register has changed from 0 to 1. This bit is set to 1, not
 * only when the errors in Auto CMD12 occur, but also when the Auto
 * CMD12 is not executed due to the previous command error.
 */

#define BP_USDHC_INT_STATUS_AC12E      24
#define BM_USDHC_INT_STATUS_AC12E      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_AC12E(v)   ((((reg32_t) v) << 24) & BM_USDHC_INT_STATUS_AC12E)
#else
#define BF_USDHC_INT_STATUS_AC12E(v)   (((v) << 24) & BM_USDHC_INT_STATUS_AC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_AC12E(v)   BF_CS1(USDHC_INT_STATUS, AC12E, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field TNE
 *
 * Tuning Error: (only for SD3.0 SDR104 mode)  This bit is set when an unrecoverable error is
 * detected in a tuning                                 circuit. By detecting Tuning Error, Host
 * Driver needs to abort a                                 command executeing and perform tuning.
 */

#define BP_USDHC_INT_STATUS_TNE      26
#define BM_USDHC_INT_STATUS_TNE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_TNE(v)   ((((reg32_t) v) << 26) & BM_USDHC_INT_STATUS_TNE)
#else
#define BF_USDHC_INT_STATUS_TNE(v)   (((v) << 26) & BM_USDHC_INT_STATUS_TNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_TNE(v)   BF_CS1(USDHC_INT_STATUS, TNE, v)
#endif

/* --- Register HW_USDHC_INT_STATUS, field DMAE
 *
 * DMA Error:  Occurs when an Internal DMA transfer has failed. This bit is set to
 * 1, when some error occurs in the data transfer. This error can be
 * caused by either Simple DMA or ADMA, depending on which DMA is in
 * use. The value in DMA System Address register is the next fetch
 * address where the error occurs. Since any error corrupts the whole
 * data block, the Host Driver shall re-start the transfer from the
 * corrupted block boundary. The address of the block boundary can be
 * calculated either from the current DS_ADDR value or from the
 * remaining number of blocks and the block size.
 */

#define BP_USDHC_INT_STATUS_DMAE      28
#define BM_USDHC_INT_STATUS_DMAE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_DMAE(v)   ((((reg32_t) v) << 28) & BM_USDHC_INT_STATUS_DMAE)
#else
#define BF_USDHC_INT_STATUS_DMAE(v)   (((v) << 28) & BM_USDHC_INT_STATUS_DMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_DMAE(v)   BF_CS1(USDHC_INT_STATUS, DMAE, v)
#endif

/*!
 * @brief HW_USDHC_INT_STATUS_EN - Interrupt Status Enable
 *
 * Setting the bits in this register to 1 enables the corresponding
 * Interrupt Status to be set by the specified event. If any bit is
 * cleared, the corresponding Interrupt Status bit is also cleared (i.e.
 * when the bit in this register is cleared, the corresponding bit in
 * Interrupt Status Register is always 0).   Depending on IABG bit setting, uSDHC may be programmed
 * to sample the                                 card interrupt signal during the interrupt period
 * and hold its value                                 in the flip-flop. There will be some delays on
 * the Card Interrupt,                                 asserted from the card, to the time the Host
 * System is informed.  To detect a CMD line conflict, the Host Driver must set both Command
 * Timeout Error Status Enable and Command CRC Error Status Enable to
 * 1.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCSEN : 1; //!< Command Complete Status Enable:  1 Enabled  0 Masked
        unsigned TCSEN : 1; //!< Transfer Complete Status Enable:
        unsigned BGESEN : 1; //!< Block Gap Event Status Enable:
        unsigned DINTSEN : 1; //!< DMA Interrupt Status Enable:
        unsigned BWRSEN : 1; //!< Buffer Write Ready Status Enable:
        unsigned BRRSEN : 1; //!< Buffer Read Ready Status Enable:
        unsigned CINSSEN : 1; //!< Card Insertion Status Enable:
        unsigned CRMSEN : 1; //!< Card Removal Status Enable:
        unsigned CINTSEN : 1; //!< Card Interrupt Status Enable:  If this bit is set to 0, the uSDHC will clear the interrupt request to the System. The Card Interrupt detection is stopped when this bit is cleared and restarted when this bit is set to 1. The Host Driver should clear the Card Interrupt Status Enable before servicing the Card Interrupt and should set this bit again after all interrupt requests from the card are cleared to prevent inadvertent interrupts.
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RTESEN : 1; //!< Re-Tuning Event Status Enable
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned TPSEN : 1; //!< Tuning Pass Status Enable
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned CTOESEN : 1; //!< Command Timeout Error Status Enable:
        unsigned CCESEN : 1; //!< Command CRC Error Status Enable:
        unsigned CEBESEN : 1; //!< Command End Bit Error Status Enable:
        unsigned CIESEN : 1; //!< Command Index Error Status Enable:
        unsigned DTOESEN : 1; //!< Data Timeout Error Status Enable:
        unsigned DCESEN : 1; //!< Data CRC Error Status Enable:
        unsigned DEBESEN : 1; //!< Data End Bit Error Status Enable:
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned AC12ESEN : 1; //!< Auto CMD12 Error Status Enable:
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned TNESEN : 1; //!< Tuning Error Status Enable:
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned DMAESEN : 1; //!< DMA Error Status Enable:
        unsigned RESERVED6 : 3; //!< Reserved
    } B;
} hw_usdhc_int_status_en_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_INT_STATUS_EN register
 */
#define HW_USDHC_INT_STATUS_EN_ADDR(x)      (REGS_USDHC_BASE(x) + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_INT_STATUS_EN(x)           (*(volatile hw_usdhc_int_status_en_t *) HW_USDHC_INT_STATUS_EN_ADDR(x))
#define HW_USDHC_INT_STATUS_EN_RD(x)        (HW_USDHC_INT_STATUS_EN(x).U)
#define HW_USDHC_INT_STATUS_EN_WR(x, v)     (HW_USDHC_INT_STATUS_EN(x).U = (v))
#define HW_USDHC_INT_STATUS_EN_SET(x, v)    (HW_USDHC_INT_STATUS_EN_WR(x, HW_USDHC_INT_STATUS_EN_RD(x) |  (v)))
#define HW_USDHC_INT_STATUS_EN_CLR(x, v)    (HW_USDHC_INT_STATUS_EN_WR(x, HW_USDHC_INT_STATUS_EN_RD(x) & ~(v)))
#define HW_USDHC_INT_STATUS_EN_TOG(x, v)    (HW_USDHC_INT_STATUS_EN_WR(x, HW_USDHC_INT_STATUS_EN_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_INT_STATUS_EN bitfields
 */

/* --- Register HW_USDHC_INT_STATUS_EN, field CCSEN
 *
 * Command Complete Status Enable:  1 Enabled  0 Masked
 */

#define BP_USDHC_INT_STATUS_EN_CCSEN      0
#define BM_USDHC_INT_STATUS_EN_CCSEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CCSEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_INT_STATUS_EN_CCSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CCSEN(v)   (((v) << 0) & BM_USDHC_INT_STATUS_EN_CCSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CCSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CCSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field TCSEN
 *
 * Transfer Complete Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_TCSEN      1
#define BM_USDHC_INT_STATUS_EN_TCSEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_TCSEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_INT_STATUS_EN_TCSEN)
#else
#define BF_USDHC_INT_STATUS_EN_TCSEN(v)   (((v) << 1) & BM_USDHC_INT_STATUS_EN_TCSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_TCSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, TCSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field BGESEN
 *
 * Block Gap Event Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_BGESEN      2
#define BM_USDHC_INT_STATUS_EN_BGESEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_BGESEN(v)   ((((reg32_t) v) << 2) & BM_USDHC_INT_STATUS_EN_BGESEN)
#else
#define BF_USDHC_INT_STATUS_EN_BGESEN(v)   (((v) << 2) & BM_USDHC_INT_STATUS_EN_BGESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_BGESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, BGESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DINTSEN
 *
 * DMA Interrupt Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_DINTSEN      3
#define BM_USDHC_INT_STATUS_EN_DINTSEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DINTSEN(v)   ((((reg32_t) v) << 3) & BM_USDHC_INT_STATUS_EN_DINTSEN)
#else
#define BF_USDHC_INT_STATUS_EN_DINTSEN(v)   (((v) << 3) & BM_USDHC_INT_STATUS_EN_DINTSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DINTSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DINTSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field BWRSEN
 *
 * Buffer Write Ready Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_BWRSEN      4
#define BM_USDHC_INT_STATUS_EN_BWRSEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_BWRSEN(v)   ((((reg32_t) v) << 4) & BM_USDHC_INT_STATUS_EN_BWRSEN)
#else
#define BF_USDHC_INT_STATUS_EN_BWRSEN(v)   (((v) << 4) & BM_USDHC_INT_STATUS_EN_BWRSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_BWRSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, BWRSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field BRRSEN
 *
 * Buffer Read Ready Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_BRRSEN      5
#define BM_USDHC_INT_STATUS_EN_BRRSEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_BRRSEN(v)   ((((reg32_t) v) << 5) & BM_USDHC_INT_STATUS_EN_BRRSEN)
#else
#define BF_USDHC_INT_STATUS_EN_BRRSEN(v)   (((v) << 5) & BM_USDHC_INT_STATUS_EN_BRRSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_BRRSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, BRRSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CINSSEN
 *
 * Card Insertion Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_CINSSEN      6
#define BM_USDHC_INT_STATUS_EN_CINSSEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CINSSEN(v)   ((((reg32_t) v) << 6) & BM_USDHC_INT_STATUS_EN_CINSSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CINSSEN(v)   (((v) << 6) & BM_USDHC_INT_STATUS_EN_CINSSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CINSSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CINSSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CRMSEN
 *
 * Card Removal Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_CRMSEN      7
#define BM_USDHC_INT_STATUS_EN_CRMSEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CRMSEN(v)   ((((reg32_t) v) << 7) & BM_USDHC_INT_STATUS_EN_CRMSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CRMSEN(v)   (((v) << 7) & BM_USDHC_INT_STATUS_EN_CRMSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CRMSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CRMSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CINTSEN
 *
 * Card Interrupt Status Enable:  If this bit is set to 0, the uSDHC will clear the interrupt
 * request                                 to the System. The Card Interrupt detection is stopped
 * when this bit                                 is cleared and restarted when this bit is set to 1.
 * The Host Driver                                 should clear the Card Interrupt Status Enable
 * before servicing the                                 Card Interrupt and should set this bit again
 * after all interrupt                                 requests from the card are cleared to prevent
 * inadvertent                                 interrupts.
 */

#define BP_USDHC_INT_STATUS_EN_CINTSEN      8
#define BM_USDHC_INT_STATUS_EN_CINTSEN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CINTSEN(v)   ((((reg32_t) v) << 8) & BM_USDHC_INT_STATUS_EN_CINTSEN)
#else
#define BF_USDHC_INT_STATUS_EN_CINTSEN(v)   (((v) << 8) & BM_USDHC_INT_STATUS_EN_CINTSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CINTSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CINTSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field RTESEN
 *
 * Re-Tuning Event Status Enable
 */

#define BP_USDHC_INT_STATUS_EN_RTESEN      12
#define BM_USDHC_INT_STATUS_EN_RTESEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_RTESEN(v)   ((((reg32_t) v) << 12) & BM_USDHC_INT_STATUS_EN_RTESEN)
#else
#define BF_USDHC_INT_STATUS_EN_RTESEN(v)   (((v) << 12) & BM_USDHC_INT_STATUS_EN_RTESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_RTESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, RTESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field TPSEN
 *
 * Tuning Pass Status Enable
 */

#define BP_USDHC_INT_STATUS_EN_TPSEN      14
#define BM_USDHC_INT_STATUS_EN_TPSEN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_TPSEN(v)   ((((reg32_t) v) << 14) & BM_USDHC_INT_STATUS_EN_TPSEN)
#else
#define BF_USDHC_INT_STATUS_EN_TPSEN(v)   (((v) << 14) & BM_USDHC_INT_STATUS_EN_TPSEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_TPSEN(v)   BF_CS1(USDHC_INT_STATUS_EN, TPSEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CTOESEN
 *
 * Command Timeout Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_CTOESEN      16
#define BM_USDHC_INT_STATUS_EN_CTOESEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CTOESEN(v)   ((((reg32_t) v) << 16) & BM_USDHC_INT_STATUS_EN_CTOESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CTOESEN(v)   (((v) << 16) & BM_USDHC_INT_STATUS_EN_CTOESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CTOESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CTOESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CCESEN
 *
 * Command CRC Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_CCESEN      17
#define BM_USDHC_INT_STATUS_EN_CCESEN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CCESEN(v)   ((((reg32_t) v) << 17) & BM_USDHC_INT_STATUS_EN_CCESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CCESEN(v)   (((v) << 17) & BM_USDHC_INT_STATUS_EN_CCESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CCESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CCESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CEBESEN
 *
 * Command End Bit Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_CEBESEN      18
#define BM_USDHC_INT_STATUS_EN_CEBESEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CEBESEN(v)   ((((reg32_t) v) << 18) & BM_USDHC_INT_STATUS_EN_CEBESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CEBESEN(v)   (((v) << 18) & BM_USDHC_INT_STATUS_EN_CEBESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CEBESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CEBESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field CIESEN
 *
 * Command Index Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_CIESEN      19
#define BM_USDHC_INT_STATUS_EN_CIESEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_CIESEN(v)   ((((reg32_t) v) << 19) & BM_USDHC_INT_STATUS_EN_CIESEN)
#else
#define BF_USDHC_INT_STATUS_EN_CIESEN(v)   (((v) << 19) & BM_USDHC_INT_STATUS_EN_CIESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_CIESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, CIESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DTOESEN
 *
 * Data Timeout Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_DTOESEN      20
#define BM_USDHC_INT_STATUS_EN_DTOESEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DTOESEN(v)   ((((reg32_t) v) << 20) & BM_USDHC_INT_STATUS_EN_DTOESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DTOESEN(v)   (((v) << 20) & BM_USDHC_INT_STATUS_EN_DTOESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DTOESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DTOESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DCESEN
 *
 * Data CRC Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_DCESEN      21
#define BM_USDHC_INT_STATUS_EN_DCESEN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DCESEN(v)   ((((reg32_t) v) << 21) & BM_USDHC_INT_STATUS_EN_DCESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DCESEN(v)   (((v) << 21) & BM_USDHC_INT_STATUS_EN_DCESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DCESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DCESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DEBESEN
 *
 * Data End Bit Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_DEBESEN      22
#define BM_USDHC_INT_STATUS_EN_DEBESEN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DEBESEN(v)   ((((reg32_t) v) << 22) & BM_USDHC_INT_STATUS_EN_DEBESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DEBESEN(v)   (((v) << 22) & BM_USDHC_INT_STATUS_EN_DEBESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DEBESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DEBESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field AC12ESEN
 *
 * Auto CMD12 Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_AC12ESEN      24
#define BM_USDHC_INT_STATUS_EN_AC12ESEN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_AC12ESEN(v)   ((((reg32_t) v) << 24) & BM_USDHC_INT_STATUS_EN_AC12ESEN)
#else
#define BF_USDHC_INT_STATUS_EN_AC12ESEN(v)   (((v) << 24) & BM_USDHC_INT_STATUS_EN_AC12ESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_AC12ESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, AC12ESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field TNESEN
 *
 * Tuning Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_TNESEN      26
#define BM_USDHC_INT_STATUS_EN_TNESEN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_TNESEN(v)   ((((reg32_t) v) << 26) & BM_USDHC_INT_STATUS_EN_TNESEN)
#else
#define BF_USDHC_INT_STATUS_EN_TNESEN(v)   (((v) << 26) & BM_USDHC_INT_STATUS_EN_TNESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_TNESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, TNESEN, v)
#endif

/* --- Register HW_USDHC_INT_STATUS_EN, field DMAESEN
 *
 * DMA Error Status Enable:
 */

#define BP_USDHC_INT_STATUS_EN_DMAESEN      28
#define BM_USDHC_INT_STATUS_EN_DMAESEN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_STATUS_EN_DMAESEN(v)   ((((reg32_t) v) << 28) & BM_USDHC_INT_STATUS_EN_DMAESEN)
#else
#define BF_USDHC_INT_STATUS_EN_DMAESEN(v)   (((v) << 28) & BM_USDHC_INT_STATUS_EN_DMAESEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_STATUS_EN_DMAESEN(v)   BF_CS1(USDHC_INT_STATUS_EN, DMAESEN, v)
#endif

/*!
 * @brief HW_USDHC_INT_SIGNAL_EN - Interrupt Signal Enable
 *
 * This register is used to select which interrupt status is indicated to
 * the Host System as the interrupt. These status bits all share the same
 * interrupt line. Setting any of these bits to 1 enables interrupt
 * generation. The corresponding Status register bit will generate an
 * interrupt when the corresponding interrupt signal enable bit is set.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCIEN : 1; //!< Command Complete Interrupt Enable:
        unsigned TCIEN : 1; //!< Transfer Complete Interrupt Enable:
        unsigned BGEIEN : 1; //!< Block Gap Event Interrupt Enable:
        unsigned DINTIEN : 1; //!< DMA Interrupt Enable:
        unsigned BWRIEN : 1; //!< Buffer Write Ready Interrupt Enable:
        unsigned BRRIEN : 1; //!< Buffer Read Ready Interrupt Enable:
        unsigned CINSIEN : 1; //!< Card Insertion Interrupt Enable:
        unsigned CRMIEN : 1; //!< Card Removal Interrupt Enable:
        unsigned CINTIEN : 1; //!< Card Interrupt Interrupt Enable:
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned RTEIEN : 1; //!< Re-Tuning Event Interrupt Enable
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned TPIEN : 1; //!< Tuning Pass Interrupt Enable
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned CTOEIEN : 1; //!< Command Timeout Error Interrupt Enable
        unsigned CCEIEN : 1; //!< Command CRC Error Interrupt Enable:
        unsigned CEBEIEN : 1; //!< Command End Bit Error Interrupt Enable:
        unsigned CIEIEN : 1; //!< Command Index Error Interrupt Enable:
        unsigned DTOEIEN : 1; //!< Data Timeout Error Interrupt Enable:
        unsigned DCEIEN : 1; //!< Data CRC Error Interrupt Enable:
        unsigned DEBEIEN : 1; //!< Data End Bit Error Interrupt Enable:
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned AC12EIEN : 1; //!< Auto CMD12 Error Interrupt Enable:
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned TNEIEN : 1; //!< Tuning Error Interrupt Enable
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned DMAEIEN : 1; //!< DMA Error Interrupt Enable:
        unsigned RESERVED6 : 3; //!< Reserved
    } B;
} hw_usdhc_int_signal_en_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_INT_SIGNAL_EN register
 */
#define HW_USDHC_INT_SIGNAL_EN_ADDR(x)      (REGS_USDHC_BASE(x) + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_INT_SIGNAL_EN(x)           (*(volatile hw_usdhc_int_signal_en_t *) HW_USDHC_INT_SIGNAL_EN_ADDR(x))
#define HW_USDHC_INT_SIGNAL_EN_RD(x)        (HW_USDHC_INT_SIGNAL_EN(x).U)
#define HW_USDHC_INT_SIGNAL_EN_WR(x, v)     (HW_USDHC_INT_SIGNAL_EN(x).U = (v))
#define HW_USDHC_INT_SIGNAL_EN_SET(x, v)    (HW_USDHC_INT_SIGNAL_EN_WR(x, HW_USDHC_INT_SIGNAL_EN_RD(x) |  (v)))
#define HW_USDHC_INT_SIGNAL_EN_CLR(x, v)    (HW_USDHC_INT_SIGNAL_EN_WR(x, HW_USDHC_INT_SIGNAL_EN_RD(x) & ~(v)))
#define HW_USDHC_INT_SIGNAL_EN_TOG(x, v)    (HW_USDHC_INT_SIGNAL_EN_WR(x, HW_USDHC_INT_SIGNAL_EN_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_INT_SIGNAL_EN bitfields
 */

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CCIEN
 *
 * Command Complete Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CCIEN      0
#define BM_USDHC_INT_SIGNAL_EN_CCIEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CCIEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_INT_SIGNAL_EN_CCIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CCIEN(v)   (((v) << 0) & BM_USDHC_INT_SIGNAL_EN_CCIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CCIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CCIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field TCIEN
 *
 * Transfer Complete Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_TCIEN      1
#define BM_USDHC_INT_SIGNAL_EN_TCIEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_TCIEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_INT_SIGNAL_EN_TCIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_TCIEN(v)   (((v) << 1) & BM_USDHC_INT_SIGNAL_EN_TCIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_TCIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, TCIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field BGEIEN
 *
 * Block Gap Event Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_BGEIEN      2
#define BM_USDHC_INT_SIGNAL_EN_BGEIEN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_BGEIEN(v)   ((((reg32_t) v) << 2) & BM_USDHC_INT_SIGNAL_EN_BGEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_BGEIEN(v)   (((v) << 2) & BM_USDHC_INT_SIGNAL_EN_BGEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_BGEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, BGEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DINTIEN
 *
 * DMA Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_DINTIEN      3
#define BM_USDHC_INT_SIGNAL_EN_DINTIEN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DINTIEN(v)   ((((reg32_t) v) << 3) & BM_USDHC_INT_SIGNAL_EN_DINTIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DINTIEN(v)   (((v) << 3) & BM_USDHC_INT_SIGNAL_EN_DINTIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DINTIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DINTIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field BWRIEN
 *
 * Buffer Write Ready Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_BWRIEN      4
#define BM_USDHC_INT_SIGNAL_EN_BWRIEN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_BWRIEN(v)   ((((reg32_t) v) << 4) & BM_USDHC_INT_SIGNAL_EN_BWRIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_BWRIEN(v)   (((v) << 4) & BM_USDHC_INT_SIGNAL_EN_BWRIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_BWRIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, BWRIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field BRRIEN
 *
 * Buffer Read Ready Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_BRRIEN      5
#define BM_USDHC_INT_SIGNAL_EN_BRRIEN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_BRRIEN(v)   ((((reg32_t) v) << 5) & BM_USDHC_INT_SIGNAL_EN_BRRIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_BRRIEN(v)   (((v) << 5) & BM_USDHC_INT_SIGNAL_EN_BRRIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_BRRIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, BRRIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CINSIEN
 *
 * Card Insertion Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CINSIEN      6
#define BM_USDHC_INT_SIGNAL_EN_CINSIEN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CINSIEN(v)   ((((reg32_t) v) << 6) & BM_USDHC_INT_SIGNAL_EN_CINSIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CINSIEN(v)   (((v) << 6) & BM_USDHC_INT_SIGNAL_EN_CINSIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CINSIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CINSIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CRMIEN
 *
 * Card Removal Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CRMIEN      7
#define BM_USDHC_INT_SIGNAL_EN_CRMIEN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CRMIEN(v)   ((((reg32_t) v) << 7) & BM_USDHC_INT_SIGNAL_EN_CRMIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CRMIEN(v)   (((v) << 7) & BM_USDHC_INT_SIGNAL_EN_CRMIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CRMIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CRMIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CINTIEN
 *
 * Card Interrupt Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CINTIEN      8
#define BM_USDHC_INT_SIGNAL_EN_CINTIEN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CINTIEN(v)   ((((reg32_t) v) << 8) & BM_USDHC_INT_SIGNAL_EN_CINTIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CINTIEN(v)   (((v) << 8) & BM_USDHC_INT_SIGNAL_EN_CINTIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CINTIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CINTIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field RTEIEN
 *
 * Re-Tuning Event Interrupt Enable
 */

#define BP_USDHC_INT_SIGNAL_EN_RTEIEN      12
#define BM_USDHC_INT_SIGNAL_EN_RTEIEN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_RTEIEN(v)   ((((reg32_t) v) << 12) & BM_USDHC_INT_SIGNAL_EN_RTEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_RTEIEN(v)   (((v) << 12) & BM_USDHC_INT_SIGNAL_EN_RTEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_RTEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, RTEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field TPIEN
 *
 * Tuning Pass Interrupt Enable
 */

#define BP_USDHC_INT_SIGNAL_EN_TPIEN      14
#define BM_USDHC_INT_SIGNAL_EN_TPIEN      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_TPIEN(v)   ((((reg32_t) v) << 14) & BM_USDHC_INT_SIGNAL_EN_TPIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_TPIEN(v)   (((v) << 14) & BM_USDHC_INT_SIGNAL_EN_TPIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_TPIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, TPIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CTOEIEN
 *
 * Command Timeout Error Interrupt Enable
 */

#define BP_USDHC_INT_SIGNAL_EN_CTOEIEN      16
#define BM_USDHC_INT_SIGNAL_EN_CTOEIEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CTOEIEN(v)   ((((reg32_t) v) << 16) & BM_USDHC_INT_SIGNAL_EN_CTOEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CTOEIEN(v)   (((v) << 16) & BM_USDHC_INT_SIGNAL_EN_CTOEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CTOEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CTOEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CCEIEN
 *
 * Command CRC Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CCEIEN      17
#define BM_USDHC_INT_SIGNAL_EN_CCEIEN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CCEIEN(v)   ((((reg32_t) v) << 17) & BM_USDHC_INT_SIGNAL_EN_CCEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CCEIEN(v)   (((v) << 17) & BM_USDHC_INT_SIGNAL_EN_CCEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CCEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CCEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CEBEIEN
 *
 * Command End Bit Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CEBEIEN      18
#define BM_USDHC_INT_SIGNAL_EN_CEBEIEN      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CEBEIEN(v)   ((((reg32_t) v) << 18) & BM_USDHC_INT_SIGNAL_EN_CEBEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CEBEIEN(v)   (((v) << 18) & BM_USDHC_INT_SIGNAL_EN_CEBEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CEBEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CEBEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field CIEIEN
 *
 * Command Index Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_CIEIEN      19
#define BM_USDHC_INT_SIGNAL_EN_CIEIEN      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_CIEIEN(v)   ((((reg32_t) v) << 19) & BM_USDHC_INT_SIGNAL_EN_CIEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_CIEIEN(v)   (((v) << 19) & BM_USDHC_INT_SIGNAL_EN_CIEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_CIEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, CIEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DTOEIEN
 *
 * Data Timeout Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_DTOEIEN      20
#define BM_USDHC_INT_SIGNAL_EN_DTOEIEN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DTOEIEN(v)   ((((reg32_t) v) << 20) & BM_USDHC_INT_SIGNAL_EN_DTOEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DTOEIEN(v)   (((v) << 20) & BM_USDHC_INT_SIGNAL_EN_DTOEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DTOEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DTOEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DCEIEN
 *
 * Data CRC Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_DCEIEN      21
#define BM_USDHC_INT_SIGNAL_EN_DCEIEN      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DCEIEN(v)   ((((reg32_t) v) << 21) & BM_USDHC_INT_SIGNAL_EN_DCEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DCEIEN(v)   (((v) << 21) & BM_USDHC_INT_SIGNAL_EN_DCEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DCEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DCEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DEBEIEN
 *
 * Data End Bit Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_DEBEIEN      22
#define BM_USDHC_INT_SIGNAL_EN_DEBEIEN      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DEBEIEN(v)   ((((reg32_t) v) << 22) & BM_USDHC_INT_SIGNAL_EN_DEBEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DEBEIEN(v)   (((v) << 22) & BM_USDHC_INT_SIGNAL_EN_DEBEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DEBEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DEBEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field AC12EIEN
 *
 * Auto CMD12 Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_AC12EIEN      24
#define BM_USDHC_INT_SIGNAL_EN_AC12EIEN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_AC12EIEN(v)   ((((reg32_t) v) << 24) & BM_USDHC_INT_SIGNAL_EN_AC12EIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_AC12EIEN(v)   (((v) << 24) & BM_USDHC_INT_SIGNAL_EN_AC12EIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_AC12EIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, AC12EIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field TNEIEN
 *
 * Tuning Error Interrupt Enable
 */

#define BP_USDHC_INT_SIGNAL_EN_TNEIEN      26
#define BM_USDHC_INT_SIGNAL_EN_TNEIEN      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_TNEIEN(v)   ((((reg32_t) v) << 26) & BM_USDHC_INT_SIGNAL_EN_TNEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_TNEIEN(v)   (((v) << 26) & BM_USDHC_INT_SIGNAL_EN_TNEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_TNEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, TNEIEN, v)
#endif

/* --- Register HW_USDHC_INT_SIGNAL_EN, field DMAEIEN
 *
 * DMA Error Interrupt Enable:
 */

#define BP_USDHC_INT_SIGNAL_EN_DMAEIEN      28
#define BM_USDHC_INT_SIGNAL_EN_DMAEIEN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_INT_SIGNAL_EN_DMAEIEN(v)   ((((reg32_t) v) << 28) & BM_USDHC_INT_SIGNAL_EN_DMAEIEN)
#else
#define BF_USDHC_INT_SIGNAL_EN_DMAEIEN(v)   (((v) << 28) & BM_USDHC_INT_SIGNAL_EN_DMAEIEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_INT_SIGNAL_EN_DMAEIEN(v)   BF_CS1(USDHC_INT_SIGNAL_EN, DMAEIEN, v)
#endif

/*!
 * @brief HW_USDHC_AUTOCMD12_ERR_STATUS - Auto CMD12 Error Status
 *
 * When the Auto CMD12 Error Status bit in the Status register is set, the
 * Host Driver shall check this register to identify what kind of error the
 * Auto CMD12 indicated. This register is valid only when the Auto CMD12
 * Error status bit is set.  The table bwlow shows the relationship between the Auto CMGD12 CRC
 * Error                             and the Auto CMD12 Command Timeout Error.   Relationship
 * Between Command CRC Error and Command Timeout Error                                 for Auto
 * CMD12         Auto CMD12 CRC Error    Auto CMD12 Timeout
 * Error    Type of Error        0    0    No Error      0    1    Response Timeout Error      1
 * 0    Response CRC Error      1    1    CMD line conflict       Changes in Auto CMD12 Error Status
 * register can be classified in three                             scenarios:   When the uSDHC is
 * going to issue an Auto CMD12.  Set bit 0 to 1 if the Auto CMD12 can't be issued due to an
 * error in the previous command  Set bit 0 to 0 if the Auto CMD12 is issued    At the end bit of an
 * Auto CMD12 response.  Check errors correspond to bits 1-4.  Set bits 1-4 corresponding to
 * detected errors.  Clear bits 1-4 corresponding to detected errors    Before reading the Auto
 * CMD12 Error Status bit 7.  Set bit 7 to 1 if there is a command that can't be issued  Clear bit 7
 * if there is no command to issue     The timing for generating the Auto CMD12 Error and writing to
 * the Command                             register are asynchronous. After that, bit 7 shall be
 * sampled when the                             driver is not writing to the Command register. So it
 * is suggested to                             read this register only when the AC12E bit in
 * Interrupt Status register                             is set. An Auto CMD12 Error Interrupt is
 * generated when one of the error                             bits (0-4) is set to 1. The Command
 * Not Issued By Auto CMD12 Error does                             not generate an interrupt.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned AC12NE : 1; //!< Auto CMD12 Not Executed:  If memory multiple block data transfer is not started, due to a command error, this bit is not set because it is not necessary to issue an Auto CMD12. Setting this bit to 1 means the uSDHC cannot issue the Auto CMD12 to stop a memory multiple block data transfer due to some error. If this bit is set to 1, other error status bits (1-4) have no meaning.
        unsigned AC12TOE : 1; //!< Auto CMD12 Timeout Error:  Occurs if no response is returned within 64 SDCLK cycles from the end bit of the command. If this bit is set to1, the other error status bits (2-4) have no meaning.
        unsigned AC12EBE : 1; //!< Auto CMD12 End Bit Error:  Occurs when detecting that the end bit of command response is 0 which should be 1.
        unsigned AC12CE : 1; //!< Auto CMD12 CRC Error:  Occurs when detecting a CRC error in the command response.
        unsigned AC12IE : 1; //!< Auto CMD12 Index Error:  Occurs if the Command Index error occurs in response to a command.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned CNIBAC12E : 1; //!< Command Not Issued By Auto CMD12 Error:  Setting this bit to 1 means CMD_wo_DAT is not executed due to an Auto CMD12 Error (D04-D01) in this register.
        unsigned RESERVED1 : 24; //!< Reserved
    } B;
} hw_usdhc_autocmd12_err_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_AUTOCMD12_ERR_STATUS register
 */
#define HW_USDHC_AUTOCMD12_ERR_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_AUTOCMD12_ERR_STATUS(x)           (*(volatile hw_usdhc_autocmd12_err_status_t *) HW_USDHC_AUTOCMD12_ERR_STATUS_ADDR(x))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x)        (HW_USDHC_AUTOCMD12_ERR_STATUS(x).U)
#define HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, v)     (HW_USDHC_AUTOCMD12_ERR_STATUS(x).U = (v))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_SET(x, v)    (HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x) |  (v)))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_CLR(x, v)    (HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x) & ~(v)))
#define HW_USDHC_AUTOCMD12_ERR_STATUS_TOG(x, v)    (HW_USDHC_AUTOCMD12_ERR_STATUS_WR(x, HW_USDHC_AUTOCMD12_ERR_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_AUTOCMD12_ERR_STATUS bitfields
 */

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12NE
 *
 * Auto CMD12 Not Executed:  If memory multiple block data transfer is not started, due to a
 * command error, this bit is not set because it is not necessary to
 * issue an Auto CMD12. Setting this bit to 1 means the uSDHC cannot
 * issue the Auto CMD12 to stop a memory multiple block data transfer
 * due to some error. If this bit is set to 1, other error status bits
 * (1-4) have no meaning.
 */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12NE      0
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12NE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12NE(v)   ((((reg32_t) v) << 0) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12NE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12NE(v)   (((v) << 0) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12NE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12NE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12NE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12TOE
 *
 * Auto CMD12 Timeout Error:  Occurs if no response is returned within 64 SDCLK cycles from the end
 * bit of the command. If this bit is set to1, the other error status
 * bits (2-4) have no meaning.
 */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE      1
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(v)   ((((reg32_t) v) << 1) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(v)   (((v) << 1) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12TOE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12EBE
 *
 * Auto CMD12 End Bit Error:  Occurs when detecting that the end bit of command response is 0 which
 * should be 1.
 */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE      2
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(v)   ((((reg32_t) v) << 2) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(v)   (((v) << 2) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12EBE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12CE
 *
 * Auto CMD12 CRC Error:  Occurs when detecting a CRC error in the command response.
 */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12CE      3
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12CE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12CE(v)   ((((reg32_t) v) << 3) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12CE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12CE(v)   (((v) << 3) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12CE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12CE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12CE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field AC12IE
 *
 * Auto CMD12 Index Error:  Occurs if the Command Index error occurs in response to a
 * command.
 */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_AC12IE      4
#define BM_USDHC_AUTOCMD12_ERR_STATUS_AC12IE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12IE(v)   ((((reg32_t) v) << 4) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12IE)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_AC12IE(v)   (((v) << 4) & BM_USDHC_AUTOCMD12_ERR_STATUS_AC12IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_AC12IE(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, AC12IE, v)
#endif

/* --- Register HW_USDHC_AUTOCMD12_ERR_STATUS, field CNIBAC12E
 *
 * Command Not Issued By Auto CMD12 Error:  Setting this bit to 1 means CMD_wo_DAT is not executed
 * due to an Auto                                 CMD12 Error (D04-D01) in this register.
 */

#define BP_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E      7
#define BM_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(v)   ((((reg32_t) v) << 7) & BM_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E)
#else
#define BF_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(v)   (((v) << 7) & BM_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(v)   BF_CS1(USDHC_AUTOCMD12_ERR_STATUS, CNIBAC12E, v)
#endif

/*!
 * @brief HW_USDHC_HOST_CTRL_CAP - Host Controller Capabilities
 *
 * This register provides the Host Driver with information specific to the
 * uSDHC implementation. The value in this register is the power-on-reset
 * value, and does not change with a software reset. Any write to this
 * register is ignored.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned MBL : 3; //!< Max Block Length:  This value indicates the maximum block size that the Host Driver can read and write to the buffer in the uSDHC. The buffer shall transfer block size without wait cycles.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ADMAS : 1; //!< ADMA Support:  This bit indicates whether the uSDHC supports the ADMA feature.
        unsigned HSS : 1; //!< High Speed Support:  This bit indicates whether the uSDHC supports High Speed mode and the Host System can supply a SD Clock frequency from 25 MHz to 50 MHz.
        unsigned DMAS : 1; //!< DMA Support:  This bit indicates whether the uSDHC is capable of using the internal DMA to transfer data between system memory and the data buffer directly.
        unsigned SRS : 1; //!< Suspend / Resume Support:  This bit indicates whether the uSDHC supports Suspend / Resume functionality. If this bit is 0, the Suspend and Resume mechanism, as well as the Read Wait, are not supported, and the Host Driver shall not issue either Suspend or Resume commands.
        unsigned VS33 : 1; //!< Voltage Support 3.3V:  This bit shall depend on the Host System ability.
        unsigned VS30 : 1; //!< Voltage Support 3.0V:  This bit shall depend on the Host System ability.
        unsigned VS18 : 1; //!< Voltage Support 1.8V:  This bit shall depend on the Host System ability.
        unsigned RESERVED2 : 5; //!< Reserved
    } B;
} hw_usdhc_host_ctrl_cap_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_HOST_CTRL_CAP register
 */
#define HW_USDHC_HOST_CTRL_CAP_ADDR(x)      (REGS_USDHC_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_HOST_CTRL_CAP(x)           (*(volatile hw_usdhc_host_ctrl_cap_t *) HW_USDHC_HOST_CTRL_CAP_ADDR(x))
#define HW_USDHC_HOST_CTRL_CAP_RD(x)        (HW_USDHC_HOST_CTRL_CAP(x).U)
#define HW_USDHC_HOST_CTRL_CAP_WR(x, v)     (HW_USDHC_HOST_CTRL_CAP(x).U = (v))
#define HW_USDHC_HOST_CTRL_CAP_SET(x, v)    (HW_USDHC_HOST_CTRL_CAP_WR(x, HW_USDHC_HOST_CTRL_CAP_RD(x) |  (v)))
#define HW_USDHC_HOST_CTRL_CAP_CLR(x, v)    (HW_USDHC_HOST_CTRL_CAP_WR(x, HW_USDHC_HOST_CTRL_CAP_RD(x) & ~(v)))
#define HW_USDHC_HOST_CTRL_CAP_TOG(x, v)    (HW_USDHC_HOST_CTRL_CAP_WR(x, HW_USDHC_HOST_CTRL_CAP_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_HOST_CTRL_CAP bitfields
 */

/* --- Register HW_USDHC_HOST_CTRL_CAP, field MBL
 *
 * Max Block Length:  This value indicates the maximum block size that the Host Driver can
 * read and write to the buffer in the uSDHC. The buffer shall transfer
 * block size without wait cycles.
 */

#define BP_USDHC_HOST_CTRL_CAP_MBL      16
#define BM_USDHC_HOST_CTRL_CAP_MBL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_MBL(v)   ((((reg32_t) v) << 16) & BM_USDHC_HOST_CTRL_CAP_MBL)
#else
#define BF_USDHC_HOST_CTRL_CAP_MBL(v)   (((v) << 16) & BM_USDHC_HOST_CTRL_CAP_MBL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_MBL(v)   BF_CS1(USDHC_HOST_CTRL_CAP, MBL, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field ADMAS
 *
 * ADMA Support:  This bit indicates whether the uSDHC supports the ADMA feature.
 */

#define BP_USDHC_HOST_CTRL_CAP_ADMAS      20
#define BM_USDHC_HOST_CTRL_CAP_ADMAS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_ADMAS(v)   ((((reg32_t) v) << 20) & BM_USDHC_HOST_CTRL_CAP_ADMAS)
#else
#define BF_USDHC_HOST_CTRL_CAP_ADMAS(v)   (((v) << 20) & BM_USDHC_HOST_CTRL_CAP_ADMAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_ADMAS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, ADMAS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field HSS
 *
 * High Speed Support:  This bit indicates whether the uSDHC supports High Speed mode and the
 * Host System can supply a SD Clock frequency from 25 MHz to 50
 * MHz.
 */

#define BP_USDHC_HOST_CTRL_CAP_HSS      21
#define BM_USDHC_HOST_CTRL_CAP_HSS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_HSS(v)   ((((reg32_t) v) << 21) & BM_USDHC_HOST_CTRL_CAP_HSS)
#else
#define BF_USDHC_HOST_CTRL_CAP_HSS(v)   (((v) << 21) & BM_USDHC_HOST_CTRL_CAP_HSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_HSS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, HSS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field DMAS
 *
 * DMA Support:  This bit indicates whether the uSDHC is capable of using the internal
 * DMA to transfer data between system memory and the data buffer
 * directly.
 */

#define BP_USDHC_HOST_CTRL_CAP_DMAS      22
#define BM_USDHC_HOST_CTRL_CAP_DMAS      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_DMAS(v)   ((((reg32_t) v) << 22) & BM_USDHC_HOST_CTRL_CAP_DMAS)
#else
#define BF_USDHC_HOST_CTRL_CAP_DMAS(v)   (((v) << 22) & BM_USDHC_HOST_CTRL_CAP_DMAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_DMAS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, DMAS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field SRS
 *
 * Suspend / Resume Support:  This bit indicates whether the uSDHC supports Suspend / Resume
 * functionality. If this bit is 0, the Suspend and Resume mechanism,
 * as well as the Read Wait, are not supported, and the Host Driver
 * shall not issue either Suspend or Resume commands.
 */

#define BP_USDHC_HOST_CTRL_CAP_SRS      23
#define BM_USDHC_HOST_CTRL_CAP_SRS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_SRS(v)   ((((reg32_t) v) << 23) & BM_USDHC_HOST_CTRL_CAP_SRS)
#else
#define BF_USDHC_HOST_CTRL_CAP_SRS(v)   (((v) << 23) & BM_USDHC_HOST_CTRL_CAP_SRS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_SRS(v)   BF_CS1(USDHC_HOST_CTRL_CAP, SRS, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field VS33
 *
 * Voltage Support 3.3V:  This bit shall depend on the Host System ability.
 */

#define BP_USDHC_HOST_CTRL_CAP_VS33      24
#define BM_USDHC_HOST_CTRL_CAP_VS33      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_VS33(v)   ((((reg32_t) v) << 24) & BM_USDHC_HOST_CTRL_CAP_VS33)
#else
#define BF_USDHC_HOST_CTRL_CAP_VS33(v)   (((v) << 24) & BM_USDHC_HOST_CTRL_CAP_VS33)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_VS33(v)   BF_CS1(USDHC_HOST_CTRL_CAP, VS33, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field VS30
 *
 * Voltage Support 3.0V:  This bit shall depend on the Host System ability.
 */

#define BP_USDHC_HOST_CTRL_CAP_VS30      25
#define BM_USDHC_HOST_CTRL_CAP_VS30      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_VS30(v)   ((((reg32_t) v) << 25) & BM_USDHC_HOST_CTRL_CAP_VS30)
#else
#define BF_USDHC_HOST_CTRL_CAP_VS30(v)   (((v) << 25) & BM_USDHC_HOST_CTRL_CAP_VS30)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_VS30(v)   BF_CS1(USDHC_HOST_CTRL_CAP, VS30, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_CAP, field VS18
 *
 * Voltage Support 1.8V:  This bit shall depend on the Host System ability.
 */

#define BP_USDHC_HOST_CTRL_CAP_VS18      26
#define BM_USDHC_HOST_CTRL_CAP_VS18      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_CAP_VS18(v)   ((((reg32_t) v) << 26) & BM_USDHC_HOST_CTRL_CAP_VS18)
#else
#define BF_USDHC_HOST_CTRL_CAP_VS18(v)   (((v) << 26) & BM_USDHC_HOST_CTRL_CAP_VS18)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_CAP_VS18(v)   BF_CS1(USDHC_HOST_CTRL_CAP, VS18, v)
#endif

/*!
 * @brief HW_USDHC_WTMK_LVL - Watermark Level
 *
 * Both write and read watermark levels (FIFO threshold) are configurable.
 * There value can range from 1 to 128 words. Both write and read burst
 * lengths are also Configurable. There value can range from 1 to 31
 * words.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_WML : 8; //!< Read Watermark Level:  The number of words used as the watermark level (FIFO threshold) in a DMA read operation. Also the number of words as a sequence of read bursts in back-to-back mode. The maximum legal value for the read water mark level is 128.
        unsigned RD_BRST_LEN : 5; //!< Read Burst Length:  Due to system restriction, the actual burst length may not exceed 16.    The number of words the uSDHC reads in a single burst. The read burst length must be less than or equal to the read watermark level, and all bursts within a watermark level transfer will be in back-to-back mode. On reset, this field will be 8. Writing 0 to this field will result in '01000' (i.e. it is not able to clear this field).
        unsigned RESERVED0 : 3; //!< Reserved
        unsigned WR_WML : 8; //!< Write Watermark Level:  The number of words used as the watermark level (FIFO threshold) in a DMA write operation. Also the number of words as a sequence of write bursts in back-to-back mode. The maximum legal value for the write watermark level is 128.
        unsigned WR_BRST_LEN : 5; //!< Write Burst Length:  Due to system restriction, the actual burst length may not exceed 16.    The number of words the uSDHC writes in a single burst. The write burst length must be less than or equal to the write watermark level, and all bursts within a watermark level transfer will be in back-to-back mode. On reset, this field will be 8. Writing 0 to this field will result in '01000' (i.e. it is not able to clear this field).
        unsigned RESERVED1 : 3; //!< Reserved
    } B;
} hw_usdhc_wtmk_lvl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_WTMK_LVL register
 */
#define HW_USDHC_WTMK_LVL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_WTMK_LVL(x)           (*(volatile hw_usdhc_wtmk_lvl_t *) HW_USDHC_WTMK_LVL_ADDR(x))
#define HW_USDHC_WTMK_LVL_RD(x)        (HW_USDHC_WTMK_LVL(x).U)
#define HW_USDHC_WTMK_LVL_WR(x, v)     (HW_USDHC_WTMK_LVL(x).U = (v))
#define HW_USDHC_WTMK_LVL_SET(x, v)    (HW_USDHC_WTMK_LVL_WR(x, HW_USDHC_WTMK_LVL_RD(x) |  (v)))
#define HW_USDHC_WTMK_LVL_CLR(x, v)    (HW_USDHC_WTMK_LVL_WR(x, HW_USDHC_WTMK_LVL_RD(x) & ~(v)))
#define HW_USDHC_WTMK_LVL_TOG(x, v)    (HW_USDHC_WTMK_LVL_WR(x, HW_USDHC_WTMK_LVL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_WTMK_LVL bitfields
 */

/* --- Register HW_USDHC_WTMK_LVL, field RD_WML
 *
 * Read Watermark Level:  The number of words used as the watermark level (FIFO threshold) in a
 * DMA read operation. Also the number of words as a sequence of read
 * bursts in back-to-back mode. The maximum legal value for the read
 * water mark level is 128.
 */

#define BP_USDHC_WTMK_LVL_RD_WML      0
#define BM_USDHC_WTMK_LVL_RD_WML      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_RD_WML(v)   ((((reg32_t) v) << 0) & BM_USDHC_WTMK_LVL_RD_WML)
#else
#define BF_USDHC_WTMK_LVL_RD_WML(v)   (((v) << 0) & BM_USDHC_WTMK_LVL_RD_WML)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_RD_WML(v)   BF_CS1(USDHC_WTMK_LVL, RD_WML, v)
#endif

/* --- Register HW_USDHC_WTMK_LVL, field RD_BRST_LEN
 *
 * Read Burst Length:  Due to system restriction, the                                         actual
 * burst length may not exceed 16.    The number of words the uSDHC reads in a single burst. The
 * read burst                                 length must be less than or equal to the read
 * watermark level, and                                 all bursts within a watermark level transfer
 * will be in back-to-back                                 mode. On reset, this field will be 8.
 * Writing 0 to this field will                                 result in '01000' (i.e. it is not
 * able to clear this field).
 */

#define BP_USDHC_WTMK_LVL_RD_BRST_LEN      8
#define BM_USDHC_WTMK_LVL_RD_BRST_LEN      0x00001f00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_RD_BRST_LEN(v)   ((((reg32_t) v) << 8) & BM_USDHC_WTMK_LVL_RD_BRST_LEN)
#else
#define BF_USDHC_WTMK_LVL_RD_BRST_LEN(v)   (((v) << 8) & BM_USDHC_WTMK_LVL_RD_BRST_LEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_RD_BRST_LEN(v)   BF_CS1(USDHC_WTMK_LVL, RD_BRST_LEN, v)
#endif

/* --- Register HW_USDHC_WTMK_LVL, field WR_WML
 *
 * Write Watermark Level:  The number of words used as the watermark level (FIFO threshold) in a
 * DMA write operation. Also the number of words as a sequence of write
 * bursts in back-to-back mode. The maximum legal value for the write
 * watermark level is 128.
 */

#define BP_USDHC_WTMK_LVL_WR_WML      16
#define BM_USDHC_WTMK_LVL_WR_WML      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_WR_WML(v)   ((((reg32_t) v) << 16) & BM_USDHC_WTMK_LVL_WR_WML)
#else
#define BF_USDHC_WTMK_LVL_WR_WML(v)   (((v) << 16) & BM_USDHC_WTMK_LVL_WR_WML)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_WR_WML(v)   BF_CS1(USDHC_WTMK_LVL, WR_WML, v)
#endif

/* --- Register HW_USDHC_WTMK_LVL, field WR_BRST_LEN
 *
 * Write Burst Length:  Due to system restriction, the
 * actual burst length may not exceed 16.    The number of words the uSDHC writes in a single burst.
 * The write                                 burst length must be less than or equal to the write
 * watermark                                 level, and all bursts within a watermark level transfer
 * will be in                                 back-to-back mode. On reset, this field will be 8.
 * Writing 0 to this                                 field will result in '01000' (i.e. it is not
 * able to clear this                                 field).
 */

#define BP_USDHC_WTMK_LVL_WR_BRST_LEN      24
#define BM_USDHC_WTMK_LVL_WR_BRST_LEN      0x1f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_WTMK_LVL_WR_BRST_LEN(v)   ((((reg32_t) v) << 24) & BM_USDHC_WTMK_LVL_WR_BRST_LEN)
#else
#define BF_USDHC_WTMK_LVL_WR_BRST_LEN(v)   (((v) << 24) & BM_USDHC_WTMK_LVL_WR_BRST_LEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_WTMK_LVL_WR_BRST_LEN(v)   BF_CS1(USDHC_WTMK_LVL, WR_BRST_LEN, v)
#endif

/*!
 * @brief HW_USDHC_MIX_CTRL - Mixer Control
 *
 * This register is used to DMA and data transfer. To prevent data loss, The
 * software should be check if data transfer is active before write this
 * register. Olny data transfer is invalid there can be write. These bits
 * are DPSEL, MBSEL, DTDSEL, AC12EN, BCEN and DMAEN.   Transfer Type Register Setting for Various
 * Transfer Types          Multi/Single Block                                             Select
 * Block Count Enable    Block Count    Function        0    Don't Care    Don't Care    Single
 * Transfer      1    0    Don't Care    Infinite Transfer      1    1    Positive Number
 * Multiple Transfer      1    1    Zero    No Data Transfer
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DMAEN : 1; //!< DMA Enable:  This bit enables DMA functionality. If this bit is set to 1, a DMA operation shall begin when the Host Driver sets the DPSEL bit of this register. Whether the Simple DMA, or the Advanced DMA, is active depends on the DMA Select field of the Protocol Control register.
        unsigned BCEN : 1; //!< Block Count Enable:  This bit is used to enable the Block Count register, which is only relevant for multiple block transfers. When this bit is 0, the internal counter for block is disabled, which is useful in executing an infinite transfer.
        unsigned AC12EN : 1; //!< Auto CMD12 Enable:  Multiple block transfers for memory require a CMD12 to stop the transaction. When this bit is set to 1, the uSDHC will issue a CMD12 automatically when the last block transfer has completed. The Host Driver shall not set this bit to issue commands that do not require CMD12 to stop a multiple block data transfer. In particular, secure commands defined in File Security Specification (see reference list) do not require CMD12. In single block transfer, the uSDHC will ignore this bit no matter if it is set or not.
        unsigned DDR_EN : 1; //!< Dual Data Rate mode selection
        unsigned DTDSEL : 1; //!< Data Transfer Direction Select:  This bit defines the direction of DAT line data transfers. The bit is set to 1 by the Host Driver to transfer data from the SD card to the uSDHC and is set to 0 for all other commands.
        unsigned MSBSEL : 1; //!< Multi / Single Block Select:  This bit enables multiple block DAT line data transfers. For any other commands, this bit shall be set to 0. If this bit is 0, it is not necessary to set the Block Count register. (Refer to ).
        unsigned NIBBLE_POS : 1; //!< In DDR 4 bit mode nibble position indictation. 0- the sequence is 'odd high nibble -> even high nibble -> odd low nibble -> even low nibble'; 1- the sequence is 'odd high nibble -> odd low nibble -> even high nibble -> even low nibble'.
        unsigned AC23EN : 1; //!< Auto CMD23 Enable  When this bit is set to 1, the Host Controller issues a CMD23 automatically before issuing a command specified in the Command Register.
        unsigned RESERVED0 : 14; //!< Reserved
        unsigned EXE_TUNE : 1; //!< Execute Tuning: (Only used for SD3.0, SDR104 mode)  This bit is set to 1 to indicate the Host Driver is starting tuning procedure. Tuning procedure is aborted by writing 0.  When std_tuning_en is 0, this bit is set to 1 to indicate the Host Driver is starting tuning procedure. Tuning procedure is aborted by writing 0.
        unsigned SMP_CLK_SEL : 1; //!< Tuned clock or Fixed clock is used to sample data/cmd (Only used for SD3.0, SDR104 mode)  When std_tuning_en is 0, this bit is used to select Tuned clock or Fixed clock to sample data/cmd (Only used for SD3.0, SDR104 mode)
        unsigned AUTO_TUNE_EN : 1; //!< Auto tuning enable (Only used for SD3.0, SDR104 mode)
        unsigned FBCLK_SEL : 1; //!< Feedback clock source selection (Only used for SD3.0, SDR104 mode)
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned AC12_RD_POINT : 1; //!< Only for debug.  It's used to control when to send Auto CMD12 after multi-block read.  1 send Auto CMD12 8 cycles after CRC is checked successfully  0 send Auto CMD12 right after CRC is checked successfully
        unsigned CMD_DMY_WAIT_CFG : 1; //!< Only for debug.  It's also used to control the number of dummy clock cycles after each command when CMD_DMY_EN bit is enabled.  CMD_DMY_EN = 0, CMD_DMY_WAIT_CFG = x : 12 dummy clocks after each command  CMD_DMY_EN = 1, CMD_DMY_WAIT_CFG = 0: 20 dummy clocks after each command  CMD_DMY_EN = 1, CMD_DMY_WAIT_CFG = 1: 31 dummy clocks after each command
        unsigned CMD_DMY_EN : 1; //!< Only for debug.  It's used to control the number of dummy clock cycles after each command.
    } B;
} hw_usdhc_mix_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_MIX_CTRL register
 */
#define HW_USDHC_MIX_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_MIX_CTRL(x)           (*(volatile hw_usdhc_mix_ctrl_t *) HW_USDHC_MIX_CTRL_ADDR(x))
#define HW_USDHC_MIX_CTRL_RD(x)        (HW_USDHC_MIX_CTRL(x).U)
#define HW_USDHC_MIX_CTRL_WR(x, v)     (HW_USDHC_MIX_CTRL(x).U = (v))
#define HW_USDHC_MIX_CTRL_SET(x, v)    (HW_USDHC_MIX_CTRL_WR(x, HW_USDHC_MIX_CTRL_RD(x) |  (v)))
#define HW_USDHC_MIX_CTRL_CLR(x, v)    (HW_USDHC_MIX_CTRL_WR(x, HW_USDHC_MIX_CTRL_RD(x) & ~(v)))
#define HW_USDHC_MIX_CTRL_TOG(x, v)    (HW_USDHC_MIX_CTRL_WR(x, HW_USDHC_MIX_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_MIX_CTRL bitfields
 */

/* --- Register HW_USDHC_MIX_CTRL, field DMAEN
 *
 * DMA Enable:  This bit enables DMA functionality. If this bit is set to 1, a DMA
 * operation shall begin when the Host Driver sets the DPSEL bit of
 * this register. Whether the Simple DMA, or the Advanced DMA, is
 * active depends on the DMA Select field of the Protocol Control
 * register.
 */

#define BP_USDHC_MIX_CTRL_DMAEN      0
#define BM_USDHC_MIX_CTRL_DMAEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_DMAEN(v)   ((((reg32_t) v) << 0) & BM_USDHC_MIX_CTRL_DMAEN)
#else
#define BF_USDHC_MIX_CTRL_DMAEN(v)   (((v) << 0) & BM_USDHC_MIX_CTRL_DMAEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_DMAEN(v)   BF_CS1(USDHC_MIX_CTRL, DMAEN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field BCEN
 *
 * Block Count Enable:  This bit is used to enable the Block Count register, which is only
 * relevant for multiple block transfers. When this bit is 0, the
 * internal counter for block is disabled, which is useful in executing
 * an infinite transfer.
 */

#define BP_USDHC_MIX_CTRL_BCEN      1
#define BM_USDHC_MIX_CTRL_BCEN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_BCEN(v)   ((((reg32_t) v) << 1) & BM_USDHC_MIX_CTRL_BCEN)
#else
#define BF_USDHC_MIX_CTRL_BCEN(v)   (((v) << 1) & BM_USDHC_MIX_CTRL_BCEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_BCEN(v)   BF_CS1(USDHC_MIX_CTRL, BCEN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AC12EN
 *
 * Auto CMD12 Enable:  Multiple block transfers for memory require a CMD12 to stop the
 * transaction. When this bit is set to 1, the uSDHC will issue a CMD12
 * automatically when the last block transfer has completed. The Host
 * Driver shall not set this bit to issue commands that do not require
 * CMD12 to stop a multiple block data transfer. In particular, secure
 * commands defined in File Security Specification (see reference list)
 * do not require CMD12. In single block transfer, the uSDHC will
 * ignore this bit no matter if it is set or not.
 */

#define BP_USDHC_MIX_CTRL_AC12EN      2
#define BM_USDHC_MIX_CTRL_AC12EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AC12EN(v)   ((((reg32_t) v) << 2) & BM_USDHC_MIX_CTRL_AC12EN)
#else
#define BF_USDHC_MIX_CTRL_AC12EN(v)   (((v) << 2) & BM_USDHC_MIX_CTRL_AC12EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AC12EN(v)   BF_CS1(USDHC_MIX_CTRL, AC12EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field DDR_EN
 *
 * Dual Data Rate mode selection
 */

#define BP_USDHC_MIX_CTRL_DDR_EN      3
#define BM_USDHC_MIX_CTRL_DDR_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_DDR_EN(v)   ((((reg32_t) v) << 3) & BM_USDHC_MIX_CTRL_DDR_EN)
#else
#define BF_USDHC_MIX_CTRL_DDR_EN(v)   (((v) << 3) & BM_USDHC_MIX_CTRL_DDR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_DDR_EN(v)   BF_CS1(USDHC_MIX_CTRL, DDR_EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field DTDSEL
 *
 * Data Transfer Direction Select:  This bit defines the direction of DAT line data transfers. The
 * bit is                                 set to 1 by the Host Driver to transfer data from the SD
 * card to the                                 uSDHC and is set to 0 for all other commands.
 */

#define BP_USDHC_MIX_CTRL_DTDSEL      4
#define BM_USDHC_MIX_CTRL_DTDSEL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_DTDSEL(v)   ((((reg32_t) v) << 4) & BM_USDHC_MIX_CTRL_DTDSEL)
#else
#define BF_USDHC_MIX_CTRL_DTDSEL(v)   (((v) << 4) & BM_USDHC_MIX_CTRL_DTDSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_DTDSEL(v)   BF_CS1(USDHC_MIX_CTRL, DTDSEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field MSBSEL
 *
 * Multi / Single Block Select:  This bit enables multiple block DAT line data transfers. For any
 * other commands, this bit shall be set to 0. If this bit is 0, it is
 * not necessary to set the Block Count register. (Refer to ).
 */

#define BP_USDHC_MIX_CTRL_MSBSEL      5
#define BM_USDHC_MIX_CTRL_MSBSEL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_MSBSEL(v)   ((((reg32_t) v) << 5) & BM_USDHC_MIX_CTRL_MSBSEL)
#else
#define BF_USDHC_MIX_CTRL_MSBSEL(v)   (((v) << 5) & BM_USDHC_MIX_CTRL_MSBSEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_MSBSEL(v)   BF_CS1(USDHC_MIX_CTRL, MSBSEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field NIBBLE_POS
 *
 * In DDR 4 bit mode nibble position indictation. 0- the sequence is
 * 'odd high nibble -> even high nibble -> odd low nibble ->                                 even
 * low nibble'; 1- the sequence is 'odd high nibble -> odd low
 * nibble -> even high nibble -> even low nibble'.
 */

#define BP_USDHC_MIX_CTRL_NIBBLE_POS      6
#define BM_USDHC_MIX_CTRL_NIBBLE_POS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_NIBBLE_POS(v)   ((((reg32_t) v) << 6) & BM_USDHC_MIX_CTRL_NIBBLE_POS)
#else
#define BF_USDHC_MIX_CTRL_NIBBLE_POS(v)   (((v) << 6) & BM_USDHC_MIX_CTRL_NIBBLE_POS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_NIBBLE_POS(v)   BF_CS1(USDHC_MIX_CTRL, NIBBLE_POS, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AC23EN
 *
 * Auto CMD23 Enable  When this bit is set to 1, the Host Controller issues a CMD23
 * automatically before issuing a command specified in the Command
 * Register.
 */

#define BP_USDHC_MIX_CTRL_AC23EN      7
#define BM_USDHC_MIX_CTRL_AC23EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AC23EN(v)   ((((reg32_t) v) << 7) & BM_USDHC_MIX_CTRL_AC23EN)
#else
#define BF_USDHC_MIX_CTRL_AC23EN(v)   (((v) << 7) & BM_USDHC_MIX_CTRL_AC23EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AC23EN(v)   BF_CS1(USDHC_MIX_CTRL, AC23EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field EXE_TUNE
 *
 * Execute Tuning: (Only used for SD3.0, SDR104 mode)  This bit is set to 1 to indicate the Host
 * Driver is starting tuning                                 procedure. Tuning procedure is aborted
 * by writing 0.  When std_tuning_en is 0, this bit is set to 1 to indicate the Host Driver is
 * starting tuning                                 procedure. Tuning procedure is aborted by writing
 * 0.
 */

#define BP_USDHC_MIX_CTRL_EXE_TUNE      22
#define BM_USDHC_MIX_CTRL_EXE_TUNE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_EXE_TUNE(v)   ((((reg32_t) v) << 22) & BM_USDHC_MIX_CTRL_EXE_TUNE)
#else
#define BF_USDHC_MIX_CTRL_EXE_TUNE(v)   (((v) << 22) & BM_USDHC_MIX_CTRL_EXE_TUNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_EXE_TUNE(v)   BF_CS1(USDHC_MIX_CTRL, EXE_TUNE, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field SMP_CLK_SEL
 *
 * Tuned clock or Fixed clock is used to sample data/cmd (Only used for
 * SD3.0, SDR104 mode)  When std_tuning_en is 0, this bit is used to select Tuned clock or Fixed
 * clock to sample data/cmd (Only used for                                 SD3.0, SDR104 mode)
 */

#define BP_USDHC_MIX_CTRL_SMP_CLK_SEL      23
#define BM_USDHC_MIX_CTRL_SMP_CLK_SEL      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_SMP_CLK_SEL(v)   ((((reg32_t) v) << 23) & BM_USDHC_MIX_CTRL_SMP_CLK_SEL)
#else
#define BF_USDHC_MIX_CTRL_SMP_CLK_SEL(v)   (((v) << 23) & BM_USDHC_MIX_CTRL_SMP_CLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_SMP_CLK_SEL(v)   BF_CS1(USDHC_MIX_CTRL, SMP_CLK_SEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AUTO_TUNE_EN
 *
 * Auto tuning enable (Only used for SD3.0, SDR104 mode)
 */

#define BP_USDHC_MIX_CTRL_AUTO_TUNE_EN      24
#define BM_USDHC_MIX_CTRL_AUTO_TUNE_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AUTO_TUNE_EN(v)   ((((reg32_t) v) << 24) & BM_USDHC_MIX_CTRL_AUTO_TUNE_EN)
#else
#define BF_USDHC_MIX_CTRL_AUTO_TUNE_EN(v)   (((v) << 24) & BM_USDHC_MIX_CTRL_AUTO_TUNE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AUTO_TUNE_EN(v)   BF_CS1(USDHC_MIX_CTRL, AUTO_TUNE_EN, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field FBCLK_SEL
 *
 * Feedback clock source selection (Only used for SD3.0, SDR104
 * mode)
 */

#define BP_USDHC_MIX_CTRL_FBCLK_SEL      25
#define BM_USDHC_MIX_CTRL_FBCLK_SEL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_FBCLK_SEL(v)   ((((reg32_t) v) << 25) & BM_USDHC_MIX_CTRL_FBCLK_SEL)
#else
#define BF_USDHC_MIX_CTRL_FBCLK_SEL(v)   (((v) << 25) & BM_USDHC_MIX_CTRL_FBCLK_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_FBCLK_SEL(v)   BF_CS1(USDHC_MIX_CTRL, FBCLK_SEL, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field AC12_RD_POINT
 *
 * Only for debug.  It's used to control when to send Auto CMD12 after multi-block
 * read.  1 send Auto CMD12 8 cycles after CRC is checked successfully  0 send Auto CMD12 right
 * after CRC is checked successfully
 */

#define BP_USDHC_MIX_CTRL_AC12_RD_POINT      29
#define BM_USDHC_MIX_CTRL_AC12_RD_POINT      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_AC12_RD_POINT(v)   ((((reg32_t) v) << 29) & BM_USDHC_MIX_CTRL_AC12_RD_POINT)
#else
#define BF_USDHC_MIX_CTRL_AC12_RD_POINT(v)   (((v) << 29) & BM_USDHC_MIX_CTRL_AC12_RD_POINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_AC12_RD_POINT(v)   BF_CS1(USDHC_MIX_CTRL, AC12_RD_POINT, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field CMD_DMY_WAIT_CFG
 *
 * Only for debug.  It's also used to control the number of dummy clock cycles after each
 * command when CMD_DMY_EN bit is enabled.  CMD_DMY_EN = 0, CMD_DMY_WAIT_CFG = x : 12 dummy clocks
 * after each                                 command  CMD_DMY_EN = 1, CMD_DMY_WAIT_CFG = 0: 20
 * dummy clocks after each                                 command  CMD_DMY_EN = 1, CMD_DMY_WAIT_CFG
 * = 1: 31 dummy clocks after each                                 command
 */

#define BP_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG      30
#define BM_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG(v)   ((((reg32_t) v) << 30) & BM_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG)
#else
#define BF_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG(v)   (((v) << 30) & BM_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_CMD_DMY_WAIT_CFG(v)   BF_CS1(USDHC_MIX_CTRL, CMD_DMY_WAIT_CFG, v)
#endif

/* --- Register HW_USDHC_MIX_CTRL, field CMD_DMY_EN
 *
 * Only for debug.  It's used to control the number of dummy clock cycles after each
 * command.
 */

#define BP_USDHC_MIX_CTRL_CMD_DMY_EN      31
#define BM_USDHC_MIX_CTRL_CMD_DMY_EN      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MIX_CTRL_CMD_DMY_EN(v)   ((((reg32_t) v) << 31) & BM_USDHC_MIX_CTRL_CMD_DMY_EN)
#else
#define BF_USDHC_MIX_CTRL_CMD_DMY_EN(v)   (((v) << 31) & BM_USDHC_MIX_CTRL_CMD_DMY_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MIX_CTRL_CMD_DMY_EN(v)   BF_CS1(USDHC_MIX_CTRL, CMD_DMY_EN, v)
#endif

/*!
 * @brief HW_USDHC_FORCE_EVENT - Force Event
 *
 * The Force Event Register is not a physically implemented register.
 * Rather, it is an address at which the Interrupt Status Register can be
 * written if the corresponding bit of the Interrupt Status Enable Register
 * is set. This register is a write only register and writing 0 to it has
 * no effect. Writing 1 to this register actually sets the corresponding
 * bit of Interrupt Status Register. A read from this register always
 * results in 0's. In order to change the corresponding status bits in the
 * Interrupt Status Register, make sure to set IPGEN bit in System Control
 * Register so that ipg_clk is always active.  Forcing a card interrupt will generate a short pulse
 * on the DAT[1] line,                             and the driver may treat this interrupt as a
 * normal interrupt. The                             interrupt service routine may skip polling the
 * card interrupt factor as                             the interrupt is self cleared.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FEVTAC12NE : 1; //!< Force Event Auto Command 12 Not Executed:  Forces the AC12NE bit in the Auto Command12 Error Status Register to be set
        unsigned FEVTAC12TOE : 1; //!< Force Event Auto Command 12 Time Out Error:  Forces the AC12TOE bit in the Auto Command12 Error Status Register to be set
        unsigned FEVTAC12CE : 1; //!< Force Event Auto Command 12 CRC Error:  Forces the AC12CE bit in the Auto Command12 Error Status Register to be set
        unsigned FEVTAC12EBE : 1; //!< Force Event Auto Command 12 End Bit Error:  Forces the AC12EBE bit in the Auto Command12 Error Status Register to be set
        unsigned FEVTAC12IE : 1; //!< Force Event Auto Command 12 Index Error:  Forces the AC12IE bit in the Auto Command12 Error Status Register to be set
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned FEVTCNIBAC12E : 1; //!< Force Event Command Not Executed By Auto Command 12 Error:  Forces the CNIBAC12E bit in the Auto Command12 Error Status Register to be set
        unsigned RESERVED1 : 8; //!< Reserved
        unsigned FEVTCCE : 1; //!< Force Event Command Time Out Error:  Forces the CTOE bit of Interrupt Status Register to be set
        unsigned FEVTCCE1 : 1; //!< Force Event Command CRC Error:  Forces the CCE bit of Interrupt Status Register to be set
        unsigned FEVTCEBE : 1; //!< Force Event Command End Bit Error:  Forces the CEBE bit of Interrupt Status Register to be set
        unsigned FEVTCIE : 1; //!< Force Event Command Index Error:  Forces the CCE bit of Interrupt Status Register to be set
        unsigned FEVTDTOE : 1; //!< Force Event Data Time Out Error:  Force the DTOE bit of Interrupt Status Register to be set
        unsigned FEVTDCE : 1; //!< Force Event Data CRC Error:  Forces the DCE bit of Interrupt Status Register to be set
        unsigned FEVTDEBE : 1; //!< Force Event Data End Bit Error:  Forces the DEBE bit of Interrupt Status Register to be set
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned FEVTAC12E : 1; //!< Force Event Auto Command 12 Error:  Forces the AC12E bit of Interrupt Status Register to be set
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned FEVTTNE : 1; //!< Force Tuning Error:  Forces the TNE bit of Interrupt Status Register to be set
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned FEVTDMAE : 1; //!< Force Event DMA Error:  Forces the DMAE bit of Interrupt Status Register to be set
        unsigned RESERVED5 : 2; //!< Reserved
        unsigned FEVTCINT : 1; //!< Force Event Card Interrupt:  Writing 1 to this bit generates a short low-level pulse on the internal DAT[1] line, as if a self clearing interrupt was received from the external card. If enabled, the CINT bit will be set and the interrupt service routine may treat this interrupt as a normal interrupt from the external card.
    } B;
} hw_usdhc_force_event_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_FORCE_EVENT register
 */
#define HW_USDHC_FORCE_EVENT_ADDR(x)      (REGS_USDHC_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_FORCE_EVENT(x)           (*(volatile hw_usdhc_force_event_t *) HW_USDHC_FORCE_EVENT_ADDR(x))
#define HW_USDHC_FORCE_EVENT_RD(x)        (HW_USDHC_FORCE_EVENT(x).U)
#define HW_USDHC_FORCE_EVENT_WR(x, v)     (HW_USDHC_FORCE_EVENT(x).U = (v))
#define HW_USDHC_FORCE_EVENT_SET(x, v)    (HW_USDHC_FORCE_EVENT_WR(x, HW_USDHC_FORCE_EVENT_RD(x) |  (v)))
#define HW_USDHC_FORCE_EVENT_CLR(x, v)    (HW_USDHC_FORCE_EVENT_WR(x, HW_USDHC_FORCE_EVENT_RD(x) & ~(v)))
#define HW_USDHC_FORCE_EVENT_TOG(x, v)    (HW_USDHC_FORCE_EVENT_WR(x, HW_USDHC_FORCE_EVENT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_FORCE_EVENT bitfields
 */

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12NE
 *
 * Force Event Auto Command 12 Not Executed:  Forces the AC12NE bit in the Auto Command12 Error
 * Status Register to                                 be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTAC12NE      0
#define BM_USDHC_FORCE_EVENT_FEVTAC12NE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12NE(v)   ((((reg32_t) v) << 0) & BM_USDHC_FORCE_EVENT_FEVTAC12NE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12NE(v)   (((v) << 0) & BM_USDHC_FORCE_EVENT_FEVTAC12NE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12NE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12NE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12TOE
 *
 * Force Event Auto Command 12 Time Out Error:  Forces the AC12TOE bit in the Auto Command12 Error
 * Status Register to                                 be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTAC12TOE      1
#define BM_USDHC_FORCE_EVENT_FEVTAC12TOE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12TOE(v)   ((((reg32_t) v) << 1) & BM_USDHC_FORCE_EVENT_FEVTAC12TOE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12TOE(v)   (((v) << 1) & BM_USDHC_FORCE_EVENT_FEVTAC12TOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12TOE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12TOE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12CE
 *
 * Force Event Auto Command 12 CRC Error:  Forces the AC12CE bit in the Auto Command12 Error Status
 * Register to                                 be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTAC12CE      2
#define BM_USDHC_FORCE_EVENT_FEVTAC12CE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12CE(v)   ((((reg32_t) v) << 2) & BM_USDHC_FORCE_EVENT_FEVTAC12CE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12CE(v)   (((v) << 2) & BM_USDHC_FORCE_EVENT_FEVTAC12CE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12CE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12CE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12EBE
 *
 * Force Event Auto Command 12 End Bit Error:  Forces the AC12EBE bit in the Auto Command12 Error
 * Status Register to                                 be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTAC12EBE      3
#define BM_USDHC_FORCE_EVENT_FEVTAC12EBE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12EBE(v)   ((((reg32_t) v) << 3) & BM_USDHC_FORCE_EVENT_FEVTAC12EBE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12EBE(v)   (((v) << 3) & BM_USDHC_FORCE_EVENT_FEVTAC12EBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12EBE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12EBE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12IE
 *
 * Force Event Auto Command 12 Index Error:  Forces the AC12IE bit in the Auto Command12 Error
 * Status Register to                                 be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTAC12IE      4
#define BM_USDHC_FORCE_EVENT_FEVTAC12IE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12IE(v)   ((((reg32_t) v) << 4) & BM_USDHC_FORCE_EVENT_FEVTAC12IE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12IE(v)   (((v) << 4) & BM_USDHC_FORCE_EVENT_FEVTAC12IE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12IE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12IE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCNIBAC12E
 *
 * Force Event Command Not Executed By Auto Command 12 Error:  Forces the CNIBAC12E bit in the Auto
 * Command12 Error Status Register                                 to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTCNIBAC12E      7
#define BM_USDHC_FORCE_EVENT_FEVTCNIBAC12E      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCNIBAC12E(v)   ((((reg32_t) v) << 7) & BM_USDHC_FORCE_EVENT_FEVTCNIBAC12E)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCNIBAC12E(v)   (((v) << 7) & BM_USDHC_FORCE_EVENT_FEVTCNIBAC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCNIBAC12E(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCNIBAC12E, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCCE
 *
 * Force Event Command Time Out Error:  Forces the CTOE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTCCE      16
#define BM_USDHC_FORCE_EVENT_FEVTCCE      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   ((((reg32_t) v) << 16) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   (((v) << 16) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCCE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCCE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCCE
 *
 * Force Event Command CRC Error:  Forces the CCE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTCCE      17
#define BM_USDHC_FORCE_EVENT_FEVTCCE      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   ((((reg32_t) v) << 17) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCCE(v)   (((v) << 17) & BM_USDHC_FORCE_EVENT_FEVTCCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCCE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCCE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCEBE
 *
 * Force Event Command End Bit Error:  Forces the CEBE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTCEBE      18
#define BM_USDHC_FORCE_EVENT_FEVTCEBE      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCEBE(v)   ((((reg32_t) v) << 18) & BM_USDHC_FORCE_EVENT_FEVTCEBE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCEBE(v)   (((v) << 18) & BM_USDHC_FORCE_EVENT_FEVTCEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCEBE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCEBE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCIE
 *
 * Force Event Command Index Error:  Forces the CCE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTCIE      19
#define BM_USDHC_FORCE_EVENT_FEVTCIE      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCIE(v)   ((((reg32_t) v) << 19) & BM_USDHC_FORCE_EVENT_FEVTCIE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCIE(v)   (((v) << 19) & BM_USDHC_FORCE_EVENT_FEVTCIE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCIE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCIE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDTOE
 *
 * Force Event Data Time Out Error:  Force the DTOE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTDTOE      20
#define BM_USDHC_FORCE_EVENT_FEVTDTOE      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDTOE(v)   ((((reg32_t) v) << 20) & BM_USDHC_FORCE_EVENT_FEVTDTOE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDTOE(v)   (((v) << 20) & BM_USDHC_FORCE_EVENT_FEVTDTOE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDTOE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDTOE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDCE
 *
 * Force Event Data CRC Error:  Forces the DCE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTDCE      21
#define BM_USDHC_FORCE_EVENT_FEVTDCE      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDCE(v)   ((((reg32_t) v) << 21) & BM_USDHC_FORCE_EVENT_FEVTDCE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDCE(v)   (((v) << 21) & BM_USDHC_FORCE_EVENT_FEVTDCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDCE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDCE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDEBE
 *
 * Force Event Data End Bit Error:  Forces the DEBE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTDEBE      22
#define BM_USDHC_FORCE_EVENT_FEVTDEBE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDEBE(v)   ((((reg32_t) v) << 22) & BM_USDHC_FORCE_EVENT_FEVTDEBE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDEBE(v)   (((v) << 22) & BM_USDHC_FORCE_EVENT_FEVTDEBE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDEBE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDEBE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTAC12E
 *
 * Force Event Auto Command 12 Error:  Forces the AC12E bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTAC12E      24
#define BM_USDHC_FORCE_EVENT_FEVTAC12E      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTAC12E(v)   ((((reg32_t) v) << 24) & BM_USDHC_FORCE_EVENT_FEVTAC12E)
#else
#define BF_USDHC_FORCE_EVENT_FEVTAC12E(v)   (((v) << 24) & BM_USDHC_FORCE_EVENT_FEVTAC12E)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTAC12E(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTAC12E, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTTNE
 *
 * Force Tuning Error:  Forces the TNE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTTNE      26
#define BM_USDHC_FORCE_EVENT_FEVTTNE      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTTNE(v)   ((((reg32_t) v) << 26) & BM_USDHC_FORCE_EVENT_FEVTTNE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTTNE(v)   (((v) << 26) & BM_USDHC_FORCE_EVENT_FEVTTNE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTTNE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTTNE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTDMAE
 *
 * Force Event DMA Error:  Forces the DMAE bit of Interrupt Status Register to be set
 */

#define BP_USDHC_FORCE_EVENT_FEVTDMAE      28
#define BM_USDHC_FORCE_EVENT_FEVTDMAE      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTDMAE(v)   ((((reg32_t) v) << 28) & BM_USDHC_FORCE_EVENT_FEVTDMAE)
#else
#define BF_USDHC_FORCE_EVENT_FEVTDMAE(v)   (((v) << 28) & BM_USDHC_FORCE_EVENT_FEVTDMAE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTDMAE(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTDMAE, v)
#endif

/* --- Register HW_USDHC_FORCE_EVENT, field FEVTCINT
 *
 * Force Event Card Interrupt:  Writing 1 to this bit generates a short low-level pulse on the
 * internal DAT[1] line, as if a self clearing interrupt was received
 * from the external card. If enabled, the CINT bit will be set and the
 * interrupt service routine may treat this interrupt as a normal
 * interrupt from the external card.
 */

#define BP_USDHC_FORCE_EVENT_FEVTCINT      31
#define BM_USDHC_FORCE_EVENT_FEVTCINT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_FORCE_EVENT_FEVTCINT(v)   ((((reg32_t) v) << 31) & BM_USDHC_FORCE_EVENT_FEVTCINT)
#else
#define BF_USDHC_FORCE_EVENT_FEVTCINT(v)   (((v) << 31) & BM_USDHC_FORCE_EVENT_FEVTCINT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_FORCE_EVENT_FEVTCINT(v)   BF_CS1(USDHC_FORCE_EVENT, FEVTCINT, v)
#endif

/*!
 * @brief HW_USDHC_ADMA_ERR_STATUS - ADMA Error Status Register
 *
 * When an ADMA Error Interrupt has occurred, the ADMA Error States field in
 * this register holds the ADMA state and the ADMA System Address register
 * holds the address around the error descriptor.  For recovering from this error, the Host Driver
 * requires the ADMA state                             to identify the error descriptor address as
 * follows:   ST_STOP: Previous location set in the ADMA System Address register
 * is the error descriptor address  ST_FDS: Current location set in the ADMA System Address register
 * is                                 the error descriptor address  ST_CADR: This state is never set
 * because it only increments the                                 descriptor pointer and doesn't
 * generate an ADMA error  ST_TFR: Previous location set in the ADMA System Address register is
 * the error descriptor address   In case of a write operation, the Host Driver should use the
 * ACMD22 to                             get the number of the written block, rather than using this
 * information,                             since unwritten data may exist in the Host Controller.
 * The Host Controller generates the ADMA Error Interrupt when it detects
 * invalid descriptor data (Valid=0) in the ST_FDS state. The Host Driver
 * can distinguish this error by reading the Valid bit of the error
 * descriptor.   ADMA Error State Coding         D01-D00    ADMA Error State (when error has
 * occurred)    Contents of ADMA System Address
 * Register        00    ST_STOP (Stop DMA)    Holds the address of the next
 * executable Descriptor command      01    ST_FDS (Fetch
 * Descriptor)    Holds the valid Descriptor                                                 address
 * 10    ST_CADR (Change                                             Address)    No ADMA Error is
 * generated      11    ST_TFR (Transfer Data)    Holds the address of the next
 * executable Descriptor command
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ADMAES : 2; //!< ADMA Error State (when ADMA Error is occurred.):  This field indicates the state of the ADMA when an error has occurred during an ADMA data transfer. Refer to for more details.
        unsigned ADMALME : 1; //!< ADMA Length Mismatch Error:  This error occurs in the following 2 cases:   While the Block Count Enable is being set, the total data length specified by the Descriptor table is different from that specified by the Block Count and Block Length  Total data length can not be divided by the block length
        unsigned ADMADCE : 1; //!< ADMA Descritor Error:  This error occurs when invalid descriptor fetched by ADMA:
        unsigned RESERVED0 : 28; //!< Reserved
    } B;
} hw_usdhc_adma_err_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_ADMA_ERR_STATUS register
 */
#define HW_USDHC_ADMA_ERR_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_ADMA_ERR_STATUS(x)           (*(volatile hw_usdhc_adma_err_status_t *) HW_USDHC_ADMA_ERR_STATUS_ADDR(x))
#define HW_USDHC_ADMA_ERR_STATUS_RD(x)        (HW_USDHC_ADMA_ERR_STATUS(x).U)
#define HW_USDHC_ADMA_ERR_STATUS_WR(x, v)     (HW_USDHC_ADMA_ERR_STATUS(x).U = (v))
#define HW_USDHC_ADMA_ERR_STATUS_SET(x, v)    (HW_USDHC_ADMA_ERR_STATUS_WR(x, HW_USDHC_ADMA_ERR_STATUS_RD(x) |  (v)))
#define HW_USDHC_ADMA_ERR_STATUS_CLR(x, v)    (HW_USDHC_ADMA_ERR_STATUS_WR(x, HW_USDHC_ADMA_ERR_STATUS_RD(x) & ~(v)))
#define HW_USDHC_ADMA_ERR_STATUS_TOG(x, v)    (HW_USDHC_ADMA_ERR_STATUS_WR(x, HW_USDHC_ADMA_ERR_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_ADMA_ERR_STATUS bitfields
 */

/* --- Register HW_USDHC_ADMA_ERR_STATUS, field ADMAES
 *
 * ADMA Error State (when ADMA Error is occurred.):  This field indicates the state of the ADMA when
 * an error has occurred                                 during an ADMA data transfer. Refer to for
 * more details.
 */

#define BP_USDHC_ADMA_ERR_STATUS_ADMAES      0
#define BM_USDHC_ADMA_ERR_STATUS_ADMAES      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_ERR_STATUS_ADMAES(v)   ((((reg32_t) v) << 0) & BM_USDHC_ADMA_ERR_STATUS_ADMAES)
#else
#define BF_USDHC_ADMA_ERR_STATUS_ADMAES(v)   (((v) << 0) & BM_USDHC_ADMA_ERR_STATUS_ADMAES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_ERR_STATUS_ADMAES(v)   BF_CS1(USDHC_ADMA_ERR_STATUS, ADMAES, v)
#endif

/* --- Register HW_USDHC_ADMA_ERR_STATUS, field ADMALME
 *
 * ADMA Length Mismatch Error:  This error occurs in the following 2 cases:   While the Block Count
 * Enable is being set, the total data length                                     specified by the
 * Descriptor table is different from that                                     specified by the
 * Block Count and Block Length  Total data length can not be divided by the block length
 */

#define BP_USDHC_ADMA_ERR_STATUS_ADMALME      2
#define BM_USDHC_ADMA_ERR_STATUS_ADMALME      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_ERR_STATUS_ADMALME(v)   ((((reg32_t) v) << 2) & BM_USDHC_ADMA_ERR_STATUS_ADMALME)
#else
#define BF_USDHC_ADMA_ERR_STATUS_ADMALME(v)   (((v) << 2) & BM_USDHC_ADMA_ERR_STATUS_ADMALME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_ERR_STATUS_ADMALME(v)   BF_CS1(USDHC_ADMA_ERR_STATUS, ADMALME, v)
#endif

/* --- Register HW_USDHC_ADMA_ERR_STATUS, field ADMADCE
 *
 * ADMA Descritor Error:  This error occurs when invalid descriptor fetched by ADMA:
 */

#define BP_USDHC_ADMA_ERR_STATUS_ADMADCE      3
#define BM_USDHC_ADMA_ERR_STATUS_ADMADCE      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_ERR_STATUS_ADMADCE(v)   ((((reg32_t) v) << 3) & BM_USDHC_ADMA_ERR_STATUS_ADMADCE)
#else
#define BF_USDHC_ADMA_ERR_STATUS_ADMADCE(v)   (((v) << 3) & BM_USDHC_ADMA_ERR_STATUS_ADMADCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_ERR_STATUS_ADMADCE(v)   BF_CS1(USDHC_ADMA_ERR_STATUS, ADMADCE, v)
#endif

/*!
 * @brief HW_USDHC_ADMA_SYS_ADDR - ADMA System Address
 *
 * This register contains the physical system memory address used for ADMA
 * transfers.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned ADS_ADDR : 30; //!< ADMA System Address:  This register holds the word address of the executing command in the Descriptor table. At the start of ADMA, the Host Driver shall set the start address of the Descriptor table. The ADMA engine increments this register address whenever fetching a Descriptor command. When the ADMA is stopped at the Block Gap, this register indicates the address of the next executable Descriptor command. When the ADMA Error Interrupt is generated, this register shall hold the valid Descriptor address depending on the ADMA state. The lower 2 bits of this register is tied to '0' so the ADMA address is always word aligned.  Since this register supports dynamic address reflecting, when TC bit is set, it automatically alters the value of internal address counter, so SW cannot change this register when TC bit is set. Such restriction is also listed in .
    } B;
} hw_usdhc_adma_sys_addr_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_ADMA_SYS_ADDR register
 */
#define HW_USDHC_ADMA_SYS_ADDR_ADDR(x)      (REGS_USDHC_BASE(x) + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_ADMA_SYS_ADDR(x)           (*(volatile hw_usdhc_adma_sys_addr_t *) HW_USDHC_ADMA_SYS_ADDR_ADDR(x))
#define HW_USDHC_ADMA_SYS_ADDR_RD(x)        (HW_USDHC_ADMA_SYS_ADDR(x).U)
#define HW_USDHC_ADMA_SYS_ADDR_WR(x, v)     (HW_USDHC_ADMA_SYS_ADDR(x).U = (v))
#define HW_USDHC_ADMA_SYS_ADDR_SET(x, v)    (HW_USDHC_ADMA_SYS_ADDR_WR(x, HW_USDHC_ADMA_SYS_ADDR_RD(x) |  (v)))
#define HW_USDHC_ADMA_SYS_ADDR_CLR(x, v)    (HW_USDHC_ADMA_SYS_ADDR_WR(x, HW_USDHC_ADMA_SYS_ADDR_RD(x) & ~(v)))
#define HW_USDHC_ADMA_SYS_ADDR_TOG(x, v)    (HW_USDHC_ADMA_SYS_ADDR_WR(x, HW_USDHC_ADMA_SYS_ADDR_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_ADMA_SYS_ADDR bitfields
 */

/* --- Register HW_USDHC_ADMA_SYS_ADDR, field ADS_ADDR
 *
 * ADMA System Address:  This register holds the word address of the executing command in the
 * Descriptor table. At the start of ADMA, the Host Driver shall set
 * the start address of the Descriptor table. The ADMA engine
 * increments this register address whenever fetching a Descriptor
 * command. When the ADMA is stopped at the Block Gap, this register
 * indicates the address of the next executable Descriptor command.
 * When the ADMA Error Interrupt is generated, this register shall hold
 * the valid Descriptor address depending on the ADMA state. The lower
 * 2 bits of this register is tied to '0' so the ADMA address is always
 * word aligned.  Since this register supports dynamic address reflecting, when TC bit
 * is set, it automatically alters the value of internal address
 * counter, so SW cannot change this register when TC bit is set. Such
 * restriction is also listed in .
 */

#define BP_USDHC_ADMA_SYS_ADDR_ADS_ADDR      2
#define BM_USDHC_ADMA_SYS_ADDR_ADS_ADDR      0xfffffffc

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_ADMA_SYS_ADDR_ADS_ADDR(v)   ((((reg32_t) v) << 2) & BM_USDHC_ADMA_SYS_ADDR_ADS_ADDR)
#else
#define BF_USDHC_ADMA_SYS_ADDR_ADS_ADDR(v)   (((v) << 2) & BM_USDHC_ADMA_SYS_ADDR_ADS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_ADMA_SYS_ADDR_ADS_ADDR(v)   BF_CS1(USDHC_ADMA_SYS_ADDR, ADS_ADDR, v)
#endif

/*!
 * @brief HW_USDHC_DLL_CTRL - DLL (Delay Line) Control
 *
 * This register contains control bits for DLL.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLL_CTRL_ENABLE : 1; //!< Set this bit to 1 to enable the DLL and delay chain; otherwise; set to 0 to bypasses DLL. Note that using the slave delay line override feature with SLV_OVERRIDE and SLV_OVERRIDE VAL, the DLL does not need to be enabled
        unsigned DLL_CTRL_RESET : 1; //!< Setting this bit to 1 force a reset on DLL. This will cause the DLL to lose lock and re-calibrate to detect an ref_clock half period phase shift. This signal is used by the DLL as edge-sensitive, so in order to create a subsequent reset, RESET must be taken low and then asserted again
        unsigned DLL_CTRL_SLV_FORCE_UPD : 1; //!< Setting this bit to 1, forces the slave delay line to update to the DLL calibrated value immediately. The slave delay line shall update automatically based on the SLV_UPDATE_INT interval or when a DLL lock condition is sensed. Subsequent forcing of the slave-line update can only occur if SLV_FORCE_UP is set back to 0 and then asserted again (edge triggered). Be sure to use it when uSDHC is idle. This function may not work when uSDHC is working on data/cmd/response.
        unsigned DLL_CTRL_SLV_DLY_TARGET : 4; //!< The delay target for the uSDHC loopback read clock can be programmed in 1/16th increments of an ref_clock half-period. The delay is ((DLL_CTRL_SLV_DLY_TARGET[6:0] +1)* ref_clock/2)/16 So the input read-clock can be delayed relative input data from (ref_clock/2)/16 to ref_clock*4
        unsigned DLL_CTRL_GATE_UPDATE : 1; //!< Set this bit to 1 to force DLL not update from now on.Since when clock_in exists, glitches might appear during update. This bit is used by software if we met such kind of condition. Set it to 0 to let DLL update automatically
        unsigned DLL_CTRL_SLV_OVERRIDE : 1; //!< Set this bit to 1 to Enable manual override for slave delay chain using SLV_OVERRIDE_VAL; to set 0 to disable manual override. This feature does not require the DLL to tbe enabled using the ENABLE bit. In fact to reduce power, if SLV_OVERRIDE is used, it is recommended to disable the DLL with ENABLE=0
        unsigned DLL_CTRL_SLV_OVERRIDE_VAL : 7; //!< When SLV_OVERRIDE=1 This field is used to select 1 of 128 physical taps manually. A value of 0 selects tap 1, and a value of 0x7f selects tap 128.
        unsigned DLL_CTRL_SLV_DLY_TARGET1 : 3; //!< Refer to DLL_CTRL_SLV_DLY_TARGET[3:0] below.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned DLL_CTRL_SLV_UPDATE_INT : 8; //!< slave delay line update interval. If default 0 is used, it means 256 cycles of ref_clock. A value of 0x0f results in 15 cycles and so on. Note that software can always cause an update of the slave-delay line using the SLV_FORCE_UPDATE register. Note that the slave delay line will also update automatically when the reference DLL transitions to a locked state (from an un-locked state).
        unsigned DLL_CTRL_REF_UPDATE_INT : 4; //!< DLL control loop update interval. The interval cycle is (2 + REF_UPDATE_INT) * ref_clock. By default, the DLL control loop shall update every two ref_clock cycles. It should be noted that increasing the reference delay-line update interval reduces the ability of the DLL to adjust to fast changes in conditions that may effect the delay (such as voltage and temperature)
    } B;
} hw_usdhc_dll_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DLL_CTRL register
 */
#define HW_USDHC_DLL_CTRL_ADDR(x)      (REGS_USDHC_BASE(x) + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DLL_CTRL(x)           (*(volatile hw_usdhc_dll_ctrl_t *) HW_USDHC_DLL_CTRL_ADDR(x))
#define HW_USDHC_DLL_CTRL_RD(x)        (HW_USDHC_DLL_CTRL(x).U)
#define HW_USDHC_DLL_CTRL_WR(x, v)     (HW_USDHC_DLL_CTRL(x).U = (v))
#define HW_USDHC_DLL_CTRL_SET(x, v)    (HW_USDHC_DLL_CTRL_WR(x, HW_USDHC_DLL_CTRL_RD(x) |  (v)))
#define HW_USDHC_DLL_CTRL_CLR(x, v)    (HW_USDHC_DLL_CTRL_WR(x, HW_USDHC_DLL_CTRL_RD(x) & ~(v)))
#define HW_USDHC_DLL_CTRL_TOG(x, v)    (HW_USDHC_DLL_CTRL_WR(x, HW_USDHC_DLL_CTRL_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DLL_CTRL bitfields
 */

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_ENABLE
 *
 * Set this bit to 1 to enable the DLL and delay chain; otherwise; set
 * to 0 to bypasses DLL. Note that using the slave delay line override
 * feature with SLV_OVERRIDE and SLV_OVERRIDE VAL, the DLL does not
 * need to be enabled
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_ENABLE      0
#define BM_USDHC_DLL_CTRL_DLL_CTRL_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_ENABLE(v)   ((((reg32_t) v) << 0) & BM_USDHC_DLL_CTRL_DLL_CTRL_ENABLE)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_ENABLE(v)   (((v) << 0) & BM_USDHC_DLL_CTRL_DLL_CTRL_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_ENABLE(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_ENABLE, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_RESET
 *
 * Setting this bit to 1 force a reset on DLL. This will cause the DLL
 * to lose lock and re-calibrate to detect an ref_clock half period
 * phase shift. This signal is used by the DLL as edge-sensitive, so in
 * order to create a subsequent reset, RESET must be taken low and then
 * asserted again
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_RESET      1
#define BM_USDHC_DLL_CTRL_DLL_CTRL_RESET      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_RESET(v)   ((((reg32_t) v) << 1) & BM_USDHC_DLL_CTRL_DLL_CTRL_RESET)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_RESET(v)   (((v) << 1) & BM_USDHC_DLL_CTRL_DLL_CTRL_RESET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_RESET(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_RESET, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_FORCE_UPD
 *
 * Setting this bit to 1, forces the slave delay line to update to the
 * DLL calibrated value immediately. The slave delay line shall update
 * automatically based on the SLV_UPDATE_INT interval or when a DLL
 * lock condition is sensed. Subsequent forcing of the slave-line
 * update can only occur if SLV_FORCE_UP is set back to 0 and then
 * asserted again (edge triggered). Be sure to use it when uSDHC is
 * idle. This function may not work when uSDHC is working on
 * data/cmd/response.
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD      2
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(v)   ((((reg32_t) v) << 2) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(v)   (((v) << 2) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_FORCE_UPD, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_DLY_TARGET
 *
 * The delay target for the uSDHC loopback read clock can be programmed
 * in 1/16th increments of an ref_clock half-period. The delay is
 * ((DLL_CTRL_SLV_DLY_TARGET[6:0] +1)* ref_clock/2)/16 So the input
 * read-clock can be delayed relative input data from (ref_clock/2)/16
 * to ref_clock*4
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      3
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      0x00000078

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   ((((reg32_t) v) << 3) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   (((v) << 3) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_DLY_TARGET, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_GATE_UPDATE
 *
 * Set this bit to 1 to force DLL not update from now on.Since when
 * clock_in exists, glitches might appear during update. This bit is
 * used by software if we met such kind of condition. Set it to 0 to
 * let DLL update automatically
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE      7
#define BM_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(v)   ((((reg32_t) v) << 7) & BM_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(v)   (((v) << 7) & BM_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_GATE_UPDATE, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_OVERRIDE
 *
 * Set this bit to 1 to Enable manual override for slave delay chain
 * using SLV_OVERRIDE_VAL; to set 0 to disable manual override. This
 * feature does not require the DLL to tbe enabled using the ENABLE
 * bit. In fact to reduce power, if SLV_OVERRIDE is used, it is
 * recommended to disable the DLL with ENABLE=0
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE      8
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(v)   ((((reg32_t) v) << 8) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(v)   (((v) << 8) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_OVERRIDE, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_OVERRIDE_VAL
 *
 * When SLV_OVERRIDE=1 This field is used to select 1 of 128 physical
 * taps manually. A value of 0 selects tap 1, and a value of 0x7f
 * selects tap 128.
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL      9
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL      0x0000fe00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(v)   ((((reg32_t) v) << 9) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(v)   (((v) << 9) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_OVERRIDE_VAL, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_DLY_TARGET
 *
 * Refer to DLL_CTRL_SLV_DLY_TARGET[3:0] below.
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      16
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   ((((reg32_t) v) << 16) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   (((v) << 16) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_DLY_TARGET, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_SLV_UPDATE_INT
 *
 * slave delay line update interval. If default 0 is used, it means 256
 * cycles of ref_clock. A value of 0x0f results in 15 cycles and so on.
 * Note that software can always cause an update of the slave-delay
 * line using the SLV_FORCE_UPDATE register. Note that the slave delay
 * line will also update automatically when the reference DLL
 * transitions to a locked state (from an un-locked state).
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT      20
#define BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT      0x0ff00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(v)   ((((reg32_t) v) << 20) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(v)   (((v) << 20) & BM_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_SLV_UPDATE_INT, v)
#endif

/* --- Register HW_USDHC_DLL_CTRL, field DLL_CTRL_REF_UPDATE_INT
 *
 * DLL control loop update interval. The interval cycle is (2 +
 * REF_UPDATE_INT) * ref_clock. By default, the DLL control loop shall
 * update every two ref_clock cycles. It should be noted that
 * increasing the reference delay-line update interval reduces the
 * ability of the DLL to adjust to fast changes in conditions that may
 * effect the delay (such as voltage and temperature)
 */

#define BP_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT      28
#define BM_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(v)   ((((reg32_t) v) << 28) & BM_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT)
#else
#define BF_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(v)   (((v) << 28) & BM_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(v)   BF_CS1(USDHC_DLL_CTRL, DLL_CTRL_REF_UPDATE_INT, v)
#endif

/*!
 * @brief HW_USDHC_DLL_STATUS - DLL Status
 *
 * This register contains the DLL status information. All bits are read only
 * and will read the same as the power-reset value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLL_STS_SLV_LOCK : 1; //!< Slave delay-line lock status. This signifies that a valid calibration has been set to the slave-delay line and that the slave-delay line is implementing the programmed delay value
        unsigned DLL_STS_REF_LOCK : 1; //!< Reference DLL lock status. This signifies that the DLL has detected and locked to a half-phase ref_clock shift, allowing the slave delay-line to perform programmed clock delays
        unsigned DLL_STS_SLV_SEL : 7; //!< Slave delay line select status. This is the instant value generated from reference chain. Since only when ref_lock is detected can the reference chain get updated, this value should be the right value next be update to the slave line when reference is locked.
        unsigned DLL_STS_REF_SEL : 7; //!< Reference delay line select taps. Be noted this is encoded by 7 bits for 127taps.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usdhc_dll_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_DLL_STATUS register
 */
#define HW_USDHC_DLL_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_DLL_STATUS(x)           (*(volatile hw_usdhc_dll_status_t *) HW_USDHC_DLL_STATUS_ADDR(x))
#define HW_USDHC_DLL_STATUS_RD(x)        (HW_USDHC_DLL_STATUS(x).U)
#define HW_USDHC_DLL_STATUS_WR(x, v)     (HW_USDHC_DLL_STATUS(x).U = (v))
#define HW_USDHC_DLL_STATUS_SET(x, v)    (HW_USDHC_DLL_STATUS_WR(x, HW_USDHC_DLL_STATUS_RD(x) |  (v)))
#define HW_USDHC_DLL_STATUS_CLR(x, v)    (HW_USDHC_DLL_STATUS_WR(x, HW_USDHC_DLL_STATUS_RD(x) & ~(v)))
#define HW_USDHC_DLL_STATUS_TOG(x, v)    (HW_USDHC_DLL_STATUS_WR(x, HW_USDHC_DLL_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_DLL_STATUS bitfields
 */

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_SLV_LOCK
 *
 * Slave delay-line lock status. This signifies that a valid calibration
 * has been set to the slave-delay line and that the slave-delay line
 * is implementing the programmed delay value
 */

#define BP_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK      0
#define BM_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(v)   ((((reg32_t) v) << 0) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(v)   (((v) << 0) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_SLV_LOCK, v)
#endif

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_REF_LOCK
 *
 * Reference DLL lock status. This signifies that the DLL has detected
 * and locked to a half-phase ref_clock shift, allowing the slave
 * delay-line to perform programmed clock delays
 */

#define BP_USDHC_DLL_STATUS_DLL_STS_REF_LOCK      1
#define BM_USDHC_DLL_STATUS_DLL_STS_REF_LOCK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_LOCK(v)   ((((reg32_t) v) << 1) & BM_USDHC_DLL_STATUS_DLL_STS_REF_LOCK)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_LOCK(v)   (((v) << 1) & BM_USDHC_DLL_STATUS_DLL_STS_REF_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_REF_LOCK(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_REF_LOCK, v)
#endif

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_SLV_SEL
 *
 * Slave delay line select status. This is the instant value generated
 * from reference chain. Since only when ref_lock is detected can the
 * reference chain get updated, this value should be the right value
 * next be update to the slave line when reference is locked.
 */

#define BP_USDHC_DLL_STATUS_DLL_STS_SLV_SEL      2
#define BM_USDHC_DLL_STATUS_DLL_STS_SLV_SEL      0x000001fc

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_SEL(v)   ((((reg32_t) v) << 2) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_SEL)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_SLV_SEL(v)   (((v) << 2) & BM_USDHC_DLL_STATUS_DLL_STS_SLV_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_SLV_SEL(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_SLV_SEL, v)
#endif

/* --- Register HW_USDHC_DLL_STATUS, field DLL_STS_REF_SEL
 *
 * Reference delay line select taps. Be noted this is encoded by 7 bits
 * for 127taps.
 */

#define BP_USDHC_DLL_STATUS_DLL_STS_REF_SEL      9
#define BM_USDHC_DLL_STATUS_DLL_STS_REF_SEL      0x0000fe00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_SEL(v)   ((((reg32_t) v) << 9) & BM_USDHC_DLL_STATUS_DLL_STS_REF_SEL)
#else
#define BF_USDHC_DLL_STATUS_DLL_STS_REF_SEL(v)   (((v) << 9) & BM_USDHC_DLL_STATUS_DLL_STS_REF_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_DLL_STATUS_DLL_STS_REF_SEL(v)   BF_CS1(USDHC_DLL_STATUS, DLL_STS_REF_SEL, v)
#endif

/*!
 * @brief HW_USDHC_CLK_TUNE_CTRL_STATUS - CLK Tuning Control and Status
 *
 * This register contains the Clock Tuning Control status information. All
 * bits are read only and will read the same as the power-reset value. This
 * register is added to support SD3.0 UHS-I SDR104 mode.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DLY_CELL_SET_POST : 4; //!< Set the number of delay cells on the feedback clock between CLK_OUT and CLK_POST.
        unsigned DLY_CELL_SET_OUT : 4; //!< Set the number of delay cells on the feedback clock between CLK_PRE and CLK_OUT.
        unsigned DLY_CELL_SET_PRE : 7; //!< Set the number of delay cells on the feedback clock between the feedback clock and CLK_PRE.
        unsigned NXT_ERR : 1; //!< NXT error which means the number of delay cells added on the feedback clock is too large. It's valid only when SMP_CLK_SEL of Mix control register(bit23 of 0x48) is enabled.
        unsigned TAP_SEL_POST : 4; //!< Reflect the number of delay cells added on the feedback clock between CLK_OUT and CLK_POST.
        unsigned TAP_SEL_OUT : 4; //!< Reflect the number of delay cells added on the feedback clock between CLK_PRE and CLK_OUT.
        unsigned TAP_SEL_PRE : 7; //!< Reflect the number of delay cells added on the feedback clock between the feedback clock and CLK_PRE.  When AUTO_TUNE_EN(bit24 of 0x48) is disabled, TAP_SEL_PRE is always equal to DLY_CELL_SET_PRE.  When AUTO_TUNE_EN(bit24 of 0x48) is enabled, TAP_SEL_PRE will be updated automatically according to the status of the auto tuning circuit to adjust the sample clock phase.
        unsigned PRE_ERR : 1; //!< PRE error which means the number of delay cells added on the feedback clock is too small. It's valid only when SMP_CLK_SEL of Mix control register(bit23 of 0x48) is enabled.
    } B;
} hw_usdhc_clk_tune_ctrl_status_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_CLK_TUNE_CTRL_STATUS register
 */
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_ADDR(x)      (REGS_USDHC_BASE(x) + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_CLK_TUNE_CTRL_STATUS(x)           (*(volatile hw_usdhc_clk_tune_ctrl_status_t *) HW_USDHC_CLK_TUNE_CTRL_STATUS_ADDR(x))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x)        (HW_USDHC_CLK_TUNE_CTRL_STATUS(x).U)
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, v)     (HW_USDHC_CLK_TUNE_CTRL_STATUS(x).U = (v))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_SET(x, v)    (HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x) |  (v)))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_CLR(x, v)    (HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x) & ~(v)))
#define HW_USDHC_CLK_TUNE_CTRL_STATUS_TOG(x, v)    (HW_USDHC_CLK_TUNE_CTRL_STATUS_WR(x, HW_USDHC_CLK_TUNE_CTRL_STATUS_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_CLK_TUNE_CTRL_STATUS bitfields
 */

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field DLY_CELL_SET_POST
 *
 * Set the number of delay cells on the feedback clock between CLK_OUT
 * and CLK_POST.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST      0
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(v)   ((((reg32_t) v) << 0) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(v)   (((v) << 0) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, DLY_CELL_SET_POST, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field DLY_CELL_SET_OUT
 *
 * Set the number of delay cells on the feedback clock between CLK_PRE
 * and CLK_OUT.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT      4
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(v)   ((((reg32_t) v) << 4) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(v)   (((v) << 4) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, DLY_CELL_SET_OUT, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field DLY_CELL_SET_PRE
 *
 * Set the number of delay cells on the feedback clock between the
 * feedback clock and CLK_PRE.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE      8
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(v)   ((((reg32_t) v) << 8) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(v)   (((v) << 8) & BM_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, DLY_CELL_SET_PRE, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field NXT_ERR
 *
 * NXT error which means the number of delay cells added on the feedback
 * clock is too large. It's valid only when SMP_CLK_SEL of Mix control
 * register(bit23 of 0x48) is enabled.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR      15
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(v)   ((((reg32_t) v) << 15) & BM_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(v)   (((v) << 15) & BM_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, NXT_ERR, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field TAP_SEL_POST
 *
 * Reflect the number of delay cells added on the feedback clock between
 * CLK_OUT and CLK_POST.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST      16
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(v)   ((((reg32_t) v) << 16) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(v)   (((v) << 16) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, TAP_SEL_POST, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field TAP_SEL_OUT
 *
 * Reflect the number of delay cells added on the feedback clock between
 * CLK_PRE and CLK_OUT.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT      20
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(v)   ((((reg32_t) v) << 20) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(v)   (((v) << 20) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, TAP_SEL_OUT, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field TAP_SEL_PRE
 *
 * Reflect the number of delay cells added on the feedback clock between
 * the feedback clock and CLK_PRE.  When AUTO_TUNE_EN(bit24 of 0x48) is disabled, TAP_SEL_PRE is
 * always                                 equal to DLY_CELL_SET_PRE.  When AUTO_TUNE_EN(bit24 of
 * 0x48) is enabled, TAP_SEL_PRE will be                                 updated automatically
 * according to the status of the auto tuning                                 circuit to adjust the
 * sample clock phase.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE      24
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(v)   ((((reg32_t) v) << 24) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(v)   (((v) << 24) & BM_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, TAP_SEL_PRE, v)
#endif

/* --- Register HW_USDHC_CLK_TUNE_CTRL_STATUS, field PRE_ERR
 *
 * PRE error which means the number of delay cells added on the feedback
 * clock is too small. It's valid only when SMP_CLK_SEL of Mix control
 * register(bit23 of 0x48) is enabled.
 */

#define BP_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR      31
#define BM_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(v)   ((((reg32_t) v) << 31) & BM_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR)
#else
#define BF_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(v)   (((v) << 31) & BM_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(v)   BF_CS1(USDHC_CLK_TUNE_CTRL_STATUS, PRE_ERR, v)
#endif

/*!
 * @brief HW_USDHC_VEND_SPEC - Vendor Specific Register
 *
 * This register contains the vendor specific control/status register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EXT_DMA_EN : 1; //!< External DMA Request Enable  Enable the request to external DMA. When the internal DMA (either Simple DMA or Advanced DMA) is not in use, and this bit is set, uSDHC will send out DMA request when the internal buffer is ready. This bit is particularly useful when transferring data by ARM platform polling mode, and it is not allowed to send out the external DMA request. By default, this bit is set.
        unsigned VSELECT : 1; //!< Voltage Selection  Change the value of output signal SD_VSELECT, to control the voltage on pads for external card. There must be a control circuit out of uSDHC to change the voltage on pads.
        unsigned CONFLICT_CHK_EN : 1; //!< It's not implemented in uSDHC IP.  Conflict check enable.
        unsigned AC12_WR_CHKBUSY_EN : 1; //!< Check busy enable after auto CMD12 for write data packet
        unsigned DAT3_CD_POL : 1; //!< This bit only uses for debugging.  Polarity of Dat3 pin when it's used as card detection:
        unsigned CD_POL : 1; //!< This bit only uses for debugging.  Polarity of the CD pin:
        unsigned WP_POL : 1; //!< This bit only uses for debugging.  Polarity of the WP pin:
        unsigned CLKONJ_IN_ABORT : 1; //!< This bit only uses for debugging.  Force SD_CLK output active when sending Abort command:
        unsigned FRC_SDCLK_ON : 1; //!< Force SD_CLK output active:
        unsigned AC12_ISNOT_ABORT : 1; //!< This bit only uses for debugging.  Auto CMD12 is not a abort command:
        unsigned DDREN_ACT_ATONCE : 1; //!< This bit only uses for debugging.  DDR_EN setting take active at once:
        unsigned IPG_CLK_SOFT_EN : 1; //!< IPG_CLK software enable
        unsigned HCLK_SOFT_EN : 1; //!< Please note, hardware auto-enables the AHB clock when the internal DMA is enabled even if HCLK_SOFT_EN is 0.  AHB clock software enable
        unsigned IPG_PERCLK_SOFT_EN : 1; //!< ipg_perclk software enable
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned CRC_CHK_DIS : 1; //!< CRC check disable
        unsigned INT_ST_VAL : 8; //!< Internal State Value  Internal state value, reflecting the corresponding state value selected by Debug Select field. This field is read-only and write to this field does not have effect.
        unsigned DBG_SEL : 4; //!< Debug Select  Select the internal sub-module to show its internal state value.
        unsigned CMD_OE_PRE_EN : 1; //!< Only for debug.  Control the assert point of CMD_OE signal
        unsigned AC12_RD_CHKBUSY_EN : 1; //!< Only for debug.  Auto CMD12 to terminate multi-block read needs to check busy or not
        unsigned CARD_DET_IN_IDLE_ENJ : 1; //!< Only for debug.  Card detection is only detected during data line idle.
        unsigned RESERVED1 : 1; //!< Reserved
    } B;
} hw_usdhc_vend_spec_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_VEND_SPEC register
 */
#define HW_USDHC_VEND_SPEC_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_VEND_SPEC(x)           (*(volatile hw_usdhc_vend_spec_t *) HW_USDHC_VEND_SPEC_ADDR(x))
#define HW_USDHC_VEND_SPEC_RD(x)        (HW_USDHC_VEND_SPEC(x).U)
#define HW_USDHC_VEND_SPEC_WR(x, v)     (HW_USDHC_VEND_SPEC(x).U = (v))
#define HW_USDHC_VEND_SPEC_SET(x, v)    (HW_USDHC_VEND_SPEC_WR(x, HW_USDHC_VEND_SPEC_RD(x) |  (v)))
#define HW_USDHC_VEND_SPEC_CLR(x, v)    (HW_USDHC_VEND_SPEC_WR(x, HW_USDHC_VEND_SPEC_RD(x) & ~(v)))
#define HW_USDHC_VEND_SPEC_TOG(x, v)    (HW_USDHC_VEND_SPEC_WR(x, HW_USDHC_VEND_SPEC_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_VEND_SPEC bitfields
 */

/* --- Register HW_USDHC_VEND_SPEC, field EXT_DMA_EN
 *
 * External DMA Request Enable  Enable the request to external DMA. When the internal DMA (either
 * Simple DMA or Advanced DMA) is not in use, and this bit is set,
 * uSDHC will send out DMA request when the internal buffer is ready.
 * This bit is particularly useful when transferring data by ARM platform
 * polling mode, and it is not allowed to send out the external DMA
 * request. By default, this bit is set.
 */

#define BP_USDHC_VEND_SPEC_EXT_DMA_EN      0
#define BM_USDHC_VEND_SPEC_EXT_DMA_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_EXT_DMA_EN(v)   ((((reg32_t) v) << 0) & BM_USDHC_VEND_SPEC_EXT_DMA_EN)
#else
#define BF_USDHC_VEND_SPEC_EXT_DMA_EN(v)   (((v) << 0) & BM_USDHC_VEND_SPEC_EXT_DMA_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_EXT_DMA_EN(v)   BF_CS1(USDHC_VEND_SPEC, EXT_DMA_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field VSELECT
 *
 * Voltage Selection  Change the value of output signal SD_VSELECT, to control the voltage on
 * pads for external card. There must be a control circuit out of uSDHC
 * to change the voltage on pads.
 */

#define BP_USDHC_VEND_SPEC_VSELECT      1
#define BM_USDHC_VEND_SPEC_VSELECT      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_VSELECT(v)   ((((reg32_t) v) << 1) & BM_USDHC_VEND_SPEC_VSELECT)
#else
#define BF_USDHC_VEND_SPEC_VSELECT(v)   (((v) << 1) & BM_USDHC_VEND_SPEC_VSELECT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_VSELECT(v)   BF_CS1(USDHC_VEND_SPEC, VSELECT, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CONFLICT_CHK_EN
 *
 * It's not implemented in uSDHC IP.  Conflict check enable.
 */

#define BP_USDHC_VEND_SPEC_CONFLICT_CHK_EN      2
#define BM_USDHC_VEND_SPEC_CONFLICT_CHK_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CONFLICT_CHK_EN(v)   ((((reg32_t) v) << 2) & BM_USDHC_VEND_SPEC_CONFLICT_CHK_EN)
#else
#define BF_USDHC_VEND_SPEC_CONFLICT_CHK_EN(v)   (((v) << 2) & BM_USDHC_VEND_SPEC_CONFLICT_CHK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CONFLICT_CHK_EN(v)   BF_CS1(USDHC_VEND_SPEC, CONFLICT_CHK_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field AC12_WR_CHKBUSY_EN
 *
 * Check busy enable after auto CMD12 for write data packet
 */

#define BP_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN      3
#define BM_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(v)   ((((reg32_t) v) << 3) & BM_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN)
#else
#define BF_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(v)   (((v) << 3) & BM_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(v)   BF_CS1(USDHC_VEND_SPEC, AC12_WR_CHKBUSY_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field DAT3_CD_POL
 *
 * This bit only uses for debugging.  Polarity of Dat3 pin when it's used as card detection:
 */

#define BP_USDHC_VEND_SPEC_DAT3_CD_POL      4
#define BM_USDHC_VEND_SPEC_DAT3_CD_POL      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_DAT3_CD_POL(v)   ((((reg32_t) v) << 4) & BM_USDHC_VEND_SPEC_DAT3_CD_POL)
#else
#define BF_USDHC_VEND_SPEC_DAT3_CD_POL(v)   (((v) << 4) & BM_USDHC_VEND_SPEC_DAT3_CD_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_DAT3_CD_POL(v)   BF_CS1(USDHC_VEND_SPEC, DAT3_CD_POL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CD_POL
 *
 * This bit only uses for debugging.  Polarity of the CD pin:
 */

#define BP_USDHC_VEND_SPEC_CD_POL      5
#define BM_USDHC_VEND_SPEC_CD_POL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CD_POL(v)   ((((reg32_t) v) << 5) & BM_USDHC_VEND_SPEC_CD_POL)
#else
#define BF_USDHC_VEND_SPEC_CD_POL(v)   (((v) << 5) & BM_USDHC_VEND_SPEC_CD_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CD_POL(v)   BF_CS1(USDHC_VEND_SPEC, CD_POL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field WP_POL
 *
 * This bit only uses for debugging.  Polarity of the WP pin:
 */

#define BP_USDHC_VEND_SPEC_WP_POL      6
#define BM_USDHC_VEND_SPEC_WP_POL      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_WP_POL(v)   ((((reg32_t) v) << 6) & BM_USDHC_VEND_SPEC_WP_POL)
#else
#define BF_USDHC_VEND_SPEC_WP_POL(v)   (((v) << 6) & BM_USDHC_VEND_SPEC_WP_POL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_WP_POL(v)   BF_CS1(USDHC_VEND_SPEC, WP_POL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CLKONJ_IN_ABORT
 *
 * This bit only uses for debugging.  Force SD_CLK output active when sending Abort command:
 */

#define BP_USDHC_VEND_SPEC_CLKONJ_IN_ABORT      7
#define BM_USDHC_VEND_SPEC_CLKONJ_IN_ABORT      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CLKONJ_IN_ABORT(v)   ((((reg32_t) v) << 7) & BM_USDHC_VEND_SPEC_CLKONJ_IN_ABORT)
#else
#define BF_USDHC_VEND_SPEC_CLKONJ_IN_ABORT(v)   (((v) << 7) & BM_USDHC_VEND_SPEC_CLKONJ_IN_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CLKONJ_IN_ABORT(v)   BF_CS1(USDHC_VEND_SPEC, CLKONJ_IN_ABORT, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field FRC_SDCLK_ON
 *
 * Force SD_CLK output active:
 */

#define BP_USDHC_VEND_SPEC_FRC_SDCLK_ON      8
#define BM_USDHC_VEND_SPEC_FRC_SDCLK_ON      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_FRC_SDCLK_ON(v)   ((((reg32_t) v) << 8) & BM_USDHC_VEND_SPEC_FRC_SDCLK_ON)
#else
#define BF_USDHC_VEND_SPEC_FRC_SDCLK_ON(v)   (((v) << 8) & BM_USDHC_VEND_SPEC_FRC_SDCLK_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_FRC_SDCLK_ON(v)   BF_CS1(USDHC_VEND_SPEC, FRC_SDCLK_ON, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field AC12_ISNOT_ABORT
 *
 * This bit only uses for debugging.  Auto CMD12 is not a abort command:
 */

#define BP_USDHC_VEND_SPEC_AC12_ISNOT_ABORT      9
#define BM_USDHC_VEND_SPEC_AC12_ISNOT_ABORT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_AC12_ISNOT_ABORT(v)   ((((reg32_t) v) << 9) & BM_USDHC_VEND_SPEC_AC12_ISNOT_ABORT)
#else
#define BF_USDHC_VEND_SPEC_AC12_ISNOT_ABORT(v)   (((v) << 9) & BM_USDHC_VEND_SPEC_AC12_ISNOT_ABORT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_AC12_ISNOT_ABORT(v)   BF_CS1(USDHC_VEND_SPEC, AC12_ISNOT_ABORT, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field DDREN_ACT_ATONCE
 *
 * This bit only uses for debugging.  DDR_EN setting take active at once:
 */

#define BP_USDHC_VEND_SPEC_DDREN_ACT_ATONCE      10
#define BM_USDHC_VEND_SPEC_DDREN_ACT_ATONCE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_DDREN_ACT_ATONCE(v)   ((((reg32_t) v) << 10) & BM_USDHC_VEND_SPEC_DDREN_ACT_ATONCE)
#else
#define BF_USDHC_VEND_SPEC_DDREN_ACT_ATONCE(v)   (((v) << 10) & BM_USDHC_VEND_SPEC_DDREN_ACT_ATONCE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_DDREN_ACT_ATONCE(v)   BF_CS1(USDHC_VEND_SPEC, DDREN_ACT_ATONCE, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field IPG_CLK_SOFT_EN
 *
 * IPG_CLK software enable
 */

#define BP_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN      11
#define BM_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN(v)   ((((reg32_t) v) << 11) & BM_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN)
#else
#define BF_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN(v)   (((v) << 11) & BM_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_IPG_CLK_SOFT_EN(v)   BF_CS1(USDHC_VEND_SPEC, IPG_CLK_SOFT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field HCLK_SOFT_EN
 *
 * Please note, hardware auto-enables the AHB clock when the internal
 * DMA is enabled even if HCLK_SOFT_EN is 0.  AHB clock software enable
 */

#define BP_USDHC_VEND_SPEC_HCLK_SOFT_EN      12
#define BM_USDHC_VEND_SPEC_HCLK_SOFT_EN      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_HCLK_SOFT_EN(v)   ((((reg32_t) v) << 12) & BM_USDHC_VEND_SPEC_HCLK_SOFT_EN)
#else
#define BF_USDHC_VEND_SPEC_HCLK_SOFT_EN(v)   (((v) << 12) & BM_USDHC_VEND_SPEC_HCLK_SOFT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_HCLK_SOFT_EN(v)   BF_CS1(USDHC_VEND_SPEC, HCLK_SOFT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field IPG_PERCLK_SOFT_EN
 *
 * ipg_perclk software enable
 */

#define BP_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN      13
#define BM_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN(v)   ((((reg32_t) v) << 13) & BM_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN)
#else
#define BF_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN(v)   (((v) << 13) & BM_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_IPG_PERCLK_SOFT_EN(v)   BF_CS1(USDHC_VEND_SPEC, IPG_PERCLK_SOFT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CRC_CHK_DIS
 *
 * CRC check disable
 */

#define BP_USDHC_VEND_SPEC_CRC_CHK_DIS      15
#define BM_USDHC_VEND_SPEC_CRC_CHK_DIS      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CRC_CHK_DIS(v)   ((((reg32_t) v) << 15) & BM_USDHC_VEND_SPEC_CRC_CHK_DIS)
#else
#define BF_USDHC_VEND_SPEC_CRC_CHK_DIS(v)   (((v) << 15) & BM_USDHC_VEND_SPEC_CRC_CHK_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CRC_CHK_DIS(v)   BF_CS1(USDHC_VEND_SPEC, CRC_CHK_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field INT_ST_VAL
 *
 * Internal State Value  Internal state value, reflecting the corresponding state value
 * selected by Debug Select field. This field is read-only and write to
 * this field does not have effect.
 */

#define BP_USDHC_VEND_SPEC_INT_ST_VAL      16
#define BM_USDHC_VEND_SPEC_INT_ST_VAL      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_INT_ST_VAL(v)   ((((reg32_t) v) << 16) & BM_USDHC_VEND_SPEC_INT_ST_VAL)
#else
#define BF_USDHC_VEND_SPEC_INT_ST_VAL(v)   (((v) << 16) & BM_USDHC_VEND_SPEC_INT_ST_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_INT_ST_VAL(v)   BF_CS1(USDHC_VEND_SPEC, INT_ST_VAL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field DBG_SEL
 *
 * Debug Select  Select the internal sub-module to show its internal state value.
 */

#define BP_USDHC_VEND_SPEC_DBG_SEL      24
#define BM_USDHC_VEND_SPEC_DBG_SEL      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_DBG_SEL(v)   ((((reg32_t) v) << 24) & BM_USDHC_VEND_SPEC_DBG_SEL)
#else
#define BF_USDHC_VEND_SPEC_DBG_SEL(v)   (((v) << 24) & BM_USDHC_VEND_SPEC_DBG_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_DBG_SEL(v)   BF_CS1(USDHC_VEND_SPEC, DBG_SEL, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CMD_OE_PRE_EN
 *
 * Only for debug.  Control the assert point of CMD_OE signal
 */

#define BP_USDHC_VEND_SPEC_CMD_OE_PRE_EN      28
#define BM_USDHC_VEND_SPEC_CMD_OE_PRE_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CMD_OE_PRE_EN(v)   ((((reg32_t) v) << 28) & BM_USDHC_VEND_SPEC_CMD_OE_PRE_EN)
#else
#define BF_USDHC_VEND_SPEC_CMD_OE_PRE_EN(v)   (((v) << 28) & BM_USDHC_VEND_SPEC_CMD_OE_PRE_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CMD_OE_PRE_EN(v)   BF_CS1(USDHC_VEND_SPEC, CMD_OE_PRE_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field AC12_RD_CHKBUSY_EN
 *
 * Only for debug.  Auto CMD12 to terminate multi-block read needs to check busy or
 * not
 */

#define BP_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN      29
#define BM_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN(v)   ((((reg32_t) v) << 29) & BM_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN)
#else
#define BF_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN(v)   (((v) << 29) & BM_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_AC12_RD_CHKBUSY_EN(v)   BF_CS1(USDHC_VEND_SPEC, AC12_RD_CHKBUSY_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC, field CARD_DET_IN_IDLE_ENJ
 *
 * Only for debug.  Card detection is only detected during data line idle.
 */

#define BP_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ      30
#define BM_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ(v)   ((((reg32_t) v) << 30) & BM_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ)
#else
#define BF_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ(v)   (((v) << 30) & BM_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC_CARD_DET_IN_IDLE_ENJ(v)   BF_CS1(USDHC_VEND_SPEC, CARD_DET_IN_IDLE_ENJ, v)
#endif

/*!
 * @brief HW_USDHC_MMC_BOOT - MMC Boot Register
 *
 * This register contains the MMC Fast Boot control register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DTOCV_ACK : 4; //!< Boot ACK time out counter value.
        unsigned BOOT_ACK : 1; //!< Boot ack mode select 0: no ack 1: ack
        unsigned BOOT_MODE : 1; //!< Boot mode select 0: normal boot 1: alternative boot
        unsigned BOOT_EN : 1; //!< Boot mode enable 0: fast boot disable 1: fast boot enable
        unsigned AUTO_SABG_EN : 1; //!< When boot, enable auto stop at block gap function. This function will be triggered, and host will stop at block gap when received card block cnt is equal to (BLK_CNT - BOOT_BLK_CNT).
        unsigned DISABLE_TIME_OUT : 1; //!< Please note, when this bit is set, there is no timeout check no matter boot_en is set or not.  Disable time out.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned BOOT_BLK_CNT : 16; //!< The value defines the Stop At Block Gap value of automatic mode. When received card block cnt is equal to (BLK_CNT - BOOT_BLK_CNT) and AUTO_SABG_EN is 1, then Stop At Block Gap.  Here, BLK_CNT is defined in the Block Atrributes Register, bit31-16 of 0x04.
    } B;
} hw_usdhc_mmc_boot_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_MMC_BOOT register
 */
#define HW_USDHC_MMC_BOOT_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_MMC_BOOT(x)           (*(volatile hw_usdhc_mmc_boot_t *) HW_USDHC_MMC_BOOT_ADDR(x))
#define HW_USDHC_MMC_BOOT_RD(x)        (HW_USDHC_MMC_BOOT(x).U)
#define HW_USDHC_MMC_BOOT_WR(x, v)     (HW_USDHC_MMC_BOOT(x).U = (v))
#define HW_USDHC_MMC_BOOT_SET(x, v)    (HW_USDHC_MMC_BOOT_WR(x, HW_USDHC_MMC_BOOT_RD(x) |  (v)))
#define HW_USDHC_MMC_BOOT_CLR(x, v)    (HW_USDHC_MMC_BOOT_WR(x, HW_USDHC_MMC_BOOT_RD(x) & ~(v)))
#define HW_USDHC_MMC_BOOT_TOG(x, v)    (HW_USDHC_MMC_BOOT_WR(x, HW_USDHC_MMC_BOOT_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_MMC_BOOT bitfields
 */

/* --- Register HW_USDHC_MMC_BOOT, field DTOCV_ACK
 *
 * Boot ACK time out counter value.
 */

#define BP_USDHC_MMC_BOOT_DTOCV_ACK      0
#define BM_USDHC_MMC_BOOT_DTOCV_ACK      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_DTOCV_ACK(v)   ((((reg32_t) v) << 0) & BM_USDHC_MMC_BOOT_DTOCV_ACK)
#else
#define BF_USDHC_MMC_BOOT_DTOCV_ACK(v)   (((v) << 0) & BM_USDHC_MMC_BOOT_DTOCV_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_DTOCV_ACK(v)   BF_CS1(USDHC_MMC_BOOT, DTOCV_ACK, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_ACK
 *
 * Boot ack mode select 0: no ack 1: ack
 */

#define BP_USDHC_MMC_BOOT_BOOT_ACK      4
#define BM_USDHC_MMC_BOOT_BOOT_ACK      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_ACK(v)   ((((reg32_t) v) << 4) & BM_USDHC_MMC_BOOT_BOOT_ACK)
#else
#define BF_USDHC_MMC_BOOT_BOOT_ACK(v)   (((v) << 4) & BM_USDHC_MMC_BOOT_BOOT_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_ACK(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_ACK, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_MODE
 *
 * Boot mode select 0: normal boot 1: alternative boot
 */

#define BP_USDHC_MMC_BOOT_BOOT_MODE      5
#define BM_USDHC_MMC_BOOT_BOOT_MODE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_MODE(v)   ((((reg32_t) v) << 5) & BM_USDHC_MMC_BOOT_BOOT_MODE)
#else
#define BF_USDHC_MMC_BOOT_BOOT_MODE(v)   (((v) << 5) & BM_USDHC_MMC_BOOT_BOOT_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_MODE(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_MODE, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_EN
 *
 * Boot mode enable 0: fast boot disable 1: fast boot enable
 */

#define BP_USDHC_MMC_BOOT_BOOT_EN      6
#define BM_USDHC_MMC_BOOT_BOOT_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_EN(v)   ((((reg32_t) v) << 6) & BM_USDHC_MMC_BOOT_BOOT_EN)
#else
#define BF_USDHC_MMC_BOOT_BOOT_EN(v)   (((v) << 6) & BM_USDHC_MMC_BOOT_BOOT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_EN(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_EN, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field AUTO_SABG_EN
 *
 * When boot, enable auto stop at block gap function. This function will
 * be triggered, and host will stop at block gap when received card
 * block cnt is equal to (BLK_CNT - BOOT_BLK_CNT).
 */

#define BP_USDHC_MMC_BOOT_AUTO_SABG_EN      7
#define BM_USDHC_MMC_BOOT_AUTO_SABG_EN      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_AUTO_SABG_EN(v)   ((((reg32_t) v) << 7) & BM_USDHC_MMC_BOOT_AUTO_SABG_EN)
#else
#define BF_USDHC_MMC_BOOT_AUTO_SABG_EN(v)   (((v) << 7) & BM_USDHC_MMC_BOOT_AUTO_SABG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_AUTO_SABG_EN(v)   BF_CS1(USDHC_MMC_BOOT, AUTO_SABG_EN, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field DISABLE_TIME_OUT
 *
 * Please note, when this bit is set, there is no timeout check no
 * matter boot_en is set or not.  Disable time out.
 */

#define BP_USDHC_MMC_BOOT_DISABLE_TIME_OUT      8
#define BM_USDHC_MMC_BOOT_DISABLE_TIME_OUT      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_DISABLE_TIME_OUT(v)   ((((reg32_t) v) << 8) & BM_USDHC_MMC_BOOT_DISABLE_TIME_OUT)
#else
#define BF_USDHC_MMC_BOOT_DISABLE_TIME_OUT(v)   (((v) << 8) & BM_USDHC_MMC_BOOT_DISABLE_TIME_OUT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_DISABLE_TIME_OUT(v)   BF_CS1(USDHC_MMC_BOOT, DISABLE_TIME_OUT, v)
#endif

/* --- Register HW_USDHC_MMC_BOOT, field BOOT_BLK_CNT
 *
 * The value defines the Stop At Block Gap value of automatic mode. When
 * received card block cnt is equal to (BLK_CNT - BOOT_BLK_CNT) and
 * AUTO_SABG_EN is 1, then Stop At Block Gap.  Here, BLK_CNT is defined in the Block Atrributes
 * Register, bit31-16                                 of 0x04.
 */

#define BP_USDHC_MMC_BOOT_BOOT_BLK_CNT      16
#define BM_USDHC_MMC_BOOT_BOOT_BLK_CNT      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_MMC_BOOT_BOOT_BLK_CNT(v)   ((((reg32_t) v) << 16) & BM_USDHC_MMC_BOOT_BOOT_BLK_CNT)
#else
#define BF_USDHC_MMC_BOOT_BOOT_BLK_CNT(v)   (((v) << 16) & BM_USDHC_MMC_BOOT_BOOT_BLK_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_MMC_BOOT_BOOT_BLK_CNT(v)   BF_CS1(USDHC_MMC_BOOT, BOOT_BLK_CNT, v)
#endif

/*!
 * @brief HW_USDHC_VEND_SPEC2 - Vendor Specific 2 Register
 *
 * This register contains the vendor specific control 2 register.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SDR104_TIMING_DIS : 1; //!< Timeout counter test.  This bit only uses for debugging.
        unsigned SDR104_OE_DIS : 1; //!< CMD_OE/DAT_OE logic generation test.  This bit only uses for debugging.
        unsigned SDR104_NSD_DIS : 1; //!< Interrupt window after abort command is sent.  This bit only uses for debugging.
        unsigned CARD_INT_D3_TEST : 1; //!< Card interrupt detection test.  This bit only uses for debugging.
        unsigned TUNING_8BIT_EN : 1; //!< Enable the auto tuning circuit to check the DAT[7:0]. It's used with the TUNING_1bit_EN together.
        unsigned TUNING_1BIT_EN : 1; //!< Enable the auto tuning circuit to check the DAT0 only. It's used with the TUNING_8bit_EN together.
        unsigned TUNING_CMD_EN : 1; //!< Enable the auto tuning circuit to check the CMD line.
        unsigned CARD_INT_AUTO_CLR_DIS : 1; //!< Disable the feature to clear the Card interrupt status bit when Card Interrupt status enable bit is cleared.  This bit only uses for debugging.
        unsigned RESERVED0 : 24; //!< Reserved
    } B;
} hw_usdhc_vend_spec2_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_VEND_SPEC2 register
 */
#define HW_USDHC_VEND_SPEC2_ADDR(x)      (REGS_USDHC_BASE(x) + 0xc8)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_VEND_SPEC2(x)           (*(volatile hw_usdhc_vend_spec2_t *) HW_USDHC_VEND_SPEC2_ADDR(x))
#define HW_USDHC_VEND_SPEC2_RD(x)        (HW_USDHC_VEND_SPEC2(x).U)
#define HW_USDHC_VEND_SPEC2_WR(x, v)     (HW_USDHC_VEND_SPEC2(x).U = (v))
#define HW_USDHC_VEND_SPEC2_SET(x, v)    (HW_USDHC_VEND_SPEC2_WR(x, HW_USDHC_VEND_SPEC2_RD(x) |  (v)))
#define HW_USDHC_VEND_SPEC2_CLR(x, v)    (HW_USDHC_VEND_SPEC2_WR(x, HW_USDHC_VEND_SPEC2_RD(x) & ~(v)))
#define HW_USDHC_VEND_SPEC2_TOG(x, v)    (HW_USDHC_VEND_SPEC2_WR(x, HW_USDHC_VEND_SPEC2_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_VEND_SPEC2 bitfields
 */

/* --- Register HW_USDHC_VEND_SPEC2, field SDR104_TIMING_DIS
 *
 * Timeout counter test.  This bit only uses for debugging.
 */

#define BP_USDHC_VEND_SPEC2_SDR104_TIMING_DIS      0
#define BM_USDHC_VEND_SPEC2_SDR104_TIMING_DIS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_SDR104_TIMING_DIS(v)   ((((reg32_t) v) << 0) & BM_USDHC_VEND_SPEC2_SDR104_TIMING_DIS)
#else
#define BF_USDHC_VEND_SPEC2_SDR104_TIMING_DIS(v)   (((v) << 0) & BM_USDHC_VEND_SPEC2_SDR104_TIMING_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_SDR104_TIMING_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, SDR104_TIMING_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field SDR104_OE_DIS
 *
 * CMD_OE/DAT_OE logic generation test.  This bit only uses for debugging.
 */

#define BP_USDHC_VEND_SPEC2_SDR104_OE_DIS      1
#define BM_USDHC_VEND_SPEC2_SDR104_OE_DIS      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_SDR104_OE_DIS(v)   ((((reg32_t) v) << 1) & BM_USDHC_VEND_SPEC2_SDR104_OE_DIS)
#else
#define BF_USDHC_VEND_SPEC2_SDR104_OE_DIS(v)   (((v) << 1) & BM_USDHC_VEND_SPEC2_SDR104_OE_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_SDR104_OE_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, SDR104_OE_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field SDR104_NSD_DIS
 *
 * Interrupt window after abort command is sent.  This bit only uses for debugging.
 */

#define BP_USDHC_VEND_SPEC2_SDR104_NSD_DIS      2
#define BM_USDHC_VEND_SPEC2_SDR104_NSD_DIS      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_SDR104_NSD_DIS(v)   ((((reg32_t) v) << 2) & BM_USDHC_VEND_SPEC2_SDR104_NSD_DIS)
#else
#define BF_USDHC_VEND_SPEC2_SDR104_NSD_DIS(v)   (((v) << 2) & BM_USDHC_VEND_SPEC2_SDR104_NSD_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_SDR104_NSD_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, SDR104_NSD_DIS, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field CARD_INT_D3_TEST
 *
 * Card interrupt detection test.  This bit only uses for debugging.
 */

#define BP_USDHC_VEND_SPEC2_CARD_INT_D3_TEST      3
#define BM_USDHC_VEND_SPEC2_CARD_INT_D3_TEST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_CARD_INT_D3_TEST(v)   ((((reg32_t) v) << 3) & BM_USDHC_VEND_SPEC2_CARD_INT_D3_TEST)
#else
#define BF_USDHC_VEND_SPEC2_CARD_INT_D3_TEST(v)   (((v) << 3) & BM_USDHC_VEND_SPEC2_CARD_INT_D3_TEST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_CARD_INT_D3_TEST(v)   BF_CS1(USDHC_VEND_SPEC2, CARD_INT_D3_TEST, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field TUNING_8BIT_EN
 *
 * Enable the auto tuning circuit to check the DAT[7:0]. It's used with the
 * TUNING_1bit_EN together.
 */

#define BP_USDHC_VEND_SPEC2_TUNING_8BIT_EN      4
#define BM_USDHC_VEND_SPEC2_TUNING_8BIT_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_TUNING_8BIT_EN(v)   ((((reg32_t) v) << 4) & BM_USDHC_VEND_SPEC2_TUNING_8BIT_EN)
#else
#define BF_USDHC_VEND_SPEC2_TUNING_8BIT_EN(v)   (((v) << 4) & BM_USDHC_VEND_SPEC2_TUNING_8BIT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_TUNING_8BIT_EN(v)   BF_CS1(USDHC_VEND_SPEC2, TUNING_8BIT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field TUNING_1BIT_EN
 *
 * Enable the auto tuning circuit to check the DAT0 only. It's used with the
 * TUNING_8bit_EN together.
 */

#define BP_USDHC_VEND_SPEC2_TUNING_1BIT_EN      5
#define BM_USDHC_VEND_SPEC2_TUNING_1BIT_EN      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_TUNING_1BIT_EN(v)   ((((reg32_t) v) << 5) & BM_USDHC_VEND_SPEC2_TUNING_1BIT_EN)
#else
#define BF_USDHC_VEND_SPEC2_TUNING_1BIT_EN(v)   (((v) << 5) & BM_USDHC_VEND_SPEC2_TUNING_1BIT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_TUNING_1BIT_EN(v)   BF_CS1(USDHC_VEND_SPEC2, TUNING_1BIT_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field TUNING_CMD_EN
 *
 * Enable the auto tuning circuit to check the CMD line.
 */

#define BP_USDHC_VEND_SPEC2_TUNING_CMD_EN      6
#define BM_USDHC_VEND_SPEC2_TUNING_CMD_EN      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_TUNING_CMD_EN(v)   ((((reg32_t) v) << 6) & BM_USDHC_VEND_SPEC2_TUNING_CMD_EN)
#else
#define BF_USDHC_VEND_SPEC2_TUNING_CMD_EN(v)   (((v) << 6) & BM_USDHC_VEND_SPEC2_TUNING_CMD_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_TUNING_CMD_EN(v)   BF_CS1(USDHC_VEND_SPEC2, TUNING_CMD_EN, v)
#endif

/* --- Register HW_USDHC_VEND_SPEC2, field CARD_INT_AUTO_CLR_DIS
 *
 * Disable the feature to clear the Card interrupt status bit when Card
 * Interrupt status enable bit is cleared.  This bit only uses for debugging.
 */

#define BP_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS      7
#define BM_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS(v)   ((((reg32_t) v) << 7) & BM_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS)
#else
#define BF_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS(v)   (((v) << 7) & BM_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_VEND_SPEC2_CARD_INT_AUTO_CLR_DIS(v)   BF_CS1(USDHC_VEND_SPEC2, CARD_INT_AUTO_CLR_DIS, v)
#endif

/*!
 * @brief HW_USDHC_HOST_CTRL_VER - Host Controller Version
 *
 * This register contains the vendor Host Controller version information.
 * All bits are read only and will read the same as the power-reset
 * value.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SVN : 8; //!< Specification Version Number:  These status bits indicate the Host Controller Specification Version.  00 SD Host Specification Version 1.0  03 SD Host Specification Version 3.0, supports Test Event Register and ADMA.  All others) Reserved
        unsigned VVN : 8; //!< Vendor Version Number:  These status bits are reserved for the vendor version number. The Host Driver shall not use this status.  01 Freescale uSDHC Version 1.1  others) Reserved
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_usdhc_host_ctrl_ver_t;
#endif

/*
 * constants & macros for entire multi-block USDHC_HOST_CTRL_VER register
 */
#define HW_USDHC_HOST_CTRL_VER_ADDR(x)      (REGS_USDHC_BASE(x) + 0xfc)

#ifndef __LANGUAGE_ASM__
#define HW_USDHC_HOST_CTRL_VER(x)           (*(volatile hw_usdhc_host_ctrl_ver_t *) HW_USDHC_HOST_CTRL_VER_ADDR(x))
#define HW_USDHC_HOST_CTRL_VER_RD(x)        (HW_USDHC_HOST_CTRL_VER(x).U)
#define HW_USDHC_HOST_CTRL_VER_WR(x, v)     (HW_USDHC_HOST_CTRL_VER(x).U = (v))
#define HW_USDHC_HOST_CTRL_VER_SET(x, v)    (HW_USDHC_HOST_CTRL_VER_WR(x, HW_USDHC_HOST_CTRL_VER_RD(x) |  (v)))
#define HW_USDHC_HOST_CTRL_VER_CLR(x, v)    (HW_USDHC_HOST_CTRL_VER_WR(x, HW_USDHC_HOST_CTRL_VER_RD(x) & ~(v)))
#define HW_USDHC_HOST_CTRL_VER_TOG(x, v)    (HW_USDHC_HOST_CTRL_VER_WR(x, HW_USDHC_HOST_CTRL_VER_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual USDHC_HOST_CTRL_VER bitfields
 */

/* --- Register HW_USDHC_HOST_CTRL_VER, field SVN
 *
 * Specification Version Number:  These status bits indicate the Host Controller Specification
 * Version.  00 SD Host Specification Version 1.0  03 SD Host Specification Version 3.0, supports
 * Test Event Register                                 and ADMA.  All others) Reserved
 */

#define BP_USDHC_HOST_CTRL_VER_SVN      0
#define BM_USDHC_HOST_CTRL_VER_SVN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_VER_SVN(v)   ((((reg32_t) v) << 0) & BM_USDHC_HOST_CTRL_VER_SVN)
#else
#define BF_USDHC_HOST_CTRL_VER_SVN(v)   (((v) << 0) & BM_USDHC_HOST_CTRL_VER_SVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_VER_SVN(v)   BF_CS1(USDHC_HOST_CTRL_VER, SVN, v)
#endif

/* --- Register HW_USDHC_HOST_CTRL_VER, field VVN
 *
 * Vendor Version Number:  These status bits are reserved for the vendor version number. The
 * Host Driver shall not use this status.  01 Freescale uSDHC Version 1.1  others) Reserved
 */

#define BP_USDHC_HOST_CTRL_VER_VVN      8
#define BM_USDHC_HOST_CTRL_VER_VVN      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_USDHC_HOST_CTRL_VER_VVN(v)   ((((reg32_t) v) << 8) & BM_USDHC_HOST_CTRL_VER_VVN)
#else
#define BF_USDHC_HOST_CTRL_VER_VVN(v)   (((v) << 8) & BM_USDHC_HOST_CTRL_VER_VVN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_USDHC_HOST_CTRL_VER_VVN(v)   BF_CS1(USDHC_HOST_CTRL_VER, VVN, v)
#endif



/*!
 * @brief All USDHC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_usdhc_ds_addr_t DS_ADDR; //!< DMA System Address
    volatile hw_usdhc_blk_att_t BLK_ATT; //!< Block Attributes
    volatile hw_usdhc_cmd_arg_t CMD_ARG; //!< Command Argument
    volatile hw_usdhc_cmd_xfr_typ_t CMD_XFR_TYP; //!< Command Transfer Type
    volatile hw_usdhc_cmd_rsp0_t CMD_RSP0; //!< Command Response0
    volatile hw_usdhc_cmd_rsp1_t CMD_RSP1; //!< Command Response1
    volatile hw_usdhc_cmd_rsp2_t CMD_RSP2; //!< Command Response2
    volatile hw_usdhc_cmd_rsp3_t CMD_RSP3; //!< Command Response3
    volatile hw_usdhc_data_buff_acc_port_t DATA_BUFF_ACC_PORT; //!< Data Buffer Access Port
    volatile hw_usdhc_pres_state_t PRES_STATE; //!< Present State
    volatile hw_usdhc_prot_ctrl_t PROT_CTRL; //!< Protocol Control
    volatile hw_usdhc_sys_ctrl_t SYS_CTRL; //!< System Control
    volatile hw_usdhc_int_status_t INT_STATUS; //!< Interrupt Status
    volatile hw_usdhc_int_status_en_t INT_STATUS_EN; //!< Interrupt Status Enable
    volatile hw_usdhc_int_signal_en_t INT_SIGNAL_EN; //!< Interrupt Signal Enable
    volatile hw_usdhc_autocmd12_err_status_t AUTOCMD12_ERR_STATUS; //!< Auto CMD12 Error Status
    volatile hw_usdhc_host_ctrl_cap_t HOST_CTRL_CAP; //!< Host Controller Capabilities
    volatile hw_usdhc_wtmk_lvl_t WTMK_LVL; //!< Watermark Level
    volatile hw_usdhc_mix_ctrl_t MIX_CTRL; //!< Mixer Control
    reg32_t _reserved0;
    volatile hw_usdhc_force_event_t FORCE_EVENT; //!< Force Event
    volatile hw_usdhc_adma_err_status_t ADMA_ERR_STATUS; //!< ADMA Error Status Register
    volatile hw_usdhc_adma_sys_addr_t ADMA_SYS_ADDR; //!< ADMA System Address
    reg32_t _reserved1;
    volatile hw_usdhc_dll_ctrl_t DLL_CTRL; //!< DLL (Delay Line) Control
    volatile hw_usdhc_dll_status_t DLL_STATUS; //!< DLL Status
    volatile hw_usdhc_clk_tune_ctrl_status_t CLK_TUNE_CTRL_STATUS; //!< CLK Tuning Control and Status
    reg32_t _reserved2[21];
    volatile hw_usdhc_vend_spec_t VEND_SPEC; //!< Vendor Specific Register
    volatile hw_usdhc_mmc_boot_t MMC_BOOT; //!< MMC Boot Register
    volatile hw_usdhc_vend_spec2_t VEND_SPEC2; //!< Vendor Specific 2 Register
    reg32_t _reserved3[12];
    volatile hw_usdhc_host_ctrl_ver_t HOST_CTRL_VER; //!< Host Controller Version
} hw_usdhc_t
#endif

//! @brief Macro to access all USDHC registers.
//! @param x USDHC instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USDHC(0)</code>.
#define HW_USDHC(x)     (*(volatile hw_usdhc_t *) REGS_USDHC_BASE(x))


#endif // _USDHC_H
