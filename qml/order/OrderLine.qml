import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "../"

import "qrc:/mdi/Icon.js" as MdiFont

Rectangle {
    id: order_line
    color: "#17212b" // "#232e3c" //"#3e525c"

    width: parent.width //orderWidth
    height: orderHeight



    radius: 3
    //border.width: 1
    //border.color: "red"

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
            spacing: 0

            CustomRoundButton {
                diameter: 30

                Layout.leftMargin: 5
                Layout.rightMargin: 5

                text: MdiFont.Icon.chevronDown
                borderColor: "#232e3c"
            }

            OrderData {
                orderData: orderPrice
                round: 2

                Layout.minimumWidth: 60
                Layout.maximumWidth: 60
                Layout.preferredWidth: 60
            }

            CustomRoundButton {
                diameter: 30

                Layout.leftMargin: 5
                Layout.rightMargin: 15

                text: MdiFont.Icon.chevronUp
                borderColor: "#232e3c"
            }

            ColumnLayout { Layout.fillWidth: true }

            OrderData {
                orderData: orderAmount
                round: 5

                Layout.minimumWidth: 80
                Layout.maximumWidth: 80
                Layout.preferredWidth: 80
            }

            ColumnLayout { Layout.fillWidth: true }

            OrderData {
                orderData: orderValue
                round: 7

                Layout.minimumWidth: 80
                Layout.maximumWidth: 80
                Layout.preferredWidth: 80
            }

            IconButton {
                id: cancel_bid
                Layout.leftMargin: 5
                Layout.rightMargin: 0
                imageSource: "qrc:/img/delete.svg"

                onClicked: {
                    crp.cancel_order(orderID.toString())
                }
            }

//            OrderOptionsColumn {
//                width: parent.width * 0.2
//                height: parent.height

//                Layout.fillWidth: true
//                Layout.fillHeight: true

//                color: "#17212b" //"#132e3c"
//            }

            //ColumnLayout { Layout.fillWidth: true }
        }
    }
}

