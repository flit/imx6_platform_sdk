/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  mipi_common.h
 * @brief mipi common definitions.
 *
 * @ingroup diag_mipi
 */

#ifndef _MIPI_COMMON_H_
#define _MIPI_COMMON_H_
/* Standard testbench defines files */
#include "imx_i2c.h"
#include "hardware.h"
#include <math.h>

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))

#define DPI_MODE 1
#define IO_EXPANDER_ADDR    (0x1b)
#define MIPI_CSI_ADDR       (0x3c)  //for 5640//78

///////////////////////////////////////////////////////////////////////
////////DSI LINK DEFINITION////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define     CLKLANEBYTEPERIOD   10  //since we are using 800Mbps phy, the DSI controller working at 100Hz
#define     NUMBEROFLANES       1   //2 Data Lanes
#define 	DSI_CLK_DIV		0x107

//////////////////////////////////////////////////////////////////////
////////VIDEO DEFINITION--480x800 period 25///////////////////////////
////////////////////////////////////////////////////////////////////////
/*All these parameters are from the LCD spec*/
#define     DPITHSA             8   //hsync valid witdh
#define     DPITHBP             8   //Horizontal Back Porch
#define     DPITHACT            480 //Horizontal active pixel
#define     DPITHFP             8   //Horizontal Front Porch
#define     DPIVSALINES         4   //Vertical Synchronization witdth
#define     DPIVBPLINES         4   //Vertical Back Porch
#define     DPIVACTLINES        800 //Vertical active lines
#define     DPIVFPLINES         4   //Vertical Front Porch

#define     DPIVCHANNELID       0   //Configures the DPI Virtual Channel ID that is indexed to the Video mode packets.
#define     DPICOLORMODE        7   //DPI color coding. 0: 16bit config1; 1: 16bit config2; 2: 16bit config3; 3: 18bit config1; 4: 18bit config2; 5 to 7: 24 bit
#define     DPIDATENACTLOW      1   //Set to configure Data enable pin (dpidaten) as Active low.
#define     DPIVSYNCACTLOW      1   //Set to configure Vertical Synchronism pin (dpivsync) as Active low.
#define     DPIHSYNCACTLOW      1   //Set to configure Horizontal Synchronism pin (dpihsync) as Active low.
#define     DPICOLRMACTLOW      0   //Set to configure Shut Down pin (dpishutdn) as Active low.
#define     DPISHTDMACTLOW      0   //Set to configure Color Mode pin (dpicolcorm) as Active low
#define     ENABLE18BPPLOOSELY  0   //When in 18 bit video mode this enable the 18 bit loosely packed pixel stream

////////////////////////////////////////////////////////////////////////
/////////////////////PACKET HANDLER DEFINITION//////////////////////////
////////////////////////////////////////////////////////////////////////
#define     EOTPGENERATION       1  //Enables the generation of EOTpacket before going to Low POWER
#define     EOTPRECEPTION        0  //Programs the Core to expect for EOTpackets when transmission are received
#define     BTA_ENABLE           1  //Enables Bus Turn-Around request.
#define     EN_ECC_RX            1  //Enables ECC reception, error correction and reporting.
#define     EN_CRC_RX            1  //Enables CRC reception and error reporting
#define     EN_VID_RX            1  //Generic interface read-back Virtual Channel identification
#define     VIDEO_MODE_ENABLE    1
#define     COMMAND_MODE_ENABLE  0
#define     VID_MODE_EN          1  //Enables DPI Video mode transmission.
#define     VIDEO_MODE           3  //0-syncro w/ sync pulses; 1-synchro w/ sync events; 2,3-synchro w/ sync events
#define     LP_VSA_EN            1  //Enables the LOW power transition when in Vertical Sync Active Region
#define     LP_VBP_EN            1  //Enables the LOW power transition when in Vertical Back Porch Region
#define     LP_VFP_EN            1  //Enables the LOW power transition when in Vertical Front Porch Region
#define     LP_VACT_EN           1  //Enables the LOW power transition when in Vertical Active Line Region
#define     LP_HBP_EN            1  //Enables the LOW power transition when in Horizontal Back Porch Region
#define     LP_HFP_EN            1  //Enables the LOW power transition when in Horizontal Front Porch Region
#define     ENABLE_MULT_PKTS     0  //if there is no active video time overhead or in burst mode shoudl be set 0
#define     ENABLE_NULL_PKTS     0  //if there is no active video time overhead or in burst mode shoudl be set 0
#define     BAT_ACK_EN           0  //Enables the request for an acknowledge response at the end of a frame.
#define     BTA_MAX_TIME         0xd00
#define     PHY_LP_TO_HS         0x40
#define     PHY_HS_TO_LP         0x40

