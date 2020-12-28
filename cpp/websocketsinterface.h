#ifndef WEBSOCKETSINTERFACE_H
#define WEBSOCKETSINTERFACE_H

#include <QObject>

class WebSocketsInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketsInterface(QObject *parent = nullptr);

signals:

};

#endif // WEBSOCKETSINTERFACE_H
