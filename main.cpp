#include <QCoreApplication>
#include "manager.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "==================== welcome to web spider =================";
    Manager* m = new Manager(&a);
    m->init();
    m->getNetworkManager()->start2Fetch();
    return a.exec();
}

