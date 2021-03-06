#ifndef LOCALMANAGER_H
#define LOCALMANAGER_H
#include <QFile>
#include <QObject>
#include "constant.h"
#include "treenode.h"

class LocalManager : public QObject
{
    Q_OBJECT
public:
    explicit LocalManager(QObject *parent = 0);
    void init();
    ~LocalManager();
    void addFetchRecord2File(TreeNode* node);
    void openFetchRecordFile();
    void closeFetchRecordFile();
    // format the txt report to html
    void Txt2Html();
signals:

public slots:

private:
    void checkLocalFolderExist();
    void checktxtLocalFileExist();

    QFile* m_file;
};

#endif // LOCALMANAGER_H
