#include "completer.h"

Completer::Completer(QObject *parent) : QObject(parent)
{
}

Completer::Completer(const QString &name, const QString &key, QObject *parent)
    :QObject(parent), m_name(name), m_key(key)
{
}

QString Completer::name() const
{
    return m_name;
}

QString Completer::key() const
{
    return m_key;
}

void Completer::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Completer::setKey(QString key)
{
    if (m_key == key)
        return;

    m_key = key;
    emit keyChanged(m_key);
}
