/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file  ocotp.c
 * @brief OCOTP driver for e-fuse.
 * @ingroup diag_ocotp
 */

#include <stdio.h>
#include "hardware.h"
#include "ocotp/ocotp.h"
#include "registers/regsocotp.h"

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

static int Delay4Busy(void);
static int ReadOTPValues(uint32_t * pau32Registers, uint32_t u32RegIndex, uint32_t u32Count);
static int32_t WriteOTPValues(uint32_t * pau32Registers, uint32_t u32RegIndex, uint32_t u32Count);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * @brief Waits until OCOTP_CTRL BUSY bit is cleared.
 *
 * @return SUCCESS on success otherwise ERROR_BIT_SET
 * @todo also deal with timeout and test for BUSY still set
 */
int Delay4Busy(void)
{
    // Wait until the busy flag clears.
    while (HW_OCOTP_CTRL.B.BUSY);

    // process any errors
    if (HW_OCOTP_CTRL.B.ERROR) {
        // clear the error bit so more writes can be done
        HW_OCOTP_CTRL_CLR(BM_OCOTP_CTRL_ERROR);
        return ERROR_OTP_CTRL_ERROR;
    }
    return SUCCESS;
}

/*!
 * @brief Read OTP register values from device.
 *
 * @param  pau32Registers Pointer to an array of register values
 * @param  u32RegIndex Register index
 * @param  u32Count Length of array in first parameter
 * @return SUCCESS or Error
 */
int ReadOTPValues(uint32_t * pau32Registers, uint32_t u32RegIndex, uint32_t u32Count)
{
    uint32_t i;                      // index used in for loops
    uint32_t u32Result;

    for (i = 0; i < u32Count; i++) {
        u32Result = Delay4Busy();
        if (u32Result != SUCCESS) {
            return u32Result;
        }
        // Write the requested address into HW_OCOTP_CTRL register
        HW_OCOTP_CTRL_WR(BF_OCOTP_CTRL_ADDR(u32RegIndex + i));
        // Initiate a read of 4bytes at an OTP address.
        HW_OCOTP_READ_CTRL_WR(BM_OCOTP_READ_CTRL_READ_FUSE);
        // Have to wait for busy bit to be cleared
        Delay4Busy();
        // Finally, read the data
        pau32Registers[i] = HW_OCOTP_READ_FUSE_DATA_RD();
    }

    return (SUCCESS);
}

/*!
 * Program OTP registers with values passed in register array parameter.
 *
 * @param  pau32Registers Pointer to array of register values
 * @param  u32RegIndex Register index
 * @param  u32Count Length of array in first parameter
 * @retval ERROR_OTP_CTRL_BUSY The OCOTP peripheral is already busy.
 * @retval ERROR_OTP_CTRL_ERROR An error occured.
 * @retval ERROR_OTP_RD_BANK_OPEN, if reading
 * @retval SUCCESS
 */
