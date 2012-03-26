/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_i2c.c
 * @brief Main driver for the I2C controller. It initializes the controller
 *        and handles the master mode.
 *
 * @ingroup diag_i2c
 */

#include "hardware.h"
#include "i2c/imx_i2c.h"

/* Max number of operations to wait to receuve ack */
#define WAIT_RXAK_LOOPS     1000000

#define I2C_DEBUG

#ifdef I2C_DEBUG
#define I2CDBG(fmt,args...) debug_printf(fmt, ## args)
#else
#define I2CDBG(fmt,args...)
#endif

#define get_status(x) readw(x + I2C_I2SR)

static const uint16_t i2c_freq_div[50][2] = {
        { 22,   0x20 }, { 24,   0x21 }, { 26,   0x22 }, { 28,   0x23 },
        { 30,   0x00 }, { 32,   0x24 }, { 36,   0x25 }, { 40,   0x26 },
        { 42,   0x03 }, { 44,   0x27 }, { 48,   0x28 }, { 52,   0x05 },
        { 56,   0x29 }, { 60,   0x06 }, { 64,   0x2A }, { 72,   0x2B },
        { 80,   0x2C }, { 88,   0x09 }, { 96,   0x2D }, { 104,  0x0A },
        { 112,  0x2E }, { 128,  0x2F }, { 144,  0x0C }, { 160,  0x30 },
        { 192,  0x31 }, { 224,  0x32 }, { 240,  0x0F }, { 256,  0x33 },
        { 288,  0x10 }, { 320,  0x34 }, { 384,  0x35 }, { 448,  0x36 },
        { 480,  0x13 }, { 512,  0x37 }, { 576,  0x14 }, { 640,  0x38 },
        { 768,  0x39 }, { 896,  0x3A }, { 960,  0x17 }, { 1024, 0x3B },
        { 1152, 0x18 }, { 1280, 0x3C }, { 1536, 0x3D }, { 1792, 0x3E },
        { 1920, 0x1B }, { 2048, 0x3F }, { 2304, 0x1C }, { 2560, 0x1D },
        { 3072, 0x1E }, { 3840, 0x1F }
};

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

static inline int is_bus_free(unsigned int base);
static int wait_till_busy(uint32_t base);
static inline void imx_send_stop(unsigned int base);
static int wait_op_done(uint32_t base, int is_tx);
static int tx_byte(uint8_t * data, uint32_t base);
static int rx_bytes(uint8_t * data, uint32_t base, int sz);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * Loop status register for IBB to go 0
 * The loop breaks on max number of iterations
 *
 * @param   base        base address of I2C module 
 *
 * @return  0 if successful; -1 otherwise
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
 * @param   base        base address of I2C module 
 *
 * @return  0 if successful; -1 otherwise
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
 * @param   base        base address of I2C module 
 *
 * @return  none
 */
static inline void imx_send_stop(unsigned int base)
{
    writew((readw(base + I2C_I2CR) & ~I2C_I2CR_MSTA), base + I2C_I2CR);
}

/*!
 * @brief Wait for operation done.
 *
 * This function loops until we get an interrupt. On timeout it returns -1.
 * It reports arbitration lost if IAL bit of I2SR register is set
 * Clears the interrupt
 * If operation is transfer byte function will make sure we received an ack
 *
 * @param   base        base address of I2C module 
 * @param   is_tx       Pass 1 for transfering, 0 for receiving 
 *
 * @return  0 if successful; negative integer otherwise
 */
static int wait_op_done(uint32_t base, int is_tx)
{
    volatile unsigned short v;
    int i = WAIT_RXAK_LOOPS;

    /* Loop until we get an interrupt */
    while ((((v = readw(base + I2C_I2SR)) & I2C_I2SR_IIF) == 0) && (--i > 0)) ;

    /* If timeout error occurred return error */
    if (i <= 0) {
        debug_printf("I2C Error: timeout unexpected\n");
        return -1;
    }

    /* Clear the interrupts */
    writew(0x0, base + I2C_I2SR);

    /* Check for arbitration lost */
    if (v & I2C_I2SR_IAL) {
        debug_printf("Error %d: Arbitration lost\n", __LINE__);
        return ERR_ARB_LOST;
    }

    /* Check for ACK received in transmit mode */
    if (is_tx) {
        if (v & I2C_I2SR_RXAK) {
            /* No ACK received, generate STOP by clearing MSTA bit */
            debug_printf("Error %d: no ack received\n", __LINE__);
            /* Generate a STOP signal */
            imx_send_stop(base);
            return ERR_NO_ACK;
        }
    }

    return 0;
}

/*!
 * For master TX
 * Implements a loop to send a byte to I2C slave.
 * Always expect a RXAK signal to be set!
 *
 * @param   base        base address of I2C module 
 * @param   data        return buffer for data
 *
 * @return  0 if successful; -1 otherwise
 */
static int tx_byte(uint8_t * data, uint32_t base)
{
    int ret;
    debug_printf("%s(data=0x%02x, base=0x%x)\n", __FUNCTION__, *data, base);

    /* clear both IAL and IIF bits */
    writew(0, base + I2C_I2SR);

    /* write to data register */
    writew(*data, base + I2C_I2DR);

    /* wait for transfer of byte to complete */
    ret = wait_op_done(base, 1);

    return ret;
}

/*!
 * For master RX
 * Implements a loop to receive bytes from I2C slave.
 *
 * @param   base        base address of I2C module 
 * @param   data        return buffer for data
 * @param   sz          number of bytes to receive
 *
 * @return  0 if successful; -1 otherwise
 */
