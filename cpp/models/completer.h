#ifndef COMPLETER_H
#define COMPLETER_H

#include <QObject>

class Completer : public QObject
{
    Q_OBJECT


public:
    explicit Completer(QObject *parent = nullptr);

    Completer(const QString &name,const QString &key, QObject *parent = nullptr);

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)

    QString name() const;

    QString key() const;

    void setName(QString name);

    void setKey(QString key);

signals:

    void nameChanged(QString name);
    void keyChanged(QString key);

private:

    QString m_name, m_key;
};

#endif // COMPLETER_H
