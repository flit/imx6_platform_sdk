/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @file gpmi.c
 * @brief The driver source for the GPMI controller.
 *
 * @ingroup diag_nand
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hardware.h"
#include "nand_devices.h"
#include "gpmi.h"
#include "regsapbh.h"
#include "regsgpmi.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! Controls whether GPMI timing values should be printed to TSS when they are set.
//! Set to 1 to print timings.
//! This may need an increased stack for the PMI task due to an issue in tss_logtext_Flush(0)
#define GPMI_PRINT_TIMINGS 0 // SEE NOTE ON PREVIOUS LINE about stack issues

#define MAX_DATA_SETUP_CYCLES (BM_GPMI_TIMING0_DATA_SETUP >> BP_GPMI_TIMING0_DATA_SETUP)

#define MAX_DATA_SAMPLE_DELAY_CYCLES            (uint32_t)(BM_GPMI_CTRL1_RDN_DELAY >> BP_GPMI_CTRL1_RDN_DELAY)
#define GPMI_DELAY_SHIFT                        (3)         // Right shift value to get the fractional GPMI time for data delay
#define GPMI_MAX_DLL_PERIOD_NS                  (32)        // Max GPMI clock Period that the GPMI DLL works for
#define GPMI_DLL_HALF_THRESHOLD_PERIOD_NS       (16)        // Threshold for GPMI clock Period that above thise requires a divide by two for the DLL 
#define GPMI_WAIT_CYCLES_AFTER_DLL_ENABLE       (64)        // Number of GPMI clock cycles to wait for use of GPMI after DLL enable 

#define GPMI_DATA_SETUP_NS                      (0)         // Time in nanoSeconds required for GPMI data read internal setup

#define GPMI_MAX_HARDWARE_DELAY_NS              (uint32_t)(16)        // Time in nanoSeconds required for GPMI data read internal setup

// Max data delay possible for the GPMI.  Use the min 
// of the time (16 nS) or what will fit in the register
// If the GPMI clock period is greater than 
// GPMI_MAX_DLL_PERIOD_NS then can't use the delay.
#define GPMI_GET_MAX_DELAY_NS(x)                ((x < GPMI_MAX_DLL_PERIOD_NS) ? \
                                                (MIN( GPMI_MAX_HARDWARE_DELAY_NS, ((MAX_DATA_SAMPLE_DELAY_CYCLES * x) / u32GpmiDelayFraction))) : \
                                                0)

///////////////////////////////////////////////////////////////////////////////
//     GPMI Timing
//////////////////////////////////////////////////////////////////////////////

//! Frequency in kHz for GPMI_CLK. PMI will do its best to give us
//! this frequency when the PLL is enabled.
#define GPMI_CLK_PLL_ON_FREQUENCY_kHZ (96000)

//! Frequency to use for GPMI_CLK when the PLL is disabled.
#define GPMI_CLK_PLL_OFF_FREQUENCY_kHZ (24000)

// Should only need 10msec (Program/Erase), and reads shouldn't be anywhere near this long..
#define FLASH_BUSY_TIMEOUT          10000  //!< Busy Timeout time in microsec. (10msec)

//! 24MHz / (TDS+TDH) => 6MHz NAND strobe, TAS=0, TDS=45, TDH=30 nsec
//! Use the worst case conditions for all supported NANDs by default.
#define NAND_GPMI_TIMING0(AddSetup, DataSetup, DataHold) \
           (BF_GPMI_TIMING0_ADDRESS_SETUP(AddSetup) | \
            BF_GPMI_TIMING0_DATA_HOLD(DataHold) | \
            BF_GPMI_TIMING0_DATA_SETUP(DataSetup))

#define DDI_NAND_HAL_GPMI_SOFT_RESET_LATENCY  (2)

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

uint32_t rom_nand_hal_GpmiInitializeDataSampleDelay(uint32_t u32GpmiPeriod_ns, bool bWriteToTheDevice);
void rom_nand_hal_GpmiSetAndEnableDataSampleDelay(uint32_t u32DelayCycles, uint32_t u32GpmiPeriod_ns);

void ddi_nand_hal_GpmiSetNandTiming(const NAND_Timing2_struct_t * pNAND_Timing2_struct, 
                                    uint32_t u32GpmiPeriod_ns, 
                                    uint32_t u32PropDelayMin_ns, 
                                    uint32_t u32PropDelayMax_ns,
                                    bool bWriteToTheDevice);

uint32_t rom_nand_hal_FindGpmiCyclesCeiling(uint64_t u32NandTime_ns, uint32_t u32GpmiPeriod_ns, uint32_t u32MinVal = 0);
uint32_t rom_nand_hal_FindGpmiCyclesRounded(uint64_t u32NandTime_ns, uint32_t u32GpmiPeriod_ns);

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

//! Current GPMI timings.
NAND_Timing2_struct_t   g_zNandTiming;

//! Minimum propagation delay of GPMI signals to and from the NAND.
uint32_t                g_u32GPMIPropDelayMin_ns=5;

//! Maximum propagation delay of GPMI signals to and from the NAND.
uint32_t                g_u32GPMIPropDelayMax_ns=9;

GpmiDmaInfo_t g_gpmiDmaInfo;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#if GPMI_PRINT_TIMINGS

