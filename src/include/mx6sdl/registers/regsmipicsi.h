/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MIPI_CSI_H
#define _MIPI_CSI_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_MIPI_CSI_VERSION - Controller Version Identification Register
 * - HW_MIPI_CSI_N_LANES - Number of Active Data Lanes
 * - HW_MIPI_CSI_PHY_SHUTDOWNZ - Phy shutdown control
 * - HW_MIPI_CSI_DPHY_RSTZ - Phy reset control
 * - HW_MIPI_CSI_CSI2_RESETN - CSI2 controller reset
 * - HW_MIPI_CSI_PHY_STATE - General settings for all blocks
 * - HW_MIPI_CSI_DATA_IDS_1 - Data IDs for which IDI reports line boundary matching errors
 * - HW_MIPI_CSI_ERR1 - Error state register 1
 * - HW_MIPI_CSI_ERR2 - Error state register 2
 * - HW_MIPI_CSI_MASK2 - Masks for errors 2
 * - HW_MIPI_CSI_PHY_TST_CRTL0 - D-PHY Test interface control 0
 * - HW_MIPI_CSI_PHY_TST_CTRL1 - D-PHY Test interface control 1
 *
 * hw_mipi_csi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_MIPI_CSI_BASE
#define REGS_MIPI_CSI_BASE (0x020dc000) //!< Base address for MIPI_CSI.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_VERSION - Controller Version Identification Register (RO)
 *
 * Name: Controller Version Identification Register  Address Offset: 0x000  Size: 32 bits  Default
 * Value: CSI_VERSION_ID  Access: Read
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned VERSION : 32; //!< Version of the CSI-2 Host Controller Default Value: CSI_VERSION_ID
    } B;
} hw_mipi_csi_version_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_VERSION register
 */
#define HW_MIPI_CSI_VERSION_ADDR      (REGS_MIPI_CSI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_VERSION           (*(volatile hw_mipi_csi_version_t *) HW_MIPI_CSI_VERSION_ADDR)
#define HW_MIPI_CSI_VERSION_RD()      (HW_MIPI_CSI_VERSION.U)
#endif

/*
 * constants & macros for individual MIPI_CSI_VERSION bitfields
 */

/* --- Register HW_MIPI_CSI_VERSION, field VERSION[31:0] (RO)
 *
 * Version of the CSI-2 Host Controller Default Value: CSI_VERSION_ID
 */

#define BP_MIPI_CSI_VERSION_VERSION      (0)
#define BM_MIPI_CSI_VERSION_VERSION      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_N_LANES - Number of Active Data Lanes (RW)
 *
 * Name: Number of Active Data Lanes  Address Offset: 0x004  Size: 2 bits  Size: 1 bits  Default
 * Value: CSI_N_LANES  Access: Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned N_LANES : 1; //!< Number of Active Data Lanes Can only be updated when the PHY lane is in stop state. Default Value: CSI_N_LANES
        unsigned RESERVED0 : 1; //!< 
        unsigned RESERVED1 : 30; //!< Reserved
    } B;
} hw_mipi_csi_n_lanes_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_N_LANES register
 */
#define HW_MIPI_CSI_N_LANES_ADDR      (REGS_MIPI_CSI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_N_LANES           (*(volatile hw_mipi_csi_n_lanes_t *) HW_MIPI_CSI_N_LANES_ADDR)
#define HW_MIPI_CSI_N_LANES_RD()      (HW_MIPI_CSI_N_LANES.U)
#define HW_MIPI_CSI_N_LANES_WR(v)     (HW_MIPI_CSI_N_LANES.U = (v))
#define HW_MIPI_CSI_N_LANES_SET(v)    (HW_MIPI_CSI_N_LANES_WR(HW_MIPI_CSI_N_LANES_RD() |  (v)))
#define HW_MIPI_CSI_N_LANES_CLR(v)    (HW_MIPI_CSI_N_LANES_WR(HW_MIPI_CSI_N_LANES_RD() & ~(v)))
#define HW_MIPI_CSI_N_LANES_TOG(v)    (HW_MIPI_CSI_N_LANES_WR(HW_MIPI_CSI_N_LANES_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_N_LANES bitfields
 */

/* --- Register HW_MIPI_CSI_N_LANES, field N_LANES[0:0] (RW)
 *
 * Number of Active Data Lanes Can only be updated when the PHY lane is in stop state. Default
 * Value: CSI_N_LANES
 *
 * Values:
 * 0 - 1 Data Lane (Lane 0)
 * 1 - 2 Data Lanes (Lane 0, and 1)
 */

#define BP_MIPI_CSI_N_LANES_N_LANES      (0)
#define BM_MIPI_CSI_N_LANES_N_LANES      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_N_LANES_N_LANES(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_N_LANES_N_LANES)
#else
#define BF_MIPI_CSI_N_LANES_N_LANES(v)   (((v) << 0) & BM_MIPI_CSI_N_LANES_N_LANES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the N_LANES field to a new value.
#define BW_MIPI_CSI_N_LANES_N_LANES(v)   BF_CS1(MIPI_CSI_N_LANES, N_LANES, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_PHY_SHUTDOWNZ - Phy shutdown control (RW)
 *
 * Name: Phy shutdown control  Address Offset: 0x008  Size: 1 bit  Default Value: 0  Access:
 * Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_SHUTDOWNZ : 1; //!< Shutdown input. This line is used to place the complete macro in power down. All analog blocks are in power down mode and digital logic is cleared. Active Low Default Value: 0
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_mipi_csi_phy_shutdownz_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_PHY_SHUTDOWNZ register
 */
#define HW_MIPI_CSI_PHY_SHUTDOWNZ_ADDR      (REGS_MIPI_CSI_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_PHY_SHUTDOWNZ           (*(volatile hw_mipi_csi_phy_shutdownz_t *) HW_MIPI_CSI_PHY_SHUTDOWNZ_ADDR)
#define HW_MIPI_CSI_PHY_SHUTDOWNZ_RD()      (HW_MIPI_CSI_PHY_SHUTDOWNZ.U)
#define HW_MIPI_CSI_PHY_SHUTDOWNZ_WR(v)     (HW_MIPI_CSI_PHY_SHUTDOWNZ.U = (v))
#define HW_MIPI_CSI_PHY_SHUTDOWNZ_SET(v)    (HW_MIPI_CSI_PHY_SHUTDOWNZ_WR(HW_MIPI_CSI_PHY_SHUTDOWNZ_RD() |  (v)))
#define HW_MIPI_CSI_PHY_SHUTDOWNZ_CLR(v)    (HW_MIPI_CSI_PHY_SHUTDOWNZ_WR(HW_MIPI_CSI_PHY_SHUTDOWNZ_RD() & ~(v)))
#define HW_MIPI_CSI_PHY_SHUTDOWNZ_TOG(v)    (HW_MIPI_CSI_PHY_SHUTDOWNZ_WR(HW_MIPI_CSI_PHY_SHUTDOWNZ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_PHY_SHUTDOWNZ bitfields
 */

/* --- Register HW_MIPI_CSI_PHY_SHUTDOWNZ, field PHY_SHUTDOWNZ[0:0] (RW)
 *
 * Shutdown input. This line is used to place the complete macro in power down. All analog blocks
 * are in power down mode and digital logic is cleared. Active Low Default Value: 0
 */

