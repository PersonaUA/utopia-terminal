import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: order_line
    Layout.fillWidth: true
    width: main.width
    height: 37
    color: "#232e3c"

    radius: 3

    property var orderModel
    property int orderIndex
    property int orderID

    property string orderTask
    property real orderPrice
    property real orderAmount
    property real orderValue

    property string orderCur
    property string orderEcur


    RowLayout {
        width: parent.width
        height: parent.height

        Layout.fillWidth: true
        Layout.fillHeight: true

        spacing: 0

        OrderPartRow {
            //BUY ORDERS
            width: parent.width * 0.4
            height: parent.height

            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.maximumWidth: parent.width * 0.4

            color: "#132e3c"

            //leftMargin: 20
            //rightMargin: 15
        }

        OrderOptionsColumn {
            width: parent.width * 0.2
            height: parent.height

            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "#17212b" //"#132e3c"
        }
        OrderPartRow {
            //SELL ORDERS
            width: parent.width * 0.4
            height: parent.height

            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.maximumWidth: parent.width * 0.4

            color: "#132e3c"

            //leftMargin: 20
            //rightMargin: 15
        }




//        OrderPartRow {
//            //Total amount
//            width: parent.width * 0.2
//            height: parent.height

//            Layout.fillWidth: true
//            Layout.fillHeight: true
//            color: "#132e3c"

//            leftMargin: 10
//            rightMargin: 5
//        }

//        OrderPartRow {
//            //SELL ORDERS
//            width: parent.width * 0.4
//            height: parent.height
//            Layout.fillWidth: true
//            Layout.fillHeight: true
//            color: "#132e3c"

//            leftMargin: 20
//            rightMargin: 15
//        }

    }
}





//import QtQuick
//import QtQuick.Controls
//import QtQuick.Layouts

//import "qrc:/mdi/Icon.js" as MdiFont

//Rectangle {
//    id: order_line
//    color: "#232e3c" //"#3e525c"
//    //width: main.width ? main.width : 100
//    height: orderHeight
//    radius: 3

//    property int orderHeight: 35

//    property var orderModel
//    property int orderIndex
//    property int orderID

//    property string orderTask
//    property real orderPrice
//    property real orderAmount
//    property real orderValue

//    property string orderCur
//    property string orderEcur


//    ColumnLayout {
//        width: parent.width
//        height: parent.height
//        Layout.fillWidth: true
//        Layout.fillHeight: true
//        spacing: 0

//        RowLayout {
//            width: parent.width
//            Layout.fillHeight: true
//            Layout.fillWidth: true
//            focus: false
//            spacing: -1

//            //Type
//            //price
//            // total amount
//            // value
//            // Remaining Amount

//            Label {
//                Layout.fillWidth: true
//                horizontalAlignment: Qt.AlignLeft
//                verticalAlignment: Qt.AlignVCenter

//                Layout.minimumWidth: 50
//                Layout.maximumWidth: 50
//                Layout.preferredWidth: 50

//                font.pointSize: 10
//                font.family: "Roboto"
//                color: orderTask == "buy" ? "#5a7fb9" : "#e8596b"
//                //color: isBuy ? "#5a7fb9" : "#e8596b"

//                Layout.leftMargin: 10

//                text: orderTask.toUpperCase()    //Number.parseFloat(orderData.toFixed(precision)) // (1 * orderData.toFixed(precision)).toFixed(); //1 * orderData.toFixed(precision)
//            }

//            OrderData {
//                orderData: orderID
//            }

//           // ColumnLayout { Layout.fillWidth: true }

//            OrderData {
//                orderData: orderPrice
//                round: 2
//                suffix: " " + orderEcur.toUpperCase()
//            }

//           // ColumnLayout { Layout.fillWidth: true }

//            OrderData {
//                orderData: orderAmount
//                round: 5
//                suffix: " " + orderCur.toUpperCase()
//            }

//            //ColumnLayout { Layout.fillWidth: true }

//            OrderData {
//                Layout.fillWidth: true
//                orderData: orderValue
//                round: 7
//                suffix: " " + orderEcur.toUpperCase()
//            }



//           ColumnLayout { Layout.fillWidth: true }

//           IconButton {
//               id: inc_bid
//               Layout.rightMargin: 20
//               Layout.leftMargin: 20
//               imageSource: "qrc:/img/arrow_24.png"

//               onClicked: {
//                   crp.change_bid(orderID.toString(), orderPrice + 1, orderAmount, orderTask)
//                   //crp.buy(orderPrice + 10, orderAmount)
//               }
//           }

//           IconButton {
//               id: cancel_bid
//               Layout.rightMargin: 20
//               imageSource: "qrc:/img/delete.svg"

//               onClicked: {
//                   crp.cancel_order(orderID.toString())
//               }
//           }
//        }
//    }
//}
