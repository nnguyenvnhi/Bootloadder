/***********************************************************************************
**  PROJECT      : OTA_STM32                                                      **
**                                                                                **  
**  FILENAME     : Modbus_GenerationFrame                                         **
**                                                                                **
**  VERSION      : 1.0.0                                                          **
**                                                                                **
**  DATE         : 2022-05-02                                                     **
**                                                                                **
**  AUTHOR       : VAN NHi - NGUYEN                                               **
**                                                                                **
**  VENDOR       : @                                                              **
**                                                                                **
**  DESCRIPTION  : PROJECT HEADER FILE                                            **
**                                                                                **                                                                               
**  MAY BE CHANGED BY USER : NGUYEN VAN NHI                                       **
**                                                                                **
***********************************************************************************/
#include "Modbus_GenerationFrame.h"
uint16 *MG_GenerateFrame(uint8 Command, uint8* Content, uint8 ContentSize){
    uint16 *siData;
    uint16 siCount = 0;
    uint8** ucContent = &Content;
    CRCFrame CRC;
    
    *siData = SOF_VALUE; siCount++; siData++;
    *siData = Command; siCount++; siData++; 
    *siData = ContentSize; siCount++; siData++;

    for(int i = 0; i<ContentSize; i++){
        *siData = **ucContent;
        siData++;
        *ucContent++;
    }
    siCount+=ContentSize;

    uint16 siCRCWord = CRC16(siData, siCount);
    CRC.CRCContent = siCRCWord;
    *siData = CRC.CRC16_2Bytes[0];
    siCount++; siData++;
    *siData = CRC.CRC16_2Bytes[1];
    siCount++;
    siData++;

    *siData = EOF_VALUE; 
    siData++;
    siData -= siCount;

    return siData;
}
