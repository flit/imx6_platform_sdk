/*----------------------------------------------------------------------------
SigmaTel Inc
$Archive: /Fatfs/FileSystem/Fat32/base/DeleteRecord.c $                                        
$Revision: 8 $                                       
$Date: 9/18/03 6:49p $                                           
Description: Deleterecord.c
Notes: This file read provides Base function to Delete a record
-----------------------------------------------------------------------------*/

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

>  Function Name: int32_t  DeleteRecord(int32_t HandleNumber, int32_t RecordNo)

   FunctionType:  Reentrant

   Inputs:        1)  HandleNumber
                  2)  RecordNo
				   
   Outputs:       SUCCESS or error code if error occurs   
   
   Description:   Mark the directoy record of the given record no. and all the long
                  directory records associated with it as deleted.  
----------------------------------------------------------------------------*/
int32_t DeleteRecord(int32_t HandleNumber, int32_t RecordNo)
{
    int firstbyteofrecord;
    uint8_t DeleteDirrecordch = DELETEDDIRRECORDCHARA;
    uint8_t buf[33];
    RtStatus_t	 Retval;
    int64_t lTemp;

	if (Handle[HandleNumber].StartingCluster == 0)
	{
        if((Retval= FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].CurrentSector,Handle[HandleNumber].BytePosInSector,
            &DeleteDirrecordch,0,1,WRITE_TYPE_RANDOM)) <0)
			return Retval;
	}
   	else
	{
        if((Retval = (RtStatus_t)Fwrite(HandleNumber,&DeleteDirrecordch,1))<=0)
	        return Retval;
   	}

   	
   	/*Now delete all long file name records that are associated with 
    the file to be deleted */

    while(1)
	{
	    RecordNo--;  //Decrement record number

		if(RecordNo<0)
		    break;

        // This line is needed because ReadDirectoryRecord
        // does and Fseek and a Fread, which results in
        // next iteration of this loop looking at data
        // that's completely bogus if we do not seek
        // back to the beginning.
        if((Retval= Fseek(HandleNumber,0,SEEK_SET))<0)
        {
           return Retval;
        }

        if((lTemp = ReadDirectoryRecord(HandleNumber,RecordNo,buf))<0)
        {
		    return  ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;   //(RtStatus_t)lTemp;       
	   	}
            
        if(lTemp == 0)
        {
		    break;
        }
                        
	    firstbyteofrecord = FSGetByte(buf,0);
        
        /* First check if record is not already deleted or parent/this directory record */
		
		if(firstbyteofrecord == 0xE5 || firstbyteofrecord == 0x2E)
	        break;

        /* Second check if the attribute is set to LONGDIRATTRIBUTE(0x0f) => long file name */    
	   	if((FSGetByte(buf,DIR_ATTRIBUTEOFFSET)) != LONGDIRATTRIBUTE)
		    break;
         
        /* Finally check if first cluster position is 0*/
     	if(FSGetWord(buf,DIR_FSTCLUSLOOFFSET) != 0)
		    break;
        /* The record must be a long file name therefore delete it*/
     	/* check for root directory*/
        if (Handle[HandleNumber].StartingCluster == 0)
		{
            if((Retval = FSWriteSector(Handle[HandleNumber].Device,Handle[HandleNumber].CurrentSector,Handle[HandleNumber].BytePosInSector,
	            &DeleteDirrecordch,0,1,WRITE_TYPE_RANDOM)) <0)
			    return Retval;
  		}
        else
	    {
        	/*set Handle to original position*/
            if((Retval=Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR))<0)
    		    return Retval;

            if((Retval = (RtStatus_t)Fwrite(HandleNumber,&DeleteDirrecordch,1))<=0)
			    return Retval;
   	    }
  	}	 
	return SUCCESS;
}



 
	 
	   
  

			 




			 
