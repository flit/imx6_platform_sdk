/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_SRC_REGISTERS_H__
#define __HW_SRC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ SRC registers defined in this header file.
 *
 * - HW_SRC_SCR - SRC Control Register
 * - HW_SRC_SBMR1 - SRC Boot Mode Register 1
 * - HW_SRC_SRSR - SRC Reset Status Register
 * - HW_SRC_SISR - SRC Interrupt Status Register
 * - HW_SRC_SIMR - SRC Interrupt Mask Register
 * - HW_SRC_SBMR2 - SRC Boot Mode Register 2
 * - HW_SRC_GPR1 - SRC General Purpose Register 1
 * - HW_SRC_GPR2 - SRC General Purpose Register 2
 * - HW_SRC_GPR3 - SRC General Purpose Register 3
 * - HW_SRC_GPR4 - SRC General Purpose Register 4
 * - HW_SRC_GPR5 - SRC General Purpose Register 5
 * - HW_SRC_GPR6 - SRC General Purpose Register 6
 * - HW_SRC_GPR7 - SRC General Purpose Register 7
 * - HW_SRC_GPR8 - SRC General Purpose Register 8
 * - HW_SRC_GPR9 - SRC General Purpose Register 9
 * - HW_SRC_GPR10 - SRC General Purpose Register 10
 *
 * - hw_src_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SRC_BASE
#define HW_SRC_INSTANCE_COUNT (1) //!< Number of instances of the SRC module.
#define REGS_SRC_BASE (0x020d8000) //!< Base address for SRC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SCR - SRC Control Register (RW)
 *
 * Reset value: 0x00000521
 *
 * The Reset control register (SCR), contains bits that control operation of the reset controller.
 */
typedef union _hw_src_scr
{
    reg32_t U;
    struct _hw_src_scr_bitfields
    {
        unsigned WARM_RESET_ENABLE : 1; //!< [0] Warm reset enable bit. Warm reset will be enabled only if warm_reset_enable bit is set. Otherwise all warm reset sources will generate cold reset.
        unsigned SW_GPU_RST : 1; //!< [1] Software reset for gpu this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details. the reset process will involve 8 gpu cycles before negating the gpu reset, to allow reset assertion to propagate into gpu.
        unsigned SW_VPU_RST : 1; //!< [2] Software reset for vpu this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details. the reset process will involve 8 vpu cycles before negating the vpu reset, to allow reset assertion to propagate into vpu.
        unsigned SW_IPU1_RST : 1; //!< [3] Software reset for ipu1 Note: this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details.
        unsigned SW_OPEN_VG_RST : 1; //!< [4] Software reset for open_vg this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details. the reset process will involve 8 open_vg cycles before negating the open_vg reset, to allow reset assertion to propagate into open_vg.
        unsigned WARM_RST_BYPASS_COUNT : 2; //!< [6:5] Defines the ckil cycles to count before bypassing the emi acknowledge for warm reset. If the emi acknowledge will not be asserted before this counter has elapsed, then a cold reset will be initiated.
        unsigned MASK_WDOG_RST : 4; //!< [10:7] Mask wdog_rst_b source. If these 4 bits are coded from A to 5 then, wdog_rst_b input to SRC will be masked and wdog_rst_b will not create reset to the IC. During the time the WDOG event is masked using SRC logic, it is likely that WDOG Reset Status Register (WRSR) bit 1 (which indicates WDOG timeout event) will get asserted. SW / OS developer must prepare for this case. Re-enable WDOG is possible, by un-mask it in SRC, though it must be preceded by servicing the WDOG. However, for the case that the event has been asserted, the status bit (WRSR bit-1) will remain asserted, regardless of servicing the WDOG module. (HW reset is the only mean to cause de-assertion of that bit). any other code will be coded to 1010 i.e. wdog_rst_b is not masked
        unsigned WEIM_RST : 1; //!< [11] WEIM reset is needed in order to reconfigure the weim chip select. The software reset bit must de-asserted. The weim chip select configuration should be updated. The software bit must be re-asserted since this is not self-refresh.
        unsigned SW_IPU2_RST : 1; //!< [12] Software reset for ipu2 this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details.
        unsigned CORE0_RST : 1; //!< [13] Software reset for core0 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE1_RST : 1; //!< [14] Software reset for core1 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE2_RST : 1; //!< [15] Software reset for core2 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE3_RST : 1; //!< [16] Software reset for core3 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE0_DBG_RST : 1; //!< [17] Software reset for core0 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE1_DBG_RST : 1; //!< [18] Software reset for core1 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE2_DBG_RST : 1; //!< [19] Software reset for core2 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE3_DBG_RST : 1; //!< [20] Software reset for core3 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORES_DBG_RST : 1; //!< [21] Software reset for debug of arm platform only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE1_ENABLE : 1; //!< [22] CPU core1 enable. core0 cannot be disabled
        unsigned CORE2_ENABLE : 1; //!< [23] CPU core2 enable. core0 cannot be disabled
        unsigned CORE3_ENABLE : 1; //!< [24] CPU core3 enable. core0 cannot be disabled
        unsigned DBG_RST_MSK_PG : 1; //!< [25] Do not assert debug resets after power gating event of cpu
        unsigned RESERVED0 : 6; //!< [31:26] Reserved
    } B;
} hw_src_scr_t;
#endif

/*
 * constants & macros for entire SRC_SCR register
 */
#define HW_SRC_SCR_ADDR      (REGS_SRC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_SCR           (*(volatile hw_src_scr_t *) HW_SRC_SCR_ADDR)
#define HW_SRC_SCR_RD()      (HW_SRC_SCR.U)
#define HW_SRC_SCR_WR(v)     (HW_SRC_SCR.U = (v))
#define HW_SRC_SCR_SET(v)    (HW_SRC_SCR_WR(HW_SRC_SCR_RD() |  (v)))
#define HW_SRC_SCR_CLR(v)    (HW_SRC_SCR_WR(HW_SRC_SCR_RD() & ~(v)))
#define HW_SRC_SCR_TOG(v)    (HW_SRC_SCR_WR(HW_SRC_SCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_SCR bitfields
 */

/* --- Register HW_SRC_SCR, field WARM_RESET_ENABLE[0] (RW)
 *
 * Warm reset enable bit. Warm reset will be enabled only if warm_reset_enable bit is set. Otherwise
 * all warm reset sources will generate cold reset.
 *
 * Values:
 * 0 - Warm reset disabled
 * 1 - Warm reset enabled
 */

#define BP_SRC_SCR_WARM_RESET_ENABLE      (0)      //!< Bit position for SRC_SCR_WARM_RESET_ENABLE.
#define BM_SRC_SCR_WARM_RESET_ENABLE      (0x00000001)  //!< Bit mask for SRC_SCR_WARM_RESET_ENABLE.

//! @brief Get value of SRC_SCR_WARM_RESET_ENABLE from a register value.
#define BG_SRC_SCR_WARM_RESET_ENABLE(r)   (((r) & BM_SRC_SCR_WARM_RESET_ENABLE) >> BP_SRC_SCR_WARM_RESET_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_WARM_RESET_ENABLE.
#define BF_SRC_SCR_WARM_RESET_ENABLE(v)   ((((reg32_t) v) << BP_SRC_SCR_WARM_RESET_ENABLE) & BM_SRC_SCR_WARM_RESET_ENABLE)
#else
//! @brief Format value for bitfield SRC_SCR_WARM_RESET_ENABLE.
#define BF_SRC_SCR_WARM_RESET_ENABLE(v)   (((v) << BP_SRC_SCR_WARM_RESET_ENABLE) & BM_SRC_SCR_WARM_RESET_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WARM_RESET_ENABLE field to a new value.
#define BW_SRC_SCR_WARM_RESET_ENABLE(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_WARM_RESET_ENABLE) | BF_SRC_SCR_WARM_RESET_ENABLE(v)))
#endif


/* --- Register HW_SRC_SCR, field SW_GPU_RST[1] (RW)
 *
 * Software reset for gpu this is a self clearing bit. Once it is set to 1, the reset process will
 * begin, and once it finishes, this bit will be self cleared. Software can determine that the reset
 * has finished once this bit is cleared. Software can also configure SRC to generate interrutp once
 * the software has finished. Please referto SISR register for details. the reset process will
 * involve 8 gpu cycles before negating the gpu reset, to allow reset assertion to propagate into
 * gpu.
 *
 * Values:
 * 0 - do not assert gpu reset
 * 1 - assert gpu reset
 */

#define BP_SRC_SCR_SW_GPU_RST      (1)      //!< Bit position for SRC_SCR_SW_GPU_RST.
#define BM_SRC_SCR_SW_GPU_RST      (0x00000002)  //!< Bit mask for SRC_SCR_SW_GPU_RST.

//! @brief Get value of SRC_SCR_SW_GPU_RST from a register value.
#define BG_SRC_SCR_SW_GPU_RST(r)   (((r) & BM_SRC_SCR_SW_GPU_RST) >> BP_SRC_SCR_SW_GPU_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_SW_GPU_RST.
#define BF_SRC_SCR_SW_GPU_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_SW_GPU_RST) & BM_SRC_SCR_SW_GPU_RST)
#else
//! @brief Format value for bitfield SRC_SCR_SW_GPU_RST.
#define BF_SRC_SCR_SW_GPU_RST(v)   (((v) << BP_SRC_SCR_SW_GPU_RST) & BM_SRC_SCR_SW_GPU_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_GPU_RST field to a new value.
#define BW_SRC_SCR_SW_GPU_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_SW_GPU_RST) | BF_SRC_SCR_SW_GPU_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field SW_VPU_RST[2] (RW)
 *
 * Software reset for vpu this is a self clearing bit. Once it is set to 1, the reset process will
 * begin, and once it finishes, this bit will be self cleared. Software can determine that the reset
 * has finished once this bit is cleared. Software can also configure SRC to generate interrutp once
 * the software has finished. Please referto SISR register for details. the reset process will
 * involve 8 vpu cycles before negating the vpu reset, to allow reset assertion to propagate into
 * vpu.
 *
 * Values:
 * 0 - do not assert vpu reset
 * 1 - assert vpu reset
 */

#define BP_SRC_SCR_SW_VPU_RST      (2)      //!< Bit position for SRC_SCR_SW_VPU_RST.
#define BM_SRC_SCR_SW_VPU_RST      (0x00000004)  //!< Bit mask for SRC_SCR_SW_VPU_RST.

//! @brief Get value of SRC_SCR_SW_VPU_RST from a register value.
#define BG_SRC_SCR_SW_VPU_RST(r)   (((r) & BM_SRC_SCR_SW_VPU_RST) >> BP_SRC_SCR_SW_VPU_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_SW_VPU_RST.
#define BF_SRC_SCR_SW_VPU_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_SW_VPU_RST) & BM_SRC_SCR_SW_VPU_RST)
#else
//! @brief Format value for bitfield SRC_SCR_SW_VPU_RST.
#define BF_SRC_SCR_SW_VPU_RST(v)   (((v) << BP_SRC_SCR_SW_VPU_RST) & BM_SRC_SCR_SW_VPU_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_VPU_RST field to a new value.
#define BW_SRC_SCR_SW_VPU_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_SW_VPU_RST) | BF_SRC_SCR_SW_VPU_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field SW_IPU1_RST[3] (RW)
 *
 * Software reset for ipu1 Note: this is a self clearing bit. Once it is set to 1, the reset process
 * will begin, and once it finishes, this bit will be self cleared. Software can determine that the
 * reset has finished once this bit is cleared. Software can also configure SRC to generate
 * interrutp once the software has finished. Please referto SISR register for details.
 *
 * Values:
 * 0 - do not assert ipu1 reset
 * 1 - assert ipu1 reset
 */

#define BP_SRC_SCR_SW_IPU1_RST      (3)      //!< Bit position for SRC_SCR_SW_IPU1_RST.
#define BM_SRC_SCR_SW_IPU1_RST      (0x00000008)  //!< Bit mask for SRC_SCR_SW_IPU1_RST.

