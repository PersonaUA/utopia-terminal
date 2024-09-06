import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../order"

// MY ORDERS LIST
RowLayout {
    id: orders_row
    width: main.width
    height: 100
    spacing: 0

    Rectangle {
        color: "#131b24" //'transparent'
        Layout.fillWidth: true
        Layout.fillHeight: true
        //Layout.maximumWidth: parent.width //* 0.4

        Orders {}

//        ScrollView {
//            width: parent.width
//            height: parent.height

//            OrderList {
//                model: crp.buy_orders
//            }
//        }
    }
}
