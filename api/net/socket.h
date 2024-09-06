#pragma once


#include <QtWebSockets/QWebSocket>

#include <QtNetwork/QSslError>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QUrl>


class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(const QUrl &url, QString auth_token, QObject *parent = nullptr);


Q_SIGNALS:
    void closed();

private Q_SLOTS:

    void onError(const QAbstractSocket::SocketError &socketError);
    void onSslErrors(const QList<QSslError> &errors);

    void onDisconnected();
    void onStateChanged(QAbstractSocket::SocketState socketState);

    void onConnected();
    void onTextMessageReceived(QString message);

private:
    QWebSocket* m_webSocket;
    QUrl m_url;

    QString m_auth_token;

};


