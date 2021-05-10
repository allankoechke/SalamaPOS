#ifndef PROCESSINTERFACE_H
#define PROCESSINTERFACE_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class ProcessInterface : public QObject
{
    Q_OBJECT
public:
    explicit ProcessInterface(QObject *parent = nullptr);
    ~ProcessInterface();

    Q_PROPERTY(QString authorize MEMBER m_authorize NOTIFY authorizeChanged)
    Q_PROPERTY(QString command MEMBER m_command NOTIFY commandChanged)
    Q_PROPERTY(QString args MEMBER m_args NOTIFY argsChanged)

    Q_INVOKABLE void execute(const QString &path);

signals:
    void error(QString error);

    void readyRead(QString data);

    void finished(int exitCode, QProcess::ExitStatus exitStatus);

    void readyReadError(QString error);

    void authorizeChanged(QString authorize);

    void commandChanged(QString command);

    void argsChanged(QString args);

private slots:
    void _readyRead();

    void _readyReadError();

private:
    QString m_authorize;
    QString m_command;
    QString m_args;
    QProcess * process;
};

#endif // PROCESSINTERFACE_H
