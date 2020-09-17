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
    Q_ASSERT(m_db.open());

    try {
        m_db.transaction();
        QSqlQuery query;
        QString sql;

        QFile file(":/sql/tables.sql");
        file.open(QIODevice::ReadOnly);
        sql = file.readAll();

        if(query.exec(sql))
        {
            m_db.commit();
            qInfo() << " [INFO] Database has been instantiated ... "; //[" << query.executedQuery() << " ]";

            if(query.exec("SELECT * FROM product_type"))
            {
                int count = 0;

                while(query.next())
                {
                    count++;
                }

                if(count == 0)
                {
                    QString sql;
                    sql = "INSERT INTO product_type(type_id, type_name) VALUES ('1658977', 'General')";

                    if(query.exec(sql))
                    {
                        qDebug() << ">> New ctaegory Added";
                        return true;
                    }

                    else
                    {
                        qDebug() << "Error Adding item: " << query.lastError().text();
                        return false;
                    }
                }

                // else
                //qInfo() << ">> Categories: " << count;
            }
        }

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
