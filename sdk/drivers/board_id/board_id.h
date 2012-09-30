/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file board_id.h
 * @brief header file with board and chip defines to be included by all the tests/utils
 *
 */

#ifndef BOARD_ID_H_
#define BOARD_ID_H_

#include "registers/regsusbanalog.h"
#include "registers/regsocotp.h"

/*!
 * @brief FSL_BOARD_ID - Fused Freescale Reference Board ID
 *
 * Reset value: 0x00000000
 *
 * The FSL_BOARD_ID represents the fused board ID for Freescale Reference Boards.
 */
typedef union _fsl_board_id {
    reg32_t U;
    struct _fsl_board_id_bitfields {
        unsigned CHIP_REV_MINOR:8;  //!< [7:0] Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned CHIP_REV_MAJOR:8;  //!< [15:8] Fixed read-only value reflecting the MAJOR field of the RTL version.
        unsigned CHIP_TYPE_ID:8;    //!< [23:16] Fixed read-only value reflecting the CHIP_TYPE field of the RTL version.
        unsigned BOARD_REV:4;   //!< [27:24] Fixed read-only value reflecting the BOARD_REV field of the Board Version set in the OCOTP fuses.
        unsigned BOARD_TYPE_ID:4;   //!< [31:28] Fixed read-only value reflecting the BOARD_TYPE field of the Board Version set in the OCOTP fuses.
    } B;
} fsl_board_id_t;

// Get the FSL Board ID  (fsl_board_id_t)
fsl_board_id_t get_board_id(void);
// Get strings describing the various components of the FSL Board ID  (fsl_board_id_t)
void chip_name(char* const name, const uint32_t chip_id, const bool long_name_flag);
void chip_revision(char* const rev_str, const uint32_t major_rev, const uint32_t minor_rev);
void board_name(char* const name, const uint32_t board_id);
void board_revision(char* const name, const uint32_t board_rev);
void board_description(char* const desc);

void show_board_id(const fsl_board_id_t board_id, const char* const indent);

/* Chip Type */
#define CHIP_TYPE_MX6SL         0x60
#define CHIP_TYPE_MX6SDL        0x61
#define CHIP_TYPE_MX6DQ         0x63

/* Chip Major Revision */
#define CHIP_MAJOR_REV_TO1      0x00
#define CHIP_MAJOR_REV_TO2      0x01

/* Chip Minor Revision */
#define CHIP_MINOR_REV_DOT0     0x00
#define CHIP_MINOR_REV_DOT1     0x01
#define CHIP_MINOR_REV_DOT2     0x02

/* Board Type */
#define BOARD_TYPE_DEFAULT      0x0
#define BOARD_TYPE_SABRE_AI     0x1
#define BOARD_TYPE_SMART_DEVICE 0x2
#define BOARD_TYPE_SABRE_LITE   0x3
#define BOARD_TYPE_EVB          0x4
#define BOARD_TYPE_EVK          0x5

/* Board Revision */
#define BOARD_REVISION_DEFAULT	0x0
#define BOARD_REVISION_A	    0x1
#define BOARD_REVISION_B	    0x2
#define BOARD_REVISION_BX       0x3
#define BOARD_REVISION_C        0x4

#if defined(CHIP_MX6SL)
#define CHIP_TYPE        CHIP_TYPE_MX6SL
#elif defined(CHIP_MX6SDL)
#define CHIP_TYPE        CHIP_TYPE_MX6SDL
#elif defined(CHIP_MX6DQ)
#define CHIP_TYPE        CHIP_TYPE_MX6DQ
#else
#error Need to define a chip type
#endif

#if defined(BOARD_SABRE_AI)
#define BOARD_TYPE            BOARD_TYPE_SABRE_AI
#elif defined(BOARD_SMART_DEVICE)
#define BOARD_TYPE            BOARD_TYPE_SMART_DEVICE
#elif defined(BOARD_SABRE_LITE)
#define BOARD_TYPE            BOARD_TYPE_SABRE_LITE
#elif defined(BOARD_EVB)
#define BOARD_TYPE            BOARD_TYPE_EVB
#elif defined(BOARD_EVK)
#define BOARD_TYPE            BOARD_TYPE_EVK
#else
#error Need to define a board type
#endif

