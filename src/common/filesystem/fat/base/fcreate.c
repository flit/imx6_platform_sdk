/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/Fcreate.c $
 $Revision: 18 $                                       
 $Date: 9/18/03 7:14p $
 Description: Fcreate.c
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

>  Function Name: int32_t Fcreate(int32_t HandleNumber,uint8_t *FileName,int32_t stringtype,int32_t length,int32_t index)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to File Name
                  3)stringtype
                  4)length
                  5)index

   Outputs:       Returns HandleNumber if Success, or ERROR Code if  Error Occurs

   Description:   Creates a new file in a given directory

<
----------------------------------------------------------------------------*/
int32_t Fcreate(int32_t HandleNumber,uint8_t *FileName,int32_t stringtype,int32_t length,int32_t index)
{
    RtStatus_t RetValue = SUCCESS;
	uint8_t UnicodeBuffer[MAX_UNICODE_SIZE];

    EnterNonReentrantSection();
    if((Handle[HandleNumber].Mode & READ_MODE) !=READ_MODE)
	{
    	LeaveNonReentrantSection();
        return ERROR_OS_FILESYSTEM_DIRECTORY_IS_NOT_WRITABLE;
	}

    ddi_ldl_push_media_task("Fcreate");
    
    if((RetValue = CreateDirRecord(FileName,HandleNumber,0,ARCHIVE,stringtype,length,index,UnicodeBuffer,0)) <0)
	{
        ddi_ldl_pop_media_task();
        LeaveNonReentrantSection();
		return RetValue;
    }
    
    if(Handle[HandleNumber].StartingCluster!=0)
	{
        if((RetValue = Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR)) <0)
		{
            ddi_ldl_pop_media_task();
            LeaveNonReentrantSection();
			return RetValue;
		}
    }
    
	Handle[HandleNumber].FileSize = 0;
    UpdateHandle(HandleNumber,0);

    LeaveNonReentrantSection();
    ddi_ldl_pop_media_task();
    return SUCCESS;
}