//! @brief Get value of SRC_SCR_SW_IPU1_RST from a register value.
#define BG_SRC_SCR_SW_IPU1_RST(r)   (((r) & BM_SRC_SCR_SW_IPU1_RST) >> BP_SRC_SCR_SW_IPU1_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_SW_IPU1_RST.
#define BF_SRC_SCR_SW_IPU1_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_SW_IPU1_RST) & BM_SRC_SCR_SW_IPU1_RST)
#else
//! @brief Format value for bitfield SRC_SCR_SW_IPU1_RST.
#define BF_SRC_SCR_SW_IPU1_RST(v)   (((v) << BP_SRC_SCR_SW_IPU1_RST) & BM_SRC_SCR_SW_IPU1_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_IPU1_RST field to a new value.
#define BW_SRC_SCR_SW_IPU1_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_SW_IPU1_RST) | BF_SRC_SCR_SW_IPU1_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field SW_OPEN_VG_RST[4] (RW)
 *
 * Software reset for open_vg this is a self clearing bit. Once it is set to 1, the reset process
 * will begin, and once it finishes, this bit will be self cleared. Software can determine that the
 * reset has finished once this bit is cleared. Software can also configure SRC to generate
 * interrutp once the software has finished. Please referto SISR register for details. the reset
 * process will involve 8 open_vg cycles before negating the open_vg reset, to allow reset assertion
 * to propagate into open_vg.
 *
 * Values:
 * 0 - do not assert open_vg reset
 * 1 - assert open_vg reset
 */

#define BP_SRC_SCR_SW_OPEN_VG_RST      (4)      //!< Bit position for SRC_SCR_SW_OPEN_VG_RST.
#define BM_SRC_SCR_SW_OPEN_VG_RST      (0x00000010)  //!< Bit mask for SRC_SCR_SW_OPEN_VG_RST.

//! @brief Get value of SRC_SCR_SW_OPEN_VG_RST from a register value.
#define BG_SRC_SCR_SW_OPEN_VG_RST(r)   (((r) & BM_SRC_SCR_SW_OPEN_VG_RST) >> BP_SRC_SCR_SW_OPEN_VG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_SW_OPEN_VG_RST.
#define BF_SRC_SCR_SW_OPEN_VG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_SW_OPEN_VG_RST) & BM_SRC_SCR_SW_OPEN_VG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_SW_OPEN_VG_RST.
#define BF_SRC_SCR_SW_OPEN_VG_RST(v)   (((v) << BP_SRC_SCR_SW_OPEN_VG_RST) & BM_SRC_SCR_SW_OPEN_VG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_OPEN_VG_RST field to a new value.
#define BW_SRC_SCR_SW_OPEN_VG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_SW_OPEN_VG_RST) | BF_SRC_SCR_SW_OPEN_VG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field WARM_RST_BYPASS_COUNT[6:5] (RW)
 *
 * Defines the ckil cycles to count before bypassing the emi acknowledge for warm reset. If the emi
 * acknowledge will not be asserted before this counter has elapsed, then a cold reset will be
 * initiated.
 *
 * Values:
 * 00 - Counter not to be used - system will wait until emi acknowledge until it is asserted.
 * 01 - Wait 16 ckil cycles before changing warm reset to a cold reset.
 * 10 - Wait 32 ckil cycles before changing warm reset to a cold reset.
 * 11 - Wait 64 ckil cycles before changing warm reset to a cold reset
 */

#define BP_SRC_SCR_WARM_RST_BYPASS_COUNT      (5)      //!< Bit position for SRC_SCR_WARM_RST_BYPASS_COUNT.
#define BM_SRC_SCR_WARM_RST_BYPASS_COUNT      (0x00000060)  //!< Bit mask for SRC_SCR_WARM_RST_BYPASS_COUNT.

//! @brief Get value of SRC_SCR_WARM_RST_BYPASS_COUNT from a register value.
#define BG_SRC_SCR_WARM_RST_BYPASS_COUNT(r)   (((r) & BM_SRC_SCR_WARM_RST_BYPASS_COUNT) >> BP_SRC_SCR_WARM_RST_BYPASS_COUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_WARM_RST_BYPASS_COUNT.
#define BF_SRC_SCR_WARM_RST_BYPASS_COUNT(v)   ((((reg32_t) v) << BP_SRC_SCR_WARM_RST_BYPASS_COUNT) & BM_SRC_SCR_WARM_RST_BYPASS_COUNT)
#else
//! @brief Format value for bitfield SRC_SCR_WARM_RST_BYPASS_COUNT.
#define BF_SRC_SCR_WARM_RST_BYPASS_COUNT(v)   (((v) << BP_SRC_SCR_WARM_RST_BYPASS_COUNT) & BM_SRC_SCR_WARM_RST_BYPASS_COUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WARM_RST_BYPASS_COUNT field to a new value.
#define BW_SRC_SCR_WARM_RST_BYPASS_COUNT(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_WARM_RST_BYPASS_COUNT) | BF_SRC_SCR_WARM_RST_BYPASS_COUNT(v)))
#endif


/* --- Register HW_SRC_SCR, field MASK_WDOG_RST[10:7] (RW)
 *
 * Mask wdog_rst_b source. If these 4 bits are coded from A to 5 then, wdog_rst_b input to SRC will
 * be masked and wdog_rst_b will not create reset to the IC. During the time the WDOG event is
 * masked using SRC logic, it is likely that WDOG Reset Status Register (WRSR) bit 1 (which
 * indicates WDOG timeout event) will get asserted. SW / OS developer must prepare for this case.
 * Re-enable WDOG is possible, by un-mask it in SRC, though it must be preceded by servicing the
 * WDOG. However, for the case that the event has been asserted, the status bit (WRSR bit-1) will
 * remain asserted, regardless of servicing the WDOG module. (HW reset is the only mean to cause de-
 * assertion of that bit). any other code will be coded to 1010 i.e. wdog_rst_b is not masked
 *
 * Values:
 * 0101 - wdog_rst_b is masked
 * 1010 - wdog_rst_b is not masked (default)
 */

#define BP_SRC_SCR_MASK_WDOG_RST      (7)      //!< Bit position for SRC_SCR_MASK_WDOG_RST.
#define BM_SRC_SCR_MASK_WDOG_RST      (0x00000780)  //!< Bit mask for SRC_SCR_MASK_WDOG_RST.

//! @brief Get value of SRC_SCR_MASK_WDOG_RST from a register value.
#define BG_SRC_SCR_MASK_WDOG_RST(r)   (((r) & BM_SRC_SCR_MASK_WDOG_RST) >> BP_SRC_SCR_MASK_WDOG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_MASK_WDOG_RST.
#define BF_SRC_SCR_MASK_WDOG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_MASK_WDOG_RST) & BM_SRC_SCR_MASK_WDOG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_MASK_WDOG_RST.
#define BF_SRC_SCR_MASK_WDOG_RST(v)   (((v) << BP_SRC_SCR_MASK_WDOG_RST) & BM_SRC_SCR_MASK_WDOG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_WDOG_RST field to a new value.
#define BW_SRC_SCR_MASK_WDOG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_MASK_WDOG_RST) | BF_SRC_SCR_MASK_WDOG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field WEIM_RST[11] (RW)
 *
 * WEIM reset is needed in order to reconfigure the weim chip select. The software reset bit must
 * de-asserted. The weim chip select configuration should be updated. The software bit must be re-
 * asserted since this is not self-refresh.
 */

#define BP_SRC_SCR_WEIM_RST      (11)      //!< Bit position for SRC_SCR_WEIM_RST.
#define BM_SRC_SCR_WEIM_RST      (0x00000800)  //!< Bit mask for SRC_SCR_WEIM_RST.

//! @brief Get value of SRC_SCR_WEIM_RST from a register value.
#define BG_SRC_SCR_WEIM_RST(r)   (((r) & BM_SRC_SCR_WEIM_RST) >> BP_SRC_SCR_WEIM_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_WEIM_RST.
#define BF_SRC_SCR_WEIM_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_WEIM_RST) & BM_SRC_SCR_WEIM_RST)
#else
//! @brief Format value for bitfield SRC_SCR_WEIM_RST.
#define BF_SRC_SCR_WEIM_RST(v)   (((v) << BP_SRC_SCR_WEIM_RST) & BM_SRC_SCR_WEIM_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WEIM_RST field to a new value.
#define BW_SRC_SCR_WEIM_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_WEIM_RST) | BF_SRC_SCR_WEIM_RST(v)))
#endif

/* --- Register HW_SRC_SCR, field SW_IPU2_RST[12] (RW)
 *
 * Software reset for ipu2 this is a self clearing bit. Once it is set to 1, the reset process will
 * begin, and once it finishes, this bit will be self cleared. Software can determine that the reset
 * has finished once this bit is cleared. Software can also configure SRC to generate interrutp once
 * the software has finished. Please referto SISR register for details.
 *
 * Values:
 * 0 - do not assert ipu2 reset
 * 1 - assert ipu2 reset
 */

#define BP_SRC_SCR_SW_IPU2_RST      (12)      //!< Bit position for SRC_SCR_SW_IPU2_RST.
#define BM_SRC_SCR_SW_IPU2_RST      (0x00001000)  //!< Bit mask for SRC_SCR_SW_IPU2_RST.

//! @brief Get value of SRC_SCR_SW_IPU2_RST from a register value.
#define BG_SRC_SCR_SW_IPU2_RST(r)   (((r) & BM_SRC_SCR_SW_IPU2_RST) >> BP_SRC_SCR_SW_IPU2_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_SW_IPU2_RST.
#define BF_SRC_SCR_SW_IPU2_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_SW_IPU2_RST) & BM_SRC_SCR_SW_IPU2_RST)
#else
//! @brief Format value for bitfield SRC_SCR_SW_IPU2_RST.
#define BF_SRC_SCR_SW_IPU2_RST(v)   (((v) << BP_SRC_SCR_SW_IPU2_RST) & BM_SRC_SCR_SW_IPU2_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_IPU2_RST field to a new value.
#define BW_SRC_SCR_SW_IPU2_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_SW_IPU2_RST) | BF_SRC_SCR_SW_IPU2_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE0_RST[13] (RW)
 *
 * Software reset for core0 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE0_RST      (13)      //!< Bit position for SRC_SCR_CORE0_RST.
#define BM_SRC_SCR_CORE0_RST      (0x00002000)  //!< Bit mask for SRC_SCR_CORE0_RST.

//! @brief Get value of SRC_SCR_CORE0_RST from a register value.
#define BG_SRC_SCR_CORE0_RST(r)   (((r) & BM_SRC_SCR_CORE0_RST) >> BP_SRC_SCR_CORE0_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE0_RST.
#define BF_SRC_SCR_CORE0_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE0_RST) & BM_SRC_SCR_CORE0_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE0_RST.
#define BF_SRC_SCR_CORE0_RST(v)   (((v) << BP_SRC_SCR_CORE0_RST) & BM_SRC_SCR_CORE0_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE0_RST field to a new value.
#define BW_SRC_SCR_CORE0_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE0_RST) | BF_SRC_SCR_CORE0_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE1_RST[14] (RW)
 *
 * Software reset for core1 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE1_RST      (14)      //!< Bit position for SRC_SCR_CORE1_RST.
#define BM_SRC_SCR_CORE1_RST      (0x00004000)  //!< Bit mask for SRC_SCR_CORE1_RST.

//! @brief Get value of SRC_SCR_CORE1_RST from a register value.
#define BG_SRC_SCR_CORE1_RST(r)   (((r) & BM_SRC_SCR_CORE1_RST) >> BP_SRC_SCR_CORE1_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE1_RST.
#define BF_SRC_SCR_CORE1_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE1_RST) & BM_SRC_SCR_CORE1_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE1_RST.
#define BF_SRC_SCR_CORE1_RST(v)   (((v) << BP_SRC_SCR_CORE1_RST) & BM_SRC_SCR_CORE1_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE1_RST field to a new value.
#define BW_SRC_SCR_CORE1_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE1_RST) | BF_SRC_SCR_CORE1_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE2_RST[15] (RW)
 *
 * Software reset for core2 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE2_RST      (15)      //!< Bit position for SRC_SCR_CORE2_RST.
