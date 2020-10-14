#include "alarms.h"

Alarms::Alarms(QObject *parent) : QObject(parent)
{

}

Alarms::Alarms(const QString &alarmType, const QString &alarmString, const QString &alarmId, const bool &alarmIsActive, QObject *parent)
    : QObject(parent), m_alarmType(alarmType), m_alarmString(alarmString), m_alarmId(alarmId), m_alarmIsActive(alarmIsActive)
{ }

QString Alarms::alarmType() const
{
    return m_alarmType;
}

QString Alarms::alarmString() const
{
    return m_alarmString;
}

QString Alarms::alarmId() const
{
    return m_alarmId;
}

bool Alarms::alarmIsActive() const
{
    return m_alarmIsActive;
}

void Alarms::setAlarmType(QString alarmType)
{
    if (m_alarmType == alarmType)
        return;

    m_alarmType = alarmType;
    emit alarmTypeChanged(m_alarmType);
}

void Alarms::setAlarmString(QString alarmString)
{
    if (m_alarmString == alarmString)
        return;

    m_alarmString = alarmString;
    emit alarmStringChanged(m_alarmString);
}

void Alarms::setAlarmId(QString alarmId)
{
    if (m_alarmId == alarmId)
        return;

    m_alarmId = alarmId;
    emit alarmIdChanged(m_alarmId);
}

void Alarms::setAlarmIsActive(bool alarmIsActive)
{
    if (m_alarmIsActive == alarmIsActive)
        return;

    m_alarmIsActive = alarmIsActive;
    emit alarmIsActiveChanged(m_alarmIsActive);
}