static void _print_dynamic_timing_summary(
    uint32_t u32GpmiPeriod_ns,
    uint32_t u32GpmiDelayFraction,
    uint32_t i32tEYE,
    uint32_t i32DelayTime_ns,
    uint32_t u32GpmiMaxDelay_ns,
    uint32_t u32DataSetupCycles,
    uint32_t u32DataSetup_ns)
{
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  GpmiPeriod = %d ns\n", u32GpmiPeriod_ns);
    tss_logtext_Flush(0);
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  GpmiDelayFraction = %d\n", u32GpmiDelayFraction);
    tss_logtext_Flush(0);
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  tEYE = %d ns\n", i32tEYE);
    tss_logtext_Flush(0);
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  DelayTime = %d ns\n", i32DelayTime_ns);
    tss_logtext_Flush(0);
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  GpmiMaxDelay = %d ns\n", u32GpmiMaxDelay_ns);
    tss_logtext_Flush(0);
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  DataSetupCycles = %d cycles\n", u32DataSetupCycles);
    tss_logtext_Flush(0);
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "  DataSetup = %d ns\n", u32DataSetup_ns);
    tss_logtext_Flush(0);

    return;    
}
#endif  //GPMI_PRINT_TIMINGS

void gpmi_init_apbh()
{
    // APBH - disable reset, enable clock
    // bring APBH out of reset
    HW_APBH_CTRL0_CLR(BM_APBH_CTRL0_SFTRST);
    // Poll until the SFTRST is truly deasserted.
    while (HW_APBH_CTRL0.B.SFTRST);

    HW_APBH_CTRL0_CLR(BM_APBH_CTRL0_CLKGATE);
    // Poll until the CLKGATE is truly deasserted.
    while (HW_APBH_CTRL0.B.CLKGATE);
}

void gpmi_init_dma_channel(int u32ChipNumber)
{
    reg32_t r32ChipDmaNumber = NAND0_APBH_CH + u32ChipNumber;

    // Reset dma channel
    BW_APBH_CTRL0_RESET_CHANNEL(0x1 << r32ChipDmaNumber);
    
    // Wait for the reset to complete
    while ( HW_APBH_CTRL0.B.RESET_CHANNEL & (0x1 << r32ChipDmaNumber) );
    
    // Clear IRQ
    HW_APBH_CTRL1_CLR(0x1 << r32ChipDmaNumber);
}

void gpmi_configure_gpmi()
{
    // Put GPMI in NAND mode, disable DEVICE reset, and make certain
    // polarity is active high, sample on GPMI clock
    HW_GPMI_CTRL1_WR(
        BF_GPMI_CTRL1_DEV_RESET(BV_GPMI_CTRL1_DEV_RESET__DISABLED) |
        BF_GPMI_CTRL1_ATA_IRQRDY_POLARITY(BV_GPMI_CTRL1_ATA_IRQRDY_POLARITY__ACTIVEHIGH) |
        BW_GPMI_CTRL1_GPMI_MODE(BV_GPMI_CTRL1_GPMI_MODE__NAND));
}


////////////////////////////////////////////////////////////////////////////////
//! \brief GPMI fuction to delay by given number of microSeconds
//!
//! Delay the given number of microSeconds
//!
//! \return none
//!
//! \internal
//! To view function details, see rom_nand_hal_gpmi.c.
////////////////////////////////////////////////////////////////////////////////
void NandDelayMicroSeconds(uint32_t delayMicroSeconds)
{
    uint32_t startTime = hw_profile_GetMicroseconds();

    // account for being inbetween counts on the timer 
    delayMicroSeconds++;

    // Make sure any changes in the future are safe for timer wrap-around...
    while ((hw_profile_GetMicroseconds() - startTime) < delayMicroSeconds)
    {
    }
}

__INIT_TEXT RtStatus_t gpmi_init(unsigned chipSelectCount, uint32_t minDelay, uint32_t maxDelay)

