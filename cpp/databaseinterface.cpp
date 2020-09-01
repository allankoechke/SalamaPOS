#include "databaseinterface.h"

DatabaseInterface::DatabaseInterface(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("localhost");
    m_db.setUserName("postgres");
    m_db.setPassword("postgresdb");
    bool status = m_db.open();

    Q_ASSERT(status);
    emit databaseStatusChanged(status);
}

void DatabaseInterface::addToDatabase(const QString &querry, const QVariantMap &map)
{
    QSqlQuery m_query;
    m_query.prepare(querry);

    if(map.count() != 0)
    {
        for(int i=0; i<map.count(); i++)
        {
            //m_query.bindValue(":", map.value(i));
        }
    }
    //m_query.bindValue(":id", 1001);
    //m_query.bindValue(":name", "Thad Beaumont");
    //m_query.bindValue(":salary", 65000);
    m_query.exec();
}
