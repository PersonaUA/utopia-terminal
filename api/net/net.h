#ifndef NET_H
#define NET_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkCookie>
#include <QNetworkCookieJar>

#include <QDomDocument>

class Net : public QObject
{
    Q_OBJECT

public:
    explicit Net(QObject *parent = 0);

public slots:
    void setCookie(QString cname, QString cvalue);


    void getData(QString str_url);



    void postDataXml(QString str_url, QString post_data);
    void postDataForm(QString str_url, QUrlQuery postData);

    void onResult(QNetworkReply *reply);

signals:
    void onReady(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QNetworkCookieJar *m_CookieJar;
    QNetworkCookie *m_cookie;
};

#endif // NET_H
