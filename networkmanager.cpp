#include "networkmanager.h"
#include <QLoggingCategory>
#include <QAuthenticator>
#include <QUrl>

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{
    this->m_pm = new ParseManager(this);
}

void NetworkManager::init()
{
  m_net_access_manager = new QNetworkAccessManager(this);
  QLoggingCategory::setFilterRules("qt.network.ssl.warning=false");

  QObject::connect(m_net_access_manager, SIGNAL(finished(QNetworkReply*)),
                   this, SLOT(handleNetworkReply(QNetworkReply*)));

  QObject::connect(m_net_access_manager, SIGNAL(authenticationRequired(QNetworkReply*, QAuthenticator* )),
                   this, SLOT(hadleAuthenticationRequired(QNetworkReply*, QAuthenticator*)));

  QObject::connect(m_net_access_manager, SIGNAL(encrypted(QNetworkReply*)),
                   this, SLOT(handleEncrypted(QNetworkReply*)));

  QObject::connect(m_net_access_manager, SIGNAL(networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)),
                   this, SLOT(handleNetworkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility)));

  QObject::connect(m_net_access_manager, SIGNAL(preSharedKeyAuthenticationRequired(QNetworkReply*, QSslPreSharedKeyAuthenticator*)),
                   this, SLOT(handlePreSharedKeyAuthenticationRequired(QNetworkReply*, QSslPreSharedKeyAuthenticator*)));

  QObject::connect(m_net_access_manager, SIGNAL(proxyAuthenticationRequired(const QNetworkProxy&, QAuthenticator*)),
                   this, SLOT(handleProxyAuthenticationRequired(const QNetworkProxy&, QAuthenticator*)));

  QObject::connect(m_net_access_manager, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError>&)),
                   this, SLOT(handleSSLErrors(QNetworkReply*, const QList<QSslError>&)));

}

void NetworkManager::start2Fetch(QString url)
{
    qDebug() << "[start2Fetch] -->" << url;
    m_net_access_manager->get(QNetworkRequest(QUrl(url)));

}

void NetworkManager::start2Fetch()
{
    start2Fetch(webUrl);
}

void NetworkManager::startFetchNextGoal()
{
    // go on to fetch for the next goal
    QString goalStr = this->m_pm->getTreeManager()->popOneTrackGoal();
    if(!goalStr.isEmpty())
    {
        start2Fetch(goalStr);
    }
    else
    {
        // finish all the work
        qDebug() <<"";
        qDebug() << "-------------------------------";
        qDebug() << "[all finished ...]";
        qDebug() << "-------------------------------";
        this->m_pm->getTreeManager()->printTreeMap();
    }
}

void NetworkManager::handleNetworkReply(QNetworkReply *reply)
{
    QVariant statusCodeV =  reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if(statusCodeV == 200)
    {
        qDebug() << "[handleNetworkReply] ok ....";
        QByteArray bytes = reply->readAll();
        QString data = QString::fromUtf8(bytes);

        this->m_pm->startParsing(data, reply->request().url().toString());
        startFetchNextGoal();
    }
    else
    {
        qDebug() << "[handleNetworkReply] failed ..." << statusCodeV;
        // failed so go on to fetch the next goal
        startFetchNextGoal();
    }
}

void NetworkManager::hadleAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qDebug() << "[hadleAuthenticationRequired]";
    authenticator->setUser(webUrl_user);
    authenticator->setPassword(webUrl_password);
}

void NetworkManager::handleEncrypted(QNetworkReply *reply)
{
    qDebug() << "[handleEncrypted]";
}

void NetworkManager::handleNetworkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    qDebug() << "[handleNetworkAccessibleChanged]";
}

void NetworkManager::handlePreSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    qDebug() << "[handlePreSharedKeyAuthenticationRequired]";
}

void NetworkManager::handleProxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    qDebug() << "[handleProxyAuthenticationRequired]";
}

void NetworkManager::handleSSLErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    qDebug() << "[handleSSLErrors]";
}