// bool bUse16BitData,
//                                    uint32_t u32ChipNumber,
//                                    bool bUseAlternateChipEnables,
//                                    bool bUse1_8V_Drive,
//                                    bool bEnableInternalPullups)
{
    RtStatus_t status;

    // Can't boot from NAND if GPMI block is not present
    if (!(HW_GPMI_STAT_RD() & BM_GPMI_STAT_PRESENT))
    {
        return ERROR_DDI_NAND_GPMI_NOT_PRESENT;
    }

    // Init APBH DMA controller.
    gpmi_init_apbh();
    gpmi_init_dma_channel(u32ChipNumber);
    
    // Init interrupts.
    gpmi_init_interrupts(u32ChipNumber);

    // CLKGATE = 0 and DIV = 1 (we're assuming a 24MHz XTAL for this).
    // HW_CLKCTRL_GPMICLKCTRL_WR(0x01);
    // Clock dividers are now set globally for PLL bypass in startup / setup_default_clocks()
    // The divider may also be changed by drivers (like USB) that turn on the PLL
    // HW_CLKCTRL_GPMICLKCTRL_CLR(BM_CLKCTRL_GPMICLKCTRL_CLKGATE); // ungate

    // Ungate GPMICLK. Because the gate is upstream of the divider, special
    // care must be taken to make sure the divider is set correctly. Any
    // change to HW_CLKCTRL_GPMICLKCTRL.B.DIV while the clock is gated is
    // saved to the register, but *NOT* transferred to the actual divider.
    // Clearing HW_CLKCTRL_GPMICLKCTRL.B.WAIT_PLL_LOCK serves two purposes.
    // First, it forces the divider to update because it writes the control
    // register while the clock is not gated. Second, it makes sure the update
    // completes immediately by removing the PLL locked qualifier.
    HW_CLKCTRL_GPMI.B.CLKGATE = 0;

    // Set GPMI_CLK frequency.
    status = ddi_clocks_GpmiClkInit(GPMI_CLK_PLL_ON_FREQUENCY_kHZ, GPMI_CLK_PLL_OFF_FREQUENCY_kHZ);
    if (status != SUCCESS)
    {
        return status;
    }

    // Soft-reset GPMI
    gpmi_soft_reset();
    
    // Init ECC blocks.
    if (0 == u32ChipNumber)
    {
        bch_ecc_init();
    }

    g_u32GPMIPropDelayMin_ns = minDelay;
    g_u32GPMIPropDelayMax_ns = maxDelay;

    // Use the failsafe timings and default 24MHz clock
    NAND_Timing2_struct_t safeTimings;
    gpmi_get_safe_timings(&safeTimings);
    ddi_nand_hal_GpmiSetNandTiming(&safeTimings, 0, g_u32GPMIPropDelayMin_ns, g_u32GPMIPropDelayMax_ns, true /* bWriteToTheDevice */);
    
    // Set the timeout for the wait for ready mode.
    gpmi_set_busy_timeout(FLASH_BUSY_TIMEOUT);

    {
        // Convert zero-based "chip number" into the quantity of NANDs to be used on the GPMI.
        uint32_t u32NumberOfNANDs = u32ChipNumber + 1;

        // Configure all of the pads that will be used for GPMI.
        ddi_nand_hal_ConfigurePinmux(bUse16BitData, u32NumberOfNANDs,
                                     bUseAlternateChipEnables, bUse1_8V_Drive, bEnableInternalPullups);
    }

    // Put GPMI in NAND mode, disable DEVICE reset, and make certain
    // polarity is active high, sample on GPMI clock
    gpmi_configure_gpmi();

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief GPMI Init Data Sample Delay.
//!
//! This function determines the fraction of GPMI period for the data sample 
//! delay period per delay count.  The data sample delay period per cycle is a 
//! fraction of the GPMI clock.  The fraction amount is a function of chip type 
//! and GPMI clock speed.  
//!
//! \param[in]  u32GpmiPeriod_ns GPMI Clock Period in nsec.
//! \param[in]  bWriteToTheDevice   A boolean that indicates whether this function should
//!                                 actually write any values to registers.
//!
//! \return Fraction (ie amount to divide by) of the GPMI period for a delay period
//!
//! \internal
//! To view function details, see rom_nand_hal_gpmi.c.
////////////////////////////////////////////////////////////////////////////////
uint32_t rom_nand_hal_GpmiInitializeDataSampleDelay(uint32_t u32GpmiPeriod_ns, bool bWriteToTheDevice)
{
    uint32_t retVal = GPMI_DELAY_SHIFT;

    if ( bWriteToTheDevice )
    {
        BW_GPMI_CTRL1_DLL_ENABLE(0);                        // Init to a known value
        BW_GPMI_CTRL1_RDN_DELAY(0);                         // Init to a known value
    }

    if (u32GpmiPeriod_ns > GPMI_DLL_HALF_THRESHOLD_PERIOD_NS )
    {
        // the GPMI clock period is high enough that the DLL
        // requires a divide by two
        if ( bWriteToTheDevice )
        {
            BW_GPMI_CTRL1_HALF_PERIOD(1);
        }
        retVal++;                                       // Account for the half period, add 1 to shift (or / by 2)
    }

    return (1 << retVal);
}



////////////////////////////////////////////////////////////////////////////////
//! \brief GPMI Set And Start Data Sample Delay.
//!
//! This function sets the NAND Timing register which controls the delay 
//! in the data read sampling.  It then set the delay hardware to be active
//! (if needed by hardware)
//!
//! \param[in]  u32DelayCycles Delay count to put to register
//!
//! \return None
//!
//! \internal
//! To view function details, see rom_nand_hal_gpmi.c.
////////////////////////////////////////////////////////////////////////////////
void rom_nand_hal_GpmiSetAndEnableDataSampleDelay(uint32_t u32DelayCycles, uint32_t u32GpmiPeriod_ns)
{
    // !!! DLL_ENABLE must be set to zero when setting RDN_DELAY or HALF_PERIOD!!!
    BW_GPMI_CTRL1_DLL_ENABLE(0);

    if ((u32DelayCycles == 0) || (u32GpmiPeriod_ns > GPMI_MAX_DLL_PERIOD_NS) )
    {
        // If no delay is desired, or if GPMI clock period is out of supported 
        // range, then don't enable the delay

        //BW_GPMI_CTRL1_DLL_ENABLE(0);    // This is already done several lines up
        BW_GPMI_CTRL1_RDN_DELAY(0);
        BW_GPMI_CTRL1_HALF_PERIOD(0);
    }
    else
    {
        // Set the delay and needed registers to run.  GPMI_CTRL1_HALF_PERIOD is 
        // assumed to have already been set properly

        uint32_t waitTimeNeeded;

        BW_GPMI_CTRL1_RDN_DELAY(u32DelayCycles);
        BW_GPMI_CTRL1_DLL_ENABLE(1);

        // After the GPMI DLL has been enable it is reqiured to wait for 
        // GPMI_WAIT_CYCLES_AFTER_DLL_ENABLE number of GPMI clock cycles before 
        // using the GPMI interface.

        // calculate out the wait time and convert from nanoSeconds to microSeconds
        waitTimeNeeded = (u32GpmiPeriod_ns * GPMI_WAIT_CYCLES_AFTER_DLL_ENABLE) / 1000;

        // wait until the required time for DLL hardware startup has passed.
        NandDelayMicroSeconds(waitTimeNeeded);

    }
}


////////////////////////////////////////////////////////////////////////////////
//! \brief Find NAND Timing.
//!
//! This function determines the NAND Timing parameter which is given in
//! units of GPMI cycles.  The GPMI period is used to determine how many
//! cycles fit into the NAND parameter.
//!
//! \param[in]  u32NandTime_ns      The quantity in nsec to be converted to units of
//!                                 GPMI cycles.
//! \param[in]  u32GpmiPeriod_ns    GPMI Clock Period in nsec.
//!
//! \return Number of GPMI cycles required for this time.
//!
//! \internal
//! To view function details, see rom_nand_hal_gpmi.c.
////////////////////////////////////////////////////////////////////////////////
uint32_t rom_nand_hal_FindGpmiCyclesCeiling(uint64_t u32NandTime_ns, uint32_t u32GpmiPeriod_ns, uint32_t u32MinVal)
{
    uint32_t retVal = ((u32NandTime_ns + (u32GpmiPeriod_ns - 1)) / u32GpmiPeriod_ns);
    return std::max(retVal, u32MinVal);
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Find a NAND timing value that is rounded as appropriate.
//!
//! This function determines the NAND Timing parameter which is given in
//! units of GPMI cycles.  The GPMI period is used to determine how many
//! cycles fit into the NAND parameter, rounding up or down as appropriate.
//!
//! \param[in]  u32NandTime_ns      The quantity in nsec to be converted to units of
//!                                 GPMI cycles.
//! \param[in]  u32GpmiPeriod_ns    GPMI Clock Period in nsec.
//!
//! \return Number of GPMI cycles required for this time.
//!
//! \internal
//! To view function details, see rom_nand_hal_gpmi.c.
////////////////////////////////////////////////////////////////////////////////
uint32_t rom_nand_hal_FindGpmiCyclesRounded(uint64_t u32NandTime_ns, uint32_t u32GpmiPeriod_ns)
{
    return (u32NandTime_ns + (u32GpmiPeriod_ns>>1)) / u32GpmiPeriod_ns;
}

#ifdef __cplusplus
extern "C" {
#endif
////////////////////////////////////////////////////////////////////////////////
//! \brief Compute and setup the NAND clocks.
//!
//! This function sets the GPMI NAND timing based upon the desired NAND timings that
//! are passed in. If the GPMI clock period is non-zero it is used in the
//! calculation of the new register values. If zero is passed instead, the
//! current GPMI_CLK frequency is obtained and used to calculate the period
//! in nanoseconds.
//!
//! \param[in]  pNewNANDTiming  Pointer to a nand-timing Structure with Address Setup, Data Setup and Hold, etc.
//!                             This structure must be one of those that contains an eState element,
//!                             so this function can tell how to crack it and process it.
//! \param[in]  u32GpmiPeriod_ns GPMI Clock Period in nsec. May be zero, in
//!                             which case the actual current GPMI_CLK period is used.
//! \param[in] u32PropDelayMin_ns Minimum propagation delay in nanoseconds.
//! \param[in] u32PropDelayMax_ns Maximum propagation delay in nanoseconds.
//! \param[in]  bWriteToTheDevice   A boolean that indicates whether this function should
//!                                 actually write any values to registers.
//!
////////////////////////////////////////////////////////////////////////////////
void nand_hal_GpmiSetNandTiming(const NAND_Timing2_struct_t * pNAND_Timing2_struct, 
                                    uint32_t u32GpmiPeriod_ns, 
                                    uint32_t u32PropDelayMin_ns, 
                                    uint32_t u32PropDelayMax_ns,
                                    bool bWriteToTheDevice)
{
    uint32_t u32GpmiDelayFraction;
    uint32_t u32GpmiMaxDelay_ns;
    uint32_t u32AddressSetupCycles;
    uint32_t u32DataSetupCycles;
    uint32_t u32DataHoldCycles;
    uint32_t u32DataSampleDelayCycles;
    uint32_t u32DataSetup_ns;
    int32_t  i32tEYE;
    int32_t  i32DelayTime_ns;
    #if GPMI_PRINT_TIMINGS
    char     bPrintInterimTimings = false;
    #endif

    if ( NULL == pNAND_Timing2_struct ) return;

    // If u32GpmiPeriod is passed in as 0, we get the current GPMI_CLK frequency
    // and compute the period in ns.
    if (u32GpmiPeriod_ns == 0)
    {
        uint32_t freq_kHz = ddi_clocks_GetGpmiClkInit();
        u32GpmiPeriod_ns = 1000000 / freq_kHz;
    }

    u32GpmiDelayFraction = rom_nand_hal_GpmiInitializeDataSampleDelay(u32GpmiPeriod_ns, bWriteToTheDevice);

    u32GpmiMaxDelay_ns = GPMI_GET_MAX_DELAY_NS(u32GpmiPeriod_ns);


#if GPMI_PRINT_TIMINGS
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "NAND GPMI timings:\n");
    tss_logtext_Flush(0);
#endif

    /* *******************************************************************
        Process the given AddressSetup, DataSetup, and DataHold
        parameters
    ******************************************************************* */

    // The chip hardware quantizes the setup and hold parameters to intervals of
    // the GPMI clock period.
    // Quantize the setup and hold parameters to the next-highest GPMI clock period to
    // make sure we use at least the requested times.
    //
    // For DataSetup and DataHold, the chip interprets a value of zero as the largest
    // amount of delay supported.  This is not what's intended by a zero
    // in the input parameter, so we modify the zero input parameter to
    // the smallest supported value.

    u32AddressSetupCycles = rom_nand_hal_FindGpmiCyclesCeiling(pNAND_Timing2_struct->u8AddressSetup, u32GpmiPeriod_ns, 0);
    u32DataSetupCycles    = rom_nand_hal_FindGpmiCyclesCeiling(pNAND_Timing2_struct->u8DataSetup, u32GpmiPeriod_ns, 1);
    u32DataHoldCycles     = rom_nand_hal_FindGpmiCyclesCeiling(pNAND_Timing2_struct->u8DataHold, u32GpmiPeriod_ns, 1);


    switch ( pNAND_Timing2_struct->eState )
    {
        case e_NAND_Timing_State_STATIC_DSAMPLE_TIME:
        {
            // Get delay time and include required chip read setup time
            i32DelayTime_ns = pNAND_Timing2_struct->u8DSAMPLE_TIME + GPMI_DATA_SETUP_NS;

            // Extend the Data Setup time as needed to reduce delay time below 
            // the max supported by hardware.  Also keep DataSetup in allowable range
            while ((i32DelayTime_ns > u32GpmiMaxDelay_ns) && (u32DataSetupCycles  < MAX_DATA_SETUP_CYCLES))
            {
                u32DataSetupCycles++;
                i32DelayTime_ns -= u32GpmiPeriod_ns;
                if (i32DelayTime_ns < 0)
                {
                    i32DelayTime_ns = 0;
                }
            }
            
            u32DataSampleDelayCycles = std::min( rom_nand_hal_FindGpmiCyclesCeiling( (u32GpmiDelayFraction * i32DelayTime_ns), u32GpmiPeriod_ns, 0), MAX_DATA_SAMPLE_DELAY_CYCLES);

#if GPMI_PRINT_TIMINGS
            tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "(--static--)\n");
            tss_logtext_Flush(0);
#endif
            break;
        } // case e_NAND_Timing_State_STATIC_DSAMPLE_TIME:

        case e_NAND_Timing_State_DYNAMIC_DSAMPLE_TIME:
        {


            // Compute the times associated with the quantized number of GPMI cycles.
            u32DataSetup_ns = u32GpmiPeriod_ns * u32DataSetupCycles;

            // This accounts for chip specific GPMI read setup time on the data sample 
            // circuit.  See 378x datasheet "14.3.4. High-Speed NAND Timing"
            u32PropDelayMax_ns += GPMI_DATA_SETUP_NS;

         /* *******************************************************************
                Compute tEYE, the width of the data eye when reading from the NAND.
            ******************************************************************* */

            // Note that we use the quantized versions of setup and hold, because the chip
            // uses these quantized values, and these timings create the eye.
            //
            // end of the eye = u32PropDelayMin_ns + pNAND_Timing2_struct->u8RHOH + u32DataSetup_ns
            // start of the eye = u32PropDelayMax_ns + pNAND_Timing2_struct->u8REA
            i32tEYE = ( (int)u32PropDelayMin_ns + (int)pNAND_Timing2_struct->u8RHOH + (int)u32DataSetup_ns ) - ( (int)u32PropDelayMax_ns + (int)pNAND_Timing2_struct->u8REA );


            // The eye has to be open.  Constrain tEYE to be greater than zero
            // and the number of DataSetup cycles to fit in the timing register.
            while ( (i32tEYE <= 0) && (u32DataSetupCycles  < MAX_DATA_SETUP_CYCLES) )
            {
                // The eye is not open.  An increase in data-setup time 
                // causes a coresponding increase to size of the eye.
                u32DataSetupCycles++;                               // Give an additional DataSetup cycle
                u32DataSetup_ns += u32GpmiPeriod_ns;                // Keep DataSetup time in step with cycles
                i32tEYE += u32GpmiPeriod_ns;                        // And adjust the tEYE accordingly

            } // while ( i32tEYE


         /* *******************************************************************
                Compute the ideal point at which to sample the data
                at the center of tEYE.
            ******************************************************************* */

            // Find the delay to get the center in time-units.
            // Delay for center of the eye = ((end of the eye + start of the eye) / 2) - DataSetup
            // This simplifies to the following:
            i32DelayTime_ns = ( (int)u32PropDelayMax_ns + (int)pNAND_Timing2_struct->u8REA + (int)u32PropDelayMin_ns + (int)pNAND_Timing2_struct->u8RHOH - (int)u32DataSetup_ns ) >> 1;

            // The chip can't accomodate a negative parameter for the sample point.
            if ( i32DelayTime_ns < 0 ) i32DelayTime_ns = 0;

            //  Make sure the required DelayTime does not exceed the max allowed value.
            //  Also make sure the quantized DelayTime (at u32DataSampleDelayCycles) is 
            //  within the eye.  
            //
            //  Increasing DataSetup decreases the length of DelayTime 
            //  required to get to into the eye.  Increasing DataSetup also moves the rear 
            //  of the eye back, enlarges the eye (helpful in the case where quantized 
            //  DelayTime does not fall inside the initial eye).
            //          
            //          ____                   __________________________________________
            //  RDN         \_________________/
            //
            //                                               <----- tEYE ---->
            //                                             /--------------------\
            //  Read Data --------------------------------<                      >-------
            //                                             \--------------------/
            //              ^                 ^                      ^   tEYE/2     ^
            //              |                 |                      |              |
            //              |<---DataSetup--->|<-----DelayTime------>|              |
            //              |                 |                      |              |
            //              |                 |                                     |
            //              |                 |<------quantized DelayTime---------->|
            //              |                 |                                     |
            //                                      

            #if GPMI_PRINT_TIMINGS
            tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "(--dynamic--)(--Start--)\n");
            _print_dynamic_timing_summary(
                u32GpmiPeriod_ns,
                u32GpmiDelayFraction,
                i32tEYE,
                i32DelayTime_ns,
                u32GpmiMaxDelay_ns,
                u32DataSetupCycles,
                u32DataSetup_ns);

            #endif
            // Extend the Data Setup time as needed to reduce delay time below 
            // the max allowable value.  Also keep DataSetup in allowable range
            while ((i32DelayTime_ns > u32GpmiMaxDelay_ns) && (u32DataSetupCycles  < MAX_DATA_SETUP_CYCLES))
            {
                #if GPMI_PRINT_TIMINGS
                if ( !bPrintInterimTimings )
                {
                    // Print an explanation once now...
                    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "(DelayTime > GPMI max %d) and DataSetupCycles < max %d. Adjusting DelayTime.\n",u32GpmiMaxDelay_ns,MAX_DATA_SETUP_CYCLES );
                    tss_logtext_Flush(0);
                    // ...and print an interim list of timings afterward.
                    bPrintInterimTimings = true;
                }
                #endif
                u32DataSetupCycles++;                               // Give an additional DataSetup cycle
                u32DataSetup_ns += u32GpmiPeriod_ns;                // Keep DataSetup time in step with cycles
                i32tEYE += u32GpmiPeriod_ns;                        // And adjust the tEYE accordingly
                i32DelayTime_ns -= (u32GpmiPeriod_ns >> 1);         // decrease DelayTime by one half DataSetup cycle worth, to keep in the middle of the eye
                if (i32DelayTime_ns < 0)
                {
                    i32DelayTime_ns = 0;                            // Do not allow DelayTime less than zero
                }
            }

            // The DelayTime parameter is expressed in the chip in units of fractions of GPMI clocks.
            // Convert DelayTime to an integer quantity of fractional GPMI cycles..
            u32DataSampleDelayCycles = std::min( rom_nand_hal_FindGpmiCyclesCeiling( (u32GpmiDelayFraction * i32DelayTime_ns), u32GpmiPeriod_ns, 0), MAX_DATA_SAMPLE_DELAY_CYCLES);

            #if GPMI_PRINT_TIMINGS
            if ( bPrintInterimTimings )
            {
                _print_dynamic_timing_summary(
                    u32GpmiPeriod_ns,
                    u32GpmiDelayFraction,
                    i32tEYE,
                    i32DelayTime_ns,
                    u32GpmiMaxDelay_ns,
                    u32DataSetupCycles,
                    u32DataSetup_ns);
                bPrintInterimTimings = false;
            }

            #endif
            #define DSAMPLE_IS_NOT_WITHIN_THE_DATA_EYE  ( i32tEYE>>1 < std::abs( (int32_t)((u32DataSampleDelayCycles * u32GpmiPeriod_ns) / u32GpmiDelayFraction) - i32DelayTime_ns ))

            // While the quantized DelayTime is out of the eye reduce the DelayTime or extend 
            // the DataSetup to get in the eye.  Do not allow the number of DataSetup cycles to 
            // exceed the max supported by hardware.
            while ( DSAMPLE_IS_NOT_WITHIN_THE_DATA_EYE
                    && (u32DataSetupCycles  < MAX_DATA_SETUP_CYCLES) )
            {
                #if GPMI_PRINT_TIMINGS
                if ( !bPrintInterimTimings )
                {
                    // Print an explanation once now.
                    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "Data sample point not within data eye.  Adjusting.\n" );
                    bPrintInterimTimings = true;
                }
                #endif
                if ( ((u32DataSampleDelayCycles * u32GpmiPeriod_ns) / u32GpmiDelayFraction) > i32DelayTime_ns )
                {
                    // If quantized DelayTime is greater than max reach of the eye decrease quantized 
                    // DelayTime to get it into the eye or before the eye

                    if (u32DataSampleDelayCycles != 0)
                    {
                        u32DataSampleDelayCycles--;
                    }
                }
                else
                {
                    // If quantized DelayTime is less than min reach of the eye, shift up the sample 
                    // point by increasing DataSetup.  This will also open the eye (helping get 
                    // quantized DelayTime in the eye)
                    u32DataSetupCycles++;                           // Give an additional DataSetup cycle
                    u32DataSetup_ns += u32GpmiPeriod_ns;            // Keep DataSetup time in step with cycles
                    i32tEYE         += u32GpmiPeriod_ns;            // And adjust the tEYE accordingly
                    i32DelayTime_ns -= (u32GpmiPeriod_ns >> 1);     // decrease DelayTime by one half DataSetup cycle worth, to keep in the middle of the eye
                    i32DelayTime_ns -= u32GpmiPeriod_ns;            // ...and one less period for DelayTime.

                    if ( i32DelayTime_ns < 0 ) i32DelayTime_ns = 0; // keep DelayTime from going negative

                    // Convert time to GPMI cycles and make sure the number of 
                    // cycles fit in the coresponding hardware register...
                    u32DataSampleDelayCycles = std::min( rom_nand_hal_FindGpmiCyclesCeiling( (u32GpmiDelayFraction * i32DelayTime_ns), u32GpmiPeriod_ns, 0), MAX_DATA_SAMPLE_DELAY_CYCLES);
                }

            }   // while ( DSAMPLE_IS_NOT_WITHIN_THE_DATA_EYE )

#if GPMI_PRINT_TIMINGS
            tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "(--Final--)\n");
            _print_dynamic_timing_summary(
                u32GpmiPeriod_ns,
                u32GpmiDelayFraction,
                i32tEYE,
                i32DelayTime_ns,
                u32GpmiMaxDelay_ns,
                u32DataSetupCycles,
                u32DataSetup_ns);
