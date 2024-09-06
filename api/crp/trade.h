#pragma once

#include <QObject>
#include <QTime>
#include <QDateTime>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDateTime>


namespace crp {

class HistoryTrade
{
public:
    HistoryTrade();
    HistoryTrade(const QJsonObject &json);

    void parse(const QJsonObject &json);



    QString record_id() const;
    void set_record_id(const QString &value);

    bool is_buy() const;
    void set_is_buy(const bool &value);

    qreal price() const;
    void set_price(const qreal &value);

    qreal amount() const;
    void set_amount(const qreal &value);

    qreal value() const;
    void set_value(const qreal &value);

    QString created_at() const;
    void set_created_at(const QTime &value);

    QString record_type() const;
    void set_record_type(const QString &value);



private:
    QString m_record_id;
    bool m_is_buy;
    qreal m_price;
    qreal m_amount;
    qreal m_value;
    QString m_created_at;

    QString m_record_type;
};

}