static int rx_bytes(uint8_t * data, uint32_t base, int sz)
{
    unsigned short i2cr;
    int i;

    for (i = 0; sz > 0; sz--, i++) {
        if (wait_op_done(base, 0) != 0)
            return -1;

        /* the next two if-statements setup for the next read control register value */
        if (sz == 1) {
            /* last byte --> generate STOP */
            /* generate STOP by clearing MSTA bit */
            imx_send_stop(base);
        }

        if (sz == 2) {
            /* 2nd last byte --> set TXAK bit to NOT generate ACK */
            i2cr = readw(base + I2C_I2CR);
            writew(i2cr | I2C_I2CR_TXAK, base + I2C_I2CR);
        }
        /* read the true data */
        data[i] = readw(base + I2C_I2DR);
        debug_printf("OK 0x%02x\n", data[i]);
    }

    return 0;
}

int32_t i2c_xfer(imx_i2c_request_t *rq, int dir)
{
    uint32_t reg, ret = 0;
    uint16_t i2cr;
    uint8_t i, data;
    uint32_t base = rq->ctl_addr;

    if (rq->buffer_sz == 0 || rq->buffer == NULL) {
        printf("Invalid register address size=%x, buffer size=%x, buffer=%x\n",
               rq->reg_addr_sz, rq->buffer_sz, (unsigned int)rq->buffer);
        return -1;
    }

    /* clear the status register */
    writew(0, base + I2C_I2SR);

    /* enable the I2C controller */
    i2cr = I2C_I2CR_IEN;
    writew(i2cr, base + I2C_I2CR);

    /* Check if bus is free, if not return error */
    if (is_bus_free(base) != 0) {
        return -1;
    }

    /* Step 1: Select master mode, assert START signal and also indicate TX mode */
    i2cr |= I2C_I2CR_MSTA | I2C_I2CR_MTX;
    writew(i2cr, base + I2C_I2CR);

    /* make sure bus is busy after the START signal */
    if (wait_till_busy(base) != 0) {
        debug_printf("1\n");
        return -1;
    }
    /* Step 2: send slave address + read/write at the LSB */
    data = (rq->dev_addr << 1) | I2C_WRITE;

    if ((ret = tx_byte(&data, base)) != 0) {
        debug_printf("START TX ERR %d\n", ret);

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
        debug_printf("sending I2C=0x%x device register: data=0x%x, byte %d\n", base, data, i);

        if (tx_byte(&data, base) != 0) {
            return -1;
        }
    }

    /* Step 4: read/write data */
    if (dir == I2C_READ) {
        /* do repeat-start */
        i2cr = readw(base + I2C_I2CR) | I2C_I2CR_RSTA;
        writew(i2cr, base + I2C_I2CR);

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
        i2cr = readw(base + I2C_I2CR) & ~I2C_I2CR_MTX;
        /* if only one byte to read, make sure don't send ack */
        if (rq->buffer_sz == 1) {
            i2cr |= I2C_I2CR_TXAK;
        }
        writew(i2cr, base + I2C_I2CR);

        /* dummy read */
        data = readw(base + I2C_I2DR);

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
    }

    /* generate STOP by clearing MSTA bit */
    imx_send_stop(base);

    /* Check if bus is free, if not return error */
    if (is_bus_free(base) != 0) {
        printf("WARNING: bus is not free\n");
    }
    
    /* disable the controller */
    writew(0, base + I2C_I2CR);

    return ret;
}

void i2c_setup_interrupt(hw_module_t *port, uint8_t state)
{
    if (state == ENABLE) {
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
       /* enable the IRQ at the ARM core level */
        enable_interrupt(port->irq_id, CPU_0, 0);
        /* clear the status register */
        writew(0, port->base + I2C_I2SR);
        /* and enable the interrupts in the I2C controller */
        writew(readw(port->base + I2C_I2CR) | I2C_I2CR_IIEN, port->base + I2C_I2CR);
    } else {
        /* disable the IRQ at the ARM core level */
        disable_interrupt(port->irq_id, CPU_0);
        /* and disable the interrupts in the I2C controller */
        writew(readw(port->base + I2C_I2CR) & ~I2C_I2CR_IIEN, port->base + I2C_I2CR);
        /* clear the status register */
        writew(0, port->base + I2C_I2SR);
    }
}

int i2c_init(uint32_t base, uint32_t baud)
{
    uint32_t src_clk, divider;
    uint8_t index;

    /* enable the source clocks to the I2C port */
    clock_gating_config(base, CLOCK_ON);

    /* Set iomux configuration */
    i2c_iomux_config(base);

    /* reset I2C */
    writew(0, base + I2C_I2CR);

    /* Adjust the divider to get the closest SCL frequency to baud rate */
    src_clk = get_main_clock(IPG_PER_CLK);
    divider = src_clk / baud;
    if(divider < i2c_freq_div[0][0])
    {
        divider = i2c_freq_div[0][0];
        index = 0;
        printf("Warning :can't find a smaller divider than %d.\n", divider);
        printf("SCL frequency is set at %d - expected was %d.\n", src_clk/divider, baud);
    }
    else if(divider > i2c_freq_div[49][0])
    {
        divider = i2c_freq_div[49][0];
        index = 49;
        printf("Warning: can't find a bigger divider than %d.\n", divider);
        printf("SCL frequency is set at %d - expected was %d.\n", src_clk/divider, baud);
    }
    else
    {
        for(index=0;i2c_freq_div[index][0]<divider;index++);
        divider = i2c_freq_div[index][0];
    }
    writew(i2c_freq_div[index][1], base + I2C_IFDR);

    /* set an I2C slave address */
    writew(IMX6_SLAVE_ID, base + I2C_IADR);

    /* clear the status register */
    writew(0, base + I2C_I2SR);

    /* enable the I2C controller */
    writew(I2C_I2CR_IEN, base + I2C_I2CR);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
