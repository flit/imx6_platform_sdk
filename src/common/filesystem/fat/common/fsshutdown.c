/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/common/FsShutDown.c $              
 $Revision: 2 $                                       
 $Date: 9/19/03 9:39a $      
 Description: FsShutDown.c
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
/*----------------------------------------------------------------------------
		Extern Declarations
----------------------------------------------------------------------------*/
extern int  FSDriveShutdown(int DeviceNumber);
/*----------------------------------------------------------------------------

>  Function Name:  RtStatus_t FSShutdown(void)

   FunctionType:   Reentrant

   Inputs:         Nil

   Outputs:        Returns 0 on success else an error code
                   
   Description:    Shutdown the file system  
                    
<
----------------------------------------------------------------------------*/
RtStatus_t FSShutdown(void)
{
    int32_t i=0;
	RtStatus_t RetValue = SUCCESS;

	/* Close all the active file handles */
	
	for (i =0; i < maxhandles; i++)
    {
	    if((Handleactive(i))==SUCCESS)
	    {
	        if(Fclose(i) <0)
		        continue;
	    }
    }

	/* Flush the cache */
	
    if((RetValue = (RtStatus_t)FlushCache()) != SUCCESS)
    {
        return RetValue;
    }          

	/* Shutdown external and internal drive */

	for( i=0; i<maxdevices-1; i++ )
    {
		FSDriveShutdown(i);
    }

	/* Clear any global data */
	/* TODOFSINITSHUTDOWN */
	
    return RetValue;
}


