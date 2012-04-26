/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Searchfile.c $                                        
 $Revision: 2 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: Searchfile.c
 Notes:	This file read provides higherlevel API function to search file
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 
#include "DirOffset.h" 

/*----------------------------------------------------------------------------
		Extern Declarations
----------------------------------------------------------------------------*/
/* hardcoded for now */
int32_t Changedirectory(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype)
{return 0;}
/*----------------------------------------------------------------------------
>  Function Name: int32_t Searchfile(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype)

   FunctionType:  Non-Reentrant

   Inputs:        1) Handle Number 
                  2) Pointer to file name
                  3) Stringtype
				   
   Outputs:       HandleNumber of free handle populated by the given filename       
   
   Description:   Searches the specified file.
----------------------------------------------------------------------------*/
int32_t Searchfile(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype)
{
    int32_t filefound, index = 0; 
			  
    SetHandleforsearch(HandleNumber,filepath,stringtype,&index);
    
    filefound =  Changedirectory(HandleNumber,filepath,stringtype);
 
    return (filefound); 
}
	 




		