#define BM_SRC_SCR_CORE2_RST      (0x00008000)  //!< Bit mask for SRC_SCR_CORE2_RST.

//! @brief Get value of SRC_SCR_CORE2_RST from a register value.
#define BG_SRC_SCR_CORE2_RST(r)   (((r) & BM_SRC_SCR_CORE2_RST) >> BP_SRC_SCR_CORE2_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE2_RST.
#define BF_SRC_SCR_CORE2_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE2_RST) & BM_SRC_SCR_CORE2_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE2_RST.
#define BF_SRC_SCR_CORE2_RST(v)   (((v) << BP_SRC_SCR_CORE2_RST) & BM_SRC_SCR_CORE2_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE2_RST field to a new value.
#define BW_SRC_SCR_CORE2_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE2_RST) | BF_SRC_SCR_CORE2_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE3_RST[16] (RW)
 *
 * Software reset for core3 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE3_RST      (16)      //!< Bit position for SRC_SCR_CORE3_RST.
#define BM_SRC_SCR_CORE3_RST      (0x00010000)  //!< Bit mask for SRC_SCR_CORE3_RST.

//! @brief Get value of SRC_SCR_CORE3_RST from a register value.
#define BG_SRC_SCR_CORE3_RST(r)   (((r) & BM_SRC_SCR_CORE3_RST) >> BP_SRC_SCR_CORE3_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE3_RST.
#define BF_SRC_SCR_CORE3_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE3_RST) & BM_SRC_SCR_CORE3_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE3_RST.
#define BF_SRC_SCR_CORE3_RST(v)   (((v) << BP_SRC_SCR_CORE3_RST) & BM_SRC_SCR_CORE3_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE3_RST field to a new value.
#define BW_SRC_SCR_CORE3_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE3_RST) | BF_SRC_SCR_CORE3_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE0_DBG_RST[17] (RW)
 *
 * Software reset for core0 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 debug reset
 * 1 - assert core0 debug reset
 */

#define BP_SRC_SCR_CORE0_DBG_RST      (17)      //!< Bit position for SRC_SCR_CORE0_DBG_RST.
#define BM_SRC_SCR_CORE0_DBG_RST      (0x00020000)  //!< Bit mask for SRC_SCR_CORE0_DBG_RST.

//! @brief Get value of SRC_SCR_CORE0_DBG_RST from a register value.
#define BG_SRC_SCR_CORE0_DBG_RST(r)   (((r) & BM_SRC_SCR_CORE0_DBG_RST) >> BP_SRC_SCR_CORE0_DBG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE0_DBG_RST.
#define BF_SRC_SCR_CORE0_DBG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE0_DBG_RST) & BM_SRC_SCR_CORE0_DBG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE0_DBG_RST.
#define BF_SRC_SCR_CORE0_DBG_RST(v)   (((v) << BP_SRC_SCR_CORE0_DBG_RST) & BM_SRC_SCR_CORE0_DBG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE0_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE0_DBG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE0_DBG_RST) | BF_SRC_SCR_CORE0_DBG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE1_DBG_RST[18] (RW)
 *
 * Software reset for core1 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core1 debug reset
 * 1 - assert core1 debug reset
 */

#define BP_SRC_SCR_CORE1_DBG_RST      (18)      //!< Bit position for SRC_SCR_CORE1_DBG_RST.
#define BM_SRC_SCR_CORE1_DBG_RST      (0x00040000)  //!< Bit mask for SRC_SCR_CORE1_DBG_RST.

//! @brief Get value of SRC_SCR_CORE1_DBG_RST from a register value.
#define BG_SRC_SCR_CORE1_DBG_RST(r)   (((r) & BM_SRC_SCR_CORE1_DBG_RST) >> BP_SRC_SCR_CORE1_DBG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE1_DBG_RST.
#define BF_SRC_SCR_CORE1_DBG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE1_DBG_RST) & BM_SRC_SCR_CORE1_DBG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE1_DBG_RST.
#define BF_SRC_SCR_CORE1_DBG_RST(v)   (((v) << BP_SRC_SCR_CORE1_DBG_RST) & BM_SRC_SCR_CORE1_DBG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE1_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE1_DBG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE1_DBG_RST) | BF_SRC_SCR_CORE1_DBG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE2_DBG_RST[19] (RW)
 *
 * Software reset for core2 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core2 debug reset
 * 1 - assert core2 debug reset
 */

#define BP_SRC_SCR_CORE2_DBG_RST      (19)      //!< Bit position for SRC_SCR_CORE2_DBG_RST.
#define BM_SRC_SCR_CORE2_DBG_RST      (0x00080000)  //!< Bit mask for SRC_SCR_CORE2_DBG_RST.

//! @brief Get value of SRC_SCR_CORE2_DBG_RST from a register value.
#define BG_SRC_SCR_CORE2_DBG_RST(r)   (((r) & BM_SRC_SCR_CORE2_DBG_RST) >> BP_SRC_SCR_CORE2_DBG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE2_DBG_RST.
#define BF_SRC_SCR_CORE2_DBG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE2_DBG_RST) & BM_SRC_SCR_CORE2_DBG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE2_DBG_RST.
#define BF_SRC_SCR_CORE2_DBG_RST(v)   (((v) << BP_SRC_SCR_CORE2_DBG_RST) & BM_SRC_SCR_CORE2_DBG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE2_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE2_DBG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE2_DBG_RST) | BF_SRC_SCR_CORE2_DBG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE3_DBG_RST[20] (RW)
 *
 * Software reset for core3 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core3 debug reset
 * 1 - assert core3 debug reset
 */

#define BP_SRC_SCR_CORE3_DBG_RST      (20)      //!< Bit position for SRC_SCR_CORE3_DBG_RST.
#define BM_SRC_SCR_CORE3_DBG_RST      (0x00100000)  //!< Bit mask for SRC_SCR_CORE3_DBG_RST.

//! @brief Get value of SRC_SCR_CORE3_DBG_RST from a register value.
#define BG_SRC_SCR_CORE3_DBG_RST(r)   (((r) & BM_SRC_SCR_CORE3_DBG_RST) >> BP_SRC_SCR_CORE3_DBG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE3_DBG_RST.
#define BF_SRC_SCR_CORE3_DBG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE3_DBG_RST) & BM_SRC_SCR_CORE3_DBG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORE3_DBG_RST.
#define BF_SRC_SCR_CORE3_DBG_RST(v)   (((v) << BP_SRC_SCR_CORE3_DBG_RST) & BM_SRC_SCR_CORE3_DBG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE3_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE3_DBG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE3_DBG_RST) | BF_SRC_SCR_CORE3_DBG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORES_DBG_RST[21] (RW)
 *
 * Software reset for debug of arm platform only. this is a self clearing bit. Once it is set to 1,
 * the reset process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert arm platform debug reset
 * 1 - assert arm platform debug reset
 */

#define BP_SRC_SCR_CORES_DBG_RST      (21)      //!< Bit position for SRC_SCR_CORES_DBG_RST.
#define BM_SRC_SCR_CORES_DBG_RST      (0x00200000)  //!< Bit mask for SRC_SCR_CORES_DBG_RST.

//! @brief Get value of SRC_SCR_CORES_DBG_RST from a register value.
#define BG_SRC_SCR_CORES_DBG_RST(r)   (((r) & BM_SRC_SCR_CORES_DBG_RST) >> BP_SRC_SCR_CORES_DBG_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORES_DBG_RST.
#define BF_SRC_SCR_CORES_DBG_RST(v)   ((((reg32_t) v) << BP_SRC_SCR_CORES_DBG_RST) & BM_SRC_SCR_CORES_DBG_RST)
#else
//! @brief Format value for bitfield SRC_SCR_CORES_DBG_RST.
#define BF_SRC_SCR_CORES_DBG_RST(v)   (((v) << BP_SRC_SCR_CORES_DBG_RST) & BM_SRC_SCR_CORES_DBG_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORES_DBG_RST field to a new value.
#define BW_SRC_SCR_CORES_DBG_RST(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORES_DBG_RST) | BF_SRC_SCR_CORES_DBG_RST(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE1_ENABLE[22] (RW)
 *
 * CPU core1 enable. core0 cannot be disabled
 *
 * Values:
 * 0 - core1 is disabled
 * 1 - core1 is enabled
 */

#define BP_SRC_SCR_CORE1_ENABLE      (22)      //!< Bit position for SRC_SCR_CORE1_ENABLE.
#define BM_SRC_SCR_CORE1_ENABLE      (0x00400000)  //!< Bit mask for SRC_SCR_CORE1_ENABLE.

//! @brief Get value of SRC_SCR_CORE1_ENABLE from a register value.
#define BG_SRC_SCR_CORE1_ENABLE(r)   (((r) & BM_SRC_SCR_CORE1_ENABLE) >> BP_SRC_SCR_CORE1_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE1_ENABLE.
#define BF_SRC_SCR_CORE1_ENABLE(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE1_ENABLE) & BM_SRC_SCR_CORE1_ENABLE)
#else
//! @brief Format value for bitfield SRC_SCR_CORE1_ENABLE.
#define BF_SRC_SCR_CORE1_ENABLE(v)   (((v) << BP_SRC_SCR_CORE1_ENABLE) & BM_SRC_SCR_CORE1_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE1_ENABLE field to a new value.
#define BW_SRC_SCR_CORE1_ENABLE(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE1_ENABLE) | BF_SRC_SCR_CORE1_ENABLE(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE2_ENABLE[23] (RW)
 *
 * CPU core2 enable. core0 cannot be disabled
 *
 * Values:
 * 0 - core2 is disabled
 * 1 - core2 is enabled
 */

#define BP_SRC_SCR_CORE2_ENABLE      (23)      //!< Bit position for SRC_SCR_CORE2_ENABLE.
#define BM_SRC_SCR_CORE2_ENABLE      (0x00800000)  //!< Bit mask for SRC_SCR_CORE2_ENABLE.

//! @brief Get value of SRC_SCR_CORE2_ENABLE from a register value.
#define BG_SRC_SCR_CORE2_ENABLE(r)   (((r) & BM_SRC_SCR_CORE2_ENABLE) >> BP_SRC_SCR_CORE2_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE2_ENABLE.
#define BF_SRC_SCR_CORE2_ENABLE(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE2_ENABLE) & BM_SRC_SCR_CORE2_ENABLE)
#else
//! @brief Format value for bitfield SRC_SCR_CORE2_ENABLE.
#define BF_SRC_SCR_CORE2_ENABLE(v)   (((v) << BP_SRC_SCR_CORE2_ENABLE) & BM_SRC_SCR_CORE2_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE2_ENABLE field to a new value.
#define BW_SRC_SCR_CORE2_ENABLE(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE2_ENABLE) | BF_SRC_SCR_CORE2_ENABLE(v)))
#endif


/* --- Register HW_SRC_SCR, field CORE3_ENABLE[24] (RW)
 *
 * CPU core3 enable. core0 cannot be disabled
 *
 * Values:
 * 0 - core3 is disabled
 * 1 - core3 is enabled
 */

#define BP_SRC_SCR_CORE3_ENABLE      (24)      //!< Bit position for SRC_SCR_CORE3_ENABLE.
#define BM_SRC_SCR_CORE3_ENABLE      (0x01000000)  //!< Bit mask for SRC_SCR_CORE3_ENABLE.

