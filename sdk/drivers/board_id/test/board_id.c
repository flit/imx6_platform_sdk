/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file hardware.c
 * @brief This file contains the module definitions and some init functions.
 *
 * @ingroup diag_init
 */

#include "board_id/board_id.h"
#include "soc_memory_map.h"
//#include "ccm_pll_reg_define.h"
#include "ccm_pll.h"

void chip_name_func(char *name, uint32_t chip_id, bool long_name_flag)
{
    char long_name[64] = { 0 };

    switch (chip_id) {
    case CHIP_TYPE_MX6SL:
        sprintf(name, "MX6SL");
        sprintf(long_name, "MX6 Solo-Lite (MX6SL)");
        break;
    case CHIP_TYPE_MX6SDL:
        sprintf(name, "MX6SDL");
        sprintf(long_name, "MX6 Solo/Dual-Lite (MX6SDL)");
        break;
    case CHIP_TYPE_MX6DQ:
        sprintf(name, "MX6DQ");
        sprintf(long_name, "MX6 Dual/Quad (MX6DQ)");
        break;
    default:
        sprintf(name, "UNKNOWN");
        sprintf(long_name, "UNKNOWN CHIP");
        break;
    }

    if (long_name_flag) {
        sprintf(name, long_name);
    }
}

void chip_revision_func(char *rev_str, uint32_t major_rev, uint32_t minor_rev)
{
    char major = 'x';
    char minor = 'x';

    switch (major_rev) {
    case CHIP_MAJOR_REV_TO1:
        major = '1';
        break;
    case CHIP_MAJOR_REV_TO2:
        major = '2';
        break;
    default:
        major = 'x';
        break;
    }

    switch (minor_rev) {
    case CHIP_MINOR_REV_DOT0:
        minor = '0';
        break;
    case CHIP_MINOR_REV_DOT1:
        minor = '1';
        break;
    case CHIP_MINOR_REV_DOT2:
        minor = '2';
        break;
    default:
        minor = 'x';
        break;
    }

    sprintf(rev_str, "TO%c.%c", major, minor);
}

void board_name_func(char *name, uint32_t board_id)
{
    switch (board_id) {
    case BOARD_TYPE_SABRE_AI:
        sprintf(name, "Sabre AI (ARD)");
        break;
    case BOARD_TYPE_SMART_DEVICE:
        sprintf(name, "Smart Device (SD)");
        break;
    case BOARD_TYPE_SABRE_LITE:
        sprintf(name, "Sabre Lite (QSB)");
        break;
    case BOARD_TYPE_EVB:
        sprintf(name, "EVB");
        break;
    default:
        sprintf(name, "UNKNOWN BOARD");
        break;
    }
}

void board_revision_func(char *name, uint32_t board_rev)
{
    char revision[8] = "rev. x\0\0";

    switch (board_rev) {
    case 1:
        revision[5] = 'A';
        break;
    case 2:
        revision[5] = 'B';
        break;
    case 3:
        revision[5] = 'C';
        break;
    default:
        revision[5] = (char)((board_rev & 0xFF) + '0');
        break;
    }

    sprintf(name, revision);
}

void board_description(char *desc)
{
	fsl_board_id_t board_id = get_board_id();

	char chip_str[64] = { 0 };
	char chip_rev_str[64] = { 0 };
	char board_str[64] = { 0 };
	char board_rev_str[64] = { 0 };

	chip_name_func(chip_str, board_id.B.CHIP_TYPE_ID, false);
	chip_revision_func(chip_rev_str, board_id.B.CHIP_REV_MAJOR, board_id.B.CHIP_REV_MINOR);
	board_name_func(board_str, board_id.B.BOARD_TYPE_IDD);
	board_revision_func(board_rev_str, board_id.B.BOARD_REV);

	sprintf(desc, "%s %s %s %s", chip_str, chip_rev_str, board_str, board_rev_str);
}

/*!
 * Get the board id info
 */
