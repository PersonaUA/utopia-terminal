#include "history.h"

namespace crp {

History::History() { }
History::History(const QJsonObject &json) { this->parse(json); }

QList<HistoryTrade> History::historyTradeItems() const { return this->m_historyTradeItems; }
//----------------------------------------------------------------------------------------
void History::parse(const QJsonObject &json)
{
    if (json["success"].toBool() == false)
        return;

    QJsonObject result = json["result"].toObject();
    QJsonArray items = result["items"].toArray();

    foreach (const QJsonValue & jsonValue, items)
    {
        crp::HistoryTrade item(jsonValue.toObject());

        //qDebug() << "order " << order.price() << order.amount() << order.value();

        this->m_historyTradeItems << item;
    }


}


}
