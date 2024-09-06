import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    //Layout.fillWidth: true
    Layout.minimumWidth: 100
    Layout.maximumWidth: 200
    Layout.preferredWidth: 150

    property real bookData
    property int round
    property string suffix: ""

    Label {
        Layout.fillWidth: true
        horizontalAlignment: Qt.AlignLeft
        verticalAlignment: Qt.AlignVCenter
        font.pointSize: 11
        font.family: "Roboto"
        color: "#bbbbbb"

        Layout.leftMargin: 20

        text: 1 * bookData.toFixed(round) + suffix
    }
}
