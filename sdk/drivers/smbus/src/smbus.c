/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/* SMBus is a subset of I2C specification. The max. frequency is 100KHz,
 * while the min. frequency is 10KHz.
 * SMBus can use the interface of I2C, but the SMBus devices usually don't 
 * have the address pins. The SMBus device must be enumerated by sending
 * GUID command and Assign address command.
*/
#include "smbus/smbus.h"
#define WAIT_RXAK_LOOPS     1000000
#define SMBUS_CLK_FREQ      80000   /*80kHz */

#define I2C_IADR       0x0
#define I2C_IFDR       0x4
#define I2C_I2CR       0x8
#define I2C_I2SR       0xC
#define I2C_I2DR       0x10          
#define I2C_I2CR_IEN   (1<<7)
#define I2C_I2CR_IIEN  (1<<6)
#define I2C_I2CR_MSTA  (1<<5)
#define I2C_I2CR_MTX   (1<<4)
#define I2C_I2CR_TXAK  (1<<3)
#define I2C_I2CR_RSTA  (1<<2)

#define I2C_I2SR_ICF   (1<<7)
#define I2C_I2SR_IAAS  (1<<6)
#define I2C_I2SR_IBB   (1<<5)
#define I2C_I2SR_IAL   (1<<4)
#define I2C_I2SR_SRW   (1<<2)
#define I2C_I2SR_IIF   (1<<1)
#define I2C_I2SR_RXAK  (1<<0)

struct clk_div_table {
    int reg_value;
    int div;
};

static const struct clk_div_table smbus_clk_table[] = {
    {0x20, 22}, {0x21, 24}, {0x22, 26}, {0x23, 28},
    {0, 30}, {1, 32}, {0x24, 32}, {2, 36},
    {0x25, 36}, {0x26, 40}, {3, 42}, {0x27, 44},
    {4, 48}, {0x28, 48}, {5, 52}, {0x29, 56},
    {6, 60}, {0x2A, 64}, {7, 72}, {0x2B, 72},
    {8, 80}, {0x2C, 80}, {9, 88}, {0x2D, 96},
    {0xA, 104}, {0x2E, 112}, {0xB, 128}, {0x2F, 128},
    {0xC, 144}, {0xD, 160}, {0x30, 160}, {0xE, 192},
    {0x31, 192}, {0x32, 224}, {0xF, 240}, {0x33, 256},
    {0x10, 288}, {0x11, 320}, {0x34, 320}, {0x12, 384},
    {0x35, 384}, {0x36, 448}, {0x13, 480}, {0x37, 512},
    {0x14, 576}, {0x15, 640}, {0x38, 640}, {0x16, 768},
    {0x39, 768}, {0x3A, 896}, {0x17, 960}, {0x3B, 1024},
    {0x18, 1152}, {0x19, 1280}, {0x3C, 1280}, {0x1A, 1536},
    {0x3D, 1536}, {0x3E, 1792}, {0x1B, 1920}, {0x3F, 2048},
    {0x1C, 2304}, {0x1D, 2560}, {0x1E, 3072}, {0x1F, 3840},
    {0, 0}
};

static const uint8_t smbus_reserved_address_pool[] = {
    0x00,                       /*General Call Address, when bit 0 is 0;
                                   START byte, when bit0 is 1 */
    0x01,                       /*CBUS address */
    0x02,                       /*reserved for different bus format */
    0x03, 0x04, 0x05, 0x06, 0x7,    /*reserved */
    0x08,                       /*SMBus Host Address */
    0x09,                       /*Smart Battery Charger */
    0x0A,                       /*Smart Battery System Manager */
    0x0B,                       /*Smart Battery */
    0x0C,                       /*SMBus Alert Response */
    0x28,                       /*ACCESS.bus host */
    0x2C,                       /*reserved */
    0x2D,                       /*reserved */
    0x37,                       /*ACCESS.bus default address */
    0x40, 0x41, 0x42, 0x43, 0x44,   /*reserved */
    0x48, 0x49, 0x4A, 0x4B,     /*prototype addresses */
    0x61,                       /*SMBus Device Default Address */
    0x78, 0x79, 0x7A, 0x7B,     /*10-bit addressing */
    0x7C, 0x7D, 0x7E, 0x7F,     /*reserved */
};

#define I2C_DELAY(count)        \
{                               \
    volatile uint32_t loop = count;  \
    while (loop -- != 0) {      \
    }                           \
}