//! @brief Get value of SRC_SCR_CORE3_ENABLE from a register value.
#define BG_SRC_SCR_CORE3_ENABLE(r)   (((r) & BM_SRC_SCR_CORE3_ENABLE) >> BP_SRC_SCR_CORE3_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_CORE3_ENABLE.
#define BF_SRC_SCR_CORE3_ENABLE(v)   ((((reg32_t) v) << BP_SRC_SCR_CORE3_ENABLE) & BM_SRC_SCR_CORE3_ENABLE)
#else
//! @brief Format value for bitfield SRC_SCR_CORE3_ENABLE.
#define BF_SRC_SCR_CORE3_ENABLE(v)   (((v) << BP_SRC_SCR_CORE3_ENABLE) & BM_SRC_SCR_CORE3_ENABLE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE3_ENABLE field to a new value.
#define BW_SRC_SCR_CORE3_ENABLE(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_CORE3_ENABLE) | BF_SRC_SCR_CORE3_ENABLE(v)))
#endif


/* --- Register HW_SRC_SCR, field DBG_RST_MSK_PG[25] (RW)
 *
 * Do not assert debug resets after power gating event of cpu
 *
 * Values:
 * 0 - don't mask cpu debug resets (debug resets will be asserted after power gating event)
 * 1 - maks cpu debug resets (debug resets won't be asserted after power gating event)
 */

#define BP_SRC_SCR_DBG_RST_MSK_PG      (25)      //!< Bit position for SRC_SCR_DBG_RST_MSK_PG.
#define BM_SRC_SCR_DBG_RST_MSK_PG      (0x02000000)  //!< Bit mask for SRC_SCR_DBG_RST_MSK_PG.

//! @brief Get value of SRC_SCR_DBG_RST_MSK_PG from a register value.
#define BG_SRC_SCR_DBG_RST_MSK_PG(r)   (((r) & BM_SRC_SCR_DBG_RST_MSK_PG) >> BP_SRC_SCR_DBG_RST_MSK_PG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SCR_DBG_RST_MSK_PG.
#define BF_SRC_SCR_DBG_RST_MSK_PG(v)   ((((reg32_t) v) << BP_SRC_SCR_DBG_RST_MSK_PG) & BM_SRC_SCR_DBG_RST_MSK_PG)
#else
//! @brief Format value for bitfield SRC_SCR_DBG_RST_MSK_PG.
#define BF_SRC_SCR_DBG_RST_MSK_PG(v)   (((v) << BP_SRC_SCR_DBG_RST_MSK_PG) & BM_SRC_SCR_DBG_RST_MSK_PG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DBG_RST_MSK_PG field to a new value.
#define BW_SRC_SCR_DBG_RST_MSK_PG(v)   (HW_SRC_SCR_WR((HW_SRC_SCR_RD() & ~BM_SRC_SCR_DBG_RST_MSK_PG) | BF_SRC_SCR_DBG_RST_MSK_PG(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SBMR1 - SRC Boot Mode Register 1 (RO)
 *
 * Reset value: 0x00000000
 *
 * The Boot Mode register (SBMR) contains bits that reflect the status of Boot Mode Pins of the
 * chip. The default values for those bits depends on the values of pins/fuses during reset
 * sequence, hence the question mark on their default value.
 */
typedef union _hw_src_sbmr1
{
    reg32_t U;
    struct _hw_src_sbmr1_bitfields
    {
        unsigned BOOT_CFG1 : 8; //!< [7:0] Please refer to fuse map.
        unsigned BOOT_CFG2 : 8; //!< [15:8] Please refer to fuse map.
        unsigned BOOT_CFG3 : 8; //!< [23:16] Please refer to fuse map.
        unsigned BOOT_CFG4 : 8; //!< [31:24] Please refer to fuse map.
    } B;
} hw_src_sbmr1_t;
#endif

/*
 * constants & macros for entire SRC_SBMR1 register
 */
#define HW_SRC_SBMR1_ADDR      (REGS_SRC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_SBMR1           (*(volatile hw_src_sbmr1_t *) HW_SRC_SBMR1_ADDR)
#define HW_SRC_SBMR1_RD()      (HW_SRC_SBMR1.U)
#endif

/*
 * constants & macros for individual SRC_SBMR1 bitfields
 */

/* --- Register HW_SRC_SBMR1, field BOOT_CFG1[7:0] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG1      (0)      //!< Bit position for SRC_SBMR1_BOOT_CFG1.
#define BM_SRC_SBMR1_BOOT_CFG1      (0x000000ff)  //!< Bit mask for SRC_SBMR1_BOOT_CFG1.

//! @brief Get value of SRC_SBMR1_BOOT_CFG1 from a register value.
#define BG_SRC_SBMR1_BOOT_CFG1(r)   (((r) & BM_SRC_SBMR1_BOOT_CFG1) >> BP_SRC_SBMR1_BOOT_CFG1)

/* --- Register HW_SRC_SBMR1, field BOOT_CFG2[15:8] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG2      (8)      //!< Bit position for SRC_SBMR1_BOOT_CFG2.
#define BM_SRC_SBMR1_BOOT_CFG2      (0x0000ff00)  //!< Bit mask for SRC_SBMR1_BOOT_CFG2.

//! @brief Get value of SRC_SBMR1_BOOT_CFG2 from a register value.
#define BG_SRC_SBMR1_BOOT_CFG2(r)   (((r) & BM_SRC_SBMR1_BOOT_CFG2) >> BP_SRC_SBMR1_BOOT_CFG2)

/* --- Register HW_SRC_SBMR1, field BOOT_CFG3[23:16] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG3      (16)      //!< Bit position for SRC_SBMR1_BOOT_CFG3.
#define BM_SRC_SBMR1_BOOT_CFG3      (0x00ff0000)  //!< Bit mask for SRC_SBMR1_BOOT_CFG3.

//! @brief Get value of SRC_SBMR1_BOOT_CFG3 from a register value.
#define BG_SRC_SBMR1_BOOT_CFG3(r)   (((r) & BM_SRC_SBMR1_BOOT_CFG3) >> BP_SRC_SBMR1_BOOT_CFG3)

/* --- Register HW_SRC_SBMR1, field BOOT_CFG4[31:24] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG4      (24)      //!< Bit position for SRC_SBMR1_BOOT_CFG4.
#define BM_SRC_SBMR1_BOOT_CFG4      (0xff000000)  //!< Bit mask for SRC_SBMR1_BOOT_CFG4.

//! @brief Get value of SRC_SBMR1_BOOT_CFG4 from a register value.
#define BG_SRC_SBMR1_BOOT_CFG4(r)   (((r) & BM_SRC_SBMR1_BOOT_CFG4) >> BP_SRC_SBMR1_BOOT_CFG4)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SRSR - SRC Reset Status Register (RW)
 *
 * Reset value: 0x00000001
 *
 * The SRSR is a write to one clear register which records the source of the reset events for the
 * chip. The SRC reset status register will capture all the reset sources that have occurred. This
 * register is reset on ipp_reset_b. This is a read-write register,  For bit[6-0] - writing zero
 * does not have any effect. Writing one will clear the corresponding bit. The individual bits can
 * be cleared by writing one to that bit. When the system comes out of reset, this register will
 * have bits set corresponding to all the reset sources that occurred during system reset. Software
 * has to take care to clear this register by writing one after every reset that occurs so that the
 * register will contain the information of recently occurred reset.
 */
typedef union _hw_src_srsr
{
    reg32_t U;
    struct _hw_src_srsr_bitfields
    {
        unsigned IPP_RESET_B : 1; //!< [0] Indicates whether reset was the result of ipp_reset_b pin (Power-up sequence)
        unsigned RESERVED0 : 1; //!< [1] Reserved.
        unsigned CSU_RESET_B : 1; //!< [2] Indicates whether the reset was the result of the csu_reset_b input. If case the csu_reset_b occured during a warm reset process, during the phase that ipg_clk is not available yet, then the occurance of csu reset will not be reflected in this bit.
        unsigned IPP_USER_RESET_B : 1; //!< [3] Indicates whether the reset was the result of the ipp_user_reset_b qulified reset.
        unsigned WDOG_RST_B : 1; //!< [4] IC Watchdog Time-out reset. Indicates whether the reset was the result of the watchdog time-out event.
        unsigned JTAG_RST_B : 1; //!< [5] HIGH - Z JTAG reset. Indicates whether the reset was the result of HIGH-Z reset reset from JTAG. Connections at chip-level: jtag_rst_b -> sjc_ieee_reset_b
        unsigned JTAG_SW_RST : 1; //!< [6] JTAG SW reset. Indicates whether the reset was the result of software reset from JTAG. Connections at chip-level: jtag_sw_rst -> sjc_gpccr_reg_2_b
        unsigned RESERVED1 : 9; //!< [15:7] Reserved
        unsigned WARM_BOOT : 1; //!< [16] Warm boot indication gives software capability to notify that warm boot was initiated by software. This indicates to the software that it saved the needed info in the memory before initiating the warm reset. In this case , software will set this bit to '1', before initiating the warm reset. The warm_boot bit should be used as indication only after a warm_reset sequence. Software should clear this bit after warm_reset to indicate that next warm_reset is not done with warm_boot. Please refer to for details on warm_reset.
        unsigned RESERVED2 : 15; //!< [31:17] Reserved
    } B;
} hw_src_srsr_t;
#endif

/*
 * constants & macros for entire SRC_SRSR register
 */
#define HW_SRC_SRSR_ADDR      (REGS_SRC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_SRSR           (*(volatile hw_src_srsr_t *) HW_SRC_SRSR_ADDR)
#define HW_SRC_SRSR_RD()      (HW_SRC_SRSR.U)
#define HW_SRC_SRSR_WR(v)     (HW_SRC_SRSR.U = (v))
#define HW_SRC_SRSR_SET(v)    (HW_SRC_SRSR_WR(HW_SRC_SRSR_RD() |  (v)))
#define HW_SRC_SRSR_CLR(v)    (HW_SRC_SRSR_WR(HW_SRC_SRSR_RD() & ~(v)))
#define HW_SRC_SRSR_TOG(v)    (HW_SRC_SRSR_WR(HW_SRC_SRSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_SRSR bitfields
 */

/* --- Register HW_SRC_SRSR, field IPP_RESET_B[0] (W1C)
 *
 * Indicates whether reset was the result of ipp_reset_b pin (Power-up sequence)
 *
 * Values:
 * 0 - Reset is not a result of ipp_reset_b pin.
 * 1 - Reset is a result of ipp_reset_b pin.
 */

#define BP_SRC_SRSR_IPP_RESET_B      (0)      //!< Bit position for SRC_SRSR_IPP_RESET_B.
#define BM_SRC_SRSR_IPP_RESET_B      (0x00000001)  //!< Bit mask for SRC_SRSR_IPP_RESET_B.

//! @brief Get value of SRC_SRSR_IPP_RESET_B from a register value.
#define BG_SRC_SRSR_IPP_RESET_B(r)   (((r) & BM_SRC_SRSR_IPP_RESET_B) >> BP_SRC_SRSR_IPP_RESET_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_IPP_RESET_B.
#define BF_SRC_SRSR_IPP_RESET_B(v)   ((((reg32_t) v) << BP_SRC_SRSR_IPP_RESET_B) & BM_SRC_SRSR_IPP_RESET_B)
#else
//! @brief Format value for bitfield SRC_SRSR_IPP_RESET_B.
#define BF_SRC_SRSR_IPP_RESET_B(v)   (((v) << BP_SRC_SRSR_IPP_RESET_B) & BM_SRC_SRSR_IPP_RESET_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPP_RESET_B field to a new value.
#define BW_SRC_SRSR_IPP_RESET_B(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_IPP_RESET_B) | BF_SRC_SRSR_IPP_RESET_B(v)))
#endif


/* --- Register HW_SRC_SRSR, field CSU_RESET_B[2] (W1C)
 *
 * Indicates whether the reset was the result of the csu_reset_b input. If case the csu_reset_b
 * occured during a warm reset process, during the phase that ipg_clk is not available yet, then the
 * occurance of csu reset will not be reflected in this bit.
 *
 * Values:
 * 0 - Reset is not a result of the csu_reset_b event.
 * 1 - Reset is a result of the csu_reset_b event.
 */