int32_t WriteOTPValues(uint32_t * pau32Registers, uint32_t u32RegIndex, uint32_t u32Count)
{
    uint32_t i;

    /* In order to avoid erroneous code performing erroneous writes to OTP,
     * a special unlocking sequence is required for writes.
     *
     * 1. Check that HW_OCOTP_CTRL_BUSY and HW_OCOTP_CTRL_ERROR are
     * clear. Overlapped accesses are not supported by the controller. Any pending
     * write must be completed before a write access can be requested.
     */

    if (HW_OCOTP_CTRL.B.BUSY) {
        return ERROR_OTP_CTRL_BUSY;
    }

    if (HW_OCOTP_CTRL.B.ERROR) {
        return ERROR_OTP_CTRL_ERROR;
    }

    /* 2. Setup timing register - ipg_clk typically at 66.5MHz <=> 15ns
     * tRELAX = (OCOTP_TIMING[RELAX]+1)/ipg_frequency > 16.2ns
     *
     * tPGM = ((OCOTP_TIMING[STROBE_PROG]+1)- 2*(OCOTP_TIMING[RELAX]+1))/ipg_frequency
     * 9000ns < tPGM (typ 10000ns) < 11000ns
     *
     * tRD = ((OCOTP_TIMING[STROBE_READ]+1)- 2*(OCOTP_TIMING[RELAX]+1))/ipg_frequency > 36ns
     *
     * Default value of timing register is 0x01461299
     * => RELAX = 1 => tRELAX = 30ns
     * => STROBE_PROG = 299 => tPGM = 9930ns
     * => STROBE_READ = 6 => tRD = 45ns
     */
    HW_OCOTP_TIMING_WR(
        BF_OCOTP_TIMING_STROBE_PROG(0x299)
        | BF_OCOTP_TIMING_RELAX(0x1)
        | BF_OCOTP_TIMING_STROBE_READ(0x6)
        | BF_OCOTP_TIMING_WAIT(0x5));

    for (i = 0; i < u32Count; i++) {
        uint32_t u32DelayResult = Delay4Busy();
        if (u32DelayResult != SUCCESS) {
            return u32DelayResult;
        }
        /* 3. Write the requested address to HW_OCOTP_CTRL_ADDR and program the
         * unlock code into HW_OCOTP_CTRL_WR_UNLOCK. This must be programmed
         * for each write access. The lock code is documented in the XML register
         * description. Both the unlock code and address can be written in the same
         * operation.
         */

        HW_OCOTP_CTRL_WR(
            BF_OCOTP_CTRL_WR_UNLOCK(BV_OCOTP_CTRL_WR_UNLOCK__KEY)
            | BF_OCOTP_CTRL_ADDR(u32RegIndex + i));

        /* 4. Write the data to HW_OCOTP_DATA. This will automatically set
         * HW_OCOTP_CTRL_BUSY and clear HW_OCOTP_CTRL_WR_UNLOCK. In
         * this case, the data is a programming mask. Bit fields with 1s will result in that
         * OTP bit being set. Only the controller can clear HW_OCOTP_CTRL_BUSY. The
         * controller will use the mask to program a 32-bit word in the OTP per the address
         * in ADDR. At the same time that the write is accepted, the controller makes an
         * internal copy of HW_OCOTP_CTRL_ADDR which cannot be updated until the
         * next write sequence is initiated. This copy guarantees that erroneous writes to
         * HW_OCOTP_CTRL_ADDR will not affect an active write operation. It should
         * also be noted that during the programming HW_OCOTP_DATA will shift right
         * (with zero fill). This shifting is required to program the OTP serially. During the
         * write operation, HW_OCOTP_DATA cannot be modified.
         */

        HW_OCOTP_DATA_WR(pau32Registers[i]);

        /* 5. Once complete, the controller will clear BUSY. A write request to a protected
         * region will result in no OTP access and no setting of
         * HW_OCOTP_CTRL_BUSY. In addition HW_OCOTP_CTRL_ERROR will be
         * set. It must be cleared by software before any new write access can be issued.
         * It should be noted that write latencies to OTP are in the order of 10s to 100s of
         * microseconds per word. Write latencies will vary based on the location of the word
         * within the OTP bank. Once a write is initiated, HW_OCOTP_DATA is shifted one bit
         * per every 32 HCLK cycles.
         */

        Delay4Busy();
    }

    return SUCCESS;
}

int32_t ocotp_sense_fuse(uint32_t bank, uint32_t row)
{
    int32_t error;
    uint32_t calc_row, value=0;

    calc_row = bank * 8 + row;
    if ((error = ReadOTPValues(&value, calc_row, 1)) != SUCCESS) {
//         printf("Error: Error reading fuse 0x%x\n", error);
        return 0;
    }
    return value;
}

void ocotp_fuse_blow_row(uint32_t bank, uint32_t row, uint32_t value)
{
    int32_t error;
    uint32_t calc_row;

    calc_row = bank * 8 + row;

    if ((error = WriteOTPValues(&value, calc_row, 1)) != SUCCESS) {
//         printf("Error: Error programming fuse 0x%x\n", error);
        return;
    }
//     printf("Fuse programmed successfully\n");
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
