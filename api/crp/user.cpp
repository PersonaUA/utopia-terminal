#include "user.h"

namespace crp {

User::User() { }
User::User(const QJsonObject &json, QString state) { this->parse(json, state); }

QString User::id() const { return this->m_id; }
QString User::name() const { return this->m_name; }
QString User::status() const { return this->m_status; }
QString User::lang() const { return this->m_lang; }

QString User::auth_token() const { return this->m_auth_token; }
//----------------------------------------------------------------------------------------
void User::parse_login(QJsonObject result)
{
    QJsonObject user_session = result["user_session"].toObject();
    QJsonObject user = user_session["user"].toObject();
    QJsonObject session = user_session["session"].toObject();

    this->m_name = user["name"].toString();
    this->m_status = user["status"].toString();
    this->m_lang = user["lang"].toString();

    this->m_auth_token = result["auth_token"].toString();
    this->m_session_id = session["id"].toString();

    qDebug() << "User: " << this->m_name;
}
//----------------------------------------------------------------------------------------
void User::parse_balance(QJsonObject result)
{
    QJsonArray jsonArray = result["allbalance"].toArray();

    foreach (const QJsonValue & jsonValue, jsonArray)
    {
        QJsonObject json_currency = jsonValue.toObject();

        int id = json_currency["id"].toInt();

        double balance = json_currency["balance"].toDouble();

        auto currency = new crp::Currency;

        // currency->parse(json_currency);
        //qDebug() << name << " " << balance;
        //orders::order order(jsonValue.toObject());
        //this->m_orders << order;
        //this->m_map_orders << order.map();
    }

}

//----------------------------------------------------------------------------------------
void User::parse(const QJsonObject &json, QString state) {

    if (json["success"].toBool() == true)
    {
        QJsonObject result = json["result"].toObject();

        if (state == "login")
        {
            parse_login(result);
        }
        else if (state == "balance")
        {
            parse_balance(result);
        }

    } else {
        qDebug() << "ERROR: Not found";
    }
}

}
