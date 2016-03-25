#include "treemanager.h"

TreeManager::TreeManager(QObject *parent) : QObject(parent)
{
    init();
}

void TreeManager::addTreeNode(QString parentUrl, QString name, QString url)
{
    // check the map is empty of not
    if(m_treeMap.count() > 0)
    {
        if(m_treeMap.contains(parentUrl))
        {
            // find the match key
            addTreeNode(m_treeMap.value(parentUrl), parentUrl, name, url);
        }
        else
        {
            qDebug() << "[addTreeNode] error. : parentUrl = " << parentUrl << " name = " << name << " url = " << url;
        }
    }
    else
    {
        // the map is empty
        qDebug() << "[addTreeNode] is empty";
        addTreeNode(m_tree, parentUrl, name, url);
    }

}

void TreeManager::printTreeMap()
{
    // go to print the tree map for developing
    qDebug() << "[printTreeMap] " << "size = " << m_treeMap.count();
    QMap<QString,TreeNode*>::const_iterator i = m_treeMap.begin();
    while (i != m_treeMap.end())
    {
        qDebug() <<"[printTreeMap] "<< i.key() << " --> " << i.value();
        i++;
    }
}

void TreeManager::saveFetchReport2LocalFile()
{

}

void TreeManager::addTrackGoal(QString str)
{
    // add the new goal url for tracking
    this->m_trackList.prepend(str);
}

void TreeManager::removeTrackGoal(QString str)
{
    this->m_trackList.removeOne(str);
}

QString TreeManager::popOneTrackGoal()
{
    if(this->m_trackList.isEmpty())
    {
        return "";
    }
    else
    {
        return this->m_trackList.takeLast();
    }
}

QString TreeManager::printFetchReport()
{
    qDebug() << "[printTreeMap] " << "size = " << m_treeMap.count();
    QMap<QString,TreeNode*>::const_iterator i = m_treeMap.begin();
    while (i != m_treeMap.end())
    {
        qDebug() <<"[printFetchReport] ..............................";
        if(i.value()->isFolder() == false)
        {
            qDebug() << i.value()->getName() << " = " << i.key();
        }
        i++;
    }
}

void TreeManager::addTreeNode(TreeNode *node, QString parentUrl, QString name, QString url)
{
    // filter the already conatins url, if exist, no need to add again
    if(m_treeMap.contains(url)) return;

    // create the new treeNode
    TreeNode* newNode = new TreeNode(node);
    newNode->setName(name);
    newNode->setParent(node);
    newNode->setUrl(url);

    // set to the parent tree ndoe
    node->addChild(newNode);

    // insert the new record to the treeMap
    m_treeMap.insert(url, newNode);

    // check if the new node is folder, if yes, add to the goal list
    if(newNode->isFolder())
    {
        addTrackGoal(newNode->getUrl());
    }

}

void TreeManager::init()
{
    this->m_tree = new TreeNode(this);

    // add the first key-value to the tree map
    this->m_treeMap.insert(webUrl, m_tree);
}