//            NandDelayMicroSeconds(GPMI_PRINT_DELAY);
#endif

            break;
        } //case e_NAND_Timing_State_DYNAMIC_DSAMPLE_TIME:

        default:
#if GPMI_PRINT_TIMINGS
            tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "(--unchanged--)\n");
            tss_logtext_Flush(0);
#endif
            return;
    } // switch ( pNAND_Timing2_struct->eState )

#if GPMI_PRINT_TIMINGS
    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "GPMI (tDS, tDH, tAS, DelayT) = (%d, %d, %d, %d) ns\n",
                    u32GpmiPeriod_ns * u32DataSetupCycles,
                    u32GpmiPeriod_ns * u32DataHoldCycles,
                    u32GpmiPeriod_ns * u32AddressSetupCycles,
                    ((u32GpmiPeriod_ns * u32DataSampleDelayCycles) / u32GpmiDelayFraction) );
    tss_logtext_Flush(0);
//    NandDelayMicroSeconds(GPMI_PRINT_DELAY);

    tss_logtext_Print(LOGTEXT_VERBOSITY_3 | LOGTEXT_EVENT_DDI_NAND_GROUP, "(DataSetup, DataHold, AddressSetup, DelayTime) = (%d, %d, %d, %d) Count\n",
                    u32DataSetupCycles,
                    u32DataHoldCycles,
                    u32AddressSetupCycles,
                    u32DataSampleDelayCycles );

    tss_logtext_Flush(0);
