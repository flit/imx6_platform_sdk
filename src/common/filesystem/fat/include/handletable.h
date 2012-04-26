#ifndef _HANDLE_TABLE_H_

#define _HANDLE_TABLE_H_

#include <types.h>
#include "fstypes.h"

#define NUM_SEEKPOINTS_CACHED 10

// Propagate changes to this table to the appropriate structure in fstypes.h
// In this case, the HANDLEENTRYSIZE should be updated.

typedef struct
{
uint8_t HandleActive;
int8_t  Device;
uint8_t Mode;
int32_t StartingCluster;
int32_t CurrentOffset;
int32_t CurrentCluster;
int32_t CurrentSector;
int32_t BytePosInSector;
uint8_t SectorPosInCluster;
int32_t DirSector;
int32_t DirOffset;
int32_t ErrorCode;
int32_t FileSize;
int32_t SeekPointsClusters[NUM_SEEKPOINTS_CACHED]; 
int32_t SeekPointsClusterStep;      // the cluster step in the SeekPoint cluster buffer
int32_t SeekPointsBaseFileSize;     //The file size based to calculate SeekPointsClusterStep.
                                    // We need this because file size will change with mode "w+"

}HandleTable_t;

#endif // !_HANDLE_TABLE_H_