#define BP_SRC_SRSR_CSU_RESET_B      (2)      //!< Bit position for SRC_SRSR_CSU_RESET_B.
#define BM_SRC_SRSR_CSU_RESET_B      (0x00000004)  //!< Bit mask for SRC_SRSR_CSU_RESET_B.

//! @brief Get value of SRC_SRSR_CSU_RESET_B from a register value.
#define BG_SRC_SRSR_CSU_RESET_B(r)   (((r) & BM_SRC_SRSR_CSU_RESET_B) >> BP_SRC_SRSR_CSU_RESET_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_CSU_RESET_B.
#define BF_SRC_SRSR_CSU_RESET_B(v)   ((((reg32_t) v) << BP_SRC_SRSR_CSU_RESET_B) & BM_SRC_SRSR_CSU_RESET_B)
#else
//! @brief Format value for bitfield SRC_SRSR_CSU_RESET_B.
#define BF_SRC_SRSR_CSU_RESET_B(v)   (((v) << BP_SRC_SRSR_CSU_RESET_B) & BM_SRC_SRSR_CSU_RESET_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CSU_RESET_B field to a new value.
#define BW_SRC_SRSR_CSU_RESET_B(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_CSU_RESET_B) | BF_SRC_SRSR_CSU_RESET_B(v)))
#endif


/* --- Register HW_SRC_SRSR, field IPP_USER_RESET_B[3] (W1C)
 *
 * Indicates whether the reset was the result of the ipp_user_reset_b qulified reset.
 *
 * Values:
 * 0 - Reset is not a result of the ipp_user_reset_b qulified as COLD event.
 * 1 - Reset is a result of the ipp_user_reset_b qulified as COLD event.
 */

#define BP_SRC_SRSR_IPP_USER_RESET_B      (3)      //!< Bit position for SRC_SRSR_IPP_USER_RESET_B.
#define BM_SRC_SRSR_IPP_USER_RESET_B      (0x00000008)  //!< Bit mask for SRC_SRSR_IPP_USER_RESET_B.

//! @brief Get value of SRC_SRSR_IPP_USER_RESET_B from a register value.
#define BG_SRC_SRSR_IPP_USER_RESET_B(r)   (((r) & BM_SRC_SRSR_IPP_USER_RESET_B) >> BP_SRC_SRSR_IPP_USER_RESET_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_IPP_USER_RESET_B.
#define BF_SRC_SRSR_IPP_USER_RESET_B(v)   ((((reg32_t) v) << BP_SRC_SRSR_IPP_USER_RESET_B) & BM_SRC_SRSR_IPP_USER_RESET_B)
#else
//! @brief Format value for bitfield SRC_SRSR_IPP_USER_RESET_B.
#define BF_SRC_SRSR_IPP_USER_RESET_B(v)   (((v) << BP_SRC_SRSR_IPP_USER_RESET_B) & BM_SRC_SRSR_IPP_USER_RESET_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPP_USER_RESET_B field to a new value.
#define BW_SRC_SRSR_IPP_USER_RESET_B(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_IPP_USER_RESET_B) | BF_SRC_SRSR_IPP_USER_RESET_B(v)))
#endif


/* --- Register HW_SRC_SRSR, field WDOG_RST_B[4] (W1C)
 *
 * IC Watchdog Time-out reset. Indicates whether the reset was the result of the watchdog time-out
 * event.
 *
 * Values:
 * 0 - Reset is not a result of the watchdog time-out event.
 * 1 - Reset is a result of the watchdog time-out event.
 */

#define BP_SRC_SRSR_WDOG_RST_B      (4)      //!< Bit position for SRC_SRSR_WDOG_RST_B.
#define BM_SRC_SRSR_WDOG_RST_B      (0x00000010)  //!< Bit mask for SRC_SRSR_WDOG_RST_B.

//! @brief Get value of SRC_SRSR_WDOG_RST_B from a register value.
#define BG_SRC_SRSR_WDOG_RST_B(r)   (((r) & BM_SRC_SRSR_WDOG_RST_B) >> BP_SRC_SRSR_WDOG_RST_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_WDOG_RST_B.
#define BF_SRC_SRSR_WDOG_RST_B(v)   ((((reg32_t) v) << BP_SRC_SRSR_WDOG_RST_B) & BM_SRC_SRSR_WDOG_RST_B)
#else
//! @brief Format value for bitfield SRC_SRSR_WDOG_RST_B.
#define BF_SRC_SRSR_WDOG_RST_B(v)   (((v) << BP_SRC_SRSR_WDOG_RST_B) & BM_SRC_SRSR_WDOG_RST_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDOG_RST_B field to a new value.
#define BW_SRC_SRSR_WDOG_RST_B(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_WDOG_RST_B) | BF_SRC_SRSR_WDOG_RST_B(v)))
#endif


/* --- Register HW_SRC_SRSR, field JTAG_RST_B[5] (W1C)
 *
 * HIGH - Z JTAG reset. Indicates whether the reset was the result of HIGH-Z reset reset from JTAG.
 * Connections at chip-level: jtag_rst_b -> sjc_ieee_reset_b
 *
 * Values:
 * 0 - Reset is not a result of HIGH-Z reset from JTAG.
 * 1 - Reset is a result of HIGH-Z reset from JTAG.
 */

#define BP_SRC_SRSR_JTAG_RST_B      (5)      //!< Bit position for SRC_SRSR_JTAG_RST_B.
#define BM_SRC_SRSR_JTAG_RST_B      (0x00000020)  //!< Bit mask for SRC_SRSR_JTAG_RST_B.

//! @brief Get value of SRC_SRSR_JTAG_RST_B from a register value.
#define BG_SRC_SRSR_JTAG_RST_B(r)   (((r) & BM_SRC_SRSR_JTAG_RST_B) >> BP_SRC_SRSR_JTAG_RST_B)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_JTAG_RST_B.
#define BF_SRC_SRSR_JTAG_RST_B(v)   ((((reg32_t) v) << BP_SRC_SRSR_JTAG_RST_B) & BM_SRC_SRSR_JTAG_RST_B)
#else
//! @brief Format value for bitfield SRC_SRSR_JTAG_RST_B.
#define BF_SRC_SRSR_JTAG_RST_B(v)   (((v) << BP_SRC_SRSR_JTAG_RST_B) & BM_SRC_SRSR_JTAG_RST_B)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the JTAG_RST_B field to a new value.
#define BW_SRC_SRSR_JTAG_RST_B(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_JTAG_RST_B) | BF_SRC_SRSR_JTAG_RST_B(v)))
#endif


/* --- Register HW_SRC_SRSR, field JTAG_SW_RST[6] (W1C)
 *
 * JTAG SW reset. Indicates whether the reset was the result of software reset from JTAG.
 * Connections at chip-level: jtag_sw_rst -> sjc_gpccr_reg_2_b
 *
 * Values:
 * 0 - Reset is not a result of software reset from JTAG.
 * 1 - Reset is a result of software reset from JTAG.
 */

#define BP_SRC_SRSR_JTAG_SW_RST      (6)      //!< Bit position for SRC_SRSR_JTAG_SW_RST.
#define BM_SRC_SRSR_JTAG_SW_RST      (0x00000040)  //!< Bit mask for SRC_SRSR_JTAG_SW_RST.

//! @brief Get value of SRC_SRSR_JTAG_SW_RST from a register value.
#define BG_SRC_SRSR_JTAG_SW_RST(r)   (((r) & BM_SRC_SRSR_JTAG_SW_RST) >> BP_SRC_SRSR_JTAG_SW_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_JTAG_SW_RST.
#define BF_SRC_SRSR_JTAG_SW_RST(v)   ((((reg32_t) v) << BP_SRC_SRSR_JTAG_SW_RST) & BM_SRC_SRSR_JTAG_SW_RST)
#else
//! @brief Format value for bitfield SRC_SRSR_JTAG_SW_RST.
#define BF_SRC_SRSR_JTAG_SW_RST(v)   (((v) << BP_SRC_SRSR_JTAG_SW_RST) & BM_SRC_SRSR_JTAG_SW_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the JTAG_SW_RST field to a new value.
#define BW_SRC_SRSR_JTAG_SW_RST(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_JTAG_SW_RST) | BF_SRC_SRSR_JTAG_SW_RST(v)))
#endif


/* --- Register HW_SRC_SRSR, field WARM_BOOT[16] (RW)
 *
 * Warm boot indication gives software capability to notify that warm boot was initiated by
 * software. This indicates to the software that it saved the needed info in the memory before
 * initiating the warm reset. In this case , software will set this bit to '1', before initiating
 * the warm reset. The warm_boot bit should be used as indication only after a warm_reset sequence.
 * Software should clear this bit after warm_reset to indicate that next warm_reset is not done with
 * warm_boot. Please refer to for details on warm_reset.
 *
 * Values:
 * 0 - warm boot process not initiated by software.
 * 1 - warm boot initiated by software.
 */

#define BP_SRC_SRSR_WARM_BOOT      (16)      //!< Bit position for SRC_SRSR_WARM_BOOT.
#define BM_SRC_SRSR_WARM_BOOT      (0x00010000)  //!< Bit mask for SRC_SRSR_WARM_BOOT.

//! @brief Get value of SRC_SRSR_WARM_BOOT from a register value.
#define BG_SRC_SRSR_WARM_BOOT(r)   (((r) & BM_SRC_SRSR_WARM_BOOT) >> BP_SRC_SRSR_WARM_BOOT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SRSR_WARM_BOOT.
#define BF_SRC_SRSR_WARM_BOOT(v)   ((((reg32_t) v) << BP_SRC_SRSR_WARM_BOOT) & BM_SRC_SRSR_WARM_BOOT)
#else
//! @brief Format value for bitfield SRC_SRSR_WARM_BOOT.
#define BF_SRC_SRSR_WARM_BOOT(v)   (((v) << BP_SRC_SRSR_WARM_BOOT) & BM_SRC_SRSR_WARM_BOOT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WARM_BOOT field to a new value.
#define BW_SRC_SRSR_WARM_BOOT(v)   (HW_SRC_SRSR_WR((HW_SRC_SRSR_RD() & ~BM_SRC_SRSR_WARM_BOOT) | BF_SRC_SRSR_WARM_BOOT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SISR - SRC Interrupt Status Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_src_sisr
{
    reg32_t U;
    struct _hw_src_sisr_bitfields
    {
        unsigned GPU_PASSED_RESET : 1; //!< [0] Interrupt generated to indicate that gpu passed software reset and is ready to be used
        unsigned VPU_PASSED_RESET : 1; //!< [1] Interrupt generated to indicate that vpu passed software reset and is ready to be used
        unsigned IPU1_PASSED_RESET : 1; //!< [2] Interrupt generated to indicate that ipu passed software reset and is ready to be used
        unsigned OPEN_VG_PASSED_RESET : 1; //!< [3] Interrupt generated to indicate that open_vg passed software reset and is ready to be used
        unsigned IPU2_PASSED_RESET : 1; //!< [4] Interrupt generated to indicate that ipu2 passed software reset and is ready to be used
        unsigned CORE0_WDOG_RST_REQ : 1; //!< [5] Wdog reset request from CPU core0. Read-only status bit.
        unsigned CORE1_WDOG_RST_REQ : 1; //!< [6] Wdog reset request from CPU core1. Read-only status bit.
        unsigned CORE2_WDOG_RST_REQ : 1; //!< [7] Wdog reset request from CPU core2. Read-only status bit.
        unsigned CORE3_WDOG_RST_REQ : 1; //!< [8] Wdog reset request from CPU core3. Read-only status bit.
        unsigned RESERVED0 : 23; //!< [31:9] Reserved
    } B;
} hw_src_sisr_t;
#endif

/*
 * constants & macros for entire SRC_SISR register
 */
