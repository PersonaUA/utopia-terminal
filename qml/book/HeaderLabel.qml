import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {

    Layout.fillWidth: true
    Layout.fillHeight: true

    property string labelText
    //property int leftMargin
    //property int rightMargin

    Label {
        Layout.fillWidth: true

        horizontalAlignment: Qt.AlignLeft
        verticalAlignment: Qt.AlignVCenter

        font.pointSize: 11
        font.family: "Roboto"
        color: "#bbbbbb"

        Layout.leftMargin: leftMargin
        Layout.rightMargin: rightMargin

        text: labelText
    }
}