#define BP_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ      (0)
#define BM_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ)
#else
#define BF_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ(v)   (((v) << 0) & BM_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_SHUTDOWNZ field to a new value.
#define BW_MIPI_CSI_PHY_SHUTDOWNZ_PHY_SHUTDOWNZ(v)   BF_CS1(MIPI_CSI_PHY_SHUTDOWNZ, PHY_SHUTDOWNZ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_DPHY_RSTZ - Phy reset control (RW)
 *
 * Name: Phy reset control  Address Offset: 0x00C  Size: 1 bit  Default Value: 0  Access: Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DPHY_RSTZ : 1; //!< DPHY reset output. Active Low Default Value: 0
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_mipi_csi_dphy_rstz_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_DPHY_RSTZ register
 */
#define HW_MIPI_CSI_DPHY_RSTZ_ADDR      (REGS_MIPI_CSI_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_DPHY_RSTZ           (*(volatile hw_mipi_csi_dphy_rstz_t *) HW_MIPI_CSI_DPHY_RSTZ_ADDR)
#define HW_MIPI_CSI_DPHY_RSTZ_RD()      (HW_MIPI_CSI_DPHY_RSTZ.U)
#define HW_MIPI_CSI_DPHY_RSTZ_WR(v)     (HW_MIPI_CSI_DPHY_RSTZ.U = (v))
#define HW_MIPI_CSI_DPHY_RSTZ_SET(v)    (HW_MIPI_CSI_DPHY_RSTZ_WR(HW_MIPI_CSI_DPHY_RSTZ_RD() |  (v)))
#define HW_MIPI_CSI_DPHY_RSTZ_CLR(v)    (HW_MIPI_CSI_DPHY_RSTZ_WR(HW_MIPI_CSI_DPHY_RSTZ_RD() & ~(v)))
#define HW_MIPI_CSI_DPHY_RSTZ_TOG(v)    (HW_MIPI_CSI_DPHY_RSTZ_WR(HW_MIPI_CSI_DPHY_RSTZ_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_DPHY_RSTZ bitfields
 */

/* --- Register HW_MIPI_CSI_DPHY_RSTZ, field DPHY_RSTZ[0:0] (RW)
 *
 * DPHY reset output. Active Low Default Value: 0
 */

#define BP_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ      (0)
#define BM_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ)
#else
#define BF_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ(v)   (((v) << 0) & BM_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DPHY_RSTZ field to a new value.
#define BW_MIPI_CSI_DPHY_RSTZ_DPHY_RSTZ(v)   BF_CS1(MIPI_CSI_DPHY_RSTZ, DPHY_RSTZ, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_CSI2_RESETN - CSI2 controller reset (RW)
 *
 * Name: CSI2 controller reset  Address Offset: 0x010  Size: 1 bit  Default Value: 0  Access:
 * Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CSI2_RESETN : 1; //!< CSI-2 controller reset output. Active Low Default Value: 0
        unsigned RESERVED0 : 31; //!< Reserved
    } B;
} hw_mipi_csi_csi2_resetn_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_CSI2_RESETN register
 */
#define HW_MIPI_CSI_CSI2_RESETN_ADDR      (REGS_MIPI_CSI_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_CSI2_RESETN           (*(volatile hw_mipi_csi_csi2_resetn_t *) HW_MIPI_CSI_CSI2_RESETN_ADDR)
#define HW_MIPI_CSI_CSI2_RESETN_RD()      (HW_MIPI_CSI_CSI2_RESETN.U)
#define HW_MIPI_CSI_CSI2_RESETN_WR(v)     (HW_MIPI_CSI_CSI2_RESETN.U = (v))
#define HW_MIPI_CSI_CSI2_RESETN_SET(v)    (HW_MIPI_CSI_CSI2_RESETN_WR(HW_MIPI_CSI_CSI2_RESETN_RD() |  (v)))
#define HW_MIPI_CSI_CSI2_RESETN_CLR(v)    (HW_MIPI_CSI_CSI2_RESETN_WR(HW_MIPI_CSI_CSI2_RESETN_RD() & ~(v)))
#define HW_MIPI_CSI_CSI2_RESETN_TOG(v)    (HW_MIPI_CSI_CSI2_RESETN_WR(HW_MIPI_CSI_CSI2_RESETN_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_CSI2_RESETN bitfields
 */

/* --- Register HW_MIPI_CSI_CSI2_RESETN, field CSI2_RESETN[0:0] (RW)
 *
 * CSI-2 controller reset output. Active Low Default Value: 0
 */

#define BP_MIPI_CSI_CSI2_RESETN_CSI2_RESETN      (0)
#define BM_MIPI_CSI_CSI2_RESETN_CSI2_RESETN      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_CSI2_RESETN_CSI2_RESETN(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_CSI2_RESETN_CSI2_RESETN)
#else
#define BF_MIPI_CSI_CSI2_RESETN_CSI2_RESETN(v)   (((v) << 0) & BM_MIPI_CSI_CSI2_RESETN_CSI2_RESETN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CSI2_RESETN field to a new value.
#define BW_MIPI_CSI_CSI2_RESETN_CSI2_RESETN(v)   BF_CS1(MIPI_CSI_CSI2_RESETN, CSI2_RESETN, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_PHY_STATE - General settings for all blocks (RO)
 *
 * Name: General settings for all blocks  Address Offset: 0x014  Size: 12 bit  Size: 8 bit  Default
 * Value: 0  Access: Read (with exception of bit 11 which is Read/Write)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_RXULPSESC_0 : 1; //!< Lane module 0 has entered the Ultra Low Power mode Default Value: 0
        unsigned PHY_RXULPSESC_1 : 1; //!< Lane module 1 has entered the Ultra Low Power mode Default Value: 0
        unsigned RESERVED0 : 2; //!< 
        unsigned PHY_STOPSTATEDATA_0 : 1; //!< Data Lane 0 in Stop state Default Value: 0
        unsigned PHY_STOPSTATEDATA_1 : 1; //!< Data Lane 1 in Stop state Default Value: 0
        unsigned RESERVED1 : 2; //!< 
        unsigned PHY_RXCLKACTIVEHS : 1; //!< Indicates that the clock lane is actively receiving a DDR clock Default Value: 0
        unsigned PHY_RXULPSCLKNOT : 1; //!< Active Low. This signal indicates that the Clock Lane module has entered the Ultra Low Power state Default Value: 0
        unsigned PHY_STOPSTATECLK : 1; //!< Clock Lane in Stop state Default Value: 0
        unsigned BYPASS_2ECC_TST : 1; //!< Payload Bypass test mode for double ECC errors Default Value: 0
        unsigned RESERVED2 : 20; //!< Reserved
    } B;
} hw_mipi_csi_phy_state_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_PHY_STATE register
 */
#define HW_MIPI_CSI_PHY_STATE_ADDR      (REGS_MIPI_CSI_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_PHY_STATE           (*(volatile hw_mipi_csi_phy_state_t *) HW_MIPI_CSI_PHY_STATE_ADDR)
#define HW_MIPI_CSI_PHY_STATE_RD()      (HW_MIPI_CSI_PHY_STATE.U)
#endif

/*
 * constants & macros for individual MIPI_CSI_PHY_STATE bitfields
 */

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_RXULPSESC_0[0:0] (RO)
 *
 * Lane module 0 has entered the Ultra Low Power mode Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_RXULPSESC_0      (0)
#define BM_MIPI_CSI_PHY_STATE_PHY_RXULPSESC_0      (0x00000001)

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_RXULPSESC_1[1:1] (RO)
 *
 * Lane module 1 has entered the Ultra Low Power mode Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_RXULPSESC_1      (1)
#define BM_MIPI_CSI_PHY_STATE_PHY_RXULPSESC_1      (0x00000002)

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_STOPSTATEDATA_0[4:4] (RO)
 *
 * Data Lane 0 in Stop state Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_STOPSTATEDATA_0      (4)
