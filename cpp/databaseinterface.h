#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariantMap>
#include <QSqlDatabase>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <exception>
#include <QFile>
#include <QDate>


class DatabaseInterface : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseInterface(QObject *parent = nullptr);

    bool initializeDatabase();

signals:

public slots:

private:
    QString db_pswd, db_name, db_uname;
};

#endif // DATABASEINTERFACE_H
