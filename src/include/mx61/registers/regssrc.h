/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SRC_H
#define _SRC_H

#include "regs.h"

/*
 * Registers defined in this header file.
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
 * hw_src_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SRC_BASE
#define REGS_SRC_BASE (0x020d8000) //!< Base address for SRC.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SCR - SRC Control Register (RW)
 *
 * The Reset control register (SCR), contains bits that control operation of the reset controller.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned WARM_RESET_ENABLE : 1; //!< Warm reset enable bit. Warm reset will be enabled only if warm_reset_enable bit is set. Otherwise all warm reset sources will generate cold reset.
        unsigned SW_GPU_RST : 1; //!< Software reset for gpu this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details. the reset process will involve 8 gpu cycles before negating the gpu reset, to allow reset assertion to propagate into gpu.
        unsigned SW_VPU_RST : 1; //!< Software reset for vpu this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details. the reset process will involve 8 vpu cycles before negating the vpu reset, to allow reset assertion to propagate into vpu.
        unsigned SW_IPU1_RST : 1; //!< Software reset for ipu1 Note: this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details.
        unsigned SW_OPEN_VG_RST : 1; //!< Software reset for open_vg this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details. the reset process will involve 8 open_vg cycles before negating the open_vg reset, to allow reset assertion to propagate into open_vg.
        unsigned WARM_RST_BYPASS_COUNT : 2; //!< Defines the ckil cycles to count before bypassing the emi acknowledge for warm reset. If the emi acknowledge will not be asserted before this counter has elapsed, then a cold reset will be initiated.
        unsigned MASK_WDOG_RST : 4; //!< Mask wdog_rst_b source. If these 4 bits are coded from A to 5 then, wdog_rst_b input to SRC will be masked and wdog_rst_b will not create reset to the IC. During the time the WDOG event is masked using SRC logic, it is likely that WDOG Reset Status Register (WRSR) bit 1 (which indicates WDOG timeout event) will get asserted. SW / OS developer must prepare for this case. Re-enable WDOG is possible, by un-mask it in SRC, though it must be preceded by servicing the WDOG. However, for the case that the event has been asserted, the status bit (WRSR bit-1) will remain asserted, regardless of servicing the WDOG module. (HW reset is the only mean to cause de-assertion of that bit). any other code will be coded to 1010 i.e. wdog_rst_b is not masked
        unsigned WEIM_RST : 1; //!< WEIM reset is needed in order to reconfigure the weim chip select. The software reset bit must de-asserted. The weim chip select configuration should be updated. The software bit must be re-asserted since this is not self-refresh.
        unsigned SW_IPU2_RST : 1; //!< Software reset for ipu2 this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared. Software can determine that the reset has finished once this bit is cleared. Software can also configure SRC to generate interrutp once the software has finished. Please referto SISR register for details.
        unsigned CORE0_RST : 1; //!< Software reset for core0 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE1_RST : 1; //!< Software reset for core1 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE2_RST : 1; //!< Software reset for core2 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE3_RST : 1; //!< Software reset for core3 only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE0_DBG_RST : 1; //!< Software reset for core0 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE1_DBG_RST : 1; //!< Software reset for core1 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE2_DBG_RST : 1; //!< Software reset for core2 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE3_DBG_RST : 1; //!< Software reset for core3 debug only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORES_DBG_RST : 1; //!< Software reset for debug of arm platform only. this is a self clearing bit. Once it is set to 1, the reset process will begin, and once it finishes, this bit will be self cleared.
        unsigned CORE1_ENABLE : 1; //!< CPU core1 enable. core0 cannot be disabled
        unsigned CORE2_ENABLE : 1; //!< CPU core2 enable. core0 cannot be disabled
        unsigned CORE3_ENABLE : 1; //!< CPU core3 enable. core0 cannot be disabled
        unsigned DBG_RST_MSK_PG : 1; //!< Do not assert debug resets after power gating event of cpu
        unsigned RESERVED0 : 6; //!< Reserved
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

/* --- Register HW_SRC_SCR, field WARM_RESET_ENABLE (RW)
 *
 * Warm reset enable bit. Warm reset will be enabled only if warm_reset_enable bit is set. Otherwise
 * all warm reset sources will generate cold reset.
 *
 * Values:
 * 0 - Warm reset disabled
 * 1 - Warm reset enabled
 */

#define BP_SRC_SCR_WARM_RESET_ENABLE      0
#define BM_SRC_SCR_WARM_RESET_ENABLE      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_WARM_RESET_ENABLE(v)   ((((reg32_t) v) << 0) & BM_SRC_SCR_WARM_RESET_ENABLE)
#else
#define BF_SRC_SCR_WARM_RESET_ENABLE(v)   (((v) << 0) & BM_SRC_SCR_WARM_RESET_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WARM_RESET_ENABLE field to a new value.
#define BW_SRC_SCR_WARM_RESET_ENABLE(v)   BF_CS1(SRC_SCR, WARM_RESET_ENABLE, v)
#endif


