// UTOPIA PROJECT

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

//#include "../_common/net/net.h"
#include "api/crp/crp.h"
#include "api/net/sslsocket.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //const QUrl url(u"qrc:/Utopia/main.qml"_qs);
    const QUrl url(QStringLiteral("qrc:/main.qml"));


    Crp crp;
    engine.rootContext()->setContextProperty("crp", &crp);



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);


    //SslSocket client(QUrl(QStringLiteral("wss://crp.is:8181/socket.io/?EIO=3&transport=websocket")));
    //Q_UNUSED(client);

    return app.exec();
}
