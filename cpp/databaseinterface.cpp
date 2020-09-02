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

    //connect(this, &QSqlDatabase::open, this, &DatabaseInterface::onDatabaseStatusChangedd);
    //connect(this, &DatabaseInterface::databaseStatusChangedd, this, &DatabaseInterface::onDatabaseStatusChangedd);
}

void DatabaseInterface::initializeDatabase()
{
    m_db.transaction();
    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS app_user (\
               username varchar(45) NOT NULL,\
               password varchar(450) NOT NULL,\
               enabled integer NOT NULL DEFAULT '1',\
               PRIMARY KEY (username))");

    emit databaseStatusChanged(true);
    m_db.commit();

    qDebug() << "Database has been instantiated ...";
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

void DatabaseInterface::onDatabaseStatusChanged(const bool &status)
{
    qDebug() << "Database Status : " << status;
}

void DatabaseInterface::onDatabaseStatusChangedd()
{
    qDebug() << "Slot called!";
}