#if defined(BOARD_REV_B)
#define BOARD_REVISION        BOARD_REVISION_B
#elif defined(BOARD_REV_A)
#define BOARD_REVISION        BOARD_REVISION_A
#else
#error Need to define a board revision
#endif

/* --- Register HW_USB_ANALOG_DIGPROG, field CHIP_TYPE[23:16] (RO)
 *
 * Fixed read-only value reflecting the CHIP_TYPE field of the RTL version.
 */

#define BP_USB_ANALOG_DIGPROG_CHIP_TYPE      (16)   //!< Bit position for USB_ANALOG_DIGPROG_CHIP_TYPE.
#define BM_USB_ANALOG_DIGPROG_CHIP_TYPE      (0x00ff0000)   //!< Bit mask for USB_ANALOG_DIGPROG_CHIP_TYPE.

//! @brief Get value of USB_ANALOG_DIGPROG_CHIP_TYPE from a register value.
#define BG_USB_ANALOG_DIGPROG_CHIP_TYPE(r)   (((r) & BM_USB_ANALOG_DIGPROG_CHIP_TYPE) >> BP_USB_ANALOG_DIGPROG_CHIP_TYPE)

/* --- Register HW_USB_ANALOG_DIGPROG, field MAJOR_REV[15:8] (RO)
 *
 * Fixed read-only value reflecting the MAJOR_REV field of the RTL version.
 */

#define BP_USB_ANALOG_DIGPROG_MAJOR_REV      (8)    //!< Bit position for USB_ANALOG_DIGPROG_MAJOR_REV.
#define BM_USB_ANALOG_DIGPROG_MAJOR_REV      (0x0000ff00)   //!< Bit mask for USB_ANALOG_DIGPROG_MAJOR_REV.

//! @brief Get value of USB_ANALOG_DIGPROG_MAJOR_REV from a register value.
#define BG_USB_ANALOG_DIGPROG_MAJOR_REV(r)   (((r) & BM_USB_ANALOG_DIGPROG_MAJOR_REV) >> BP_USB_ANALOG_DIGPROG_MAJOR_REV)

/*!
 * @brief HW_OCOTP_GP1 - Value of OTP Bank4 Word6 (HW Capabilities) (RW)
 *
 * Reset value: 0x00000000
 *
 * Copied from the OTP automatically after reset. Can be re-loaded by setting
 * HW_OCOTP_CTRL[RELOAD_SHADOWS]  Shadowed memory mapped access to OTP Bank 4, word 6 (ADDR = 0x26).
 * EXAMPLE   Empty Example.
 */
#define HW_OCOTP_GP1_BANK      4
#define HW_OCOTP_GP1_ROW       6

/* --- Register HW_OCOTP_GP1, field BOARD_TYPE[15:12] (RO)
 *
 * Fixed read-only value reflecting the BOARD_TYPE field of the Board Version set in the OCOTP fuses.
 */

#define BP_OCOTP_GP1_BOARD_TYPE      (12)   //!< Bit position for OCOTP_GP1_BOARD_TYPE.
#define BM_OCOTP_GP1_BOARD_TYPE      (0x0000f000)   //!< Bit mask for OCOTP_GP1_BOARD_TYPE.

//! @brief Get value of OCOTP_GP1_CHIP_TYPE from a register value.
#define BG_OCOTP_GP1_BOARD_TYPE(r)   (((r) & BM_OCOTP_GP1_BOARD_TYPE) >> BP_OCOTP_GP1_BOARD_TYPE)

/* --- Register HW_OCOTP_GP1, field BOARD_REV[11:8] (RO)
 *
 * Fixed read-only value reflecting the BOARD_REV field of the Board Version set in the OCOTP fuses.
 */

#define BP_OCOTP_GP1_BOARD_REV      (8) //!< Bit position for OCOTP_GP1_BOARD_REV.
#define BM_OCOTP_GP1_BOARD_REV      (0x00000f00)    //!< Bit mask for OCOTP_GP1_BOARD_REV.

//! @brief Get value of OCOTP_GP1_BOARD_REV from a register value.
#define BG_OCOTP_GP1_BOARD_REV(r)   (((r) & BM_OCOTP_GP1_BOARD_REV) >> BP_OCOTP_GP1_BOARD_REV)

#endif /*BOARD_ID_H_ */
