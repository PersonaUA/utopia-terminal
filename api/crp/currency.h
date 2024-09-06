#pragma once

#include <QObject>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>




#include "qtqml/qqmlhelpers.h"
#include <QVariant>
#include <QDebug>

namespace crp {

class Currency : public QObject
{
    Q_OBJECT
    QML_WRITABLE_PROPERTY (uint,    currency_id)
    QML_WRITABLE_PROPERTY (QString,        name)
    QML_WRITABLE_PROPERTY (uint,          round)

public:
    explicit Currency(QObject* parent = nullptr) {

        //m_key = key;
        //m_val = val;
    }

    void parse(const QJsonObject &json);

};

}

//#pragma once

//#include <QObject>
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonArray>

//#include "qtqml/qqmlhelpers.h"

////#include "qtqml/qqmlobjectlistmodel.h"


//namespace crp {

//class Currency : public QObject
//{
//    Q_OBJECT
//    QML_WRITABLE_PROPERTY (uint,         currency_id)
//    QML_WRITABLE_PROPERTY (QString,             name)
//    QML_WRITABLE_PROPERTY (QString,         fullname)
//    QML_WRITABLE_PROPERTY (QString,          appname)
//    QML_WRITABLE_PROPERTY (QString,             icon)

//    QML_WRITABLE_PROPERTY (uint,               round)

//    QML_WRITABLE_PROPERTY (qreal,        deposit_fee)
//    QML_WRITABLE_PROPERTY (qreal,        deposit_min)
//    QML_WRITABLE_PROPERTY (qreal,       withdraw_fee)
//    QML_WRITABLE_PROPERTY (qreal,   withdraw_fee_pro)
//    QML_WRITABLE_PROPERTY (qreal,       withdraw_min)

//    QML_WRITABLE_PROPERTY (uint,        address_size)

//    QML_WRITABLE_PROPERTY (qreal,            min_fee)

//    QML_WRITABLE_PROPERTY (bool,              enable)
//    QML_WRITABLE_PROPERTY (bool,                show)


//public:
//    explicit Currency (QObject * parent = NULL) : QObject (parent) {

//    }


//    //explicit Currency(QObject *parent = nullptr, const QJsonObject json = *new QJsonObject());

//    //Currency();
//    //Currency(const QJsonObject &json);

//    void parse(const QJsonObject &json);


//    //explicit Currency(QObject * parent = nullptr, uint currency_id = 0) : QObject (parent) {

//      //  m_currency_id = currency_id;
//        //m_expand = false;
//        //m_ext = new QQmlObjectListModel<Extension>(parent, "ext", "key");
//    //}


//private:


//};

//}
