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
#include <exception>
#include <QFile>


class DatabaseInterface : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseInterface(QObject *parent = nullptr);
    ~DatabaseInterface();

    void initializeDatabase();


private slots:
    void addToDatabase(const QString &querry, const QVariantMap & map);

signals:
    void databaseStatusChanged(const bool & status);

    void databaseStatusChangedd();

public slots:
    void onDatabaseStatusChanged(const bool & status);

    void onDatabaseStatusChangedd();

    void onWriteToDbChanged(const QString & querry, const QJsonObject & json,const QVariantList & type);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEINTERFACE_H
