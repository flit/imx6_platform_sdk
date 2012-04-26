#include "handletable.h"
#include "os/filesystem/fat/include/devicetable.h"
#include "os/filesystem/os_filesystem_errordefs.h"
#include "os/filesystem/fsproj.h"
#include "drivers/media/ddi_media.h"
#include "filespec.h"

extern int g_FSinitErrorCode;
extern int32_t gCurrentRecord;
extern HandleTable_t *Handle;
extern FileSystemMediaTable_t *MediaTable;
extern FileSpecs_t * FileSpec;
extern uint8_t gCurrentWorkingdirectory[];
extern const uint8_t Short_NameRes_Ch[];  
extern const uint8_t Long_NameRes_Ch[];
extern const uint8_t DriveLetter[];

// Media cache wrappers.
RtStatus_t FSWriteSector(int32_t deviceNumber, int32_t sectorNumber, int32_t destOffset, uint8_t * sourceBuffer, int32_t sourceOffset, int32_t numBytesToWrite, int32_t writeType);
RtStatus_t FSWriteSector_BypassCache(int32_t deviceNumber, int32_t sectorNumber, int32_t destOffset, uint8_t * sourceBuffer, int32_t sourceOffset, int32_t numBytesToWrite, int32_t writeType);
RtStatus_t FSEraseSector(int32_t deviceNumber, int32_t sectorNumber);
int32_t * FSReadSector(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, uint32_t * token);
int32_t * FSReadSector_BypassCache(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, uint8_t *pBuffer, uint32_t * token);
RtStatus_t FSReleaseSector(uint32_t token);
RtStatus_t FSFlushSector(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, int32_t ix, int32_t * writeFlag);

// Function Prototypes.
RtStatus_t CreateDirectory(int32_t HandleNumber,uint8_t *Filepath,int32_t length,int32_t index,int32_t stringtype);                                     
RtStatus_t Handleactive(int32_t HandleNumber);
RtStatus_t ReadRootdirRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer);
RtStatus_t Freehandle(int32_t HandleNumber);
RtStatus_t GetChar(uint8_t *Buffer,int32_t *offset);
void PutChar(uint8_t *Buffer,int32_t *offset,int32_t Char);
RtStatus_t SetcurrentPos(int32_t HandleNumber,int32_t RecordNumber);
RtStatus_t DiscardTrailigPeriodsw(uint8_t *Buffer,int32_t length,int32_t index);
RtStatus_t DiscardTrailigPeriods(uint8_t *Buffer,int32_t length,int32_t index,int32_t flag);
RtStatus_t Strcpyw(uint8_t *filepath, uint8_t *file_path1,int32_t length, int32_t index);
RtStatus_t IsShortNameValid(uint8_t *Buffer,int32_t length,int32_t index);
RtStatus_t Strcpy(uint8_t *filepath, uint8_t *file_path1,int32_t length, int32_t index);
void Setshortfilename(int32_t HandleNumber,uint8_t *Buffer,uint8_t *shortfilename);
RtStatus_t FindfreeRecord(int32_t Handlenumber,int32_t count);
int32_t CheckspaceinRootdir(int32_t Handlenumber,int32_t count);
void ArrangeFileName(uint8_t *Buffer,uint8_t *ShortFileName);
RtStatus_t ArrangeLongFileName(int32_t HandleNumber,uint8_t *filename,int32_t count,int32_t chksum);
RtStatus_t ChkSum(uint8_t *filename);

RtStatus_t CreateShortDirRecord
(
  uint8_t *filename,
  int32_t HandleNumber,
  int32_t ClusterNumber,
  int32_t DirAttr,
  int32_t FileSize
);

RtStatus_t Getname(uint8_t *filepath, int32_t currentPosition);
RtStatus_t GetnameW(uint8_t *filepath,int32_t currentPosition);
RtStatus_t GetNewcluster(int32_t Handlenumber);
RtStatus_t ClearCluster(int32_t HandleNumber);

int32_t ClearCluster_GrowFile(int32_t HandleNumber);

RtStatus_t FindNextSector(int32_t Device,int32_t HandleNumber);
int32_t Findnextcluster(int32_t DeviceNum,int32_t clusterno);
int32_t Firstsectorofcluster(int32_t DeviceNum,int32_t clusterno);
RtStatus_t Changecase(int32_t wordno);
RtStatus_t Shortdirmatch(int32_t HandleNumber,int32_t RecordNo,uint8_t *shortname,uint8_t *file,uint8_t *buf,int32_t Flag,
                                          int32_t lenght,int32_t index,uint8_t *Buffer);
