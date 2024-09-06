#include "balance.h"

namespace crp {

Balance::Balance(QObject *parent) : QObject(parent)
{
    m_currencies = new QQmlObjectListModel<crp::Currency>(parent, "currencies", "currency_id");
    m_balances = new QQmlObjectListModel<dom::Balance>(parent, "balances", "name");
}

void Balance::parse(const QJsonObject &json)
{
    if (json["success"].toBool() != true)
        return;


    QJsonObject result = json["result"].toObject();
    QJsonArray jsonArray = result["allbalance"].toArray();

    foreach (const QJsonValue & jsonValue, jsonArray)
    {
        QJsonObject json_currency = jsonValue.toObject();

        crp::Currency* currency = new crp::Currency;
        currency->parse(json_currency);

        get_currencies()->append(currency);

        dom::Balance* dom_balance = new dom::Balance;

        dom_balance->set_currency_id(json_currency["id"].toInt());

        dom_balance->set_balance(json_currency["balance"].toDouble());
        dom_balance->set_reserve(json_currency["reserve"].toDouble());

        dom_balance->set_name(currency->get_name());
        dom_balance->set_round(currency->get_round());

        get_balances()->append(dom_balance);

        qDebug() << dom_balance->get_name() << " " << dom_balance->get_balance();

        //orders::order order(jsonValue.toObject());
        //this->m_orders << order;
        //this->m_map_orders << order.map();
    }
}

}