#define HW_SRC_SISR_ADDR      (REGS_SRC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_SISR           (*(volatile hw_src_sisr_t *) HW_SRC_SISR_ADDR)
#define HW_SRC_SISR_RD()      (HW_SRC_SISR.U)
#endif

/*
 * constants & macros for individual SRC_SISR bitfields
 */

/* --- Register HW_SRC_SISR, field GPU_PASSED_RESET[0] (RO)
 *
 * Interrupt generated to indicate that gpu passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to gpu passed reset
 * 1 - interrupt genrerated due to gpu passed reset
 */

#define BP_SRC_SISR_GPU_PASSED_RESET      (0)      //!< Bit position for SRC_SISR_GPU_PASSED_RESET.
#define BM_SRC_SISR_GPU_PASSED_RESET      (0x00000001)  //!< Bit mask for SRC_SISR_GPU_PASSED_RESET.

//! @brief Get value of SRC_SISR_GPU_PASSED_RESET from a register value.
#define BG_SRC_SISR_GPU_PASSED_RESET(r)   (((r) & BM_SRC_SISR_GPU_PASSED_RESET) >> BP_SRC_SISR_GPU_PASSED_RESET)


/* --- Register HW_SRC_SISR, field VPU_PASSED_RESET[1] (RO)
 *
 * Interrupt generated to indicate that vpu passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to vpu passed reset
 * 1 - interrupt genrerated due to vpu passed reset
 */

#define BP_SRC_SISR_VPU_PASSED_RESET      (1)      //!< Bit position for SRC_SISR_VPU_PASSED_RESET.
#define BM_SRC_SISR_VPU_PASSED_RESET      (0x00000002)  //!< Bit mask for SRC_SISR_VPU_PASSED_RESET.

//! @brief Get value of SRC_SISR_VPU_PASSED_RESET from a register value.
#define BG_SRC_SISR_VPU_PASSED_RESET(r)   (((r) & BM_SRC_SISR_VPU_PASSED_RESET) >> BP_SRC_SISR_VPU_PASSED_RESET)


/* --- Register HW_SRC_SISR, field IPU1_PASSED_RESET[2] (RO)
 *
 * Interrupt generated to indicate that ipu passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to ipu passed reset
 * 1 - interrupt genrerated due to ipu passed reset
 */

#define BP_SRC_SISR_IPU1_PASSED_RESET      (2)      //!< Bit position for SRC_SISR_IPU1_PASSED_RESET.
#define BM_SRC_SISR_IPU1_PASSED_RESET      (0x00000004)  //!< Bit mask for SRC_SISR_IPU1_PASSED_RESET.

//! @brief Get value of SRC_SISR_IPU1_PASSED_RESET from a register value.
#define BG_SRC_SISR_IPU1_PASSED_RESET(r)   (((r) & BM_SRC_SISR_IPU1_PASSED_RESET) >> BP_SRC_SISR_IPU1_PASSED_RESET)


/* --- Register HW_SRC_SISR, field OPEN_VG_PASSED_RESET[3] (RO)
 *
 * Interrupt generated to indicate that open_vg passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to open_vg passed reset
 * 1 - interrupt genrerated due to open_vg passed reset
 */

#define BP_SRC_SISR_OPEN_VG_PASSED_RESET      (3)      //!< Bit position for SRC_SISR_OPEN_VG_PASSED_RESET.
#define BM_SRC_SISR_OPEN_VG_PASSED_RESET      (0x00000008)  //!< Bit mask for SRC_SISR_OPEN_VG_PASSED_RESET.

//! @brief Get value of SRC_SISR_OPEN_VG_PASSED_RESET from a register value.
#define BG_SRC_SISR_OPEN_VG_PASSED_RESET(r)   (((r) & BM_SRC_SISR_OPEN_VG_PASSED_RESET) >> BP_SRC_SISR_OPEN_VG_PASSED_RESET)


/* --- Register HW_SRC_SISR, field IPU2_PASSED_RESET[4] (RO)
 *
 * Interrupt generated to indicate that ipu2 passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to ipu2 passed reset
 * 1 - interrupt genrerated due to ipu2 passed reset
 */

#define BP_SRC_SISR_IPU2_PASSED_RESET      (4)      //!< Bit position for SRC_SISR_IPU2_PASSED_RESET.
#define BM_SRC_SISR_IPU2_PASSED_RESET      (0x00000010)  //!< Bit mask for SRC_SISR_IPU2_PASSED_RESET.

//! @brief Get value of SRC_SISR_IPU2_PASSED_RESET from a register value.
#define BG_SRC_SISR_IPU2_PASSED_RESET(r)   (((r) & BM_SRC_SISR_IPU2_PASSED_RESET) >> BP_SRC_SISR_IPU2_PASSED_RESET)


/* --- Register HW_SRC_SISR, field CORE0_WDOG_RST_REQ[5] (RO)
 *
 * Wdog reset request from CPU core0. Read-only status bit.
 */

#define BP_SRC_SISR_CORE0_WDOG_RST_REQ      (5)      //!< Bit position for SRC_SISR_CORE0_WDOG_RST_REQ.
#define BM_SRC_SISR_CORE0_WDOG_RST_REQ      (0x00000020)  //!< Bit mask for SRC_SISR_CORE0_WDOG_RST_REQ.

//! @brief Get value of SRC_SISR_CORE0_WDOG_RST_REQ from a register value.
#define BG_SRC_SISR_CORE0_WDOG_RST_REQ(r)   (((r) & BM_SRC_SISR_CORE0_WDOG_RST_REQ) >> BP_SRC_SISR_CORE0_WDOG_RST_REQ)

/* --- Register HW_SRC_SISR, field CORE1_WDOG_RST_REQ[6] (RO)
 *
 * Wdog reset request from CPU core1. Read-only status bit.
 */

#define BP_SRC_SISR_CORE1_WDOG_RST_REQ      (6)      //!< Bit position for SRC_SISR_CORE1_WDOG_RST_REQ.
#define BM_SRC_SISR_CORE1_WDOG_RST_REQ      (0x00000040)  //!< Bit mask for SRC_SISR_CORE1_WDOG_RST_REQ.

//! @brief Get value of SRC_SISR_CORE1_WDOG_RST_REQ from a register value.
#define BG_SRC_SISR_CORE1_WDOG_RST_REQ(r)   (((r) & BM_SRC_SISR_CORE1_WDOG_RST_REQ) >> BP_SRC_SISR_CORE1_WDOG_RST_REQ)

/* --- Register HW_SRC_SISR, field CORE2_WDOG_RST_REQ[7] (RO)
 *
 * Wdog reset request from CPU core2. Read-only status bit.
 */

#define BP_SRC_SISR_CORE2_WDOG_RST_REQ      (7)      //!< Bit position for SRC_SISR_CORE2_WDOG_RST_REQ.
#define BM_SRC_SISR_CORE2_WDOG_RST_REQ      (0x00000080)  //!< Bit mask for SRC_SISR_CORE2_WDOG_RST_REQ.

//! @brief Get value of SRC_SISR_CORE2_WDOG_RST_REQ from a register value.
#define BG_SRC_SISR_CORE2_WDOG_RST_REQ(r)   (((r) & BM_SRC_SISR_CORE2_WDOG_RST_REQ) >> BP_SRC_SISR_CORE2_WDOG_RST_REQ)

/* --- Register HW_SRC_SISR, field CORE3_WDOG_RST_REQ[8] (RO)
 *
 * Wdog reset request from CPU core3. Read-only status bit.
 */

#define BP_SRC_SISR_CORE3_WDOG_RST_REQ      (8)      //!< Bit position for SRC_SISR_CORE3_WDOG_RST_REQ.
#define BM_SRC_SISR_CORE3_WDOG_RST_REQ      (0x00000100)  //!< Bit mask for SRC_SISR_CORE3_WDOG_RST_REQ.

//! @brief Get value of SRC_SISR_CORE3_WDOG_RST_REQ from a register value.
#define BG_SRC_SISR_CORE3_WDOG_RST_REQ(r)   (((r) & BM_SRC_SISR_CORE3_WDOG_RST_REQ) >> BP_SRC_SISR_CORE3_WDOG_RST_REQ)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SIMR - SRC Interrupt Mask Register (RW)
 *
 * Reset value: 0x0000001f
 *

 */
typedef union _hw_src_simr
{
    reg32_t U;
    struct _hw_src_simr_bitfields
    {
        unsigned MASK_GPU_PASSED_RESET : 1; //!< [0] mask interrupt generation due to gpu passed reset
        unsigned MASK_VPU_PASSED_RESET : 1; //!< [1] mask interrupt generation due to vpu passed reset
        unsigned MASK_IPU_PASSED_RESET : 1; //!< [2] mask interrupt generation due to ipu passed reset
        unsigned MASK_OPEN_VG_PASSED_RESET : 1; //!< [3] mask interrupt generation due to open_vg passed reset
        unsigned MASK_IPU2_PASSED_RESET : 1; //!< [4] mask interrupt generation due to ipu2 passed reset
        unsigned RESERVED0 : 27; //!< [31:5] Reserved
    } B;
} hw_src_simr_t;
#endif

/*
 * constants & macros for entire SRC_SIMR register
 */
#define HW_SRC_SIMR_ADDR      (REGS_SRC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_SIMR           (*(volatile hw_src_simr_t *) HW_SRC_SIMR_ADDR)
#define HW_SRC_SIMR_RD()      (HW_SRC_SIMR.U)
#define HW_SRC_SIMR_WR(v)     (HW_SRC_SIMR.U = (v))
#define HW_SRC_SIMR_SET(v)    (HW_SRC_SIMR_WR(HW_SRC_SIMR_RD() |  (v)))
#define HW_SRC_SIMR_CLR(v)    (HW_SRC_SIMR_WR(HW_SRC_SIMR_RD() & ~(v)))
#define HW_SRC_SIMR_TOG(v)    (HW_SRC_SIMR_WR(HW_SRC_SIMR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_SIMR bitfields
 */

/* --- Register HW_SRC_SIMR, field MASK_GPU_PASSED_RESET[0] (RW)
 *
 * mask interrupt generation due to gpu passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to gpu passed reset - interrupt will be created
 * 1 - mask interrupt due to gpu passed reset
 */

#define BP_SRC_SIMR_MASK_GPU_PASSED_RESET      (0)      //!< Bit position for SRC_SIMR_MASK_GPU_PASSED_RESET.
#define BM_SRC_SIMR_MASK_GPU_PASSED_RESET      (0x00000001)  //!< Bit mask for SRC_SIMR_MASK_GPU_PASSED_RESET.

//! @brief Get value of SRC_SIMR_MASK_GPU_PASSED_RESET from a register value.
#define BG_SRC_SIMR_MASK_GPU_PASSED_RESET(r)   (((r) & BM_SRC_SIMR_MASK_GPU_PASSED_RESET) >> BP_SRC_SIMR_MASK_GPU_PASSED_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SIMR_MASK_GPU_PASSED_RESET.
#define BF_SRC_SIMR_MASK_GPU_PASSED_RESET(v)   ((((reg32_t) v) << BP_SRC_SIMR_MASK_GPU_PASSED_RESET) & BM_SRC_SIMR_MASK_GPU_PASSED_RESET)
#else
//! @brief Format value for bitfield SRC_SIMR_MASK_GPU_PASSED_RESET.
#define BF_SRC_SIMR_MASK_GPU_PASSED_RESET(v)   (((v) << BP_SRC_SIMR_MASK_GPU_PASSED_RESET) & BM_SRC_SIMR_MASK_GPU_PASSED_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_GPU_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_GPU_PASSED_RESET(v)   (HW_SRC_SIMR_WR((HW_SRC_SIMR_RD() & ~BM_SRC_SIMR_MASK_GPU_PASSED_RESET) | BF_SRC_SIMR_MASK_GPU_PASSED_RESET(v)))
#endif


