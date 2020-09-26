#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QRect>
#include <QScreen>
#include <QJsonDocument>
#include <QJsonObject>
#include <QGuiApplication>
#include <QSettings>

#include "databaseinterface.h"
#include "serialportinterface.h"
#include "webapiinterface.h"
#include "websocketsinterface.h"

class QmlInterface : public QObject
{
    Q_OBJECT

public:
    explicit QmlInterface(QObject *parent = nullptr);

    Q_PROPERTY(bool isDarkTheme READ isDarkTheme WRITE setIsDarkTheme NOTIFY isDarkThemeChanged)

    Q_INVOKABLE QJsonObject getScreenSize();

    bool isDarkTheme() const;

public slots:
    void setIsDarkTheme(bool isDarkTheme);

signals:
    void databaseReadyChanged();

    void isDarkThemeChanged(bool isDarkTheme);

private slots:

private:
    DatabaseInterface * m_databaseInterface;

    bool m_isDarkTheme;

    QSettings m_settings;
};

#endif // QMLINTERFACE_H
