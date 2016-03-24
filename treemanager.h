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

    // add the new found node from parsing
    void addTreeNode(QString parentUrl, QString name, QString url);

signals:

public slots:

private:
    void init();

private:
    TreeNode* m_tree;
};

#endif // TREEMANAGER_H
