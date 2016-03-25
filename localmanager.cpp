#include "localmanager.h"
#include <QFile>
#include <QDir>

const QString LOCALFile = "/tmp/web_spider/fetch_report.txt";
const QString LOCALFOLDER = "/tmp/web_spider/";

LocalManager::LocalManager(QObject *parent) : QObject(parent)
{

}

void LocalManager::init()
{
    checkLocalFolderExist();
    checkLocalFileExist();

    this->m_file = new QFile(LOCALFile, this);
    openFetchRecordFile();
}

LocalManager::~LocalManager()
{
}

// add fetch record to local file
// format
// name-url\n
void LocalManager::addFetchRecord2File(TreeNode *node)
{
        QTextStream out(m_file);
        QString str;
        str.append(node->getName().toUtf8());
        str.append("-----");
        str.append(node->getUrl());
        str.append("\n");
        out<<str;
}

void LocalManager::openFetchRecordFile()
{
    if(!m_file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "[LocalManager]: open local record file failed";
    }

}

void LocalManager::closeFetchRecordFile()
{
    this->m_file->close();
}

void LocalManager::checkLocalFolderExist()
{
    // check the /temp/web_spider is exist or not, if not create
    QDir dir(LOCALFOLDER);
    if(!dir.exists())
    {
        qDebug() << "[checkLocalFolderExist] create the local folder to store data";
        dir.mkpath(LOCALFOLDER);
    }
}

void LocalManager::checkLocalFileExist()
{
    // check the file is exist or not,if not create it
    QFile report_file(LOCALFile);
    if(!report_file.exists())
    {
        qDebug() << "[checkLocalFileExist] create the local report file";
        report_file.open(QIODevice::WriteOnly | QIODevice::Text);

        report_file.close();
    }

}

