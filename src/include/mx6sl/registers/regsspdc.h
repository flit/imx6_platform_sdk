/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SPDC_REGISTERS_H__
#define __HW_SPDC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL SPDC registers defined in this header file.
 *
 * - HW_SPDC_EPD_DISP_TRIGGER - Display Trigger
 * - HW_SPDC_EPD_UPDATE_X_Y - Display Coordinate
 * - HW_SPDC_EPD_UPDATE_W_H - Display Area Size
 * - HW_SPDC_EPD_LUT_PARA_UPDATE - LUT Parameter Update
 * - HW_SPDC_EPD_OPERATE - Display Normal Operation
 * - HW_SPDC_EPD_PANEL_INIT_SET - SPDC Initial Setting
 * - HW_SPDC_EPD_TEMPER_SETTING - Environment Temperature
 * - HW_SPDC_EPD_NEXT_BUF - Next Frame Memory Address
 * - HW_SPDC_EPD_CURRENT_BUF - Current Frame Memory Address
 * - HW_SPDC_EPD_PREVIOUS_BUFF - Previous Frame Memory Address
 * - HW_SPDC_EPD_FRM_CNT_BUFF - Counter Frame Memory Address
 * - HW_SPDC_EPD_LUT_BUFF - LUT Memory Address
 * - HW_SPDC_EPD_INT_EN - Interrupt Enable
 * - HW_SPDC_EPD_INT_ST_CLR - Interrupt Status & Clear
 * - HW_SPDC_EPD_STATUS - SPDC Operation Status
 * - HW_SPDC_EPD_PANEL_TYPE_VER - Panel Type Related Information
 * - HW_SPDC_EPD_TCON_VER - SPDC IP Version
 * - HW_SPDC_EPD_SW_GATE_CLK - All Clock Gating Enable
 *
 * - hw_spdc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SPDC_BASE
#define HW_SPDC_INSTANCE_COUNT (1) //!< Number of instances of the SPDC module.
#define REGS_SPDC_BASE (0x020e8000) //!< Base address for SPDC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_DISP_TRIGGER - Display Trigger (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_disp_trigger
{
    reg32_t U;
    struct _hw_spdc_epd_disp_trigger_bitfields
    {
        unsigned DISP_TRIG : 1; //!< [0] EPD screen update trigger When set to "1" it will trigger TCON start to display image on panel.
        unsigned EPD_MODE : 3; //!< [3:1] EPD update mode setting 0x0 MODE_0 - It will be displayed with mode 0 waveform 0x1 MODE_1 - It will be displayed with mode 1 waveform 0x2 MODE_2 - It will be displayed with mode 2 waveform 0x3 MODE_3 - It will be displayed with mode 3 waveform 0x4 MODE_4 - It will be displayed with mode 4 waveform (High Speed Handwriting Mode) 0x5 MODE_5 - It will be displayed with mode 5 waveform 0x7 MODE_7 - It will be displayed with mode 7 waveform
        unsigned FLASH_SET : 1; //!< [4] Judge EPD screen update will be flashed or not in mode 7 0x0 NO_FLASH - It will not be flashed screen update in mode 7 0x1 FLASH - It will be flashed screen update in mode 7
        unsigned RESERVED0 : 27; //!< [31:5] Reserved
    } B;
} hw_spdc_epd_disp_trigger_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_DISP_TRIGGER register
 */
#define HW_SPDC_EPD_DISP_TRIGGER_ADDR      (REGS_SPDC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_DISP_TRIGGER           (*(volatile hw_spdc_epd_disp_trigger_t *) HW_SPDC_EPD_DISP_TRIGGER_ADDR)
#define HW_SPDC_EPD_DISP_TRIGGER_RD()      (HW_SPDC_EPD_DISP_TRIGGER.U)
#define HW_SPDC_EPD_DISP_TRIGGER_WR(v)     (HW_SPDC_EPD_DISP_TRIGGER.U = (v))
#define HW_SPDC_EPD_DISP_TRIGGER_SET(v)    (HW_SPDC_EPD_DISP_TRIGGER_WR(HW_SPDC_EPD_DISP_TRIGGER_RD() |  (v)))
#define HW_SPDC_EPD_DISP_TRIGGER_CLR(v)    (HW_SPDC_EPD_DISP_TRIGGER_WR(HW_SPDC_EPD_DISP_TRIGGER_RD() & ~(v)))
#define HW_SPDC_EPD_DISP_TRIGGER_TOG(v)    (HW_SPDC_EPD_DISP_TRIGGER_WR(HW_SPDC_EPD_DISP_TRIGGER_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_DISP_TRIGGER bitfields
 */

/* --- Register HW_SPDC_EPD_DISP_TRIGGER, field DISP_TRIG[0] (RW)
 *
 * EPD screen update trigger When set to "1" it will trigger TCON start to display image on panel.
 */

#define BP_SPDC_EPD_DISP_TRIGGER_DISP_TRIG      (0)      //!< Bit position for SPDC_EPD_DISP_TRIGGER_DISP_TRIG.
#define BM_SPDC_EPD_DISP_TRIGGER_DISP_TRIG      (0x00000001)  //!< Bit mask for SPDC_EPD_DISP_TRIGGER_DISP_TRIG.

//! @brief Get value of SPDC_EPD_DISP_TRIGGER_DISP_TRIG from a register value.
#define BG_SPDC_EPD_DISP_TRIGGER_DISP_TRIG(r)   (((r) & BM_SPDC_EPD_DISP_TRIGGER_DISP_TRIG) >> BP_SPDC_EPD_DISP_TRIGGER_DISP_TRIG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_DISP_TRIGGER_DISP_TRIG.
#define BF_SPDC_EPD_DISP_TRIGGER_DISP_TRIG(v)   ((((reg32_t) v) << BP_SPDC_EPD_DISP_TRIGGER_DISP_TRIG) & BM_SPDC_EPD_DISP_TRIGGER_DISP_TRIG)
#else
//! @brief Format value for bitfield SPDC_EPD_DISP_TRIGGER_DISP_TRIG.
#define BF_SPDC_EPD_DISP_TRIGGER_DISP_TRIG(v)   (((v) << BP_SPDC_EPD_DISP_TRIGGER_DISP_TRIG) & BM_SPDC_EPD_DISP_TRIGGER_DISP_TRIG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISP_TRIG field to a new value.
#define BW_SPDC_EPD_DISP_TRIGGER_DISP_TRIG(v)   (HW_SPDC_EPD_DISP_TRIGGER_WR((HW_SPDC_EPD_DISP_TRIGGER_RD() & ~BM_SPDC_EPD_DISP_TRIGGER_DISP_TRIG) | BF_SPDC_EPD_DISP_TRIGGER_DISP_TRIG(v)))
#endif

/* --- Register HW_SPDC_EPD_DISP_TRIGGER, field EPD_MODE[3:1] (RW)
 *
 * EPD update mode setting 0x0 MODE_0 - It will be displayed with mode 0 waveform 0x1 MODE_1 - It
 * will be displayed with mode 1 waveform 0x2 MODE_2 - It will be displayed with mode 2 waveform 0x3
 * MODE_3 - It will be displayed with mode 3 waveform 0x4 MODE_4 - It will be displayed with mode 4
 * waveform (High Speed Handwriting Mode) 0x5 MODE_5 - It will be displayed with mode 5 waveform 0x7
 * MODE_7 - It will be displayed with mode 7 waveform
 */

#define BP_SPDC_EPD_DISP_TRIGGER_EPD_MODE      (1)      //!< Bit position for SPDC_EPD_DISP_TRIGGER_EPD_MODE.
#define BM_SPDC_EPD_DISP_TRIGGER_EPD_MODE      (0x0000000e)  //!< Bit mask for SPDC_EPD_DISP_TRIGGER_EPD_MODE.

//! @brief Get value of SPDC_EPD_DISP_TRIGGER_EPD_MODE from a register value.
#define BG_SPDC_EPD_DISP_TRIGGER_EPD_MODE(r)   (((r) & BM_SPDC_EPD_DISP_TRIGGER_EPD_MODE) >> BP_SPDC_EPD_DISP_TRIGGER_EPD_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_DISP_TRIGGER_EPD_MODE.
#define BF_SPDC_EPD_DISP_TRIGGER_EPD_MODE(v)   ((((reg32_t) v) << BP_SPDC_EPD_DISP_TRIGGER_EPD_MODE) & BM_SPDC_EPD_DISP_TRIGGER_EPD_MODE)
#else
//! @brief Format value for bitfield SPDC_EPD_DISP_TRIGGER_EPD_MODE.
#define BF_SPDC_EPD_DISP_TRIGGER_EPD_MODE(v)   (((v) << BP_SPDC_EPD_DISP_TRIGGER_EPD_MODE) & BM_SPDC_EPD_DISP_TRIGGER_EPD_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EPD_MODE field to a new value.
#define BW_SPDC_EPD_DISP_TRIGGER_EPD_MODE(v)   (HW_SPDC_EPD_DISP_TRIGGER_WR((HW_SPDC_EPD_DISP_TRIGGER_RD() & ~BM_SPDC_EPD_DISP_TRIGGER_EPD_MODE) | BF_SPDC_EPD_DISP_TRIGGER_EPD_MODE(v)))
#endif

/* --- Register HW_SPDC_EPD_DISP_TRIGGER, field FLASH_SET[4] (RW)
 *
 * Judge EPD screen update will be flashed or not in mode 7 0x0 NO_FLASH - It will not be flashed
 * screen update in mode 7 0x1 FLASH - It will be flashed screen update in mode 7
 */

#define BP_SPDC_EPD_DISP_TRIGGER_FLASH_SET      (4)      //!< Bit position for SPDC_EPD_DISP_TRIGGER_FLASH_SET.
#define BM_SPDC_EPD_DISP_TRIGGER_FLASH_SET      (0x00000010)  //!< Bit mask for SPDC_EPD_DISP_TRIGGER_FLASH_SET.

//! @brief Get value of SPDC_EPD_DISP_TRIGGER_FLASH_SET from a register value.
#define BG_SPDC_EPD_DISP_TRIGGER_FLASH_SET(r)   (((r) & BM_SPDC_EPD_DISP_TRIGGER_FLASH_SET) >> BP_SPDC_EPD_DISP_TRIGGER_FLASH_SET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_DISP_TRIGGER_FLASH_SET.
#define BF_SPDC_EPD_DISP_TRIGGER_FLASH_SET(v)   ((((reg32_t) v) << BP_SPDC_EPD_DISP_TRIGGER_FLASH_SET) & BM_SPDC_EPD_DISP_TRIGGER_FLASH_SET)
#else
//! @brief Format value for bitfield SPDC_EPD_DISP_TRIGGER_FLASH_SET.
#define BF_SPDC_EPD_DISP_TRIGGER_FLASH_SET(v)   (((v) << BP_SPDC_EPD_DISP_TRIGGER_FLASH_SET) & BM_SPDC_EPD_DISP_TRIGGER_FLASH_SET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FLASH_SET field to a new value.
#define BW_SPDC_EPD_DISP_TRIGGER_FLASH_SET(v)   (HW_SPDC_EPD_DISP_TRIGGER_WR((HW_SPDC_EPD_DISP_TRIGGER_RD() & ~BM_SPDC_EPD_DISP_TRIGGER_FLASH_SET) | BF_SPDC_EPD_DISP_TRIGGER_FLASH_SET(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_UPDATE_X_Y - Display Coordinate (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_update_x_y
{
    reg32_t U;
    struct _hw_spdc_epd_update_x_y_bitfields
    {
        unsigned COORDINATE_Y : 12; //!< [11:0] Vertical coordinate of update region (minimum: 1) If image have rotated counterclockwise 90 Y should be 4n + 1 format where n is integer
        unsigned RESERVED0 : 4; //!< [15:12] Reserved
        unsigned COORDINATE_X : 12; //!< [27:16] Horizontal coordinate of update region (minimum: 1) X should be 4n + 1 format where n is integer
        unsigned RESERVED1 : 4; //!< [31:28] Reserved
    } B;
} hw_spdc_epd_update_x_y_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_UPDATE_X_Y register
 */