//    NandDelayMicroSeconds(GPMI_PRINT_DELAY);
#endif

    if ( bWriteToTheDevice )
    {
        // Set the values in the registers.
        HW_GPMI_TIMING0_WR(NAND_GPMI_TIMING0(u32AddressSetupCycles, u32DataSetupCycles, u32DataHoldCycles));

        rom_nand_hal_GpmiSetAndEnableDataSampleDelay(u32DataSampleDelayCycles, u32GpmiPeriod_ns);
    }

    return;
}
#ifdef __cplusplus
} // extern "C"
#endif

void gpmi_set_busy_timeout(uint32_t busyTimeout)
{
    // Get current GPMI_CLK period in nanoseconds.
    uint32_t freq_kHz = ddi_clocks_GetGpmiClkInit();
    uint32_t u32GpmiPeriod_ns = 1000000 / freq_kHz;
    
    // Convert from microseconds to nanoseconds.
    uint64_t busyTimeout_ns = busyTimeout * 1000;
    
    // Divide the number of GPMI_CLK cycles for the timeout by 4096 as the
    // timeout register expects.
    uint32_t busyTimeout_gpmiclk = rom_nand_hal_FindGpmiCyclesCeiling(busyTimeout_ns, u32GpmiPeriod_ns) / 4096;
    
    // The busy timeout field is only 16 bits, so make sure the desired timeout will fit.
    if ((busyTimeout_gpmiclk & 0xffff0000) != 0)
    {
        // Set the timeout to the maximum value.
        busyTimeout_gpmiclk = 0xffff;
    }
    
    HW_GPMI_TIMING1_WR(BF_GPMI_TIMING1_DEVICE_BUSY_TIMEOUT(busyTimeout_gpmiclk));
}

