#include "treemanager.h"

TreeManager::TreeManager(QObject *parent) : QObject(parent)
{
    this->m_tree = new TreeNode(this);
    init();
}

void TreeManager::addTreeNode(QString parentUrl, QString name, QString url)
{
}

void TreeManager::init()
{

}

