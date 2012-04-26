/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/CreateDirectoryRecord.c $
 $Revision: 21 $
 $Date: 9/16/03 12:23p $
 Description: CreateDirectoryRecord.c
 Notes:
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <string.h>

#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <os/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "DIrOffset.h"

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t CreateDirRecord(uint8_t *filepath,int32_t HandleNumber,int32_t ClusterNumber,
                  int32_t DirAttr,int32_t stringtype,int32_t length,int32_t index,uint8_t *Buffer)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name or directory
                  2) HandleNumber
                  3) Cluster Number
                  4) Directory Attribute
                  5) String type
                  6) Length
                  7) Index
                  8) Pointer to buffer

   Outputs:       Returns SUCCESS else an error code

   Description:   Creates new directory record in the free record of the directory sector
<
----------------------------------------------------------------------------*/
RtStatus_t CreateDirRecord
(
  uint8_t *filepath,
  int32_t HandleNumber,
  int32_t ClusterNumber,
  int32_t DirAttr,
  int32_t stringtype,
  int32_t length,
  int32_t index,
  uint8_t *Buffer,
  int32_t FileSize
)
{
    int32_t strlen,Flag=0,count=0;
    RtStatus_t RetValue;

    uint8_t buf[32];
    uint8_t ShortNameDir[12];

    uint8_t shortfilename[15];
    int32_t chksum, byte, offset=0;
    int k, i, j;

    for (k = 0; k < 12; k++)
    {
        ShortNameDir[k] = 0x20;
        shortfilename[k] = 0x00;
    }
    memset(buf,0,32);
    if(stringtype == kDBCSEncoding)
    {
        length=DiscardTrailigPeriods(filepath,length,index,0);
	}
    else if(stringtype == kUTF16Encoding)
    {
	    //modify: double the length
	    Strcpyw((uint8_t *)filepath,Buffer,length,index);

        length= DiscardTrailigPeriodsw((uint8_t *)Buffer,(length-index),index);  
        
        // The PutWord was not being qualified by 
        // if (length<MAX_UNICODE_SIZE) and therefore
        // causing stack corruption.
        if (length<MAX_UNICODE_SIZE)
        {
          PutWord(Buffer,0,length);
        }
    }

    if(stringtype == kDBCSEncoding)
 	{
 	    if((Flag = IsShortNameValid(filepath,length,index))<0)
	        return (RtStatus_t)Flag;
   	    if(Flag==1)
	        DBCStoUnicode(filepath,(uint8_t*)Buffer,index,length);
   	    else
	    {
	        count=1;
            Strcpy(filepath,(uint8_t*)shortfilename,length,index);
	    }
    }



    if((stringtype == kUTF16Encoding) || (Flag == 1))  // TOVERIFY2   2.6 ver not chosen since 3.05 ver differed and sgtl-HK was referenced in comments of 2.6 ver.
	{
	    strlen = StrlengthW((uint8_t*)Buffer);
        for(i=0;i<strlen;i++)
	    {
 		    byte = FSGetWord(Buffer,offset);
		    for(j=0;j<LONGNAMERES_CH;j++)
		    {
		        if(byte <0x20)
			        return ERROR_OS_FILESYSTEM_ILLEGAL_FILENAME_CHARA;
		        if(byte == Long_NameRes_Ch[j])
		            return ERROR_OS_FILESYSTEM_ILLEGAL_FILENAME_CHARA;
		    }
		    offset+=2;
        }
	    count = (strlen-1)/LONGDIRCH_PER_RECORD + 2;

	    /* set the filename to fit in 8+3 format */
        Setshortfilename(HandleNumber,Buffer,(uint8_t*)shortfilename);
    }

    if(Handle[HandleNumber].StartingCluster!= 0)
	{
	    if((RetValue = FindfreeRecord(HandleNumber,count)) <0)
            return RetValue;
    } 
	else
	{
        if((RetValue = (RtStatus_t)CheckspaceinRootdir(HandleNumber,count)) < 0)
	 	    return RetValue;
	}

    Handle[HandleNumber].Mode |= CREATE_MODE; // einfo
	ArrangeFileName(shortfilename,ShortNameDir);
    
    if(stringtype == kUTF16Encoding || Flag == 1)
   	{
        chksum = ChkSum((uint8_t*)ShortNameDir);
        ArrangeLongFileName(HandleNumber,(uint8_t*)Buffer,count,chksum);
	}
	 
    if((RetValue = CreateShortDirRecord(&ShortNameDir[0],HandleNumber,ClusterNumber,DirAttr,FileSize)) <0)
	{
        Handle[HandleNumber].Mode ^= CREATE_MODE; 
        return RetValue;
	}

    Handle[HandleNumber].FileSize=FileSize;
    
    Handle[HandleNumber].Mode ^= CREATE_MODE;	
	return SUCCESS;
}

/*----------------------------------------------------------------------------
>  Function Name: int32_t ChkSum(uint8_t *filename)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name or directory
                 
   Outputs:       Chksum computed over the given filename.

   Description:   Computes the chksum of the given filename.
<
----------------------------------------------------------------------------*/
int32_t ChkSum(uint8_t *filename)
{
    int32_t Sum=0,temp;
    int i;

    for(i=0;i<11;i++)
    {
        temp = 0;
        if(Sum & 1)
            temp = 0x80;
        Sum = temp + (Sum >>1) + (FSGetByte(filename,i));
        Sum = Sum & 0xff;
    }	
    return Sum;
}
