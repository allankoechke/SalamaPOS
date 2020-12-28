#ifndef ALARMS_H
#define ALARMS_H

#include <QObject>

class Alarms : public QObject
{
    Q_OBJECT

public:
    explicit Alarms(QObject *parent = nullptr);
    Alarms(const QString &alarmType, const QString &alarmString, const QString &alarmId, const bool &alarmIsActive, QObject *parent = nullptr);

    Q_PROPERTY(QString alarmType READ alarmType WRITE setAlarmType NOTIFY alarmTypeChanged)
    Q_PROPERTY(QString alarmString READ alarmString WRITE setAlarmString NOTIFY alarmStringChanged)
    Q_PROPERTY(QString alarmId READ alarmId WRITE setAlarmId NOTIFY alarmIdChanged)
    Q_PROPERTY(bool alarmIsActive READ alarmIsActive WRITE setAlarmIsActive NOTIFY alarmIsActiveChanged)


    QString alarmType() const;

    QString alarmString() const;

    QString alarmId() const;

    bool alarmIsActive() const;

    void setAlarmType(QString alarmType);

    void setAlarmString(QString alarmString);

    void setAlarmId(QString alarmId);

    void setAlarmIsActive(bool alarmIsActive);

signals:
    void alarmTypeChanged(QString alarmType);
    void alarmStringChanged(QString alarmString);
    void alarmIdChanged(QString alarmId);
    void alarmIsActiveChanged(bool alarmIsActive);

private:
    QString m_alarmType, m_alarmString, m_alarmId;

    bool m_alarmIsActive;
};

#endif // ALARMS_H