/* --- Register HW_SRC_SCR, field SW_GPU_RST (RW)
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

#define BP_SRC_SCR_SW_GPU_RST      1
#define BM_SRC_SCR_SW_GPU_RST      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_SW_GPU_RST(v)   ((((reg32_t) v) << 1) & BM_SRC_SCR_SW_GPU_RST)
#else
#define BF_SRC_SCR_SW_GPU_RST(v)   (((v) << 1) & BM_SRC_SCR_SW_GPU_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_GPU_RST field to a new value.
#define BW_SRC_SCR_SW_GPU_RST(v)   BF_CS1(SRC_SCR, SW_GPU_RST, v)
#endif


/* --- Register HW_SRC_SCR, field SW_VPU_RST (RW)
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

#define BP_SRC_SCR_SW_VPU_RST      2
#define BM_SRC_SCR_SW_VPU_RST      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_SW_VPU_RST(v)   ((((reg32_t) v) << 2) & BM_SRC_SCR_SW_VPU_RST)
#else
#define BF_SRC_SCR_SW_VPU_RST(v)   (((v) << 2) & BM_SRC_SCR_SW_VPU_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_VPU_RST field to a new value.
#define BW_SRC_SCR_SW_VPU_RST(v)   BF_CS1(SRC_SCR, SW_VPU_RST, v)
#endif


/* --- Register HW_SRC_SCR, field SW_IPU1_RST (RW)
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

#define BP_SRC_SCR_SW_IPU1_RST      3
#define BM_SRC_SCR_SW_IPU1_RST      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_SW_IPU1_RST(v)   ((((reg32_t) v) << 3) & BM_SRC_SCR_SW_IPU1_RST)
#else
#define BF_SRC_SCR_SW_IPU1_RST(v)   (((v) << 3) & BM_SRC_SCR_SW_IPU1_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_IPU1_RST field to a new value.
#define BW_SRC_SCR_SW_IPU1_RST(v)   BF_CS1(SRC_SCR, SW_IPU1_RST, v)
#endif


/* --- Register HW_SRC_SCR, field SW_OPEN_VG_RST (RW)
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

#define BP_SRC_SCR_SW_OPEN_VG_RST      4
#define BM_SRC_SCR_SW_OPEN_VG_RST      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_SW_OPEN_VG_RST(v)   ((((reg32_t) v) << 4) & BM_SRC_SCR_SW_OPEN_VG_RST)
#else
#define BF_SRC_SCR_SW_OPEN_VG_RST(v)   (((v) << 4) & BM_SRC_SCR_SW_OPEN_VG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_OPEN_VG_RST field to a new value.
#define BW_SRC_SCR_SW_OPEN_VG_RST(v)   BF_CS1(SRC_SCR, SW_OPEN_VG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field WARM_RST_BYPASS_COUNT (RW)
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

#define BP_SRC_SCR_WARM_RST_BYPASS_COUNT      5
#define BM_SRC_SCR_WARM_RST_BYPASS_COUNT      0x00000060

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_WARM_RST_BYPASS_COUNT(v)   ((((reg32_t) v) << 5) & BM_SRC_SCR_WARM_RST_BYPASS_COUNT)
#else
#define BF_SRC_SCR_WARM_RST_BYPASS_COUNT(v)   (((v) << 5) & BM_SRC_SCR_WARM_RST_BYPASS_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WARM_RST_BYPASS_COUNT field to a new value.
#define BW_SRC_SCR_WARM_RST_BYPASS_COUNT(v)   BF_CS1(SRC_SCR, WARM_RST_BYPASS_COUNT, v)
#endif


/* --- Register HW_SRC_SCR, field MASK_WDOG_RST (RW)
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

#define BP_SRC_SCR_MASK_WDOG_RST      7
#define BM_SRC_SCR_MASK_WDOG_RST      0x00000780

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_MASK_WDOG_RST(v)   ((((reg32_t) v) << 7) & BM_SRC_SCR_MASK_WDOG_RST)
#else
#define BF_SRC_SCR_MASK_WDOG_RST(v)   (((v) << 7) & BM_SRC_SCR_MASK_WDOG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_WDOG_RST field to a new value.
#define BW_SRC_SCR_MASK_WDOG_RST(v)   BF_CS1(SRC_SCR, MASK_WDOG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field WEIM_RST (RW)
 *
 * WEIM reset is needed in order to reconfigure the weim chip select. The software reset bit must
 * de-asserted. The weim chip select configuration should be updated. The software bit must be re-
 * asserted since this is not self-refresh.
 */

#define BP_SRC_SCR_WEIM_RST      11
#define BM_SRC_SCR_WEIM_RST      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_WEIM_RST(v)   ((((reg32_t) v) << 11) & BM_SRC_SCR_WEIM_RST)
#else
#define BF_SRC_SCR_WEIM_RST(v)   (((v) << 11) & BM_SRC_SCR_WEIM_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WEIM_RST field to a new value.
#define BW_SRC_SCR_WEIM_RST(v)   BF_CS1(SRC_SCR, WEIM_RST, v)
#endif

