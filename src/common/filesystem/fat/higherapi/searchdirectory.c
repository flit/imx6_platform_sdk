/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Searchdirectory.c $                                        
 $Revision: 7 $                                       
 $Date: 9/13/03 7:03p $                                           
 Description: Searchdirectory.c
 Notes:	This file read provides higherlevel API function to searchdirectory
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
#include <stdlib.h>

/*----------------------------------------------------------------------------
		Extern Declarations
----------------------------------------------------------------------------*/

extern  int32_t ConverToShortname(uint8_t *file,uint8_t *filenamebuf,int32_t index,int32_t length);
/*----------------------------------------------------------------------------
>  Function Name:  int32_t Searchdirectory(int32_t HandleNumber,uint8_t *file,int32_t stringtype,int32_t Flag,int32_t length,int32_t index,uint8_t *Buffer,BOOL bInputIsSFN)

   FunctionType:   Reentrant

   Inputs:         1) Handle Number
                   2) Pointer to file name
				   3) String type
                   4) Flag
                   5) Length
                   6) Index
                   7) Pointer to buffer 
                   8) bInputIsSFN 
				   
   Outputs:        Starting cluster of the directory found or an error code
                   if function fails. 
   
   Description:    This function checks the directory record from record number 0 
                   to the end of directory for matching the file/directory name.  
----------------------------------------------------------------------------*/
// Modified by SGTL_HK
//int32_t Searchdirectory(int32_t HandleNumber,uint8_t *file,int32_t stringtype,int32_t Flag,int32_t length,int32_t index,uint8_t *Buffer)
//int32_t Searchdirectory(int32_t HandleNumber,uint8_t *file,int32_t stringtype,int32_t Flag,int32_t length,int32_t index,uint8_t *Buffer,bool bInputIsSFN)
// fam:removing SGTL_HK code and restoring good old code
int32_t Searchdirectory(int32_t HandleNumber,uint8_t *file,int32_t stringtype,int32_t Flag,int32_t length,int32_t index,uint8_t *Buffer,bool bSearchFlag,int32_t *pLastRecordnum)
{
    int32_t clusterlo,filefound=0,strlen,offset; 
    int32_t Char,dirattribute,Flag1=0;
    uint8_t buf[32];
    int32_t clusterno;
    int  byte,byte1;
    int32_t RecordNo;   
    
    int64_t Retval;
    int32_t i32ScanFlag = 0;

#ifdef FS_USE_MALLOC
    uint8_t * Shortname;
    int32_t * ucs2buffer;
    Shortname = malloc(256*sizeof(uint8_t));
    if( NULL == Shortname ) {
        return ERROR_OS_FILESYSTEM_MEMORY;
    }
	ucs2buffer = malloc(128*sizeof(int32_t));
    if(NULL == ucs2buffer) {
		free(Shortname);
		return ERROR_OS_FILESYSTEM_MEMORY;
    }
#else
    uint8_t Shortname[256];
    int32_t ucs2buffer[128];
#endif

    offset = index;

    byte = GetChar(file,&offset);
    byte1 = GetChar(file,&offset);
    strlen =  length-index-1;
	/* Special case of .. entry */
    if((byte == 0x2e && byte1 == 0x2e) && strlen==2)
    {
	    PutWord(Shortname,0x2e2e,0);
	    PutByte(Shortname,0,2);
    }
    else
    { 
        if(stringtype == kDBCSEncoding) //Check whether string type is kDBCSEncoding or kUTF16Encoding 
        {
        length=DiscardTrailigPeriods(file,length,index,1);
        Flag1=ConverToShortname(file,(uint8_t*)Shortname,index,length);
	    Uppercase((uint8_t*)Shortname);
    }   
        else        //If kUTF16Encoding then create shortname for long directory and pass this buffer to MatchdirRecordW.
            
        {
	        Strcpyw((uint8_t *)file, (uint8_t *)ucs2buffer,length,index);
	        UnicodeToOEM((uint8_t *)ucs2buffer,(uint8_t *)Shortname, length-index, 0); 
	        Uppercase((uint8_t*)Shortname);
         }   
    }   
#ifdef FS_USE_MALLOC
	free(ucs2buffer);
#endif

    if(bSearchFlag==0)
    {
        RecordNo=0;
        *pLastRecordnum=0;
    }
    else {
        RecordNo=*pLastRecordnum;
    }

    do
    {
        if((Retval = ReadDirectoryRecord(HandleNumber,RecordNo,buf))<0) {
#ifdef FS_USE_MALLOC
            free(Shortname);
#endif
		    return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;
        }
	 
	    Char=0;
	    Char = GetChar((uint8_t*)buf,&Char);
        // A free record is found, if Char is 0
        if(Char == 0)
        {
            if(bSearchFlag==1)
            {
                RecordNo=0;
                i32ScanFlag++;
            }
            else
		    break;
        }
        dirattribute =  FSGetByte(buf,DIR_ATTRIBUTEOFFSET);
        if(stringtype == kDBCSEncoding) 
        {
            if(!(dirattribute & VOLUME_ID))
	        {
	            if(dirattribute != LONGDIRATTRIBUTE)
		  	    {
                   // Modified by SGTL_HK
	               
// fam:removing SGTL_HK code and restoring good old code
//	            	if (bInputIsSFN)		
//    				{
//      					filefound = Shortdirmatch(HandleNumber,RecordNo,file,(uint8_t*)file,buf,Flag1,index,length,Buffer);
//    				}
//    				else	
//    				{
//    	                filefound = Shortdirmatch(HandleNumber,RecordNo,file,(uint8_t*)Shortname,buf,Flag1,index,length,Buffer);
//    	            } 
                    filefound = Shortdirmatch(HandleNumber,RecordNo,file,(uint8_t*)Shortname,buf,Flag1,index,length,Buffer);
				}
	           
	        }
	    }
        if(stringtype == kUTF16Encoding)  
	    { 
	        if((filefound =MatchdirRecordW(HandleNumber,RecordNo,file,buf,index,length,(uint8_t*)Shortname)) == ERROR_OS_FILESYSTEM_FILE_FOUND)
		    {
                dirattribute =  FSGetByte(buf,DIR_ATTRIBUTEOFFSET);     
            	if(dirattribute == LONGDIRATTRIBUTE)				
		 	    {							
    		 	    if(!( (FSGetWord(file,index) == 0x2E) && (FSGetWord(file,(index+2)) == 0x2E)&&((length-index) == 4)))
    		        {
    		     	    RecordNo++;
                        if ((Retval = ReadDirectoryRecord(HandleNumber,RecordNo,buf)) < 0) {
#ifdef FS_USE_MALLOC
							free(Shortname);
#endif
                            return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;
                        }
    			    }
			    }	   								
	        }
	    }
	  	 
	    if(filefound == ERROR_OS_FILESYSTEM_FILE_FOUND)
	    {
            if (Handle[HandleNumber].StartingCluster != 0)
   	            Fseek(HandleNumber,RecordNo*32,SEEK_SET);
		    else
                SetcurrentPos(HandleNumber,RecordNo);
	   
	        clusterlo = FSGetWord(buf,DIR_FSTCLUSLOOFFSET);
		    clusterno = FSGetWord(buf,DIR_FSTCLUSHIOFFSET);
		    clusterno =	 (int32_t)clusterlo + (clusterno << 16);
			Handle[HandleNumber].FileSize = FSGetDWord((uint8_t *)buf,DIR_FILESIZEOFFSET);
            if(bSearchFlag==1) {
                *pLastRecordnum=RecordNo;
            }
#ifdef FS_USE_MALLOC
			free(Shortname);
#endif
	        return (clusterno);
	    }
	  
	    RecordNo++;
        if (i32ScanFlag)
        {
            if (RecordNo >= *pLastRecordnum)
                break;
        }
	}while(1);
#ifdef FS_USE_MALLOC
	free(Shortname);
#endif
	
    //change is applied upto end of file	
    // changes added to support special short file names  16/9/2004
    // When five or more files exist that can result in duplicate short file names, Windows XP Professional
    // uses a slightly different method for creating short file names.
    // For the fifth and subsequent files, Windows XP Professional:
    //    Uses only the first two letters of the long file name. 
    //Generates the next four letters of the short file name by mathematically manipulating the remaining letters of the long file name. 
     // to support this we have to again go for long directory name match if string type is kDBCSEncoding and if this function is not called from setshortfilename()

     if(stringtype == kDBCSEncoding && Flag == 1)
      {
       RecordNo = 0;
       do
        {
            if((Retval = ReadDirectoryRecord(HandleNumber,RecordNo,buf))<0)
                return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;

            Char=0;
            Char = FSGetByte(buf,0);
            if(Char == 0)
              break;
            dirattribute =  FSGetByte(buf,DIR_ATTRIBUTEOFFSET);

            if(dirattribute == LONGDIRATTRIBUTE)
            {
              if(Char == 1 || Char == 0x41)
              {
                   RecordNo++;
                       DBCStoUnicode(file,(uint8_t*)Buffer,index,length);
	               strlen = StrlengthW((uint8_t*)Buffer);
	               strlen = strlen<<1;
	               filefound = Longdirmatch(HandleNumber,RecordNo,(uint8_t*)Buffer,0,strlen,UCS2s);
	               
                   if(filefound == ERROR_OS_FILESYSTEM_FILE_FOUND)
                   {
                       if ((Retval = ReadDirectoryRecord(HandleNumber,RecordNo,buf)) < 0) {
                            return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;
                       }
                        if (Handle[HandleNumber].StartingCluster != 0)
   	                        Fseek(HandleNumber,RecordNo*32,SEEK_SET);
		                else
                            SetcurrentPos(HandleNumber,RecordNo);
	                clusterlo = FSGetWord(buf,DIR_FSTCLUSLOOFFSET);
		            clusterno = FSGetWord(buf,DIR_FSTCLUSHIOFFSET);
		            clusterno =	 (int32_t)clusterlo + (clusterno << 16);
			    Handle[HandleNumber].FileSize = FSGetDWord((uint8_t*)buf,DIR_FILESIZEOFFSET);
	                return (clusterno);
                   }
                }
              }     
                
            RecordNo++;

        }while(Retval !=0);
               
     }
    return (ERROR_OS_FILESYSTEM_FILE_NOT_FOUND);
}
