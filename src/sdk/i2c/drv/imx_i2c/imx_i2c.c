/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "hardware.h"
#include "imx_i2c.h"

/* Max number of operations to wait to receuve ack */
#define WAIT_RXAK_LOOPS     1000000

/*!
 * Loop status register for IBB to go 0
 * The loop breaks on max number of iterations
 *
 * @param   base        base address of i2c module 
 *
 * @return              0 if successful; -1 otherwise
 */
static inline int is_bus_free(unsigned int base)
{
    int i = WAIT_RXAK_LOOPS;

    while ((readw(base + I2C_I2SR) & I2C_I2SR_IBB) && (--i > 0)) ;

    if (i <= 0) {
        printf("Error: I2C Bus not free!\n");
        return -1;
    }

    return 0;
}

/*!
 * Loop status register for IBB to go 1.
 * It breaks the loop if there's an arbitration lost occurred or max iterations
 *
 * @param   base        base address of i2c module 
 *
 * @return              0 if successful; -1 otherwise
 */
static int wait_till_busy(uint32_t base)
{
    int i = 100000;

    while (((readw(base + I2C_I2SR) & I2C_I2SR_IBB) == 0) && (--i > 0)) {
        if (readw(base + I2C_I2SR) & I2C_I2SR_IAL) {
            printf("Error: arbitration lost!\n");
            return -1;
        }
    }

    if (i <= 0) {
        printf("I2C Error: timeout in %s; %d\n", __FUNCTION__, __LINE__);
        return -1;
    }

    return 0;
}

/*!
 * Generates a STOP signal, called by rx and tx routines
 *
 * @param   base        base address of i2c module 
 *
 * @return              none
 */
static inline void imx_send_stop(unsigned int base)
{
    writew((readw(base + I2C_I2CR) & ~(I2C_I2CR_MSTA)), base + I2C_I2CR);
}

/*!
 * wait for operation done
 * This function loops until we get an interrupt. On timeout it returns -1.
 * It reports arbitration lost if IAL bit of I2SR register is set
 * Clears the interrupt
 * If operation is transfer byte function will make sure we received an ack
 *
 * @param   base        base address of i2c module 
 * @param   is_tx       Pass 1 for transfering, 0 for receiving 
 *
 * @return              0 if successful; negative integer otherwise
 */
static int wait_op_done(uint32_t base, int is_tx)
{
    volatile unsigned short v;
    int i = WAIT_RXAK_LOOPS;

    /* Loop until we get an interrupt */
    while ((((v = readw(base + I2C_I2SR)) & I2C_I2SR_IIF) == 0) && (--i > 0)) ;

    /* If timeout error occurred return error */
    if (i <= 0) {
        printf1("I2C Error: timeout unexpected\n");
        return -1;
    }

    /* Clear the interrupt */
    writew(0x0, base + I2C_I2SR);

    /* Check for arbitration lost */
    if (v & I2C_I2SR_IAL) {
        printf1("Error %d: Arbitration lost\n", __LINE__);
        return ERR_ARB_LOST;
    }

    /* Check for ACK received in transmit mode */
    if (is_tx) {
        if (v & I2C_I2SR_RXAK) {
            /* No ACK received, generate STOP by clearing MSTA bit */
            printf1("Error %d: no ack received\n", __LINE__);
            /* Generate a STOP signal */
            imx_send_stop(base);
            return ERR_NO_ACK;
        }
    }

    return 0;
}

/*!
 * For master TX
 * Implements a loop to send a byte to i2c slave.
 * Always expect a RXAK signal to be set!
 *
 * @param   base        base address of i2c module 
 * @param   data        return buffer for data
 *
 * @return              0 if successful; -1 otherwise
 */
static int tx_byte(uint8_t * data, uint32_t base)
{
    int ret = 0;
    printf1("%s(data=0x%02x, base=0x%x)\n", __FUNCTION__, *data, base);

    /* clear both IAL and IIF bits */
    writew(0, base + I2C_I2SR);

    /* clear data register */
    writew(*data, base + I2C_I2DR);

    /* wait for transfer of byte to complete */
    if ((ret = wait_op_done(base, 1)) != 0)
        return ret;

    return ret;
}

/*!
 * For master RX
 * Implements a loop to receive bytes from i2c slave.
 *
 * @param   base        base address of i2c module 
 * @param   data        return buffer for data
 * @param   sz          number of bytes to receive
 *
 * @return              0 if successful; -1 otherwise
 */
