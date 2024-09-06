#include "order.h"

namespace dom {

//----------------------------------------------------------------------------------------
void Order::parse(const QJsonObject &json)
{
    m_price = json["price"].toDouble();
    m_amount = json["amount"].toDouble();
    m_value = json["value"].toDouble();
}

}
