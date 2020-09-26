#include "qmlinterface.h"

QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    m_databaseInterface = new DatabaseInterface(parent);
    bool status = m_databaseInterface->initializeDatabase();

    if(status)
        emit databaseReadyChanged();

    QCoreApplication::setOrganizationName("lalanke");
    QCoreApplication::setOrganizationDomain("lalanke.com");
    QCoreApplication::setApplicationName("Salama P.O.S.");

    bool isFirstTime = m_settings.value("General/isFirstTime", true).toBool();
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

bool QmlInterface::isDarkTheme() const
{
    return m_isDarkTheme;
}

void QmlInterface::setIsDarkTheme(bool isDarkTheme)
{
    if (m_isDarkTheme == isDarkTheme)
        return;

    m_isDarkTheme = isDarkTheme;
    emit isDarkThemeChanged(m_isDarkTheme);
}


