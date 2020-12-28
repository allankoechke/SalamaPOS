#include "webapiinterface.h"

WebApiInterface::WebApiInterface(QObject *parent) : QObject(parent)
{

}

void WebApiInterface::onCheckForUpdates(const int &cVersion)
{
    // Q_UNUSED(cVersion)

    connect(&m_networkManager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply* pReply){

        QJsonDocument document = QJsonDocument::fromJson(pReply->readAll().data());
        QJsonObject rootObj = document.object();

        // qDebug() << "Received Data: " << document;

        if(cVersion < rootObj.value("version").toInt())
        {
            qDebug() << ">> New version is available";
            emit newVersionAvailable(rootObj);
        }

        // emit a signal on getting full data
        pReply->deleteLater();


    });

    QUrl url("https://bjgs657959.execute-api.us-east-2.amazonaws.com/default/checkUpdatesSalamaPOS");
    QNetworkRequest request(url);
    m_networkManager.get(request);
}

void WebApiInterface::onDownloadUpdate()
{

}

void WebApiInterface::onInstallUpdate()
{

}
