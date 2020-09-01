#ifndef WEBAPIINTERFACE_H
#define WEBAPIINTERFACE_H

#include <QObject>

class WebApiInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebApiInterface(QObject *parent = nullptr);

signals:

};

#endif // WEBAPIINTERFACE_H
