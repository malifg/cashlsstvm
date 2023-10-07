QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BAL/GPIO/gpiohandler.cpp \
    BAL/UART/uart.cpp \
    Communication/ftphandler.cpp \
    Communication/updatemanager.cpp \
    HAL/HS_K24/hs_k24.cpp \
    PrinterManager/printerhandler.cpp \
    Utilities/Logger.cpp \
    Utilities/filesystem.cpp \
    Utilities/utils.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BAL/GPIO/gpiohandler.h \
    BAL/UART/uart.h \
    Communication/ftphandler.h \
    Communication/updatemanager.h \
    HAL/HS_K24/hs_k24.h \
    PrinterManager/logo.h \
    PrinterManager/printerhandler.h \
    Utilities/Logger.h \
    Utilities/common.h \
    Utilities/constants.h \
    Utilities/filesystem.h \
    Utilities/singleton.h \
    Utilities/threading.h \
    Utilities/utils.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
