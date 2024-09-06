#pragma once

#include <QObject>
#include "qtqml/qqmlhelpers.h"
//#include "qtqml/qqmlobjectlistmodel.h"
#include <QVariant>
#include <QPair>
//#include "extension.h"


//#include "../lib/qqmlvariantlistmodel.h"

namespace dom {

class Book : public QObject
{
    Q_OBJECT
    QML_WRITABLE_PROPERTY (qreal,   price)    //key
    QML_WRITABLE_PROPERTY (qreal,   amount)
    QML_WRITABLE_PROPERTY (qreal,    value)
    QML_WRITABLE_PROPERTY (uint,      time)
    //QML_WRITABLE_PROPERTY (bool,    is_buy)     // buy-1|sell-0

public slots:


public:

    explicit Book(QObject * parent = NULL) : QObject (parent) {

        //m_expand = false;
        //m_ext = new QQmlObjectListModel<Extension>(parent, "ext", "key");
    }
};

}