#define BM_MIPI_CSI_PHY_STATE_PHY_STOPSTATEDATA_0      (0x00000010)

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_STOPSTATEDATA_1[5:5] (RO)
 *
 * Data Lane 1 in Stop state Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_STOPSTATEDATA_1      (5)
#define BM_MIPI_CSI_PHY_STATE_PHY_STOPSTATEDATA_1      (0x00000020)

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_RXCLKACTIVEHS[8:8] (RO)
 *
 * Indicates that the clock lane is actively receiving a DDR clock Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_RXCLKACTIVEHS      (8)
#define BM_MIPI_CSI_PHY_STATE_PHY_RXCLKACTIVEHS      (0x00000100)

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_RXULPSCLKNOT[9:9] (RO)
 *
 * Active Low. This signal indicates that the Clock Lane module has entered the Ultra Low Power
 * state Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_RXULPSCLKNOT      (9)
#define BM_MIPI_CSI_PHY_STATE_PHY_RXULPSCLKNOT      (0x00000200)

/* --- Register HW_MIPI_CSI_PHY_STATE, field PHY_STOPSTATECLK[10:10] (RO)
 *
 * Clock Lane in Stop state Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_PHY_STOPSTATECLK      (10)
#define BM_MIPI_CSI_PHY_STATE_PHY_STOPSTATECLK      (0x00000400)

/* --- Register HW_MIPI_CSI_PHY_STATE, field BYPASS_2ECC_TST[11:11] (RW)
 *
 * Payload Bypass test mode for double ECC errors Default Value: 0
 */

#define BP_MIPI_CSI_PHY_STATE_BYPASS_2ECC_TST      (11)
#define BM_MIPI_CSI_PHY_STATE_BYPASS_2ECC_TST      (0x00000800)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_DATA_IDS_1 - Data IDs for which IDI reports line boundary matching errors (RW)
 *
 * Name: Data IDs for which IDI reports line boundary matching errors  Address Offset: 0x018  Size:
 * 32 bit  Default Value: 0  Access: Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DI0_DT : 6; //!< Data ID 0 Data Type Default Value: 0
        unsigned DI0_VC : 2; //!< Data ID 0 Virtual channel Default Value: 0
        unsigned DI1_DT : 6; //!< Data ID 1 Data Type Default Value: 0
        unsigned DI1_VC : 2; //!< Data ID 1 Virtual channel Default Value: 0
        unsigned DI2_DT : 6; //!< DATA ID 2 Data Type Default Value: 0
        unsigned DI2_VC : 2; //!< DATA ID 2 Virtual channel Default Value: 0
        unsigned DI3_DT : 6; //!< Data ID 3 Data Type Default Value: 0
        unsigned DI3_VC : 2; //!< Data ID 3 Virtual channel Default Value: 0
    } B;
} hw_mipi_csi_data_ids_1_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_DATA_IDS_1 register
 */
#define HW_MIPI_CSI_DATA_IDS_1_ADDR      (REGS_MIPI_CSI_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_DATA_IDS_1           (*(volatile hw_mipi_csi_data_ids_1_t *) HW_MIPI_CSI_DATA_IDS_1_ADDR)
#define HW_MIPI_CSI_DATA_IDS_1_RD()      (HW_MIPI_CSI_DATA_IDS_1.U)
#define HW_MIPI_CSI_DATA_IDS_1_WR(v)     (HW_MIPI_CSI_DATA_IDS_1.U = (v))
#define HW_MIPI_CSI_DATA_IDS_1_SET(v)    (HW_MIPI_CSI_DATA_IDS_1_WR(HW_MIPI_CSI_DATA_IDS_1_RD() |  (v)))
#define HW_MIPI_CSI_DATA_IDS_1_CLR(v)    (HW_MIPI_CSI_DATA_IDS_1_WR(HW_MIPI_CSI_DATA_IDS_1_RD() & ~(v)))
#define HW_MIPI_CSI_DATA_IDS_1_TOG(v)    (HW_MIPI_CSI_DATA_IDS_1_WR(HW_MIPI_CSI_DATA_IDS_1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_DATA_IDS_1 bitfields
 */

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI0_DT[5:0] (RW)
 *
 * Data ID 0 Data Type Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI0_DT      (0)
#define BM_MIPI_CSI_DATA_IDS_1_DI0_DT      (0x0000003f)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI0_DT(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_DATA_IDS_1_DI0_DT)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI0_DT(v)   (((v) << 0) & BM_MIPI_CSI_DATA_IDS_1_DI0_DT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI0_DT field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI0_DT(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI0_DT, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI0_VC[7:6] (RW)
 *
 * Data ID 0 Virtual channel Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI0_VC      (6)
#define BM_MIPI_CSI_DATA_IDS_1_DI0_VC      (0x000000c0)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI0_VC(v)   ((((reg32_t) v) << 6) & BM_MIPI_CSI_DATA_IDS_1_DI0_VC)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI0_VC(v)   (((v) << 6) & BM_MIPI_CSI_DATA_IDS_1_DI0_VC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI0_VC field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI0_VC(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI0_VC, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI1_DT[13:8] (RW)
 *
 * Data ID 1 Data Type Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI1_DT      (8)
#define BM_MIPI_CSI_DATA_IDS_1_DI1_DT      (0x00003f00)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI1_DT(v)   ((((reg32_t) v) << 8) & BM_MIPI_CSI_DATA_IDS_1_DI1_DT)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI1_DT(v)   (((v) << 8) & BM_MIPI_CSI_DATA_IDS_1_DI1_DT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI1_DT field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI1_DT(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI1_DT, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI1_VC[15:14] (RW)
 *
 * Data ID 1 Virtual channel Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI1_VC      (14)
#define BM_MIPI_CSI_DATA_IDS_1_DI1_VC      (0x0000c000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI1_VC(v)   ((((reg32_t) v) << 14) & BM_MIPI_CSI_DATA_IDS_1_DI1_VC)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI1_VC(v)   (((v) << 14) & BM_MIPI_CSI_DATA_IDS_1_DI1_VC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI1_VC field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI1_VC(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI1_VC, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI2_DT[21:16] (RW)
 *
 * DATA ID 2 Data Type Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI2_DT      (16)
#define BM_MIPI_CSI_DATA_IDS_1_DI2_DT      (0x003f0000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI2_DT(v)   ((((reg32_t) v) << 16) & BM_MIPI_CSI_DATA_IDS_1_DI2_DT)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI2_DT(v)   (((v) << 16) & BM_MIPI_CSI_DATA_IDS_1_DI2_DT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI2_DT field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI2_DT(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI2_DT, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI2_VC[23:22] (RW)
 *
 * DATA ID 2 Virtual channel Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI2_VC      (22)
#define BM_MIPI_CSI_DATA_IDS_1_DI2_VC      (0x00c00000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI2_VC(v)   ((((reg32_t) v) << 22) & BM_MIPI_CSI_DATA_IDS_1_DI2_VC)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI2_VC(v)   (((v) << 22) & BM_MIPI_CSI_DATA_IDS_1_DI2_VC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI2_VC field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI2_VC(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI2_VC, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI3_DT[29:24] (RW)
 *
 * Data ID 3 Data Type Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI3_DT      (24)
#define BM_MIPI_CSI_DATA_IDS_1_DI3_DT      (0x3f000000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI3_DT(v)   ((((reg32_t) v) << 24) & BM_MIPI_CSI_DATA_IDS_1_DI3_DT)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI3_DT(v)   (((v) << 24) & BM_MIPI_CSI_DATA_IDS_1_DI3_DT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI3_DT field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI3_DT(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI3_DT, v)
#endif

