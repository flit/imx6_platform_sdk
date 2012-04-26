/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/platform/platform.c $
 $Revision: 17 $
 $Date: 9/13/03 12:22p $
 Description: platform.c
 Notes:	This file read provides API to work on 32bit platforms.
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
//#include <stdio.h>
#include <types.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
//! \brief      Returns a byte from buffer.
//!
//! \fntype     Function
//!
//! As per the offset given this function returns byte from buffer.
//!
//! \param[in]  buffer          Pointer to a buffer.
//! \param[in]  iOffsetInUint8  Offset in bytes to a byte in that buffer.
//!
//! \retval int32_t             A byte that was in buffer at offset iOffsetInUint8.
//!
////////////////////////////////////////////////////////////////////////////////
int32_t FSGetByte(uint8_t *buffer, int32_t iOffsetInUint8)
{
    int temp;
    temp = ((uint8_t)buffer[iOffsetInUint8]);
    return temp;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief      Returns a u16 from buffer.
//!
//! \fntype     Function
//!
//! As per the offset given this function returns u16 from buffer.
//!
//! \param[in]  buffer          Pointer to a buffer.
//! \param[in]  iOffsetInUint8  Offset in bytes to a u16 in that buffer.
//!
//! \retval int32_t             A u16 that was in buffer at offset iOffsetInUint8.
//!
////////////////////////////////////////////////////////////////////////////////
int32_t FSGetWord(uint8_t *buffer, int32_t iOffsetInUint8)
{
    int temp;
    temp = (((uint32_t)buffer[iOffsetInUint8]) | ((((uint32_t)buffer[iOffsetInUint8+1]) & 0xff) << 8));
    return temp;
}

////////////////////////////////////////////////////////////////////////////////
//! \brief      Returns a u32 from buffer.
//!
//! \fntype     Function
//!
//! As per the offset given this function returns u32 from buffer.
//!
//! \param[in]  buffer          Pointer to a buffer.
//! \param[in]  iOffsetInUint8  Offset in bytes to a u32 in that buffer.
//!
//! \retval int32_t             A u32 that was in buffer at offset iOffsetInUint8.
//!
////////////////////////////////////////////////////////////////////////////////
uint32_t FSGetDWord(uint8_t *buffer, int32_t iOffsetInUint8)
{
    uint32_t temp;
    temp = (((uint32_t)buffer[iOffsetInUint8]) | ((((uint32_t)buffer[iOffsetInUint8+1]) & 0xff) << 8) |
            ((((uint32_t)buffer[iOffsetInUint8+2]) & 0xff) << 16)  | ((((uint32_t)buffer[iOffsetInUint8+3]) & 0xff) << 24));
    return temp;
}

/*----------------------------------------------------------------------------
>  Function Name: void PutByte(uint8_t *buffer, uint8_t byte,int32_t Offset)

   FunctionType:  Function

   Inputs:        1) Pointer to buffer
                  2) byte
                  3) Offset

   Outputs:       None

   Description:   Puts byte into buffer at given offset.
<
----------------------------------------------------------------------------*/
void PutByte(uint8_t *buffer, uint8_t byte,int32_t Offset)
{
    buffer[Offset] = (uint8_t)(byte & 0xff);
}

/*----------------------------------------------------------------------------
>  Function Name: void PutWord(uint8_t *buffer, int32_t word, int32_t Offset)

   FunctionType:  Function

   Inputs:        1) Pointer to buffer
                  2) word
                  3) Offset

   Outputs:       None

   Description:   Puts word into byte buffer starting from given offset.
<
----------------------------------------------------------------------------*/
void PutWord(uint8_t *buffer, int32_t word, int32_t Offset)
{
    buffer[Offset] = (uint8_t)(word & 0xff);
    buffer[Offset+1] = (uint8_t)((word >> 8) & 0xff);
}

/*----------------------------------------------------------------------------
>  Function Name: void PutDword(uint8_t *buffer, int32_t dword, int32_t Offset)

   FunctionType:  Function

   Inputs:        1) Pointer to buffer
                  2) dword
                  3) Offset

   Outputs:       None

   Description:   Puts dword into byte buffer starting from given offset.
<
----------------------------------------------------------------------------*/
void PutDword(uint8_t *buffer, uint32_t dword, int32_t Offset)
{
    buffer[Offset] = (uint8_t)(dword & 0xff);
    buffer[Offset+1] = (uint8_t)((dword >> 8) & 0xff);
    buffer[Offset+2] = (uint8_t)((dword >> 16) & 0xff);
    buffer[Offset+3] = (uint8_t)((dword >> 24) & 0xff);
}

