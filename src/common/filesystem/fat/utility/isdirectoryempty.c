/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Isdirectoryempty.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:23p $                                           
 Description: Isdirectoryempty.c
 Notes:	This file read provides utility function to check whether the directory is empty or not.
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
#include "DirOffset.h" 
/*----------------------------------------------------------------------------
>  Function Name:  RtStatus_t Isdirectoryempty( int32_t Handlenumber)

   FunctionType:   Reentrant

   Inputs:         1) Handlenumber

   Outputs:        Returns SUCCESS or ERROR_OS_FILESYSTEM_DIR_NOT_EMPTY

   Description:    Determines the directory is empty or not by checking all the
                   records whether they are deleted or not 
<                   
----------------------------------------------------------------------------*/
RtStatus_t Isdirectoryempty( int32_t Handlenumber)
{
    int32_t Firstbyteofrecord, Recordno;
    int64_t NumBytesRead;
    uint8_t buf[32];

    Recordno = 2;
    do 
    { 
        if((NumBytesRead = ReadDirectoryRecord(Handlenumber,Recordno,buf))<0)
		    return  SUCCESS;
        Firstbyteofrecord = FSGetByte(buf,0);
          
        if(Firstbyteofrecord == 0x00)
		    return(SUCCESS);

        if (Firstbyteofrecord != 0xE5)
		    return(ERROR_OS_FILESYSTEM_DIR_NOT_EMPTY);
		
		Recordno++; 
    }while(NumBytesRead != 0);

    return(SUCCESS);
  
}