#define HW_SPDC_EPD_UPDATE_X_Y_ADDR      (REGS_SPDC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_UPDATE_X_Y           (*(volatile hw_spdc_epd_update_x_y_t *) HW_SPDC_EPD_UPDATE_X_Y_ADDR)
#define HW_SPDC_EPD_UPDATE_X_Y_RD()      (HW_SPDC_EPD_UPDATE_X_Y.U)
#define HW_SPDC_EPD_UPDATE_X_Y_WR(v)     (HW_SPDC_EPD_UPDATE_X_Y.U = (v))
#define HW_SPDC_EPD_UPDATE_X_Y_SET(v)    (HW_SPDC_EPD_UPDATE_X_Y_WR(HW_SPDC_EPD_UPDATE_X_Y_RD() |  (v)))
#define HW_SPDC_EPD_UPDATE_X_Y_CLR(v)    (HW_SPDC_EPD_UPDATE_X_Y_WR(HW_SPDC_EPD_UPDATE_X_Y_RD() & ~(v)))
#define HW_SPDC_EPD_UPDATE_X_Y_TOG(v)    (HW_SPDC_EPD_UPDATE_X_Y_WR(HW_SPDC_EPD_UPDATE_X_Y_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_UPDATE_X_Y bitfields
 */

/* --- Register HW_SPDC_EPD_UPDATE_X_Y, field COORDINATE_Y[11:0] (RW)
 *
 * Vertical coordinate of update region (minimum: 1) If image have rotated counterclockwise 90 Y
 * should be 4n + 1 format where n is integer
 */

#define BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y      (0)      //!< Bit position for SPDC_EPD_UPDATE_X_Y_COORDINATE_Y.
#define BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y      (0x00000fff)  //!< Bit mask for SPDC_EPD_UPDATE_X_Y_COORDINATE_Y.

//! @brief Get value of SPDC_EPD_UPDATE_X_Y_COORDINATE_Y from a register value.
#define BG_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y(r)   (((r) & BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y) >> BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_UPDATE_X_Y_COORDINATE_Y.
#define BF_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y(v)   ((((reg32_t) v) << BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y) & BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y)
#else
//! @brief Format value for bitfield SPDC_EPD_UPDATE_X_Y_COORDINATE_Y.
#define BF_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y(v)   (((v) << BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y) & BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COORDINATE_Y field to a new value.
#define BW_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y(v)   (HW_SPDC_EPD_UPDATE_X_Y_WR((HW_SPDC_EPD_UPDATE_X_Y_RD() & ~BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y) | BF_SPDC_EPD_UPDATE_X_Y_COORDINATE_Y(v)))
#endif

/* --- Register HW_SPDC_EPD_UPDATE_X_Y, field COORDINATE_X[27:16] (RW)
 *
 * Horizontal coordinate of update region (minimum: 1) X should be 4n + 1 format where n is integer
 */

#define BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_X      (16)      //!< Bit position for SPDC_EPD_UPDATE_X_Y_COORDINATE_X.
#define BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_X      (0x0fff0000)  //!< Bit mask for SPDC_EPD_UPDATE_X_Y_COORDINATE_X.

//! @brief Get value of SPDC_EPD_UPDATE_X_Y_COORDINATE_X from a register value.
#define BG_SPDC_EPD_UPDATE_X_Y_COORDINATE_X(r)   (((r) & BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_X) >> BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_X)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_UPDATE_X_Y_COORDINATE_X.
#define BF_SPDC_EPD_UPDATE_X_Y_COORDINATE_X(v)   ((((reg32_t) v) << BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_X) & BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_X)
#else
//! @brief Format value for bitfield SPDC_EPD_UPDATE_X_Y_COORDINATE_X.
#define BF_SPDC_EPD_UPDATE_X_Y_COORDINATE_X(v)   (((v) << BP_SPDC_EPD_UPDATE_X_Y_COORDINATE_X) & BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_X)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COORDINATE_X field to a new value.
#define BW_SPDC_EPD_UPDATE_X_Y_COORDINATE_X(v)   (HW_SPDC_EPD_UPDATE_X_Y_WR((HW_SPDC_EPD_UPDATE_X_Y_RD() & ~BM_SPDC_EPD_UPDATE_X_Y_COORDINATE_X) | BF_SPDC_EPD_UPDATE_X_Y_COORDINATE_X(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_UPDATE_W_H - Display Area Size (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_update_w_h
{
    reg32_t U;
    struct _hw_spdc_epd_update_w_h_bitfields
    {
        unsigned HEIGHT : 12; //!< [11:0] Height of update region If image have rotated counterclockwise 90 L should be 4n format where n is integer
        unsigned RESERVED0 : 4; //!< [15:12] Reserved
        unsigned WIDTH : 12; //!< [27:16] Width of update region W should be 4n format where n is integer
        unsigned RESERVED1 : 4; //!< [31:28] Reserved
    } B;
} hw_spdc_epd_update_w_h_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_UPDATE_W_H register
 */
#define HW_SPDC_EPD_UPDATE_W_H_ADDR      (REGS_SPDC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_UPDATE_W_H           (*(volatile hw_spdc_epd_update_w_h_t *) HW_SPDC_EPD_UPDATE_W_H_ADDR)
#define HW_SPDC_EPD_UPDATE_W_H_RD()      (HW_SPDC_EPD_UPDATE_W_H.U)
#define HW_SPDC_EPD_UPDATE_W_H_WR(v)     (HW_SPDC_EPD_UPDATE_W_H.U = (v))
#define HW_SPDC_EPD_UPDATE_W_H_SET(v)    (HW_SPDC_EPD_UPDATE_W_H_WR(HW_SPDC_EPD_UPDATE_W_H_RD() |  (v)))
#define HW_SPDC_EPD_UPDATE_W_H_CLR(v)    (HW_SPDC_EPD_UPDATE_W_H_WR(HW_SPDC_EPD_UPDATE_W_H_RD() & ~(v)))
#define HW_SPDC_EPD_UPDATE_W_H_TOG(v)    (HW_SPDC_EPD_UPDATE_W_H_WR(HW_SPDC_EPD_UPDATE_W_H_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_UPDATE_W_H bitfields
 */

/* --- Register HW_SPDC_EPD_UPDATE_W_H, field HEIGHT[11:0] (RW)
 *
 * Height of update region If image have rotated counterclockwise 90 L should be 4n format where n
 * is integer
 */

#define BP_SPDC_EPD_UPDATE_W_H_HEIGHT      (0)      //!< Bit position for SPDC_EPD_UPDATE_W_H_HEIGHT.
#define BM_SPDC_EPD_UPDATE_W_H_HEIGHT      (0x00000fff)  //!< Bit mask for SPDC_EPD_UPDATE_W_H_HEIGHT.

//! @brief Get value of SPDC_EPD_UPDATE_W_H_HEIGHT from a register value.
#define BG_SPDC_EPD_UPDATE_W_H_HEIGHT(r)   (((r) & BM_SPDC_EPD_UPDATE_W_H_HEIGHT) >> BP_SPDC_EPD_UPDATE_W_H_HEIGHT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_UPDATE_W_H_HEIGHT.
#define BF_SPDC_EPD_UPDATE_W_H_HEIGHT(v)   ((((reg32_t) v) << BP_SPDC_EPD_UPDATE_W_H_HEIGHT) & BM_SPDC_EPD_UPDATE_W_H_HEIGHT)
#else
//! @brief Format value for bitfield SPDC_EPD_UPDATE_W_H_HEIGHT.
#define BF_SPDC_EPD_UPDATE_W_H_HEIGHT(v)   (((v) << BP_SPDC_EPD_UPDATE_W_H_HEIGHT) & BM_SPDC_EPD_UPDATE_W_H_HEIGHT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HEIGHT field to a new value.
#define BW_SPDC_EPD_UPDATE_W_H_HEIGHT(v)   (HW_SPDC_EPD_UPDATE_W_H_WR((HW_SPDC_EPD_UPDATE_W_H_RD() & ~BM_SPDC_EPD_UPDATE_W_H_HEIGHT) | BF_SPDC_EPD_UPDATE_W_H_HEIGHT(v)))
#endif

/* --- Register HW_SPDC_EPD_UPDATE_W_H, field WIDTH[27:16] (RW)
 *
 * Width of update region W should be 4n format where n is integer
 */

#define BP_SPDC_EPD_UPDATE_W_H_WIDTH      (16)      //!< Bit position for SPDC_EPD_UPDATE_W_H_WIDTH.
#define BM_SPDC_EPD_UPDATE_W_H_WIDTH      (0x0fff0000)  //!< Bit mask for SPDC_EPD_UPDATE_W_H_WIDTH.

