import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/mdi/Icon.js" as MdiFont

//import "qrc:/qml/IconButton.qml" as IconButton

Rectangle {
    id: order_line
    color: "#232e3c" //"#3e525c"

    width: orderWidth
    height: orderHeight

    radius: 3
    border.width: 1
    border.color: "#333e4c"

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

            ColumnLayout { Layout.fillWidth: true }

            IconButton {
                id: inc_bid
                Layout.rightMargin: 20
                Layout.leftMargin: 20
                imageSource: "qrc:/img/arrow_24.png"

                onClicked: {
                    crp.change_bid(orderID.toString(), orderPrice + 1, orderAmount, orderTask)
                    //crp.buy(orderPrice + 10, orderAmount)
                }
            }

            IconButton {
                id: cancel_bid
                Layout.leftMargin: 0
                Layout.rightMargin: 0
                imageSource: "qrc:/img/delete.svg"

                onClicked: {
                    crp.cancel_order(orderID.toString())
                }
            }

            IconButton {
                id: dec_bid
                Layout.rightMargin: 20
                Layout.leftMargin: 20
                imageSource: "qrc:/img/arrow_24_down.png"

                onClicked: {
                    crp.change_bid(orderID.toString(), orderPrice - 1, orderAmount, orderTask)
                }
            }

            ColumnLayout { Layout.fillWidth: true }
        }
    }
}

