/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/Fread.c $
 $Revision: 19 $                                       
 $Date: 9/18/03 6:45p $
 Description: Fread.c
 Notes:	
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "fs_steering.h"
#include <stdlib.h>

/*----------------------------------------------------------------------------

>  Function Name: int32_t Fread(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToRead)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to Buffer
                  3)Number of Bytes To Read

   Outputs:       Returns Number of bytes read upon success or 
                                 0 upon failures - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED,
                                                        ERROR_OS_FILESYSTEM_INVALID_MODE,
                                                        NumBytesToRead < 0,
                                                        ERROR_OS_FILESYSTEM_EOF,
                                                        ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE

   Description:   Reads the Specified number of Bytes from the FILE

<
----------------------------------------------------------------------------*/
int32_t Fread_FAT(int32_t HandleNumber, uint8_t *Buffer, int32_t NumBytesToRead)
{
    RtStatus_t RetValue=SUCCESS;
    uint8_t *buf;
    int32_t FileSize,RemainBytesToRead;
    int Device,BuffOffset=0,BytesToCopy;
    int RemainBytesInSector,BytesPerSector;
    uint32_t cacheToken;
    
    if((HandleNumber < 0) || (HandleNumber >= maxhandles))
    {
        // Error - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED 
        return 0;
    }
    
    Device = Handle[HandleNumber].Device;
	BytesPerSector = MediaTable[Device].BytesPerSector;
    
    if((RetValue = Handleactive(HandleNumber)) < 0)
    {
        Handle[HandleNumber].ErrorCode = RetValue;
        return 0;
    }    
    
    if((Handle[HandleNumber].Mode & READ_MODE)!=READ_MODE )
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_MODE;
        return 0;
    }    

    // We treat directories as files, so a special read mode for these.
    if (Handle[HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(HandleNumber);
	}
    
    if(FileSize < (NumBytesToRead + Handle[HandleNumber].CurrentOffset))
	{
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_EOF;
        NumBytesToRead = FileSize - Handle[HandleNumber].CurrentOffset;
	}

	RemainBytesToRead = NumBytesToRead;
    if (RemainBytesToRead<0)
    {
        return 0;
    }    

    // On EOF
    if (NumBytesToRead==0)
    {
        Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_EOF;
        return 0;
    }    
    
    ddi_ldl_push_media_task("Fread_FAT");

    RemainBytesInSector = BytesPerSector - Handle[HandleNumber].BytePosInSector;

    while(RemainBytesToRead >0)
    {
		if ((RemainBytesInSector != 0) && (RemainBytesToRead > RemainBytesInSector))
		{
			BytesToCopy	= RemainBytesInSector;
			RemainBytesInSector = 0;
		}
		else
		{	
            BytesToCopy = RemainBytesToRead;
			if(BytesToCopy > BytesPerSector)
	        {
	            BytesToCopy = BytesPerSector;
	        }
		}

        if ((RetValue = UpdateHandleOffsets(HandleNumber)))
        {
            Handle[HandleNumber].ErrorCode = RetValue;
            ddi_ldl_pop_media_task();
            return (NumBytesToRead-RemainBytesToRead);
        }    

	    EnterNonReentrantSection();
        if((buf = (uint8_t *)FSReadSector(Device,Handle[HandleNumber].CurrentSector,WRITE_TYPE_RANDOM, &cacheToken))==(uint8_t *)0)
		{
            Handle[HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
		    LeaveNonReentrantSection();
            ddi_ldl_pop_media_task();
            return NumBytesToRead-RemainBytesToRead;  // READSECTOR_FAIL return here in 2.6 version fixes mmc eject bug 7183.
		}

        RemainBytesToRead -= BytesToCopy;

        memcpy(Buffer + BuffOffset, buf + Handle[HandleNumber].BytePosInSector, BytesToCopy);
        
        FSReleaseSector(cacheToken);
	    LeaveNonReentrantSection();

        Handle[HandleNumber].CurrentOffset += BytesToCopy;
        Handle[HandleNumber].BytePosInSector += BytesToCopy;

        BuffOffset+=BytesToCopy;
    }
    
    ddi_ldl_pop_media_task();

    // Force to RtStatus - all errors are negative so this will still work.
    return (RtStatus_t) NumBytesToRead;
}