fsl_board_id_t get_board_id(void)
{
    fsl_board_id_t fsl_board_id = { 0 };

    uint32_t anatop_chip_id = HW_USB_ANALOG_DIGPROG_RD();
    fsl_board_id.B.CHIP_TYPE_ID = BG_USB_ANALOG_DIGPROG_CHIP_TYPE(anatop_chip_id);
    fsl_board_id.B.CHIP_REV_MAJOR = BG_USB_ANALOG_DIGPROG_MAJOR_REV(anatop_chip_id);
    fsl_board_id.B.CHIP_REV_MINOR = BG_USB_ANALOG_DIGPROG_MINOR(anatop_chip_id);
//    printf("read 0x%08X from HW_USB_ANALOG_DIGPROG(0x%08X)\n", anatop_chip_id, HW_USB_ANALOG_DIGPROG_ADDR);

    uint32_t fused_board_id = HW_OCOTP_GP1_RD();
    fsl_board_id.B.BOARD_TYPE_IDD = BG_OCOTP_GP1_BOARD_TYPE(fused_board_id);
    fsl_board_id.B.BOARD_REV = BG_OCOTP_GP1_BOARD_REV(fused_board_id);
//    printf("read 0x%08X from HW_OCOTP_GP1(0x%08X)\n", fused_board_id, HW_OCOTP_GP1_ADDR);

    return fsl_board_id;
}

/*!
 * Display board id info
 */
void show_board_id(fsl_board_id_t board_id)
{
    printf("========== board id\n");

    char chip_str[64] = { 0 };
    char chip_str_full[64] = { 0 };
    char chip_rev_str[64] = { 0 };
    char board_str[64] = { 0 };
    char board_rev_str[64] = { 0 };

    chip_name_func(chip_str, board_id.B.CHIP_TYPE_ID, false);
    chip_name_func(chip_str_full, board_id.B.CHIP_TYPE_ID, true);
    chip_revision_func(chip_rev_str, board_id.B.CHIP_REV_MAJOR, board_id.B.CHIP_REV_MINOR);
    board_name_func(board_str, board_id.B.BOARD_TYPE_IDD);
    board_revision_func(board_rev_str, board_id.B.BOARD_REV);

    printf("\n%s %s %s %s (0x%08X)\n", chip_str, chip_rev_str, board_str, board_rev_str,
           board_id.U);
    printf("    Chip Type       = %s (0x%02X)\n", chip_str_full, board_id.B.CHIP_TYPE_ID);
    printf("    Chip Revision   = %s (0x%02X)(0x%02X)\n", chip_rev_str, board_id.B.CHIP_REV_MAJOR,
           board_id.B.CHIP_REV_MINOR);
    printf("    Board Type      = %s (0x%02X)\n", board_str, board_id.B.BOARD_TYPE_IDD);
    printf("    Board Revision  = %s (0x%02X)\n", board_rev_str, board_id.B.BOARD_REV);

    printf("==================================\n\n");
}

/*!
 * Program the board type and revision efuse
 *
 * @return  0 if successful; non-zero otherwise
 */
int program_board_id_fuses(uint32_t board_type, uint32_t board_rev)
{
//   uint32_t reg_word = ((board_type & 0xf) << 12) | ((board_rev & 0xF) << 8);

    /* First, allow fuse programming in the CCM CGPR register by setting the 'efuse_prog_supply_gate' bit */
    unsigned int temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp |= 0x00000010;         // set bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

    printf("  ** Board ID Fuses before program 0x%x\n",
            (get_board_id().B.BOARD_TYPE_IDD << 4) | get_board_id().B.BOARD_REV);

    /* blow the fuse */
//    fuse_blow_row(HW_OCOTP_GP1_BANK, HW_OCOTP_GP1_ROW, reg_word);
//    if (sense_fuse(HW_OCOTP_GP1_BANK, HW_OCOTP_GP1_ROW) != reg_word) {
//        printf("  ** Fuse read-back-verify failed, read back 0x%x, should be: 0x%x\n",
//               sense_fuse(HW_OCOTP_GP1_BANK, HW_OCOTP_GP1_ROW), reg_word);

        /* Disable fuse programming in the CCM CGPR register by clearing the 'efuse_prog_supply_gate' bit */
//        temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
//        temp &= ~(0x00000010);  // clear bit 4, efuse_prog_supply_gate bit
//        writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

//        return TEST_FAILED;
//    }

    printf("  ** Fuses programmed successfully.\n\n");
    printf("  ** Board ID Fuses after program 0x%x\n",
            (get_board_id().B.BOARD_TYPE_IDD << 4) | get_board_id().B.BOARD_REV);

    /* reload the otp shadow registers */
//    reload_otp_shadow_registers();

    printf("  ** Board ID Fuses after reload 0x%x\n",
            (get_board_id().B.BOARD_TYPE_IDD << 4) | get_board_id().B.BOARD_REV);

    /* Disable fuse programming in the CCM CGPR register by clearing the 'efuse_prog_supply_gate' bit */
    temp = readl(CCM_BASE_ADDR + CCM_CGPR_OFFSET);
    temp &= ~(0x00000010);      // clear bit 4, efuse_prog_supply_gate bit
    writel(temp, (CCM_BASE_ADDR + CCM_CGPR_OFFSET));

    return TEST_PASSED;
}

