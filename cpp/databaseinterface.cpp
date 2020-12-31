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

    /*
    QSqlDatabase db = QSqlDatabase::database("setDb");
    db = db.addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName(db_uname);
    db.setPassword(db_pswd);
    db.setDatabaseName("postgres");
    db.open();

    if(!db.isOpen())
    {
        qDebug() << "Couldn't open Db: " << db.lastError().text();
    }

    Q_ASSERT(db.isOpen());

    QSqlQuery query;
    QString sql, createDb = "CREATE DATABASE salama WITH OWNER = postgres ENCODING = 'UTF8' CONNECTION LIMIT = -1;";

    if(query.exec(createDb))
    {
        qDebug() << "Database Created!";
    } else {
        qDebug() << "Error Creating Db: " << query.lastError().text();
    }

    db.close();
    db.removeDatabase("setDb");
    qDebug() << "Database Created!";
    */
}


QString DatabaseInterface::initializeDatabase()
{
    QSqlDatabase m_db;

    try {
        m_db = QSqlDatabase::database("default");
        m_db = m_db.addDatabase("QPSQL");
        m_db.setHostName("localhost");
        m_db.setUserName(db_uname);
        m_db.setPassword(db_pswd);
        m_db.setDatabaseName("salama");

        if(!m_db.open())
        {
            return "false:Error Connecting Db => " + m_db.lastError().text();
        }

        else
        {
            Q_ASSERT(m_db.open());

            QSqlQuery query;
            QString sql;

            QFile file(":/sql/tables.sql");
            file.open(QIODevice::ReadOnly);
            sql = file.readAll();

            auto sql_segments = sql.split("--comment");

            m_db.transaction();
            // int index = 0;

            foreach (const QString &sql_str, sql_segments)
            {
                // index ++;
                if(query.exec(sql_str))
                {
                    // m_db.commit();
                }

                else
                {
                    m_db.rollback();

                    qDebug() << "Error executing : " << query.lastError().text();
                }

                // qDebug() << "Data " << index << " / " << sql_segments.size();
            }

            if(m_db.isOpen())
                return "true:OK";

            else
            {
                QString str = "Error Creating Db: " + query.lastError().text();
                // qDebug() << str;
                return "false:" + str;
            }
        }

    } catch (std::exception &e) {
        QString err = ">> Error executing SQL: " + QString::fromUtf8(e.what());
        // qDebug() << err;
        return "false:"+err;
    }

    return "false:Error Creating Database";
}