/* --- Register HW_SRC_SCR, field SW_IPU2_RST (RW)
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

#define BP_SRC_SCR_SW_IPU2_RST      12
#define BM_SRC_SCR_SW_IPU2_RST      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_SW_IPU2_RST(v)   ((((reg32_t) v) << 12) & BM_SRC_SCR_SW_IPU2_RST)
#else
#define BF_SRC_SCR_SW_IPU2_RST(v)   (((v) << 12) & BM_SRC_SCR_SW_IPU2_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SW_IPU2_RST field to a new value.
#define BW_SRC_SCR_SW_IPU2_RST(v)   BF_CS1(SRC_SCR, SW_IPU2_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE0_RST (RW)
 *
 * Software reset for core0 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE0_RST      13
#define BM_SRC_SCR_CORE0_RST      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE0_RST(v)   ((((reg32_t) v) << 13) & BM_SRC_SCR_CORE0_RST)
#else
#define BF_SRC_SCR_CORE0_RST(v)   (((v) << 13) & BM_SRC_SCR_CORE0_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE0_RST field to a new value.
#define BW_SRC_SCR_CORE0_RST(v)   BF_CS1(SRC_SCR, CORE0_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE1_RST (RW)
 *
 * Software reset for core1 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE1_RST      14
#define BM_SRC_SCR_CORE1_RST      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE1_RST(v)   ((((reg32_t) v) << 14) & BM_SRC_SCR_CORE1_RST)
#else
#define BF_SRC_SCR_CORE1_RST(v)   (((v) << 14) & BM_SRC_SCR_CORE1_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE1_RST field to a new value.
#define BW_SRC_SCR_CORE1_RST(v)   BF_CS1(SRC_SCR, CORE1_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE2_RST (RW)
 *
 * Software reset for core2 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE2_RST      15
#define BM_SRC_SCR_CORE2_RST      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE2_RST(v)   ((((reg32_t) v) << 15) & BM_SRC_SCR_CORE2_RST)
#else
#define BF_SRC_SCR_CORE2_RST(v)   (((v) << 15) & BM_SRC_SCR_CORE2_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE2_RST field to a new value.
#define BW_SRC_SCR_CORE2_RST(v)   BF_CS1(SRC_SCR, CORE2_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE3_RST (RW)
 *
 * Software reset for core3 only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 reset
 * 1 - assert core0 reset
 */

#define BP_SRC_SCR_CORE3_RST      16
#define BM_SRC_SCR_CORE3_RST      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE3_RST(v)   ((((reg32_t) v) << 16) & BM_SRC_SCR_CORE3_RST)
#else
#define BF_SRC_SCR_CORE3_RST(v)   (((v) << 16) & BM_SRC_SCR_CORE3_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE3_RST field to a new value.
#define BW_SRC_SCR_CORE3_RST(v)   BF_CS1(SRC_SCR, CORE3_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE0_DBG_RST (RW)
 *
 * Software reset for core0 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core0 debug reset
 * 1 - assert core0 debug reset
 */

#define BP_SRC_SCR_CORE0_DBG_RST      17
#define BM_SRC_SCR_CORE0_DBG_RST      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE0_DBG_RST(v)   ((((reg32_t) v) << 17) & BM_SRC_SCR_CORE0_DBG_RST)
#else
#define BF_SRC_SCR_CORE0_DBG_RST(v)   (((v) << 17) & BM_SRC_SCR_CORE0_DBG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE0_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE0_DBG_RST(v)   BF_CS1(SRC_SCR, CORE0_DBG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE1_DBG_RST (RW)
 *
 * Software reset for core1 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core1 debug reset
 * 1 - assert core1 debug reset
 */

#define BP_SRC_SCR_CORE1_DBG_RST      18
#define BM_SRC_SCR_CORE1_DBG_RST      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE1_DBG_RST(v)   ((((reg32_t) v) << 18) & BM_SRC_SCR_CORE1_DBG_RST)
#else
#define BF_SRC_SCR_CORE1_DBG_RST(v)   (((v) << 18) & BM_SRC_SCR_CORE1_DBG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE1_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE1_DBG_RST(v)   BF_CS1(SRC_SCR, CORE1_DBG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE2_DBG_RST (RW)
 *
 * Software reset for core2 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core2 debug reset
 * 1 - assert core2 debug reset
 */

#define BP_SRC_SCR_CORE2_DBG_RST      19
#define BM_SRC_SCR_CORE2_DBG_RST      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE2_DBG_RST(v)   ((((reg32_t) v) << 19) & BM_SRC_SCR_CORE2_DBG_RST)
#else
#define BF_SRC_SCR_CORE2_DBG_RST(v)   (((v) << 19) & BM_SRC_SCR_CORE2_DBG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE2_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE2_DBG_RST(v)   BF_CS1(SRC_SCR, CORE2_DBG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE3_DBG_RST (RW)
 *
 * Software reset for core3 debug only. this is a self clearing bit. Once it is set to 1, the reset
 * process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert core3 debug reset
 * 1 - assert core3 debug reset
 */

