import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "qrc:/mdi/Icon.js" as MdiFont

Rectangle {
    id: order_line
    color: "#17212b" // "#232e3c" //"#3e525c"
    width: parent.width
    height: historyHeight
    //radius: 3


    property var historyModel

    property int historyIndex
    property var historyID

    property real historyPrice
    property real historyAmount
    property string historyTime

    property bool isBuy

    property int historyHeight: 24


    ColumnLayout {
        width: parent.width
        height: parent.height

        Layout.fillHeight: true
        spacing: -1

        RowLayout {
            width: parent.width
            Layout.fillHeight: true
            focus: false
            spacing: -1

            Label {
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignLeft
                verticalAlignment: Qt.AlignVCenter
                font.pointSize: 8
                font.family: "Roboto"
                color: "#bbbbbb"

                Layout.leftMargin: 10

                text: historyAmount.toFixed(5)
            }

//            OrderData {
//                orderData: historyAmount
//                precision: 2
//            }

            ColumnLayout { Layout.fillWidth: true }

            Label {
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignLeft
                verticalAlignment: Qt.AlignVCenter
                font.pointSize: 8
                font.family: "Roboto"
                color: isBuy ? "#5a7fb9" : "#e8596b"

                Layout.leftMargin: 10

                text: historyPrice.toFixed(2) //historyTime
            }


//            OrderData {
//                orderData: historyPrice
//                precision: 5
//            }

            ColumnLayout { Layout.fillWidth: true }

            Label {
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignLeft
                verticalAlignment: Qt.AlignVCenter
                font.pointSize: 8
                font.family: "Roboto"
                color: "#bbbbbb"

                Layout.leftMargin: 10

                text: historyTime
            }



            //ColumnLayout { Layout.fillWidth: true }
        }
    }
}
