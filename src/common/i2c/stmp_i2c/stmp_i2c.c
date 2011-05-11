/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @defgroup diag_i2c I2C Test
 */

/*!
 * @file stmp_i2c.c
 * @brief I2C driver for MX28
 *
 * @ingroup diag_i2c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hardware.h"
#include "regsapbx.h"
#include "regsi2c.h"
#include "mxc_i2c.h"

//#define MXC_I2C_DEBUG
#undef MXC_I2C_DEBUG

#ifdef MXC_I2C_DEBUG
#define printf1    printf
#else
#define printf1(fmt,args...)
#endif
extern char ApbxDmaInit(void);
extern char ApbxDmaResetChan(unsigned char Channel, char bReset);
extern char ApbxDmaEnableCommandCmpltIrq(unsigned char Channel, char bEnable);
extern char ApbxDmaInitChan(unsigned char Channel, char bEnableIrq);
//extern char ApbxStartDma(unsigned char Channel,unsigned int memAddrPA, unsigned char semaphore);
extern char ApbxDmaClearCommandCmpltIrq(unsigned char Channel);

extern void hal_delay_us(unsigned int usecs);

#define HW_APBX_DMA_I2C0_CHANNEL 6
#define HW_APBX_DMA_I2C1_CHANNEL 7

#define I2C_DMA_CHAIN_ADDR 0x00004000   // On-chip RAM
#define I2C_DMA_BUFF_ADDR   0x00004800  // On-chip RAM

#define I2C_RW_WRITE                    1   // Perform Write operation
#define I2C_RW_READ                     2   // Perform Read operation

#define I2C_MASTER_MODE                 1   // I2C Master Mode

//Set slave mode from IOCTL is obsolete feature, use enable slave instead.
//Keep the definition here for back compatible purpose.
#define I2C_SLAVE_MODE                  2   // I2C Slave Mode

#define I2C_NO_ERROR                    (0) // Last operation successful
#define I2C_ERR_MOPS_CREATE             (-1)    // Mutex Creation failed
#define I2C_ERR_PA_VA_MISSING           (-2)    // Physical -> Virtual Mapping failed
#define I2C_ERR_EOPS_CREATE             (-3)    // Event Creation failed
#define I2C_ERR_IRQ_SYSINTR_MISSING     (-4)    // IRQ -> System Interrupt ID Mapping failed
#define I2C_ERR_INT_INIT                (-5)    // Interrupt Initialization failed
#define I2C_ERR_WORKER_THREAD           (-6)    // Worker thread failed
#define I2C_ERR_NO_ACK_ISSUED           (-7)    // No Acknowledge Issued
#define I2C_ERR_NULL_BUF                (-8)    // NULL Buffer
#define I2C_ERR_INVALID_BUFSIZE         (-9)    // Invalid Buffer Size
#define I2C_ERR_NULL_LPIRESULT          (-10)   // NULL lpiResult field
#define I2C_ERR_CLOCK_FAILURE           (-11)   // CRM Operation Failure
#define I2C_ERR_TRANSFER_TIMEOUT        (-12)   // I2C transmit timeout error
#define I2C_ERR_ARBITRATION_LOST        (-13)   // I2C arbitration lost error
#define I2C_ERR_STATEMENT_CORRUPT       (-14)   // I2C goto an undefined error
#define I2C_ERR_EARLY_TERM                  (-15)   // I2C got NAK before end of transfer
#define I2C_ERR_GENERAL                        (-16)    // general error

//------------------------------------------------------------------------------
// Types
//------------------------------------------------------------------------------
// I2C Packet
typedef struct {
    unsigned char byAddr;       // I2C slave device address for this I2C operation
    unsigned char byRW;         // Read = I2C_READ or Write = I2C_WRITE
    unsigned char *pbyBuf;      // Message Buffer
    int wLen;                   // Message Buffer Length
    char lpiResult;             // Contains the result of last operation
} I2C_PACKET, *PI2C_PACKET;

// I2C Transfer Block
typedef struct {
    I2C_PACKET *pI2CPackets;
    int iNumPackets;
} I2C_TRANSFER_BLOCK, *PI2C_TRANSFER_BLOCK;

// I2C DMA Chain: each buffer can transfer a max of ~64K
typedef struct I2C_DMA_BUFFER {
    unsigned int pNextBuff;     // address of next buffer in the descriptor chain
    unsigned int dwDMACmd;      // DMA command word
    unsigned int pbDataBufferAddress;   // PHYSICAL ADDRESS of data buffer to be read/written
    unsigned int dwCtrl0;       // control word
} I2C_DMA_BUFFER;

int test_flag_simple_i2c_device = 0;

extern char ApbxStartDma(unsigned char Channel, unsigned int memAddrPA, unsigned char semaphore);

/*!
 * copy data
 *
 * @param   dst  destination address
 * @param   src  source address
 * @param   len  length
 */
