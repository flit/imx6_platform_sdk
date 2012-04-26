/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/fatapi/CheckspaceinRootdir.c $                                        
 $Revision: 7 $                                       
 $Date: 9/13/03 6:59p $                                           
 Description: CheckspaceinRootdir.c
 Notes:	This file read provides FAT API to find free space in root directory
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
/*----------------------------------------------------------------------------
>  Function Name:  int32_t CheckspaceinRootdir(int32_t Handlenumber,int32_t Flag)

   FunctionType:   Reentrant

   Inputs:         1) Handle number
                   2) Flag

   Outputs:        Returns index no of free record in root directory if there is a space for new dir record
                   else error ERROR_OS_FILESYSTEM_NOSPACE_IN_ROOTDIRECTORY

   Description:    Determines space in root directory by determining the first character 
                   of directory record for 0x00 or 0xE5 
<
----------------------------------------------------------------------------*/
int32_t CheckspaceinRootdir(int32_t Handlenumber,int32_t Flag)
{
    int32_t NumBytesread;
    int Firstbyte;
    int i;
    uint8_t Buffer[96];	   
    int Recordno;

//   	variable "Devicenum" was set but never used
//	Devicenum = 	Handle[Handlenumber].Device;
    Recordno = 0;

	do 
    { 
        if((NumBytesread = ReadRootdirRecord(Handlenumber,Recordno,Buffer))<0)
            return  NumBytesread;
        Firstbyte = FSGetByte(Buffer,0);
        if(Firstbyte ==  0x00)
		    return(SUCCESS);
	     
		else if(Firstbyte == 0xE5)
		{
		    if(Flag ==1)
		        return(SUCCESS);
		 	else
			{
			    i=1;
			    while(1)
			    {
				    Recordno++; 
			        NumBytesread = ReadRootdirRecord(Handlenumber,Recordno,Buffer);
	                Firstbyte = FSGetByte(Buffer,0);
				    if(Firstbyte ==  0x00)
			   	        return(SUCCESS);
				 
			        else if(Firstbyte != 0xE5)
				        break;
				    else
				    {
    				    i++;
				        if (i==Flag)
				        {
                            SetcurrentPos(Handlenumber,(Recordno-i+1));
   				 	        return SUCCESS;
				        }
				    }
		        }
			}
		}
		Recordno++; 
	}while(NumBytesread != 0);
		  
    return ERROR_OS_FILESYSTEM_NOSPACE_IN_ROOTDIRECTORY;

}


