#include "processinterface.h"

ProcessInterface::ProcessInterface(QObject *parent) : QObject(parent)
{
    process = new QProcess(this);

    connect(process, &QProcess::readyReadStandardOutput, this, &ProcessInterface::_readyRead);
    connect(process, &QProcess::readyReadStandardError, this, &ProcessInterface::_readyReadError);
//    connect(process, &QProcess::finished, [=](int exitCode, QProcess::ExitStatus exitStatus)
//    {
//        emit finished(exitCode, exitStatus);
//    });
}

ProcessInterface::~ProcessInterface()
{
    delete process;
}

void ProcessInterface::execute(const QString &path)
{
    qDebug() << "Starting local backup!";

    QStringList args;

    args << m_args;
    args << path;

    process->start(m_command, args);

    qDebug() << "Waiting for finished!";

    process->waitForFinished(3000);

    qDebug() << "Ending local backup";
}

void ProcessInterface::_readyRead()
{
    auto bt = process->readAllStandardOutput();
    QString  data(bt);

    qDebug() << "Reading output data: " << data;
    emit readyRead(data);
}

void ProcessInterface::_readyReadError()
{
    auto bt = process->readAllStandardError();
    QString  _error(bt);

    qDebug() << "Reading error data: " << _error;

    emit readyReadError(_error);
}