#define BP_SRC_SCR_CORE3_DBG_RST      20
#define BM_SRC_SCR_CORE3_DBG_RST      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE3_DBG_RST(v)   ((((reg32_t) v) << 20) & BM_SRC_SCR_CORE3_DBG_RST)
#else
#define BF_SRC_SCR_CORE3_DBG_RST(v)   (((v) << 20) & BM_SRC_SCR_CORE3_DBG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE3_DBG_RST field to a new value.
#define BW_SRC_SCR_CORE3_DBG_RST(v)   BF_CS1(SRC_SCR, CORE3_DBG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORES_DBG_RST (RW)
 *
 * Software reset for debug of arm platform only. this is a self clearing bit. Once it is set to 1,
 * the reset process will begin, and once it finishes, this bit will be self cleared.
 *
 * Values:
 * 0 - do not assert arm platform debug reset
 * 1 - assert arm platform debug reset
 */

#define BP_SRC_SCR_CORES_DBG_RST      21
#define BM_SRC_SCR_CORES_DBG_RST      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORES_DBG_RST(v)   ((((reg32_t) v) << 21) & BM_SRC_SCR_CORES_DBG_RST)
#else
#define BF_SRC_SCR_CORES_DBG_RST(v)   (((v) << 21) & BM_SRC_SCR_CORES_DBG_RST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORES_DBG_RST field to a new value.
#define BW_SRC_SCR_CORES_DBG_RST(v)   BF_CS1(SRC_SCR, CORES_DBG_RST, v)
#endif


/* --- Register HW_SRC_SCR, field CORE1_ENABLE (RW)
 *
 * CPU core1 enable. core0 cannot be disabled
 *
 * Values:
 * 0 - core1 is disabled
 * 1 - core1 is enabled
 */

#define BP_SRC_SCR_CORE1_ENABLE      22
#define BM_SRC_SCR_CORE1_ENABLE      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE1_ENABLE(v)   ((((reg32_t) v) << 22) & BM_SRC_SCR_CORE1_ENABLE)
#else
#define BF_SRC_SCR_CORE1_ENABLE(v)   (((v) << 22) & BM_SRC_SCR_CORE1_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE1_ENABLE field to a new value.
#define BW_SRC_SCR_CORE1_ENABLE(v)   BF_CS1(SRC_SCR, CORE1_ENABLE, v)
#endif


/* --- Register HW_SRC_SCR, field CORE2_ENABLE (RW)
 *
 * CPU core2 enable. core0 cannot be disabled
 *
 * Values:
 * 0 - core2 is disabled
 * 1 - core2 is enabled
 */

#define BP_SRC_SCR_CORE2_ENABLE      23
#define BM_SRC_SCR_CORE2_ENABLE      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE2_ENABLE(v)   ((((reg32_t) v) << 23) & BM_SRC_SCR_CORE2_ENABLE)
#else
#define BF_SRC_SCR_CORE2_ENABLE(v)   (((v) << 23) & BM_SRC_SCR_CORE2_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE2_ENABLE field to a new value.
#define BW_SRC_SCR_CORE2_ENABLE(v)   BF_CS1(SRC_SCR, CORE2_ENABLE, v)
#endif


/* --- Register HW_SRC_SCR, field CORE3_ENABLE (RW)
 *
 * CPU core3 enable. core0 cannot be disabled
 *
 * Values:
 * 0 - core3 is disabled
 * 1 - core3 is enabled
 */

#define BP_SRC_SCR_CORE3_ENABLE      24
#define BM_SRC_SCR_CORE3_ENABLE      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_CORE3_ENABLE(v)   ((((reg32_t) v) << 24) & BM_SRC_SCR_CORE3_ENABLE)
#else
#define BF_SRC_SCR_CORE3_ENABLE(v)   (((v) << 24) & BM_SRC_SCR_CORE3_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CORE3_ENABLE field to a new value.
#define BW_SRC_SCR_CORE3_ENABLE(v)   BF_CS1(SRC_SCR, CORE3_ENABLE, v)
#endif


/* --- Register HW_SRC_SCR, field DBG_RST_MSK_PG (RW)
 *
 * Do not assert debug resets after power gating event of cpu
 *
 * Values:
 * 0 - don't mask cpu debug resets (debug resets will be asserted after power gating event)
 * 1 - maks cpu debug resets (debug resets won't be asserted after power gating event)
 */

#define BP_SRC_SCR_DBG_RST_MSK_PG      25
#define BM_SRC_SCR_DBG_RST_MSK_PG      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SCR_DBG_RST_MSK_PG(v)   ((((reg32_t) v) << 25) & BM_SRC_SCR_DBG_RST_MSK_PG)
#else
#define BF_SRC_SCR_DBG_RST_MSK_PG(v)   (((v) << 25) & BM_SRC_SCR_DBG_RST_MSK_PG)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DBG_RST_MSK_PG field to a new value.
#define BW_SRC_SCR_DBG_RST_MSK_PG(v)   BF_CS1(SRC_SCR, DBG_RST_MSK_PG, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SBMR1 - SRC Boot Mode Register 1 (RO)
 *
 * The Boot Mode register (SBMR) contains bits that reflect the status of Boot Mode Pins of the
 * chip. The default values for those bits depends on the values of pins/fuses during reset
 * sequence, hence the question mark on their default value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned BOOT_CFG1 : 8; //!< Please refer to fuse map.
        unsigned BOOT_CFG2 : 8; //!< Please refer to fuse map.
        unsigned BOOT_CFG3 : 8; //!< Please refer to fuse map.
        unsigned BOOT_CFG4 : 8; //!< Please refer to fuse map.
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

