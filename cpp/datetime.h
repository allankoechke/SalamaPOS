#ifndef DATETIME_H
#define DATETIME_H

#include <QObject>
#include <QDateTime>

class DateTime : public QObject
{
    Q_OBJECT
public:
    explicit DateTime(QObject *parent = nullptr);

    Q_INVOKABLE QStringList getTimestamp(const QString &when);

signals:

};

#endif // DATETIME_H
