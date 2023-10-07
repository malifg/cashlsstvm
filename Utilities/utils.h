#ifndef UTILS_H
#define UTILS_H

#include "Utilities/common.h"
#include "Utilities/singleton.h"
#include "Utilities/constants.h"
#include "Utilities/filesystem.h"
#include "Utilities/threading.h"
#include "Utilities/Logger.h"


class Utils : public Singleton<Utils>
{
private:


public:
    Utils();

};

#endif // UTILS_H