/* --- Register HW_SRC_SBMR1, field BOOT_CFG1 (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG1      0
#define BM_SRC_SBMR1_BOOT_CFG1      0x000000ff

/* --- Register HW_SRC_SBMR1, field BOOT_CFG2 (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG2      8
#define BM_SRC_SBMR1_BOOT_CFG2      0x0000ff00

/* --- Register HW_SRC_SBMR1, field BOOT_CFG3 (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG3      16
#define BM_SRC_SBMR1_BOOT_CFG3      0x00ff0000

/* --- Register HW_SRC_SBMR1, field BOOT_CFG4 (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR1_BOOT_CFG4      24
#define BM_SRC_SBMR1_BOOT_CFG4      0xff000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SRSR - SRC Reset Status Register (RW)
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
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IPP_RESET_B : 1; //!< Indicates whether reset was the result of ipp_reset_b pin (Power-up sequence)
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned CSU_RESET_B : 1; //!< Indicates whether the reset was the result of the csu_reset_b input. If case the csu_reset_b occured during a warm reset process, during the phase that ipg_clk is not available yet, then the occurance of csu reset will not be reflected in this bit.
        unsigned IPP_USER_RESET_B : 1; //!< Indicates whether the reset was the result of the ipp_user_reset_b qulified reset.
        unsigned WDOG_RST_B : 1; //!< IC Watchdog Time-out reset. Indicates whether the reset was the result of the watchdog time-out event.
        unsigned JTAG_RST_B : 1; //!< HIGH - Z JTAG reset. Indicates whether the reset was the result of HIGH-Z reset reset from JTAG. Connections at chip-level: jtag_rst_b -> sjc_ieee_reset_b
        unsigned JTAG_SW_RST : 1; //!< JTAG SW reset. Indicates whether the reset was the result of software reset from JTAG. Connections at chip-level: jtag_sw_rst -> sjc_gpccr_reg_2_b
        unsigned RESERVED1 : 9; //!< Reserved
        unsigned WARM_BOOT : 1; //!< Warm boot indication gives software capability to notify that warm boot was initiated by software. This indicates to the software that it saved the needed info in the memory before initiating the warm reset. In this case , software will set this bit to '1', before initiating the warm reset. The warm_boot bit should be used as indication only after a warm_reset sequence. Software should clear this bit after warm_reset to indicate that next warm_reset is not done with warm_boot. Please refer to for details on warm_reset.
        unsigned RESERVED2 : 15; //!< Reserved
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

/* --- Register HW_SRC_SRSR, field IPP_RESET_B (W1C)
 *
 * Indicates whether reset was the result of ipp_reset_b pin (Power-up sequence)
 *
 * Values:
 * 0 - Reset is not a result of ipp_reset_b pin.
 * 1 - Reset is a result of ipp_reset_b pin.
 */

#define BP_SRC_SRSR_IPP_RESET_B      0
#define BM_SRC_SRSR_IPP_RESET_B      0x00000001


/* --- Register HW_SRC_SRSR, field CSU_RESET_B (W1C)
 *
 * Indicates whether the reset was the result of the csu_reset_b input. If case the csu_reset_b
 * occured during a warm reset process, during the phase that ipg_clk is not available yet, then the
 * occurance of csu reset will not be reflected in this bit.
 *
 * Values:
 * 0 - Reset is not a result of the csu_reset_b event.
 * 1 - Reset is a result of the csu_reset_b event.
 */

#define BP_SRC_SRSR_CSU_RESET_B      2
#define BM_SRC_SRSR_CSU_RESET_B      0x00000004


/* --- Register HW_SRC_SRSR, field IPP_USER_RESET_B (W1C)
 *
 * Indicates whether the reset was the result of the ipp_user_reset_b qulified reset.
 *
 * Values:
 * 0 - Reset is not a result of the ipp_user_reset_b qulified as COLD event.
 * 1 - Reset is a result of the ipp_user_reset_b qulified as COLD event.
 */

#define BP_SRC_SRSR_IPP_USER_RESET_B      3
#define BM_SRC_SRSR_IPP_USER_RESET_B      0x00000008


/* --- Register HW_SRC_SRSR, field WDOG_RST_B (W1C)
 *
 * IC Watchdog Time-out reset. Indicates whether the reset was the result of the watchdog time-out
 * event.
 *
 * Values:
 * 0 - Reset is not a result of the watchdog time-out event.
 * 1 - Reset is a result of the watchdog time-out event.
 */

