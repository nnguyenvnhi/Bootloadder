#ifndef _MODBUS_GENERATIONFRAME_H
#define _MODBUS_GENERATIONFRAME_H

#include "Std_Types.h"
#include "CRC32.h"
#define START_COMMAND 0x01
#define STOP_COMMAND 0x02
#define HEADER_COMMAND 0x03
#define DATA_COMMAND 0x04
#define RESPONSE_COMMAND 0x05
#define SOF_VALUE 0x3A
#define EOF_VALUE 0x00


typedef union{
    uint8 CRC16_2Bytes[2];
    uint16 CRCContent;
}CRCFrame;

uint16 *MG_GenerateFrame(uint8 Command, uint8* Content, uint8 ContentSize);
uint16 *MG_GenerateStartFrame(uint8 Command, uint8* Content, uint8 ContentSize);
uint16 *MG_GenerateStopFrame(uint8 Command, uint8* Content, uint8 ContentSize);
uint16 *MG_GenerateDataFrame(uint8 Command, uint8* Content, uint8 ContentSize);
uint16 *MG_GenerateResponseFrame(uint8 Command, uint8* Content, uint8 ContentSize);
uint16 *MG_GenerateHeaderFrame(uint8 Command, uint8* Content, uint8 ContentSize);

#endif