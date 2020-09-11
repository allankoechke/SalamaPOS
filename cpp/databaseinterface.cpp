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

        if(query.exec("SELECT * FROM product_type"))
        {
            int count = 0;
            QString sql;

            while(query.next())
            {
                count++;
            }

            if(count == 0)
            {
                QString sql;
                sql = "INSERT INTO product_type(type_name) VALUES ('General')";

                if(query.exec(sql))
                    qDebug() << ">> New ctaegory Added";

                else
                    qDebug() << "Error Adding item: " << query.lastError().text();
            }

            else
                qInfo() << ">> Categories: " << count;

            QFile file(":/sql/tables.sql");
            file.open(QIODevice::ReadOnly);
            sql = file.readAll();

            if(query.exec(sql))
            {
                m_db.commit();
                qInfo() << ">> Database has been instantiated ...";
                return true;
            }

            else
                qDebug() << "Error Creating Db: " << query.lastError().text();
        }

    } catch (std::exception &e) {
        qDebug() << ">> Error executing SQL: " << e.what();
        return false;
    }

    return false;
}
