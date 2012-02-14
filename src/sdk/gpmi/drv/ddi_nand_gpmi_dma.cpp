/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#include "drivers/media/ddi_media.h"
#include "ddi_nand_gpmi_internal.h"
#include "os/thi/os_thi_api.h"
#include "hw/core/vmemory.h"
#include "hw/core/mmu.h"
#include "hw/core/hw_core.h"
#include "hw/profile/hw_profile.h"
#include "components/profile/cmp_profile.h"
#include "drivers/ddi_subgroups.h"

#ifdef DEBUG_DMA_TOUT
#include "arm_ghs.h"
#include <string.h>
#include "ddi_nand_gpmi_dma.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

typedef struct _DmaTest
{
    uint32_t uNand;
    uint32_t Return;
    uint32_t ReturnCode;
    uint32_t uNandReturn;
    uint32_t iSema;
} DmaTest;
uint32_t DmaStatus1, DmaStatus2;
DmaTest Testing[40];
uint32_t gTestcount = 0;
NAND_dma_read_t  testNandDmaDescriptor;
dma_cmd_t *pDmaCmdTest;
#endif // DEBUG_DMA_TOUT

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

GpmiDmaInfo_t g_gpmiDmaInfo;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// See ddi_nand_gpmi.h for documentation.
////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_gpmi_wait_for_dma(uint32_t u32usec, uint32_t u32NANDDeviceNum)
{
    reg32_t     r32ChipDmaNumber = NAND0_APBH_CH + u32NANDDeviceNum;
#ifdef RTOS_THREADX
    uint32_t    retCode_tx_semaphore;
#endif
    bool        bTimedOut = FALSE;
    RtStatus_t  rtStatus = SUCCESS;
    bool saveIrqState;

#ifdef DEBUG_DMA_TOUT
    uint32_t    i32Sema;
#if defined(ENABLE_SDRAM_DEBUG_MEM) && defined(CMP_PROFILE_ENABLE)
    {
        uint32_t    Handle;
        Handle = cmp_profile_start(DDI_NAND_GROUP, "ddi_gpmi_wait_for_dma start");
        cmp_profile_stop(Handle);
    }
#endif
#endif

#ifdef RTOS_THREADX
    // if a DMA is not occuring right now, return SUCCESS.  Otherwise, get stuck
    // in semaphore get below.
    if (!g_gpmiPmiStatus.bInDmaFlag)
    {
        return SUCCESS;
    }

    // Get the semaphore.  The interrupt service routine will put an instance in place.
    uint32_t timeoutTicks = OS_USECS_TO_TICKS(u32usec);
    if (u32usec == 0)
    {
        timeoutTicks = TX_WAIT_FOREVER;
    }
    retCode_tx_semaphore = tx_semaphore_get(&g_gpmiDmaInfo.pSemaphore, timeoutTicks);

    // Note that, in the RTOS_THREADX case, SEMA.PHORE register can easily be nonzero if the CPU is running fast.
    // (The DMA engine can trigger the ISR at the end of the DMA, before decrementing
    // the SEMA.PHORE count, thus creating a race condition that lets us find a
    // nonzero SEMA.PHORE value here.)
    //
    // Since SEMA.PHORE can still be nonzero, we cannot use it as
    // evidence of timeout.  We have to rely on the RTOS timeout indicator.
    bTimedOut = ( TX_SUCCESS != retCode_tx_semaphore );

    #ifdef DEBUG_DMA_TOUT
    i32Sema = HW_APBH_CHn_SEMA_RD(r32ChipDmaNumber) & BM_APBH_CHn_SEMA_PHORE;
    #endif

#else   // RTOS_THREADX not defined
    // Poll for DMA completion.
    {
        uint64_t u64StartTime;

        // Microsecond read - always read at start of transaction so that if
        // ThreadX times out, that time is included in the overall timeout time.
        u64StartTime = g_gpmiDmaInfo.uStartDMATime;

        // End of DMA chain will decrement the hardware semaphore.  Poll the hardware semaphore for
        // DMA completion.
        do {
            i32Sema = HW_APBH_CHn_SEMA_RD(r32ChipDmaNumber) & BM_APBH_CHn_SEMA_PHORE;
        } while ((i32Sema != 0) && ( (hw_profile_GetMicroseconds() - u64StartTime) < u32usec));
    }

    // Re-read the hardware semaphore in case a higher-priority thread caused the timeout between semaphore
    // and timeout test.
    i32Sema = HW_APBH_CHn_SEMA_RD(r32ChipDmaNumber) & BM_APBH_CHn_SEMA_PHORE;

    bTimedOut = (0 != i32Sema);
    
#endif  // ifdef RTOS_THREADX

#ifdef DEBUG_DMA_TOUT
    Testing[gTestcount].iSema = i32Sema;
    Testing[gTestcount].ReturnCode = (RtStatus_t)BF_RDn(APBH_CHn_BAR, r32ChipDmaNumber, ADDRESS);
    Testing[gTestcount].uNandReturn = u32NANDDeviceNum;
    gTestcount = (gTestcount+1);
    gTestcount &= 31;

    DmaStatus1 = HW_APBH_CHn_CURCMDAR_RD(NAND0_APBH_CH);
    DmaStatus2 = HW_APBH_CHn_CURCMDAR_RD(NAND0_APBH_CH + 1);

    memcpy((void *)&testNandDmaDescriptor, pDmaCmdTest,sizeof(NAND_dma_read_t));

    if ( i32Sema > BF_APBH_CHn_SEMA_PHORE(1) )
    {
        // i32Sema should never be greater than a count of '1', because
        // we never start two DMAs on a DMA channel at one time.
        SystemHalt();
    }
#endif // DEBUG_DMA_TOUT

    //
    // If timeout: return error,
    //       else: return BAR field from last DMA command
    //

    if ( bTimedOut )
    {
        // The DMA has not completed within the alotted time.
        //
        // Clean up.

        #ifdef DEBUG_DMA_TOUT
        // NOTE: Do not SystemHalt() here, since a timeout is a valid
        // outcome when the driver is scanning chip-enables to determine
        // which ones are connected to NANDs.
        
        // Enable and edit the following line to set some visible GPIO
        // signal, if you need to see a signal on an oscilloscope.
        //
        // HW_PINCTRL_DOUT0_SET(0x8000);    // BANK0[cs] = 11
        #endif

        //! \todo Since we don't know exactly what caused the timeout, it 
        //! could be beneficial to also reset the GPMI block here.
        //! Note, however, that soft-resetting the GPMI block changes
        //! its register settings.  Thus, it would also be necessary to
        //! re-initialize the GPMI settings completely.  Otherwise the
        //! GPMI may not work.
        //ddi_gpmi_soft_reset();
        
        // abort dma by resetting channel
        BW_APBH_CTRL0_RESET_CHANNEL(1 << r32ChipDmaNumber);
        // Wait for the reset to complete
        while ( HW_APBH_CTRL0.B.RESET_CHANNEL & (0x1 << r32ChipDmaNumber) )
        {
            ;
        }

        //
        // Okay, this is important.
        // When we read from the NAND using GPMI with ECC,
        // there will be an ECC interrupt upon completion of the ECC correction.
        // Thereafter, these actions must happen in sequence:
        //     1.  ECC status must be read.
        //     2.  ECC ISR must be reenabled.
        //     3.  ECC-completion must be cleared, which frees the ECC
        //         block to process the next data.
        // The status must be read before the ECC-completion is cleared, or
        // the next ECC cycle will overwrite the status.  In the case of a
        // successful DMA and ECC, the code that reads the ECC status
        // also performs steps 2 and 3.
        // 
        // Q:  What happens if the DMA times-out for some reason?
        // A:  Somebody may have to clean-up by using steps 2 and 3.
        //     That somebody is us.
        //

        if (    // If there was an ECC-completion expected...
                (kNandGpmiDmaWaitMask_Ecc & g_gpmiDmaInfo.u16DmaWaitMask) )
        {
            // ...then we have to clear the ECC-completion and the ECC circuit.

            // Some conditions in the ECC circuit can only be cleared
            // by resetting.  For example,
            // the _UNCORRECTABLE status bit is sticky, and the only way to
            // clear it is to soft-reset the ECC circuit.
            // This status bit is also used to generate the "uncorrectable"
            // values in the correction-count fields of the status registers
            // so those values are also affected.
            //
            // Reset the ECC circuit.
            ddi_ecc8_soft_reset();

            // It is not necessary to reset the BCH block after an "uncorrectable" error.
            // In fact, due to a 378x chip bug it is not possible to reset the
            // BCH block after it has been used to transfer data.

            // Clear the ECC-completion.
            ddi_gpmi_clear_ecc_isr_enable( );
        }

        rtStatus = ERROR_DDI_NAND_GPMI_DMA_TIMEOUT;
    }
    else
    {
        // The DMA descriptor chain was set up with the alternate meaning
        // of the BAR register.  Rather than containing an
        // address at this point, it contains a return-code that indicates whether
        // the "success" or "failure" part of the chain executed last.
        // So, here we get that return code.
        rtStatus = (RtStatus_t)BF_RDn(APBH_CHn_BAR, r32ChipDmaNumber, ADDRESS);
    }

    // Now that we are sure we the DMA is really finished or has been killed,
    // make sure we coordinate with PMI.
    
    // Disable IRQs for a little bit. We don't want to be interrupted between
    // ddi_gpmi_wait_for_pmi_event() and setting bInDmaFlag.
    saveIrqState = hw_core_EnableIrqInterrupt(false);

    // We're done with the DMA.
    g_gpmiPmiStatus.bInDmaFlag = false;

    // Now that the DMA is done, acknowledge any pending PMI pre-change events.
    ddi_gpmi_ack_pmi_event();

    // Restore IRQs.
    hw_core_EnableIrqInterrupt(saveIrqState);

#if defined(DEBUG_DMA_TOUT) && defined(ENABLE_SDRAM_DEBUG_MEM) && defined(CMP_PROFILE_ENABLE)
    {
        uint32_t    Handle;
        Handle = cmp_profile_start(DDI_NAND_GROUP, "ddi_gpmi_wait_for_dma end");
        cmp_profile_stop(Handle);
    }
#endif

    return rtStatus;

}