/* --- Register HW_SRC_SIMR, field MASK_VPU_PASSED_RESET[1] (RW)
 *
 * mask interrupt generation due to vpu passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to vpu passed reset - interrupt will be created
 * 1 - mask interrupt due to vpu passed reset
 */

#define BP_SRC_SIMR_MASK_VPU_PASSED_RESET      (1)      //!< Bit position for SRC_SIMR_MASK_VPU_PASSED_RESET.
#define BM_SRC_SIMR_MASK_VPU_PASSED_RESET      (0x00000002)  //!< Bit mask for SRC_SIMR_MASK_VPU_PASSED_RESET.

//! @brief Get value of SRC_SIMR_MASK_VPU_PASSED_RESET from a register value.
#define BG_SRC_SIMR_MASK_VPU_PASSED_RESET(r)   (((r) & BM_SRC_SIMR_MASK_VPU_PASSED_RESET) >> BP_SRC_SIMR_MASK_VPU_PASSED_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SIMR_MASK_VPU_PASSED_RESET.
#define BF_SRC_SIMR_MASK_VPU_PASSED_RESET(v)   ((((reg32_t) v) << BP_SRC_SIMR_MASK_VPU_PASSED_RESET) & BM_SRC_SIMR_MASK_VPU_PASSED_RESET)
#else
//! @brief Format value for bitfield SRC_SIMR_MASK_VPU_PASSED_RESET.
#define BF_SRC_SIMR_MASK_VPU_PASSED_RESET(v)   (((v) << BP_SRC_SIMR_MASK_VPU_PASSED_RESET) & BM_SRC_SIMR_MASK_VPU_PASSED_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VPU_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_VPU_PASSED_RESET(v)   (HW_SRC_SIMR_WR((HW_SRC_SIMR_RD() & ~BM_SRC_SIMR_MASK_VPU_PASSED_RESET) | BF_SRC_SIMR_MASK_VPU_PASSED_RESET(v)))
#endif


/* --- Register HW_SRC_SIMR, field MASK_IPU_PASSED_RESET[2] (RW)
 *
 * mask interrupt generation due to ipu passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to ipu passed reset - interrupt will be created
 * 1 - mask interrupt due to ipu passed reset
 */

#define BP_SRC_SIMR_MASK_IPU_PASSED_RESET      (2)      //!< Bit position for SRC_SIMR_MASK_IPU_PASSED_RESET.
#define BM_SRC_SIMR_MASK_IPU_PASSED_RESET      (0x00000004)  //!< Bit mask for SRC_SIMR_MASK_IPU_PASSED_RESET.

//! @brief Get value of SRC_SIMR_MASK_IPU_PASSED_RESET from a register value.
#define BG_SRC_SIMR_MASK_IPU_PASSED_RESET(r)   (((r) & BM_SRC_SIMR_MASK_IPU_PASSED_RESET) >> BP_SRC_SIMR_MASK_IPU_PASSED_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SIMR_MASK_IPU_PASSED_RESET.
#define BF_SRC_SIMR_MASK_IPU_PASSED_RESET(v)   ((((reg32_t) v) << BP_SRC_SIMR_MASK_IPU_PASSED_RESET) & BM_SRC_SIMR_MASK_IPU_PASSED_RESET)
#else
//! @brief Format value for bitfield SRC_SIMR_MASK_IPU_PASSED_RESET.
#define BF_SRC_SIMR_MASK_IPU_PASSED_RESET(v)   (((v) << BP_SRC_SIMR_MASK_IPU_PASSED_RESET) & BM_SRC_SIMR_MASK_IPU_PASSED_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_IPU_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_IPU_PASSED_RESET(v)   (HW_SRC_SIMR_WR((HW_SRC_SIMR_RD() & ~BM_SRC_SIMR_MASK_IPU_PASSED_RESET) | BF_SRC_SIMR_MASK_IPU_PASSED_RESET(v)))
#endif


/* --- Register HW_SRC_SIMR, field MASK_OPEN_VG_PASSED_RESET[3] (RW)
 *
 * mask interrupt generation due to open_vg passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to open_vg passed reset - interrupt will be created
 * 1 - mask interrupt due to open_vg passed reset
 */

#define BP_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET      (3)      //!< Bit position for SRC_SIMR_MASK_OPEN_VG_PASSED_RESET.
#define BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET      (0x00000008)  //!< Bit mask for SRC_SIMR_MASK_OPEN_VG_PASSED_RESET.

//! @brief Get value of SRC_SIMR_MASK_OPEN_VG_PASSED_RESET from a register value.
#define BG_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(r)   (((r) & BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET) >> BP_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SIMR_MASK_OPEN_VG_PASSED_RESET.
#define BF_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)   ((((reg32_t) v) << BP_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET) & BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET)
#else
//! @brief Format value for bitfield SRC_SIMR_MASK_OPEN_VG_PASSED_RESET.
#define BF_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)   (((v) << BP_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET) & BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_OPEN_VG_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)   (HW_SRC_SIMR_WR((HW_SRC_SIMR_RD() & ~BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET) | BF_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)))
#endif


/* --- Register HW_SRC_SIMR, field MASK_IPU2_PASSED_RESET[4] (RW)
 *
 * mask interrupt generation due to ipu2 passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to ipu2 passed reset - interrupt will be created
 * 1 - mask interrupt due to ipu2 passed reset
 */

#define BP_SRC_SIMR_MASK_IPU2_PASSED_RESET      (4)      //!< Bit position for SRC_SIMR_MASK_IPU2_PASSED_RESET.
#define BM_SRC_SIMR_MASK_IPU2_PASSED_RESET      (0x00000010)  //!< Bit mask for SRC_SIMR_MASK_IPU2_PASSED_RESET.

//! @brief Get value of SRC_SIMR_MASK_IPU2_PASSED_RESET from a register value.
#define BG_SRC_SIMR_MASK_IPU2_PASSED_RESET(r)   (((r) & BM_SRC_SIMR_MASK_IPU2_PASSED_RESET) >> BP_SRC_SIMR_MASK_IPU2_PASSED_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SRC_SIMR_MASK_IPU2_PASSED_RESET.
#define BF_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)   ((((reg32_t) v) << BP_SRC_SIMR_MASK_IPU2_PASSED_RESET) & BM_SRC_SIMR_MASK_IPU2_PASSED_RESET)
#else
//! @brief Format value for bitfield SRC_SIMR_MASK_IPU2_PASSED_RESET.
#define BF_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)   (((v) << BP_SRC_SIMR_MASK_IPU2_PASSED_RESET) & BM_SRC_SIMR_MASK_IPU2_PASSED_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_IPU2_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)   (HW_SRC_SIMR_WR((HW_SRC_SIMR_RD() & ~BM_SRC_SIMR_MASK_IPU2_PASSED_RESET) | BF_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SBMR2 - SRC Boot Mode Register 2 (RO)
 *
 * Reset value: 0x00000000
 *
 * The Boot Mode register (SBMR), contains bits that reflect the status of Boot Mode Pins of the
 * chip. The default values for those bits depends on the values of pins/fuses during reset
 * sequence, hence the question mark on their default value.
 */
typedef union _hw_src_sbmr2
{
    reg32_t U;
    struct _hw_src_sbmr2_bitfields
    {
        unsigned SEC_CONFIG : 2; //!< [1:0] Please refer to fuse map.
        unsigned RESERVED0 : 1; //!< [2] Reserved
        unsigned DIR_BT_DIS : 1; //!< [3] Please refer to fuse map.
        unsigned BT_FUSE_SEL : 1; //!< [4] BT_FUSE_SEL (connected to gpio bt_fuse_sel)
        unsigned RESERVED1 : 19; //!< [23:5] Reserved.
        unsigned BMOD : 2; //!< [25:24] Please refer to fuse map.
        unsigned RESERVED2 : 1; //!< [26] Reserved
        unsigned TEST_MODE : 3; //!< [29:27] Please refer to fuse map.
        unsigned RESERVED3 : 2; //!< [31:30] Reserved
    } B;
} hw_src_sbmr2_t;
#endif

/*
 * constants & macros for entire SRC_SBMR2 register
 */
#define HW_SRC_SBMR2_ADDR      (REGS_SRC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_SBMR2           (*(volatile hw_src_sbmr2_t *) HW_SRC_SBMR2_ADDR)
#define HW_SRC_SBMR2_RD()      (HW_SRC_SBMR2.U)
#endif

/*
 * constants & macros for individual SRC_SBMR2 bitfields
 */

/* --- Register HW_SRC_SBMR2, field SEC_CONFIG[1:0] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_SEC_CONFIG      (0)      //!< Bit position for SRC_SBMR2_SEC_CONFIG.
#define BM_SRC_SBMR2_SEC_CONFIG      (0x00000003)  //!< Bit mask for SRC_SBMR2_SEC_CONFIG.

//! @brief Get value of SRC_SBMR2_SEC_CONFIG from a register value.
#define BG_SRC_SBMR2_SEC_CONFIG(r)   (((r) & BM_SRC_SBMR2_SEC_CONFIG) >> BP_SRC_SBMR2_SEC_CONFIG)

/* --- Register HW_SRC_SBMR2, field DIR_BT_DIS[3] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_DIR_BT_DIS      (3)      //!< Bit position for SRC_SBMR2_DIR_BT_DIS.
#define BM_SRC_SBMR2_DIR_BT_DIS      (0x00000008)  //!< Bit mask for SRC_SBMR2_DIR_BT_DIS.

//! @brief Get value of SRC_SBMR2_DIR_BT_DIS from a register value.
#define BG_SRC_SBMR2_DIR_BT_DIS(r)   (((r) & BM_SRC_SBMR2_DIR_BT_DIS) >> BP_SRC_SBMR2_DIR_BT_DIS)

/* --- Register HW_SRC_SBMR2, field BT_FUSE_SEL[4] (RO)
 *
 * BT_FUSE_SEL (connected to gpio bt_fuse_sel)
 */

#define BP_SRC_SBMR2_BT_FUSE_SEL      (4)      //!< Bit position for SRC_SBMR2_BT_FUSE_SEL.
#define BM_SRC_SBMR2_BT_FUSE_SEL      (0x00000010)  //!< Bit mask for SRC_SBMR2_BT_FUSE_SEL.

//! @brief Get value of SRC_SBMR2_BT_FUSE_SEL from a register value.
#define BG_SRC_SBMR2_BT_FUSE_SEL(r)   (((r) & BM_SRC_SBMR2_BT_FUSE_SEL) >> BP_SRC_SBMR2_BT_FUSE_SEL)

/* --- Register HW_SRC_SBMR2, field BMOD[25:24] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_BMOD      (24)      //!< Bit position for SRC_SBMR2_BMOD.
#define BM_SRC_SBMR2_BMOD      (0x03000000)  //!< Bit mask for SRC_SBMR2_BMOD.

//! @brief Get value of SRC_SBMR2_BMOD from a register value.
#define BG_SRC_SBMR2_BMOD(r)   (((r) & BM_SRC_SBMR2_BMOD) >> BP_SRC_SBMR2_BMOD)

/* --- Register HW_SRC_SBMR2, field TEST_MODE[29:27] (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_TEST_MODE      (27)      //!< Bit position for SRC_SBMR2_TEST_MODE.
#define BM_SRC_SBMR2_TEST_MODE      (0x38000000)  //!< Bit mask for SRC_SBMR2_TEST_MODE.

//! @brief Get value of SRC_SBMR2_TEST_MODE from a register value.
#define BG_SRC_SBMR2_TEST_MODE(r)   (((r) & BM_SRC_SBMR2_TEST_MODE) >> BP_SRC_SBMR2_TEST_MODE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR1 - SRC General Purpose Register 1 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 1 (GPR1), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr1
{
    reg32_t U;
    struct _hw_src_gpr1_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr1_t;
#endif

/*
 * constants & macros for entire SRC_GPR1 register
 */
