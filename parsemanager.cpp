#include "parsemanager.h"
#include <QXmlStreamAttributes>

ParseManager::ParseManager(QObject *parent) : QObject(parent)
{
    this->m_tm = new TreeManager(this);
}

void ParseManager::startParsing(QString str, QUrl baseUrl)
{
    QXmlStreamReader reader(str);
    while (!reader.atEnd()) {
        reader.readNext();

        if (reader.isStartElement())
        {
            //                 qDebug() << reader.name().toString() << ","
            //                      << reader.text().toString();
            parsingHrefElement(reader, baseUrl.toString());

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

void ParseManager::parsingHrefElement(QXmlStreamReader &reader, QString baseUrlStr)
{
    if(reader.name().toString() == "A" || reader.name().toString() == "a")
    {
        // go to parsing the herf content and description
        QXmlStreamAttributes att = reader.attributes();
        for(int i = 0; i < att.length(); i++)
        {
            if( att.at(i).name().toString() == "HREF" || att.at(i).name().toString() == "href")
            {
                QString linkStr;
                linkStr.append(baseUrlStr);
                linkStr.append(att.at(i).value());

                qDebug() <<  reader.readElementText() << " = " << linkStr;
            }
        }
    }
}


