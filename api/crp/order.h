#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace crp {

class Order
{
public:
    Order();
    Order(const QJsonObject &json);

    void parse(const QJsonObject &json);

    qreal price() const;
    void set_price(const qreal &value);

    qreal amount() const;
    void set_amount(const qreal &value);

    qreal value() const;
    void set_value(const qreal &value);


private:
    qreal m_price;
    qreal m_amount;
    qreal m_value;

};

}