/* Program the board ID fuses if not already done */
int program_board_id_enable = 0;
int program_board_id(void)
{
    if (!program_board_id_enable) {
        return TEST_NOTPRESENT;
    }

    printf("\n---- Running < BOARD ID > test\n");

    char chip_str[64] = { 0 };
    char chip_str_full[64] = { 0 };
    char chip_rev_str[64] = { 0 };
    char board_str[64] = { 0 };
    char board_rev_str[64] = { 0 };

    fsl_board_id_t board_id = get_board_id();

    chip_name_func(chip_str, board_id.B.CHIP_TYPE_ID, false);
    chip_name_func(chip_str_full, board_id.B.CHIP_TYPE_ID, true);
    chip_revision_func(chip_rev_str, board_id.B.CHIP_REV_MAJOR, board_id.B.CHIP_REV_MINOR);
    board_name_func(board_str, board_id.B.BOARD_TYPE_IDD);
    board_revision_func(board_rev_str, board_id.B.BOARD_REV);

    if (board_id.B.BOARD_TYPE_IDD == 0 || board_id.B.BOARD_REV == 0) {
        // Board is not programmed
        printf("\nNo Board ID found in the fuses.\n");
        board_id.B.BOARD_TYPE_IDD = BOARD_TYPE;
        board_id.B.BOARD_REV = BOARD_REVISION;
        printf("This OBDS binary will program Board ID to 0x%08X as detailed below:\n", board_id.U);
        show_board_id(board_id);
        printf("Continue with irreversible operation to program Board ID?\n");
        if (!is_input_char('y')) {
            // Do not program the suggested value to Board ID fuse bank
            printf("NOT programming board ID to fuses.\n\n");
            return TEST_BYPASSED;
        }
        // DO THE PROGRAMMING
        int err = program_board_id_fuses(BOARD_TYPE, BOARD_REVISION);
        if (err == TEST_PASSED) {
            printf("Fuses programmed successfully.\n\n");
            show_board_id(get_board_id());
        }

        return err;
    } 
else if (board_id.B.BOARD_TYPE_IDD != BOARD_TYPE || board_id.B.BOARD_REV != BOARD_REVISION ||
          board_id.B.CHIP_TYPE_ID != CHIP_TYPE) {
        // Software is not compiled for this board
       printf("\nSoftware is not compiled for this board.\n");

        chip_name_func(chip_str, CHIP_TYPE, false);
        board_name_func(board_str, BOARD_TYPE);
        board_revision_func(board_rev_str, BOARD_REVISION);
        printf("Software for %s %s %s.\n", chip_str, board_str, board_rev_str);

        chip_name_func(chip_str, board_id.B.CHIP_TYPE_ID, false);
        board_name_func(board_str, board_id.B.BOARD_TYPE_IDD);
        board_revision_func(board_rev_str, board_id.B.BOARD_REV);
        printf("Board is %s %s %s.\n\n", chip_str, board_str, board_rev_str);

        return TEST_FAILED;
    } else if (board_id.B.BOARD_TYPE_IDD == BOARD_TYPE || board_id.B.BOARD_REV == BOARD_REVISION) {
        // Board ID fuses are already correct
        printf("\nBoard ID fuses are already programmed.\n\n");
        show_board_id(board_id);

        return TEST_PASSED;
    } else {
        // Unhandled cases
        printf("\nUnknown failure.\n\n");
        show_board_id(board_id);

        return TEST_FAILED;
    }

    return TEST_PASSED;
}

//RUN_TEST_EARLY("BOARD ID", program_board_id)
