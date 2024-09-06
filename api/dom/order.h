#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "qtqml/qqmlhelpers.h"
//#include "qtqml/qqmlobjectlistmodel.h"
#include <QVariant>
#include <QPair>
//#include "extension.h"


//#include "../lib/qqmlvariantlistmodel.h"

//"order_id": 23299845,
//"amount": 0.0015,
//"price": 59350,
//"value": 89.025,
//"orig_value": 89.025,
//"date_reg": 1714731900601,
//"task": "sell",
//"status": "open",
//"orig_amount": 0.0015,
//"cur": "btc",
//"ecur": "usdt",
//"price_executed": 0,
//"value_executed": 0



namespace dom {

class Order : public QObject
{
    Q_OBJECT
    //QML_WRITABLE_PROPERTY (qreal,     order_id)
    //QML_WRITABLE_PROPERTY (qreal,     price)
    //QML_WRITABLE_PROPERTY (qreal,     amount)
    //QML_WRITABLE_PROPERTY (qreal,     value)

    QML_WRITABLE_PROPERTY (uint,     order_id)
    QML_WRITABLE_PROPERTY (qreal,    amount)
    QML_WRITABLE_PROPERTY (qreal,    price)
    QML_WRITABLE_PROPERTY (qreal,    value)

    QML_WRITABLE_PROPERTY (qreal,    orig_value)
    QML_WRITABLE_PROPERTY (uint,     date_reg)
    QML_WRITABLE_PROPERTY (QString,  task)
    QML_WRITABLE_PROPERTY (QString,  status)
    QML_WRITABLE_PROPERTY (uint,     orig_amount)
    QML_WRITABLE_PROPERTY (QString,  cur)
    QML_WRITABLE_PROPERTY (QString,  ecur)
    QML_WRITABLE_PROPERTY (qreal,    price_executed)
    QML_WRITABLE_PROPERTY (qreal,    value_executed)


public slots:


public:

    explicit Order(QObject * parent = NULL) : QObject (parent) {

        //m_expand = false;
        //m_ext = new QQmlObjectListModel<Extension>(parent, "ext", "key");
    }

    void parse(const QJsonObject &json);
};

}

