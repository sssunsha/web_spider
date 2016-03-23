#ifndef PARSEMANAGER_H
#define PARSEMANAGER_H
#include "constant.h"
#include <QObject>

class ParseManager : public QObject
{
    Q_OBJECT
public:
    explicit ParseManager(QObject *parent = 0);

signals:

public slots:
};

#endif // PARSEMANAGER_H
