/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

//! \file    ddi_nand_gpmi_dma_isr.cpp
//! \brief   Routines for handling the DMA completion ISR for the NANDs.
//!
//! This file contains the NAND HAL DMA completion Interrupt Subroutine.

#include "types.h"
#include "ddi_nand_gpmi_internal.h"
#include "registers/regsapbh.h"
#include "components/profile/cmp_profile.h"
#include "drivers/ddi_subgroups.h"
#include "os/thi/os_thi_api.h"
#include "os/dmi/os_dmi_api.h"
#include "hw/icoll/hw_icoll.h"
#include "registers/hw_irq.h"
#include "drivers/icoll/ddi_icoll.h"

#ifdef DEBUG_DMA_TOUT
extern uint32_t DmaStatus1, DmaStatus2;
#endif

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define ENABLEVECTOR_BEFORE  (0)

///////////////////////////////////////////////////////////////////////////////
// Prototypes
///////////////////////////////////////////////////////////////////////////////

void ddi_nand_GpmiDmaIsrHandler(void *pParam);
void ddi_nand_BchIsrHandler(void *pParam);

///////////////////////////////////////////////////////////////////////////////
// Code
///////////////////////////////////////////////////////////////////////////////

inline void ddi_gpmi_clear_dma_command_complete_irq(int chip)
{
    // Clear the command-complete IRQ for this chip...
    HW_APBH_CTRL1_CLR((BM_APBH_CTRL1_CH4_CMDCMPLT_IRQ << chip));
    
    // ...and do a dummy read-back to make sure the value has been written.
    volatile uint32_t u32Dummy = HW_APBH_CTRL1_RD();
}

inline void ddi_gpmi_set_dma_irq_enabled(int chip)
{
    HW_APBH_CTRL1_SET(BM_APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN << chip);
}

inline void ddi_gpmi_clear_bch_ctrl_complete_irq()
{
    // Clear the ECC-complete IRQ...
    HW_BCH_CTRL_CLR(BM_BCH_CTRL_COMPLETE_IRQ);
    
    // ...and do a dummy read-back to make sure the value has been written.
    volatile uint32_t u32Dummy = HW_BCH_CTRL_RD();
}

inline void ddi_gpmi_set_bch_irq_enabled()
{
    BF_SET(BCH_CTRL, COMPLETE_IRQ_EN);
}

