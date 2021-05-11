#ifndef COMPLETER_H
#define COMPLETER_H

#include <QObject>

class Completer : public QObject
{
    Q_OBJECT


public:
    explicit Completer(QObject *parent = nullptr);

    Completer(const QString &name,const QString &key, const float &sp, QObject *parent = nullptr);

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(float sp READ sp WRITE setSp NOTIFY spChanged)

    QString name() const;

    QString key() const;

    void setName(QString name);

    void setKey(QString key);

    float sp() const;

public slots:
    void setSp(float sp);

signals:

    void nameChanged(QString name);
    void keyChanged(QString key);

    void spChanged(float sp);

private:

    QString m_name, m_key;
    float m_sp;
};

#endif // COMPLETER_H
