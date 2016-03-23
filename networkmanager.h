#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include "constant.h"

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    void init();

signals:

public slots:
};

#endif // NETWORKMANAGER_H
