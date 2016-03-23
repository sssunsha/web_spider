#include "parsemanager.h"
#include <QXmlStreamReader>


ParseManager::ParseManager(QObject *parent) : QObject(parent)
{

}

void ParseManager::startParsing(QString str)
{
    QXmlStreamReader reader(str);
    while (!reader.atEnd()) {
          reader.readNext();

          if (reader.isStartElement())
             {
                 qDebug() << "element name: '" << reader.name().toString() << "'"
                     << ", text: '" << reader.text().toString() << "'" << endl;
             }
             else if (reader.hasError())
             {
                 qDebug() << "reader error: " << reader.errorString() << endl;
             }
             else if (reader.atEnd())
             {
                 qDebug() << "Reached end, done" << endl;
             }
    }

}

