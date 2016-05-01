#include "localmanager.h"
#include <QFile>
#include <QDir>

#ifdef Q_OS_WIN32
const QString TXTLOCALFILE = "F:\\qt_workspace\\web_spider_tmp\\fetch_report.txt";
const QString HTMLLOCALFILE = "F:\\qt_workspace\\web_spider_tmp\\index.html";
const QString LOCALFOLDER = "F:\\qt_workspace\\web_spider_tmp";
#else
const QString TXTLOCALFILE = "/tmp/web_spider/fetch_report.txt";
const QString HTMLLOCALFILE = "/tmp/web_spider/index.html";
const QString LOCALFOLDER = "/tmp/web_spider/";
#endif




QString htmlHeardStr = QString("<html><head>"
                               "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />"
                               "<title>{title}</title></head><body><H1>{title}</H1><hr>\n");
QString htmlContentStr = QString("<p><A HREF=\"{url}\">{name}</A>\n");
QString htmlFooterStr = QString("<hr></body></html>");

LocalManager::LocalManager(QObject *parent) : QObject(parent)
{

}

void LocalManager::init()
{
    checkLocalFolderExist();
    checktxtLocalFileExist();

    this->m_file = new QFile(TXTLOCALFILE, this);
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
    str.append(txtSplitMark);
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
    QFile txtFile(TXTLOCALFILE);
    QFile htmlFile(HTMLLOCALFILE);
    if(htmlFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream htmlOut(&htmlFile);

        // insert the header of the html
        QString str = htmlHeardStr;

        // replace the {title} with baseurl
        str.replace("{title}", Constant::web_url);

        // write the replaced header str
        htmlOut << str;

        if(txtFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream txtIn(&txtFile);
            while (!txtIn.atEnd()) {
                QString line = txtIn.readLine();
                QStringList lineList = line.split(txtSplitMark);
                QString contentStr(htmlContentStr);
                str = contentStr.replace("{name}", lineList.at(0));
                str = contentStr.replace("{url}", lineList.at(1));

               htmlOut << str;
            }

            txtFile.close();
        }
        else
        {
            qDebug() << "[Txt2Html]: failed to open the txt file";
        }

        // insert the footer
        htmlOut << htmlFooterStr;
        htmlFile.close();

        qDebug() << "[Txt2Html]: finish transform txt to html";
    }
    else
    {
        qDebug() << "[Txt2Html]: failed to open the html file";
    }




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

