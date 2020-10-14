#include "alarmsmodel.h"

AlarmsModel::AlarmsModel(QObject *parent) : QAbstractListModel(parent)
{
}

int AlarmsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_alarmsList.size();
}

QVariant AlarmsModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > m_alarmsList.count())
        return QVariant();

    Alarms * alarms = m_alarmsList.at(index.row());

    if(role == AlarmTypeRole)
        return alarms->alarmType();

    if(role == AlarmStringRole)
        return alarms->alarmString();

    if(role == AlarmIdRole)
        return alarms->alarmId();

    if(role == AlarmIsActiveRole)
        return alarms->alarmIsActive();

    else return QVariant();
}

bool AlarmsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Alarms * alarms = m_alarmsList.at(index.row());
    bool changed = false;

    switch (role)
    {
    case AlarmTypeRole:
    {
        if( alarms->alarmType() != value.toString())
        {
            alarms->setAlarmType(value.toString());
            changed = true;
        }

        break;
    }

    case AlarmStringRole:
    {
        if( alarms->alarmString() != value.toString())
        {
            alarms->setAlarmString(value.toString());
            changed = true;
        }

        break;
    }

    case AlarmIdRole:
    {
        if( alarms->alarmId() != value.toString())
        {
            alarms->setAlarmId(value.toString());
            changed = true;
        }

        break;
    }

    case AlarmIsActiveRole:
    {
        if( alarms->alarmIsActive() != value.toBool())
        {
            alarms->setAlarmIsActive(value.toBool());
            changed = true;
        }

        break;
    }

    }

    if(changed)
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags AlarmsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> AlarmsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[AlarmTypeRole] = "alarm_type";
    roles[AlarmStringRole] = "alarm_text";
    roles[AlarmIdRole] = "alarm_id";
    roles[AlarmIsActiveRole] = "alarm_isActive";

    return roles;
}

void AlarmsModel::addAlarmItem(const QString &type, const QString &content)
{
    QString id = QString::number(QDateTime::currentMSecsSinceEpoch());
    addAlarmItem(new Alarms(type, content, id, false));
}

void AlarmsModel::removeAlarmItem(const QVariant &id)
{
    int _id = getAlarmId(id);

    if(_id != -1)
    {
        beginRemoveRows(QModelIndex(), _id, _id);
        m_alarmsList.removeAt(_id);
        endRemoveRows();

        qDebug() << "Alarm Removed";
    }
}

void AlarmsModel::addAlarmItem(Alarms *alarms)
{
    const int index = m_alarmsList.size();
    beginInsertRows(QModelIndex(), index, index);
    m_alarmsList.append(alarms);
    endInsertRows();
}

int AlarmsModel::getAlarmId(const QVariant &id)
{
    for(int i=0; i<m_alarmsList.size()-1; i++)
    {
        QVariant _id = data(this->index(i), AlarmIdRole);

        if(id == _id)
            return i;
    }

    return -1;
}
