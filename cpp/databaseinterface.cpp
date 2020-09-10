#include "databaseinterface.h"

DatabaseInterface::DatabaseInterface(QObject *parent) : QObject(parent)
{
    QFile file(":/json/db-credentials.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QString jsonString = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObj = doc.object();

    QString db_uname = jsonObj.value(QString("username")).toString();
    QString db_pswd = jsonObj.value(QString("password")).toString();
    QString db_name = jsonObj.value(QString("database")).toString();

    // Debug
    //qDebug()<< db_uname << ", " << db_pswd << ", " << db_name;

    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("localhost");
    m_db.setUserName(db_uname);
    m_db.setPassword(db_pswd);
    m_db.setDatabaseName(db_name);
    const bool status = m_db.open();

    //qDebug() << "Is db open? " << status;
    emit databaseStatusChanged(status);

    initializeDatabase();
}

DatabaseInterface::~DatabaseInterface()
{
    m_db.close();
}

void DatabaseInterface::initializeDatabase()
{
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

            QFile file(":/sql/tables.sql");
            file.open(QIODevice::ReadOnly);
            sql = file.readAll();

            if(query.exec(sql))
            {
                m_db.commit();



                qInfo() << ">> Database has been instantiated ...";
            }

            else
            {
                qDebug() << "Error Creating Db: " << query.lastError().text();

                // throw query.lastError().text();
            }
        }

    } catch (std::exception &e) {
        qDebug() << "Error executing SQL: " << e.what();
    }

    emit databaseReady();

    qDebug() << ">> database Ready emitted";
}

QSqlDatabase DatabaseInterface::getDb()
{
    return m_db;
}
