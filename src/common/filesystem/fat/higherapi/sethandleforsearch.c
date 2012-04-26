/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/SetHandleforsearch.c $                                        
 $Revision: 17 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: SetHandleforsearch.c
 Notes:	This file read provides higherlevel API function to set the given handle
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
>  Function Name: int32_t SetHandleforsearch(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype,int32_t *index)

   FunctionType:  Reentrant

   Inputs:        1) Handle Number 
                  2) Pointer to file name
                  3) Stringtype
                  4) Index
				   
   Outputs:       Fields of Handle is set according to the given file path. 

   Description:   This function searches whether the file path is from root directory,
                  current working directory or parent directory based on the 
                  file path given. It sets the given handle based on this search.
----------------------------------------------------------------------------*/
int32_t SetHandleforsearch(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype,int32_t *index)
{
    int32_t Firstword=0,secondword=0,clusterlo,offset=0; 
    int64_t NumBytesRead;
    int i;
    uint8_t buf[32];
    int32_t clusterno;  
    int Firstchar=0,secondchar=0;
    int32_t numdots=0,Byte,Count=0;

    *index=0;
    if(HandleNumber > maxhandles)
        return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

        
	Count = Strlength(filepath);
	for(i=0; i <=Count; i++)
	{
		Byte = FSGetByte((uint8_t *)filepath,i);
		if(Byte==0x2e)
		{
			//This is to check number of .(dots) in between '/'(slashes) or '\0' (null character)
			//If .(dots) are greater than 2 return error
			while(1)
			{
				Byte = FSGetByte((uint8_t *)filepath,i);i++;
				if(Byte==0x2e)
					numdots++;
				if(Byte!=0x2e)
					break;
			}
			if((numdots>2) && ((Byte=='\0') || (Byte=='/')))
				return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH;
			//Reset the .(dot) count as new set of .(dots) will start with new count
			numdots=0;
		}
	}
    if(stringtype == kDBCSEncoding)
    {
        Firstchar = GetChar(filepath,&offset);
		secondchar = GetChar(filepath,&offset);
	}
    else if(stringtype == kUTF16Encoding)
	{
	    Firstword = FSGetWord(filepath,0);
	    secondword = FSGetWord(filepath,2);
	}

	if (secondchar == ':' || secondword == ':')
	{

        Handle[HandleNumber].Device = -1;
        for(i=0; i < maxdevices; i++)
        {
            if(Firstchar == DriveLetter[i] || Firstword == DriveLetter[i])
            {
                if(MediaTable[i].DevicePresent)
                {
                    Handle[HandleNumber].Device = i;
                    break;
                }
            }
            Firstchar =Changecase(Firstchar);
            Firstword =Changecase(Firstword);

            if(Firstchar == DriveLetter[i] || Firstword == DriveLetter[i])
            {
                if(MediaTable[i].DevicePresent)
                {
                    Handle[HandleNumber].Device = i;
                    break;
                }
            }
        }  // for (maxdevices)
	    if(Handle[HandleNumber].Device < 0)
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
			   
       	Handle[HandleNumber].Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE + READ_MODE + WRITE_MODE);	 // set mode to directory to read the directory 
        if((ChangeToRootdirectory(HandleNumber)) < 0)
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
        if(stringtype == kDBCSEncoding)
	    {
		    if((ExtractPath(filepath,index)) == END_OF_DIR_PATH)
                return END_OF_DIR_PATH;
		}
	    else if(stringtype == kUTF16Encoding)
 	    {
	        if((ExtractPathW(filepath,index)) == END_OF_DIR_PATH)
                return END_OF_DIR_PATH;
	    }
	 
	}

	else if(Firstchar == '/' || Firstword == '/')
	{
        Handle[HandleNumber].Device = Handle[0].Device;
       	Handle[HandleNumber].Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE + READ_MODE + WRITE_MODE);	 // set mode to directory to read the directory 
        if((ChangeToRootdirectory(HandleNumber)) < 0)
            return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
        if(stringtype == kDBCSEncoding)
		{
		    if((ExtractPath(filepath,index)) == END_OF_DIR_PATH)
                return END_OF_DIR_PATH;
		}
	    else if(stringtype == kUTF16Encoding)
 	    {
		    if((ExtractPathW(filepath,index)) == END_OF_DIR_PATH)
                return END_OF_DIR_PATH;
		}
	 
	}

	else 
	{
	    Handle[HandleNumber]=Handle[CWD_HANDLE];
        Handle[CWD_HANDLE].Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE + READ_MODE + WRITE_MODE);		// set mode to directory to read the directory 
     
        if(Firstchar == 0x2E ||Firstword ==0x2E)
	    {
	 	    if(secondchar == 0x2E || secondword ==0x2E)
	        {
    		    if(Handle[HandleNumber].StartingCluster==MediaTable[Handle[HandleNumber].Device].RootdirCluster)
				    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH;
	            NumBytesRead =  ReadDirectoryRecord(HandleNumber,1,buf); 
	  	        clusterlo = FSGetWord(buf,DIR_FSTCLUSLOOFFSET);
			    clusterno = FSGetWord(buf,DIR_FSTCLUSHIOFFSET);
			    clusterno =	 (int32_t)clusterlo + (clusterno << 16);
			    if(clusterno == 0)
			        clusterno = MediaTable[Handle[HandleNumber].Device].RootdirCluster;
			    UpdateHandle(HandleNumber,clusterno);
            }
		    if(stringtype == kDBCSEncoding)
		    {
		        if((ExtractPath(filepath,index)) == END_OF_DIR_PATH)
                    return END_OF_DIR_PATH;
		    }
		    else if(stringtype == kUTF16Encoding)
            {
		        if((ExtractPathW(filepath,index)) == END_OF_DIR_PATH)
                    return END_OF_DIR_PATH;
		    }
        }
    }
	
	(void)NumBytesRead;
	return(SUCCESS);

}


	 




		
