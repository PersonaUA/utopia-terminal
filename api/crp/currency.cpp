#include "currency.h"

namespace crp {

//Currency::Currency(QObject *parent, const QJsonObject json) : QObject(parent)
//{}

//Currency::Currency(const QJsonObject &json) { this->parse(json); }



//----------------------------------------------------------------------------------------
void Currency::parse(const QJsonObject &json)
{
    QJsonObject currency = json["currency"].toObject();

    this->m_currency_id = currency["id"].toInteger();
    this->m_name = currency["name"].toString();

    this->m_round = currency["round"].toInteger();

//    this->m_fullname = currency["fullname"].toString();
//    this->m_appname = currency["appname"].toString();
//    this->m_icon = currency["icon"].toString();

//    this->m_round = currency["round"].toInteger();

//    this->m_deposit_fee = currency["round"].toDouble();
//    this->m_deposit_min = currency["deposit_min"].toDouble();
//    this->m_withdraw_fee = currency["withdraw_fee"].toDouble();
//    this->m_withdraw_fee_pro = currency["withdraw_fee_pro"].toDouble();
//    this->m_withdraw_min = currency["withdraw_min"].toDouble();

//    this->m_address_size = currency["address_size"].toInteger();

//    this->m_min_fee = currency["min_fee"].toDouble();

//    this->m_enable = currency["enable"].toBool();
//    this->m_show = currency["show"].toBool();
}


}