RtStatus_t ddi_gpmi_init_interrupts(uint32_t u32ChipNumber)
{
    UINT retCode;

    // Only need to register the handler for the first chip
    // since the same DMA interrupt is used for all channels.
    if (u32ChipNumber == 0)
    {
        // Create the DMA complete Semaphore.
        retCode = tx_semaphore_create(&g_gpmiDmaInfo.pSemaphore, "GPMI:DMA", 0);
        if (TX_SUCCESS != retCode )
        {
            SystemHalt();
        }

#ifdef RTOS_THREADX

        // setup and enable the isr for the BCH IRQ
        ddi_icoll_RegisterIrqHandler(
            VECTOR_IRQ_BCH,
            ddi_nand_BchIsrHandler,
            &g_gpmiDmaInfo,
            IRQ_HANDLER_DIRECT,
            ICOLL_PRIORITY_LEVEL_0);

        // setup and enable the isr for the GPMI DMA IRQ
        ddi_icoll_RegisterIrqHandler(
            VECTOR_IRQ_GPMI_DMA,
            ddi_nand_GpmiDmaIsrHandler,
            &g_gpmiDmaInfo,
            IRQ_HANDLER_DIRECT,
            ICOLL_PRIORITY_LEVEL_0);

#if ENABLEVECTOR_BEFORE
        hw_icoll_EnableVector(VECTOR_IRQ_GPMI_DMA, true);
        hw_icoll_EnableVector(VECTOR_IRQ_BCH, true);
#endif
#endif // RTOS_THREADX

    }   // if (u32ChipNumber == 0)

    // clear and enable the APBH DMA IRQs
    ddi_gpmi_clear_dma_command_complete_irq(u32ChipNumber);
    ddi_gpmi_set_dma_irq_enabled(u32ChipNumber);

    // clear and enable the ECC IRQs
    ddi_gpmi_clear_bch_ctrl_complete_irq();
    ddi_gpmi_set_bch_irq_enabled();

#if defined(RTOS_THREADX) && !ENABLEVECTOR_BEFORE
    hw_icoll_EnableVector(VECTOR_IRQ_GPMI_DMA, true);
    hw_icoll_EnableVector(VECTOR_IRQ_BCH, true);
#endif // defined(RTOS_THREADX) && !ENABLEVECTOR_BEFORE

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief      ISR for the GPMI dma complete IRQ.
//!
//! \fntype     Interrupt Service
//!
//! Signals GPMI dma completed by signaling the NAND semaphore.
//! This is dependent on the state of pParam->u16DmaWaitMask.
//!
//! Then clears and enables the interrupt.
//!
//! \param[in]  pParam  Pointer to GpmiDmaInfo_t.
////////////////////////////////////////////////////////////////////////////////
void ddi_nand_GpmiDmaIsrHandler(void *pParam)
{
    GpmiDmaInfo_t * pWaitStruct = (GpmiDmaInfo_t *)pParam;

    //
    // Aside: We cannot check the SEMA.PHORE register here.
    // The DMA engine in the 37xx can trigger the ISR at the end of the DMA, before decrementing
    // the SEMA.PHORE count, thus creating a race condition that lets us find a
    // nonzero SEMA.PHORE value here.
    //

    bool bSomeError = FALSE;
    // Check for an error on the DMA channel assigned to this chip
    if (HW_APBH_CTRL2_RD() & (BM_APBH_CTRL2_CH4_ERROR_IRQ << (pWaitStruct->u16CurrentChip)) != 0)
    {
        // If an error occured, clear it.  The ddi_gpmi_wait_for_dma function
        // will reset the channel.
        HW_APBH_CTRL2_CLR(BP_APBH_CTRL2_CH4_ERROR_IRQ << pWaitStruct->u16CurrentChip);
        bSomeError = TRUE;
    }

    // Note that this ISR has run.
    pWaitStruct->u16DmaWaitStatus |= kNandGpmiDmaWaitMask_GpmiDma;

    // See if all criteria have been met, to declare the DMA finished.
    if (pWaitStruct->u16DmaWaitMask == pWaitStruct->u16DmaWaitStatus)
    {

        // There is code waiting for the completion of ECC.
        if ( !bSomeError )
        {
            // If there was no error, then signal the completion.
            tx_semaphore_put(&pWaitStruct->pSemaphore);
        }
    }

    // clear the APBH dma IRQ and re-enable the associated vector in icoll.
    ddi_gpmi_clear_dma_isr_enable( pWaitStruct->u16CurrentChip );
}


void ddi_gpmi_clear_dma_isr_enable(uint16_t u16CurrentChip)
{
    // clear the APBH dma IRQ and re-enable the associated vector in icoll.

#if ENABLEVECTOR_BEFORE
    hw_icoll_EnableVector(VECTOR_IRQ_GPMI_DMA, true);
#endif

    ddi_gpmi_clear_dma_command_complete_irq(u16CurrentChip);

#if !ENABLEVECTOR_BEFORE
    hw_icoll_EnableVector(VECTOR_IRQ_GPMI_DMA, true);
#endif
}

void ddi_gpmi_clear_ecc_isr_enable(void)
{
    // Clear the ECC Complete IRQ and re-enable the associated vector in icoll.

#if ENABLEVECTOR_BEFORE
    hw_icoll_EnableVector(VECTOR_IRQ_BCH, true);
#endif
    
    ddi_gpmi_clear_bch_ctrl_complete_irq();
    ddi_gpmi_set_bch_irq_enabled();

#if !ENABLEVECTOR_BEFORE
    hw_icoll_EnableVector(VECTOR_IRQ_BCH, true);
#endif
}

////////////////////////////////////////////////////////////////////////////////
//! \brief      ISR for the APBH BCH-complete IRQ.
//!
//! \fntype     Interrupt Service
//!
//! Possibly signals APBH ECC completed by signaling the NAND semaphore.
//! This is dependent on the state of pParam->u16DmaWaitMask.
//!
//! Then clears and enables the interrupt.
//!
//! \param[in]  pParam  Pointer to GpmiDmaInfo_t.
////////////////////////////////////////////////////////////////////////////////
void ddi_nand_BchIsrHandler(void *pParam)
{
    GpmiDmaInfo_t * pWaitStruct = (GpmiDmaInfo_t *)pParam;

    // Note that this ISR has run.
    pWaitStruct->u16DmaWaitStatus |= kNandGpmiDmaWaitMask_Ecc;

    // See if all criteria have been met, to declare the DMA finished.
    if (pWaitStruct->u16DmaWaitMask == pWaitStruct->u16DmaWaitStatus)
    {
        bool    bSomeError = FALSE;

        // See if this interrupt came from a bus-error on APBH,
        // possibly because the address of the transaction was invalid.
        if (BF_RD(BCH_CTRL, BM_ERROR_IRQ))
        {
	        // If an error occured, clear it.  The ddi_gpmi_wait_for_dma function
	        // will reset the channel.
            HW_BCH_CTRL_CLR(BM_BCH_CTRL_BM_ERROR_IRQ);
            bSomeError = TRUE;
        }

	    // Check for an error on the DMA channel assigned to
	    // this chip
	    if (HW_APBH_CTRL2_RD() & (BM_APBH_CTRL2_CH4_ERROR_IRQ << (pWaitStruct->u16CurrentChip)) != 0)
	    {
		    // If an error occured, clear it.  The ddi_gpmi_wait_for_dma function
		    // will reset the channel.
	        HW_APBH_CTRL2_CLR(BP_APBH_CTRL2_CH4_ERROR_IRQ << pWaitStruct->u16CurrentChip);

            bSomeError = TRUE;
 	    }

        // There is code waiting for the completion of ECC.
        if ( !bSomeError )
        {
            // If there was no error, then signal the completion.
            tx_semaphore_put(&pWaitStruct->pSemaphore);
        }
    }

    // At this point we DO NOT
    //  * Clear the ECC IRQ
    //  * Re-enable the associated vector in icoll.
    // Reason: The ECC STATUS must be preserved until the client
    // application can read it, to see the ECC results.
    // It is the client application's responsibility to
    // perform the aforementioned actions after the ECC STATUS
    // has been read.

}

// EOF
//! @}
