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

    property var orderModel

    property int orderIndex
    property var orderID

    property real orderPrice
    property real orderAmount
    property real orderValue

    property int orderHeight: 37
    property int orderWidth


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

            BookData {
                bookData: orderPrice
                round: 2
            }

            ColumnLayout { Layout.fillWidth: true }

            BookData {
                bookData: orderAmount
                round: 5
            }

            ColumnLayout { Layout.fillWidth: true }

            BookData {
                bookData: orderValue
                round: 7
            }

            //ColumnLayout { Layout.fillWidth: true }
        }
    }
}



