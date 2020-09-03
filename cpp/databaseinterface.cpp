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
    m_db.setDatabaseName("test1"); //db_name);
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

        QFile file(":/sql/tables.sql");
        file.open(QIODevice::ReadOnly);
        QString sql = file.readAll();

        //qDebug() << sql;

        query.exec(sql);

        //emit databaseStatusChanged(true);
        m_db.commit();

        qDebug() << "Database has been instantiated ...";

    } catch (std::exception &e) {
        qDebug() << "Error executing SQL: " << e.what();
    }

}

void DatabaseInterface::addToDatabase(const QString &querry, const QVariantMap &map)
{
    qDebug() << "New Querry from qml";

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

void DatabaseInterface::onWriteToDbChanged(const QString &querry, const QJsonObject &json, const QVariantList &type)
{
    qDebug() << "New Querry from qml";

    QSqlQuery m_query;
    m_query.prepare(querry);

    QVariantList var_list;
    var_list.append("barcode");
    var_list.append("item_name");
    var_list.append("item_unit");
    var_list.append("item_bp");
    var_list.append("item_sp");
    var_list.append("item_qty");
    var_list.append("item_company");

    if(type.count() != 0)
    {
        for(int i=0; i<7; i++)
        {
            if(type.at(i).toString() == "string")
            {
                int item = json.value(var_list.at(i).toString()).toInt();
                m_query.bindValue(":"+var_list.at(i).toString(), item);
            }

            else if(type.at(i).toString() == "real")
            {
                float item = json.value(var_list.at(i).toString()).toDouble();
                m_query.bindValue(":"+var_list.at(i).toString(), item);
            }

            else if(type.at(i).toString() == "int")
            {
                int item = json.value(var_list.at(i).toString()).toInt();
                m_query.bindValue(":"+var_list.at(i).toString(), item);
            }

            else
            {
                qDebug() << "Error bindind this value";
                qDebug() << "Index: " << i;
            }
        }
    }

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