void gpmi_disable()
{
    // Gate clocks to GPMI.
    BW_GPMI_CTRL0_CLKGATE(1);
    
    // Disable BCH as well.
    bch_ecc_disable();
}

void gpmi_enable_writes(bool bClearOrSet)
{
    BW_GPMI_CTRL1_DEV_RESET(bClearOrSet);
}

void gpmi_soft_reset(void)
{
    int64_t musecs;

    // Reset the GPMI_CTRL0 block.
    // Prepare for soft-reset by making sure that SFTRST is not currently
    // asserted.  Also clear CLKGATE so we can wait for its assertion below.
    HW_GPMI_CTRL0_CLR(BM_GPMI_CTRL0_SFTRST);

    // Wait at least a microsecond for SFTRST to deassert.
    musecs = hw_profile_GetMicroseconds();
    while (HW_GPMI_CTRL0.B.SFTRST || (hw_profile_GetMicroseconds() - musecs < DDI_NAND_HAL_GPMI_SOFT_RESET_LATENCY));

    // Also clear CLKGATE so we can wait for its assertion below.
    HW_GPMI_CTRL0_CLR(BM_GPMI_CTRL0_CLKGATE);

    // Now soft-reset the hardware.
    HW_GPMI_CTRL0_SET(BM_GPMI_CTRL0_SFTRST);

    // Poll until clock is in the gated state before subsequently
    // clearing soft reset and clock gate.
    while (!HW_GPMI_CTRL0.B.CLKGATE)
    {
        ; // busy wait
    }

    // bring GPMI_CTRL0 out of reset
    HW_GPMI_CTRL0_CLR(BM_GPMI_CTRL0_SFTRST);

    // Wait at least a microsecond for SFTRST to deassert. In actuality, we
    // need to wait 3 GPMI clocks, but this is much easier to implement.
    musecs = hw_profile_GetMicroseconds();
    while (HW_GPMI_CTRL0.B.SFTRST || (hw_profile_GetMicroseconds() - musecs < DDI_NAND_HAL_GPMI_SOFT_RESET_LATENCY));

    HW_GPMI_CTRL0_CLR(BM_GPMI_CTRL0_CLKGATE);

    // Poll until clock is in the NON-gated state before returning.
    while (HW_GPMI_CTRL0.B.CLKGATE)
    {
        ; // busy wait
    }
}

