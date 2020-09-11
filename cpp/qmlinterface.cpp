#include "qmlinterface.h"

QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    m_databaseInterface = new DatabaseInterface(parent);
    bool status = m_databaseInterface->initializeDatabase();

    if(status)
        emit databaseReadyChanged();

    qDebug() << ">> " << status;
}


