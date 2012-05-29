/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
                      *//*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Fopen.c $                                        
 $Revision: 18 $                                       
 $Date: 9/18/03 11:50a $                                           
 Description: Fopen.c
 Notes:	This file read provides higherlevel API function to open a file
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <filesystem/fsapi.h>   //! \todo malinclusion
#include "platform.h"
#include "bootsecoffset.h"
#include "diroffset.h"

/*----------------------------------------------------------------------------
>  Function Name: int32_t Fopen(uint8_t *filepath,uint8_t *mode)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name
                  2) Mode 
 -----------------------------------------------------------------------------*/

uint8_t ReadBuffer[2048];

uint8_t testfile[] = "subdir/fsproj.h";

 ////////////////////////////////////////////////////////////////////////////////
//
//>  Name:           TestFopenwRead
//
//   Type:           Function
//
//   Description:    Test the read mode for function Fopenw which Supports the UCS3 format.                   
//   Inputs:         none 
//
//   Outputs:        none
//                   
//   Notes:          This function is same as fopen except that passed name is in UCS3 format.
//                   if file does not exist,it will return error.
//<                  In this mode we can only read from the file
//////////////////////////////////////////////////////////////////////////////////
int fat_test(void)
{
    int count = 0;
    int TestResult = 0;
    int32_t fout;

    printf("FSInit				");
    if (FSInit(NULL, bufy, maxdevices, maxhandles, maxcaches) != SUCCESS) {
        TestResult = -1;
        printf("FAIL\n");
    } else {
        printf("PASS\n");
    }

    /*init the drive */
    FSDriveInit(0);

    SetCWDHandle(0);

    if ((fout = Fopen(testfile, (uint8_t *) "r")) < 0)
    {
        printf("Can't open the file: %s !\n", testfile);
        return ERROR_GENERIC;
    }

    printf("File %s opened!\n", testfile);

    while (1) {
        if ((count = Fread(fout, ReadBuffer, 2048)) < 0) {
            Fclose(fout);
            return ERROR_GENERIC;
        } else if (count < 2048) {
            ReadBuffer[count] = '\0';
            printf("%s\n", ReadBuffer);
            break;

        } else {
            printf("%s\n", ReadBuffer);
        }
    }

    printf("\n*****************File Reading End********************\n");

    Fclose(fout);
    FlushCache();
    return 0;
}
