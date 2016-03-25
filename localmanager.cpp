#include "localmanager.h"
#include <QFile>
#include <QDir>

const QString TXTLOCALFILE = "/tmp/web_spider/fetch_report.txt";
const QString HTMLTXTLOCALFILE = "/tmp/web_spider/index.html";
const QString LOCALFOLDER = "/tmp/web_spider/";

LocalManager::LocalManager(QObject *parent) : QObject(parent)
{

}

void LocalManager::init()
{
    checkLocalFolderExist();
    checktxtLocalFileExist();

    this->m_file = new QFile(TXTLOCALFILE, this);
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

void LocalManager::Txt2Html()
{

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

void LocalManager::checktxtLocalFileExist()
{
    // check the file is exist or not,if not create it
    QFile report_file(TXTLOCALFILE);
    if(!report_file.exists())
    {
        qDebug() << "[checkTXTLOCALFILEExist] create the local report file";
        report_file.open(QIODevice::WriteOnly | QIODevice::Text);

        report_file.close();
    }

}

