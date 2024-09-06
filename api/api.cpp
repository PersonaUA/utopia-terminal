#include "api.h"
#include <QDateTime>
#include <QtGlobal>

//#define MDNS_TYPE "_esphomelib._tcp"
#define MDNS_TYPE "_esphomelib._tcp"
#define MDNS_TYPE2 "_ewelink._tcp"

Api::Api(QObject* parent) : QObject(parent)
{
    m_devices = new QQmlObjectListModel<Device>(parent, "devices", "dev_id");

    QString zerotypes[] = {"_esphomelib", "_ewelink"};

    for (auto z : zerotypes) {
        QZeroConf* _zeroConf = new QZeroConf();
        //zc.append(_zeroConf);

        connect(_zeroConf, &QZeroConf::serviceAdded, this, &Api::addService);
        connect(_zeroConf, &QZeroConf::serviceRemoved, this, &Api::removeService);
        connect(_zeroConf, &QZeroConf::serviceUpdated, this, &Api::updateService);

        _zeroConf->startBrowser(z + "._tcp", QAbstractSocket::IPv4Protocol);
    }


//    zeroConf = new QZeroConf();
//    zeroConf2 = new QZeroConf();

//    connect(zeroConf, &QZeroConf::serviceAdded, this, &Api::addService);
//    connect(zeroConf, &QZeroConf::serviceRemoved, this, &Api::removeService);
//    connect(zeroConf, &QZeroConf::serviceUpdated, this, &Api::updateService);

//    connect(zeroConf2, &QZeroConf::serviceAdded, this, &Api::addService);
//    connect(zeroConf2, &QZeroConf::serviceRemoved, this, &Api::removeService);
//    connect(zeroConf2, &QZeroConf::serviceUpdated, this, &Api::updateService);


//    zeroConf->startBrowser(MDNS_TYPE, QAbstractSocket::IPv4Protocol);
//    zeroConf2->startBrowser(MDNS_TYPE2, QAbstractSocket::IPv4Protocol);
}

//-----------------------------------------------------------------------------
void Api::addService(QZeroConfService zcs)
{
   // auto f = zcs.data();
    //qDebug() << f->interfaceIndex();

    auto name = zcs->name();
    auto ip = zcs->ip().toString();

    auto port = zcs->port();

    auto domain = zcs->domain();
    auto host = zcs->host();
    auto txt = zcs->txt();

    qDebug() << "TYPE: " << zcs->type();

    //qDebug() << name;
    //qDebug() << ip;
    //qDebug() << port;
    //qDebug() << domain;
    //qDebug() << host;
    qDebug() << txt;

    QByteArray mac_arr = txt.value("mac");

    QString mac;

    for (int i = 0; i < 6; i++)
    {
        mac.append(mac_arr.left(2).toUpper());

        if (mac_arr.size() > 2)
            mac.append(QString(":"));

        mac_arr.remove(0, 2);
    }


    Device* d = new Device;


    d->set_network(txt.value("network"));
    d->set_board(txt.value("board"));


    d->set_ip_addr(ip);
    d->set_name(name);
    d->set_port(port);
    d->set_expand(false);

    d->set_mac(mac);

    d->set_time(QDateTime::currentDateTime().toString("hh:mm:ss"));

    if (zcs->type().contains("esphome")) {

        d->set_dev_id(name);
        //d->set_platform(txt.value("platform"));
        d->set_platform("ESPHOME");

        d->set_esphome_version(txt.value("version"));

    } else if (zcs->type().contains("ewelink")) {

        d->set_platform("SONOFF");

        auto s = name.split("_");
        d->set_dev_id(s[1]);

        d->set_name("SPM-Main");
        d->set_esphome_version(s[1]); // DEVICE ID !!!

        d->set_dev_id(s[1]); // DEVICE ID

        //e->get_ext()->append(new Extension(nullptr, "image_url", image_url));
        auto map = zcs->txt();

        auto val = map.value("id");
        qDebug() << "ID: " << val;
    }

    get_devices()->append(d);
}
//-----------------------------------------------------------------------------
void Api::removeService(QZeroConfService zcs)
{
    qInfo() << "Remove Service: " << zcs->name();


    QQmlObjectListModel<Device>* devices = get_devices();

    Device* d = devices->getByUid(zcs->name());
    devices->remove(d);
}
//-----------------------------------------------------------------------------
void Api::updateService(QZeroConfService zcs)
{
    qInfo() << "Service updated: " << zcs->txt();
}

