#include "parsemanager.h"
#include <QXmlStreamAttributes>
#include <QRegExp>

ParseManager::ParseManager(QObject *parent) : QObject(parent)
{
    this->m_tm = new TreeManager(this);
}

void ParseManager::startParsing(QString str, QString baseUrl)
{
    QXmlStreamReader reader(str);
    while (!reader.atEnd()) {
        reader.readNext();

        if (reader.isStartElement())
        {
//            parsingHrefElement(reader, baseUrl);
            parsingHrefElement(reader, webUrl);

        }
        else if (reader.hasError())
        {
//            qDebug() << "[startParsing] reader error: " << reader.errorString() << endl;
        }
        else if (reader.atEnd())
        {
//            qDebug() << "[startParsing] Reached end, done" << endl;
        }
    }

        // finish the parsing, print the map for check
    //    this->m_tm->printTreeMap();
}


//TODO: not finished
// do the parsing with regex
void ParseManager::startRegexParsing(QString str, QString baseUrl)
{
        // look for the <a>...</a>, and get the infromation

    QRegExp rx("(<a href=[\\S]+</a>)",  Qt::CaseInsensitive);
    QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
        list << rx.cap(1);
        pos += rx.matchedLength();
    }
    qDebug() << list;
}

TreeManager *ParseManager::getTreeManager()
{
    return this->m_tm;
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
                QString url = baseUrlStr;
                url.remove(url.length()-1, 1);
                linkStr.append(url);
                linkStr.append(att.at(i).value());

//                qDebug() <<"[parsingHrefElement] "<<  reader.readElementText() << " = " << linkStr;
                this->m_tm->addTreeNode(baseUrlStr, reader.readElementText(), linkStr);
            }
        }
    }
}


