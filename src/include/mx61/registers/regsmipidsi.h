/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MIPI_DSI_H
#define _MIPI_DSI_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_MIPI_DSI_VERSION - Version of the DSI host ctrl
 * - HW_MIPI_DSI_PWR_UP - Core power up
 * - HW_MIPI_DSI_CLKMGR_CFG - Number of active data lanes
 * - HW_MIPI_DSI_DPI_CFG - DPI interface configuration
 * - HW_MIPI_DSI_DBI_CFG - DBI interface configuration
 * - HW_MIPI_DSI_DBIS_CMDSIZE - DBI command size configuration
 * - HW_MIPI_DSI_PCKHDL_CFG - Packet handler configuration
 * - HW_MIPI_DSI_VID_MODE_CFG - Video Mode Configuration
 * - HW_MIPI_DSI_VID_PKT_CFG - Video packet configuration
 * - HW_MIPI_DSI_CMD_MODE_CFG - Command mode configuration
 * - HW_MIPI_DSI_TMR_LINE_CFG - Line timer configuration
 * - HW_MIPI_DSI_VTIMING_CFG - Vertical timing configuration
 * - HW_MIPI_DSI_PHY_TMR_CFG - D-PHY timing configuration
 * - HW_MIPI_DSI_GEN_HDR - Generic packet Header configuration
 * - HW_MIPI_DSI_GEN_PLD_DATA - Generic payload data in/out
 * - HW_MIPI_DSI_CMD_PKT_STATUS - Command packet status
 * - HW_MIPI_DSI_TO_CNT_CFG0 - Time Out timers configuration
 * - HW_MIPI_DSI_ERROR_ST0 - Interrupt status register 0
 * - HW_MIPI_DSI_ERROR_ST1 - Interrupt status register 1
 * - HW_MIPI_DSI_ERROR_MSK0 - Masks Interrupt generation trigged by ERROR_ST0 register
 * - HW_MIPI_DSI_ERROR_MSK1 - Masks Interrupt generation trigged by ERROR_ST1 register
 * - HW_MIPI_DSI_PHY_RSTZ - D-PHY reset control
 * - HW_MIPI_DSI_PHY_IF_CFG_ - D-PHY interface configuration
 * - HW_MIPI_DSI_PHY_IF_CTRL - D-PHY PPI interface control
 * - HW_MIPI_DSI_PHY_STATUS - D-PHY PPI status interface
 * - HW_MIPI_DSI_PHY_TST_CTRL0 - D-PHY Test interface control 0
 * - HW_MIPI_DSI_PHY_TST_CTRL1 - D-PHY Test interface control 1
 *
 * hw_mipi_dsi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_MIPI_DSI_BASE
#define REGS_MIPI_DSI_BASE (0x020e0000) //!< Base address for MIPI_DSI.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_VERSION - Version of the DSI host ctrl (RO)
 *
 * Size: 32 bits  Offset: 0x0  Memory Access: R
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VERSION : 32; //!< Version of the DSI host controller
    } B;
} hw_mipi_dsi_version_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_VERSION register
 */
#define HW_MIPI_DSI_VERSION_ADDR      (REGS_MIPI_DSI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_VERSION           (*(volatile hw_mipi_dsi_version_t *) HW_MIPI_DSI_VERSION_ADDR)
#define HW_MIPI_DSI_VERSION_RD()      (HW_MIPI_DSI_VERSION.U)
#endif

/*
 * constants & macros for individual MIPI_DSI_VERSION bitfields
 */

/* --- Register HW_MIPI_DSI_VERSION, field VERSION (RO)
 *
 * Version of the DSI host controller
 */

#define BP_MIPI_DSI_VERSION_VERSION      0
#define BM_MIPI_DSI_VERSION_VERSION      0xffffffff

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PWR_UP - Core power up (RW)
 *
 * Size: 32 bits  Offset: 0x4  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SHUTDOWNZ : 1; //!< Core power up
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_mipi_dsi_pwr_up_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PWR_UP register
 */
#define HW_MIPI_DSI_PWR_UP_ADDR      (REGS_MIPI_DSI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PWR_UP           (*(volatile hw_mipi_dsi_pwr_up_t *) HW_MIPI_DSI_PWR_UP_ADDR)
#define HW_MIPI_DSI_PWR_UP_RD()      (HW_MIPI_DSI_PWR_UP.U)
#define HW_MIPI_DSI_PWR_UP_WR(v)     (HW_MIPI_DSI_PWR_UP.U = (v))
#define HW_MIPI_DSI_PWR_UP_SET(v)    (HW_MIPI_DSI_PWR_UP_WR(HW_MIPI_DSI_PWR_UP_RD() |  (v)))
#define HW_MIPI_DSI_PWR_UP_CLR(v)    (HW_MIPI_DSI_PWR_UP_WR(HW_MIPI_DSI_PWR_UP_RD() & ~(v)))
#define HW_MIPI_DSI_PWR_UP_TOG(v)    (HW_MIPI_DSI_PWR_UP_WR(HW_MIPI_DSI_PWR_UP_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PWR_UP bitfields
 */

/* --- Register HW_MIPI_DSI_PWR_UP, field SHUTDOWNZ (RW)
 *
 * Core power up
 *
 * Values:
 * 0 - reset;
 * 1 - power up)
 */

#define BP_MIPI_DSI_PWR_UP_SHUTDOWNZ      0
#define BM_MIPI_DSI_PWR_UP_SHUTDOWNZ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PWR_UP_SHUTDOWNZ(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PWR_UP_SHUTDOWNZ)
#else
#define BF_MIPI_DSI_PWR_UP_SHUTDOWNZ(v)   (((v) << 0) & BM_MIPI_DSI_PWR_UP_SHUTDOWNZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SHUTDOWNZ field to a new value.
#define BW_MIPI_DSI_PWR_UP_SHUTDOWNZ(v)   BF_CS1(MIPI_DSI_PWR_UP, SHUTDOWNZ, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_CLKMGR_CFG - Number of active data lanes (RW)
 *
 * Size: 32 bits  Offset: 0x8  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TX_ESC_CLK_DIVIDSION : 8; //!< Division factor for TX ESCAPE clock source (lanebyteclk pin), values 0 and 1 stop TX_ESC clock generation.
        unsigned TO_CLK_DIVIDSION : 8; //!< Division factor for Time Out clock used as timing unit in the configuration of HS to LP and LP to HS transition error.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_mipi_dsi_clkmgr_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_CLKMGR_CFG register
 */
#define HW_MIPI_DSI_CLKMGR_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_CLKMGR_CFG           (*(volatile hw_mipi_dsi_clkmgr_cfg_t *) HW_MIPI_DSI_CLKMGR_CFG_ADDR)
#define HW_MIPI_DSI_CLKMGR_CFG_RD()      (HW_MIPI_DSI_CLKMGR_CFG.U)
#define HW_MIPI_DSI_CLKMGR_CFG_WR(v)     (HW_MIPI_DSI_CLKMGR_CFG.U = (v))
#define HW_MIPI_DSI_CLKMGR_CFG_SET(v)    (HW_MIPI_DSI_CLKMGR_CFG_WR(HW_MIPI_DSI_CLKMGR_CFG_RD() |  (v)))
#define HW_MIPI_DSI_CLKMGR_CFG_CLR(v)    (HW_MIPI_DSI_CLKMGR_CFG_WR(HW_MIPI_DSI_CLKMGR_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_CLKMGR_CFG_TOG(v)    (HW_MIPI_DSI_CLKMGR_CFG_WR(HW_MIPI_DSI_CLKMGR_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_CLKMGR_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_CLKMGR_CFG, field TX_ESC_CLK_DIVIDSION (RW)
 *
 * Division factor for TX ESCAPE clock source (lanebyteclk pin), values 0 and 1 stop TX_ESC clock
 * generation.
 */

#define BP_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION      0
#define BM_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION)
#else
#define BF_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION(v)   (((v) << 0) & BM_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TX_ESC_CLK_DIVIDSION field to a new value.
#define BW_MIPI_DSI_CLKMGR_CFG_TX_ESC_CLK_DIVIDSION(v)   BF_CS1(MIPI_DSI_CLKMGR_CFG, TX_ESC_CLK_DIVIDSION, v)
#endif

/* --- Register HW_MIPI_DSI_CLKMGR_CFG, field TO_CLK_DIVIDSION (RW)
 *
 * Division factor for Time Out clock used as timing unit in the configuration of HS to LP and LP to
 * HS transition error.
 */

#define BP_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION      8
#define BM_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION)
#else
#define BF_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION(v)   (((v) << 8) & BM_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TO_CLK_DIVIDSION field to a new value.
#define BW_MIPI_DSI_CLKMGR_CFG_TO_CLK_DIVIDSION(v)   BF_CS1(MIPI_DSI_CLKMGR_CFG, TO_CLK_DIVIDSION, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_DPI_CFG - DPI interface configuration (RW)
 *
 * Size: 32 bits  Offset: 0xc  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DPI_VID : 2; //!< Configures the DPI Virtual Channel ID that will be indexed to the Video mode packets.
        unsigned DPI_COLOR_CODING : 3; //!< DPI color coding.
        unsigned DATAEN_ACTIVE_LOW : 1; //!< Set to configure Data enable pin (dpidaten) as Active low
        unsigned VSYNC_ACTIVE_LOW : 1; //!< Set to configure Vertical Synchronism pin (dpivsync) as Active low
        unsigned HSYNC_ACTIVE_LOW : 1; //!< Set to configure Horizontal Synchronism pin (dpihsync) as Active low
        unsigned SHUTD_ACTIVE_LOW : 1; //!< Set to configure Shut Down pin (dpishutdn) as Active low
        unsigned COLORM_ACTIVE_LOW : 1; //!< Set to configure Color Mode pin (dpicolcorm) as Active low
        unsigned EN18_LOOSELY : 1; //!< Enable 18 loosely packet pixel stream.
        unsigned RESERVED0 : 21; //!< Reserved
    } B;
} hw_mipi_dsi_dpi_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_DPI_CFG register
 */
#define HW_MIPI_DSI_DPI_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_DPI_CFG           (*(volatile hw_mipi_dsi_dpi_cfg_t *) HW_MIPI_DSI_DPI_CFG_ADDR)
#define HW_MIPI_DSI_DPI_CFG_RD()      (HW_MIPI_DSI_DPI_CFG.U)
#define HW_MIPI_DSI_DPI_CFG_WR(v)     (HW_MIPI_DSI_DPI_CFG.U = (v))
#define HW_MIPI_DSI_DPI_CFG_SET(v)    (HW_MIPI_DSI_DPI_CFG_WR(HW_MIPI_DSI_DPI_CFG_RD() |  (v)))
#define HW_MIPI_DSI_DPI_CFG_CLR(v)    (HW_MIPI_DSI_DPI_CFG_WR(HW_MIPI_DSI_DPI_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_DPI_CFG_TOG(v)    (HW_MIPI_DSI_DPI_CFG_WR(HW_MIPI_DSI_DPI_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_DPI_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_DPI_CFG, field DPI_VID (RW)
 *
 * Configures the DPI Virtual Channel ID that will be indexed to the Video mode packets.
 */

#define BP_MIPI_DSI_DPI_CFG_DPI_VID      0
#define BM_MIPI_DSI_DPI_CFG_DPI_VID      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_DPI_VID(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_DPI_CFG_DPI_VID)
#else
#define BF_MIPI_DSI_DPI_CFG_DPI_VID(v)   (((v) << 0) & BM_MIPI_DSI_DPI_CFG_DPI_VID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPI_VID field to a new value.
#define BW_MIPI_DSI_DPI_CFG_DPI_VID(v)   BF_CS1(MIPI_DSI_DPI_CFG, DPI_VID, v)
#endif

/* --- Register HW_MIPI_DSI_DPI_CFG, field DPI_COLOR_CODING (RW)
 *
 * DPI color coding.
 *
 * Values:
 * 0 - 16bit config1
 * 1 - 16bit config2;
 * 2 - 16bit config3;
 * 3 - 18bit config1;
 * 4 - 18bit config2;
 * 5 - to 7 24 bit.
 */

#define BP_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING      2
#define BM_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING)
#else
#define BF_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING(v)   (((v) << 2) & BM_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPI_COLOR_CODING field to a new value.
#define BW_MIPI_DSI_DPI_CFG_DPI_COLOR_CODING(v)   BF_CS1(MIPI_DSI_DPI_CFG, DPI_COLOR_CODING, v)
#endif


/* --- Register HW_MIPI_DSI_DPI_CFG, field DATAEN_ACTIVE_LOW (RW)
 *
 * Set to configure Data enable pin (dpidaten) as Active low
 */

#define BP_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW      5
#define BM_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW)
#else
#define BF_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW(v)   (((v) << 5) & BM_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATAEN_ACTIVE_LOW field to a new value.
#define BW_MIPI_DSI_DPI_CFG_DATAEN_ACTIVE_LOW(v)   BF_CS1(MIPI_DSI_DPI_CFG, DATAEN_ACTIVE_LOW, v)
#endif

/* --- Register HW_MIPI_DSI_DPI_CFG, field VSYNC_ACTIVE_LOW (RW)
 *
 * Set to configure Vertical Synchronism pin (dpivsync) as Active low
 */

#define BP_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW      6
#define BM_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW)
#else
#define BF_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW(v)   (((v) << 6) & BM_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_ACTIVE_LOW field to a new value.
#define BW_MIPI_DSI_DPI_CFG_VSYNC_ACTIVE_LOW(v)   BF_CS1(MIPI_DSI_DPI_CFG, VSYNC_ACTIVE_LOW, v)
#endif

/* --- Register HW_MIPI_DSI_DPI_CFG, field HSYNC_ACTIVE_LOW (RW)
 *
 * Set to configure Horizontal Synchronism pin (dpihsync) as Active low
 */

#define BP_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW      7
#define BM_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW)
#else
#define BF_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW(v)   (((v) << 7) & BM_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_ACTIVE_LOW field to a new value.
#define BW_MIPI_DSI_DPI_CFG_HSYNC_ACTIVE_LOW(v)   BF_CS1(MIPI_DSI_DPI_CFG, HSYNC_ACTIVE_LOW, v)
#endif

/* --- Register HW_MIPI_DSI_DPI_CFG, field SHUTD_ACTIVE_LOW (RW)
 *
 * Set to configure Shut Down pin (dpishutdn) as Active low
 */

#define BP_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW      8
#define BM_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW)
#else
#define BF_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW(v)   (((v) << 8) & BM_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SHUTD_ACTIVE_LOW field to a new value.
#define BW_MIPI_DSI_DPI_CFG_SHUTD_ACTIVE_LOW(v)   BF_CS1(MIPI_DSI_DPI_CFG, SHUTD_ACTIVE_LOW, v)
#endif

/* --- Register HW_MIPI_DSI_DPI_CFG, field COLORM_ACTIVE_LOW (RW)
 *
 * Set to configure Color Mode pin (dpicolcorm) as Active low
 */

#define BP_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW      9
#define BM_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW)
#else
#define BF_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW(v)   (((v) << 9) & BM_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the COLORM_ACTIVE_LOW field to a new value.
#define BW_MIPI_DSI_DPI_CFG_COLORM_ACTIVE_LOW(v)   BF_CS1(MIPI_DSI_DPI_CFG, COLORM_ACTIVE_LOW, v)
#endif

/* --- Register HW_MIPI_DSI_DPI_CFG, field EN18_LOOSELY (RW)
 *
 * Enable 18 loosely packet pixel stream.
 */

#define BP_MIPI_DSI_DPI_CFG_EN18_LOOSELY      10
#define BM_MIPI_DSI_DPI_CFG_EN18_LOOSELY      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DPI_CFG_EN18_LOOSELY(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_DPI_CFG_EN18_LOOSELY)
#else
#define BF_MIPI_DSI_DPI_CFG_EN18_LOOSELY(v)   (((v) << 10) & BM_MIPI_DSI_DPI_CFG_EN18_LOOSELY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN18_LOOSELY field to a new value.
#define BW_MIPI_DSI_DPI_CFG_EN18_LOOSELY(v)   BF_CS1(MIPI_DSI_DPI_CFG, EN18_LOOSELY, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_DBI_CFG - DBI interface configuration (RW)
 *
 * Size: 32 bits  Offset: 0x10  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DBI_VID : 2; //!< Configures the DBI Virtual Channel ID that will be indexed to the DCS packets.
        unsigned IN_DBI_CONF : 4; //!< Configures DBI input pixel data configuration;
        unsigned LUT_SIZE_CONF : 2; //!< Configures the size used to transport Write Lut commands;
        unsigned PARTITIONING_EN : 1; //!< Enables write memory continue through input command (system needs to ensure correct partitioning of Long Write commands)
        unsigned OUT_DBI_CONF : 4; //!< Configures the DBI output pixel data configuration;
        unsigned RESERVED0 : 19; //!< Reserved
    } B;
} hw_mipi_dsi_dbi_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_DBI_CFG register
 */
#define HW_MIPI_DSI_DBI_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_DBI_CFG           (*(volatile hw_mipi_dsi_dbi_cfg_t *) HW_MIPI_DSI_DBI_CFG_ADDR)
#define HW_MIPI_DSI_DBI_CFG_RD()      (HW_MIPI_DSI_DBI_CFG.U)
#define HW_MIPI_DSI_DBI_CFG_WR(v)     (HW_MIPI_DSI_DBI_CFG.U = (v))
#define HW_MIPI_DSI_DBI_CFG_SET(v)    (HW_MIPI_DSI_DBI_CFG_WR(HW_MIPI_DSI_DBI_CFG_RD() |  (v)))
#define HW_MIPI_DSI_DBI_CFG_CLR(v)    (HW_MIPI_DSI_DBI_CFG_WR(HW_MIPI_DSI_DBI_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_DBI_CFG_TOG(v)    (HW_MIPI_DSI_DBI_CFG_WR(HW_MIPI_DSI_DBI_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_DBI_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_DBI_CFG, field DBI_VID (RW)
 *
 * Configures the DBI Virtual Channel ID that will be indexed to the DCS packets.
 */