#define HW_SRC_GPR1_ADDR      (REGS_SRC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR1           (*(volatile hw_src_gpr1_t *) HW_SRC_GPR1_ADDR)
#define HW_SRC_GPR1_RD()      (HW_SRC_GPR1.U)
#define HW_SRC_GPR1_WR(v)     (HW_SRC_GPR1.U = (v))
#define HW_SRC_GPR1_SET(v)    (HW_SRC_GPR1_WR(HW_SRC_GPR1_RD() |  (v)))
#define HW_SRC_GPR1_CLR(v)    (HW_SRC_GPR1_WR(HW_SRC_GPR1_RD() & ~(v)))
#define HW_SRC_GPR1_TOG(v)    (HW_SRC_GPR1_WR(HW_SRC_GPR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR1 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR2 - SRC General Purpose Register 2 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 2(GPR2), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr2
{
    reg32_t U;
    struct _hw_src_gpr2_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr2_t;
#endif

/*
 * constants & macros for entire SRC_GPR2 register
 */
#define HW_SRC_GPR2_ADDR      (REGS_SRC_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR2           (*(volatile hw_src_gpr2_t *) HW_SRC_GPR2_ADDR)
#define HW_SRC_GPR2_RD()      (HW_SRC_GPR2.U)
#define HW_SRC_GPR2_WR(v)     (HW_SRC_GPR2.U = (v))
#define HW_SRC_GPR2_SET(v)    (HW_SRC_GPR2_WR(HW_SRC_GPR2_RD() |  (v)))
#define HW_SRC_GPR2_CLR(v)    (HW_SRC_GPR2_WR(HW_SRC_GPR2_RD() & ~(v)))
#define HW_SRC_GPR2_TOG(v)    (HW_SRC_GPR2_WR(HW_SRC_GPR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR2 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR3 - SRC General Purpose Register 3 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 3 (GPR3), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr3
{
    reg32_t U;
    struct _hw_src_gpr3_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr3_t;
#endif

/*
 * constants & macros for entire SRC_GPR3 register
 */
#define HW_SRC_GPR3_ADDR      (REGS_SRC_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR3           (*(volatile hw_src_gpr3_t *) HW_SRC_GPR3_ADDR)
#define HW_SRC_GPR3_RD()      (HW_SRC_GPR3.U)
#define HW_SRC_GPR3_WR(v)     (HW_SRC_GPR3.U = (v))
#define HW_SRC_GPR3_SET(v)    (HW_SRC_GPR3_WR(HW_SRC_GPR3_RD() |  (v)))
#define HW_SRC_GPR3_CLR(v)    (HW_SRC_GPR3_WR(HW_SRC_GPR3_RD() & ~(v)))
#define HW_SRC_GPR3_TOG(v)    (HW_SRC_GPR3_WR(HW_SRC_GPR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR3 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR4 - SRC General Purpose Register 4 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 4 (GPR4), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr4
{
    reg32_t U;
    struct _hw_src_gpr4_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr4_t;
#endif

/*
 * constants & macros for entire SRC_GPR4 register
 */
#define HW_SRC_GPR4_ADDR      (REGS_SRC_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR4           (*(volatile hw_src_gpr4_t *) HW_SRC_GPR4_ADDR)
#define HW_SRC_GPR4_RD()      (HW_SRC_GPR4.U)
#define HW_SRC_GPR4_WR(v)     (HW_SRC_GPR4.U = (v))
#define HW_SRC_GPR4_SET(v)    (HW_SRC_GPR4_WR(HW_SRC_GPR4_RD() |  (v)))
#define HW_SRC_GPR4_CLR(v)    (HW_SRC_GPR4_WR(HW_SRC_GPR4_RD() & ~(v)))
#define HW_SRC_GPR4_TOG(v)    (HW_SRC_GPR4_WR(HW_SRC_GPR4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR4 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR5 - SRC General Purpose Register 5 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 5(GPR5), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr5
{
    reg32_t U;
    struct _hw_src_gpr5_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr5_t;
#endif

/*
 * constants & macros for entire SRC_GPR5 register
 */
#define HW_SRC_GPR5_ADDR      (REGS_SRC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR5           (*(volatile hw_src_gpr5_t *) HW_SRC_GPR5_ADDR)
#define HW_SRC_GPR5_RD()      (HW_SRC_GPR5.U)
#define HW_SRC_GPR5_WR(v)     (HW_SRC_GPR5.U = (v))
#define HW_SRC_GPR5_SET(v)    (HW_SRC_GPR5_WR(HW_SRC_GPR5_RD() |  (v)))
#define HW_SRC_GPR5_CLR(v)    (HW_SRC_GPR5_WR(HW_SRC_GPR5_RD() & ~(v)))
#define HW_SRC_GPR5_TOG(v)    (HW_SRC_GPR5_WR(HW_SRC_GPR5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR5 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR6 - SRC General Purpose Register 6 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 6(GPR6), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr6
{
    reg32_t U;
    struct _hw_src_gpr6_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr6_t;
#endif

/*
 * constants & macros for entire SRC_GPR6 register
 */
#define HW_SRC_GPR6_ADDR      (REGS_SRC_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR6           (*(volatile hw_src_gpr6_t *) HW_SRC_GPR6_ADDR)
#define HW_SRC_GPR6_RD()      (HW_SRC_GPR6.U)
#define HW_SRC_GPR6_WR(v)     (HW_SRC_GPR6.U = (v))
#define HW_SRC_GPR6_SET(v)    (HW_SRC_GPR6_WR(HW_SRC_GPR6_RD() |  (v)))
#define HW_SRC_GPR6_CLR(v)    (HW_SRC_GPR6_WR(HW_SRC_GPR6_RD() & ~(v)))
#define HW_SRC_GPR6_TOG(v)    (HW_SRC_GPR6_WR(HW_SRC_GPR6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR6 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR7 - SRC General Purpose Register 7 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 7(GPR7), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr7
{
    reg32_t U;
    struct _hw_src_gpr7_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr7_t;
#endif

/*
 * constants & macros for entire SRC_GPR7 register
 */
#define HW_SRC_GPR7_ADDR      (REGS_SRC_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR7           (*(volatile hw_src_gpr7_t *) HW_SRC_GPR7_ADDR)
#define HW_SRC_GPR7_RD()      (HW_SRC_GPR7.U)
#define HW_SRC_GPR7_WR(v)     (HW_SRC_GPR7.U = (v))
#define HW_SRC_GPR7_SET(v)    (HW_SRC_GPR7_WR(HW_SRC_GPR7_RD() |  (v)))
#define HW_SRC_GPR7_CLR(v)    (HW_SRC_GPR7_WR(HW_SRC_GPR7_RD() & ~(v)))
#define HW_SRC_GPR7_TOG(v)    (HW_SRC_GPR7_WR(HW_SRC_GPR7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR7 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR8 - SRC General Purpose Register 8 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 8(GPR8), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr8
{
    reg32_t U;
    struct _hw_src_gpr8_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose
    } B;
} hw_src_gpr8_t;
#endif

/*
 * constants & macros for entire SRC_GPR8 register
 */
#define HW_SRC_GPR8_ADDR      (REGS_SRC_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR8           (*(volatile hw_src_gpr8_t *) HW_SRC_GPR8_ADDR)
#define HW_SRC_GPR8_RD()      (HW_SRC_GPR8.U)
#define HW_SRC_GPR8_WR(v)     (HW_SRC_GPR8.U = (v))
#define HW_SRC_GPR8_SET(v)    (HW_SRC_GPR8_WR(HW_SRC_GPR8_RD() |  (v)))
#define HW_SRC_GPR8_CLR(v)    (HW_SRC_GPR8_WR(HW_SRC_GPR8_RD() & ~(v)))
#define HW_SRC_GPR8_TOG(v)    (HW_SRC_GPR8_WR(HW_SRC_GPR8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR8 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR9 - SRC General Purpose Register 9 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 9(GPR9), contains read/write bits that can be used for any purpose.
 */
typedef union _hw_src_gpr9
{
    reg32_t U;
    struct _hw_src_gpr9_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose. this register is reseted only by POR reset.
    } B;
} hw_src_gpr9_t;
#endif

/*
 * constants & macros for entire SRC_GPR9 register
 */
#define HW_SRC_GPR9_ADDR      (REGS_SRC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR9           (*(volatile hw_src_gpr9_t *) HW_SRC_GPR9_ADDR)
#define HW_SRC_GPR9_RD()      (HW_SRC_GPR9.U)
#define HW_SRC_GPR9_WR(v)     (HW_SRC_GPR9.U = (v))
#define HW_SRC_GPR9_SET(v)    (HW_SRC_GPR9_WR(HW_SRC_GPR9_RD() |  (v)))
#define HW_SRC_GPR9_CLR(v)    (HW_SRC_GPR9_WR(HW_SRC_GPR9_RD() & ~(v)))
#define HW_SRC_GPR9_TOG(v)    (HW_SRC_GPR9_WR(HW_SRC_GPR9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR9 bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR10 - SRC General Purpose Register 10 (RW)
 *
 * Reset value: 0x00000000
 *
 * The general purpose register 10(GPR10), contains read/write bits that can be used for any
 * purpose.
 */
typedef union _hw_src_gpr10
{
    reg32_t U;
    struct _hw_src_gpr10_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Read/write bits, for general purpose. this register is reseted only by POR reset.
    } B;
} hw_src_gpr10_t;
#endif

/*
 * constants & macros for entire SRC_GPR10 register
 */
#define HW_SRC_GPR10_ADDR      (REGS_SRC_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SRC_GPR10           (*(volatile hw_src_gpr10_t *) HW_SRC_GPR10_ADDR)
#define HW_SRC_GPR10_RD()      (HW_SRC_GPR10.U)
#define HW_SRC_GPR10_WR(v)     (HW_SRC_GPR10.U = (v))
#define HW_SRC_GPR10_SET(v)    (HW_SRC_GPR10_WR(HW_SRC_GPR10_RD() |  (v)))
#define HW_SRC_GPR10_CLR(v)    (HW_SRC_GPR10_WR(HW_SRC_GPR10_RD() & ~(v)))
#define HW_SRC_GPR10_TOG(v)    (HW_SRC_GPR10_WR(HW_SRC_GPR10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SRC_GPR10 bitfields
 */


/*!
 * @brief All SRC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_src
{
    volatile hw_src_scr_t SCR; //!< SRC Control Register
    volatile hw_src_sbmr1_t SBMR1; //!< SRC Boot Mode Register 1
    volatile hw_src_srsr_t SRSR; //!< SRC Reset Status Register
    reg32_t _reserved0[2];
    volatile hw_src_sisr_t SISR; //!< SRC Interrupt Status Register
    volatile hw_src_simr_t SIMR; //!< SRC Interrupt Mask Register
    volatile hw_src_sbmr2_t SBMR2; //!< SRC Boot Mode Register 2
    volatile hw_src_gpr1_t GPR1; //!< SRC General Purpose Register 1
    volatile hw_src_gpr2_t GPR2; //!< SRC General Purpose Register 2
    volatile hw_src_gpr3_t GPR3; //!< SRC General Purpose Register 3
    volatile hw_src_gpr4_t GPR4; //!< SRC General Purpose Register 4
    volatile hw_src_gpr5_t GPR5; //!< SRC General Purpose Register 5
    volatile hw_src_gpr6_t GPR6; //!< SRC General Purpose Register 6
    volatile hw_src_gpr7_t GPR7; //!< SRC General Purpose Register 7
    volatile hw_src_gpr8_t GPR8; //!< SRC General Purpose Register 8
    volatile hw_src_gpr9_t GPR9; //!< SRC General Purpose Register 9
    volatile hw_src_gpr10_t GPR10; //!< SRC General Purpose Register 10
} hw_src_t;
#pragma pack()

//! @brief Macro to access all SRC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SRC(0)</code>.
#define HW_SRC     (*(volatile hw_src_t *) REGS_SRC_BASE)

#endif


#endif // __HW_SRC_REGISTERS_H__
