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

///////////////////////////////////////////////////////////////////////////
//! \brief This function is the same as Fread except that it bypasses cache
//!
//! \fntype Function
//!
//!	Reads the Specified number of Bytes from the FILE.  This
//! function intentionally bypasses filesystem cache for those
//! situations when going through filesystem cache hurts 
//! performance.
//!                   
//! In order to use this function, buffer needs to be read
//! from the beginning of a sector.  This function cannot
//! handle reads which begin in the middle of a sector.
//!
//! \param[in]   i32HandleNumber
//! \param[out]  pBuffer
//! \param[in]   i32NumBytesToRead
//!
//! \retval     Number of bytes read upon success or
//! \retval     0 upon failures - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED,
//!                                      ERROR_OS_FILESYSTEM_INVALID_MODE, 
//!                                      i32NumBytesToRead < 0,
//!                                      ERROR_OS_FILESYSTEM_EOF, and
//!                                      ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE
//!
//! \pre This function can only be used for cases where current position of
//       file is located at beginning of sector.
//! \pre pBuffer has to point to Buffer which is at least big enough to
//!      hold a sector.
//!
///////////////////////////////////////////////////////////////////////////

int32_t Fread_BypassCache(int32_t i32HandleNumber, uint8_t *pBuffer, int32_t i32NumBytesToRead)
{
    RtStatus_t RetValue=SUCCESS;
    int32_t    FileSize;
    int32_t    RemainBytesToRead;
    int32_t    Device;
    int32_t    BuffOffset=0;
    int32_t    BytesToCopy;
    int32_t    RemainBytesInSector;
    int32_t    BytesPerSector;
    uint32_t cacheToken = 0;
    
    if((i32HandleNumber < 0) || (i32HandleNumber >= maxhandles))
    {
        // Error - ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED
        return 0;
    }
    
    Device = Handle[i32HandleNumber].Device;
	BytesPerSector = MediaTable[Device].BytesPerSector;
    
    if((RetValue = Handleactive(i32HandleNumber)) < 0)
    {
        Handle[i32HandleNumber].ErrorCode = RetValue;
        return 0;
    }    
    
    if((Handle[i32HandleNumber].Mode & READ_MODE)!=READ_MODE )
    {
        Handle[i32HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_INVALID_MODE;
        return 0;
    }    

    // We treat directories as files, so a special read mode for these.
    if (Handle[i32HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize = 0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(i32HandleNumber);
	}
    
    if(FileSize < (i32NumBytesToRead + Handle[i32HandleNumber].CurrentOffset))
	{
        Handle[i32HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_EOF;
        i32NumBytesToRead = FileSize - Handle[i32HandleNumber].CurrentOffset;
	}

	RemainBytesToRead = i32NumBytesToRead;
    if (RemainBytesToRead<0)
    {
        return 0;
    }    

    // On EOF
    if (i32NumBytesToRead==0)
    {
        Handle[i32HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_EOF;
        return 0;
    }    
    
    ddi_ldl_push_media_task("Fread_BypassCache");

    RemainBytesInSector = BytesPerSector - Handle[i32HandleNumber].BytePosInSector;

	EnterNonReentrantSection();

    while(RemainBytesToRead >0)
    {
        uint8_t * readBuf;
        
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

        if ((RetValue = UpdateHandleOffsets(i32HandleNumber)))
        {
            Handle[i32HandleNumber].ErrorCode = RetValue;
		    LeaveNonReentrantSection();
            ddi_ldl_pop_media_task();
            return (i32NumBytesToRead-RemainBytesToRead);
        }    

        readBuf = (uint8_t *)FSReadSector_BypassCache(Device, Handle[i32HandleNumber].CurrentSector, WRITE_TYPE_RANDOM, &(pBuffer[BuffOffset]), &cacheToken);
        if( readBuf == NULL)
        {
            Handle[i32HandleNumber].ErrorCode = ERROR_OS_FILESYSTEM_MEDIAREAD_FAILED;
            LeaveNonReentrantSection();
            ddi_ldl_pop_media_task();
            return (i32NumBytesToRead-RemainBytesToRead);
        }
        // use memmove() just in case the buffers are overlapping
        memmove(&pBuffer[BuffOffset], readBuf + Handle[i32HandleNumber].BytePosInSector, BytesToCopy);
        FSReleaseSector(cacheToken);

        RemainBytesToRead -= BytesToCopy;

        Handle[i32HandleNumber].CurrentOffset += BytesToCopy;
        Handle[i32HandleNumber].BytePosInSector += BytesToCopy;

        BuffOffset+=BytesToCopy;
    }

	LeaveNonReentrantSection();
    ddi_ldl_pop_media_task();
    // Force to RtStatus - all errors are negative so this will still work.
    return (RtStatus_t) i32NumBytesToRead;
}



