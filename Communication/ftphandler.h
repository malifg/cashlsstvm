#ifndef FTPHANDLER_H
#define FTPHANDLER_H


#include <QCoreApplication>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include "Utilities/Logger.h"
#include <stdio.h>


#define FILE_SAVE_ERROR        7
#define FILE_DOWNLOAD_ERROR    8



class ftphandler
{
public:
    ftphandler();


    int downloadFile(std::string servername,std::string username,std::string password,std::string remotefilename,std::string localfilepath);
    char oururl[256];

};

#endif // FTPHANDLER_H