static inline int is_bus_free(unsigned int base)
{
    int i = WAIT_RXAK_LOOPS;

    while ((readw(base + I2C_I2SR) & I2C_I2SR_IBB) && (--i > 0)) ;

    if (i <= 0) {
        printf("Error: SMBus is not free!\n");
        return -1;
    }

    return 0;
}

static int wait_till_busy(uint32_t base)
{
    int i = 100000;

    while (((readw(base + I2C_I2SR) & I2C_I2SR_IBB) == 0) && (--i > 0)) {
        if (readw(base + I2C_I2SR) & I2C_I2SR_IAL) {
            printf("SMBus Error: arbitration lost!\n");
            return -1;
        }
    }

    if (i <= 0) {
        printf("SMBus Error: timeout in %s; %d\n", __FUNCTION__, __LINE__);
        return -1;
    }

    return 0;
}

#define ASSERT_NO_ARBITRATION_LOST(stat)  \
{ \
    if (stat & I2C_I2SR_IAL) { \
        printf("SMBus Error %d: Arbitration lost\n", __LINE__); \
        return -1; \
    } \
}

static inline void imx_send_stop(unsigned int base)
{
    writew((readw(base + I2C_I2CR) & ~(I2C_I2CR_MSTA)), base + I2C_I2CR);
}

static int wait_op_done(uint32_t base, int is_tx)
{
    volatile unsigned short v;
    int i = WAIT_RXAK_LOOPS;

    while ((((v = readw(base + I2C_I2SR)) & I2C_I2SR_IIF) == 0) && (--i > 0)) ;

    if (i <= 0) {
        printf("SMBus Error: timeout unexpected\n");
        return -1;
    }

    writew(0x0, base + I2C_I2SR);

    if (v & I2C_I2SR_IAL) {
        printf("SMBus Error %d: Arbitration lost\n", __LINE__);
        return ERR_ARB_LOST;
    }

    if (is_tx) {
        if (v & I2C_I2SR_RXAK) {
            printf("SMBus Error %d: no ack received\n", __LINE__);
            /* Generate a STOP signal */
            imx_send_stop(base);
            return ERR_NO_ACK;
        }
    }

    return 0;
}

// For master TX, always expect a RXAK signal to be set!
static int smbus_tx_byte(uint8_t * data, uint32_t base)
{
    int ret = 0;
    printf("%s(data=0x%02x, base=0x%x)\n", __FUNCTION__, *data, base);

    // clear both IAL and IIF bits
    writew(0, base + I2C_I2SR);

    writew(*data, base + I2C_I2DR);

    if ((ret = wait_op_done(base, 1)) != 0)
        return ret;

    return ret;
}

// For master RX
static int smbus_rx_bytes(uint8_t * data, uint32_t base, int sz)
{
    unsigned short i2cr;
    int i, ret = 0;

    for (i = 0; sz > 0; sz--, i++) {
        if (wait_op_done(base, 0) != 0)
            return -1;

        // the next two if-statements setup for the next read control register value
        if (sz == 1) {
            // last byte --> generate STOP
            imx_send_stop(base);
        }

        if (sz == 2) {
            // 2nd last byte --> set TXAK bit to NOT generate ACK
            i2cr = readw(base + I2C_I2CR);
            writew(i2cr | I2C_I2CR_TXAK, base + I2C_I2CR);
        }
        // read the true data
        data[i] = readw(base + I2C_I2DR);
        printf("OK 0x%02x\n", data[i]);
    }

    return ret;
}

/*!
 * This is a rather simple function that can be used for most i2c devices.
 * Common steps for both READ and WRITE:
 *      step 1: issue start signal
 *      step 2: put i2c device addr on the bus (always 1 byte write. the dir always I2C_WRITE)
 *      step 3: offset of the i2c device write (offset within the device. can be 1-4 bytes)
 * For READ:
 *      step 4: do repeat-start
 *      step 5: send slave address again, but indicate a READ operation by setting LSB bit
 *      Step 6: change to receive mode
 *      Step 7: dummy read
 *      Step 8: reading
 * For WRITE:
 *      Step 4: do data write
 *      Step 5: generate STOP by clearing MSTA bit
 *
 * @param base      i.MX i2c module base
 * @param rq        pointer to struct imx_i2c_request
 * @param dir       SMBUS_WRITE(0)/SMBUS_READ(1)
 *
 * @return          0 on success; non-zero otherwise
 */
