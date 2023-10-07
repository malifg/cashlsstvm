#ifndef GPIOHANDLER_H
#define GPIOHANDLER_H

#include <Utilities/utils.h>

enum GPIO_DIR
{
    GPIO_OUTPUT                 = 0x01,
    GPIO_INPUT                  = 0x02
};

class GPIOHandler : public Singleton<GPIOHandler>
{
public:
    GPIOHandler();
    int digitalOutputSetValue(unsigned int pinNumber, bool value);
    int digitalInputGetValue(unsigned int pinNumber, bool* value);
    int gpioUnexport(unsigned int gpio);


private:
    int gpioExport(unsigned int gpio);
    int checkIfGpioExported(unsigned int gpio);
    int gpioSetDir(unsigned int gpio, GPIO_DIR dir);
    int gpioSetValue(unsigned int gpio, unsigned int value);
    int gpioGetValue(unsigned int gpio, unsigned int *value);

};

#endif // GPIOHANDLER_H
