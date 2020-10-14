#ifndef ALARMSMODEL_H
#define ALARMSMODEL_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QAbstractListModel>

#include "src/alarms.h"

class AlarmsModel : public QAbstractListModel
{
    Q_OBJECT

    enum AlarmsModelRoles{
        AlarmTypeRole = Qt::UserRole + 1,
        AlarmStringRole,
        AlarmIdRole,
        AlarmIsActiveRole
    };

public:
    explicit AlarmsModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Q_INVOKABLES
    Q_INVOKABLE void addAlarmItem(const QString &type, const QString &content);
    Q_INVOKABLE void removeAlarmItem(const QVariant &id);

    // Internals
    void addAlarmItem(Alarms * alarms);
    int getAlarmId(const QVariant &id);

signals:

private:
    QList<Alarms *> m_alarmsList;

};

#endif // ALARMSMODEL_H
