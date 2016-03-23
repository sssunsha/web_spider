#include <QCoreApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Manager* m = new Manager(&a);
    m->init();




    return a.exec();
}