/* --- Register HW_MIPI_CSI_DATA_IDS_1, field DI3_VC[31:30] (RW)
 *
 * Data ID 3 Virtual channel Default Value: 0
 */

#define BP_MIPI_CSI_DATA_IDS_1_DI3_VC      (30)
#define BM_MIPI_CSI_DATA_IDS_1_DI3_VC      (0xc0000000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_DATA_IDS_1_DI3_VC(v)   ((((reg32_t) v) << 30) & BM_MIPI_CSI_DATA_IDS_1_DI3_VC)
#else
#define BF_MIPI_CSI_DATA_IDS_1_DI3_VC(v)   (((v) << 30) & BM_MIPI_CSI_DATA_IDS_1_DI3_VC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DI3_VC field to a new value.
#define BW_MIPI_CSI_DATA_IDS_1_DI3_VC(v)   BF_CS1(MIPI_CSI_DATA_IDS_1, DI3_VC, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_ERR1 - Error state register 1 (RO)
 *
 * Name: Error state register 1  Address Offset: 0x020  Size: 29 bit  Size: 29 bit  Default Value: 0
 * Access: Read
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_ERRSOTSYNCHS_0 : 1; //!< Start of Transmission Error on data lane 0 (no synchronization achieved) Default Value: 0
        unsigned PHY_ERRSOTSYNCHS_1 : 1; //!< Start of Transmission Error on data lane 1 (no synchronization achieved) Default Value: 0
        unsigned RESERVED0 : 2; //!< 
        unsigned ERR_F_BNDRY_MATCH_VC0 : 1; //!< Error matching Frame Start with Frame End for Virtual Channel 0 Default Value: 0
        unsigned ERR_F_BNDRY_MATCH_VC1 : 1; //!< Error matching Frame Start with Frame End for Virtual Channel 1 Default Value: 0
        unsigned ERR_F_BNDRY_MATCH_VC2 : 1; //!< Error matching Frame Start with Frame End for Virtual Channel 2 Default Value: 0
        unsigned ERR_F_BNDRY_MATCH_VC3 : 1; //!< Error matching Frame Start with Frame End for Virtual Channel 3 Default Value: 0
        unsigned ERR_F_SEQ_VC0 : 1; //!< Incorrect Frame Sequence detected in Virtual Channel 0 Default Value: 0
        unsigned ERR_F_SEQ_VC1 : 1; //!< Incorrect Frame Sequence detected in Virtual Channel 1 Default Value: 0
        unsigned ERR_F_SEQ_VC2 : 1; //!< Incorrect Frame Sequence detected in Virtual Channel 2 Default Value: 0
        unsigned ERR_F_SEQ_VC3 : 1; //!< Incorrect Frame Sequence detected in Virtual Channel 3 Default Value: 0
        unsigned ERR_FRAME_DATA_VC0 : 1; //!< Last received frame, in Virtual Channel 0, had at least one CRC error Default Value: 0
        unsigned ERR_FRAME_DATA_VC1 : 1; //!< Last received frame, in Virtual Channel 1, had at least one CRC error Default Value: 0
        unsigned ERR_FRAME_DATA_VC2 : 1; //!< Last received frame, in Virtual Channel 2, had at least one CRC error Default Value: 0
        unsigned ERR_FRAME_DATA_VC3 : 1; //!< Last received frame, in Virtual Channel 3, had at least one CRC error Default Value: 0
        unsigned ERR_L_BNDRY_MATCH_DI0 : 1; //!< Error matching Line Start with Line End for vc0 and dt0 Default Value: 0
        unsigned ERR_L_BNDRY_MATCH_DI1 : 1; //!< Error matching Line Start with Line End for vc1 and dt1 Default Value: 0
        unsigned ERR_L_BNDRY_MATCH_DI2 : 1; //!< Error matching Line Start with Line End for vc2 and dt2 Default Value: 0
        unsigned ERR_L_BNDRY_MATCH_DI3 : 1; //!< Error matching Line Start with Line End for vc3 and dt3 Default Value: 0
        unsigned ERR_L_SEQ_DI0 : 1; //!< Error in the sequence of lines for vc0 and dt0 Default Value: 0
        unsigned ERR_L_SEQ_DI1 : 1; //!< Error in the sequence of lines for vc1 and dt1 Default Value: 0
        unsigned ERR_L_SEQ_DI2 : 1; //!< Error in the sequence of lines for vc2 and dt2 Default Value: 0
        unsigned ERR_L_SEQ_DI3 : 1; //!< Error in the sequence of lines for vc3 and dt3 Default Value: 0
        unsigned VC0_ERR_CRC : 1; //!< Checksum Error detected on Virtual Channel 0 Default Value: 0
        unsigned VC1_ERR_CRC : 1; //!< Checksum Error detected on Virtual Channel 1 Default Value: 0
        unsigned VC2_ERR_CRC : 1; //!< Checksum Error detected on Virtual Channel 2 Default Value: 0
        unsigned VC3_ERR_CRC : 1; //!< Checksum Error detected on Virtual Channel 3 Default Value: 0
        unsigned ERR_ECC_DOUBLE : 1; //!< Header ECC contains 2 errors. Unrecoverable. Default Value: 0
        unsigned RESERVED1 : 3; //!< Reserved
    } B;
} hw_mipi_csi_err1_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_ERR1 register
 */
#define HW_MIPI_CSI_ERR1_ADDR      (REGS_MIPI_CSI_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_ERR1           (*(volatile hw_mipi_csi_err1_t *) HW_MIPI_CSI_ERR1_ADDR)
#define HW_MIPI_CSI_ERR1_RD()      (HW_MIPI_CSI_ERR1.U)
#endif

/*
 * constants & macros for individual MIPI_CSI_ERR1 bitfields
 */

