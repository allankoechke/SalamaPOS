#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>


#include "databaseinterface.h"
#include "serialportinterface.h"
#include "webapiinterface.h"
#include "websocketsinterface.h"

class QmlInterface : public QObject
{
    Q_OBJECT
public:
    explicit QmlInterface(QObject *parent = nullptr);

    Q_INVOKABLE void initDatabase();

    Q_INVOKABLE void writeToDb(const QString & querry, const QVariantList & list);

    Q_INVOKABLE void readFromDb(const QString & querry, const QVariantList & list);

signals:
    void writeToDbChanged(const QString & querry, const QVariantList & list);

    void readFromDbChanged(const QString & querry, const QVariantList & list);

};

#endif // QMLINTERFACE_H