#define BP_MIPI_DSI_DBI_CFG_DBI_VID      0
#define BM_MIPI_DSI_DBI_CFG_DBI_VID      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBI_CFG_DBI_VID(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_DBI_CFG_DBI_VID)
#else
#define BF_MIPI_DSI_DBI_CFG_DBI_VID(v)   (((v) << 0) & BM_MIPI_DSI_DBI_CFG_DBI_VID)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_VID field to a new value.
#define BW_MIPI_DSI_DBI_CFG_DBI_VID(v)   BF_CS1(MIPI_DSI_DBI_CFG, DBI_VID, v)
#endif

/* --- Register HW_MIPI_DSI_DBI_CFG, field IN_DBI_CONF (RW)
 *
 * Configures DBI input pixel data configuration;
 *
 * Values:
 * 0 - 8bit 8bpp;
 * 1 - 8bit 12bpp;
 * 2 - 8bit 16bpp;
 * 3 - 8bit 18bpp;
 * 4 - 8bit 24bpp;
 * 5 - 9bit 18bpp;
 * 6 - 16bit 8bpp;
 * 7 - 16bit 12bpp;
 * 8 - 16bit 16bpp;
 * 9 - 16bit 18bpp, option1;
 * 10 - 16bit 18bpp, option2;
 * 11 - 16bit 24bpp, option1;
 * 12 - 16bit 24bpp, option2
 */

#define BP_MIPI_DSI_DBI_CFG_IN_DBI_CONF      2
#define BM_MIPI_DSI_DBI_CFG_IN_DBI_CONF      0x0000003c

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBI_CFG_IN_DBI_CONF(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_DBI_CFG_IN_DBI_CONF)
#else
#define BF_MIPI_DSI_DBI_CFG_IN_DBI_CONF(v)   (((v) << 2) & BM_MIPI_DSI_DBI_CFG_IN_DBI_CONF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IN_DBI_CONF field to a new value.
#define BW_MIPI_DSI_DBI_CFG_IN_DBI_CONF(v)   BF_CS1(MIPI_DSI_DBI_CFG, IN_DBI_CONF, v)
#endif


/* --- Register HW_MIPI_DSI_DBI_CFG, field LUT_SIZE_CONF (RW)
 *
 * Configures the size used to transport Write Lut commands;
 *
 * Values:
 * 0 - 16-bit color display;
 * 1 - 18-bit color display;
 * 2 - 24-bit color display;
 * 3 - 16-bit color display
 */

#define BP_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF      6
#define BM_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF)
#else
#define BF_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF(v)   (((v) << 6) & BM_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LUT_SIZE_CONF field to a new value.
#define BW_MIPI_DSI_DBI_CFG_LUT_SIZE_CONF(v)   BF_CS1(MIPI_DSI_DBI_CFG, LUT_SIZE_CONF, v)
#endif


/* --- Register HW_MIPI_DSI_DBI_CFG, field PARTITIONING_EN (RW)
 *
 * Enables write memory continue through input command (system needs to ensure correct partitioning
 * of Long Write commands)
 */

#define BP_MIPI_DSI_DBI_CFG_PARTITIONING_EN      8
#define BM_MIPI_DSI_DBI_CFG_PARTITIONING_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBI_CFG_PARTITIONING_EN(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_DBI_CFG_PARTITIONING_EN)
#else
#define BF_MIPI_DSI_DBI_CFG_PARTITIONING_EN(v)   (((v) << 8) & BM_MIPI_DSI_DBI_CFG_PARTITIONING_EN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PARTITIONING_EN field to a new value.
#define BW_MIPI_DSI_DBI_CFG_PARTITIONING_EN(v)   BF_CS1(MIPI_DSI_DBI_CFG, PARTITIONING_EN, v)
#endif

/* --- Register HW_MIPI_DSI_DBI_CFG, field OUT_DBI_CONF (RW)
 *
 * Configures the DBI output pixel data configuration;
 *
 * Values:
 * 0 - 8bit 8bpp;
 * 1 - 8bit 12bpp;
 * 2 - 8bit 16bpp;
 * 3 - 8bit 18bpp;
 * 4 - 8bit 24bpp;
 * 5 - 9bit 18bpp;
 * 6 - 16bit 8bpp;
 * 7 - 16bit 12bpp;
 * 8 - 16bit 16bpp;
 * 9 - 16bit 18bpp, option1;
 * 10 - 16bit 18bpp, option2;
 * 11 - 16bit 24bpp, option1;
 * 12 - 16bit 24bpp, option2
 */

#define BP_MIPI_DSI_DBI_CFG_OUT_DBI_CONF      9
#define BM_MIPI_DSI_DBI_CFG_OUT_DBI_CONF      0x00001e00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBI_CFG_OUT_DBI_CONF(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_DBI_CFG_OUT_DBI_CONF)
#else
#define BF_MIPI_DSI_DBI_CFG_OUT_DBI_CONF(v)   (((v) << 9) & BM_MIPI_DSI_DBI_CFG_OUT_DBI_CONF)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the OUT_DBI_CONF field to a new value.
#define BW_MIPI_DSI_DBI_CFG_OUT_DBI_CONF(v)   BF_CS1(MIPI_DSI_DBI_CFG, OUT_DBI_CONF, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_DBIS_CMDSIZE - DBI command size configuration (RW)
 *
 * Size: 32 bits  Offset: 0x14  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned WR_CMD_SIZE : 16; //!< Configures the size of the DCS write memory commands. Size of DSI packet payload is the actual payload size minus 1 since the DCS command is in the DSI packet payload.
        unsigned ALLOWED_CMD_SIZE : 16; //!< Configures the maximum allowed size of a DCS write memory command. This register is used to partition a write memory command into several write memory continues. It is only used if bit 'partitioning_en' is disabled. Size of DSI packet payload is the actual payload size minus 1 since the DCS command is in the DSI packet payload.
    } B;
} hw_mipi_dsi_dbis_cmdsize_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_DBIS_CMDSIZE register
 */
#define HW_MIPI_DSI_DBIS_CMDSIZE_ADDR      (REGS_MIPI_DSI_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_DBIS_CMDSIZE           (*(volatile hw_mipi_dsi_dbis_cmdsize_t *) HW_MIPI_DSI_DBIS_CMDSIZE_ADDR)
#define HW_MIPI_DSI_DBIS_CMDSIZE_RD()      (HW_MIPI_DSI_DBIS_CMDSIZE.U)
#define HW_MIPI_DSI_DBIS_CMDSIZE_WR(v)     (HW_MIPI_DSI_DBIS_CMDSIZE.U = (v))
#define HW_MIPI_DSI_DBIS_CMDSIZE_SET(v)    (HW_MIPI_DSI_DBIS_CMDSIZE_WR(HW_MIPI_DSI_DBIS_CMDSIZE_RD() |  (v)))
#define HW_MIPI_DSI_DBIS_CMDSIZE_CLR(v)    (HW_MIPI_DSI_DBIS_CMDSIZE_WR(HW_MIPI_DSI_DBIS_CMDSIZE_RD() & ~(v)))
#define HW_MIPI_DSI_DBIS_CMDSIZE_TOG(v)    (HW_MIPI_DSI_DBIS_CMDSIZE_WR(HW_MIPI_DSI_DBIS_CMDSIZE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_DBIS_CMDSIZE bitfields
 */

/* --- Register HW_MIPI_DSI_DBIS_CMDSIZE, field WR_CMD_SIZE (RW)
 *
 * Configures the size of the DCS write memory commands. Size of DSI packet payload is the actual
 * payload size minus 1 since the DCS command is in the DSI packet payload.
 */

#define BP_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE      0
#define BM_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE)
#else
#define BF_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE(v)   (((v) << 0) & BM_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WR_CMD_SIZE field to a new value.
#define BW_MIPI_DSI_DBIS_CMDSIZE_WR_CMD_SIZE(v)   BF_CS1(MIPI_DSI_DBIS_CMDSIZE, WR_CMD_SIZE, v)
#endif

/* --- Register HW_MIPI_DSI_DBIS_CMDSIZE, field ALLOWED_CMD_SIZE (RW)
 *
 * Configures the maximum allowed size of a DCS write memory command. This register is used to
 * partition a write memory command into several write memory continues. It is only used if bit
 * 'partitioning_en' is disabled. Size of DSI packet payload is the actual payload size minus 1
 * since the DCS command is in the DSI packet payload.
 */

#define BP_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE      16
#define BM_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE)
#else
#define BF_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE(v)   (((v) << 16) & BM_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ALLOWED_CMD_SIZE field to a new value.
#define BW_MIPI_DSI_DBIS_CMDSIZE_ALLOWED_CMD_SIZE(v)   BF_CS1(MIPI_DSI_DBIS_CMDSIZE, ALLOWED_CMD_SIZE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PCKHDL_CFG - Packet handler configuration (RW)
 *
 * Size: 32 bits  Offset: 0x18  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EN_EOTP_TX : 1; //!< Enables EOTp transmission
        unsigned EN_EOTN_RX : 1; //!< Enables EOTp reception
        unsigned EN_BTA : 1; //!< Enables Bus Turn-Around request
        unsigned EN_ECC_RX : 1; //!< Enables ECC reception, error correction and reporting
        unsigned EN_CRC_RX : 1; //!< Enables CRC reception and error reporting
        unsigned GEN_VID_RX : 2; //!< Generic interface read-back Virtual Channel identification
        unsigned RESERVED0 : 25; //!< Reserved
    } B;
} hw_mipi_dsi_pckhdl_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PCKHDL_CFG register
 */
#define HW_MIPI_DSI_PCKHDL_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PCKHDL_CFG           (*(volatile hw_mipi_dsi_pckhdl_cfg_t *) HW_MIPI_DSI_PCKHDL_CFG_ADDR)
#define HW_MIPI_DSI_PCKHDL_CFG_RD()      (HW_MIPI_DSI_PCKHDL_CFG.U)
#define HW_MIPI_DSI_PCKHDL_CFG_WR(v)     (HW_MIPI_DSI_PCKHDL_CFG.U = (v))
#define HW_MIPI_DSI_PCKHDL_CFG_SET(v)    (HW_MIPI_DSI_PCKHDL_CFG_WR(HW_MIPI_DSI_PCKHDL_CFG_RD() |  (v)))
#define HW_MIPI_DSI_PCKHDL_CFG_CLR(v)    (HW_MIPI_DSI_PCKHDL_CFG_WR(HW_MIPI_DSI_PCKHDL_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_PCKHDL_CFG_TOG(v)    (HW_MIPI_DSI_PCKHDL_CFG_WR(HW_MIPI_DSI_PCKHDL_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PCKHDL_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_PCKHDL_CFG, field EN_EOTP_TX (RW)
 *
 * Enables EOTp transmission
 */

#define BP_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX      0
#define BM_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX)
#else
#define BF_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX(v)   (((v) << 0) & BM_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_EOTP_TX field to a new value.
#define BW_MIPI_DSI_PCKHDL_CFG_EN_EOTP_TX(v)   BF_CS1(MIPI_DSI_PCKHDL_CFG, EN_EOTP_TX, v)
#endif

/* --- Register HW_MIPI_DSI_PCKHDL_CFG, field EN_EOTN_RX (RW)
 *
 * Enables EOTp reception
 */

#define BP_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX      1
#define BM_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX)
#else
#define BF_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX(v)   (((v) << 1) & BM_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_EOTN_RX field to a new value.
#define BW_MIPI_DSI_PCKHDL_CFG_EN_EOTN_RX(v)   BF_CS1(MIPI_DSI_PCKHDL_CFG, EN_EOTN_RX, v)
#endif

/* --- Register HW_MIPI_DSI_PCKHDL_CFG, field EN_BTA (RW)
 *
 * Enables Bus Turn-Around request
 */

#define BP_MIPI_DSI_PCKHDL_CFG_EN_BTA      2
#define BM_MIPI_DSI_PCKHDL_CFG_EN_BTA      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PCKHDL_CFG_EN_BTA(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_PCKHDL_CFG_EN_BTA)
#else
#define BF_MIPI_DSI_PCKHDL_CFG_EN_BTA(v)   (((v) << 2) & BM_MIPI_DSI_PCKHDL_CFG_EN_BTA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_BTA field to a new value.
#define BW_MIPI_DSI_PCKHDL_CFG_EN_BTA(v)   BF_CS1(MIPI_DSI_PCKHDL_CFG, EN_BTA, v)
#endif

/* --- Register HW_MIPI_DSI_PCKHDL_CFG, field EN_ECC_RX (RW)
 *
 * Enables ECC reception, error correction and reporting
 */

#define BP_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX      3
#define BM_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX)
#else
#define BF_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX(v)   (((v) << 3) & BM_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ECC_RX field to a new value.
#define BW_MIPI_DSI_PCKHDL_CFG_EN_ECC_RX(v)   BF_CS1(MIPI_DSI_PCKHDL_CFG, EN_ECC_RX, v)
#endif

/* --- Register HW_MIPI_DSI_PCKHDL_CFG, field EN_CRC_RX (RW)
 *
 * Enables CRC reception and error reporting
 */

#define BP_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX      4
#define BM_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX)
#else
#define BF_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX(v)   (((v) << 4) & BM_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_CRC_RX field to a new value.
#define BW_MIPI_DSI_PCKHDL_CFG_EN_CRC_RX(v)   BF_CS1(MIPI_DSI_PCKHDL_CFG, EN_CRC_RX, v)
#endif

/* --- Register HW_MIPI_DSI_PCKHDL_CFG, field GEN_VID_RX (RW)
 *
 * Generic interface read-back Virtual Channel identification
 */

#define BP_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX      5
#define BM_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX)
#else
#define BF_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX(v)   (((v) << 5) & BM_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_VID_RX field to a new value.
#define BW_MIPI_DSI_PCKHDL_CFG_GEN_VID_RX(v)   BF_CS1(MIPI_DSI_PCKHDL_CFG, GEN_VID_RX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_VID_MODE_CFG - Video Mode Configuration (RW)
 *
 * Size: 32 bits  Offset: 0x1c  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EN_VIDEO_MODE : 1; //!< Enables DPI Video mode transmission
        unsigned VID_MODE_TYPE : 2; //!< Selects video mode transmission type. 0: Non-burst with Sync pulses; 1: Non-burst with Sync events; 2-3: Burst with Sync pulses.
        unsigned EN_LP_VSA : 1; //!< Enables return to Low Power inside VSA period when timing allows
        unsigned EN_LP_VBP : 1; //!< Enables return to Low Power inside VBP period when timing allows
        unsigned EN_LP_VFP : 1; //!< Enables return to Low Power inside VFP period when timing allows
        unsigned EN_LP_VACT : 1; //!< Enables return to Low Power inside VACT period when timing allows
        unsigned EN_LP_HBP : 1; //!< Enables return to Low Power inside HBP period when timing allows
        unsigned EN_LP_HFP : 1; //!< Enables return to Low Power inside HFP period when timing allows
        unsigned EN_MULTI_PKT : 1; //!< Enables the tranmission of multi video packets in the HACT period
        unsigned EN_NULL_PKT : 1; //!< Enables the tranmission of null packets in the HACT period
        unsigned FRAME_BTA_ACK : 1; //!< Enables the request for an acknowledge response at the end of a frame
        unsigned RESERVED0 : 20; //!< Reserved
    } B;
} hw_mipi_dsi_vid_mode_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_VID_MODE_CFG register
 */
#define HW_MIPI_DSI_VID_MODE_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_VID_MODE_CFG           (*(volatile hw_mipi_dsi_vid_mode_cfg_t *) HW_MIPI_DSI_VID_MODE_CFG_ADDR)
#define HW_MIPI_DSI_VID_MODE_CFG_RD()      (HW_MIPI_DSI_VID_MODE_CFG.U)
#define HW_MIPI_DSI_VID_MODE_CFG_WR(v)     (HW_MIPI_DSI_VID_MODE_CFG.U = (v))
#define HW_MIPI_DSI_VID_MODE_CFG_SET(v)    (HW_MIPI_DSI_VID_MODE_CFG_WR(HW_MIPI_DSI_VID_MODE_CFG_RD() |  (v)))
#define HW_MIPI_DSI_VID_MODE_CFG_CLR(v)    (HW_MIPI_DSI_VID_MODE_CFG_WR(HW_MIPI_DSI_VID_MODE_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_VID_MODE_CFG_TOG(v)    (HW_MIPI_DSI_VID_MODE_CFG_WR(HW_MIPI_DSI_VID_MODE_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_VID_MODE_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_VIDEO_MODE (RW)
 *
 * Enables DPI Video mode transmission
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE      0
#define BM_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE(v)   (((v) << 0) & BM_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_VIDEO_MODE field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_VIDEO_MODE(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_VIDEO_MODE, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field VID_MODE_TYPE (RW)
 *
 * Selects video mode transmission type. 0: Non-burst with Sync pulses; 1: Non-burst with Sync
 * events; 2-3: Burst with Sync pulses.
 */

