#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QRect>
#include <QScreen>
#include <QJsonDocument>
#include <QJsonObject>
#include <QGuiApplication>

#include "databaseinterface.h"
#include "serialportinterface.h"
#include "webapiinterface.h"
#include "websocketsinterface.h"

class QmlInterface : public QObject
{
    Q_OBJECT

public:
    explicit QmlInterface(QObject *parent = nullptr);

    Q_INVOKABLE QJsonObject getScreenSize();

signals:
    void databaseReadyChanged();

private slots:

private:
    DatabaseInterface * m_databaseInterface;

};

#endif // QMLINTERFACE_H
