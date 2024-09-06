import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Rectangle {
    id: buy_sell_button_line
    color: "transparent"
    width: parent.width
    height: 50

    property int lineHeight: 50
    property double price

    ColumnLayout {
        width: parent.width
        height: parent.height

        Layout.fillHeight: true
        spacing: 2

        RowLayout {
            width: parent.width
            Layout.fillHeight: true
            focus: false
            spacing: -1

            Button {
                id: button
                Layout.fillWidth: true

                Layout.rightMargin: 10
                Layout.leftMargin: 10

                Layout.alignment: Qt.AlignHCenter
                Layout.maximumWidth: 150
                Layout.minimumWidth: 150
                Layout.preferredWidth: 150

                flat: true
                //width: parent.width / 2
                text: button_text

                background: Rectangle {
                    implicitWidth: 100
                    implicitHeight: 40
                    color: button.hovered ? (button.down ? "#4b7cb0" : "#5b98d9") : "#5288c1" //
                    radius: 4
                }
            }

        }
    }
}
