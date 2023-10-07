#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define OK                                              0
#define SERIAL_PORT_OPEN_ERROR                          2
#define SERIAL_PORT_WRITE_ERROR                         3
#define SERIAL_PORT_MAX_BUFFER_READ_SIZE_ERROR          4
#define SERIAL_PORT_TIMEOUT_ERROR                       5


#define MAX_SERIAL_READ_BUFFER                          256


class Uart
{
public:
    Uart();
    int serialOpenPort(char* portName, int baudRate);
    int serialClosePort();
    int serialRead(char* readData, int readDataSize, int* outlen, int timeout /* ms */);
    int serialWrite(char* writeData, int size);


private:
    int serialPortFd;


};

#endif // UART_H
