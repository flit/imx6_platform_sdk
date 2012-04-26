/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/FindNext.c $
 $Revision: 8 $                                       
 $Date: 9/18/03 7:31p $
 Description: FindNext.c
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
#include "FileSpec.h"
/*----------------------------------------------------------------------------
		Extern Declarations
----------------------------------------------------------------------------*/
extern FileSpecs_t* FileSpec;
/*----------------------------------------------------------------------------
		Global Declarations
----------------------------------------------------------------------------*/
int StringCompare(uint8_t *Buffer,uint8_t *DestBufffer,int32_t StringLength,int32_t Offset);
/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t FindNext(int32_t HandleNumber,FindData_t *_finddata)

   FunctionType:  Reentrant but this function should not be called from multiple task

   Inputs:        1)Handle Number
                  2)File Specification Structure

   Outputs:       Returns 0 on Success else an ErrorCode if Error occurs 

   Description:   It reads the directory record from the given record and finds 
   				  the first file or directory which matches the specifications.
<
----------------------------------------------------------------------------*/
RtStatus_t FindNext(int32_t HandleNumber,FindData_t *_finddata)
{
    int RetValue=0,Byte,i=0,j=0;
	uint8_t Buffer[32];
	RtStatus_t Return= ERROR_OS_FILESYSTEM_NO_MATCHING_RECORD;
	int64_t key;

    if((HandleNumber <0)||(HandleNumber >= maxhandles))
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    if((RetValue = Handleactive(HandleNumber))<0)
        return ERROR_OS_FILESYSTEM_HANDLE_NOT_ACTIVE;

	while(1)
	{
		if((key = ReadDirectoryRecord(HandleNumber,FileSpec[HandleNumber].gCurrentRecord++,Buffer))<=0)
			return	ERROR_OS_FILESYSTEM_NO_MATCHING_RECORD;

		// Check for Long File name
        if((FSGetByte(Buffer,DIR_ATTRIBUTEOFFSET))==LONGDIRATTRIBUTE)
			continue;
        Byte = FSGetByte(Buffer,DIR_NAMEOFFSET);
        // Check for . and .. Entry
        if(Byte=='.')
            continue;
		// End of directories
		if(Byte==0)
			break;
		else
		{
			if(Byte!=0xe5)
			{   // Check for kanji fix
				if(Byte==0x05)
				    PutByte(Buffer,0xe5,0);
				if(!(RetValue = StringCompare(Buffer,FileSpec[HandleNumber].FileName,Strlength(FileSpec[HandleNumber].FileName),0)))
				{
					if(!(RetValue = StringCompare(Buffer,FileSpec[HandleNumber].FileExtension,Strlength(FileSpec[HandleNumber].FileExtension),8)))
					{
					    for(i=0; i < 8; i++)
						{
						    if((Byte = FSGetByte(Buffer,i))==' ')
							    break;
							else 
								PutByte(_finddata->name,Byte,i);
						}
						if((Byte = FSGetByte(Buffer,8))!=' ')
						    PutByte(_finddata->name,'.',i);
						else 
							PutByte(_finddata->name,0,i);
						i++;

						for(j=8;j < 11; j++)
						{
							if((Byte = FSGetByte(Buffer,j))==' ')
								break;
							else 
								PutByte(_finddata->name,Byte,i++);
						}
						PutByte(_finddata->name,0,i);
						_finddata->attrib = FSGetByte(Buffer,DIR_ATTRIBUTEOFFSET);
						_finddata->startrecord = FileSpec[HandleNumber].gCurrentRecord;
						_finddata->FileSize = FSGetDWord(Buffer,DIR_FILESIZEOFFSET);
						_finddata->Key = key;
					Return = SUCCESS;
						break;
					}
				}
			}
		}
	} // while(1)

	(void)RetValue;
	return Return;
}
/*----------------------------------------------------------------------------
>  Function Name: int StringCompare(uint8_t *Buffer,uint8_t *DestBufffer,int32_t StringLength,int32_t Offset)

   FunctionType:  Non-Reentrant
   
   Inputs:        1)Pointer to buffer
                  2)Pointer to destination buffer
                  3)String length
                  4)Offset

   Outputs:       Returns 0  or  1

   Description:   Compares the string.
<
----------------------------------------------------------------------------*/
int StringCompare(uint8_t *Buffer,uint8_t *DestBufffer,int32_t StringLength,int32_t Offset)
{
    int i=0,Byte,j=0;
	int RetValue=1;
	for( i=0; i < StringLength; i++)
	{
	    if((Byte = FSGetByte(DestBufffer,i))=='\0')
			break;
		if((Byte == FSGetByte(Buffer,i+Offset)))
			j++;
	}
	if(j==StringLength)
		return 0;

    return RetValue;
}



