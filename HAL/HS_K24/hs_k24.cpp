#include "hs_k24.h"

HS_K24::HS_K24()
{

}

int HS_K24::cutPaper(PAPER_CUT cutType)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmd[3] = {0x1D, 0x56, 0x00};
    if (cutType == PAPER_FULL_CUT)
        cmd[2] = 0x00;
    else
        cmd[2] = 0x01;
    if (printerUart.serialWrite(cmd, 3) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;

}

int HS_K24::feedPaper(unsigned int lineCount)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmd[3] = {0x1B, 0x64, 0x00};
    cmd[2] = lineCount;
    if (printerUart.serialWrite(cmd, 3) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}

int HS_K24::printString(char *inputString, int size)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char* cmdString = inputString;
    if (printerUart.serialWrite(cmdString, size) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdPrint[1] = {0x0A};
    if (printerUart.serialWrite(cmdPrint, 1) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}

int HS_K24::printQR(char *inputQR, int size)
{
    if (size != 128)
        return PRINTER_QR_CODE_SIZE_ERROR;

    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmdInit[2] = {0x1B, 0x40};
    if (printerUart.serialWrite(cmdInit, 2) != OK)
            return PRINTER_SEND_COMMAND_ERROR;

    char cmdModelType[8] = {0x1D, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x43, 0x00};
    cmdModelType[7] = QR_CODE_SIZE;
    if (printerUart.serialWrite(cmdModelType, 8) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdECC[8] = {0x1D, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x45, 0x00};
    cmdECC[7] = QR_CODE_ECC;

    if (printerUart.serialWrite(cmdECC, 8) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdSetQRCodeData[8] = {0x1D, 0x28, 0x6b, 0x00, 0x00, 0x31, 0x50, 0x30};
    cmdSetQRCodeData[3] = size+3;

    if (printerUart.serialWrite(cmdSetQRCodeData, 8) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char* cmdDataQR = inputQR;
    if (printerUart.serialWrite(cmdDataQR, size) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdCenterQR[3] ={0x1B, 0x61, 0x01};
    if (printerUart.serialWrite(cmdCenterQR, 3) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdPrintQR[8] = {0x1D, 0x28, 0x6B, 0x03, 0x00, 0x31, 0x51, 0x30};
    if (printerUart.serialWrite(cmdPrintQR, 8) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;

}

int HS_K24::setAlignment(PRINTER_ALIGNMENT alignType)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmdAlignmentChange[3] = {0x1B, 0x61, 0x00};
    if (alignType == ALIGN_RIGHT)
        cmdAlignmentChange[2] = 0x02;
    else if (alignType == ALIGN_CENTER)
        cmdAlignmentChange[2] = 0x01;
    else if (alignType == ALIGN_LEFT)
        cmdAlignmentChange[2] = 0x00;
    if (printerUart.serialWrite(cmdAlignmentChange, 3) != OK)
            return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}

int HS_K24::printReverseColorString(char *inputString, int size)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmdReverseColor[3] = {0x1D, 0x42, 0x01};
    if (printerUart.serialWrite(cmdReverseColor, 3) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char* cmdString = inputString;
    if (printerUart.serialWrite(cmdString, size) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdPrint[1] = {0x0A};
    if (printerUart.serialWrite(cmdPrint, 1) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    char cmdBackToBaseColor[3] = {0x1D, 0x42, 0x00};
    if (printerUart.serialWrite(cmdBackToBaseColor, 3) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}

int HS_K24::setPersianCodeTable()
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmdSetPersianCodeTable[5] = {0x1C, 0x2E, 0x1B, 0x74, 0x14};
    if (printerUart.serialWrite(cmdSetPersianCodeTable, 5) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}

int HS_K24::setLineSpacing(unsigned int per0125mm)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
        return PRINTER_OPEN_PORT_ERROR;

    char cmdSetLineSpacing[3] = {0x1B, 0x33, 0x00};
    cmdSetLineSpacing[2] = per0125mm;
    if (printerUart.serialWrite(cmdSetLineSpacing, 3) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}

int HS_K24::printBitmap(char *inputBitmap, int sizeV)
{
    if (printerUart.serialOpenPort(PORT_HS_K24_PRINTER, 115200) != OK)
         return PRINTER_OPEN_PORT_ERROR;

    char cmdPrintWithMoreHeating[5] ={0x1B, 0x37, 0x09, 0x64, 0x02};
    if (printerUart.serialWrite(cmdPrintWithMoreHeating, 5) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    for (int i=0; i<sizeV; i++)
    {
       char cmdBitmapSetting[4] = {0x12, 0x56, 0x00, 0x00};
       cmdBitmapSetting[2] = 0x01;
       if (printerUart.serialWrite(cmdBitmapSetting, 4) != OK)
           return PRINTER_SEND_COMMAND_ERROR;

       char cmdBitmapData[48];
       for (int j=0; j<48; j++)
       {
           cmdBitmapData[j] = inputBitmap[48*i+j];
       }
       if (printerUart.serialWrite(cmdBitmapData, 48) != OK)
           return PRINTER_SEND_COMMAND_ERROR;
    }

    char cmdPrintWithRegularHeating[5] ={0x1B, 0x37, 0x09, 0x50, 0x02};
    if (printerUart.serialWrite(cmdPrintWithRegularHeating, 5) != OK)
        return PRINTER_SEND_COMMAND_ERROR;

    if (printerUart.serialClosePort() != OK)
        return PRINTER_CLOSE_PORT_ERROR;

    return OK;
}
