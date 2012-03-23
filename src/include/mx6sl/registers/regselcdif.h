/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_ELCDIF_REGISTERS_H__
#define __HW_ELCDIF_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL ELCDIF registers defined in this header file.
 *
 * - HW_ELCDIF_CTRL - eLCDIF General Control Register
 * - HW_ELCDIF_CTRL1 - eLCDIF General Control1 Register
 * - HW_ELCDIF_CTRL2 - eLCDIF General Control2 Register
 * - HW_ELCDIF_TRANSFER_COUNT - eLCDIF Horizontal and Vertical Valid Data Count Register
 * - HW_ELCDIF_CUR_BUF - LCD Interface Current Buffer Address Register
 * - HW_ELCDIF_NEXT_BUF - LCD Interface Next Buffer Address Register
 * - HW_ELCDIF_TIMING - LCD Interface Timing Register
 * - HW_ELCDIF_VDCTRL0 - eLCDIF VSYNC Mode and Dotclk Mode Control Register0
 * - HW_ELCDIF_VDCTRL1 - eLCDIF VSYNC Mode and Dotclk Mode Control Register1
 * - HW_ELCDIF_VDCTRL2 - LCDIF VSYNC Mode and Dotclk Mode Control Register2
 * - HW_ELCDIF_VDCTRL3 - eLCDIF VSYNC Mode and Dotclk Mode Control Register3
 * - HW_ELCDIF_VDCTRL4 - eLCDIF VSYNC Mode and Dotclk Mode Control Register4
 * - HW_ELCDIF_DVICTRL0 - Digital Video Interface Control0 Register
 * - HW_ELCDIF_DVICTRL1 - Digital Video Interface Control1 Register
 * - HW_ELCDIF_DVICTRL2 - Digital Video Interface Control2 Register
 * - HW_ELCDIF_DVICTRL3 - Digital Video Interface Control3 Register
 * - HW_ELCDIF_DVICTRL4 - Digital Video Interface Control4 Register
 * - HW_ELCDIF_CSC_COEFF0 - RGB to YCbCr 4:2:2 CSC Coefficient0 Register
 * - HW_ELCDIF_CSC_COEFF1 - RGB to YCbCr 4:2:2 CSC Coefficient1 Register
 * - HW_ELCDIF_CSC_COEFF2 - RGB to YCbCr 4:2:2 CSC Coefficent2 Register
 * - HW_ELCDIF_CSC_COEFF3 - RGB to YCbCr 4:2:2 CSC Coefficient3 Register
 * - HW_ELCDIF_CSC_COEFF4 - RGB to YCbCr 4:2:2 CSC Coefficient4 Register
 * - HW_ELCDIF_CSC_OFFSET - RGB to YCbCr 4:2:2 CSC Offset Register
 * - HW_ELCDIF_CSC_LIMIT - RGB to YCbCr 4:2:2 CSC Limit Register
 * - HW_ELCDIF_DATA - LCD Interface Data Register
 * - HW_ELCDIF_BM_ERROR_STAT - Bus Master Error Status Register
 * - HW_ELCDIF_CRC_STAT - CRC Status Register
 * - HW_ELCDIF_STAT - LCD Interface Status Register
 * - HW_ELCDIF_VERSION - LCD Interface Version Register
 * - HW_ELCDIF_DEBUG0 - LCD Interface Debug0 Register
 * - HW_ELCDIF_DEBUG1 - LCD Interface Debug1 Register
 * - HW_ELCDIF_DEBUG2 - LCD Interface Debug2 Register
 * - HW_ELCDIF_THRES - eLCDIF Threshold Register
 *
 * - hw_elcdif_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ELCDIF_BASE
#define HW_ELCDIF_INSTANCE_COUNT (1) //!< Number of instances of the ELCDIF module.
#define REGS_ELCDIF_BASE (0x020f8000) //!< Base address for ELCDIF.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CTRL - eLCDIF General Control Register (RW)
 *
 * Reset value: 0xc0000000
 *
 * The LCD Interface Control Register provides overall control of the eLCDIF block. The eLCDIF
 * Control Register provides a variety of control functions to the programmer. These functions allow
 * the interface to be very flexible to work with a variety of LCD controllers, and to minimize
 * overhead and increase performance of LCD programming. The register has been organized such that
 * switching between the different LCD modes can be done with minimum PIO writes.
 */
typedef union _hw_elcdif_ctrl
{
    reg32_t U;
    struct _hw_elcdif_ctrl_bitfields
    {
        unsigned RUN : 1; //!< [0] When this bit is set by software, the eLCDIF will start fetching data in either the DMA mode or the bus master mode and sending it across the interface. This bit must remain set for all the time the block is in operation.
        unsigned DATA_FORMAT_24_BIT : 1; //!< [1] Used only when WORD_LENGTH = 3, i.e. 24-bit. Note that this applies to both packed and unpacked 24-bit data.
        unsigned DATA_FORMAT_18_BIT : 1; //!< [2] Used only when WORD_LENGTH = 2, i.e. 18-bit.
        unsigned DATA_FORMAT_16_BIT : 1; //!< [3] When this bit is 1 and WORD_LENGTH = 0, it implies that the the 16-bit data is in ARGB555 format. When this bit is 0 and WORD_LENGTH = 0, it implies that the 16-bit data is in RGB565 format. When WORD_LENGTH is not 0, this bit is a dont care.
        unsigned RESERVED0 : 1; //!< [4] Reserved bits. Write as 0.
        unsigned MASTER : 1; //!< [5] Set this bit to make the eLCDIF act as a bus master. If this bit is reset, the eLCDIF will act in its traditional DMA slave mode.
        unsigned ENABLE_PXP_HANDSHAKE : 1; //!< [6] If this bit is set and LCDIF_MASTER bit is set, the eLCDIF will act as bus master and the handshake mechanism between eLCDIF and ePXP will be turned on. If LCDIF_MASTER bit is not set, this bit becomes a don't care.
        unsigned RGB_TO_YCBCR422_CSC : 1; //!< [7] Set this bit to 1 to enable conversion from RGB to YCbCr colorspace. See the LCDIF_CSC_ registers for further details.
        unsigned WORD_LENGTH : 2; //!< [9:8] Input data format.
        unsigned LCD_DATABUS_WIDTH : 2; //!< [11:10] LCD Data bus transfer width.
        unsigned CSC_DATA_SWIZZLE : 2; //!< [13:12] This field specifies how to swap the bytes after the data has been converted into an internal representation of 24 bits per pixel and before it is transmitted over the LCD interface bus. The data is always transmitted with the least significant byte/hword (half word) first after the swizzle takes place. So, INPUT_DATA_SWIZZLE takes place first on the incoming data, and then CSC_DATA_SWIZZLE is applied. The swizzle function is independent of the WORD_LENGTH or the LCD_DATABUS_WIDTH fields. If RGB_TO_YCRCB422_CSC bit is set, the swizzle occurs on the Y, Cb, Cr values. The supported swizzle configurations are:
        unsigned INPUT_DATA_SWIZZLE : 2; //!< [15:14] This field specifies how to swap the bytes fetched by the bus master interface. The swizzle function is independent of the WORD_LENGTH bit. The supported swizzle configurations are:
        unsigned DATA_SELECT : 1; //!< [16] Command Mode polarity bit. This bit should only be changed when RUN is 0.
        unsigned DOTCLK_MODE : 1; //!< [17] Set this bit to 1 to make the hardware go into the DOTCLK mode, i.e. VSYNC/HSYNC/DOTCLK/ENABLE interface mode. ENABLE is optional, selected by the ENABLE_PRESENT bit. Toggle this bit from 1 to 0 to make the hardware go out of DOTCLK mode after completing all data transfer and deasserting the RUN bit.
        unsigned VSYNC_MODE : 1; //!< [18] Setting this bit to 1 will make the eLCDIF hardware go into VSYNC mode. WAIT_FOR_VSYNC_EDGE can be used only if this bit is set. If VSYNC signal is required to be an output from the block, SYNC_SIGNALS_ON bit in LCDIF_VDCTRL4 register must be set.
        unsigned BYPASS_COUNT : 1; //!< [19] When this bit is 0, it means that eLCDIF will stop the block operation and turn off the RUN bit after the amount of data indicated by the LCDIF_TRANSFER_COUNT register has been transferred out. When this bit is set to 1, the block will continue normal operation indefinitely until it is told to stop. This bit must be 0 in MPU and VSYNC modes, and must be 1 in DOTCLK and DVI modes of operation.
        unsigned DVI_MODE : 1; //!< [20] Set this bit to 1 to get into theITU-R BT.656 digital video interface mode. Toggle this bit from 1 to 0 to make the hardware go out of DVI mode after completing all data transfer, deasserting the RUN bit and toggling the dma_end_cmd signal.
        unsigned SHIFT_NUM_BITS : 5; //!< [25:21] The data to be transmitted is shifted left or right by this number of bits.
        unsigned DATA_SHIFT_DIR : 1; //!< [26] Use this bit to determine the direction of shift of transmit data. In the DVI mode, it works only on the active data, not on the timing codes and ancillary data.
        unsigned WAIT_FOR_VSYNC_EDGE : 1; //!< [27] Setting this bit to 1 will make the hardware wait for the triggering VSYNC edge before starting write transfers to the LCD. Used only in the VSYNC mode of operation.
        unsigned READ_WRITEB : 1; //!< [28] By default, eLCDIF is in the write mode. Setting this bit to 1 will make the hardware go into 6800/8080 MPU read mode. Make sure that DMA operation is selected (LCDIF_MASTER bit is 0) when performing read operations.
        unsigned YCBCR422_INPUT : 1; //!< [29] Zero implies input data is in RGB color space. One implies input data is in YCbCr 4:2:2 format, such that YCbYCr are packed in a 32-bit word. It also means that there are 2 pixels in 4 bytes. If this bit is set, software should program the H_COUNT field in the TRANSFER_COUNT register to the total number of pixels that will have to be fetched by the eLCDIF block per line and the BYTE_PACKING_FORMAT should be 0xF. The WORD_LENGTH does not matter in this case.
        unsigned CLKGATE : 1; //!< [30] This bit must be set to zero for normal operation. When set to one it gates off the clocks to the block.
        unsigned SFTRST : 1; //!< [31] This bit must be set to zero to enable normal operation of the eLCDIF. When set to one, it forces a block level reset.
    } B;
} hw_elcdif_ctrl_t;
#endif

/*
 * constants & macros for entire ELCDIF_CTRL register
 */
#define HW_ELCDIF_CTRL_ADDR      (REGS_ELCDIF_BASE + 0x0)
#define HW_ELCDIF_CTRL_SET_ADDR  (HW_ELCDIF_CTRL_ADDR + 0x4)
#define HW_ELCDIF_CTRL_CLR_ADDR  (HW_ELCDIF_CTRL_ADDR + 0x8)
#define HW_ELCDIF_CTRL_TOG_ADDR  (HW_ELCDIF_CTRL_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CTRL           (*(volatile hw_elcdif_ctrl_t *) HW_ELCDIF_CTRL_ADDR)
#define HW_ELCDIF_CTRL_RD()      (HW_ELCDIF_CTRL.U)
#define HW_ELCDIF_CTRL_WR(v)     (HW_ELCDIF_CTRL.U = (v))
#define HW_ELCDIF_CTRL_SET(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL_SET_ADDR) = (v))
#define HW_ELCDIF_CTRL_CLR(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL_CLR_ADDR) = (v))
#define HW_ELCDIF_CTRL_TOG(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual ELCDIF_CTRL bitfields
 */

/* --- Register HW_ELCDIF_CTRL, field RUN[0] (RW)
 *
 * When this bit is set by software, the eLCDIF will start fetching data in either the DMA mode or
 * the bus master mode and sending it across the interface. This bit must remain set for all the
 * time the block is in operation.
 */

#define BP_ELCDIF_CTRL_RUN      (0)      //!< Bit position for ELCDIF_CTRL_RUN.
#define BM_ELCDIF_CTRL_RUN      (0x00000001)  //!< Bit mask for ELCDIF_CTRL_RUN.

//! @brief Get value of ELCDIF_CTRL_RUN from a register value.
#define BG_ELCDIF_CTRL_RUN(r)   (((r) & BM_ELCDIF_CTRL_RUN) >> BP_ELCDIF_CTRL_RUN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_RUN.
#define BF_ELCDIF_CTRL_RUN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_RUN) & BM_ELCDIF_CTRL_RUN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_RUN.
#define BF_ELCDIF_CTRL_RUN(v)   (((v) << BP_ELCDIF_CTRL_RUN) & BM_ELCDIF_CTRL_RUN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RUN field to a new value.
#define BW_ELCDIF_CTRL_RUN(v)   BF_CS1(ELCDIF_CTRL, RUN, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field DATA_FORMAT_24_BIT[1] (RW)
 *
 * Used only when WORD_LENGTH = 3, i.e. 24-bit. Note that this applies to both packed and unpacked
 * 24-bit data.
 *
 * Values:
 * ALL_24_BITS_VALID = 0x0 - Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
 * DROP_UPPER_2_BITS_PER_BYTE = 0x1 - Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2
 *     bits in each byte do not contain any useful data, and should be dropped.
 */

#define BP_ELCDIF_CTRL_DATA_FORMAT_24_BIT      (1)      //!< Bit position for ELCDIF_CTRL_DATA_FORMAT_24_BIT.
#define BM_ELCDIF_CTRL_DATA_FORMAT_24_BIT      (0x00000002)  //!< Bit mask for ELCDIF_CTRL_DATA_FORMAT_24_BIT.

//! @brief Get value of ELCDIF_CTRL_DATA_FORMAT_24_BIT from a register value.
#define BG_ELCDIF_CTRL_DATA_FORMAT_24_BIT(r)   (((r) & BM_ELCDIF_CTRL_DATA_FORMAT_24_BIT) >> BP_ELCDIF_CTRL_DATA_FORMAT_24_BIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_FORMAT_24_BIT.
#define BF_ELCDIF_CTRL_DATA_FORMAT_24_BIT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DATA_FORMAT_24_BIT) & BM_ELCDIF_CTRL_DATA_FORMAT_24_BIT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_FORMAT_24_BIT.
#define BF_ELCDIF_CTRL_DATA_FORMAT_24_BIT(v)   (((v) << BP_ELCDIF_CTRL_DATA_FORMAT_24_BIT) & BM_ELCDIF_CTRL_DATA_FORMAT_24_BIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_FORMAT_24_BIT field to a new value.
#define BW_ELCDIF_CTRL_DATA_FORMAT_24_BIT(v)   BF_CS1(ELCDIF_CTRL, DATA_FORMAT_24_BIT, v)
#endif

#define BV_ELCDIF_CTRL_DATA_FORMAT_24_BIT__ALL_24_BITS_VALID (0x0) //!< Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
#define BV_ELCDIF_CTRL_DATA_FORMAT_24_BIT__DROP_UPPER_2_BITS_PER_BYTE (0x1) //!< Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in each byte do not contain any useful data, and should be dropped.

/* --- Register HW_ELCDIF_CTRL, field DATA_FORMAT_18_BIT[2] (RW)
 *
 * Used only when WORD_LENGTH = 2, i.e. 18-bit.
 *
 * Values:
 * LOWER_18_BITS_VALID = 0x0 - Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14
 *     bits do not contain any useful data.
 * UPPER_18_BITS_VALID = 0x1 - Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14
 *     bits do not contain any useful data.
 */

#define BP_ELCDIF_CTRL_DATA_FORMAT_18_BIT      (2)      //!< Bit position for ELCDIF_CTRL_DATA_FORMAT_18_BIT.
#define BM_ELCDIF_CTRL_DATA_FORMAT_18_BIT      (0x00000004)  //!< Bit mask for ELCDIF_CTRL_DATA_FORMAT_18_BIT.

//! @brief Get value of ELCDIF_CTRL_DATA_FORMAT_18_BIT from a register value.
#define BG_ELCDIF_CTRL_DATA_FORMAT_18_BIT(r)   (((r) & BM_ELCDIF_CTRL_DATA_FORMAT_18_BIT) >> BP_ELCDIF_CTRL_DATA_FORMAT_18_BIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_FORMAT_18_BIT.
#define BF_ELCDIF_CTRL_DATA_FORMAT_18_BIT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DATA_FORMAT_18_BIT) & BM_ELCDIF_CTRL_DATA_FORMAT_18_BIT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_FORMAT_18_BIT.
#define BF_ELCDIF_CTRL_DATA_FORMAT_18_BIT(v)   (((v) << BP_ELCDIF_CTRL_DATA_FORMAT_18_BIT) & BM_ELCDIF_CTRL_DATA_FORMAT_18_BIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_FORMAT_18_BIT field to a new value.
#define BW_ELCDIF_CTRL_DATA_FORMAT_18_BIT(v)   BF_CS1(ELCDIF_CTRL, DATA_FORMAT_18_BIT, v)
#endif

#define BV_ELCDIF_CTRL_DATA_FORMAT_18_BIT__LOWER_18_BITS_VALID (0x0) //!< Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits do not contain any useful data.
#define BV_ELCDIF_CTRL_DATA_FORMAT_18_BIT__UPPER_18_BITS_VALID (0x1) //!< Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits do not contain any useful data.

/* --- Register HW_ELCDIF_CTRL, field DATA_FORMAT_16_BIT[3] (RW)
 *
 * When this bit is 1 and WORD_LENGTH = 0, it implies that the the 16-bit data is in ARGB555 format.
 * When this bit is 0 and WORD_LENGTH = 0, it implies that the 16-bit data is in RGB565 format. When
 * WORD_LENGTH is not 0, this bit is a dont care.
 */

#define BP_ELCDIF_CTRL_DATA_FORMAT_16_BIT      (3)      //!< Bit position for ELCDIF_CTRL_DATA_FORMAT_16_BIT.
#define BM_ELCDIF_CTRL_DATA_FORMAT_16_BIT      (0x00000008)  //!< Bit mask for ELCDIF_CTRL_DATA_FORMAT_16_BIT.

//! @brief Get value of ELCDIF_CTRL_DATA_FORMAT_16_BIT from a register value.
#define BG_ELCDIF_CTRL_DATA_FORMAT_16_BIT(r)   (((r) & BM_ELCDIF_CTRL_DATA_FORMAT_16_BIT) >> BP_ELCDIF_CTRL_DATA_FORMAT_16_BIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_FORMAT_16_BIT.
#define BF_ELCDIF_CTRL_DATA_FORMAT_16_BIT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DATA_FORMAT_16_BIT) & BM_ELCDIF_CTRL_DATA_FORMAT_16_BIT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_FORMAT_16_BIT.
#define BF_ELCDIF_CTRL_DATA_FORMAT_16_BIT(v)   (((v) << BP_ELCDIF_CTRL_DATA_FORMAT_16_BIT) & BM_ELCDIF_CTRL_DATA_FORMAT_16_BIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_FORMAT_16_BIT field to a new value.
#define BW_ELCDIF_CTRL_DATA_FORMAT_16_BIT(v)   BF_CS1(ELCDIF_CTRL, DATA_FORMAT_16_BIT, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field MASTER[5] (RW)
 *
 * Set this bit to make the eLCDIF act as a bus master. If this bit is reset, the eLCDIF will act in
 * its traditional DMA slave mode.
 */

#define BP_ELCDIF_CTRL_MASTER      (5)      //!< Bit position for ELCDIF_CTRL_MASTER.
#define BM_ELCDIF_CTRL_MASTER      (0x00000020)  //!< Bit mask for ELCDIF_CTRL_MASTER.

//! @brief Get value of ELCDIF_CTRL_MASTER from a register value.
#define BG_ELCDIF_CTRL_MASTER(r)   (((r) & BM_ELCDIF_CTRL_MASTER) >> BP_ELCDIF_CTRL_MASTER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_MASTER.
#define BF_ELCDIF_CTRL_MASTER(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_MASTER) & BM_ELCDIF_CTRL_MASTER)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_MASTER.
#define BF_ELCDIF_CTRL_MASTER(v)   (((v) << BP_ELCDIF_CTRL_MASTER) & BM_ELCDIF_CTRL_MASTER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASTER field to a new value.
#define BW_ELCDIF_CTRL_MASTER(v)   BF_CS1(ELCDIF_CTRL, MASTER, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field ENABLE_PXP_HANDSHAKE[6] (RW)
 *
 * If this bit is set and LCDIF_MASTER bit is set, the eLCDIF will act as bus master and the
 * handshake mechanism between eLCDIF and ePXP will be turned on. If LCDIF_MASTER bit is not set,
 * this bit becomes a don't care.
 */

#define BP_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE      (6)      //!< Bit position for ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE.
#define BM_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE      (0x00000040)  //!< Bit mask for ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE.

//! @brief Get value of ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE from a register value.
#define BG_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE(r)   (((r) & BM_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE) >> BP_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE.
#define BF_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE) & BM_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE.
#define BF_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE(v)   (((v) << BP_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE) & BM_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PXP_HANDSHAKE field to a new value.
#define BW_ELCDIF_CTRL_ENABLE_PXP_HANDSHAKE(v)   BF_CS1(ELCDIF_CTRL, ENABLE_PXP_HANDSHAKE, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field RGB_TO_YCBCR422_CSC[7] (RW)
 *
 * Set this bit to 1 to enable conversion from RGB to YCbCr colorspace. See the LCDIF_CSC_ registers
 * for further details.
 */

#define BP_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC      (7)      //!< Bit position for ELCDIF_CTRL_RGB_TO_YCBCR422_CSC.
#define BM_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC      (0x00000080)  //!< Bit mask for ELCDIF_CTRL_RGB_TO_YCBCR422_CSC.

//! @brief Get value of ELCDIF_CTRL_RGB_TO_YCBCR422_CSC from a register value.
#define BG_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC(r)   (((r) & BM_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC) >> BP_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_RGB_TO_YCBCR422_CSC.
#define BF_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC) & BM_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_RGB_TO_YCBCR422_CSC.
#define BF_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC(v)   (((v) << BP_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC) & BM_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RGB_TO_YCBCR422_CSC field to a new value.
#define BW_ELCDIF_CTRL_RGB_TO_YCBCR422_CSC(v)   BF_CS1(ELCDIF_CTRL, RGB_TO_YCBCR422_CSC, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field WORD_LENGTH[9:8] (RW)
 *
 * Input data format.
 *
 * Values:
 * 16_BIT = 0x0 - Input data is 16 bits per pixel.
 * 8_BIT = 0x1 - Input data is 8 bits wide.
 * 18_BIT = 0x2 - Input data is 18 bits per pixel.
 * 24_BIT = 0x3 - Input data is 24 bits per pixel.
 */

#define BP_ELCDIF_CTRL_WORD_LENGTH      (8)      //!< Bit position for ELCDIF_CTRL_WORD_LENGTH.
#define BM_ELCDIF_CTRL_WORD_LENGTH      (0x00000300)  //!< Bit mask for ELCDIF_CTRL_WORD_LENGTH.

//! @brief Get value of ELCDIF_CTRL_WORD_LENGTH from a register value.
#define BG_ELCDIF_CTRL_WORD_LENGTH(r)   (((r) & BM_ELCDIF_CTRL_WORD_LENGTH) >> BP_ELCDIF_CTRL_WORD_LENGTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_WORD_LENGTH.
#define BF_ELCDIF_CTRL_WORD_LENGTH(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_WORD_LENGTH) & BM_ELCDIF_CTRL_WORD_LENGTH)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_WORD_LENGTH.
#define BF_ELCDIF_CTRL_WORD_LENGTH(v)   (((v) << BP_ELCDIF_CTRL_WORD_LENGTH) & BM_ELCDIF_CTRL_WORD_LENGTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WORD_LENGTH field to a new value.
#define BW_ELCDIF_CTRL_WORD_LENGTH(v)   BF_CS1(ELCDIF_CTRL, WORD_LENGTH, v)
#endif

#define BV_ELCDIF_CTRL_WORD_LENGTH__16_BIT (0x0) //!< Input data is 16 bits per pixel.
#define BV_ELCDIF_CTRL_WORD_LENGTH__8_BIT (0x1) //!< Input data is 8 bits wide.
#define BV_ELCDIF_CTRL_WORD_LENGTH__18_BIT (0x2) //!< Input data is 18 bits per pixel.
#define BV_ELCDIF_CTRL_WORD_LENGTH__24_BIT (0x3) //!< Input data is 24 bits per pixel.

/* --- Register HW_ELCDIF_CTRL, field LCD_DATABUS_WIDTH[11:10] (RW)
 *
 * LCD Data bus transfer width.
 *
 * Values:
 * 16_BIT = 0x0 - 16-bit data bus mode.
 * 8_BIT = 0x1 - 8-bit data bus mode.
 * 18_BIT = 0x2 - 18-bit data bus mode.
 * 24_BIT = 0x3 - 24-bit data bus mode.
 */

#define BP_ELCDIF_CTRL_LCD_DATABUS_WIDTH      (10)      //!< Bit position for ELCDIF_CTRL_LCD_DATABUS_WIDTH.
#define BM_ELCDIF_CTRL_LCD_DATABUS_WIDTH      (0x00000c00)  //!< Bit mask for ELCDIF_CTRL_LCD_DATABUS_WIDTH.

//! @brief Get value of ELCDIF_CTRL_LCD_DATABUS_WIDTH from a register value.
#define BG_ELCDIF_CTRL_LCD_DATABUS_WIDTH(r)   (((r) & BM_ELCDIF_CTRL_LCD_DATABUS_WIDTH) >> BP_ELCDIF_CTRL_LCD_DATABUS_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_LCD_DATABUS_WIDTH.
#define BF_ELCDIF_CTRL_LCD_DATABUS_WIDTH(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_LCD_DATABUS_WIDTH) & BM_ELCDIF_CTRL_LCD_DATABUS_WIDTH)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_LCD_DATABUS_WIDTH.
#define BF_ELCDIF_CTRL_LCD_DATABUS_WIDTH(v)   (((v) << BP_ELCDIF_CTRL_LCD_DATABUS_WIDTH) & BM_ELCDIF_CTRL_LCD_DATABUS_WIDTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LCD_DATABUS_WIDTH field to a new value.
#define BW_ELCDIF_CTRL_LCD_DATABUS_WIDTH(v)   BF_CS1(ELCDIF_CTRL, LCD_DATABUS_WIDTH, v)
#endif

#define BV_ELCDIF_CTRL_LCD_DATABUS_WIDTH__16_BIT (0x0) //!< 16-bit data bus mode.
#define BV_ELCDIF_CTRL_LCD_DATABUS_WIDTH__8_BIT (0x1) //!< 8-bit data bus mode.
#define BV_ELCDIF_CTRL_LCD_DATABUS_WIDTH__18_BIT (0x2) //!< 18-bit data bus mode.
#define BV_ELCDIF_CTRL_LCD_DATABUS_WIDTH__24_BIT (0x3) //!< 24-bit data bus mode.

/* --- Register HW_ELCDIF_CTRL, field CSC_DATA_SWIZZLE[13:12] (RW)
 *
 * This field specifies how to swap the bytes after the data has been converted into an internal
 * representation of 24 bits per pixel and before it is transmitted over the LCD interface bus. The
 * data is always transmitted with the least significant byte/hword (half word) first after the
 * swizzle takes place. So, INPUT_DATA_SWIZZLE takes place first on the incoming data, and then
 * CSC_DATA_SWIZZLE is applied. The swizzle function is independent of the WORD_LENGTH or the
 * LCD_DATABUS_WIDTH fields. If RGB_TO_YCRCB422_CSC bit is set, the swizzle occurs on the Y, Cb, Cr
 * values. The supported swizzle configurations are:
 *
 * Values:
 * NO_SWAP = 0x0 - No byte swapping.(Little endian)
 * LITTLE_ENDIAN = 0x0 - Little Endian byte ordering (same as NO_SWAP).
 * BIG_ENDIAN_SWAP = 0x1 - Big Endian swap (swap bytes 0,3 and 1,2).
 * SWAP_ALL_BYTES = 0x1 - Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 * HWD_SWAP = 0x2 - Swap half-words.
 * HWD_BYTE_SWAP = 0x3 - Swap bytes within each half-word.
 */

#define BP_ELCDIF_CTRL_CSC_DATA_SWIZZLE      (12)      //!< Bit position for ELCDIF_CTRL_CSC_DATA_SWIZZLE.
#define BM_ELCDIF_CTRL_CSC_DATA_SWIZZLE      (0x00003000)  //!< Bit mask for ELCDIF_CTRL_CSC_DATA_SWIZZLE.

//! @brief Get value of ELCDIF_CTRL_CSC_DATA_SWIZZLE from a register value.
#define BG_ELCDIF_CTRL_CSC_DATA_SWIZZLE(r)   (((r) & BM_ELCDIF_CTRL_CSC_DATA_SWIZZLE) >> BP_ELCDIF_CTRL_CSC_DATA_SWIZZLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_CSC_DATA_SWIZZLE.
#define BF_ELCDIF_CTRL_CSC_DATA_SWIZZLE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_CSC_DATA_SWIZZLE) & BM_ELCDIF_CTRL_CSC_DATA_SWIZZLE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_CSC_DATA_SWIZZLE.
#define BF_ELCDIF_CTRL_CSC_DATA_SWIZZLE(v)   (((v) << BP_ELCDIF_CTRL_CSC_DATA_SWIZZLE) & BM_ELCDIF_CTRL_CSC_DATA_SWIZZLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_DATA_SWIZZLE field to a new value.
#define BW_ELCDIF_CTRL_CSC_DATA_SWIZZLE(v)   BF_CS1(ELCDIF_CTRL, CSC_DATA_SWIZZLE, v)
#endif

#define BV_ELCDIF_CTRL_CSC_DATA_SWIZZLE__NO_SWAP (0x0) //!< No byte swapping.(Little endian)
#define BV_ELCDIF_CTRL_CSC_DATA_SWIZZLE__LITTLE_ENDIAN (0x0) //!< Little Endian byte ordering (same as NO_SWAP).
#define BV_ELCDIF_CTRL_CSC_DATA_SWIZZLE__BIG_ENDIAN_SWAP (0x1) //!< Big Endian swap (swap bytes 0,3 and 1,2).
#define BV_ELCDIF_CTRL_CSC_DATA_SWIZZLE__SWAP_ALL_BYTES (0x1) //!< Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
#define BV_ELCDIF_CTRL_CSC_DATA_SWIZZLE__HWD_SWAP (0x2) //!< Swap half-words.
#define BV_ELCDIF_CTRL_CSC_DATA_SWIZZLE__HWD_BYTE_SWAP (0x3) //!< Swap bytes within each half-word.

/* --- Register HW_ELCDIF_CTRL, field INPUT_DATA_SWIZZLE[15:14] (RW)
 *
 * This field specifies how to swap the bytes fetched by the bus master interface. The swizzle
 * function is independent of the WORD_LENGTH bit. The supported swizzle configurations are:
 *
 * Values:
 * NO_SWAP = 0x0 - No byte swapping.(Little endian)
 * LITTLE_ENDIAN = 0x0 - Little Endian byte ordering (same as NO_SWAP).
 * BIG_ENDIAN_SWAP = 0x1 - Big Endian swap (swap bytes 0,3 and 1,2).
 * SWAP_ALL_BYTES = 0x1 - Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 * HWD_SWAP = 0x2 - Swap half-words.
 * HWD_BYTE_SWAP = 0x3 - Swap bytes within each half-word.
 */

#define BP_ELCDIF_CTRL_INPUT_DATA_SWIZZLE      (14)      //!< Bit position for ELCDIF_CTRL_INPUT_DATA_SWIZZLE.
#define BM_ELCDIF_CTRL_INPUT_DATA_SWIZZLE      (0x0000c000)  //!< Bit mask for ELCDIF_CTRL_INPUT_DATA_SWIZZLE.

//! @brief Get value of ELCDIF_CTRL_INPUT_DATA_SWIZZLE from a register value.
#define BG_ELCDIF_CTRL_INPUT_DATA_SWIZZLE(r)   (((r) & BM_ELCDIF_CTRL_INPUT_DATA_SWIZZLE) >> BP_ELCDIF_CTRL_INPUT_DATA_SWIZZLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_INPUT_DATA_SWIZZLE.
#define BF_ELCDIF_CTRL_INPUT_DATA_SWIZZLE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_INPUT_DATA_SWIZZLE) & BM_ELCDIF_CTRL_INPUT_DATA_SWIZZLE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_INPUT_DATA_SWIZZLE.
#define BF_ELCDIF_CTRL_INPUT_DATA_SWIZZLE(v)   (((v) << BP_ELCDIF_CTRL_INPUT_DATA_SWIZZLE) & BM_ELCDIF_CTRL_INPUT_DATA_SWIZZLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INPUT_DATA_SWIZZLE field to a new value.
#define BW_ELCDIF_CTRL_INPUT_DATA_SWIZZLE(v)   BF_CS1(ELCDIF_CTRL, INPUT_DATA_SWIZZLE, v)
#endif

#define BV_ELCDIF_CTRL_INPUT_DATA_SWIZZLE__NO_SWAP (0x0) //!< No byte swapping.(Little endian)
#define BV_ELCDIF_CTRL_INPUT_DATA_SWIZZLE__LITTLE_ENDIAN (0x0) //!< Little Endian byte ordering (same as NO_SWAP).
#define BV_ELCDIF_CTRL_INPUT_DATA_SWIZZLE__BIG_ENDIAN_SWAP (0x1) //!< Big Endian swap (swap bytes 0,3 and 1,2).
#define BV_ELCDIF_CTRL_INPUT_DATA_SWIZZLE__SWAP_ALL_BYTES (0x1) //!< Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
#define BV_ELCDIF_CTRL_INPUT_DATA_SWIZZLE__HWD_SWAP (0x2) //!< Swap half-words.
#define BV_ELCDIF_CTRL_INPUT_DATA_SWIZZLE__HWD_BYTE_SWAP (0x3) //!< Swap bytes within each half-word.

/* --- Register HW_ELCDIF_CTRL, field DATA_SELECT[16] (RW)
 *
 * Command Mode polarity bit. This bit should only be changed when RUN is 0.
 *
 * Values:
 * CMD_MODE = 0x0 - Command Mode. DCn signal is Low.
 * DATA_MODE = 0x1 - Data Mode. DCn signal is High.
 */

#define BP_ELCDIF_CTRL_DATA_SELECT      (16)      //!< Bit position for ELCDIF_CTRL_DATA_SELECT.
#define BM_ELCDIF_CTRL_DATA_SELECT      (0x00010000)  //!< Bit mask for ELCDIF_CTRL_DATA_SELECT.

//! @brief Get value of ELCDIF_CTRL_DATA_SELECT from a register value.
#define BG_ELCDIF_CTRL_DATA_SELECT(r)   (((r) & BM_ELCDIF_CTRL_DATA_SELECT) >> BP_ELCDIF_CTRL_DATA_SELECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_SELECT.
#define BF_ELCDIF_CTRL_DATA_SELECT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DATA_SELECT) & BM_ELCDIF_CTRL_DATA_SELECT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_SELECT.
#define BF_ELCDIF_CTRL_DATA_SELECT(v)   (((v) << BP_ELCDIF_CTRL_DATA_SELECT) & BM_ELCDIF_CTRL_DATA_SELECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_SELECT field to a new value.
#define BW_ELCDIF_CTRL_DATA_SELECT(v)   BF_CS1(ELCDIF_CTRL, DATA_SELECT, v)
#endif

#define BV_ELCDIF_CTRL_DATA_SELECT__CMD_MODE (0x0) //!< Command Mode. DCn signal is Low.
#define BV_ELCDIF_CTRL_DATA_SELECT__DATA_MODE (0x1) //!< Data Mode. DCn signal is High.

/* --- Register HW_ELCDIF_CTRL, field DOTCLK_MODE[17] (RW)
 *
 * Set this bit to 1 to make the hardware go into the DOTCLK mode, i.e. VSYNC/HSYNC/DOTCLK/ENABLE
 * interface mode. ENABLE is optional, selected by the ENABLE_PRESENT bit. Toggle this bit from 1 to
 * 0 to make the hardware go out of DOTCLK mode after completing all data transfer and deasserting
 * the RUN bit.
 */

#define BP_ELCDIF_CTRL_DOTCLK_MODE      (17)      //!< Bit position for ELCDIF_CTRL_DOTCLK_MODE.
#define BM_ELCDIF_CTRL_DOTCLK_MODE      (0x00020000)  //!< Bit mask for ELCDIF_CTRL_DOTCLK_MODE.

//! @brief Get value of ELCDIF_CTRL_DOTCLK_MODE from a register value.
#define BG_ELCDIF_CTRL_DOTCLK_MODE(r)   (((r) & BM_ELCDIF_CTRL_DOTCLK_MODE) >> BP_ELCDIF_CTRL_DOTCLK_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DOTCLK_MODE.
#define BF_ELCDIF_CTRL_DOTCLK_MODE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DOTCLK_MODE) & BM_ELCDIF_CTRL_DOTCLK_MODE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DOTCLK_MODE.
#define BF_ELCDIF_CTRL_DOTCLK_MODE(v)   (((v) << BP_ELCDIF_CTRL_DOTCLK_MODE) & BM_ELCDIF_CTRL_DOTCLK_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOTCLK_MODE field to a new value.
#define BW_ELCDIF_CTRL_DOTCLK_MODE(v)   BF_CS1(ELCDIF_CTRL, DOTCLK_MODE, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field VSYNC_MODE[18] (RW)
 *
 * Setting this bit to 1 will make the eLCDIF hardware go into VSYNC mode. WAIT_FOR_VSYNC_EDGE can
 * be used only if this bit is set. If VSYNC signal is required to be an output from the block,
 * SYNC_SIGNALS_ON bit in LCDIF_VDCTRL4 register must be set.
 */

#define BP_ELCDIF_CTRL_VSYNC_MODE      (18)      //!< Bit position for ELCDIF_CTRL_VSYNC_MODE.
#define BM_ELCDIF_CTRL_VSYNC_MODE      (0x00040000)  //!< Bit mask for ELCDIF_CTRL_VSYNC_MODE.

//! @brief Get value of ELCDIF_CTRL_VSYNC_MODE from a register value.
#define BG_ELCDIF_CTRL_VSYNC_MODE(r)   (((r) & BM_ELCDIF_CTRL_VSYNC_MODE) >> BP_ELCDIF_CTRL_VSYNC_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_VSYNC_MODE.
#define BF_ELCDIF_CTRL_VSYNC_MODE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_VSYNC_MODE) & BM_ELCDIF_CTRL_VSYNC_MODE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_VSYNC_MODE.
#define BF_ELCDIF_CTRL_VSYNC_MODE(v)   (((v) << BP_ELCDIF_CTRL_VSYNC_MODE) & BM_ELCDIF_CTRL_VSYNC_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_MODE field to a new value.
#define BW_ELCDIF_CTRL_VSYNC_MODE(v)   BF_CS1(ELCDIF_CTRL, VSYNC_MODE, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field BYPASS_COUNT[19] (RW)
 *
 * When this bit is 0, it means that eLCDIF will stop the block operation and turn off the RUN bit
 * after the amount of data indicated by the LCDIF_TRANSFER_COUNT register has been transferred out.
 * When this bit is set to 1, the block will continue normal operation indefinitely until it is told
 * to stop. This bit must be 0 in MPU and VSYNC modes, and must be 1 in DOTCLK and DVI modes of
 * operation.
 */

#define BP_ELCDIF_CTRL_BYPASS_COUNT      (19)      //!< Bit position for ELCDIF_CTRL_BYPASS_COUNT.
#define BM_ELCDIF_CTRL_BYPASS_COUNT      (0x00080000)  //!< Bit mask for ELCDIF_CTRL_BYPASS_COUNT.

//! @brief Get value of ELCDIF_CTRL_BYPASS_COUNT from a register value.
#define BG_ELCDIF_CTRL_BYPASS_COUNT(r)   (((r) & BM_ELCDIF_CTRL_BYPASS_COUNT) >> BP_ELCDIF_CTRL_BYPASS_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_BYPASS_COUNT.
#define BF_ELCDIF_CTRL_BYPASS_COUNT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_BYPASS_COUNT) & BM_ELCDIF_CTRL_BYPASS_COUNT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_BYPASS_COUNT.
#define BF_ELCDIF_CTRL_BYPASS_COUNT(v)   (((v) << BP_ELCDIF_CTRL_BYPASS_COUNT) & BM_ELCDIF_CTRL_BYPASS_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYPASS_COUNT field to a new value.
#define BW_ELCDIF_CTRL_BYPASS_COUNT(v)   BF_CS1(ELCDIF_CTRL, BYPASS_COUNT, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field DVI_MODE[20] (RW)
 *
 * Set this bit to 1 to get into theITU-R BT.656 digital video interface mode. Toggle this bit from
 * 1 to 0 to make the hardware go out of DVI mode after completing all data transfer, deasserting
 * the RUN bit and toggling the dma_end_cmd signal.
 */

#define BP_ELCDIF_CTRL_DVI_MODE      (20)      //!< Bit position for ELCDIF_CTRL_DVI_MODE.
#define BM_ELCDIF_CTRL_DVI_MODE      (0x00100000)  //!< Bit mask for ELCDIF_CTRL_DVI_MODE.

//! @brief Get value of ELCDIF_CTRL_DVI_MODE from a register value.
#define BG_ELCDIF_CTRL_DVI_MODE(r)   (((r) & BM_ELCDIF_CTRL_DVI_MODE) >> BP_ELCDIF_CTRL_DVI_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DVI_MODE.
#define BF_ELCDIF_CTRL_DVI_MODE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DVI_MODE) & BM_ELCDIF_CTRL_DVI_MODE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DVI_MODE.
#define BF_ELCDIF_CTRL_DVI_MODE(v)   (((v) << BP_ELCDIF_CTRL_DVI_MODE) & BM_ELCDIF_CTRL_DVI_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DVI_MODE field to a new value.
#define BW_ELCDIF_CTRL_DVI_MODE(v)   BF_CS1(ELCDIF_CTRL, DVI_MODE, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field SHIFT_NUM_BITS[25:21] (RW)
 *
 * The data to be transmitted is shifted left or right by this number of bits.
 */

#define BP_ELCDIF_CTRL_SHIFT_NUM_BITS      (21)      //!< Bit position for ELCDIF_CTRL_SHIFT_NUM_BITS.
#define BM_ELCDIF_CTRL_SHIFT_NUM_BITS      (0x03e00000)  //!< Bit mask for ELCDIF_CTRL_SHIFT_NUM_BITS.

//! @brief Get value of ELCDIF_CTRL_SHIFT_NUM_BITS from a register value.
#define BG_ELCDIF_CTRL_SHIFT_NUM_BITS(r)   (((r) & BM_ELCDIF_CTRL_SHIFT_NUM_BITS) >> BP_ELCDIF_CTRL_SHIFT_NUM_BITS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_SHIFT_NUM_BITS.
#define BF_ELCDIF_CTRL_SHIFT_NUM_BITS(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_SHIFT_NUM_BITS) & BM_ELCDIF_CTRL_SHIFT_NUM_BITS)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_SHIFT_NUM_BITS.
#define BF_ELCDIF_CTRL_SHIFT_NUM_BITS(v)   (((v) << BP_ELCDIF_CTRL_SHIFT_NUM_BITS) & BM_ELCDIF_CTRL_SHIFT_NUM_BITS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SHIFT_NUM_BITS field to a new value.
#define BW_ELCDIF_CTRL_SHIFT_NUM_BITS(v)   BF_CS1(ELCDIF_CTRL, SHIFT_NUM_BITS, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field DATA_SHIFT_DIR[26] (RW)
 *
 * Use this bit to determine the direction of shift of transmit data. In the DVI mode, it works only
 * on the active data, not on the timing codes and ancillary data.
 *
 * Values:
 * TXDATA_SHIFT_LEFT = 0x0 - Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
 * TXDATA_SHIFT_RIGHT = 0x1 - Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
 */

#define BP_ELCDIF_CTRL_DATA_SHIFT_DIR      (26)      //!< Bit position for ELCDIF_CTRL_DATA_SHIFT_DIR.
#define BM_ELCDIF_CTRL_DATA_SHIFT_DIR      (0x04000000)  //!< Bit mask for ELCDIF_CTRL_DATA_SHIFT_DIR.

//! @brief Get value of ELCDIF_CTRL_DATA_SHIFT_DIR from a register value.
#define BG_ELCDIF_CTRL_DATA_SHIFT_DIR(r)   (((r) & BM_ELCDIF_CTRL_DATA_SHIFT_DIR) >> BP_ELCDIF_CTRL_DATA_SHIFT_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_SHIFT_DIR.
#define BF_ELCDIF_CTRL_DATA_SHIFT_DIR(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_DATA_SHIFT_DIR) & BM_ELCDIF_CTRL_DATA_SHIFT_DIR)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_DATA_SHIFT_DIR.
#define BF_ELCDIF_CTRL_DATA_SHIFT_DIR(v)   (((v) << BP_ELCDIF_CTRL_DATA_SHIFT_DIR) & BM_ELCDIF_CTRL_DATA_SHIFT_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_SHIFT_DIR field to a new value.
#define BW_ELCDIF_CTRL_DATA_SHIFT_DIR(v)   BF_CS1(ELCDIF_CTRL, DATA_SHIFT_DIR, v)
#endif

#define BV_ELCDIF_CTRL_DATA_SHIFT_DIR__TXDATA_SHIFT_LEFT (0x0) //!< Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
#define BV_ELCDIF_CTRL_DATA_SHIFT_DIR__TXDATA_SHIFT_RIGHT (0x1) //!< Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.

/* --- Register HW_ELCDIF_CTRL, field WAIT_FOR_VSYNC_EDGE[27] (RW)
 *
 * Setting this bit to 1 will make the hardware wait for the triggering VSYNC edge before starting
 * write transfers to the LCD. Used only in the VSYNC mode of operation.
 */

#define BP_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE      (27)      //!< Bit position for ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE.
#define BM_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE      (0x08000000)  //!< Bit mask for ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE.

//! @brief Get value of ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE from a register value.
#define BG_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE(r)   (((r) & BM_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE) >> BP_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE.
#define BF_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE) & BM_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE.
#define BF_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE(v)   (((v) << BP_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE) & BM_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAIT_FOR_VSYNC_EDGE field to a new value.
#define BW_ELCDIF_CTRL_WAIT_FOR_VSYNC_EDGE(v)   BF_CS1(ELCDIF_CTRL, WAIT_FOR_VSYNC_EDGE, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field READ_WRITEB[28] (RW)
 *
 * By default, eLCDIF is in the write mode. Setting this bit to 1 will make the hardware go into
 * 6800/8080 MPU read mode. Make sure that DMA operation is selected (LCDIF_MASTER bit is 0) when
 * performing read operations.
 */

#define BP_ELCDIF_CTRL_READ_WRITEB      (28)      //!< Bit position for ELCDIF_CTRL_READ_WRITEB.
#define BM_ELCDIF_CTRL_READ_WRITEB      (0x10000000)  //!< Bit mask for ELCDIF_CTRL_READ_WRITEB.

//! @brief Get value of ELCDIF_CTRL_READ_WRITEB from a register value.
#define BG_ELCDIF_CTRL_READ_WRITEB(r)   (((r) & BM_ELCDIF_CTRL_READ_WRITEB) >> BP_ELCDIF_CTRL_READ_WRITEB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_READ_WRITEB.
#define BF_ELCDIF_CTRL_READ_WRITEB(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_READ_WRITEB) & BM_ELCDIF_CTRL_READ_WRITEB)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_READ_WRITEB.
#define BF_ELCDIF_CTRL_READ_WRITEB(v)   (((v) << BP_ELCDIF_CTRL_READ_WRITEB) & BM_ELCDIF_CTRL_READ_WRITEB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the READ_WRITEB field to a new value.
#define BW_ELCDIF_CTRL_READ_WRITEB(v)   BF_CS1(ELCDIF_CTRL, READ_WRITEB, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field YCBCR422_INPUT[29] (RW)
 *
 * Zero implies input data is in RGB color space. One implies input data is in YCbCr 4:2:2 format,
 * such that YCbYCr are packed in a 32-bit word. It also means that there are 2 pixels in 4 bytes.
 * If this bit is set, software should program the H_COUNT field in the TRANSFER_COUNT register to
 * the total number of pixels that will have to be fetched by the eLCDIF block per line and the
 * BYTE_PACKING_FORMAT should be 0xF. The WORD_LENGTH does not matter in this case.
 */

#define BP_ELCDIF_CTRL_YCBCR422_INPUT      (29)      //!< Bit position for ELCDIF_CTRL_YCBCR422_INPUT.
#define BM_ELCDIF_CTRL_YCBCR422_INPUT      (0x20000000)  //!< Bit mask for ELCDIF_CTRL_YCBCR422_INPUT.

//! @brief Get value of ELCDIF_CTRL_YCBCR422_INPUT from a register value.
#define BG_ELCDIF_CTRL_YCBCR422_INPUT(r)   (((r) & BM_ELCDIF_CTRL_YCBCR422_INPUT) >> BP_ELCDIF_CTRL_YCBCR422_INPUT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_YCBCR422_INPUT.
#define BF_ELCDIF_CTRL_YCBCR422_INPUT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_YCBCR422_INPUT) & BM_ELCDIF_CTRL_YCBCR422_INPUT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_YCBCR422_INPUT.
#define BF_ELCDIF_CTRL_YCBCR422_INPUT(v)   (((v) << BP_ELCDIF_CTRL_YCBCR422_INPUT) & BM_ELCDIF_CTRL_YCBCR422_INPUT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the YCBCR422_INPUT field to a new value.
#define BW_ELCDIF_CTRL_YCBCR422_INPUT(v)   BF_CS1(ELCDIF_CTRL, YCBCR422_INPUT, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field CLKGATE[30] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one it gates off the clocks to the
 * block.
 */

#define BP_ELCDIF_CTRL_CLKGATE      (30)      //!< Bit position for ELCDIF_CTRL_CLKGATE.
#define BM_ELCDIF_CTRL_CLKGATE      (0x40000000)  //!< Bit mask for ELCDIF_CTRL_CLKGATE.

//! @brief Get value of ELCDIF_CTRL_CLKGATE from a register value.
#define BG_ELCDIF_CTRL_CLKGATE(r)   (((r) & BM_ELCDIF_CTRL_CLKGATE) >> BP_ELCDIF_CTRL_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_CLKGATE.
#define BF_ELCDIF_CTRL_CLKGATE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_CLKGATE) & BM_ELCDIF_CTRL_CLKGATE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_CLKGATE.
#define BF_ELCDIF_CTRL_CLKGATE(v)   (((v) << BP_ELCDIF_CTRL_CLKGATE) & BM_ELCDIF_CTRL_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_ELCDIF_CTRL_CLKGATE(v)   BF_CS1(ELCDIF_CTRL, CLKGATE, v)
#endif

/* --- Register HW_ELCDIF_CTRL, field SFTRST[31] (RW)
 *
 * This bit must be set to zero to enable normal operation of the eLCDIF. When set to one, it forces
 * a block level reset.
 */

#define BP_ELCDIF_CTRL_SFTRST      (31)      //!< Bit position for ELCDIF_CTRL_SFTRST.
#define BM_ELCDIF_CTRL_SFTRST      (0x80000000)  //!< Bit mask for ELCDIF_CTRL_SFTRST.

//! @brief Get value of ELCDIF_CTRL_SFTRST from a register value.
#define BG_ELCDIF_CTRL_SFTRST(r)   (((r) & BM_ELCDIF_CTRL_SFTRST) >> BP_ELCDIF_CTRL_SFTRST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL_SFTRST.
#define BF_ELCDIF_CTRL_SFTRST(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL_SFTRST) & BM_ELCDIF_CTRL_SFTRST)
#else
//! @brief Format value for bitfield ELCDIF_CTRL_SFTRST.
#define BF_ELCDIF_CTRL_SFTRST(v)   (((v) << BP_ELCDIF_CTRL_SFTRST) & BM_ELCDIF_CTRL_SFTRST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_ELCDIF_CTRL_SFTRST(v)   BF_CS1(ELCDIF_CTRL, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CTRL1 - eLCDIF General Control1 Register (RW)
 *
 * Reset value: 0x000f0000
 *
 * The eLCDIF Control Register provides overall control of the eLCDIF block.  The eLCDIF Control1
 * Register provides additional programming to the eLCDIF. It implements some bits which are
 * unlikely to change often in a particular application. It also carries interrupt-related bits
 * which are common across more than one mode of operation.
 */
typedef union _hw_elcdif_ctrl1
{
    reg32_t U;
    struct _hw_elcdif_ctrl1_bitfields
    {
        unsigned RESET : 1; //!< [0] Reset bit for the external LCD controller. This bit can be changed at any time. It CANNOT be reset by SFTRST.
        unsigned MODE86 : 1; //!< [1] This bit is used to select between the 8080 and 6800 series of microprocessor modes. This bit should only be changed when RUN is 0.
        unsigned BUSY_ENABLE : 1; //!< [2] This bit enables the use of the interface's busy signal input. This should be enabled for LCD controllers that implement a busy line (to stall the eLCDIF from sending more data until ready). Otherwise this bit should be cleared.
        unsigned RESERVED0 : 5; //!< [7:3] Reserved bits. Write as 0.
        unsigned VSYNC_EDGE_IRQ : 1; //!< [8] This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is cleared by software by writing a one to its SCT clear address. It is set whenever the leading VSYNC edge is detected in the VSYNC and DOTCLK modes. In the DVI mode, it is asserted every time the block enters a new field.
        unsigned CUR_FRAME_DONE_IRQ : 1; //!< [9] This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is cleared by software by writing a one to its SCT clear address. It indicates that the hardware has completed transmitting the current frame and is in the vertical blanking period in the DOTCLK/DVI modes. In the MPU and VSYNC modes, this IRQ is asserted at the end of the data transfer indicated by LCDIF_TRANSFER_COUNT register.
        unsigned UNDERFLOW_IRQ : 1; //!< [10] This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is cleared by software by writing a one to its SCT clear address. A TXFIFO underflow in the write mode (MPU/VSYNC/DOTCLK/DVI mode) was detected. Could produce an error in the DOTCLK / DVI modes.
        unsigned OVERFLOW_IRQ : 1; //!< [11] This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is cleared by software by writing a one to its SCT clear address. A latency FIFO (LFIFO) overflow in the write mode (MPU/VSYNC/DOTCLK/DVI mode) was detected, data samples have been lost.
        unsigned VSYNC_EDGE_IRQ_EN : 1; //!< [12] This bit is set to enable an interrupt every time the hardware encounters the leading VSYNC edge in the VSYNC and DOTCLK modes, or the beginning of every field in DVI mode.
        unsigned CUR_FRAME_DONE_IRQ_EN : 1; //!< [13] This bit is set to 1 enable an interrupt every time the hardware enters in the vertical blanking state.
        unsigned UNDERFLOW_IRQ_EN : 1; //!< [14] This bit is set to enable an underflow interrupt in the TXFIFO in the write mode.
        unsigned OVERFLOW_IRQ_EN : 1; //!< [15] This bit is set to enable an overflow interrupt in the TXFIFO in the write mode.
        unsigned BYTE_PACKING_FORMAT : 4; //!< [19:16] This bitfield is used to show which data bytes in a 32-bit word are valid. Default value 0xf indicates that all bytes are valid. For 8-bit transfers, any combination in this bitfield will mean valid data is present in the corresponding bytes. In the 16-bit mode, a 16-bit half-word is valid only if adjacent bits [1:0] or [3:2] or both are 1. A value of 0x0 will mean that none of the bytes are valid and should not be used. For example, set the bit field value to 0x7 if the display data is arranged in the 24-bit unpacked format (A-R-G-B where A value does not have be transmitted). When input data is in YCbCr 4:2:2 format (YCBCR422_INPUT is 1), H_COUNT should be the number of pixels that should be fetched by the block and the BYTE_PACKING_FORMAT should be 0xF.(Note - YCBCR422_INPUT = 1 implies 2 pixels per 32 bits).
        unsigned IRQ_ON_ALTERNATE_FIELDS : 1; //!< [20] If this bit is set, the eLCDIF block will assert the cur_frame_done interrupt only on alternate fields, otherwise it will issue the interrupt on both odd and even field. This bit is mostly relevant if INTERLACE_FIELDS is set. This feature is only available in DOTCLK and DVI modes.
        unsigned FIFO_CLEAR : 1; //!< [21] Set this bit to clear all the data in the latency FIFO (LFIFO), TXFIFO and the RXFIFO.
        unsigned START_INTERLACE_FROM_SECOND_FIELD : 1; //!< [22] The default is to grab the odd lines first and then the even lines. Set this bit if it is required to grab the even lines first and then the odd lines. (Line numbers start from 1, so odd lines are 1,3,5,etc. and even lines are 2,4,6, etc.)
        unsigned INTERLACE_FIELDS : 1; //!< [23] Set this bit if it is required that the eLCDIF block fetches odd lines in one field and even lines in the other field. It will work only in LCDIF_MASTER is set to 1.
        unsigned RECOVER_ON_UNDERFLOW : 1; //!< [24] Set this bit to enable the eLCDIF block to recover in the next field/frame if there was an underflow in the current field/frame.
        unsigned BM_ERROR_IRQ : 1; //!< [25] This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is cleared by software by writing a one to its SCT clear address. This bit will be set when the eLCDIF is in master mode and an error response was returned by the slave.
        unsigned BM_ERROR_IRQ_EN : 1; //!< [26] This bit is set to enable bus master error interrupt in the eLCDIF master mode.
        unsigned COMBINE_MPU_WR_STRB : 1; //!< [27] If this bit is not set, the write strobe will be driven on LCD_WR_RWn pin in the 8080 mode and on the LCD_RD_E pin in the 6800 mode. If it is set, the write strobe of both the 6800 and 8080 modes will be driven only on the LCD_WR_RWn pin. Note that this does not work for read strobe.
        unsigned RESERVED1 : 4; //!< [31:28] Reserved bits. Write as 0.
    } B;
} hw_elcdif_ctrl1_t;
#endif

/*
 * constants & macros for entire ELCDIF_CTRL1 register
 */
#define HW_ELCDIF_CTRL1_ADDR      (REGS_ELCDIF_BASE + 0x10)
#define HW_ELCDIF_CTRL1_SET_ADDR  (HW_ELCDIF_CTRL1_ADDR + 0x4)
#define HW_ELCDIF_CTRL1_CLR_ADDR  (HW_ELCDIF_CTRL1_ADDR + 0x8)
#define HW_ELCDIF_CTRL1_TOG_ADDR  (HW_ELCDIF_CTRL1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CTRL1           (*(volatile hw_elcdif_ctrl1_t *) HW_ELCDIF_CTRL1_ADDR)
#define HW_ELCDIF_CTRL1_RD()      (HW_ELCDIF_CTRL1.U)
#define HW_ELCDIF_CTRL1_WR(v)     (HW_ELCDIF_CTRL1.U = (v))
#define HW_ELCDIF_CTRL1_SET(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL1_SET_ADDR) = (v))
#define HW_ELCDIF_CTRL1_CLR(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL1_CLR_ADDR) = (v))
#define HW_ELCDIF_CTRL1_TOG(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL1_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual ELCDIF_CTRL1 bitfields
 */

/* --- Register HW_ELCDIF_CTRL1, field RESET[0] (RW)
 *
 * Reset bit for the external LCD controller. This bit can be changed at any time. It CANNOT be
 * reset by SFTRST.
 *
 * Values:
 * LCDRESET_LOW = 0x0 - LCD_RESET output signal is low.
 * LCDRESET_HIGH = 0x1 - LCD_RESET output signal is high.
 */

#define BP_ELCDIF_CTRL1_RESET      (0)      //!< Bit position for ELCDIF_CTRL1_RESET.
#define BM_ELCDIF_CTRL1_RESET      (0x00000001)  //!< Bit mask for ELCDIF_CTRL1_RESET.

//! @brief Get value of ELCDIF_CTRL1_RESET from a register value.
#define BG_ELCDIF_CTRL1_RESET(r)   (((r) & BM_ELCDIF_CTRL1_RESET) >> BP_ELCDIF_CTRL1_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_RESET.
#define BF_ELCDIF_CTRL1_RESET(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_RESET) & BM_ELCDIF_CTRL1_RESET)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_RESET.
#define BF_ELCDIF_CTRL1_RESET(v)   (((v) << BP_ELCDIF_CTRL1_RESET) & BM_ELCDIF_CTRL1_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_ELCDIF_CTRL1_RESET(v)   BF_CS1(ELCDIF_CTRL1, RESET, v)
#endif

#define BV_ELCDIF_CTRL1_RESET__LCDRESET_LOW (0x0) //!< LCD_RESET output signal is low.
#define BV_ELCDIF_CTRL1_RESET__LCDRESET_HIGH (0x1) //!< LCD_RESET output signal is high.

/* --- Register HW_ELCDIF_CTRL1, field MODE86[1] (RW)
 *
 * This bit is used to select between the 8080 and 6800 series of microprocessor modes. This bit
 * should only be changed when RUN is 0.
 *
 * Values:
 * 8080_MODE = 0x0 - Pins LCD_WR_RWn and LCD_RD_E function as active low WR and active low RD signals respectively.
 * 6800_MODE = 0x1 - Pins LCD_WR_RWn and LCD_RD_E function as Read/Writeb and active high Enable signals respectively.
 */

#define BP_ELCDIF_CTRL1_MODE86      (1)      //!< Bit position for ELCDIF_CTRL1_MODE86.
#define BM_ELCDIF_CTRL1_MODE86      (0x00000002)  //!< Bit mask for ELCDIF_CTRL1_MODE86.

//! @brief Get value of ELCDIF_CTRL1_MODE86 from a register value.
#define BG_ELCDIF_CTRL1_MODE86(r)   (((r) & BM_ELCDIF_CTRL1_MODE86) >> BP_ELCDIF_CTRL1_MODE86)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_MODE86.
#define BF_ELCDIF_CTRL1_MODE86(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_MODE86) & BM_ELCDIF_CTRL1_MODE86)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_MODE86.
#define BF_ELCDIF_CTRL1_MODE86(v)   (((v) << BP_ELCDIF_CTRL1_MODE86) & BM_ELCDIF_CTRL1_MODE86)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MODE86 field to a new value.
#define BW_ELCDIF_CTRL1_MODE86(v)   BF_CS1(ELCDIF_CTRL1, MODE86, v)
#endif

#define BV_ELCDIF_CTRL1_MODE86__8080_MODE (0x0) //!< Pins LCD_WR_RWn and LCD_RD_E function as active low WR and active low RD signals respectively.
#define BV_ELCDIF_CTRL1_MODE86__6800_MODE (0x1) //!< Pins LCD_WR_RWn and LCD_RD_E function as Read/Writeb and active high Enable signals respectively.

/* --- Register HW_ELCDIF_CTRL1, field BUSY_ENABLE[2] (RW)
 *
 * This bit enables the use of the interface's busy signal input. This should be enabled for LCD
 * controllers that implement a busy line (to stall the eLCDIF from sending more data until ready).
 * Otherwise this bit should be cleared.
 *
 * Values:
 * BUSY_DISABLED = 0x0 - The busy signal from the LCD controller will be ignored.
 * BUSY_ENABLED = 0x1 - Enable the use of the busy signal from the LCD controller.
 */

#define BP_ELCDIF_CTRL1_BUSY_ENABLE      (2)      //!< Bit position for ELCDIF_CTRL1_BUSY_ENABLE.
#define BM_ELCDIF_CTRL1_BUSY_ENABLE      (0x00000004)  //!< Bit mask for ELCDIF_CTRL1_BUSY_ENABLE.

//! @brief Get value of ELCDIF_CTRL1_BUSY_ENABLE from a register value.
#define BG_ELCDIF_CTRL1_BUSY_ENABLE(r)   (((r) & BM_ELCDIF_CTRL1_BUSY_ENABLE) >> BP_ELCDIF_CTRL1_BUSY_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_BUSY_ENABLE.
#define BF_ELCDIF_CTRL1_BUSY_ENABLE(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_BUSY_ENABLE) & BM_ELCDIF_CTRL1_BUSY_ENABLE)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_BUSY_ENABLE.
#define BF_ELCDIF_CTRL1_BUSY_ENABLE(v)   (((v) << BP_ELCDIF_CTRL1_BUSY_ENABLE) & BM_ELCDIF_CTRL1_BUSY_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BUSY_ENABLE field to a new value.
#define BW_ELCDIF_CTRL1_BUSY_ENABLE(v)   BF_CS1(ELCDIF_CTRL1, BUSY_ENABLE, v)
#endif

#define BV_ELCDIF_CTRL1_BUSY_ENABLE__BUSY_DISABLED (0x0) //!< The busy signal from the LCD controller will be ignored.
#define BV_ELCDIF_CTRL1_BUSY_ENABLE__BUSY_ENABLED (0x1) //!< Enable the use of the busy signal from the LCD controller.

/* --- Register HW_ELCDIF_CTRL1, field VSYNC_EDGE_IRQ[8] (RW)
 *
 * This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is
 * cleared by software by writing a one to its SCT clear address. It is set whenever the leading
 * VSYNC edge is detected in the VSYNC and DOTCLK modes. In the DVI mode, it is asserted every time
 * the block enters a new field.
 *
 * Values:
 * NO_REQUEST = 0x0 - No Interrupt Request Pending.
 * REQUEST = 0x1 - Interrupt Request Pending.
 */

#define BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ      (8)      //!< Bit position for ELCDIF_CTRL1_VSYNC_EDGE_IRQ.
#define BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ      (0x00000100)  //!< Bit mask for ELCDIF_CTRL1_VSYNC_EDGE_IRQ.

//! @brief Get value of ELCDIF_CTRL1_VSYNC_EDGE_IRQ from a register value.
#define BG_ELCDIF_CTRL1_VSYNC_EDGE_IRQ(r)   (((r) & BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ) >> BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_VSYNC_EDGE_IRQ.
#define BF_ELCDIF_CTRL1_VSYNC_EDGE_IRQ(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ) & BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_VSYNC_EDGE_IRQ.
#define BF_ELCDIF_CTRL1_VSYNC_EDGE_IRQ(v)   (((v) << BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ) & BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_EDGE_IRQ field to a new value.
#define BW_ELCDIF_CTRL1_VSYNC_EDGE_IRQ(v)   BF_CS1(ELCDIF_CTRL1, VSYNC_EDGE_IRQ, v)
#endif

#define BV_ELCDIF_CTRL1_VSYNC_EDGE_IRQ__NO_REQUEST (0x0) //!< No Interrupt Request Pending.
#define BV_ELCDIF_CTRL1_VSYNC_EDGE_IRQ__REQUEST (0x1) //!< Interrupt Request Pending.

/* --- Register HW_ELCDIF_CTRL1, field CUR_FRAME_DONE_IRQ[9] (RW)
 *
 * This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is
 * cleared by software by writing a one to its SCT clear address. It indicates that the hardware has
 * completed transmitting the current frame and is in the vertical blanking period in the DOTCLK/DVI
 * modes. In the MPU and VSYNC modes, this IRQ is asserted at the end of the data transfer indicated
 * by LCDIF_TRANSFER_COUNT register.
 *
 * Values:
 * NO_REQUEST = 0x0 - No Interrupt Request Pending.
 * REQUEST = 0x1 - Interrupt Request Pending.
 */

#define BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ      (9)      //!< Bit position for ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ.
#define BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ      (0x00000200)  //!< Bit mask for ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ.

//! @brief Get value of ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ from a register value.
#define BG_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ(r)   (((r) & BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ) >> BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ.
#define BF_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ) & BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ.
#define BF_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ(v)   (((v) << BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ) & BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CUR_FRAME_DONE_IRQ field to a new value.
#define BW_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ(v)   BF_CS1(ELCDIF_CTRL1, CUR_FRAME_DONE_IRQ, v)
#endif

#define BV_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ__NO_REQUEST (0x0) //!< No Interrupt Request Pending.
#define BV_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ__REQUEST (0x1) //!< Interrupt Request Pending.

/* --- Register HW_ELCDIF_CTRL1, field UNDERFLOW_IRQ[10] (RW)
 *
 * This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is
 * cleared by software by writing a one to its SCT clear address. A TXFIFO underflow in the write
 * mode (MPU/VSYNC/DOTCLK/DVI mode) was detected. Could produce an error in the DOTCLK / DVI modes.
 *
 * Values:
 * NO_REQUEST = 0x0 - No Interrupt Request Pending.
 * REQUEST = 0x1 - Interrupt Request Pending.
 */

#define BP_ELCDIF_CTRL1_UNDERFLOW_IRQ      (10)      //!< Bit position for ELCDIF_CTRL1_UNDERFLOW_IRQ.
#define BM_ELCDIF_CTRL1_UNDERFLOW_IRQ      (0x00000400)  //!< Bit mask for ELCDIF_CTRL1_UNDERFLOW_IRQ.

//! @brief Get value of ELCDIF_CTRL1_UNDERFLOW_IRQ from a register value.
#define BG_ELCDIF_CTRL1_UNDERFLOW_IRQ(r)   (((r) & BM_ELCDIF_CTRL1_UNDERFLOW_IRQ) >> BP_ELCDIF_CTRL1_UNDERFLOW_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_UNDERFLOW_IRQ.
#define BF_ELCDIF_CTRL1_UNDERFLOW_IRQ(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_UNDERFLOW_IRQ) & BM_ELCDIF_CTRL1_UNDERFLOW_IRQ)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_UNDERFLOW_IRQ.
#define BF_ELCDIF_CTRL1_UNDERFLOW_IRQ(v)   (((v) << BP_ELCDIF_CTRL1_UNDERFLOW_IRQ) & BM_ELCDIF_CTRL1_UNDERFLOW_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNDERFLOW_IRQ field to a new value.
#define BW_ELCDIF_CTRL1_UNDERFLOW_IRQ(v)   BF_CS1(ELCDIF_CTRL1, UNDERFLOW_IRQ, v)
#endif

#define BV_ELCDIF_CTRL1_UNDERFLOW_IRQ__NO_REQUEST (0x0) //!< No Interrupt Request Pending.
#define BV_ELCDIF_CTRL1_UNDERFLOW_IRQ__REQUEST (0x1) //!< Interrupt Request Pending.

/* --- Register HW_ELCDIF_CTRL1, field OVERFLOW_IRQ[11] (RW)
 *
 * This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is
 * cleared by software by writing a one to its SCT clear address. A latency FIFO (LFIFO) overflow in
 * the write mode (MPU/VSYNC/DOTCLK/DVI mode) was detected, data samples have been lost.
 *
 * Values:
 * NO_REQUEST = 0x0 - No Interrupt Request Pending.
 * REQUEST = 0x1 - Interrupt Request Pending.
 */

#define BP_ELCDIF_CTRL1_OVERFLOW_IRQ      (11)      //!< Bit position for ELCDIF_CTRL1_OVERFLOW_IRQ.
#define BM_ELCDIF_CTRL1_OVERFLOW_IRQ      (0x00000800)  //!< Bit mask for ELCDIF_CTRL1_OVERFLOW_IRQ.

//! @brief Get value of ELCDIF_CTRL1_OVERFLOW_IRQ from a register value.
#define BG_ELCDIF_CTRL1_OVERFLOW_IRQ(r)   (((r) & BM_ELCDIF_CTRL1_OVERFLOW_IRQ) >> BP_ELCDIF_CTRL1_OVERFLOW_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_OVERFLOW_IRQ.
#define BF_ELCDIF_CTRL1_OVERFLOW_IRQ(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_OVERFLOW_IRQ) & BM_ELCDIF_CTRL1_OVERFLOW_IRQ)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_OVERFLOW_IRQ.
#define BF_ELCDIF_CTRL1_OVERFLOW_IRQ(v)   (((v) << BP_ELCDIF_CTRL1_OVERFLOW_IRQ) & BM_ELCDIF_CTRL1_OVERFLOW_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERFLOW_IRQ field to a new value.
#define BW_ELCDIF_CTRL1_OVERFLOW_IRQ(v)   BF_CS1(ELCDIF_CTRL1, OVERFLOW_IRQ, v)
#endif

#define BV_ELCDIF_CTRL1_OVERFLOW_IRQ__NO_REQUEST (0x0) //!< No Interrupt Request Pending.
#define BV_ELCDIF_CTRL1_OVERFLOW_IRQ__REQUEST (0x1) //!< Interrupt Request Pending.

/* --- Register HW_ELCDIF_CTRL1, field VSYNC_EDGE_IRQ_EN[12] (RW)
 *
 * This bit is set to enable an interrupt every time the hardware encounters the leading VSYNC edge
 * in the VSYNC and DOTCLK modes, or the beginning of every field in DVI mode.
 */

#define BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN      (12)      //!< Bit position for ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN.
#define BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN      (0x00001000)  //!< Bit mask for ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN.

//! @brief Get value of ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN from a register value.
#define BG_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN(r)   (((r) & BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN) >> BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN.
#define BF_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN) & BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN.
#define BF_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN(v)   (((v) << BP_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN) & BM_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_EDGE_IRQ_EN field to a new value.
#define BW_ELCDIF_CTRL1_VSYNC_EDGE_IRQ_EN(v)   BF_CS1(ELCDIF_CTRL1, VSYNC_EDGE_IRQ_EN, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field CUR_FRAME_DONE_IRQ_EN[13] (RW)
 *
 * This bit is set to 1 enable an interrupt every time the hardware enters in the vertical blanking
 * state.
 */

#define BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN      (13)      //!< Bit position for ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN.
#define BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN      (0x00002000)  //!< Bit mask for ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN.

//! @brief Get value of ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN from a register value.
#define BG_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN(r)   (((r) & BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN) >> BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN.
#define BF_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN) & BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN.
#define BF_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN(v)   (((v) << BP_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN) & BM_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CUR_FRAME_DONE_IRQ_EN field to a new value.
#define BW_ELCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN(v)   BF_CS1(ELCDIF_CTRL1, CUR_FRAME_DONE_IRQ_EN, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field UNDERFLOW_IRQ_EN[14] (RW)
 *
 * This bit is set to enable an underflow interrupt in the TXFIFO in the write mode.
 */

#define BP_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN      (14)      //!< Bit position for ELCDIF_CTRL1_UNDERFLOW_IRQ_EN.
#define BM_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN      (0x00004000)  //!< Bit mask for ELCDIF_CTRL1_UNDERFLOW_IRQ_EN.

//! @brief Get value of ELCDIF_CTRL1_UNDERFLOW_IRQ_EN from a register value.
#define BG_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN(r)   (((r) & BM_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN) >> BP_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_UNDERFLOW_IRQ_EN.
#define BF_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN) & BM_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_UNDERFLOW_IRQ_EN.
#define BF_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN(v)   (((v) << BP_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN) & BM_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UNDERFLOW_IRQ_EN field to a new value.
#define BW_ELCDIF_CTRL1_UNDERFLOW_IRQ_EN(v)   BF_CS1(ELCDIF_CTRL1, UNDERFLOW_IRQ_EN, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field OVERFLOW_IRQ_EN[15] (RW)
 *
 * This bit is set to enable an overflow interrupt in the TXFIFO in the write mode.
 */

#define BP_ELCDIF_CTRL1_OVERFLOW_IRQ_EN      (15)      //!< Bit position for ELCDIF_CTRL1_OVERFLOW_IRQ_EN.
#define BM_ELCDIF_CTRL1_OVERFLOW_IRQ_EN      (0x00008000)  //!< Bit mask for ELCDIF_CTRL1_OVERFLOW_IRQ_EN.

//! @brief Get value of ELCDIF_CTRL1_OVERFLOW_IRQ_EN from a register value.
#define BG_ELCDIF_CTRL1_OVERFLOW_IRQ_EN(r)   (((r) & BM_ELCDIF_CTRL1_OVERFLOW_IRQ_EN) >> BP_ELCDIF_CTRL1_OVERFLOW_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_OVERFLOW_IRQ_EN.
#define BF_ELCDIF_CTRL1_OVERFLOW_IRQ_EN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_OVERFLOW_IRQ_EN) & BM_ELCDIF_CTRL1_OVERFLOW_IRQ_EN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_OVERFLOW_IRQ_EN.
#define BF_ELCDIF_CTRL1_OVERFLOW_IRQ_EN(v)   (((v) << BP_ELCDIF_CTRL1_OVERFLOW_IRQ_EN) & BM_ELCDIF_CTRL1_OVERFLOW_IRQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OVERFLOW_IRQ_EN field to a new value.
#define BW_ELCDIF_CTRL1_OVERFLOW_IRQ_EN(v)   BF_CS1(ELCDIF_CTRL1, OVERFLOW_IRQ_EN, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field BYTE_PACKING_FORMAT[19:16] (RW)
 *
 * This bitfield is used to show which data bytes in a 32-bit word are valid. Default value 0xf
 * indicates that all bytes are valid. For 8-bit transfers, any combination in this bitfield will
 * mean valid data is present in the corresponding bytes. In the 16-bit mode, a 16-bit half-word is
 * valid only if adjacent bits [1:0] or [3:2] or both are 1. A value of 0x0 will mean that none of
 * the bytes are valid and should not be used. For example, set the bit field value to 0x7 if the
 * display data is arranged in the 24-bit unpacked format (A-R-G-B where A value does not have be
 * transmitted). When input data is in YCbCr 4:2:2 format (YCBCR422_INPUT is 1), H_COUNT should be
 * the number of pixels that should be fetched by the block and the BYTE_PACKING_FORMAT should be
 * 0xF.(Note - YCBCR422_INPUT = 1 implies 2 pixels per 32 bits).
 */

#define BP_ELCDIF_CTRL1_BYTE_PACKING_FORMAT      (16)      //!< Bit position for ELCDIF_CTRL1_BYTE_PACKING_FORMAT.
#define BM_ELCDIF_CTRL1_BYTE_PACKING_FORMAT      (0x000f0000)  //!< Bit mask for ELCDIF_CTRL1_BYTE_PACKING_FORMAT.

//! @brief Get value of ELCDIF_CTRL1_BYTE_PACKING_FORMAT from a register value.
#define BG_ELCDIF_CTRL1_BYTE_PACKING_FORMAT(r)   (((r) & BM_ELCDIF_CTRL1_BYTE_PACKING_FORMAT) >> BP_ELCDIF_CTRL1_BYTE_PACKING_FORMAT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_BYTE_PACKING_FORMAT.
#define BF_ELCDIF_CTRL1_BYTE_PACKING_FORMAT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_BYTE_PACKING_FORMAT) & BM_ELCDIF_CTRL1_BYTE_PACKING_FORMAT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_BYTE_PACKING_FORMAT.
#define BF_ELCDIF_CTRL1_BYTE_PACKING_FORMAT(v)   (((v) << BP_ELCDIF_CTRL1_BYTE_PACKING_FORMAT) & BM_ELCDIF_CTRL1_BYTE_PACKING_FORMAT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BYTE_PACKING_FORMAT field to a new value.
#define BW_ELCDIF_CTRL1_BYTE_PACKING_FORMAT(v)   BF_CS1(ELCDIF_CTRL1, BYTE_PACKING_FORMAT, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field IRQ_ON_ALTERNATE_FIELDS[20] (RW)
 *
 * If this bit is set, the eLCDIF block will assert the cur_frame_done interrupt only on alternate
 * fields, otherwise it will issue the interrupt on both odd and even field. This bit is mostly
 * relevant if INTERLACE_FIELDS is set. This feature is only available in DOTCLK and DVI modes.
 */

#define BP_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS      (20)      //!< Bit position for ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS.
#define BM_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS      (0x00100000)  //!< Bit mask for ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS.

//! @brief Get value of ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS from a register value.
#define BG_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS(r)   (((r) & BM_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS) >> BP_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS.
#define BF_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS) & BM_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS.
#define BF_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS(v)   (((v) << BP_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS) & BM_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ON_ALTERNATE_FIELDS field to a new value.
#define BW_ELCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS(v)   BF_CS1(ELCDIF_CTRL1, IRQ_ON_ALTERNATE_FIELDS, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field FIFO_CLEAR[21] (RW)
 *
 * Set this bit to clear all the data in the latency FIFO (LFIFO), TXFIFO and the RXFIFO.
 */

#define BP_ELCDIF_CTRL1_FIFO_CLEAR      (21)      //!< Bit position for ELCDIF_CTRL1_FIFO_CLEAR.
#define BM_ELCDIF_CTRL1_FIFO_CLEAR      (0x00200000)  //!< Bit mask for ELCDIF_CTRL1_FIFO_CLEAR.

//! @brief Get value of ELCDIF_CTRL1_FIFO_CLEAR from a register value.
#define BG_ELCDIF_CTRL1_FIFO_CLEAR(r)   (((r) & BM_ELCDIF_CTRL1_FIFO_CLEAR) >> BP_ELCDIF_CTRL1_FIFO_CLEAR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_FIFO_CLEAR.
#define BF_ELCDIF_CTRL1_FIFO_CLEAR(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_FIFO_CLEAR) & BM_ELCDIF_CTRL1_FIFO_CLEAR)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_FIFO_CLEAR.
#define BF_ELCDIF_CTRL1_FIFO_CLEAR(v)   (((v) << BP_ELCDIF_CTRL1_FIFO_CLEAR) & BM_ELCDIF_CTRL1_FIFO_CLEAR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FIFO_CLEAR field to a new value.
#define BW_ELCDIF_CTRL1_FIFO_CLEAR(v)   BF_CS1(ELCDIF_CTRL1, FIFO_CLEAR, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field START_INTERLACE_FROM_SECOND_FIELD[22] (RW)
 *
 * The default is to grab the odd lines first and then the even lines. Set this bit if it is
 * required to grab the even lines first and then the odd lines. (Line numbers start from 1, so odd
 * lines are 1,3,5,etc. and even lines are 2,4,6, etc.)
 */

#define BP_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD      (22)      //!< Bit position for ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD.
#define BM_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD      (0x00400000)  //!< Bit mask for ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD.

//! @brief Get value of ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD from a register value.
#define BG_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD(r)   (((r) & BM_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD) >> BP_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD.
#define BF_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD) & BM_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD.
#define BF_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD(v)   (((v) << BP_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD) & BM_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the START_INTERLACE_FROM_SECOND_FIELD field to a new value.
#define BW_ELCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD(v)   BF_CS1(ELCDIF_CTRL1, START_INTERLACE_FROM_SECOND_FIELD, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field INTERLACE_FIELDS[23] (RW)
 *
 * Set this bit if it is required that the eLCDIF block fetches odd lines in one field and even
 * lines in the other field. It will work only in LCDIF_MASTER is set to 1.
 */

#define BP_ELCDIF_CTRL1_INTERLACE_FIELDS      (23)      //!< Bit position for ELCDIF_CTRL1_INTERLACE_FIELDS.
#define BM_ELCDIF_CTRL1_INTERLACE_FIELDS      (0x00800000)  //!< Bit mask for ELCDIF_CTRL1_INTERLACE_FIELDS.

//! @brief Get value of ELCDIF_CTRL1_INTERLACE_FIELDS from a register value.
#define BG_ELCDIF_CTRL1_INTERLACE_FIELDS(r)   (((r) & BM_ELCDIF_CTRL1_INTERLACE_FIELDS) >> BP_ELCDIF_CTRL1_INTERLACE_FIELDS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_INTERLACE_FIELDS.
#define BF_ELCDIF_CTRL1_INTERLACE_FIELDS(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_INTERLACE_FIELDS) & BM_ELCDIF_CTRL1_INTERLACE_FIELDS)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_INTERLACE_FIELDS.
#define BF_ELCDIF_CTRL1_INTERLACE_FIELDS(v)   (((v) << BP_ELCDIF_CTRL1_INTERLACE_FIELDS) & BM_ELCDIF_CTRL1_INTERLACE_FIELDS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INTERLACE_FIELDS field to a new value.
#define BW_ELCDIF_CTRL1_INTERLACE_FIELDS(v)   BF_CS1(ELCDIF_CTRL1, INTERLACE_FIELDS, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field RECOVER_ON_UNDERFLOW[24] (RW)
 *
 * Set this bit to enable the eLCDIF block to recover in the next field/frame if there was an
 * underflow in the current field/frame.
 */

#define BP_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW      (24)      //!< Bit position for ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW.
#define BM_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW      (0x01000000)  //!< Bit mask for ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW.

//! @brief Get value of ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW from a register value.
#define BG_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW(r)   (((r) & BM_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW) >> BP_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW.
#define BF_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW) & BM_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW.
#define BF_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW(v)   (((v) << BP_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW) & BM_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RECOVER_ON_UNDERFLOW field to a new value.
#define BW_ELCDIF_CTRL1_RECOVER_ON_UNDERFLOW(v)   BF_CS1(ELCDIF_CTRL1, RECOVER_ON_UNDERFLOW, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field BM_ERROR_IRQ[25] (RW)
 *
 * This bit is set to indicate that an interrupt is requested by the eLCDIF block. This bit is
 * cleared by software by writing a one to its SCT clear address. This bit will be set when the
 * eLCDIF is in master mode and an error response was returned by the slave.
 *
 * Values:
 * NO_REQUEST = 0x0 - No Interrupt Request Pending.
 * REQUEST = 0x1 - Interrupt Request Pending.
 */

#define BP_ELCDIF_CTRL1_BM_ERROR_IRQ      (25)      //!< Bit position for ELCDIF_CTRL1_BM_ERROR_IRQ.
#define BM_ELCDIF_CTRL1_BM_ERROR_IRQ      (0x02000000)  //!< Bit mask for ELCDIF_CTRL1_BM_ERROR_IRQ.

//! @brief Get value of ELCDIF_CTRL1_BM_ERROR_IRQ from a register value.
#define BG_ELCDIF_CTRL1_BM_ERROR_IRQ(r)   (((r) & BM_ELCDIF_CTRL1_BM_ERROR_IRQ) >> BP_ELCDIF_CTRL1_BM_ERROR_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_BM_ERROR_IRQ.
#define BF_ELCDIF_CTRL1_BM_ERROR_IRQ(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_BM_ERROR_IRQ) & BM_ELCDIF_CTRL1_BM_ERROR_IRQ)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_BM_ERROR_IRQ.
#define BF_ELCDIF_CTRL1_BM_ERROR_IRQ(v)   (((v) << BP_ELCDIF_CTRL1_BM_ERROR_IRQ) & BM_ELCDIF_CTRL1_BM_ERROR_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BM_ERROR_IRQ field to a new value.
#define BW_ELCDIF_CTRL1_BM_ERROR_IRQ(v)   BF_CS1(ELCDIF_CTRL1, BM_ERROR_IRQ, v)
#endif

#define BV_ELCDIF_CTRL1_BM_ERROR_IRQ__NO_REQUEST (0x0) //!< No Interrupt Request Pending.
#define BV_ELCDIF_CTRL1_BM_ERROR_IRQ__REQUEST (0x1) //!< Interrupt Request Pending.

/* --- Register HW_ELCDIF_CTRL1, field BM_ERROR_IRQ_EN[26] (RW)
 *
 * This bit is set to enable bus master error interrupt in the eLCDIF master mode.
 */

#define BP_ELCDIF_CTRL1_BM_ERROR_IRQ_EN      (26)      //!< Bit position for ELCDIF_CTRL1_BM_ERROR_IRQ_EN.
#define BM_ELCDIF_CTRL1_BM_ERROR_IRQ_EN      (0x04000000)  //!< Bit mask for ELCDIF_CTRL1_BM_ERROR_IRQ_EN.

//! @brief Get value of ELCDIF_CTRL1_BM_ERROR_IRQ_EN from a register value.
#define BG_ELCDIF_CTRL1_BM_ERROR_IRQ_EN(r)   (((r) & BM_ELCDIF_CTRL1_BM_ERROR_IRQ_EN) >> BP_ELCDIF_CTRL1_BM_ERROR_IRQ_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_BM_ERROR_IRQ_EN.
#define BF_ELCDIF_CTRL1_BM_ERROR_IRQ_EN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_BM_ERROR_IRQ_EN) & BM_ELCDIF_CTRL1_BM_ERROR_IRQ_EN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_BM_ERROR_IRQ_EN.
#define BF_ELCDIF_CTRL1_BM_ERROR_IRQ_EN(v)   (((v) << BP_ELCDIF_CTRL1_BM_ERROR_IRQ_EN) & BM_ELCDIF_CTRL1_BM_ERROR_IRQ_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BM_ERROR_IRQ_EN field to a new value.
#define BW_ELCDIF_CTRL1_BM_ERROR_IRQ_EN(v)   BF_CS1(ELCDIF_CTRL1, BM_ERROR_IRQ_EN, v)
#endif

/* --- Register HW_ELCDIF_CTRL1, field COMBINE_MPU_WR_STRB[27] (RW)
 *
 * If this bit is not set, the write strobe will be driven on LCD_WR_RWn pin in the 8080 mode and on
 * the LCD_RD_E pin in the 6800 mode. If it is set, the write strobe of both the 6800 and 8080 modes
 * will be driven only on the LCD_WR_RWn pin. Note that this does not work for read strobe.
 */

#define BP_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB      (27)      //!< Bit position for ELCDIF_CTRL1_COMBINE_MPU_WR_STRB.
#define BM_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB      (0x08000000)  //!< Bit mask for ELCDIF_CTRL1_COMBINE_MPU_WR_STRB.

//! @brief Get value of ELCDIF_CTRL1_COMBINE_MPU_WR_STRB from a register value.
#define BG_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB(r)   (((r) & BM_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB) >> BP_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL1_COMBINE_MPU_WR_STRB.
#define BF_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB) & BM_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB)
#else
//! @brief Format value for bitfield ELCDIF_CTRL1_COMBINE_MPU_WR_STRB.
#define BF_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB(v)   (((v) << BP_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB) & BM_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMBINE_MPU_WR_STRB field to a new value.
#define BW_ELCDIF_CTRL1_COMBINE_MPU_WR_STRB(v)   BF_CS1(ELCDIF_CTRL1, COMBINE_MPU_WR_STRB, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CTRL2 - eLCDIF General Control2 Register (RW)
 *
 * Reset value: 0x00200000
 *
 * The eLCDIF Control Register provides overall control of the eLCDIF block.  The eLCDIF Control2
 * Register provides additional programming to the eLCDIF. It implements some bits which are
 * unlikely to change often in a particular application.
 */
typedef union _hw_elcdif_ctrl2
{
    reg32_t U;
    struct _hw_elcdif_ctrl2_bitfields
    {
        unsigned RESERVED0 : 1; //!< [0] Reserved bits. Write as 0.
        unsigned INITIAL_DUMMY_READ : 3; //!< [3:1] The value in this field determines the number of dummy 8/16/18/24-bit subwords that have to be read back from the LCD panel/controller. They will then not be stored in the read FIFO.
        unsigned READ_MODE_NUM_PACKED_SUBWORDS : 3; //!< [6:4] Indicates the number of valid 8/16/18/24-bit subwords that will be packed into the 32-bit word in read mode. The subword size (8,16, 18 or 24 bits) is determined by the LCD_DATABUS_WIDTH field. The swizzle operation is performed after READ_MODE_NUM_PACKED_SUBWORDS number of subwords has been received and stored in little-endian format. For example, if LCD_DATABUS_WIDTH is set to 8-bit and data to be read back has to be stored in memory in 24-bit unpacked RGB format, set READ_MODE_NUM_PACKED_SUBWORDS to 0x3 so that each 32-bit word will contain only 3 valid bytes (RGB). Maximum value of READ_MODE_NUM_PACKED_SUBWORDS is 4 for 8-bit databus, 2 for 16-bit databus and 1 for 18/24-bit databus.
        unsigned RESERVED1 : 1; //!< [7] Reserved bits. Write as 0.
        unsigned READ_MODE_6_BIT_INPUT : 1; //!< [8] Setting this bit to 1 indicates to eLCDIF that even though LCD_DATABUS_WIDTH is set to 8 bits, the input data is actually only 6 bits wide and exists on D5-D0.
        unsigned READ_MODE_OUTPUT_IN_RGB_FORMAT : 1; //!< [9] Setting this bit will enable the eLCDIF to convert the incoming data to the RGB format given by WORD_LENGTH bitfield. This feature is not available when WORD_LENGTH is set to 8 bits. eLCDIF performs this operation of converting to RGB format after the endianness has been determined by the READ_PACK_DIR bitfield.
        unsigned READ_PACK_DIR : 1; //!< [10] The default value of 0 indicates data is stored in the little endian format. When LCD_DATABUS_WIDTH is 8-bit, this bit provides the option of rearranging the data byte-wise in the big endian format. For example, if READ_MODE_NUM_PACKED_SUBWORDS = 3 and the order of incoming data is 0x11, 0x22 and 0x33, then setting this bit to 1 will cause the data to be stored as 0x00112233 as opposed to the default 0x00332211. This operation occurs after the shifting operation done by SHIFT_NUM_BITS bitfield.
        unsigned RESERVED2 : 1; //!< [11] Reserved bits. Write as 0.
        unsigned EVEN_LINE_PATTERN : 3; //!< [14:12] This field determines the order of the RGB components of each pixel in EVEN lines (line numbers 2,4,6,..). This bitfield must be 0 in DVI mode.
        unsigned RESERVED3 : 1; //!< [15] Reserved bits. Write as 0.
        unsigned ODD_LINE_PATTERN : 3; //!< [18:16] This field determines the order of the RGB components of each pixel in ODD lines (line numbers 1,3,5,..). This bitfield must be 0 in DVI mode.
        unsigned RESERVED4 : 1; //!< [19] Reserved bits. Write as 0.
        unsigned BURST_LEN_8 : 1; //!< [20] By default, when the eLCDIF is in the bus master mode, it will issue AXI bursts of length 16 (except when in packed 24 bpp mode, it will issue bursts of length 15). When this bit is set to 1, the block will issue bursts of length 8 (except when in packed 24 bpp mode, it will issue bursts of length 9). Note that this bitfield is only applicable when LCDIF_MASTER is set to 1.
        unsigned OUTSTANDING_REQS : 3; //!< [23:21] This bitfield indicates the maximum number of outstanding transactions that eLCDIF should request when it is acting as a bus master. Default is 2 outstanding transactions.
        unsigned RESERVED5 : 8; //!< [31:24] Reserved bits. Write as 0.
    } B;
} hw_elcdif_ctrl2_t;
#endif

/*
 * constants & macros for entire ELCDIF_CTRL2 register
 */
#define HW_ELCDIF_CTRL2_ADDR      (REGS_ELCDIF_BASE + 0x20)
#define HW_ELCDIF_CTRL2_SET_ADDR  (HW_ELCDIF_CTRL2_ADDR + 0x4)
#define HW_ELCDIF_CTRL2_CLR_ADDR  (HW_ELCDIF_CTRL2_ADDR + 0x8)
#define HW_ELCDIF_CTRL2_TOG_ADDR  (HW_ELCDIF_CTRL2_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CTRL2           (*(volatile hw_elcdif_ctrl2_t *) HW_ELCDIF_CTRL2_ADDR)
#define HW_ELCDIF_CTRL2_RD()      (HW_ELCDIF_CTRL2.U)
#define HW_ELCDIF_CTRL2_WR(v)     (HW_ELCDIF_CTRL2.U = (v))
#define HW_ELCDIF_CTRL2_SET(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL2_SET_ADDR) = (v))
#define HW_ELCDIF_CTRL2_CLR(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL2_CLR_ADDR) = (v))
#define HW_ELCDIF_CTRL2_TOG(v)    ((*(volatile reg32_t *) HW_ELCDIF_CTRL2_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual ELCDIF_CTRL2 bitfields
 */

/* --- Register HW_ELCDIF_CTRL2, field INITIAL_DUMMY_READ[3:1] (RW)
 *
 * The value in this field determines the number of dummy 8/16/18/24-bit subwords that have to be
 * read back from the LCD panel/controller. They will then not be stored in the read FIFO.
 */

#define BP_ELCDIF_CTRL2_INITIAL_DUMMY_READ      (1)      //!< Bit position for ELCDIF_CTRL2_INITIAL_DUMMY_READ.
#define BM_ELCDIF_CTRL2_INITIAL_DUMMY_READ      (0x0000000e)  //!< Bit mask for ELCDIF_CTRL2_INITIAL_DUMMY_READ.

//! @brief Get value of ELCDIF_CTRL2_INITIAL_DUMMY_READ from a register value.
#define BG_ELCDIF_CTRL2_INITIAL_DUMMY_READ(r)   (((r) & BM_ELCDIF_CTRL2_INITIAL_DUMMY_READ) >> BP_ELCDIF_CTRL2_INITIAL_DUMMY_READ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_INITIAL_DUMMY_READ.
#define BF_ELCDIF_CTRL2_INITIAL_DUMMY_READ(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_INITIAL_DUMMY_READ) & BM_ELCDIF_CTRL2_INITIAL_DUMMY_READ)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_INITIAL_DUMMY_READ.
#define BF_ELCDIF_CTRL2_INITIAL_DUMMY_READ(v)   (((v) << BP_ELCDIF_CTRL2_INITIAL_DUMMY_READ) & BM_ELCDIF_CTRL2_INITIAL_DUMMY_READ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INITIAL_DUMMY_READ field to a new value.
#define BW_ELCDIF_CTRL2_INITIAL_DUMMY_READ(v)   BF_CS1(ELCDIF_CTRL2, INITIAL_DUMMY_READ, v)
#endif

/* --- Register HW_ELCDIF_CTRL2, field READ_MODE_NUM_PACKED_SUBWORDS[6:4] (RW)
 *
 * Indicates the number of valid 8/16/18/24-bit subwords that will be packed into the 32-bit word in
 * read mode. The subword size (8,16, 18 or 24 bits) is determined by the LCD_DATABUS_WIDTH field.
 * The swizzle operation is performed after READ_MODE_NUM_PACKED_SUBWORDS number of subwords has
 * been received and stored in little-endian format. For example, if LCD_DATABUS_WIDTH is set to
 * 8-bit and data to be read back has to be stored in memory in 24-bit unpacked RGB format, set
 * READ_MODE_NUM_PACKED_SUBWORDS to 0x3 so that each 32-bit word will contain only 3 valid bytes
 * (RGB). Maximum value of READ_MODE_NUM_PACKED_SUBWORDS is 4 for 8-bit databus, 2 for 16-bit
 * databus and 1 for 18/24-bit databus.
 */

#define BP_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS      (4)      //!< Bit position for ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS.
#define BM_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS      (0x00000070)  //!< Bit mask for ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS.

//! @brief Get value of ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS from a register value.
#define BG_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS(r)   (((r) & BM_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS) >> BP_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS.
#define BF_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS) & BM_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS.
#define BF_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS(v)   (((v) << BP_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS) & BM_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the READ_MODE_NUM_PACKED_SUBWORDS field to a new value.
#define BW_ELCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS(v)   BF_CS1(ELCDIF_CTRL2, READ_MODE_NUM_PACKED_SUBWORDS, v)
#endif

/* --- Register HW_ELCDIF_CTRL2, field READ_MODE_6_BIT_INPUT[8] (RW)
 *
 * Setting this bit to 1 indicates to eLCDIF that even though LCD_DATABUS_WIDTH is set to 8 bits,
 * the input data is actually only 6 bits wide and exists on D5-D0.
 */

#define BP_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT      (8)      //!< Bit position for ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT.
#define BM_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT      (0x00000100)  //!< Bit mask for ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT.

//! @brief Get value of ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT from a register value.
#define BG_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT(r)   (((r) & BM_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT) >> BP_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT.
#define BF_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT) & BM_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT.
#define BF_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT(v)   (((v) << BP_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT) & BM_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the READ_MODE_6_BIT_INPUT field to a new value.
#define BW_ELCDIF_CTRL2_READ_MODE_6_BIT_INPUT(v)   BF_CS1(ELCDIF_CTRL2, READ_MODE_6_BIT_INPUT, v)
#endif

/* --- Register HW_ELCDIF_CTRL2, field READ_MODE_OUTPUT_IN_RGB_FORMAT[9] (RW)
 *
 * Setting this bit will enable the eLCDIF to convert the incoming data to the RGB format given by
 * WORD_LENGTH bitfield. This feature is not available when WORD_LENGTH is set to 8 bits. eLCDIF
 * performs this operation of converting to RGB format after the endianness has been determined by
 * the READ_PACK_DIR bitfield.
 */

#define BP_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT      (9)      //!< Bit position for ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT.
#define BM_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT      (0x00000200)  //!< Bit mask for ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT.

//! @brief Get value of ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT from a register value.
#define BG_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT(r)   (((r) & BM_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT) >> BP_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT.
#define BF_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT) & BM_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT.
#define BF_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT(v)   (((v) << BP_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT) & BM_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the READ_MODE_OUTPUT_IN_RGB_FORMAT field to a new value.
#define BW_ELCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT(v)   BF_CS1(ELCDIF_CTRL2, READ_MODE_OUTPUT_IN_RGB_FORMAT, v)
#endif

/* --- Register HW_ELCDIF_CTRL2, field READ_PACK_DIR[10] (RW)
 *
 * The default value of 0 indicates data is stored in the little endian format. When
 * LCD_DATABUS_WIDTH is 8-bit, this bit provides the option of rearranging the data byte-wise in the
 * big endian format. For example, if READ_MODE_NUM_PACKED_SUBWORDS = 3 and the order of incoming
 * data is 0x11, 0x22 and 0x33, then setting this bit to 1 will cause the data to be stored as
 * 0x00112233 as opposed to the default 0x00332211. This operation occurs after the shifting
 * operation done by SHIFT_NUM_BITS bitfield.
 */

#define BP_ELCDIF_CTRL2_READ_PACK_DIR      (10)      //!< Bit position for ELCDIF_CTRL2_READ_PACK_DIR.
#define BM_ELCDIF_CTRL2_READ_PACK_DIR      (0x00000400)  //!< Bit mask for ELCDIF_CTRL2_READ_PACK_DIR.

//! @brief Get value of ELCDIF_CTRL2_READ_PACK_DIR from a register value.
#define BG_ELCDIF_CTRL2_READ_PACK_DIR(r)   (((r) & BM_ELCDIF_CTRL2_READ_PACK_DIR) >> BP_ELCDIF_CTRL2_READ_PACK_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_PACK_DIR.
#define BF_ELCDIF_CTRL2_READ_PACK_DIR(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_READ_PACK_DIR) & BM_ELCDIF_CTRL2_READ_PACK_DIR)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_READ_PACK_DIR.
#define BF_ELCDIF_CTRL2_READ_PACK_DIR(v)   (((v) << BP_ELCDIF_CTRL2_READ_PACK_DIR) & BM_ELCDIF_CTRL2_READ_PACK_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the READ_PACK_DIR field to a new value.
#define BW_ELCDIF_CTRL2_READ_PACK_DIR(v)   BF_CS1(ELCDIF_CTRL2, READ_PACK_DIR, v)
#endif

/* --- Register HW_ELCDIF_CTRL2, field EVEN_LINE_PATTERN[14:12] (RW)
 *
 * This field determines the order of the RGB components of each pixel in EVEN lines (line numbers
 * 2,4,6,..). This bitfield must be 0 in DVI mode.
 *
 * Values:
 * RGB = 0x0 - 
 * RBG = 0x1 - 
 * GBR = 0x2 - 
 * GRB = 0x3 - 
 * BRG = 0x4 - 
 * BGR = 0x5 - 
 */

#define BP_ELCDIF_CTRL2_EVEN_LINE_PATTERN      (12)      //!< Bit position for ELCDIF_CTRL2_EVEN_LINE_PATTERN.
#define BM_ELCDIF_CTRL2_EVEN_LINE_PATTERN      (0x00007000)  //!< Bit mask for ELCDIF_CTRL2_EVEN_LINE_PATTERN.

//! @brief Get value of ELCDIF_CTRL2_EVEN_LINE_PATTERN from a register value.
#define BG_ELCDIF_CTRL2_EVEN_LINE_PATTERN(r)   (((r) & BM_ELCDIF_CTRL2_EVEN_LINE_PATTERN) >> BP_ELCDIF_CTRL2_EVEN_LINE_PATTERN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_EVEN_LINE_PATTERN.
#define BF_ELCDIF_CTRL2_EVEN_LINE_PATTERN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_EVEN_LINE_PATTERN) & BM_ELCDIF_CTRL2_EVEN_LINE_PATTERN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_EVEN_LINE_PATTERN.
#define BF_ELCDIF_CTRL2_EVEN_LINE_PATTERN(v)   (((v) << BP_ELCDIF_CTRL2_EVEN_LINE_PATTERN) & BM_ELCDIF_CTRL2_EVEN_LINE_PATTERN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EVEN_LINE_PATTERN field to a new value.
#define BW_ELCDIF_CTRL2_EVEN_LINE_PATTERN(v)   BF_CS1(ELCDIF_CTRL2, EVEN_LINE_PATTERN, v)
#endif

#define BV_ELCDIF_CTRL2_EVEN_LINE_PATTERN__RGB (0x0) //!< 
#define BV_ELCDIF_CTRL2_EVEN_LINE_PATTERN__RBG (0x1) //!< 
#define BV_ELCDIF_CTRL2_EVEN_LINE_PATTERN__GBR (0x2) //!< 
#define BV_ELCDIF_CTRL2_EVEN_LINE_PATTERN__GRB (0x3) //!< 
#define BV_ELCDIF_CTRL2_EVEN_LINE_PATTERN__BRG (0x4) //!< 
#define BV_ELCDIF_CTRL2_EVEN_LINE_PATTERN__BGR (0x5) //!< 

/* --- Register HW_ELCDIF_CTRL2, field ODD_LINE_PATTERN[18:16] (RW)
 *
 * This field determines the order of the RGB components of each pixel in ODD lines (line numbers
 * 1,3,5,..). This bitfield must be 0 in DVI mode.
 *
 * Values:
 * RGB = 0x0 - 
 * RBG = 0x1 - 
 * GBR = 0x2 - 
 * GRB = 0x3 - 
 * BRG = 0x4 - 
 * BGR = 0x5 - 
 */

#define BP_ELCDIF_CTRL2_ODD_LINE_PATTERN      (16)      //!< Bit position for ELCDIF_CTRL2_ODD_LINE_PATTERN.
#define BM_ELCDIF_CTRL2_ODD_LINE_PATTERN      (0x00070000)  //!< Bit mask for ELCDIF_CTRL2_ODD_LINE_PATTERN.

//! @brief Get value of ELCDIF_CTRL2_ODD_LINE_PATTERN from a register value.
#define BG_ELCDIF_CTRL2_ODD_LINE_PATTERN(r)   (((r) & BM_ELCDIF_CTRL2_ODD_LINE_PATTERN) >> BP_ELCDIF_CTRL2_ODD_LINE_PATTERN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_ODD_LINE_PATTERN.
#define BF_ELCDIF_CTRL2_ODD_LINE_PATTERN(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_ODD_LINE_PATTERN) & BM_ELCDIF_CTRL2_ODD_LINE_PATTERN)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_ODD_LINE_PATTERN.
#define BF_ELCDIF_CTRL2_ODD_LINE_PATTERN(v)   (((v) << BP_ELCDIF_CTRL2_ODD_LINE_PATTERN) & BM_ELCDIF_CTRL2_ODD_LINE_PATTERN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ODD_LINE_PATTERN field to a new value.
#define BW_ELCDIF_CTRL2_ODD_LINE_PATTERN(v)   BF_CS1(ELCDIF_CTRL2, ODD_LINE_PATTERN, v)
#endif

#define BV_ELCDIF_CTRL2_ODD_LINE_PATTERN__RGB (0x0) //!< 
#define BV_ELCDIF_CTRL2_ODD_LINE_PATTERN__RBG (0x1) //!< 
#define BV_ELCDIF_CTRL2_ODD_LINE_PATTERN__GBR (0x2) //!< 
#define BV_ELCDIF_CTRL2_ODD_LINE_PATTERN__GRB (0x3) //!< 
#define BV_ELCDIF_CTRL2_ODD_LINE_PATTERN__BRG (0x4) //!< 
#define BV_ELCDIF_CTRL2_ODD_LINE_PATTERN__BGR (0x5) //!< 

/* --- Register HW_ELCDIF_CTRL2, field BURST_LEN_8[20] (RW)
 *
 * By default, when the eLCDIF is in the bus master mode, it will issue AXI bursts of length 16
 * (except when in packed 24 bpp mode, it will issue bursts of length 15). When this bit is set to
 * 1, the block will issue bursts of length 8 (except when in packed 24 bpp mode, it will issue
 * bursts of length 9). Note that this bitfield is only applicable when LCDIF_MASTER is set to 1.
 */

#define BP_ELCDIF_CTRL2_BURST_LEN_8      (20)      //!< Bit position for ELCDIF_CTRL2_BURST_LEN_8.
#define BM_ELCDIF_CTRL2_BURST_LEN_8      (0x00100000)  //!< Bit mask for ELCDIF_CTRL2_BURST_LEN_8.

//! @brief Get value of ELCDIF_CTRL2_BURST_LEN_8 from a register value.
#define BG_ELCDIF_CTRL2_BURST_LEN_8(r)   (((r) & BM_ELCDIF_CTRL2_BURST_LEN_8) >> BP_ELCDIF_CTRL2_BURST_LEN_8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_BURST_LEN_8.
#define BF_ELCDIF_CTRL2_BURST_LEN_8(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_BURST_LEN_8) & BM_ELCDIF_CTRL2_BURST_LEN_8)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_BURST_LEN_8.
#define BF_ELCDIF_CTRL2_BURST_LEN_8(v)   (((v) << BP_ELCDIF_CTRL2_BURST_LEN_8) & BM_ELCDIF_CTRL2_BURST_LEN_8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BURST_LEN_8 field to a new value.
#define BW_ELCDIF_CTRL2_BURST_LEN_8(v)   BF_CS1(ELCDIF_CTRL2, BURST_LEN_8, v)
#endif

/* --- Register HW_ELCDIF_CTRL2, field OUTSTANDING_REQS[23:21] (RW)
 *
 * This bitfield indicates the maximum number of outstanding transactions that eLCDIF should request
 * when it is acting as a bus master. Default is 2 outstanding transactions.
 *
 * Values:
 * REQ_1 = 0x0 - 
 * REQ_2 = 0x1 - 
 * REQ_4 = 0x2 - 
 * REQ_8 = 0x3 - 
 * REQ_16 = 0x4 - 
 */

#define BP_ELCDIF_CTRL2_OUTSTANDING_REQS      (21)      //!< Bit position for ELCDIF_CTRL2_OUTSTANDING_REQS.
#define BM_ELCDIF_CTRL2_OUTSTANDING_REQS      (0x00e00000)  //!< Bit mask for ELCDIF_CTRL2_OUTSTANDING_REQS.

//! @brief Get value of ELCDIF_CTRL2_OUTSTANDING_REQS from a register value.
#define BG_ELCDIF_CTRL2_OUTSTANDING_REQS(r)   (((r) & BM_ELCDIF_CTRL2_OUTSTANDING_REQS) >> BP_ELCDIF_CTRL2_OUTSTANDING_REQS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CTRL2_OUTSTANDING_REQS.
#define BF_ELCDIF_CTRL2_OUTSTANDING_REQS(v)   ((((reg32_t) v) << BP_ELCDIF_CTRL2_OUTSTANDING_REQS) & BM_ELCDIF_CTRL2_OUTSTANDING_REQS)
#else
//! @brief Format value for bitfield ELCDIF_CTRL2_OUTSTANDING_REQS.
#define BF_ELCDIF_CTRL2_OUTSTANDING_REQS(v)   (((v) << BP_ELCDIF_CTRL2_OUTSTANDING_REQS) & BM_ELCDIF_CTRL2_OUTSTANDING_REQS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OUTSTANDING_REQS field to a new value.
#define BW_ELCDIF_CTRL2_OUTSTANDING_REQS(v)   BF_CS1(ELCDIF_CTRL2, OUTSTANDING_REQS, v)
#endif

#define BV_ELCDIF_CTRL2_OUTSTANDING_REQS__REQ_1 (0x0) //!< 
#define BV_ELCDIF_CTRL2_OUTSTANDING_REQS__REQ_2 (0x1) //!< 
#define BV_ELCDIF_CTRL2_OUTSTANDING_REQS__REQ_4 (0x2) //!< 
#define BV_ELCDIF_CTRL2_OUTSTANDING_REQS__REQ_8 (0x3) //!< 
#define BV_ELCDIF_CTRL2_OUTSTANDING_REQS__REQ_16 (0x4) //!< 

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_TRANSFER_COUNT - eLCDIF Horizontal and Vertical Valid Data Count Register (RW)
 *
 * Reset value: 0x00010000
 *
 * This register tells the eLCDIF how much data will be sent for this frame, or transaction. The
 * total number of words is a product of the V_COUNT and H_COUNT fields. The word size is specified
 * by the WORD_LENGTH field.  This register gives the dimensions of the input frame. For normal
 * operation, but V_COUNT and H_COUNT should be non-zero.
 */
typedef union _hw_elcdif_transfer_count
{
    reg32_t U;
    struct _hw_elcdif_transfer_count_bitfields
    {
        unsigned H_COUNT : 16; //!< [15:0] Total valid data (pixels) in each horizontal line. The data size is given by the WORD_LENGTH. When input data is is in YCbCr 4:2:2 format (YCBCR422_INPUT is 1), H_COUNT should be the number of 32-bit words that should be fetched by the block and the BYTE_PACKING_FORMAT should be 0xF. In 24-bit packed format (WORD_LENGTH=0x3, BYTE_PACKING_FORMAT=0xF), the H_COUNT must be a multiple of 4 pixels. In 16-bit packed format (WORD_LENGTH=0x0, BYTE_PACKING_FORMAT=0xF), the H_COUNT must be a multiple of 2 pixels.
        unsigned V_COUNT : 16; //!< [31:16] Number of horizontal lines per frame which contain valid data. In DOTCLK mode, V_COUNT should be the same as the number of active horizontal lines in a progressive frame. In DVI mode, V_COUNT should be the number of active horizontal lines per frame, and not per field.
    } B;
} hw_elcdif_transfer_count_t;
#endif

/*
 * constants & macros for entire ELCDIF_TRANSFER_COUNT register
 */
#define HW_ELCDIF_TRANSFER_COUNT_ADDR      (REGS_ELCDIF_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_TRANSFER_COUNT           (*(volatile hw_elcdif_transfer_count_t *) HW_ELCDIF_TRANSFER_COUNT_ADDR)
#define HW_ELCDIF_TRANSFER_COUNT_RD()      (HW_ELCDIF_TRANSFER_COUNT.U)
#define HW_ELCDIF_TRANSFER_COUNT_WR(v)     (HW_ELCDIF_TRANSFER_COUNT.U = (v))
#define HW_ELCDIF_TRANSFER_COUNT_SET(v)    (HW_ELCDIF_TRANSFER_COUNT_WR(HW_ELCDIF_TRANSFER_COUNT_RD() |  (v)))
#define HW_ELCDIF_TRANSFER_COUNT_CLR(v)    (HW_ELCDIF_TRANSFER_COUNT_WR(HW_ELCDIF_TRANSFER_COUNT_RD() & ~(v)))
#define HW_ELCDIF_TRANSFER_COUNT_TOG(v)    (HW_ELCDIF_TRANSFER_COUNT_WR(HW_ELCDIF_TRANSFER_COUNT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_TRANSFER_COUNT bitfields
 */

/* --- Register HW_ELCDIF_TRANSFER_COUNT, field H_COUNT[15:0] (RW)
 *
 * Total valid data (pixels) in each horizontal line. The data size is given by the WORD_LENGTH.
 * When input data is is in YCbCr 4:2:2 format (YCBCR422_INPUT is 1), H_COUNT should be the number
 * of 32-bit words that should be fetched by the block and the BYTE_PACKING_FORMAT should be 0xF. In
 * 24-bit packed format (WORD_LENGTH=0x3, BYTE_PACKING_FORMAT=0xF), the H_COUNT must be a multiple
 * of 4 pixels. In 16-bit packed format (WORD_LENGTH=0x0, BYTE_PACKING_FORMAT=0xF), the H_COUNT must
 * be a multiple of 2 pixels.
 */

#define BP_ELCDIF_TRANSFER_COUNT_H_COUNT      (0)      //!< Bit position for ELCDIF_TRANSFER_COUNT_H_COUNT.
#define BM_ELCDIF_TRANSFER_COUNT_H_COUNT      (0x0000ffff)  //!< Bit mask for ELCDIF_TRANSFER_COUNT_H_COUNT.

//! @brief Get value of ELCDIF_TRANSFER_COUNT_H_COUNT from a register value.
#define BG_ELCDIF_TRANSFER_COUNT_H_COUNT(r)   (((r) & BM_ELCDIF_TRANSFER_COUNT_H_COUNT) >> BP_ELCDIF_TRANSFER_COUNT_H_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_TRANSFER_COUNT_H_COUNT.
#define BF_ELCDIF_TRANSFER_COUNT_H_COUNT(v)   ((((reg32_t) v) << BP_ELCDIF_TRANSFER_COUNT_H_COUNT) & BM_ELCDIF_TRANSFER_COUNT_H_COUNT)
#else
//! @brief Format value for bitfield ELCDIF_TRANSFER_COUNT_H_COUNT.
#define BF_ELCDIF_TRANSFER_COUNT_H_COUNT(v)   (((v) << BP_ELCDIF_TRANSFER_COUNT_H_COUNT) & BM_ELCDIF_TRANSFER_COUNT_H_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the H_COUNT field to a new value.
#define BW_ELCDIF_TRANSFER_COUNT_H_COUNT(v)   (HW_ELCDIF_TRANSFER_COUNT_WR((HW_ELCDIF_TRANSFER_COUNT_RD() & ~BM_ELCDIF_TRANSFER_COUNT_H_COUNT) | BF_ELCDIF_TRANSFER_COUNT_H_COUNT(v)))
#endif

/* --- Register HW_ELCDIF_TRANSFER_COUNT, field V_COUNT[31:16] (RW)
 *
 * Number of horizontal lines per frame which contain valid data. In DOTCLK mode, V_COUNT should be
 * the same as the number of active horizontal lines in a progressive frame. In DVI mode, V_COUNT
 * should be the number of active horizontal lines per frame, and not per field.
 */

#define BP_ELCDIF_TRANSFER_COUNT_V_COUNT      (16)      //!< Bit position for ELCDIF_TRANSFER_COUNT_V_COUNT.
#define BM_ELCDIF_TRANSFER_COUNT_V_COUNT      (0xffff0000)  //!< Bit mask for ELCDIF_TRANSFER_COUNT_V_COUNT.

//! @brief Get value of ELCDIF_TRANSFER_COUNT_V_COUNT from a register value.
#define BG_ELCDIF_TRANSFER_COUNT_V_COUNT(r)   (((r) & BM_ELCDIF_TRANSFER_COUNT_V_COUNT) >> BP_ELCDIF_TRANSFER_COUNT_V_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_TRANSFER_COUNT_V_COUNT.
#define BF_ELCDIF_TRANSFER_COUNT_V_COUNT(v)   ((((reg32_t) v) << BP_ELCDIF_TRANSFER_COUNT_V_COUNT) & BM_ELCDIF_TRANSFER_COUNT_V_COUNT)
#else
//! @brief Format value for bitfield ELCDIF_TRANSFER_COUNT_V_COUNT.
#define BF_ELCDIF_TRANSFER_COUNT_V_COUNT(v)   (((v) << BP_ELCDIF_TRANSFER_COUNT_V_COUNT) & BM_ELCDIF_TRANSFER_COUNT_V_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the V_COUNT field to a new value.
#define BW_ELCDIF_TRANSFER_COUNT_V_COUNT(v)   (HW_ELCDIF_TRANSFER_COUNT_WR((HW_ELCDIF_TRANSFER_COUNT_RD() & ~BM_ELCDIF_TRANSFER_COUNT_V_COUNT) | BF_ELCDIF_TRANSFER_COUNT_V_COUNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CUR_BUF - LCD Interface Current Buffer Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register indicates the address of the current frame being transmitted by eLCDIF.  When the
 * eLCDIF is behaving as a master, this address points to the address of the current frame of data
 * being sent out via the LCDIF. When the current frame is done, the LCDIF block will assert the
 * cur_frame_done interrupt for software to take action. The block will also copy the
 * LCDIF_NEXT_BUF_ADDR into this bitfield so that the software can program the next frame address
 * into the LCDIF_NEXT_BUF_ADDR bitfield. This address must always be double-word aligned.
 */
typedef union _hw_elcdif_cur_buf
{
    reg32_t U;
    struct _hw_elcdif_cur_buf_bitfields
    {
        unsigned ADDR : 32; //!< [31:0] -
    } B;
} hw_elcdif_cur_buf_t;
#endif

/*
 * constants & macros for entire ELCDIF_CUR_BUF register
 */
#define HW_ELCDIF_CUR_BUF_ADDR      (REGS_ELCDIF_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CUR_BUF           (*(volatile hw_elcdif_cur_buf_t *) HW_ELCDIF_CUR_BUF_ADDR)
#define HW_ELCDIF_CUR_BUF_RD()      (HW_ELCDIF_CUR_BUF.U)
#define HW_ELCDIF_CUR_BUF_WR(v)     (HW_ELCDIF_CUR_BUF.U = (v))
#define HW_ELCDIF_CUR_BUF_SET(v)    (HW_ELCDIF_CUR_BUF_WR(HW_ELCDIF_CUR_BUF_RD() |  (v)))
#define HW_ELCDIF_CUR_BUF_CLR(v)    (HW_ELCDIF_CUR_BUF_WR(HW_ELCDIF_CUR_BUF_RD() & ~(v)))
#define HW_ELCDIF_CUR_BUF_TOG(v)    (HW_ELCDIF_CUR_BUF_WR(HW_ELCDIF_CUR_BUF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CUR_BUF bitfields
 */

/* --- Register HW_ELCDIF_CUR_BUF, field ADDR[31:0] (RW)
 *
 * -
 */

#define BP_ELCDIF_CUR_BUF_ADDR      (0)      //!< Bit position for ELCDIF_CUR_BUF_ADDR.
#define BM_ELCDIF_CUR_BUF_ADDR      (0xffffffff)  //!< Bit mask for ELCDIF_CUR_BUF_ADDR.

//! @brief Get value of ELCDIF_CUR_BUF_ADDR from a register value.
#define BG_ELCDIF_CUR_BUF_ADDR(r)   (((r) & BM_ELCDIF_CUR_BUF_ADDR) >> BP_ELCDIF_CUR_BUF_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CUR_BUF_ADDR.
#define BF_ELCDIF_CUR_BUF_ADDR(v)   ((((reg32_t) v) << BP_ELCDIF_CUR_BUF_ADDR) & BM_ELCDIF_CUR_BUF_ADDR)
#else
//! @brief Format value for bitfield ELCDIF_CUR_BUF_ADDR.
#define BF_ELCDIF_CUR_BUF_ADDR(v)   (((v) << BP_ELCDIF_CUR_BUF_ADDR) & BM_ELCDIF_CUR_BUF_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_ELCDIF_CUR_BUF_ADDR(v)   (HW_ELCDIF_CUR_BUF_WR((HW_ELCDIF_CUR_BUF_RD() & ~BM_ELCDIF_CUR_BUF_ADDR) | BF_ELCDIF_CUR_BUF_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_NEXT_BUF - LCD Interface Next Buffer Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register indicates the address of next frame that will be transmitted by eLCDIF.  When the
 * eLCDIF is behaving as a master, this address points to the address of the next frame of data that
 * will be sent out via the eLCDIF. It is upto the software to make sure that this register is
 * programmed before the end of the current frame, otherwise it might result in old data going out
 * the eLCDIF. This address must always be double-word aligned.
 */
typedef union _hw_elcdif_next_buf
{
    reg32_t U;
    struct _hw_elcdif_next_buf_bitfields
    {
        unsigned ADDR : 32; //!< [31:0] -
    } B;
} hw_elcdif_next_buf_t;
#endif

/*
 * constants & macros for entire ELCDIF_NEXT_BUF register
 */
#define HW_ELCDIF_NEXT_BUF_ADDR      (REGS_ELCDIF_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_NEXT_BUF           (*(volatile hw_elcdif_next_buf_t *) HW_ELCDIF_NEXT_BUF_ADDR)
#define HW_ELCDIF_NEXT_BUF_RD()      (HW_ELCDIF_NEXT_BUF.U)
#define HW_ELCDIF_NEXT_BUF_WR(v)     (HW_ELCDIF_NEXT_BUF.U = (v))
#define HW_ELCDIF_NEXT_BUF_SET(v)    (HW_ELCDIF_NEXT_BUF_WR(HW_ELCDIF_NEXT_BUF_RD() |  (v)))
#define HW_ELCDIF_NEXT_BUF_CLR(v)    (HW_ELCDIF_NEXT_BUF_WR(HW_ELCDIF_NEXT_BUF_RD() & ~(v)))
#define HW_ELCDIF_NEXT_BUF_TOG(v)    (HW_ELCDIF_NEXT_BUF_WR(HW_ELCDIF_NEXT_BUF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_NEXT_BUF bitfields
 */

/* --- Register HW_ELCDIF_NEXT_BUF, field ADDR[31:0] (RW)
 *
 * -
 */

#define BP_ELCDIF_NEXT_BUF_ADDR      (0)      //!< Bit position for ELCDIF_NEXT_BUF_ADDR.
#define BM_ELCDIF_NEXT_BUF_ADDR      (0xffffffff)  //!< Bit mask for ELCDIF_NEXT_BUF_ADDR.

//! @brief Get value of ELCDIF_NEXT_BUF_ADDR from a register value.
#define BG_ELCDIF_NEXT_BUF_ADDR(r)   (((r) & BM_ELCDIF_NEXT_BUF_ADDR) >> BP_ELCDIF_NEXT_BUF_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_NEXT_BUF_ADDR.
#define BF_ELCDIF_NEXT_BUF_ADDR(v)   ((((reg32_t) v) << BP_ELCDIF_NEXT_BUF_ADDR) & BM_ELCDIF_NEXT_BUF_ADDR)
#else
//! @brief Format value for bitfield ELCDIF_NEXT_BUF_ADDR.
#define BF_ELCDIF_NEXT_BUF_ADDR(v)   (((v) << BP_ELCDIF_NEXT_BUF_ADDR) & BM_ELCDIF_NEXT_BUF_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_ELCDIF_NEXT_BUF_ADDR(v)   (HW_ELCDIF_NEXT_BUF_WR((HW_ELCDIF_NEXT_BUF_RD() & ~BM_ELCDIF_NEXT_BUF_ADDR) | BF_ELCDIF_NEXT_BUF_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_TIMING - LCD Interface Timing Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The LCD interface timing register controls the various setup and hold times enforced by the LCD
 * interface in the 6800/8080 MPU and VSYNC modes of operation.  The values used in this register
 * are dependent on the particular LCD controller used, consult the users manual for the particular
 * controller for required timings. Each field of the register must be non-zero, therefore the
 * minimum value is: 0x01010101. NOTE: the timings are not automatically adjusted if the
 * CLK_DIS_LCDIFn frequency changes--it may be necessary to adjust the timings if CLK_DIS_LCDIFn
 * changes. NOTE: Each field in this register must be non-zero for the MPU and VSYNC modes to
 * function. The settings in this register do not affect the DOTCLK and DVI modes.
 */
typedef union _hw_elcdif_timing
{
    reg32_t U;
    struct _hw_elcdif_timing_bitfields
    {
        unsigned DATA_SETUP : 8; //!< [7:0] Data bus setup time in CLK_DIS_LCDIFn cycles. Also the time that the data strobe is asserted in a cycle.
        unsigned DATA_HOLD : 8; //!< [15:8] Data bus hold time in CLK_DIS_LCDIFn cycles. Also the time that the data strobe is de-asserted in a cycle
        unsigned CMD_SETUP : 8; //!< [23:16] Number of CLK_DIS_LCDIFn cycles that the the DCn signal is active before CEn is asserted.
        unsigned CMD_HOLD : 8; //!< [31:24] Number of CLK_DIS_LCDIFn cycles that the DCn signal is active after CEn is deasserted.
    } B;
} hw_elcdif_timing_t;
#endif

/*
 * constants & macros for entire ELCDIF_TIMING register
 */
#define HW_ELCDIF_TIMING_ADDR      (REGS_ELCDIF_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_TIMING           (*(volatile hw_elcdif_timing_t *) HW_ELCDIF_TIMING_ADDR)
#define HW_ELCDIF_TIMING_RD()      (HW_ELCDIF_TIMING.U)
#define HW_ELCDIF_TIMING_WR(v)     (HW_ELCDIF_TIMING.U = (v))
#define HW_ELCDIF_TIMING_SET(v)    (HW_ELCDIF_TIMING_WR(HW_ELCDIF_TIMING_RD() |  (v)))
#define HW_ELCDIF_TIMING_CLR(v)    (HW_ELCDIF_TIMING_WR(HW_ELCDIF_TIMING_RD() & ~(v)))
#define HW_ELCDIF_TIMING_TOG(v)    (HW_ELCDIF_TIMING_WR(HW_ELCDIF_TIMING_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_TIMING bitfields
 */

/* --- Register HW_ELCDIF_TIMING, field DATA_SETUP[7:0] (RW)
 *
 * Data bus setup time in CLK_DIS_LCDIFn cycles. Also the time that the data strobe is asserted in a
 * cycle.
 */

#define BP_ELCDIF_TIMING_DATA_SETUP      (0)      //!< Bit position for ELCDIF_TIMING_DATA_SETUP.
#define BM_ELCDIF_TIMING_DATA_SETUP      (0x000000ff)  //!< Bit mask for ELCDIF_TIMING_DATA_SETUP.

//! @brief Get value of ELCDIF_TIMING_DATA_SETUP from a register value.
#define BG_ELCDIF_TIMING_DATA_SETUP(r)   (((r) & BM_ELCDIF_TIMING_DATA_SETUP) >> BP_ELCDIF_TIMING_DATA_SETUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_TIMING_DATA_SETUP.
#define BF_ELCDIF_TIMING_DATA_SETUP(v)   ((((reg32_t) v) << BP_ELCDIF_TIMING_DATA_SETUP) & BM_ELCDIF_TIMING_DATA_SETUP)
#else
//! @brief Format value for bitfield ELCDIF_TIMING_DATA_SETUP.
#define BF_ELCDIF_TIMING_DATA_SETUP(v)   (((v) << BP_ELCDIF_TIMING_DATA_SETUP) & BM_ELCDIF_TIMING_DATA_SETUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_SETUP field to a new value.
#define BW_ELCDIF_TIMING_DATA_SETUP(v)   (HW_ELCDIF_TIMING_WR((HW_ELCDIF_TIMING_RD() & ~BM_ELCDIF_TIMING_DATA_SETUP) | BF_ELCDIF_TIMING_DATA_SETUP(v)))
#endif

/* --- Register HW_ELCDIF_TIMING, field DATA_HOLD[15:8] (RW)
 *
 * Data bus hold time in CLK_DIS_LCDIFn cycles. Also the time that the data strobe is de-asserted in
 * a cycle
 */

#define BP_ELCDIF_TIMING_DATA_HOLD      (8)      //!< Bit position for ELCDIF_TIMING_DATA_HOLD.
#define BM_ELCDIF_TIMING_DATA_HOLD      (0x0000ff00)  //!< Bit mask for ELCDIF_TIMING_DATA_HOLD.

//! @brief Get value of ELCDIF_TIMING_DATA_HOLD from a register value.
#define BG_ELCDIF_TIMING_DATA_HOLD(r)   (((r) & BM_ELCDIF_TIMING_DATA_HOLD) >> BP_ELCDIF_TIMING_DATA_HOLD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_TIMING_DATA_HOLD.
#define BF_ELCDIF_TIMING_DATA_HOLD(v)   ((((reg32_t) v) << BP_ELCDIF_TIMING_DATA_HOLD) & BM_ELCDIF_TIMING_DATA_HOLD)
#else
//! @brief Format value for bitfield ELCDIF_TIMING_DATA_HOLD.
#define BF_ELCDIF_TIMING_DATA_HOLD(v)   (((v) << BP_ELCDIF_TIMING_DATA_HOLD) & BM_ELCDIF_TIMING_DATA_HOLD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_HOLD field to a new value.
#define BW_ELCDIF_TIMING_DATA_HOLD(v)   (HW_ELCDIF_TIMING_WR((HW_ELCDIF_TIMING_RD() & ~BM_ELCDIF_TIMING_DATA_HOLD) | BF_ELCDIF_TIMING_DATA_HOLD(v)))
#endif

/* --- Register HW_ELCDIF_TIMING, field CMD_SETUP[23:16] (RW)
 *
 * Number of CLK_DIS_LCDIFn cycles that the the DCn signal is active before CEn is asserted.
 */

#define BP_ELCDIF_TIMING_CMD_SETUP      (16)      //!< Bit position for ELCDIF_TIMING_CMD_SETUP.
#define BM_ELCDIF_TIMING_CMD_SETUP      (0x00ff0000)  //!< Bit mask for ELCDIF_TIMING_CMD_SETUP.

//! @brief Get value of ELCDIF_TIMING_CMD_SETUP from a register value.
#define BG_ELCDIF_TIMING_CMD_SETUP(r)   (((r) & BM_ELCDIF_TIMING_CMD_SETUP) >> BP_ELCDIF_TIMING_CMD_SETUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_TIMING_CMD_SETUP.
#define BF_ELCDIF_TIMING_CMD_SETUP(v)   ((((reg32_t) v) << BP_ELCDIF_TIMING_CMD_SETUP) & BM_ELCDIF_TIMING_CMD_SETUP)
#else
//! @brief Format value for bitfield ELCDIF_TIMING_CMD_SETUP.
#define BF_ELCDIF_TIMING_CMD_SETUP(v)   (((v) << BP_ELCDIF_TIMING_CMD_SETUP) & BM_ELCDIF_TIMING_CMD_SETUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CMD_SETUP field to a new value.
#define BW_ELCDIF_TIMING_CMD_SETUP(v)   (HW_ELCDIF_TIMING_WR((HW_ELCDIF_TIMING_RD() & ~BM_ELCDIF_TIMING_CMD_SETUP) | BF_ELCDIF_TIMING_CMD_SETUP(v)))
#endif

/* --- Register HW_ELCDIF_TIMING, field CMD_HOLD[31:24] (RW)
 *
 * Number of CLK_DIS_LCDIFn cycles that the DCn signal is active after CEn is deasserted.
 */

#define BP_ELCDIF_TIMING_CMD_HOLD      (24)      //!< Bit position for ELCDIF_TIMING_CMD_HOLD.
#define BM_ELCDIF_TIMING_CMD_HOLD      (0xff000000)  //!< Bit mask for ELCDIF_TIMING_CMD_HOLD.

//! @brief Get value of ELCDIF_TIMING_CMD_HOLD from a register value.
#define BG_ELCDIF_TIMING_CMD_HOLD(r)   (((r) & BM_ELCDIF_TIMING_CMD_HOLD) >> BP_ELCDIF_TIMING_CMD_HOLD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_TIMING_CMD_HOLD.
#define BF_ELCDIF_TIMING_CMD_HOLD(v)   ((((reg32_t) v) << BP_ELCDIF_TIMING_CMD_HOLD) & BM_ELCDIF_TIMING_CMD_HOLD)
#else
//! @brief Format value for bitfield ELCDIF_TIMING_CMD_HOLD.
#define BF_ELCDIF_TIMING_CMD_HOLD(v)   (((v) << BP_ELCDIF_TIMING_CMD_HOLD) & BM_ELCDIF_TIMING_CMD_HOLD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CMD_HOLD field to a new value.
#define BW_ELCDIF_TIMING_CMD_HOLD(v)   (HW_ELCDIF_TIMING_WR((HW_ELCDIF_TIMING_RD() & ~BM_ELCDIF_TIMING_CMD_HOLD) | BF_ELCDIF_TIMING_CMD_HOLD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_VDCTRL0 - eLCDIF VSYNC Mode and Dotclk Mode Control Register0 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to control the VSYNC and DOTCLK modes of the LCDIF so as to work with
 * different types of LCDs like moving picture displays and delta pixel displays.  This register
 * gives general programmability to the VSYNC signal including polarity, direction, pulse width,
 * etc.
 */
typedef union _hw_elcdif_vdctrl0
{
    reg32_t U;
    struct _hw_elcdif_vdctrl0_bitfields
    {
        unsigned VSYNC_PULSE_WIDTH : 18; //!< [17:0] Number of units for which VSYNC signal is active. For the DOTCLK mode, the unit is determined by the VSYNC_PULSE_WIDTH_UNIT. If the VSYNC_PULSE_WIDTH_UNIT is 0 for DOTCLK mode, VSYNC_PULSE_WIDTH must be less than HSYNC_PERIOD. For the VSYNC interface mode, it should be in terms of number of CLK_DIS_LCDIFn cycles only.
        unsigned HALF_LINE_MODE : 1; //!< [18] When this bit is 0, the first field (VSYNC period) will end in half a horizontal line and the second field will begin with half a horizontal line. When this bit is 1, all fields will end with half a horizontal line, and none will begin with half a horizontal line.
        unsigned HALF_LINE : 1; //!< [19] Setting this bit to 1 will make the total VSYNC period equal to the VSYNC_PERIOD field plus half the HORIZONTAL_PERIOD field (i.e. VSYNC_PERIOD field plus half horizontal line), otherwise it is just VSYNC_PERIOD. Should be only used in the DOTCLK mode, not in the VSYNC interface mode.
        unsigned VSYNC_PULSE_WIDTH_UNIT : 1; //!< [20] Default 0 for counting VSYNC_PULSE_WIDTH in terms of CLK_DIS_LCDIFn cycles. Set it to 1 to count in terms of complete horizontal lines.
        unsigned VSYNC_PERIOD_UNIT : 1; //!< [21] Default 0 for counting VSYNC_PERIOD in terms of CLK_DIS_LCDIFn cycles. Set it to 1 to count in terms of complete horizontal lines. CLK_DIS_LCDIFn cycles should be used in the VSYNC mode, while horizontal line should be used in the DOTCLK mode.
        unsigned RESERVED0 : 2; //!< [23:22] Reserved bits. Write as 0.
        unsigned ENABLE_POL : 1; //!< [24] Default 0 active low during valid data transfer on each horizontal line.
        unsigned DOTCLK_POL : 1; //!< [25] Default is data launched at negative edge of DOTCLK and captured at positive edge. Set it to 1 to invert the polarity. Set it to 0 in DVI mode.
        unsigned HSYNC_POL : 1; //!< [26] Default 0 active low during HSYNC_PULSE_WIDTH time and will be high during the rest of the HSYNC period. Set it to 1 to invert the polarity.
        unsigned VSYNC_POL : 1; //!< [27] Default 0 active low during VSYNC_PULSE_WIDTH time and will be high during the rest of the VSYNC period. Set it to 1 to invert the polarity.
        unsigned ENABLE_PRESENT : 1; //!< [28] Setting this bit to 1 will make the hardware generate the ENABLE signal in the DOTCLK mode, thereby making it the true RGB interface along with the remaining three signals VSYNC, HSYNC and DOTCLK.
        unsigned VSYNC_OEB : 1; //!< [29] 0 means the VSYNC signal is an output, 1 means it is an input. Should be set to 0 in the DOTCLK mode.
        unsigned RESERVED1 : 2; //!< [31:30] Reserved bits. Write as 0.
    } B;
} hw_elcdif_vdctrl0_t;
#endif

/*
 * constants & macros for entire ELCDIF_VDCTRL0 register
 */
#define HW_ELCDIF_VDCTRL0_ADDR      (REGS_ELCDIF_BASE + 0x70)
#define HW_ELCDIF_VDCTRL0_SET_ADDR  (HW_ELCDIF_VDCTRL0_ADDR + 0x4)
#define HW_ELCDIF_VDCTRL0_CLR_ADDR  (HW_ELCDIF_VDCTRL0_ADDR + 0x8)
#define HW_ELCDIF_VDCTRL0_TOG_ADDR  (HW_ELCDIF_VDCTRL0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_VDCTRL0           (*(volatile hw_elcdif_vdctrl0_t *) HW_ELCDIF_VDCTRL0_ADDR)
#define HW_ELCDIF_VDCTRL0_RD()      (HW_ELCDIF_VDCTRL0.U)
#define HW_ELCDIF_VDCTRL0_WR(v)     (HW_ELCDIF_VDCTRL0.U = (v))
#define HW_ELCDIF_VDCTRL0_SET(v)    ((*(volatile reg32_t *) HW_ELCDIF_VDCTRL0_SET_ADDR) = (v))
#define HW_ELCDIF_VDCTRL0_CLR(v)    ((*(volatile reg32_t *) HW_ELCDIF_VDCTRL0_CLR_ADDR) = (v))
#define HW_ELCDIF_VDCTRL0_TOG(v)    ((*(volatile reg32_t *) HW_ELCDIF_VDCTRL0_TOG_ADDR) = (v))
#endif

/*
 * constants & macros for individual ELCDIF_VDCTRL0 bitfields
 */

/* --- Register HW_ELCDIF_VDCTRL0, field VSYNC_PULSE_WIDTH[17:0] (RW)
 *
 * Number of units for which VSYNC signal is active. For the DOTCLK mode, the unit is determined by
 * the VSYNC_PULSE_WIDTH_UNIT. If the VSYNC_PULSE_WIDTH_UNIT is 0 for DOTCLK mode, VSYNC_PULSE_WIDTH
 * must be less than HSYNC_PERIOD. For the VSYNC interface mode, it should be in terms of number of
 * CLK_DIS_LCDIFn cycles only.
 */

#define BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH      (0)      //!< Bit position for ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH.
#define BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH      (0x0003ffff)  //!< Bit mask for ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH.

//! @brief Get value of ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH from a register value.
#define BG_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH(r)   (((r) & BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH) >> BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH.
#define BF_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH) & BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH.
#define BF_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH(v)   (((v) << BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH) & BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_PULSE_WIDTH field to a new value.
#define BW_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH(v)   BF_CS1(ELCDIF_VDCTRL0, VSYNC_PULSE_WIDTH, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field HALF_LINE_MODE[18] (RW)
 *
 * When this bit is 0, the first field (VSYNC period) will end in half a horizontal line and the
 * second field will begin with half a horizontal line. When this bit is 1, all fields will end with
 * half a horizontal line, and none will begin with half a horizontal line.
 */

#define BP_ELCDIF_VDCTRL0_HALF_LINE_MODE      (18)      //!< Bit position for ELCDIF_VDCTRL0_HALF_LINE_MODE.
#define BM_ELCDIF_VDCTRL0_HALF_LINE_MODE      (0x00040000)  //!< Bit mask for ELCDIF_VDCTRL0_HALF_LINE_MODE.

//! @brief Get value of ELCDIF_VDCTRL0_HALF_LINE_MODE from a register value.
#define BG_ELCDIF_VDCTRL0_HALF_LINE_MODE(r)   (((r) & BM_ELCDIF_VDCTRL0_HALF_LINE_MODE) >> BP_ELCDIF_VDCTRL0_HALF_LINE_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_HALF_LINE_MODE.
#define BF_ELCDIF_VDCTRL0_HALF_LINE_MODE(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_HALF_LINE_MODE) & BM_ELCDIF_VDCTRL0_HALF_LINE_MODE)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_HALF_LINE_MODE.
#define BF_ELCDIF_VDCTRL0_HALF_LINE_MODE(v)   (((v) << BP_ELCDIF_VDCTRL0_HALF_LINE_MODE) & BM_ELCDIF_VDCTRL0_HALF_LINE_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LINE_MODE field to a new value.
#define BW_ELCDIF_VDCTRL0_HALF_LINE_MODE(v)   BF_CS1(ELCDIF_VDCTRL0, HALF_LINE_MODE, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field HALF_LINE[19] (RW)
 *
 * Setting this bit to 1 will make the total VSYNC period equal to the VSYNC_PERIOD field plus half
 * the HORIZONTAL_PERIOD field (i.e. VSYNC_PERIOD field plus half horizontal line), otherwise it is
 * just VSYNC_PERIOD. Should be only used in the DOTCLK mode, not in the VSYNC interface mode.
 */

#define BP_ELCDIF_VDCTRL0_HALF_LINE      (19)      //!< Bit position for ELCDIF_VDCTRL0_HALF_LINE.
#define BM_ELCDIF_VDCTRL0_HALF_LINE      (0x00080000)  //!< Bit mask for ELCDIF_VDCTRL0_HALF_LINE.

//! @brief Get value of ELCDIF_VDCTRL0_HALF_LINE from a register value.
#define BG_ELCDIF_VDCTRL0_HALF_LINE(r)   (((r) & BM_ELCDIF_VDCTRL0_HALF_LINE) >> BP_ELCDIF_VDCTRL0_HALF_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_HALF_LINE.
#define BF_ELCDIF_VDCTRL0_HALF_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_HALF_LINE) & BM_ELCDIF_VDCTRL0_HALF_LINE)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_HALF_LINE.
#define BF_ELCDIF_VDCTRL0_HALF_LINE(v)   (((v) << BP_ELCDIF_VDCTRL0_HALF_LINE) & BM_ELCDIF_VDCTRL0_HALF_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HALF_LINE field to a new value.
#define BW_ELCDIF_VDCTRL0_HALF_LINE(v)   BF_CS1(ELCDIF_VDCTRL0, HALF_LINE, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field VSYNC_PULSE_WIDTH_UNIT[20] (RW)
 *
 * Default 0 for counting VSYNC_PULSE_WIDTH in terms of CLK_DIS_LCDIFn cycles. Set it to 1 to count
 * in terms of complete horizontal lines.
 */

#define BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT      (20)      //!< Bit position for ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT.
#define BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT      (0x00100000)  //!< Bit mask for ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT.

//! @brief Get value of ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT from a register value.
#define BG_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT(r)   (((r) & BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT) >> BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT.
#define BF_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT) & BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT.
#define BF_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT(v)   (((v) << BP_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT) & BM_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_PULSE_WIDTH_UNIT field to a new value.
#define BW_ELCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT(v)   BF_CS1(ELCDIF_VDCTRL0, VSYNC_PULSE_WIDTH_UNIT, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field VSYNC_PERIOD_UNIT[21] (RW)
 *
 * Default 0 for counting VSYNC_PERIOD in terms of CLK_DIS_LCDIFn cycles. Set it to 1 to count in
 * terms of complete horizontal lines. CLK_DIS_LCDIFn cycles should be used in the VSYNC mode, while
 * horizontal line should be used in the DOTCLK mode.
 */

#define BP_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT      (21)      //!< Bit position for ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT.
#define BM_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT      (0x00200000)  //!< Bit mask for ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT.

//! @brief Get value of ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT from a register value.
#define BG_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT(r)   (((r) & BM_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT) >> BP_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT.
#define BF_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT) & BM_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT.
#define BF_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT(v)   (((v) << BP_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT) & BM_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_PERIOD_UNIT field to a new value.
#define BW_ELCDIF_VDCTRL0_VSYNC_PERIOD_UNIT(v)   BF_CS1(ELCDIF_VDCTRL0, VSYNC_PERIOD_UNIT, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field ENABLE_POL[24] (RW)
 *
 * Default 0 active low during valid data transfer on each horizontal line.
 */

#define BP_ELCDIF_VDCTRL0_ENABLE_POL      (24)      //!< Bit position for ELCDIF_VDCTRL0_ENABLE_POL.
#define BM_ELCDIF_VDCTRL0_ENABLE_POL      (0x01000000)  //!< Bit mask for ELCDIF_VDCTRL0_ENABLE_POL.

//! @brief Get value of ELCDIF_VDCTRL0_ENABLE_POL from a register value.
#define BG_ELCDIF_VDCTRL0_ENABLE_POL(r)   (((r) & BM_ELCDIF_VDCTRL0_ENABLE_POL) >> BP_ELCDIF_VDCTRL0_ENABLE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_ENABLE_POL.
#define BF_ELCDIF_VDCTRL0_ENABLE_POL(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_ENABLE_POL) & BM_ELCDIF_VDCTRL0_ENABLE_POL)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_ENABLE_POL.
#define BF_ELCDIF_VDCTRL0_ENABLE_POL(v)   (((v) << BP_ELCDIF_VDCTRL0_ENABLE_POL) & BM_ELCDIF_VDCTRL0_ENABLE_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_POL field to a new value.
#define BW_ELCDIF_VDCTRL0_ENABLE_POL(v)   BF_CS1(ELCDIF_VDCTRL0, ENABLE_POL, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field DOTCLK_POL[25] (RW)
 *
 * Default is data launched at negative edge of DOTCLK and captured at positive edge. Set it to 1 to
 * invert the polarity. Set it to 0 in DVI mode.
 */

#define BP_ELCDIF_VDCTRL0_DOTCLK_POL      (25)      //!< Bit position for ELCDIF_VDCTRL0_DOTCLK_POL.
#define BM_ELCDIF_VDCTRL0_DOTCLK_POL      (0x02000000)  //!< Bit mask for ELCDIF_VDCTRL0_DOTCLK_POL.

//! @brief Get value of ELCDIF_VDCTRL0_DOTCLK_POL from a register value.
#define BG_ELCDIF_VDCTRL0_DOTCLK_POL(r)   (((r) & BM_ELCDIF_VDCTRL0_DOTCLK_POL) >> BP_ELCDIF_VDCTRL0_DOTCLK_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_DOTCLK_POL.
#define BF_ELCDIF_VDCTRL0_DOTCLK_POL(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_DOTCLK_POL) & BM_ELCDIF_VDCTRL0_DOTCLK_POL)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_DOTCLK_POL.
#define BF_ELCDIF_VDCTRL0_DOTCLK_POL(v)   (((v) << BP_ELCDIF_VDCTRL0_DOTCLK_POL) & BM_ELCDIF_VDCTRL0_DOTCLK_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOTCLK_POL field to a new value.
#define BW_ELCDIF_VDCTRL0_DOTCLK_POL(v)   BF_CS1(ELCDIF_VDCTRL0, DOTCLK_POL, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field HSYNC_POL[26] (RW)
 *
 * Default 0 active low during HSYNC_PULSE_WIDTH time and will be high during the rest of the HSYNC
 * period. Set it to 1 to invert the polarity.
 */

#define BP_ELCDIF_VDCTRL0_HSYNC_POL      (26)      //!< Bit position for ELCDIF_VDCTRL0_HSYNC_POL.
#define BM_ELCDIF_VDCTRL0_HSYNC_POL      (0x04000000)  //!< Bit mask for ELCDIF_VDCTRL0_HSYNC_POL.

//! @brief Get value of ELCDIF_VDCTRL0_HSYNC_POL from a register value.
#define BG_ELCDIF_VDCTRL0_HSYNC_POL(r)   (((r) & BM_ELCDIF_VDCTRL0_HSYNC_POL) >> BP_ELCDIF_VDCTRL0_HSYNC_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_HSYNC_POL.
#define BF_ELCDIF_VDCTRL0_HSYNC_POL(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_HSYNC_POL) & BM_ELCDIF_VDCTRL0_HSYNC_POL)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_HSYNC_POL.
#define BF_ELCDIF_VDCTRL0_HSYNC_POL(v)   (((v) << BP_ELCDIF_VDCTRL0_HSYNC_POL) & BM_ELCDIF_VDCTRL0_HSYNC_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_POL field to a new value.
#define BW_ELCDIF_VDCTRL0_HSYNC_POL(v)   BF_CS1(ELCDIF_VDCTRL0, HSYNC_POL, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field VSYNC_POL[27] (RW)
 *
 * Default 0 active low during VSYNC_PULSE_WIDTH time and will be high during the rest of the VSYNC
 * period. Set it to 1 to invert the polarity.
 */

#define BP_ELCDIF_VDCTRL0_VSYNC_POL      (27)      //!< Bit position for ELCDIF_VDCTRL0_VSYNC_POL.
#define BM_ELCDIF_VDCTRL0_VSYNC_POL      (0x08000000)  //!< Bit mask for ELCDIF_VDCTRL0_VSYNC_POL.

//! @brief Get value of ELCDIF_VDCTRL0_VSYNC_POL from a register value.
#define BG_ELCDIF_VDCTRL0_VSYNC_POL(r)   (((r) & BM_ELCDIF_VDCTRL0_VSYNC_POL) >> BP_ELCDIF_VDCTRL0_VSYNC_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_POL.
#define BF_ELCDIF_VDCTRL0_VSYNC_POL(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_VSYNC_POL) & BM_ELCDIF_VDCTRL0_VSYNC_POL)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_POL.
#define BF_ELCDIF_VDCTRL0_VSYNC_POL(v)   (((v) << BP_ELCDIF_VDCTRL0_VSYNC_POL) & BM_ELCDIF_VDCTRL0_VSYNC_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_POL field to a new value.
#define BW_ELCDIF_VDCTRL0_VSYNC_POL(v)   BF_CS1(ELCDIF_VDCTRL0, VSYNC_POL, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field ENABLE_PRESENT[28] (RW)
 *
 * Setting this bit to 1 will make the hardware generate the ENABLE signal in the DOTCLK mode,
 * thereby making it the true RGB interface along with the remaining three signals VSYNC, HSYNC and
 * DOTCLK.
 */

#define BP_ELCDIF_VDCTRL0_ENABLE_PRESENT      (28)      //!< Bit position for ELCDIF_VDCTRL0_ENABLE_PRESENT.
#define BM_ELCDIF_VDCTRL0_ENABLE_PRESENT      (0x10000000)  //!< Bit mask for ELCDIF_VDCTRL0_ENABLE_PRESENT.

//! @brief Get value of ELCDIF_VDCTRL0_ENABLE_PRESENT from a register value.
#define BG_ELCDIF_VDCTRL0_ENABLE_PRESENT(r)   (((r) & BM_ELCDIF_VDCTRL0_ENABLE_PRESENT) >> BP_ELCDIF_VDCTRL0_ENABLE_PRESENT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_ENABLE_PRESENT.
#define BF_ELCDIF_VDCTRL0_ENABLE_PRESENT(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_ENABLE_PRESENT) & BM_ELCDIF_VDCTRL0_ENABLE_PRESENT)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_ENABLE_PRESENT.
#define BF_ELCDIF_VDCTRL0_ENABLE_PRESENT(v)   (((v) << BP_ELCDIF_VDCTRL0_ENABLE_PRESENT) & BM_ELCDIF_VDCTRL0_ENABLE_PRESENT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_PRESENT field to a new value.
#define BW_ELCDIF_VDCTRL0_ENABLE_PRESENT(v)   BF_CS1(ELCDIF_VDCTRL0, ENABLE_PRESENT, v)
#endif

/* --- Register HW_ELCDIF_VDCTRL0, field VSYNC_OEB[29] (RW)
 *
 * 0 means the VSYNC signal is an output, 1 means it is an input. Should be set to 0 in the DOTCLK
 * mode.
 *
 * Values:
 * VSYNC_OUTPUT = 0x0 - The VSYNC pin is in the output mode and the VSYNC signal has to be generated by the eLCDIF block.
 * VSYNC_INPUT = 0x1 - The VSYNC pin is in the input mode and the LCD controller sends the VSYNC signal to the block.
 */

#define BP_ELCDIF_VDCTRL0_VSYNC_OEB      (29)      //!< Bit position for ELCDIF_VDCTRL0_VSYNC_OEB.
#define BM_ELCDIF_VDCTRL0_VSYNC_OEB      (0x20000000)  //!< Bit mask for ELCDIF_VDCTRL0_VSYNC_OEB.

//! @brief Get value of ELCDIF_VDCTRL0_VSYNC_OEB from a register value.
#define BG_ELCDIF_VDCTRL0_VSYNC_OEB(r)   (((r) & BM_ELCDIF_VDCTRL0_VSYNC_OEB) >> BP_ELCDIF_VDCTRL0_VSYNC_OEB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_OEB.
#define BF_ELCDIF_VDCTRL0_VSYNC_OEB(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL0_VSYNC_OEB) & BM_ELCDIF_VDCTRL0_VSYNC_OEB)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL0_VSYNC_OEB.
#define BF_ELCDIF_VDCTRL0_VSYNC_OEB(v)   (((v) << BP_ELCDIF_VDCTRL0_VSYNC_OEB) & BM_ELCDIF_VDCTRL0_VSYNC_OEB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_OEB field to a new value.
#define BW_ELCDIF_VDCTRL0_VSYNC_OEB(v)   BF_CS1(ELCDIF_VDCTRL0, VSYNC_OEB, v)
#endif

#define BV_ELCDIF_VDCTRL0_VSYNC_OEB__VSYNC_OUTPUT (0x0) //!< The VSYNC pin is in the output mode and the VSYNC signal has to be generated by the eLCDIF block.
#define BV_ELCDIF_VDCTRL0_VSYNC_OEB__VSYNC_INPUT (0x1) //!< The VSYNC pin is in the input mode and the LCD controller sends the VSYNC signal to the block.

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_VDCTRL1 - eLCDIF VSYNC Mode and Dotclk Mode Control Register1 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to control the VSYNC signal in the VSYNC and DOTCLK modes of the block.
 * This register determines the period and duty cycle of the VSYNC signal when it is generated in
 * the block.
 */
typedef union _hw_elcdif_vdctrl1
{
    reg32_t U;
    struct _hw_elcdif_vdctrl1_bitfields
    {
        unsigned VSYNC_PERIOD : 32; //!< [31:0] Total number of units between two positive or two negative edges of the VSYNC signal. If HALF_LINE is set, it is implicitly calculated to be VSYNC_PERIOD plus half HSYNC_PERIOD.
    } B;
} hw_elcdif_vdctrl1_t;
#endif

/*
 * constants & macros for entire ELCDIF_VDCTRL1 register
 */
#define HW_ELCDIF_VDCTRL1_ADDR      (REGS_ELCDIF_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_VDCTRL1           (*(volatile hw_elcdif_vdctrl1_t *) HW_ELCDIF_VDCTRL1_ADDR)
#define HW_ELCDIF_VDCTRL1_RD()      (HW_ELCDIF_VDCTRL1.U)
#define HW_ELCDIF_VDCTRL1_WR(v)     (HW_ELCDIF_VDCTRL1.U = (v))
#define HW_ELCDIF_VDCTRL1_SET(v)    (HW_ELCDIF_VDCTRL1_WR(HW_ELCDIF_VDCTRL1_RD() |  (v)))
#define HW_ELCDIF_VDCTRL1_CLR(v)    (HW_ELCDIF_VDCTRL1_WR(HW_ELCDIF_VDCTRL1_RD() & ~(v)))
#define HW_ELCDIF_VDCTRL1_TOG(v)    (HW_ELCDIF_VDCTRL1_WR(HW_ELCDIF_VDCTRL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_VDCTRL1 bitfields
 */

/* --- Register HW_ELCDIF_VDCTRL1, field VSYNC_PERIOD[31:0] (RW)
 *
 * Total number of units between two positive or two negative edges of the VSYNC signal. If
 * HALF_LINE is set, it is implicitly calculated to be VSYNC_PERIOD plus half HSYNC_PERIOD.
 */

#define BP_ELCDIF_VDCTRL1_VSYNC_PERIOD      (0)      //!< Bit position for ELCDIF_VDCTRL1_VSYNC_PERIOD.
#define BM_ELCDIF_VDCTRL1_VSYNC_PERIOD      (0xffffffff)  //!< Bit mask for ELCDIF_VDCTRL1_VSYNC_PERIOD.

//! @brief Get value of ELCDIF_VDCTRL1_VSYNC_PERIOD from a register value.
#define BG_ELCDIF_VDCTRL1_VSYNC_PERIOD(r)   (((r) & BM_ELCDIF_VDCTRL1_VSYNC_PERIOD) >> BP_ELCDIF_VDCTRL1_VSYNC_PERIOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL1_VSYNC_PERIOD.
#define BF_ELCDIF_VDCTRL1_VSYNC_PERIOD(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL1_VSYNC_PERIOD) & BM_ELCDIF_VDCTRL1_VSYNC_PERIOD)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL1_VSYNC_PERIOD.
#define BF_ELCDIF_VDCTRL1_VSYNC_PERIOD(v)   (((v) << BP_ELCDIF_VDCTRL1_VSYNC_PERIOD) & BM_ELCDIF_VDCTRL1_VSYNC_PERIOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_PERIOD field to a new value.
#define BW_ELCDIF_VDCTRL1_VSYNC_PERIOD(v)   (HW_ELCDIF_VDCTRL1_WR((HW_ELCDIF_VDCTRL1_RD() & ~BM_ELCDIF_VDCTRL1_VSYNC_PERIOD) | BF_ELCDIF_VDCTRL1_VSYNC_PERIOD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_VDCTRL2 - LCDIF VSYNC Mode and Dotclk Mode Control Register2 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to control the HSYNC signal in the DOTCLK mode of the block.  This register
 * determines the period and duty cycle of the HSYNC signal when it is generated in the block.
 */
typedef union _hw_elcdif_vdctrl2
{
    reg32_t U;
    struct _hw_elcdif_vdctrl2_bitfields
    {
        unsigned HSYNC_PERIOD : 18; //!< [17:0] Total number of CLK_DIS_LCDIFn cycles between two positive or two negative edges of the HSYNC signal.
        unsigned HSYNC_PULSE_WIDTH : 14; //!< [31:18] Number of CLK_DIS_LCDIFn cycles for which HSYNC signal is active.
    } B;
} hw_elcdif_vdctrl2_t;
#endif

/*
 * constants & macros for entire ELCDIF_VDCTRL2 register
 */
#define HW_ELCDIF_VDCTRL2_ADDR      (REGS_ELCDIF_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_VDCTRL2           (*(volatile hw_elcdif_vdctrl2_t *) HW_ELCDIF_VDCTRL2_ADDR)
#define HW_ELCDIF_VDCTRL2_RD()      (HW_ELCDIF_VDCTRL2.U)
#define HW_ELCDIF_VDCTRL2_WR(v)     (HW_ELCDIF_VDCTRL2.U = (v))
#define HW_ELCDIF_VDCTRL2_SET(v)    (HW_ELCDIF_VDCTRL2_WR(HW_ELCDIF_VDCTRL2_RD() |  (v)))
#define HW_ELCDIF_VDCTRL2_CLR(v)    (HW_ELCDIF_VDCTRL2_WR(HW_ELCDIF_VDCTRL2_RD() & ~(v)))
#define HW_ELCDIF_VDCTRL2_TOG(v)    (HW_ELCDIF_VDCTRL2_WR(HW_ELCDIF_VDCTRL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_VDCTRL2 bitfields
 */

/* --- Register HW_ELCDIF_VDCTRL2, field HSYNC_PERIOD[17:0] (RW)
 *
 * Total number of CLK_DIS_LCDIFn cycles between two positive or two negative edges of the HSYNC
 * signal.
 */

#define BP_ELCDIF_VDCTRL2_HSYNC_PERIOD      (0)      //!< Bit position for ELCDIF_VDCTRL2_HSYNC_PERIOD.
#define BM_ELCDIF_VDCTRL2_HSYNC_PERIOD      (0x0003ffff)  //!< Bit mask for ELCDIF_VDCTRL2_HSYNC_PERIOD.

//! @brief Get value of ELCDIF_VDCTRL2_HSYNC_PERIOD from a register value.
#define BG_ELCDIF_VDCTRL2_HSYNC_PERIOD(r)   (((r) & BM_ELCDIF_VDCTRL2_HSYNC_PERIOD) >> BP_ELCDIF_VDCTRL2_HSYNC_PERIOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL2_HSYNC_PERIOD.
#define BF_ELCDIF_VDCTRL2_HSYNC_PERIOD(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL2_HSYNC_PERIOD) & BM_ELCDIF_VDCTRL2_HSYNC_PERIOD)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL2_HSYNC_PERIOD.
#define BF_ELCDIF_VDCTRL2_HSYNC_PERIOD(v)   (((v) << BP_ELCDIF_VDCTRL2_HSYNC_PERIOD) & BM_ELCDIF_VDCTRL2_HSYNC_PERIOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_PERIOD field to a new value.
#define BW_ELCDIF_VDCTRL2_HSYNC_PERIOD(v)   (HW_ELCDIF_VDCTRL2_WR((HW_ELCDIF_VDCTRL2_RD() & ~BM_ELCDIF_VDCTRL2_HSYNC_PERIOD) | BF_ELCDIF_VDCTRL2_HSYNC_PERIOD(v)))
#endif

/* --- Register HW_ELCDIF_VDCTRL2, field HSYNC_PULSE_WIDTH[31:18] (RW)
 *
 * Number of CLK_DIS_LCDIFn cycles for which HSYNC signal is active.
 */

#define BP_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH      (18)      //!< Bit position for ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH.
#define BM_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH      (0xfffc0000)  //!< Bit mask for ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH.

//! @brief Get value of ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH from a register value.
#define BG_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(r)   (((r) & BM_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH) >> BP_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH.
#define BF_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH) & BM_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH.
#define BF_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(v)   (((v) << BP_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH) & BM_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_PULSE_WIDTH field to a new value.
#define BW_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(v)   (HW_ELCDIF_VDCTRL2_WR((HW_ELCDIF_VDCTRL2_RD() & ~BM_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH) | BF_ELCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_VDCTRL3 - eLCDIF VSYNC Mode and Dotclk Mode Control Register3 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to determine the vertical and horizontal wait counts.  This register
 * determines the back porches of HSYNC and VSYNC signals when they are generated by the block.
 */
typedef union _hw_elcdif_vdctrl3
{
    reg32_t U;
    struct _hw_elcdif_vdctrl3_bitfields
    {
        unsigned VERTICAL_WAIT_CNT : 16; //!< [15:0] In the VSYNC interface mode, wait for this number of CLK_DIS_LCDIFn cycles from the falling VSYNC edge (or rising if VSYNC_POL is 1) before starting LCD transactions and is applicable only if WAIT_FOR_VSYNC_EDGE is set. Minimum is CMD_SETUP+5. In the DOTCLK mode, it accounts for the veritcal back porch lines plus the number of horizontal lines before the moving picture begins. The unit for this parameter is inherently the same as the VSYNC_PERIOD_UNIT.
        unsigned HORIZONTAL_WAIT_CNT : 12; //!< [27:16] In the DOTCLK mode, wait for this number of clocks from falling edge (or rising if HSYNC_POL is 1) of HSYNC signal to account for horizontal back porch plus the number of DOTCLKs before the moving picture information begins.
        unsigned VSYNC_ONLY : 1; //!< [28] This bit must be set to 1 in the VSYNC mode of operation, and 0 in the DOTCLK mode of operation.
        unsigned MUX_SYNC_SIGNALS : 1; //!< [29] When this bit is set, the eLCDIF block will internally mux HSYNC with LCD_D14, DOTCLK with LCD_D13 and ENABLE with LCD_D12, otherwise these signals will go out on separate pins. This feature can be used to maintain backward compatability with 37xx.
        unsigned RESERVED0 : 2; //!< [31:30] Reserved bits, write as 0.
    } B;
} hw_elcdif_vdctrl3_t;
#endif

/*
 * constants & macros for entire ELCDIF_VDCTRL3 register
 */
#define HW_ELCDIF_VDCTRL3_ADDR      (REGS_ELCDIF_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_VDCTRL3           (*(volatile hw_elcdif_vdctrl3_t *) HW_ELCDIF_VDCTRL3_ADDR)
#define HW_ELCDIF_VDCTRL3_RD()      (HW_ELCDIF_VDCTRL3.U)
#define HW_ELCDIF_VDCTRL3_WR(v)     (HW_ELCDIF_VDCTRL3.U = (v))
#define HW_ELCDIF_VDCTRL3_SET(v)    (HW_ELCDIF_VDCTRL3_WR(HW_ELCDIF_VDCTRL3_RD() |  (v)))
#define HW_ELCDIF_VDCTRL3_CLR(v)    (HW_ELCDIF_VDCTRL3_WR(HW_ELCDIF_VDCTRL3_RD() & ~(v)))
#define HW_ELCDIF_VDCTRL3_TOG(v)    (HW_ELCDIF_VDCTRL3_WR(HW_ELCDIF_VDCTRL3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_VDCTRL3 bitfields
 */

/* --- Register HW_ELCDIF_VDCTRL3, field VERTICAL_WAIT_CNT[15:0] (RW)
 *
 * In the VSYNC interface mode, wait for this number of CLK_DIS_LCDIFn cycles from the falling VSYNC
 * edge (or rising if VSYNC_POL is 1) before starting LCD transactions and is applicable only if
 * WAIT_FOR_VSYNC_EDGE is set. Minimum is CMD_SETUP+5. In the DOTCLK mode, it accounts for the
 * veritcal back porch lines plus the number of horizontal lines before the moving picture begins.
 * The unit for this parameter is inherently the same as the VSYNC_PERIOD_UNIT.
 */

#define BP_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT      (0)      //!< Bit position for ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT.
#define BM_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT      (0x0000ffff)  //!< Bit mask for ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT.

//! @brief Get value of ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT from a register value.
#define BG_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT(r)   (((r) & BM_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT) >> BP_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT.
#define BF_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT) & BM_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT.
#define BF_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT(v)   (((v) << BP_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT) & BM_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VERTICAL_WAIT_CNT field to a new value.
#define BW_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT(v)   (HW_ELCDIF_VDCTRL3_WR((HW_ELCDIF_VDCTRL3_RD() & ~BM_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT) | BF_ELCDIF_VDCTRL3_VERTICAL_WAIT_CNT(v)))
#endif

/* --- Register HW_ELCDIF_VDCTRL3, field HORIZONTAL_WAIT_CNT[27:16] (RW)
 *
 * In the DOTCLK mode, wait for this number of clocks from falling edge (or rising if HSYNC_POL is
 * 1) of HSYNC signal to account for horizontal back porch plus the number of DOTCLKs before the
 * moving picture information begins.
 */

#define BP_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT      (16)      //!< Bit position for ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT.
#define BM_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT      (0x0fff0000)  //!< Bit mask for ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT.

//! @brief Get value of ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT from a register value.
#define BG_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(r)   (((r) & BM_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT) >> BP_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT.
#define BF_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT) & BM_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT.
#define BF_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(v)   (((v) << BP_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT) & BM_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HORIZONTAL_WAIT_CNT field to a new value.
#define BW_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(v)   (HW_ELCDIF_VDCTRL3_WR((HW_ELCDIF_VDCTRL3_RD() & ~BM_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT) | BF_ELCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(v)))
#endif

/* --- Register HW_ELCDIF_VDCTRL3, field VSYNC_ONLY[28] (RW)
 *
 * This bit must be set to 1 in the VSYNC mode of operation, and 0 in the DOTCLK mode of operation.
 */

#define BP_ELCDIF_VDCTRL3_VSYNC_ONLY      (28)      //!< Bit position for ELCDIF_VDCTRL3_VSYNC_ONLY.
#define BM_ELCDIF_VDCTRL3_VSYNC_ONLY      (0x10000000)  //!< Bit mask for ELCDIF_VDCTRL3_VSYNC_ONLY.

//! @brief Get value of ELCDIF_VDCTRL3_VSYNC_ONLY from a register value.
#define BG_ELCDIF_VDCTRL3_VSYNC_ONLY(r)   (((r) & BM_ELCDIF_VDCTRL3_VSYNC_ONLY) >> BP_ELCDIF_VDCTRL3_VSYNC_ONLY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL3_VSYNC_ONLY.
#define BF_ELCDIF_VDCTRL3_VSYNC_ONLY(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL3_VSYNC_ONLY) & BM_ELCDIF_VDCTRL3_VSYNC_ONLY)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL3_VSYNC_ONLY.
#define BF_ELCDIF_VDCTRL3_VSYNC_ONLY(v)   (((v) << BP_ELCDIF_VDCTRL3_VSYNC_ONLY) & BM_ELCDIF_VDCTRL3_VSYNC_ONLY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_ONLY field to a new value.
#define BW_ELCDIF_VDCTRL3_VSYNC_ONLY(v)   (HW_ELCDIF_VDCTRL3_WR((HW_ELCDIF_VDCTRL3_RD() & ~BM_ELCDIF_VDCTRL3_VSYNC_ONLY) | BF_ELCDIF_VDCTRL3_VSYNC_ONLY(v)))
#endif

/* --- Register HW_ELCDIF_VDCTRL3, field MUX_SYNC_SIGNALS[29] (RW)
 *
 * When this bit is set, the eLCDIF block will internally mux HSYNC with LCD_D14, DOTCLK with
 * LCD_D13 and ENABLE with LCD_D12, otherwise these signals will go out on separate pins. This
 * feature can be used to maintain backward compatability with 37xx.
 */

#define BP_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS      (29)      //!< Bit position for ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS.
#define BM_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS      (0x20000000)  //!< Bit mask for ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS.

//! @brief Get value of ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS from a register value.
#define BG_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS(r)   (((r) & BM_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS) >> BP_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS.
#define BF_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS) & BM_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS.
#define BF_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS(v)   (((v) << BP_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS) & BM_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MUX_SYNC_SIGNALS field to a new value.
#define BW_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS(v)   (HW_ELCDIF_VDCTRL3_WR((HW_ELCDIF_VDCTRL3_RD() & ~BM_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS) | BF_ELCDIF_VDCTRL3_MUX_SYNC_SIGNALS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_VDCTRL4 - eLCDIF VSYNC Mode and Dotclk Mode Control Register4 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register is used to control the DOTCLK mode of the block.  This register determines the
 * active data in each horizontal line in the DOTCLK mode. Note that the total number of active
 * horizontal lines in the DOTCLK mode is the same as the V_COUNT bitfield in the
 * LCDIF_TRANSFER_COUNT register.
 */
typedef union _hw_elcdif_vdctrl4
{
    reg32_t U;
    struct _hw_elcdif_vdctrl4_bitfields
    {
        unsigned DOTCLK_H_VALID_DATA_CNT : 18; //!< [17:0] Total number of CLK_DIS_LCDIFn cycles on each horizontal line that carry valid data in DOTCLK mode.
        unsigned SYNC_SIGNALS_ON : 1; //!< [18] Set this field to 1 if the LCD controller requires that the VSYNC or VSYNC/HSYNC/DOTCLK control signals should be active atleast one frame before the data transfers actually start and remain active atleast one frame after the data transfers end. The hardware does not count the number of frames automatically. Rather, the VSYNC edge interrupt can be monitored by software to count the number of frames that have occured after this bit is set and then the RUN bit can be set to start the data transactions. This bit must always be set in the DOTCLK mode of operation, and it must be set in the VSYNC mode of operation when VSYNC signal is an output.
        unsigned RESERVED0 : 10; //!< [28:19] Reserved bits, write as 0.
        unsigned DOTCLK_DLY_SEL : 3; //!< [31:29] This bitfield selects the amount of time by which the DOTCLK signal should be delayed before coming out of the LCD_DOTCK pin. 0 = 2ns; 1=4ns;2=6ns;3=8ns. Remaining values are reserved.
    } B;
} hw_elcdif_vdctrl4_t;
#endif

/*
 * constants & macros for entire ELCDIF_VDCTRL4 register
 */
#define HW_ELCDIF_VDCTRL4_ADDR      (REGS_ELCDIF_BASE + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_VDCTRL4           (*(volatile hw_elcdif_vdctrl4_t *) HW_ELCDIF_VDCTRL4_ADDR)
#define HW_ELCDIF_VDCTRL4_RD()      (HW_ELCDIF_VDCTRL4.U)
#define HW_ELCDIF_VDCTRL4_WR(v)     (HW_ELCDIF_VDCTRL4.U = (v))
#define HW_ELCDIF_VDCTRL4_SET(v)    (HW_ELCDIF_VDCTRL4_WR(HW_ELCDIF_VDCTRL4_RD() |  (v)))
#define HW_ELCDIF_VDCTRL4_CLR(v)    (HW_ELCDIF_VDCTRL4_WR(HW_ELCDIF_VDCTRL4_RD() & ~(v)))
#define HW_ELCDIF_VDCTRL4_TOG(v)    (HW_ELCDIF_VDCTRL4_WR(HW_ELCDIF_VDCTRL4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_VDCTRL4 bitfields
 */

/* --- Register HW_ELCDIF_VDCTRL4, field DOTCLK_H_VALID_DATA_CNT[17:0] (RW)
 *
 * Total number of CLK_DIS_LCDIFn cycles on each horizontal line that carry valid data in DOTCLK
 * mode.
 */

#define BP_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT      (0)      //!< Bit position for ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT.
#define BM_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT      (0x0003ffff)  //!< Bit mask for ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT.

//! @brief Get value of ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT from a register value.
#define BG_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(r)   (((r) & BM_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT) >> BP_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT.
#define BF_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT) & BM_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT.
#define BF_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(v)   (((v) << BP_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT) & BM_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOTCLK_H_VALID_DATA_CNT field to a new value.
#define BW_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(v)   (HW_ELCDIF_VDCTRL4_WR((HW_ELCDIF_VDCTRL4_RD() & ~BM_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT) | BF_ELCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(v)))
#endif

/* --- Register HW_ELCDIF_VDCTRL4, field SYNC_SIGNALS_ON[18] (RW)
 *
 * Set this field to 1 if the LCD controller requires that the VSYNC or VSYNC/HSYNC/DOTCLK control
 * signals should be active atleast one frame before the data transfers actually start and remain
 * active atleast one frame after the data transfers end. The hardware does not count the number of
 * frames automatically. Rather, the VSYNC edge interrupt can be monitored by software to count the
 * number of frames that have occured after this bit is set and then the RUN bit can be set to start
 * the data transactions. This bit must always be set in the DOTCLK mode of operation, and it must
 * be set in the VSYNC mode of operation when VSYNC signal is an output.
 */

#define BP_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON      (18)      //!< Bit position for ELCDIF_VDCTRL4_SYNC_SIGNALS_ON.
#define BM_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON      (0x00040000)  //!< Bit mask for ELCDIF_VDCTRL4_SYNC_SIGNALS_ON.

//! @brief Get value of ELCDIF_VDCTRL4_SYNC_SIGNALS_ON from a register value.
#define BG_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON(r)   (((r) & BM_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON) >> BP_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL4_SYNC_SIGNALS_ON.
#define BF_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON) & BM_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL4_SYNC_SIGNALS_ON.
#define BF_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON(v)   (((v) << BP_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON) & BM_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SYNC_SIGNALS_ON field to a new value.
#define BW_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON(v)   (HW_ELCDIF_VDCTRL4_WR((HW_ELCDIF_VDCTRL4_RD() & ~BM_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON) | BF_ELCDIF_VDCTRL4_SYNC_SIGNALS_ON(v)))
#endif

/* --- Register HW_ELCDIF_VDCTRL4, field DOTCLK_DLY_SEL[31:29] (RW)
 *
 * This bitfield selects the amount of time by which the DOTCLK signal should be delayed before
 * coming out of the LCD_DOTCK pin. 0 = 2ns; 1=4ns;2=6ns;3=8ns. Remaining values are reserved.
 */

#define BP_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL      (29)      //!< Bit position for ELCDIF_VDCTRL4_DOTCLK_DLY_SEL.
#define BM_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL      (0xe0000000)  //!< Bit mask for ELCDIF_VDCTRL4_DOTCLK_DLY_SEL.

//! @brief Get value of ELCDIF_VDCTRL4_DOTCLK_DLY_SEL from a register value.
#define BG_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL(r)   (((r) & BM_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL) >> BP_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_VDCTRL4_DOTCLK_DLY_SEL.
#define BF_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL(v)   ((((reg32_t) v) << BP_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL) & BM_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL)
#else
//! @brief Format value for bitfield ELCDIF_VDCTRL4_DOTCLK_DLY_SEL.
#define BF_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL(v)   (((v) << BP_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL) & BM_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DOTCLK_DLY_SEL field to a new value.
#define BW_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL(v)   (HW_ELCDIF_VDCTRL4_WR((HW_ELCDIF_VDCTRL4_RD() & ~BM_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL) | BF_ELCDIF_VDCTRL4_DOTCLK_DLY_SEL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DVICTRL0 - Digital Video Interface Control0 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The Digital Video interface Control0 register provides the overall control of the Digital Video
 * interface.  This register gives information about the horizontal active, horizontal blanking and
 * total number of lines in the ITU-R BT.656 interface.   EXAMPLE   //525/60 video system
 * HW_LCDIF_DVICTRL0_H_ACTIVE_CNT_WR(0x5A0);//1440 HW_LCDIF_DVICTRL0_H_BLANKING_CNT_WR(0x106);//262
 * //625/50 video system HW_LCDIF_DVICTRL0_H_ACTIVE_CNT_WR(0x5A0);//1440
 * HW_LCDIF_DVICTRL0_H_BLANKING_CNT_WR(0x112);//274
 */
typedef union _hw_elcdif_dvictrl0
{
    reg32_t U;
    struct _hw_elcdif_dvictrl0_bitfields
    {
        unsigned H_BLANKING_CNT : 12; //!< [11:0] Number of blanking samples to be inserted between EAV and SAV during horizontal blanking interval.
        unsigned RESERVED0 : 4; //!< [15:12] Reserved bits, write as 0.
        unsigned H_ACTIVE_CNT : 12; //!< [27:16] Number of active video samples to be transmitted. (Mostly will be 1440 for both PAL and NTSC). Must always be a multiple of 4.
        unsigned RESERVED1 : 4; //!< [31:28] Reserved bits, write as 0.
    } B;
} hw_elcdif_dvictrl0_t;
#endif

/*
 * constants & macros for entire ELCDIF_DVICTRL0 register
 */
#define HW_ELCDIF_DVICTRL0_ADDR      (REGS_ELCDIF_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DVICTRL0           (*(volatile hw_elcdif_dvictrl0_t *) HW_ELCDIF_DVICTRL0_ADDR)
#define HW_ELCDIF_DVICTRL0_RD()      (HW_ELCDIF_DVICTRL0.U)
#define HW_ELCDIF_DVICTRL0_WR(v)     (HW_ELCDIF_DVICTRL0.U = (v))
#define HW_ELCDIF_DVICTRL0_SET(v)    (HW_ELCDIF_DVICTRL0_WR(HW_ELCDIF_DVICTRL0_RD() |  (v)))
#define HW_ELCDIF_DVICTRL0_CLR(v)    (HW_ELCDIF_DVICTRL0_WR(HW_ELCDIF_DVICTRL0_RD() & ~(v)))
#define HW_ELCDIF_DVICTRL0_TOG(v)    (HW_ELCDIF_DVICTRL0_WR(HW_ELCDIF_DVICTRL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_DVICTRL0 bitfields
 */

/* --- Register HW_ELCDIF_DVICTRL0, field H_BLANKING_CNT[11:0] (RW)
 *
 * Number of blanking samples to be inserted between EAV and SAV during horizontal blanking
 * interval.
 */

#define BP_ELCDIF_DVICTRL0_H_BLANKING_CNT      (0)      //!< Bit position for ELCDIF_DVICTRL0_H_BLANKING_CNT.
#define BM_ELCDIF_DVICTRL0_H_BLANKING_CNT      (0x00000fff)  //!< Bit mask for ELCDIF_DVICTRL0_H_BLANKING_CNT.

//! @brief Get value of ELCDIF_DVICTRL0_H_BLANKING_CNT from a register value.
#define BG_ELCDIF_DVICTRL0_H_BLANKING_CNT(r)   (((r) & BM_ELCDIF_DVICTRL0_H_BLANKING_CNT) >> BP_ELCDIF_DVICTRL0_H_BLANKING_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL0_H_BLANKING_CNT.
#define BF_ELCDIF_DVICTRL0_H_BLANKING_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL0_H_BLANKING_CNT) & BM_ELCDIF_DVICTRL0_H_BLANKING_CNT)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL0_H_BLANKING_CNT.
#define BF_ELCDIF_DVICTRL0_H_BLANKING_CNT(v)   (((v) << BP_ELCDIF_DVICTRL0_H_BLANKING_CNT) & BM_ELCDIF_DVICTRL0_H_BLANKING_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the H_BLANKING_CNT field to a new value.
#define BW_ELCDIF_DVICTRL0_H_BLANKING_CNT(v)   (HW_ELCDIF_DVICTRL0_WR((HW_ELCDIF_DVICTRL0_RD() & ~BM_ELCDIF_DVICTRL0_H_BLANKING_CNT) | BF_ELCDIF_DVICTRL0_H_BLANKING_CNT(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL0, field H_ACTIVE_CNT[27:16] (RW)
 *
 * Number of active video samples to be transmitted. (Mostly will be 1440 for both PAL and NTSC).
 * Must always be a multiple of 4.
 */

#define BP_ELCDIF_DVICTRL0_H_ACTIVE_CNT      (16)      //!< Bit position for ELCDIF_DVICTRL0_H_ACTIVE_CNT.
#define BM_ELCDIF_DVICTRL0_H_ACTIVE_CNT      (0x0fff0000)  //!< Bit mask for ELCDIF_DVICTRL0_H_ACTIVE_CNT.

//! @brief Get value of ELCDIF_DVICTRL0_H_ACTIVE_CNT from a register value.
#define BG_ELCDIF_DVICTRL0_H_ACTIVE_CNT(r)   (((r) & BM_ELCDIF_DVICTRL0_H_ACTIVE_CNT) >> BP_ELCDIF_DVICTRL0_H_ACTIVE_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL0_H_ACTIVE_CNT.
#define BF_ELCDIF_DVICTRL0_H_ACTIVE_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL0_H_ACTIVE_CNT) & BM_ELCDIF_DVICTRL0_H_ACTIVE_CNT)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL0_H_ACTIVE_CNT.
#define BF_ELCDIF_DVICTRL0_H_ACTIVE_CNT(v)   (((v) << BP_ELCDIF_DVICTRL0_H_ACTIVE_CNT) & BM_ELCDIF_DVICTRL0_H_ACTIVE_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the H_ACTIVE_CNT field to a new value.
#define BW_ELCDIF_DVICTRL0_H_ACTIVE_CNT(v)   (HW_ELCDIF_DVICTRL0_WR((HW_ELCDIF_DVICTRL0_RD() & ~BM_ELCDIF_DVICTRL0_H_ACTIVE_CNT) | BF_ELCDIF_DVICTRL0_H_ACTIVE_CNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DVICTRL1 - Digital Video Interface Control1 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The Digital Video interface Control1 register provides the overall control of the Digital Video
 * interface.  This register contains information about the Field1 start and end, and the Field2
 * start in the ITU-R BT.656 interface.   EXAMPLE   //525/60 video system
 * HW_LCDIF_DVICTRL1_F1_START_LINE_WR(0x4);//4 HW_LCDIF_DVICTRL1_F1_END_LINE_WR(0x109);//265
 * HW_LCDIF_DVICTRL1_F2_START_LINE_WR(0x10A);//266 //625/50 video system
 * HW_LCDIF_DVICTRL1_F1_START_LINE_WR(0x1);//1 HW_LCDIF_DVICTRL1_F1_END_LINE_WR(0x138);//312
 * HW_LCDIF_DVICTRL1_F2_START_LINE_WR(0x139);//313
 */
typedef union _hw_elcdif_dvictrl1
{
    reg32_t U;
    struct _hw_elcdif_dvictrl1_bitfields
    {
        unsigned F2_START_LINE : 10; //!< [9:0] Vertical line number from which Field 2 begins.
        unsigned F1_END_LINE : 10; //!< [19:10] Vertical line number at which Field1 ends.
        unsigned F1_START_LINE : 10; //!< [29:20] Vertical line number from which Field 1 begins.
        unsigned RESERVED0 : 2; //!< [31:30] Reserved bits, write as 0.
    } B;
} hw_elcdif_dvictrl1_t;
#endif

/*
 * constants & macros for entire ELCDIF_DVICTRL1 register
 */
#define HW_ELCDIF_DVICTRL1_ADDR      (REGS_ELCDIF_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DVICTRL1           (*(volatile hw_elcdif_dvictrl1_t *) HW_ELCDIF_DVICTRL1_ADDR)
#define HW_ELCDIF_DVICTRL1_RD()      (HW_ELCDIF_DVICTRL1.U)
#define HW_ELCDIF_DVICTRL1_WR(v)     (HW_ELCDIF_DVICTRL1.U = (v))
#define HW_ELCDIF_DVICTRL1_SET(v)    (HW_ELCDIF_DVICTRL1_WR(HW_ELCDIF_DVICTRL1_RD() |  (v)))
#define HW_ELCDIF_DVICTRL1_CLR(v)    (HW_ELCDIF_DVICTRL1_WR(HW_ELCDIF_DVICTRL1_RD() & ~(v)))
#define HW_ELCDIF_DVICTRL1_TOG(v)    (HW_ELCDIF_DVICTRL1_WR(HW_ELCDIF_DVICTRL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_DVICTRL1 bitfields
 */

/* --- Register HW_ELCDIF_DVICTRL1, field F2_START_LINE[9:0] (RW)
 *
 * Vertical line number from which Field 2 begins.
 */

#define BP_ELCDIF_DVICTRL1_F2_START_LINE      (0)      //!< Bit position for ELCDIF_DVICTRL1_F2_START_LINE.
#define BM_ELCDIF_DVICTRL1_F2_START_LINE      (0x000003ff)  //!< Bit mask for ELCDIF_DVICTRL1_F2_START_LINE.

//! @brief Get value of ELCDIF_DVICTRL1_F2_START_LINE from a register value.
#define BG_ELCDIF_DVICTRL1_F2_START_LINE(r)   (((r) & BM_ELCDIF_DVICTRL1_F2_START_LINE) >> BP_ELCDIF_DVICTRL1_F2_START_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL1_F2_START_LINE.
#define BF_ELCDIF_DVICTRL1_F2_START_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL1_F2_START_LINE) & BM_ELCDIF_DVICTRL1_F2_START_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL1_F2_START_LINE.
#define BF_ELCDIF_DVICTRL1_F2_START_LINE(v)   (((v) << BP_ELCDIF_DVICTRL1_F2_START_LINE) & BM_ELCDIF_DVICTRL1_F2_START_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the F2_START_LINE field to a new value.
#define BW_ELCDIF_DVICTRL1_F2_START_LINE(v)   (HW_ELCDIF_DVICTRL1_WR((HW_ELCDIF_DVICTRL1_RD() & ~BM_ELCDIF_DVICTRL1_F2_START_LINE) | BF_ELCDIF_DVICTRL1_F2_START_LINE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL1, field F1_END_LINE[19:10] (RW)
 *
 * Vertical line number at which Field1 ends.
 */

#define BP_ELCDIF_DVICTRL1_F1_END_LINE      (10)      //!< Bit position for ELCDIF_DVICTRL1_F1_END_LINE.
#define BM_ELCDIF_DVICTRL1_F1_END_LINE      (0x000ffc00)  //!< Bit mask for ELCDIF_DVICTRL1_F1_END_LINE.

//! @brief Get value of ELCDIF_DVICTRL1_F1_END_LINE from a register value.
#define BG_ELCDIF_DVICTRL1_F1_END_LINE(r)   (((r) & BM_ELCDIF_DVICTRL1_F1_END_LINE) >> BP_ELCDIF_DVICTRL1_F1_END_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL1_F1_END_LINE.
#define BF_ELCDIF_DVICTRL1_F1_END_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL1_F1_END_LINE) & BM_ELCDIF_DVICTRL1_F1_END_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL1_F1_END_LINE.
#define BF_ELCDIF_DVICTRL1_F1_END_LINE(v)   (((v) << BP_ELCDIF_DVICTRL1_F1_END_LINE) & BM_ELCDIF_DVICTRL1_F1_END_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the F1_END_LINE field to a new value.
#define BW_ELCDIF_DVICTRL1_F1_END_LINE(v)   (HW_ELCDIF_DVICTRL1_WR((HW_ELCDIF_DVICTRL1_RD() & ~BM_ELCDIF_DVICTRL1_F1_END_LINE) | BF_ELCDIF_DVICTRL1_F1_END_LINE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL1, field F1_START_LINE[29:20] (RW)
 *
 * Vertical line number from which Field 1 begins.
 */

#define BP_ELCDIF_DVICTRL1_F1_START_LINE      (20)      //!< Bit position for ELCDIF_DVICTRL1_F1_START_LINE.
#define BM_ELCDIF_DVICTRL1_F1_START_LINE      (0x3ff00000)  //!< Bit mask for ELCDIF_DVICTRL1_F1_START_LINE.

//! @brief Get value of ELCDIF_DVICTRL1_F1_START_LINE from a register value.
#define BG_ELCDIF_DVICTRL1_F1_START_LINE(r)   (((r) & BM_ELCDIF_DVICTRL1_F1_START_LINE) >> BP_ELCDIF_DVICTRL1_F1_START_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL1_F1_START_LINE.
#define BF_ELCDIF_DVICTRL1_F1_START_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL1_F1_START_LINE) & BM_ELCDIF_DVICTRL1_F1_START_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL1_F1_START_LINE.
#define BF_ELCDIF_DVICTRL1_F1_START_LINE(v)   (((v) << BP_ELCDIF_DVICTRL1_F1_START_LINE) & BM_ELCDIF_DVICTRL1_F1_START_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the F1_START_LINE field to a new value.
#define BW_ELCDIF_DVICTRL1_F1_START_LINE(v)   (HW_ELCDIF_DVICTRL1_WR((HW_ELCDIF_DVICTRL1_RD() & ~BM_ELCDIF_DVICTRL1_F1_START_LINE) | BF_ELCDIF_DVICTRL1_F1_START_LINE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DVICTRL2 - Digital Video Interface Control2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The Digital Video interface Control2 register provides the overall control of the Digital Video
 * interface.  This register contains information about the Field2 end, and the Vertical Blanking1
 * interval in the ITU-R BT.656 interface.   EXAMPLE   //525/60 video system
 * HW_LCDIF_DVICTRL2_F2_END_LINE_WR(0x3);//3 HW_LCDIF_DVICTRL2_V1_BLANK_START_LINE_WR(0x108);//264
 * HW_LCDIF_DVICTRL2_V1_BLANK_END_LINE_WR(0x11A);//282 //625/50 video system
 * HW_LCDIF_DVICTRL2_F2_END_LINE_WR(0x271);//625
 * HW_LCDIF_DVICTRL2_V1_BLANK_START_LINE_WR(0x137);//311
 * HW_LCDIF_DVICTRL2_V1_BLANK_END_LINE_WR(0x14F);//335
 */
typedef union _hw_elcdif_dvictrl2
{
    reg32_t U;
    struct _hw_elcdif_dvictrl2_bitfields
    {
        unsigned V1_BLANK_END_LINE : 10; //!< [9:0] Vertical line number in the beginning part of Field2 where first Vertical Blanking interval ends.
        unsigned V1_BLANK_START_LINE : 10; //!< [19:10] Vertical line number towards the end of Field1 where first Vertical Blanking interval starts.
        unsigned F2_END_LINE : 10; //!< [29:20] Vertical line number at which Field 2 ends.
        unsigned RESERVED0 : 2; //!< [31:30] Reserved bits, write as 0.
    } B;
} hw_elcdif_dvictrl2_t;
#endif

/*
 * constants & macros for entire ELCDIF_DVICTRL2 register
 */
#define HW_ELCDIF_DVICTRL2_ADDR      (REGS_ELCDIF_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DVICTRL2           (*(volatile hw_elcdif_dvictrl2_t *) HW_ELCDIF_DVICTRL2_ADDR)
#define HW_ELCDIF_DVICTRL2_RD()      (HW_ELCDIF_DVICTRL2.U)
#define HW_ELCDIF_DVICTRL2_WR(v)     (HW_ELCDIF_DVICTRL2.U = (v))
#define HW_ELCDIF_DVICTRL2_SET(v)    (HW_ELCDIF_DVICTRL2_WR(HW_ELCDIF_DVICTRL2_RD() |  (v)))
#define HW_ELCDIF_DVICTRL2_CLR(v)    (HW_ELCDIF_DVICTRL2_WR(HW_ELCDIF_DVICTRL2_RD() & ~(v)))
#define HW_ELCDIF_DVICTRL2_TOG(v)    (HW_ELCDIF_DVICTRL2_WR(HW_ELCDIF_DVICTRL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_DVICTRL2 bitfields
 */

/* --- Register HW_ELCDIF_DVICTRL2, field V1_BLANK_END_LINE[9:0] (RW)
 *
 * Vertical line number in the beginning part of Field2 where first Vertical Blanking interval ends.
 */

#define BP_ELCDIF_DVICTRL2_V1_BLANK_END_LINE      (0)      //!< Bit position for ELCDIF_DVICTRL2_V1_BLANK_END_LINE.
#define BM_ELCDIF_DVICTRL2_V1_BLANK_END_LINE      (0x000003ff)  //!< Bit mask for ELCDIF_DVICTRL2_V1_BLANK_END_LINE.

//! @brief Get value of ELCDIF_DVICTRL2_V1_BLANK_END_LINE from a register value.
#define BG_ELCDIF_DVICTRL2_V1_BLANK_END_LINE(r)   (((r) & BM_ELCDIF_DVICTRL2_V1_BLANK_END_LINE) >> BP_ELCDIF_DVICTRL2_V1_BLANK_END_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL2_V1_BLANK_END_LINE.
#define BF_ELCDIF_DVICTRL2_V1_BLANK_END_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL2_V1_BLANK_END_LINE) & BM_ELCDIF_DVICTRL2_V1_BLANK_END_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL2_V1_BLANK_END_LINE.
#define BF_ELCDIF_DVICTRL2_V1_BLANK_END_LINE(v)   (((v) << BP_ELCDIF_DVICTRL2_V1_BLANK_END_LINE) & BM_ELCDIF_DVICTRL2_V1_BLANK_END_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the V1_BLANK_END_LINE field to a new value.
#define BW_ELCDIF_DVICTRL2_V1_BLANK_END_LINE(v)   (HW_ELCDIF_DVICTRL2_WR((HW_ELCDIF_DVICTRL2_RD() & ~BM_ELCDIF_DVICTRL2_V1_BLANK_END_LINE) | BF_ELCDIF_DVICTRL2_V1_BLANK_END_LINE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL2, field V1_BLANK_START_LINE[19:10] (RW)
 *
 * Vertical line number towards the end of Field1 where first Vertical Blanking interval starts.
 */

#define BP_ELCDIF_DVICTRL2_V1_BLANK_START_LINE      (10)      //!< Bit position for ELCDIF_DVICTRL2_V1_BLANK_START_LINE.
#define BM_ELCDIF_DVICTRL2_V1_BLANK_START_LINE      (0x000ffc00)  //!< Bit mask for ELCDIF_DVICTRL2_V1_BLANK_START_LINE.

//! @brief Get value of ELCDIF_DVICTRL2_V1_BLANK_START_LINE from a register value.
#define BG_ELCDIF_DVICTRL2_V1_BLANK_START_LINE(r)   (((r) & BM_ELCDIF_DVICTRL2_V1_BLANK_START_LINE) >> BP_ELCDIF_DVICTRL2_V1_BLANK_START_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL2_V1_BLANK_START_LINE.
#define BF_ELCDIF_DVICTRL2_V1_BLANK_START_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL2_V1_BLANK_START_LINE) & BM_ELCDIF_DVICTRL2_V1_BLANK_START_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL2_V1_BLANK_START_LINE.
#define BF_ELCDIF_DVICTRL2_V1_BLANK_START_LINE(v)   (((v) << BP_ELCDIF_DVICTRL2_V1_BLANK_START_LINE) & BM_ELCDIF_DVICTRL2_V1_BLANK_START_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the V1_BLANK_START_LINE field to a new value.
#define BW_ELCDIF_DVICTRL2_V1_BLANK_START_LINE(v)   (HW_ELCDIF_DVICTRL2_WR((HW_ELCDIF_DVICTRL2_RD() & ~BM_ELCDIF_DVICTRL2_V1_BLANK_START_LINE) | BF_ELCDIF_DVICTRL2_V1_BLANK_START_LINE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL2, field F2_END_LINE[29:20] (RW)
 *
 * Vertical line number at which Field 2 ends.
 */

#define BP_ELCDIF_DVICTRL2_F2_END_LINE      (20)      //!< Bit position for ELCDIF_DVICTRL2_F2_END_LINE.
#define BM_ELCDIF_DVICTRL2_F2_END_LINE      (0x3ff00000)  //!< Bit mask for ELCDIF_DVICTRL2_F2_END_LINE.

//! @brief Get value of ELCDIF_DVICTRL2_F2_END_LINE from a register value.
#define BG_ELCDIF_DVICTRL2_F2_END_LINE(r)   (((r) & BM_ELCDIF_DVICTRL2_F2_END_LINE) >> BP_ELCDIF_DVICTRL2_F2_END_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL2_F2_END_LINE.
#define BF_ELCDIF_DVICTRL2_F2_END_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL2_F2_END_LINE) & BM_ELCDIF_DVICTRL2_F2_END_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL2_F2_END_LINE.
#define BF_ELCDIF_DVICTRL2_F2_END_LINE(v)   (((v) << BP_ELCDIF_DVICTRL2_F2_END_LINE) & BM_ELCDIF_DVICTRL2_F2_END_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the F2_END_LINE field to a new value.
#define BW_ELCDIF_DVICTRL2_F2_END_LINE(v)   (HW_ELCDIF_DVICTRL2_WR((HW_ELCDIF_DVICTRL2_RD() & ~BM_ELCDIF_DVICTRL2_F2_END_LINE) | BF_ELCDIF_DVICTRL2_F2_END_LINE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DVICTRL3 - Digital Video Interface Control3 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The Digital Video interface Control3 register provides the overall control of the Digital Video
 * interface.  This register contains information about the Vertical Blanking2 interval in the ITU-R
 * BT.656 interface.   EXAMPLE   //525/60 video system
 * HW_LCDIF_DVICTRL3_V2_BLANK_START_LINE_WR(0x1);//1
 * HW_LCDIF_DVICTRL3_V2_BLANK_END_LINE_WR(0x13);//19 HW_LCDIF_DVICTRL0_V_LINES_CNT_WR(0x20D);//525
 * //625/50 video system HW_LCDIF_DVICTRL3_V2_BLANK_START_LINE_WR(0x270);//624
 * HW_LCDIF_DVICTRL3_V2_BLANK_END_LINE_WR(0x16);//22 HW_LCDIF_DVICTRL0_V_LINES_CNT_WR(0x271);//625
 */
typedef union _hw_elcdif_dvictrl3
{
    reg32_t U;
    struct _hw_elcdif_dvictrl3_bitfields
    {
        unsigned V_LINES_CNT : 10; //!< [9:0] Total number of vertical lines per frame (generally 525 or 625)
        unsigned V2_BLANK_END_LINE : 10; //!< [19:10] Vertical line number in the beginning part of Field1 where second Vertical Blanking interval ends.
        unsigned V2_BLANK_START_LINE : 10; //!< [29:20] Vertical line number towards the end of Field2 where second Vertical Blanking interval starts.
        unsigned RESERVED0 : 2; //!< [31:30] Reserved bits, write as 0.
    } B;
} hw_elcdif_dvictrl3_t;
#endif

/*
 * constants & macros for entire ELCDIF_DVICTRL3 register
 */
#define HW_ELCDIF_DVICTRL3_ADDR      (REGS_ELCDIF_BASE + 0xf0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DVICTRL3           (*(volatile hw_elcdif_dvictrl3_t *) HW_ELCDIF_DVICTRL3_ADDR)
#define HW_ELCDIF_DVICTRL3_RD()      (HW_ELCDIF_DVICTRL3.U)
#define HW_ELCDIF_DVICTRL3_WR(v)     (HW_ELCDIF_DVICTRL3.U = (v))
#define HW_ELCDIF_DVICTRL3_SET(v)    (HW_ELCDIF_DVICTRL3_WR(HW_ELCDIF_DVICTRL3_RD() |  (v)))
#define HW_ELCDIF_DVICTRL3_CLR(v)    (HW_ELCDIF_DVICTRL3_WR(HW_ELCDIF_DVICTRL3_RD() & ~(v)))
#define HW_ELCDIF_DVICTRL3_TOG(v)    (HW_ELCDIF_DVICTRL3_WR(HW_ELCDIF_DVICTRL3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_DVICTRL3 bitfields
 */

/* --- Register HW_ELCDIF_DVICTRL3, field V_LINES_CNT[9:0] (RW)
 *
 * Total number of vertical lines per frame (generally 525 or 625)
 */

#define BP_ELCDIF_DVICTRL3_V_LINES_CNT      (0)      //!< Bit position for ELCDIF_DVICTRL3_V_LINES_CNT.
#define BM_ELCDIF_DVICTRL3_V_LINES_CNT      (0x000003ff)  //!< Bit mask for ELCDIF_DVICTRL3_V_LINES_CNT.

//! @brief Get value of ELCDIF_DVICTRL3_V_LINES_CNT from a register value.
#define BG_ELCDIF_DVICTRL3_V_LINES_CNT(r)   (((r) & BM_ELCDIF_DVICTRL3_V_LINES_CNT) >> BP_ELCDIF_DVICTRL3_V_LINES_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL3_V_LINES_CNT.
#define BF_ELCDIF_DVICTRL3_V_LINES_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL3_V_LINES_CNT) & BM_ELCDIF_DVICTRL3_V_LINES_CNT)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL3_V_LINES_CNT.
#define BF_ELCDIF_DVICTRL3_V_LINES_CNT(v)   (((v) << BP_ELCDIF_DVICTRL3_V_LINES_CNT) & BM_ELCDIF_DVICTRL3_V_LINES_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the V_LINES_CNT field to a new value.
#define BW_ELCDIF_DVICTRL3_V_LINES_CNT(v)   (HW_ELCDIF_DVICTRL3_WR((HW_ELCDIF_DVICTRL3_RD() & ~BM_ELCDIF_DVICTRL3_V_LINES_CNT) | BF_ELCDIF_DVICTRL3_V_LINES_CNT(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL3, field V2_BLANK_END_LINE[19:10] (RW)
 *
 * Vertical line number in the beginning part of Field1 where second Vertical Blanking interval
 * ends.
 */

#define BP_ELCDIF_DVICTRL3_V2_BLANK_END_LINE      (10)      //!< Bit position for ELCDIF_DVICTRL3_V2_BLANK_END_LINE.
#define BM_ELCDIF_DVICTRL3_V2_BLANK_END_LINE      (0x000ffc00)  //!< Bit mask for ELCDIF_DVICTRL3_V2_BLANK_END_LINE.

//! @brief Get value of ELCDIF_DVICTRL3_V2_BLANK_END_LINE from a register value.
#define BG_ELCDIF_DVICTRL3_V2_BLANK_END_LINE(r)   (((r) & BM_ELCDIF_DVICTRL3_V2_BLANK_END_LINE) >> BP_ELCDIF_DVICTRL3_V2_BLANK_END_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL3_V2_BLANK_END_LINE.
#define BF_ELCDIF_DVICTRL3_V2_BLANK_END_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL3_V2_BLANK_END_LINE) & BM_ELCDIF_DVICTRL3_V2_BLANK_END_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL3_V2_BLANK_END_LINE.
#define BF_ELCDIF_DVICTRL3_V2_BLANK_END_LINE(v)   (((v) << BP_ELCDIF_DVICTRL3_V2_BLANK_END_LINE) & BM_ELCDIF_DVICTRL3_V2_BLANK_END_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the V2_BLANK_END_LINE field to a new value.
#define BW_ELCDIF_DVICTRL3_V2_BLANK_END_LINE(v)   (HW_ELCDIF_DVICTRL3_WR((HW_ELCDIF_DVICTRL3_RD() & ~BM_ELCDIF_DVICTRL3_V2_BLANK_END_LINE) | BF_ELCDIF_DVICTRL3_V2_BLANK_END_LINE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL3, field V2_BLANK_START_LINE[29:20] (RW)
 *
 * Vertical line number towards the end of Field2 where second Vertical Blanking interval starts.
 */

#define BP_ELCDIF_DVICTRL3_V2_BLANK_START_LINE      (20)      //!< Bit position for ELCDIF_DVICTRL3_V2_BLANK_START_LINE.
#define BM_ELCDIF_DVICTRL3_V2_BLANK_START_LINE      (0x3ff00000)  //!< Bit mask for ELCDIF_DVICTRL3_V2_BLANK_START_LINE.

//! @brief Get value of ELCDIF_DVICTRL3_V2_BLANK_START_LINE from a register value.
#define BG_ELCDIF_DVICTRL3_V2_BLANK_START_LINE(r)   (((r) & BM_ELCDIF_DVICTRL3_V2_BLANK_START_LINE) >> BP_ELCDIF_DVICTRL3_V2_BLANK_START_LINE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL3_V2_BLANK_START_LINE.
#define BF_ELCDIF_DVICTRL3_V2_BLANK_START_LINE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL3_V2_BLANK_START_LINE) & BM_ELCDIF_DVICTRL3_V2_BLANK_START_LINE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL3_V2_BLANK_START_LINE.
#define BF_ELCDIF_DVICTRL3_V2_BLANK_START_LINE(v)   (((v) << BP_ELCDIF_DVICTRL3_V2_BLANK_START_LINE) & BM_ELCDIF_DVICTRL3_V2_BLANK_START_LINE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the V2_BLANK_START_LINE field to a new value.
#define BW_ELCDIF_DVICTRL3_V2_BLANK_START_LINE(v)   (HW_ELCDIF_DVICTRL3_WR((HW_ELCDIF_DVICTRL3_RD() & ~BM_ELCDIF_DVICTRL3_V2_BLANK_START_LINE) | BF_ELCDIF_DVICTRL3_V2_BLANK_START_LINE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DVICTRL4 - Digital Video Interface Control4 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The Digital Video interface Control4 register provides the overall control of the Digital Video
 * interface.  This register is used to add side borders to the output if the input frame width is
 * less than 720 pixels.   EXAMPLE   //If input frame has only 640 pixels per line, but output is
 * supposed to have 720 pixels per line. HW_LCDIF_DVICTRL4_H_FILL_CNT_WR(0x50);//80
 * HW_LCDIF_DVICTRL4_Y_FILL_VALUE_WR(0x10);//16 HW_LCDIF_DVICTRL4_CB_FILL_VALUE_WR(0x80);//128
 * HW_LCDIF_DVICTRL4_CR_FILL_VALUE_WR(0x80);//128
 */
typedef union _hw_elcdif_dvictrl4
{
    reg32_t U;
    struct _hw_elcdif_dvictrl4_bitfields
    {
        unsigned H_FILL_CNT : 8; //!< [7:0] Number of active video samples that have to be filled with the filler data in the front and back portions of the active horizontal interval. Must be a multiple of 4. This field will have to be programmed if the input frame has less than 720 pixels per line.
        unsigned CR_FILL_VALUE : 8; //!< [15:8] Value of CR component of filler data.
        unsigned CB_FILL_VALUE : 8; //!< [23:16] Value of CB component of filler data
        unsigned Y_FILL_VALUE : 8; //!< [31:24] Value of Y component of filler data
    } B;
} hw_elcdif_dvictrl4_t;
#endif

/*
 * constants & macros for entire ELCDIF_DVICTRL4 register
 */
#define HW_ELCDIF_DVICTRL4_ADDR      (REGS_ELCDIF_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DVICTRL4           (*(volatile hw_elcdif_dvictrl4_t *) HW_ELCDIF_DVICTRL4_ADDR)
#define HW_ELCDIF_DVICTRL4_RD()      (HW_ELCDIF_DVICTRL4.U)
#define HW_ELCDIF_DVICTRL4_WR(v)     (HW_ELCDIF_DVICTRL4.U = (v))
#define HW_ELCDIF_DVICTRL4_SET(v)    (HW_ELCDIF_DVICTRL4_WR(HW_ELCDIF_DVICTRL4_RD() |  (v)))
#define HW_ELCDIF_DVICTRL4_CLR(v)    (HW_ELCDIF_DVICTRL4_WR(HW_ELCDIF_DVICTRL4_RD() & ~(v)))
#define HW_ELCDIF_DVICTRL4_TOG(v)    (HW_ELCDIF_DVICTRL4_WR(HW_ELCDIF_DVICTRL4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_DVICTRL4 bitfields
 */

/* --- Register HW_ELCDIF_DVICTRL4, field H_FILL_CNT[7:0] (RW)
 *
 * Number of active video samples that have to be filled with the filler data in the front and back
 * portions of the active horizontal interval. Must be a multiple of 4. This field will have to be
 * programmed if the input frame has less than 720 pixels per line.
 */

#define BP_ELCDIF_DVICTRL4_H_FILL_CNT      (0)      //!< Bit position for ELCDIF_DVICTRL4_H_FILL_CNT.
#define BM_ELCDIF_DVICTRL4_H_FILL_CNT      (0x000000ff)  //!< Bit mask for ELCDIF_DVICTRL4_H_FILL_CNT.

//! @brief Get value of ELCDIF_DVICTRL4_H_FILL_CNT from a register value.
#define BG_ELCDIF_DVICTRL4_H_FILL_CNT(r)   (((r) & BM_ELCDIF_DVICTRL4_H_FILL_CNT) >> BP_ELCDIF_DVICTRL4_H_FILL_CNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL4_H_FILL_CNT.
#define BF_ELCDIF_DVICTRL4_H_FILL_CNT(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL4_H_FILL_CNT) & BM_ELCDIF_DVICTRL4_H_FILL_CNT)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL4_H_FILL_CNT.
#define BF_ELCDIF_DVICTRL4_H_FILL_CNT(v)   (((v) << BP_ELCDIF_DVICTRL4_H_FILL_CNT) & BM_ELCDIF_DVICTRL4_H_FILL_CNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the H_FILL_CNT field to a new value.
#define BW_ELCDIF_DVICTRL4_H_FILL_CNT(v)   (HW_ELCDIF_DVICTRL4_WR((HW_ELCDIF_DVICTRL4_RD() & ~BM_ELCDIF_DVICTRL4_H_FILL_CNT) | BF_ELCDIF_DVICTRL4_H_FILL_CNT(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL4, field CR_FILL_VALUE[15:8] (RW)
 *
 * Value of CR component of filler data.
 */

#define BP_ELCDIF_DVICTRL4_CR_FILL_VALUE      (8)      //!< Bit position for ELCDIF_DVICTRL4_CR_FILL_VALUE.
#define BM_ELCDIF_DVICTRL4_CR_FILL_VALUE      (0x0000ff00)  //!< Bit mask for ELCDIF_DVICTRL4_CR_FILL_VALUE.

//! @brief Get value of ELCDIF_DVICTRL4_CR_FILL_VALUE from a register value.
#define BG_ELCDIF_DVICTRL4_CR_FILL_VALUE(r)   (((r) & BM_ELCDIF_DVICTRL4_CR_FILL_VALUE) >> BP_ELCDIF_DVICTRL4_CR_FILL_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL4_CR_FILL_VALUE.
#define BF_ELCDIF_DVICTRL4_CR_FILL_VALUE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL4_CR_FILL_VALUE) & BM_ELCDIF_DVICTRL4_CR_FILL_VALUE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL4_CR_FILL_VALUE.
#define BF_ELCDIF_DVICTRL4_CR_FILL_VALUE(v)   (((v) << BP_ELCDIF_DVICTRL4_CR_FILL_VALUE) & BM_ELCDIF_DVICTRL4_CR_FILL_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CR_FILL_VALUE field to a new value.
#define BW_ELCDIF_DVICTRL4_CR_FILL_VALUE(v)   (HW_ELCDIF_DVICTRL4_WR((HW_ELCDIF_DVICTRL4_RD() & ~BM_ELCDIF_DVICTRL4_CR_FILL_VALUE) | BF_ELCDIF_DVICTRL4_CR_FILL_VALUE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL4, field CB_FILL_VALUE[23:16] (RW)
 *
 * Value of CB component of filler data
 */

#define BP_ELCDIF_DVICTRL4_CB_FILL_VALUE      (16)      //!< Bit position for ELCDIF_DVICTRL4_CB_FILL_VALUE.
#define BM_ELCDIF_DVICTRL4_CB_FILL_VALUE      (0x00ff0000)  //!< Bit mask for ELCDIF_DVICTRL4_CB_FILL_VALUE.

//! @brief Get value of ELCDIF_DVICTRL4_CB_FILL_VALUE from a register value.
#define BG_ELCDIF_DVICTRL4_CB_FILL_VALUE(r)   (((r) & BM_ELCDIF_DVICTRL4_CB_FILL_VALUE) >> BP_ELCDIF_DVICTRL4_CB_FILL_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL4_CB_FILL_VALUE.
#define BF_ELCDIF_DVICTRL4_CB_FILL_VALUE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL4_CB_FILL_VALUE) & BM_ELCDIF_DVICTRL4_CB_FILL_VALUE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL4_CB_FILL_VALUE.
#define BF_ELCDIF_DVICTRL4_CB_FILL_VALUE(v)   (((v) << BP_ELCDIF_DVICTRL4_CB_FILL_VALUE) & BM_ELCDIF_DVICTRL4_CB_FILL_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CB_FILL_VALUE field to a new value.
#define BW_ELCDIF_DVICTRL4_CB_FILL_VALUE(v)   (HW_ELCDIF_DVICTRL4_WR((HW_ELCDIF_DVICTRL4_RD() & ~BM_ELCDIF_DVICTRL4_CB_FILL_VALUE) | BF_ELCDIF_DVICTRL4_CB_FILL_VALUE(v)))
#endif

/* --- Register HW_ELCDIF_DVICTRL4, field Y_FILL_VALUE[31:24] (RW)
 *
 * Value of Y component of filler data
 */

#define BP_ELCDIF_DVICTRL4_Y_FILL_VALUE      (24)      //!< Bit position for ELCDIF_DVICTRL4_Y_FILL_VALUE.
#define BM_ELCDIF_DVICTRL4_Y_FILL_VALUE      (0xff000000)  //!< Bit mask for ELCDIF_DVICTRL4_Y_FILL_VALUE.

//! @brief Get value of ELCDIF_DVICTRL4_Y_FILL_VALUE from a register value.
#define BG_ELCDIF_DVICTRL4_Y_FILL_VALUE(r)   (((r) & BM_ELCDIF_DVICTRL4_Y_FILL_VALUE) >> BP_ELCDIF_DVICTRL4_Y_FILL_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DVICTRL4_Y_FILL_VALUE.
#define BF_ELCDIF_DVICTRL4_Y_FILL_VALUE(v)   ((((reg32_t) v) << BP_ELCDIF_DVICTRL4_Y_FILL_VALUE) & BM_ELCDIF_DVICTRL4_Y_FILL_VALUE)
#else
//! @brief Format value for bitfield ELCDIF_DVICTRL4_Y_FILL_VALUE.
#define BF_ELCDIF_DVICTRL4_Y_FILL_VALUE(v)   (((v) << BP_ELCDIF_DVICTRL4_Y_FILL_VALUE) & BM_ELCDIF_DVICTRL4_Y_FILL_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the Y_FILL_VALUE field to a new value.
#define BW_ELCDIF_DVICTRL4_Y_FILL_VALUE(v)   (HW_ELCDIF_DVICTRL4_WR((HW_ELCDIF_DVICTRL4_RD() & ~BM_ELCDIF_DVICTRL4_Y_FILL_VALUE) | BF_ELCDIF_DVICTRL4_Y_FILL_VALUE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_COEFF0 - RGB to YCbCr 4:2:2 CSC Coefficient0 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * LCDIF_CSC_COEFF0 register provides overall control over color space conversion from RGB to 4:2:2
 * YCbCr. The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R
 * + C4*G + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries
 * programming information about RGB to YCbCr 4:2:2 CSC.   EXAMPLE
 * HW_LCDIF_CSC_COEFF0_C0_WR(0x41);//0.257x256=65 HW_LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_WR(0x3);
 */
typedef union _hw_elcdif_csc_coeff0
{
    reg32_t U;
    struct _hw_elcdif_csc_coeff0_bitfields
    {
        unsigned CSC_SUBSAMPLE_FILTER : 2; //!< [1:0] This register describes the filtering and subsampling scheme to be performed on the chroma components in order to convert from YCbCr 4:4:4 to YCbCr 4:2:2 space. Note that the following descriptions apply individually to Cb and Cr.
        unsigned RESERVED0 : 14; //!< [15:2] Reserved bits, write as 0.
        unsigned C0 : 10; //!< [25:16] Two's complement red multiplier coefficient for Y
        unsigned RESERVED1 : 6; //!< [31:26] Reserved bits, write as 0.
    } B;
} hw_elcdif_csc_coeff0_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_COEFF0 register
 */
#define HW_ELCDIF_CSC_COEFF0_ADDR      (REGS_ELCDIF_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_COEFF0           (*(volatile hw_elcdif_csc_coeff0_t *) HW_ELCDIF_CSC_COEFF0_ADDR)
#define HW_ELCDIF_CSC_COEFF0_RD()      (HW_ELCDIF_CSC_COEFF0.U)
#define HW_ELCDIF_CSC_COEFF0_WR(v)     (HW_ELCDIF_CSC_COEFF0.U = (v))
#define HW_ELCDIF_CSC_COEFF0_SET(v)    (HW_ELCDIF_CSC_COEFF0_WR(HW_ELCDIF_CSC_COEFF0_RD() |  (v)))
#define HW_ELCDIF_CSC_COEFF0_CLR(v)    (HW_ELCDIF_CSC_COEFF0_WR(HW_ELCDIF_CSC_COEFF0_RD() & ~(v)))
#define HW_ELCDIF_CSC_COEFF0_TOG(v)    (HW_ELCDIF_CSC_COEFF0_WR(HW_ELCDIF_CSC_COEFF0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_COEFF0 bitfields
 */

/* --- Register HW_ELCDIF_CSC_COEFF0, field CSC_SUBSAMPLE_FILTER[1:0] (RW)
 *
 * This register describes the filtering and subsampling scheme to be performed on the chroma
 * components in order to convert from YCbCr 4:4:4 to YCbCr 4:2:2 space. Note that the following
 * descriptions apply individually to Cb and Cr.
 *
 * Values:
 * SAMPLE_AND_HOLD = 0x0 - No filtering, simply keep every chroma value for samples numbered 2n and discard chroma values
 *     associated with all samples numbered 2n+1.
 * RSRVD = 0x1 - Reserved
 * INTERSTITIAL = 0x2 - Chroma samples numbered 2n and 2n+1 are averaged (weights 1/2, 1/2) and that chroma value replaces
 *     the two chroma values at 2n and 2n+1. This chroma now exists horizontally halfway between the
 *     two luma samples.
 * COSITED = 0x3 - Chroma samples numbered 2n-1, 2n, and 2n+1 are averaged (weights 1/4,1/2,1/4) and that chroma value
 *     exists at the same site as the luma sample numbered 2n and the chroma samples at 2n+1 are
 *     discarded.
 */

#define BP_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER      (0)      //!< Bit position for ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER.
#define BM_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER      (0x00000003)  //!< Bit mask for ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER.

//! @brief Get value of ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER from a register value.
#define BG_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(r)   (((r) & BM_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER) >> BP_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER.
#define BF_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER) & BM_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER.
#define BF_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(v)   (((v) << BP_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER) & BM_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CSC_SUBSAMPLE_FILTER field to a new value.
#define BW_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(v)   (HW_ELCDIF_CSC_COEFF0_WR((HW_ELCDIF_CSC_COEFF0_RD() & ~BM_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER) | BF_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(v)))
#endif

#define BV_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER__SAMPLE_AND_HOLD (0x0) //!< No filtering, simply keep every chroma value for samples numbered 2n and discard chroma values associated with all samples numbered 2n+1.
#define BV_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER__RSRVD (0x1) //!< Reserved
#define BV_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER__INTERSTITIAL (0x2) //!< Chroma samples numbered 2n and 2n+1 are averaged (weights 1/2, 1/2) and that chroma value replaces the two chroma values at 2n and 2n+1. This chroma now exists horizontally halfway between the two luma samples.
#define BV_ELCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER__COSITED (0x3) //!< Chroma samples numbered 2n-1, 2n, and 2n+1 are averaged (weights 1/4,1/2,1/4) and that chroma value exists at the same site as the luma sample numbered 2n and the chroma samples at 2n+1 are discarded.

/* --- Register HW_ELCDIF_CSC_COEFF0, field C0[25:16] (RW)
 *
 * Two's complement red multiplier coefficient for Y
 */

#define BP_ELCDIF_CSC_COEFF0_C0      (16)      //!< Bit position for ELCDIF_CSC_COEFF0_C0.
#define BM_ELCDIF_CSC_COEFF0_C0      (0x03ff0000)  //!< Bit mask for ELCDIF_CSC_COEFF0_C0.

//! @brief Get value of ELCDIF_CSC_COEFF0_C0 from a register value.
#define BG_ELCDIF_CSC_COEFF0_C0(r)   (((r) & BM_ELCDIF_CSC_COEFF0_C0) >> BP_ELCDIF_CSC_COEFF0_C0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF0_C0.
#define BF_ELCDIF_CSC_COEFF0_C0(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF0_C0) & BM_ELCDIF_CSC_COEFF0_C0)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF0_C0.
#define BF_ELCDIF_CSC_COEFF0_C0(v)   (((v) << BP_ELCDIF_CSC_COEFF0_C0) & BM_ELCDIF_CSC_COEFF0_C0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C0 field to a new value.
#define BW_ELCDIF_CSC_COEFF0_C0(v)   (HW_ELCDIF_CSC_COEFF0_WR((HW_ELCDIF_CSC_COEFF0_RD() & ~BM_ELCDIF_CSC_COEFF0_C0) | BF_ELCDIF_CSC_COEFF0_C0(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_COEFF1 - RGB to YCbCr 4:2:2 CSC Coefficient1 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * LCDIF_CSC_COEFF1 register provides overall control over color space conversion from RGB to 4:2:2
 * YCbCr. The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R
 * + C4*G + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries
 * programming information about RGB to YCbCr 4:2:2 CSC.   EXAMPLE
 * HW_LCDIF_CSC_COEFF1_C1_WR(0x81);//0.504x256=129 HW_LCDIF_CSC_COEFF1_C2_WR(0x19);//0.098x256=25
 */
typedef union _hw_elcdif_csc_coeff1
{
    reg32_t U;
    struct _hw_elcdif_csc_coeff1_bitfields
    {
        unsigned C1 : 10; //!< [9:0] Two's complement green multiplier coefficient for Y
        unsigned RESERVED0 : 6; //!< [15:10] Reserved bits, write as 0.
        unsigned C2 : 10; //!< [25:16] Two's complement blue multiplier coefficient for Y
        unsigned RESERVED1 : 6; //!< [31:26] Reserved bits, write as 0.
    } B;
} hw_elcdif_csc_coeff1_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_COEFF1 register
 */
#define HW_ELCDIF_CSC_COEFF1_ADDR      (REGS_ELCDIF_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_COEFF1           (*(volatile hw_elcdif_csc_coeff1_t *) HW_ELCDIF_CSC_COEFF1_ADDR)
#define HW_ELCDIF_CSC_COEFF1_RD()      (HW_ELCDIF_CSC_COEFF1.U)
#define HW_ELCDIF_CSC_COEFF1_WR(v)     (HW_ELCDIF_CSC_COEFF1.U = (v))
#define HW_ELCDIF_CSC_COEFF1_SET(v)    (HW_ELCDIF_CSC_COEFF1_WR(HW_ELCDIF_CSC_COEFF1_RD() |  (v)))
#define HW_ELCDIF_CSC_COEFF1_CLR(v)    (HW_ELCDIF_CSC_COEFF1_WR(HW_ELCDIF_CSC_COEFF1_RD() & ~(v)))
#define HW_ELCDIF_CSC_COEFF1_TOG(v)    (HW_ELCDIF_CSC_COEFF1_WR(HW_ELCDIF_CSC_COEFF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_COEFF1 bitfields
 */

/* --- Register HW_ELCDIF_CSC_COEFF1, field C1[9:0] (RW)
 *
 * Two's complement green multiplier coefficient for Y
 */

#define BP_ELCDIF_CSC_COEFF1_C1      (0)      //!< Bit position for ELCDIF_CSC_COEFF1_C1.
#define BM_ELCDIF_CSC_COEFF1_C1      (0x000003ff)  //!< Bit mask for ELCDIF_CSC_COEFF1_C1.

//! @brief Get value of ELCDIF_CSC_COEFF1_C1 from a register value.
#define BG_ELCDIF_CSC_COEFF1_C1(r)   (((r) & BM_ELCDIF_CSC_COEFF1_C1) >> BP_ELCDIF_CSC_COEFF1_C1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF1_C1.
#define BF_ELCDIF_CSC_COEFF1_C1(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF1_C1) & BM_ELCDIF_CSC_COEFF1_C1)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF1_C1.
#define BF_ELCDIF_CSC_COEFF1_C1(v)   (((v) << BP_ELCDIF_CSC_COEFF1_C1) & BM_ELCDIF_CSC_COEFF1_C1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C1 field to a new value.
#define BW_ELCDIF_CSC_COEFF1_C1(v)   (HW_ELCDIF_CSC_COEFF1_WR((HW_ELCDIF_CSC_COEFF1_RD() & ~BM_ELCDIF_CSC_COEFF1_C1) | BF_ELCDIF_CSC_COEFF1_C1(v)))
#endif

/* --- Register HW_ELCDIF_CSC_COEFF1, field C2[25:16] (RW)
 *
 * Two's complement blue multiplier coefficient for Y
 */

#define BP_ELCDIF_CSC_COEFF1_C2      (16)      //!< Bit position for ELCDIF_CSC_COEFF1_C2.
#define BM_ELCDIF_CSC_COEFF1_C2      (0x03ff0000)  //!< Bit mask for ELCDIF_CSC_COEFF1_C2.

//! @brief Get value of ELCDIF_CSC_COEFF1_C2 from a register value.
#define BG_ELCDIF_CSC_COEFF1_C2(r)   (((r) & BM_ELCDIF_CSC_COEFF1_C2) >> BP_ELCDIF_CSC_COEFF1_C2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF1_C2.
#define BF_ELCDIF_CSC_COEFF1_C2(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF1_C2) & BM_ELCDIF_CSC_COEFF1_C2)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF1_C2.
#define BF_ELCDIF_CSC_COEFF1_C2(v)   (((v) << BP_ELCDIF_CSC_COEFF1_C2) & BM_ELCDIF_CSC_COEFF1_C2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C2 field to a new value.
#define BW_ELCDIF_CSC_COEFF1_C2(v)   (HW_ELCDIF_CSC_COEFF1_WR((HW_ELCDIF_CSC_COEFF1_RD() & ~BM_ELCDIF_CSC_COEFF1_C2) | BF_ELCDIF_CSC_COEFF1_C2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_COEFF2 - RGB to YCbCr 4:2:2 CSC Coefficent2 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * LCDIF_CSC_COEFF2 register provides overall control over color space conversion from RGB to 4:2:2
 * YCbCr. The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R
 * + C4*G + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries
 * programming information about RGB to YCbCr 4:2:2 CSC.   EXAMPLE
 * HW_LCDIF_CSC_COEFF2_C3_WR(0x3DB);//-0.148x256=-37
 * HW_LCDIF_CSC_COEFF2_C4_WR(0x3B6);//-0.291x256=-74
 */
typedef union _hw_elcdif_csc_coeff2
{
    reg32_t U;
    struct _hw_elcdif_csc_coeff2_bitfields
    {
        unsigned C3 : 10; //!< [9:0] Two's complement red multiplier coefficient for Cb
        unsigned RESERVED0 : 6; //!< [15:10] Reserved bits, write as 0.
        unsigned C4 : 10; //!< [25:16] Two's complement green multiplier coefficient for Cb
        unsigned RESERVED1 : 6; //!< [31:26] Reserved bits, write as 0.
    } B;
} hw_elcdif_csc_coeff2_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_COEFF2 register
 */
#define HW_ELCDIF_CSC_COEFF2_ADDR      (REGS_ELCDIF_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_COEFF2           (*(volatile hw_elcdif_csc_coeff2_t *) HW_ELCDIF_CSC_COEFF2_ADDR)
#define HW_ELCDIF_CSC_COEFF2_RD()      (HW_ELCDIF_CSC_COEFF2.U)
#define HW_ELCDIF_CSC_COEFF2_WR(v)     (HW_ELCDIF_CSC_COEFF2.U = (v))
#define HW_ELCDIF_CSC_COEFF2_SET(v)    (HW_ELCDIF_CSC_COEFF2_WR(HW_ELCDIF_CSC_COEFF2_RD() |  (v)))
#define HW_ELCDIF_CSC_COEFF2_CLR(v)    (HW_ELCDIF_CSC_COEFF2_WR(HW_ELCDIF_CSC_COEFF2_RD() & ~(v)))
#define HW_ELCDIF_CSC_COEFF2_TOG(v)    (HW_ELCDIF_CSC_COEFF2_WR(HW_ELCDIF_CSC_COEFF2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_COEFF2 bitfields
 */

/* --- Register HW_ELCDIF_CSC_COEFF2, field C3[9:0] (RW)
 *
 * Two's complement red multiplier coefficient for Cb
 */

#define BP_ELCDIF_CSC_COEFF2_C3      (0)      //!< Bit position for ELCDIF_CSC_COEFF2_C3.
#define BM_ELCDIF_CSC_COEFF2_C3      (0x000003ff)  //!< Bit mask for ELCDIF_CSC_COEFF2_C3.

//! @brief Get value of ELCDIF_CSC_COEFF2_C3 from a register value.
#define BG_ELCDIF_CSC_COEFF2_C3(r)   (((r) & BM_ELCDIF_CSC_COEFF2_C3) >> BP_ELCDIF_CSC_COEFF2_C3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF2_C3.
#define BF_ELCDIF_CSC_COEFF2_C3(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF2_C3) & BM_ELCDIF_CSC_COEFF2_C3)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF2_C3.
#define BF_ELCDIF_CSC_COEFF2_C3(v)   (((v) << BP_ELCDIF_CSC_COEFF2_C3) & BM_ELCDIF_CSC_COEFF2_C3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C3 field to a new value.
#define BW_ELCDIF_CSC_COEFF2_C3(v)   (HW_ELCDIF_CSC_COEFF2_WR((HW_ELCDIF_CSC_COEFF2_RD() & ~BM_ELCDIF_CSC_COEFF2_C3) | BF_ELCDIF_CSC_COEFF2_C3(v)))
#endif

/* --- Register HW_ELCDIF_CSC_COEFF2, field C4[25:16] (RW)
 *
 * Two's complement green multiplier coefficient for Cb
 */

#define BP_ELCDIF_CSC_COEFF2_C4      (16)      //!< Bit position for ELCDIF_CSC_COEFF2_C4.
#define BM_ELCDIF_CSC_COEFF2_C4      (0x03ff0000)  //!< Bit mask for ELCDIF_CSC_COEFF2_C4.

//! @brief Get value of ELCDIF_CSC_COEFF2_C4 from a register value.
#define BG_ELCDIF_CSC_COEFF2_C4(r)   (((r) & BM_ELCDIF_CSC_COEFF2_C4) >> BP_ELCDIF_CSC_COEFF2_C4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF2_C4.
#define BF_ELCDIF_CSC_COEFF2_C4(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF2_C4) & BM_ELCDIF_CSC_COEFF2_C4)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF2_C4.
#define BF_ELCDIF_CSC_COEFF2_C4(v)   (((v) << BP_ELCDIF_CSC_COEFF2_C4) & BM_ELCDIF_CSC_COEFF2_C4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C4 field to a new value.
#define BW_ELCDIF_CSC_COEFF2_C4(v)   (HW_ELCDIF_CSC_COEFF2_WR((HW_ELCDIF_CSC_COEFF2_RD() & ~BM_ELCDIF_CSC_COEFF2_C4) | BF_ELCDIF_CSC_COEFF2_C4(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_COEFF3 - RGB to YCbCr 4:2:2 CSC Coefficient3 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * LCDIF_CSC_COEFF3 register provides overall control over color space conversion from RGB to 4:2:2
 * YCbCr. The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R
 * + C4*G + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries
 * programming information about RGB to YCbCr 4:2:2 CSC.   EXAMPLE
 * HW_LCDIF_CSC_COEFF3_C5_WR(0x70);//0.439x256=112 HW_LCDIF_CSC_COEFF3_C6_WR(0x70);//0.439x256=112
 */
typedef union _hw_elcdif_csc_coeff3
{
    reg32_t U;
    struct _hw_elcdif_csc_coeff3_bitfields
    {
        unsigned C5 : 10; //!< [9:0] Two's complement blue multiplier coefficient for Cb
        unsigned RESERVED0 : 6; //!< [15:10] Reserved bits, write as 0.
        unsigned C6 : 10; //!< [25:16] Two's complement red multiplier coefficient for Cr
        unsigned RESERVED1 : 6; //!< [31:26] Reserved bits, write as 0.
    } B;
} hw_elcdif_csc_coeff3_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_COEFF3 register
 */
#define HW_ELCDIF_CSC_COEFF3_ADDR      (REGS_ELCDIF_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_COEFF3           (*(volatile hw_elcdif_csc_coeff3_t *) HW_ELCDIF_CSC_COEFF3_ADDR)
#define HW_ELCDIF_CSC_COEFF3_RD()      (HW_ELCDIF_CSC_COEFF3.U)
#define HW_ELCDIF_CSC_COEFF3_WR(v)     (HW_ELCDIF_CSC_COEFF3.U = (v))
#define HW_ELCDIF_CSC_COEFF3_SET(v)    (HW_ELCDIF_CSC_COEFF3_WR(HW_ELCDIF_CSC_COEFF3_RD() |  (v)))
#define HW_ELCDIF_CSC_COEFF3_CLR(v)    (HW_ELCDIF_CSC_COEFF3_WR(HW_ELCDIF_CSC_COEFF3_RD() & ~(v)))
#define HW_ELCDIF_CSC_COEFF3_TOG(v)    (HW_ELCDIF_CSC_COEFF3_WR(HW_ELCDIF_CSC_COEFF3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_COEFF3 bitfields
 */

/* --- Register HW_ELCDIF_CSC_COEFF3, field C5[9:0] (RW)
 *
 * Two's complement blue multiplier coefficient for Cb
 */

#define BP_ELCDIF_CSC_COEFF3_C5      (0)      //!< Bit position for ELCDIF_CSC_COEFF3_C5.
#define BM_ELCDIF_CSC_COEFF3_C5      (0x000003ff)  //!< Bit mask for ELCDIF_CSC_COEFF3_C5.

//! @brief Get value of ELCDIF_CSC_COEFF3_C5 from a register value.
#define BG_ELCDIF_CSC_COEFF3_C5(r)   (((r) & BM_ELCDIF_CSC_COEFF3_C5) >> BP_ELCDIF_CSC_COEFF3_C5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF3_C5.
#define BF_ELCDIF_CSC_COEFF3_C5(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF3_C5) & BM_ELCDIF_CSC_COEFF3_C5)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF3_C5.
#define BF_ELCDIF_CSC_COEFF3_C5(v)   (((v) << BP_ELCDIF_CSC_COEFF3_C5) & BM_ELCDIF_CSC_COEFF3_C5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C5 field to a new value.
#define BW_ELCDIF_CSC_COEFF3_C5(v)   (HW_ELCDIF_CSC_COEFF3_WR((HW_ELCDIF_CSC_COEFF3_RD() & ~BM_ELCDIF_CSC_COEFF3_C5) | BF_ELCDIF_CSC_COEFF3_C5(v)))
#endif

/* --- Register HW_ELCDIF_CSC_COEFF3, field C6[25:16] (RW)
 *
 * Two's complement red multiplier coefficient for Cr
 */

#define BP_ELCDIF_CSC_COEFF3_C6      (16)      //!< Bit position for ELCDIF_CSC_COEFF3_C6.
#define BM_ELCDIF_CSC_COEFF3_C6      (0x03ff0000)  //!< Bit mask for ELCDIF_CSC_COEFF3_C6.

//! @brief Get value of ELCDIF_CSC_COEFF3_C6 from a register value.
#define BG_ELCDIF_CSC_COEFF3_C6(r)   (((r) & BM_ELCDIF_CSC_COEFF3_C6) >> BP_ELCDIF_CSC_COEFF3_C6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF3_C6.
#define BF_ELCDIF_CSC_COEFF3_C6(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF3_C6) & BM_ELCDIF_CSC_COEFF3_C6)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF3_C6.
#define BF_ELCDIF_CSC_COEFF3_C6(v)   (((v) << BP_ELCDIF_CSC_COEFF3_C6) & BM_ELCDIF_CSC_COEFF3_C6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C6 field to a new value.
#define BW_ELCDIF_CSC_COEFF3_C6(v)   (HW_ELCDIF_CSC_COEFF3_WR((HW_ELCDIF_CSC_COEFF3_RD() & ~BM_ELCDIF_CSC_COEFF3_C6) | BF_ELCDIF_CSC_COEFF3_C6(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_COEFF4 - RGB to YCbCr 4:2:2 CSC Coefficient4 Register (RW)
 *
 * Reset value: 0x00000000
 *
 * LCDIF_CSC_COEFF4 register provides overall control over color space conversion from RGB to 4:2:2
 * YCbCr. The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R
 * + C4*G + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries
 * programming information about RGB to YCbCr 4:2:2 CSC.   EXAMPLE
 * HW_LCDIF_CSC_COEFF4_C7_WR(0x3A2);//-0.368x256=-94
 * HW_LCDIF_CSC_COEFF4_C8_WR(0x3EE);//-0.071x256=-18
 */
typedef union _hw_elcdif_csc_coeff4
{
    reg32_t U;
    struct _hw_elcdif_csc_coeff4_bitfields
    {
        unsigned C7 : 10; //!< [9:0] Two's complement green multiplier coefficient for Cr
        unsigned RESERVED0 : 6; //!< [15:10] Reserved bits, write as 0.
        unsigned C8 : 10; //!< [25:16] Two's complement blue multiplier coefficient for Cr
        unsigned RESERVED1 : 6; //!< [31:26] Reserved bits, write as 0.
    } B;
} hw_elcdif_csc_coeff4_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_COEFF4 register
 */
#define HW_ELCDIF_CSC_COEFF4_ADDR      (REGS_ELCDIF_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_COEFF4           (*(volatile hw_elcdif_csc_coeff4_t *) HW_ELCDIF_CSC_COEFF4_ADDR)
#define HW_ELCDIF_CSC_COEFF4_RD()      (HW_ELCDIF_CSC_COEFF4.U)
#define HW_ELCDIF_CSC_COEFF4_WR(v)     (HW_ELCDIF_CSC_COEFF4.U = (v))
#define HW_ELCDIF_CSC_COEFF4_SET(v)    (HW_ELCDIF_CSC_COEFF4_WR(HW_ELCDIF_CSC_COEFF4_RD() |  (v)))
#define HW_ELCDIF_CSC_COEFF4_CLR(v)    (HW_ELCDIF_CSC_COEFF4_WR(HW_ELCDIF_CSC_COEFF4_RD() & ~(v)))
#define HW_ELCDIF_CSC_COEFF4_TOG(v)    (HW_ELCDIF_CSC_COEFF4_WR(HW_ELCDIF_CSC_COEFF4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_COEFF4 bitfields
 */

/* --- Register HW_ELCDIF_CSC_COEFF4, field C7[9:0] (RW)
 *
 * Two's complement green multiplier coefficient for Cr
 */

#define BP_ELCDIF_CSC_COEFF4_C7      (0)      //!< Bit position for ELCDIF_CSC_COEFF4_C7.
#define BM_ELCDIF_CSC_COEFF4_C7      (0x000003ff)  //!< Bit mask for ELCDIF_CSC_COEFF4_C7.

//! @brief Get value of ELCDIF_CSC_COEFF4_C7 from a register value.
#define BG_ELCDIF_CSC_COEFF4_C7(r)   (((r) & BM_ELCDIF_CSC_COEFF4_C7) >> BP_ELCDIF_CSC_COEFF4_C7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF4_C7.
#define BF_ELCDIF_CSC_COEFF4_C7(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF4_C7) & BM_ELCDIF_CSC_COEFF4_C7)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF4_C7.
#define BF_ELCDIF_CSC_COEFF4_C7(v)   (((v) << BP_ELCDIF_CSC_COEFF4_C7) & BM_ELCDIF_CSC_COEFF4_C7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C7 field to a new value.
#define BW_ELCDIF_CSC_COEFF4_C7(v)   (HW_ELCDIF_CSC_COEFF4_WR((HW_ELCDIF_CSC_COEFF4_RD() & ~BM_ELCDIF_CSC_COEFF4_C7) | BF_ELCDIF_CSC_COEFF4_C7(v)))
#endif

/* --- Register HW_ELCDIF_CSC_COEFF4, field C8[25:16] (RW)
 *
 * Two's complement blue multiplier coefficient for Cr
 */

#define BP_ELCDIF_CSC_COEFF4_C8      (16)      //!< Bit position for ELCDIF_CSC_COEFF4_C8.
#define BM_ELCDIF_CSC_COEFF4_C8      (0x03ff0000)  //!< Bit mask for ELCDIF_CSC_COEFF4_C8.

//! @brief Get value of ELCDIF_CSC_COEFF4_C8 from a register value.
#define BG_ELCDIF_CSC_COEFF4_C8(r)   (((r) & BM_ELCDIF_CSC_COEFF4_C8) >> BP_ELCDIF_CSC_COEFF4_C8)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_COEFF4_C8.
#define BF_ELCDIF_CSC_COEFF4_C8(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_COEFF4_C8) & BM_ELCDIF_CSC_COEFF4_C8)
#else
//! @brief Format value for bitfield ELCDIF_CSC_COEFF4_C8.
#define BF_ELCDIF_CSC_COEFF4_C8(v)   (((v) << BP_ELCDIF_CSC_COEFF4_C8) & BM_ELCDIF_CSC_COEFF4_C8)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the C8 field to a new value.
#define BW_ELCDIF_CSC_COEFF4_C8(v)   (HW_ELCDIF_CSC_COEFF4_WR((HW_ELCDIF_CSC_COEFF4_RD() & ~BM_ELCDIF_CSC_COEFF4_C8) | BF_ELCDIF_CSC_COEFF4_C8(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_OFFSET - RGB to YCbCr 4:2:2 CSC Offset Register (RW)
 *
 * Reset value: 0x00800010
 *
 * LCDIF_CSC_ register provides overall control over color space conversion from RGB to 4:2:2 YCbCr.
 * The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R + C4*G
 * + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries programming
 * information about RGB to YCbCr 4:2:2 CSC.
 */
typedef union _hw_elcdif_csc_offset
{
    reg32_t U;
    struct _hw_elcdif_csc_offset_bitfields
    {
        unsigned Y_OFFSET : 9; //!< [8:0] Two's complement offset for the Y component
        unsigned RESERVED0 : 7; //!< [15:9] Reserved bits, write as 0.
        unsigned CBCR_OFFSET : 9; //!< [24:16] Two's complement offset for the Cb and Cr components
        unsigned RESERVED1 : 7; //!< [31:25] Reserved bits, write as 0.
    } B;
} hw_elcdif_csc_offset_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_OFFSET register
 */
#define HW_ELCDIF_CSC_OFFSET_ADDR      (REGS_ELCDIF_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_OFFSET           (*(volatile hw_elcdif_csc_offset_t *) HW_ELCDIF_CSC_OFFSET_ADDR)
#define HW_ELCDIF_CSC_OFFSET_RD()      (HW_ELCDIF_CSC_OFFSET.U)
#define HW_ELCDIF_CSC_OFFSET_WR(v)     (HW_ELCDIF_CSC_OFFSET.U = (v))
#define HW_ELCDIF_CSC_OFFSET_SET(v)    (HW_ELCDIF_CSC_OFFSET_WR(HW_ELCDIF_CSC_OFFSET_RD() |  (v)))
#define HW_ELCDIF_CSC_OFFSET_CLR(v)    (HW_ELCDIF_CSC_OFFSET_WR(HW_ELCDIF_CSC_OFFSET_RD() & ~(v)))
#define HW_ELCDIF_CSC_OFFSET_TOG(v)    (HW_ELCDIF_CSC_OFFSET_WR(HW_ELCDIF_CSC_OFFSET_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_OFFSET bitfields
 */

/* --- Register HW_ELCDIF_CSC_OFFSET, field Y_OFFSET[8:0] (RW)
 *
 * Two's complement offset for the Y component
 */

#define BP_ELCDIF_CSC_OFFSET_Y_OFFSET      (0)      //!< Bit position for ELCDIF_CSC_OFFSET_Y_OFFSET.
#define BM_ELCDIF_CSC_OFFSET_Y_OFFSET      (0x000001ff)  //!< Bit mask for ELCDIF_CSC_OFFSET_Y_OFFSET.

//! @brief Get value of ELCDIF_CSC_OFFSET_Y_OFFSET from a register value.
#define BG_ELCDIF_CSC_OFFSET_Y_OFFSET(r)   (((r) & BM_ELCDIF_CSC_OFFSET_Y_OFFSET) >> BP_ELCDIF_CSC_OFFSET_Y_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_OFFSET_Y_OFFSET.
#define BF_ELCDIF_CSC_OFFSET_Y_OFFSET(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_OFFSET_Y_OFFSET) & BM_ELCDIF_CSC_OFFSET_Y_OFFSET)
#else
//! @brief Format value for bitfield ELCDIF_CSC_OFFSET_Y_OFFSET.
#define BF_ELCDIF_CSC_OFFSET_Y_OFFSET(v)   (((v) << BP_ELCDIF_CSC_OFFSET_Y_OFFSET) & BM_ELCDIF_CSC_OFFSET_Y_OFFSET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the Y_OFFSET field to a new value.
#define BW_ELCDIF_CSC_OFFSET_Y_OFFSET(v)   (HW_ELCDIF_CSC_OFFSET_WR((HW_ELCDIF_CSC_OFFSET_RD() & ~BM_ELCDIF_CSC_OFFSET_Y_OFFSET) | BF_ELCDIF_CSC_OFFSET_Y_OFFSET(v)))
#endif

/* --- Register HW_ELCDIF_CSC_OFFSET, field CBCR_OFFSET[24:16] (RW)
 *
 * Two's complement offset for the Cb and Cr components
 */

#define BP_ELCDIF_CSC_OFFSET_CBCR_OFFSET      (16)      //!< Bit position for ELCDIF_CSC_OFFSET_CBCR_OFFSET.
#define BM_ELCDIF_CSC_OFFSET_CBCR_OFFSET      (0x01ff0000)  //!< Bit mask for ELCDIF_CSC_OFFSET_CBCR_OFFSET.

//! @brief Get value of ELCDIF_CSC_OFFSET_CBCR_OFFSET from a register value.
#define BG_ELCDIF_CSC_OFFSET_CBCR_OFFSET(r)   (((r) & BM_ELCDIF_CSC_OFFSET_CBCR_OFFSET) >> BP_ELCDIF_CSC_OFFSET_CBCR_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_OFFSET_CBCR_OFFSET.
#define BF_ELCDIF_CSC_OFFSET_CBCR_OFFSET(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_OFFSET_CBCR_OFFSET) & BM_ELCDIF_CSC_OFFSET_CBCR_OFFSET)
#else
//! @brief Format value for bitfield ELCDIF_CSC_OFFSET_CBCR_OFFSET.
#define BF_ELCDIF_CSC_OFFSET_CBCR_OFFSET(v)   (((v) << BP_ELCDIF_CSC_OFFSET_CBCR_OFFSET) & BM_ELCDIF_CSC_OFFSET_CBCR_OFFSET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CBCR_OFFSET field to a new value.
#define BW_ELCDIF_CSC_OFFSET_CBCR_OFFSET(v)   (HW_ELCDIF_CSC_OFFSET_WR((HW_ELCDIF_CSC_OFFSET_RD() & ~BM_ELCDIF_CSC_OFFSET_CBCR_OFFSET) | BF_ELCDIF_CSC_OFFSET_CBCR_OFFSET(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CSC_LIMIT - RGB to YCbCr 4:2:2 CSC Limit Register (RW)
 *
 * Reset value: 0x00ff00ff
 *
 * LCDIF_CSC_CTRL0 register provides overall control over color space conversion from RGB to 4:2:2
 * YCbCr. The equations for the conversion are given by: Y = C0*R + C1*G + C2*B + Y_offset Cb= C3*R
 * + C4*G + C5*B + CbCr_offset Cr= C6*R + C7*G + C8*B + CbCr_offset  This register carries
 * programming information about RGB to YCbCr 4:2:2 CSC. Note that the values in this register are
 * unsigned.   EXAMPLE   HW_LCDIF_CSC_LIMIT_CBCR_MIN_WR(0x10);//16
 * HW_LCDIF_CSC_LIMIT_CBCR_MAX_WR(0xF0);//240 HW_LCDIF_CSC_LIMIT_Y_MIN_WR(0x10);//16
 * HW_LCDIF_CSC_LIMIT_Y_MAX_WR(0xEB);//235
 */
typedef union _hw_elcdif_csc_limit
{
    reg32_t U;
    struct _hw_elcdif_csc_limit_bitfields
    {
        unsigned Y_MAX : 8; //!< [7:0] Upper limit of Y after RGB to 4:2:2 YCbCr conversion
        unsigned Y_MIN : 8; //!< [15:8] Lower limit of Y after RGB to 4:2:2 YCbCr conversion
        unsigned CBCR_MAX : 8; //!< [23:16] Upper limit of Cb and Cr after RGB to 4:2:2 YCbCr conversion
        unsigned CBCR_MIN : 8; //!< [31:24] Lower limit of Cb and Cr after RGB to 4:2:2 YCbCr conversion
    } B;
} hw_elcdif_csc_limit_t;
#endif

/*
 * constants & macros for entire ELCDIF_CSC_LIMIT register
 */
#define HW_ELCDIF_CSC_LIMIT_ADDR      (REGS_ELCDIF_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CSC_LIMIT           (*(volatile hw_elcdif_csc_limit_t *) HW_ELCDIF_CSC_LIMIT_ADDR)
#define HW_ELCDIF_CSC_LIMIT_RD()      (HW_ELCDIF_CSC_LIMIT.U)
#define HW_ELCDIF_CSC_LIMIT_WR(v)     (HW_ELCDIF_CSC_LIMIT.U = (v))
#define HW_ELCDIF_CSC_LIMIT_SET(v)    (HW_ELCDIF_CSC_LIMIT_WR(HW_ELCDIF_CSC_LIMIT_RD() |  (v)))
#define HW_ELCDIF_CSC_LIMIT_CLR(v)    (HW_ELCDIF_CSC_LIMIT_WR(HW_ELCDIF_CSC_LIMIT_RD() & ~(v)))
#define HW_ELCDIF_CSC_LIMIT_TOG(v)    (HW_ELCDIF_CSC_LIMIT_WR(HW_ELCDIF_CSC_LIMIT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CSC_LIMIT bitfields
 */

/* --- Register HW_ELCDIF_CSC_LIMIT, field Y_MAX[7:0] (RW)
 *
 * Upper limit of Y after RGB to 4:2:2 YCbCr conversion
 */

#define BP_ELCDIF_CSC_LIMIT_Y_MAX      (0)      //!< Bit position for ELCDIF_CSC_LIMIT_Y_MAX.
#define BM_ELCDIF_CSC_LIMIT_Y_MAX      (0x000000ff)  //!< Bit mask for ELCDIF_CSC_LIMIT_Y_MAX.

//! @brief Get value of ELCDIF_CSC_LIMIT_Y_MAX from a register value.
#define BG_ELCDIF_CSC_LIMIT_Y_MAX(r)   (((r) & BM_ELCDIF_CSC_LIMIT_Y_MAX) >> BP_ELCDIF_CSC_LIMIT_Y_MAX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_Y_MAX.
#define BF_ELCDIF_CSC_LIMIT_Y_MAX(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_LIMIT_Y_MAX) & BM_ELCDIF_CSC_LIMIT_Y_MAX)
#else
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_Y_MAX.
#define BF_ELCDIF_CSC_LIMIT_Y_MAX(v)   (((v) << BP_ELCDIF_CSC_LIMIT_Y_MAX) & BM_ELCDIF_CSC_LIMIT_Y_MAX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the Y_MAX field to a new value.
#define BW_ELCDIF_CSC_LIMIT_Y_MAX(v)   (HW_ELCDIF_CSC_LIMIT_WR((HW_ELCDIF_CSC_LIMIT_RD() & ~BM_ELCDIF_CSC_LIMIT_Y_MAX) | BF_ELCDIF_CSC_LIMIT_Y_MAX(v)))
#endif

/* --- Register HW_ELCDIF_CSC_LIMIT, field Y_MIN[15:8] (RW)
 *
 * Lower limit of Y after RGB to 4:2:2 YCbCr conversion
 */

#define BP_ELCDIF_CSC_LIMIT_Y_MIN      (8)      //!< Bit position for ELCDIF_CSC_LIMIT_Y_MIN.
#define BM_ELCDIF_CSC_LIMIT_Y_MIN      (0x0000ff00)  //!< Bit mask for ELCDIF_CSC_LIMIT_Y_MIN.

//! @brief Get value of ELCDIF_CSC_LIMIT_Y_MIN from a register value.
#define BG_ELCDIF_CSC_LIMIT_Y_MIN(r)   (((r) & BM_ELCDIF_CSC_LIMIT_Y_MIN) >> BP_ELCDIF_CSC_LIMIT_Y_MIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_Y_MIN.
#define BF_ELCDIF_CSC_LIMIT_Y_MIN(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_LIMIT_Y_MIN) & BM_ELCDIF_CSC_LIMIT_Y_MIN)
#else
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_Y_MIN.
#define BF_ELCDIF_CSC_LIMIT_Y_MIN(v)   (((v) << BP_ELCDIF_CSC_LIMIT_Y_MIN) & BM_ELCDIF_CSC_LIMIT_Y_MIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the Y_MIN field to a new value.
#define BW_ELCDIF_CSC_LIMIT_Y_MIN(v)   (HW_ELCDIF_CSC_LIMIT_WR((HW_ELCDIF_CSC_LIMIT_RD() & ~BM_ELCDIF_CSC_LIMIT_Y_MIN) | BF_ELCDIF_CSC_LIMIT_Y_MIN(v)))
#endif

/* --- Register HW_ELCDIF_CSC_LIMIT, field CBCR_MAX[23:16] (RW)
 *
 * Upper limit of Cb and Cr after RGB to 4:2:2 YCbCr conversion
 */

#define BP_ELCDIF_CSC_LIMIT_CBCR_MAX      (16)      //!< Bit position for ELCDIF_CSC_LIMIT_CBCR_MAX.
#define BM_ELCDIF_CSC_LIMIT_CBCR_MAX      (0x00ff0000)  //!< Bit mask for ELCDIF_CSC_LIMIT_CBCR_MAX.

//! @brief Get value of ELCDIF_CSC_LIMIT_CBCR_MAX from a register value.
#define BG_ELCDIF_CSC_LIMIT_CBCR_MAX(r)   (((r) & BM_ELCDIF_CSC_LIMIT_CBCR_MAX) >> BP_ELCDIF_CSC_LIMIT_CBCR_MAX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_CBCR_MAX.
#define BF_ELCDIF_CSC_LIMIT_CBCR_MAX(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_LIMIT_CBCR_MAX) & BM_ELCDIF_CSC_LIMIT_CBCR_MAX)
#else
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_CBCR_MAX.
#define BF_ELCDIF_CSC_LIMIT_CBCR_MAX(v)   (((v) << BP_ELCDIF_CSC_LIMIT_CBCR_MAX) & BM_ELCDIF_CSC_LIMIT_CBCR_MAX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CBCR_MAX field to a new value.
#define BW_ELCDIF_CSC_LIMIT_CBCR_MAX(v)   (HW_ELCDIF_CSC_LIMIT_WR((HW_ELCDIF_CSC_LIMIT_RD() & ~BM_ELCDIF_CSC_LIMIT_CBCR_MAX) | BF_ELCDIF_CSC_LIMIT_CBCR_MAX(v)))
#endif

/* --- Register HW_ELCDIF_CSC_LIMIT, field CBCR_MIN[31:24] (RW)
 *
 * Lower limit of Cb and Cr after RGB to 4:2:2 YCbCr conversion
 */

#define BP_ELCDIF_CSC_LIMIT_CBCR_MIN      (24)      //!< Bit position for ELCDIF_CSC_LIMIT_CBCR_MIN.
#define BM_ELCDIF_CSC_LIMIT_CBCR_MIN      (0xff000000)  //!< Bit mask for ELCDIF_CSC_LIMIT_CBCR_MIN.

//! @brief Get value of ELCDIF_CSC_LIMIT_CBCR_MIN from a register value.
#define BG_ELCDIF_CSC_LIMIT_CBCR_MIN(r)   (((r) & BM_ELCDIF_CSC_LIMIT_CBCR_MIN) >> BP_ELCDIF_CSC_LIMIT_CBCR_MIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_CBCR_MIN.
#define BF_ELCDIF_CSC_LIMIT_CBCR_MIN(v)   ((((reg32_t) v) << BP_ELCDIF_CSC_LIMIT_CBCR_MIN) & BM_ELCDIF_CSC_LIMIT_CBCR_MIN)
#else
//! @brief Format value for bitfield ELCDIF_CSC_LIMIT_CBCR_MIN.
#define BF_ELCDIF_CSC_LIMIT_CBCR_MIN(v)   (((v) << BP_ELCDIF_CSC_LIMIT_CBCR_MIN) & BM_ELCDIF_CSC_LIMIT_CBCR_MIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CBCR_MIN field to a new value.
#define BW_ELCDIF_CSC_LIMIT_CBCR_MIN(v)   (HW_ELCDIF_CSC_LIMIT_WR((HW_ELCDIF_CSC_LIMIT_RD() & ~BM_ELCDIF_CSC_LIMIT_CBCR_MIN) | BF_ELCDIF_CSC_LIMIT_CBCR_MIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DATA - LCD Interface Data Register (RW)
 *
 * Reset value: 0x00000000
 *
 * NOTE: this is now an unsupported feature of the eLCDIF and this should be removed from the
 * design. The data sent to an external LCD controller is written to this register. Data can be
 * written to this register (from the processor's perspective) as bytes half-words (16 bits) or
 * words (32 bits) as appropriate.  This register holds the 32-bit word written by either the ARM
 * platform or the DMA into LCDIF. This data then gets sent out by the block across the interface.
 * When the block is in bus master mode, this register gets the value of the lower 32 bits of the
 * 64-bit data bus whenever it is received.
 */
typedef union _hw_elcdif_data
{
    reg32_t U;
    struct _hw_elcdif_data_bitfields
    {
        unsigned DATA_ZERO : 8; //!< [7:0] Byte 0 (least significant byte) of data written to eLCDIF by the DMA or the ARM platform.
        unsigned DATA_ONE : 8; //!< [15:8] Byte 1 of data written to eLCDIF by the DMA or the ARM platform.
        unsigned DATA_TWO : 8; //!< [23:16] Byte 2 of data written to eLCDIF by the DMA or the ARM platform.
        unsigned DATA_THREE : 8; //!< [31:24] Byte 3 (most significant byte) of data written to LCDIF by the DMA or the ARM platform.
    } B;
} hw_elcdif_data_t;
#endif

/*
 * constants & macros for entire ELCDIF_DATA register
 */
#define HW_ELCDIF_DATA_ADDR      (REGS_ELCDIF_BASE + 0x180)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DATA           (*(volatile hw_elcdif_data_t *) HW_ELCDIF_DATA_ADDR)
#define HW_ELCDIF_DATA_RD()      (HW_ELCDIF_DATA.U)
#define HW_ELCDIF_DATA_WR(v)     (HW_ELCDIF_DATA.U = (v))
#define HW_ELCDIF_DATA_SET(v)    (HW_ELCDIF_DATA_WR(HW_ELCDIF_DATA_RD() |  (v)))
#define HW_ELCDIF_DATA_CLR(v)    (HW_ELCDIF_DATA_WR(HW_ELCDIF_DATA_RD() & ~(v)))
#define HW_ELCDIF_DATA_TOG(v)    (HW_ELCDIF_DATA_WR(HW_ELCDIF_DATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_DATA bitfields
 */

/* --- Register HW_ELCDIF_DATA, field DATA_ZERO[7:0] (RW)
 *
 * Byte 0 (least significant byte) of data written to eLCDIF by the DMA or the ARM platform.
 */

#define BP_ELCDIF_DATA_DATA_ZERO      (0)      //!< Bit position for ELCDIF_DATA_DATA_ZERO.
#define BM_ELCDIF_DATA_DATA_ZERO      (0x000000ff)  //!< Bit mask for ELCDIF_DATA_DATA_ZERO.

//! @brief Get value of ELCDIF_DATA_DATA_ZERO from a register value.
#define BG_ELCDIF_DATA_DATA_ZERO(r)   (((r) & BM_ELCDIF_DATA_DATA_ZERO) >> BP_ELCDIF_DATA_DATA_ZERO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DATA_DATA_ZERO.
#define BF_ELCDIF_DATA_DATA_ZERO(v)   ((((reg32_t) v) << BP_ELCDIF_DATA_DATA_ZERO) & BM_ELCDIF_DATA_DATA_ZERO)
#else
//! @brief Format value for bitfield ELCDIF_DATA_DATA_ZERO.
#define BF_ELCDIF_DATA_DATA_ZERO(v)   (((v) << BP_ELCDIF_DATA_DATA_ZERO) & BM_ELCDIF_DATA_DATA_ZERO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ZERO field to a new value.
#define BW_ELCDIF_DATA_DATA_ZERO(v)   (HW_ELCDIF_DATA_WR((HW_ELCDIF_DATA_RD() & ~BM_ELCDIF_DATA_DATA_ZERO) | BF_ELCDIF_DATA_DATA_ZERO(v)))
#endif

/* --- Register HW_ELCDIF_DATA, field DATA_ONE[15:8] (RW)
 *
 * Byte 1 of data written to eLCDIF by the DMA or the ARM platform.
 */

#define BP_ELCDIF_DATA_DATA_ONE      (8)      //!< Bit position for ELCDIF_DATA_DATA_ONE.
#define BM_ELCDIF_DATA_DATA_ONE      (0x0000ff00)  //!< Bit mask for ELCDIF_DATA_DATA_ONE.

//! @brief Get value of ELCDIF_DATA_DATA_ONE from a register value.
#define BG_ELCDIF_DATA_DATA_ONE(r)   (((r) & BM_ELCDIF_DATA_DATA_ONE) >> BP_ELCDIF_DATA_DATA_ONE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DATA_DATA_ONE.
#define BF_ELCDIF_DATA_DATA_ONE(v)   ((((reg32_t) v) << BP_ELCDIF_DATA_DATA_ONE) & BM_ELCDIF_DATA_DATA_ONE)
#else
//! @brief Format value for bitfield ELCDIF_DATA_DATA_ONE.
#define BF_ELCDIF_DATA_DATA_ONE(v)   (((v) << BP_ELCDIF_DATA_DATA_ONE) & BM_ELCDIF_DATA_DATA_ONE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ONE field to a new value.
#define BW_ELCDIF_DATA_DATA_ONE(v)   (HW_ELCDIF_DATA_WR((HW_ELCDIF_DATA_RD() & ~BM_ELCDIF_DATA_DATA_ONE) | BF_ELCDIF_DATA_DATA_ONE(v)))
#endif

/* --- Register HW_ELCDIF_DATA, field DATA_TWO[23:16] (RW)
 *
 * Byte 2 of data written to eLCDIF by the DMA or the ARM platform.
 */

#define BP_ELCDIF_DATA_DATA_TWO      (16)      //!< Bit position for ELCDIF_DATA_DATA_TWO.
#define BM_ELCDIF_DATA_DATA_TWO      (0x00ff0000)  //!< Bit mask for ELCDIF_DATA_DATA_TWO.

//! @brief Get value of ELCDIF_DATA_DATA_TWO from a register value.
#define BG_ELCDIF_DATA_DATA_TWO(r)   (((r) & BM_ELCDIF_DATA_DATA_TWO) >> BP_ELCDIF_DATA_DATA_TWO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DATA_DATA_TWO.
#define BF_ELCDIF_DATA_DATA_TWO(v)   ((((reg32_t) v) << BP_ELCDIF_DATA_DATA_TWO) & BM_ELCDIF_DATA_DATA_TWO)
#else
//! @brief Format value for bitfield ELCDIF_DATA_DATA_TWO.
#define BF_ELCDIF_DATA_DATA_TWO(v)   (((v) << BP_ELCDIF_DATA_DATA_TWO) & BM_ELCDIF_DATA_DATA_TWO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_TWO field to a new value.
#define BW_ELCDIF_DATA_DATA_TWO(v)   (HW_ELCDIF_DATA_WR((HW_ELCDIF_DATA_RD() & ~BM_ELCDIF_DATA_DATA_TWO) | BF_ELCDIF_DATA_DATA_TWO(v)))
#endif

/* --- Register HW_ELCDIF_DATA, field DATA_THREE[31:24] (RW)
 *
 * Byte 3 (most significant byte) of data written to LCDIF by the DMA or the ARM platform.
 */

#define BP_ELCDIF_DATA_DATA_THREE      (24)      //!< Bit position for ELCDIF_DATA_DATA_THREE.
#define BM_ELCDIF_DATA_DATA_THREE      (0xff000000)  //!< Bit mask for ELCDIF_DATA_DATA_THREE.

//! @brief Get value of ELCDIF_DATA_DATA_THREE from a register value.
#define BG_ELCDIF_DATA_DATA_THREE(r)   (((r) & BM_ELCDIF_DATA_DATA_THREE) >> BP_ELCDIF_DATA_DATA_THREE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_DATA_DATA_THREE.
#define BF_ELCDIF_DATA_DATA_THREE(v)   ((((reg32_t) v) << BP_ELCDIF_DATA_DATA_THREE) & BM_ELCDIF_DATA_DATA_THREE)
#else
//! @brief Format value for bitfield ELCDIF_DATA_DATA_THREE.
#define BF_ELCDIF_DATA_DATA_THREE(v)   (((v) << BP_ELCDIF_DATA_DATA_THREE) & BM_ELCDIF_DATA_DATA_THREE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_THREE field to a new value.
#define BW_ELCDIF_DATA_DATA_THREE(v)   (HW_ELCDIF_DATA_WR((HW_ELCDIF_DATA_RD() & ~BM_ELCDIF_DATA_DATA_THREE) | BF_ELCDIF_DATA_DATA_THREE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_BM_ERROR_STAT - Bus Master Error Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register reflects the virtual address at which the AXI master received an error response
 * from the slave.  When the BM_ERROR_IRQ is asserted, the address of the bus error is updated in
 * the register.
 */
typedef union _hw_elcdif_bm_error_stat
{
    reg32_t U;
    struct _hw_elcdif_bm_error_stat_bitfields
    {
        unsigned ADDR : 32; //!< [31:0] Virtual address at which bus master error occurred.
    } B;
} hw_elcdif_bm_error_stat_t;
#endif

/*
 * constants & macros for entire ELCDIF_BM_ERROR_STAT register
 */
#define HW_ELCDIF_BM_ERROR_STAT_ADDR      (REGS_ELCDIF_BASE + 0x190)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_BM_ERROR_STAT           (*(volatile hw_elcdif_bm_error_stat_t *) HW_ELCDIF_BM_ERROR_STAT_ADDR)
#define HW_ELCDIF_BM_ERROR_STAT_RD()      (HW_ELCDIF_BM_ERROR_STAT.U)
#define HW_ELCDIF_BM_ERROR_STAT_WR(v)     (HW_ELCDIF_BM_ERROR_STAT.U = (v))
#define HW_ELCDIF_BM_ERROR_STAT_SET(v)    (HW_ELCDIF_BM_ERROR_STAT_WR(HW_ELCDIF_BM_ERROR_STAT_RD() |  (v)))
#define HW_ELCDIF_BM_ERROR_STAT_CLR(v)    (HW_ELCDIF_BM_ERROR_STAT_WR(HW_ELCDIF_BM_ERROR_STAT_RD() & ~(v)))
#define HW_ELCDIF_BM_ERROR_STAT_TOG(v)    (HW_ELCDIF_BM_ERROR_STAT_WR(HW_ELCDIF_BM_ERROR_STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_BM_ERROR_STAT bitfields
 */

/* --- Register HW_ELCDIF_BM_ERROR_STAT, field ADDR[31:0] (RW)
 *
 * Virtual address at which bus master error occurred.
 */

#define BP_ELCDIF_BM_ERROR_STAT_ADDR      (0)      //!< Bit position for ELCDIF_BM_ERROR_STAT_ADDR.
#define BM_ELCDIF_BM_ERROR_STAT_ADDR      (0xffffffff)  //!< Bit mask for ELCDIF_BM_ERROR_STAT_ADDR.

//! @brief Get value of ELCDIF_BM_ERROR_STAT_ADDR from a register value.
#define BG_ELCDIF_BM_ERROR_STAT_ADDR(r)   (((r) & BM_ELCDIF_BM_ERROR_STAT_ADDR) >> BP_ELCDIF_BM_ERROR_STAT_ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_BM_ERROR_STAT_ADDR.
#define BF_ELCDIF_BM_ERROR_STAT_ADDR(v)   ((((reg32_t) v) << BP_ELCDIF_BM_ERROR_STAT_ADDR) & BM_ELCDIF_BM_ERROR_STAT_ADDR)
#else
//! @brief Format value for bitfield ELCDIF_BM_ERROR_STAT_ADDR.
#define BF_ELCDIF_BM_ERROR_STAT_ADDR(v)   (((v) << BP_ELCDIF_BM_ERROR_STAT_ADDR) & BM_ELCDIF_BM_ERROR_STAT_ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_ELCDIF_BM_ERROR_STAT_ADDR(v)   (HW_ELCDIF_BM_ERROR_STAT_WR((HW_ELCDIF_BM_ERROR_STAT_RD() & ~BM_ELCDIF_BM_ERROR_STAT_ADDR) | BF_ELCDIF_BM_ERROR_STAT_ADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_CRC_STAT - CRC Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register reflects the CRC value of each frame sent out by eLCDIF. The CRC is done on the
 * final output bus, so the value will be dependent on the LCD_DATABUS_WIDTH bitfield even if the
 * input data is the same.  This register will be updated when the CUR_FRAME_DONE_IRQ is asserted.
 * In the case of DVI mode, the CRC is calculated for the entire frame, not separately for each
 * field in the frame.
 */
typedef union _hw_elcdif_crc_stat
{
    reg32_t U;
    struct _hw_elcdif_crc_stat_bitfields
    {
        unsigned CRC_VALUE : 32; //!< [31:0] Calculated CRC value.
    } B;
} hw_elcdif_crc_stat_t;
#endif

/*
 * constants & macros for entire ELCDIF_CRC_STAT register
 */
#define HW_ELCDIF_CRC_STAT_ADDR      (REGS_ELCDIF_BASE + 0x1a0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_CRC_STAT           (*(volatile hw_elcdif_crc_stat_t *) HW_ELCDIF_CRC_STAT_ADDR)
#define HW_ELCDIF_CRC_STAT_RD()      (HW_ELCDIF_CRC_STAT.U)
#define HW_ELCDIF_CRC_STAT_WR(v)     (HW_ELCDIF_CRC_STAT.U = (v))
#define HW_ELCDIF_CRC_STAT_SET(v)    (HW_ELCDIF_CRC_STAT_WR(HW_ELCDIF_CRC_STAT_RD() |  (v)))
#define HW_ELCDIF_CRC_STAT_CLR(v)    (HW_ELCDIF_CRC_STAT_WR(HW_ELCDIF_CRC_STAT_RD() & ~(v)))
#define HW_ELCDIF_CRC_STAT_TOG(v)    (HW_ELCDIF_CRC_STAT_WR(HW_ELCDIF_CRC_STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_CRC_STAT bitfields
 */

/* --- Register HW_ELCDIF_CRC_STAT, field CRC_VALUE[31:0] (RW)
 *
 * Calculated CRC value.
 */

#define BP_ELCDIF_CRC_STAT_CRC_VALUE      (0)      //!< Bit position for ELCDIF_CRC_STAT_CRC_VALUE.
#define BM_ELCDIF_CRC_STAT_CRC_VALUE      (0xffffffff)  //!< Bit mask for ELCDIF_CRC_STAT_CRC_VALUE.

//! @brief Get value of ELCDIF_CRC_STAT_CRC_VALUE from a register value.
#define BG_ELCDIF_CRC_STAT_CRC_VALUE(r)   (((r) & BM_ELCDIF_CRC_STAT_CRC_VALUE) >> BP_ELCDIF_CRC_STAT_CRC_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_CRC_STAT_CRC_VALUE.
#define BF_ELCDIF_CRC_STAT_CRC_VALUE(v)   ((((reg32_t) v) << BP_ELCDIF_CRC_STAT_CRC_VALUE) & BM_ELCDIF_CRC_STAT_CRC_VALUE)
#else
//! @brief Format value for bitfield ELCDIF_CRC_STAT_CRC_VALUE.
#define BF_ELCDIF_CRC_STAT_CRC_VALUE(v)   (((v) << BP_ELCDIF_CRC_STAT_CRC_VALUE) & BM_ELCDIF_CRC_STAT_CRC_VALUE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRC_VALUE field to a new value.
#define BW_ELCDIF_CRC_STAT_CRC_VALUE(v)   (HW_ELCDIF_CRC_STAT_WR((HW_ELCDIF_CRC_STAT_RD() & ~BM_ELCDIF_CRC_STAT_CRC_VALUE) | BF_ELCDIF_CRC_STAT_CRC_VALUE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_STAT - LCD Interface Status Register (RO)
 *
 * Reset value: 0x95000000
 *
 * The LCD interface status register can be used to check the current status of the eLCDIF block.
 * The LCD interface status register that contains read only views of some parameters or current
 * state of the block.
 */
typedef union _hw_elcdif_stat
{
    reg32_t U;
    struct _hw_elcdif_stat_bitfields
    {
        unsigned LFIFO_COUNT : 9; //!< [8:0] Read only view of the current count in Latency buffer (LFIFO).
        unsigned RESERVED0 : 15; //!< [23:9] Reserved bits. Write as 0.
        unsigned DVI_CURRENT_FIELD : 1; //!< [24] Read only view of the current field being transmitted. DVI_CURRENT_FIELD = 0 means field 1. DVI_CURRENT_FIELD = 1 means field 2.
        unsigned BUSY : 1; //!< [25] Read only view of the input busy signal from the external LCD controller.
        unsigned TXFIFO_EMPTY : 1; //!< [26] Read only view of the signal that indicates that LCD write dapatath FIFO is empty, will be generally used in the read mode of the LCD interface.
        unsigned TXFIFO_FULL : 1; //!< [27] Read only view of the signal that indicates that LCD write datapath FIFO is full, will be generally used in the write mode of the LCD interface.
        unsigned LFIFO_EMPTY : 1; //!< [28] Read only view of the signal that indicates that LCD read dapatath FIFO is empty, will be generally used in the read mode of the LCD interface.
        unsigned LFIFO_FULL : 1; //!< [29] Read only view of the signal that indicates that LCD read datapath FIFO is full, will be generally used in the write mode of the LCD interface.
        unsigned DMA_REQ : 1; //!< [30] Reflects the current state of the DMA Request line for the eLCDIF. The DMA Request line toggles for each new request.
        unsigned PRESENT : 1; //!< [31] 0: eLCDIF not present on this product 1: eLCDIF is present.
    } B;
} hw_elcdif_stat_t;
#endif

/*
 * constants & macros for entire ELCDIF_STAT register
 */
#define HW_ELCDIF_STAT_ADDR      (REGS_ELCDIF_BASE + 0x1b0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_STAT           (*(volatile hw_elcdif_stat_t *) HW_ELCDIF_STAT_ADDR)
#define HW_ELCDIF_STAT_RD()      (HW_ELCDIF_STAT.U)
#endif

/*
 * constants & macros for individual ELCDIF_STAT bitfields
 */

/* --- Register HW_ELCDIF_STAT, field LFIFO_COUNT[8:0] (RO)
 *
 * Read only view of the current count in Latency buffer (LFIFO).
 */

#define BP_ELCDIF_STAT_LFIFO_COUNT      (0)      //!< Bit position for ELCDIF_STAT_LFIFO_COUNT.
#define BM_ELCDIF_STAT_LFIFO_COUNT      (0x000001ff)  //!< Bit mask for ELCDIF_STAT_LFIFO_COUNT.

//! @brief Get value of ELCDIF_STAT_LFIFO_COUNT from a register value.
#define BG_ELCDIF_STAT_LFIFO_COUNT(r)   (((r) & BM_ELCDIF_STAT_LFIFO_COUNT) >> BP_ELCDIF_STAT_LFIFO_COUNT)

/* --- Register HW_ELCDIF_STAT, field DVI_CURRENT_FIELD[24] (RO)
 *
 * Read only view of the current field being transmitted. DVI_CURRENT_FIELD = 0 means field 1.
 * DVI_CURRENT_FIELD = 1 means field 2.
 */

#define BP_ELCDIF_STAT_DVI_CURRENT_FIELD      (24)      //!< Bit position for ELCDIF_STAT_DVI_CURRENT_FIELD.
#define BM_ELCDIF_STAT_DVI_CURRENT_FIELD      (0x01000000)  //!< Bit mask for ELCDIF_STAT_DVI_CURRENT_FIELD.

//! @brief Get value of ELCDIF_STAT_DVI_CURRENT_FIELD from a register value.
#define BG_ELCDIF_STAT_DVI_CURRENT_FIELD(r)   (((r) & BM_ELCDIF_STAT_DVI_CURRENT_FIELD) >> BP_ELCDIF_STAT_DVI_CURRENT_FIELD)

/* --- Register HW_ELCDIF_STAT, field BUSY[25] (RO)
 *
 * Read only view of the input busy signal from the external LCD controller.
 */

#define BP_ELCDIF_STAT_BUSY      (25)      //!< Bit position for ELCDIF_STAT_BUSY.
#define BM_ELCDIF_STAT_BUSY      (0x02000000)  //!< Bit mask for ELCDIF_STAT_BUSY.

//! @brief Get value of ELCDIF_STAT_BUSY from a register value.
#define BG_ELCDIF_STAT_BUSY(r)   (((r) & BM_ELCDIF_STAT_BUSY) >> BP_ELCDIF_STAT_BUSY)

/* --- Register HW_ELCDIF_STAT, field TXFIFO_EMPTY[26] (RO)
 *
 * Read only view of the signal that indicates that LCD write dapatath FIFO is empty, will be
 * generally used in the read mode of the LCD interface.
 */

#define BP_ELCDIF_STAT_TXFIFO_EMPTY      (26)      //!< Bit position for ELCDIF_STAT_TXFIFO_EMPTY.
#define BM_ELCDIF_STAT_TXFIFO_EMPTY      (0x04000000)  //!< Bit mask for ELCDIF_STAT_TXFIFO_EMPTY.

//! @brief Get value of ELCDIF_STAT_TXFIFO_EMPTY from a register value.
#define BG_ELCDIF_STAT_TXFIFO_EMPTY(r)   (((r) & BM_ELCDIF_STAT_TXFIFO_EMPTY) >> BP_ELCDIF_STAT_TXFIFO_EMPTY)

/* --- Register HW_ELCDIF_STAT, field TXFIFO_FULL[27] (RO)
 *
 * Read only view of the signal that indicates that LCD write datapath FIFO is full, will be
 * generally used in the write mode of the LCD interface.
 */

#define BP_ELCDIF_STAT_TXFIFO_FULL      (27)      //!< Bit position for ELCDIF_STAT_TXFIFO_FULL.
#define BM_ELCDIF_STAT_TXFIFO_FULL      (0x08000000)  //!< Bit mask for ELCDIF_STAT_TXFIFO_FULL.

//! @brief Get value of ELCDIF_STAT_TXFIFO_FULL from a register value.
#define BG_ELCDIF_STAT_TXFIFO_FULL(r)   (((r) & BM_ELCDIF_STAT_TXFIFO_FULL) >> BP_ELCDIF_STAT_TXFIFO_FULL)

/* --- Register HW_ELCDIF_STAT, field LFIFO_EMPTY[28] (RO)
 *
 * Read only view of the signal that indicates that LCD read dapatath FIFO is empty, will be
 * generally used in the read mode of the LCD interface.
 */

#define BP_ELCDIF_STAT_LFIFO_EMPTY      (28)      //!< Bit position for ELCDIF_STAT_LFIFO_EMPTY.
#define BM_ELCDIF_STAT_LFIFO_EMPTY      (0x10000000)  //!< Bit mask for ELCDIF_STAT_LFIFO_EMPTY.

//! @brief Get value of ELCDIF_STAT_LFIFO_EMPTY from a register value.
#define BG_ELCDIF_STAT_LFIFO_EMPTY(r)   (((r) & BM_ELCDIF_STAT_LFIFO_EMPTY) >> BP_ELCDIF_STAT_LFIFO_EMPTY)

/* --- Register HW_ELCDIF_STAT, field LFIFO_FULL[29] (RO)
 *
 * Read only view of the signal that indicates that LCD read datapath FIFO is full, will be
 * generally used in the write mode of the LCD interface.
 */

#define BP_ELCDIF_STAT_LFIFO_FULL      (29)      //!< Bit position for ELCDIF_STAT_LFIFO_FULL.
#define BM_ELCDIF_STAT_LFIFO_FULL      (0x20000000)  //!< Bit mask for ELCDIF_STAT_LFIFO_FULL.

//! @brief Get value of ELCDIF_STAT_LFIFO_FULL from a register value.
#define BG_ELCDIF_STAT_LFIFO_FULL(r)   (((r) & BM_ELCDIF_STAT_LFIFO_FULL) >> BP_ELCDIF_STAT_LFIFO_FULL)

/* --- Register HW_ELCDIF_STAT, field DMA_REQ[30] (RO)
 *
 * Reflects the current state of the DMA Request line for the eLCDIF. The DMA Request line toggles
 * for each new request.
 */

#define BP_ELCDIF_STAT_DMA_REQ      (30)      //!< Bit position for ELCDIF_STAT_DMA_REQ.
#define BM_ELCDIF_STAT_DMA_REQ      (0x40000000)  //!< Bit mask for ELCDIF_STAT_DMA_REQ.

//! @brief Get value of ELCDIF_STAT_DMA_REQ from a register value.
#define BG_ELCDIF_STAT_DMA_REQ(r)   (((r) & BM_ELCDIF_STAT_DMA_REQ) >> BP_ELCDIF_STAT_DMA_REQ)

/* --- Register HW_ELCDIF_STAT, field PRESENT[31] (RO)
 *
 * 0: eLCDIF not present on this product 1: eLCDIF is present.
 */

#define BP_ELCDIF_STAT_PRESENT      (31)      //!< Bit position for ELCDIF_STAT_PRESENT.
#define BM_ELCDIF_STAT_PRESENT      (0x80000000)  //!< Bit mask for ELCDIF_STAT_PRESENT.

//! @brief Get value of ELCDIF_STAT_PRESENT from a register value.
#define BG_ELCDIF_STAT_PRESENT(r)   (((r) & BM_ELCDIF_STAT_PRESENT) >> BP_ELCDIF_STAT_PRESENT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_VERSION - LCD Interface Version Register (RO)
 *
 * Reset value: 0x04000000
 *
 * The LCD interface version register can be used to read the version of the eLCDIF IP being used in
 * this SoC.  The LCD interface debug register is for diagnostic use only.
 */
typedef union _hw_elcdif_version
{
    reg32_t U;
    struct _hw_elcdif_version_bitfields
    {
        unsigned STEP : 16; //!< [15:0] Fixed read-only value reflecting the stepping of RTL version.
        unsigned MINOR : 8; //!< [23:16] Fixed read-only value reflecting the MINOR field of RTL version.
        unsigned MAJOR : 8; //!< [31:24] Fixed read-only value reflecting the MAJOR field of RTL version.
    } B;
} hw_elcdif_version_t;
#endif

/*
 * constants & macros for entire ELCDIF_VERSION register
 */
#define HW_ELCDIF_VERSION_ADDR      (REGS_ELCDIF_BASE + 0x1c0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_VERSION           (*(volatile hw_elcdif_version_t *) HW_ELCDIF_VERSION_ADDR)
#define HW_ELCDIF_VERSION_RD()      (HW_ELCDIF_VERSION.U)
#endif

/*
 * constants & macros for individual ELCDIF_VERSION bitfields
 */

/* --- Register HW_ELCDIF_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-only value reflecting the stepping of RTL version.
 */

#define BP_ELCDIF_VERSION_STEP      (0)      //!< Bit position for ELCDIF_VERSION_STEP.
#define BM_ELCDIF_VERSION_STEP      (0x0000ffff)  //!< Bit mask for ELCDIF_VERSION_STEP.

//! @brief Get value of ELCDIF_VERSION_STEP from a register value.
#define BG_ELCDIF_VERSION_STEP(r)   (((r) & BM_ELCDIF_VERSION_STEP) >> BP_ELCDIF_VERSION_STEP)

/* --- Register HW_ELCDIF_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of RTL version.
 */

#define BP_ELCDIF_VERSION_MINOR      (16)      //!< Bit position for ELCDIF_VERSION_MINOR.
#define BM_ELCDIF_VERSION_MINOR      (0x00ff0000)  //!< Bit mask for ELCDIF_VERSION_MINOR.

//! @brief Get value of ELCDIF_VERSION_MINOR from a register value.
#define BG_ELCDIF_VERSION_MINOR(r)   (((r) & BM_ELCDIF_VERSION_MINOR) >> BP_ELCDIF_VERSION_MINOR)

/* --- Register HW_ELCDIF_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of RTL version.
 */

#define BP_ELCDIF_VERSION_MAJOR      (24)      //!< Bit position for ELCDIF_VERSION_MAJOR.
#define BM_ELCDIF_VERSION_MAJOR      (0xff000000)  //!< Bit mask for ELCDIF_VERSION_MAJOR.

//! @brief Get value of ELCDIF_VERSION_MAJOR from a register value.
#define BG_ELCDIF_VERSION_MAJOR(r)   (((r) & BM_ELCDIF_VERSION_MAJOR) >> BP_ELCDIF_VERSION_MAJOR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DEBUG0 - LCD Interface Debug0 Register (RO)
 *
 * Reset value: 0x0e810000
 *
 * The LCD interface debug0 register provides a diagnostic view of the state machine and other
 * useful internal signals.  The LCD interface debug register is for diagnostic use only.
 */
typedef union _hw_elcdif_debug0
{
    reg32_t U;
    struct _hw_elcdif_debug0_bitfields
    {
        unsigned MST_WORDS : 4; //!< [3:0] Read only view of the current bursts issued by the AXI bus master.
        unsigned MST_OUTSTANDING_REQS : 5; //!< [8:4] Read only view of the current outstanding requests issued by the AXI bus master.
        unsigned MST_AVALID : 1; //!< [9] Read only view of the mst_avalid signal issued by the AXI bus master.
        unsigned CUR_REQ_STATE : 2; //!< [11:10] Read only view of the request state machine.
        unsigned PXP_B1_DONE : 1; //!< [12] Buffer1 done signal issued by eLCDIF.
        unsigned PXP_LCDIF_B1_READY : 1; //!< [13] Buffer1 ready signal issued by ePXP.
        unsigned PXP_B0_DONE : 1; //!< [14] Buffer0 done signal issued by eLCDIF.
        unsigned PXP_LCDIF_B0_READY : 1; //!< [15] Buffer0 ready signal issued by ePXP.
        unsigned CUR_STATE : 7; //!< [22:16] Read only view of the current state machine state in the current mode of operation.
        unsigned EMPTY_WORD : 1; //!< [23] Indicates that the current word is empty.
        unsigned CUR_FRAME_TX : 1; //!< [24] This bit is 1 for the time the current frame is being transmitted in the VSYNC mode. Useful for VSYNC mode debug.
        unsigned VSYNC : 1; //!< [25] Read only view of VSYNC signal.
        unsigned HSYNC : 1; //!< [26] Read only view of HSYNC signal.
        unsigned ENABLE : 1; //!< [27] Read only view of ENABLE signal.
        unsigned DMACMDKICK : 1; //!< [28] Read only view of the DMA command kick signal.
        unsigned SYNC_SIGNALS_ON_REG : 1; //!< [29] Read only view of internal sync_signals_on_reg signal.
        unsigned WAIT_FOR_VSYNC_EDGE_OUT : 1; //!< [30] Read only view of WAIT_FOR_VSYNC_EDGE bit in the VSYNC mode after it comes out of the TXFIFO.
        unsigned STREAMING_END_DETECTED : 1; //!< [31] Read only view of the DOTCLK_MODE or DVI_MODE bit going from 1 to 0.
    } B;
} hw_elcdif_debug0_t;
#endif

/*
 * constants & macros for entire ELCDIF_DEBUG0 register
 */
#define HW_ELCDIF_DEBUG0_ADDR      (REGS_ELCDIF_BASE + 0x1d0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DEBUG0           (*(volatile hw_elcdif_debug0_t *) HW_ELCDIF_DEBUG0_ADDR)
#define HW_ELCDIF_DEBUG0_RD()      (HW_ELCDIF_DEBUG0.U)
#endif

/*
 * constants & macros for individual ELCDIF_DEBUG0 bitfields
 */

/* --- Register HW_ELCDIF_DEBUG0, field MST_WORDS[3:0] (RO)
 *
 * Read only view of the current bursts issued by the AXI bus master.
 */

#define BP_ELCDIF_DEBUG0_MST_WORDS      (0)      //!< Bit position for ELCDIF_DEBUG0_MST_WORDS.
#define BM_ELCDIF_DEBUG0_MST_WORDS      (0x0000000f)  //!< Bit mask for ELCDIF_DEBUG0_MST_WORDS.

//! @brief Get value of ELCDIF_DEBUG0_MST_WORDS from a register value.
#define BG_ELCDIF_DEBUG0_MST_WORDS(r)   (((r) & BM_ELCDIF_DEBUG0_MST_WORDS) >> BP_ELCDIF_DEBUG0_MST_WORDS)

/* --- Register HW_ELCDIF_DEBUG0, field MST_OUTSTANDING_REQS[8:4] (RO)
 *
 * Read only view of the current outstanding requests issued by the AXI bus master.
 */

#define BP_ELCDIF_DEBUG0_MST_OUTSTANDING_REQS      (4)      //!< Bit position for ELCDIF_DEBUG0_MST_OUTSTANDING_REQS.
#define BM_ELCDIF_DEBUG0_MST_OUTSTANDING_REQS      (0x000001f0)  //!< Bit mask for ELCDIF_DEBUG0_MST_OUTSTANDING_REQS.

//! @brief Get value of ELCDIF_DEBUG0_MST_OUTSTANDING_REQS from a register value.
#define BG_ELCDIF_DEBUG0_MST_OUTSTANDING_REQS(r)   (((r) & BM_ELCDIF_DEBUG0_MST_OUTSTANDING_REQS) >> BP_ELCDIF_DEBUG0_MST_OUTSTANDING_REQS)

/* --- Register HW_ELCDIF_DEBUG0, field MST_AVALID[9] (RO)
 *
 * Read only view of the mst_avalid signal issued by the AXI bus master.
 */

#define BP_ELCDIF_DEBUG0_MST_AVALID      (9)      //!< Bit position for ELCDIF_DEBUG0_MST_AVALID.
#define BM_ELCDIF_DEBUG0_MST_AVALID      (0x00000200)  //!< Bit mask for ELCDIF_DEBUG0_MST_AVALID.

//! @brief Get value of ELCDIF_DEBUG0_MST_AVALID from a register value.
#define BG_ELCDIF_DEBUG0_MST_AVALID(r)   (((r) & BM_ELCDIF_DEBUG0_MST_AVALID) >> BP_ELCDIF_DEBUG0_MST_AVALID)

/* --- Register HW_ELCDIF_DEBUG0, field CUR_REQ_STATE[11:10] (RO)
 *
 * Read only view of the request state machine.
 */

#define BP_ELCDIF_DEBUG0_CUR_REQ_STATE      (10)      //!< Bit position for ELCDIF_DEBUG0_CUR_REQ_STATE.
#define BM_ELCDIF_DEBUG0_CUR_REQ_STATE      (0x00000c00)  //!< Bit mask for ELCDIF_DEBUG0_CUR_REQ_STATE.

//! @brief Get value of ELCDIF_DEBUG0_CUR_REQ_STATE from a register value.
#define BG_ELCDIF_DEBUG0_CUR_REQ_STATE(r)   (((r) & BM_ELCDIF_DEBUG0_CUR_REQ_STATE) >> BP_ELCDIF_DEBUG0_CUR_REQ_STATE)

/* --- Register HW_ELCDIF_DEBUG0, field PXP_B1_DONE[12] (RO)
 *
 * Buffer1 done signal issued by eLCDIF.
 */

#define BP_ELCDIF_DEBUG0_PXP_B1_DONE      (12)      //!< Bit position for ELCDIF_DEBUG0_PXP_B1_DONE.
#define BM_ELCDIF_DEBUG0_PXP_B1_DONE      (0x00001000)  //!< Bit mask for ELCDIF_DEBUG0_PXP_B1_DONE.

//! @brief Get value of ELCDIF_DEBUG0_PXP_B1_DONE from a register value.
#define BG_ELCDIF_DEBUG0_PXP_B1_DONE(r)   (((r) & BM_ELCDIF_DEBUG0_PXP_B1_DONE) >> BP_ELCDIF_DEBUG0_PXP_B1_DONE)

/* --- Register HW_ELCDIF_DEBUG0, field PXP_LCDIF_B1_READY[13] (RO)
 *
 * Buffer1 ready signal issued by ePXP.
 */

#define BP_ELCDIF_DEBUG0_PXP_LCDIF_B1_READY      (13)      //!< Bit position for ELCDIF_DEBUG0_PXP_LCDIF_B1_READY.
#define BM_ELCDIF_DEBUG0_PXP_LCDIF_B1_READY      (0x00002000)  //!< Bit mask for ELCDIF_DEBUG0_PXP_LCDIF_B1_READY.

//! @brief Get value of ELCDIF_DEBUG0_PXP_LCDIF_B1_READY from a register value.
#define BG_ELCDIF_DEBUG0_PXP_LCDIF_B1_READY(r)   (((r) & BM_ELCDIF_DEBUG0_PXP_LCDIF_B1_READY) >> BP_ELCDIF_DEBUG0_PXP_LCDIF_B1_READY)

/* --- Register HW_ELCDIF_DEBUG0, field PXP_B0_DONE[14] (RO)
 *
 * Buffer0 done signal issued by eLCDIF.
 */

#define BP_ELCDIF_DEBUG0_PXP_B0_DONE      (14)      //!< Bit position for ELCDIF_DEBUG0_PXP_B0_DONE.
#define BM_ELCDIF_DEBUG0_PXP_B0_DONE      (0x00004000)  //!< Bit mask for ELCDIF_DEBUG0_PXP_B0_DONE.

//! @brief Get value of ELCDIF_DEBUG0_PXP_B0_DONE from a register value.
#define BG_ELCDIF_DEBUG0_PXP_B0_DONE(r)   (((r) & BM_ELCDIF_DEBUG0_PXP_B0_DONE) >> BP_ELCDIF_DEBUG0_PXP_B0_DONE)

/* --- Register HW_ELCDIF_DEBUG0, field PXP_LCDIF_B0_READY[15] (RO)
 *
 * Buffer0 ready signal issued by ePXP.
 */

#define BP_ELCDIF_DEBUG0_PXP_LCDIF_B0_READY      (15)      //!< Bit position for ELCDIF_DEBUG0_PXP_LCDIF_B0_READY.
#define BM_ELCDIF_DEBUG0_PXP_LCDIF_B0_READY      (0x00008000)  //!< Bit mask for ELCDIF_DEBUG0_PXP_LCDIF_B0_READY.

//! @brief Get value of ELCDIF_DEBUG0_PXP_LCDIF_B0_READY from a register value.
#define BG_ELCDIF_DEBUG0_PXP_LCDIF_B0_READY(r)   (((r) & BM_ELCDIF_DEBUG0_PXP_LCDIF_B0_READY) >> BP_ELCDIF_DEBUG0_PXP_LCDIF_B0_READY)

/* --- Register HW_ELCDIF_DEBUG0, field CUR_STATE[22:16] (RO)
 *
 * Read only view of the current state machine state in the current mode of operation.
 */

#define BP_ELCDIF_DEBUG0_CUR_STATE      (16)      //!< Bit position for ELCDIF_DEBUG0_CUR_STATE.
#define BM_ELCDIF_DEBUG0_CUR_STATE      (0x007f0000)  //!< Bit mask for ELCDIF_DEBUG0_CUR_STATE.

//! @brief Get value of ELCDIF_DEBUG0_CUR_STATE from a register value.
#define BG_ELCDIF_DEBUG0_CUR_STATE(r)   (((r) & BM_ELCDIF_DEBUG0_CUR_STATE) >> BP_ELCDIF_DEBUG0_CUR_STATE)

/* --- Register HW_ELCDIF_DEBUG0, field EMPTY_WORD[23] (RO)
 *
 * Indicates that the current word is empty.
 */

#define BP_ELCDIF_DEBUG0_EMPTY_WORD      (23)      //!< Bit position for ELCDIF_DEBUG0_EMPTY_WORD.
#define BM_ELCDIF_DEBUG0_EMPTY_WORD      (0x00800000)  //!< Bit mask for ELCDIF_DEBUG0_EMPTY_WORD.

//! @brief Get value of ELCDIF_DEBUG0_EMPTY_WORD from a register value.
#define BG_ELCDIF_DEBUG0_EMPTY_WORD(r)   (((r) & BM_ELCDIF_DEBUG0_EMPTY_WORD) >> BP_ELCDIF_DEBUG0_EMPTY_WORD)

/* --- Register HW_ELCDIF_DEBUG0, field CUR_FRAME_TX[24] (RO)
 *
 * This bit is 1 for the time the current frame is being transmitted in the VSYNC mode. Useful for
 * VSYNC mode debug.
 */

#define BP_ELCDIF_DEBUG0_CUR_FRAME_TX      (24)      //!< Bit position for ELCDIF_DEBUG0_CUR_FRAME_TX.
#define BM_ELCDIF_DEBUG0_CUR_FRAME_TX      (0x01000000)  //!< Bit mask for ELCDIF_DEBUG0_CUR_FRAME_TX.

//! @brief Get value of ELCDIF_DEBUG0_CUR_FRAME_TX from a register value.
#define BG_ELCDIF_DEBUG0_CUR_FRAME_TX(r)   (((r) & BM_ELCDIF_DEBUG0_CUR_FRAME_TX) >> BP_ELCDIF_DEBUG0_CUR_FRAME_TX)

/* --- Register HW_ELCDIF_DEBUG0, field VSYNC[25] (RO)
 *
 * Read only view of VSYNC signal.
 */

#define BP_ELCDIF_DEBUG0_VSYNC      (25)      //!< Bit position for ELCDIF_DEBUG0_VSYNC.
#define BM_ELCDIF_DEBUG0_VSYNC      (0x02000000)  //!< Bit mask for ELCDIF_DEBUG0_VSYNC.

//! @brief Get value of ELCDIF_DEBUG0_VSYNC from a register value.
#define BG_ELCDIF_DEBUG0_VSYNC(r)   (((r) & BM_ELCDIF_DEBUG0_VSYNC) >> BP_ELCDIF_DEBUG0_VSYNC)

/* --- Register HW_ELCDIF_DEBUG0, field HSYNC[26] (RO)
 *
 * Read only view of HSYNC signal.
 */

#define BP_ELCDIF_DEBUG0_HSYNC      (26)      //!< Bit position for ELCDIF_DEBUG0_HSYNC.
#define BM_ELCDIF_DEBUG0_HSYNC      (0x04000000)  //!< Bit mask for ELCDIF_DEBUG0_HSYNC.

//! @brief Get value of ELCDIF_DEBUG0_HSYNC from a register value.
#define BG_ELCDIF_DEBUG0_HSYNC(r)   (((r) & BM_ELCDIF_DEBUG0_HSYNC) >> BP_ELCDIF_DEBUG0_HSYNC)

/* --- Register HW_ELCDIF_DEBUG0, field ENABLE[27] (RO)
 *
 * Read only view of ENABLE signal.
 */

#define BP_ELCDIF_DEBUG0_ENABLE      (27)      //!< Bit position for ELCDIF_DEBUG0_ENABLE.
#define BM_ELCDIF_DEBUG0_ENABLE      (0x08000000)  //!< Bit mask for ELCDIF_DEBUG0_ENABLE.

//! @brief Get value of ELCDIF_DEBUG0_ENABLE from a register value.
#define BG_ELCDIF_DEBUG0_ENABLE(r)   (((r) & BM_ELCDIF_DEBUG0_ENABLE) >> BP_ELCDIF_DEBUG0_ENABLE)

/* --- Register HW_ELCDIF_DEBUG0, field DMACMDKICK[28] (RO)
 *
 * Read only view of the DMA command kick signal.
 */

#define BP_ELCDIF_DEBUG0_DMACMDKICK      (28)      //!< Bit position for ELCDIF_DEBUG0_DMACMDKICK.
#define BM_ELCDIF_DEBUG0_DMACMDKICK      (0x10000000)  //!< Bit mask for ELCDIF_DEBUG0_DMACMDKICK.

//! @brief Get value of ELCDIF_DEBUG0_DMACMDKICK from a register value.
#define BG_ELCDIF_DEBUG0_DMACMDKICK(r)   (((r) & BM_ELCDIF_DEBUG0_DMACMDKICK) >> BP_ELCDIF_DEBUG0_DMACMDKICK)

/* --- Register HW_ELCDIF_DEBUG0, field SYNC_SIGNALS_ON_REG[29] (RO)
 *
 * Read only view of internal sync_signals_on_reg signal.
 */

#define BP_ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG      (29)      //!< Bit position for ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG.
#define BM_ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG      (0x20000000)  //!< Bit mask for ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG.

//! @brief Get value of ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG from a register value.
#define BG_ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG(r)   (((r) & BM_ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG) >> BP_ELCDIF_DEBUG0_SYNC_SIGNALS_ON_REG)

/* --- Register HW_ELCDIF_DEBUG0, field WAIT_FOR_VSYNC_EDGE_OUT[30] (RO)
 *
 * Read only view of WAIT_FOR_VSYNC_EDGE bit in the VSYNC mode after it comes out of the TXFIFO.
 */

#define BP_ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT      (30)      //!< Bit position for ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT.
#define BM_ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT      (0x40000000)  //!< Bit mask for ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT.

//! @brief Get value of ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT from a register value.
#define BG_ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT(r)   (((r) & BM_ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT) >> BP_ELCDIF_DEBUG0_WAIT_FOR_VSYNC_EDGE_OUT)

/* --- Register HW_ELCDIF_DEBUG0, field STREAMING_END_DETECTED[31] (RO)
 *
 * Read only view of the DOTCLK_MODE or DVI_MODE bit going from 1 to 0.
 */

#define BP_ELCDIF_DEBUG0_STREAMING_END_DETECTED      (31)      //!< Bit position for ELCDIF_DEBUG0_STREAMING_END_DETECTED.
#define BM_ELCDIF_DEBUG0_STREAMING_END_DETECTED      (0x80000000)  //!< Bit mask for ELCDIF_DEBUG0_STREAMING_END_DETECTED.

//! @brief Get value of ELCDIF_DEBUG0_STREAMING_END_DETECTED from a register value.
#define BG_ELCDIF_DEBUG0_STREAMING_END_DETECTED(r)   (((r) & BM_ELCDIF_DEBUG0_STREAMING_END_DETECTED) >> BP_ELCDIF_DEBUG0_STREAMING_END_DETECTED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DEBUG1 - LCD Interface Debug1 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The LCD interface debug1 register provides a diagnostic view of the state machine and other
 * useful internal signals.  The LCD interface debug register is for diagnostic use only.
 */
typedef union _hw_elcdif_debug1
{
    reg32_t U;
    struct _hw_elcdif_debug1_bitfields
    {
        unsigned V_DATA_COUNT : 16; //!< [15:0] Read only view of the current state of the vertical data counter.
        unsigned H_DATA_COUNT : 16; //!< [31:16] Read only view of the current state of the horizontal data counter.
    } B;
} hw_elcdif_debug1_t;
#endif

/*
 * constants & macros for entire ELCDIF_DEBUG1 register
 */
#define HW_ELCDIF_DEBUG1_ADDR      (REGS_ELCDIF_BASE + 0x1e0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DEBUG1           (*(volatile hw_elcdif_debug1_t *) HW_ELCDIF_DEBUG1_ADDR)
#define HW_ELCDIF_DEBUG1_RD()      (HW_ELCDIF_DEBUG1.U)
#endif

/*
 * constants & macros for individual ELCDIF_DEBUG1 bitfields
 */

/* --- Register HW_ELCDIF_DEBUG1, field V_DATA_COUNT[15:0] (RO)
 *
 * Read only view of the current state of the vertical data counter.
 */

#define BP_ELCDIF_DEBUG1_V_DATA_COUNT      (0)      //!< Bit position for ELCDIF_DEBUG1_V_DATA_COUNT.
#define BM_ELCDIF_DEBUG1_V_DATA_COUNT      (0x0000ffff)  //!< Bit mask for ELCDIF_DEBUG1_V_DATA_COUNT.

//! @brief Get value of ELCDIF_DEBUG1_V_DATA_COUNT from a register value.
#define BG_ELCDIF_DEBUG1_V_DATA_COUNT(r)   (((r) & BM_ELCDIF_DEBUG1_V_DATA_COUNT) >> BP_ELCDIF_DEBUG1_V_DATA_COUNT)

/* --- Register HW_ELCDIF_DEBUG1, field H_DATA_COUNT[31:16] (RO)
 *
 * Read only view of the current state of the horizontal data counter.
 */

#define BP_ELCDIF_DEBUG1_H_DATA_COUNT      (16)      //!< Bit position for ELCDIF_DEBUG1_H_DATA_COUNT.
#define BM_ELCDIF_DEBUG1_H_DATA_COUNT      (0xffff0000)  //!< Bit mask for ELCDIF_DEBUG1_H_DATA_COUNT.

//! @brief Get value of ELCDIF_DEBUG1_H_DATA_COUNT from a register value.
#define BG_ELCDIF_DEBUG1_H_DATA_COUNT(r)   (((r) & BM_ELCDIF_DEBUG1_H_DATA_COUNT) >> BP_ELCDIF_DEBUG1_H_DATA_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_DEBUG2 - LCD Interface Debug2 Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The LCD interface debug2 register provides a diagnostic view of the state machine and other
 * useful internal signals.  The LCD interface debug register is for diagnostic use only.
 */
typedef union _hw_elcdif_debug2
{
    reg32_t U;
    struct _hw_elcdif_debug2_bitfields
    {
        unsigned MST_ADDRESS : 32; //!< [31:0] Read only view of the current address issued by the AXI bus master.
    } B;
} hw_elcdif_debug2_t;
#endif

/*
 * constants & macros for entire ELCDIF_DEBUG2 register
 */
#define HW_ELCDIF_DEBUG2_ADDR      (REGS_ELCDIF_BASE + 0x1f0)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_DEBUG2           (*(volatile hw_elcdif_debug2_t *) HW_ELCDIF_DEBUG2_ADDR)
#define HW_ELCDIF_DEBUG2_RD()      (HW_ELCDIF_DEBUG2.U)
#endif

/*
 * constants & macros for individual ELCDIF_DEBUG2 bitfields
 */

/* --- Register HW_ELCDIF_DEBUG2, field MST_ADDRESS[31:0] (RO)
 *
 * Read only view of the current address issued by the AXI bus master.
 */

#define BP_ELCDIF_DEBUG2_MST_ADDRESS      (0)      //!< Bit position for ELCDIF_DEBUG2_MST_ADDRESS.
#define BM_ELCDIF_DEBUG2_MST_ADDRESS      (0xffffffff)  //!< Bit mask for ELCDIF_DEBUG2_MST_ADDRESS.

//! @brief Get value of ELCDIF_DEBUG2_MST_ADDRESS from a register value.
#define BG_ELCDIF_DEBUG2_MST_ADDRESS(r)   (((r) & BM_ELCDIF_DEBUG2_MST_ADDRESS) >> BP_ELCDIF_DEBUG2_MST_ADDRESS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ELCDIF_THRES - eLCDIF Threshold Register (RW)
 *
 * Reset value: 0x0100000f
 *
 * This register is used to activate control signals when the number of pixels reaches the
 * programmed threshold. These control signals, in turn, can be used to manipulate access priority
 * or dynamically change the input clock frequency to meet the required pixel throughput.  Memory
 * request priority threshold register.
 */
typedef union _hw_elcdif_thres
{
    reg32_t U;
    struct _hw_elcdif_thres_bitfields
    {
        unsigned PANIC : 9; //!< [8:0] This value should be set to a value of pixels, from 0 to 511. When the number of pixels in the input pixel FIFO is LESS than this value, the panic control output will be raised. This signal can be used to raise the access eLCDIF's access priority.
        unsigned RESERVED0 : 7; //!< [15:9] Reserved bits. Write as 0.
        unsigned FASTCLOCK : 9; //!< [24:16] This value should be set to a value of pixels, from 0 to 511. When the number of pixels in the input pixel FIFO is LESS than this value, the fast clock control output will be raised. This signal can be used to reduce the system bus clock frequency to save power during horizontal/vertical blanking intervals. This value should also be programmed to a value that is greater than the "PANIC" threshold value. This will allow a faster clock to recover the number of pixels in the FIFO before a "panic" level is encountered.
        unsigned RESERVED1 : 7; //!< [31:25] Reserved bits. Write as 0.
    } B;
} hw_elcdif_thres_t;
#endif

/*
 * constants & macros for entire ELCDIF_THRES register
 */
#define HW_ELCDIF_THRES_ADDR      (REGS_ELCDIF_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_ELCDIF_THRES           (*(volatile hw_elcdif_thres_t *) HW_ELCDIF_THRES_ADDR)
#define HW_ELCDIF_THRES_RD()      (HW_ELCDIF_THRES.U)
#define HW_ELCDIF_THRES_WR(v)     (HW_ELCDIF_THRES.U = (v))
#define HW_ELCDIF_THRES_SET(v)    (HW_ELCDIF_THRES_WR(HW_ELCDIF_THRES_RD() |  (v)))
#define HW_ELCDIF_THRES_CLR(v)    (HW_ELCDIF_THRES_WR(HW_ELCDIF_THRES_RD() & ~(v)))
#define HW_ELCDIF_THRES_TOG(v)    (HW_ELCDIF_THRES_WR(HW_ELCDIF_THRES_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ELCDIF_THRES bitfields
 */

/* --- Register HW_ELCDIF_THRES, field PANIC[8:0] (RW)
 *
 * This value should be set to a value of pixels, from 0 to 511. When the number of pixels in the
 * input pixel FIFO is LESS than this value, the panic control output will be raised. This signal
 * can be used to raise the access eLCDIF's access priority.
 */

#define BP_ELCDIF_THRES_PANIC      (0)      //!< Bit position for ELCDIF_THRES_PANIC.
#define BM_ELCDIF_THRES_PANIC      (0x000001ff)  //!< Bit mask for ELCDIF_THRES_PANIC.

//! @brief Get value of ELCDIF_THRES_PANIC from a register value.
#define BG_ELCDIF_THRES_PANIC(r)   (((r) & BM_ELCDIF_THRES_PANIC) >> BP_ELCDIF_THRES_PANIC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_THRES_PANIC.
#define BF_ELCDIF_THRES_PANIC(v)   ((((reg32_t) v) << BP_ELCDIF_THRES_PANIC) & BM_ELCDIF_THRES_PANIC)
#else
//! @brief Format value for bitfield ELCDIF_THRES_PANIC.
#define BF_ELCDIF_THRES_PANIC(v)   (((v) << BP_ELCDIF_THRES_PANIC) & BM_ELCDIF_THRES_PANIC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PANIC field to a new value.
#define BW_ELCDIF_THRES_PANIC(v)   (HW_ELCDIF_THRES_WR((HW_ELCDIF_THRES_RD() & ~BM_ELCDIF_THRES_PANIC) | BF_ELCDIF_THRES_PANIC(v)))
#endif

/* --- Register HW_ELCDIF_THRES, field FASTCLOCK[24:16] (RW)
 *
 * This value should be set to a value of pixels, from 0 to 511. When the number of pixels in the
 * input pixel FIFO is LESS than this value, the fast clock control output will be raised. This
 * signal can be used to reduce the system bus clock frequency to save power during
 * horizontal/vertical blanking intervals. This value should also be programmed to a value that is
 * greater than the "PANIC" threshold value. This will allow a faster clock to recover the number of
 * pixels in the FIFO before a "panic" level is encountered.
 */

#define BP_ELCDIF_THRES_FASTCLOCK      (16)      //!< Bit position for ELCDIF_THRES_FASTCLOCK.
#define BM_ELCDIF_THRES_FASTCLOCK      (0x01ff0000)  //!< Bit mask for ELCDIF_THRES_FASTCLOCK.

//! @brief Get value of ELCDIF_THRES_FASTCLOCK from a register value.
#define BG_ELCDIF_THRES_FASTCLOCK(r)   (((r) & BM_ELCDIF_THRES_FASTCLOCK) >> BP_ELCDIF_THRES_FASTCLOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ELCDIF_THRES_FASTCLOCK.
#define BF_ELCDIF_THRES_FASTCLOCK(v)   ((((reg32_t) v) << BP_ELCDIF_THRES_FASTCLOCK) & BM_ELCDIF_THRES_FASTCLOCK)
#else
//! @brief Format value for bitfield ELCDIF_THRES_FASTCLOCK.
#define BF_ELCDIF_THRES_FASTCLOCK(v)   (((v) << BP_ELCDIF_THRES_FASTCLOCK) & BM_ELCDIF_THRES_FASTCLOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FASTCLOCK field to a new value.
#define BW_ELCDIF_THRES_FASTCLOCK(v)   (HW_ELCDIF_THRES_WR((HW_ELCDIF_THRES_RD() & ~BM_ELCDIF_THRES_FASTCLOCK) | BF_ELCDIF_THRES_FASTCLOCK(v)))
#endif


/*!
 * @brief All ELCDIF module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_elcdif
{
    volatile hw_elcdif_ctrl_t CTRL; //!< eLCDIF General Control Register
    volatile reg32_t CTRL_SET; //!< eLCDIF General Control Register Set
    volatile reg32_t CTRL_CLR; //!< eLCDIF General Control Register Clear
    volatile reg32_t CTRL_TOG; //!< eLCDIF General Control Register Toggle
    volatile hw_elcdif_ctrl1_t CTRL1; //!< eLCDIF General Control1 Register
    volatile reg32_t CTRL1_SET; //!< eLCDIF General Control1 Register Set
    volatile reg32_t CTRL1_CLR; //!< eLCDIF General Control1 Register Clear
    volatile reg32_t CTRL1_TOG; //!< eLCDIF General Control1 Register Toggle
    volatile hw_elcdif_ctrl2_t CTRL2; //!< eLCDIF General Control2 Register
    volatile reg32_t CTRL2_SET; //!< eLCDIF General Control2 Register Set
    volatile reg32_t CTRL2_CLR; //!< eLCDIF General Control2 Register Clear
    volatile reg32_t CTRL2_TOG; //!< eLCDIF General Control2 Register Toggle
    volatile hw_elcdif_transfer_count_t TRANSFER_COUNT; //!< eLCDIF Horizontal and Vertical Valid Data Count Register
    reg32_t _reserved0[3];
    volatile hw_elcdif_cur_buf_t CUR_BUF; //!< LCD Interface Current Buffer Address Register
    reg32_t _reserved1[3];
    volatile hw_elcdif_next_buf_t NEXT_BUF; //!< LCD Interface Next Buffer Address Register
    reg32_t _reserved2[3];
    volatile hw_elcdif_timing_t TIMING; //!< LCD Interface Timing Register
    reg32_t _reserved3[3];
    volatile hw_elcdif_vdctrl0_t VDCTRL0; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register0
    volatile reg32_t VDCTRL0_SET; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register0 Set
    volatile reg32_t VDCTRL0_CLR; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register0 Clear
    volatile reg32_t VDCTRL0_TOG; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register0 Toggle
    volatile hw_elcdif_vdctrl1_t VDCTRL1; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register1
    reg32_t _reserved4[3];
    volatile hw_elcdif_vdctrl2_t VDCTRL2; //!< LCDIF VSYNC Mode and Dotclk Mode Control Register2
    reg32_t _reserved5[3];
    volatile hw_elcdif_vdctrl3_t VDCTRL3; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register3
    reg32_t _reserved6[3];
    volatile hw_elcdif_vdctrl4_t VDCTRL4; //!< eLCDIF VSYNC Mode and Dotclk Mode Control Register4
    reg32_t _reserved7[3];
    volatile hw_elcdif_dvictrl0_t DVICTRL0; //!< Digital Video Interface Control0 Register
    reg32_t _reserved8[3];
    volatile hw_elcdif_dvictrl1_t DVICTRL1; //!< Digital Video Interface Control1 Register
    reg32_t _reserved9[3];
    volatile hw_elcdif_dvictrl2_t DVICTRL2; //!< Digital Video Interface Control2 Register
    reg32_t _reserved10[3];
    volatile hw_elcdif_dvictrl3_t DVICTRL3; //!< Digital Video Interface Control3 Register
    reg32_t _reserved11[3];
    volatile hw_elcdif_dvictrl4_t DVICTRL4; //!< Digital Video Interface Control4 Register
    reg32_t _reserved12[3];
    volatile hw_elcdif_csc_coeff0_t CSC_COEFF0; //!< RGB to YCbCr 4:2:2 CSC Coefficient0 Register
    reg32_t _reserved13[3];
    volatile hw_elcdif_csc_coeff1_t CSC_COEFF1; //!< RGB to YCbCr 4:2:2 CSC Coefficient1 Register
    reg32_t _reserved14[3];
    volatile hw_elcdif_csc_coeff2_t CSC_COEFF2; //!< RGB to YCbCr 4:2:2 CSC Coefficent2 Register
    reg32_t _reserved15[3];
    volatile hw_elcdif_csc_coeff3_t CSC_COEFF3; //!< RGB to YCbCr 4:2:2 CSC Coefficient3 Register
    reg32_t _reserved16[3];
    volatile hw_elcdif_csc_coeff4_t CSC_COEFF4; //!< RGB to YCbCr 4:2:2 CSC Coefficient4 Register
    reg32_t _reserved17[3];
    volatile hw_elcdif_csc_offset_t CSC_OFFSET; //!< RGB to YCbCr 4:2:2 CSC Offset Register
    reg32_t _reserved18[3];
    volatile hw_elcdif_csc_limit_t CSC_LIMIT; //!< RGB to YCbCr 4:2:2 CSC Limit Register
    reg32_t _reserved19[3];
    volatile hw_elcdif_data_t DATA; //!< LCD Interface Data Register
    reg32_t _reserved20[3];
    volatile hw_elcdif_bm_error_stat_t BM_ERROR_STAT; //!< Bus Master Error Status Register
    reg32_t _reserved21[3];
    volatile hw_elcdif_crc_stat_t CRC_STAT; //!< CRC Status Register
    reg32_t _reserved22[3];
    volatile hw_elcdif_stat_t STAT; //!< LCD Interface Status Register
    reg32_t _reserved23[3];
    volatile hw_elcdif_version_t VERSION; //!< LCD Interface Version Register
    reg32_t _reserved24[3];
    volatile hw_elcdif_debug0_t DEBUG0; //!< LCD Interface Debug0 Register
    reg32_t _reserved25[3];
    volatile hw_elcdif_debug1_t DEBUG1; //!< LCD Interface Debug1 Register
    reg32_t _reserved26[3];
    volatile hw_elcdif_debug2_t DEBUG2; //!< LCD Interface Debug2 Register
    reg32_t _reserved27[3];
    volatile hw_elcdif_thres_t THRES; //!< eLCDIF Threshold Register
} hw_elcdif_t;
#pragma pack()

//! @brief Macro to access all ELCDIF registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ELCDIF(0)</code>.
#define HW_ELCDIF     (*(volatile hw_elcdif_t *) REGS_ELCDIF_BASE)

#endif


#endif // __HW_ELCDIF_REGISTERS_H__
