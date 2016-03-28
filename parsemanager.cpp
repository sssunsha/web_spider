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


// do the String parsing
void ParseManager::startStringParsing(QString str, QString baseUrl)
{
    // look for <a......</a>
    int posBegin = 0;
    int posEnd = 0;
    QString beginStr = "<a";
    QString endStr = "</a>";

    QString hrefBeginStr = "href=\"";
    QString hrefEndStr = "\"";
    QString nameBeginStr = ">";
    QString nameEndStr = "<";

    int hrefBeingPos = 0;
    int hrefEndPos = 0;
    int nameBeginPos = 0;
    int nameEndPos = 0;

    do {
        posBegin = str.indexOf(beginStr, posEnd, Qt::CaseInsensitive);
        if(posBegin >= 0)
        {
            posEnd = str.indexOf(endStr, posBegin, Qt::CaseInsensitive);
            if(posEnd >=0)
            {
                // get the <a>...</a> sentence
                QString aStr = str.mid(posBegin, posEnd-posBegin+4);
//                qDebug() << aStr;
                // parsing for the url and name
                hrefBeingPos = aStr.indexOf(hrefBeginStr, 0, Qt::CaseInsensitive);
                hrefEndPos = aStr.indexOf(hrefEndStr, hrefBeingPos+ 7, Qt::CaseInsensitive);
                nameBeginPos = aStr.indexOf(nameBeginStr, 0, Qt::CaseInsensitive);
                nameEndPos = aStr.indexOf(nameEndStr, nameBeginPos, Qt::CaseInsensitive);


                QString linkStr;
                QString url = webUrl;
                url.remove(url.length()-1, 1);
                linkStr.append(url);
                linkStr.append(aStr.mid(hrefBeingPos+6, hrefEndPos-hrefBeingPos-6));
//                qDebug() << linkStr;
                QString nameStr = aStr.mid(nameBeginPos+1, nameEndPos-nameBeginPos-1);
//                qDebug() << nameStr;
                this->m_tm->addTreeNode(webUrl, nameStr, linkStr);
            }
        }
        else
        {
            break;
        }

    }while(posEnd >= 0);

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


