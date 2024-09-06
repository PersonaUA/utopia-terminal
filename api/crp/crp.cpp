#include "crp.h"
#include "qurlquery.h"
//-----------------------------------------------------------------------------


#define URL_CRP "https://crp.is:8182"

#define USER_LOGIN "/user/login"
#define USER_LOGOUT "/user/logout"
#define USER_BALANCE "/user/balance"

#define MARKET_PANEL "/market/panel"

#define API_URL "https://crp.is:8182/user/login"


//-----------------------------------------------------------------------------

Crp::Crp(QObject *parent) : QObject(parent)
{
    net = new Net(this);
    connect(net, &Net::onReady, this, &Crp::readyRead);

    set_buy_price(62000);
    set_sell_price(64000);
    set_sell_amount(2);
    set_buy_amount(1);


    m_sell_book = new QQmlObjectListModel<dom::Book>(parent, "sell_book", "price");          // price - key
    m_buy_book = new QQmlObjectListModel<dom::Book>(parent, "buy_book", "price");           // price - key

    m_orders = new QQmlObjectListModel<dom::Order>(parent, "orders", "order_id");

    m_ssl_socket = new SslSocket(parent, QUrl(QStringLiteral("wss://crp.is:8181/socket.io/?EIO=3&transport=websocket")));



    m_sell_orders = new QQmlObjectListModel<dom::Order>(parent, "sell_orders", "order_id");
    m_buy_orders = new QQmlObjectListModel<dom::Order>(parent, "buy_orders", "order_id");

    m_history_trade_items = new QQmlObjectListModel<dom::TradeItem>(parent, "history_trade_items", "record_id");


    //connect(m_ssl_socket, &SslSocket::onMessage, this, &Crp::onSocketMessage);
    //const QString auth_token = "9e0852dc-c1f0-4f54-9d89-c50aa15ae413";
    //net->setCookie("auth_token", auth_token);

   // login();
}
//-----------------------------------------------------------------------------
qreal Crp::spread()
{
    if (get_sell_book()->count() > 0 && get_buy_book()->count() > 0)
    {
        auto top_sell_price = get_sell_book()->at(0)->get_price();
        auto top_buy_price = get_buy_book()->at(0)->get_price();
        m_spread = top_sell_price - top_buy_price;

        return m_spread;

    } else {

        return 0;
    }
}
//-----------------------------------------------------------------------------
void Crp::onSocketMessage(QString msg_code, QString msg_text)
{
    if (msg_text == "") return;

    auto m = "[" + msg_text + "]";

    QJsonDocument jsonDoc = QJsonDocument::fromJson(m.toUtf8());

    auto msg_type = jsonDoc[0].toString();
    QJsonObject jsonObj = jsonDoc[1].toObject();


    if (msg_type == "book") {

        ws_book_parse(jsonObj);

    } else if (msg_type == "trade_history") {

        ws_trade_history_parse(jsonObj);

    } else if (msg_type == "orders") {

        ws_orders_parse(jsonObj);

    } else if (msg_type == "balance") {

        ws_balance_parse(jsonObj);
    }
}
//-----------------------------------------------------------------------------
void Crp::ws_order_update(const QJsonObject &json, dom::Order* dom_order)
{
    dom_order->set_order_id(json["order_id"].toInteger());
    dom_order->set_price(json["price"].toDouble());
    dom_order->set_amount(json["amount"].toDouble());
    dom_order->set_value(json["value"].toDouble());

    dom_order->set_orig_value(json["orig_value"].toDouble());
    dom_order->set_date_reg(json["date_reg"].toDouble());
    dom_order->set_task(json["task"].toString());
    dom_order->set_status(json["status"].toString());
    dom_order->set_orig_amount(json["orig_amount"].toDouble());
    dom_order->set_cur(json["cur"].toString());
    dom_order->set_ecur(json["ecur"].toString());
    dom_order->set_price_executed(json["price_executed"].toDouble());
    dom_order->set_value_executed(json["value_executed"].toDouble());
}
//-----------------------------------------------------------------------------
void Crp::ws_balance_parse(const QJsonObject &json)
{
    const QString cur = json["cur"].toString();
    const qreal balance = json["balance"].toDouble();
    const qreal reserve = json["reserve"].toDouble();

    if (cur == "usdt")
    {
        set_buy_balance(balance);
        set_buy_balance_reserve(reserve);
    }
    else if (cur == "btc")
    {
        set_sell_balance(balance);
        set_sell_balance_reserve(reserve);
    }
}
//-----------------------------------------------------------------------------
void Crp::ws_orders_parse(const QJsonObject &json)
{
    QJsonArray orders = json["orders"].toArray();

    if (orders.count() > 0)
    {
        foreach (const QJsonValue & jv, orders)
        {
            auto obj = jv.toObject();

            auto order_id = obj["order_id"].toInteger();

            dom::Order* dom_order;

            auto task = obj["task"].toString(); // SELL or BUY

            QQmlObjectListModel<dom::Order> * orders;

            orders = (task == "buy") ? get_buy_orders() : get_sell_orders();

            dom_order = orders->getByUid(QString::number(order_id)); //check sell_orders


            if (!dom_order)
            {
                // CREATE ORDER
                dom_order = new dom::Order;

                ws_order_update(obj, dom_order);

                orders->append(dom_order);

            } else {
                //UPDATE ORDER
                auto status = obj["status"].toString();

                if (status == "open")
                {
                    ws_order_update(obj, dom_order);
                }
                else if (status == "close" || status == "cancel")
                {
                    orders->remove(dom_order);
                }
            }
        }


    }
}
//-----------------------------------------------------------------------------
void Crp::ws_trade_history_parse(const QJsonObject &json)
{
    QJsonArray items_array = json["items"].toArray();

    if (items_array.count() > 0)
    {
        foreach (const QJsonValue & jv, items_array)
        {
            crp::HistoryTrade item(jv.toObject());

            dom::TradeItem* dom_trade_item = new dom::TradeItem;

            dom_trade_item->set_price(item.price());
            dom_trade_item->set_amount(item.amount());
            dom_trade_item->set_value(item.value());

            dom_trade_item->set_is_buy(item.is_buy());
            dom_trade_item->set_created_at(item.created_at());

            get_history_trade_items()->insert(0, dom_trade_item);
        }
    }
}
//-----------------------------------------------------------------------------
void Crp::ws_book_parse(const QJsonObject &json)
{
    QString type = json["type"].toString();
    QJsonArray book_array = json["book"].toArray();

    if (book_array.count() > 0)
    {
        QJsonObject book_int = book_array[0].toObject();

        auto price = book_int["price"].toDouble();
        auto value = book_int["value"].toDouble();
        auto amount = book_int["amount"].toDouble();

        dom::Book* dom_book = new dom::Book;

        dom_book->set_price(price);
        dom_book->set_amount(amount);
        dom_book->set_value(value);

        append_book(dom_book, type);

    } else
    {
        qreal price = json["price"].toDouble();
        remove_book_item(price, type);
    }

    emit spreadChanged();
}

