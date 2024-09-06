import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    anchors.fill: parent
    color: "#232e3c" //"#232e3c"

RowLayout {
    width: parent.width
    height: parent.height

    Layout.fillWidth: true
    Layout.fillHeight: true

    spacing: 0

    // BUY ORDERS LIST
    Rectangle {
        color: "#131b24"
        Layout.fillWidth: true
        Layout.fillHeight: true

        Layout.maximumWidth: main.width * 0.4
        Layout.minimumWidth: main.width * 0.4
        Layout.preferredWidth: main.width * 0.4

        //border.width: 1
        //border.color: "#232e3c"

        ScrollView {
            width: parent.width
            height: parent.height

            OrderList {
                model: crp.buy_orders
            }
        }
    }

    // SPREAD
    Rectangle {
        color: "#17212b"
        Layout.fillWidth: true
        Layout.fillHeight: true

        Layout.maximumWidth: main.width * 0.2
        Layout.minimumWidth: main.width * 0.2
        Layout.preferredWidth: main.width * 0.2

        //border.width: 1
        //border.color: "#232e3c"

        ColumnLayout {
            anchors.fill: parent
            Layout.alignment: Qt.AlignHCenter
            Layout.margins: 0
            spacing: -1

            OrderData {

                Layout.minimumWidth: parent.width
                Layout.maximumWidth: parent.width
                Layout.preferredWidth: parent.width

                prefix: "Spread: $"
                orderData: crp.spread
                horAlignment: 4 //Qt.AlignCenter
            }
        }

//        Label {
//            width: parent.width

//            //Layout.fillWidth: true
//            Layout.alignment: Qt.AlignHCenter

//            horizontalAlignment: Qt.AlignCenter
//            verticalAlignment: Qt.AlignVCenter

//            font.pointSize: 11
//            font.family: "Roboto"
//            color: "#bbbbbb"

//            Layout.topMargin: 20

//            text: "Spread: $123.45"
//        }

    }

    // SELL ORDERS LIST
    Rectangle {
        color: "#131b24"
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.maximumWidth: parent.width * 0.4

        //border.width: 1
        //border.color: "#232e3c"

        ScrollView {
            width: parent.width
            height: parent.height

            OrderList {
                model: crp.sell_orders
            }
        }
    }
}

}
