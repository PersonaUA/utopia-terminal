#ifndef PANEL_H
#define PANEL_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "api/crp/order.h"

namespace crp {


//-----------------------------------------------------------------------------
struct Volumes {
    qreal sell;
    qreal buy;
};
//-----------------------------------------------------------------------------
class Panel
{

public:
    Panel();
    Panel(const QJsonObject &json);

    void parse(const QJsonObject &json);

  //  QList<order> orders() const;

    QList<Order> bookSell() const;
    QList<Order> bookBuy() const;



private:
    QList<Order> m_book_sell;
    QList<Order> m_book_buy;

    Volumes m_volumes;

    QDateTime m_time;
    QString m_cur;
    QString m_ecur;
    QString m_pair;

};

} // end of namespace

#endif // PANEL_H