RtStatus_t gpmi_set_timings( NAND_Timing2_struct_t const * pNT, bool bWriteToTheDevice )
{
    // Handle a NULL pNT (means clock-change only, so use old pNT)
    if ( (pNT != NULL) && (bWriteToTheDevice) )
    {
        // We have a new set of timings at the pNT parameter.
        // Copy the new timing-table into the static table. (structure-copy)
        g_zNandTiming = *pNT;
    }

    // Pass 0 for period to use 24MHz default.
    nand_hal_GpmiSetNandTiming(pNT, 0, g_u32GPMIPropDelayMin_ns, g_u32GPMIPropDelayMax_ns, bWriteToTheDevice);

    return SUCCESS;
}

void gpmi_get_safe_timings(NAND_Timing2_struct_t * timings)
{
    const NAND_Timing2_struct_t safeTimings = NAND_SAFESTARTUP_TIMINGS;
    *timings = safeTimings;
}

const NAND_Timing2_struct_t * gpmi_get_current_timings()
{
    return &g_zNandTiming;
}

RtStatus_t gpmi_wait_for_dma(uint32_t u32usec, uint32_t u32NANDDeviceNum)
{
    reg32_t     r32ChipDmaNumber = NAND0_APBH_CH + u32NANDDeviceNum;
#ifdef RTOS_THREADX
    uint32_t    retCode_tx_semaphore;
#endif
    bool        bTimedOut = FALSE;
    RtStatus_t  rtStatus = SUCCESS;
    bool saveIrqState;

#ifdef RTOS_THREADX
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

    return rtStatus;

}

