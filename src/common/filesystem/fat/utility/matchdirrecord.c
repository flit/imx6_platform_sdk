/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/MatchdirRecord.c $                                        
 $Revision: 6 $                                       
 $Date: 9/13/03 7:06p $                                           
 Description: MatchdirRecord.c
 Notes:	This file read provides utility function to match directory record
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
>  Function Name:  RtStatus_t MatchdirRecordW(int32_t HandleNumber,int32_t RecordNo,uint8_t *file,uint8_t *buf,int32_t index,int32_t length)

   FunctionType:   Reentrant

   Inputs:         1) Handle number
                   2) Record Number
				   3) Pointer to file name
				   4) Pointer to buffer
                   5) Index
                   6) Length
                   7) Shortnamebuf
  Outputs:         Returns ERROR_OS_FILESYSTEM_FILE_FOUND if filename matches otherwise ERROR_OS_FILESYSTEM_FILE_NOT_FOUND.
      
  Description:     This function first checks the long directory attribute from the directory record 
                   and if it is set then it checks the first byte of the record. If it is set to 
                   first long directory subcomponent then it matches the given file name with long 
                   directory name.  
                   IF long directory attribute is not set then function will try to match short directory record from passed 
                   Shortnamebuf.If file name matches then returns ERROR_OS_FILESYSTEM_FILE_FOUND else returns file not found 
<    
----------------------------------------------------------------------------*/
RtStatus_t MatchdirRecordW(int32_t HandleNumber,int32_t RecordNo, uint8_t *file,uint8_t *buf,int32_t index,int32_t length,uint8_t *Shortnamebuf)
{
    RtStatus_t filefound=SUCCESS;
    int32_t dirattribute;
    int Firstbyte;
	
    // SGTL_HK change
    //int32_t shortname[13],ucs2buffer[13];   
    Firstbyte = file[index];
	if( (file[index] == 0x2E) && (file[index+1] == 0x2E)&&((length-index) == 2))
	{
        RecordNo++;
        filefound = Longdirmatch(HandleNumber,RecordNo,file,index,length,UCS3s);
	}
	else 
	{
        dirattribute =  FSGetByte(buf,DIR_ATTRIBUTEOFFSET);

        if(dirattribute == LONGDIRATTRIBUTE)
        {
            Firstbyte = FSGetByte(buf,0);
            if(Firstbyte == 1 || Firstbyte == 0x41)
            {
                RecordNo++;
                length= DiscardTrailigPeriodsw(file,length,index);
                filefound = Longdirmatch(HandleNumber,RecordNo,file,index,length,UCS3s);
	        }
        }
      // #if 0 // removed segment to be like sdk3.05    TOVERIFY2   do we need this fix for player? is it benign in MTP?
        else            // else block inserted for HK fix. Merged into br_sdk_2600 by HJ on 11May2005    TOVERIFY correctness review.
        {
	//	SGTL-HK 1-3-2005
	//	If the Length of the Name > 11, it must Not be a Short Name so No File will be found
	//modify: change the equation 
//		    if (((length/2 - index/2)-1) <= 11)
//		    {
//        //modify: Replace function with Strcpyw function 
//        //      strcpyUCS3_2((int32_t *)file, ucs2buffer, index,length);
//		        Strcpyw((uint8_t *)file, (uint8_t *)ucs2buffer,length,index);
//		        UnicodeToOEM((uint8_t *)ucs2buffer,(uint8_t *)shortname, length-index, 0); 
//		        Uppercase((uint8_t*)shortname);
    	                filefound = Shortdirmatch(HandleNumber,RecordNo,(uint8_t *)Shortnamebuf,(uint8_t *)Shortnamebuf,buf,0,0,length,0);
     	
		   // }
        }
      // #endif
	}
    return(filefound);
}



 
