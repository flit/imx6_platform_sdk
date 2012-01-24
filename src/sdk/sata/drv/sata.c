/*
 * Copyright (C) 2010-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#include "imx_sata.h"
#include "atapi.h"

///////////////////////////////////////////////////////////////////
//                      Macro Definitions                        //
///////////////////////////////////////////////////////////////////
#define PRINT(opt,fmt,args...) \
	if(opt) \
		printf(fmt, ## args)

///////////////////////////////////////////////////////////////////
//                      Global Variables                         //
///////////////////////////////////////////////////////////////////
sata_command_header_t *cmdhdr = NULL;
sata_command_table_t *cmdtbl = NULL;
sata_ahci_regs_t *imx_sata_host = (sata_ahci_regs_t *) SATA_BASE_ADDR;
sata_port_regs_t *imx_sata_port0 =
    (sata_port_regs_t *) SATA_PORT_N_BASE_ADDRESS(0, SATA_BASE_ADDR);
sata_identify_data_t hdd_ident;
disk_identify_t ident;
sata_phy_ref_clk_t sata_phy_clk_sel = OSC_UNKNOWN;

///////////////////////////////////////////////////////////////////
//                Extern Variables Re-declaration                //
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//                  Extern Function Re-declaration               //
///////////////////////////////////////////////////////////////////
extern void sata_clock_enable(void);
extern void sata_power_on(void);
//////////////////////////////////////////////////////////////////
//                      Local Variables                          //
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//                  Local Function Declarations                  //
///////////////////////////////////////////////////////////////////
static void sata_ahci_host_info_print(sata_ahci_regs_t * ahci);

static sata_return_t sata_ahci_set_port_idle(sata_port_regs_t * port_n_regs);
static sata_return_t sata_ahci_port_reset(sata_port_regs_t * port_n_regs);

static void sata_clock_init(sata_phy_ref_clk_t * phyclk);
static sata_return_t sata_hdd_init(void);
static sata_return_t ahci_find_empty_slot(sata_port_regs_t * port);
static sata_return_t sata_wait_command_done(u32 port_no);

static sata_return_t sata_reg_fis_h2d(sata_port_regs_t * port,  //the base address of the SATA port to run the command
                                      u32 sect_addr,    //start address of the first sector
                                      u32 sect_cnt, //the sector number to read or write
                                      u32 rw,   //the data transfer direction: read or write
                                      u32 command,  //ATAPI command code
                                      char features,    //content in feature register of the shadow register block
                                      u32 size, //the data transfer size in byte
                                      u32 data_addr,    //base address of data buffer
                                      sata_command_header_t * cmdh, //the pointer of command header
                                      sata_command_table_t * cmdt); //the pointer of command table
static sata_return_t sata_non_queued_error_recovery(void);
//SATA PHY Control Functions
static sata_return_t sata_phy_cr_ack_polling(u32 max_iterations, u32 expected_val);
static sata_return_t sata_phy_cr_write(u32 addr, u32 val);
static sata_return_t sata_phy_cr_read(u32 addr, u32 * data);
static sata_return_t sata_phy_cr_addr(u32 addr);
static void sata_phy_config_mpll(char prop_ctl, char int_ctl, char ncy5, char ncy, char prescale);
///////////////////////////////////////////////////////////////////
//                  Global Function Declarations                 //
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//                  Function Defintions                          //
///////////////////////////////////////////////////////////////////
/*=============================================================================
FUNCTION:			sata_pio_read_sector
DESCRIPTION:		This function read some sectors from SATA HDD.
ARGUMENTS PASSED:   start_block - the address of start sector
                    buf         - the pointer of destination buffer
                    len         - the length to read
RETURN VALUE:		Pass  - True
                    Faile - False
IMPORTANT NOTES:
===============================================================================*/
sata_return_t sata_pio_read_sector(u32 start_block, u8 * buf, u32 len)
{
    u32 sect_cnt = 0;
    u32 sect_start_addr = 0;
    sata_return_t ret = SATA_FAIL;
    sect_cnt = len / SATA_HDD_SECTOR_SIZE;
    sect_start_addr = start_block;  //*SATA_HDD_SECTOR_SIZE;
    u32 try_times = 10;

  exec:

    if (try_times == 0) {
        //PRINT(0,"+SATAERR: !error@sata_pio_read_sector blk%d@0x%08x,len%d\n",start_block,buf,len);
        return (!ret);
    }

    cmdhdr = (sata_command_header_t *) SATA_COMMAND_LIST_BASE;
    cmdtbl = (sata_command_table_t *) SATA_COMMAND_TABLE_BASE;

    ret = sata_reg_fis_h2d(imx_sata_port0,
                           sect_start_addr,
                           sect_cnt,
                           SATA_READ, ATAPI_COMMAND_READ_SECTOR, 0, len, (u32) buf, cmdhdr, cmdtbl);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_pio_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    ret = sata_wait_command_done(PORT0);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_pio_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    try_times--;

    return (!ret);
}

