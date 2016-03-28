#include <QCoreApplication>
#include "constant.h"
#include "manager.h"
#include <QDebug>


QString Constant::web_url;

bool argChecking(int argc, char *argv[])
{
    switch(argc)
    {
    case 1:
          Constant::web_url = QString("http://linux.linuxidc.com/");
        break;
    case 2:
        Constant::web_url = QString(argv[1]);
        break;
    default:
        qDebug("invalid command ...");
        return false;
    }
    return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "==================== welcome to web spider =================";

    if(argChecking(argc, argv))
    {
        Manager* m = new Manager(&a);
        m->init();
        m->getNetworkManager()->start2Fetch();
        return a.exec();
    }
    else
    {
        return -1;
    }
}

