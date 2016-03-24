#ifndef TREENODE_H
#define TREENODE_H

// the tree node to describe the website structure

#include <QObject>
#include "constant.h"
#include "QList"
#include "QUrl"

class TreeNode : public QObject
{
    Q_OBJECT
public:
    explicit TreeNode(QObject *parent = 0);

    void setName(QString str);
    void setUrl(QString url);
    void setParent(TreeNode* father);
    void setIsFolder(bool is_folder);
    void setType(QString type);

    void addChild(TreeNode* child);
    int getChildCount();

    QString getName();
    QString getUrl();
    QString getType();
    TreeNode* getParent();
    bool isFolder();
    QList<TreeNode *>* getChildList();


signals:

public slots:

private:
    void init();

private: // basic
    // true: folder means has children
    // false: resource, no child
    bool m_isFolder;
    TreeNode* m_parent;
    QString m_url; // self node url
    QString m_name; // description name

private: // folder
    // for child and father
    QList<TreeNode*>* m_childList;

private: // resource
    QString m_type;

};

#endif // TREENODE_H
