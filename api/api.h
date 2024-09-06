#pragma once

#include <QObject>

#include "../qtqml/qqmlobjectlistmodel.h"
#include "qtzeroconf/qzeroconf.h"
#include "dom/device.h"


class Api : public QObject
{
    Q_OBJECT
    QML_OBJMODEL_PROPERTY(Device,  devices)

public:
    explicit Api(QObject* parent = nullptr);

public slots:



private slots:
    void addService(QZeroConfService item);
    void removeService(QZeroConfService item);
    void updateService(QZeroConfService zcs);

private:
    QZeroConf* zeroConf;
    QZeroConf* zeroConf2;

    QList<QZeroConf*> zc;

};