#define BP_SRC_SRSR_WDOG_RST_B      4
#define BM_SRC_SRSR_WDOG_RST_B      0x00000010


/* --- Register HW_SRC_SRSR, field JTAG_RST_B (W1C)
 *
 * HIGH - Z JTAG reset. Indicates whether the reset was the result of HIGH-Z reset reset from JTAG.
 * Connections at chip-level: jtag_rst_b -> sjc_ieee_reset_b
 *
 * Values:
 * 0 - Reset is not a result of HIGH-Z reset from JTAG.
 * 1 - Reset is a result of HIGH-Z reset from JTAG.
 */

#define BP_SRC_SRSR_JTAG_RST_B      5
#define BM_SRC_SRSR_JTAG_RST_B      0x00000020


/* --- Register HW_SRC_SRSR, field JTAG_SW_RST (W1C)
 *
 * JTAG SW reset. Indicates whether the reset was the result of software reset from JTAG.
 * Connections at chip-level: jtag_sw_rst -> sjc_gpccr_reg_2_b
 *
 * Values:
 * 0 - Reset is not a result of software reset from JTAG.
 * 1 - Reset is a result of software reset from JTAG.
 */

#define BP_SRC_SRSR_JTAG_SW_RST      6
#define BM_SRC_SRSR_JTAG_SW_RST      0x00000040


/* --- Register HW_SRC_SRSR, field WARM_BOOT (RW)
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

#define BP_SRC_SRSR_WARM_BOOT      16
#define BM_SRC_SRSR_WARM_BOOT      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SRSR_WARM_BOOT(v)   ((((reg32_t) v) << 16) & BM_SRC_SRSR_WARM_BOOT)
#else
#define BF_SRC_SRSR_WARM_BOOT(v)   (((v) << 16) & BM_SRC_SRSR_WARM_BOOT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the WARM_BOOT field to a new value.
#define BW_SRC_SRSR_WARM_BOOT(v)   BF_CS1(SRC_SRSR, WARM_BOOT, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SISR - SRC Interrupt Status Register (RO)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned GPU_PASSED_RESET : 1; //!< Interrupt generated to indicate that gpu passed software reset and is ready to be used
        unsigned VPU_PASSED_RESET : 1; //!< Interrupt generated to indicate that vpu passed software reset and is ready to be used
        unsigned IPU1_PASSED_RESET : 1; //!< Interrupt generated to indicate that ipu passed software reset and is ready to be used
        unsigned OPEN_VG_PASSED_RESET : 1; //!< Interrupt generated to indicate that open_vg passed software reset and is ready to be used
        unsigned IPU2_PASSED_RESET : 1; //!< Interrupt generated to indicate that ipu2 passed software reset and is ready to be used
        unsigned CORE0_WDOG_RST_REQ : 1; //!< Wdog reset request from CPU core0. Read-only status bit.
        unsigned CORE1_WDOG_RST_REQ : 1; //!< Wdog reset request from CPU core1. Read-only status bit.
        unsigned CORE2_WDOG_RST_REQ : 1; //!< Wdog reset request from CPU core2. Read-only status bit.
        unsigned CORE3_WDOG_RST_REQ : 1; //!< Wdog reset request from CPU core3. Read-only status bit.
        unsigned RESERVED0 : 23; //!< Reserved
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

/* --- Register HW_SRC_SISR, field GPU_PASSED_RESET (RO)
 *
 * Interrupt generated to indicate that gpu passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to gpu passed reset
 * 1 - interrupt genrerated due to gpu passed reset
 */

#define BP_SRC_SISR_GPU_PASSED_RESET      0
#define BM_SRC_SISR_GPU_PASSED_RESET      0x00000001


/* --- Register HW_SRC_SISR, field VPU_PASSED_RESET (RO)
 *
 * Interrupt generated to indicate that vpu passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to vpu passed reset
 * 1 - interrupt genrerated due to vpu passed reset
 */

#define BP_SRC_SISR_VPU_PASSED_RESET      1
#define BM_SRC_SISR_VPU_PASSED_RESET      0x00000002


/* --- Register HW_SRC_SISR, field IPU1_PASSED_RESET (RO)
 *
 * Interrupt generated to indicate that ipu passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to ipu passed reset
 * 1 - interrupt genrerated due to ipu passed reset
 */

#define BP_SRC_SISR_IPU1_PASSED_RESET      2
#define BM_SRC_SISR_IPU1_PASSED_RESET      0x00000004


/* --- Register HW_SRC_SISR, field OPEN_VG_PASSED_RESET (RO)
 *
 * Interrupt generated to indicate that open_vg passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to open_vg passed reset
 * 1 - interrupt genrerated due to open_vg passed reset
 */

#define BP_SRC_SISR_OPEN_VG_PASSED_RESET      3
#define BM_SRC_SISR_OPEN_VG_PASSED_RESET      0x00000008


/* --- Register HW_SRC_SISR, field IPU2_PASSED_RESET (RO)
 *
 * Interrupt generated to indicate that ipu2 passed software reset and is ready to be used
 *
 * Values:
 * 0 - interrupt genrerated not due to ipu2 passed reset
 * 1 - interrupt genrerated due to ipu2 passed reset
 */