void memcpy_byte(char *dst, char *src, int len)
{
    int i;
    for (i = 0; i < len; i++) {
        *(dst + i) = *(src + i);
    }

}

/*!
 * Set clock rate of I2C
 *
 * @param   ClkRate  clock rate
 *
 */
void i2cSetupTimingRegs(unsigned int ClkRate)
{
    // 100 khz or less: std mode
    if (ClkRate <= 100000) {
        HW_I2C_TIMING0_WR(0x00780030);  // high time = 120 clocks, read bit at 48 for 95KHz at 24mhz
        HW_I2C_TIMING1_WR(0x00800030);  // low time at 128, write bit at 48 for 95 kHz at 24 MHz

    }
    // 400 khz: fast-mode
    else {
        HW_I2C_TIMING0_WR(0x000F0007);  // high time = 15 clocks, read bit at 7 for 400KHz at 24mhz
        HW_I2C_TIMING1_WR(0x001F000F);  // low time at 31, write bit at 15 for 400 kHz at 24 MHz

    }

    HW_I2C_TIMING2_WR(0x0015000d);  // bus free count of 21 lead in count of 13

    //printf("TIMING0: 0x%08x, TIMING1: 0x%08x\r\n", HW_I2C_TIMING0_RD(), HW_I2C_TIMING1_RD());
}

/*!
 * Function: ProcessPackets
//
// This is the main engine that transmits or receives data from I2C Bus
// Interface. This engine implements the complete I2C Bus Protocol which allows
// the calling process to interact with all I2C-compliant slave device. This
// method has built-in mechanism to prevent concurrent execution.
//
 * @Param:
//      pPacket
//          [in] Contains all the necessary information to transmit/
//          receive from the slave device.
//
//      dwNumPackets
//          [in] Number of packets to be processed.
//
 * Returns:
//      TRUE   Success.
//      FALSE  Failed
//
 */