/* --- Register HW_MIPI_CSI_ERR1, field PHY_ERRSOTSYNCHS_0[0:0] (RO)
 *
 * Start of Transmission Error on data lane 0 (no synchronization achieved) Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_PHY_ERRSOTSYNCHS_0      (0)
#define BM_MIPI_CSI_ERR1_PHY_ERRSOTSYNCHS_0      (0x00000001)

/* --- Register HW_MIPI_CSI_ERR1, field PHY_ERRSOTSYNCHS_1[1:1] (RO)
 *
 * Start of Transmission Error on data lane 1 (no synchronization achieved) Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_PHY_ERRSOTSYNCHS_1      (1)
#define BM_MIPI_CSI_ERR1_PHY_ERRSOTSYNCHS_1      (0x00000002)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_BNDRY_MATCH_VC0[4:4] (RO)
 *
 * Error matching Frame Start with Frame End for Virtual Channel 0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC0      (4)
#define BM_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC0      (0x00000010)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_BNDRY_MATCH_VC1[5:5] (RO)
 *
 * Error matching Frame Start with Frame End for Virtual Channel 1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC1      (5)
#define BM_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC1      (0x00000020)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_BNDRY_MATCH_VC2[6:6] (RO)
 *
 * Error matching Frame Start with Frame End for Virtual Channel 2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC2      (6)
#define BM_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC2      (0x00000040)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_BNDRY_MATCH_VC3[7:7] (RO)
 *
 * Error matching Frame Start with Frame End for Virtual Channel 3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC3      (7)
#define BM_MIPI_CSI_ERR1_ERR_F_BNDRY_MATCH_VC3      (0x00000080)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_SEQ_VC0[8:8] (RO)
 *
 * Incorrect Frame Sequence detected in Virtual Channel 0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_SEQ_VC0      (8)
#define BM_MIPI_CSI_ERR1_ERR_F_SEQ_VC0      (0x00000100)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_SEQ_VC1[9:9] (RO)
 *
 * Incorrect Frame Sequence detected in Virtual Channel 1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_SEQ_VC1      (9)
#define BM_MIPI_CSI_ERR1_ERR_F_SEQ_VC1      (0x00000200)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_SEQ_VC2[10:10] (RO)
 *
 * Incorrect Frame Sequence detected in Virtual Channel 2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_SEQ_VC2      (10)
#define BM_MIPI_CSI_ERR1_ERR_F_SEQ_VC2      (0x00000400)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_F_SEQ_VC3[11:11] (RO)
 *
 * Incorrect Frame Sequence detected in Virtual Channel 3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_F_SEQ_VC3      (11)
#define BM_MIPI_CSI_ERR1_ERR_F_SEQ_VC3      (0x00000800)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_FRAME_DATA_VC0[12:12] (RO)
 *
 * Last received frame, in Virtual Channel 0, had at least one CRC error Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC0      (12)
#define BM_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC0      (0x00001000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_FRAME_DATA_VC1[13:13] (RO)
 *
 * Last received frame, in Virtual Channel 1, had at least one CRC error Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC1      (13)
#define BM_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC1      (0x00002000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_FRAME_DATA_VC2[14:14] (RO)
 *
 * Last received frame, in Virtual Channel 2, had at least one CRC error Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC2      (14)
#define BM_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC2      (0x00004000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_FRAME_DATA_VC3[15:15] (RO)
 *
 * Last received frame, in Virtual Channel 3, had at least one CRC error Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC3      (15)
#define BM_MIPI_CSI_ERR1_ERR_FRAME_DATA_VC3      (0x00008000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_BNDRY_MATCH_DI0[16:16] (RO)
 *
 * Error matching Line Start with Line End for vc0 and dt0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI0      (16)
#define BM_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI0      (0x00010000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_BNDRY_MATCH_DI1[17:17] (RO)
 *
 * Error matching Line Start with Line End for vc1 and dt1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI1      (17)
#define BM_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI1      (0x00020000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_BNDRY_MATCH_DI2[18:18] (RO)
 *
 * Error matching Line Start with Line End for vc2 and dt2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI2      (18)
#define BM_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI2      (0x00040000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_BNDRY_MATCH_DI3[19:19] (RO)
 *
 * Error matching Line Start with Line End for vc3 and dt3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI3      (19)
#define BM_MIPI_CSI_ERR1_ERR_L_BNDRY_MATCH_DI3      (0x00080000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_SEQ_DI0[20:20] (RO)
 *
 * Error in the sequence of lines for vc0 and dt0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_SEQ_DI0      (20)
#define BM_MIPI_CSI_ERR1_ERR_L_SEQ_DI0      (0x00100000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_SEQ_DI1[21:21] (RO)
 *
 * Error in the sequence of lines for vc1 and dt1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_SEQ_DI1      (21)
#define BM_MIPI_CSI_ERR1_ERR_L_SEQ_DI1      (0x00200000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_SEQ_DI2[22:22] (RO)
 *
 * Error in the sequence of lines for vc2 and dt2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_SEQ_DI2      (22)
#define BM_MIPI_CSI_ERR1_ERR_L_SEQ_DI2      (0x00400000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_L_SEQ_DI3[23:23] (RO)
 *
 * Error in the sequence of lines for vc3 and dt3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_L_SEQ_DI3      (23)
#define BM_MIPI_CSI_ERR1_ERR_L_SEQ_DI3      (0x00800000)

/* --- Register HW_MIPI_CSI_ERR1, field VC0_ERR_CRC[24:24] (RO)
 *
 * Checksum Error detected on Virtual Channel 0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_VC0_ERR_CRC      (24)
#define BM_MIPI_CSI_ERR1_VC0_ERR_CRC      (0x01000000)

/* --- Register HW_MIPI_CSI_ERR1, field VC1_ERR_CRC[25:25] (RO)
 *
 * Checksum Error detected on Virtual Channel 1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_VC1_ERR_CRC      (25)
#define BM_MIPI_CSI_ERR1_VC1_ERR_CRC      (0x02000000)

/* --- Register HW_MIPI_CSI_ERR1, field VC2_ERR_CRC[26:26] (RO)
 *
 * Checksum Error detected on Virtual Channel 2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_VC2_ERR_CRC      (26)
#define BM_MIPI_CSI_ERR1_VC2_ERR_CRC      (0x04000000)

/* --- Register HW_MIPI_CSI_ERR1, field VC3_ERR_CRC[27:27] (RO)
 *
 * Checksum Error detected on Virtual Channel 3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_VC3_ERR_CRC      (27)
#define BM_MIPI_CSI_ERR1_VC3_ERR_CRC      (0x08000000)

/* --- Register HW_MIPI_CSI_ERR1, field ERR_ECC_DOUBLE[28:28] (RO)
 *
 * Header ECC contains 2 errors. Unrecoverable. Default Value: 0
 */

#define BP_MIPI_CSI_ERR1_ERR_ECC_DOUBLE      (28)
#define BM_MIPI_CSI_ERR1_ERR_ECC_DOUBLE      (0x10000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_ERR2 - Error state register 2 (RO)
 *
 * Name: Error state register 2  Address Offset: 0x024  Size: 24 bit  Default Value: 0  Access: Read
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_ERRESC_0 : 1; //!< Escape Entry Error (ULPM) on data lane 0 Default Value: 0
        unsigned PHY_ERRESC_1 : 1; //!< Escape Entry Error (ULPM) on data lane 1 Default Value: 0
        unsigned RESERVED0 : 2; //!< 
        unsigned PHY_ERRSOTHS_0 : 1; //!< Start of Transmission Error on data lane 0 (synchronization can still be achieved) Default Value: 0
        unsigned PHY_ERRSOTHS_1 : 1; //!< Start of Transmission Error on data lane 1 (synchronization can still be achieved) Default Value: 0
        unsigned RESERVED1 : 2; //!< 
        unsigned VC0_ERR_ECC_CORRECTED : 1; //!< Header error detected and corrected on Virtual Channel 0 Default Value: 0
        unsigned VC1_ERR_ECC_CORRECTED : 1; //!< Header error detected and corrected on Virtual Channel 1 Default Value: 0
        unsigned VC2_ERR_ECC_CORRECTED : 1; //!< Header error detected and corrected on Virtual Channel 2 Default Value: 0
        unsigned VC3_ERR_ECC_CORRECTED : 1; //!< Header error detected and corrected on Virtual Channel 3 Default Value: 0
        unsigned ERR_ID_VC0 : 1; //!< Unrecognized or unimplemented data type detected in Virtual Channel 0 Default Value: 0
        unsigned ERR_ID_VC1 : 1; //!< Unrecognized or unimplemented data type detected in Virtual Channel 1 Default Value: 0
        unsigned ERR_ID_VC2 : 1; //!< Unrecognized or unimplemented data type detected in Virtual Channel 2 Default Value: 0
        unsigned ERR_ID_VC3 : 1; //!< Unrecognized or unimplemented data type detected in Virtual Channel 3 Default Value: 0
        unsigned RESERVED2 : 8; //!< 
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_mipi_csi_err2_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_ERR2 register
 */
#define HW_MIPI_CSI_ERR2_ADDR      (REGS_MIPI_CSI_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_ERR2           (*(volatile hw_mipi_csi_err2_t *) HW_MIPI_CSI_ERR2_ADDR)
#define HW_MIPI_CSI_ERR2_RD()      (HW_MIPI_CSI_ERR2.U)
#endif

