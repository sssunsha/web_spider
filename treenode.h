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

    QString getName();
    QString getUrl();
    QString getType();
    TreeNode* getParent();
    bool isFolder();

signals:

public slots:

private: // basic
    // true: folder means has children
    // false: resource, no child
    bool m_isFolder;
    TreeNode* m_parent;
    QString m_url; // self node url
    QString m_name; // description name

private: // folder
    // for child and father
    QList<TreeNode*>* m_child;

private: // resource
    QString m_type;

};

#endif // TREENODE_H
