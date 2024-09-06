#include "sslsocket.h"

#include <QtCore/QDebug>
#include <QtWebSockets/QWebSocket>
#include <QCoreApplication>

#include <QRegularExpression>
#include <QStringLiteral>

#include <QTime>
#include <QByteArray>


QT_USE_NAMESPACE



//-----------------------------------------------------------------------------
SslSocket::SslSocket(QObject *parent, const QUrl &url) : QObject(parent)
{
    connect(&m_webSocket, &QWebSocket::connected, this, &SslSocket::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &SslSocket::onDisconnected);
    connect(&m_webSocket, &QWebSocket::pong, this, &SslSocket::onPong);
    connect(&m_webSocket, QOverload<const QList<QSslError>&>::of(&QWebSocket::sslErrors), this, &SslSocket::onSslErrors);
}
//-----------------------------------------------------------------------------
void SslSocket::open(QString auth_token)
{
    m_auth_token = auth_token;

    m_webSocket.open(QUrl(QStringLiteral("wss://crp.is:8181/socket.io/?EIO=3&transport=websocket")));
    // m_webSocket.open(QUrl(url));

    qDebug() << "WebSocket open...";
}
//-----------------------------------------------------------------------------
void SslSocket::onConnected()
{
    qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &SslSocket::onTextMessageReceived);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, QOverload<>::of(&SslSocket::ping_server));

    qDebug() << QTime::currentTime();

    m_timer->start(25000);

    QString user_join = "42[\"user-join\",\"" + m_auth_token + "\"]";
    QString trade_leave = "42[\"trade-leave\",\"btc_usdt\"]";
    QString trade_join = "42[\"trade-join\",\"btc_usdt\"]";

    m_webSocket.sendTextMessage(user_join);
    m_webSocket.sendTextMessage(trade_leave);
    m_webSocket.sendTextMessage(trade_join);

}
//-----------------------------------------------------------------------------
void SslSocket::onDisconnected()
{
    qDebug() << m_webSocket.errorString() << " CloseCode is >>> " << m_webSocket.closeReason();

    qDebug() << QTime::currentTime();
}


//-----------------------------------------------------------------------------
void SslSocket::onPong(quint64 elapsedTime, const QByteArray &payload)
{
    qDebug() << "pong " << QString(payload);
}
//-----------------------------------------------------------------------------
void SslSocket::ping_server()
{
    m_webSocket.sendTextMessage(QStringLiteral("2").toUtf8());

    //m_webSocket.ping(); //(QStringLiteral("2").toUtf8());
    qDebug() << "ping";
}
//-----------------------------------------------------------------------------
void SslSocket::onTextMessageReceived(QString message)
{
    QString matched_code = "";
    QString matched_text = "";

    static QRegularExpression re_code("^(.*?)\\[");
    QRegularExpressionMatch match_code = re_code.match(message);

    if (match_code.hasMatch()) {
        matched_code = match_code.captured(1);
    }


    static QRegularExpression re_text("(?<=\\[).*(?=\\])");
    QRegularExpressionMatch match_text = re_text.match(message);


    if (match_text.hasMatch()) {
        matched_text = match_text.captured(0);
    }

    emit onMessage(matched_code, matched_text);


  //  qDebug() << "Message received:" << message;
    //qApp->quit();
}
//-----------------------------------------------------------------------------
void SslSocket::onSslErrors(const QList<QSslError> &errors)
{
    Q_UNUSED(errors);

    // WARNING: Never ignore SSL errors in production code.
    // The proper way to handle self-signed certificates is to add a custom root
    // to the CA store.
    qDebug() << m_webSocket.errorString();

    m_webSocket.ignoreSslErrors();
}

