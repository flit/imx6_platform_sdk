/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/FindFirst.c $
 $Revision: 12 $
 $Date: 10/17/03 9:43a $
 Description: FindFirst.c
 Notes:
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "FileSpec.h"
/*----------------------------------------------------------------------------
		Extern Declarations
----------------------------------------------------------------------------*/
extern FileSpecs_t* FileSpec;
extern RtStatus_t FindNext(int32_t HandleNumber,FindData_t *_finddata);
extern int32_t StringCompare(uint8_t *Buffer,uint8_t *DestBufffer,int32_t StringLength,int32_t Offset);
/*----------------------------------------------------------------------------
		Global Declarations
----------------------------------------------------------------------------*/
uint8_t *CharacterSearch(uint8_t *buf,uint8_t Character);
/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t FindFirst(FindData_t *_finddata,uint8_t *FileName)

   FunctionType:  Reentrant but this function should not be called from multiple task

   Inputs:        1) File Specification(Structure)
				  2) Pointer to file name

   Outputs:       Returns 0 on Success else an ErrorCode if Error occurs

   Description:   It provides base, the file name and the extension of the file
   				  to the FindNext() function
<
----------------------------------------------------------------------------*/
RtStatus_t FindFirst(FindData_t *_finddata,uint8_t *FileName)
{
    int32_t StringLength;
    uint8_t Buffer[MAX_FILESNAME*3];
    int32_t HandleNumber;
    uint8_t *Ptr,*Ptr1;
    int32_t i;


	if((StringLength = Strlength(FileName)) > (MAX_FILESNAME-1))
		return ERROR_OS_FILESYSTEM_LONG_FILE_NAME;

    _finddata->startrecord=0;   //modify: It must start from 0th record
    for(i=0; i < MAX_FILESNAME*3;i++)
	    Buffer[i]=0;
	if((HandleNumber = Searchfreehandleallocate()) <0)
		return (RtStatus_t)HandleNumber;

	Handle[HandleNumber] = Handle[CWD_HANDLE];

	Handle[HandleNumber].Mode = (FileSystemModeTypes_t)(READ_MODE | DIRECTORY_MODE);

    Uppercase(FileName);

	for(i=0; i < StringLength; i++)
	{
	    Buffer[i] = FSGetByte(FileName,i);
	}

    FileSpec[HandleNumber].DirAttribute=_finddata->attrib;
	FileSpec[HandleNumber].FileExtension[0]=0;
    Ptr = CharacterSearch(Buffer,'.');
    if(Ptr)
    {
		Ptr1 = CharacterSearch(Ptr,'*');

		if(Ptr1)
		    *Ptr1=0;
		for(i=0; i <4; i++)
		{
			FileSpec[HandleNumber].FileExtension[i] = FSGetByte(Ptr,i+1);
		}
		Ptr[0]=0;
    }

	if(CharacterSearch(Buffer,'*'))
	{
		*CharacterSearch(Buffer,'*')=0;
	}

	for(i=0; i < 9; i++)
	{
		FileSpec[HandleNumber].FileName[i] = FSGetByte(Buffer,i);
	}
    FileSpec[HandleNumber].gCurrentRecord=_finddata->startrecord;

	if(!(FindNext(HandleNumber,_finddata)))
	    return (RtStatus_t)HandleNumber;
	else
    {
        Freehandle(HandleNumber);
		return ERROR_OS_FILESYSTEM_NO_MATCHING_RECORD;
    }
}
/*----------------------------------------------------------------------------
>  Function Name: uint8_t *CharacterSearch(uint8_t *buf,uint8_t Character)

   FunctionType:  Non-Reentrant

   Inputs:        1) Pointer to buffer
                  2) Character

   Outputs:       Pointer to character

   Description:   It searches the character
<
----------------------------------------------------------------------------*/
//Use the exact same prototype of the static function to convert

uint8_t *CharacterSearch(uint8_t *buf,uint8_t Character)
{
    uint8_t *Buf = buf;
    while(Buf[0]!='\0')
    {
        if(*Buf == Character)
            return Buf;
//      *Buf++; //original code, not sure it is right ???
		Buf++;
    }

    return (uint8_t*)0;
}