//-----------------------------------------------------------------------------
void Crp::remove_book_item(qreal price, QString type)
{
    auto book = type == "sell" ? get_sell_book() : get_buy_book();

    uint index = 0;

    foreach (auto & r, book->toList())
    {
        if (r->get_price() == price)
        {
            book->remove(index);
            qDebug() << "REMOVE " << price << " OK";
            break;
        }

        index++;
    }

    qDebug() << "NOT FOUND " << type << price;

  //  std::remove_if(book.begin(), book.end(),
  //      [price](const dom::Book* b) -> bool { return b->get_price() == price; });

}
//-----------------------------------------------------------------------------
void Crp::append_book(dom::Book* item, QString type)
{
    auto book = type == "sell" ? get_sell_book() : get_buy_book();

    uint index = 0;

    if (book->count() > 0) {

        foreach (auto & r, book->toList())
        {
            if (item->get_price() < r->get_price() && type == "sell")
            {
                book->insert(index, item);  // SELL

                //qDebug() << "INSERT BOOK" << index << item->get_price();

                break;
            }
            else if (item->get_price() > r->get_price() && type == "buy")
            {
                book->insert(index, item);  // SELL

                //qDebug() << "INSERT BOOK" << index << item->get_price();

                break;
            }
            else if (item->get_price() == r->get_price())
            {
                r->set_amount(item->get_amount()); // Update Amount
                r->set_value(item->get_value());    // Update Value

                //qDebug() << "UPDATE BOOK ITEM" << index << item->get_price();
                break;
            }

            index++;
        }

    } else {

        book->append(item);
        qDebug() << "APPEND BOOK" << item->get_price();
    }



//    std::sort(book.begin(), book.end(),
//        [](const dom::Book* a, const dom::Book* b) -> bool {
//            return a->get_price() < b->get_price(); //implement your logic here
//    });

//    get_sell_book()->clear();

}
//-----------------------------------------------------------------------------
void Crp::load_orders()
{
    qDebug() << "LOAD ORDERS !!!";
    //net->setCookie("auth_token", m_user.auth_token());

    this->m_state = "orders";
    net->getData("https://crp.is:8182/orders?status=open");
}
//-----------------------------------------------------------------------------
void Crp::cancel_order(uint order_id)
{
    qDebug() << order_id;

    QUrlQuery postData;
    postData.addQueryItem("order_id", QString::number(order_id));

    this->m_state = "order_cancel";
    net->postDataForm("https://crp.is:8182/market/cancel", postData);
}
//-----------------------------------------------------------------------------
void Crp::buy(qreal price, qreal amount)
{
    QString str_price = QString::number(price);
    QString str_amount = QString::number(amount);

    qDebug() << "NEW PRICE " << str_price;

    QUrlQuery postData;
    postData.addQueryItem("pair", "btc_usdt");
    postData.addQueryItem("amount", str_amount);
    postData.addQueryItem("price", str_price);

    this->m_state = "buy_sell";
    net->postDataForm("https://crp.is:8182/market/buy", postData);
}
//-----------------------------------------------------------------------------
void Crp::sell(qreal price, qreal amount)
{
    QString str_price = QString::number(price);
    QString str_amount = QString::number(amount);

    qDebug() << "NEW PRICE " << str_price;

    QUrlQuery postData;
    postData.addQueryItem("pair", "btc_usdt");
    postData.addQueryItem("amount", str_amount);
    postData.addQueryItem("price", str_price);

    this->m_state = "buy_sell";
    net->postDataForm("https://crp.is:8182/market/sell", postData);
}
//-----------------------------------------------------------------------------
void Crp::change_bid(uint order_id, qreal price, qreal amount, QString task)
{
    // 1.Cancel Order
    // 2.Buy Order
    // ДОБАВИТЬ ОЧЕРЕДЬ

    m_new_price = price;
    m_new_amount = amount;
    m_task = task;

    QUrlQuery postData;
    postData.addQueryItem("order_id", QString::number(order_id));

    this->m_state = "change_bid";
    net->postDataForm("https://crp.is:8182/market/cancel", postData);
}
//-----------------------------------------------------------------------------
void Crp::login(QString pk, QString pass)
{
    QUrl url("https://crp.is:8182/user/login");

    QUrlQuery postData;

    postData.addQueryItem("PublicKey", pk);
    postData.addQueryItem("password", pass);

    this->m_state = "login";
    net->postDataForm("https://crp.is:8182/user/login", postData);
}
//-----------------------------------------------------------------------------
void Crp::balance()
{

    //net->setCookie("auth_token", m_user.auth_token());

    this->m_state = "balance";
    net->getData("https://crp.is:8182/user/balance");
}
//-----------------------------------------------------------------------------
void Crp::panel()
{
    QUrlQuery postData;
    postData.addQueryItem("pair", "btc_usdt");

    this->m_state = "panel";
    net->postDataForm("https://crp.is:8182/market/panel", postData);
}
//-----------------------------------------------------------------------------
void Crp::history_trade()
{
    QUrlQuery postData;
    postData.addQueryItem("pair", "btc_usdt");

    this->m_state = "history_trade";
    net->getData("https://crp.is:8182/history/trade?pair=btc_usdt");
}
//-----------------------------------------------------------------------------
void Crp::parse_login(const QJsonDocument &json)
{
    QJsonObject jsonObject = json.object();

    m_user = crp::User(jsonObject, m_state);

    qDebug() << m_user.auth_token();

    net->setCookie("auth_token", m_user.auth_token());

    //open_socket(m_user.auth_token());
    m_state = "ready";
}
//-----------------------------------------------------------------------------
void Crp::open_socket(QString auth_token) {

    connect(m_ssl_socket, &SslSocket::onMessage, this, &Crp::onSocketMessage);

    m_ssl_socket->open(auth_token);


   // SslSocket client(QUrl(QStringLiteral("wss://crp.is:8181/socket.io/?EIO=3&transport=websocket")));

   // SslSocket ssl_socket(QUrl(QStringLiteral("wss://crp.is:8181/socket.io/?EIO=3&transport=websocket")));
}
//-----------------------------------------------------------------------------
void Crp::parse_balance(const QJsonObject &json)
{
    //QJsonObject jsonObject = json.object();

    m_balance = new crp::Balance();
    m_balance->parse(json);


    auto balances = m_balance->get_balances();
    auto usdt = balances->getByUid("usdt");
    auto btc = balances->getByUid("btc");

    set_buy_balance(usdt->get_balance());
    set_buy_balance_reserve(usdt->get_reserve());

    auto buy_round = usdt->get_round();
    qDebug() << "buy_round = " << buy_round;

    set_buy_round(buy_round);   // precision


    set_sell_balance(btc->get_balance());
    set_sell_balance_reserve(btc->get_reserve());

    auto sell_round = btc->get_round();
    qDebug() << "sell_round = " << sell_round;

    set_buy_round(sell_round);   // precision

    set_sell_round(btc->get_round());   // precision

    m_state = "ready";
}
//-----------------------------------------------------------------------------
bool Crp::parse_order_cancel(const QJsonDocument &json)
{
    bool res = false;

    QJsonObject jsonObject = json.object();

    if (jsonObject["success"].toBool() == false)
    {
        return res;
    } else
    {
        res = true;
    }

    QJsonObject result = jsonObject["result"].toObject();
    auto success = result["success"].toBool();
    auto order_id = result["order_id"].toInteger();

    qDebug() << order_id << success;

    return res;

    //dom::Order* order = get_orders()->getByUid(QString::number(order_id));
    //get_orders()->remove(order);
}
//-----------------------------------------------------------------------------
bool Crp::parse_buy_sell(const QJsonDocument &json)
{
    QJsonObject jsonObject = json.object();


    if (jsonObject["success"].toBool() == false) return false;

    QJsonObject result = jsonObject["result"].toObject();
    auto success = result["success"].toBool();
    auto order_id = result["order_id"].toInteger();

    qDebug() << order_id << success;

    return true;
}
//-----------------------------------------------------------------------------
void Crp::parse_orders(const QJsonDocument &json)
{
    qDebug() << "PARSE ORDERS !!!";

    QJsonObject jsonObject = json.object();

    if (jsonObject["success"].toBool() == false)
    {
        qDebug() << "PARSE ORDERS SUCCESS FALSE";
        return;
    }

    get_orders()->clear();

    QJsonObject result = jsonObject["result"].toObject();
    QJsonArray allorders = result["allorders"].toArray();

    foreach (const QJsonValue & jv, allorders)
    {
        dom::Order* dom_order = new dom::Order;

        dom_order->set_order_id(jv["order_id"].toInteger());

        dom_order->set_price(jv["price"].toDouble());
        dom_order->set_amount(jv["amount"].toDouble());
        dom_order->set_value(jv["value"].toDouble());

        dom_order->set_value(jv["orig_value"].toDouble());
        dom_order->set_date_reg(jv["date_reg"].toInteger());
        dom_order->set_task(jv["task"].toString());
        dom_order->set_status(jv["status"].toString());
        dom_order->set_orig_amount(jv["orig_amount"].toDouble());

        dom_order->set_cur(jv["cur"].toString());
        dom_order->set_ecur(jv["ecur"].toString());
        dom_order->set_price_executed(jv["price_executed"].toDouble());
        dom_order->set_value_executed(jv["value_executed"].toDouble());


        if (dom_order->get_task() == "buy")
        {
            get_buy_orders()->append(dom_order);
        }
        else if (dom_order->get_task() == "sell")
        {
            get_sell_orders()->append(dom_order);
        }


        qDebug() << dom_order->get_task() << dom_order->get_price();

        //dom::Order order(jsonValue.toObject());

        //qDebug() << "order " << order.price() << order.amount() << order.value();

        //this->m_book_sell << order;
    }

}

