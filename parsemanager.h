#ifndef PARSEMANAGER_H
#define PARSEMANAGER_H
#include "constant.h"
#include "treemanager.h"
#include <QObject>
#include <QXmlStreamReader>

class ParseManager : public QObject
{
    Q_OBJECT
public:
    explicit ParseManager(QObject *parent = 0);
    void startParsing(QString str, QString baseUrl);
    void startRegexParsing(QString str, QString baseUrl);
    TreeManager* getTreeManager();
signals:

public slots:

private:
    void parsingHrefElement(QXmlStreamReader& reader, QString baseUrlStr);


    TreeManager* m_tm;
};

#endif // PARSEMANAGER_H