/*
 * constants & macros for individual MIPI_CSI_ERR2 bitfields
 */

/* --- Register HW_MIPI_CSI_ERR2, field PHY_ERRESC_0[0:0] (RO)
 *
 * Escape Entry Error (ULPM) on data lane 0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_PHY_ERRESC_0      (0)
#define BM_MIPI_CSI_ERR2_PHY_ERRESC_0      (0x00000001)

/* --- Register HW_MIPI_CSI_ERR2, field PHY_ERRESC_1[1:1] (RO)
 *
 * Escape Entry Error (ULPM) on data lane 1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_PHY_ERRESC_1      (1)
#define BM_MIPI_CSI_ERR2_PHY_ERRESC_1      (0x00000002)

/* --- Register HW_MIPI_CSI_ERR2, field PHY_ERRSOTHS_0[4:4] (RO)
 *
 * Start of Transmission Error on data lane 0 (synchronization can still be achieved) Default Value:
 * 0
 */

#define BP_MIPI_CSI_ERR2_PHY_ERRSOTHS_0      (4)
#define BM_MIPI_CSI_ERR2_PHY_ERRSOTHS_0      (0x00000010)

/* --- Register HW_MIPI_CSI_ERR2, field PHY_ERRSOTHS_1[5:5] (RO)
 *
 * Start of Transmission Error on data lane 1 (synchronization can still be achieved) Default Value:
 * 0
 */

#define BP_MIPI_CSI_ERR2_PHY_ERRSOTHS_1      (5)
#define BM_MIPI_CSI_ERR2_PHY_ERRSOTHS_1      (0x00000020)

/* --- Register HW_MIPI_CSI_ERR2, field VC0_ERR_ECC_CORRECTED[8:8] (RO)
 *
 * Header error detected and corrected on Virtual Channel 0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_VC0_ERR_ECC_CORRECTED      (8)
#define BM_MIPI_CSI_ERR2_VC0_ERR_ECC_CORRECTED      (0x00000100)

/* --- Register HW_MIPI_CSI_ERR2, field VC1_ERR_ECC_CORRECTED[9:9] (RO)
 *
 * Header error detected and corrected on Virtual Channel 1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_VC1_ERR_ECC_CORRECTED      (9)
#define BM_MIPI_CSI_ERR2_VC1_ERR_ECC_CORRECTED      (0x00000200)

/* --- Register HW_MIPI_CSI_ERR2, field VC2_ERR_ECC_CORRECTED[10:10] (RO)
 *
 * Header error detected and corrected on Virtual Channel 2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_VC2_ERR_ECC_CORRECTED      (10)
#define BM_MIPI_CSI_ERR2_VC2_ERR_ECC_CORRECTED      (0x00000400)

/* --- Register HW_MIPI_CSI_ERR2, field VC3_ERR_ECC_CORRECTED[11:11] (RO)
 *
 * Header error detected and corrected on Virtual Channel 3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_VC3_ERR_ECC_CORRECTED      (11)
#define BM_MIPI_CSI_ERR2_VC3_ERR_ECC_CORRECTED      (0x00000800)

/* --- Register HW_MIPI_CSI_ERR2, field ERR_ID_VC0[12:12] (RO)
 *
 * Unrecognized or unimplemented data type detected in Virtual Channel 0 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_ERR_ID_VC0      (12)
#define BM_MIPI_CSI_ERR2_ERR_ID_VC0      (0x00001000)

/* --- Register HW_MIPI_CSI_ERR2, field ERR_ID_VC1[13:13] (RO)
 *
 * Unrecognized or unimplemented data type detected in Virtual Channel 1 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_ERR_ID_VC1      (13)
#define BM_MIPI_CSI_ERR2_ERR_ID_VC1      (0x00002000)

/* --- Register HW_MIPI_CSI_ERR2, field ERR_ID_VC2[14:14] (RO)
 *
 * Unrecognized or unimplemented data type detected in Virtual Channel 2 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_ERR_ID_VC2      (14)
#define BM_MIPI_CSI_ERR2_ERR_ID_VC2      (0x00004000)

/* --- Register HW_MIPI_CSI_ERR2, field ERR_ID_VC3[15:15] (RO)
 *
 * Unrecognized or unimplemented data type detected in Virtual Channel 3 Default Value: 0
 */

#define BP_MIPI_CSI_ERR2_ERR_ID_VC3      (15)
#define BM_MIPI_CSI_ERR2_ERR_ID_VC3      (0x00008000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_MASK2 - Masks for errors 2 (RW)
 *
 * Name: Masks for errors 2  Address Offset: 0x02C  Size: 24 bit  Default Value: 0  Access:
 * Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MASK_PHY_ERRESC_0 : 1; //!< Mask for phy_erresc_0. Default Value: 0
        unsigned MASK_PHY_ERRESC_1 : 1; //!< Mask for phy_erresc_1. Default Value: 0
        unsigned RESERVED0 : 2; //!< 
        unsigned MASK_PHY_ERRSOTHS_0 : 1; //!< Mask for phy_errsoths_0. Default Value: 0
        unsigned MASK_PHY_ERRSOTHS_1 : 1; //!< Mask for phy_errsoths_1. Default Value: 0
        unsigned RESERVED1 : 2; //!< 
        unsigned MASK_VC0_ERR_ECC_CORRECTED : 1; //!< Mask for vc0_err_ecc_corrected. Default Value: 0
        unsigned MASK_VC1_ERR_ECC_CORRECTED : 1; //!< Mask for vc1_err_ecc_corrected. Default Value: 0
        unsigned MASK_VC2_ERR_ECC_CORRECTED : 1; //!< Mask for vc2_err_ecc_corrected. Default Value: 0
        unsigned MASK_VC3_ERR_ECC_CORRECTED : 1; //!< Mask for vc3_err_ecc_corrected. Default Value: 0
        unsigned MASK_ERR_ID_VC0 : 1; //!< Mask for err_id_vc0. Default Value: 0
        unsigned MASK_ERR_ID_VC1 : 1; //!< Mask for err_id_vc1. Default Value: 0
        unsigned MASK_ERR_ID_VC2 : 1; //!< Mask for err_id_vc2. Default Value: 0
        unsigned MASK_ERR_ID_VC3 : 1; //!< Mask for err_id_vc3. Default Value: 0
        unsigned RESERVED2 : 8; //!< 
        unsigned RESERVED3 : 8; //!< Reserved
    } B;
} hw_mipi_csi_mask2_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_MASK2 register
 */
#define HW_MIPI_CSI_MASK2_ADDR      (REGS_MIPI_CSI_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_MASK2           (*(volatile hw_mipi_csi_mask2_t *) HW_MIPI_CSI_MASK2_ADDR)
#define HW_MIPI_CSI_MASK2_RD()      (HW_MIPI_CSI_MASK2.U)
#define HW_MIPI_CSI_MASK2_WR(v)     (HW_MIPI_CSI_MASK2.U = (v))
#define HW_MIPI_CSI_MASK2_SET(v)    (HW_MIPI_CSI_MASK2_WR(HW_MIPI_CSI_MASK2_RD() |  (v)))
#define HW_MIPI_CSI_MASK2_CLR(v)    (HW_MIPI_CSI_MASK2_WR(HW_MIPI_CSI_MASK2_RD() & ~(v)))
#define HW_MIPI_CSI_MASK2_TOG(v)    (HW_MIPI_CSI_MASK2_WR(HW_MIPI_CSI_MASK2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_MASK2 bitfields
 */

