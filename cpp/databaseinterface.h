#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlQuery>
#include <QVariantMap>
#include <QSqlDatabase>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QFile>


class DatabaseInterface : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseInterface(QObject *parent = nullptr);

    void initializeDatabase();


private slots:
    void addToDatabase(const QString &querry, const QVariantMap & map);

signals:
    void databaseStatusChanged(const bool & status);

    void databaseStatusChangedd();

public slots:
    void onDatabaseStatusChanged(const bool & status);

    void onDatabaseStatusChangedd();

private:
    QSqlDatabase m_db;
};

#endif // DATABASEINTERFACE_H
