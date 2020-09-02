#include "qmlinterface.h"

QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    m_databaseInterface = new DatabaseInterface(parent);

    connect(m_databaseInterface,&DatabaseInterface::databaseStatusChanged,this,&QmlInterface::onDatabaseStatusChanged);
}

void QmlInterface::initDatabase()
{

}

void QmlInterface::writeToDb(const QString &querry, const QVariantList &list)
{

}

void QmlInterface::readFromDb(const QString &querry, const QVariantList &list)
{

}

void QmlInterface::onDatabaseStatusChanged(const bool &status)
{
    qDebug() << "Db Status: " << status;

    if(status)
        qDebug()<<"Database Opened Successfully!";

    else
        qDebug()<<"Error opening database!";
}
