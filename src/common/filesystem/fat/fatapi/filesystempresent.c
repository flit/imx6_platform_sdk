/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/filesystempresent.c $                                        
 $Revision: 5 $                                       
 $Date: 9/13/03 12:21p $                                           
 Description: filesystempresent.c
 Notes:	This file read provides FAT API to find whether the file system is present
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "BootSecOffset.h" 

//
// Prototypes
//
RtStatus_t FileSystemBootSectorVerify( uint8_t* buf );

/*----------------------------------------------------------------------------

>  Function Name: RtStatus_t FileSystemPresent(int32_t DeviceNum)

   FunctionType:  Reentrant

   Inputs:        1) Device number

   Outputs:       Returns 0, if file system found else 
                  ERROR_OS_FILESYSTEM_READSECTOR_FAIL if the PBS cannot be read.
                  or
                  ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND if the PBS is missing.

   Description:   Determines FAT file system by checking 0xaa55 signature
<
----------------------------------------------------------------------------*/
RtStatus_t FileSystemPresent(int32_t DeviceNum)
{ 
    uint8_t     *buf;
    uint32_t    cacheToken;
    RtStatus_t  rtStatus = SUCCESS;

	if((DeviceNum <0 ) || (DeviceNum >= maxdevices))
    {
		return ERROR_OS_FILESYSTEM_DEVICE_NOT_SUPPORTED;
    }

    EnterNonReentrantSection();
    /* Read the BootSector */ 
    if((buf = (uint8_t*)FSReadSector(DeviceNum, BOOTSECTOR,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t*)0)
	{
		rtStatus = ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
        goto _exit;
	}

    rtStatus = FileSystemBootSectorVerify( buf );

_exit:
    FSReleaseSector(cacheToken);
	LeaveNonReentrantSection();
    
    return rtStatus;
}


////////////////////////////////////////////////////////////////////////////////
//! \brief      Check for the standard PBS 0xaa55 signature.
//!
//! \fntype     Function
//!
//! In the given buffer "*buf", this function looks at the standard
//! offset to confirm the presence of the standard sector-0 PBS signature,
//! nominally "0xaa55".
//!
//! \param[in]  buf     Pointer to a buffer containing the contents of sector 0.
//!
//! \retval SUCCESS                                     If the signature is found.
//! \retval ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND    If not found.
//!
////////////////////////////////////////////////////////////////////////////////
RtStatus_t FileSystemBootSectorVerify( uint8_t* buf )
{
    int  signature; 

    // To determine whether the filesystem is present or not, get the two bytes of Bootsector
    // at offsets 510 and 511, regardless of the sector size.
    signature = FSGetWord((uint8_t*)buf, BPB_AND_FSI_SIGNATURE_OFFSET_512B_SECTOR);

    /* compare the last two bytes with the signature 0xaa55 */
    if (signature == BOOT_SECTOR_SIGNATURE)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

}