#define     GEN_SW_0P_LP_ENA     1
#define     GEN_SW_1P_LP_ENA     1
#define     GEN_SW_2P_LP_ENA     1
#define     GEN_SR_0P_LP_ENA     1
#define     GEN_SR_1P_LP_ENA     1
#define     GEN_SR_2P_LP_ENA     1
#define     DSC_SW_0P_LP_ENA     1
#define     DSC_SW_1P_LP_ENA     1
#define     DSC_SR_0P_LP_ENA     1
#define     MAX_READ_PACKET_SIZE 1
#define     GEN_LW_LP_ENA        0
#define     DCS_LW_LP_ENA        1
#define     ACK_REQUEST_ENABLE   0
#define     TEAR_FX_ENABLE       0
#define     PHY_STOP_WAIT_TIME   0x10
#define     TXREQESTCLKHS        1
#define     TXREQULPSCLK         0
#define     TXEXITULPSCLK        0
#define     TXREQULPSLAN         0
#define     TXEXITULPSLAN        0
#define     TXTRIGGERS           0

////////////////////////////////////////////////////////////////////////
/////////////////////DBI INTEFACE DEFINITION////////////////////////////
////////////////////////////////////////////////////////////////////////
#define     DBIVCHANNELID        0  //;
#define     DBIIFCONFIG          0x0b   //16bit interface 8bpp color mode
#define     DBIWRITEMAXSIZE      0x49   //;
#define     DBILUTSIZECFG        1  //;//LUT size 0-48bytes; 1-128bytes; 2-192bytes; 3-48bytes
#define     DBIOUTPARTIENA       1  //;
#define     DBIWRITECOMSIZE      0x091  //;
#define     PIXELS_PER_PACKET   480
#define     NUMBER_OF_CHUNKS    0x08
#define     NULL_PKT_SIZE       0x08

////////////////////////////////////////////////////////////////////////
//////////Video mode calc parames///////////////////////////////////////
////////////////////////////////////////////////////////////////////////
#define     DPI2BYTECLKRATIO    DPI2LANECLKRATIO*NUMBEROFLANES  // The ratio of byte clocks per pixel clock
#define     CLKMGR_CFG          0x00
#define     DPI_CFG             (DPIVCHANNELID)|(DPICOLORMODE<<2)|(DPIDATENACTLOW<<5)| \
                                (DPIVSYNCACTLOW<<6)|(DPIHSYNCACTLOW<<7)|(DPICOLRMACTLOW<<8)|(DPISHTDMACTLOW<<9)|\
                                (ENABLE18BPPLOOSELY<<10)
