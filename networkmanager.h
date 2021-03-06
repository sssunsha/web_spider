#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include "constant.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "parsemanager.h"


class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = 0);
    void init();
    void start2Fetch(QString ul);
    void start2Fetch();
    void startFetchNextGoal();

signals:

public slots:
    void handleNetworkReply(QNetworkReply* reply);
    void hadleAuthenticationRequired(QNetworkReply * reply, QAuthenticator * authenticator);
    void handleEncrypted(QNetworkReply * reply);
    void handleNetworkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible);
    void handlePreSharedKeyAuthenticationRequired(QNetworkReply * reply, QSslPreSharedKeyAuthenticator * authenticator);
    void handleProxyAuthenticationRequired(const QNetworkProxy & proxy, QAuthenticator * authenticator);
    void handleSSLErrors(QNetworkReply * reply, const QList<QSslError> & errors);

private:
     QNetworkAccessManager* m_net_access_manager;
     ParseManager* m_pm;
};

#endif // NETWORKMANAGER_H
