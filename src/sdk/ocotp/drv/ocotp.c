/*
 * Copyright (C) 2009-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
/*!
 * @file  ocotp.c
 * @brief e-fuse driver
 *
 */
#include <stdio.h>
#include "hardware.h"
#include "ocotp.h"

/*!
 * Waits until OCOTP_CTRL BUSY bit is cleared.
 *
 * @return SUCCESS on success otherwise ERROR_BIT_SET
 *
 */
uint32_t Delay4Busy(void)
{
    uint32_t u32Rtn = SUCCESS;
    bool done = false;

    while (!done) {
        if ((HW_OCOTP_CTRL_RD() & BM_OCOTP_CTRL_BUSY) == 0) {
            done = true;
        }
    }

    // process any errors
    // @todo: also deal with timeout and test for BUSY still set
    if (HW_OCOTP_CTRL_RD() & BM_OCOTP_CTRL_ERROR) {
        // clear the error bit so more writes can be done
        HW_OCOTP_CTRL_CLR(BM_OCOTP_CTRL_ERROR);
        u32Rtn |= ERROR_BIT_SET;
    }
    return (u32Rtn);
}

/*!
 * Read OTP register values from device.
 *
 * @param  pau32Registers, pointer to an array of register values
 * @param  u32RegIndex, register index
 * @param  u32Count, length of array in first parameter
 * @return SUCCESS or Error
 */
static int ReadOTPValues(uint32_t * pau32Registers, uint32_t u32RegIndex, uint32_t u32Count)
{
    uint32_t i;                      // index used in for loops
    uint32_t u32Result = SUCCESS;

    for (i = 0; i < u32Count; i++) {
        if ((u32Result = Delay4Busy()) != SUCCESS) {
            goto done;
        }
        // Write the requested address into HW_OCOTP_CTRL register
        HW_OCOTP_CTRL_WR((u32RegIndex + i) & BM_OCOTP_CTRL_ADDR);
        // Initiate a read of 4bytes at an OTP address.
        HW_OCOTP_READ_CTRL_WR(OCOTP_READ_CTRL_READ_FUSE);
        // Have to wait for busy bit to be cleared
        Delay4Busy();
        // Finally, read the data
        pau32Registers[i] = HW_OCOTP_READ_FUSE_DATA_RD();
    }

  done:
    if (u32Result == ERROR_BIT_SET)
        return ERROR_OTP_CTRL_ERROR;
    return (SUCCESS);
}

/*!
 * Program OTP registers with values passed in register array parameter.
 *
 * @param  pau32Registers pointer to array of register values
 * @param  u32RegIndex, register index
 * @param  u32Count, length of array in first parameter
 * @return ERROR_OTP_CTRL_BUSY, if busy
 *         ERROR_OTP_CTRL_ERROR, if error
 *         ERROR_OTP_RD_BANK_OPEN, if reading
 *         otherwise SUCCESS
 */
int32_t WriteOTPValues(uint32_t * pau32Registers, uint32_t u32RegIndex, uint32_t u32Count)
{
    uint32_t i;
    int32_t i32RetValue = SUCCESS;

    /* In order to avoid erroneous code performing erroneous writes to OTP,
     * a special unlocking sequence is required for writes.
     *
     * 1. Check that HW_OCOTP_CTRL_BUSY and HW_OCOTP_CTRL_ERROR are
     * clear. Overlapped accesses are not supported by the controller. Any pending
     * write must be completed before a write access can be requested.
     */

    if (HW_OCOTP_CTRL_RD() & BM_OCOTP_CTRL_BUSY) {
        return ERROR_OTP_CTRL_BUSY;
    }

    if (HW_OCOTP_CTRL_RD() & BM_OCOTP_CTRL_ERROR) {
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
    HW_OCOTP_TIMING_WR(0x01461299);

    for (i = 0; i < u32Count; i++) {
        uint32_t u32DelayResult = Delay4Busy();
        if (u32DelayResult != SUCCESS) {
            if (u32DelayResult & ERROR_BIT_SET) {
                i32RetValue = ERROR_OTP_CTRL_ERROR;
                goto done;
            }
            i32RetValue = ERROR_OTP_CTRL_TIMEOUT;
            goto done;
        }
        /* 3. Write the requested address to HW_OCOTP_CTRL_ADDR and program the
         * unlock code into HW_OCOTP_CTRL_WR_UNLOCK. This must be programmed
         * for each write access. The lock code is documented in the XML register
         * description. Both the unlock code and address can be written in the same
         * operation.
         */

        HW_OCOTP_CTRL_WR(OCOTP_WR_UNLOCK_KEY_VALUE | ((u32RegIndex + i) & BM_OCOTP_CTRL_ADDR));

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
//        HW_OCOTP_CTRL_WR(HW_OCOTP_CTRL_RD() | BM_OCOTP_CTRL_RELOAD_SHADOWS);
    }

  done:

    return (i32RetValue);
}

/*!
 * Read the value of fuses located at bank/row.
 *
 * @param  bank of the fuse
 * @param  row of the fuse
 * @return fuse value
 */
int32_t sense_fuse(uint32_t bank, uint32_t row)
{
    int32_t error;
    uint32_t calc_row, value;

    calc_row = bank * 8 + row;
    if ((error = ReadOTPValues(&value, calc_row, 1)) != SUCCESS) {
        printf("Error: Error reading fuse 0x%x\n", error);
        return 0;
    }
    return value;
}

/*!
 * Program fuses located at bank/row to value.
 *
 * @param  bank of the fuses.
 * @param  row of the fuses.
 * @param  value to program in fuses.
 */
void fuse_blow_row(uint32_t bank, uint32_t row, uint32_t value)
{
    int32_t error;
    uint32_t calc_row;

    calc_row = bank * 8 + row;

    if ((error = WriteOTPValues(&value, calc_row, 1)) != SUCCESS) {
        printf("Error: Error programming fuse 0x%x\n", error);
        return;
    }
    printf("Fuse programmed successfully\n");

    return;
}
