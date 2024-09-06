#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "api/crp/trade.h"

namespace crp {


class History
{
public:
    History();
    History(const QJsonObject &json);

    void parse(const QJsonObject &json);

    QList<HistoryTrade> historyTradeItems() const;

private:
    QList<HistoryTrade> m_historyTradeItems;



};

}
