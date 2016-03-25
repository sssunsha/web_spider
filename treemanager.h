#ifndef TREEMANAGER_H
#define TREEMANAGER_H

#include <QObject>
#include <QMap>
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
    void printTreeMap();
    void saveFetchReport2LocalFile();
    void addTrackGoal(QString str);
    void removeTrackGoal(QString str);
    QString popOneTrackGoal();
    QString printFetchReport();


signals:

public slots:

private:
    void addTreeNode(TreeNode* node, QString parentUrl, QString name, QString url);
    void init();

private:
    TreeNode* m_tree;
    QMap<QString,TreeNode*> m_treeMap;  // the url and TreeNode key-value map
    QList<QString> m_trackList; // the track list for Network download and tracking
};

#endif // TREEMANAGER_H
