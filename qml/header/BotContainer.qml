import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    property int round: 1
    property double balance: 0
    property string button_text
    property double priceStart
    property string img_source


    color: 'transparent'
    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.margins: 0



    //width: parent.width * 0.2
    height: 150

    //border.width: 1
    //border.color: "#232e3c"

    //Layout.maximumWidth: parent.width / 2

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

            Label {
                height: 50
                padding: 0
                Layout.fillWidth: true
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                font.pointSize: 14
                font.family: "Roboto"
                color: "#dddddd"
                text: "BOT"
            }
        }

        RowLayout { Layout.fillHeight: true }

        RowLayout {
            Layout.leftMargin: 10
            Layout.rightMargin: 10
            Layout.topMargin: 10

            spacing: 10
            height: 50

        }

        RowLayout { Layout.fillHeight: true }

        BuySellButtonLine {
            Layout.bottomMargin: 10
        }
    }
}
