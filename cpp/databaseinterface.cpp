#include "databaseinterface.h"

DatabaseInterface::DatabaseInterface(QObject *parent) : QObject(parent)
{
    QFile file(":/json/db-credentials.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QString jsonString = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObj = doc.object();

    db_uname = jsonObj.value(QString("username")).toString();
    db_pswd = jsonObj.value(QString("password")).toString();
    db_name = jsonObj.value(QString("database")).toString();

}


bool DatabaseInterface::initializeDatabase()
{
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("localhost");
    m_db.setUserName(db_uname);
    m_db.setPassword(db_pswd);
    m_db.setDatabaseName(db_name);
    // Q_ASSERT(m_db.open());
    m_db.open();

    if(!m_db.isOpen())
    {
        qDebug() << "Couldn't open Db: " << m_db.lastError().text();
    }

    Q_ASSERT(m_db.isOpen());

    try {
        m_db.transaction();
        QSqlQuery query;
        QString sql;

        QFile file(":/sql/tables.sql");
        file.open(QIODevice::ReadOnly);
        sql = file.readAll();

        auto sql_segments = sql.split("--comment");

        // int index = 1;

        foreach (const QString &sql_str, sql_segments)
        {
            if(query.exec(sql_str))
            {
                // m_db.commit();
            }

            else
            {
                qDebug() << "Error executing : " << query.lastError().text();
            }

            // qDebug() << "Executing : " << index << "/" << sql_segments.size();
            // index ++;
        }

        if(m_db.isOpen())
            return true;

        else
        {
            qDebug() << "Error Creating Db: " << query.lastError().text();
            return false;
        }



    } catch (std::exception &e) {
        qDebug() << ">> Error executing SQL: " << e.what();
        return false;
    }

    return false;
}
