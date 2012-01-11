/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file imx_i2c_slave.c
 * @brief Slave mode driver for the I2C controller.
 *
 * @ingroup diag_i2c
 */

#include "hardware.h"

/* Max number of operations to wait to receuve ack */
#define WAIT_RXAK_LOOPS     1000000

#define get_status(x) readw(x + I2C_I2SR)

static uint8_t g_wait_for_irq;
static uint16_t g_i2c_status_reg;
static uint32_t g_port_base_addr;
static uint8_t g_addr_cycle, g_data_cycle;
static uint8_t g_read_access;

/*!
 * I2C interrupt routine.
 */
void i2c_interrupt_routine(void)
{
    g_i2c_status_reg = readw(g_port_base_addr + I2C_I2SR);
    /* clear the status register */
    writew(0, g_port_base_addr + I2C_I2SR);

    g_wait_for_irq = 0;
}

/*!
 * I2C handler for the slave mode. The function is based on the
 * flow chart for typical I2C polling routine described in the
 * I2C controller chapter of the reference manual.
 *
 * @param   rq - pointer to struct imx_i2c_request
 */
void i2c_slave_handler(struct imx_i2c_request *rq)
{
    uint16_t i2cr, i2sr;
    uint8_t data, offset;
    uint32_t base = rq->ctl_addr;

    /* use a local version of the status updated during the last interrupt */
    i2sr = g_i2c_status_reg;
    g_i2c_status_reg = 0;

    /* if I2SR is cleared, there's nothing to do */
    if(!i2sr)
        return;

    /* read the current state of the control register */
    i2cr = readw(base + I2C_I2CR);

    /* was the i.MX6 slave address matched <=> IAAS=1? */
    if(i2sr & I2C_I2SR_IAAS)
    {
        /* IAAS=1, so enter in an address cycle */
        /* is it a master read access <=> SRW=1? */
        if(i2sr & I2C_I2SR_SRW)
        {
            /* SRW=1, so this is a master read access */
            /* set transmit mode */
            i2cr |= I2C_I2CR_MTX;
            writew(i2cr, base + I2C_I2CR);

            /* set a flag to notify that this is a read from master */
            g_read_access = I2C_I2SR_SRW;

            /* get the data from the application */
            (int32_t)(*rq->slave_transmit)(rq);
            /* first sent byte */
            data = rq->buffer[g_addr_cycle];
            g_data_cycle++;
            /* transmit the data */
            writew(data, base + I2C_I2DR);
       }
        else
        {
            /* SRW=0, this is a master write access */
            /* set receive mode */
            i2cr &= ~I2C_I2CR_MTX;
            writew(i2cr, base + I2C_I2CR);
            /* dummy read of the received slave address */
            data = readw(base + I2C_I2DR);
        }
    }
    else
    {
        /* IAAS=0, so enter in a data cycle */
        /* is it in transmit mode? */
        if(i2cr & I2C_I2CR_MTX)
        {
            /* MTX=1, so this is in transmit mode */
            /* is ACK received <=> RXAK=0? */
            if(!(i2sr & I2C_I2SR_RXAK))
            {
                /* RXAK=0, an acknowledge was received */
                /* get data from the application if not done 
                    already during the first data access above */
                /* following sent bytes */
                data = rq->buffer[g_data_cycle + g_addr_cycle];
                g_data_cycle++;
                /* transmit the data */
                writew(data, base + I2C_I2DR);
            }
            else
            {
                /* RXAK=1, no acknowledge was received */
                /* set receive mode */
                i2cr &= ~I2C_I2CR_MTX;
                writew(i2cr, base + I2C_I2CR);
                /* dummy read of the received data */
                data = readw(base + I2C_I2DR);
            }
        }
        else
        {
            /* MTX=0, so this is in receive mode */
            if(g_addr_cycle < rq->reg_addr_sz)
            {
                /* this is an address that is read */
                offset = g_addr_cycle;
                g_addr_cycle++;
            }
            else
            {
                /*this is a data that is read */
                offset = g_addr_cycle + g_data_cycle;               
                g_data_cycle++;
            }
            /* read the received data */
            rq->buffer[offset] = readw(base + I2C_I2DR);
        }
    }
}

