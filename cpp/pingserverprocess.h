#ifndef PINGSERVERPROCESS_H
#define PINGSERVERPROCESS_H

#include <QObject>
#include <QTimer>
#include <QProcess>
#include <QDebug>

class PingServerProcess : public QObject
{
    Q_OBJECT
public:
    explicit PingServerProcess(QObject *parent = nullptr);

    ~PingServerProcess()
    {
        m_pingProcess.terminate();
    }

    /// \brief  Starts a ping check in a loop
    /// \param[in]  urlToPing   The url that needs to be pinged continuously
    /// \param[in]  pingInterval    Interval (in seconds) at which specified url must be pinged
    void startPingCheck(const int& pingIntervalInSecs = 5);

signals:
    /// \brief  Signal emitted when pinging of specified url fails
    void pingFailed();

    /// \brief Signal to emit network connection state
    void connectionStatusChanged(bool is_connected);

public slots:
    /// \brief  Slot called periodically to ping specified url
    void onStartPing();

    /// \brief  Slot called when ping process returns a message
    void onPingFinished();

private:
    /// \brief  Timer used to ping repeatedly
    QTimer m_pingTimer;

    /// \brief  Ping process
    QProcess m_pingProcess;

    /// \brief  Pinged url
    QString m_pingUrl;

    /// \brief Boolean to hold state of the network internal connection
    bool isWaitingConnection=false, isConnected=false;
};

#endif // PINGSERVERPROCESS_H
