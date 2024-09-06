#include "net.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>

#define PK "979F97573494F3FE3AC3F6690AA064402CE386CC6BE4873CC7DD2752B53F0C78"
#define PASS "HUIhnirefnj987ydgsyegi#$#"
//-----------------------------------------------------------------------------
Net::Net(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();
    m_CookieJar = new QNetworkCookieJar();
    m_cookie = new QNetworkCookie();


    // подключаем сигнал о завершении получения данных к обработчику полученного ответа
    connect(manager, &QNetworkAccessManager::finished, this, &Net::onResult);
}
//-----------------------------------------------------------------------------

void Net::setCookie(QString cname, QString cvalue)
{
    m_cookie->setName(cname.toUtf8());
    m_cookie->setValue(cvalue.toUtf8());

    //m_cookie(cname.toUtf8(), cvalue.toUtf8());

    //QList<QNetworkCookie> cookies;
    //cookies.append(cookie);

    qDebug() << "Cookie = " << cvalue;

    QNetworkCookieJar *mCookieJar = new QNetworkCookieJar();
    mCookieJar->insertCookie(*m_cookie);

    auto cj = manager->cookieJar();
    cj->insertCookie(*m_cookie);


    //manager->setCookieJar(mCookieJar);
}

//-----------------------------------------------------------------------------
void Net::postDataXml(QString str_url, QString post_data)
{
    QUrl url(str_url);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");

    manager->post(request, post_data.toUtf8());
}

//-----------------------------------------------------------------------------
void Net::getData(QString str_url)
{
    QUrl url(str_url);
    QNetworkRequest request(url);

    manager->get(request);
}
//------------------------------------------------------------------------------------------------------------------
void Net::postDataForm(QString str_url, QUrlQuery postData)
{
    QUrl url(str_url);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}

//------------------------------------------------------------------------------------------------------------------
void Net::onResult(QNetworkReply *reply)
{
    if(reply->error()){

        qDebug() << "ERROR";
        qDebug() << reply->errorString();

    } else {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

        switch (statusCode) {
            case 200:

                emit onReady(reply);

                break;

            default:
                qDebug() << statusCode;
        }
    }
}