char ProcessPackets(I2C_PACKET packets[], unsigned int numPackets)
{
    char retVal = TRUE;
    I2C_DMA_BUFFER *pDescChain[8];
    unsigned int *DescChainPhysAddr[8];
    unsigned int *DMABuffVirAddr[8];
    unsigned int *DMABuffPhysAddr[8];
    int i, count;

    // Flag to signal if address cycle just completed
//    char bRSTACycleComplete;
    unsigned int dwCtrl0 = 0, dwDMACmd = 0;
    unsigned char Mode = I2C_MASTER_MODE;

    if (numPackets > 8) {
        printf("packet number should not be more than 8.\n");
        return FALSE;
    }
    // enable the clock
    HW_I2C_CTRL0_CLR(BM_I2C_CTRL0_CLKGATE);

    //wait for a moment
    HW_I2C_CTRL0_RD();

    // Configure clock frequency and setup/hold times based on dwLastClkRate
    i2cSetupTimingRegs(100000);

    // set ACK_MODE
    HW_I2C_CTRL1_SET(BM_I2C_CTRL1_ACK_MODE);

    for (i = 0; i < 8; i++) {
        DMABuffVirAddr[i] = (unsigned int *)(I2C_DMA_BUFF_ADDR + 8 * i);    //each dma buffer contains 8-byte space.
        memset(DMABuffVirAddr[i], 0x0, 8);
        DMABuffPhysAddr[i] = DMABuffVirAddr[i];
    }

    for (i = 0; i < 8; i++) {
        pDescChain[i] = (I2C_DMA_BUFFER *) (I2C_DMA_CHAIN_ADDR + i * sizeof(I2C_DMA_BUFFER));
        memset(pDescChain[i], 0x0, sizeof(I2C_DMA_BUFFER));
        DescChainPhysAddr[i] = (unsigned int *)pDescChain[i];
    }

    // For each I2C packet, transfer data as specified
//    bRSTACycleComplete = FALSE;
    for (i = 0; i < numPackets; i++) {
        dwCtrl0 = 0;
        dwDMACmd = 0;

        // link to this buffer from previous buffer
        if (i > 0) {

            //   pDescChain[i] = (I2C_DMA_BUFFER *) ((unsigned int) pDescChain[0] + i * sizeof(I2C_DMA_BUFFER));
            pDescChain[i - 1]->pNextBuff =
                (unsigned int)DescChainPhysAddr[0] + i * sizeof(I2C_DMA_BUFFER);

            pDescChain[i - 1]->dwDMACmd |= BF_APBX_CHn_CMD_CHAIN(1);
        }

        packets[i].lpiResult = (char)I2C_ERR_STATEMENT_CORRUPT;

        // set CMDWORD to 1
        dwDMACmd |= BF_APBX_CHn_CMD_CMDWORDS(1);

        // if this is not the last packet, or it is 1st packet
        if (i != numPackets - 1 || i == 0) {
            //printf("ProcessPacket():Issuing START command: %d\r\n", i);

            // set the PRE_SEND_START bit in the CTRL0 word
            dwCtrl0 |= BM_I2C_CTRL0_PRE_SEND_START;

            // if there is more than 1 packet in the chain, set the RETAIN_LOCK bit on all buffers except first and last
            if ((numPackets > 1 && i != 0) || (test_flag_simple_i2c_device))
                dwCtrl0 |= BF_I2C_CTRL0_RETAIN_CLOCK(BV_I2C_CTRL0_RETAIN_CLOCK__HOLD_LOW);

            // WAIT4ENDCMD
            dwDMACmd |= BF_APBX_CHn_CMD_WAIT4ENDCMD(1);
        }
        // Send a STOP signal if this is our final packet
        if (i == numPackets - 1) {
            //printf("ProcessPacket():Issuing STOP command: %d\r\n", i);

            // set the PRE_SEND_START bit in the CTRL0 word
            dwCtrl0 |= BM_I2C_CTRL0_POST_SEND_STOP;

            // SEND_NAK if this is a read
            if (packets[i].byRW == I2C_RW_READ)
                dwCtrl0 |= BM_I2C_CTRL0_SEND_NAK_ON_LAST;

            // set IRQONCMPLT if this is last descriptor in the chain
            dwDMACmd |= BF_APBX_CHn_CMD_IRQONCMPLT(1);

            // decrement SEMAPHORE, only on last buffer
            dwDMACmd |= BF_APBX_CHn_CMD_SEMAPHORE(1);

            // no next descriptor
            pDescChain[i]->pNextBuff = 0;

        }
        // set MASTER_MODE bit according to Mode
        dwCtrl0 |= (Mode == I2C_MASTER_MODE) ? BM_I2C_CTRL0_MASTER_MODE : 0;

        // set DIRECTION bit based on packet info
        dwCtrl0 |= (packets[i].byRW == I2C_RW_WRITE) ? BM_I2C_CTRL0_DIRECTION : 0;
        dwDMACmd |=
            (packets[i].byRW ==
             I2C_RW_WRITE) ? BF_APBX_CHn_CMD_COMMAND(BV_APBX_CHn_CMD_COMMAND__DMA_READ) :
            BF_APBX_CHn_CMD_COMMAND(BV_APBX_CHn_CMD_COMMAND__DMA_WRITE);

        // set XFER_COUNT
        dwCtrl0 |= BF_I2C_CTRL0_XFER_COUNT(packets[i].wLen);
        dwDMACmd |= BF_APBX_CHn_CMD_XFER_COUNT(packets[i].wLen);

        // Setup the ith buffer in the chain

        pDescChain[i]->dwCtrl0 = dwCtrl0;
        pDescChain[i]->pbDataBufferAddress = (unsigned int)DMABuffPhysAddr[i];  //later, do a memcpy to/from packets[i].pbyBuf;
        pDescChain[i]->dwDMACmd = dwDMACmd;

        // copy over the bytes to the DMA buffer before starting the write
        if (packets[i].byRW == I2C_RW_WRITE) {
            if (((unsigned int)packets[i].pbyBuf % 4) != 0)
                printf("packets[%d].pbyBuf(0x%x) address is not 4B aligned\n", i,
                       (unsigned int)packets[i].pbyBuf);
            memcpy_byte((char *)DMABuffVirAddr[i], (char *)packets[i].pbyBuf, (int)packets[i].wLen);

        }

        packets[i].lpiResult = I2C_NO_ERROR;

    }

    if (!ApbxDmaInitChan(HW_APBX_DMA_I2C0_CHANNEL, TRUE)) {
        printf("ProcessPackets: Unable to initialize DMA channel\r\n");
        retVal = FALSE;
        goto __exit;
    }

    if (test_flag_simple_i2c_device) {
        count = 200;
        while (count--) {
            //add delay here
            hal_delay_us(1000);
        }
    }
    // Start the  DMA channel
    ApbxStartDma(HW_APBX_DMA_I2C0_CHANNEL, (unsigned int)DescChainPhysAddr[0], 1);

    //add delay here
    hal_delay_us(20000);

    count = 100;
    while (!(HW_APBX_CTRL1_RD() & (1 << HW_APBX_DMA_I2C0_CHANNEL)) && (count--)) {
        hal_delay_us(200);
    }

    // wait for completion
    if ((HW_APBX_CTRL1_RD() & (1 << HW_APBX_DMA_I2C0_CHANNEL))
        || !(HW_APBX_CHn_SEMA_RD(HW_APBX_DMA_I2C0_CHANNEL) & BM_APBX_CHn_SEMA_PHORE)) {

        // error checking
        if (HW_APBX_CTRL2_RD() & (1 << HW_APBX_DMA_I2C0_CHANNEL)) {
            printf("Error tranferring data: CTRL0: 0x%08x CTRL1: 0x%08x Status: 0x%x\r\n",
                   HW_I2C_CTRL0_RD(), HW_I2C_CTRL1_RD(), HW_I2C_STAT_RD());

            // clear the DMA error interrupt bit
            HW_APBX_CTRL2_CLR(BM_APBX_CTRL2_CH3_ERROR_IRQ);

            for (i = 0; i < numPackets; i++) {
                if (HW_I2C_CTRL1.B.NO_SLAVE_ACK_IRQ) {
                    packets[i].lpiResult = (char)I2C_ERR_NO_ACK_ISSUED;
                } else if (HW_I2C_CTRL1.B.EARLY_TERM_IRQ) {
                    packets[i].lpiResult = (char)I2C_ERR_EARLY_TERM;
                } else if (HW_I2C_CTRL1.B.MASTER_LOSS_IRQ) {
                    packets[i].lpiResult = (char)I2C_ERR_GENERAL;
                }
            }

            retVal = FALSE;

            // reset module and DMA
            //Reset();
        }
        // success
        else {
            if (packets[numPackets - 1].byRW == I2C_RW_READ) {
                if (((unsigned int)packets[numPackets - 1].pbyBuf % 4) != 0)
                    printf
                        ("packets[%d].pbyBuf(0x%x) address is not 4B aligned. Will cause data error.\n",
                         i, (unsigned int)packets[i].pbyBuf);

                //printf("0x%x, 0x%x, 0x%x\n", numPackets, DMABuffVirAddr[numPackets-1], *DMABuffVirAddr[numPackets-1]);
                memcpy_byte((char *)packets[numPackets - 1].pbyBuf,
                            (char *)DMABuffVirAddr[numPackets - 1], packets[numPackets - 1].wLen);

                //printf("0x%x, 0x%x\n", packets[numPackets-1].pbyBuf, *packets[numPackets-1].pbyBuf);
            }
        }
    }
    // WAIT_TIMEOUT or WAIT_FAILED
    else {
        printf("Timeout while waiting for I2C DMA interrupt\r\n");

        for (i = 0; i < numPackets; i++) {
            packets[i].lpiResult = (char)I2C_ERR_TRANSFER_TIMEOUT;
        }

        retVal = FALSE;

    }

    // Disable the interrupt
    ApbxDmaEnableCommandCmpltIrq(HW_APBX_DMA_I2C0_CHANNEL, FALSE);

    // clear the I2C DMA interrupt
    ApbxDmaClearCommandCmpltIrq(HW_APBX_DMA_I2C0_CHANNEL);

    // stop channel (puts it in reset state)
    ApbxDmaResetChan(HW_APBX_DMA_I2C0_CHANNEL, TRUE);

  __exit:

    // clock gate
    HW_I2C_CTRL0_SET(BM_I2C_CTRL0_CLKGATE);

    return retVal;
}

