#include "socket.h"

//-----------------------------------------------------------------------------
Socket::Socket(const QUrl &url, QString auth_token, QObject *parent) : QObject(parent), m_url(url), m_auth_token(auth_token)
{
    qDebug() << "WebSocket server:" << url;

    m_webSocket = new QWebSocket(QString(), QWebSocketProtocol::VersionLatest, this);    

    connect(m_webSocket, &QWebSocket::sslErrors, this, &Socket::onSslErrors);    

    connect(m_webSocket, &QWebSocket::disconnected, this, &Socket::onDisconnected);
    connect(m_webSocket, &QWebSocket::stateChanged, this, &Socket::onStateChanged);

    connect(m_webSocket, QOverload<const QList<QSslError>&>::of(&QWebSocket::sslErrors), this, &Socket::onSslErrors);

    connect(m_webSocket, &QWebSocket::connected, this, &Socket::onConnected);
    connect(m_webSocket, &QWebSocket::disconnected, this, &Socket::closed);


    QSslConfiguration sslConfiguration = m_webSocket->sslConfiguration();
    sslConfiguration.setPeerVerifyMode(QSslSocket::VerifyPeer);
    m_webSocket->setSslConfiguration(sslConfiguration);
    m_webSocket->ignoreSslErrors();


    m_webSocket->setPauseMode(QAbstractSocket::PauseNever);

    m_webSocket->open(QUrl(url));    
}
//-----------------------------------------------------------------------------
void Socket::onSslErrors(const QList<QSslError> &errors)
{
    qDebug() << m_webSocket->errorString();
}
//-----------------------------------------------------------------------------
void Socket::onError(const QAbstractSocket::SocketError &socketError)
{
    qDebug() << m_webSocket->errorString() << " Error:" << socketError;
}
//-----------------------------------------------------------------------------
void Socket::onDisconnected()
{
    qDebug() << m_webSocket->errorString() << " CloseCode is >>> " << m_webSocket->closeCode();
}
//-----------------------------------------------------------------------------
void Socket::onStateChanged(QAbstractSocket::SocketState socketState)
{
    qDebug() << "StateChanged : " << socketState;
}
//-----------------------------------------------------------------------------
void Socket::onConnected()
{
    qDebug() << "WebSocket connected";

    connect(m_webSocket, &QWebSocket::textMessageReceived, this, &Socket::onTextMessageReceived);

    QString msg_chat_join = "[\"chat-join\",{\"auth_token\":\"" + m_auth_token + "\",\"group\":\"main\"}]";

    QString msg_user_join = "[\"user-join\",\"" + m_auth_token + "\"]";

    qDebug() << msg_chat_join;

    m_webSocket->sendTextMessage(msg_chat_join);

    qDebug() << "Message Chat Join Sended";
}

//-----------------------------------------------------------------------------
void Socket::onTextMessageReceived(QString message)
{
    qDebug() << "Message received:" << message;    
}
//-----------------------------------------------------------------------------
