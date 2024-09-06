import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects


Rectangle {
    id: trade_container

    property int round: 1

    property string name

    property double balance: 0
    property double reserve: 0

    property string button_text

    property double price
    property double amount


    property string img_source


    color: 'transparent'

    Layout.margins: 0
    Layout.fillWidth: true
    Layout.fillHeight: true

    //width: parent.width * 0.4
    height: 200

    border.width: 1
    border.color: "#232e3c"


    ColumnLayout {
        anchors.fill: parent
        Layout.alignment: Qt.AlignHCenter
        Layout.margins: 0

        spacing: -1

        RowLayout {
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            Layout.topMargin: 10

            spacing: 10
            height: 50

            Image {
                width: 32; height: 32
                fillMode: Image.PreserveAspectFit
                source: img_source
            }

            Label {
                height: 50
                padding: 0              
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignLeft
                verticalAlignment: Qt.AlignVCenter
                font.pointSize: 14
                font.family: "Roboto"
                color: "#dddddd"
                text: balance.toFixed(8)
            }

            ColumnLayout { Layout.fillWidth: true }

            Label {
                height: 50
                padding: 0
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignRight
                verticalAlignment: Qt.AlignVCenter
                font.pointSize: 14
                font.family: "Roboto"
                color: "#dddddd"
                text: 1 * reserve.toFixed(8)
            }

        }

        RowLayout { Layout.fillHeight: true }

        // PRICE
        InputLine {
            Layout.margins: 0
            height: 50
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.maximumWidth: 300
            Layout.minimumWidth: 200
            Layout.preferredWidth: 200

            Layout.maximumHeight: 50
            Layout.minimumHeight: 50
            Layout.preferredHeight: 50

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            value: price
            placeholderText: "Price " + name
        }

        // AMOUNT
        InputLine {
            Layout.margins: 0
            height: 50
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.maximumWidth: 300
            Layout.minimumWidth: 200
            Layout.preferredWidth: 200

            Layout.maximumHeight: 50
            Layout.minimumHeight: 50
            Layout.preferredHeight: 50

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            value: amount
            placeholderText: "Amount " + name
        }

        RowLayout { Layout.fillHeight: true }



        RowLayout {

            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter

            AmountSlider {}

        }

        BuySellButtonLine {
            Layout.bottomMargin: 10
        }



    }

//    layer.enabled: true

//    layer.effect: DropShadow {
//        anchors.fill: toolBar
//        horizontalOffset: 0
//        verticalOffset: 1
//        radius: 3
//        samples: 10
//        color: "#000"
//        opacity: 0.2
//    }

}