#define BP_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE      1
#define BM_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE      0x00000006

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE(v)   (((v) << 1) & BM_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VID_MODE_TYPE field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_VID_MODE_TYPE(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, VID_MODE_TYPE, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_LP_VSA (RW)
 *
 * Enables return to Low Power inside VSA period when timing allows
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA      3
#define BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA(v)   (((v) << 3) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LP_VSA field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_LP_VSA(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_LP_VSA, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_LP_VBP (RW)
 *
 * Enables return to Low Power inside VBP period when timing allows
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP      4
#define BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP(v)   (((v) << 4) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LP_VBP field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_LP_VBP(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_LP_VBP, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_LP_VFP (RW)
 *
 * Enables return to Low Power inside VFP period when timing allows
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP      5
#define BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP(v)   (((v) << 5) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LP_VFP field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_LP_VFP(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_LP_VFP, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_LP_VACT (RW)
 *
 * Enables return to Low Power inside VACT period when timing allows
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT      6
#define BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT(v)   (((v) << 6) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LP_VACT field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_LP_VACT(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_LP_VACT, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_LP_HBP (RW)
 *
 * Enables return to Low Power inside HBP period when timing allows
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP      7
#define BM_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP(v)   (((v) << 7) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LP_HBP field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_LP_HBP(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_LP_HBP, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_LP_HFP (RW)
 *
 * Enables return to Low Power inside HFP period when timing allows
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP      8
#define BM_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP(v)   (((v) << 8) & BM_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_LP_HFP field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_LP_HFP(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_LP_HFP, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_MULTI_PKT (RW)
 *
 * Enables the tranmission of multi video packets in the HACT period
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT      9
#define BM_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT(v)   (((v) << 9) & BM_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_MULTI_PKT field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_MULTI_PKT(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_MULTI_PKT, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field EN_NULL_PKT (RW)
 *
 * Enables the tranmission of null packets in the HACT period
 */

#define BP_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT      10
#define BM_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT(v)   (((v) << 10) & BM_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_NULL_PKT field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_EN_NULL_PKT(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, EN_NULL_PKT, v)
#endif

/* --- Register HW_MIPI_DSI_VID_MODE_CFG, field FRAME_BTA_ACK (RW)
 *
 * Enables the request for an acknowledge response at the end of a frame
 */

#define BP_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK      11
#define BM_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK)
#else
#define BF_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK(v)   (((v) << 11) & BM_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FRAME_BTA_ACK field to a new value.
#define BW_MIPI_DSI_VID_MODE_CFG_FRAME_BTA_ACK(v)   BF_CS1(MIPI_DSI_VID_MODE_CFG, FRAME_BTA_ACK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_VID_PKT_CFG - Video packet configuration (RW)
 *
 * Size: 32 bits  Offset: 0x20  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VID_PKT_SIZE : 11; //!< Configures the number of pixel on a single video packet. (If using 18 bit mode and not enabling loosely packet stream this value must be a multiple of 4)
        unsigned NUM_CHUNKS : 10; //!< Configures the number of chunks to be transmitted during a Line period. (A chunk is a video packet or a null packet)
        unsigned NULL_PKT_SIZE : 10; //!< Configures the number of bytes in a null packet
        unsigned RESERVED0 : 1; //!< Reserved
    } B;
} hw_mipi_dsi_vid_pkt_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_VID_PKT_CFG register
 */
#define HW_MIPI_DSI_VID_PKT_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_VID_PKT_CFG           (*(volatile hw_mipi_dsi_vid_pkt_cfg_t *) HW_MIPI_DSI_VID_PKT_CFG_ADDR)
#define HW_MIPI_DSI_VID_PKT_CFG_RD()      (HW_MIPI_DSI_VID_PKT_CFG.U)
#define HW_MIPI_DSI_VID_PKT_CFG_WR(v)     (HW_MIPI_DSI_VID_PKT_CFG.U = (v))
#define HW_MIPI_DSI_VID_PKT_CFG_SET(v)    (HW_MIPI_DSI_VID_PKT_CFG_WR(HW_MIPI_DSI_VID_PKT_CFG_RD() |  (v)))
#define HW_MIPI_DSI_VID_PKT_CFG_CLR(v)    (HW_MIPI_DSI_VID_PKT_CFG_WR(HW_MIPI_DSI_VID_PKT_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_VID_PKT_CFG_TOG(v)    (HW_MIPI_DSI_VID_PKT_CFG_WR(HW_MIPI_DSI_VID_PKT_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_VID_PKT_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_VID_PKT_CFG, field VID_PKT_SIZE (RW)
 *
 * Configures the number of pixel on a single video packet. (If using 18 bit mode and not enabling
 * loosely packet stream this value must be a multiple of 4)
 */

#define BP_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE      0
#define BM_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE      0x000007ff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE)
#else
#define BF_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE(v)   (((v) << 0) & BM_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VID_PKT_SIZE field to a new value.
#define BW_MIPI_DSI_VID_PKT_CFG_VID_PKT_SIZE(v)   BF_CS1(MIPI_DSI_VID_PKT_CFG, VID_PKT_SIZE, v)
#endif

/* --- Register HW_MIPI_DSI_VID_PKT_CFG, field NUM_CHUNKS (RW)
 *
 * Configures the number of chunks to be transmitted during a Line period. (A chunk is a video
 * packet or a null packet)
 */

#define BP_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS      11
#define BM_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS      0x001ff800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS)
#else
#define BF_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS(v)   (((v) << 11) & BM_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM_CHUNKS field to a new value.
#define BW_MIPI_DSI_VID_PKT_CFG_NUM_CHUNKS(v)   BF_CS1(MIPI_DSI_VID_PKT_CFG, NUM_CHUNKS, v)
#endif

/* --- Register HW_MIPI_DSI_VID_PKT_CFG, field NULL_PKT_SIZE (RW)
 *
 * Configures the number of bytes in a null packet
 */

#define BP_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE      21
#define BM_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE      0x7fe00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE(v)   ((((reg32_t) v) << 21) & BM_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE)
#else
#define BF_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE(v)   (((v) << 21) & BM_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the NULL_PKT_SIZE field to a new value.
#define BW_MIPI_DSI_VID_PKT_CFG_NULL_PKT_SIZE(v)   BF_CS1(MIPI_DSI_VID_PKT_CFG, NULL_PKT_SIZE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_CMD_MODE_CFG - Command mode configuration (RW)
 *
 * Size: 32 bits  Offset: 0x24  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned EN_CMD_MODE : 1; //!< Enables the Command Mode Protocol for transmissions.
        unsigned GEN_SW_0P_TX : 1; //!< Configures the Generic Short Write Packet with 0 Parameters command transmission type.
        unsigned GEN_SW_1P_TX : 1; //!< Configures the Generic Short Write Packet with 1 Parameters command transmission type.
        unsigned GEN_SW_2P_TX : 1; //!< Configures the Generic Short Write Packet with 2 Parameters command transmission type.
        unsigned GEN_SR_0P_TX : 1; //!< Configures the Generic Short Read Packet with 0 Parameters command transmission type.
        unsigned GEN_SR_1P_TX : 1; //!< Configures the Generic Short Read Packet with 1 Parameters command transmission type.
        unsigned GEN_SR_2P_TX : 1; //!< Configures the Generic Short Read Packet with 2 Parameters command transmission type.
        unsigned DCS_SW_0P_TX : 1; //!< Configures the DCS Short Write Packet with 0 Parameters command transmission type.
        unsigned DCS_SW_1P_TX : 1; //!< Configures the DCS Short Write Packet with 1 Parameters command transmission type.
        unsigned DCS_SW_2P_TX : 1; //!< Configures the DCS Short Write Packet with 2 Parameters command transmission type.
        unsigned MAX_RD_PKT_SIZE : 1; //!< Configures the Maximum Read Packet Size command transmission type.
        unsigned GEN_LW_TX : 1; //!< Configures the Generic Long Write Packet command transmission type.
        unsigned DCS_LW_TX : 1; //!< Configures the DCS Long Write Packet command transmission type.
        unsigned EN_ACK_RQST : 1; //!< Enables the acknowledge request after each packet transmission
        unsigned EN_TEAR_FX : 1; //!< Enables the tearing effect acknowledge request
        unsigned RESERVED0 : 17; //!< Reserved
    } B;
} hw_mipi_dsi_cmd_mode_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_CMD_MODE_CFG register
 */
#define HW_MIPI_DSI_CMD_MODE_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_CMD_MODE_CFG           (*(volatile hw_mipi_dsi_cmd_mode_cfg_t *) HW_MIPI_DSI_CMD_MODE_CFG_ADDR)
#define HW_MIPI_DSI_CMD_MODE_CFG_RD()      (HW_MIPI_DSI_CMD_MODE_CFG.U)
#define HW_MIPI_DSI_CMD_MODE_CFG_WR(v)     (HW_MIPI_DSI_CMD_MODE_CFG.U = (v))
#define HW_MIPI_DSI_CMD_MODE_CFG_SET(v)    (HW_MIPI_DSI_CMD_MODE_CFG_WR(HW_MIPI_DSI_CMD_MODE_CFG_RD() |  (v)))
#define HW_MIPI_DSI_CMD_MODE_CFG_CLR(v)    (HW_MIPI_DSI_CMD_MODE_CFG_WR(HW_MIPI_DSI_CMD_MODE_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_CMD_MODE_CFG_TOG(v)    (HW_MIPI_DSI_CMD_MODE_CFG_WR(HW_MIPI_DSI_CMD_MODE_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_CMD_MODE_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field EN_CMD_MODE (RW)
 *
 * Enables the Command Mode Protocol for transmissions.
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE      0
#define BM_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE(v)   (((v) << 0) & BM_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_CMD_MODE field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_EN_CMD_MODE(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, EN_CMD_MODE, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_SW_0P_TX (RW)
 *
 * Configures the Generic Short Write Packet with 0 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX      1
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX(v)   (((v) << 1) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_SW_0P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_SW_0P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_SW_0P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_SW_1P_TX (RW)
 *
 * Configures the Generic Short Write Packet with 1 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX      2
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX(v)   (((v) << 2) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_SW_1P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_SW_1P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_SW_1P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_SW_2P_TX (RW)
 *
 * Configures the Generic Short Write Packet with 2 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX      3
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX(v)   (((v) << 3) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_SW_2P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_SW_2P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_SW_2P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_SR_0P_TX (RW)
 *
 * Configures the Generic Short Read Packet with 0 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX      4
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX(v)   (((v) << 4) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_SR_0P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_SR_0P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_SR_0P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_SR_1P_TX (RW)
 *
 * Configures the Generic Short Read Packet with 1 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX      5
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX(v)   (((v) << 5) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_SR_1P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_SR_1P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_SR_1P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_SR_2P_TX (RW)
 *
 * Configures the Generic Short Read Packet with 2 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX      6
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX(v)   (((v) << 6) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_SR_2P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_SR_2P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_SR_2P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field DCS_SW_0P_TX (RW)
 *
 * Configures the DCS Short Write Packet with 0 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX      7
#define BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX(v)   (((v) << 7) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCS_SW_0P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_DCS_SW_0P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, DCS_SW_0P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field DCS_SW_1P_TX (RW)
 *
 * Configures the DCS Short Write Packet with 1 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX      8
#define BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX(v)   (((v) << 8) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCS_SW_1P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_DCS_SW_1P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, DCS_SW_1P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field DCS_SW_2P_TX (RW)
 *
 * Configures the DCS Short Write Packet with 2 Parameters command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX      9
#define BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX(v)   (((v) << 9) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCS_SW_2P_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_DCS_SW_2P_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, DCS_SW_2P_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field MAX_RD_PKT_SIZE (RW)
 *
 * Configures the Maximum Read Packet Size command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE      10
#define BM_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE(v)   (((v) << 10) & BM_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MAX_RD_PKT_SIZE field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_MAX_RD_PKT_SIZE(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, MAX_RD_PKT_SIZE, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field GEN_LW_TX (RW)
 *
 * Configures the Generic Long Write Packet command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX      11
#define BM_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX(v)   (((v) << 11) & BM_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_LW_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_GEN_LW_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, GEN_LW_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field DCS_LW_TX (RW)
 *
 * Configures the DCS Long Write Packet command transmission type.
 *
 * Values:
 * 0 - High Speed;
 * 1 - Low Power
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX      12
#define BM_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX(v)   (((v) << 12) & BM_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DCS_LW_TX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_DCS_LW_TX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, DCS_LW_TX, v)
#endif


/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field EN_ACK_RQST (RW)
 *
 * Enables the acknowledge request after each packet transmission
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST      13
#define BM_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST(v)   ((((reg32_t) v) << 13) & BM_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST(v)   (((v) << 13) & BM_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_ACK_RQST field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_EN_ACK_RQST(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, EN_ACK_RQST, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_MODE_CFG, field EN_TEAR_FX (RW)
 *
 * Enables the tearing effect acknowledge request
 */

#define BP_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX      14
#define BM_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX(v)   ((((reg32_t) v) << 14) & BM_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX)
#else
#define BF_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX(v)   (((v) << 14) & BM_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EN_TEAR_FX field to a new value.
#define BW_MIPI_DSI_CMD_MODE_CFG_EN_TEAR_FX(v)   BF_CS1(MIPI_DSI_CMD_MODE_CFG, EN_TEAR_FX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_TMR_LINE_CFG - Line timer configuration (RW)
 *
 * Size: 32 bits  Offset: 0x28  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HSA_TIME : 9; //!< Configures the Horizontal Synchronism Active period in lane byte clock cycles
        unsigned HBP_TIME : 9; //!< Configures the Horizontal Back Porch period in lane byte clock cycles
        unsigned HLINE_TIME : 14; //!< Configures the size of the total line counted in lane byte cycles
    } B;
} hw_mipi_dsi_tmr_line_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_TMR_LINE_CFG register
 */
#define HW_MIPI_DSI_TMR_LINE_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_TMR_LINE_CFG           (*(volatile hw_mipi_dsi_tmr_line_cfg_t *) HW_MIPI_DSI_TMR_LINE_CFG_ADDR)
#define HW_MIPI_DSI_TMR_LINE_CFG_RD()      (HW_MIPI_DSI_TMR_LINE_CFG.U)
#define HW_MIPI_DSI_TMR_LINE_CFG_WR(v)     (HW_MIPI_DSI_TMR_LINE_CFG.U = (v))
#define HW_MIPI_DSI_TMR_LINE_CFG_SET(v)    (HW_MIPI_DSI_TMR_LINE_CFG_WR(HW_MIPI_DSI_TMR_LINE_CFG_RD() |  (v)))
#define HW_MIPI_DSI_TMR_LINE_CFG_CLR(v)    (HW_MIPI_DSI_TMR_LINE_CFG_WR(HW_MIPI_DSI_TMR_LINE_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_TMR_LINE_CFG_TOG(v)    (HW_MIPI_DSI_TMR_LINE_CFG_WR(HW_MIPI_DSI_TMR_LINE_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_TMR_LINE_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_TMR_LINE_CFG, field HSA_TIME (RW)
 *
 * Configures the Horizontal Synchronism Active period in lane byte clock cycles
 */

#define BP_MIPI_DSI_TMR_LINE_CFG_HSA_TIME      0
#define BM_MIPI_DSI_TMR_LINE_CFG_HSA_TIME      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_TMR_LINE_CFG_HSA_TIME(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_TMR_LINE_CFG_HSA_TIME)
#else
#define BF_MIPI_DSI_TMR_LINE_CFG_HSA_TIME(v)   (((v) << 0) & BM_MIPI_DSI_TMR_LINE_CFG_HSA_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSA_TIME field to a new value.
#define BW_MIPI_DSI_TMR_LINE_CFG_HSA_TIME(v)   BF_CS1(MIPI_DSI_TMR_LINE_CFG, HSA_TIME, v)
#endif

/* --- Register HW_MIPI_DSI_TMR_LINE_CFG, field HBP_TIME (RW)
 *
 * Configures the Horizontal Back Porch period in lane byte clock cycles
 */

#define BP_MIPI_DSI_TMR_LINE_CFG_HBP_TIME      9
#define BM_MIPI_DSI_TMR_LINE_CFG_HBP_TIME      0x0003fe00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_TMR_LINE_CFG_HBP_TIME(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_TMR_LINE_CFG_HBP_TIME)
#else
#define BF_MIPI_DSI_TMR_LINE_CFG_HBP_TIME(v)   (((v) << 9) & BM_MIPI_DSI_TMR_LINE_CFG_HBP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HBP_TIME field to a new value.
#define BW_MIPI_DSI_TMR_LINE_CFG_HBP_TIME(v)   BF_CS1(MIPI_DSI_TMR_LINE_CFG, HBP_TIME, v)
#endif

/* --- Register HW_MIPI_DSI_TMR_LINE_CFG, field HLINE_TIME (RW)
 *
 * Configures the size of the total line counted in lane byte cycles
 */

#define BP_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME      18
#define BM_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME      0xfffc0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME(v)   ((((reg32_t) v) << 18) & BM_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME)
#else
#define BF_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME(v)   (((v) << 18) & BM_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HLINE_TIME field to a new value.
#define BW_MIPI_DSI_TMR_LINE_CFG_HLINE_TIME(v)   BF_CS1(MIPI_DSI_TMR_LINE_CFG, HLINE_TIME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_VTIMING_CFG - Vertical timing configuration (RW)
 *
 * Size: 32 bits  Offset: 0x2c  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VSA_LINES : 4; //!< Configures the Vertical Synchronism Active period measured in horizontal lines
        unsigned VBP_LINES : 6; //!< Configures the Vertical Back Porch period measured in horizontal lines
        unsigned VFP_LINES : 6; //!< Configures the Vertical Front Porch period measured in horizontal lines
        unsigned V_ACTIVE_LINES : 11; //!< Configures the Vertical Active period measured in horizontal lines
        unsigned RESERVED0 : 5; //!< Reserved
    } B;
} hw_mipi_dsi_vtiming_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_VTIMING_CFG register
 */
#define HW_MIPI_DSI_VTIMING_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_VTIMING_CFG           (*(volatile hw_mipi_dsi_vtiming_cfg_t *) HW_MIPI_DSI_VTIMING_CFG_ADDR)
#define HW_MIPI_DSI_VTIMING_CFG_RD()      (HW_MIPI_DSI_VTIMING_CFG.U)
#define HW_MIPI_DSI_VTIMING_CFG_WR(v)     (HW_MIPI_DSI_VTIMING_CFG.U = (v))
#define HW_MIPI_DSI_VTIMING_CFG_SET(v)    (HW_MIPI_DSI_VTIMING_CFG_WR(HW_MIPI_DSI_VTIMING_CFG_RD() |  (v)))
#define HW_MIPI_DSI_VTIMING_CFG_CLR(v)    (HW_MIPI_DSI_VTIMING_CFG_WR(HW_MIPI_DSI_VTIMING_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_VTIMING_CFG_TOG(v)    (HW_MIPI_DSI_VTIMING_CFG_WR(HW_MIPI_DSI_VTIMING_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_VTIMING_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_VTIMING_CFG, field VSA_LINES (RW)
 *
 * Configures the Vertical Synchronism Active period measured in horizontal lines
 */

#define BP_MIPI_DSI_VTIMING_CFG_VSA_LINES      0
#define BM_MIPI_DSI_VTIMING_CFG_VSA_LINES      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VTIMING_CFG_VSA_LINES(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_VTIMING_CFG_VSA_LINES)
#else
#define BF_MIPI_DSI_VTIMING_CFG_VSA_LINES(v)   (((v) << 0) & BM_MIPI_DSI_VTIMING_CFG_VSA_LINES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VSA_LINES field to a new value.
#define BW_MIPI_DSI_VTIMING_CFG_VSA_LINES(v)   BF_CS1(MIPI_DSI_VTIMING_CFG, VSA_LINES, v)
#endif

/* --- Register HW_MIPI_DSI_VTIMING_CFG, field VBP_LINES (RW)
 *
 * Configures the Vertical Back Porch period measured in horizontal lines
 */

#define BP_MIPI_DSI_VTIMING_CFG_VBP_LINES      4
#define BM_MIPI_DSI_VTIMING_CFG_VBP_LINES      0x000003f0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VTIMING_CFG_VBP_LINES(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_VTIMING_CFG_VBP_LINES)
#else
#define BF_MIPI_DSI_VTIMING_CFG_VBP_LINES(v)   (((v) << 4) & BM_MIPI_DSI_VTIMING_CFG_VBP_LINES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VBP_LINES field to a new value.
#define BW_MIPI_DSI_VTIMING_CFG_VBP_LINES(v)   BF_CS1(MIPI_DSI_VTIMING_CFG, VBP_LINES, v)
#endif

/* --- Register HW_MIPI_DSI_VTIMING_CFG, field VFP_LINES (RW)
 *
 * Configures the Vertical Front Porch period measured in horizontal lines
 */

#define BP_MIPI_DSI_VTIMING_CFG_VFP_LINES      10
#define BM_MIPI_DSI_VTIMING_CFG_VFP_LINES      0x0000fc00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VTIMING_CFG_VFP_LINES(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_VTIMING_CFG_VFP_LINES)
#else
#define BF_MIPI_DSI_VTIMING_CFG_VFP_LINES(v)   (((v) << 10) & BM_MIPI_DSI_VTIMING_CFG_VFP_LINES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the VFP_LINES field to a new value.
#define BW_MIPI_DSI_VTIMING_CFG_VFP_LINES(v)   BF_CS1(MIPI_DSI_VTIMING_CFG, VFP_LINES, v)
#endif

/* --- Register HW_MIPI_DSI_VTIMING_CFG, field V_ACTIVE_LINES (RW)
 *
 * Configures the Vertical Active period measured in horizontal lines
 */

#define BP_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES      16
#define BM_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES      0x07ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES)
#else
#define BF_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES(v)   (((v) << 16) & BM_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the V_ACTIVE_LINES field to a new value.
#define BW_MIPI_DSI_VTIMING_CFG_V_ACTIVE_LINES(v)   BF_CS1(MIPI_DSI_VTIMING_CFG, V_ACTIVE_LINES, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_TMR_CFG - D-PHY timing configuration (RW)
 *
 * Size: 32 bits  Offset: 0x30  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BTA_TIME : 12; //!< Configures the maximum time required to perform the Bus Turn Around operation measured in lane byte clock cycles
        unsigned PHY_LP2HS_TIME : 8; //!< Configures the maximum time that the PHY takes to go from Low Power to High Speed transmission measured in lane byte clock cycles
        unsigned PHY_HS2LP_TIME : 8; //!< Configures the maximum time that the PHY takes to go from High Speed to Low Power transmission measured in lane byte clock cycles
        unsigned RESERVED0 : 4; //!< Reserved
    } B;
} hw_mipi_dsi_phy_tmr_cfg_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_TMR_CFG register
 */