static int rx_bytes(uint8_t * data, uint32_t base, int sz)
{
    unsigned short i2cr;
    int i, ret = 0;

    for (i = 0; sz > 0; sz--, i++) {
        if (wait_op_done(base, 0) != 0)
            return -1;

        /* the next two if-statements setup for the next read control register value */
        if (sz == 1) {
            /* last byte --> generate STOP */
            imx_send_stop(base);
        }

        if (sz == 2) {
            /* 2nd last byte --> set TXAK bit to NOT generate ACK */
            i2cr = readw(base + I2C_I2CR);
            writew(i2cr | I2C_I2CR_TXAK, base + I2C_I2CR);
        }
        /* read the true data */
        data[i] = readw(base + I2C_I2DR);
        printf1("OK 0x%02x\n", data[i]);
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
 * @param dir       I2C_READ/I2C_WRITE
 *
 * @return          0 on success; non-zero otherwise
 */
int i2c_xfer(uint32_t base, struct imx_i2c_request *rq, int dir)
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
    /* reset and enable I2C */
    writew(0, base + I2C_I2CR);
    writew(I2C_I2CR_IEN, base + I2C_I2CR);
    /* Need wait at least 2 cycles of per_clk */
    hal_delay_us(5000);

    /* 1.2 clear both IAL and IIF bits */
    writew(0, base + I2C_I2SR);

    /* 1.3 assert START signal and also indicate TX mode */
    i2cr = I2C_I2CR_IEN;
    writew(i2cr, base + I2C_I2CR);
    i2cr = I2C_I2CR_IEN | I2C_I2CR_MTX;
    writew(i2cr, base + I2C_I2CR);
    i2cr = I2C_I2CR_IEN | I2C_I2CR_MSTA | I2C_I2CR_MTX;
    writew(i2cr, base + I2C_I2CR);

    /* 1.4 make sure bus is busy after the START signal */
    if (wait_till_busy(base) != 0) {
        printf1("1\n");
        return -1;
    }
    /* Step 2: send slave address + read/write at the LSB */
    data = (rq->dev_addr << 1) | I2C_WRITE;

    if ((ret = tx_byte(&data, base)) != 0) {
        printf1("START TX ERR %d\n", ret);

        if (ret == ERR_NO_ACK) {
            return ERR_NO_ACK_ON_START;
        } else {
            return ret;
        }
    }
    /* Step 3: send I2C device register address */
    if (rq->reg_addr_sz > 4) {
        printf("Warning register address size %d should less than 4\n", rq->reg_addr_sz);
        rq->reg_addr_sz = 4;
    }

    reg = rq->reg_addr;

    for (i = 0; i < rq->reg_addr_sz; i++, reg >>= 8) {
        data = reg & 0xFF;
        printf1("sending I2C=0x%x device register: data=0x%x, byte %d\n", base, data, i);

        if (tx_byte(&data, base) != 0) {
            return -1;
        }
    }

    /* Step 4: read/write data */
    if (dir == I2C_READ) {
        /* do repeat-start */
        i2cr = readw(base + I2C_I2CR);
        writew(i2cr | I2C_I2CR_RSTA, base + I2C_I2CR);

        /* make sure bus is busy after the REPEATED START signal */
        if (wait_till_busy(base) != 0) {
            return ERR_TX;
        }
        /* send slave address again, but indicate read operation */
        data = (rq->dev_addr << 1) | I2C_READ;

        if (tx_byte(&data, base) != 0) {
            return -1;
        }
        /* change to receive mode */
        i2cr = readw(base + I2C_I2CR);

        if (rq->buffer_sz == 1) {
            /* if only one byte to read, make sure don't send ack */
            i2cr |= I2C_I2CR_TXAK;
        }

        writew(i2cr & ~I2C_I2CR_MTX, base + I2C_I2CR);
        /* dummy read */
        readw(base + I2C_I2DR);

        /* now reading ... */
        if (rx_bytes(rq->buffer, base, rq->buffer_sz) != 0) {
            return -1;
        }
    } else {
        /* I2C_WRITE */
        for (i = 0; i < rq->buffer_sz; i++) {
            /* send device register value */
            data = rq->buffer[i];

            if ((ret = tx_byte(&data, base)) != 0) {
                break;
            }
        }

        /* generate STOP by clearing MSTA bit */
        imx_send_stop(base);
    }

    /* Check if bus is free, if not return error */
    if (is_bus_free(base) != 0) {
        printf("WARNING: bus is not free\n");
    }
    writew(0, base + I2C_I2CR);

    return ret;
}

/*!
 * Initialize and enable a i2c module -- mainly enable the I2C clock, module
 * itself and the I2C clock prescaler.
 *
 * @param   base        base address of i2c module (also assigned for I2Cx_CLK)
 * @param   baud        the desired data rate
 *
 * @return              0 if successful; non-zero otherwise
 */
int i2c_init(uint32_t base, uint32_t baud)
{
    /* Set iomux configuration */
    io_cfg_i2c(base);

    /* reset I2C */
    writew(0, base + I2C_I2CR);

    /* 
     * since we find a valid divider, it is time to configure the frequency 
     *  divider register 
     */
    writew(0x14, base + I2C_IFDR);
    writew(I2C_I2CR_IEN, base + I2C_I2CR);

    return 0;
}
