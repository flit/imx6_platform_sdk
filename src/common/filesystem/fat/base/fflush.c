/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/Fflush.c $
 $Revision: 9 $                                       
 $Date: 9/13/03 12:20p $
 Description: Fflush.c
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
#include "diroffset.h"

/*----------------------------------------------------------------------------

>  Function Name:  RtStatus_t  Fflush(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber

   Outputs:       Returns 0 if Success Else an ErrorCode

   Description:   Flushes the Buffer

<
----------------------------------------------------------------------------*/
RtStatus_t  Fflush(int32_t HandleNumber)
{
    RtStatus_t RetValue;
    int32_t i32WriteFlag=0;
    uint32_t filesizeread, * readBuffer, fsizeoffset;
    uint32_t cacheToken;

    if((HandleNumber < 0)||(HandleNumber >= maxhandles))
    {
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;
    }
    
    if((RetValue = Handleactive(HandleNumber))<0)
    {
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;
    }
    
    ddi_ldl_push_media_task("Fflush");
    
    if((RetValue = FSFlushSector(Handle[HandleNumber].Device,Handle[HandleNumber].CurrentSector,WRITE_TYPE_RANDOM,-1,&i32WriteFlag)) <0)
    {
        ddi_ldl_pop_media_task();
        return RetValue;
    }

    EnterNonReentrantSection();
    if((readBuffer = (uint32_t *) FSReadSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,WRITE_TYPE_RANDOM, &cacheToken)) <= 0)
    {
        ddi_ldl_pop_media_task();
        LeaveNonReentrantSection();
        return RetValue;
    }

    fsizeoffset  =  (DIR_FILESIZEOFFSET + Handle[HandleNumber].DirOffset)/sizeof(uint32_t);
    filesizeread =  *(readBuffer + fsizeoffset);
    
    FSReleaseSector(cacheToken);
    
    LeaveNonReentrantSection();
    
    if (filesizeread != Handle[HandleNumber].FileSize)
    {  
        if((RetValue = UpdateFileSize(HandleNumber,0)) < 0)
        {
            return ERROR_OS_FILESYSTEM_EOF;
        }
    
        if((RetValue = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,
                                   DIR_FILESIZEOFFSET + Handle[HandleNumber].DirOffset,(uint8_t *)&Handle[HandleNumber].FileSize,
                                   0,4,WRITE_TYPE_RANDOM)) <0)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
    }

    if(i32WriteFlag==1)
    {
        if ((RetValue = DriveFlush(Handle[HandleNumber].Device)) != SUCCESS)
        {
            ddi_ldl_pop_media_task();
            return RetValue;
        }
    }
    ddi_ldl_pop_media_task();
    return SUCCESS;
}
