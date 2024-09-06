#pragma once

#include <QObject>
#include "qtqml/qqmlhelpers.h"


namespace dom {

class Balance : public QObject
{
    Q_OBJECT
    QML_WRITABLE_PROPERTY (uint,   currency_id)
    QML_WRITABLE_PROPERTY (qreal,       balance)
    QML_WRITABLE_PROPERTY (qreal,       reserve)
    QML_WRITABLE_PROPERTY (QString,        name)
    QML_WRITABLE_PROPERTY (uint,          round)

public slots:


public:

    explicit Balance(QObject * parent = NULL) : QObject (parent) { }
};

}