////////////////////////////////////////////////////////////////////////////////
// See ddi_nand_gpmi.h for documentation.
////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_gpmi_start_dma(dma_cmd_t * pDmaCmd, uint32_t dmaCommandLength, uint32_t u32NANDDeviceNum, uint16_t u16DmaWaitMask)
{
    uint32_t    physicalCommandAddress;
    reg32_t     r32ChannelMask          = (0x1 << (NAND0_APBH_CH+u32NANDDeviceNum));
    reg32_t     r32ChipDmaNumber        = (NAND0_APBH_CH+u32NANDDeviceNum);
    bool        bDmaIsRunning;
    RtStatus_t  rtStatus = SUCCESS;
    bool saveIrqState;
    
    assert(g_gpmiPmiStatus.bInDmaFlag == false);

#ifdef DEBUG_DMA_TOUT
#if defined(ENABLE_SDRAM_DEBUG_MEM) && defined(CMP_PROFILE_ENABLE)
    {
        uint32_t    Handle;
        Handle = cmp_profile_start(DDI_NAND_GROUP, "ddi_gpmi_start_dma start");
        cmp_profile_stop(Handle);
    }
#endif
    // Save the pointer to the descriptor that started this DMA.
    // It can be used in "wait DMA" to memcpy() the descriptor for debug.
    pDmaCmdTest = pDmaCmd;
    //if( u32NANDDeviceNum == 1)
    //{
    //    memcpy((void *)&testNandDmaDescriptor, pDmaCmd,sizeof(NAND_dma_read_t));
    //}
#endif

    // Save off the chip that we're watching in the DMA completion structure.
    // todo - can we watch more than 1 chip at a later time?
    g_gpmiDmaInfo.u16CurrentChip = u32NANDDeviceNum;
    
    // Set the criteria for finishing this DMA.
    g_gpmiDmaInfo.u16DmaWaitMask      = u16DmaWaitMask;
    
    // Clear the status word used to check the criteria for finishing this DMA.
    g_gpmiDmaInfo.u16DmaWaitStatus    = kNandGpmiDmaWaitMask_Nothing;

#ifdef DEBUG_DMA_TOUT
    Testing[gTestcount].uNand = u32NANDDeviceNum;
    Testing[gTestcount].Return = (int)(__builtin_return_address(0)); // Return address in the calling function.
#endif

    // Alert me if a DMA chain is currently running!!
    // Note that this checks the SEMA.PHORE register field for the DMA.
    bDmaIsRunning = ddi_gpmi_is_dma_active(u32NANDDeviceNum);

    #ifdef RTOS_THREADX
    if (bDmaIsRunning)
    {
        // Note that, in the RTOS_THREADX case, SEMA.PHORE register field
        // can easily be nonzero if the CPU is running fast.
        // (The DMA engine can trigger the ISR at the end of the DMA, before decrementing
        // the SEMA.PHORE count, thus creating a race condition that lets us find a
        // nonzero SEMA.PHORE value here.)
        //
        // We will delay a bit, and then re-check the semaphore.
        tx_thread_sleep( 1 );

        // Alert me if a DMA chain is currently running!!
        // Note that this checks the SEMA.PHORE register field for the DMA.
        bDmaIsRunning = ddi_gpmi_is_dma_active(u32NANDDeviceNum);

    } // if (bDmaIsRunning)
    #endif  // ifdef RTOS_THREADX

    if (bDmaIsRunning)
    {
#ifdef DEBUG_DMA_TOUT
        DmaStatus1 = HW_APBH_CHn_CURCMDAR_RD(NAND0_APBH_CH);
        DmaStatus2 = HW_APBH_CHn_CURCMDAR_RD(NAND0_APBH_CH + 1);
        //SystemHalt();
#endif
    
        rtStatus = ERROR_DDI_NAND_GPMI_DMA_BUSY;

#if defined(DEBUG_DMA_TOUT) && defined(ENABLE_SDRAM_DEBUG_MEM) && defined(CMP_PROFILE_ENABLE)
        {
            uint32_t    Handle;
            Handle = cmp_profile_start(DDI_NAND_GROUP, "ddi_gpmi_start_dma end (ddi_gpmi_is_dma_active)");
            cmp_profile_stop(Handle);
        }
#endif
        goto _standardExit;

    } // if (bDmaIsRunning)

    // At this point, there should be no DMA running.
    // Sanity-test to make sure the DMA channel IRQ is deasserted.
    // (Note that the optimizing compiler will probably combine the
    // body of this section with the previous section.)
    if ( 0 != (HW_APBH_CTRL1_RD() & (r32ChannelMask << BP_APBH_CTRL1_CH0_CMDCMPLT_IRQ)) )
    {
#ifdef DEBUG_DMA_TOUT
        DmaStatus1 = HW_APBH_CHn_CURCMDAR_RD(NAND0_APBH_CH);
        DmaStatus2 = HW_APBH_CHn_CURCMDAR_RD(NAND0_APBH_CH + 1);
        //SystemHalt();
#endif
    
        rtStatus = ERROR_DDI_NAND_GPMI_DMA_BUSY;

#if defined(DEBUG_DMA_TOUT) && defined(ENABLE_SDRAM_DEBUG_MEM) && defined(CMP_PROFILE_ENABLE)
        {
            uint32_t    Handle;
            Handle = cmp_profile_start(DDI_NAND_GROUP, "ddi_gpmi_start_dma end (BP_APBH_CTRL1_CH0_CMDCMPLT_IRQ)");
            cmp_profile_stop(Handle);
        }
#endif
        goto _standardExit;
    }

    // Now that we are sure we really want to start the DMA,
    // make sure we coordinate with PMI.
    
    // Disable IRQs for a little bit. We don't want to be interrupted between
    // ddi_gpmi_wait_for_pmi_event() and setting bInDmaFlag.
    saveIrqState = hw_core_EnableIrqInterrupt(false);

    // If PMI has told us that it is changing something important, we will wait
    // until that change is complete before starting any further DMAs.
    ddi_gpmi_wait_for_pmi_event();

    // Set the flag that says there is an active DMA, since we've made it past
    // all the locks that could hold us off. This flag must not be set before
    // the ddi_gpmi_wait_for_pmi_event() call above.
    g_gpmiPmiStatus.bInDmaFlag = true;
    
    // Restore IRQs.
    hw_core_EnableIrqInterrupt(saveIrqState);

    // Get the physical address of the DMA chain.
    physicalCommandAddress = (uint32_t)nand_virtual_to_physical(pDmaCmd);

    // Flush the data cache. We don't need to invalidate since the hardware is only reading
    // the DMA chain, not writing to it. If the caller set the length to 0, then they don't
    // want us to flush the cache, probably because they just flushed the entire cache already.
    if (dmaCommandLength > 0)
    {
        hw_core_clean_DCache_MVA_BySize((uint32_t)pDmaCmd, dmaCommandLength);
    }

    // Initialize DMA by setting up NextCMD field
    HW_APBH_CHn_NXTCMDAR_WR(r32ChipDmaNumber, (reg32_t)physicalCommandAddress);

    // Start DMA by incrementing the semaphore.
    BW_APBH_CHn_SEMA_INCREMENT_SEMA(r32ChipDmaNumber, 1);

    // Record the time that I started the transaction
    // Used in the NAND_HAL_Dma_Status function below and the ddi_gpmi_wait_for_dma
    // function above to determine timeouts.
    g_gpmiDmaInfo.uStartDMATime = hw_profile_GetMicroseconds();

_standardExit:
#if defined(DEBUG_DMA_TOUT) && defined(ENABLE_SDRAM_DEBUG_MEM) && defined(CMP_PROFILE_ENABLE)
    {
        uint32_t    Handle;
        Handle = cmp_profile_start(DDI_NAND_GROUP, "ddi_gpmi_start_dma end");
        cmp_profile_stop(Handle);
    }
#endif

    return rtStatus;
}

////////////////////////////////////////////////////////////////////////////////
// See ddi_nand_gpmi.h for documentation.
////////////////////////////////////////////////////////////////////////////////
bool ddi_gpmi_is_dma_active(uint32_t u32NANDDeviceNum)
{
    uint32_t    u32Sema;
    reg32_t     r32ChipDmaNumber    = (NAND0_APBH_CH+u32NANDDeviceNum);
    uint32_t    u32Run;

    u32Sema = HW_APBH_CHn_SEMA_RD(r32ChipDmaNumber) & BM_APBH_CHn_SEMA_PHORE;

    u32Run = BF_RD(GPMI_CTRL0, RUN);

    // A nonzero value for either of these means a DMA is running.
    return ( u32Sema | u32Run );
}

// eof nand_hal_dma_util.c
//! @}
