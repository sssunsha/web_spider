#ifndef LOCALMANAGER_H
#define LOCALMANAGER_H

#include <QObject>
#include "constant.h"

class LocalManager : public QObject
{
    Q_OBJECT
public:
    explicit LocalManager(QObject *parent = 0);
    void init();
signals:

public slots:
};

#endif // LOCALMANAGER_H