//-----------------------------------------------------------------------------
void Crp::parse_panel(const QJsonDocument &json)
{
    QJsonObject jsonObject = json.object();

    m_panel = crp::Panel(jsonObject);

    get_sell_book()->clear();
    get_buy_book()->clear();

    //fill data

    for (auto order_sell : m_panel.bookSell()) {

        dom::Book* book = new dom::Book;

        book->set_price(order_sell.price());
        book->set_amount(order_sell.amount());
        book->set_value(order_sell.value());

        //get_sell_orders()->append(dom_order);

        get_sell_book()->append(book);

        //qDebug() << "SELL" << book->get_price();
    }

    for (auto order_buy : m_panel.bookBuy()) {

        dom::Book* book = new dom::Book;

        book->set_price(order_buy.price());
        book->set_amount(order_buy.amount());
        book->set_value(order_buy.value());

        //get_buy_orders()->append(dom_order);
        get_buy_book()->append(book);
    }

    emit spreadChanged();

    m_state = "ready";
}
//------------------------------------------------------------------------
void Crp::parse_history_trade(const QJsonDocument &json)
{
    QJsonObject jsonObject = json.object();

    m_history = crp::History(jsonObject);

    get_history_trade_items()->clear();

    for (auto i : m_history.historyTradeItems()) {

        dom::TradeItem* dom_trade_item = new dom::TradeItem;

        dom_trade_item->set_price(i.price());
        dom_trade_item->set_amount(i.amount());
        dom_trade_item->set_value(i.value());

        dom_trade_item->set_is_buy(i.is_buy());
        dom_trade_item->set_created_at(i.created_at());

        get_history_trade_items()->append(dom_trade_item);
    }

    m_state = "ready";
}
//------------------------------------------------------------------------
void Crp::readyRead(QNetworkReply *reply) {

    QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObject = jsonResponse.object();

    if (m_state == "change_bid") {
        qDebug() << "readyRead INC_BID";

        if(this->parse_order_cancel(jsonResponse))
        {
            if (m_task == "buy")
                buy(m_new_price, m_new_amount);

            else if (m_task == "sell")
                sell(m_new_price, m_new_amount);
        }
        else {
            qDebug() << "ERROR INC BID";
        }
        //m_state = "ready";
        //load_orders();
    }
    else if (m_state == "buy_sell") {

        if(this->parse_buy_sell(jsonResponse))
        {
            qDebug() << "Order placed";
        } else {
            qDebug() << "ERROR ORDER PLACED";
        }

        m_state = "ready";

        load_orders();
    }
    else if (m_state == "order_cancel") {

        if(this->parse_order_cancel(jsonResponse))
        {
            qDebug() << "Order canceled OK";
        }

        m_state = "ready";
        load_orders();
    }
    else if (m_state == "orders") {
        qDebug() << "readyRead orders";

        this->parse_orders(jsonResponse);
        m_state = "ready";

    }
    else if (m_state == "login") {
        qDebug() << "readyRead login";

        this->parse_login(jsonResponse);
        this->balance();





      //  m_state = "ready";
     //   this->balance();

      //  m_state = "ready";
      //  this->panel();

   //
   //     connect(net, &Net::onReady, this, &Crp::readyRead);

        //emit onOrders();
    }
    else if (m_state == "balance")
    {
        qDebug() << "readyRead balance";

        this->parse_balance(jsonObject);
        this->panel();

        //m_state = "ready";
        //qDebug() << "OK.";
    }
    else if (m_state == "panel")
    {
        //qDebug() << "readyRead panel";
        this->parse_panel(jsonResponse);
        this->history_trade();
        //m_state = "ready";
    }
    else if (m_state == "history_trade")
    {
        //qDebug() << "readyRead history_trade";
        this->parse_history_trade(jsonResponse);
        open_socket(m_user.auth_token());

        //m_state = "ready";
    }
    else {
        qDebug() << "m_state " << m_state;
    }
}
