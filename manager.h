#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "networkmanager.h"
#include "localmanager.h"
#include "constant.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = 0);
    void init();
    NetworkManager *getNetworkManager();
    LocalManager* getLocalManager();

signals:

public slots:

private:
    NetworkManager* m_nm;
    LocalManager* m_lm;

};

#endif // MANAGER_H
