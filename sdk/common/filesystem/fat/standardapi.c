/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/standardapi/Fclose.c $
 $Revision: 9 $
 $Date: 9/13/03 12:23p $
 Description: Fclose.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "filesystem/fsapi.h"
#include "fat_internal.h"
#include "fs_steering.h"

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t Fclose(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns 0 on success else an Error Code if error occurs

   Description:   Closes the opened file 
<
----------------------------------------------------------------------------*/
RtStatus_t Fclose_FAT(int32_t HandleNumber)
{
    RtStatus_t RetValue;

	if((HandleNumber < 0)||(HandleNumber >=maxhandles))
    {
	    return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
	}
    
    if((RetValue = Handleactive(HandleNumber)) <0)
    {
        return RetValue;
	}
    
    if(Handle[HandleNumber].Mode & (WRITE_MODE|APPEND_MODE))
    {
        // If file is opened in write mode flush the sector
        if((RetValue = Fflush(HandleNumber)) < 0)
        {
            return RetValue;
        }
    }        

    RetValue = Freehandle(HandleNumber);
    
    return RetValue;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t Fgetc(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns Byte read from file or EOF or an Error Code if  Error Occurs

   Description:   Reads the byte from file 
<
----------------------------------------------------------------------------*/
RtStatus_t Fgetc(int32_t HandleNumber)
{
    int32_t ReturnByte=0;
    RtStatus_t RetValue;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if((RetValue = Handleactive(HandleNumber))<0)
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

    if((Feof(HandleNumber))==ERROR_OS_FILESYSTEM_EOF)
        return ERROR_OS_FILESYSTEM_EOF;
    
    if((RetValue = (RtStatus_t)(Fread(HandleNumber,(uint8_t *)&ReturnByte,1))) <= 0 )
        return RetValue;
    
    return ReturnByte;
}

/*----------------------------------------------------------------------------
>  Function Name: uint8_t *Fgets(int32_t HandleNumber,int32_t NumBytesToRead,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Number of Bytes to Read
                  3)Pointer to Buffer 

   Outputs:       Returns pointer to buffer containing string else Null Pointer.

   Description:   Reads the string from file.
<
----------------------------------------------------------------------------*/
uint8_t *Fgets(int32_t HandleNumber, int32_t NumBytesToRead, uint8_t *Buffer)
{
    int32_t i;
    RtStatus_t RetValue;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return (uint8_t *)0;

    if((RetValue = Handleactive(HandleNumber))<0)
        return (uint8_t *)0;

    for(i=0; i < NumBytesToRead; i++)
    {
        if((RetValue = Fgetc(HandleNumber)) < 0)
            return (uint8_t *)0;
        PutByte(Buffer,RetValue,i);
        if( RetValue=='\n')
        {
            PutByte(Buffer,0,i+1);
            return Buffer;
        }
    }    
    PutByte(Buffer,0,i);
    return Buffer;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t Fputc(int32_t HandleNumber,int32_t ByteToWrite)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Byte to Write

   Outputs:       Returns Byte Written or EOF or an Error Code if  Error Occurs

   Description:   Writes the Byte to file 
<
----------------------------------------------------------------------------*/
RtStatus_t Fputc(int32_t HandleNumber,int32_t ByteToWrite)
{
    int32_t RetValue = SUCCESS;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if((RetValue = Handleactive(HandleNumber))<0)
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

    if((RetValue = (RtStatus_t)Fwrite(HandleNumber,(uint8_t *)&ByteToWrite,1)) <= 0)
        return ERROR_OS_FILESYSTEM_EOF;

    //! todo - what does the following line do?
    (void)RetValue;    
    return ByteToWrite;
}

/*----------------------------------------------------------------------------
>  Function Name: uint8_t *Fputs(int32_t HandleNumber,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to Buffer

   Outputs:       Returns pointer to buffer on success else NULL Pointer

   Description:   Writes the string to the file
<
----------------------------------------------------------------------------*/
uint8_t *Fputs(int32_t HandleNumber,uint8_t *Buffer)
{
    int32_t  NumBytesToWrite,i;
    RtStatus_t RetValue = SUCCESS;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return (uint8_t *)0;

    if((RetValue = Handleactive(HandleNumber))<0)
        return (uint8_t *)0;

    NumBytesToWrite = Strlength((uint8_t *)Buffer);
    for(i=0; i < NumBytesToWrite;i++)
    {
        if((RetValue = Fputc(HandleNumber,FSGetByte(Buffer,i))) < 0)
            return (uint8_t *)0;
    }

    (void)RetValue;
    return Buffer;
}
