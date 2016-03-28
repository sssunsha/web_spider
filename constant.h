#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>
#include <QDebug>
#include <QObject>

// working type:
// 1. track: just to check the resouce information, and collect them
// 2. download: download the resource

enum CHECK_TYPE {
    E_UNCHECK,
    E_CHECKED,
};

// resorce state
// 1. unknown
// 2. tracked : is a resource, have been tracked, but not plan to download
// 3. need download : plan to download
// 4. downloading : is in download
// 5. downloaded
enum RESOURCE_STATE {
    E_UNKNOW,
    E_TRACKED,
    E_NEED_DOWNLOAD,
    E_DOWNLOADING,
    E_DOWNLOADED
};


const QString webUrl_user = QString("www.linuxidc.com");
const QString webUrl_password = QString("www.linuxidc.com");
const QString txtSplitMark = QString("-----");

class Constant{
public:
    static QString web_url;
};

#endif // CONSTANT_H