/*!
 * transfer data
 *
 * @param   i2c_nr  i2c device number
 * @param   rq  i2c request
 * @param   dir read/wirte
 */
int i2c_xfer(unsigned int i2c_nr, struct mxc_i2c_request *rq, int dir)
{
    unsigned char i;
    int ret = 0;
    I2C_PACKET packets[8];
    char buf[8] = { 0 };
    char recbuf[8] = { 0 };
    unsigned int buf1;

    if (dir == 1)               // read
    {
        //device address
        packets[0].byAddr = rq->dev_addr;
        packets[0].byRW = I2C_RW_WRITE;
        //result
        packets[0].lpiResult = 0;
        //data buffer
        buf[0] = rq->dev_addr << 1; //dev addr+write
        for (i = 0; i < rq->reg_addr_sz; i++) {
            buf[i + 1] = (rq->reg_addr >> 8 * (rq->reg_addr_sz - 1 - i)) & 0xff;
        }
        packets[0].pbyBuf = (unsigned char *)buf;
        //transfer size
        packets[0].wLen = rq->reg_addr_sz + 1;

        //device address
        packets[1].byAddr = rq->dev_addr;
        packets[1].byRW = I2C_RW_WRITE;
        //result
        packets[1].lpiResult = 0;
        //data buffer
        buf1 = (rq->dev_addr << 1) | 0x1;   //dev addr+read

        packets[1].pbyBuf = (unsigned char *)&buf1;

        packets[1].wLen = 1;

        //device address
        packets[2].byAddr = rq->dev_addr;
        packets[2].byRW = I2C_RW_READ;
        //result
        packets[2].lpiResult = 0;

        packets[2].pbyBuf = (unsigned char *)recbuf;

        packets[2].wLen = rq->buffer_sz;

        ProcessPackets(packets, 3);

        memcpy_byte((char *)rq->buffer, (char *)packets[2].pbyBuf, rq->buffer_sz);

    } else if (dir == 0) {      //write
        //device address
        packets[0].byAddr = rq->dev_addr;
        packets[0].byRW = I2C_RW_WRITE;
        //result
        packets[0].lpiResult = 0;
        //data buffer
        buf[0] = rq->dev_addr << 1; //dev addr+write
        for (i = 0; i < rq->reg_addr_sz; i++) {
            buf[i + 1] = (rq->reg_addr >> 8 * (rq->reg_addr_sz - 1 - i)) & 0xff;
        }
        for (i = 0; i < rq->buffer_sz; i++) {
            buf[i + 1 + rq->reg_addr_sz] = rq->buffer[i];
        }

        packets[0].pbyBuf = (unsigned char *)buf;
        //transfer size
        packets[0].wLen = rq->reg_addr_sz + rq->buffer_sz + 1;

        ProcessPackets(packets, 1);

    }

    return ret;
}

