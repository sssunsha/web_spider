#include "treemanager.h"

TreeManager::TreeManager(QObject *parent) : QObject(parent)
{
    this->m_tree = new TreeNode(this);
    init();
}

void TreeManager::addTreeNode(QString parentUrl, QString name, QString url)
{

    TreeNode* node = m_tree;
    if(node->getUrl().isNull())
    {
        // now the tree is empty
    }
    else
    {
       addTreeNode(node, parentUrl, name, url);
    }
}

void TreeManager::addTreeNode(TreeNode* node, QString parentUrl, QString name, QString url)
{
    if(node->getUrl() == parentUrl)
    {
        // add the child tree node
    }
    else
    {

    }

}

void TreeManager::init()
{

}

