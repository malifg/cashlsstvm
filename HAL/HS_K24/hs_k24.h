#ifndef HS_K24_H
#define HS_K24_H

#include <Utilities/utils.h>
#include <BAL/UART/uart.h>

#define PORT_HS_K24_PRINTER             "/dev/ttyUSB0"
#define PRINTER_OPEN_PORT_ERROR         1000
#define PRINTER_SEND_COMMAND_ERROR      1001
#define PRINTER_CLOSE_PORT_ERROR        1002
#define PRINTER_QR_CODE_SIZE_ERROR      1003
#define QR_CODE_SIZE                    4
#define QR_CODE_ECC                     50
enum PAPER_CUT
{
    PAPER_FULL_CUT = 0,
    PAPER_SEMI_CUT = 1
};

enum PRINTER_ALIGNMENT
{
    ALIGN_RIGHT = 0,
    ALIGN_CENTER = 1,
    ALIGN_LEFT = 2
};

class HS_K24
{
public:
    HS_K24();
    int cutPaper(PAPER_CUT cutType);
    int feedPaper(unsigned int lineCount);
    int setLineSpacing(unsigned int per0125mm);
    int printString(char* inputString, int size);
    int printReverseColorString(char* inputString, int size);
    int printQR(char* inputQR, int size);
    int printBitmap(char* inputBitmap, int sizeV);
    int setAlignment(PRINTER_ALIGNMENT alignType);
    int setPersianCodeTable();

private:
    Uart printerUart;
};

#endif // HS_K24_H