/*!
 * transfer data for ltc2478
 *
 * @param   i2c_nr  i2c device number
 * @param   rq  i2c request
 * @param   dir read/wirte
 */
int i2c_xfer_ltc2487(unsigned int i2c_nr, struct mxc_i2c_request *rq, int dir)
{
    unsigned char i;
    int ret = 0;
    I2C_PACKET packets[8];
    char buf[8] = { 0 };
    char recbuf[8] = { 0 };
    unsigned int buf1;

    if (dir == 1)               // read
    {

        //device address
        packets[0].byAddr = rq->dev_addr;
        packets[0].byRW = I2C_RW_WRITE;
        //result
        packets[0].lpiResult = 0;
        //data buffer
        buf1 = (rq->dev_addr << 1) | 0x1;   //dev addr+read
        packets[0].pbyBuf = (unsigned char *)&buf1;
        packets[0].wLen = 1;

        //device address
        packets[1].byAddr = (rq->dev_addr);
        packets[1].byRW = I2C_RW_READ;
        //result
        packets[1].lpiResult = 0;
        packets[1].pbyBuf = (unsigned char *)recbuf;
        packets[1].wLen = rq->buffer_sz;

        ProcessPackets(packets, 2);

        memcpy_byte((char *)rq->buffer, (char *)packets[1].pbyBuf, rq->buffer_sz);

    } else if (dir == 0) {      //write
        //device address
        packets[0].byAddr = rq->dev_addr;
        packets[0].byRW = I2C_RW_WRITE;
        //result
        packets[0].lpiResult = 0;
        //data buffer
        buf[0] = rq->dev_addr << 1; //dev addr+write
        for (i = 0; i < rq->reg_addr_sz; i++) {
            buf[i + 1] = (rq->reg_addr >> 8 * (rq->reg_addr_sz - 1 - i)) & 0xff;
        }
        for (i = 0; i < rq->buffer_sz; i++) {
            buf[i + 1 + rq->reg_addr_sz] = rq->buffer[i];
        }

        packets[0].pbyBuf = (unsigned char *)buf;
        //transfer size
        packets[0].wLen = rq->reg_addr_sz + rq->buffer_sz + 1;

        ProcessPackets(packets, 1);

    }

    return ret;
}

