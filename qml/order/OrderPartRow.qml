import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/mdi/Icon.js" as MdiFont

Rectangle {
    id: order_line
    color: "#232e3c" //"#3e525c"

    width: orderWidth
    height: orderHeight


    radius: 3

    ColumnLayout {
        width: parent.width
        height: parent.height

        Layout.fillHeight: true
        spacing: 0

        RowLayout {
            width: parent.width
            Layout.fillHeight: true
            focus: false
            spacing: -1

            OrderData {
                bookData: orderPrice
                round: 2
            }

            ColumnLayout { Layout.fillWidth: true }

            OrderData {
                bookData: orderAmount
                round: 5
            }

            ColumnLayout { Layout.fillWidth: true }

            OrderData {
                bookData: orderValue
                round: 7
            }

            //ColumnLayout { Layout.fillWidth: true }
        }
    }
}





//import QtQuick
//import QtQuick.Controls
//import QtQuick.Layouts

//Rectangle {
//    id: rec_line
//    //width: 360
//    //height: 40
//    color: "#232e3c"

//    property int leftMargin: 20
//    property int rightMargin: 15

//    //border.width: 1
//    //border.color: "#333e4c"

//    RowLayout {
//        width: parent.width
//        height: parent.height

//        Layout.fillWidth: true
//        Layout.fillHeight: true

//        OrderColumnData {
//            width: parent.width * 0.33
//            row1_data: orderPrice
//            row2_data: orderAmount
//            row1_round: 2
//            row2_round: 5
//            row1_prefix: qsTr("Цена: ")
//            //row1_suffix: qsTr(" USDT")
//            row2_prefix: qsTr("Кол-во: ")
//            //row2_suffix: qsTr(" BTC")
//        }

//        OrderColumnData {
//            width: parent.width * 0.33
//            row1_data: orderValue
//            row2_data: orderAmount
//            row1_round: 7
//            row2_round: 5
//            row1_prefix: qsTr("Сумма: ")
//            //row1_suffix: qsTr(" USDT")
//            row2_prefix: qsTr("Остаток: ")
//            //row2_suffix: qsTr(" BTC")
//        }
//    }
//}
