#ifndef WEBAPIINTERFACE_H
#define WEBAPIINTERFACE_H

#include <QObject>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class WebApiInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebApiInterface(QObject *parent = nullptr);

public slots:
    void onCheckForUpdates();

    void onDownloadUpdate();

    void onInstallUpdate();

signals:

private:
    QNetworkAccessManager m_networkManager;
};

#endif // WEBAPIINTERFACE_H