/*!
 * Initialize and enable a i2c module -- mainly enable the I2C clock, module
 * itself and the I2C clock prescaler.
 *
 * @param   base        base address of SoC i2c module (also assigned for I2Cx_CLK)
 * @param   baue        the desired data rate
 *
 * @return              0 if successful; non-zero otherwise
 */
int i2c_init(unsigned int base, unsigned int baud)
{
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    //pin mux
    i2c_pinmux();
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    // reset and enable I2C
    HW_I2C_CTRL0_CLR(BM_I2C_CTRL0_SFTRST);
    HW_I2C_CTRL0_CLR(BM_I2C_CTRL0_CLKGATE);

    // asserting soft-reset
    HW_I2C_CTRL0_SET(BM_I2C_CTRL0_SFTRST);

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    // waiting for confirmation of soft-reset
    while (!HW_I2C_CTRL0.B.CLKGATE) ;
    // Done.

    HW_I2C_CTRL0_CLR(BM_I2C_CTRL0_SFTRST);
    HW_I2C_CTRL0_CLR(BM_I2C_CTRL0_CLKGATE);
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    ApbxDmaInit();
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    // disable the I2C DMA interrupts
    ApbxDmaEnableCommandCmpltIrq(HW_APBX_DMA_I2C0_CHANNEL, FALSE);
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    // Put the DMA in RESET State
    ApbxDmaResetChan(HW_APBX_DMA_I2C0_CHANNEL, TRUE);
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    return 0;
}

/*!
 * Test I2C eeprom at24cxx
 *
 *
 * @return              0 if successful; non-zero otherwise
 */
static int i2c_eeprom_at24cxx_test(void)
{
    char buf[4];
    unsigned int byteAddr = 100;
    struct mxc_i2c_request rq;

    test_flag_simple_i2c_device = 0;

    rq.dev_addr = MX28_I2C_EEPROM_DEV_ADDRESS >> 1;
    rq.reg_addr = byteAddr;
    rq.reg_addr_sz = 2;
    rq.buffer_sz = 3;
    rq.buffer = (unsigned char *)buf;

    buf[0] = 'F';               //0x89;
    buf[1] = 'S';               //0x11;
    buf[2] = 'L';
    printf("mx28 evk i2c test:\n");

    printf("+test i2c eeprom\n");
    printf("Write to Data : 0x%x, 0x%x, 0x%x\n", buf[0], buf[1], buf[2]);
    //1- read, 0- write
    i2c_xfer(0, &rq, 0);

    printf("Read back Data: ");

    rq.dev_addr = MX28_I2C_EEPROM_DEV_ADDRESS >> 1;
    rq.reg_addr = byteAddr;
    rq.reg_addr_sz = 2;
    rq.buffer_sz = 3;
    rq.buffer = (unsigned char *)buf;

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    i2c_xfer(0, &rq, 1);

    printf("0x%x, 0x%x, 0x%x\n", rq.buffer[0], rq.buffer[1], rq.buffer[2]);

    if ((rq.buffer[0] != 'F') || (rq.buffer[1] != 'S') || (rq.buffer[2] != 'L')) {
        printf("i2c eeprom test fail.\n");
        printf("please make sure EEPROM is mounted on board\n");
        return 1;
    } else {
        printf("i2c eeprom test pass.\n");
        return 0;
    }
}

typedef union {
    unsigned char adc_rd_buf[3];
} adc_rd_reg_t;

/*!
 * Test I2C adc ltc2478
 * @return      TEST_PASSED or TEST_FAILED
 */
