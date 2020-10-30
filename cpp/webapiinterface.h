#ifndef WEBAPIINTERFACE_H
#define WEBAPIINTERFACE_H

#include <QObject>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class WebApiInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebApiInterface(QObject *parent = nullptr);

public slots:
    void onCheckForUpdates(const int &cVersion);

    void onDownloadUpdate();

    void onInstallUpdate();

signals:
    void newVersionAvailable(const QJsonObject &json);

private:
    QNetworkAccessManager m_networkManager;
};

#endif // WEBAPIINTERFACE_H
