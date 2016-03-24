#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <QObject>
#include "constant.h"
#include "treenode.h"

// the manager to manager the whole tree (include all the tree node)
class TreeManager : public QObject
{
    Q_OBJECT
public:
    explicit TreeManager(QObject *parent = 0);

signals:

public slots:
};

#endif // TREEMANAGER_H