/* --- Register HW_MIPI_CSI_MASK2, field MASK_PHY_ERRESC_0[0:0] (RW)
 *
 * Mask for phy_erresc_0. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0      (0)
#define BM_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0)
#else
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0(v)   (((v) << 0) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_PHY_ERRESC_0 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_PHY_ERRESC_0(v)   BF_CS1(MIPI_CSI_MASK2, MASK_PHY_ERRESC_0, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_PHY_ERRESC_1[1:1] (RW)
 *
 * Mask for phy_erresc_1. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1      (1)
#define BM_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1(v)   ((((reg32_t) v) << 1) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1)
#else
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1(v)   (((v) << 1) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_PHY_ERRESC_1 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_PHY_ERRESC_1(v)   BF_CS1(MIPI_CSI_MASK2, MASK_PHY_ERRESC_1, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_PHY_ERRSOTHS_0[4:4] (RW)
 *
 * Mask for phy_errsoths_0. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0      (4)
#define BM_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0(v)   ((((reg32_t) v) << 4) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0)
#else
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0(v)   (((v) << 4) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_PHY_ERRSOTHS_0 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_0(v)   BF_CS1(MIPI_CSI_MASK2, MASK_PHY_ERRSOTHS_0, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_PHY_ERRSOTHS_1[5:5] (RW)
 *
 * Mask for phy_errsoths_1. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1      (5)
#define BM_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1(v)   ((((reg32_t) v) << 5) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1)
#else
#define BF_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1(v)   (((v) << 5) & BM_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_PHY_ERRSOTHS_1 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_PHY_ERRSOTHS_1(v)   BF_CS1(MIPI_CSI_MASK2, MASK_PHY_ERRSOTHS_1, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_VC0_ERR_ECC_CORRECTED[8:8] (RW)
 *
 * Mask for vc0_err_ecc_corrected. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED      (8)
#define BM_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED      (0x00000100)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED(v)   ((((reg32_t) v) << 8) & BM_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED)
#else
#define BF_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED(v)   (((v) << 8) & BM_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VC0_ERR_ECC_CORRECTED field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_VC0_ERR_ECC_CORRECTED(v)   BF_CS1(MIPI_CSI_MASK2, MASK_VC0_ERR_ECC_CORRECTED, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_VC1_ERR_ECC_CORRECTED[9:9] (RW)
 *
 * Mask for vc1_err_ecc_corrected. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED      (9)
#define BM_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED      (0x00000200)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED(v)   ((((reg32_t) v) << 9) & BM_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED)
#else
#define BF_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED(v)   (((v) << 9) & BM_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VC1_ERR_ECC_CORRECTED field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_VC1_ERR_ECC_CORRECTED(v)   BF_CS1(MIPI_CSI_MASK2, MASK_VC1_ERR_ECC_CORRECTED, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_VC2_ERR_ECC_CORRECTED[10:10] (RW)
 *
 * Mask for vc2_err_ecc_corrected. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED      (10)
#define BM_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED      (0x00000400)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED(v)   ((((reg32_t) v) << 10) & BM_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED)
#else
#define BF_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED(v)   (((v) << 10) & BM_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VC2_ERR_ECC_CORRECTED field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_VC2_ERR_ECC_CORRECTED(v)   BF_CS1(MIPI_CSI_MASK2, MASK_VC2_ERR_ECC_CORRECTED, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_VC3_ERR_ECC_CORRECTED[11:11] (RW)
 *
 * Mask for vc3_err_ecc_corrected. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED      (11)
#define BM_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED      (0x00000800)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED(v)   ((((reg32_t) v) << 11) & BM_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED)
#else
#define BF_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED(v)   (((v) << 11) & BM_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VC3_ERR_ECC_CORRECTED field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_VC3_ERR_ECC_CORRECTED(v)   BF_CS1(MIPI_CSI_MASK2, MASK_VC3_ERR_ECC_CORRECTED, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_ERR_ID_VC0[12:12] (RW)
 *
 * Mask for err_id_vc0. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_ERR_ID_VC0      (12)
#define BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC0      (0x00001000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC0(v)   ((((reg32_t) v) << 12) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC0)
#else
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC0(v)   (((v) << 12) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC0)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_ERR_ID_VC0 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_ERR_ID_VC0(v)   BF_CS1(MIPI_CSI_MASK2, MASK_ERR_ID_VC0, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_ERR_ID_VC1[13:13] (RW)
 *
 * Mask for err_id_vc1. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_ERR_ID_VC1      (13)
#define BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC1      (0x00002000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC1(v)   ((((reg32_t) v) << 13) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC1)
#else
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC1(v)   (((v) << 13) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC1)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_ERR_ID_VC1 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_ERR_ID_VC1(v)   BF_CS1(MIPI_CSI_MASK2, MASK_ERR_ID_VC1, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_ERR_ID_VC2[14:14] (RW)
 *
 * Mask for err_id_vc2. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_ERR_ID_VC2      (14)
#define BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC2      (0x00004000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC2(v)   ((((reg32_t) v) << 14) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC2)
#else
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC2(v)   (((v) << 14) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC2)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_ERR_ID_VC2 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_ERR_ID_VC2(v)   BF_CS1(MIPI_CSI_MASK2, MASK_ERR_ID_VC2, v)
#endif

/* --- Register HW_MIPI_CSI_MASK2, field MASK_ERR_ID_VC3[15:15] (RW)
 *
 * Mask for err_id_vc3. Default Value: 0
 */

#define BP_MIPI_CSI_MASK2_MASK_ERR_ID_VC3      (15)
#define BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC3      (0x00008000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC3(v)   ((((reg32_t) v) << 15) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC3)
#else
#define BF_MIPI_CSI_MASK2_MASK_ERR_ID_VC3(v)   (((v) << 15) & BM_MIPI_CSI_MASK2_MASK_ERR_ID_VC3)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_ERR_ID_VC3 field to a new value.
#define BW_MIPI_CSI_MASK2_MASK_ERR_ID_VC3(v)   BF_CS1(MIPI_CSI_MASK2, MASK_ERR_ID_VC3, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_PHY_TST_CRTL0 - D-PHY Test interface control 0 (RW)
 *
 * Name: D-PHY Test interface control 0  Address Offset: 0x030  Size: 2 bit  Default Value: 0
 * Access: Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_TESTCLR : 1; //!< PHY test interface clear. Used when active performs vendor specific interface initialization(Active High). Default Value: 0
        unsigned PHY_TESTCLK : 1; //!< PHY test interface strobe signal. Used to clock TESTDIN bus into the D-PHY. In conjunction with TESTEN signal controls the operation selection. Default Value: 0
        unsigned RESERVED0 : 30; //!< Reserved
    } B;
} hw_mipi_csi_phy_tst_crtl0_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_PHY_TST_CRTL0 register
 */
#define HW_MIPI_CSI_PHY_TST_CRTL0_ADDR      (REGS_MIPI_CSI_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_PHY_TST_CRTL0           (*(volatile hw_mipi_csi_phy_tst_crtl0_t *) HW_MIPI_CSI_PHY_TST_CRTL0_ADDR)
#define HW_MIPI_CSI_PHY_TST_CRTL0_RD()      (HW_MIPI_CSI_PHY_TST_CRTL0.U)
#define HW_MIPI_CSI_PHY_TST_CRTL0_WR(v)     (HW_MIPI_CSI_PHY_TST_CRTL0.U = (v))
#define HW_MIPI_CSI_PHY_TST_CRTL0_SET(v)    (HW_MIPI_CSI_PHY_TST_CRTL0_WR(HW_MIPI_CSI_PHY_TST_CRTL0_RD() |  (v)))
#define HW_MIPI_CSI_PHY_TST_CRTL0_CLR(v)    (HW_MIPI_CSI_PHY_TST_CRTL0_WR(HW_MIPI_CSI_PHY_TST_CRTL0_RD() & ~(v)))
#define HW_MIPI_CSI_PHY_TST_CRTL0_TOG(v)    (HW_MIPI_CSI_PHY_TST_CRTL0_WR(HW_MIPI_CSI_PHY_TST_CRTL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_PHY_TST_CRTL0 bitfields
 */

