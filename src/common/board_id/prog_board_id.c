/*
 * Copyright (C) 2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <stdio.h>
#include "hardware.h"

extern int board_id_fuse_program(void);
extern int board_rev_fuse_program(void);

/* Program the board ID fuses if not already done */
void program_board_id_fuses(char *chip)
{
    int program_board_id_fuse = 1;
    int program_board_rev_fuse = 1;

    if (board_id == 0) {
        if (!auto_run_enable) {
            printf("\nNo Board ID found in the fuses\n");
            printf("This %s SDK binary will program Board ID to 0x%x\n", chip, BOARD_TYPE_ID);
            if (!is_input_char('y'))
                /* Do not program the suggested value to Board ID fuse bank */
                program_board_id_fuse = 0;
        }
        if (program_board_id_fuse) {
            if (board_id_fuse_program() != 0) {
                while (1) ;
            }
        }
        board_id = BOARD_TYPE_ID;
    }
    if (board_rev == 0) {
        if (!auto_run_enable) {
            printf("\nNo Board Rev found in the fuses\n");
            printf("This %s SDK binary will program Board Rev to 0x%x\n", chip, BOARD_VERSION_ID);
            if (!is_input_char('y'))
                /* Do not program the suggested value to Board ID fuse bank */
                program_board_rev_fuse = 0;
        }

        if (program_board_rev_fuse) {
            if (board_rev_fuse_program() != 0) {
                while (1) ;
            }
        }
        board_rev = BOARD_VERSION_ID;
    }
}
