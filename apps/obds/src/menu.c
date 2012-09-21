/*
 * Copyright (C) 2009-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

/*!
 * @defgroup diag_init Base OBDS files
 */

#include "hardware.h"
#include "board_id/board_id.h"
#include "version.h"
#include "obds.h"
#include "menu.h"

extern test_module_t* obds_test_modules[MAX_TEST_NR];
extern int total_tests;

/*!
 * @file  extra.c
 * @brief menu(); function
 *
 * @ingroup diag_init
 */
void menu(void)
{

    char chip_str[64] = { 0 };
    char chip_str_full[64] = { 0 };
    char chip_rev_str[64] = { 0 };
    char board_str[64] = { 0 };
    char board_rev_str[64] = { 0 };

    fsl_board_id_t fsl_board_id = get_board_id();
    chip_name(chip_str, fsl_board_id.B.CHIP_TYPE_ID, false);
    chip_name(chip_str_full, fsl_board_id.B.CHIP_TYPE_ID, true);
    chip_revision(chip_rev_str, fsl_board_id.B.CHIP_REV_MAJOR, fsl_board_id.B.CHIP_REV_MINOR);
    board_name(board_str, fsl_board_id.B.BOARD_TYPE_ID);
    board_revision(board_rev_str, fsl_board_id.B.BOARD_REV);

	printf("This is an interactive test menu for %s %s %s %s.\n\n", chip_str, chip_rev_str, board_str, board_rev_str);

    while (1) // executing tests
	{
		int idx = 0;
		for (idx = 0; idx < total_tests; ++idx )
		{
			// print menu
			printf("%02d. %s\n", idx, obds_test_modules[idx]->name );
		}

		while (getchar() != NONE_CHAR); // empty key buffer
		char key = '0';
	    int test = -1;

select_test:
	    while (1) // getting user input to specify which test to run
	    {
			if ( test == -1 )
				printf("\n\nEnter test number followed by the enter key, 'm' for menu, or 'q' to exit.\n");

			// get a key press
			while ((key = getchar()) == NONE_CHAR);
			// echo the key
			printf("%c", key);

			if ( key >= '0' && key <= '9' )
			{
				// user entered a number

				// if it's the first number
				if ( test == -1 )
				{
					// we need more input
					test = key-'0';
					continue;
				}
				else
				{
					// got a second number.
					// multiply the first number by 10 and
					// add the second number;
					test = test*10 + key-'0';

					// we're done because there shouldn't be over 100 tests
					printf("\n");
					break;
				}
			}
			else if ( key == '\n' || key == '\r' )
			{
				// user hit ENTER_KEY

				// user hit enter meaning the test number is only one digit.
				// confirm and break or start over.
				if ( test > 0 && test <= 9 )
					break;
				else
				{
					printf("Invalid key.\n");
					// start over with test  number input
					test = -1;
					continue;
				}
			}
			else if ( key == 'q' || key == 'Q' )
			{
				// user hit EXIT key
				printf("\nExiting test menu.\n");
				break;
			}
			else if ( key == 'm' || key == 'M' )
			{
				// user hit MENU key
				printf("\n");
				break;
			}
			else
			{
				// user hit INVLAID key
				printf("\nInvalid key.\n");
				// start over with test  number input
				test = -1;
				continue;
			}

	    } // while (1) - getting user input to specify which test to run

		if ( key == 'q' || key =='Q' )
			break;
		else if  ( key == 'm' || key =='M' )
			continue;

		// run the test
		if ( -1 < test  && test < total_tests )
		{
	    	obds_test_modules[test]->result = (*obds_test_modules[test]->func_ptr)();
	    	if ( obds_test_modules[test]->result == TEST_NOTPRESENT)
	    		printf("%s test is not supported for this configuration.\n", obds_test_modules[test]->name);

	    	test = -1;
			goto select_test;
		}
	    else
	    {
	    	printf("Invalid test number (%d).\n", test+1);
	    	test = -1;
			goto select_test;
	    }

	} // while (1) - executing tests

} // void menu(void)

