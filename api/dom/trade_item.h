#pragma once

#include <QObject>
#include "qdatetime.h"
#include "qtqml/qqmlhelpers.h"
#include <QVariant>
#include <QPair>

namespace dom {


class TradeItem : public QObject
{
    Q_OBJECT
    QML_WRITABLE_PROPERTY (QString,     record_id)
    QML_WRITABLE_PROPERTY (bool,           is_buy)
    QML_WRITABLE_PROPERTY (qreal,           price)
    QML_WRITABLE_PROPERTY (qreal,          amount)
    QML_WRITABLE_PROPERTY (qreal,           value)
    QML_WRITABLE_PROPERTY (QString,      created_at)



public slots:


public:

    explicit TradeItem(QObject * parent = NULL) : QObject (parent) {}
};



}
