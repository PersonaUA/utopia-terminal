#include "panel.h"

namespace crp {

Panel::Panel() { }
Panel::Panel(const QJsonObject &json) { this->parse(json); }

QList<Order> Panel::bookSell() const { return this->m_book_sell; }
QList<Order> Panel::bookBuy() const { return this->m_book_buy; }

//----------------------------------------------------------------------------------------
void Panel::parse(const QJsonObject &json)
{
    if (json["success"].toBool() == false)
        return;

    QJsonObject result = json["result"].toObject();

    QJsonArray bool_sell = result["book_sell"].toArray();
    QJsonArray book_buy = result["book_buy"].toArray();

    //qDebug() << "BOOK_SELL";
    foreach (const QJsonValue & jsonValue, bool_sell)
    {
        crp::Order order(jsonValue.toObject());

        //qDebug() << "order " << order.price() << order.amount() << order.value();

        this->m_book_sell << order;
    }

    //qDebug() << "BOOK_BUY";
    foreach (const QJsonValue & jsonValue, book_buy)
    {
        crp::Order order(jsonValue.toObject());

        //qDebug() << "order " << order.price() << order.amount() << order.value();

        this->m_book_buy << order;
    }

    this->m_cur = result["cur"].toString();
    this->m_ecur = result["ecur"].toString();
    this->m_pair = result["pair"].toString();
}

}
