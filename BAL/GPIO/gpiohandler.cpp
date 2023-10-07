#include "gpiohandler.h"

GPIOHandler::GPIOHandler()
{

}


int GPIOHandler::gpioExport(unsigned int gpio)
{
    int fd, len;

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0)
    {
        Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Failed to open gpio export file");
        return FILE_OPEN_ERROR;
    }

    char buf[4];
    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return OK;
}


int GPIOHandler::gpioUnexport(unsigned int gpio)
{
    int fd, len;

    fd = open("/sys/class/gpio//unexport", O_WRONLY);
    if (fd < 0)
    {
        Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Failed to open gpio unexport file");
        return FILE_OPEN_ERROR;
    }

    char buf[4];
    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return OK;
}

int GPIOHandler::checkIfGpioExported(unsigned int gpio)
{
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);

    if(access(buf, F_OK) == -1)
        return GPIO_IS_NOT_EXPORTED;
    else
        return OK;
}

int GPIOHandler::gpioSetDir(unsigned int gpio, GPIO_DIR dir)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Failed to open gpio %d direction file", gpio);
        return FILE_OPEN_ERROR;
    }

    if (dir == GPIO_DIR::GPIO_OUTPUT)
        write(fd, "out", 4);
    else
        write(fd, "in", 3);

    close(fd);

    return OK;
}



int GPIOHandler::gpioSetValue(unsigned int gpio, unsigned int value)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);

    fd = open(buf, O_WRONLY);
    if (fd < 0)
    {
        Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Failed to open gpio %d value file", gpio);
        return FILE_OPEN_ERROR;
    }

    if (value == 1)
        write(fd, "1", 2);
    else
        write(fd, "0", 2);

    close(fd);

    return OK;
}



int GPIOHandler::gpioGetValue(unsigned int gpio, unsigned int *value)
{
    int fd;
    char buf[64];
    char readValue;

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);

    fd = open(buf, O_RDONLY);
    if (fd < 0)
    {
        Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Failed to open gpio %d value file", gpio);
        return FILE_OPEN_ERROR;
    }

    read(fd, &readValue, 1);

    if (readValue == '0')
        *value = 0;
    else
        *value = 1;

    close(fd);

    return OK;
}


int GPIOHandler::digitalOutputSetValue(unsigned int pinNumber, bool value)
{
    if(checkIfGpioExported(pinNumber) != OK)
    {
        gpioExport(pinNumber);
    }

    if(gpioSetDir(pinNumber, GPIO_DIR::GPIO_OUTPUT) == OK)
    {
        if(value == true)
        {
          if(gpioSetValue(pinNumber, 1) == OK)
              return OK;
          else
              return GPIO_SET_VALUE_ERROR;
        }
        else
        {
          if(gpioSetValue(pinNumber, 0) == OK)
              return OK;
          else
              return GPIO_SET_VALUE_ERROR;
        }
    }
    else
        return GPIO_SET_VALUE_ERROR;

    return OK;
}

int GPIOHandler::digitalInputGetValue(unsigned int pinNumber, bool* value)
{
    unsigned int inputValue = 0;
    if(checkIfGpioExported(pinNumber) != OK)
    {
        gpioExport(pinNumber);
    }

    if(gpioSetDir(pinNumber, GPIO_DIR::GPIO_INPUT) == OK)
    {
        if(gpioGetValue(pinNumber, &inputValue) == OK)
        {
            if (inputValue == 0)
                *value = false;
            else
                *value = true;
        }
        else
            return GPIO_GET_VALUE_ERROR;
    }
    else
        return GPIO_GET_VALUE_ERROR;

    return OK;
}
