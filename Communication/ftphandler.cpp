#include "ftphandler.h"

ftphandler::ftphandler()
{

}


int ftphandler::downloadFile(std::string servername,std::string username,std::string password,std::string remotefilename,std::string localfilepath)
{
    QNetworkAccessManager manager;


    sprintf(oururl,"ftp://%s:%s@%s/%s", username.c_str(), password.c_str(), servername.c_str(), remotefilename.c_str());
    QUrl url(oururl);
    url.setUserName(username.c_str());
    url.setPassword(password.c_str());

    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();


    if (reply->error() == QNetworkReply::NoError)
    {
       QFile file(QString::fromStdString(localfilepath));

        if (file.open(QIODevice::WriteOnly))
        {
            file.write(reply->readAll());
            file.close();

        }
        else
        {
            Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Failed to save file");
            return FILE_SAVE_ERROR;

        }
    }
    else
    {
        Logger::LOG(__FILE__, __FUNCTION__, __LINE__, LOG_TYPE::ERROR, "Download failed: %S", reply->errorString().toStdString().c_str());
        return FILE_DOWNLOAD_ERROR;

    }

    reply->deleteLater();

}
