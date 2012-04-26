/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Longfilename.c $                                        
 $Revision: 9 $                                       
 $Date: 10/01/03 2:23p $                                           
 Description: Longfilename.c
 Notes:	This file read provides higherlevel API function to provide long file name.
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
#include <string.h>

#define READ_CASE_EXTENSION_BYTE    0x0C
#define LOWER_CASE_BASENM_BIT3      0x08
#define LOWER_CASE_EXTNM_BIT4       0x10
#define SHORTNM_MAX_FILE_LEN        12

/*----------------------------------------------------------------------------
>  Function Name:  int32_t ConstructLongFileName(int32_t HandleNumber, int32_t RecordNumber, int32_t *LFNBuffer)

   FunctionType:   Reentrant

   Inputs:         1) Handle number
                   2) Record Number
				   3) Pointer to file name buffer
   
   Outputs:        Returns Length of the Long file name string
      
   Description:    Provides long file name
----------------------------------------------------------------------------*/
int32_t ConstructLongFileName(int32_t HandleNumber, int32_t RecordNumber, int8_t *LFNBuffer)
{
    int32_t offset,Dirattribute,Signature;
    int i = 1, j;
    uint8_t Buffer[36];
    int LFNStringOffset=0;
    uint32_t unicodeWord;

    RecordNumber--;

    if (RecordNumber < 0)
    {
        PutWord((uint8_t*)LFNBuffer,0,0);
        return 0;
    }
    while(1)
    {  
        if(RecordNumber >=0)
        {   
            memset(Buffer,0,36);
            if (ReadDirectoryRecord(HandleNumber,RecordNumber,Buffer)< 0)  
                return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;        
            RecordNumber--;
            if(i==1)
            {  
                //only occurs once per file (i only equals 1 the first iteration of the loop).
                Signature= FSGetByte((uint8_t*)Buffer,LDIRORDOFFSET);
                if((Signature & 0x000000FF) != 0x00000001 && (Signature & 0x000000FF) != 0x00000041)
                { 
                    //in this case there is no LFN entry
                    PutWord((uint8_t*)LFNBuffer,0,LFNStringOffset);     
                    return LFNStringOffset;
                }
            } 
            Dirattribute = FSGetByte((uint8_t*)Buffer,DIR_ATTRIBUTEOFFSET);
            if(Dirattribute!=  0x0000000F)
            {
                PutWord((uint8_t*)LFNBuffer,0,LFNStringOffset);    
                return LFNStringOffset;
            }
        }
        else
        {
            PutWord((uint8_t*)LFNBuffer,0,LFNStringOffset);
            return LFNStringOffset;
        }
        offset =LDIRNAME1OFFSET;
        for(j=0;j<5;j++)
        {
            //5 chars
            if(LFNStringOffset >= MAX_FILENAME_LENGTH*2)
            {
                LFNStringOffset = MAX_FILENAME_LENGTH*2;
                return LFNStringOffset;
            }
            unicodeWord = GetUnicodeWord(Buffer,offset); 
            PutWord((uint8_t*)LFNBuffer,unicodeWord,LFNStringOffset);
            LFNStringOffset+=2;
            offset+=2;
        }
        offset=LDIRNAME2OFFSET;
        for(j=0;j<6;j++)
        {  
            //6 chars
            if(LFNStringOffset >= MAX_FILENAME_LENGTH*2)
            {
                LFNStringOffset = MAX_FILENAME_LENGTH*2;
                return LFNStringOffset;
            }
            unicodeWord = GetUnicodeWord(Buffer,offset); 
            PutWord((uint8_t*)LFNBuffer,unicodeWord,LFNStringOffset);
            LFNStringOffset+=2;
            offset+=2;
        }
        offset=LDIRNAME3OFFSET;
        for(j=0;j<2;j++)
        {  
            //2 chars
            if(LFNStringOffset >= MAX_FILENAME_LENGTH*2)
            {
                LFNStringOffset = MAX_FILENAME_LENGTH*2;
                return LFNStringOffset;
            }
            unicodeWord = GetUnicodeWord(Buffer,offset); 
            PutWord((uint8_t*)LFNBuffer,unicodeWord,LFNStringOffset);
            LFNStringOffset+=2;
            offset+=2;
        }
        i++;
    } // while(1)            
}
              