#define HW_MIPI_DSI_PHY_TMR_CFG_ADDR      (REGS_MIPI_DSI_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_TMR_CFG           (*(volatile hw_mipi_dsi_phy_tmr_cfg_t *) HW_MIPI_DSI_PHY_TMR_CFG_ADDR)
#define HW_MIPI_DSI_PHY_TMR_CFG_RD()      (HW_MIPI_DSI_PHY_TMR_CFG.U)
#define HW_MIPI_DSI_PHY_TMR_CFG_WR(v)     (HW_MIPI_DSI_PHY_TMR_CFG.U = (v))
#define HW_MIPI_DSI_PHY_TMR_CFG_SET(v)    (HW_MIPI_DSI_PHY_TMR_CFG_WR(HW_MIPI_DSI_PHY_TMR_CFG_RD() |  (v)))
#define HW_MIPI_DSI_PHY_TMR_CFG_CLR(v)    (HW_MIPI_DSI_PHY_TMR_CFG_WR(HW_MIPI_DSI_PHY_TMR_CFG_RD() & ~(v)))
#define HW_MIPI_DSI_PHY_TMR_CFG_TOG(v)    (HW_MIPI_DSI_PHY_TMR_CFG_WR(HW_MIPI_DSI_PHY_TMR_CFG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_TMR_CFG bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_TMR_CFG, field BTA_TIME (RW)
 *
 * Configures the maximum time required to perform the Bus Turn Around operation measured in lane
 * byte clock cycles
 */

#define BP_MIPI_DSI_PHY_TMR_CFG_BTA_TIME      0
#define BM_MIPI_DSI_PHY_TMR_CFG_BTA_TIME      0x00000fff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TMR_CFG_BTA_TIME(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_TMR_CFG_BTA_TIME)
#else
#define BF_MIPI_DSI_PHY_TMR_CFG_BTA_TIME(v)   (((v) << 0) & BM_MIPI_DSI_PHY_TMR_CFG_BTA_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BTA_TIME field to a new value.
#define BW_MIPI_DSI_PHY_TMR_CFG_BTA_TIME(v)   BF_CS1(MIPI_DSI_PHY_TMR_CFG, BTA_TIME, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_TMR_CFG, field PHY_LP2HS_TIME (RW)
 *
 * Configures the maximum time that the PHY takes to go from Low Power to High Speed transmission
 * measured in lane byte clock cycles
 */

#define BP_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME      12
#define BM_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME      0x000ff000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME)
#else
#define BF_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME(v)   (((v) << 12) & BM_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_LP2HS_TIME field to a new value.
#define BW_MIPI_DSI_PHY_TMR_CFG_PHY_LP2HS_TIME(v)   BF_CS1(MIPI_DSI_PHY_TMR_CFG, PHY_LP2HS_TIME, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_TMR_CFG, field PHY_HS2LP_TIME (RW)
 *
 * Configures the maximum time that the PHY takes to go from High Speed to Low Power transmission
 * measured in lane byte clock cycles
 */

#define BP_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME      20
#define BM_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME      0x0ff00000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME(v)   ((((reg32_t) v) << 20) & BM_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME)
#else
#define BF_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME(v)   (((v) << 20) & BM_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_HS2LP_TIME field to a new value.
#define BW_MIPI_DSI_PHY_TMR_CFG_PHY_HS2LP_TIME(v)   BF_CS1(MIPI_DSI_PHY_TMR_CFG, PHY_HS2LP_TIME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_GEN_HDR - Generic packet Header configuration (RW)
 *
 * Size: 32 bits  Offset: 0x34  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GEN_HTYPE : 8; //!< Configures the packet type to be transmitted through the generic interface. Writing to this register triggers packet transmission (Payload must be written in advance)
        unsigned GEN_HDATA : 16; //!< Configures the packet data to be transmitted through the generic interface
        unsigned RESERVED0 : 8; //!< Reserved
    } B;
} hw_mipi_dsi_gen_hdr_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_GEN_HDR register
 */
#define HW_MIPI_DSI_GEN_HDR_ADDR      (REGS_MIPI_DSI_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_GEN_HDR           (*(volatile hw_mipi_dsi_gen_hdr_t *) HW_MIPI_DSI_GEN_HDR_ADDR)
#define HW_MIPI_DSI_GEN_HDR_RD()      (HW_MIPI_DSI_GEN_HDR.U)
#define HW_MIPI_DSI_GEN_HDR_WR(v)     (HW_MIPI_DSI_GEN_HDR.U = (v))
#define HW_MIPI_DSI_GEN_HDR_SET(v)    (HW_MIPI_DSI_GEN_HDR_WR(HW_MIPI_DSI_GEN_HDR_RD() |  (v)))
#define HW_MIPI_DSI_GEN_HDR_CLR(v)    (HW_MIPI_DSI_GEN_HDR_WR(HW_MIPI_DSI_GEN_HDR_RD() & ~(v)))
#define HW_MIPI_DSI_GEN_HDR_TOG(v)    (HW_MIPI_DSI_GEN_HDR_WR(HW_MIPI_DSI_GEN_HDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_GEN_HDR bitfields
 */

/* --- Register HW_MIPI_DSI_GEN_HDR, field GEN_HTYPE (RW)
 *
 * Configures the packet type to be transmitted through the generic interface. Writing to this
 * register triggers packet transmission (Payload must be written in advance)
 */

#define BP_MIPI_DSI_GEN_HDR_GEN_HTYPE      0
#define BM_MIPI_DSI_GEN_HDR_GEN_HTYPE      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_GEN_HDR_GEN_HTYPE(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_GEN_HDR_GEN_HTYPE)
#else
#define BF_MIPI_DSI_GEN_HDR_GEN_HTYPE(v)   (((v) << 0) & BM_MIPI_DSI_GEN_HDR_GEN_HTYPE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_HTYPE field to a new value.
#define BW_MIPI_DSI_GEN_HDR_GEN_HTYPE(v)   BF_CS1(MIPI_DSI_GEN_HDR, GEN_HTYPE, v)
#endif

/* --- Register HW_MIPI_DSI_GEN_HDR, field GEN_HDATA (RW)
 *
 * Configures the packet data to be transmitted through the generic interface
 */

#define BP_MIPI_DSI_GEN_HDR_GEN_HDATA      8
#define BM_MIPI_DSI_GEN_HDR_GEN_HDATA      0x00ffff00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_GEN_HDR_GEN_HDATA(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_GEN_HDR_GEN_HDATA)
#else
#define BF_MIPI_DSI_GEN_HDR_GEN_HDATA(v)   (((v) << 8) & BM_MIPI_DSI_GEN_HDR_GEN_HDATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_HDATA field to a new value.
#define BW_MIPI_DSI_GEN_HDR_GEN_HDATA(v)   BF_CS1(MIPI_DSI_GEN_HDR, GEN_HDATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_GEN_PLD_DATA - Generic payload data in/out (RW)
 *
 * Size: 32 bits  Offset: 0x38  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GEN_PLD_DATA : 32; //!< This register contains the input/output generic packet data. Write access to it writes the content of the packet payload. Read access reads the incoming generic read data
    } B;
} hw_mipi_dsi_gen_pld_data_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_GEN_PLD_DATA register
 */
#define HW_MIPI_DSI_GEN_PLD_DATA_ADDR      (REGS_MIPI_DSI_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_GEN_PLD_DATA           (*(volatile hw_mipi_dsi_gen_pld_data_t *) HW_MIPI_DSI_GEN_PLD_DATA_ADDR)
#define HW_MIPI_DSI_GEN_PLD_DATA_RD()      (HW_MIPI_DSI_GEN_PLD_DATA.U)
#define HW_MIPI_DSI_GEN_PLD_DATA_WR(v)     (HW_MIPI_DSI_GEN_PLD_DATA.U = (v))
#define HW_MIPI_DSI_GEN_PLD_DATA_SET(v)    (HW_MIPI_DSI_GEN_PLD_DATA_WR(HW_MIPI_DSI_GEN_PLD_DATA_RD() |  (v)))
#define HW_MIPI_DSI_GEN_PLD_DATA_CLR(v)    (HW_MIPI_DSI_GEN_PLD_DATA_WR(HW_MIPI_DSI_GEN_PLD_DATA_RD() & ~(v)))
#define HW_MIPI_DSI_GEN_PLD_DATA_TOG(v)    (HW_MIPI_DSI_GEN_PLD_DATA_WR(HW_MIPI_DSI_GEN_PLD_DATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_GEN_PLD_DATA bitfields
 */

/* --- Register HW_MIPI_DSI_GEN_PLD_DATA, field GEN_PLD_DATA (RW)
 *
 * This register contains the input/output generic packet data. Write access to it writes the
 * content of the packet payload. Read access reads the incoming generic read data
 */

#define BP_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA      0
#define BM_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA)
#else
#define BF_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA(v)   (((v) << 0) & BM_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_DATA field to a new value.
#define BW_MIPI_DSI_GEN_PLD_DATA_GEN_PLD_DATA(v)   BF_CS1(MIPI_DSI_GEN_PLD_DATA, GEN_PLD_DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_CMD_PKT_STATUS - Command packet status (RW)
 *
 * Size: 32 bits  Offset: 0x3c  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GEN_CMD_EMPTY : 1; //!< Reports the empty status of the generic command FIFO
        unsigned GEN_CMD_FULL : 1; //!< Reports the full status of the generic command FIFO
        unsigned GEN_PLD_W_EMPTY : 1; //!< Reports the empty status of the generic write payload FIFO
        unsigned GEN_PLD_W_FULL : 1; //!< Reports the full status of the generic write payload FIFO
        unsigned GEN_PLD_R_EMPTY : 1; //!< Reports the empty status of the generic read payload FIFO
        unsigned GEN_PLD_R_FULL : 1; //!< Reports the full status of the generic read payload FIFO
        unsigned GEN_RD_CMD_BUSY : 1; //!< Set when a read command is issued and cleared once the entire response is stored in the FIFO
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned DBI_CMD_EMPTY : 1; //!< Reports the empty status of the DBI command FIFO
        unsigned DBI_CMD_FULL : 1; //!< Reports the full status of the DBI command FIFO
        unsigned DBI_PLD_W_EMPTY : 1; //!< Reports the empty status of the DBI write payload FIFO
        unsigned DBI_PLD_W_FULL : 1; //!< Reports the full status of the DBI write payload FIFO
        unsigned DBI_PLD_R_EMPTY : 1; //!< Reports the empty status of the DBI read payload FIFO
        unsigned DBI_PLD_R_FULL : 1; //!< Reports the full status of the DBI read payload FIFO
        unsigned DBI_RD_CMD_BUSY : 1; //!< Set when a read command is issued and cleared once the entire response is stored in the FIFO
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_mipi_dsi_cmd_pkt_status_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_CMD_PKT_STATUS register
 */
