#include "webapiinterface.h"

WebApiInterface::WebApiInterface(QObject *parent) : QObject(parent)
{

}

void WebApiInterface::onCheckForUpdates()
{
    connect(&m_networkManager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply* pReply){

        QByteArray m_DownloadedData = pReply->readAll();

        // emit a signal on getting full data
        pReply->deleteLater();
        // emit downloaded();

        // QFile file;
        // file.

    });

    QUrl url("https://drive.google.com/file/d/1kseo2G8RS06mRR-4CZDqIcEY-yPDERZn/view?usp=sharing");
    QNetworkRequest request(url);
    m_networkManager.get(request);



}

void WebApiInterface::onDownloadUpdate()
{

}

void WebApiInterface::onInstallUpdate()
{

}