#define     DBI_CFG             (DBIVCHANNELID)|(DBIIFCONFIG<<2)|(DBILUTSIZECFG<<6)|(DBIOUTPARTIENA<<8)|(DBIIFCONFIG<<9)
#define     DBI_CMD_CTRL        (DBIWRITECOMSIZE+1)|(DBIWRITEMAXSIZE<<16)
#define     PCKHDL_CFG          (EOTPGENERATION)|(EOTPRECEPTION<<1)|(BTA_ENABLE<<2)|(EN_ECC_RX<<3)|(EN_CRC_RX<<4)|(EN_VID_RX<<5)
#define     VID_MODE_CFG        (VID_MODE_EN)|(VIDEO_MODE<<1)|(LP_VSA_EN<<3)|(LP_VBP_EN<<4)| \
                                (LP_VFP_EN<<5)|(LP_VACT_EN<<6)|(LP_HBP_EN<<7)|(LP_HFP_EN<<8)| \
                                (ENABLE_MULT_PKTS<<9)|(ENABLE_NULL_PKTS<<10)|(BAT_ACK_EN<<11)
#define     VID_PKT_CFG         (PIXELS_PER_PACKET)|(NUMBER_OF_CHUNKS<<11)|(NULL_PKT_SIZE<<21)
#define     COMMAND_MODE_CFG    (COMMAND_MODE_ENABLE)|(GEN_SW_0P_LP_ENA<<1)|(GEN_SW_1P_LP_ENA<<2)| \
                                (GEN_SW_2P_LP_ENA<<3)|(GEN_SR_0P_LP_ENA<<4)|(GEN_SR_1P_LP_ENA<<5)| \
                                (GEN_SR_2P_LP_ENA<<6)|(DSC_SW_0P_LP_ENA<<7)|(DSC_SW_1P_LP_ENA<<8)| \
                                (DSC_SR_0P_LP_ENA<<9)|(MAX_READ_PACKET_SIZE<<10)|(GEN_LW_LP_ENA<<11)| \
                                (DCS_LW_LP_ENA<<12)|(ACK_REQUEST_ENABLE<<13)|(TEAR_FX_ENABLE<<14)
#define     TMR_LINE_CFG        (THSA)|(THBP<<9)|(THLINE<<18)
#define     VTIMING_CFG         (DPIVSALINES)|(DPIVBPLINES<<4)|(DPIVFPLINES<<10)|(DPIVACTLINES<<16)
#define     PHY_TIMING_CFG      (BTA_MAX_TIME)|(PHY_LP_TO_HS<<12)|(PHY_HS_TO_LP<<20)
#define     PHY_IF_CFG          (NUMBEROFLANES-1)|(PHY_STOP_WAIT_TIME<<2)
#define     PWR_UP              1
#define     PHYRSTZ             7
#define     PHY_IF_CTRL         (TXREQESTCLKHS)|(TXREQULPSCLK<<1)|(TXREQULPSLAN<<2)|(TXEXITULPSLAN<<3)|(TXTRIGGERS<<4)
#define     DBI_CONFIG_VALUE                        0xc0895e81%5

#define    HSI_MEM_BASE_ADDRESS                    MMDC1_ARB_BASE_ADDR

#define    OFFSET_CSI2_VERSION                      0x000
#define    OFFSET_CSI2_N_LANES                      0x004
#define    OFFSET_CSI2_PHY_SHUTDOWNZ                0x008
#define    OFFSET_CSI2_DPHY_RSTZ                    0x00c
#define    OFFSET_CSI2_RESETN                       0x010
#define    OFFSET_CSI2_PHY_STATE                    0x014
#define    OFFSET_CSI2_DATA_IDS_1                   0x018
#define    OFFSET_CSI2_DATA_IDS_2                   0x01c
#define    OFFSET_CSI2_ERR1                         0x020
#define    OFFSET_CSI2_ERR2                         0x024
#define    OFFSET_CSI2_MSK1                         0x028
#define    OFFSET_CSI2_MSK2                         0x02c
#define    OFFSET_CSI2_PHY_TST_CTRL0                0x030
#define    OFFSET_CSI2_PHY_TST_CTRL1                0x034
#define    OFFSET_CSI2_SFT_RESET	                0xf00

