/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/CreateDirectory.c $
 $Revision: 13 $                                       
 $Date: 9/16/03 12:21p $
 Description: CreateDirectory.c
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
#include <stdlib.h>

/*----------------------------------------------------------------------------

>  Function Name: int32_t CreateDirectory(int32_t HandleNumber,uint8_t *Filepath,int32_t length,int32_t index,int32_t stringtype)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                  2)Pointer to File Name
                  3)length(end of string from file path)
                  4)index(points to start of the string from file path)  
		          5)stringtype(kUTF16Encoding or kDBCSEncoding)    
   Outputs:       Return HandleNumber if Success, or ERROR CODE if  Error Occurs

   Description:   Creates a new Directory  in a given directory

<
----------------------------------------------------------------------------*/
int32_t CreateDirectory(int32_t HandleNumber,uint8_t *Filepath,int32_t length,int32_t index,int32_t stringtype)
{
    uint8_t Buffer[33];
    uint8_t ShortName[12];
    int32_t ClusterNumber,NewClusterNum;
    int32_t Device = Handle[HandleNumber].Device;
    int  TempHandleActive=0;
    int  TempDevice=0;
    FileSystemModeTypes_t  TempMode=NOT_WRITE_MODE;
    int32_t TempStartingCluster=0;
    int32_t TempCurrentOffset=0;
    int32_t TempCurrentCluster=0;
    int32_t TempCurrentSector=0;
    int  TempBytePosInSector=0;
    int  TempSectorPosInCluster=0;
    int32_t TempDirSector=0;
    int  TempDirOffset=0;
    int32_t RetValue;
    uint32_t TempFileSize=0;
    int k,Count,i,j;
    uint8_t Byte;
    int Word;
    int32_t RecordNum=0;
    
#ifdef FS_USE_MALLOC
    uint8_t * UnicodeBuffer;
    UnicodeBuffer = malloc(MAX_UNICODE_SIZE*sizeof(uint8_t));
    if( NULL == UnicodeBuffer ) {
        return ERROR_OS_FILESYSTEM_MEMORY;
    }
#else
    uint8_t UnicodeBuffer[MAX_UNICODE_SIZE];
#endif

    EnterNonReentrantSection();
    for (k=0;k<sizeof(ShortName);k++)
        ShortName[k] = 0x20;

    memset(Buffer,0,sizeof(Buffer));
   
    //This HandleNumber will be Current dir HandleNumber=0
    if((Handle[HandleNumber].Mode & READ_MODE) !=READ_MODE)
    {
        LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
        free(UnicodeBuffer);
#endif
        return ERROR_OS_FILESYSTEM_DIRECTORY_IS_NOT_WRITABLE;
    }
    
    //Check if Directory is already present
    if (stringtype == kUTF16Encoding)     //check for kUTF16Encoding or kDBCSEncoding
    {
    	if ((RetValue = Searchdirectory(HandleNumber, Filepath, kUTF16Encoding, 0, length, index, (uint8_t*)UnicodeBuffer,1,&RecordNum/*, TRUE*/)) >= 0)
    	{
    		LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
    		return ERROR_OS_FILESYSTEM_DUPLICATE_FILE_NAME;
    	}
    }
    else
    {
     	if((RetValue=Searchdirectory(HandleNumber,Filepath,kDBCSEncoding,0, (length+1), index,(uint8_t*)UnicodeBuffer,1,&RecordNum/*, FALSE*/))>=0)
     	{
       		LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
         	return ERROR_OS_FILESYSTEM_DUPLICATE_FILE_NAME;
     	}
    }
    if (stringtype == kDBCSEncoding)
    {     //check for kUTF16Encoding or kDBCSEncoding
	    Count = Strlength(Filepath);

	    for(i=0; i <=Count; i++)
	    {
		    Byte = FSGetByte(Filepath,i);
		    if(Byte==0x2e)
		    {
			    //This is to check number of .or...(dots) are there in file path return with error
                //because it is invalid to create dir with only .or ..
			    while(1)
			    {
				    Byte = FSGetByte(Filepath,i);i++;
				    if(Byte!=0x2e)
					    break;
			    }
			    if(Byte=='\0')
                {
                    LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
                    free(UnicodeBuffer);
#endif
				    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH;
                }
		    }
	    }
      }  
    else
    {
    
	    Count = StrlengthW(Filepath);
        j=0;
	    for(i=0; i <=Count*2; i+=2)
	    {
		    Word = GetCharW(Filepath,&j);
		    if(Word==0x2e)
		    {
			    //This is to check number of .or...(dots) are there in file path return with error
                //because it is invalid to create dir with  only .or ..
			    while(1)
			    {
				    Word = GetCharW(Filepath,&j);
				    if(Word!=0x2e)
					    break;
			    }
			    if(Word=='\0')
                {
                    LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
                    free(UnicodeBuffer);
#endif
				    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH;
                }
		    }
	    }
      }  
    
    if((ClusterNumber = FirstfreeAndallocate(Device)) <=0)
    {
        LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
        free(UnicodeBuffer);
#endif
        return ClusterNumber;
    }
	//Copy the handle    
    TempHandleActive = Handle[HandleNumber].HandleActive;
    TempDevice = Handle[HandleNumber].Device;
    TempMode = (FileSystemModeTypes_t)Handle[HandleNumber].Mode;
    TempStartingCluster = Handle[HandleNumber].StartingCluster;
    TempCurrentOffset = Handle[HandleNumber].CurrentOffset;
    TempCurrentCluster = Handle[HandleNumber].CurrentCluster;
    TempCurrentSector = Handle[HandleNumber].CurrentSector;
    TempBytePosInSector= Handle[HandleNumber].BytePosInSector;
    TempSectorPosInCluster = Handle[HandleNumber].SectorPosInCluster;
    TempDirSector = Handle[HandleNumber].DirSector;
    TempDirOffset = Handle[HandleNumber].DirOffset;
    TempFileSize  =  Handle[HandleNumber].FileSize;

    if (stringtype == kUTF16Encoding)     //check for kUTF16Encoding or kDBCSEncoding
    {
    	if ((RetValue = (int32_t)CreateDirRecord(Filepath, HandleNumber, ClusterNumber, DIRECTORY+ARCHIVE,
    												kUTF16Encoding, length, index, (uint8_t *)UnicodeBuffer,0)) < 0)
    	{
    		LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
    		return RetValue;
    	}
    }
    else
    {
        if((RetValue = (int32_t)CreateDirRecord(Filepath,HandleNumber,ClusterNumber,DIRECTORY+ARCHIVE,kDBCSEncoding,length,index,UnicodeBuffer,0))< 0)
        {
            LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
            return RetValue;
        }
    }
    NewClusterNum = Handle[HandleNumber].StartingCluster;

	//This will update the handle to the created directory
    UpdateHandle(HandleNumber,ClusterNumber);
    
    if((RetValue = (int32_t)ClearCluster(HandleNumber)) <0)
    {
        LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
        free(UnicodeBuffer);
#endif
	    return RetValue;
    }

    Handle[HandleNumber].Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE + READ_MODE + WRITE_MODE);

    if(Handle[HandleNumber].StartingCluster!=0)
    {
        PutByte(ShortName,0x2e,0);

        if((RetValue = (int32_t)CreateShortDirRecord(ShortName,HandleNumber,ClusterNumber,DIRECTORY+ARCHIVE,0)) <0)
        {
            LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
            return RetValue;
        }
        Handle[HandleNumber].Mode = (FileSystemModeTypes_t)(DIRECTORY_MODE + READ_MODE + WRITE_MODE);
        PutByte(ShortName,0x2e,1);

//        if(MediaTable[Handle[HandleNumber].Device].FATType==FAT32 && Handle[HandleNumber].StartingCluster==2)
        if(MediaTable[Handle[HandleNumber].Device].FATType==FAT32 && NewClusterNum==2)
	NewClusterNum=0;//For FAT32 also starting cluster of .. entry should be zero

        if((RetValue = (int32_t)CreateShortDirRecord(ShortName,HandleNumber,NewClusterNum,DIRECTORY+ARCHIVE,0)) <0)
        {
            LeaveNonReentrantSection();
#ifdef FS_USE_MALLOC
            free(UnicodeBuffer);
#endif
            return RetValue;
        }
    }
	//Restore the handle
    Handle[HandleNumber].HandleActive = TempHandleActive;
    Handle[HandleNumber].Device = TempDevice;
    Handle[HandleNumber].Mode = TempMode;
    Handle[HandleNumber].StartingCluster = TempStartingCluster;
    Handle[HandleNumber].CurrentOffset = TempCurrentOffset;
    Handle[HandleNumber].CurrentCluster = TempCurrentCluster;
    Handle[HandleNumber].CurrentSector = TempCurrentSector;
    Handle[HandleNumber].BytePosInSector = TempBytePosInSector;
    Handle[HandleNumber].SectorPosInCluster = TempSectorPosInCluster;
    Handle[HandleNumber].DirSector = TempDirSector;
    Handle[HandleNumber].DirOffset = TempDirOffset;
    Handle[HandleNumber].FileSize = TempFileSize;
    LeaveNonReentrantSection();

#ifdef FS_USE_MALLOC
    free(UnicodeBuffer);
#endif
    return  (int32_t)SUCCESS;
}
