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

    // Property
    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)

    // Q_INVOKABLES
    Q_INVOKABLE void addAlarmItem(const QString &type, const QString &content);
    Q_INVOKABLE void removeAlarmItem(const QVariant &id);

    // Internals
    void addAlarmItem(Alarms * alarms);
    int getAlarmId(const QVariant &id);

    int size() const;

public slots:
    void setSize(int size);

signals:

    void sizeChanged(int size);

private:
    QList<Alarms *> m_alarmsList;

    int m_size;
};

#endif // ALARMSMODEL_H
