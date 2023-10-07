#include "uart.h"

Uart::Uart()
{
    serialPortFd = 0;
}
int Uart::serialOpenPort(char* portName, int baudRate)
{

    if (serialPortFd >=0)
        serialClosePort();


    serialPortFd = open(portName, O_RDWR);
    if(serialPortFd < 0)
    {
        return SERIAL_PORT_OPEN_ERROR;
    }

    struct termios tty;

    if (tcgetattr(serialPortFd, &tty) < 0)
    {
        return SERIAL_PORT_OPEN_ERROR;
    }

    cfsetospeed(&tty, baudRate);
    cfsetispeed(&tty, baudRate);

    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;                 /* 8-bit characters */
    tty.c_cflag &= ~PARENB;             /* no parity bit */
    tty.c_cflag &= ~CSTOPB;             /* only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;            /* no hardware flowcontrol */

    /* setup for non-canonical mode */
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;

    /* fetch bytes as they become available */
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;

    if (tcsetattr(serialPortFd, TCSANOW, &tty) != 0)
    {
        return errno;
    }

    return OK;
}


int Uart::serialClosePort()
{
    if (serialPortFd >=0)
    {
        close(serialPortFd);
        serialPortFd = -1;
    }
    return OK;
}



int Uart::serialWrite(char* writeData, int size)
{
    if(write(serialPortFd, writeData, size) < size)
    {
        return SERIAL_PORT_WRITE_ERROR;
    }
    return OK;
}

int Uart::serialRead(char* readData, int readDataSize, int* outlen, int timeout /* ms */)
{
    fd_set set;
    struct timeval t;

    t.tv_sec = timeout / 1000;
    t.tv_usec = (timeout % 1000) * 1000;

    if(readDataSize > MAX_SERIAL_READ_BUFFER)
        return SERIAL_PORT_MAX_BUFFER_READ_SIZE_ERROR;

    FD_ZERO(&set);  /* clear the set */
    FD_SET(serialPortFd, &set); /* add our file descriptor to the set */

    if(select(serialPortFd + 1, &set, nullptr, nullptr, &t) > 0)
    {
        if (FD_ISSET(serialPortFd, &set))
        {
            *outlen = read(serialPortFd, readData, readDataSize);
        }
    }
    else
    {
        return SERIAL_PORT_TIMEOUT_ERROR;
    }
    return OK;
}
