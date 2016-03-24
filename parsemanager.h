#ifndef PARSEMANAGER_H
#define PARSEMANAGER_H
#include "constant.h"
#include <QObject>
#include <QXmlStreamReader>

class ParseManager : public QObject
{
    Q_OBJECT
public:
    explicit ParseManager(QObject *parent = 0);
    void startParsing(QString str);
signals:

public slots:

private:
    void parsingHrefElement(QXmlStreamReader& reader);
};

#endif // PARSEMANAGER_H
