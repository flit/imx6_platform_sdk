/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Getcwd.c $                                        
 $Revision: 3 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: Getcwd.c
 Notes:	This file read provides higherlevel API function to get current working directory
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
//#include "platform.h"
//#include "BootSecOffset.h" 
//#include "DirOffset.h" 
//#include "dirrecord.h" 
/*----------------------------------------------------------------------------
>  Function Name: uint8_t *Getcwd(void)

   FunctionType:  Reentrant

   Inputs:        void
				   
   Outputs:       Pointer to current working directory buffer      
   
   Description:   This function returns the pointer to the gCurrentWorkingdirectory
                  string buffer.
----------------------------------------------------------------------------*/
uint8_t *Getcwd(void)
{
#ifdef CWD_STRING   
    return gCurrentWorkingdirectory;
#else
    return NULL;
#endif    
    
}
	 




		







			 




			 