#define    OFFSET_DSI_VERSION                      0x000
#define    OFFSET_DSI_PWR_UP                       0x004
#define    OFFSET_DSI_CLKMGR_CFG                   0x008
#define    OFFSET_DSI_DPI_CFG                      0x00c
#define    OFFSET_DSI_DBI_CFG                      0x010
#define    OFFSET_DSI_DBI_CMDSIZE                  0x014
#define    OFFSET_DSI_PCKHDL_CFG                   0x018
#define    OFFSET_DSI_VID_MODE_CFG                 0x01c
#define    OFFSET_DSI_VID_PKT_CFG                  0x020
#define    OFFSET_DSI_CMD_MODE_CFG                 0x024
#define    OFFSET_DSI_TMR_LINE_CFG                 0x028
#define    OFFSET_DSI_VTIMING_CFG                  0x02c
#define    OFFSET_DSI_TMR_CFG                      0x030
#define    OFFSET_DSI_GEN_HDR                      0x034
#define    OFFSET_DSI_GEN_PLD_DATA                 0x038
#define    OFFSET_DSI_CMD_PKT_STATUS               0x03c
#define    OFFSET_DSI_TO_CNT_CFG                   0x040
#define    OFFSET_DSI_ERROR_ST0                    0x044
#define    OFFSET_DSI_ERROR_ST1                    0x048
#define    OFFSET_DSI_ERROR_MSK0                   0x04c
#define    OFFSET_DSI_ERROR_MSK1                   0x050
#define    OFFSET_DSI_PHY_RSTZ                     0x054
#define    OFFSET_DSI_PHY_IF_CFG                   0x058
#define    OFFSET_DSI_PHY_IF_CTRL                  0x05c
#define    OFFSET_DSI_PHY_STATUS                   0x060
#define    OFFSET_DSI_PHY_TST_CTRL0                0x064
#define    OFFSET_DSI_PHY_TST_CTRL1                0x068
#define    OFFSET_DSI_DPHY_CTRL                    0xf00
#define    OFFSET_DSI_DPHY_STATUS                  0xf04
#define    OFFSET_CSI2_DPHY_CTRL0                  0xf08
#define    OFFSET_CSI2_DPHY_CTRL1                  0xf0c
#define    OFFSET_CSI2_DPHY_STATUS                 0xf10
#define    OFFSET_DPHY_TEST_CTRL                   0xf14

/*MIPI CSI registers*/
#define    CSI2_VERSION         (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_VERSION         )
#define    CSI2_N_LANES		    (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_N_LANES	       )
#define    CSI2_PHY_SHUTDOWNZ   (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_PHY_SHUTDOWNZ   )
#define    CSI2_DPHY_RSTZ       (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_DPHY_RSTZ       )
#define    CSI2_RESETN          (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_RESETN          )
#define    CSI2_PHY_STATE       (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_PHY_STATE       )
#define    CSI2_DATA_IDS_1      (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_DATA_IDS_1      )
#define    CSI2_DATA_IDS_2      (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_DATA_IDS_2      )
#define    CSI2_ERR1            (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_ERR1            )
#define    CSI2_ERR2            (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_ERR2            )
#define    CSI2_MSK1            (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_MSK1            )
#define    CSI2_MSK2            (MIPI_CSI2_BASE_ADDR + OFFSET_CSI2_MSK2            )
#define    CSI2_PHY_TST_CTRL0   (MIPI_CSI2_BASE_ADDR+ OFFSET_CSI2_PHY_TST_CTRL0   )
#define    CSI2_PHY_TST_CTRL1   (MIPI_CSI2_BASE_ADDR+ OFFSET_CSI2_PHY_TST_CTRL1   )
#define    CSI2_SFT_RESET       (MIPI_CSI2_BASE_ADDR+ OFFSET_CSI2_SFT_RESET   )