#define HW_MIPI_DSI_CMD_PKT_STATUS_ADDR      (REGS_MIPI_DSI_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_CMD_PKT_STATUS           (*(volatile hw_mipi_dsi_cmd_pkt_status_t *) HW_MIPI_DSI_CMD_PKT_STATUS_ADDR)
#define HW_MIPI_DSI_CMD_PKT_STATUS_RD()      (HW_MIPI_DSI_CMD_PKT_STATUS.U)
#define HW_MIPI_DSI_CMD_PKT_STATUS_WR(v)     (HW_MIPI_DSI_CMD_PKT_STATUS.U = (v))
#define HW_MIPI_DSI_CMD_PKT_STATUS_SET(v)    (HW_MIPI_DSI_CMD_PKT_STATUS_WR(HW_MIPI_DSI_CMD_PKT_STATUS_RD() |  (v)))
#define HW_MIPI_DSI_CMD_PKT_STATUS_CLR(v)    (HW_MIPI_DSI_CMD_PKT_STATUS_WR(HW_MIPI_DSI_CMD_PKT_STATUS_RD() & ~(v)))
#define HW_MIPI_DSI_CMD_PKT_STATUS_TOG(v)    (HW_MIPI_DSI_CMD_PKT_STATUS_WR(HW_MIPI_DSI_CMD_PKT_STATUS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_CMD_PKT_STATUS bitfields
 */

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_CMD_EMPTY (RW)
 *
 * Reports the empty status of the generic command FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY      0
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY(v)   (((v) << 0) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_CMD_EMPTY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_EMPTY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_CMD_EMPTY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_CMD_FULL (RW)
 *
 * Reports the full status of the generic command FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL      1
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL(v)   (((v) << 1) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_CMD_FULL field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_CMD_FULL(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_CMD_FULL, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_PLD_W_EMPTY (RW)
 *
 * Reports the empty status of the generic write payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY      2
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY(v)   (((v) << 2) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_W_EMPTY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_EMPTY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_PLD_W_EMPTY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_PLD_W_FULL (RW)
 *
 * Reports the full status of the generic write payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL      3
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL(v)   (((v) << 3) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_W_FULL field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_W_FULL(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_PLD_W_FULL, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_PLD_R_EMPTY (RW)
 *
 * Reports the empty status of the generic read payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY      4
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY(v)   (((v) << 4) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_R_EMPTY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_EMPTY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_PLD_R_EMPTY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_PLD_R_FULL (RW)
 *
 * Reports the full status of the generic read payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL      5
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL(v)   (((v) << 5) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_R_FULL field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_PLD_R_FULL(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_PLD_R_FULL, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field GEN_RD_CMD_BUSY (RW)
 *
 * Set when a read command is issued and cleared once the entire response is stored in the FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY      6
#define BM_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY(v)   (((v) << 6) & BM_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_RD_CMD_BUSY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_GEN_RD_CMD_BUSY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, GEN_RD_CMD_BUSY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field RESERVED1 (RW)
 *
 * Reserved
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_RESERVED1      7
#define BM_MIPI_DSI_CMD_PKT_STATUS_RESERVED1      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_RESERVED1(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_CMD_PKT_STATUS_RESERVED1)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_RESERVED1(v)   (((v) << 7) & BM_MIPI_DSI_CMD_PKT_STATUS_RESERVED1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESERVED1 field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_RESERVED1(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, RESERVED1, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_CMD_EMPTY (RW)
 *
 * Reports the empty status of the DBI command FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY      8
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY(v)   (((v) << 8) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_CMD_EMPTY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_EMPTY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_CMD_EMPTY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_CMD_FULL (RW)
 *
 * Reports the full status of the DBI command FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL      9
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL(v)   (((v) << 9) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_CMD_FULL field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_CMD_FULL(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_CMD_FULL, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_PLD_W_EMPTY (RW)
 *
 * Reports the empty status of the DBI write payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY      10
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY(v)   (((v) << 10) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_W_EMPTY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_EMPTY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_PLD_W_EMPTY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_PLD_W_FULL (RW)
 *
 * Reports the full status of the DBI write payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL      11
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL(v)   (((v) << 11) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_W_FULL field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_W_FULL(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_PLD_W_FULL, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_PLD_R_EMPTY (RW)
 *
 * Reports the empty status of the DBI read payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY      12
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY(v)   (((v) << 12) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_R_EMPTY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_EMPTY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_PLD_R_EMPTY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_PLD_R_FULL (RW)
 *
 * Reports the full status of the DBI read payload FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL      13
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL(v)   ((((reg32_t) v) << 13) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL(v)   (((v) << 13) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_R_FULL field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_PLD_R_FULL(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_PLD_R_FULL, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field DBI_RD_CMD_BUSY (RW)
 *
 * Set when a read command is issued and cleared once the entire response is stored in the FIFO
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY      14
#define BM_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY(v)   ((((reg32_t) v) << 14) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY(v)   (((v) << 14) & BM_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_RD_CMD_BUSY field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_DBI_RD_CMD_BUSY(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, DBI_RD_CMD_BUSY, v)
#endif

/* --- Register HW_MIPI_DSI_CMD_PKT_STATUS, field RESERVED2 (RW)
 *
 * Reserved
 */

#define BP_MIPI_DSI_CMD_PKT_STATUS_RESERVED2      15
#define BM_MIPI_DSI_CMD_PKT_STATUS_RESERVED2      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_CMD_PKT_STATUS_RESERVED2(v)   ((((reg32_t) v) << 15) & BM_MIPI_DSI_CMD_PKT_STATUS_RESERVED2)
#else
#define BF_MIPI_DSI_CMD_PKT_STATUS_RESERVED2(v)   (((v) << 15) & BM_MIPI_DSI_CMD_PKT_STATUS_RESERVED2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RESERVED2 field to a new value.
#define BW_MIPI_DSI_CMD_PKT_STATUS_RESERVED2(v)   BF_CS1(MIPI_DSI_CMD_PKT_STATUS, RESERVED2, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_TO_CNT_CFG0 - Time Out timers configuration (RW)
 *
 * Size: 32 bits  Offset: 0x40  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned HSTX_TO_CNT : 16; //!< Configures the time out counter that will trigger a High Speed Transmission Time Out Contention Detection (Measured in TO_CLK_DIVISION cycles)
        unsigned LPRX_TO_CNT : 16; //!< Configures the time out counter that will trigger a Low Power Reception Time Out Contention Detection. (Measured in TO_CLK_DIVISION cycles)
    } B;
} hw_mipi_dsi_to_cnt_cfg0_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_TO_CNT_CFG0 register
 */
#define HW_MIPI_DSI_TO_CNT_CFG0_ADDR      (REGS_MIPI_DSI_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_TO_CNT_CFG0           (*(volatile hw_mipi_dsi_to_cnt_cfg0_t *) HW_MIPI_DSI_TO_CNT_CFG0_ADDR)
#define HW_MIPI_DSI_TO_CNT_CFG0_RD()      (HW_MIPI_DSI_TO_CNT_CFG0.U)
#define HW_MIPI_DSI_TO_CNT_CFG0_WR(v)     (HW_MIPI_DSI_TO_CNT_CFG0.U = (v))
#define HW_MIPI_DSI_TO_CNT_CFG0_SET(v)    (HW_MIPI_DSI_TO_CNT_CFG0_WR(HW_MIPI_DSI_TO_CNT_CFG0_RD() |  (v)))
#define HW_MIPI_DSI_TO_CNT_CFG0_CLR(v)    (HW_MIPI_DSI_TO_CNT_CFG0_WR(HW_MIPI_DSI_TO_CNT_CFG0_RD() & ~(v)))
#define HW_MIPI_DSI_TO_CNT_CFG0_TOG(v)    (HW_MIPI_DSI_TO_CNT_CFG0_WR(HW_MIPI_DSI_TO_CNT_CFG0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_TO_CNT_CFG0 bitfields
 */

/* --- Register HW_MIPI_DSI_TO_CNT_CFG0, field HSTX_TO_CNT (RW)
 *
 * Configures the time out counter that will trigger a High Speed Transmission Time Out Contention
 * Detection (Measured in TO_CLK_DIVISION cycles)
 */

#define BP_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT      0
#define BM_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT)
#else
#define BF_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT(v)   (((v) << 0) & BM_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTX_TO_CNT field to a new value.
#define BW_MIPI_DSI_TO_CNT_CFG0_HSTX_TO_CNT(v)   BF_CS1(MIPI_DSI_TO_CNT_CFG0, HSTX_TO_CNT, v)
#endif

/* --- Register HW_MIPI_DSI_TO_CNT_CFG0, field LPRX_TO_CNT (RW)
 *
 * Configures the time out counter that will trigger a Low Power Reception Time Out Contention
 * Detection. (Measured in TO_CLK_DIVISION cycles)
 */

#define BP_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT      16
#define BM_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT)
#else
#define BF_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT(v)   (((v) << 16) & BM_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the LPRX_TO_CNT field to a new value.
#define BW_MIPI_DSI_TO_CNT_CFG0_LPRX_TO_CNT(v)   BF_CS1(MIPI_DSI_TO_CNT_CFG0, LPRX_TO_CNT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_ERROR_ST0 - Interrupt status register 0 (RW)
 *
 * Size: 32 bits  Offset: 0x44  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ACK_WITH_ERR_0 : 1; //!< Retrieves SoT Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_1 : 1; //!< Retrieves SoT Sync Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_2 : 1; //!< Retrieves EoT Sync Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_3 : 1; //!< Retrieves Escape Mode Entry Command Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_4 : 1; //!< Retrieves Low-Power Transmit Sync Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_5 : 1; //!< Retrieves HS Receive Timeout Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_6 : 1; //!< Retrieves False Control Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_7 : 1; //!< Retrieves Reserved (specific to device) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_8 : 1; //!< Retrieves ECC Error, single-bit (detected and corrected) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_9 : 1; //!< Retrieves ECC Error, multi-bit (detected, not corrected) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_10 : 1; //!< Retrieves Checksum Error (Long packet only) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_11 : 1; //!< Retrieves DSI Data Type Not Recognized from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_12 : 1; //!< Retrieves DSI VC ID Invalid from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_13 : 1; //!< Retrieves Invalid Transmission Length from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_14 : 1; //!< Retrieves Reserved (specific to device) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_15 : 1; //!< Retrieves DSI Protocol Violation from Display Acknowledge Error Report
        unsigned DPHY_ERRORS_0 : 1; //!< ErrEsc Escape Entry Error from Lane 0
        unsigned DPHY_ERRORS_1 : 1; //!< ErrSyncEsc Low-Power Data Transmission Synchronization Error from Lane 0
        unsigned DPHY_ERRORS_2 : 1; //!< ErrControl Control Error from Lane 0
        unsigned DPHY_ERRORS_3 : 1; //!< ErrContentionLP0 LP0 Contention Error from Lane 0
        unsigned DPHY_ERRORS_4 : 1; //!< ErrContentionLP1 LP1 Contention Error from Lane 0
        unsigned RESERVED0 : 11; //!< Reserved
    } B;
} hw_mipi_dsi_error_st0_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_ERROR_ST0 register
 */
#define HW_MIPI_DSI_ERROR_ST0_ADDR      (REGS_MIPI_DSI_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_ERROR_ST0           (*(volatile hw_mipi_dsi_error_st0_t *) HW_MIPI_DSI_ERROR_ST0_ADDR)
#define HW_MIPI_DSI_ERROR_ST0_RD()      (HW_MIPI_DSI_ERROR_ST0.U)
#define HW_MIPI_DSI_ERROR_ST0_WR(v)     (HW_MIPI_DSI_ERROR_ST0.U = (v))
#define HW_MIPI_DSI_ERROR_ST0_SET(v)    (HW_MIPI_DSI_ERROR_ST0_WR(HW_MIPI_DSI_ERROR_ST0_RD() |  (v)))
#define HW_MIPI_DSI_ERROR_ST0_CLR(v)    (HW_MIPI_DSI_ERROR_ST0_WR(HW_MIPI_DSI_ERROR_ST0_RD() & ~(v)))
#define HW_MIPI_DSI_ERROR_ST0_TOG(v)    (HW_MIPI_DSI_ERROR_ST0_WR(HW_MIPI_DSI_ERROR_ST0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_ERROR_ST0 bitfields
 */

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_0 (RW)
 *
 * Retrieves SoT Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0      0
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0(v)   (((v) << 0) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_0 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_0(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_0, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_1 (RW)
 *
 * Retrieves SoT Sync Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1      1
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1(v)   (((v) << 1) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_1 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_1(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_1, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_2 (RW)
 *
 * Retrieves EoT Sync Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2      2
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2(v)   (((v) << 2) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_2 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_2(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_2, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_3 (RW)
 *
 * Retrieves Escape Mode Entry Command Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3      3
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3(v)   (((v) << 3) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_3 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_3(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_3, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_4 (RW)
 *
 * Retrieves Low-Power Transmit Sync Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4      4
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4(v)   (((v) << 4) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_4 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_4(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_4, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_5 (RW)
 *
 * Retrieves HS Receive Timeout Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5      5
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5(v)   (((v) << 5) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_5 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_5(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_5, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_6 (RW)
 *
 * Retrieves False Control Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6      6
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6(v)   (((v) << 6) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_6 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_6(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_6, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_7 (RW)
 *
 * Retrieves Reserved (specific to device) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7      7
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7(v)   (((v) << 7) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_7 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_7(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_7, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_8 (RW)
 *
 * Retrieves ECC Error, single-bit (detected and corrected) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8      8
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8(v)   (((v) << 8) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_8 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_8(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_8, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_9 (RW)
 *
 * Retrieves ECC Error, multi-bit (detected, not corrected) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9      9
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9(v)   (((v) << 9) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_9 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_9(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_9, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_10 (RW)
 *
 * Retrieves Checksum Error (Long packet only) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10      10
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10(v)   (((v) << 10) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_10 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_10(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_10, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_11 (RW)
 *
 * Retrieves DSI Data Type Not Recognized from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11      11
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11(v)   (((v) << 11) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_11 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_11(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_11, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_12 (RW)
 *
 * Retrieves DSI VC ID Invalid from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12      12
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12(v)   (((v) << 12) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_12 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_12(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_12, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_13 (RW)
 *
 * Retrieves Invalid Transmission Length from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13      13
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13(v)   ((((reg32_t) v) << 13) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13(v)   (((v) << 13) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_13 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_13(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_13, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_14 (RW)
 *
 * Retrieves Reserved (specific to device) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14      14
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14(v)   ((((reg32_t) v) << 14) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14(v)   (((v) << 14) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_14 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_14(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_14, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field ACK_WITH_ERR_15 (RW)
 *
 * Retrieves DSI Protocol Violation from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15      15
#define BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15(v)   ((((reg32_t) v) << 15) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15)
#else
#define BF_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15(v)   (((v) << 15) & BM_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_15 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_ACK_WITH_ERR_15(v)   BF_CS1(MIPI_DSI_ERROR_ST0, ACK_WITH_ERR_15, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field DPHY_ERRORS_0 (RW)
 *
 * ErrEsc Escape Entry Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0      16
#define BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0)
#else
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0(v)   (((v) << 16) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_0 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_0(v)   BF_CS1(MIPI_DSI_ERROR_ST0, DPHY_ERRORS_0, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field DPHY_ERRORS_1 (RW)
 *
 * ErrSyncEsc Low-Power Data Transmission Synchronization Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1      17
#define BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1(v)   ((((reg32_t) v) << 17) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1)
#else
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1(v)   (((v) << 17) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_1 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_1(v)   BF_CS1(MIPI_DSI_ERROR_ST0, DPHY_ERRORS_1, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field DPHY_ERRORS_2 (RW)
 *
 * ErrControl Control Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2      18
#define BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2(v)   ((((reg32_t) v) << 18) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2)
#else
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2(v)   (((v) << 18) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_2 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_2(v)   BF_CS1(MIPI_DSI_ERROR_ST0, DPHY_ERRORS_2, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field DPHY_ERRORS_3 (RW)
 *
 * ErrContentionLP0 LP0 Contention Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3      19
#define BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3(v)   ((((reg32_t) v) << 19) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3)
#else
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3(v)   (((v) << 19) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_3 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_3(v)   BF_CS1(MIPI_DSI_ERROR_ST0, DPHY_ERRORS_3, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST0, field DPHY_ERRORS_4 (RW)
 *
 * ErrContentionLP1 LP1 Contention Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4      20
#define BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4(v)   ((((reg32_t) v) << 20) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4)
#else
#define BF_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4(v)   (((v) << 20) & BM_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_4 field to a new value.
#define BW_MIPI_DSI_ERROR_ST0_DPHY_ERRORS_4(v)   BF_CS1(MIPI_DSI_ERROR_ST0, DPHY_ERRORS_4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_ERROR_ST1 - Interrupt status register 1 (RW)
 *
 * Size: 32 bits  Offset: 0x48  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TO_HS_TX : 1; //!< High Speed Transmission Time Out Counter reached the end and Contention Detection as been detected
        unsigned TO_LP_RX : 1; //!< Low Power Reception Time Out Counter reached the end and Contention Detection as been detected
        unsigned ECC_SINLGE_ERR : 1; //!< ECC single error was detected and corrected in a received packet
        unsigned ECC_MULTI_ERR : 1; //!< ECC multiple error was detected in a received packet
        unsigned CRC_ERR : 1; //!< CRC error was detected in the received packet payload
        unsigned PKT_SIZE_ERR : 1; //!< Packet size error was detected during packet reception
        unsigned EOPT_ERR : 1; //!< EOTp Packet not received at the end of the incoming peripheral transmission
        unsigned DPI_PLD_WR_ERR : 1; //!< During a DPI pixel line storage the payload FIFO went full and data stored is corrupted
        unsigned GEN_CMD_WR_ERR : 1; //!< System tried to write a command through the generic interface and FIFO was full, therefore the command was not written
        unsigned GEN_PLD_WR_ERR : 1; //!< System tried to write a payload data through the generic interface and FIFO was full, therefore the payload was not written
        unsigned GEN_PLD_SEND_ERR : 1; //!< During a generic interface packet build, the payload FIFO went empty and data was sent corrupted
        unsigned GEN_PLD_RD_ERR : 1; //!< During a DCS read data, the payload FIFO went empty and data was send to the interface corrupted
        unsigned GEN_PLD_RECV_ERR : 1; //!< During a generic interface packet read back, the payload FIFO went full and received data was corrupted
        unsigned DBI_CMD_WR_ERR : 1; //!< System tried to write a command through the DBI but the command FIFO was full, therefore the command was not written
        unsigned DBI_PLD_WR_ERR : 1; //!< System tried to write payload data through the DBI interface and the FIFO was full, therefore the Command was not written
        unsigned DBI_PLD_RD_ERR : 1; //!< During a DCS read data, the payload FIFO went empty and data was send to the interface corrupted
        unsigned DBI_PLD_RECV_ERR : 1; //!< During a DBI read back packet, the payload FIFO went full and received data was corrupted
        unsigned DBI_ILLEGAL_COMM_ERR : 1; //!< Attempt to write an illegal command on the DPI interface and core blocked by transmission
        unsigned RESERVED0 : 14; //!< Reserved
    } B;
} hw_mipi_dsi_error_st1_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_ERROR_ST1 register
 */
#define HW_MIPI_DSI_ERROR_ST1_ADDR      (REGS_MIPI_DSI_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_ERROR_ST1           (*(volatile hw_mipi_dsi_error_st1_t *) HW_MIPI_DSI_ERROR_ST1_ADDR)
#define HW_MIPI_DSI_ERROR_ST1_RD()      (HW_MIPI_DSI_ERROR_ST1.U)
#define HW_MIPI_DSI_ERROR_ST1_WR(v)     (HW_MIPI_DSI_ERROR_ST1.U = (v))
#define HW_MIPI_DSI_ERROR_ST1_SET(v)    (HW_MIPI_DSI_ERROR_ST1_WR(HW_MIPI_DSI_ERROR_ST1_RD() |  (v)))
#define HW_MIPI_DSI_ERROR_ST1_CLR(v)    (HW_MIPI_DSI_ERROR_ST1_WR(HW_MIPI_DSI_ERROR_ST1_RD() & ~(v)))
#define HW_MIPI_DSI_ERROR_ST1_TOG(v)    (HW_MIPI_DSI_ERROR_ST1_WR(HW_MIPI_DSI_ERROR_ST1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_ERROR_ST1 bitfields
 */

/* --- Register HW_MIPI_DSI_ERROR_ST1, field TO_HS_TX (RW)
 *
 * High Speed Transmission Time Out Counter reached the end and Contention Detection as been
 * detected
 */

#define BP_MIPI_DSI_ERROR_ST1_TO_HS_TX      0
#define BM_MIPI_DSI_ERROR_ST1_TO_HS_TX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_TO_HS_TX(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_ERROR_ST1_TO_HS_TX)
#else
#define BF_MIPI_DSI_ERROR_ST1_TO_HS_TX(v)   (((v) << 0) & BM_MIPI_DSI_ERROR_ST1_TO_HS_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TO_HS_TX field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_TO_HS_TX(v)   BF_CS1(MIPI_DSI_ERROR_ST1, TO_HS_TX, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field TO_LP_RX (RW)
 *
 * Low Power Reception Time Out Counter reached the end and Contention Detection as been detected
 */

#define BP_MIPI_DSI_ERROR_ST1_TO_LP_RX      1
#define BM_MIPI_DSI_ERROR_ST1_TO_LP_RX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_TO_LP_RX(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_ERROR_ST1_TO_LP_RX)
#else
#define BF_MIPI_DSI_ERROR_ST1_TO_LP_RX(v)   (((v) << 1) & BM_MIPI_DSI_ERROR_ST1_TO_LP_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TO_LP_RX field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_TO_LP_RX(v)   BF_CS1(MIPI_DSI_ERROR_ST1, TO_LP_RX, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field ECC_SINLGE_ERR (RW)
 *
 * ECC single error was detected and corrected in a received packet
 */

#define BP_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR      2
#define BM_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR(v)   (((v) << 2) & BM_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_SINLGE_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_ECC_SINLGE_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, ECC_SINLGE_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field ECC_MULTI_ERR (RW)
 *
 * ECC multiple error was detected in a received packet
 */

#define BP_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR      3
#define BM_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR(v)   (((v) << 3) & BM_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_MULTI_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_ECC_MULTI_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, ECC_MULTI_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field CRC_ERR (RW)
 *
 * CRC error was detected in the received packet payload
 */

#define BP_MIPI_DSI_ERROR_ST1_CRC_ERR      4
#define BM_MIPI_DSI_ERROR_ST1_CRC_ERR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_CRC_ERR(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_ERROR_ST1_CRC_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_CRC_ERR(v)   (((v) << 4) & BM_MIPI_DSI_ERROR_ST1_CRC_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRC_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_CRC_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, CRC_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field PKT_SIZE_ERR (RW)
 *
 * Packet size error was detected during packet reception
 */

#define BP_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR      5
#define BM_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR(v)   (((v) << 5) & BM_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PKT_SIZE_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_PKT_SIZE_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, PKT_SIZE_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field EOPT_ERR (RW)
 *
 * EOTp Packet not received at the end of the incoming peripheral transmission
 */

#define BP_MIPI_DSI_ERROR_ST1_EOPT_ERR      6
#define BM_MIPI_DSI_ERROR_ST1_EOPT_ERR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_EOPT_ERR(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_ERROR_ST1_EOPT_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_EOPT_ERR(v)   (((v) << 6) & BM_MIPI_DSI_ERROR_ST1_EOPT_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EOPT_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_EOPT_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, EOPT_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field DPI_PLD_WR_ERR (RW)
 *
 * During a DPI pixel line storage the payload FIFO went full and data stored is corrupted
 */

#define BP_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR      7
#define BM_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR(v)   (((v) << 7) & BM_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPI_PLD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_DPI_PLD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, DPI_PLD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field GEN_CMD_WR_ERR (RW)
 *
 * System tried to write a command through the generic interface and FIFO was full, therefore the
 * command was not written
 */

#define BP_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR      8
#define BM_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR(v)   (((v) << 8) & BM_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_CMD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_GEN_CMD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, GEN_CMD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field GEN_PLD_WR_ERR (RW)
 *
 * System tried to write a payload data through the generic interface and FIFO was full, therefore
 * the payload was not written
 */

#define BP_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR      9
#define BM_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR(v)   (((v) << 9) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_GEN_PLD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, GEN_PLD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field GEN_PLD_SEND_ERR (RW)
 *
 * During a generic interface packet build, the payload FIFO went empty and data was sent corrupted
 */

#define BP_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR      10
#define BM_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR(v)   (((v) << 10) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_SEND_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_GEN_PLD_SEND_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, GEN_PLD_SEND_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field GEN_PLD_RD_ERR (RW)
 *
 * During a DCS read data, the payload FIFO went empty and data was send to the interface corrupted
 */

#define BP_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR      11
#define BM_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR(v)   (((v) << 11) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_RD_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_GEN_PLD_RD_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, GEN_PLD_RD_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field GEN_PLD_RECV_ERR (RW)
 *
 * During a generic interface packet read back, the payload FIFO went full and received data was
 * corrupted
 */

#define BP_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR      12
#define BM_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR(v)   (((v) << 12) & BM_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_RECV_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_GEN_PLD_RECV_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, GEN_PLD_RECV_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field DBI_CMD_WR_ERR (RW)
 *
 * System tried to write a command through the DBI but the command FIFO was full, therefore the
 * command was not written
 */

#define BP_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR      13
#define BM_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR(v)   ((((reg32_t) v) << 13) & BM_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR(v)   (((v) << 13) & BM_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_CMD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_DBI_CMD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, DBI_CMD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field DBI_PLD_WR_ERR (RW)
 *
 * System tried to write payload data through the DBI interface and the FIFO was full, therefore the
 * Command was not written
 */

#define BP_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR      14
#define BM_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR(v)   ((((reg32_t) v) << 14) & BM_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR(v)   (((v) << 14) & BM_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_DBI_PLD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, DBI_PLD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field DBI_PLD_RD_ERR (RW)
 *
 * During a DCS read data, the payload FIFO went empty and data was send to the interface corrupted
 */

#define BP_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR      15
#define BM_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR(v)   ((((reg32_t) v) << 15) & BM_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR(v)   (((v) << 15) & BM_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_RD_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_DBI_PLD_RD_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, DBI_PLD_RD_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field DBI_PLD_RECV_ERR (RW)
 *
 * During a DBI read back packet, the payload FIFO went full and received data was corrupted
 */

#define BP_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR      16
#define BM_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR(v)   (((v) << 16) & BM_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_RECV_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_DBI_PLD_RECV_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, DBI_PLD_RECV_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_ST1, field DBI_ILLEGAL_COMM_ERR (RW)
 *
 * Attempt to write an illegal command on the DPI interface and core blocked by transmission
 */

#define BP_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR      17
#define BM_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR(v)   ((((reg32_t) v) << 17) & BM_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR)
#else
#define BF_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR(v)   (((v) << 17) & BM_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_ILLEGAL_COMM_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_ST1_DBI_ILLEGAL_COMM_ERR(v)   BF_CS1(MIPI_DSI_ERROR_ST1, DBI_ILLEGAL_COMM_ERR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_ERROR_MSK0 - Masks Interrupt generation trigged by ERROR_ST0 register (RW)
 *
 * Size: 32 bits  Offset: 0x4c  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ACK_WITH_ERR_0 : 1; //!< Masks SoT Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_1 : 1; //!< Masks SoT Sync Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_2 : 1; //!< Masks EoT Sync Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_3 : 1; //!< Masks Escape Mode Entry Command Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_4 : 1; //!< Masks Low-Power Transmit Sync Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_5 : 1; //!< Masks HS Receive Timeout Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_6 : 1; //!< Masks False Control Error from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_7 : 1; //!< Masks Reserved (specific to device) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_8 : 1; //!< Masks ECC Error, single-bit (detected and corrected) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_9 : 1; //!< Masks ECC Error, multi-bit (detected, not corrected) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_10 : 1; //!< Masks Checksum Error (Long packet only) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_11 : 1; //!< Masks DSI Data Type Not Recognized from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_12 : 1; //!< Masks DSI VC ID Invalid from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_13 : 1; //!< Masks Invalid Transmission Length from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_14 : 1; //!< Masks Reserved (specific to device) from Display Acknowledge Error Report
        unsigned ACK_WITH_ERR_15 : 1; //!< Masks DSI Protocol Violation from Display Acknowledge Error Report
        unsigned DPHY_ERRORS_0 : 1; //!< ErrEsc Escape Entry Error from Lane 0
        unsigned DPHY_ERRORS_1 : 1; //!< ErrSyncEsc Low-Power Data Transmission Synchronization Error from Lane 0
        unsigned DPHY_ERRORS_2 : 1; //!< ErrControl Control Error from Lane 0
        unsigned DPHY_ERRORS_3 : 1; //!< ErrContentionLP0 LP0 Contention Error from Lane 0
        unsigned DPHY_ERRORS_4 : 1; //!< ErrContentionLP1 LP1 Contention Error from Lane 0
        unsigned RESERVED0 : 11; //!< Reserved
    } B;
} hw_mipi_dsi_error_msk0_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_ERROR_MSK0 register
 */
#define HW_MIPI_DSI_ERROR_MSK0_ADDR      (REGS_MIPI_DSI_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_ERROR_MSK0           (*(volatile hw_mipi_dsi_error_msk0_t *) HW_MIPI_DSI_ERROR_MSK0_ADDR)
#define HW_MIPI_DSI_ERROR_MSK0_RD()      (HW_MIPI_DSI_ERROR_MSK0.U)
#define HW_MIPI_DSI_ERROR_MSK0_WR(v)     (HW_MIPI_DSI_ERROR_MSK0.U = (v))
#define HW_MIPI_DSI_ERROR_MSK0_SET(v)    (HW_MIPI_DSI_ERROR_MSK0_WR(HW_MIPI_DSI_ERROR_MSK0_RD() |  (v)))
#define HW_MIPI_DSI_ERROR_MSK0_CLR(v)    (HW_MIPI_DSI_ERROR_MSK0_WR(HW_MIPI_DSI_ERROR_MSK0_RD() & ~(v)))
#define HW_MIPI_DSI_ERROR_MSK0_TOG(v)    (HW_MIPI_DSI_ERROR_MSK0_WR(HW_MIPI_DSI_ERROR_MSK0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_ERROR_MSK0 bitfields
 */

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_0 (RW)
 *
 * Masks SoT Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0      0
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0(v)   (((v) << 0) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_0 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_0(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_0, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_1 (RW)
 *
 * Masks SoT Sync Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1      1
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1(v)   (((v) << 1) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_1 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_1(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_1, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_2 (RW)
 *
 * Masks EoT Sync Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2      2
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2(v)   (((v) << 2) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_2 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_2(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_2, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_3 (RW)
 *
 * Masks Escape Mode Entry Command Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3      3
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3(v)   (((v) << 3) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_3 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_3(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_3, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_4 (RW)
 *
 * Masks Low-Power Transmit Sync Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4      4
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4(v)   (((v) << 4) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_4 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_4(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_4, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_5 (RW)
 *
 * Masks HS Receive Timeout Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5      5
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5(v)   (((v) << 5) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_5 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_5(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_5, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_6 (RW)
 *
 * Masks False Control Error from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6      6
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6(v)   (((v) << 6) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_6 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_6(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_6, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_7 (RW)
 *
 * Masks Reserved (specific to device) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7      7
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7(v)   (((v) << 7) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_7 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_7(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_7, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_8 (RW)
 *
 * Masks ECC Error, single-bit (detected and corrected) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8      8
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8(v)   (((v) << 8) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_8 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_8(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_8, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_9 (RW)
 *
 * Masks ECC Error, multi-bit (detected, not corrected) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9      9
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9(v)   (((v) << 9) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_9 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_9(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_9, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_10 (RW)
 *
 * Masks Checksum Error (Long packet only) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10      10
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10(v)   (((v) << 10) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_10 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_10(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_10, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_11 (RW)
 *
 * Masks DSI Data Type Not Recognized from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11      11
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11(v)   (((v) << 11) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_11 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_11(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_11, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_12 (RW)
 *
 * Masks DSI VC ID Invalid from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12      12
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12(v)   (((v) << 12) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_12 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_12(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_12, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_13 (RW)
 *
 * Masks Invalid Transmission Length from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13      13
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13(v)   ((((reg32_t) v) << 13) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13(v)   (((v) << 13) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_13 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_13(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_13, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_14 (RW)
 *
 * Masks Reserved (specific to device) from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14      14
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14(v)   ((((reg32_t) v) << 14) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14(v)   (((v) << 14) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_14 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_14(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_14, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field ACK_WITH_ERR_15 (RW)
 *
 * Masks DSI Protocol Violation from Display Acknowledge Error Report
 */

#define BP_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15      15
#define BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15(v)   ((((reg32_t) v) << 15) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15)
#else
#define BF_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15(v)   (((v) << 15) & BM_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ACK_WITH_ERR_15 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_ACK_WITH_ERR_15(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, ACK_WITH_ERR_15, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field DPHY_ERRORS_0 (RW)
 *
 * ErrEsc Escape Entry Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0      16
#define BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0)
#else
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0(v)   (((v) << 16) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_0 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_0(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, DPHY_ERRORS_0, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field DPHY_ERRORS_1 (RW)
 *
 * ErrSyncEsc Low-Power Data Transmission Synchronization Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1      17
#define BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1(v)   ((((reg32_t) v) << 17) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1)
#else
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1(v)   (((v) << 17) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_1 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_1(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, DPHY_ERRORS_1, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field DPHY_ERRORS_2 (RW)
 *
 * ErrControl Control Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2      18
#define BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2(v)   ((((reg32_t) v) << 18) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2)
#else
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2(v)   (((v) << 18) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_2 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_2(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, DPHY_ERRORS_2, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field DPHY_ERRORS_3 (RW)
 *
 * ErrContentionLP0 LP0 Contention Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3      19
#define BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3(v)   ((((reg32_t) v) << 19) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3)
#else
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3(v)   (((v) << 19) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_3 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_3(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, DPHY_ERRORS_3, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK0, field DPHY_ERRORS_4 (RW)
 *
 * ErrContentionLP1 LP1 Contention Error from Lane 0
 */

#define BP_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4      20
#define BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4(v)   ((((reg32_t) v) << 20) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4)
#else
#define BF_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4(v)   (((v) << 20) & BM_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_ERRORS_4 field to a new value.
#define BW_MIPI_DSI_ERROR_MSK0_DPHY_ERRORS_4(v)   BF_CS1(MIPI_DSI_ERROR_MSK0, DPHY_ERRORS_4, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_ERROR_MSK1 - Masks Interrupt generation trigged by ERROR_ST1 register (RW)
 *
 * Size: 32 bits  Offset: 0x50  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned TO_HS_TX : 1; //!< Masks High Speed Transmission Time Out Counter error
        unsigned TO_LP_RX : 1; //!< Masks Low Power Reception Time Out Counter error
        unsigned ECC_SINLGE_ERR : 1; //!< Masks ECC single error
        unsigned ECC_MULTI_ERR : 1; //!< Masks ECC multiple error
        unsigned CRC_ERR : 1; //!< Masks CRC error
        unsigned PKT_SIZE_ERR : 1; //!< Masks Packet size error
        unsigned EOPT_ERR : 1; //!< Masks EOTp Packet not received error
        unsigned DPI_PLD_WR_ERR : 1; //!< Masks DPI pixel line payload FIFO full error
        unsigned GEN_CMD_WR_ERR : 1; //!< Masks command FIFO of generic interface full error
        unsigned GEN_PLD_WR_ERR : 1; //!< Masks payload data FIFO of generic interface full error
        unsigned GEN_PLD_SEND_ERR : 1; //!< Masks generic interface packet build FIFO empty error
        unsigned GEN_PLD_RD_ERR : 1; //!< Masks DCS read data payload FIFO empty error
        unsigned GEN_PLD_RECV_ERR : 1; //!< Masks generic interface packet read back FIFO full error
        unsigned DBI_CMD_WR_ERR : 1; //!< Masks DBI command FIFO full error
        unsigned DBI_PLD_WR_ERR : 1; //!< Masks write payload data DBI FIFO full error
        unsigned DBI_PLD_RD_ERR : 1; //!< Masks payload DBI FIFO empty error
        unsigned DBI_PLD_RECV_ERR : 1; //!< Masks DBI read back packet payload FIFO full error
        unsigned DBI_ILLEGAL_COMM_ERR : 1; //!< Masks error attempt to write an illegal command on DPI
        unsigned RESERVED0 : 14; //!< Reserved
    } B;
} hw_mipi_dsi_error_msk1_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_ERROR_MSK1 register
 */
#define HW_MIPI_DSI_ERROR_MSK1_ADDR      (REGS_MIPI_DSI_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_ERROR_MSK1           (*(volatile hw_mipi_dsi_error_msk1_t *) HW_MIPI_DSI_ERROR_MSK1_ADDR)
#define HW_MIPI_DSI_ERROR_MSK1_RD()      (HW_MIPI_DSI_ERROR_MSK1.U)
#define HW_MIPI_DSI_ERROR_MSK1_WR(v)     (HW_MIPI_DSI_ERROR_MSK1.U = (v))
#define HW_MIPI_DSI_ERROR_MSK1_SET(v)    (HW_MIPI_DSI_ERROR_MSK1_WR(HW_MIPI_DSI_ERROR_MSK1_RD() |  (v)))
#define HW_MIPI_DSI_ERROR_MSK1_CLR(v)    (HW_MIPI_DSI_ERROR_MSK1_WR(HW_MIPI_DSI_ERROR_MSK1_RD() & ~(v)))
#define HW_MIPI_DSI_ERROR_MSK1_TOG(v)    (HW_MIPI_DSI_ERROR_MSK1_WR(HW_MIPI_DSI_ERROR_MSK1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_ERROR_MSK1 bitfields
 */

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field TO_HS_TX (RW)
 *
 * Masks High Speed Transmission Time Out Counter error
 */

#define BP_MIPI_DSI_ERROR_MSK1_TO_HS_TX      0
#define BM_MIPI_DSI_ERROR_MSK1_TO_HS_TX      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_TO_HS_TX(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_ERROR_MSK1_TO_HS_TX)
#else
#define BF_MIPI_DSI_ERROR_MSK1_TO_HS_TX(v)   (((v) << 0) & BM_MIPI_DSI_ERROR_MSK1_TO_HS_TX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TO_HS_TX field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_TO_HS_TX(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, TO_HS_TX, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field TO_LP_RX (RW)
 *
 * Masks Low Power Reception Time Out Counter error
 */

#define BP_MIPI_DSI_ERROR_MSK1_TO_LP_RX      1
#define BM_MIPI_DSI_ERROR_MSK1_TO_LP_RX      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_TO_LP_RX(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_ERROR_MSK1_TO_LP_RX)
#else
#define BF_MIPI_DSI_ERROR_MSK1_TO_LP_RX(v)   (((v) << 1) & BM_MIPI_DSI_ERROR_MSK1_TO_LP_RX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the TO_LP_RX field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_TO_LP_RX(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, TO_LP_RX, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field ECC_SINLGE_ERR (RW)
 *
 * Masks ECC single error
 */

#define BP_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR      2
#define BM_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR(v)   (((v) << 2) & BM_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_SINLGE_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_ECC_SINLGE_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, ECC_SINLGE_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field ECC_MULTI_ERR (RW)
 *
 * Masks ECC multiple error
 */

#define BP_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR      3
#define BM_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR(v)   (((v) << 3) & BM_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_MULTI_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_ECC_MULTI_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, ECC_MULTI_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field CRC_ERR (RW)
 *
 * Masks CRC error
 */

#define BP_MIPI_DSI_ERROR_MSK1_CRC_ERR      4
#define BM_MIPI_DSI_ERROR_MSK1_CRC_ERR      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_CRC_ERR(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_ERROR_MSK1_CRC_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_CRC_ERR(v)   (((v) << 4) & BM_MIPI_DSI_ERROR_MSK1_CRC_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CRC_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_CRC_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, CRC_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field PKT_SIZE_ERR (RW)
 *
 * Masks Packet size error
 */

#define BP_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR      5
#define BM_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR(v)   (((v) << 5) & BM_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PKT_SIZE_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_PKT_SIZE_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, PKT_SIZE_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field EOPT_ERR (RW)
 *
 * Masks EOTp Packet not received error
 */

#define BP_MIPI_DSI_ERROR_MSK1_EOPT_ERR      6
#define BM_MIPI_DSI_ERROR_MSK1_EOPT_ERR      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_EOPT_ERR(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_ERROR_MSK1_EOPT_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_EOPT_ERR(v)   (((v) << 6) & BM_MIPI_DSI_ERROR_MSK1_EOPT_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the EOPT_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_EOPT_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, EOPT_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field DPI_PLD_WR_ERR (RW)
 *
 * Masks DPI pixel line payload FIFO full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR      7
#define BM_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR(v)   (((v) << 7) & BM_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPI_PLD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_DPI_PLD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, DPI_PLD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field GEN_CMD_WR_ERR (RW)
 *
 * Masks command FIFO of generic interface full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR      8
#define BM_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR(v)   (((v) << 8) & BM_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_CMD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_GEN_CMD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, GEN_CMD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field GEN_PLD_WR_ERR (RW)
 *
 * Masks payload data FIFO of generic interface full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR      9
#define BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR(v)   (((v) << 9) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_GEN_PLD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, GEN_PLD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field GEN_PLD_SEND_ERR (RW)
 *
 * Masks generic interface packet build FIFO empty error
 */

#define BP_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR      10
#define BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR(v)   (((v) << 10) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_SEND_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_GEN_PLD_SEND_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, GEN_PLD_SEND_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field GEN_PLD_RD_ERR (RW)
 *
 * Masks DCS read data payload FIFO empty error
 */

#define BP_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR      11
#define BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR(v)   (((v) << 11) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_RD_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_GEN_PLD_RD_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, GEN_PLD_RD_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field GEN_PLD_RECV_ERR (RW)
 *
 * Masks generic interface packet read back FIFO full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR      12
#define BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR(v)   (((v) << 12) & BM_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GEN_PLD_RECV_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_GEN_PLD_RECV_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, GEN_PLD_RECV_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field DBI_CMD_WR_ERR (RW)
 *
 * Masks DBI command FIFO full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR      13
#define BM_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR(v)   ((((reg32_t) v) << 13) & BM_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR(v)   (((v) << 13) & BM_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_CMD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_DBI_CMD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, DBI_CMD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field DBI_PLD_WR_ERR (RW)
 *
 * Masks write payload data DBI FIFO full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR      14
#define BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR(v)   ((((reg32_t) v) << 14) & BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR(v)   (((v) << 14) & BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_WR_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_DBI_PLD_WR_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, DBI_PLD_WR_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field DBI_PLD_RD_ERR (RW)
 *
 * Masks payload DBI FIFO empty error
 */

#define BP_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR      15
#define BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR(v)   ((((reg32_t) v) << 15) & BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR(v)   (((v) << 15) & BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_RD_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_DBI_PLD_RD_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, DBI_PLD_RD_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field DBI_PLD_RECV_ERR (RW)
 *
 * Masks DBI read back packet payload FIFO full error
 */

#define BP_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR      16
#define BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR(v)   (((v) << 16) & BM_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_PLD_RECV_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_DBI_PLD_RECV_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, DBI_PLD_RECV_ERR, v)
#endif

/* --- Register HW_MIPI_DSI_ERROR_MSK1, field DBI_ILLEGAL_COMM_ERR (RW)
 *
 * Masks error attempt to write an illegal command on DPI
 */

#define BP_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR      17
#define BM_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR(v)   ((((reg32_t) v) << 17) & BM_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR)
#else
#define BF_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR(v)   (((v) << 17) & BM_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBI_ILLEGAL_COMM_ERR field to a new value.
#define BW_MIPI_DSI_ERROR_MSK1_DBI_ILLEGAL_COMM_ERR(v)   BF_CS1(MIPI_DSI_ERROR_MSK1, DBI_ILLEGAL_COMM_ERR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_RSTZ - D-PHY reset control (RW)
 *
 * Size: 32 bits  Offset: 0x54  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_SHUTDOWNZ : 1; //!< D-PHY Shutdown disable when 1, used to place the complete D-PHY macro in power down
        unsigned PHY_RSTZ : 1; //!< D-PHY Reset disable when 1, used to place the digital section of D-PHY in reset state
        unsigned PHY_ENABLECLK : 1; //!< Enables D-PHY Clock Lane Module when 1
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_mipi_dsi_phy_rstz_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_RSTZ register
 */
#define HW_MIPI_DSI_PHY_RSTZ_ADDR      (REGS_MIPI_DSI_BASE + 0x54)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_RSTZ           (*(volatile hw_mipi_dsi_phy_rstz_t *) HW_MIPI_DSI_PHY_RSTZ_ADDR)
#define HW_MIPI_DSI_PHY_RSTZ_RD()      (HW_MIPI_DSI_PHY_RSTZ.U)
#define HW_MIPI_DSI_PHY_RSTZ_WR(v)     (HW_MIPI_DSI_PHY_RSTZ.U = (v))
#define HW_MIPI_DSI_PHY_RSTZ_SET(v)    (HW_MIPI_DSI_PHY_RSTZ_WR(HW_MIPI_DSI_PHY_RSTZ_RD() |  (v)))
#define HW_MIPI_DSI_PHY_RSTZ_CLR(v)    (HW_MIPI_DSI_PHY_RSTZ_WR(HW_MIPI_DSI_PHY_RSTZ_RD() & ~(v)))
#define HW_MIPI_DSI_PHY_RSTZ_TOG(v)    (HW_MIPI_DSI_PHY_RSTZ_WR(HW_MIPI_DSI_PHY_RSTZ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_RSTZ bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_RSTZ, field PHY_SHUTDOWNZ (RW)
 *
 * D-PHY Shutdown disable when 1, used to place the complete D-PHY macro in power down
 */

#define BP_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ      0
#define BM_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ)
#else
#define BF_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ(v)   (((v) << 0) & BM_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_SHUTDOWNZ field to a new value.
#define BW_MIPI_DSI_PHY_RSTZ_PHY_SHUTDOWNZ(v)   BF_CS1(MIPI_DSI_PHY_RSTZ, PHY_SHUTDOWNZ, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_RSTZ, field PHY_RSTZ (RW)
 *
 * D-PHY Reset disable when 1, used to place the digital section of D-PHY in reset state
 */

#define BP_MIPI_DSI_PHY_RSTZ_PHY_RSTZ      1
#define BM_MIPI_DSI_PHY_RSTZ_PHY_RSTZ      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_RSTZ_PHY_RSTZ(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_PHY_RSTZ_PHY_RSTZ)
#else
#define BF_MIPI_DSI_PHY_RSTZ_PHY_RSTZ(v)   (((v) << 1) & BM_MIPI_DSI_PHY_RSTZ_PHY_RSTZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_RSTZ field to a new value.
#define BW_MIPI_DSI_PHY_RSTZ_PHY_RSTZ(v)   BF_CS1(MIPI_DSI_PHY_RSTZ, PHY_RSTZ, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_RSTZ, field PHY_ENABLECLK (RW)
 *
 * Enables D-PHY Clock Lane Module when 1
 */

#define BP_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK      2
#define BM_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK)
#else
#define BF_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK(v)   (((v) << 2) & BM_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_ENABLECLK field to a new value.
#define BW_MIPI_DSI_PHY_RSTZ_PHY_ENABLECLK(v)   BF_CS1(MIPI_DSI_PHY_RSTZ, PHY_ENABLECLK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_IF_CFG_ - D-PHY interface configuration (RW)
 *
 * Size: 32 bits  Offset: 0x58  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned N_LANES : 2; //!< Number of active data lanes.
        unsigned PHY_STOP_WAIT_TIME : 8; //!< Configures minimum wait period to request an HS transmission after the stop state accounted in clock lane cycles
        unsigned RESERVED0 : 22; //!< Reserved
    } B;
} hw_mipi_dsi_phy_if_cfg__t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_IF_CFG_ register
 */
#define HW_MIPI_DSI_PHY_IF_CFG__ADDR      (REGS_MIPI_DSI_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_IF_CFG_           (*(volatile hw_mipi_dsi_phy_if_cfg__t *) HW_MIPI_DSI_PHY_IF_CFG__ADDR)
#define HW_MIPI_DSI_PHY_IF_CFG__RD()      (HW_MIPI_DSI_PHY_IF_CFG_.U)
#define HW_MIPI_DSI_PHY_IF_CFG__WR(v)     (HW_MIPI_DSI_PHY_IF_CFG_.U = (v))
#define HW_MIPI_DSI_PHY_IF_CFG__SET(v)    (HW_MIPI_DSI_PHY_IF_CFG__WR(HW_MIPI_DSI_PHY_IF_CFG__RD() |  (v)))
#define HW_MIPI_DSI_PHY_IF_CFG__CLR(v)    (HW_MIPI_DSI_PHY_IF_CFG__WR(HW_MIPI_DSI_PHY_IF_CFG__RD() & ~(v)))
#define HW_MIPI_DSI_PHY_IF_CFG__TOG(v)    (HW_MIPI_DSI_PHY_IF_CFG__WR(HW_MIPI_DSI_PHY_IF_CFG__RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_IF_CFG_ bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_IF_CFG_, field N_LANES (RW)
 *
 * Number of active data lanes.
 *
 * Values:
 * 00 - 1 Data Lane (Lane 0)
 * 01 - 2 Data Lanes (Lane 0, and 1)
 * 10 - 3 Data Lanes (Lane 0,1 and 2)
 * 11 - 4 Data Lanes (All)
 */

#define BP_MIPI_DSI_PHY_IF_CFG__N_LANES      0
#define BM_MIPI_DSI_PHY_IF_CFG__N_LANES      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CFG__N_LANES(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_IF_CFG__N_LANES)
#else
#define BF_MIPI_DSI_PHY_IF_CFG__N_LANES(v)   (((v) << 0) & BM_MIPI_DSI_PHY_IF_CFG__N_LANES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the N_LANES field to a new value.
#define BW_MIPI_DSI_PHY_IF_CFG__N_LANES(v)   BF_CS1(MIPI_DSI_PHY_IF_CFG_, N_LANES, v)
#endif


/* --- Register HW_MIPI_DSI_PHY_IF_CFG_, field PHY_STOP_WAIT_TIME (RW)
 *
 * Configures minimum wait period to request an HS transmission after the stop state accounted in
 * clock lane cycles
 */

#define BP_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME      2
#define BM_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME      0x000003fc

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME)
#else
#define BF_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME(v)   (((v) << 2) & BM_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_STOP_WAIT_TIME field to a new value.
#define BW_MIPI_DSI_PHY_IF_CFG__PHY_STOP_WAIT_TIME(v)   BF_CS1(MIPI_DSI_PHY_IF_CFG_, PHY_STOP_WAIT_TIME, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_IF_CTRL - D-PHY PPI interface control (RW)
 *
 * Size: 32 bits  Offset: 0x5c  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_TXREQUESTCLKHS : 1; //!< Controls D-PHY PPI txrequestclkHS
        unsigned PHY_TXREQULPSCLK : 1; //!< ULPS mode Request on Clock Lane
        unsigned PHY_TXEXITULPSCLK : 1; //!< ULPS mode Exit on Clock Lane
        unsigned PHY_TXREQULPSLAN : 1; //!< ULPS mode Request on all active data lanes
        unsigned PHY_TXEXITULPSLAN : 1; //!< ULPS mode Exit on on all active data lanes
        unsigned PHY_TX_TRIGGERS : 4; //!< Controls the trigger transmissions
        unsigned RESERVED0 : 23; //!< Reserved
    } B;
} hw_mipi_dsi_phy_if_ctrl_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_IF_CTRL register
 */
#define HW_MIPI_DSI_PHY_IF_CTRL_ADDR      (REGS_MIPI_DSI_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_IF_CTRL           (*(volatile hw_mipi_dsi_phy_if_ctrl_t *) HW_MIPI_DSI_PHY_IF_CTRL_ADDR)
#define HW_MIPI_DSI_PHY_IF_CTRL_RD()      (HW_MIPI_DSI_PHY_IF_CTRL.U)
#define HW_MIPI_DSI_PHY_IF_CTRL_WR(v)     (HW_MIPI_DSI_PHY_IF_CTRL.U = (v))
#define HW_MIPI_DSI_PHY_IF_CTRL_SET(v)    (HW_MIPI_DSI_PHY_IF_CTRL_WR(HW_MIPI_DSI_PHY_IF_CTRL_RD() |  (v)))
#define HW_MIPI_DSI_PHY_IF_CTRL_CLR(v)    (HW_MIPI_DSI_PHY_IF_CTRL_WR(HW_MIPI_DSI_PHY_IF_CTRL_RD() & ~(v)))
#define HW_MIPI_DSI_PHY_IF_CTRL_TOG(v)    (HW_MIPI_DSI_PHY_IF_CTRL_WR(HW_MIPI_DSI_PHY_IF_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_IF_CTRL bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_IF_CTRL, field PHY_TXREQUESTCLKHS (RW)
 *
 * Controls D-PHY PPI txrequestclkHS
 */

#define BP_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS      0
#define BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS)
#else
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS(v)   (((v) << 0) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TXREQUESTCLKHS field to a new value.
#define BW_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQUESTCLKHS(v)   BF_CS1(MIPI_DSI_PHY_IF_CTRL, PHY_TXREQUESTCLKHS, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_IF_CTRL, field PHY_TXREQULPSCLK (RW)
 *
 * ULPS mode Request on Clock Lane
 */

#define BP_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK      1
#define BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK)
#else
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK(v)   (((v) << 1) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TXREQULPSCLK field to a new value.
#define BW_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSCLK(v)   BF_CS1(MIPI_DSI_PHY_IF_CTRL, PHY_TXREQULPSCLK, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_IF_CTRL, field PHY_TXEXITULPSCLK (RW)
 *
 * ULPS mode Exit on Clock Lane
 */

#define BP_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK      2
#define BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK)
#else
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK(v)   (((v) << 2) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TXEXITULPSCLK field to a new value.
#define BW_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSCLK(v)   BF_CS1(MIPI_DSI_PHY_IF_CTRL, PHY_TXEXITULPSCLK, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_IF_CTRL, field PHY_TXREQULPSLAN (RW)
 *
 * ULPS mode Request on all active data lanes
 */

#define BP_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN      3
#define BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN)
#else
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN(v)   (((v) << 3) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TXREQULPSLAN field to a new value.
#define BW_MIPI_DSI_PHY_IF_CTRL_PHY_TXREQULPSLAN(v)   BF_CS1(MIPI_DSI_PHY_IF_CTRL, PHY_TXREQULPSLAN, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_IF_CTRL, field PHY_TXEXITULPSLAN (RW)
 *
 * ULPS mode Exit on on all active data lanes
 */

#define BP_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN      4
#define BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN)
#else
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN(v)   (((v) << 4) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TXEXITULPSLAN field to a new value.
#define BW_MIPI_DSI_PHY_IF_CTRL_PHY_TXEXITULPSLAN(v)   BF_CS1(MIPI_DSI_PHY_IF_CTRL, PHY_TXEXITULPSLAN, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_IF_CTRL, field PHY_TX_TRIGGERS (RW)
 *
 * Controls the trigger transmissions
 */

#define BP_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS      5
#define BM_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS      0x000001e0

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS)
#else
#define BF_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS(v)   (((v) << 5) & BM_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TX_TRIGGERS field to a new value.
#define BW_MIPI_DSI_PHY_IF_CTRL_PHY_TX_TRIGGERS(v)   BF_CS1(MIPI_DSI_PHY_IF_CTRL, PHY_TX_TRIGGERS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_STATUS - D-PHY PPI status interface (RW)
 *
 * Size: 32 bits  Offset: 0x60  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHYLOCK : 1; //!< Reports status of phylock D-PHY pin
        unsigned PHYDIRECTION : 1; //!< Reports status of phydirection D-PHY pin
        unsigned PHYSTOPSTATECLKLANE : 1; //!< Reports status of phystopstateclklane D-PHY pin
        unsigned PHYRXULPSCLKNOT : 1; //!< Reports status of phyrxulpsclknot D-PHY pin
        unsigned PHYSTOPSTATE0LANE : 1; //!< Reports status of phystopstate0lane D-PHY pin
        unsigned ULPSACTIVENOT0LANE : 1; //!< Reports status of ulpsactivenot0lane D-PHY pin
        unsigned RXULPSESC0LANE : 1; //!< Reports status of rxulpsEsc0lane D-PHY pin
        unsigned PHYSTOPSTATE1LANE : 1; //!< Reports status of phystopstate1lane D-PHY pin
        unsigned ULPSACTIVENOT1LANE : 1; //!< Reports status of ulpsactivenot1lane D-PHY pin
        unsigned PHYSTOPSTATE2LANE : 1; //!< Reports status of phystopstate2lane D-PHY pin
        unsigned ULPSACTIVENOT2LANE : 1; //!< Reports status of ulpsactivenot2lane D-PHY pin
        unsigned PHYSTOPSTATE3LANE : 1; //!< Reports status of phystopstate3lane D-PHY pin
        unsigned ULPSACTIVENOT3LANE : 1; //!< Reports status of ulpsactivenot3lane D-PHY pin
        unsigned RESERVED0 : 19; //!< Reserved
    } B;
} hw_mipi_dsi_phy_status_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_STATUS register
 */
#define HW_MIPI_DSI_PHY_STATUS_ADDR      (REGS_MIPI_DSI_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_STATUS           (*(volatile hw_mipi_dsi_phy_status_t *) HW_MIPI_DSI_PHY_STATUS_ADDR)
#define HW_MIPI_DSI_PHY_STATUS_RD()      (HW_MIPI_DSI_PHY_STATUS.U)
#define HW_MIPI_DSI_PHY_STATUS_WR(v)     (HW_MIPI_DSI_PHY_STATUS.U = (v))
#define HW_MIPI_DSI_PHY_STATUS_SET(v)    (HW_MIPI_DSI_PHY_STATUS_WR(HW_MIPI_DSI_PHY_STATUS_RD() |  (v)))
#define HW_MIPI_DSI_PHY_STATUS_CLR(v)    (HW_MIPI_DSI_PHY_STATUS_WR(HW_MIPI_DSI_PHY_STATUS_RD() & ~(v)))
#define HW_MIPI_DSI_PHY_STATUS_TOG(v)    (HW_MIPI_DSI_PHY_STATUS_WR(HW_MIPI_DSI_PHY_STATUS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_STATUS bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYLOCK (RW)
 *
 * Reports status of phylock D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYLOCK      0
#define BM_MIPI_DSI_PHY_STATUS_PHYLOCK      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYLOCK(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_STATUS_PHYLOCK)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYLOCK(v)   (((v) << 0) & BM_MIPI_DSI_PHY_STATUS_PHYLOCK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYLOCK field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYLOCK(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYLOCK, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYDIRECTION (RW)
 *
 * Reports status of phydirection D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYDIRECTION      1
#define BM_MIPI_DSI_PHY_STATUS_PHYDIRECTION      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYDIRECTION(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_PHY_STATUS_PHYDIRECTION)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYDIRECTION(v)   (((v) << 1) & BM_MIPI_DSI_PHY_STATUS_PHYDIRECTION)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYDIRECTION field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYDIRECTION(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYDIRECTION, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYSTOPSTATECLKLANE (RW)
 *
 * Reports status of phystopstateclklane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE      2
#define BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE(v)   ((((reg32_t) v) << 2) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE(v)   (((v) << 2) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYSTOPSTATECLKLANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYSTOPSTATECLKLANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYSTOPSTATECLKLANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYRXULPSCLKNOT (RW)
 *
 * Reports status of phyrxulpsclknot D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT      3
#define BM_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT(v)   ((((reg32_t) v) << 3) & BM_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT(v)   (((v) << 3) & BM_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYRXULPSCLKNOT field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYRXULPSCLKNOT(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYRXULPSCLKNOT, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYSTOPSTATE0LANE (RW)
 *
 * Reports status of phystopstate0lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE      4
#define BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE(v)   ((((reg32_t) v) << 4) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE(v)   (((v) << 4) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYSTOPSTATE0LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE0LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYSTOPSTATE0LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field ULPSACTIVENOT0LANE (RW)
 *
 * Reports status of ulpsactivenot0lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE      5
#define BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE(v)   ((((reg32_t) v) << 5) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE(v)   (((v) << 5) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPSACTIVENOT0LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT0LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, ULPSACTIVENOT0LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field RXULPSESC0LANE (RW)
 *
 * Reports status of rxulpsEsc0lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE      6
#define BM_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE(v)   ((((reg32_t) v) << 6) & BM_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE(v)   (((v) << 6) & BM_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RXULPSESC0LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_RXULPSESC0LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, RXULPSESC0LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYSTOPSTATE1LANE (RW)
 *
 * Reports status of phystopstate1lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE      7
#define BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE(v)   ((((reg32_t) v) << 7) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE(v)   (((v) << 7) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYSTOPSTATE1LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE1LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYSTOPSTATE1LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field ULPSACTIVENOT1LANE (RW)
 *
 * Reports status of ulpsactivenot1lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE      8
#define BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE(v)   (((v) << 8) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPSACTIVENOT1LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT1LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, ULPSACTIVENOT1LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYSTOPSTATE2LANE (RW)
 *
 * Reports status of phystopstate2lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE      9
#define BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE(v)   ((((reg32_t) v) << 9) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE(v)   (((v) << 9) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYSTOPSTATE2LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE2LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYSTOPSTATE2LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field ULPSACTIVENOT2LANE (RW)
 *
 * Reports status of ulpsactivenot2lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE      10
#define BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE(v)   ((((reg32_t) v) << 10) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE(v)   (((v) << 10) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPSACTIVENOT2LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT2LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, ULPSACTIVENOT2LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field PHYSTOPSTATE3LANE (RW)
 *
 * Reports status of phystopstate3lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE      11
#define BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE(v)   ((((reg32_t) v) << 11) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE(v)   (((v) << 11) & BM_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHYSTOPSTATE3LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_PHYSTOPSTATE3LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, PHYSTOPSTATE3LANE, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_STATUS, field ULPSACTIVENOT3LANE (RW)
 *
 * Reports status of ulpsactivenot3lane D-PHY pin
 */

#define BP_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE      12
#define BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE(v)   ((((reg32_t) v) << 12) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE)
#else
#define BF_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE(v)   (((v) << 12) & BM_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ULPSACTIVENOT3LANE field to a new value.
#define BW_MIPI_DSI_PHY_STATUS_ULPSACTIVENOT3LANE(v)   BF_CS1(MIPI_DSI_PHY_STATUS, ULPSACTIVENOT3LANE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_TST_CTRL0 - D-PHY Test interface control 0 (RW)
 *
 * Size: 32 bits  Offset: 0x64  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_TESTCLR : 1; //!< PHY test interface clear. When active performs vendor specific interface initialization (Active High)
        unsigned PHY_TESTCLK : 1; //!< PHY test interface strobe signal. Used to clock TESTDIN bus into the D-PHY. In conjunction with TESTEN signal controls the operation selection
        unsigned RESERVED0 : 30; //!< Reserved
    } B;
} hw_mipi_dsi_phy_tst_ctrl0_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_TST_CTRL0 register
 */
#define HW_MIPI_DSI_PHY_TST_CTRL0_ADDR      (REGS_MIPI_DSI_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_TST_CTRL0           (*(volatile hw_mipi_dsi_phy_tst_ctrl0_t *) HW_MIPI_DSI_PHY_TST_CTRL0_ADDR)
#define HW_MIPI_DSI_PHY_TST_CTRL0_RD()      (HW_MIPI_DSI_PHY_TST_CTRL0.U)
#define HW_MIPI_DSI_PHY_TST_CTRL0_WR(v)     (HW_MIPI_DSI_PHY_TST_CTRL0.U = (v))
#define HW_MIPI_DSI_PHY_TST_CTRL0_SET(v)    (HW_MIPI_DSI_PHY_TST_CTRL0_WR(HW_MIPI_DSI_PHY_TST_CTRL0_RD() |  (v)))
#define HW_MIPI_DSI_PHY_TST_CTRL0_CLR(v)    (HW_MIPI_DSI_PHY_TST_CTRL0_WR(HW_MIPI_DSI_PHY_TST_CTRL0_RD() & ~(v)))
#define HW_MIPI_DSI_PHY_TST_CTRL0_TOG(v)    (HW_MIPI_DSI_PHY_TST_CTRL0_WR(HW_MIPI_DSI_PHY_TST_CTRL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_TST_CTRL0 bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_TST_CTRL0, field PHY_TESTCLR (RW)
 *
 * PHY test interface clear. When active performs vendor specific interface initialization (Active
 * High)
 */

#define BP_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR      0
#define BM_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR)
#else
#define BF_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR(v)   (((v) << 0) & BM_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTCLR field to a new value.
#define BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLR(v)   BF_CS1(MIPI_DSI_PHY_TST_CTRL0, PHY_TESTCLR, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_TST_CTRL0, field PHY_TESTCLK (RW)
 *
 * PHY test interface strobe signal. Used to clock TESTDIN bus into the D-PHY. In conjunction with
 * TESTEN signal controls the operation selection
 */

#define BP_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK      1
#define BM_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(v)   ((((reg32_t) v) << 1) & BM_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK)
#else
#define BF_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(v)   (((v) << 1) & BM_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTCLK field to a new value.
#define BW_MIPI_DSI_PHY_TST_CTRL0_PHY_TESTCLK(v)   BF_CS1(MIPI_DSI_PHY_TST_CTRL0, PHY_TESTCLK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_DSI_PHY_TST_CTRL1 - D-PHY Test interface control 1 (RW)
 *
 * Size: 32 bits  Offset: 0x68  Memory Access: R/W
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_TESTDIN : 8; //!< PHY test interface input 8-bit data bus for internal register programming and test functionalities access
        unsigned PHY_TESTDOUT : 8; //!< PHY output 8-bit data bus for read-back and internal probing functionalities
        unsigned PHY_TESTEN : 1; //!< PHY test interface operation selector: when 1 configures address write operation on the falling edge of TESTCLK; when 0 configures a data write operation on the rising edge of TESTCLK
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_mipi_dsi_phy_tst_ctrl1_t;
#endif

/*
 * constants & macros for entire MIPI_DSI_PHY_TST_CTRL1 register
 */
#define HW_MIPI_DSI_PHY_TST_CTRL1_ADDR      (REGS_MIPI_DSI_BASE + 0x68)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_DSI_PHY_TST_CTRL1           (*(volatile hw_mipi_dsi_phy_tst_ctrl1_t *) HW_MIPI_DSI_PHY_TST_CTRL1_ADDR)
#define HW_MIPI_DSI_PHY_TST_CTRL1_RD()      (HW_MIPI_DSI_PHY_TST_CTRL1.U)
#define HW_MIPI_DSI_PHY_TST_CTRL1_WR(v)     (HW_MIPI_DSI_PHY_TST_CTRL1.U = (v))
#define HW_MIPI_DSI_PHY_TST_CTRL1_SET(v)    (HW_MIPI_DSI_PHY_TST_CTRL1_WR(HW_MIPI_DSI_PHY_TST_CTRL1_RD() |  (v)))
#define HW_MIPI_DSI_PHY_TST_CTRL1_CLR(v)    (HW_MIPI_DSI_PHY_TST_CTRL1_WR(HW_MIPI_DSI_PHY_TST_CTRL1_RD() & ~(v)))
#define HW_MIPI_DSI_PHY_TST_CTRL1_TOG(v)    (HW_MIPI_DSI_PHY_TST_CTRL1_WR(HW_MIPI_DSI_PHY_TST_CTRL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_DSI_PHY_TST_CTRL1 bitfields
 */

/* --- Register HW_MIPI_DSI_PHY_TST_CTRL1, field PHY_TESTDIN (RW)
 *
 * PHY test interface input 8-bit data bus for internal register programming and test
 * functionalities access
 */

#define BP_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN      0
#define BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN(v)   ((((reg32_t) v) << 0) & BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN)
#else
#define BF_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN(v)   (((v) << 0) & BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTDIN field to a new value.
#define BW_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDIN(v)   BF_CS1(MIPI_DSI_PHY_TST_CTRL1, PHY_TESTDIN, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_TST_CTRL1, field PHY_TESTDOUT (RW)
 *
 * PHY output 8-bit data bus for read-back and internal probing functionalities
 */

#define BP_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT      8
#define BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT(v)   ((((reg32_t) v) << 8) & BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT)
#else
#define BF_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT(v)   (((v) << 8) & BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTDOUT field to a new value.
#define BW_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTDOUT(v)   BF_CS1(MIPI_DSI_PHY_TST_CTRL1, PHY_TESTDOUT, v)
#endif

/* --- Register HW_MIPI_DSI_PHY_TST_CTRL1, field PHY_TESTEN (RW)
 *
 * PHY test interface operation selector: when 1 configures address write operation on the falling
 * edge of TESTCLK; when 0 configures a data write operation on the rising edge of TESTCLK
 */

#define BP_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN      16
#define BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN(v)   ((((reg32_t) v) << 16) & BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN)
#else
#define BF_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN(v)   (((v) << 16) & BM_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTEN field to a new value.
#define BW_MIPI_DSI_PHY_TST_CTRL1_PHY_TESTEN(v)   BF_CS1(MIPI_DSI_PHY_TST_CTRL1, PHY_TESTEN, v)
#endif


/*!
 * @brief All MIPI_DSI module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_mipi_dsi_version_t VERSION; //!< Version of the DSI host ctrl
    volatile hw_mipi_dsi_pwr_up_t PWR_UP; //!< Core power up
    volatile hw_mipi_dsi_clkmgr_cfg_t CLKMGR_CFG; //!< Number of active data lanes
    volatile hw_mipi_dsi_dpi_cfg_t DPI_CFG; //!< DPI interface configuration
    volatile hw_mipi_dsi_dbi_cfg_t DBI_CFG; //!< DBI interface configuration
    volatile hw_mipi_dsi_dbis_cmdsize_t DBIS_CMDSIZE; //!< DBI command size configuration
    volatile hw_mipi_dsi_pckhdl_cfg_t PCKHDL_CFG; //!< Packet handler configuration
    volatile hw_mipi_dsi_vid_mode_cfg_t VID_MODE_CFG; //!< Video Mode Configuration
    volatile hw_mipi_dsi_vid_pkt_cfg_t VID_PKT_CFG; //!< Video packet configuration
    volatile hw_mipi_dsi_cmd_mode_cfg_t CMD_MODE_CFG; //!< Command mode configuration
    volatile hw_mipi_dsi_tmr_line_cfg_t TMR_LINE_CFG; //!< Line timer configuration
    volatile hw_mipi_dsi_vtiming_cfg_t VTIMING_CFG; //!< Vertical timing configuration
    volatile hw_mipi_dsi_phy_tmr_cfg_t PHY_TMR_CFG; //!< D-PHY timing configuration
    volatile hw_mipi_dsi_gen_hdr_t GEN_HDR; //!< Generic packet Header configuration
    volatile hw_mipi_dsi_gen_pld_data_t GEN_PLD_DATA; //!< Generic payload data in/out
    volatile hw_mipi_dsi_cmd_pkt_status_t CMD_PKT_STATUS; //!< Command packet status
    volatile hw_mipi_dsi_to_cnt_cfg0_t TO_CNT_CFG0; //!< Time Out timers configuration
    volatile hw_mipi_dsi_error_st0_t ERROR_ST0; //!< Interrupt status register 0
    volatile hw_mipi_dsi_error_st1_t ERROR_ST1; //!< Interrupt status register 1
    volatile hw_mipi_dsi_error_msk0_t ERROR_MSK0; //!< Masks Interrupt generation trigged by ERROR_ST0 register
    volatile hw_mipi_dsi_error_msk1_t ERROR_MSK1; //!< Masks Interrupt generation trigged by ERROR_ST1 register
    volatile hw_mipi_dsi_phy_rstz_t PHY_RSTZ; //!< D-PHY reset control
    volatile hw_mipi_dsi_phy_if_cfg__t PHY_IF_CFG_; //!< D-PHY interface configuration
    volatile hw_mipi_dsi_phy_if_ctrl_t PHY_IF_CTRL; //!< D-PHY PPI interface control
    volatile hw_mipi_dsi_phy_status_t PHY_STATUS; //!< D-PHY PPI status interface
    volatile hw_mipi_dsi_phy_tst_ctrl0_t PHY_TST_CTRL0; //!< D-PHY Test interface control 0
    volatile hw_mipi_dsi_phy_tst_ctrl1_t PHY_TST_CTRL1; //!< D-PHY Test interface control 1
} hw_mipi_dsi_t
#endif

//! @brief Macro to access all MIPI_DSI registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MIPI_DSI(0)</code>.
#define HW_MIPI_DSI     (*(volatile hw_mipi_dsi_t *) REGS_MIPI_DSI_BASE)


#endif // _MIPI_DSI_H
