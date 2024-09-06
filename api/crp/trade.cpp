#include "trade.h"

namespace crp {

HistoryTrade::HistoryTrade() { }
HistoryTrade::HistoryTrade(const QJsonObject &json) { this->parse(json); }

QString HistoryTrade::record_id() const { return this->m_record_id; }
bool HistoryTrade::is_buy() const { return this->m_is_buy; }

qreal HistoryTrade::price() const { return this->m_price; }
qreal HistoryTrade::amount() const { return this->m_amount; }
qreal HistoryTrade::value() const { return this->m_value; }

QString HistoryTrade::created_at() const { return this->m_created_at; }

QString HistoryTrade::record_type() const { return this->m_record_type; }

//----------------------------------------------------------------------------------------
void HistoryTrade::parse(const QJsonObject &json)
{
    m_record_id = json["record_id"].toString();
    m_is_buy = (json["record_type"].toString() == "buy") ? true : false;

    m_price = json["price"].toDouble();
    m_amount = json["amount"].toDouble();
    m_value = json["value"].toDouble();

    auto dt = json["created_at"].toInteger();    

    m_created_at = QDateTime::fromMSecsSinceEpoch(json["created_at"].toInteger()).toLocalTime().time().toString("hh:mm:ss");

    m_record_type = json["record_type"].toString();
}


}
