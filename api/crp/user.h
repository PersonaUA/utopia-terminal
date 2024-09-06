#ifndef USER_H
#define USER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "api/crp/currency.h"


namespace crp {


class User
{

public:
    User();
    User(const QJsonObject &json, QString state);


    QString id() const;
    void set_id(const QString &value);

    QString name() const;
    void set_name(const QString &value);

    QString status() const;
    void set_status(const QString &value);

    QString lang() const;
    void set_lang(const QString &value);

    QString auth_token() const;
    void set_auth_token(const QString &value);



    void parse(const QJsonObject &json, QString state);
    void parse_login(QJsonObject result);
    void parse_balance(QJsonObject result);

private:
    QString m_id;
    QString m_name;
    QString m_status;
    QString m_lang;

    QString m_auth_token;
    QString m_session_id;
};

}

#endif // USER_H
