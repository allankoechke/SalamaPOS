#include "qmlinterface.h"

QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    m_databaseInterface = new DatabaseInterface(parent);
    bool status = m_databaseInterface->initializeDatabase();

    if(status)
        emit databaseReadyChanged();

    // qDebug() << ">> " << status;
}

QJsonObject QmlInterface::getScreenSize()
{
    QJsonDocument doc = QJsonDocument::fromVariant("{ \"width\":0, \"height\":0}");
    QJsonObject size = doc.object();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    size["width"] = width;
    size["height"] = height;

    return size;
}


