/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/UpdateFileSize.c $
 $Revision: 10 $                                       
 $Date: 10/06/03 11:04a $
 Description: UpdateFileSize.c
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

>  Function Name: RtStatus_t UpdateFileSize(int32_t HandleNumber,int32_t DeleteContentFlag)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)DeleteContentFlag (if it is set, Update the file size)   

   Outputs:       Returns 0 on Success or ERROR Code if  Error Occurs

   Description:   Updates the file size if data is written 
<
----------------------------------------------------------------------------*/
RtStatus_t UpdateFileSize(int32_t HandleNumber,int32_t DeleteContentFlag)
{
    int32_t FileSize;
	int i=0;
    
    EnterNonReentrantSection();
	
    if (Handle[HandleNumber].Mode & DIRECTORY_MODE)
    {
        FileSize =  0x7fffffff; // Set the file size as the largest +ve number
    }
    else
    {
        FileSize = GET_FILE_SIZE(HandleNumber);
    }
    
    if(Handle[HandleNumber].CurrentOffset > FileSize || DeleteContentFlag==1)
	{
		Handle[HandleNumber].FileSize = Handle[HandleNumber].CurrentOffset;

	    for(i=FIRST_VALID_HANDLE;i < maxhandles;i++)
	    {
			if( i !=HandleNumber)
			{
				if(Handle[HandleNumber].Device == Handle[i].Device)
				{
					if(Handle[i].HandleActive == 1)
					{
						if(Handle[HandleNumber].DirSector == Handle[i].DirSector)
						{
							if(Handle[HandleNumber].DirOffset == Handle[i].DirOffset)
								Handle[i].FileSize = Handle[HandleNumber].FileSize;

						}
					}
				}
			}
		}
	}
     
    LeaveNonReentrantSection();
    return SUCCESS;
}