RtStatus_t Longdirmatch(int32_t HandleNumber,int32_t RecordNo,uint8_t *file,int32_t length,int32_t index,int32_t stringtype);
void UnicodeToOEM(uint8_t *file,uint8_t *shortname,int32_t length,int32_t index);
void Uppercase(uint8_t *file);
int32_t Searchdirectory(int32_t HandleNumber,uint8_t *file,int32_t stringtype,int32_t Flag,int32_t length,int32_t index,uint8_t *Buffer,bool bSearchFlag,int32_t *pLastRecordnum);
RtStatus_t Convert_itoa(int32_t Number,uint8_t *string);
void Setfilename(uint8_t *buf, uint8_t *buffer_1);
RtStatus_t UpdateHandle(int32_t HandleNumber,int32_t clusterno);
RtStatus_t SetHandleforsearch(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype,int32_t *index);
RtStatus_t Changepath(int32_t HandleNumber,uint8_t *filepath,int32_t stringtype,int32_t startposition,int32_t index);
RtStatus_t Extractfilename(uint8_t *filepath,int32_t length, int32_t *index);
int32_t ExtractPath(uint8_t *filepath,int32_t *index);
int32_t ExtractPathW(uint8_t *filepath,int32_t *index);
RtStatus_t FlushSector(int32_t deviceNumber, int32_t sectorNumber,int32_t WriteType,int32_t ix,int32_t *pi32WriteFlag);

RtStatus_t Searchfreehandleallocate(void);
RtStatus_t Isdirectoryempty( int32_t Handlenumber);
RtStatus_t DeleteRecord(int32_t HandleNumber, int32_t RecordNo);
RtStatus_t DeleteContent(int32_t HandleNumber, int32_t bUseVestigialClusterEraser);
RtStatus_t Fcreate(int32_t HandleNumber,uint8_t *FileName,int32_t stringtype,int32_t length,int32_t index);
RtStatus_t Updatehandlemode(int32_t HandleNumber,int32_t Mode);
int32_t Gethandlemode(int32_t HandleNumber);
RtStatus_t IsHandleWriteAllocated(int32_t HandleNumber);
RtStatus_t UpdateFileSize(int32_t HandleNumber,int32_t flag);
RtStatus_t Extractfilenamew(uint8_t *filepath, int32_t *index);
RtStatus_t Isfileopen(int32_t HandleNumber);
RtStatus_t UpdateHandleOffsets(int32_t HandleNumber);

int32_t FATsectorno(int32_t DeviceNum,int32_t clusterno,int32_t *FATNtryoffset);
uint8_t *ReadFAT12Entry(int32_t DeviceNum,int32_t *FATsectorNo,int32_t FATntryoffset,int32_t clusterNum,uint8_t *buf,int32_t *FATentry, uint32_t * cacheToken);
RtStatus_t WriteFATentry(int32_t DeviceNum,int32_t FATsector,int32_t FATNtryoffset,int32_t clusterno,int32_t writentry);
uint8_t *FirstfreeAndallocateFAT32(int32_t DeviceNum,int32_t FATsectrono,int32_t FAToffset ,uint8_t *buf, int32_t *ClusterNo, uint32_t cacheToken);
int32_t ReadFATentry(int32_t Devicenum,int32_t FATsector,int32_t FATNtryoffset,int32_t clusterno);
int32_t FindnextFreecurrentcluster(int32_t DeviceNum,int32_t clusterno);
int32_t FirstfreeAndallocate(int32_t DeviceNum);
RtStatus_t firstfreeandallocate_ClearAllocationsForDevice( int32_t DeviceNum );

RtStatus_t GetUnicodeWord(uint8_t *Buffer,int32_t LFNOffset);
RtStatus_t IsCurrWorkDir(int32_t HandleNumber);
RtStatus_t MatchdirRecordW(int32_t HandleNumber,int32_t RecordNo, uint8_t *file,uint8_t *buf,int32_t index,int32_t length,uint8_t *Shortnamebuf);
RtStatus_t ChangeToRootdirectory(int32_t HandleNumber);
int32_t Totalfreecluster(int32_t DeviceNum);
int32_t TotalfreeclusterFAT16(int32_t DeviceNum);

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
);

int32_t Fread_BypassCache(int32_t i32HandleNumber, uint8_t *pBuffer, int32_t i32NumBytesToRead);
                         
int32_t Extractdirnamew(uint8_t *filepath,int32_t strlength,int32_t *index);
RtStatus_t SetcwdW(uint8_t *filepath, uint8_t *gCworkingDir,int32_t index,int32_t length);

void EnterNonReentrantSection(void);
void LeaveNonReentrantSection(void);

int64_t ReadDirectoryRecord(int32_t HandleNumber,int32_t RecordNumber,uint8_t *Buffer);

void FSClearDriveBuf(int DriveNumber, int maxhandles);

RtStatus_t Cleardevicerecord(int32_t DeviceNum);
RtStatus_t GetDeviceFromHandle(int32_t HandleNumber, int32_t *pDeviceNumber);

int         Readdevicerecord(int Device,int32_t sectornum);
int         FileSystemPresent(int Device);
RtStatus_t  FileSystemBootSectorVerify( uint8_t* buf );

void SeekPoint_InitializeBuffer(int32_t HandleNumber);
