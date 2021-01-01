#ifndef WEBAPIINTERFACE_H
#define WEBAPIINTERFACE_H

#include <QObject>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QRunnable>
#include <QtNetwork>
#include <QThreadPool>

class WebApiInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebApiInterface(QObject *parent = nullptr);

    ~WebApiInterface()
    {
        delete checkConnectivityTimer;
    }

public slots:
    void onCheckForUpdates(const int &cVersion);

    void onDownloadUpdate();

    void onInstallUpdate();

    void onWebRunnableFinished(const QString &str);

    void connect2Web(const QString &state, const QJsonObject &data);

    void onCheckConnectivityTimerTimeout();

signals:
    void newVersionAvailable(const QJsonObject &json);

private:
    QNetworkAccessManager m_networkManager;

    QThreadPool m_ThreadPool;

    QTimer *checkConnectivityTimer;

    bool hasPendingWebRequestForConnectivity = false;
};


class WebInterfaceRunnable :public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit WebInterfaceRunnable(QObject * parent = nullptr);

    void setValues(const QString &state, const QJsonObject &data);

    void run();

signals:
    void finished(QString reply);

private:
    QString m_token,m_url, m_state;
    QJsonObject m_data;
};
#endif // WEBAPIINTERFACE_H
