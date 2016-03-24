#include "parsemanager.h"
#include <QXmlStreamAttributes>

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
            //                 qDebug() << reader.name().toString() << ","
            //                      << reader.text().toString();
            parsingHrefElement(reader);

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

void ParseManager::parsingHrefElement(QXmlStreamReader &reader)
{
    if(reader.name().toString() == "A" || reader.name().toString() == "a")
    {
        // go to parsing the herf content and description
        QXmlStreamAttributes att = reader.attributes();
        for(int i = 0; i < att.length(); i++)
        {
            if( att.at(i).name().toString() == "HREF" || att.at(i).name().toString() == "href")
            {
                qDebug() <<  reader.readElementText() << " = " << att.at(i).value();
            }
        }
    }
}