/*=============================================================================
FUNCTION:			sata_pio_write_sector
DESCRIPTION:		This function write some sectors from SATA HDD.
ARGUMENTS PASSED:   start_block - the number of start sector
                    buf         - the pointer of destination buffer
                    len         - the length to write
RETURN VALUE:		Pass  - True
                    Faile - False
IMPORTANT NOTES:
===============================================================================*/
sata_return_t sata_pio_write_sector(u32 start_block, u8 * buf, u32 len)
{
    u32 sect_cnt = 0;
    u32 sect_start_addr = 0;
    sata_return_t ret = SATA_FAIL;
    u32 try_times = 10;

    sect_cnt = len / SATA_HDD_SECTOR_SIZE;
    sect_start_addr = start_block;  //*SATA_HDD_SECTOR_SIZE;

  exec:

    if (try_times == 0) {
        PRINT(0, "+SATAERR: !error@sata_pio_write_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);
        return (!ret);
    }

    cmdhdr = (sata_command_header_t *) SATA_COMMAND_LIST_BASE;
    cmdtbl = (sata_command_table_t *) SATA_COMMAND_TABLE_BASE;

    ret = sata_reg_fis_h2d(imx_sata_port0,
                           sect_start_addr,
                           sect_cnt,
                           SATA_WRITE,
                           ATAPI_COMMAND_WRITE_SECTOR, 0, len, (u32) buf, cmdhdr, cmdtbl);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_pio_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    ret = sata_wait_command_done(PORT0);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_pio_write_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    return (!ret);
}

/*=============================================================================
FUNCTION:			sata_dma_read_sector
DESCRIPTION:		This function read some sectors from SATA HDD through Port
                    DMA
ARGUMENTS PASSED:   start_block - the address of start sector
                    buf         - the pointer of destination buffer
                    len         - the length to read
RETURN VALUE:		Pass  - True
                    Faile - False
IMPORTANT NOTES:
===============================================================================*/
sata_return_t sata_dma_read_sector(u32 start_block, u8 * buf, u32 len)
{
    u32 sect_cnt = 0;
    u32 sect_start_addr = 0;
    sata_return_t ret = SATA_FAIL;
    sect_cnt = len / SATA_HDD_SECTOR_SIZE;
    sect_start_addr = start_block;  //*SATA_HDD_SECTOR_SIZE;
    u32 try_times = 10;
  exec:

    if (try_times == 0) {
        PRINT(0, "+SATAERR: !error@sata_dma_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);
        return (!ret);
    }

    cmdhdr = (sata_command_header_t *) SATA_COMMAND_LIST_BASE;
    cmdtbl = (sata_command_table_t *) SATA_COMMAND_TABLE_BASE;

    ret = sata_reg_fis_h2d(imx_sata_port0,
                           sect_start_addr,
                           sect_cnt,
                           SATA_READ, ATAPI_COMMAND_READ_DMA, 0, len, (u32) buf, cmdhdr, cmdtbl);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_pio_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    ret = sata_wait_command_done(PORT0);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_dma_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    return (!ret);
}

/*=============================================================================
FUNCTION:			sata_dma_write_sector
DESCRIPTION:		This function write some sectors into SATA HDD through Port
                    DMA
ARGUMENTS PASSED:   start_block - the number of start sector
                    buf         - the pointer of destination buffer
                    len         - the length to write
RETURN VALUE:		Pass  - True
                    Faile - False
IMPORTANT NOTES:
===============================================================================*/
sata_return_t sata_dma_write_sector(u32 start_block, u8 * buf, u32 len)
{
    u32 sect_cnt = 0;
    u32 sect_start_addr = 0;
    sata_return_t ret = SATA_FAIL;

    sect_cnt = len / SATA_HDD_SECTOR_SIZE;
    sect_start_addr = start_block;  //start_block*SATA_HDD_SECTOR_SIZE;
    u32 try_times = 10;
  exec:

    if (try_times == 0) {
        PRINT(0, "+SATAERR: !error@sata_dma_write_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);
        return (!ret);
    }

    PRINT(0, "+SATAINFO: sata_dma_write_sector blk %d,len %d\n", start_block, len);

    cmdhdr = (sata_command_header_t *) SATA_COMMAND_LIST_BASE;
    cmdtbl = (sata_command_table_t *) SATA_COMMAND_TABLE_BASE;

    ret = sata_reg_fis_h2d(imx_sata_port0,
                           sect_start_addr,
                           sect_cnt,
                           SATA_WRITE, ATAPI_COMMAND_WRITE_DMA, 0, len, (u32) buf, cmdhdr, cmdtbl);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_pio_read_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    ret = sata_wait_command_done(PORT0);

    if (ret == SATA_FAIL) {
        PRINT(0, "+SATAERR: !error@sata_dma_write_sector blk%d@0x%08x,len%d\n", start_block,
              (u32) buf, len);

        if (SATA_PASS == sata_non_queued_error_recovery()) {
            try_times--;
            goto exec;
        }
    }

    return (!ret);
}

/*=============================================================================
FUNCTION:			sata_disk_read_sector
DESCRIPTION:		This function read some sectors from SATA disk with r/w
                    thread
ARGUMENTS PASSED:   start_block - the address of start sector
                    buf         - the pointer of destination buffer
                    len         - the length to read
RETURN VALUE:		Pass  - True
                    Faile - False
IMPORTANT NOTES:
==============================================================================*/
sata_return_t sata_disk_read_sector(u32 start_block, u8 * buf, u32 len)
{
    u32 i = 0;
    u32 cycle = 0;
    u32 sz = 0;
    u32 single_rd_sz = SATA_MAX_TRANSFER_DATA_SZ;
    u32 xfer_sz = 0;
    u32 blk;

    PRINT(0, "+SATAINFO: sata_disk_read_sector@blk %d, buf 0x%08x, sz %d\n", start_block, (u32) buf,
          len);
    cycle = len / single_rd_sz;

    if (len % single_rd_sz)
        cycle++;

    while (i < cycle) {
        blk = start_block + i * (single_rd_sz / SATA_HDD_SECTOR_SIZE);

        if (len > single_rd_sz)
            sz = single_rd_sz;
        else
            sz = len;

        PRINT(0, "+SATAINFO: sata_disk_read_sector cycle %d,blk %d,sz %d\n", i, blk, sz);
#ifdef SATA_PDMA_ENABLED

        if (!sata_dma_read_sector(blk, (buf + xfer_sz), sz))
#else
        if (!sata_pio_read_sector(blk, (buf + xfer_sz), sz))
#endif
        {
            PRINT(0, "+SATAERR: sata_disk_read_sector error@blk %d, buf 0x%08x, sz %d\n", blk,
                  (u32) ((u8 *) buf + i * single_rd_sz), sz);
            return SATA_FAIL;
        }

        i++;
        len -= sz;
        xfer_sz += sz;
    }

    return SATA_PASS;
}

/*=============================================================================
FUNCTION:			sata_disk_write_sector
DESCRIPTION:		This function write some sectors to SATA disk with r/w
                    thread
ARGUMENTS PASSED:   start_block - the address of start sector
                    buf         - the pointer of destination buffer
                    len         - the length to read
RETURN VALUE:		Pass  - True
                    Faile - False
IMPORTANT NOTES:
==============================================================================*/
sata_return_t sata_disk_write_sector(u32 start_block, u8 * buf, u32 len)
{
    u32 i = 0;
    u32 cycle = 0;
    u32 sz = 0;
    u32 single_wr_sz = SATA_MAX_TRANSFER_DATA_SZ;   // total 32 sectors was transferred each time
    u32 blk;
    u32 xfer_sz = 0;
    cycle = len / single_wr_sz;

    cycle = len / single_wr_sz;

    if (len % single_wr_sz)
        cycle++;

    PRINT(0, "+SATAINFO: sata_disk_write_sector@blk %d, buf 0x%08x, sz %d\n", start_block,
          (u32) buf, len);

    while (i < cycle) {
        blk = start_block + i * (single_wr_sz / SATA_HDD_SECTOR_SIZE);

        if (len > single_wr_sz)
            sz = single_wr_sz;
        else
            sz = len;

        PRINT(0, "+SATAINFO: sata_disk_write_sector cycle%d,blk %d,sz %d\n", i, blk, sz);

#ifdef SATA_PDMA_ENABLED

        if (!sata_dma_write_sector(blk, (buf + xfer_sz), sz))
#else
        if (!sata_pio_write_sector(blk, (buf + xfer_sz), sz))
#endif
        {
            PRINT(0, "+SATAERR: sata_disk_write_sector error@%d\n", i);
            return SATA_FAIL;
        }

        i++;
        len -= sz;
        xfer_sz += sz;
    }

    return SATA_PASS;
}

/*=============================================================================
FUNCTION: 			printf_buffer
DESCRIPTION:    	print a buffer
ARGUMENTS PASSED: 	None
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
void printf_buffer(u32 buff, u32 size, u32 enable)
{
    u32 i;
    unsigned char *ptr = (unsigned char *)buff;

    if (enable) {
        PRINT(0, "Data@BASE:0x%08x, LEN:%d bytes\n", buff, size);

        for (i = 0; i < size; i++) {
            PRINT(0, "%02X ", *(ptr + i));

            if (i % 16 == 15)
                PRINT(0, "\n");
        }

        PRINT(0, "\n");
    }
}

void print_identify_data(disk_identify_t * ident_data)
{
    PRINT(1, "HDD Identification Data:\n");
    PRINT(1, "\tSerial        : %s\n", (u8 *) ident_data->serial);
    PRINT(1, "\tFirmware rev. : %s\n", (u8 *) ident_data->firmware_rev);
    PRINT(1, "\tModel         : %s\n", (u8 *) ident_data->model_num);
    PRINT(1, "\tC/H/S         : %d/%d/%d\n", ident_data->cylinders_num, ident_data->heads_num,
          ident_data->sectors_num);
    PRINT(1, "\tSect Num      : %d\n", ident_data->lba_sectors_num);
    PRINT(1, "\tPhys Blk Sz   : %d\n", ident_data->phys_block_size);
    PRINT(1, "\tMax Trans Sz  : %d\n", ident_data->max_transfer * 512);
}

///////////////////////////////////////////////////////////////////
//                  Local Function Defintions                    //
///////////////////////////////////////////////////////////////////

static void _sata_identify_data_strcpy(char *dest, u16 * src, u16 size)
{
    u32 i;

    for (i = 0; i < size; i += 2) {
        *dest++ = (char)(*src >> 8);
        *dest++ = (char)(*src & 0x00FF);

        if (*src == 0x2020) {
            break;
        }

        src++;
    }

    *dest = '\0';
}

/*=============================================================================
FUNCTION: 			sata_ahci_set_port_idle
DESCRIPTION:    	make sure SATA Port in IDLE state
ARGUMENTS PASSED: 	sata_port_regs_t * port_n_regs - base address of port regs
RETURN VALUE:		pass - 0; fail - 1
IMPORTANT NOTES:	None

    Reading each implemented port's PxCMD register to ensure the controller
	is not in the running state.
	PxCMD.ST/CR/FRE/FR are all cleared -> idle state
	If the port is not idle, it should be placed in the idle state prior to
	manipulating HBA and port specific register
	Method:
	   1.clearing PxCMD.ST and waiting for PxCMD.CR to return '0' to place a port
	    into idle. At least 500ms waiting is required.
	   2.if PxCMD.FRE is set to '1', software should clear it to '0' and wait at
	    least 500ms for PxCMD.FR returning '0'
	   3.PxCMD.CR or PxCMD.FR don't clear to '0' correctly, then software may
	    attempt a port reset or a full HBA reset to recover
==============================================================================*/
static sata_return_t sata_ahci_set_port_idle(sata_port_regs_t * port_n_regs)
{
    u32 v;
    sata_return_t ret = SATA_PASS;

    v = port_n_regs->cmd;

    PRINT(0, "+SATAINFO: PxCMD@0x%08x = 0x%08x\n", (u32) (&(port_n_regs->cmd)), v);

    if (v & SATA_AHCI_PORT_N_CMD_HPCP) {
        PRINT(0, "+SATAINFO: Hot Plug Supported\n");
    }

    if ((!(v & SATA_AHCI_PORT_N_CMD_START))
        && (!(v & SATA_AHCI_PORT_N_CMD_CR))
        && (!(v & SATA_AHCI_PORT_N_CMD_FRE))
        && (!(v & SATA_AHCI_PORT_N_CMD_FR))) {
        PRINT(0, "+SATADBGMSG: The port is in IDLE state.\n");
        return ret;
    }

    /*------Place the port into IDLE state------*/
    /*Clear CMD.ST and wait for CMD.CR to return '0' */
    port_n_regs->cmd &= ~SATA_AHCI_PORT_N_CMD_START;
    hal_delay_us(PORT_N_INIT_TIMEOUT);  //delay 500ms

    if (port_n_regs->cmd & SATA_AHCI_PORT_N_CMD_CR) {
        ret = SATA_FAIL;
        PRINT(0, "+SATADBGMSG:PxCMD.CR does not return to zero.\n");
        return ret;
    }

    if (port_n_regs->cmd & SATA_AHCI_PORT_N_CMD_FRE) {
        port_n_regs->cmd &= ~SATA_AHCI_PORT_N_CMD_FRE;
        hal_delay_us(PORT_N_INIT_TIMEOUT);  //delay 500ms

        if (port_n_regs->cmd & SATA_AHCI_PORT_N_CMD_FR) {
            ret = SATA_FAIL;
            PRINT(0, "+SATADBGMSG:PxCMD.FR does not return to zero.\n");
            return ret;
        }
    }

    PRINT(0, "+SATADBGMSG:place the port into IDLE state completed.\n");
    return ret;

}

/*=============================================================================
FUNCTION: 			sata_ahci_port_reset
DESCRIPTION:    	sata_port_regs_t * port_n_regs - base address of port regs
ARGUMENTS PASSED: 	None
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
static sata_return_t sata_ahci_port_reset(sata_port_regs_t * port_n_regs)
{
    sata_return_t ret;
    port_n_regs->cmd &= ~SATA_AHCI_PORT_N_CMD_START;
    hal_delay_us(PORT_N_INIT_TIMEOUT);  //delay 500ms

    if (port_n_regs->cmd & SATA_AHCI_PORT_N_CMD_CR) {
        ret = SATA_FAIL;
        PRINT(0, "+SATADBGMSG:PxCMD.CR does not return to zero.\n");
        return ret;
    }

    port_n_regs->cmd |= SATA_AHCI_PORT_N_CMD_START;
    return SATA_PASS;
}

/*=============================================================================
FUNCTION: 			sata_ahci_host_info_print
DESCRIPTION:    	parsing the SATA host information by reading host regs
ARGUMENTS PASSED: 	None
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
static void sata_ahci_host_info_print(sata_ahci_regs_t * ahci)
{
    u32 vers, cap, speed, ip_vers;
    const char *speed_s;

    vers = ahci->vs;
    ip_vers = ahci->version;
    cap = ahci->cap;

    speed = (cap & SATA_AHCI_HOST_CAP_ISS_MASK) >> SATA_AHCI_HOST_CAP_ISS_SHIFT;

    if (speed == 1)
        speed_s = "1.5";
    else if (speed == 2)
        speed_s = "3.0";
    else if (speed == 3)
        speed_s = "6.0";
    else
        speed_s = "?";

    PRINT(1, "-------------------------------------\n");
    PRINT(1, "+SATAINFO:SATA AHCI Host Information:\n");
    PRINT(1, " AHCI Spec Ver: %x%x.%x%x\n"
          " SATA IP Ver  : %c.%c%c%c\n"
          " Command Slots: %u\n"
          " Impl. Ports  : %u\n"
          " Speed        : %sGbps\n",
          (vers >> 24) & 0xff,
          (vers >> 16) & 0xff,
          (vers >> 8) & 0xff,
          (vers) & 0xff,
          (ip_vers >> 24) & 0xff,
          (ip_vers >> 16) & 0xff,
          (ip_vers >> 8) & 0xff,
          (ip_vers) & 0xff, ((cap >> 8) & 0x1f) + 1, (cap & 0x1f) + 1, speed_s);

    PRINT(1, " Flags        : "
          "%s%s%s%s%s%s%s%s%s"
          "%s%s%s%s%s%s%s%s\n",
          cap & (1 << 31) ? "64bit" : "32bit",
          cap & (1 << 30) ? "|NCQ" : "",
          cap & (1 << 29) ? "|SNTF" : "",
          cap & (1 << 28) ? "|MPS" : "",
          cap & (1 << 27) ? "|STAG" : "",
          cap & (1 << 26) ? "|ALPM" : "",
          cap & (1 << 25) ? "|LED" : "",
          cap & (1 << 24) ? "|CLO" : "",
          cap & (1 << 19) ? "|NZO" : "",
          cap & (1 << 18) ? "|ONLY" : "",
          cap & (1 << 17) ? "|PMP" : "",
          cap & (1 << 15) ? "|PIO" : "",
          cap & (1 << 14) ? "|SLUM" : "",
          cap & (1 << 13) ? "|PART" : "",
          cap & (1 << 7) ? "|CCC" : "", cap & (1 << 6) ? "|EMS" : "", cap & (1 << 5) ? "|SXS" : "");
    PRINT(1, "-------------------------------------\n");

}

/*=============================================================================
FUNCTION: 			sata_clock_init
DESCRIPTION:    	Enable the clocks of SATA, and configure the reference clock
ARGUMENTS PASSED: 	None
RETURN VALUE:		pass - 0
                    fail - 1
IMPORTANT NOTES:
     Referene clock will come from CLKO2, which is GPIO_3
==============================================================================*/
static void sata_clock_init(sata_phy_ref_clk_t * phyclk)
{
    u32 v;
    sata_phy_ref_clk_t clk_val = *phyclk;

    /*Enable SATA module clock */
    sata_clock_enable();

    PRINT(0, "+SATADBGMSG: SATA relevant clocks gated on\n");

    if (clk_val == FREQ_100MHZ) {
        /*Set GPIO_3 as CLKO2 */
        writel(ALT4, IOMUXC_SW_MUX_CTL_PAD_GPIO_3);
        /* Configure CMD SW PAD */
        writel(0x184, IOMUXC_SW_PAD_CTL_PAD_GPIO_3);

        /*Set CLKO2 to ddr_clk_root,300MHz */
        writel(~(0x1F << 16), CCM_CCOSR);
        writel((0x9 << 16), CCM_CCOSR); //DDR

        /*Set CLKO2 Divider as 3 to get 100MHz */
        v = readl(CCM_CCOSR);
        v |= (0x2 << 21);       //div3
        writel(v, CCM_CCOSR);

        /*Enable CLKO2 */
        v = readl(CCM_CCOSR);
        v |= (0x1 << 24);
        writel(v, CCM_CCOSR);

        PRINT(0, "+SATADBGMSG: SATA PHY Clock 100MHz Div of CLKO2\n");
        PRINT(0, "+SATADBGMSG: CCOSR = 0x%08x\n", readl(CCM_CCOSR));

        sata_phy_config_mpll(7, 0, 2, 6, 2);
        PRINT(1, "+SATADBGMSG: SATA PHY Clock 100MHz divided DDR clock\n");
    } else if (clk_val == OSC_25MHZ) {
        sata_phy_config_mpll(7, 0, 2, 6, 1);
        PRINT(1, "+SATADBGMSG: SATA PHY Clock 25MHz Osc\n");
    } else if (clk_val == OSC_50MHZ) {
        sata_phy_config_mpll(7, 0, 2, 6, 0);
        PRINT(1, "+SATADBGMSG: SATA PHY Clock 50MHz Osc\n");
    } else if (clk_val == OSC_25MHZ) {
        sata_phy_config_mpll(7, 0, 2, 6, 1);
        PRINT(1, "+SATADBGMSG: SATA PHY Clock 25MHz Osc\n");
    } else if (clk_val == FUSE_USB_PHY_CLK) {
        PRINT(1, "+SATADBGMSG: SATA PHY Clock <= USB PHY1\n");
    } else if (clk_val == ANATOP_ENET_PLL) {
        PRINT(1, "+SATADBGMSG: SATA PHY Clock <= ANATOP ENET PLL\n");
    }

}

/*=============================================================================
FUNCTION: 			sata_hdd_init
DESCRIPTION:    	Read the first sector of the attached hard disk drive to
                    get the critical information
ARGUMENTS PASSED: 	None
RETURN VALUE:		pass - 0
                    fail - 1
IMPORTANT NOTES:	None
==============================================================================*/
static sata_return_t sata_hdd_init(void)
{
    sata_return_t ret = SATA_FAIL;
    unsigned char *ident_data;  //[SATA_HDD_SECTOR_SIZE];
    u32 i;
    char crc = 0;
    sata_identify_data_t *ide_idData = &hdd_ident;

    u32 total_lba_sect = 0;

    ident_data = (unsigned char *)SATA_TRANSFER_BUFFER_BASE;    //located in OCRAM
    memset(ident_data, 0, SATA_HDD_SECTOR_SIZE);
    PRINT(0, "+SATAINFO: identify data buffer base: 0x%08x\n", (u32) ident_data);
    cmdhdr = (sata_command_header_t *) SATA_COMMAND_LIST_BASE;
    cmdtbl = (sata_command_table_t *) SATA_COMMAND_TABLE_BASE;

    ret = sata_reg_fis_h2d(imx_sata_port0,
                           0,
                           1,
                           SATA_READ,
                           ATAPI_COMMAND_IDENTIFY_DEVICE,
                           0, SATA_HDD_SECTOR_SIZE, (u32) ident_data, cmdhdr, cmdtbl);

    if (ret == SATA_FAIL) {
        return (!ret);
    }

    hal_delay_us(5000);         //5ms

    ret = sata_wait_command_done(PORT0);

    printf_buffer((u32) ident_data, SATA_HDD_SECTOR_SIZE, 0);

    /*Check the data integrity of identify data */
    for (i = 0; i < SATA_HDD_SECTOR_SIZE; i++) {
        crc += *(ident_data + i);
    }

    /*check CRC: CIS[255] should be XXA5 where XX=-1*CRC thus total CRC including XX should be 0 */
    if ((*(ident_data + SATA_HDD_SECTOR_SIZE - 2) != 0xA5) || (crc != 0)) {
        PRINT(0, "+SATAERR: idetify CRC Error %xa5 != %.2x%.2x\n", (-1 * crc) & 0xff,
              ident_data[SATA_HDD_SECTOR_SIZE - 2], ident_data[SATA_HDD_SECTOR_SIZE - 1]);
        return SATA_FAIL;
    }

    /*initialize hdd identify data */
    memcpy((char *)ide_idData, ident_data, SATA_HDD_SECTOR_SIZE);

    _sata_identify_data_strcpy(ident.serial, ide_idData->serial, 20);
    _sata_identify_data_strcpy(ident.firmware_rev, ide_idData->fw_rev, 8);
    _sata_identify_data_strcpy(ident.model_num, ide_idData->model_num, 40);

    total_lba_sect = (ide_idData->lba_total_sectors[1] << 16) | ide_idData->lba_total_sectors[0];

    ident.cylinders_num = ide_idData->num_cylinders;
    ident.heads_num = ide_idData->num_heads;
    ident.sectors_num = ide_idData->num_sectors;
    ident.lba_sectors_num = total_lba_sect;
    ident.phys_block_size = ide_idData->sector_size;
    ident.max_transfer = (ide_idData->rw_mult_support & 0xFF);

    //PRINT(0,"+SATAINFO: words per logic sector: %d\n",(ide_idData->sector_sz_in_word));
    print_identify_data(&ident);

    return ret;

}

/*=============================================================================
FUNCTION: 			sata_port_status_parser
DESCRIPTION:    	parsing the status of SATA
ARGUMENTS PASSED: 	u32 status - the value of SATA PORT IS register
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
static void sata_port_status_parser(u32 status)
{

    if (status & SATA_AHCI_PORT_N_IS_CPDS) {
        PRINT(0, "+SATAINFO: CPDS - Cold Port Detect.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_TFES) {
        PRINT(0, "+SATAINFO: TFES - Task File Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_HBFS) {
        PRINT(0, "+SATAINFO: HBFS - Host Bus Fatal Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_HBDS) {
        PRINT(0, "+SATAINFO: HBDS - Host Bus Data Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_IFS) {
        PRINT(0, "+SATAINFO: IFS  - Interface Fatal Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_INFS) {
        PRINT(0, "+SATAINFO: INFS - Interface Non-Fatal Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_OFS) {
        PRINT(0, "+SATAINFO: OFS  - OverFlow Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_ERR_IPMS) {
        PRINT(0, "+SATAINFO: IPMS - Incorrect Port Multiplier Error.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_PRCS) {
        PRINT(0, "+SATAINFO: PRCS - PHY Ready Change.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_DMPS) {
        PRINT(0, "+SATAINFO: DMPS - Device Mechanical Presence.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_PCS) {
        PRINT(0, "+SATAINFO: PCS  - Port Change.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_DPS) {
        PRINT(0, "+SATAINFO: DPS  - Descriptor Processed.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_UFS) {
        PRINT(0, "+SATAINFO: UFS  - Unknown FIS.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_SDBS) {
        PRINT(0, "+SATAINFO: SDBS - Set Device Bits FIS.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_DSS) {
        PRINT(0, "+SATAINFO: DSS  - DMA Setup FIS.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_PSS) {
        PRINT(0, "+SATAINFO: PSS  - PIO Setup FIS.\n");
    }

    if (status & SATA_AHCI_PORT_N_IS_DHRS) {
        PRINT(0, "+SATAINFO: DHRS - Device to Host Register FIS.\n");
    }
}

/*=============================================================================
FUNCTION: 			ahci_find_empty_slot
DESCRIPTION:    	find an empty command slot
ARGUMENTS PASSED: 	sata_ahci_regs_t * ahci - the AHCI base address
RETURN VALUE:		return the first empty command slot during tranversing
IMPORTANT NOTES:	None
==============================================================================*/
static sata_return_t ahci_find_empty_slot(sata_port_regs_t * port)
{
    u32 idx;
    u32 empty_cmd_slot = 32;
    u32 v;

    // Get an empty command slot
    v = port->ci;
    idx = 0;

    while ((((v >> idx) & 0x1) != 0) && (idx < 32)) {
        idx = idx + 1;
    }

    empty_cmd_slot = idx;

    if (empty_cmd_slot > 31) {
        PRINT(0, "SATAERR: Can not find emmpty slot(%d)\n", empty_cmd_slot);
        return -1;
    }

    PRINT(0, "+SATADBGMSG:command slot %d is empty\n", empty_cmd_slot);
    PRINT(0, "+SATADBGMSG:command slot %d is empty\n", empty_cmd_slot);
    return empty_cmd_slot;
}

static sata_return_t sata_wait_command_done(u32 port_no)
{
    u32 i;
    sata_return_t ret = SATA_FAIL;
    u32 stat = 0;
    u32 err = 0;
    u32 port_stat = 0;
    /* wait while device busy */
    i = MAX_TIMEOUT_COUNTER;

    while (((imx_sata_host->is & SATA_AHCI_HOST_IS_PORT_N_INTR_ISSUED(port_no)) != (0x1 << port_no))
           && (--i > 0)) ;

    if (i == 0) {
        PRINT(0, "+SATAERR: wait interrupt timeout\n");
        stat = imx_sata_port0->is;
        err = imx_sata_port0->serr;
        imx_sata_port0->serr = err;
        imx_sata_port0->is = stat;  //clear port interrupt status
        imx_sata_host->is |= SATA_AHCI_HOST_IS_PORT_N_INTR_ISSUED(port_no);
    } else {
        /* Clear interrupt */
        //PRINT(0,"+SATAINFO: Port.IS = 0x%08x\n",imx_sata_host->is);
        stat = imx_sata_port0->is;
        err = imx_sata_port0->serr;
        port_stat = imx_sata_port0->ssts;

        if (stat & 0xff000000) {
            //PRINT(0,"+SATAERR: Port0.IS   : 0x%08x\n",stat);
            //sata_port_status_parser(stat);
            //PRINT(0,"+SATAERR: Err Code   : 0x%08x\n",err);
            //PRINT(0,"+SATAERR: Port Status: 0x%08x\n",port_stat);
            ret = SATA_FAIL;
        } else {
            ret = SATA_PASS;
        }

        PRINT(0, "+SATAINFO: TFD is 0x%08x\n", imx_sata_port0->tfd);

        imx_sata_port0->serr = err;
        imx_sata_port0->is = stat;  //clear port interrupt status
        imx_sata_host->is |= SATA_AHCI_HOST_IS_PORT_N_INTR_ISSUED(port_no); //clear host global interrupt status
    }

    return ret;
}

/*=============================================================================
FUNCTION: 			sata_reg_fis_h2d
DESCRIPTION:    	send a RFIS to SATA device
ARGUMENTS PASSED: 	sata_ahci_regs_t * ahci - the AHCI base address
RETURN VALUE:		return the first empty command slot during tranversing
IMPORTANT NOTES:	None
==============================================================================*/
static sata_return_t sata_reg_fis_h2d(sata_port_regs_t * port,  //the base address of the SATA port to run the command
                                      u32 sect_addr,    //start address of the first sector
                                      u32 sect_cnt, //the sector number to read or write
                                      u32 rw,   //the data transfer direction: read or write
                                      u32 command,  //ATAPI command code
                                      char features,    //content in feature register of the shadow register block
                                      u32 size, //the data transfer size in byte
                                      u32 data_addr,    //base address of data buffer
                                      sata_command_header_t * cmdh, //the pointer of command header
                                      sata_command_table_t * cmdt)  //the pointer of command table
{
    s32 ept_cmd_slot = -1;
    sata_command_header_t *cmd_hdr;

    /*get empty command slot */
    ept_cmd_slot = ahci_find_empty_slot(port);
    PRINT(0, "+SATAERR: find empty command slot %d\n", ept_cmd_slot);

    if (ept_cmd_slot == -1) {
        return SATA_FAIL;
    }

    /*fill command header */
    cmd_hdr = (sata_command_header_t *) ((u32) cmdh + ept_cmd_slot * sizeof(sata_command_header_t));
    memset((void *)cmd_hdr, 0x0, sizeof(sata_command_header_t));    //clear the command header to zero

    PRINT(0, "+SATAINFO: command header base 0x%8x\n", (u32) cmd_hdr);

    cmd_hdr->info.field.cfl = 5;    //length of Command FIS, for register FIS, it's 5 in maximum

    if (rw == SATA_WRITE)
        cmd_hdr->info.field.write = 1;
    else
        cmd_hdr->info.field.write = 0;  //read operation

    cmd_hdr->info.field.prdtl = 1;  //one PRDT
    cmd_hdr->ctba = (u32) cmdt;

    //printf_buffer((u32)cmd_hdr,sizeof(sata_command_header_t),0);
    PRINT(0, "+SATAINFO: command table base 0x%8x\n", (u32) cmdt);
    /*fill command table */

    memset((void *)cmdt, 0x0, sizeof(sata_command_table_t));

    cmdt->cfis.fisType = SATA_FIS_TYPE_RFIS_H2D;
    cmdt->cfis.pmPort_Cbit = 0x80;
    cmdt->cfis.command = command;
    cmdt->cfis.features = features;
    cmdt->cfis.lbaLow = (sect_addr & 0xFF);
    cmdt->cfis.lbaMid = ((sect_addr >> 8) & 0xFF);
    cmdt->cfis.lbaHigh = ((sect_addr >> 16) & 0xFF);
    cmdt->cfis.device = 0x40;
    cmdt->cfis.sectorNum = sect_cnt;

    cmdt->prdt.dba = data_addr;
    cmdt->prdt.dbc_ioc = ((size) - 1) | (IOC << 31);

    //printf_buffer((u32)cmdt,sizeof(sata_command_table_t),0);

    /*execute the command */
    port->ci |= (1 << ept_cmd_slot);

    return SATA_PASS;
}

/*=============================================================================
FUNCTION: 			sata_non_queued_error_recovery
DESCRIPTION:    	sata attempts to recover from an error
ARGUMENTS PASSED: 	None
RETURN VALUE:		pass or fail
IMPORTANT NOTES:	None
==============================================================================*/
static sata_return_t sata_non_queued_error_recovery(void)
{
    sata_return_t ret;
    u32 v;
    u32 errslot;
    u32 cnt;
    /*a - read PxCI to see which commands are still outstanding */
    v = imx_sata_port0->ci;
    PRINT(1, "+SATAINFO: outstanding command slots 0x%08x\n", v);
    //b - read PxCMD.CCS to determine the slot that the HBA was processing when
    //the error occured
    errslot = (imx_sata_port0->cmd & SATA_AHCI_PORT_N_CMD_CCS_MASK) >> 8;
    PRINT(1, "+SATAINFO: error occurs to command slot %d\n", errslot);
    //c - clear PxCMD.ST to 0 to reset the PxCI register, waits for PxCMD.CR to clear
    //to '0'
    imx_sata_port0->cmd &= ~SATA_AHCI_PORT_N_CMD_START;
    hal_delay_us(PORT_N_INIT_TIMEOUT);  //delay 500ms

    if (imx_sata_port0->cmd & SATA_AHCI_PORT_N_CMD_CR) {
        ret = SATA_FAIL;
        PRINT(1, "+SATADBGMSG:PxCMD.CR does not return to zero.\n");
        return ret;
    }
    //d - clear any error bits in PxSERR to enable capturing new errors
    v = imx_sata_port0->serr;
    imx_sata_port0->serr = v;
    //e - clear status bits in PxIS as appropriate
    v = imx_sata_port0->is;
    imx_sata_port0->is = v;

    v = imx_sata_host->is;
    imx_sata_host->is = v;

    //f - if PxTFD.STS.BSY or PxTFD.STS.DRQ is set to '1', issue a COMRESET to the device
    //to put it in an idle state
    if (imx_sata_port0->tfd & SATA_AHCI_PORT_N_TFD_MASK) {
        if (imx_sata_port0->cmd & SATA_AHCI_PORT_N_CMD_SUD) {
            imx_sata_port0->cmd &= ~SATA_AHCI_PORT_N_CMD_SUD;
        }

        hal_delay_us(10);       //delay 1ms
        imx_sata_port0->cmd |= SATA_AHCI_PORT_N_CMD_SUD;

        /*Start detect the attached device */
        //imx_sata_port0->sctl |= (SCTL_DET_COMM_INIT);//|SCTL_SPD_GEN2_NEGOCIATE);

        hal_delay_us(1500);     //delay at least 1ms after communication init
        /*wait spin-up finished */
        cnt = MAX_TIMEOUT_COUNTER;

        while (--cnt) {
            if (!(imx_sata_port0->tfd & SATA_AHCI_PORT_N_TFD_MASK)) {
                PRINT(1, "+SATADBGMSG: device ready now\n");
                PRINT(1, "+SATAERR : tfd 0x%08x\n", imx_sata_port0->tfd);
                break;
            }

        }

        if (!cnt) {
            PRINT(1, "+SATAERR : Timeout to get device ready\n");
            return SATA_FAIL;
        }
    }
    //g - sets PxCMD.ST to '1' to enable issuing new commands
    imx_sata_port0->cmd |= SATA_AHCI_PORT_N_CMD_START;

    return SATA_PASS;
}

//SATA PHY Control Functions
/*=============================================================================
FUNCTION: 			sata_phy_cr_ack_polling
DESCRIPTION:    	check the PHY control register acknowledge
ARGUMENTS PASSED: 	u32 expected_val - expected value in PHY status
                    register
RETURN VALUE:		return the first empty command slot during tranversing
IMPORTANT NOTES:	None
==============================================================================*/
static sata_return_t sata_phy_cr_ack_polling(u32 max_iterations, u32 expected_val)
{
    u32 v, ack;
    u32 wait_counter;

    ack = !expected_val;
    wait_counter = 0;

    while ((wait_counter < max_iterations) && (ack != expected_val)) {
        v = imx_sata_port0->physr;
        ack = ((v >> SATA_CR_STAT_ACK_LOC) & 0x1);
        wait_counter++;
    }

    if (wait_counter == max_iterations)
        return SATA_FAIL;
    else
        return SATA_PASS;
}

static sata_return_t sata_phy_cr_write(u32 addr, u32 val)
{
    u32 v;
    // write addr
    v = addr << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = v;

    // capture addr
    v |= (0x1 << SATA_CR_CTL_CAP_ADR_LOC);
    imx_sata_port0->phycr = v;

    // wait for ack
    if (sata_phy_cr_ack_polling(100, 1)) {
        PRINT(0, "SATAERR: PHY Not responding cap addr assertion\n");
        return SATA_FAIL;
    }
    // deassert cap data
    v &= 0xffff << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = v;

    // wait for ack de-assetion
    if (sata_phy_cr_ack_polling(100, 0)) {
        PRINT(0, "SATAERR: PHY Not responding cap addr de-assetion\n");
        return SATA_FAIL;
    }
    // write data
    v = val << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = v;

    // capture data
    v |= (0x1 << SATA_CR_CTL_CAP_DAT_LOC);
    imx_sata_port0->phycr = v;

    // wait for ack
    if (sata_phy_cr_ack_polling(100, 1)) {
        PRINT(0, "SATAERR: PHY Not responding cap dat assertion\n");
        return SATA_FAIL;
    }
    // deassert cap data
    v &= 0xffff << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = v;

    // wait for ack de-assetion
    if (sata_phy_cr_ack_polling(100, 0)) {
        PRINT(0, "SATAERR: PHY Not responding cap data de-assetion\n");
        return SATA_FAIL;
    }
    // assert wr signal
    v = 0x1 << SATA_CR_CTL_WR_LOC;
    imx_sata_port0->phycr = v;

    // wait for ack
    if (sata_phy_cr_ack_polling(100, 1)) {
        PRINT(0, "SATAERR: PHY Not responding write\n");
        return SATA_FAIL;
    }
    // deassert rd _signal
    v = 0x0;
    imx_sata_port0->phycr = v;

    // wait for ack de-assetion
    if (sata_phy_cr_ack_polling(100, 0)) {
        PRINT(0, "SATAERR: PHY Not responding write de-assetion\n");
        return SATA_FAIL;
    }

    return SATA_PASS;
}

static sata_return_t sata_phy_cr_read(u32 addr, u32 * data)
{
    u32 temp_rd_data;
    u32 temp_wr_data;
    // write addr
    temp_wr_data = addr << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = temp_wr_data;

    // capture addr
    temp_wr_data |= (0x1 << SATA_CR_CTL_CAP_ADR_LOC);
    imx_sata_port0->phycr = temp_wr_data;

    // wait for ack
    if (sata_phy_cr_ack_polling(100, 1)) {
        PRINT(0, "SATAERR: PHY Not responding cap addr assertion\n");
        return SATA_FAIL;
    }
    // deassert cap addr
    temp_wr_data &= 0xffff << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = temp_wr_data;

    // wait for ack de-assetion
    if (sata_phy_cr_ack_polling(100, 0)) {
        PRINT(0, "SATAERR: PHY Not responding cap addr de-assetion\n");
        return SATA_FAIL;
    }
    // assert rd signal
    temp_wr_data = 0x1 << SATA_CR_CTL_RD_LOC;
    imx_sata_port0->phycr = temp_wr_data;

    // wait for ack
    if (sata_phy_cr_ack_polling(100, 1)) {
        PRINT(0, "SATAERR: PHY Not responding read\n");
        return SATA_FAIL;
    }
    // after got ack return data
    temp_rd_data = imx_sata_port0->physr;
    *data = (temp_rd_data & (0xffff << SATA_CR_STAT_DATA_LOC));
    // deassert rd _signal
    temp_wr_data = 0x0;
    imx_sata_port0->phycr = temp_wr_data;

    // wait for ack de-assetion
    if (sata_phy_cr_ack_polling(100, 0)) {
        PRINT(0, "SATAERR: PHY Not responding read de-assetion\n");
        return SATA_FAIL;
    }

    return 0;
}

static sata_return_t sata_phy_cr_addr(u32 addr)
{
    u32 temp_wr_data;
    // write addr
    temp_wr_data = addr << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = temp_wr_data;

    // capture addr
    temp_wr_data |= (0x1 << SATA_CR_CTL_CAP_ADR_LOC);
    imx_sata_port0->phycr = temp_wr_data;

    // wait for ack
    if (sata_phy_cr_ack_polling(100, 1)) {
        PRINT(0, "SATAERR: PHY Not responding cap addr assertion\n");
        return SATA_FAIL;
    }
    // deassert cap addr
    temp_wr_data &= 0xffff << SATA_CR_CTL_DATA_LOC;
    imx_sata_port0->phycr = temp_wr_data;

    // wait for ack de-assetion
    if (sata_phy_cr_ack_polling(100, 0)) {
        PRINT(0, "SATAERR: PHY Not responding cap addr de-assetion\n");
        return SATA_FAIL;
    }

    return SATA_PASS;
}

/* freq overide reg
prop_ctl 2:0 RWCr Proportional charge pump control Proportional current = (n + 1) / 8 x full_scale
int_ctl 5:3 RWCr Integral charge pump control Integral current = (n + 1) / 8 x full_scale
ncy5 7:6 RWCr Divide-by-5 control MPLL Divider period = 4 x (NCY + 1) + NCY5.  Valid only when NCY5  NCY.
ncy 12:8 RWCr Divide-by-4 cycle control MPLL Divider period = 4 x (NCY + 1) + NCY5.  Valid only when NCY5  NCY.
prescale 14:13 RWCr Prescaler control:
 00: No scaling
 01: Doubles refclk frequency
 10: Halves refclk frequency
 11: Reserved
ovrd 15 RWCr Enables override of all bits in this register
The SATA Baudrate is 1.5Gpbs
Baudrate = MPLL_DIV * CLK
for 25Mhz, CLK = ref_clk * prescaler = 50Mhz
for 100Mhz, CLK = ref_clk /prescaler = 50Mhz

MPLL_DIV are both 30 for 25Mhz and 100Mhz ref clock

asuuming 25MHZ input:
sata_configure_mpll
(
    7,   // prop_ctl
    0,   // int_ctl
    2,   // ncy5
    6,   // ncy
    1,   // prescale
)

asuuming 50MHZ input:
sata_configure_mpll
(
    7,   // prop_ctl
    0,   // int_ctl
    2,   // ncy5
    6,   // ncy
    0,   // prescale
)
*/
static void sata_phy_config_mpll(char prop_ctl, char int_ctl, char ncy5, char ncy, char prescale)
{
    u32 freq_ovrd;

    freq_ovrd = prop_ctl | (int_ctl << 3) | (ncy5 << 6) | (ncy << 8) | (prescale << 13) | (1 << 15);
    //PRINT(0,"+SATAPHY: Phy Freq Ovrd: 0x%04x\n",freq_ovrd);
    //check rd-wr to reg
    sata_phy_cr_write(SATA_PHY_CR_CLOCK_FREQ_OVRD, freq_ovrd);

    hal_delay_us(10);
}

///////////////////////////////////////////////////////////////////
//                  Global Function Defintions                   //
///////////////////////////////////////////////////////////////////

/*=============================================================================
FUNCTION: 			sata_init
DESCRIPTION:    	Initialize SATA Controller and also identify an attached hdd
ARGUMENTS PASSED: 	None
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
sata_return_t sata_init(sata_ahci_regs_t * ahci)
{
    sata_return_t ret = SATA_PASS;
    u32 i = 0;
    u32 cnt;
    u32 ports;
    u32 cmd_slots;
    u32 v;

    sata_port_regs_t *port_n_regs;

    sata_power_on();

    if (sata_phy_clk_sel == OSC_UNKNOWN) {
        sata_phy_clk_sel = OSC_50MHZ;
        PRINT(0, "+SATADBGMSG: Ref Clk %d\n", sata_phy_clk_sel);
    }

    /*SATA clock initialization. */
    sata_clock_init(&sata_phy_clk_sel);

    /*Reset HBA */
    //ahci->ghc = SATA_AHCI_HOST_GHC_HBA_RESET;
    //ahci->ghc = SATA_AHCI_HOST_GHC_AHCI_ENABLED;
    //while(ahci->ghc&SATA_AHCI_HOST_GHC_HBA_RESET);

    /*!!Rita specific configuration!! */
    /*Set 1ms timer count value */
    ahci->timer1ms = SATA_AHCI_HOST_TIMER1MS_MASK;
    PRINT(0, "+SATADBGMSG: Timer1ms@0x%08x = 0x%08x\n", (u32) (&(ahci->timer1ms)), ahci->timer1ms);

    /*Set OOBR register */
    ahci->oobr = SATA_AHCI_HOST_OOBR_WE;
    ahci->oobr = (SATA_AHCI_HOST_OOBR_COMWAKE_MIN_VAL
                  | SATA_AHCI_HOST_OOBR_COMWAKE_MAX_VAL
                  | SATA_AHCI_HOST_OOBR_COMINIT_MIN_VAL | SATA_AHCI_HOST_OOBR_COMINIT_MAX_VAL);
    /*!!Rita specific configuration end!! */

    /*firmware initialize */
    /*Support Staggered Spin-Up */
    ahci->cap |= (SATA_AHCI_HOST_CAP_SSS);

    /*Reading PI register to determine which ports are implemented by HBA */
    ports = ahci->cap & SATA_AHCI_HOST_CAP_NP_MASK;
    ports += 1;

    for (i = 0; i < ports; i++) {
        ahci->pi |= (1 << i);
    }

    /*Clear HBA interrupt status */
    //ahci->is = 0xFF;

    for (i = 0; i < ports; i++) {
        PRINT(0, "+SATADBGMSG: Port %d Implemented\n", i);
        port_n_regs = (sata_port_regs_t *) SATA_PORT_N_BASE_ADDRESS(i, ahci);
        //PRINT(0,"+SATADBGMSG: Port %d register base 0x%08x\n",i,(u32)port_n_regs);
        /*Place the port into IDLE state */
        ret = sata_ahci_set_port_idle(port_n_regs);

        if (ret) {
            PRINT(0, "+SATADBGMSG: Error - Port reset or HBA reset is required\n");
            return SATA_FAIL;
        }

        /*Spin-up the port */
        port_n_regs->cmd |= SATA_AHCI_PORT_N_CMD_SUD;

        /*Start detect the attached device */
        port_n_regs->sctl |= (SCTL_DET_COMM_INIT | SCTL_IPM_TRANS_TO_BOTH_PM_DIS);

        hal_delay_us(1500);     //delay at least 1ms after communication init
        /*wait spin-up finished */
        cnt = MAX_TIMEOUT_COUNTER;

        while (cnt) {
            if ((port_n_regs->cmd & SATA_AHCI_PORT_N_CMD_SUD)) {
                PRINT(0, "+SATADBGMSG: Spin-Up Device completed\n");
                break;
            }

            cnt--;
        }

        if (!cnt) {
            PRINT(1, "+SATAERR : Timeout to Spin-Up Device\n");
            return SATA_FAIL;
        }

        port_n_regs->sctl &= ~SATA_AHCI_PORT_N_SCTL_DET_MASK;
        /*Allocate memory for each implemented port, and program PxCLB/CLBU/FB/FBU.
           It's better to clear the memory regions.
           After setting PxFB/FBU,software should set PxCMD.FRE to '1'
         */
        PRINT(0, "+SATADBGMSG: Allocate the memory for port %d\n", i);

        /*i.MX53 only supports Port 0 */
        //PRINT(0,"+SATADBGMSG: set CLB and FB base addr of port %d\n",i);
        //PRINT(0,"+SATADBGMSG: allocated clb addr 0x%08x\n",SATA_COMMAND_LIST_BASE);
        //PRINT(0,"+SATADBGMSG: allocated fb addr 0x%08x\n",SATA_FIS_BASE);
        memset((char *)(SATA_COMMAND_LIST_BASE + i * sizeof(sata_command_header_t) * 32), 0,
               sizeof(sata_command_header_t) * 32);
        port_n_regs->clb = (SATA_COMMAND_LIST_BASE + i * sizeof(sata_command_header_t) * 32);
        memset((char *)(SATA_RECEIVED_FIS_BASE + i * sizeof(sata_rx_fis_t)), 0,
               sizeof(sata_rx_fis_t));
        port_n_regs->fb = SATA_RECEIVED_FIS_BASE;

        /*Set the AHB burst size and transaction size
           port_n_regs->dmacr = (DMACR_AHB_BURST_SIZE_8_DWORDS<<SATA_AHCI_PORT_N_DMACR_RXABL_SHIFT)
           |(DMACR_AHB_BURST_SIZE_8_DWORDS<<SATA_AHCI_PORT_N_DMACR_TXABL_SHIFT)
           |(DMACR_TRANSAC_SIZE_16_DWORDS<<SATA_AHCI_PORT_N_DMACR_RXTS_SHIFT)
           |(DMACR_TRANSAC_SIZE_16_DWORDS<<SATA_AHCI_PORT_N_DMACR_TXTS_SHIFT);
         */
        PRINT(0, "+SATADBGMSG: PxDMACR@0x%08x = 0x%08x\n", (u32) (&(port_n_regs->dmacr)),
              (u32) (port_n_regs->dmacr));
        port_n_regs->cmd |= (SATA_AHCI_PORT_N_CMD_FRE);
        //PRINT(0,"+SATADBGMSG: clb addr 0x%08x\n",port_n_regs->clb);
        //PRINT(0,"+SATADBGMSG: fb addr 0x%08x\n",port_n_regs->fb);

        cnt = MAX_TIMEOUT_COUNTER;

        while (cnt) {
            if (((port_n_regs->ssts & SATA_AHCI_PORT_N_SSTS_DET_MASK) == SSTS_DET_DEV_DET_NO_PHY)
                || ((port_n_regs->ssts & SATA_AHCI_PORT_N_SSTS_DET_MASK) ==
                    SSTS_DET_DEV_DET_PHY_RDY)) {
                PRINT(1, "+SATADBGMSG: SATA Device Detected\n");
                break;
            }

            cnt--;
        }

        if (!cnt) {
            PRINT(1, "+SATAERR : Timeout to detect SATA device\n");
            return SATA_FAIL;
        }

        /*Check DIAG_X */
        cnt = MAX_TIMEOUT_COUNTER;

        while (cnt) {
            if (port_n_regs->serr & SATA_AHCI_PORT_N_SERR_DIAG_X) {
                PRINT(0, "+SATADBGMSG: P0SERR:0x%08x\n", port_n_regs->serr);
                PRINT(0, "+SATADBGMSG: DIAG_X\n");
                break;
            }

            cnt--;
        }

        if (!cnt) {
            PRINT(1, "+SATAERR : Timeout to check DIAG_X\n");
            return SATA_FAIL;
        }

        v = port_n_regs->serr;
        port_n_regs->serr = v;

        /*Check Task-File-Data */
        cnt = MAX_TIMEOUT_COUNTER;

        while (cnt) {
            if ((port_n_regs->tfd & SATA_AHCI_PORT_N_TFD_MASK) == 0) {
                PRINT(0, "+SATADBGMSG: Device ready\n");
                break;
            }

            cnt--;
        }

        if (!cnt) {
            PRINT(1, "+SATAERR : Timeout to check TFD\n");
            return SATA_FAIL;
        }

        /*Determine which events should cause an interrupt, and set each implemented port's
           PxIE register.
           Bit 0, DHRE, Device to Host Register FIS Interrupt
           Bit 1, PSE,  PIO Setup FIS Interrupt
           Bit 2, DSE,  DMA Setup FIS Interrupt
           Bit 3, SDBE, Set Device Bits FIS Interrupt
           Bit 4, UFE,  Unknown FIS Interrupt
           Bit 6, PCE,  Port Change Interrupt
           Bit 24,OFE,  Overflow Interrupt
           Bit 32,CPDE, Cold Port Detect Interrupt
         */
        PRINT(0, "+SATADBGMSG: Enable the interrupts of port %d\n", i);
        port_n_regs->is = 0xFFFFFFFF;   //clear all the old interrupt status;
        /*Clear PxSERR register of each implemented port by writing '1' to each implemented
           bit loation */
        PRINT(0, "+SATADBGMSG: Clear SERR register of port %d\n", i);
        port_n_regs->serr = 0xFFFFFFFF;

        port_n_regs->ie = SATA_AHCI_PORT_N_INTR_ENANBLE_MASK;
        PRINT(0, "+SATADBGMSG: Port %d.IE = 0x%08x\n", i, port_n_regs->ie);
    }

    /*Reading CAP.NCS to determine the command slots the HBA supports */
    cmd_slots = (ahci->cap & SATA_AHCI_HOST_CAP_NCS_MASK) >> SATA_AHCI_HOST_CAP_NCS_SHIFT;

    /*Enable SATA interrupt */
    ahci->ghc |= SATA_AHCI_HOST_GHC_INTR_ENABLED;

    /*Start the ports */
    for (i = 0; i < ports; i++) {
        port_n_regs = (sata_port_regs_t *) SATA_PORT_N_BASE_ADDRESS(i, ahci);
        port_n_regs->cmd |= SATA_AHCI_PORT_N_CMD_START;
    }

    sata_ahci_host_info_print(ahci);

    return ret;
}

/*=============================================================================
FUNCTION: 			sata_deinit
DESCRIPTION:    	Initialize SATA Controller and also identify an attached hdd
ARGUMENTS PASSED: 	None
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
sata_return_t sata_deinit(sata_ahci_regs_t * ahci)
{
    sata_return_t ret = SATA_PASS;
    u32 i = 0;
    u32 ports;

    sata_port_regs_t *port_n_regs;
    PRINT(0, "sata_deinit\n");

    /*Reading PI register to determine which ports are implemented by HBA */
    ports = ahci->cap & SATA_AHCI_HOST_CAP_NP_MASK;
    ports += 1;

    for (i = 0; i < ports; i++) {
        ahci->pi |= (1 << i);
    }

    /*Clear HBA interrupt status */
    //ahci->is = 0xFF;

    for (i = 0; i < ports; i++) {
        PRINT(0, "+SATADBGMSG: Port %d Implemented\n", i);
        port_n_regs = (sata_port_regs_t *) SATA_PORT_N_BASE_ADDRESS(i, ahci);
        //PRINT(0,"+SATADBGMSG: Port %d register base 0x%08x\n",i,(u32)port_n_regs);

        /*power off the port */
        port_n_regs->cmd &= ~(SATA_AHCI_PORT_N_CMD_SUD | SATA_AHCI_PORT_N_CMD_POD);

        /*Place the port into IDLE state */
        ret = sata_ahci_port_reset(port_n_regs);

        if (ret == SATA_FAIL) {
            PRINT(0, "+SATADBGMSG: Port %d reset fail.\n", i);
        }
    }

    //reset HBA
    ahci->ghc = SATA_AHCI_HOST_GHC_HBA_RESET;

    //disable AHCI
    ahci->ghc = ~SATA_AHCI_HOST_GHC_AHCI_ENABLED;

    return ret;
}

/*=============================================================================
FUNCTION: 			identify_sata_hdd
DESCRIPTION:    	detect the attached HDD and try to initialize it
ARGUMENTS PASSED: 	sata_ahci_regs_t * ahci - the base address of HBA controller
                    u32 port_number - the port to detect
RETURN VALUE:		None
IMPORTANT NOTES:	None
==============================================================================*/
sata_return_t sata_identify(sata_ahci_regs_t * ahci, u32 port_number)
{
    sata_port_regs_t *port;
    u32 hdd_attached;
    u32 hdd_sig;

    port = imx_sata_port0;
    PRINT(0, "+SATADBGMSG: SATA port %d base@0x%08x.\n", port_number, (u32) port);
    // 1. check if there is HDD attached.
    hdd_attached = (port->ssts & SATA_AHCI_PORT_N_SSTS_DET_MASK);
    PRINT(0, "+SATADBGMSG: port->ssts = 0x%08x.\n", port->ssts);

    switch (hdd_attached) {
    case SSTS_DET_NO_DEVICE_NO_PHY:
        PRINT(0, "+SATAINFO:No SATA HDD Attached\n");
        return SATA_FAIL;       //fail
    case SSTS_DET_DEV_DET_NO_PHY:
        PRINT(0, "+SATAINFO:SATA HDD Attached, but PHY not established\n");
        //configure PHY
        port->sctl = (SCTL_DET_COMM_INIT | SCTL_SPD_GEN2_NEGOCIATE);
        hal_delay_us(1200);     //at least 1ms is required to ensure COMRESET is sent
        port->cmd |= SATA_AHCI_PORT_N_CMD_START;

        if ((port->ssts & SATA_AHCI_PORT_N_SSTS_DET_MASK) != SSTS_DET_DEV_DET_PHY_RDY) {
            PRINT(0, "+SATAINFO:PHY establish fail\n");
            return SATA_FAIL;
        }

        PRINT(0, "+SATAINFO:P0SSTS is 0x%08x\n", port->ssts);
        PRINT(0, "+SATAINFO:PHY establish done\n");
        break;
    case SSTS_DET_DEV_DET_PHY_RDY:
        PRINT(0, "+SATAINFO:SATA HDD Attached, PHY established\n");
        //ready to read the sector 0 to get HDD info
        break;
    case SSTS_DET_PHY_OFFLINE:
    default:
        PRINT(0, "+SATAINFO:SATA DET Status Unknown or unsupported\n");
        return SATA_FAIL;       //faile
    }

    PRINT(0, "+SATAINFO:SATA HDD found on the port %d, ready to get HDD info\n", port_number);

    hdd_sig = port->sig;

    sata_hdd_init();

    return SATA_PASS;
}

//EOF sata_imx.c
