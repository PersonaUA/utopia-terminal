#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

#include <QUrlQuery>




#include "api/dom/balance.h"
#include "qtqml/qqmlobjectlistmodel.h"

#include "api/net/net.h"
#include "api/net/sslsocket.h"


#include "api/crp/user.h"
#include "api/crp/panel.h"
#include "api/crp/balance.h"

#include "api/crp/history.h"
#include "api/crp/trade.h"

#include "api/dom/order.h"
#include "api/dom/trade_item.h"
#include "api/dom/book.h"


class Crp : public QObject
{
    Q_OBJECT
    QML_OBJMODEL_PROPERTY(dom::Book,              sell_book)
    QML_OBJMODEL_PROPERTY(dom::Book,              buy_book)

    QML_OBJMODEL_PROPERTY(dom::Order,              orders)




    QML_OBJMODEL_PROPERTY(dom::Order,              sell_orders)
    QML_OBJMODEL_PROPERTY(dom::Order,               buy_orders)


    QML_OBJMODEL_PROPERTY(dom::TradeItem,  history_trade_items)

    QML_OBJMODEL_PROPERTY(dom::Balance,  balances)


    // USDT
    QML_WRITABLE_PROPERTY (QString,   buy_name)
    QML_WRITABLE_PROPERTY (uint,   buy_round)    

    QML_WRITABLE_PROPERTY (qreal,   buy_balance)
    QML_WRITABLE_PROPERTY (qreal,   buy_balance_reserve)

    QML_WRITABLE_PROPERTY (qreal,   buy_price)
    QML_WRITABLE_PROPERTY (qreal,   buy_amount)

    // BTC
    QML_WRITABLE_PROPERTY (QString,   sell_name)
    QML_WRITABLE_PROPERTY (uint,   sell_round)

    QML_WRITABLE_PROPERTY (qreal,   sell_balance)
    QML_WRITABLE_PROPERTY (qreal,   sell_balance_reserve)

    QML_WRITABLE_PROPERTY (qreal,   sell_price)
    QML_WRITABLE_PROPERTY (qreal,   sell_amount)


    //QML_WRITABLE_PROPERTY (qreal,   spread)
    Q_PROPERTY(qreal spread READ spread NOTIFY spreadChanged)


public:
    explicit Crp(QObject *parent = nullptr);





public slots:
    void login(QString pk, QString pass);

    void balance();
    void panel();
    void history_trade();

    qreal spread();

    void load_orders();

    void cancel_order(uint order_id);

    void buy(qreal price, qreal amount);
    void sell(qreal price, qreal amount);

    void change_bid(uint order_id, qreal price, qreal amount, QString task);

    void open_socket(QString auth_token);

private slots:
    void readyRead(QNetworkReply *reply);
    void onSocketMessage(QString msg_code, QString msg_text);

signals:
    void spreadChanged();

private:
    Net *net;

    qreal m_spread;

    QList<dom::Book *> m_list_sale_book;
    QList<dom::Book *> m_list_buy_book;

    qreal m_new_price;
    qreal m_new_amount;
    QString m_task;

    SslSocket *m_ssl_socket;

    crp::User m_user;
    crp::Balance *m_balance;
    crp::Panel m_panel;
    crp::History m_history;

    QString m_state = "ready";

    // PARSE WS
    void ws_book_parse(const QJsonObject &json);

    void ws_balance_parse(const QJsonObject &json);

    void ws_trade_history_parse(const QJsonObject &json);
    void ws_orders_parse(const QJsonObject &json);
    void ws_order_update(const QJsonObject &json, dom::Order* dom_order);


    // PARSE XHR
    void parse_login(const QJsonDocument &json);
    void parse_balance(const QJsonObject &json);
    void parse_orders(const QJsonDocument &json);
    bool parse_order_cancel(const QJsonDocument &json);
    bool parse_buy_sell(const QJsonDocument &json);
    void parse_panel(const QJsonDocument &json);
    void parse_history_trade(const QJsonDocument &json);


    void append_book(dom::Book* item, QString type);
    void remove_book_item(qreal price, QString type);

    QString auth_token = "";
};