#define BP_SRC_SISR_IPU2_PASSED_RESET      4
#define BM_SRC_SISR_IPU2_PASSED_RESET      0x00000010


/* --- Register HW_SRC_SISR, field CORE0_WDOG_RST_REQ (RO)
 *
 * Wdog reset request from CPU core0. Read-only status bit.
 */

#define BP_SRC_SISR_CORE0_WDOG_RST_REQ      5
#define BM_SRC_SISR_CORE0_WDOG_RST_REQ      0x00000020

/* --- Register HW_SRC_SISR, field CORE1_WDOG_RST_REQ (RO)
 *
 * Wdog reset request from CPU core1. Read-only status bit.
 */

#define BP_SRC_SISR_CORE1_WDOG_RST_REQ      6
#define BM_SRC_SISR_CORE1_WDOG_RST_REQ      0x00000040

/* --- Register HW_SRC_SISR, field CORE2_WDOG_RST_REQ (RO)
 *
 * Wdog reset request from CPU core2. Read-only status bit.
 */

#define BP_SRC_SISR_CORE2_WDOG_RST_REQ      7
#define BM_SRC_SISR_CORE2_WDOG_RST_REQ      0x00000080

/* --- Register HW_SRC_SISR, field CORE3_WDOG_RST_REQ (RO)
 *
 * Wdog reset request from CPU core3. Read-only status bit.
 */

#define BP_SRC_SISR_CORE3_WDOG_RST_REQ      8
#define BM_SRC_SISR_CORE3_WDOG_RST_REQ      0x00000100

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SIMR - SRC Interrupt Mask Register (RW)
 *

 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned MASK_GPU_PASSED_RESET : 1; //!< mask interrupt generation due to gpu passed reset
        unsigned MASK_VPU_PASSED_RESET : 1; //!< mask interrupt generation due to vpu passed reset
        unsigned MASK_IPU_PASSED_RESET : 1; //!< mask interrupt generation due to ipu passed reset
        unsigned MASK_OPEN_VG_PASSED_RESET : 1; //!< mask interrupt generation due to open_vg passed reset
        unsigned MASK_IPU2_PASSED_RESET : 1; //!< mask interrupt generation due to ipu2 passed reset
        unsigned RESERVED0 : 27; //!< Reserved
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

/* --- Register HW_SRC_SIMR, field MASK_GPU_PASSED_RESET (RW)
 *
 * mask interrupt generation due to gpu passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to gpu passed reset - interrupt will be created
 * 1 - mask interrupt due to gpu passed reset
 */

#define BP_SRC_SIMR_MASK_GPU_PASSED_RESET      0
#define BM_SRC_SIMR_MASK_GPU_PASSED_RESET      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SIMR_MASK_GPU_PASSED_RESET(v)   ((((reg32_t) v) << 0) & BM_SRC_SIMR_MASK_GPU_PASSED_RESET)
#else
#define BF_SRC_SIMR_MASK_GPU_PASSED_RESET(v)   (((v) << 0) & BM_SRC_SIMR_MASK_GPU_PASSED_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_GPU_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_GPU_PASSED_RESET(v)   BF_CS1(SRC_SIMR, MASK_GPU_PASSED_RESET, v)
#endif


/* --- Register HW_SRC_SIMR, field MASK_VPU_PASSED_RESET (RW)
 *
 * mask interrupt generation due to vpu passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to vpu passed reset - interrupt will be created
 * 1 - mask interrupt due to vpu passed reset
 */

#define BP_SRC_SIMR_MASK_VPU_PASSED_RESET      1
#define BM_SRC_SIMR_MASK_VPU_PASSED_RESET      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SIMR_MASK_VPU_PASSED_RESET(v)   ((((reg32_t) v) << 1) & BM_SRC_SIMR_MASK_VPU_PASSED_RESET)
#else
#define BF_SRC_SIMR_MASK_VPU_PASSED_RESET(v)   (((v) << 1) & BM_SRC_SIMR_MASK_VPU_PASSED_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_VPU_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_VPU_PASSED_RESET(v)   BF_CS1(SRC_SIMR, MASK_VPU_PASSED_RESET, v)
#endif


/* --- Register HW_SRC_SIMR, field MASK_IPU_PASSED_RESET (RW)
 *
 * mask interrupt generation due to ipu passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to ipu passed reset - interrupt will be created
 * 1 - mask interrupt due to ipu passed reset
 */

#define BP_SRC_SIMR_MASK_IPU_PASSED_RESET      2
#define BM_SRC_SIMR_MASK_IPU_PASSED_RESET      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SIMR_MASK_IPU_PASSED_RESET(v)   ((((reg32_t) v) << 2) & BM_SRC_SIMR_MASK_IPU_PASSED_RESET)
#else
#define BF_SRC_SIMR_MASK_IPU_PASSED_RESET(v)   (((v) << 2) & BM_SRC_SIMR_MASK_IPU_PASSED_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_IPU_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_IPU_PASSED_RESET(v)   BF_CS1(SRC_SIMR, MASK_IPU_PASSED_RESET, v)
#endif