/*!
 * The slave mode behaves like any device with g_addr_cycle of address + g_data_cycle of data.
 * Master read =
 * START - SLAVE_ID/W - ACK - MEM_ADDR - ACK - START - SLAVE_ID/R - ACK - DATAx - NACK - STOP
 * 
 * Example for a 16-bit address access:
 * 1st IRQ - receive the slave address and Write flag from master.
 * 2nd IRQ - receive the lower byte of the requested 16-bit address.
 * 3rd IRQ - receive the higher byte of the requested 16-bit address.
 * 4th IRQ - receive the slave address and Read flag from master.
 * 5th and next IRQ - transmit the data as long as NACK and STOP is not asserted.
 *
 * Master write =
 * START - SLAVE_ID/W - ACK - MEM_ADDR - ACK - DATAx - NACK - STOP
 *
 * 1st IRQ - receive the slave address and Write flag from master.
 * 2nd IRQ - receive the lower byte of the requested 16-bit address.
 * 3rd IRQ - receive the higher byte of the requested 16-bit address.
 * 4th and next IRQ - receive the data as long STOP is not asserted.
 */
/*!
 * Handle the I2C transfers in slave mode.
 *
 * @param   port - pointer to the I2C module structure.
 * @param   rq - pointer to struct imx_i2c_request
 */
void i2c_slave_xfer(struct hw_module *port, struct imx_i2c_request *rq)
{
    uint32_t base = rq->ctl_addr;

    /* enable the I2C controller */
    writew(I2C_I2CR_IEN, base + I2C_I2CR);
    
    /* initialize the number of addr and data cycles for the transfer */
    g_addr_cycle = 0;
    g_data_cycle = 0;
    g_read_access = 0;

    /* set the choosen I2C slave address */
    writew(rq->dev_addr, base + I2C_IADR);

    /* assign the IRQ handler to the used port */
    port->irq_subroutine = &i2c_interrupt_routine;
    g_port_base_addr = base;

    /* Enable the interrupts for the I2C controller */
    i2c_setup_interrupt(port, ENABLE);

    /* The slave behaves like a EEPROM of rq.reg_addr_sz bytes for 
     * and g_data_cycle bytes for data
     */

    /* wait for the first 1 interrupt that should make the bus busy */
    g_wait_for_irq = 1;
    while(g_wait_for_irq == 1);

    do
    {
        i2c_slave_handler(rq);

        g_wait_for_irq = 1;
        while(g_wait_for_irq == 1)
            /* the STOP condition can arrive late after the last transfer */
            if(!(get_status(base) & I2C_I2SR_IBB))
                break;
    }
    while(get_status(base) & I2C_I2SR_IBB);

    /* Provide to the application the data written by the master */
    if(g_read_access & I2C_I2SR_SRW)
    {
        /* set the number of transmitted data */
        rq->buffer_sz = g_data_cycle;

#ifdef DEBUG
        uint8_t i;
        printf("Master did a read access at address 0x");
        for(i=0;i<g_addr_cycle;i++)
            printf("%02X", rq->buffer[i]);
        printf(" of %dbytes.\n", g_data_cycle);
        printf("The transmitted data is: 0x");
        for(i=g_data_cycle;i>0;i--)
            printf("%02X", rq->buffer[i-1+g_addr_cycle]);
        printf("\n");
#endif
    }
    else
    {
        /* set the number of received data */
        rq->buffer_sz = g_data_cycle;
        /* send the received data to the application */
        (int32_t)(*rq->slave_receive)(rq);

#ifdef DEBUG
        printf("Master did a write access at address 0x");
        for(i=0;i<g_addr_cycle;i++)
            printf("%02X", rq->buffer[i]);
        printf(" of %dbytes.\n", g_data_cycle);
        printf("The received data is: 0x");
        for(i=g_data_cycle;i>0;i--)
            printf("%02X", rq->buffer[i-1+g_addr_cycle]);
        printf("\n");
#endif
    }

    /* Disable the interrupts for the I2C controller */
    i2c_setup_interrupt(port, DISABLE);

    /* disable the controller */
    writew(0, base + I2C_I2CR);
}