int smbus_xfer(uint32_t base, struct imx_i2c_request *rq, int dir)
{
    unsigned int reg;
    unsigned char i, data;
    unsigned short i2cr;

    int ret = 0;

    if (rq->buffer_sz == 0 || rq->buffer == NULL) {
        printf("Invalid register address size=%x, buffer size=%x, buffer=%x\n",
               rq->reg_addr_sz, rq->buffer_sz, (unsigned int)rq->buffer);
        return -1;
    }

    /* Check if bus is free, if not return error */
    if (is_bus_free(base) != 0) {
        return -1;
    }
    // reset and enable I2C
    writew(0, base + I2C_I2CR);
    writew(I2C_I2CR_IEN, base + I2C_I2CR);
    /* Need wait at least 2 cycles of per_clk */
    hal_delay_us(5000);

    // 1.2 clear both IAL and IIF bits
    writew(0, base + I2C_I2SR);

    // 1.3 assert START signal and also indicate TX mode
    i2cr = I2C_I2CR_IEN;
    writew(i2cr, base + I2C_I2CR);
    i2cr = I2C_I2CR_IEN | I2C_I2CR_MTX;
    writew(i2cr, base + I2C_I2CR);
    i2cr = I2C_I2CR_IEN | I2C_I2CR_MSTA | I2C_I2CR_MTX;
    writew(i2cr, base + I2C_I2CR);

    // 1.4 make sure bus is busy after the START signal
    if (wait_till_busy(base) != 0) {
        printf("1\n");
        return -1;
    }
    // Step 2: send slave address + read/write at the LSB
    data = (rq->dev_addr << 1) | I2C_WRITE;

    if ((ret = smbus_tx_byte(&data, base)) != 0) {
        printf("START TX ERR %d\n", ret);

        if (ret == ERR_NO_ACK) {
            return ERR_NO_ACK_ON_START;
        } else {
            return ret;
        }
    }
    // Step 3: send I2C device register address
    if (rq->reg_addr_sz > 4) {
        printf("Warning register address size %d should less than 4\n", rq->reg_addr_sz);
        rq->reg_addr_sz = 4;
    }

    reg = rq->reg_addr;

    for (i = 0; i < rq->reg_addr_sz; i++, reg >>= 8) {
        data = reg & 0xFF;
        printf("sending I2C=0x%x device register: data=0x%x, byte %d\n", base, data, i);

        if (smbus_tx_byte(&data, base) != 0) {
            return -1;
        }
    }

    // Step 4: read/write data
    if (dir == I2C_READ) {
        // do repeat-start
        i2cr = readw(base + I2C_I2CR);
        writew(i2cr | I2C_I2CR_RSTA, base + I2C_I2CR);

        // make sure bus is busy after the REPEATED START signal
        if (wait_till_busy(base) != 0) {
            return ERR_TX;
        }
        // send slave address again, but indicate read operation
        data = (rq->dev_addr << 1) | I2C_READ;

        if (smbus_tx_byte(&data, base) != 0) {
            return -1;
        }
        // change to receive mode
        i2cr = readw(base + I2C_I2CR);

        if (rq->buffer_sz == 1) {
            // if only one byte to read, make sure don't send ack
            i2cr |= I2C_I2CR_TXAK;
        }

        writew(i2cr & ~I2C_I2CR_MTX, base + I2C_I2CR);
        // dummy read
        readw(base + I2C_I2DR);

        // now reading ...
        if (smbus_rx_bytes(rq->buffer, base, rq->buffer_sz) != 0) {
            return -1;
        }
    } else {
        // I2C_WRITE
        for (i = 0; i < rq->buffer_sz; i++) {
            // send device register value
            data = rq->buffer[i];

            if ((ret = smbus_tx_byte(&data, base)) != 0) {
                break;
            }
        }

        // generate STOP by clearing MSTA bit
        imx_send_stop(base);
    }

    return ret;
}

/*!
 * Initialize and enable a i2c module -- mainly enable the I2C clock, module
 * itself and the I2C clock prescaler.
 *
 * @param   base        base address of i2c module (also assigned for I2Cx_CLK)
 * @param   baue        the desired data rate
 *
 * @return              0 if successful; non-zero otherwise
 */
int smbus_init(uint32_t base, uint32_t baud)
{
    uint32_t clock = get_main_clock(IPG_PER_CLK);
    uint32_t i, tmp;
    uint32_t reg_value;
//    io_cfg_i2c(base);
    i2c_iomux_config(base);

    // reset I2C
    writew(0, base + I2C_I2CR);

    for (i = 0; i < sizeof(smbus_clk_table); i++) {
        tmp = (clock / smbus_clk_table[i].div);
        if ((tmp < baud) && (tmp >= (baud * 8 / 10))) {
            reg_value = smbus_clk_table[i].reg_value;
        } else {
            continue;
        }
    }

    if (i == sizeof(smbus_clk_table)) {
        printf("! SMBUS init fail\n");
        return 1;
    }
    // since we find a valid divider, it is time to configure the register
    writew(reg_value, base + I2C_IFDR);
    writew(I2C_I2CR_IEN, base + I2C_I2CR);

    return 0;
}