/* --- Register HW_MIPI_CSI_PHY_TST_CRTL0, field PHY_TESTCLR[0:0] (RW)
 *
 * PHY test interface clear. Used when active performs vendor specific interface
 * initialization(Active High). Default Value: 0
 */

#define BP_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR      (0)
#define BM_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR)
#else
#define BF_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR(v)   (((v) << 0) & BM_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTCLR field to a new value.
#define BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLR(v)   BF_CS1(MIPI_CSI_PHY_TST_CRTL0, PHY_TESTCLR, v)
#endif

/* --- Register HW_MIPI_CSI_PHY_TST_CRTL0, field PHY_TESTCLK[1:1] (RW)
 *
 * PHY test interface strobe signal. Used to clock TESTDIN bus into the D-PHY. In conjunction with
 * TESTEN signal controls the operation selection. Default Value: 0
 */

#define BP_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK      (1)
#define BM_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(v)   ((((reg32_t) v) << 1) & BM_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK)
#else
#define BF_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(v)   (((v) << 1) & BM_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTCLK field to a new value.
#define BW_MIPI_CSI_PHY_TST_CRTL0_PHY_TESTCLK(v)   BF_CS1(MIPI_CSI_PHY_TST_CRTL0, PHY_TESTCLK, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_MIPI_CSI_PHY_TST_CTRL1 - D-PHY Test interface control 1 (RW)
 *
 * Name: D-PHY Test interface control 1  Address Offset: 0x034  Size: 17 bit  Default Value: 0
 * Access: Read/Write
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned PHY_TESTDIN : 8; //!< PHY test interface input 8-bit data bus for internal register programming and test functionalities access Default Value: 0
        unsigned PHY_TESTDOUT : 8; //!< PHY output 8-bit data bus for read-back and internal probing functionalities. Default Value: 0
        unsigned PHY_TESTEN : 1; //!< PHY test interface operation selector:
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_mipi_csi_phy_tst_ctrl1_t;
#endif

/*
 * constants & macros for entire MIPI_CSI_PHY_TST_CTRL1 register
 */
#define HW_MIPI_CSI_PHY_TST_CTRL1_ADDR      (REGS_MIPI_CSI_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_MIPI_CSI_PHY_TST_CTRL1           (*(volatile hw_mipi_csi_phy_tst_ctrl1_t *) HW_MIPI_CSI_PHY_TST_CTRL1_ADDR)
#define HW_MIPI_CSI_PHY_TST_CTRL1_RD()      (HW_MIPI_CSI_PHY_TST_CTRL1.U)
#define HW_MIPI_CSI_PHY_TST_CTRL1_WR(v)     (HW_MIPI_CSI_PHY_TST_CTRL1.U = (v))
#define HW_MIPI_CSI_PHY_TST_CTRL1_SET(v)    (HW_MIPI_CSI_PHY_TST_CTRL1_WR(HW_MIPI_CSI_PHY_TST_CTRL1_RD() |  (v)))
#define HW_MIPI_CSI_PHY_TST_CTRL1_CLR(v)    (HW_MIPI_CSI_PHY_TST_CTRL1_WR(HW_MIPI_CSI_PHY_TST_CTRL1_RD() & ~(v)))
#define HW_MIPI_CSI_PHY_TST_CTRL1_TOG(v)    (HW_MIPI_CSI_PHY_TST_CTRL1_WR(HW_MIPI_CSI_PHY_TST_CTRL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual MIPI_CSI_PHY_TST_CTRL1 bitfields
 */

/* --- Register HW_MIPI_CSI_PHY_TST_CTRL1, field PHY_TESTDIN[7:0] (RW)
 *
 * PHY test interface input 8-bit data bus for internal register programming and test
 * functionalities access Default Value: 0
 */

#define BP_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN      (0)
#define BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN(v)   ((((reg32_t) v) << 0) & BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN)
#else
#define BF_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN(v)   (((v) << 0) & BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTDIN field to a new value.
#define BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDIN(v)   BF_CS1(MIPI_CSI_PHY_TST_CTRL1, PHY_TESTDIN, v)
#endif

/* --- Register HW_MIPI_CSI_PHY_TST_CTRL1, field PHY_TESTDOUT[15:8] (RW)
 *
 * PHY output 8-bit data bus for read-back and internal probing functionalities. Default Value: 0
 */

#define BP_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT      (8)
#define BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT(v)   ((((reg32_t) v) << 8) & BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT)
#else
#define BF_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT(v)   (((v) << 8) & BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTDOUT field to a new value.
#define BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTDOUT(v)   BF_CS1(MIPI_CSI_PHY_TST_CTRL1, PHY_TESTDOUT, v)
#endif

/* --- Register HW_MIPI_CSI_PHY_TST_CTRL1, field PHY_TESTEN[16:16] (RW)
 *
 * PHY test interface operation selector:
 *
 * Values:
 * 0 - configures a data write operation on the rising edge of TESTCLK
 * 1 - configures address write operation on the falling edge of TESTCLK
 */

#define BP_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN      (16)
#define BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN(v)   ((((reg32_t) v) << 16) & BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN)
#else
#define BF_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN(v)   (((v) << 16) & BM_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the PHY_TESTEN field to a new value.
#define BW_MIPI_CSI_PHY_TST_CTRL1_PHY_TESTEN(v)   BF_CS1(MIPI_CSI_PHY_TST_CTRL1, PHY_TESTEN, v)
#endif



/*!
 * @brief All MIPI_CSI module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_mipi_csi_version_t VERSION; //!< Controller Version Identification Register
    volatile hw_mipi_csi_n_lanes_t N_LANES; //!< Number of Active Data Lanes
    volatile hw_mipi_csi_phy_shutdownz_t PHY_SHUTDOWNZ; //!< Phy shutdown control
    volatile hw_mipi_csi_dphy_rstz_t DPHY_RSTZ; //!< Phy reset control
    volatile hw_mipi_csi_csi2_resetn_t CSI2_RESETN; //!< CSI2 controller reset
    volatile hw_mipi_csi_phy_state_t PHY_STATE; //!< General settings for all blocks
    volatile hw_mipi_csi_data_ids_1_t DATA_IDS_1; //!< Data IDs for which IDI reports line boundary matching errors
    reg32_t _reserved0;
    volatile hw_mipi_csi_err1_t ERR1; //!< Error state register 1
    volatile hw_mipi_csi_err2_t ERR2; //!< Error state register 2
    reg32_t _reserved1;
    volatile hw_mipi_csi_mask2_t MASK2; //!< Masks for errors 2
    volatile hw_mipi_csi_phy_tst_crtl0_t PHY_TST_CRTL0; //!< D-PHY Test interface control 0
    volatile hw_mipi_csi_phy_tst_ctrl1_t PHY_TST_CTRL1; //!< D-PHY Test interface control 1
} hw_mipi_csi_t;
#endif

//! @brief Macro to access all MIPI_CSI registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MIPI_CSI(0)</code>.
#define HW_MIPI_CSI     (*(volatile hw_mipi_csi_t *) REGS_MIPI_CSI_BASE)


#endif // _MIPI_CSI_H
