#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

//#include <QQmlHelpers>
#include "qtqml/qqmlhelpers.h"
#include "qtqml/qqmlobjectlistmodel.h"

#include "api/crp/currency.h"

#include "api/dom/balance.h"

namespace crp {

class Balance : public QObject
{
    Q_OBJECT
    QML_WRITABLE_PROPERTY (uint,         currency_id)

    QML_WRITABLE_PROPERTY (QString,         fullname)
    QML_WRITABLE_PROPERTY (QString,          appname)
    QML_WRITABLE_PROPERTY (QString,             icon)

    QML_OBJMODEL_PROPERTY (crp::Currency,   currencies) // array
    QML_OBJMODEL_PROPERTY(dom::Balance,       balances)



public:
    explicit Balance(QObject *parent = nullptr);
//    explicit Balance(QObject *parent = nullptr, const QJsonObject json = *new QJsonObject())
//    {

//    }


    //Balance();
    //Balance(const QJsonObject &json);

    void parse(const QJsonObject &json);

    //explicit Balance(QObject * parent = nullptr) : QObject (parent) {

    //}

};


}