/*!
 * Issue prepare to ARP command onto the SMBus
 *
 * @param   n/a
 *                   
 *
 * @return              0 if successful; non-zero otherwise
 */
int smbus_prepare_to_arp(void)
{
    struct imx_i2c_request req;
    uint8_t cmd = SMBUS_CMD_PREPARE_TO_ARP;

    req.dev_addr = SMBUS_DEVICE_DEFAULT_ADDRESS;
    req.reg_addr = 0;
    req.reg_addr_sz = 0;
    req.buffer = &cmd;
    req.buffer_sz = 1;

    if (smbus_init(I2C2_BASE_ADDR, SMBUS_CLK_FREQ))
        return 1;

    if (smbus_xfer(I2C2_BASE_ADDR, &req, SMBUS_WRITE))
        return 1;

    return 0;
}

/*!
 * Issue Reset Device command onto the SMBus
 *
 * @param   addr        device addres(if default address, will issue general
 *                      reset command)
 *                   
 *
 * @return              0 if successful; non-zero otherwise
 */
int smbus_reset_device(uint8_t dev_addr)
{
    struct imx_i2c_request req;
    uint8_t cmd = SMBUS_CMD_RESET_DEVICE_GENERAL;

    req.dev_addr = SMBUS_DEVICE_DEFAULT_ADDRESS;
    req.reg_addr = 0;
    req.reg_addr_sz = 0;
    req.buffer = &cmd;
    req.buffer_sz = 1;

    if (smbus_init(I2C2_BASE_ADDR, SMBUS_CLK_FREQ))
        return 1;

    if (smbus_xfer(I2C2_BASE_ADDR, &req, SMBUS_WRITE))
        return 1;

    return 0;
}

/*!
 * Issue Get UDID command onto the SMBus
 *
 * @param   addr        device addres(if default address, will issue general
 *                      reset command)
 * @param   ptr         The pointer to save udid read from device                  
 *
 * @return              0 if successful; non-zero otherwise
 */
int smbus_get_udid(uint8_t * dev_addr, smbus_device_udid_t * ptr)
{
    struct imx_i2c_request req;
    uint8_t cmd = SMBUS_CMD_GET_UDID_GENERAL;
    uint8_t data[18];

    req.dev_addr = SMBUS_DEVICE_DEFAULT_ADDRESS;
    req.reg_addr = 0;
    req.reg_addr_sz = 0;
    req.buffer = &cmd;
    req.buffer_sz = 1;

    if (smbus_init(I2C2_BASE_ADDR, SMBUS_CLK_FREQ))
        return 1;

    if (smbus_xfer(I2C2_BASE_ADDR, &req, SMBUS_WRITE))
        return 1;

    req.dev_addr = SMBUS_DEVICE_DEFAULT_ADDRESS;
    req.reg_addr = 0;
    req.reg_addr_sz = 0;
    req.buffer = data;
    req.buffer_sz = 18;

    if (smbus_xfer(I2C2_BASE_ADDR, &req, SMBUS_READ))
        return 1;

    if (data[0] != 17) {
        printf("!SMBus Error: Get UDID wrong number data\n");
        return 1;
    }

    memcpy((char *)ptr, (data + 1), 16);
    *dev_addr = data[17];

    return 0;

}

/*!
 * Assign an address to a device which just responds to Get UDID command
 *
 * @param   addr        device address
 *                   
 *
 * @return              0 if successful; non-zero otherwise
 */
int smbus_assign_address(uint8_t * dev_addr, smbus_device_udid_t * ptr)
{
    struct imx_i2c_request req;
    uint8_t cmd = SMBUS_CMD_ASSIGN_ADDRESS;
    uint8_t data[20];

    data[0] = cmd;
    data[1] = 17;
    memcpy((data + 2), (char *)ptr, 16);
    data[19] = *dev_addr;

    req.dev_addr = SMBUS_DEVICE_DEFAULT_ADDRESS;
    req.reg_addr = 0;
    req.reg_addr_sz = 0;
    req.buffer = data;
    req.buffer_sz = 20;

    if (smbus_init(I2C2_BASE_ADDR, SMBUS_CLK_FREQ))
        return 1;

    if (smbus_xfer(I2C2_BASE_ADDR, &req, SMBUS_WRITE))
        return 1;

    return 0;
}