/*----------------------------------------------------------------------------
>  Function Name:  int32_t GetUnicodeWord(uint8_t *Buffer,int32_t LFNOffset)

   FunctionType:   Reentrant

   Inputs:         1) Pointer to Buffer
                   2) Long file name offset
   
   Outputs:        Returns 0(Null Terminator) or Unicode Word
      
   Description:    Provides Unicode Word from Unicode Character
----------------------------------------------------------------------------*/
int32_t GetUnicodeWord(uint8_t *Buffer,int32_t LFNOffset)
{	
    //each Unicode char is 2 bytes
	int rtn = 0;
	rtn =  FSGetWord(Buffer,LFNOffset); //each unicode character is stored in little endian so reverse it
	if(rtn == 0x00FFFF)
    {
	    rtn = 0;	//null terminator for unicode string
	}
	return rtn;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief      Change the basename and/or extension name in a file name to lower case
//! Please see fasapi.h for more detailed description
////////////////////////////////////////////////////////////////////////////////
int32_t CheckFileNameCase(int32_t HandleNumber, FindData_t * pFindData)
{
    int32_t Dirattribute, Idx = 0, base_len = 0;
    uint8_t Buffer[36];
    bool ChgCaseBaseLow = false;
    bool ChgCaseExtLow = false;
    uint32_t RecordNumber = pFindData->startrecord-1;

    if (ReadDirectoryRecord(HandleNumber,RecordNumber,Buffer)< 0)
    {
         return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;        
    }
    Dirattribute = FSGetByte((uint8_t*)Buffer,DIR_ATTRIBUTEOFFSET);
    if(Dirattribute !=  0x0000000F)
    {
        //Check if file created in NTFS in order to preserve cases
        //if bit 3 is set in 0x0c byte then this is all lower case basename
        //if bit 4 is set in 0x0c byte then this is all lower case extension
        Idx =  FSGetByte((uint8_t*)Buffer,READ_CASE_EXTENSION_BYTE);
        if ((Idx & LOWER_CASE_BASENM_BIT3) == LOWER_CASE_BASENM_BIT3)
        {
            ChgCaseBaseLow = true;
        }
        if ((Idx & LOWER_CASE_EXTNM_BIT4) == LOWER_CASE_EXTNM_BIT4)
        {
            ChgCaseExtLow = true;
        }

        Idx = 0;

        if ( (ChgCaseBaseLow == false) && (ChgCaseExtLow == false) )
        {
            //Base name and extension name case need not be changed
            return 0;
        }
        
        while ((pFindData->name[Idx] != '.') && (pFindData->name[Idx] != 0))
        {
            if (ChgCaseBaseLow == true)
            {
                //convert base name case
                if(pFindData->name[Idx] >= 'A' && pFindData->name[Idx] <= 'Z')
                {
                    pFindData->name[Idx] = (pFindData->name[Idx] - 'A') + 'a';
                }
            }
            Idx++;
        }
        base_len = Idx;
        if (ChgCaseExtLow == true)
        {
            //convert ext name case
            for(Idx = base_len; Idx < SHORTNM_MAX_FILE_LEN; Idx++)
            {
                if (pFindData->name[Idx] == '.')
                {
                    continue;
                }
                if(pFindData->name[Idx] >= 'A' && pFindData->name[Idx] <= 'Z')
                {
                    pFindData->name[Idx] = (pFindData->name[Idx] - 'A') + 'a';
                }
            }
        }
    }
    return 0;
}