RtStatus_t gpmi_run_dma(dma_cmd_t * theDma, unsigned chipSelect, uint16_t waitMask, uint32_t timeout)
//dma_cmd_t * pDmaCmd, uint32_t dmaCommandLength, uint32_t u32NANDDeviceNum, uint16_t u16DmaWaitMask)
{
    uint32_t    physicalCommandAddress;
    reg32_t     r32ChannelMask          = (0x1 << (NAND0_APBH_CH+u32NANDDeviceNum));
    reg32_t     r32ChipDmaNumber        = (NAND0_APBH_CH+u32NANDDeviceNum);
    bool        bDmaIsRunning;
    RtStatus_t  rtStatus = SUCCESS;
    bool saveIrqState;
    
    // Save off the chip that we're watching in the DMA completion structure.
    // todo - can we watch more than 1 chip at a later time?
    g_gpmiDmaInfo.u16CurrentChip = u32NANDDeviceNum;
    
    // Set the criteria for finishing this DMA.
    g_gpmiDmaInfo.u16DmaWaitMask      = u16DmaWaitMask;
    
    // Clear the status word used to check the criteria for finishing this DMA.
    g_gpmiDmaInfo.u16DmaWaitStatus    = kNandGpmiDmaWaitMask_Nothing;

    // Alert me if a DMA chain is currently running!!
    // Note that this checks the SEMA.PHORE register field for the DMA.
    bDmaIsRunning = gpmi_is_dma_active(u32NANDDeviceNum);

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
        rtStatus = ERROR_DDI_NAND_GPMI_DMA_BUSY;

        goto _standardExit;
    } // if (bDmaIsRunning)

    // At this point, there should be no DMA running.
    // Sanity-test to make sure the DMA channel IRQ is deasserted.
    // (Note that the optimizing compiler will probably combine the
    // body of this section with the previous section.)
    if ( 0 != (HW_APBH_CTRL1_RD() & (r32ChannelMask << BP_APBH_CTRL1_CH0_CMDCMPLT_IRQ)) )
    {
        rtStatus = ERROR_DDI_NAND_GPMI_DMA_BUSY;

        goto _standardExit;
    }

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

    return rtStatus;
}

bool gpmi_is_dma_active(uint32_t u32NANDDeviceNum)
{
    uint32_t    u32Sema;
    reg32_t     r32ChipDmaNumber    = (NAND0_APBH_CH+u32NANDDeviceNum);
    uint32_t    u32Run;

    u32Sema = HW_APBH_CHn_SEMA_RD(r32ChipDmaNumber) & BM_APBH_CHn_SEMA_PHORE;

    u32Run = BF_RD(GPMI_CTRL0, RUN);

    // A nonzero value for either of these means a DMA is running.
    return ( u32Sema | u32Run );
}

// void read_nflash_id(unsigned short *id)
// {
//     /* set up the clocks for the GPMI NAND interface */
//     gpmi_nand_clk_setup();
// 
//     HW_GPMI_CTRL0_WR(0xC0000000);   // ensure clock gated and reset set (will be cleared later)
// 
//     // preparing soft reset and clock gate.
//     HW_GPMI_CTRL0_CLR(0x40000000);  // first, ungate clock
//     HW_GPMI_CTRL0_CLR(0x80000000);  // now bring out of reset
// 
//     // Only soft reset if GPMI hasn't been enabled.
//     HW_GPMI_CTRL0_SET(BM_GPMI_CTRL0_SFTRST);
// 
//     while (!HW_GPMI_CTRL0.B.CLKGATE) {
//         // busy wait
//     }
// 
//     // Now bring out of reset and disable Clk gate.
//     HW_GPMI_CTRL0_CLR(BM_GPMI_CTRL0_SFTRST | BM_GPMI_CTRL0_CLKGATE);
//     /* Disable BCH at GPMI accessing NAND */
//     HW_GPMI_ECCCTRL_CLR(1 << 12);   //disable ECC
// 
//     GpmiNandSetSafeTiming();
// 
//     /* Set up pin muxing for NAND flash */
//     rawnand_iomux_config();
// 
//     // Put GPMI in NAND mode, keep DEVICE reset enabled, and make certain
//     // polarity is active high
//     HW_GPMI_CTRL1_WR(BF_GPMI_CTRL1_DEV_RESET(BV_GPMI_CTRL1_DEV_RESET__DISABLED) |
//                      BF_GPMI_CTRL1_ATA_IRQRDY_POLARITY
//                      (BV_GPMI_CTRL1_ATA_IRQRDY_POLARITY__ACTIVEHIGH) |
//                      BW_GPMI_CTRL1_GPMI_MODE(BV_GPMI_CTRL1_GPMI_MODE__NAND));
// 
//     // Take the APBH out of reset.
//     // APBH - disable reset, enable clock.
//     HW_APBH_CTRL0_CLR(0xC0000000);
// 
//     BW_APBH_CHANNEL_CTRL_RESET_CHANNEL(0x1 << (CHAN0));
//     HW_APBH_CTRL1_CLR(0x1 << (CHAN0));
//     /* send RESET command to the NAND flash */
//     GpmiNandReset();
// 
//     /* call function for reading NAND device ID, pass in how many devices are populated */
//     GpmiNandReadId(id);
// }

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
