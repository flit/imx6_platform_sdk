/*----------------------------------------------------------------------------
 SigmaTel Inc
 /FileSystem/Fat32/common/setcwdhandle.c               
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include "types.h"
#include "fstypes.h"
#include "errordefs.h"
#include "platform.h"
#include "handletable.h"
#include "os/filesystem/fat/include/devicetable.h"
#include "filespec.h"
#include "os/filesystem/filesystem.h"
#include "fat_internal.h"

/*----------------------------------------------------------------------------
		Globals and declarations
----------------------------------------------------------------------------*/

// Previously the size of the following global variable was 
// MAX_FILENAME_LENGTH*2.  That's not nearly enough since
// Artist name and Album name can both be of size
// MAX_FILENAME_LENGTH.
#ifdef CWD_STRING

// This padding is here to provide a safety buffer if code writes to negative offsets
// from the start of gCurrentWorkingdirectory. This is a possibility because the cwd
// is treated as both ASCII and UTF-16 at the same time, interchangeably even
// within a single function. Not good.  
uint8_t __fs_padding[4];

uint8_t gCurrentWorkingdirectory[MAX_FILENAME_LENGTH*2];

#endif // CWD_STRING

/*----------------------------------------------------------------------------

>  Function Name:  int SetCWDHandle (int DeviceNo)

   FunctionType:  

   Inputs:         Device number to set the cwd handle to root dir of

   Outputs:        Returns 0 for SUCCESS

   Description:     
<
--------- -------------------------------------------------------------------*/
int  SetCWDHandle(int DeviceNo)
{

    /* set handle CWD_HANDLE (Handle 0) to Root directory of device 0*/
	 Handle[CWD_HANDLE].HandleActive=1;
     Handle[CWD_HANDLE].Device = DeviceNo;
     Handle[CWD_HANDLE].Mode = DIRECTORY_MODE + READ_MODE + WRITE_MODE;	
     ChangeToRootdirectory(CWD_HANDLE);
#ifdef CWD_STRING   
      /* set gCurrentWorkingdirectory string to device 0*/ 

    // Terminate with 3 nulls so code that treats cwd as either ASCII or UTF-16 will see the same end-of-string.

	PutByte(gCurrentWorkingdirectory,DriveLetter[0],0);
	  PutByte(gCurrentWorkingdirectory,':',1);
	  PutByte(gCurrentWorkingdirectory,'\0',2);
      PutByte(gCurrentWorkingdirectory,'\0',3);
      PutByte(gCurrentWorkingdirectory,'\0',4);
        
#endif      
    return SUCCESS;
}

