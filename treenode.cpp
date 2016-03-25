#include "treenode.h"

TreeNode::TreeNode(QObject *parent) : QObject(parent)
{
    // create the child list
    this->m_childList = new QList<TreeNode*>;
}

void TreeNode::init()
{
    this->m_name.clear();
    this->m_parent=NULL;
    this->m_type.clear();
    this->m_url.clear();
    this->m_chidTrackIndex = 0;
    this->m_isFolder = true;
}

void TreeNode::setName(QString str)
{
    this->m_name = str;
}

void TreeNode::setUrl(QString url)
{
    this->m_url = url;
}

void TreeNode::setParent(TreeNode *father)
{
    this->m_parent = father;
}

void TreeNode::setIsFolder(bool is_folder)
{
    this->m_isFolder = is_folder;
}

void TreeNode::setType(QString type)
{
    this->m_type = type;
}

void TreeNode::setChildTrackIndex(int index)
{
    this->m_chidTrackIndex = index;
}

void TreeNode::addChild(TreeNode *child)
{
    this->m_childList->append(child);
}

int TreeNode::getChildCount()
{
    if(this->m_childList)
    {
        return this->m_childList->length();
    }

    return 0;
}

void TreeNode::setCheckType(CHECK_TYPE type)
{
    this->m_check_type = type;
}

QString TreeNode::getName()
{
    return this->m_name;
}

QString TreeNode::getUrl()
{
    return this->m_url;
}

QString TreeNode::getType()
{
    return this->m_type;
}

TreeNode *TreeNode::getParent()
{
    return this->m_parent;
}

bool TreeNode::isFolder()
{
    return this->m_isFolder;
}

QList<TreeNode *>* TreeNode::getChildList()
{
    return this->m_childList;
}

int TreeNode::getChildTrackIndex()
{
    return this->m_chidTrackIndex;
}

CHECK_TYPE TreeNode::getCheckType()
{
    return this->m_check_type;
}



