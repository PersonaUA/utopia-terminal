import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: rec_line
    //width: 360
    //height: 40
    color: "#232e3c"

    property int leftMargin: 20
    property int rightMargin: 15

    border.width: 1
    border.color: "#333e4c"

    RowLayout {
        width: parent.width
        height: parent.height

        Layout.fillWidth: true
        Layout.fillHeight: true

            HeaderLabel {
                width: parent.width * 0.33
                //leftMargin: leftMargin
                //rightMargin: rightMargin
                labelText: "Price"
            }

            HeaderLabel {
                width: parent.width * 0.33
                //leftMargin: leftMargin
                //rightMargin: rightMargin
                labelText: "BTC"
            }

            HeaderLabel {
                width: parent.width * 0.33
                //leftMargin: leftMargin
                //rightMargin: rightMargin
                labelText: "USDT"
            }

    }
}
