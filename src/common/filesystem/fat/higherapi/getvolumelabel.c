/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/getvolumelabel.c $
 $Revision: 4 $
 $Date: 9/13/03 12:20p $
 Description: getvolumelabel.c
 Notes:	This file reads provides base functon to change the directory to Root directory 
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/

#include "types.h"
#include "fstypes.h"
//#include "extern.h"
#include "error.h"
#include "platform.h"
#include "BootSecOffset.h"
#include "DirOffset.h"
//#include "dirrecord.h"
#include <os/fsapi.h> //! \todo malinclusion
#include "fat_internal.h"
///*----------------------------------------------------------------------------
//
//   Function Name:int _reentrant  GetVolumeLabel(BYTE *Buffer,int DeviceNum)
//
//   FunctionType:  Reentrant
//
//   Inputs:        1)Buffer
//					2)DeviceNumber
//
//   Outputs:       SUCCESS  or error code if an  Error  occurs
//
//   Description:   Get the Volume Id of the drive in passed Buffer
//
////----------------------------------------------------------------------------*/

int GetVolumeLabel(BYTE *Buffer,int DeviceNum)

{
	int HandleNumber;
	int buf[11]; //DIRRECORDSIZE];
	int RecordNo = 0,Char,dirattribute,Retval;
	int offset,offset_dest;
	int byte;

	/* Search for free handle and allocate it*/
	if((HandleNumber = Searchfreehandleallocate())<0)
		return(ERROR_OS_FILESYSTEM_NO_FREE_HANDLE);
	Handle[HandleNumber].Device = DeviceNum;
	Handle[HandleNumber].Mode = DIRECTORY_MODE + READ_MODE;
	/*Change to root directory*/
	if((ChangeToRootdirectory(HandleNumber)) < 0)
    {
		    Freehandle(HandleNumber);
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
    }
    /*Find the volume label record*/
	do
	{
	    if((Retval = ReadDirectoryRecord(HandleNumber,RecordNo,(BYTE *)buf))<0)
		{
		    Freehandle(HandleNumber);
		    return ERROR_OS_FILESYSTEM_VOLUMELABEL_NOT_FOUND;
		}

		Char=0;
		Char = GetChar((BYTE *)buf,&Char);
		/* If no volume id found then return*/
		if(Char == 0)
		{
		   Freehandle(HandleNumber);
		   return ERROR_OS_FILESYSTEM_VOLUMELABEL_NOT_FOUND;
		}
		if(Char == 0xe5)
		{
			RecordNo++;
			continue;
		}
		dirattribute =  FSGetByte((uint8_t *)buf,DIR_ATTRIBUTEOFFSET);

		if(!(dirattribute & READ_ONLY || dirattribute & SYSTEM || dirattribute & DIRECTORY))
		{
        	if(dirattribute & VOLUME_ID)
			{
				break;
			}
	 	}
	    RecordNo++;

	}while(Retval !=0);

	/*If volume id found then copy it in passed buffer*/
    offset = 0;
    offset_dest=0;
    while(offset<11)
    {
        byte = GetChar((BYTE *)buf,&offset);
        if(byte == 0x20)
        {
          PutByte(Buffer,'\0',offset_dest);
          break;
        }
        PutChar((BYTE *)Buffer,&offset_dest,byte);

    }
    PutByte(Buffer,'\0',offset_dest);

    Freehandle(HandleNumber);
    return SUCCESS;
}






