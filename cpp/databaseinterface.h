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

    ~DatabaseInterface();

    void initializeDatabase();

    QSqlDatabase getDb();

signals:
    void databaseStatusChanged(const bool & status);

    void databaseStatusChangedd();

    void databaseReady();

public slots:

private:
    QSqlDatabase m_db;
};

#endif // DATABASEINTERFACE_H
