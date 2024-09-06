#ifndef SSLECHOCLIENT_H
#define SSLECHOCLIENT_H

#include <QtCore/QObject>
#include <QtWebSockets/QWebSocket>
#include <QtNetwork/QSslError>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QUrl>

#include <QTimer>

QT_FORWARD_DECLARE_CLASS(QWebSocket)

class SslSocket : public QObject
{
    Q_OBJECT

public:
    explicit SslSocket(QObject *parent = nullptr, const QUrl &url = QStringLiteral(""));

    void open(QString auth_token);

private Q_SLOTS:

    void onConnected();
    void onDisconnected();

    void onPong(quint64 elapsedTime, const QByteArray &payload);

    void onTextMessageReceived(QString message);
    void onSslErrors(const QList<QSslError> &errors);


signals:
    void onMessage(QString msg_code, QString msg_text);


private:
    QWebSocket m_webSocket;

    QString m_auth_token;

    QTimer *m_timer;

    void ping_server();
};

#endif // SSLECHOCLIENT_H