/* --- Register HW_SRC_SIMR, field MASK_OPEN_VG_PASSED_RESET (RW)
 *
 * mask interrupt generation due to open_vg passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to open_vg passed reset - interrupt will be created
 * 1 - mask interrupt due to open_vg passed reset
 */

#define BP_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET      3
#define BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)   ((((reg32_t) v) << 3) & BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET)
#else
#define BF_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)   (((v) << 3) & BM_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_OPEN_VG_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_OPEN_VG_PASSED_RESET(v)   BF_CS1(SRC_SIMR, MASK_OPEN_VG_PASSED_RESET, v)
#endif


/* --- Register HW_SRC_SIMR, field MASK_IPU2_PASSED_RESET (RW)
 *
 * mask interrupt generation due to ipu2 passed reset
 *
 * Values:
 * 0 - don't mask interrupt due to ipu2 passed reset - interrupt will be created
 * 1 - mask interrupt due to ipu2 passed reset
 */

#define BP_SRC_SIMR_MASK_IPU2_PASSED_RESET      4
#define BM_SRC_SIMR_MASK_IPU2_PASSED_RESET      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)   ((((reg32_t) v) << 4) & BM_SRC_SIMR_MASK_IPU2_PASSED_RESET)
#else
#define BF_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)   (((v) << 4) & BM_SRC_SIMR_MASK_IPU2_PASSED_RESET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the MASK_IPU2_PASSED_RESET field to a new value.
#define BW_SRC_SIMR_MASK_IPU2_PASSED_RESET(v)   BF_CS1(SRC_SIMR, MASK_IPU2_PASSED_RESET, v)
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_SBMR2 - SRC Boot Mode Register 2 (RO)
 *
 * The Boot Mode register (SBMR), contains bits that reflect the status of Boot Mode Pins of the
 * chip. The default values for those bits depends on the values of pins/fuses during reset
 * sequence, hence the question mark on their default value.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SEC_CONFIG : 2; //!< Please refer to fuse map.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned DIR_BT_DIS : 1; //!< Please refer to fuse map.
        unsigned BT_FUSE_SEL : 1; //!< BT_FUSE_SEL (connected to gpio bt_fuse_sel)
        unsigned RESERVED_FUSES : 3; //!< Please refer to fuse map (connected to hwv_fuse[199:197])
        unsigned RESERVED1 : 16; //!< Reserved
        unsigned BMOD : 2; //!< Please refer to fuse map.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TEST_MODE : 3; //!< Please refer to fuse map.
        unsigned RESERVED3 : 2; //!< Reserved
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

/* --- Register HW_SRC_SBMR2, field SEC_CONFIG (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_SEC_CONFIG      0
#define BM_SRC_SBMR2_SEC_CONFIG      0x00000003

/* --- Register HW_SRC_SBMR2, field DIR_BT_DIS (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_DIR_BT_DIS      3
#define BM_SRC_SBMR2_DIR_BT_DIS      0x00000008

/* --- Register HW_SRC_SBMR2, field BT_FUSE_SEL (RO)
 *
 * BT_FUSE_SEL (connected to gpio bt_fuse_sel)
 */

#define BP_SRC_SBMR2_BT_FUSE_SEL      4
#define BM_SRC_SBMR2_BT_FUSE_SEL      0x00000010

/* --- Register HW_SRC_SBMR2, field RESERVED_FUSES (RO)
 *
 * Please refer to fuse map (connected to hwv_fuse[199:197])
 */

#define BP_SRC_SBMR2_RESERVED_FUSES      5
#define BM_SRC_SBMR2_RESERVED_FUSES      0x000000e0

/* --- Register HW_SRC_SBMR2, field BMOD (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_BMOD      24
#define BM_SRC_SBMR2_BMOD      0x03000000

/* --- Register HW_SRC_SBMR2, field TEST_MODE (RO)
 *
 * Please refer to fuse map.
 */

#define BP_SRC_SBMR2_TEST_MODE      27
#define BM_SRC_SBMR2_TEST_MODE      0x38000000

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SRC_GPR1 - SRC General Purpose Register 1 (RW)
 *
 * The general purpose register 1 (GPR1), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 2(GPR2), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 3 (GPR3), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 4 (GPR4), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 5(GPR5), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 6(GPR6), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 7(GPR7), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 8(GPR8), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose
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
 * The general purpose register 9(GPR9), contains read/write bits that can be used for any purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose. this register is reseted only by POR reset.
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
 * The general purpose register 10(GPR10), contains read/write bits that can be used for any
 * purpose.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 32; //!< Read/write bits, for general purpose. this register is reseted only by POR reset.
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
typedef struct
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
} hw_src_t
#endif

//! @brief Macro to access all SRC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SRC(0)</code>.
#define HW_SRC     (*(volatile hw_src_t *) REGS_SRC_BASE)


#endif // _SRC_H