/*MIPI DSI registers*/
#define    DSI_VERSION         (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_VERSION         )
#define    DSI_PWR_UP          (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PWR_UP          )
#define    DSI_CLKMGR_CFG      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_CLKMGR_CFG      )
#define    DSI_DPI_CFG         (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_DPI_CFG         )
#define    DSI_DBI_CFG         (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_DBI_CFG         )
#define    DSI_DBI_CMDSIZE     (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_DBI_CMDSIZE     )
#define    DSI_PCKHDL_CFG      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PCKHDL_CFG      )
#define    DSI_VID_MODE_CFG    (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_VID_MODE_CFG    )
#define    DSI_VID_PKT_CFG     (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_VID_PKT_CFG     )
#define    DSI_CMD_MODE_CFG    (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_CMD_MODE_CFG    )
#define    DSI_TMR_LINE_CFG    (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_TMR_LINE_CFG    )
#define    DSI_VTIMING_CFG     (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_VTIMING_CFG     )
#define    DSI_TMR_CFG         (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_TMR_CFG         )
#define    DSI_GEN_HDR         (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_GEN_HDR         )
#define    DSI_GEN_PLD_DATA    (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_GEN_PLD_DATA    )
#define    DSI_CMD_PKT_STATUS  (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_CMD_PKT_STATUS  )
#define    DSI_TO_CNT_CFG      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_TO_CNT_CFG      )
#define    DSI_ERROR_ST0       (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_ERROR_ST0       )
#define    DSI_ERROR_ST1       (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_ERROR_ST1       )
#define    DSI_ERROR_MSK0      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_ERROR_MSK0      )
#define    DSI_ERROR_MSK1      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_ERROR_MSK1      )
#define    DSI_PHY_RSTZ        (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PHY_RSTZ        )
#define    DSI_PHY_IF_CFG      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PHY_IF_CFG      )
#define    DSI_PHY_IF_CTRL     (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PHY_IF_CTRL     )
#define    DSI_PHY_STATUS      (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PHY_STATUS      )
#define    DSI_PHY_TST_CTRL0   (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PHY_TST_CTRL0   )
#define    DSI_PHY_TST_CTRL1   (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_PHY_TST_CTRL1   )
#define    MIPI_DPHY_TEST_DSI_CTRL       (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_DPHY_CTRL       )
#define    MIPI_DPHY_TEST_DSI_STATUS     (MIPI_DSI_BASE_ADDR+ OFFSET_DSI_DPHY_STATUS     )
#define    MIPI_DPHY_TEST_CSI2_CTRL0     (MIPI_DSI_BASE_ADDR+ OFFSET_CSI2_DPHY_CTRL0     )
#define    MIPI_DPHY_TEST_CSI2_CTRL1     (MIPI_DSI_BASE_ADDR+ OFFSET_CSI2_DPHY_CTRL1     )
#define    MIPI_DPHY_TEST_CSI2_STATUS     (MIPI_DSI_BASE_ADDR+ OFFSET_CSI2_DPHY_STATUS    )
#define    MIPI_DPHY_TEST_CTRL            (MIPI_DSI_BASE_ADDR+ OFFSET_DPHY_TEST_CTRL      )

typedef struct {
    unsigned short addr;
    unsigned short value;
    unsigned char verify;
    unsigned int delay_us;
} cam_firmware_t;

typedef struct {
    cam_firmware_t *setting;
    int size;
} mipi_cam_mode_t;

enum {
    OV5640_MODE_480X480_15FPS_RGB565,
    OV5640_MODE_VGA_640X480_15FPS_YUV422,
    OV5640_MODE_VGA_640X480_30FPS_YUV422,
};

extern cam_firmware_t ov5640_mipi_480x480_30fps_RGB565_fm[];
extern cam_firmware_t ov5640_mipi_VGA_640x480_15fps_YUV422_fm[];
extern cam_firmware_t ov5640_mipi_VGA_640x480_30fps_YUV422_fm[];

extern mipi_cam_mode_t mipi_cam_modes[];

void mipi_dsi_init(void);
#endif
