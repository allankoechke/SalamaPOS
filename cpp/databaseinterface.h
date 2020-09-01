#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QObject>
#include <QSqlQuery>
#include <QVariantMap>
#include <QSqlDatabase>


class DatabaseInterface : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseInterface(QObject *parent = nullptr);

private slots:
    void addToDatabase(const QString &querry, const QVariantMap & map);

signals:
    void databaseStatusChanged(const bool & status);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEINTERFACE_H
