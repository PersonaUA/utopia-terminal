#include "order.h"

namespace crp {

Order::Order() { }
Order::Order(const QJsonObject &json) { this->parse(json); }

qreal Order::price() const { return this->m_price; }
qreal Order::amount() const { return this->m_amount; }
qreal Order::value() const { return this->m_value; }

//----------------------------------------------------------------------------------------
void Order::parse(const QJsonObject &json)
{
    m_price = json["price"].toDouble();
    m_amount = json["amount"].toDouble();
    m_value = json["value"].toDouble();
}

}
