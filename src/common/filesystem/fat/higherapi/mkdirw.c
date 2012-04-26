/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Mkdirw.c $                                        
 $Revision: 8 $                                       
 $Date: 9/13/03 12:22p $     6/29/05 update                                          
 Description: Mkdirw.c
 Notes:	This file reads provides higherlevel api functon to make(create) a new directory
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

>  Function Name:  RtStatus_t Mkdirw(uint8_t *filepath)

   FunctionType:   Reentrant

   Inputs:        1) Pointer to file name (uint8_t)
				   
   Outputs:       FS_SUCCESS OR error code if error occurs      
   
   Description:   Searches for given directory path, if path is found then creates
                  given directory in the directoy path.
----------------------------------------------------------------------------*/
RtStatus_t Mkdirw(uint8_t *filepath)

{
    int32_t HandleNumber;
    RtStatus_t Retvalue;
    int32_t index=0,currentposition=0;  
    int32_t clusterno;	
    int32_t byte,source_offset=0;
    int32_t length;



	/* Take temporary(directory)handle for searching the directory by changing path*/
    HandleNumber = DIRECTORY_HANDLE; 

   /* if the temporary handle is already active then change path is not possible */
	if(Handleactive(HandleNumber)== SUCCESS)
		 return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;
    Handle[HandleNumber].HandleActive = 1;

   
	/* first search for the given directory */
	if (SetHandleforsearch(HandleNumber,filepath, kUTF16Encoding, &index) < 0)
    //if(SetHandleforsearch(HandleNumber,filepath,kDBCSEncoding,&index)<0)
    {
       Freehandle(HandleNumber);
       return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	}

	length=StrlengthW((uint8_t *)filepath);
    if(length==0)
        return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;    
	//length=Strlength(filepath);

    /*if at the end of dirname Directory separator(/)is found then discard it.*/
    source_offset=length-1;
    source_offset+=source_offset;
    byte = filepath[source_offset];
	if(byte == 0x002f)
	{
      //source_offset=length-1;

      filepath[source_offset] = 0;
    }
	

	currentposition=Extractfilenamew((uint8_t *)filepath, &index);
   //currentposition=Extractfilename(filepath,strlen1,&index);


   	/* Change the path to the specified path given*/
   	if(currentposition !=index)
	{
 	if ((clusterno = Changepath(HandleNumber, (uint8_t *)filepath, kUTF16Encoding, currentposition, index)) < 0)
    //if((clusterno =  Changepath(HandleNumber,filepath,kDBCSEncoding,currentposition,index)) <0)
     {
       Freehandle(HandleNumber);
         return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	 }
    UpdateHandle(HandleNumber,clusterno);
   	}

	/* remove this not required, due to compiler pbm*/
	index=0;
	/* create given directory in the directoy refernce by the handle */

	if ((Retvalue = CreateDirectory(HandleNumber, (uint8_t *)filepath, length*2, currentposition, kUTF16Encoding)) < 0)
    //if((Retvalue = CreateDirectory(HandleNumber,filepath,strlen1,currentposition))< 0)
	{
       Freehandle(HandleNumber);
	   return Retvalue;
	}

   /* Free the handle used for search */
    Freehandle(HandleNumber);
   
    return (SUCCESS); 
}

