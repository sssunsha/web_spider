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
}

void LocalManager::checkLocalFolderExist()
{
    // check the /temp/web_spider is exist or not, if not create
    QDir dir(LOCALFOLDER);
    if(!dir.exists())
    {
        qDebug() << "create the local folder to store data";
        dir.mkpath(LOCALFOLDER);
    }
}

void LocalManager::checkLocalFileExist()
{
    // check the file is exist or not,if not create it
    QFile report_file(LOCALFile);
    if(!report_file.exists())
    {
        qDebug() << "create the local recent win ball file";
        report_file.open(QIODevice::WriteOnly | QIODevice::Text);
    }

}