static int i2c_adc_ltc2487_test(void)
{
    int retVal = TEST_PASSED;
    struct mxc_i2c_request rq;
    adc_rd_reg_t rdval;
    unsigned short sig_msb, reg_val, all_zero;

    rdval.adc_rd_buf[0] = 0;
    rdval.adc_rd_buf[1] = 0;
    rdval.adc_rd_buf[2] = 0;
    printf("%s, %d\n", __FUNCTION__, __LINE__);
    //set USB_0_OC, bank3_pin06 as GPIO
    printf("0x%x=0x%x\n", HW_PINCTRL_MUXSEL6_SET, *(volatile unsigned int *)HW_PINCTRL_MUXSEL6_SET);
    *(volatile unsigned int *)HW_PINCTRL_MUXSEL6_SET |= (0x3 << 12);
    printf("0x%x=0x%x\n", HW_PINCTRL_MUXSEL6_SET, *(volatile unsigned int *)HW_PINCTRL_MUXSEL6_SET);

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    //set output LOW
    printf("0x%x=0x%x\n", HW_PINCTRL_DOUT3_CLR, *(volatile unsigned int *)HW_PINCTRL_DOUT3_CLR);
    *(volatile unsigned int *)HW_PINCTRL_DOUT3_CLR |= (1 << 6);
    printf("0x%x=0x%x\n", HW_PINCTRL_DOUT3_CLR, *(volatile unsigned int *)HW_PINCTRL_DOUT3_CLR);

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    //enable output, VDDIO_ID should be 3v now
    printf("0x%x=0x%x\n", HW_PINCTRL_DOE3_SET, *(volatile unsigned int *)HW_PINCTRL_DOE3_SET);
//    *(volatile unsigned int *)HW_PINCTRL_DOE3_SET |= (1 << 6);
    printf("0x%x=0x%x\n", HW_PINCTRL_DOE3_SET, *(volatile unsigned int *)HW_PINCTRL_DOE3_SET);
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    hal_delay_us(20000);        //delay wait for ltc2487 complete reset

    printf("+test i2c ADC LTC2487: \n");

    test_flag_simple_i2c_device = 1;

    //read conversion value
    rq.dev_addr = MX28_I2C_ADC_LTC2487_DEV_ADDRESS >> 1;
    rq.reg_addr = 0;            //byteAddr;
    rq.reg_addr_sz = 0;
    rq.buffer_sz = 3;
    rq.buffer = (unsigned char *)&rdval;    //buf;

    printf("%s, %d\n", __FUNCTION__, __LINE__);
    i2c_xfer_ltc2487(0, &rq, 1);    //read
    printf("%s, %d\n", __FUNCTION__, __LINE__);

    printf("buffer bytes  : 0x%02x, 0x%02x, 0x%02x\n", rq.buffer[0], rq.buffer[1], rq.buffer[2]);

    sig_msb = (unsigned short)rq.buffer[0];
    reg_val = (unsigned short)rq.buffer[1];
    all_zero = (unsigned short)rq.buffer[2];

    reg_val = ((sig_msb & 0x3F) << 11) | ((reg_val & 0xFFFF) << 3) | ((all_zero & 0xC0) >> 6);
    sig_msb = (sig_msb & 0xC0) >> 6;
    all_zero = all_zero & 0x3F;
    printf("ltc2487 reg   : \n");
    printf("      sig_msb :0x%02x\n", sig_msb);
    printf("      reg_val :0x%04x\n", reg_val);
    printf("      all_zero:0x%02x\n", all_zero);

    if ((sig_msb == 0x00) || all_zero)
        retVal = TEST_FAILED;
    return retVal;
}

/*!
 * Test I2C
 * @return      TEST_PASSED or TEST_FAILED
 */
static int i2c_test(void)
{
    int retVal = 0, retVal1 = 0, retVal2 = 0;

    PROMPT_RUN_TEST("I2C");
    i2c_init(0, 0);

    retVal2 = i2c_adc_ltc2487_test();

    /* Since the EVKs do not populate the EEPROM, do not test */
//    retVal1 = i2c_eeprom_at24cxx_test();

    test_flag_simple_i2c_device = 0;
    if (retVal1 || retVal2)
        retVal = 1;

    return retVal;
}

//RUN_TEST("I2C", i2c_test)