//! @brief Get value of SPDC_EPD_UPDATE_W_H_WIDTH from a register value.
#define BG_SPDC_EPD_UPDATE_W_H_WIDTH(r)   (((r) & BM_SPDC_EPD_UPDATE_W_H_WIDTH) >> BP_SPDC_EPD_UPDATE_W_H_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_UPDATE_W_H_WIDTH.
#define BF_SPDC_EPD_UPDATE_W_H_WIDTH(v)   ((((reg32_t) v) << BP_SPDC_EPD_UPDATE_W_H_WIDTH) & BM_SPDC_EPD_UPDATE_W_H_WIDTH)
#else
//! @brief Format value for bitfield SPDC_EPD_UPDATE_W_H_WIDTH.
#define BF_SPDC_EPD_UPDATE_W_H_WIDTH(v)   (((v) << BP_SPDC_EPD_UPDATE_W_H_WIDTH) & BM_SPDC_EPD_UPDATE_W_H_WIDTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WIDTH field to a new value.
#define BW_SPDC_EPD_UPDATE_W_H_WIDTH(v)   (HW_SPDC_EPD_UPDATE_W_H_WR((HW_SPDC_EPD_UPDATE_W_H_RD() & ~BM_SPDC_EPD_UPDATE_W_H_WIDTH) | BF_SPDC_EPD_UPDATE_W_H_WIDTH(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_LUT_PARA_UPDATE - LUT Parameter Update (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_lut_para_update
{
    reg32_t U;
    struct _hw_spdc_epd_lut_para_update_bitfields
    {
        unsigned LUT_PARAMETER_UPDATED_VALUE : 8; //!< [7:0] The value of update LUT parameter
        unsigned LUT_PARAMETER_UPDATED_ADDR : 8; //!< [15:8] The address of updated LUT parameter
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_spdc_epd_lut_para_update_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_LUT_PARA_UPDATE register
 */
#define HW_SPDC_EPD_LUT_PARA_UPDATE_ADDR      (REGS_SPDC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_LUT_PARA_UPDATE           (*(volatile hw_spdc_epd_lut_para_update_t *) HW_SPDC_EPD_LUT_PARA_UPDATE_ADDR)
#define HW_SPDC_EPD_LUT_PARA_UPDATE_RD()      (HW_SPDC_EPD_LUT_PARA_UPDATE.U)
#define HW_SPDC_EPD_LUT_PARA_UPDATE_WR(v)     (HW_SPDC_EPD_LUT_PARA_UPDATE.U = (v))
#define HW_SPDC_EPD_LUT_PARA_UPDATE_SET(v)    (HW_SPDC_EPD_LUT_PARA_UPDATE_WR(HW_SPDC_EPD_LUT_PARA_UPDATE_RD() |  (v)))
#define HW_SPDC_EPD_LUT_PARA_UPDATE_CLR(v)    (HW_SPDC_EPD_LUT_PARA_UPDATE_WR(HW_SPDC_EPD_LUT_PARA_UPDATE_RD() & ~(v)))
#define HW_SPDC_EPD_LUT_PARA_UPDATE_TOG(v)    (HW_SPDC_EPD_LUT_PARA_UPDATE_WR(HW_SPDC_EPD_LUT_PARA_UPDATE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_LUT_PARA_UPDATE bitfields
 */

/* --- Register HW_SPDC_EPD_LUT_PARA_UPDATE, field LUT_PARAMETER_UPDATED_VALUE[7:0] (RW)
 *
 * The value of update LUT parameter
 */

#define BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE      (0)      //!< Bit position for SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE.
#define BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE      (0x000000ff)  //!< Bit mask for SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE.

//! @brief Get value of SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE from a register value.
#define BG_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE(r)   (((r) & BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE) >> BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE.
#define BF_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE(v)   ((((reg32_t) v) << BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE) & BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE)
#else
//! @brief Format value for bitfield SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE.
#define BF_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE(v)   (((v) << BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE) & BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_PARAMETER_UPDATED_VALUE field to a new value.
#define BW_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE(v)   (HW_SPDC_EPD_LUT_PARA_UPDATE_WR((HW_SPDC_EPD_LUT_PARA_UPDATE_RD() & ~BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE) | BF_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_VALUE(v)))
#endif

/* --- Register HW_SPDC_EPD_LUT_PARA_UPDATE, field LUT_PARAMETER_UPDATED_ADDR[15:8] (RW)
 *
 * The address of updated LUT parameter
 */

#define BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR      (8)      //!< Bit position for SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR.
#define BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR      (0x0000ff00)  //!< Bit mask for SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR.

//! @brief Get value of SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR from a register value.
#define BG_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR(r)   (((r) & BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR) >> BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR.
#define BF_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR(v)   ((((reg32_t) v) << BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR) & BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR)
#else
//! @brief Format value for bitfield SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR.
#define BF_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR(v)   (((v) << BP_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR) & BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_PARAMETER_UPDATED_ADDR field to a new value.
#define BW_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR(v)   (HW_SPDC_EPD_LUT_PARA_UPDATE_WR((HW_SPDC_EPD_LUT_PARA_UPDATE_RD() & ~BM_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR) | BF_SPDC_EPD_LUT_PARA_UPDATE_LUT_PARAMETER_UPDATED_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_OPERATE - Display Normal Operation (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_operate
{
    reg32_t U;
    struct _hw_spdc_epd_operate_bitfields
    {
        unsigned DISP_REFRESH : 1; //!< [0] Display refresh When set to "1" it will trigger TCON start to refresh panel screen base on DDR image data (current frame memory) with mode 0 waveform.
        unsigned DEEP_REFRESH : 1; //!< [1] Deep refresh (combine display reset and display refresh function) When set to "1" it will trigger TCON start to reset panel screen and automatic refresh panel screen base on DDR image data (current frame memory) with mode 0 waveform.
        unsigned DISP_RESET : 1; //!< [2] Display reset When set to "1" it will trigger TCON start to reset panel screen and automatic update next/current/previous frame memories according to flash LUT setting gray level.
        unsigned RESERVED0 : 28; //!< [30:3] Reserved
        unsigned SW_TCON_RESET : 1; //!< [31] Software TCON register reset When set to "1" it will trigger TCON start to reset all internal registers in TCON.
    } B;
} hw_spdc_epd_operate_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_OPERATE register
 */
#define HW_SPDC_EPD_OPERATE_ADDR      (REGS_SPDC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_OPERATE           (*(volatile hw_spdc_epd_operate_t *) HW_SPDC_EPD_OPERATE_ADDR)
#define HW_SPDC_EPD_OPERATE_RD()      (HW_SPDC_EPD_OPERATE.U)
#define HW_SPDC_EPD_OPERATE_WR(v)     (HW_SPDC_EPD_OPERATE.U = (v))
#define HW_SPDC_EPD_OPERATE_SET(v)    (HW_SPDC_EPD_OPERATE_WR(HW_SPDC_EPD_OPERATE_RD() |  (v)))
#define HW_SPDC_EPD_OPERATE_CLR(v)    (HW_SPDC_EPD_OPERATE_WR(HW_SPDC_EPD_OPERATE_RD() & ~(v)))
#define HW_SPDC_EPD_OPERATE_TOG(v)    (HW_SPDC_EPD_OPERATE_WR(HW_SPDC_EPD_OPERATE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_OPERATE bitfields
 */

/* --- Register HW_SPDC_EPD_OPERATE, field DISP_REFRESH[0] (RW)
 *
 * Display refresh When set to "1" it will trigger TCON start to refresh panel screen base on DDR
 * image data (current frame memory) with mode 0 waveform.
 */

#define BP_SPDC_EPD_OPERATE_DISP_REFRESH      (0)      //!< Bit position for SPDC_EPD_OPERATE_DISP_REFRESH.
#define BM_SPDC_EPD_OPERATE_DISP_REFRESH      (0x00000001)  //!< Bit mask for SPDC_EPD_OPERATE_DISP_REFRESH.

//! @brief Get value of SPDC_EPD_OPERATE_DISP_REFRESH from a register value.
#define BG_SPDC_EPD_OPERATE_DISP_REFRESH(r)   (((r) & BM_SPDC_EPD_OPERATE_DISP_REFRESH) >> BP_SPDC_EPD_OPERATE_DISP_REFRESH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_OPERATE_DISP_REFRESH.
#define BF_SPDC_EPD_OPERATE_DISP_REFRESH(v)   ((((reg32_t) v) << BP_SPDC_EPD_OPERATE_DISP_REFRESH) & BM_SPDC_EPD_OPERATE_DISP_REFRESH)
#else
//! @brief Format value for bitfield SPDC_EPD_OPERATE_DISP_REFRESH.
#define BF_SPDC_EPD_OPERATE_DISP_REFRESH(v)   (((v) << BP_SPDC_EPD_OPERATE_DISP_REFRESH) & BM_SPDC_EPD_OPERATE_DISP_REFRESH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISP_REFRESH field to a new value.
#define BW_SPDC_EPD_OPERATE_DISP_REFRESH(v)   (HW_SPDC_EPD_OPERATE_WR((HW_SPDC_EPD_OPERATE_RD() & ~BM_SPDC_EPD_OPERATE_DISP_REFRESH) | BF_SPDC_EPD_OPERATE_DISP_REFRESH(v)))
#endif

/* --- Register HW_SPDC_EPD_OPERATE, field DEEP_REFRESH[1] (RW)
 *
 * Deep refresh (combine display reset and display refresh function) When set to "1" it will trigger
 * TCON start to reset panel screen and automatic refresh panel screen base on DDR image data
 * (current frame memory) with mode 0 waveform.
 */

#define BP_SPDC_EPD_OPERATE_DEEP_REFRESH      (1)      //!< Bit position for SPDC_EPD_OPERATE_DEEP_REFRESH.
#define BM_SPDC_EPD_OPERATE_DEEP_REFRESH      (0x00000002)  //!< Bit mask for SPDC_EPD_OPERATE_DEEP_REFRESH.

//! @brief Get value of SPDC_EPD_OPERATE_DEEP_REFRESH from a register value.
#define BG_SPDC_EPD_OPERATE_DEEP_REFRESH(r)   (((r) & BM_SPDC_EPD_OPERATE_DEEP_REFRESH) >> BP_SPDC_EPD_OPERATE_DEEP_REFRESH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_OPERATE_DEEP_REFRESH.
#define BF_SPDC_EPD_OPERATE_DEEP_REFRESH(v)   ((((reg32_t) v) << BP_SPDC_EPD_OPERATE_DEEP_REFRESH) & BM_SPDC_EPD_OPERATE_DEEP_REFRESH)
#else
//! @brief Format value for bitfield SPDC_EPD_OPERATE_DEEP_REFRESH.
#define BF_SPDC_EPD_OPERATE_DEEP_REFRESH(v)   (((v) << BP_SPDC_EPD_OPERATE_DEEP_REFRESH) & BM_SPDC_EPD_OPERATE_DEEP_REFRESH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEEP_REFRESH field to a new value.
#define BW_SPDC_EPD_OPERATE_DEEP_REFRESH(v)   (HW_SPDC_EPD_OPERATE_WR((HW_SPDC_EPD_OPERATE_RD() & ~BM_SPDC_EPD_OPERATE_DEEP_REFRESH) | BF_SPDC_EPD_OPERATE_DEEP_REFRESH(v)))
#endif

/* --- Register HW_SPDC_EPD_OPERATE, field DISP_RESET[2] (RW)
 *
 * Display reset When set to "1" it will trigger TCON start to reset panel screen and automatic
 * update next/current/previous frame memories according to flash LUT setting gray level.
 */

#define BP_SPDC_EPD_OPERATE_DISP_RESET      (2)      //!< Bit position for SPDC_EPD_OPERATE_DISP_RESET.
#define BM_SPDC_EPD_OPERATE_DISP_RESET      (0x00000004)  //!< Bit mask for SPDC_EPD_OPERATE_DISP_RESET.

//! @brief Get value of SPDC_EPD_OPERATE_DISP_RESET from a register value.
#define BG_SPDC_EPD_OPERATE_DISP_RESET(r)   (((r) & BM_SPDC_EPD_OPERATE_DISP_RESET) >> BP_SPDC_EPD_OPERATE_DISP_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_OPERATE_DISP_RESET.
#define BF_SPDC_EPD_OPERATE_DISP_RESET(v)   ((((reg32_t) v) << BP_SPDC_EPD_OPERATE_DISP_RESET) & BM_SPDC_EPD_OPERATE_DISP_RESET)
#else
//! @brief Format value for bitfield SPDC_EPD_OPERATE_DISP_RESET.
#define BF_SPDC_EPD_OPERATE_DISP_RESET(v)   (((v) << BP_SPDC_EPD_OPERATE_DISP_RESET) & BM_SPDC_EPD_OPERATE_DISP_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISP_RESET field to a new value.
#define BW_SPDC_EPD_OPERATE_DISP_RESET(v)   (HW_SPDC_EPD_OPERATE_WR((HW_SPDC_EPD_OPERATE_RD() & ~BM_SPDC_EPD_OPERATE_DISP_RESET) | BF_SPDC_EPD_OPERATE_DISP_RESET(v)))
#endif

/* --- Register HW_SPDC_EPD_OPERATE, field SW_TCON_RESET[31] (RW)
 *
 * Software TCON register reset When set to "1" it will trigger TCON start to reset all internal
 * registers in TCON.
 */

#define BP_SPDC_EPD_OPERATE_SW_TCON_RESET      (31)      //!< Bit position for SPDC_EPD_OPERATE_SW_TCON_RESET.
#define BM_SPDC_EPD_OPERATE_SW_TCON_RESET      (0x80000000)  //!< Bit mask for SPDC_EPD_OPERATE_SW_TCON_RESET.

//! @brief Get value of SPDC_EPD_OPERATE_SW_TCON_RESET from a register value.
#define BG_SPDC_EPD_OPERATE_SW_TCON_RESET(r)   (((r) & BM_SPDC_EPD_OPERATE_SW_TCON_RESET) >> BP_SPDC_EPD_OPERATE_SW_TCON_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_OPERATE_SW_TCON_RESET.
#define BF_SPDC_EPD_OPERATE_SW_TCON_RESET(v)   ((((reg32_t) v) << BP_SPDC_EPD_OPERATE_SW_TCON_RESET) & BM_SPDC_EPD_OPERATE_SW_TCON_RESET)
#else
//! @brief Format value for bitfield SPDC_EPD_OPERATE_SW_TCON_RESET.
#define BF_SPDC_EPD_OPERATE_SW_TCON_RESET(v)   (((v) << BP_SPDC_EPD_OPERATE_SW_TCON_RESET) & BM_SPDC_EPD_OPERATE_SW_TCON_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_TCON_RESET field to a new value.
#define BW_SPDC_EPD_OPERATE_SW_TCON_RESET(v)   (HW_SPDC_EPD_OPERATE_WR((HW_SPDC_EPD_OPERATE_RD() & ~BM_SPDC_EPD_OPERATE_SW_TCON_RESET) | BF_SPDC_EPD_OPERATE_SW_TCON_RESET(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_PANEL_INIT_SET - SPDC Initial Setting (RW)
 *
 * Reset value: 0x00002000
 *
 * Resolution Mapping Table of Gray Mode        Resolution [4:0] (binary)  Resolution Setting (Width
 * x Height)  Portrait / Landscape    11000  Display resolution is 600 x 800.  Portrait    11001
 * Display resolution is 768 x 1024  Portrait    11010  Reserved  Reserved    11011  Display
 * resolution is 600 x 1024.  Portrait    11100  Display resolution is 825 x 1200  Portrait    11101
 * Display resolution is 1024 x 1280  Portrait    11110  Display resolution is 1200 x 1600  Portrait
 * 10000  Display resolution is 800 x 1024  Portrait    10001  Display resolution is 825 x 1280
 * Portrait    10010  Display resolution is 800 x 1280  Portrait    10011  Display resolution is 768
 * x 1280  Portrait    10100  Display resolution is 960 x 1280  Portrait    00000  Display
 * resolution is 800 x 600.  Landscape    00001  Display resolution is 1024 x 768  Landscape
 * 00010  Reserved  Reserved    00011  Display resolution is 1024 x 600.  Landscape    00100
 * Display resolution is 1200 x 825  Landscape    00101  Display resolution is 1280 x 1024
 * Landscape    00110  Display resolution is 1600 x 1200  Landscape    00111  Display resolution is
 * 1024 x 800  Landscape    01000  Display resolution is 1280 x 825  Landscape    01001  Display
 * resolution is 1280 x 800  Landscape    01010  Display resolution is 1280 x 768  Landscape
 * 01011  Display resolution is 1280 x 960  Landscape    Others  Display resolution is 800 x 600.
 * Landscape       Resolution Mapping Table of RGBW Mode        Resolution [4:0] (binary)
 * Resolution Setting (Width x Height)  Portrait / Landscape    11000  Display resolution is 300 x
 * 400.  Portrait    11001  Display resolution is 384 x 512  Portrait    11010  Reserved  Reserved
 * 11011  Display resolution is 300 x 512.  Portrait    11100  Reserved  Reserved    11101  Display
 * resolution is 512 x 640  Portrait    11110  Display resolution is 600 x 800  Portrait    10000
 * Display resolution is 400 x 512  Portrait    10001  Reserved  Reserved    10010  Display
 * resolution is 400 x 640  Portrait    10011  Display resolution is 384 x 640  Portrait    10100
 * Display resolution is 480 x 640  Portrait    00000  Display resolution is 400 x 300.  Landscape
 * 00001  Display resolution is 512 x 384  Landscape    00010  Reserved  Reserved    00011  Display
 * resolution is 512 x 300.  Landscape    00100  Reserved  Reserved    00101  Display resolution is
 * 640 x 512  Landscape    00110  Display resolution is 800 x 600  Landscape    00111  Display
 * resolution is 512 x 400  Landscape    01000  Reserved  Reserved    01001  Display resolution is
 * 640 x 400  Landscape    01010  Display resolution is 640 x 384  Landscape    01011  Display
 * resolution is 640 x 480  Landscape    Others  Display resolution is 400 x 300.  Landscape
 */
typedef union _hw_spdc_epd_panel_init_set
{
    reg32_t U;
    struct _hw_spdc_epd_panel_init_set_bitfields
    {
        unsigned YOE_POL : 1; //!< [0] Set the YOE signal's polarity of gate driver IC 0x0 LOW_ENABLE -Gate pulse outputs low enable. 0x1 HIGH_ENABLE -Gate pulse outputs high enable.
        unsigned DUAL_GATE : 1; //!< [1] Set to enable the panel type of dual gate driver 0x0 SINGLE_GATE -Single gate driver (support gate driver K7900). 0x1 DOUBLE_GATE -Double side gate driver (support gate driver MEXI2300)
        unsigned RESOLUTION : 5; //!< [6:2] Set the panel resolution GRAY_MODE - Please reference the Table 45-12 RGBW_MODE -Please reference the Table 45-13
        unsigned UD : 1; //!< [7] Select gate driver IC scanning direction up or down. 0x0 DOWN -Scan down; First line=Gm◊ Gm-1 ◊…◊ G2 ◊ Last line=G1. 0x1 UP -Scan up; First line=G1 ◊ G2 ◊ … ◊ Gm-1 ◊ Last line=Gm.
        unsigned RL : 1; //!< [8] Select source driver IC scanning direction right or left. 0x0 LEFT -Shift left; First data=Sn ◊ Sn-1 ◊ …◊ S2 ◊ Last data=S1. 0x1 RIGHT -Shift right: First data=S1◊ S2 ◊ …◊ Sn-1 ◊ Last data=Sn.
        unsigned DATA_FILTER_N : 1; //!< [9] Automatic filter input image pixel data base on the display mode 0x0 ENABLE_AUTO_DATA_FILTER -Filter input data 16-step gray to 4-step gray data for mode 2 and mode 3. Filter input data 16-step gray to 2-step gray for mode 4 and mode 5 0x1 DISABLE_AUTO_DATA_FILTER- It will not be automatic filter the input image data
        unsigned POWER_READY : 1; //!< [10] Driver IC power ready signal 0x0 POWER_NOT_READY - The TCON will be hold wait for driver IC power turn on finish 0x1 POWER_READY - The TCON will into IDLE state and user cloud send the display trigger
        unsigned RGBW_MODE_EN : 1; //!< [11] RGBW color mode enable 0x0 DISABLE_RGBW_MODE -It will enable TCON into gray mode 0x1 ENABLE_ RGBW_MODE - It will enable TCON into RGBW mode
        unsigned RESERVED0 : 1; //!< [12] Reserved
        unsigned HBURST_LEN_EN : 1; //!< [13] HBURST length enable 0x0 DISABLE_HBURST - AHB2AXI gasket ignores the HBURST_LEN[3:0]. The AHB INCR will be converted to AXI Singles. 0x1 ENABLE_HBURST -AHB2AXI gasket treats the HBURST_LEN [3:0] as the valid length for current INCR transfer.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved
    } B;
} hw_spdc_epd_panel_init_set_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_PANEL_INIT_SET register
 */
#define HW_SPDC_EPD_PANEL_INIT_SET_ADDR      (REGS_SPDC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_PANEL_INIT_SET           (*(volatile hw_spdc_epd_panel_init_set_t *) HW_SPDC_EPD_PANEL_INIT_SET_ADDR)
#define HW_SPDC_EPD_PANEL_INIT_SET_RD()      (HW_SPDC_EPD_PANEL_INIT_SET.U)
#define HW_SPDC_EPD_PANEL_INIT_SET_WR(v)     (HW_SPDC_EPD_PANEL_INIT_SET.U = (v))
#define HW_SPDC_EPD_PANEL_INIT_SET_SET(v)    (HW_SPDC_EPD_PANEL_INIT_SET_WR(HW_SPDC_EPD_PANEL_INIT_SET_RD() |  (v)))
#define HW_SPDC_EPD_PANEL_INIT_SET_CLR(v)    (HW_SPDC_EPD_PANEL_INIT_SET_WR(HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~(v)))
#define HW_SPDC_EPD_PANEL_INIT_SET_TOG(v)    (HW_SPDC_EPD_PANEL_INIT_SET_WR(HW_SPDC_EPD_PANEL_INIT_SET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_PANEL_INIT_SET bitfields
 */

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field YOE_POL[0] (RW)
 *
 * Set the YOE signal's polarity of gate driver IC 0x0 LOW_ENABLE -Gate pulse outputs low enable.
 * 0x1 HIGH_ENABLE -Gate pulse outputs high enable.
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_YOE_POL      (0)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_YOE_POL.
#define BM_SPDC_EPD_PANEL_INIT_SET_YOE_POL      (0x00000001)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_YOE_POL.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_YOE_POL from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_YOE_POL(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_YOE_POL) >> BP_SPDC_EPD_PANEL_INIT_SET_YOE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_YOE_POL.
#define BF_SPDC_EPD_PANEL_INIT_SET_YOE_POL(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_YOE_POL) & BM_SPDC_EPD_PANEL_INIT_SET_YOE_POL)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_YOE_POL.
#define BF_SPDC_EPD_PANEL_INIT_SET_YOE_POL(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_YOE_POL) & BM_SPDC_EPD_PANEL_INIT_SET_YOE_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the YOE_POL field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_YOE_POL(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_YOE_POL) | BF_SPDC_EPD_PANEL_INIT_SET_YOE_POL(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field DUAL_GATE[1] (RW)
 *
 * Set to enable the panel type of dual gate driver 0x0 SINGLE_GATE -Single gate driver (support
 * gate driver K7900). 0x1 DOUBLE_GATE -Double side gate driver (support gate driver MEXI2300)
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE      (1)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_DUAL_GATE.
#define BM_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE      (0x00000002)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_DUAL_GATE.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_DUAL_GATE from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE) >> BP_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_DUAL_GATE.
#define BF_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE) & BM_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_DUAL_GATE.
#define BF_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE) & BM_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DUAL_GATE field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE) | BF_SPDC_EPD_PANEL_INIT_SET_DUAL_GATE(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field RESOLUTION[6:2] (RW)
 *
 * Set the panel resolution GRAY_MODE - Please reference the Table 45-12 RGBW_MODE -Please reference
 * the Table 45-13
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_RESOLUTION      (2)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_RESOLUTION.
#define BM_SPDC_EPD_PANEL_INIT_SET_RESOLUTION      (0x0000007c)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_RESOLUTION.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_RESOLUTION from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_RESOLUTION(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_RESOLUTION) >> BP_SPDC_EPD_PANEL_INIT_SET_RESOLUTION)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_RESOLUTION.
#define BF_SPDC_EPD_PANEL_INIT_SET_RESOLUTION(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_RESOLUTION) & BM_SPDC_EPD_PANEL_INIT_SET_RESOLUTION)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_RESOLUTION.
#define BF_SPDC_EPD_PANEL_INIT_SET_RESOLUTION(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_RESOLUTION) & BM_SPDC_EPD_PANEL_INIT_SET_RESOLUTION)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESOLUTION field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_RESOLUTION(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_RESOLUTION) | BF_SPDC_EPD_PANEL_INIT_SET_RESOLUTION(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field UD[7] (RW)
 *
 * Select gate driver IC scanning direction up or down. 0x0 DOWN -Scan down; First line=Gm◊ Gm-1 ◊…◊
 * G2 ◊ Last line=G1. 0x1 UP -Scan up; First line=G1 ◊ G2 ◊ … ◊ Gm-1 ◊ Last line=Gm.
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_UD      (7)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_UD.
#define BM_SPDC_EPD_PANEL_INIT_SET_UD      (0x00000080)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_UD.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_UD from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_UD(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_UD) >> BP_SPDC_EPD_PANEL_INIT_SET_UD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_UD.
#define BF_SPDC_EPD_PANEL_INIT_SET_UD(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_UD) & BM_SPDC_EPD_PANEL_INIT_SET_UD)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_UD.
#define BF_SPDC_EPD_PANEL_INIT_SET_UD(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_UD) & BM_SPDC_EPD_PANEL_INIT_SET_UD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UD field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_UD(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_UD) | BF_SPDC_EPD_PANEL_INIT_SET_UD(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field RL[8] (RW)
 *
 * Select source driver IC scanning direction right or left. 0x0 LEFT -Shift left; First data=Sn ◊
 * Sn-1 ◊ …◊ S2 ◊ Last data=S1. 0x1 RIGHT -Shift right: First data=S1◊ S2 ◊ …◊ Sn-1 ◊ Last data=Sn.
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_RL      (8)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_RL.
#define BM_SPDC_EPD_PANEL_INIT_SET_RL      (0x00000100)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_RL.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_RL from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_RL(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_RL) >> BP_SPDC_EPD_PANEL_INIT_SET_RL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_RL.
#define BF_SPDC_EPD_PANEL_INIT_SET_RL(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_RL) & BM_SPDC_EPD_PANEL_INIT_SET_RL)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_RL.
#define BF_SPDC_EPD_PANEL_INIT_SET_RL(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_RL) & BM_SPDC_EPD_PANEL_INIT_SET_RL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_RL(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_RL) | BF_SPDC_EPD_PANEL_INIT_SET_RL(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field DATA_FILTER_N[9] (RW)
 *
 * Automatic filter input image pixel data base on the display mode 0x0 ENABLE_AUTO_DATA_FILTER
 * -Filter input data 16-step gray to 4-step gray data for mode 2 and mode 3. Filter input data
 * 16-step gray to 2-step gray for mode 4 and mode 5 0x1 DISABLE_AUTO_DATA_FILTER- It will not be
 * automatic filter the input image data
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N      (9)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N.
#define BM_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N      (0x00000200)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N) >> BP_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N.
#define BF_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N) & BM_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N.
#define BF_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N) & BM_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_FILTER_N field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N) | BF_SPDC_EPD_PANEL_INIT_SET_DATA_FILTER_N(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field POWER_READY[10] (RW)
 *
 * Driver IC power ready signal 0x0 POWER_NOT_READY - The TCON will be hold wait for driver IC power
 * turn on finish 0x1 POWER_READY - The TCON will into IDLE state and user cloud send the display
 * trigger
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_POWER_READY      (10)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_POWER_READY.
#define BM_SPDC_EPD_PANEL_INIT_SET_POWER_READY      (0x00000400)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_POWER_READY.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_POWER_READY from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_POWER_READY(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_POWER_READY) >> BP_SPDC_EPD_PANEL_INIT_SET_POWER_READY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_POWER_READY.
#define BF_SPDC_EPD_PANEL_INIT_SET_POWER_READY(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_POWER_READY) & BM_SPDC_EPD_PANEL_INIT_SET_POWER_READY)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_POWER_READY.
#define BF_SPDC_EPD_PANEL_INIT_SET_POWER_READY(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_POWER_READY) & BM_SPDC_EPD_PANEL_INIT_SET_POWER_READY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_READY field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_POWER_READY(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_POWER_READY) | BF_SPDC_EPD_PANEL_INIT_SET_POWER_READY(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field RGBW_MODE_EN[11] (RW)
 *
 * RGBW color mode enable 0x0 DISABLE_RGBW_MODE -It will enable TCON into gray mode 0x1 ENABLE_
 * RGBW_MODE - It will enable TCON into RGBW mode
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN      (11)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN.
#define BM_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN      (0x00000800)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN) >> BP_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN.
#define BF_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN) & BM_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN.
#define BF_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN) & BM_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RGBW_MODE_EN field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN) | BF_SPDC_EPD_PANEL_INIT_SET_RGBW_MODE_EN(v)))
#endif

/* --- Register HW_SPDC_EPD_PANEL_INIT_SET, field HBURST_LEN_EN[13] (RW)
 *
 * HBURST length enable 0x0 DISABLE_HBURST - AHB2AXI gasket ignores the HBURST_LEN[3:0]. The AHB
 * INCR will be converted to AXI Singles. 0x1 ENABLE_HBURST -AHB2AXI gasket treats the HBURST_LEN
 * [3:0] as the valid length for current INCR transfer.
 */

#define BP_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN      (13)      //!< Bit position for SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN.
#define BM_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN      (0x00002000)  //!< Bit mask for SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN.

//! @brief Get value of SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN from a register value.
#define BG_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN(r)   (((r) & BM_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN) >> BP_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN.
#define BF_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN) & BM_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN.
#define BF_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN(v)   (((v) << BP_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN) & BM_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HBURST_LEN_EN field to a new value.
#define BW_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN(v)   (HW_SPDC_EPD_PANEL_INIT_SET_WR((HW_SPDC_EPD_PANEL_INIT_SET_RD() & ~BM_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN) | BF_SPDC_EPD_PANEL_INIT_SET_HBURST_LEN_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_TEMPER_SETTING - Environment Temperature (RW)
 *
 * Reset value: 0x00000000
 *
 * Temperature Mapping Table       TEMPERATURE [8:0] (binary)  Thermal Sensor Temperature (oC)
 * 110010010  -55    :  :    111111110  -1    111111111  -0.5    000000000  0    000000001  0.5
 * 000000010  1    :  :    001111111  63.5    :  :
 */
typedef union _hw_spdc_epd_temper_setting
{
    reg32_t U;
    struct _hw_spdc_epd_temper_setting_bitfields
    {
        unsigned TEMPERATURE : 9; //!< [8:0] Update TCON temperature information Temperature Information is used to indicate the temperature of operating environment. TCON IP will search the LUT for a suitable value according to the temperature information. The Table 45-15 is shown the temperature mapping table. (in two's complement format)
        unsigned RESERVED0 : 23; //!< [31:9] Reserved
    } B;
} hw_spdc_epd_temper_setting_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_TEMPER_SETTING register
 */
#define HW_SPDC_EPD_TEMPER_SETTING_ADDR      (REGS_SPDC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_TEMPER_SETTING           (*(volatile hw_spdc_epd_temper_setting_t *) HW_SPDC_EPD_TEMPER_SETTING_ADDR)
#define HW_SPDC_EPD_TEMPER_SETTING_RD()      (HW_SPDC_EPD_TEMPER_SETTING.U)
#define HW_SPDC_EPD_TEMPER_SETTING_WR(v)     (HW_SPDC_EPD_TEMPER_SETTING.U = (v))
#define HW_SPDC_EPD_TEMPER_SETTING_SET(v)    (HW_SPDC_EPD_TEMPER_SETTING_WR(HW_SPDC_EPD_TEMPER_SETTING_RD() |  (v)))
#define HW_SPDC_EPD_TEMPER_SETTING_CLR(v)    (HW_SPDC_EPD_TEMPER_SETTING_WR(HW_SPDC_EPD_TEMPER_SETTING_RD() & ~(v)))
#define HW_SPDC_EPD_TEMPER_SETTING_TOG(v)    (HW_SPDC_EPD_TEMPER_SETTING_WR(HW_SPDC_EPD_TEMPER_SETTING_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_TEMPER_SETTING bitfields
 */

/* --- Register HW_SPDC_EPD_TEMPER_SETTING, field TEMPERATURE[8:0] (RW)
 *
 * Update TCON temperature information Temperature Information is used to indicate the temperature
 * of operating environment. TCON IP will search the LUT for a suitable value according to the
 * temperature information. The Table 45-15 is shown the temperature mapping table. (in two's
 * complement format)
 */

#define BP_SPDC_EPD_TEMPER_SETTING_TEMPERATURE      (0)      //!< Bit position for SPDC_EPD_TEMPER_SETTING_TEMPERATURE.
#define BM_SPDC_EPD_TEMPER_SETTING_TEMPERATURE      (0x000001ff)  //!< Bit mask for SPDC_EPD_TEMPER_SETTING_TEMPERATURE.

//! @brief Get value of SPDC_EPD_TEMPER_SETTING_TEMPERATURE from a register value.
#define BG_SPDC_EPD_TEMPER_SETTING_TEMPERATURE(r)   (((r) & BM_SPDC_EPD_TEMPER_SETTING_TEMPERATURE) >> BP_SPDC_EPD_TEMPER_SETTING_TEMPERATURE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_TEMPER_SETTING_TEMPERATURE.
#define BF_SPDC_EPD_TEMPER_SETTING_TEMPERATURE(v)   ((((reg32_t) v) << BP_SPDC_EPD_TEMPER_SETTING_TEMPERATURE) & BM_SPDC_EPD_TEMPER_SETTING_TEMPERATURE)
#else
//! @brief Format value for bitfield SPDC_EPD_TEMPER_SETTING_TEMPERATURE.
#define BF_SPDC_EPD_TEMPER_SETTING_TEMPERATURE(v)   (((v) << BP_SPDC_EPD_TEMPER_SETTING_TEMPERATURE) & BM_SPDC_EPD_TEMPER_SETTING_TEMPERATURE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEMPERATURE field to a new value.
#define BW_SPDC_EPD_TEMPER_SETTING_TEMPERATURE(v)   (HW_SPDC_EPD_TEMPER_SETTING_WR((HW_SPDC_EPD_TEMPER_SETTING_RD() & ~BM_SPDC_EPD_TEMPER_SETTING_TEMPERATURE) | BF_SPDC_EPD_TEMPER_SETTING_TEMPERATURE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_NEXT_BUF - Next Frame Memory Address (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_next_buf
{
    reg32_t U;
    struct _hw_spdc_epd_next_buf_bitfields
    {
        unsigned NEXT_FRAME_MEMORY_ADDR : 32; //!< [31:0] Update next frame memory address of DDR memory The next frame memory address should be word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
    } B;
} hw_spdc_epd_next_buf_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_NEXT_BUF register
 */
#define HW_SPDC_EPD_NEXT_BUF_ADDR      (REGS_SPDC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_NEXT_BUF           (*(volatile hw_spdc_epd_next_buf_t *) HW_SPDC_EPD_NEXT_BUF_ADDR)
#define HW_SPDC_EPD_NEXT_BUF_RD()      (HW_SPDC_EPD_NEXT_BUF.U)
#define HW_SPDC_EPD_NEXT_BUF_WR(v)     (HW_SPDC_EPD_NEXT_BUF.U = (v))
#define HW_SPDC_EPD_NEXT_BUF_SET(v)    (HW_SPDC_EPD_NEXT_BUF_WR(HW_SPDC_EPD_NEXT_BUF_RD() |  (v)))
#define HW_SPDC_EPD_NEXT_BUF_CLR(v)    (HW_SPDC_EPD_NEXT_BUF_WR(HW_SPDC_EPD_NEXT_BUF_RD() & ~(v)))
#define HW_SPDC_EPD_NEXT_BUF_TOG(v)    (HW_SPDC_EPD_NEXT_BUF_WR(HW_SPDC_EPD_NEXT_BUF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_NEXT_BUF bitfields
 */

/* --- Register HW_SPDC_EPD_NEXT_BUF, field NEXT_FRAME_MEMORY_ADDR[31:0] (RW)
 *
 * Update next frame memory address of DDR memory The next frame memory address should be word-align
 * value, it means EPD TCON wills automatic truncate two bits of LSB.
 */

#define BP_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR      (0)      //!< Bit position for SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR.
#define BM_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR      (0xffffffff)  //!< Bit mask for SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR.

//! @brief Get value of SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR from a register value.
#define BG_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR(r)   (((r) & BM_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR) >> BP_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR(v)   ((((reg32_t) v) << BP_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR)
#else
//! @brief Format value for bitfield SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR(v)   (((v) << BP_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NEXT_FRAME_MEMORY_ADDR field to a new value.
#define BW_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR(v)   (HW_SPDC_EPD_NEXT_BUF_WR((HW_SPDC_EPD_NEXT_BUF_RD() & ~BM_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR) | BF_SPDC_EPD_NEXT_BUF_NEXT_FRAME_MEMORY_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_CURRENT_BUF - Current Frame Memory Address (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_current_buf
{
    reg32_t U;
    struct _hw_spdc_epd_current_buf_bitfields
    {
        unsigned CURRENT_FRAME_MEMORY_ADDR : 32; //!< [31:0] Update current frame memory address of DDR memory The current frame memory address should be word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
    } B;
} hw_spdc_epd_current_buf_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_CURRENT_BUF register
 */
#define HW_SPDC_EPD_CURRENT_BUF_ADDR      (REGS_SPDC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_CURRENT_BUF           (*(volatile hw_spdc_epd_current_buf_t *) HW_SPDC_EPD_CURRENT_BUF_ADDR)
#define HW_SPDC_EPD_CURRENT_BUF_RD()      (HW_SPDC_EPD_CURRENT_BUF.U)
#define HW_SPDC_EPD_CURRENT_BUF_WR(v)     (HW_SPDC_EPD_CURRENT_BUF.U = (v))
#define HW_SPDC_EPD_CURRENT_BUF_SET(v)    (HW_SPDC_EPD_CURRENT_BUF_WR(HW_SPDC_EPD_CURRENT_BUF_RD() |  (v)))
#define HW_SPDC_EPD_CURRENT_BUF_CLR(v)    (HW_SPDC_EPD_CURRENT_BUF_WR(HW_SPDC_EPD_CURRENT_BUF_RD() & ~(v)))
#define HW_SPDC_EPD_CURRENT_BUF_TOG(v)    (HW_SPDC_EPD_CURRENT_BUF_WR(HW_SPDC_EPD_CURRENT_BUF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_CURRENT_BUF bitfields
 */

/* --- Register HW_SPDC_EPD_CURRENT_BUF, field CURRENT_FRAME_MEMORY_ADDR[31:0] (RW)
 *
 * Update current frame memory address of DDR memory The current frame memory address should be
 * word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
 */

#define BP_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR      (0)      //!< Bit position for SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR.
#define BM_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR      (0xffffffff)  //!< Bit mask for SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR.

//! @brief Get value of SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR from a register value.
#define BG_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR(r)   (((r) & BM_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR) >> BP_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR(v)   ((((reg32_t) v) << BP_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR)
#else
//! @brief Format value for bitfield SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR(v)   (((v) << BP_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CURRENT_FRAME_MEMORY_ADDR field to a new value.
#define BW_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR(v)   (HW_SPDC_EPD_CURRENT_BUF_WR((HW_SPDC_EPD_CURRENT_BUF_RD() & ~BM_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR) | BF_SPDC_EPD_CURRENT_BUF_CURRENT_FRAME_MEMORY_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_PREVIOUS_BUFF - Previous Frame Memory Address (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_previous_buff
{
    reg32_t U;
    struct _hw_spdc_epd_previous_buff_bitfields
    {
        unsigned PREVIOUS_FRAME_MEMORY_ADDR : 32; //!< [31:0] Update previous frame memory address of DDR memory The previous frame memory address should be word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
    } B;
} hw_spdc_epd_previous_buff_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_PREVIOUS_BUFF register
 */
#define HW_SPDC_EPD_PREVIOUS_BUFF_ADDR      (REGS_SPDC_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_PREVIOUS_BUFF           (*(volatile hw_spdc_epd_previous_buff_t *) HW_SPDC_EPD_PREVIOUS_BUFF_ADDR)
#define HW_SPDC_EPD_PREVIOUS_BUFF_RD()      (HW_SPDC_EPD_PREVIOUS_BUFF.U)
#define HW_SPDC_EPD_PREVIOUS_BUFF_WR(v)     (HW_SPDC_EPD_PREVIOUS_BUFF.U = (v))
#define HW_SPDC_EPD_PREVIOUS_BUFF_SET(v)    (HW_SPDC_EPD_PREVIOUS_BUFF_WR(HW_SPDC_EPD_PREVIOUS_BUFF_RD() |  (v)))
#define HW_SPDC_EPD_PREVIOUS_BUFF_CLR(v)    (HW_SPDC_EPD_PREVIOUS_BUFF_WR(HW_SPDC_EPD_PREVIOUS_BUFF_RD() & ~(v)))
#define HW_SPDC_EPD_PREVIOUS_BUFF_TOG(v)    (HW_SPDC_EPD_PREVIOUS_BUFF_WR(HW_SPDC_EPD_PREVIOUS_BUFF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_PREVIOUS_BUFF bitfields
 */

/* --- Register HW_SPDC_EPD_PREVIOUS_BUFF, field PREVIOUS_FRAME_MEMORY_ADDR[31:0] (RW)
 *
 * Update previous frame memory address of DDR memory The previous frame memory address should be
 * word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
 */

#define BP_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR      (0)      //!< Bit position for SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR.
#define BM_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR      (0xffffffff)  //!< Bit mask for SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR.

//! @brief Get value of SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR from a register value.
#define BG_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR(r)   (((r) & BM_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR) >> BP_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR(v)   ((((reg32_t) v) << BP_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR)
#else
//! @brief Format value for bitfield SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR(v)   (((v) << BP_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PREVIOUS_FRAME_MEMORY_ADDR field to a new value.
#define BW_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR(v)   (HW_SPDC_EPD_PREVIOUS_BUFF_WR((HW_SPDC_EPD_PREVIOUS_BUFF_RD() & ~BM_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR) | BF_SPDC_EPD_PREVIOUS_BUFF_PREVIOUS_FRAME_MEMORY_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_FRM_CNT_BUFF - Counter Frame Memory Address (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_frm_cnt_buff
{
    reg32_t U;
    struct _hw_spdc_epd_frm_cnt_buff_bitfields
    {
        unsigned COUNTER_FRAME_MEMORY_ADDR : 32; //!< [31:0] Update counter frame memory address of DDR memory The counter frame memory address should be word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
    } B;
} hw_spdc_epd_frm_cnt_buff_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_FRM_CNT_BUFF register
 */
#define HW_SPDC_EPD_FRM_CNT_BUFF_ADDR      (REGS_SPDC_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_FRM_CNT_BUFF           (*(volatile hw_spdc_epd_frm_cnt_buff_t *) HW_SPDC_EPD_FRM_CNT_BUFF_ADDR)
#define HW_SPDC_EPD_FRM_CNT_BUFF_RD()      (HW_SPDC_EPD_FRM_CNT_BUFF.U)
#define HW_SPDC_EPD_FRM_CNT_BUFF_WR(v)     (HW_SPDC_EPD_FRM_CNT_BUFF.U = (v))
#define HW_SPDC_EPD_FRM_CNT_BUFF_SET(v)    (HW_SPDC_EPD_FRM_CNT_BUFF_WR(HW_SPDC_EPD_FRM_CNT_BUFF_RD() |  (v)))
#define HW_SPDC_EPD_FRM_CNT_BUFF_CLR(v)    (HW_SPDC_EPD_FRM_CNT_BUFF_WR(HW_SPDC_EPD_FRM_CNT_BUFF_RD() & ~(v)))
#define HW_SPDC_EPD_FRM_CNT_BUFF_TOG(v)    (HW_SPDC_EPD_FRM_CNT_BUFF_WR(HW_SPDC_EPD_FRM_CNT_BUFF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_FRM_CNT_BUFF bitfields
 */

/* --- Register HW_SPDC_EPD_FRM_CNT_BUFF, field COUNTER_FRAME_MEMORY_ADDR[31:0] (RW)
 *
 * Update counter frame memory address of DDR memory The counter frame memory address should be
 * word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
 */

#define BP_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR      (0)      //!< Bit position for SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR.
#define BM_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR      (0xffffffff)  //!< Bit mask for SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR.

//! @brief Get value of SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR from a register value.
#define BG_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR(r)   (((r) & BM_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR) >> BP_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR(v)   ((((reg32_t) v) << BP_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR)
#else
//! @brief Format value for bitfield SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR.
#define BF_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR(v)   (((v) << BP_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR) & BM_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COUNTER_FRAME_MEMORY_ADDR field to a new value.
#define BW_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR(v)   (HW_SPDC_EPD_FRM_CNT_BUFF_WR((HW_SPDC_EPD_FRM_CNT_BUFF_RD() & ~BM_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR) | BF_SPDC_EPD_FRM_CNT_BUFF_COUNTER_FRAME_MEMORY_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_LUT_BUFF - LUT Memory Address (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_lut_buff
{
    reg32_t U;
    struct _hw_spdc_epd_lut_buff_bitfields
    {
        unsigned LUT_MEMORY_ADDR : 32; //!< [31:0] Update LUT memory address of DDR memory The LUT memory address should be word-align value, it means EPD TCON wills automatic truncate two bits of LSB.
    } B;
} hw_spdc_epd_lut_buff_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_LUT_BUFF register
 */
#define HW_SPDC_EPD_LUT_BUFF_ADDR      (REGS_SPDC_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_LUT_BUFF           (*(volatile hw_spdc_epd_lut_buff_t *) HW_SPDC_EPD_LUT_BUFF_ADDR)
#define HW_SPDC_EPD_LUT_BUFF_RD()      (HW_SPDC_EPD_LUT_BUFF.U)
#define HW_SPDC_EPD_LUT_BUFF_WR(v)     (HW_SPDC_EPD_LUT_BUFF.U = (v))
#define HW_SPDC_EPD_LUT_BUFF_SET(v)    (HW_SPDC_EPD_LUT_BUFF_WR(HW_SPDC_EPD_LUT_BUFF_RD() |  (v)))
#define HW_SPDC_EPD_LUT_BUFF_CLR(v)    (HW_SPDC_EPD_LUT_BUFF_WR(HW_SPDC_EPD_LUT_BUFF_RD() & ~(v)))
#define HW_SPDC_EPD_LUT_BUFF_TOG(v)    (HW_SPDC_EPD_LUT_BUFF_WR(HW_SPDC_EPD_LUT_BUFF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_LUT_BUFF bitfields
 */

/* --- Register HW_SPDC_EPD_LUT_BUFF, field LUT_MEMORY_ADDR[31:0] (RW)
 *
 * Update LUT memory address of DDR memory The LUT memory address should be word-align value, it
 * means EPD TCON wills automatic truncate two bits of LSB.
 */

#define BP_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR      (0)      //!< Bit position for SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR.
#define BM_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR      (0xffffffff)  //!< Bit mask for SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR.

//! @brief Get value of SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR from a register value.
#define BG_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR(r)   (((r) & BM_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR) >> BP_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR.
#define BF_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR(v)   ((((reg32_t) v) << BP_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR) & BM_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR)
#else
//! @brief Format value for bitfield SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR.
#define BF_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR(v)   (((v) << BP_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR) & BM_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_MEMORY_ADDR field to a new value.
#define BW_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR(v)   (HW_SPDC_EPD_LUT_BUFF_WR((HW_SPDC_EPD_LUT_BUFF_RD() & ~BM_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR) | BF_SPDC_EPD_LUT_BUFF_LUT_MEMORY_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_INT_EN - Interrupt Enable (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_int_en
{
    reg32_t U;
    struct _hw_spdc_epd_int_en_bitfields
    {
        unsigned UPDATE_FINISH_INT_EN : 1; //!< [0] Screen update finish interrupt signal mask 0x0 DISABLE_UPDATE_FINISH_INTERRUPT - Disable Frame Update Finish Interrupt 0x1 ENABLE_UPDATE_FINISH_INTERRUPT - Enable Frame Update Finish Interrupt
        unsigned TCON_INIT_FINISH_INT_EN : 1; //!< [1] TCON initialization finish interrupt signal mask 0x0 DISABLE_TCON_INIT_FINISH_INTERRUPT - Disable TCON Initialization Finish Interrupt 0x1 ENABLE_TCON_INIT_FINISH_INTERRUPT - Enable TCON Initialization Interrupt
        unsigned LUT_DOWNLOAD_FINISH_INT_EN : 1; //!< [2] LUT initial download finish interrupt signal mask 0x0 DISABLE_LUT_DOWNLOAD_FINISH_INTERRUPT - Disable LUT initial Download Finish Interrupt 0x1 ENABLE_LUT_DOWNLOAD_FINISH_INTERRUPT - Enable LUT initial Download Finish Interrupt
        unsigned TCON_ERROR_INT_EN : 1; //!< [3] Error interrupt signal mask 0x0 DISABLE_ERRPR_INTERRUPT - Disable Error Interrupt 0x1 ENABLE_ERRPR_INTERRUPT - Enable Error Interrupt
        unsigned RESERVED0 : 28; //!< [31:4] Reserved
    } B;
} hw_spdc_epd_int_en_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_INT_EN register
 */
#define HW_SPDC_EPD_INT_EN_ADDR      (REGS_SPDC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_INT_EN           (*(volatile hw_spdc_epd_int_en_t *) HW_SPDC_EPD_INT_EN_ADDR)
#define HW_SPDC_EPD_INT_EN_RD()      (HW_SPDC_EPD_INT_EN.U)
#define HW_SPDC_EPD_INT_EN_WR(v)     (HW_SPDC_EPD_INT_EN.U = (v))
#define HW_SPDC_EPD_INT_EN_SET(v)    (HW_SPDC_EPD_INT_EN_WR(HW_SPDC_EPD_INT_EN_RD() |  (v)))
#define HW_SPDC_EPD_INT_EN_CLR(v)    (HW_SPDC_EPD_INT_EN_WR(HW_SPDC_EPD_INT_EN_RD() & ~(v)))
#define HW_SPDC_EPD_INT_EN_TOG(v)    (HW_SPDC_EPD_INT_EN_WR(HW_SPDC_EPD_INT_EN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_INT_EN bitfields
 */

/* --- Register HW_SPDC_EPD_INT_EN, field UPDATE_FINISH_INT_EN[0] (RW)
 *
 * Screen update finish interrupt signal mask 0x0 DISABLE_UPDATE_FINISH_INTERRUPT - Disable Frame
 * Update Finish Interrupt 0x1 ENABLE_UPDATE_FINISH_INTERRUPT - Enable Frame Update Finish Interrupt
 */

#define BP_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN      (0)      //!< Bit position for SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN.
#define BM_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN      (0x00000001)  //!< Bit mask for SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN.

//! @brief Get value of SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN from a register value.
#define BG_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN(r)   (((r) & BM_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN) >> BP_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN.
#define BF_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN) & BM_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN.
#define BF_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN(v)   (((v) << BP_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN) & BM_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE_FINISH_INT_EN field to a new value.
#define BW_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN(v)   (HW_SPDC_EPD_INT_EN_WR((HW_SPDC_EPD_INT_EN_RD() & ~BM_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN) | BF_SPDC_EPD_INT_EN_UPDATE_FINISH_INT_EN(v)))
#endif

/* --- Register HW_SPDC_EPD_INT_EN, field TCON_INIT_FINISH_INT_EN[1] (RW)
 *
 * TCON initialization finish interrupt signal mask 0x0 DISABLE_TCON_INIT_FINISH_INTERRUPT - Disable
 * TCON Initialization Finish Interrupt 0x1 ENABLE_TCON_INIT_FINISH_INTERRUPT - Enable TCON
 * Initialization Interrupt
 */

#define BP_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN      (1)      //!< Bit position for SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN.
#define BM_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN      (0x00000002)  //!< Bit mask for SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN.

//! @brief Get value of SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN from a register value.
#define BG_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN(r)   (((r) & BM_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN) >> BP_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN.
#define BF_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN) & BM_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN.
#define BF_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN(v)   (((v) << BP_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN) & BM_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCON_INIT_FINISH_INT_EN field to a new value.
#define BW_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN(v)   (HW_SPDC_EPD_INT_EN_WR((HW_SPDC_EPD_INT_EN_RD() & ~BM_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN) | BF_SPDC_EPD_INT_EN_TCON_INIT_FINISH_INT_EN(v)))
#endif

/* --- Register HW_SPDC_EPD_INT_EN, field LUT_DOWNLOAD_FINISH_INT_EN[2] (RW)
 *
 * LUT initial download finish interrupt signal mask 0x0 DISABLE_LUT_DOWNLOAD_FINISH_INTERRUPT -
 * Disable LUT initial Download Finish Interrupt 0x1 ENABLE_LUT_DOWNLOAD_FINISH_INTERRUPT - Enable
 * LUT initial Download Finish Interrupt
 */

#define BP_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN      (2)      //!< Bit position for SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN.
#define BM_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN      (0x00000004)  //!< Bit mask for SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN.

//! @brief Get value of SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN from a register value.
#define BG_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN(r)   (((r) & BM_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN) >> BP_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN.
#define BF_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN) & BM_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN.
#define BF_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN(v)   (((v) << BP_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN) & BM_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_DOWNLOAD_FINISH_INT_EN field to a new value.
#define BW_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN(v)   (HW_SPDC_EPD_INT_EN_WR((HW_SPDC_EPD_INT_EN_RD() & ~BM_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN) | BF_SPDC_EPD_INT_EN_LUT_DOWNLOAD_FINISH_INT_EN(v)))
#endif

/* --- Register HW_SPDC_EPD_INT_EN, field TCON_ERROR_INT_EN[3] (RW)
 *
 * Error interrupt signal mask 0x0 DISABLE_ERRPR_INTERRUPT - Disable Error Interrupt 0x1
 * ENABLE_ERRPR_INTERRUPT - Enable Error Interrupt
 */

#define BP_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN      (3)      //!< Bit position for SPDC_EPD_INT_EN_TCON_ERROR_INT_EN.
#define BM_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN      (0x00000008)  //!< Bit mask for SPDC_EPD_INT_EN_TCON_ERROR_INT_EN.

//! @brief Get value of SPDC_EPD_INT_EN_TCON_ERROR_INT_EN from a register value.
#define BG_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN(r)   (((r) & BM_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN) >> BP_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_EN_TCON_ERROR_INT_EN.
#define BF_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN) & BM_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_EN_TCON_ERROR_INT_EN.
#define BF_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN(v)   (((v) << BP_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN) & BM_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCON_ERROR_INT_EN field to a new value.
#define BW_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN(v)   (HW_SPDC_EPD_INT_EN_WR((HW_SPDC_EPD_INT_EN_RD() & ~BM_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN) | BF_SPDC_EPD_INT_EN_TCON_ERROR_INT_EN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_INT_ST_CLR - Interrupt Status & Clear (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_int_st_clr
{
    reg32_t U;
    struct _hw_spdc_epd_int_st_clr_bitfields
    {
        unsigned UPDATE_FINISH_INT_CLR : 1; //!< [0] Screen update finish interrupt signal clear When set to "1" it will trigger TCON start to clear screen update finish interrupt.
        unsigned TCON_INIT_FINISH_INT_CLR : 1; //!< [1] TCON initialization finish interrupt signal clear When set to "1" it will trigger TCON start to clear TCON initialization finish interrupt.
        unsigned LUT_DOWNLOAD_FINISH_INT_CLR : 1; //!< [2] LUT initial download finish interrupt signal clear When set to "1" it will trigger TCON start to clear LUT download finish interrupt.
        unsigned TCON_ERROR_INT_CLR : 1; //!< [3] Error interrupt signal clear When set to "1" it will trigger TCON start to clear error interrupt.
        unsigned RESERVED0 : 28; //!< [31:4] Reserved
    } B;
} hw_spdc_epd_int_st_clr_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_INT_ST_CLR register
 */
#define HW_SPDC_EPD_INT_ST_CLR_ADDR      (REGS_SPDC_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_INT_ST_CLR           (*(volatile hw_spdc_epd_int_st_clr_t *) HW_SPDC_EPD_INT_ST_CLR_ADDR)
#define HW_SPDC_EPD_INT_ST_CLR_RD()      (HW_SPDC_EPD_INT_ST_CLR.U)
#define HW_SPDC_EPD_INT_ST_CLR_WR(v)     (HW_SPDC_EPD_INT_ST_CLR.U = (v))
#define HW_SPDC_EPD_INT_ST_CLR_SET(v)    (HW_SPDC_EPD_INT_ST_CLR_WR(HW_SPDC_EPD_INT_ST_CLR_RD() |  (v)))
#define HW_SPDC_EPD_INT_ST_CLR_CLR(v)    (HW_SPDC_EPD_INT_ST_CLR_WR(HW_SPDC_EPD_INT_ST_CLR_RD() & ~(v)))
#define HW_SPDC_EPD_INT_ST_CLR_TOG(v)    (HW_SPDC_EPD_INT_ST_CLR_WR(HW_SPDC_EPD_INT_ST_CLR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_INT_ST_CLR bitfields
 */

/* --- Register HW_SPDC_EPD_INT_ST_CLR, field UPDATE_FINISH_INT_CLR[0] (RW)
 *
 * Screen update finish interrupt signal clear When set to "1" it will trigger TCON start to clear
 * screen update finish interrupt.
 */

#define BP_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR      (0)      //!< Bit position for SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR.
#define BM_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR      (0x00000001)  //!< Bit mask for SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR.

//! @brief Get value of SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR from a register value.
#define BG_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR(r)   (((r) & BM_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR) >> BP_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR(v)   (((v) << BP_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UPDATE_FINISH_INT_CLR field to a new value.
#define BW_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR(v)   (HW_SPDC_EPD_INT_ST_CLR_WR((HW_SPDC_EPD_INT_ST_CLR_RD() & ~BM_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR) | BF_SPDC_EPD_INT_ST_CLR_UPDATE_FINISH_INT_CLR(v)))
#endif

/* --- Register HW_SPDC_EPD_INT_ST_CLR, field TCON_INIT_FINISH_INT_CLR[1] (RW)
 *
 * TCON initialization finish interrupt signal clear When set to "1" it will trigger TCON start to
 * clear TCON initialization finish interrupt.
 */

#define BP_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR      (1)      //!< Bit position for SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR.
#define BM_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR      (0x00000002)  //!< Bit mask for SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR.

//! @brief Get value of SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR from a register value.
#define BG_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR(r)   (((r) & BM_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR) >> BP_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR(v)   (((v) << BP_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCON_INIT_FINISH_INT_CLR field to a new value.
#define BW_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR(v)   (HW_SPDC_EPD_INT_ST_CLR_WR((HW_SPDC_EPD_INT_ST_CLR_RD() & ~BM_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR) | BF_SPDC_EPD_INT_ST_CLR_TCON_INIT_FINISH_INT_CLR(v)))
#endif

/* --- Register HW_SPDC_EPD_INT_ST_CLR, field LUT_DOWNLOAD_FINISH_INT_CLR[2] (RW)
 *
 * LUT initial download finish interrupt signal clear When set to "1" it will trigger TCON start to
 * clear LUT download finish interrupt.
 */

#define BP_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR      (2)      //!< Bit position for SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR.
#define BM_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR      (0x00000004)  //!< Bit mask for SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR.

//! @brief Get value of SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR from a register value.
#define BG_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR(r)   (((r) & BM_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR) >> BP_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR(v)   (((v) << BP_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_DOWNLOAD_FINISH_INT_CLR field to a new value.
#define BW_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR(v)   (HW_SPDC_EPD_INT_ST_CLR_WR((HW_SPDC_EPD_INT_ST_CLR_RD() & ~BM_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR) | BF_SPDC_EPD_INT_ST_CLR_LUT_DOWNLOAD_FINISH_INT_CLR(v)))
#endif

/* --- Register HW_SPDC_EPD_INT_ST_CLR, field TCON_ERROR_INT_CLR[3] (RW)
 *
 * Error interrupt signal clear When set to "1" it will trigger TCON start to clear error interrupt.
 */

#define BP_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR      (3)      //!< Bit position for SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR.
#define BM_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR      (0x00000008)  //!< Bit mask for SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR.

//! @brief Get value of SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR from a register value.
#define BG_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR(r)   (((r) & BM_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR) >> BP_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR(v)   ((((reg32_t) v) << BP_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR)
#else
//! @brief Format value for bitfield SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR.
#define BF_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR(v)   (((v) << BP_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR) & BM_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TCON_ERROR_INT_CLR field to a new value.
#define BW_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR(v)   (HW_SPDC_EPD_INT_ST_CLR_WR((HW_SPDC_EPD_INT_ST_CLR_RD() & ~BM_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR) | BF_SPDC_EPD_INT_ST_CLR_TCON_ERROR_INT_CLR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_STATUS - SPDC Operation Status (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_status
{
    reg32_t U;
    struct _hw_spdc_epd_status_bitfields
    {
        unsigned EPD_TCON_BUSY_N : 1; //!< [0] EPD TCON busy status 0x0 BUSY_STATUS - Panel is under updating 0x1 NOT_BUSY_STATUS - Panel update finished
        unsigned RESERVED0 : 2; //!< [2:1] Reserved
        unsigned LUT_CHECKSUM : 1; //!< [3] LUT checksum status 0x0 CHECKSUM_FAIL - LUT checksum fail 0x1 CHECKSUM_SUCCESS - LUT checksum pass
        unsigned EPD_TCON_STATUS : 4; //!< [7:4] EPD TCON IP status 0x0 RST_STATUS - EPD TCON during reset phase 0x1 WAIT_FOR_CHECKSUM_AND_POWER_READY_STATUS - EPD TCON is hold for waiting checksum pass and driver IC power ready 0x2 CHECKSUM_FAIL_BUT_POWER_READY_STATUS - EPD TCON checksum fail but driver IC power ready. User need reboot EPD TCON again and double check LUT correct or not. 0x3 INITIAL_WORKING_MEMORY_STATUS - EPD TCON automatic initial all working memories 0x4 IDLE_STATUS - EPD TCON idle status 0x7 MOVE_NEXT_TO_CURRENT_MEMORY_STATUS - EPD TCON automatic move next frame memory data to current frame memory. 0x9 LUT_UPDATE_STATUS - EPD TCON automatic update the waveform LUT 0xA PANEL_UPDATE_STATUS - EPD TCON is driving the panel screen.
        unsigned RESERVED1 : 24; //!< [31:8] Reserved
    } B;
} hw_spdc_epd_status_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_STATUS register
 */
#define HW_SPDC_EPD_STATUS_ADDR      (REGS_SPDC_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_STATUS           (*(volatile hw_spdc_epd_status_t *) HW_SPDC_EPD_STATUS_ADDR)
#define HW_SPDC_EPD_STATUS_RD()      (HW_SPDC_EPD_STATUS.U)
#endif

/*
 * constants & macros for individual SPDC_EPD_STATUS bitfields
 */

/* --- Register HW_SPDC_EPD_STATUS, field EPD_TCON_BUSY_N[0] (RO)
 *
 * EPD TCON busy status 0x0 BUSY_STATUS - Panel is under updating 0x1 NOT_BUSY_STATUS - Panel update
 * finished
 */

#define BP_SPDC_EPD_STATUS_EPD_TCON_BUSY_N      (0)      //!< Bit position for SPDC_EPD_STATUS_EPD_TCON_BUSY_N.
#define BM_SPDC_EPD_STATUS_EPD_TCON_BUSY_N      (0x00000001)  //!< Bit mask for SPDC_EPD_STATUS_EPD_TCON_BUSY_N.

//! @brief Get value of SPDC_EPD_STATUS_EPD_TCON_BUSY_N from a register value.
#define BG_SPDC_EPD_STATUS_EPD_TCON_BUSY_N(r)   (((r) & BM_SPDC_EPD_STATUS_EPD_TCON_BUSY_N) >> BP_SPDC_EPD_STATUS_EPD_TCON_BUSY_N)

/* --- Register HW_SPDC_EPD_STATUS, field LUT_CHECKSUM[3] (RO)
 *
 * LUT checksum status 0x0 CHECKSUM_FAIL - LUT checksum fail 0x1 CHECKSUM_SUCCESS - LUT checksum
 * pass
 */

#define BP_SPDC_EPD_STATUS_LUT_CHECKSUM      (3)      //!< Bit position for SPDC_EPD_STATUS_LUT_CHECKSUM.
#define BM_SPDC_EPD_STATUS_LUT_CHECKSUM      (0x00000008)  //!< Bit mask for SPDC_EPD_STATUS_LUT_CHECKSUM.

//! @brief Get value of SPDC_EPD_STATUS_LUT_CHECKSUM from a register value.
#define BG_SPDC_EPD_STATUS_LUT_CHECKSUM(r)   (((r) & BM_SPDC_EPD_STATUS_LUT_CHECKSUM) >> BP_SPDC_EPD_STATUS_LUT_CHECKSUM)

/* --- Register HW_SPDC_EPD_STATUS, field EPD_TCON_STATUS[7:4] (RO)
 *
 * EPD TCON IP status 0x0 RST_STATUS - EPD TCON during reset phase 0x1
 * WAIT_FOR_CHECKSUM_AND_POWER_READY_STATUS - EPD TCON is hold for waiting checksum pass and driver
 * IC power ready 0x2 CHECKSUM_FAIL_BUT_POWER_READY_STATUS - EPD TCON checksum fail but driver IC
 * power ready. User need reboot EPD TCON again and double check LUT correct or not. 0x3
 * INITIAL_WORKING_MEMORY_STATUS - EPD TCON automatic initial all working memories 0x4 IDLE_STATUS -
 * EPD TCON idle status 0x7 MOVE_NEXT_TO_CURRENT_MEMORY_STATUS - EPD TCON automatic move next frame
 * memory data to current frame memory. 0x9 LUT_UPDATE_STATUS - EPD TCON automatic update the
 * waveform LUT 0xA PANEL_UPDATE_STATUS - EPD TCON is driving the panel screen.
 */

#define BP_SPDC_EPD_STATUS_EPD_TCON_STATUS      (4)      //!< Bit position for SPDC_EPD_STATUS_EPD_TCON_STATUS.
#define BM_SPDC_EPD_STATUS_EPD_TCON_STATUS      (0x000000f0)  //!< Bit mask for SPDC_EPD_STATUS_EPD_TCON_STATUS.

//! @brief Get value of SPDC_EPD_STATUS_EPD_TCON_STATUS from a register value.
#define BG_SPDC_EPD_STATUS_EPD_TCON_STATUS(r)   (((r) & BM_SPDC_EPD_STATUS_EPD_TCON_STATUS) >> BP_SPDC_EPD_STATUS_EPD_TCON_STATUS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_PANEL_TYPE_VER - Panel Type Related Information (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_panel_type_ver
{
    reg32_t U;
    struct _hw_spdc_epd_panel_type_ver_bitfields
    {
        unsigned PRODUCT_AND_DRIVER_ID : 16; //!< [15:0] Product ID and driver ID, they are stand for different type of panel 0x0 A060SE02 - Panel type (AUO-K7900) 0x1 A090XE01 - Panel type (AUO-K7900) Others need to be defined
        unsigned LUT_VERSION : 8; //!< [23:16] LUT version, it stands for different version of driving waveform 0x0101 V308 - Driving waveform type 0x0102 V312 - Driving waveform type Others need to be defined
        unsigned EPD_PANEL_TYPE : 8; //!< [31:24] EPD panel type, it stands for different material type of film. 0x0 ERK_1_4_A01 - Material type of film 0x1 ERK_1_4_D01 - Material type of film 0x2 ERK_2_0_A01 - Material type of film Others need to be defined
    } B;
} hw_spdc_epd_panel_type_ver_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_PANEL_TYPE_VER register
 */
#define HW_SPDC_EPD_PANEL_TYPE_VER_ADDR      (REGS_SPDC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_PANEL_TYPE_VER           (*(volatile hw_spdc_epd_panel_type_ver_t *) HW_SPDC_EPD_PANEL_TYPE_VER_ADDR)
#define HW_SPDC_EPD_PANEL_TYPE_VER_RD()      (HW_SPDC_EPD_PANEL_TYPE_VER.U)
#endif

/*
 * constants & macros for individual SPDC_EPD_PANEL_TYPE_VER bitfields
 */

/* --- Register HW_SPDC_EPD_PANEL_TYPE_VER, field PRODUCT_AND_DRIVER_ID[15:0] (RO)
 *
 * Product ID and driver ID, they are stand for different type of panel 0x0 A060SE02 - Panel type
 * (AUO-K7900) 0x1 A090XE01 - Panel type (AUO-K7900) Others need to be defined
 */

#define BP_SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID      (0)      //!< Bit position for SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID.
#define BM_SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID      (0x0000ffff)  //!< Bit mask for SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID.

//! @brief Get value of SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID from a register value.
#define BG_SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID(r)   (((r) & BM_SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID) >> BP_SPDC_EPD_PANEL_TYPE_VER_PRODUCT_AND_DRIVER_ID)

/* --- Register HW_SPDC_EPD_PANEL_TYPE_VER, field LUT_VERSION[23:16] (RO)
 *
 * LUT version, it stands for different version of driving waveform 0x0101 V308 - Driving waveform
 * type 0x0102 V312 - Driving waveform type Others need to be defined
 */

#define BP_SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION      (16)      //!< Bit position for SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION.
#define BM_SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION      (0x00ff0000)  //!< Bit mask for SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION.

//! @brief Get value of SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION from a register value.
#define BG_SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION(r)   (((r) & BM_SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION) >> BP_SPDC_EPD_PANEL_TYPE_VER_LUT_VERSION)

/* --- Register HW_SPDC_EPD_PANEL_TYPE_VER, field EPD_PANEL_TYPE[31:24] (RO)
 *
 * EPD panel type, it stands for different material type of film. 0x0 ERK_1_4_A01 - Material type of
 * film 0x1 ERK_1_4_D01 - Material type of film 0x2 ERK_2_0_A01 - Material type of film Others need
 * to be defined
 */

#define BP_SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE      (24)      //!< Bit position for SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE.
#define BM_SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE      (0xff000000)  //!< Bit mask for SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE.

//! @brief Get value of SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE from a register value.
#define BG_SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE(r)   (((r) & BM_SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE) >> BP_SPDC_EPD_PANEL_TYPE_VER_EPD_PANEL_TYPE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_TCON_VER - SPDC IP Version (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_spdc_epd_tcon_ver
{
    reg32_t U;
    struct _hw_spdc_epd_tcon_ver_bitfields
    {
        unsigned EPD_TCON_VERSION : 8; //!< [7:0] EPD TCON version, it stands for different version of EPD TCON. 0x0 AUO_T2 - EPD TCON Version Others need to be defined
        unsigned RESERVED0 : 24; //!< [31:8] Reserved
    } B;
} hw_spdc_epd_tcon_ver_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_TCON_VER register
 */
#define HW_SPDC_EPD_TCON_VER_ADDR      (REGS_SPDC_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_TCON_VER           (*(volatile hw_spdc_epd_tcon_ver_t *) HW_SPDC_EPD_TCON_VER_ADDR)
#define HW_SPDC_EPD_TCON_VER_RD()      (HW_SPDC_EPD_TCON_VER.U)
#endif

/*
 * constants & macros for individual SPDC_EPD_TCON_VER bitfields
 */

/* --- Register HW_SPDC_EPD_TCON_VER, field EPD_TCON_VERSION[7:0] (RO)
 *
 * EPD TCON version, it stands for different version of EPD TCON. 0x0 AUO_T2 - EPD TCON Version
 * Others need to be defined
 */

#define BP_SPDC_EPD_TCON_VER_EPD_TCON_VERSION      (0)      //!< Bit position for SPDC_EPD_TCON_VER_EPD_TCON_VERSION.
#define BM_SPDC_EPD_TCON_VER_EPD_TCON_VERSION      (0x000000ff)  //!< Bit mask for SPDC_EPD_TCON_VER_EPD_TCON_VERSION.

//! @brief Get value of SPDC_EPD_TCON_VER_EPD_TCON_VERSION from a register value.
#define BG_SPDC_EPD_TCON_VER_EPD_TCON_VERSION(r)   (((r) & BM_SPDC_EPD_TCON_VER_EPD_TCON_VERSION) >> BP_SPDC_EPD_TCON_VER_EPD_TCON_VERSION)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SPDC_EPD_SW_GATE_CLK - All Clock Gating Enable (RW)
 *
 * Reset value: 0x00000001
 *

 */
typedef union _hw_spdc_epd_sw_gate_clk
{
    reg32_t U;
    struct _hw_spdc_epd_sw_gate_clk_bitfields
    {
        unsigned GATING_ALL_CLK_EN : 1; //!< [0] All clocks gating enable 0x0 ENABLE_ALL_CLOCKS - All clocks free run 0x1 GATING_ALL_CLOCKS - Gating all clocks for low power
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_spdc_epd_sw_gate_clk_t;
#endif

/*
 * constants & macros for entire SPDC_EPD_SW_GATE_CLK register
 */
#define HW_SPDC_EPD_SW_GATE_CLK_ADDR      (REGS_SPDC_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_SPDC_EPD_SW_GATE_CLK           (*(volatile hw_spdc_epd_sw_gate_clk_t *) HW_SPDC_EPD_SW_GATE_CLK_ADDR)
#define HW_SPDC_EPD_SW_GATE_CLK_RD()      (HW_SPDC_EPD_SW_GATE_CLK.U)
#define HW_SPDC_EPD_SW_GATE_CLK_WR(v)     (HW_SPDC_EPD_SW_GATE_CLK.U = (v))
#define HW_SPDC_EPD_SW_GATE_CLK_SET(v)    (HW_SPDC_EPD_SW_GATE_CLK_WR(HW_SPDC_EPD_SW_GATE_CLK_RD() |  (v)))
#define HW_SPDC_EPD_SW_GATE_CLK_CLR(v)    (HW_SPDC_EPD_SW_GATE_CLK_WR(HW_SPDC_EPD_SW_GATE_CLK_RD() & ~(v)))
#define HW_SPDC_EPD_SW_GATE_CLK_TOG(v)    (HW_SPDC_EPD_SW_GATE_CLK_WR(HW_SPDC_EPD_SW_GATE_CLK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SPDC_EPD_SW_GATE_CLK bitfields
 */

/* --- Register HW_SPDC_EPD_SW_GATE_CLK, field GATING_ALL_CLK_EN[0] (RW)
 *
 * All clocks gating enable 0x0 ENABLE_ALL_CLOCKS - All clocks free run 0x1 GATING_ALL_CLOCKS -
 * Gating all clocks for low power
 */

#define BP_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN      (0)      //!< Bit position for SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN.
#define BM_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN      (0x00000001)  //!< Bit mask for SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN.

//! @brief Get value of SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN from a register value.
#define BG_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN(r)   (((r) & BM_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN) >> BP_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN.
#define BF_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN(v)   ((((reg32_t) v) << BP_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN) & BM_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN)
#else
//! @brief Format value for bitfield SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN.
#define BF_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN(v)   (((v) << BP_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN) & BM_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GATING_ALL_CLK_EN field to a new value.
#define BW_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN(v)   (HW_SPDC_EPD_SW_GATE_CLK_WR((HW_SPDC_EPD_SW_GATE_CLK_RD() & ~BM_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN) | BF_SPDC_EPD_SW_GATE_CLK_GATING_ALL_CLK_EN(v)))
#endif


/*!
 * @brief All SPDC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_spdc
{
    volatile hw_spdc_epd_disp_trigger_t EPD_DISP_TRIGGER; //!< Display Trigger
    volatile hw_spdc_epd_update_x_y_t EPD_UPDATE_X_Y; //!< Display Coordinate
    volatile hw_spdc_epd_update_w_h_t EPD_UPDATE_W_H; //!< Display Area Size
    volatile hw_spdc_epd_lut_para_update_t EPD_LUT_PARA_UPDATE; //!< LUT Parameter Update
    volatile hw_spdc_epd_operate_t EPD_OPERATE; //!< Display Normal Operation
    volatile hw_spdc_epd_panel_init_set_t EPD_PANEL_INIT_SET; //!< SPDC Initial Setting
    volatile hw_spdc_epd_temper_setting_t EPD_TEMPER_SETTING; //!< Environment Temperature
    volatile hw_spdc_epd_next_buf_t EPD_NEXT_BUF; //!< Next Frame Memory Address
    volatile hw_spdc_epd_current_buf_t EPD_CURRENT_BUF; //!< Current Frame Memory Address
    volatile hw_spdc_epd_previous_buff_t EPD_PREVIOUS_BUFF; //!< Previous Frame Memory Address
    volatile hw_spdc_epd_frm_cnt_buff_t EPD_FRM_CNT_BUFF; //!< Counter Frame Memory Address
    volatile hw_spdc_epd_lut_buff_t EPD_LUT_BUFF; //!< LUT Memory Address
    volatile hw_spdc_epd_int_en_t EPD_INT_EN; //!< Interrupt Enable
    volatile hw_spdc_epd_int_st_clr_t EPD_INT_ST_CLR; //!< Interrupt Status & Clear
    reg32_t _reserved0;
    volatile hw_spdc_epd_status_t EPD_STATUS; //!< SPDC Operation Status
    volatile hw_spdc_epd_panel_type_ver_t EPD_PANEL_TYPE_VER; //!< Panel Type Related Information
    volatile hw_spdc_epd_tcon_ver_t EPD_TCON_VER; //!< SPDC IP Version
    volatile hw_spdc_epd_sw_gate_clk_t EPD_SW_GATE_CLK; //!< All Clock Gating Enable
} hw_spdc_t;
#pragma pack()

//! @brief Macro to access all SPDC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SPDC(0)</code>.
#define HW_SPDC     (*(volatile hw_spdc_t *) REGS_SPDC_BASE)

#endif


#endif // __HW_SPDC_REGISTERS_H__
